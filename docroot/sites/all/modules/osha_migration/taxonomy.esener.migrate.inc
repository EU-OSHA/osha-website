<?php

class MigrateOshaTaxonomyEsener extends DynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Taxonomies'));
    $this->description = 'Populate the "Esener" taxonomy from JSON file in osha_migration module';

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $source_file = MigrationUtil::getSourceFile($arguments);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'code' => array(
          'type' => 'varchar',
          'length' => 30,
          'not null' => TRUE,
          'description' => 'Nace code',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceList(
      new OSHAMigrationListJSON($source_file, 'code'),
      new OSHATaxonomyMigrationItemJSON($source_file),
      array(
        'parent' => 'Parent tid',
        'en' => 'Term name in english',
        'code' => 'Term code (PK)',
      )
    );

    $this->destination = new MigrateDestinationTerm(OSHA_TAXONOMIES_ESENER);

    $this->addFieldMapping('name', 'en');
    $this->addFieldMapping('parent', 'parent');
    $this->addFieldMapping('field_esener_code', 'code');
    $this->addFieldMapping('format')->defaultValue('plain_text');

    $this->addUnmigratedDestinations(array(
      'description',
      'parent_name',
      'weight',
      'description_field',
      'description_field:summary',
      'description_field:format',
      'description_field:language',
      'field_esener_code:language',
      'path',
    ));
  }

  /**
   * Create a stub object that will be later migrated.
   *
   * @param object $migration
   *   Migration object
   * @param array $source
   *   Source object
   *
   * @return array
   *   Array with new tid
   */
  protected function createStub($migration, array $source) {
    static $voc = NULL;
    if ($voc == NULL) {
      $voc = taxonomy_vocabulary_machine_name_load(OSHA_TAXONOMIES_ESENER);
    }
    $term = new stdClass();
    $term->parent = 0;
    $term->language = 'en';
    $term->name = t('Stub for @code', array('@code' => $source[0]));
    $term->vid = $voc->vid;
    taxonomy_term_save($term);
    return array($term->tid);
  }

  /**
   * Prepare raw data pulled from source.
   *
   * {@inheritdoc }
   */
  public function prepareRow($row) {
    $row->language = 'en';

    $row->parent = 0;
    if (!empty($row->parent_code)) {
      $parent_id = MigrationUtil::findTermByFieldValue($row->parent_code, 'field_esener_code');
      if (empty($parent_id)) {
        $parent_id = $this->handleSourceMigration($this->generateMachineName(), $row->parent_code);
      }
      $row->parent = $parent_id;
    }

    return TRUE;
  }

  /**
   * Called by destination right before saving.
   *
   * @param object $entity
   *   Entity to save
   * @param object $row
   *   Source row
   */
  public function prepare($entity, $row) {
    $entity->language = "en";
    $migration = Migration::currentMigration();
    $entity_type = $migration->getDestination()->getEntityType();
    $translation_handler = entity_translation_get_handler($entity_type, $entity);
    $languages = array_keys(language_list());

    $entity->translations = $translation_handler->getTranslations();
    foreach ($languages as $language) {
      if (!empty($row->{$language})) {
        $entity->name_field[$language][0]['value'] = $row->{$language};
        /* Don't translate en (default) */
        if ($language != $row->language && !isset($entity->translations->data[$language])) {
          $translation_handler->setTranslation(array(
            'translate' => 0, 'status' => 1, 'uid' => 1,
            'language' => $language,
            'source' => $row->language,
          ));
        }
      }
    }
  }

  /**
   * Migration machine name.
   *
   * {@inheritdoc}
   */
  protected function generateMachineName() {
    return OSHA_MIGRATION_TAXONOMY_ESENER;
  }
}
