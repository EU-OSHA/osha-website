<?php

/**
 * Class MigrateOshaCalls migrates calls.txt contents. The data
 * is stored inside the <em>Calls</em> content type.
 */
class MigrateOshaCalls extends OSHADynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Content types'));
    $this->description = 'Import "Calls" contents from CSV file';

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $source_file = MigrationUtil::getSourceFile($arguments);
    $this->source = new MigrateSourceList(
      new CallsMigrateList($source_file),
      new CallsMigrateItem(),
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
    $this->destination = new MigrateDestinationNode(OSHA_CALLS_CONTENT_TYPE_CALLS, $node_options);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_calls_deadline', 'deadline');
    $this->addFieldMapping('field_publication_date', 'publication_date');

    $this->addMultilingualFileFieldMapping('field_calls_contract_notice', 'contract_notice');
    $this->addMultilingualFileFieldMapping('field_calls_contract_n_corrig', 'contract_notice_corrigendum');
    $this->addMultilingualFileFieldMapping('field_calls_technical_specs', 'technical_specifications');
    $this->addMultilingualFileFieldMapping('field_calls_amendments', 'amendments');
    $this->addMultilingualFileFieldMapping('field_calls_agency_responses', 'agency_responses');
    $this->addMultilingualFileFieldMapping('field_calls_award_notice', 'award_notice');
    $this->addMultilingualFileFieldMapping('field_calls_award_n_corrig', 'award_notice_corrigendum');

    $this->addFieldMapping('created', 'creation_date');
    $this->addFieldMapping('changed', 'modification_date');
    $this->addFieldMapping('uid')->defaultValue(1);

    $this->addUnmigratedSources(array(
      'path',
      'language',
      'workflow_state',
      'field_title',
      'info',
      'description',
      'text',
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
      'body',
      'body:format',
      'body:language',
      'field_author',
      'field_author:language',
      'comment',
      'field_calls_agency_responses:file_class',
      'field_calls_agency_responses:language',
      'field_calls_agency_responses:destination_dir',
      'field_calls_amendments:file_class',
      'field_calls_amendments:language',
      'field_calls_amendments:destination_dir',
      'field_calls_award_n_corrig:file_class',
      'field_calls_award_n_corrig:language',
      'field_calls_award_n_corrig:destination_dir',
      'field_calls_award_notice:file_class',
      'field_calls_award_notice:language',
      'field_calls_award_notice:destination_dir',
      'field_calls_contract_n_corrig:file_class',
      'field_calls_contract_n_corrig:language',
      'field_calls_contract_n_corrig:destination_dir',
      'field_calls_contract_notice:file_class',
      'field_calls_contract_notice:language',
      'field_calls_contract_notice:destination_dir',
      'field_calls_info',
      'field_calls_info:format',
      'field_calls_info:language',
      'field_calls_technical_specs:file_class',
      'field_calls_technical_specs:language',
      'field_calls_technical_specs:destination_dir',
      'field_summary',
      'field_summary:format',
      'field_summary:language',
      'title_field',
      'title_field:language',
      'path',
    ));
  }

  /**
   * Function that does all the mapping for multilingual files.
   *
   * @param string $destination
   *   The destination multilingual file field
   * @param string $source
   *   The string multilingual file field
   */
  private function addMultilingualFileFieldMapping($destination, $source) {
    $this->addFieldMapping($destination, $source);
    $this->addFieldMapping("$destination:file_replace")->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldmapping("$destination:preserve_files")->defaultValue(TRUE);
    $this->addFieldMapping("$destination:source_dir")->defaultValue(osha_migration_get_data_dir() . '/export/');
    $this->addFieldMapping("$destination:destination_file", OSHA_MIGRATION_REPLACED_PATH_PREFIX . $source);
    $this->addFieldMapping("$destination:multilingual")->defaultValue(TRUE);
  }

  /**
   * Migration machine name.
   *
   * {@inheritdoc}
   */
  protected function generateMachineName() {
    return OSHA_MIGRATION_CONTENT_TYPE_CALLS;
  }

  /**
   * Prepare raw data pulled from source.
   *
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    $row->language = "en";
    if (MigrationUtil::entityRowValidator($row, $this) === FALSE) {
      return FALSE;
    }

    MigrationUtil::cleanMigratedFileField($row, 'contract_notice', 'public://calls/documents');
    MigrationUtil::cleanMigratedFileField($row, 'contract_notice_corrigendum', 'public://calls/documents');
    MigrationUtil::cleanMigratedFileField($row, 'technical_specifications', 'public://calls/documents');
    MigrationUtil::cleanMigratedFileField($row, 'amendments', 'public://calls/documents');
    MigrationUtil::cleanMigratedFileField($row, 'agency_responses', 'public://calls/documents');
    MigrationUtil::cleanMigratedFileField($row, 'award_notice', 'public://calls/documents');
    MigrationUtil::cleanMigratedFileField($row, 'award_notice_corrigendum', 'public://calls/documents');


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
      if (!empty($row->author[$language])) {
        $entity->field_author[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->author[$language]);
        $has_translation = TRUE;
      }
      if (!empty($row->description[$language])) {
        $entity->field_summary[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->description[$language]);
        $entity->field_summary[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      if (!empty($row->text[$language])) {
        $entity->body[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->text[$language]);
        $entity->body[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      if (!empty($row->info[$language])) {
        $entity->field_calls_info[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->info[$language]);
        $entity->field_calls_info[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }

      if ($has_translation) {
        MigrationUtil::setTranslation($translation_handler, $entity, $row, $language);
      }
    }
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
      'title' => '',
      'field_title' => '',
      'info' => '',
      'deadline' => '',
      'creator' => 'Author user id from the old website',
      'description' => '',
      'text' => 'Body of the case study',
      'contract_notice' => '',
      'contract_notice_corrigendum' => '',
      'technical_specifications' => '',
      'amendments' => '',
      'agency_responses' => '',
      'award_notice' => '',
      'award_notice_corrigendum' => '',
    );
  }
}

class CallsMigrateList extends MigrateList {
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
    $work_flow_key = array_search('workflow_state', $fields);

    self::$data = array();
    while (($raw_data = fgetcsv($handle, NULL, ';')) !== FALSE) {
      $language = !empty($raw_data[1]) ? $raw_data[1] : 'en';
      $path = MigrationUtil::getIDFromSourceRow($raw_data);
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
            self::$data[$path]['title_field'][$language] = MigrationUtil::decodeHTMLText($raw_data[$key]);
            break;

          case 'contract_notice':
          case 'contract_notice_corrigendum':
          case 'technical_specifications':
          case 'amendments':
          case 'agency_responses':
          case 'award_notice':
          case 'award_notice_corrigendum':
          case 'info':
          case 'author':
          case 'text':
          case 'description':
            self::$data[$path][$field][$language] = $raw_data[$key];
            break;

          case 'path':
            $path_language = explode('/', $raw_data[$key], 3);
            self::$data[$path][$field][$language] = $path_language[2];
            continue;

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

class CallsMigrateItem extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (array_key_exists($item_id, CallsMigrateList::$data)) {
      return (object) CallsMigrateList::$data[$item_id];
    }
    return NULL;
  }
}
