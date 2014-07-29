<?php

/**
 * Class MigrateOshaCategories migrates categories.json taxonomy. The data
 * is stored inside the <em>Tags</em> taxonomy.
 *
 * Part of the <em>OSHA Taxonomies</em> translation group
 */
class MigrateOshaCategories extends DynamicMigration {

  /** @var string Target vocabulary */
  protected $vocabulary = TAXONOMY_CATEGORIES;

  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Taxonomies'));

    $this->description = 'Import "Tags" taxonomy from JSON file';

    $file_name = $arguments['file_name'];
    $source_file = sprintf("%s/%s", drupal_get_path('module', 'osha_migration'), $file_name);

    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'code' => array(
          'type' => 'varchar',
          'length' => 100,
          'not null' => TRUE,
          'description' => 'Categories code'
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceList(
      new CategoriesTaxonomyMigrationListJSON($source_file),
      new CategoriesTaxonomyMigrationItemJSON($source_file, array()),
      $this->fields()
    );

    $term_options = MigrateDestinationTerm::options('en', 'text', TRUE);
    $this->destination = new MigrateDestinationTerm($this->vocabulary, $term_options);

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
      'name_field',
      'name_field:language',
      'parent_name',
      'description',
      'path'
    ));
  }

  public function prepareRow($row) {
    $row->parent = 0;
    $row->language = 'en';
    return TRUE;
  }

  public function prepare($entity, stdClass $row) {
    $migration = Migration::currentMigration();
    $entity_type = $migration->getDestination()->getEntityType();
    $translation_handler = entity_translation_get_handler($entity_type, $entity);
    $entity->translations = $translation_handler->getTranslations();
    $supported_languages = array_keys(language_list());
    foreach ($supported_languages as $lang_code) {
      if (!empty($row->$lang_code)) {
        $entity->name_field[$lang_code][0]['value'] = $row->$lang_code;
        if($lang_code != $row->language) { // Don't translate default language (en)
          if (!isset($entity->translations->data[$lang_code])) {
            $translation_handler->setTranslation(array(
              'translate' => 0, 'status' => 1, 'uid' => 1,
              'language' => $lang_code, 'source' => $row->language,
              'created' => time()
            ));
          }
        }
      }
    }
  }

  private function fields() {
    return array(
      'code' => 'Identifier',
      'en' => 'Term name in english',
      'parent' => 'Parent term',
    );
  }

  protected function generateMachineName() {
    return 'TagsTaxonomy';
  }
}

class CategoriesTaxonomyMigrationListJSON extends MigrateListJSON {
  protected function getIDsFromJSON(array $data) {
    $ids = array();
    foreach ($data as $item) {
      $ids[] = $item['code'];
    }
    return $ids;
  }
}

class CategoriesTaxonomyMigrationItemJSON extends MigrateItemJSON {
  protected $data = array();

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