<?php

class OshaMigrateSeminars extends OSHADynamicMigration {

  /*path pattern*/
  const PATH_PATTERN = '/seminars\/([\w\d-_]+)/';

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {
    parent::__construct(MigrateGroup::getInstance('OSHA Content types'));
    $this->description = 'Import "Seminars" taxonomy from CSV file';
    $this->dependencies = array(
//      OSHA_MIGRATION_TAXONOMY_TAGS,
      OSHA_MIGRATION_TAXONOMY_THESAURUS,
    );

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $data_path = osha_migration_get_data_dir();
    $source_file = MigrationUtil::getSourceFile($arguments);
    $this->source = new MigrateSourceList(
      new SeminarsListCSV($source_file),
      new SeminarsItemCSV(),
      $this->fields()
    );

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 200,
          'not null' => TRUE,
          'description' => 'Item code',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $node_options = MigrateDestinationNode::options('en', 'full_html');
    $this->destination = new MigrateDestinationNode(OSHA_SEMINAR_CONTENT_TYPE_SEMINAR, $node_options);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_tags', 'subject');
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_thesaurus', 'multilingual_thesaurus');
    $this->addFieldMapping('field_thesaurus:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_publication_date', 'publication_date');
    $this->addFieldMapping('field_archived', 'archived');
    $this->addFieldMapping('field_expiration_date', 'expiration_date');

    $this->addFieldMapping('field_related_resources', 'files');
    $this->addFieldMapping('field_related_resources:file_class')->defaultValue('OSHAMigrateFileUri');
    $this->addFieldMapping('field_related_resources:description', 'file_descriptions');
    $this->addFieldmapping('field_related_resources:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('field_related_resources:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_related_resources:source_dir')->defaultValue($data_path . '/export/');
    $this->addFieldMapping('field_related_resources:destination_file', OSHA_MIGRATION_REPLACED_PATH_PREFIX . 'files');
    $this->addFieldMapping('field_related_resources:multilingual')->defaultValue(TRUE);
    $this->addFieldMapping('field_seminar_start_date', 'startDate');
    $this->addFieldMapping('field_seminar_end_date', 'endDate');
    $this->addFieldMapping('field_seminar_location', 'location');

    $this->addFieldMapping('body', 'description');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('created', 'creation_date');
    $this->addFieldMapping('changed', 'modification_date');
    $this->addFieldMapping('uid')->defaultValue(1);

    $this->addUnmigratedSources(array(
      'path',
      'language',
      'workflow_state',
      'creator',
      'summary',
      'attendees',
      'country',
      'contactName',
      'contactPhone',
      'contactEmail',
      'conclusions',
      'dateToBeConfirmed',
      'eventUrl',
      'furtherActions',
      'showRosterHour',
      'logo'
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
    return OSHA_MIGRATION_CONTENT_TYPE_SEMINAR;
  }

  /**
   * Prepare raw data pulled from source.
   *
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    if (MigrationUtil::entityRowValidator($row, $this) === FALSE) {
      return FALSE;
    }

    //format date according to UTC timezone
    $row->publication_date = MigrationUtil::getUTCTimestamp($row->publication_date);
    $row->expiration_date = MigrationUtil::getUTCTimestamp($row->expiration_date);
    $row->startDate = MigrationUtil::getUTCTimestamp($row->startDate);
    $row->endDate = MigrationUtil::getUTCTimestamp($row->endDate);


    $row->language = 'en';
    $tags = $row->subject . ', ' . $row->subcategory;
    $row->subject = MigrationUtil::decodeTagsTerms($tags);
    if (!empty($row->multilingual_thesaurus)) {
      $terms = explode(',', $row->multilingual_thesaurus);
      $row->multilingual_thesaurus = MigrationUtil::findTidByTaxonomyField(
        $terms,
        'field_thesaurus_code',
        OSHA_TAXONOMIES_THESAURUS
      );
    }
    else {
      $row->multilingual_thesaurus = NULL;
    }

    MigrationUtil::cleanMigratedFileField($row, 'files', 'public://seminars/documents');

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
    $mlid = db_query("SELECT mlid FROM {menu_links} WHERE menu_name = 'main-menu' AND link_title = 'Seminar reports'")->fetchField();
    if (!empty($mlid)) {
        $entity->workbench_access = array($mlid, $mlid);
    }

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
        $entity->body[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->description[$language]);
        $entity->body[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      /*
      if (!empty($row->summary[$language])) {
        $entity->field_summary[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->summary[$language]);
        $entity->field_summary[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      */
      if (!empty($row->location[$language])) {
        $entity->field_seminar_location[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->location[$language]);
        $entity->field_seminar_location[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      /*
      if (!empty($row->attendees[$language])) {
        $entity->field_seminar_attendees[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->attendees[$language]);
        $entity->field_seminar_attendees[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      if (!empty($row->eventUrl[$language])) {
        $entity->field_seminar_event_url[$language][0]['url'] = $row->eventUrl[$language];
        $has_translation = TRUE;
      }
      if (!empty($row->conclusions[$language])) {
        $entity->field_seminar_conclusions[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->conclusions[$language]);
        $entity->field_seminar_conclusions[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      if (!empty($row->furtherActions[$language])) {
        $entity->field_seminar_further_actions[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->furtherActions[$language]);
        $entity->field_seminar_further_actions[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      */

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
    if (preg_match(self::PATH_PATTERN, $row->id, $matches)) {
      $tmp_path = $row->path;
      $languages = array_keys($entity->translations->data);
      foreach($languages as $language){
        $row->path[$language] = 'tools-and-publications/seminars/' . $matches[1];
      }
      MigrationUtil::createAliases($entity, $row, 'node', 'nid');
      $row->path = $tmp_path;

      // create redirect
      MigrationUtil::createRedirects($entity, $row->id);
      parent::createRedirectsFromAliases($entity, $row);
    }
    else {
      // Call MigrationUtil::createAliases
      parent::complete($entity, $row);
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
      'creator' => 'Author user id from the old website',
      'title' => '',
      'summary' => '',
      'description' => 'Body of the seminar',
      'logo' => 'Path to image file',
      'subject' => 'Categories/Tags',
      'subcategory' => 'Merged into categories',
      'multilingual_thesaurus' => '',
      'startDate' => '',
      'endDate' => '',
      'dateToBeConfirmed' => '',
      'location' => '',
      'attendees' => '',
      'eventUrl' => '',
      'contactName' => '',
      'contactEmail' => '',
      'contactPhone' => '',
      'conclusions' => '',
      'furtherActions' => '',
      'showRosterHour' => '',
      'files' => '',
      'archived' => '',
      'expiration_date' => '',
    );
  }
}

class SeminarsListCSV extends MigrateList {
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
    if(empty($fields)) {
      return;
    }
    $work_flow_key = array_search('workflow_state', $fields);

    self::$data = array();

    while (($raw_data = fgetcsv($handle, NULL, ';')) !== FALSE) {
      $path = MigrationUtil::getIDFromSourceRow($raw_data);
      $language = !empty($raw_data[1]) ? $raw_data[1] : 'en';
      $path_parts = explode('/', $path);

      self::$data[$path]['id'] = $path;
      // Assign the workflow state of the row from english entry.
      if ($language == 'en') {
        self::$data[$path]['workflow_state'] = $raw_data[$work_flow_key];
      }

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

          case 'aliases':
          case 'description':
            self::$data[$path][$field][$language] = $raw_data[$key];
            break;

          case 'files':
            $files_with_description = array_map('trim', explode(",", $raw_data[$key]));
            $files = array();
            $descriptions = array();
            foreach ($files_with_description as $file_with_desc) {
              if (empty($file_with_desc)) {
                continue;
              }
              $details = array_map('trim', explode("|", $file_with_desc));
              if (count($details) < 2) {
                $files[] = $details[0];
                $descriptions[] = '';
              }
              elseif (count($details) == 2) {
                $files[] = $details[1];
                $descriptions[] = $details[0];
              }
              else {
                drupal_set_message(
                  t('Please check that the files for @path have at most 2 elements splited by "|")',
                    array('@input' => $path)
                  ),
                  'warning'
                );
                continue;
              }
            }
            self::$data[$path][$field][$language] = $files;
            self::$data[$path]['file_descriptions'][$language] = $descriptions;
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

class SeminarsItemCSV extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (array_key_exists($item_id, SeminarsListCSV::$data)) {
      return (object) SeminarsListCSV::$data[$item_id];
    }
    return NULL;
  }
}