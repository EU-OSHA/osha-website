<?php

class MigrateOshaTaxonomyThesaurus extends DynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Taxonomies'));
    $this->description = 'Populate the "Thesaurus" taxonomy from JSON file in osha_migration module';

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $source_file = MigrationUtil::getSourceFile($arguments);
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'code' => array(
          'type' => 'varchar',
          'length' => 30,
          'not null' => TRUE,
          'description' => 'Thesaurus code',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceList(
      new ThesaurusMigrationListJSON($source_file),
      new ThesaurusMigrationItemJSON($source_file, array()),
      array(
        'code' => 'The unique identifier',
        'en' => 'The description/name of the item',
        'parent' => 'The tid of the parent',
      )
    );

    $this->destination = new MigrateDestinationTerm(OSHA_TAXONOMIES_THESAURUS);

    $this->addFieldMapping('field_thesaurus_code', 'code');
    $this->addFieldMapping('parent', 'parent');
    $this->addFieldMapping('format')->defaultValue('plain_text');
    $this->addFieldMapping('name', 'en');
    $this->addFieldMapping('description_field:format')->defaultValue('plain_text');

    $this->addUnmigratedDestinations(array(
      'description',
      'parent_name',
      'weight',
      'description_field',
      'description_field:summary',
      'description_field:language',
      'field_thesaurus_code:language',
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
      $voc = taxonomy_vocabulary_machine_name_load(OSHA_TAXONOMIES_THESAURUS);
    }
    $term = new stdClass();
    $term->parent = 0;
    $term->language = 'en';
    $term->name = t('Stub for @code', array('@code' => $source[0]));
    $term->vid = $voc->vid;
    $term->field_thesaurus_code[LANGUAGE_NONE][]['value'] = $source[0];
    taxonomy_term_save($term);

    return array($term->tid);
  }

  /**
   * Prepare raw data pulled from source.
   *
   * {@inheritdoc }
   */
  public function prepareRow($row) {
    $row->parent = 0;
    $row->language = 'en';

    $row->parent = 0;
    if (!empty($row->parent_code)) {
      $parent_id = MigrationUtil::findTermByFieldValue($row->parent_code, 'field_thesaurus_code');
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
        $entity->name_field[$language][0]['value'] = $row->$language;
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
    return OSHA_MIGRATION_TAXONOMY_THESAURUS;
  }
}

class ThesaurusMigrationListJSON extends MigrateListJSON {

  /**
   * {@inheritdoc}
   */
  protected function getIDsFromJSON(array $data) {
    $ids = array();
    foreach ($data['@graph'] as $item) {
      $ids[] = substr($item['@id'], 6);
    }
    return $ids;
  }

  /**
   * {@inheritdoc}
   */
  public function computeCount() {
    $ret = 0;
    $data = drupal_json_decode(file_get_contents($this->listUrl));
    if ($data) {
      $ret = count($data['@graph']);
    }
    return $ret;
  }
}

class ThesaurusMigrationItemJSON extends MigrateItemJSON {

  protected $data = array();

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (empty($this->data)) {
      $raw_data = $this->loadJSONUrl($this->itemUrl);
      foreach ($raw_data['@graph'] as $src) {
        $item = array();
        $item['code'] = substr($src['@id'], 6);
        $item['parent_code'] = (
          isset($src['@skos:broaderTransitive']) ?
            substr($src['@skos:broaderTransitive']['@id'], 6) : NULL
        );
        foreach ($src["@skos:prefLabel"] as $label) {
          $item[$label['@language']] = $label['@value'];
        }
        $item['type'] = $src['@type'];
        $this->data[$item['code']] = (object) $item;
      }
    }
    return isset($this->data[$item_id]) ? $this->data[$item_id] : NULL;
  }

  /**
   * Override to parse JSON as associative array.
   *
   * {@inheritdoc}
   */
  protected function loadJSONUrl($item_url) {
    return json_decode(file_get_contents($item_url), TRUE);
  }

  /**
   * Access internal cache.
   */
  public function getData() {
    return $this->data;
  }
}
