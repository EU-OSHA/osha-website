<?php

/**
 * Class MigrateOshaCaseStudy migrates case_studies.txt contents. The data
 * is stored inside the <em>CaseStudy</em> content type.
 */
class MigrateOshaCaseStudy extends DynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Content types'));
    $this->description = 'Import "CaseStudy" contents from CSV file';
    $this->dependencies = array(
      OSHA_MIGRATION_TAXONOMY_TAGS,
      OSHA_MIGRATION_TAXONOMY_THESAURUS,
      OSHA_MIGRATION_TAXONOMY_NACE_CODES,
    );

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $data_path = osha_migration_get_data_dir();
    $source_file = MigrationUtil::getSourceFile($arguments);
    $this->source = new MigrateSourceList(
      new CaseStudyContentListCSV($source_file),
      new CaseStudyContentItemCSV(),
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
    $this->destination = new MigrateDestinationNode(OSHA_CASE_STUDY_CONTENT_TYPE_CASE_STUDY, $node_options);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_case_study_file', 'files');
    $this->addFieldMapping('field_case_study_file:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldmapping('field_case_study_file:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('field_case_study_file:source_dir')->defaultValue($data_path . '/export/');
    $this->addFieldMapping('field_case_study_file:destination_file', 'files');
    $this->addFieldMapping('field_case_study_file:multilingual')->defaultValue(TRUE);

    $this->addFieldMapping('field_tags', 'subject');
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_thesaurus', 'multilingual_thesaurus');
    $this->addFieldMapping('field_thesaurus:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_nace_codes', 'nace');
    $this->addFieldMapping('field_nace_codes:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_publication_date', 'publication_date');


    $this->addFieldMapping('created', 'creation_date');
    $this->addFieldMapping('changed', 'modification_date');
    $this->addFieldMapping('uid')->defaultValue(1);

    $this->addUnmigratedSources(array(
      'path',
      'language',
      'description',
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
      'field_case_study_cover_image:file_class',
      'field_case_study_file:file_class',
      'field_case_study_file:language',
      'field_case_study_file:destination_dir',
      'field_case_study_file:description',
      'field_case_study_file:display',
      'field_nace_codes:create_term',
      'field_nace_codes:ignore_case',
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
    return OSHA_MIGRATION_CONTENT_TYPE_CASE_STUDY;
  }

  /**
   * Executes before Import.
   */
  public function preImport() {
    MigrationUtil::activateOshaFilesHandler();
  }

  /**
   * Executes after import.
   */
  public function postImport() {
    MigrationUtil::deactivateOshaFilesHandler();
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
    $tags = $row->subject . ',' . $row->subcategory;
    $row->subject = MigrationUtil::decodeTagsTerms($tags);
    $row->multilingual_thesaurus = MigrationUtil::findTidByTaxonomyField(
      explode(',', $row->multilingual_thesaurus),
      'field_thesaurus_code',
      OSHA_TAXONOMIES_THESAURUS
    );

    if (!empty($row->nace)) {
      $row->nace = explode(',', $row->nace);
      $row->nace = MigrationUtil::findTidByTaxonomyField(
        $row->nace,
        'field_nace_code',
        OSHA_TAXONOMIES_NACE_CODES
      );
    }

    if (!empty($row->files)) {
      foreach ($row->files as $lang => $files) {
        $exp = explode(',', $files);
        if (count($exp) > 1) {
          $exp = array_map('trim', $exp);
          $row->files[$lang] = $exp;
        }
      }
    }
    MigrationUtil::cleanMigratedFileField($row, 'files', 'public://case_study/documents');


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
      if (!empty($row->text[$language])) {
        $entity->body[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->text[$language]);
        $entity->body[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      /* Don't translate en (default) */
      if ($has_translation && $language != $row->language && !isset($entity->translations->data[$language])) {
        $translation_handler->setTranslation(array(
          'translate' => 0, 'status' => 1, 'uid' => 1,
          'language' => $language,
          'source' => $row->language,
        ));
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
      'description' => '',
      'text' => 'Body of the case study',
      'subject' => 'Categories/Tags',
      'country' => '',
      'subcategory' => 'Merged into categories',
      'multilingual_thesaurus' => '',
      'nace' => 'Nace codes taxonomy',
      'files' => 'Case study files',
    );
  }

  /**
   * Sets the node aliases after the migration, nid is available.
   *
   * @param object $entity
   *   Entity to be saved
   * @param object $row
   *   Source row
   */
  public function complete($entity, $row) {
    $languages = array_keys(language_list());
    foreach ($languages as $language) {
      /* Same alias for all languages (see mappings) */
      $args = array(
        'source' => 'node/' . $entity->nid,
        'alias' => $row->id,
        'language' => $language,
      );
      path_save($args);
    }
  }
}

class CaseStudyContentListCSV extends MigrateList {
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
    while (($raw_data = fgetcsv($handle, NULL, ';')) !== FALSE) {
      $language = !empty($raw_data[1]) ? $raw_data[1] : 'en';
      $path = substr(!empty($raw_data[2]) ? $raw_data[2] : $raw_data[0], 1);
      self::$data[$path]['id'] = $path;
      foreach ($fields as $key => $field) {
        switch ($field) {
          case 'title':
            if ($language == 'en') {
              self::$data[$path]['title'] = MigrationUtil::decodeHTMLText($raw_data[$key]);
            }
            self::$data[$path]['title_field'][$language] = MigrationUtil::decodeHTMLText($raw_data[$key]);
            break;

          case 'files':
          case 'text':
            self::$data[$path][$field][$language] = $raw_data[$key];
            break;

          default:
            self::$data[$path][$field] = $raw_data[$key];
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

class CaseStudyContentItemCSV extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (array_key_exists($item_id, CaseStudyContentListCSV::$data)) {
      return (object) CaseStudyContentListCSV::$data[$item_id];
    }
    return NULL;
  }
}
