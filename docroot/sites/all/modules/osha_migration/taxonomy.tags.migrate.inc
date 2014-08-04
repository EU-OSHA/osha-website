<?php

/**
 * Class MigrateOshaTaxonomyTags migrates tags.json taxonomy. The data
 * is stored inside the <em>Tags</em> taxonomy.
 *
 * Part of the <em>OSHA Taxonomies</em> translation group
 */
class MigrateOshaTaxonomyTags extends DynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Taxonomies'));
    $this->description = 'Populate the "Tags" taxonomy from JSON file in osha_migration module';

    $source_file = MigrationUtil::getSourceFile($arguments);
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'code' => array(
          'type' => 'varchar',
          'length' => 100,
          'not null' => TRUE,
          'description' => 'Term code',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceList(
      new OSHAMigrationListJSON($source_file, 'code'),
      new TagsTaxonomyMigrationItemJSON($source_file, array()),
      array(
        'code' => 'Term code',
        'en' => 'Term name in english',
        'parent' => 'Parent term',
      )
    );

    $term_options = MigrateDestinationTerm::options('en', 'text', TRUE);
    $this->destination = new MigrateDestinationTerm(OSHA_TAXONOMIES_TAGS, $term_options);

    $this->addFieldMapping('field_tags_code', 'code');
    $this->addFieldMapping('parent', 'parent');
    $this->addFieldMapping('format')->defaultValue('plain_text');
    $this->addFieldMapping('name', 'en');
    $this->addFieldMapping('description_field:format')->defaultValue('plain_text');
    $this->addUnmigratedDestinations(array(
      'weight',
      'description_field',
      'description_field:summary',
      'description_field:language',
      'field_tags_code:language',
      'parent_name',
      'description',
      'path',
    ));
  }

  /**
   * Prepare raw data pulled from source.
   *
   * {@inheritdoc }
   */
  public function prepareRow($row) {
    $row->parent = 0;
    $row->language = 'en';
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
    $migration = Migration::currentMigration();
    $entity_type = $migration->getDestination()->getEntityType();
    $translation_handler = entity_translation_get_handler($entity_type, $entity);
    $languages = array_keys(language_list());

    $entity->translations = $translation_handler->getTranslations();
    foreach ($languages as $language) {
      if (!empty($row->{$language})) {
        $entity->name_field[$language][0]['value'] = $row->$language;
        /* Don't translate en (default) */
        if ($language != $row->language) {
          if (!isset($entity->translations->data[$language])) {
            $translation_handler->setTranslation(array(
              'translate' => 0, 'status' => 1, 'uid' => 1,
              'language' => $language,
              'source' => $row->language,
            ));
          }
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
    return OSHA_MIGRATION_TAXONOMY_TAGS;
  }
}

class TagsTaxonomyMigrationItemJSON extends MigrateItemJSON {
  protected $data = array();

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (empty($this->data)) {
      $data = $this->loadJSONUrl($this->itemUrl);
      if ($data) {
        foreach ($data as $item) {
          $this->data[$item->code] = $item;
        }
      }
    }
    return isset($this->data[$item_id]) ? $this->data[$item_id] : NULL;
  }
}
