<?php

class MigrateOshaNaceCodes extends DynamicMigration {

  protected $vocabulary = 'nace_codes';

  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Taxonomies'));

    $this->description = 'Import "Nace Codes" taxonomy from JSON file';

    if (isset($arguments['file_name'])) {
      $file_name = $arguments['file_name'];
    }
    else {
      $file_name = 'data/nace_codes.json';
    }
    $source_file = sprintf('%s/%s', drupal_get_path('module', 'osha_migration'), $file_name);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'NACE_REV_2_CODE' => array(
          'type' => 'varchar',
          'length' => 30,
          'not null' => TRUE,
          'description' => 'Nace code'
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceList(new NaceCodesMigrationListJSON($source_file),
      new NaceCodesMigrationItemJSON($source_file, array()), $this->fields());


    $term_options = MigrateDestinationTerm::options('en', 'text', TRUE);
    $this->destination = new MigrateDestinationTerm($this->vocabulary, $term_options);

    $this->addFieldMapping('field_nace_code', 'NACE_REV_2_CODE');
    $this->addFieldMapping('parent', 'parent');
    $this->addFieldMapping('format')->defaultValue('plain_text');
    $this->addFieldMapping('name', 'NACE_REV_2_DESCRIPTION');
    $this->addFieldMapping('description_field:format')->defaultValue('plain_text');
    $this->addFieldMapping('field_nace_changes', 'Change');
    $this->addFieldMapping('weight', 'weight');
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
    $term->field_nace_code[LANGUAGE_NONE][]['value'] = $source[0];
    taxonomy_term_save($term);

    return array($term->tid);
  }

  public function getWeightByCode($row) {
    $weight = NULL;
    if ($row->Level > 2) {
      $weightAsString = substr($row->NACE_REV_2_CODE, -1);
      $weight = intval($weightAsString);
    }
    else {
      if ($row->Level == 2) {
        $weightAsString = substr($row->NACE_REV_2_CODE, -2);
        $weight = intval($weightAsString);
      }
      else {
        $weight = ord($row->NACE_REV_2_CODE) - ord('A');
      }
    }

    return $weight;
  }

  public function prepareRow($row) {
    $row->parent = 0;
    $row->language = 'en';
    $row->parent = $this->getParent($row);
    $row->weight = $this->getWeightByCode($row);

    return TRUE;
  }

  function prepare($entity, stdClass $row) {
    $assoc = NaceCodesMigrationItemJSON::$cache[$row->NACE_REV_2_CODE];
    $entity->language = 'en';
    $translationsData = array();
    $languages = $this->generateLanguagesWithFieldsMap();

    foreach ($languages as $language => $fields) {
      $this->addTranslationToEntityFromRow($entity, $assoc, $language, $fields);
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

  protected function generateMachineName($machine=NULL) {
    return 'NaceCodes';
  }

  private function getParent($row) {
    $parent_code = $this->getParentCode($row);
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
      ->fieldCondition('field_nace_code', 'value', $code, '=')
      ->execute();
    if (!empty($result['taxonomy_term'])) {
      return current(array_keys($result['taxonomy_term']));
    }
    return array();
  }

  private function getParentCode($row) {
    $parent_code = NULL;
    $cached = NaceCodesMigrationItemJSON::$cache[$row->NACE_REV_2_CODE];
    if ($cached['Level'] > 3) {
      $parent_code = substr($cached['NACE_REV_2_CODE'], 0, -1);
    }
    else {
      if ($cached['Level'] == 3) {
        $parent_code = substr($cached['NACE_REV_2_CODE'], 0, -2);
      }
      else {
        if ($cached['Level'] == 2) {
          $parent_code = $cached['Sections for publication'];
        }
      }
    }
    return $parent_code;
  }

  function fields() {
    return array(
      'ID' => "id",
      'NACE_REV_2_CODE' => 'The corresponding NACE Code',
      'Sections for publication' => 'The main section the NACE Code',
      'Level' => 'The depth level of the respective tree',
      'Change' => 'The last changes made to the nace code',
      'parent' => 'The tid of the parent',
      'NACE_REV_2_DESCRIPTION' => 'The name of the NACE Code',
      'weight' => 'The generated weight of the taxonomy term'
    );
  }

  private function generateLanguagesWithFieldsMap() {
    $languages = array(
      'en' => 'en',
      'bg' => 'bg',
      'cs' => 'cs',
      'da' => 'da',
      'el' => 'el',
      'et' => 'est',
      'es' => 'es',
      'fi' => 'fi',
      'hr' => 'hr',
      'hu' => 'hu',
      'fr' => 'fr',
      'it' => 'it',
      'lt' => 'lt',
      'lv' => 'lv',
      'mt' => 'mt',
      'nl' => 'nl',
      'no' => 'no',
      'pl' => 'pl',
      'pt' => 'pt',
      'ro' => 'ro',
      'ru' => 'ru',
      'sv' => 'se',
      'sl' => 'si',
      'sk' => 'sk',
      'tr' => 'tr',
      'de' => 'de'
    );

    $specialLanguages = array('de', 'fr');
    $defaultLanguage = 'en';

    $languageFieldsMap = array();
    foreach ($languages as $language => $field_language_code) {
      if ($language == $defaultLanguage) {
        $languageFieldsMap[$language] = array(
          'description' => 'NACE_REV_2_DESCRIPTION',
          'excludes' => 'excludes',
          'includes' => 'includes',
          'includes_also' => 'includes also'
        );
      }
      else {
        if (in_array($language, $specialLanguages)) {
          $languageFieldsMap[$language] = array(
            'description' => $field_language_code . "_Description",
            'excludes' => $field_language_code . "_Excludes",
            'includes' => $field_language_code . "_Includes",
            'includes_also' => $field_language_code . "_Includes also"
          );
        }
        else {
          $languageFieldsMap[$language] = array(
            'description' => strtoupper($field_language_code) . "_DESC",
            'excludes' => strtoupper($field_language_code) . "_EXCL",
            'includes' => strtoupper($field_language_code) . "_INCL",
            'includes_also' => strtoupper($field_language_code) . "_INCL_ALSO"
          );
        }
      }
    }
    return $languageFieldsMap;
  }

  private function addTranslationToEntityFromRow(&$entity, $row, $language, $fields) {
    if (!empty($row[$fields['description']])) {
      $entity->name_field[$language][0]['value'] = $row[$fields['description']];
    }
    if (!empty($row[$fields['description']])) {
      $entity->description_field[$language][0]['value'] = $row[$fields['description']];
    }
    if (!empty($row[$fields['includes']])) {
      $entity->field_nace_includes[$language][0]['value'] = $row[$fields['includes']];
    }
    if (!empty($row[$fields['includes_also']])) {
      $entity->field_nace_includes_also[$language][0]['value'] = $row[$fields['includes_also']];
    }
    if (!empty($row[$fields['excludes']])) {
      $entity->field_nace_excludes[$language][0]['value'] = $row[$fields['excludes']];
    }
  }
}

class NaceCodesMigrationListJSON extends MigrateListJSON {
  /**
   * The default implementation assumes the IDs are top-level array elements,
   * but the array elements are the data items - we need to look inside them
   * for the IDs.
   */
  protected function getIDsFromJSON(array $data) {
    $ids = array();
    foreach ($data as $item) {
      $ids[] = $item['NACE_REV_2_CODE'];
    }
    return $ids;
  }
}

class NaceCodesMigrationItemJSON extends MigrateItemJSON {
  protected $data = array();
  public static $cache;

  public function getItem($item_id) {
    if (empty($this->data)) {
      $cache = $this->loadJSONUrl($this->itemUrl);
      foreach ($cache as $item) {
        self::$cache[$item['NACE_REV_2_CODE']] = $item;
        $this->data[$item['NACE_REV_2_CODE']] = json_decode(json_encode($item), FALSE);
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