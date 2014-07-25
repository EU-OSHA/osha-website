<?php

class MigrateOshaThesaurus extends DynamicMigration {
  protected $vocabulary = NULL;

  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Taxonomies'));

    $this->description = 'Import "Thesaurus" taxonomy from JSON file';
    $this->vocabulary = 'thesaurus';
    $file_name = $arguments['file_name'];
    $source_file = sprintf("%s/%s", drupal_get_path('module', 'osha_migration'), $file_name);

    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'code' => array(
          'type' => 'varchar',
          'length' => 30,
          'not null' => TRUE,
          'description' => 'Thesaurus code'
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceList(
      new ThesaurusMigrationListJSON($source_file),
      new ThesaurusMigrationItemJSON($source_file, array()),
      $this->fields()
    );

    $term_options = MigrateDestinationTerm::options('en', 'text', TRUE);
    $this->destination = new MigrateDestinationTerm($this->vocabulary, $term_options);

    $this->addFieldMapping('field_thesaurus_code', 'code');
    $this->addFieldMapping('parent', 'parent');
    $this->addFieldMapping('format')->defaultValue('plain_text');
    $this->addFieldMapping('name', 'en');
    $this->addFieldMapping('description_field:format')->defaultValue('plain_text');
  }

  protected function createStub(/** @noinspection PhpUnusedParameterInspection */ $migration, array $source) {
    static $voc = NULL;
    if ($voc == NULL) {
      $voc = taxonomy_vocabulary_machine_name_load($this->vocabulary);
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

  public function prepareRow($row) {
    $row->parent = 0;
    $row->language = 'en';
    $row->parent = $this->getParent($row);

    return TRUE;
  }

  public function prepare($entity, stdClass $row) {
    $entity->language = 'en';
    $translationsData = array();
    $languages = array(
      'nl',
      'sl',
      'it',
      'lv',
      'es',
      'cs',
      'pt',
      'el',
      'lt',
      'da',
      'mt',
      'pl',
      'hu',
      'sk',
      'et',
      'de',
      'ro',
      'fr',
      'sh',
      'bg',
      'sv',
      'fi',
      'tr',
      'en'
    );

    foreach ($languages as $language) {
      if (!empty($row->$language)) {
        $entity->name_field[$language][0]['value'] = $row->$language;
        $entity->description_field[$language][0]['value'] = $row->$language;
        $sourceLanguage = ($language == 'en' ? '' : 'en');
        $translationsData[$language] = array(
          'entity_type' => 'term',
          'language' => $language,
          'source' => $sourceLanguage,
          'uid' => '1',
          'status' => '1',
          'translate' => '0',
        );
      }
      $entity->translations = (object) array(
        'original' => 'en',
        'data' => $translationsData
      );
    }
  }

  private function getParent($row) {
    $parent_code = $row->parent_code;
    if (!empty($parent_code)) {
      $parent_id = self::_getTidByCode($parent_code);
      if (empty($parent_id)) {
        $parent_id = $this->handleSourceMigration($this->generateMachineName(), $parent_code);
      }
      return $parent_id;
    }
    return 0;
  }

  private static function _getTidByCode($code) {
    $query = new EntityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'taxonomy_term')
      ->fieldCondition('field_thesaurus_code', 'value', $code, '=')
      ->execute();
    if (!empty($result['taxonomy_term'])) {
      return current(array_keys($result['taxonomy_term']));
    }
    return array();
  }

  private function fields() {
    return array(
      'code' => 'The unique identifier',
      'en' => 'The description/name of the item',
      'parent' => 'The tid of the parent'
    );
  }

  protected function generateMachineName() {
    return 'ThesaurusTaxonomy';
  }
}

class ThesaurusMigrationListJSON extends MigrateListJSON {
  protected function getIDsFromJSON(array $data) {
    $ids = array();
    foreach ($data['@graph'] as $item) {
      $ids[] = substr($item['@id'], 6);
    }
    return $ids;
  }

  public function computeCount() {
    $count = 0;
    $json = NULL;
    if (empty($this->httpOptions)) {
      $json = file_get_contents($this->listUrl);
    }
    if ($json) {
      $data = drupal_json_decode($json);
      if ($data) {
        $count = count($data['@graph']);
      }
    }
    return $count;
  }
}

class ThesaurusMigrationItemJSON extends MigrateItemJSON {
  protected $data = array();

  public function getItem($item_id) {
    if (empty($this->data)) {
      $dataArray = $this->loadJSONUrl($this->itemUrl);
      foreach ($dataArray['@graph'] as $rawItem) {
        $item = array();
        $item['code'] = substr($rawItem['@id'], 6);
        $item['parent_code'] = (isset($rawItem['@skos:broaderTransitive'])
          ? substr($rawItem['@skos:broaderTransitive']['@id'], 6) : NULL);
        foreach ($rawItem["@skos:prefLabel"] as $label) {
          $item[$label['@language']] = $label['@value'];
        }
        $item['type'] = $rawItem['@type'];
        $this->data[$item['code']] = json_decode(json_encode($item), FALSE);
      }
    }

    return isset($this->data[$item_id]) ? $this->data[$item_id] : NULL;
  }

  protected function loadJSONUrl($item_url) {
    if (empty($this->httpOptions)) {
      $json = file_get_contents($item_url);
    }
    else {
      $response = drupal_http_request($item_url, $this->httpOptions);
      $json = $response->data;
    }
    return json_decode($json, TRUE);
  }
}