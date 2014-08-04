<?php

class MigrateOshaTaxonomyNaceCodes extends DynamicMigration {

  protected $vocabulary = 'nace_codes';

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Taxonomies'));
    $this->description = 'Populate the "NACE Codes" taxonomy from JSON file in osha_migration module';

    $source_file = MigrationUtil::getSourceFile($arguments);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'NACE_REV_2_CODE' => array(
          'type' => 'varchar',
          'length' => 30,
          'not null' => TRUE,
          'description' => 'Nace code',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceList(
      new OSHAMigrationListJSON($source_file, 'NACE_REV_2_CODE'),
      new NaceCodesMigrationItemJSON($source_file, array()),
      $this->fields()
    );

    $term_options = MigrateDestinationTerm::options('en', 'text', TRUE);
    $this->destination = new MigrateDestinationTerm($this->vocabulary, $term_options);

    $this->addFieldMapping('field_nace_code', 'NACE_REV_2_CODE');
    $this->addFieldMapping('parent', 'parent');
    $this->addFieldMapping('format')->defaultValue('plain_text');
    $this->addFieldMapping('name', 'NACE_REV_2_DESCRIPTION');
    $this->addFieldMapping('description_field:format')->defaultValue('plain_text');
    $this->addFieldMapping('field_nace_changes', 'Change');
    $this->addFieldMapping('weight', 'weight');

    $this->addUnmigratedDestinations(array(
      'description',
      'parent_name',
      'description_field:summary',
      'field_nace_changes:language',
      'field_nace_code:language',
      'name_field:language',
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

  /**
   * Compute term weight.
   *
   * @param object $row
   *   Source row
   *
   * @return int|null
   *   Generated weight.
   */
  public function getWeightByCode($row) {
    $weight = NULL;
    if ($row->Level > 2) {
      $weight_str = substr($row->NACE_REV_2_CODE, -1);
      $weight = intval($weight_str);
    }
    else {
      if ($row->Level == 2) {
        $weight_str = substr($row->NACE_REV_2_CODE, -2);
        $weight = intval($weight_str);
      }
      else {
        $weight = ord($row->NACE_REV_2_CODE) - ord('A');
      }
    }
    return $weight;
  }

  /**
   * Prepare raw data pulled from source.
   *
   * {@inheritdoc }
   */
  public function prepareRow($row) {
    $row->language = 'en';
    $row->weight = $this->getWeightByCode($row);

    $parent_code = $this->getParentCode($row);
    if (!empty($parent_code)) {
      $parent_id = MigrationUtil::findTermByFieldValue($parent_code, 'field_nace_code');
      if (empty($parent_id)) {
        $parent_id = $this->handleSourceMigration($this->generateMachineName(), $parent_code);
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
    $assoc = NaceCodesMigrationItemJSON::$cache[$row->NACE_REV_2_CODE];

    $migration = Migration::currentMigration();
    $entity_type = $migration->getDestination()->getEntityType();
    $translation_handler = entity_translation_get_handler($entity_type, $entity);
    $languages = $this->getSourceDestinationFieldMappings();

    $entity->translations = $translation_handler->getTranslations();
    foreach ($languages as $language => $fields) {
      foreach ($fields as $target => $source) {
        if (!empty($assoc[$source])) {
          $entity->{$target}[$language][0]['value'] = $assoc[$source];
        }
      }
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

  /**
   * Migration machine name.
   *
   * {@inheritdoc}
   */
  protected function generateMachineName() {
    return OSHA_MIGRATION_TAXONOMY_NACE_CODES;
  }


  /**
   * Extract NACE parent code from a record depending on level and code.
   *
   * @param object $row
   *   Row object
   *
   * @return null|string
   *   Code or NULL if not found
   */
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

  /**
   * Return the list of available source fields.
   *
   * @return array
   *   An array o fields with their description
   */
  public function fields() {
    return array(
      'ID' => "id",
      'NACE_REV_2_CODE' => 'The corresponding NACE Code',
      'Sections for publication' => 'The main section the NACE Code',
      'Level' => 'The depth level of the respective tree',
      'Change' => 'The last changes made to the nace code',
      'parent' => 'The tid of the parent',
      'NACE_REV_2_DESCRIPTION' => 'The name of the NACE Code',
      'weight' => 'The generated weight of the taxonomy term',
    );
  }

  /**
   * Prepare a mapping between source field and destination files. Multilingual.
   *
   * @return array
   *   Field mappings
   */
  public static function getSourceDestinationFieldMappings() {
    $languages = array_keys(language_list());
    $special = array(
      'et' => 'est',
      'sv' => 'se',
      'sl' => 'si',
    );

    $mappings = array();
    foreach ($languages as $language) {
      $code = $language;
      if (array_key_exists($language, $special)) {
        $code = $special[$language];
      }
      $mappings[$language] = array(
        'name_field' => strtoupper($code) . "_DESC",
        'description_field' => strtoupper($code) . "_DESC",
        'field_nace_excludes' => strtoupper($code) . "_EXCL",
        'field_nace_includes' => strtoupper($code) . "_INCL",
        'field_nace_includes_also' => strtoupper($code) . "_INCL_ALSO",
      );
      /* These fields have different naming convention in JSON */
      if ($language == 'en') {
        $mappings[$language] = array(
          'name_field' => 'NACE_REV_2_DESCRIPTION',
          'description_field' => 'NACE_REV_2_DESCRIPTION',
          'field_nace_excludes' => 'excludes',
          'field_nace_includes' => 'includes',
          'field_nace_includes_also' => 'includes also',
        );
      }
      elseif ($language == 'de' || $language == 'fr') {
        $mappings[$language] = array(
          'name_field' => $code . "_Description",
          'description_field' => $code . "_Description",
          'field_nace_excludes' => $code . "_Excludes",
          'field_nace_includes' => $code . "_Includes",
          'field_nace_includes_also' => $code . "_Includes also",
        );
      }
    }
    return $mappings;
  }
}

class NaceCodesMigrationItemJSON extends MigrateItemJSON {
  public static $cache;

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (empty(self::$cache)) {
      $rows = json_decode(file_get_contents($this->itemUrl), TRUE);
      foreach ($rows as $row) {
        self::$cache[$row['NACE_REV_2_CODE']] = $row;
      }
    }
    return isset(self::$cache[$item_id]) ? (object) self::$cache[$item_id] : NULL;
  }
}
