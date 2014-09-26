<?php

class OshaMigrateSeminars extends OSHADynamicMigration {

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

    $this->addFieldMapping('field_image', 'logo');
    $this->addFieldMapping('field_image:file_class')->defaultValue('OSHAMigrateFileUri');
    $this->addFieldmapping('field_image:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('field_image:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_image:source_dir')->defaultValue($data_path . '/export/');
    $this->addFieldMapping('field_image:destination_file', OSHA_MIGRATION_REPLACED_PATH_PREFIX . 'logo');
    $this->addFieldMapping('field_image:multilingual')->defaultValue(TRUE);

    $this->addFieldMapping('field_file', 'files');
    $this->addFieldMapping('field_file:file_class')->defaultValue('OSHAMigrateFileUri');
    $this->addFieldmapping('field_file:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('field_file:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_file:source_dir')->defaultValue($data_path . '/export/');
    $this->addFieldMapping('field_file:destination_file', OSHA_MIGRATION_REPLACED_PATH_PREFIX . 'files');
    $this->addFieldMapping('field_file:multilingual')->defaultValue(TRUE);

    $this->addFieldMapping('field_seminar_attachment', 'attachment');
    $this->addFieldMapping('field_seminar_attachment:file_class')->defaultValue('OSHAMigrateFileUri');
    $this->addFieldmapping('field_seminar_attachment:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('field_seminar_attachment:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_seminar_attachment:source_dir')->defaultValue($data_path . '/export/');
    $this->addFieldMapping('field_seminar_attachment:destination_file', OSHA_MIGRATION_REPLACED_PATH_PREFIX . 'attachment');
    $this->addFieldMapping('field_seminar_attachment:multilingual')->defaultValue(TRUE);

    $this->addFieldMapping('field_seminar_contact_name', 'contactName');
    $this->addFieldMapping('field_seminar_contact_phone', 'contactPhone');
    $this->addFieldMapping('field_seminar_contact_email', 'contactEmail');
    $this->addFieldMapping('field_seminar_start_date', 'startDate');
    $this->addFieldMapping('field_seminar_end_date', 'endDate');
    $this->addFieldMapping('field_sem_date_to_be_confirmed', 'dateToBeConfirmed');
    $this->addFieldMapping('field_seminar_show_roster_hour', 'showRosterHour');

    $this->addFieldMapping('body', 'description');
    $this->addFieldMapping('body:format')->defaultValue('plain_text');
    $this->addFieldMapping('created', 'creation_date');
    $this->addFieldMapping('changed', 'modification_date');
    $this->addFieldMapping('uid')->defaultValue(1);

    // TODO add unmigrated sources!

    // TODO add unmigrated destinations!
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

    MigrationUtil::cleanMigratedFileField($row, 'logo', 'public://seminars/logos');
    MigrationUtil::cleanMigratedFileField($row, 'attachment', 'public://seminars/documents');
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
      if (!empty($row->summary[$language])) {
        $entity->field_summary[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->summary[$language]);
        $entity->field_summary[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      if (!empty($row->location[$language])) {
        $entity->field_seminar_location[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->location[$language]);
        $entity->field_seminar_location[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
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
      'creator' => 'Author user id from the old website',
      'title' => '',
      'summary' => '',
      'description' => 'Body of the news',
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
      'attachment' => '',
      'conclusions' => '',
      'furtherActions' => '',
      'showRosterHour' => '',
      'files' => '',
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
              self::$data[$path]['title'] = $raw_data[$key];
            }
            self::$data[$path]['title_field'][$language] = $raw_data[$key];
            break;

          case 'description':
          case 'summary':
          case 'conclusions':
          case 'furtherActions':
          case 'attendees':
          case 'location':
          case 'eventUrl':
          case 'attachment':
          case 'logo':
            self::$data[$path][$field][$language] = $raw_data[$key];
            break;

          case 'files':
            self::$data[$path][$field][$language] = array_map('trim', explode(",", $raw_data[$key]));
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