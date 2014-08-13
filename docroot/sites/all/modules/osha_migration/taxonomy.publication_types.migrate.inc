<?php

class MigrateOshaTaxonomyPublicationTypes extends DynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Taxonomies'));
    $this->description = 'Populate the "Publication types" taxonomy from JSON file in osha_migration module';

    $source_file = MigrationUtil::getSourceFile($arguments);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'code' => array(
          'type' => 'varchar',
          'length' => 30,
          'not null' => TRUE,
          'description' => 'Publication type code',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceList(
      new OSHAMigrationListJSON($source_file, 'code'),
      new OSHATaxonomyMigrationItemJSON($source_file),
      array(
        'en' => 'Term text in english',
        'code' => 'Term code',
      )
    );

    $this->destination = new MigrateDestinationTerm(OSHA_TAXONOMIES_PUBLICATION_TYPES);

    $this->addFieldMapping('field_publication_type_code', 'code');
    $this->addFieldMapping('format')->defaultValue('plain_text');
    $this->addFieldMapping('name', 'en');

    $this->addUnmigratedDestinations(array(
      'description',
      'parent',
      'parent_name',
      'weight',
      'description_field',
      'description_field:summary',
      'description_field:format',
      'description_field:language',
      'field_publication_type_code:language',
      'path',
    ));
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
        if ($language != 'en' && !isset($entity->translations->data[$language])) {
          $translation_handler->setTranslation(array(
            'translate' => 0, 'status' => 1, 'uid' => 1,
            'language' => $language,
            'source' => 'en',
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
    return OSHA_MIGRATION_TAXONOMY_PUBLICATION_TYPES;
  }
}
