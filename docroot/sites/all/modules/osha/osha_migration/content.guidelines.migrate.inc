<?php

/**
 * Class OshaMigrateGuidelines migrates guidelines from legislation.txt.
 */
class OshaMigrateGuidelines extends OSHADynamicMigration {

  /*path pattern*/
  const PATH_PATTERN = '/\/([a-z]{2})\/legislation\/guidelines\/([\w\d-_]+)\/([\w\d-_]+)/';

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Legislation'));
    $this->description = 'Import "Guidelines" from legislation.txt';
    $this->dependencies = array(
      OSHA_MIGRATION_TAXONOMY_THESAURUS,
      OSHA_MIGRATION_TAXONOMY_NACE_CODES,
    );

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $data_path = osha_migration_get_data_dir();
    $source_file = MigrationUtil::getSourceFile($arguments);
    $this->source = new MigrateSourceList(
      new GuidelineContentListCSV($source_file),
      new GuidelineContentItemCSV(),
      $this->fields()
    );

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Item code',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $node_options = MigrateDestinationNode::options('en', 'full_html');
    $this->destination = new MigrateDestinationNode(OSHA_LEGISLATION_CONTENT_TYPE_GUIDELINE, $node_options);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_archived', 'archived');
    $this->addFieldMapping('field_expiration_date', 'expiration_date');
    $this->addFieldMapping('field_external_url', 'external_url');

    $this->addFieldMapping('field_available_in_languages', 'available_languages')->separator(',');

    $this->addFieldMapping('field_tags', 'subject');
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_thesaurus', 'multilingual_thesaurus');
    $this->addFieldMapping('field_thesaurus:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_nace_codes', 'nace');
    $this->addFieldMapping('field_nace_codes:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_legislation_category', 'legislation_category');
    $this->addFieldMapping('field_legislation_category:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_publication_date', 'publication_date');
    $this->addFieldMapping('field_needs_retranslation')->defaultValue(0);

    $this->addFieldMapping('created', 'creation_date');
    $this->addFieldMapping('changed', 'modification_date');
    $this->addFieldMapping('uid')->defaultValue(1);

    $this->addUnmigratedSources(array(
      'path',
      'language',
      'workflow_state',
      'creator',
      'country',
    ));

    $this->addUnmigratedDestinations(array(
      'promote',
      'status',
      'sticky',
      'revision',
      'log',
      'language',
      'tnid',
      'translate',
      'revision_uid',
      'is_new',
      'body:summary',
      'field_publication_date:timezone',
      'field_publication_date:rrule',
      'field_publication_date:to',
      'field_summary',
      'field_tags:create_term',
      'field_tags:ignore_case',
      'field_thesaurus:create_term',
      'field_thesaurus:ignore_case',
      'comment',
    ));
  }

  /**
   * Migration machine name.
   *
   * {@inheritdoc}
   */
  protected function generateMachineName() {
    return OSHA_MIGRATION_CONTENT_TYPE_GUIDELINE;
  }

  /**
   * Prepare raw data pulled from source.
   *
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    if(MigrationUtil::entityRowValidator($row, $this) === FALSE) {
      return FALSE;
    }

    $row->language = 'en';
    $tags = $row->subject . ', ' . $row->subcategory;
    $row->subject = MigrationUtil::decodeTagsTerms($tags);
    if (!empty($row->multilingual_thesaurus)) {
      $terms = explode(',', $row->multilingual_thesaurus);
      $row->multilingual_thesaurus = MigrationUtil::findTidByTaxonomyField(
        OSHA_TAXONOMIES_THESAURUS,
        'field_thesaurus_code',
        $terms
      );
    }
    else {
      $row->multilingual_thesaurus = NULL;
    }
    if (!empty($row->nace) || $row->nace == '0') {
      $row->nace = explode(',', $row->nace);
      $row->nace = MigrationUtil::findTidByTaxonomyField(
        $row->nace,
        'field_nace_code',
        OSHA_TAXONOMIES_NACE_CODES
      );
    }
    //Term ID for Legislation Category Taxonomy
    if(preg_match(self::PATH_PATTERN, $row->path, $matches)){
      $row->legislation_category = MigrationUtil::findTidByEntityValue(
        OSHA_TAXONOMIES_LEGISLATION_CATEGORY,
        'field_guideline_category_code',
        array($matches[2])
      );
    }

    $row->available_languages = str_replace(' ', '', $row->available_languages);

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
    parent::prepare($entity, $row);

    $migration = Migration::currentMigration();
    $languages = array_keys(language_list());
    $entity_type = $migration->getDestination()->getEntityType();
    $translation_handler = entity_translation_get_handler($entity_type, $entity);

    $entity->translations = $translation_handler->getTranslations();

    foreach ($languages as $language) {
      $has_translation = FALSE;
      if (!empty($row->title_field[$language])) {
        $entity->title_field[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->title_field[$language]);
        $has_translation = TRUE;
      }
      if (!empty($row->description[$language])) {
        $entity->field_summary[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->description[$language]);
        $has_translation = TRUE;
      }
      if (!empty($row->text[$language])) {
        $entity->body[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->text[$language]);
        $entity->body[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      if ($has_translation) {
        MigrationUtil::setTranslation($translation_handler, $entity, $row, $language);
      }
    }
  }

  /**
   * Sets the node aliases and redirects after the migration, nid is available.
   *
   * @param object $entity
   *   Entity to be saved
   * @param object $row
   *   Source row
   */
  public function complete($entity, $row) {
    if (!empty($row->original_path)) {
      // create redirects
      $original_path = substr($row->original_path, 1);
      MigrationUtil::createRedirects($entity, $original_path);
    }

    //extract directive title from path
    if(preg_match(self::PATH_PATTERN, $row->path, $matches)){
      $row->id = 'legislation/guidelines/'.$matches[3];
    }
    // call MigrationUtil::createAliases
    parent::complete($entity, $row);
  }


  /**
   * Return the list of available source fields.
   *
   * @return array
   *   An array o fields with their description
   */
  public function fields() {
    return array(
      'id' => 'Primary Key (URL pattern)',
      'path' => 'URL pattern without language',
      'language' => 'Row language',
      'workflow_state' => '',
      'creation_date' => '',
      'modification_date' => '',
      'publication_date' => '',
      'creator' => 'Author user id from the old website',
      'title' => '',
      'description' => 'Summary of the guideline',
      'text' => 'Body of the guideline',
      'subject' => 'Categories/Tags',
      'country' => '',
      'subcategory' => 'Merged into categories',
      'multilingual_thesaurus' => '',
      'nace' => 'Nace codes taxonomy',
      'archived' => '',
      'expiration_date' => '',
      'original_path' => 'The URL redirect',
      'external_url' => '',
      'available_languages' => ''
    );
  }
}

class GuidelineContentListCSV extends MigrateList {
  protected $file = '';
  public static $data = array();

  /**
   * {@inheritdoc}
   */
  public function __construct($file) {
    parent::__construct();
    $this->file = $file;
    $this->parseSourceFile();
  }

  /**
   * {@inheritdoc}
   */
  public function __toString() {
    return $this->file;
  }

  /**
   * Parse the CSV file and populate the local cache.
   */
  protected function parseSourceFile() {
    $handle = fopen($this->file, 'r');
    $fields = $raw_data = fgetcsv($handle, NULL, ';');
    self::$data = array();
    $work_flow_key = array_search('workflow_state', $fields);
    while (($raw_data = fgetcsv($handle, NULL, ';')) !== FALSE) {
      $language = !empty($raw_data[1]) ? $raw_data[1] : 'en';
      $path = MigrationUtil::getIDFromSourceRow($raw_data);
      // skip non-Guidelines
      
      if (strpos($path, 'legislation/guidelines') !== 0) {
        continue;
      }
      self::$data[$path]['id'] = $path;
      // Assign the workflow state of the row from english entry.
      if ($language == 'en') {
        self::$data[$path]['workflow_state'] = $raw_data[$work_flow_key];
      }
      // Skip the private translations.
      if (!in_array($raw_data[$work_flow_key],
        array('published', 'checked', 'to_amend'))) {
        continue;
      }
      foreach ($fields as $key => $field) {
        switch ($field) {
          case 'title':
            if ($language == 'en') {
              self::$data[$path]['title'] = MigrationUtil::decodeHTMLText($raw_data[$key]);
            }
            self::$data[$path]['title_field'][$language] = $raw_data[$key];
            break;

          case 'description':
          case 'text':
            self::$data[$path][$field][$language] = $raw_data[$key];
            break;

          default:
            if ($language == 'en') {
              self::$data[$path][$field] = $raw_data[$key];
            }
            break;
        }
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getIdList() {
    if (empty(self::$data)) {
      $this->parseSourceFile();
    }
    return array_keys(self::$data);
  }

  /**
   * {@inheritdoc}
   */
  public function computeCount() {
    return count(self::$data);
  }
}

class GuidelineContentItemCSV extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (array_key_exists($item_id, GuidelineContentListCSV::$data)) {
      return (object) GuidelineContentListCSV::$data[$item_id];
    }
    return NULL;
  }
}
