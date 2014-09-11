<?php

/**
 * Class OshaMigrateArticles migrates articles data
 */
class OshaMigrateArticles extends OSHADynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {
    parent::__construct(MigrateGroup::getInstance('OSHA Content types'));
    $this->description = 'Import "Articles" contents from CSV file';
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
      new ArticleMigrateList($source_file),
      new ArticleMigrateItem(),
      array(
        'id' => 'Unique entity path, language independent',
        'creation_date' => 'Node creation date',
        'modification_date' => 'Last modification date',
        'publication_date' => 'Node publication date',
        'title' => 'Node title',
        'description' => 'Node summary',
        'text' => 'Node content',
        'author' => 'Publication author',
        'subject' => 'Item tags',
        'relatedItems' => 'Page image',
        'multilingual_thesaurus' => 'Item Tesaurus tags merged into tags',
        'nace' => 'Item NACE Codes',
      )
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

    $node_options = MigrateDestinationNode::options('en', NULL);
    $this->destination = new MigrateDestinationNode(OSHA_ARTICLE_CONTENT_TYPE_ARTICLE, $node_options);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'text');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('field_summary', 'description');
    $this->addFieldMapping('field_image', 'relatedItems');
    $this->addFieldMapping('field_image:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldmapping('field_image:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('field_image:source_dir')->defaultValue($data_path . '/export/');
    $this->addFieldMapping('field_image:destination_file', 'relatedItems');
    $this->addFieldMapping('field_image:multilingual')->defaultValue(TRUE);

    $this->addFieldMapping('field_tags', 'subject');
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_thesaurus', 'multilingual_thesaurus');
    $this->addFieldMapping('field_thesaurus:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_nace_codes', 'nace');
    $this->addFieldMapping('field_nace_codes:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_publication_date', 'publication_date');

    $this->addFieldMapping('path', 'id');
    $this->addFieldMapping('created', 'creation_date');
    $this->addFieldMapping('changed', 'modification_date');
    $this->addFieldMapping('uid')->defaultValue(1);

    $this->addUnmigratedSources(array(
      'author'
    ));

    $this->addUnmigratedDestinations(array(
      'promote',
      'status',
      'sticky',
      'revision',
      'log',
      'language',
      'nid',
      'translate',
      'revision_uid',
      'is_new',
      'body:summary',
      'field_image:file_class',
      'field_image:title',
      'field_image:alt',
      'field_image:destination_dir',
      'field_publication_date:timezone',
      'field_publication_date:rrule',
      'field_publication_date:to',
      'field_tags:create_term',
      'field_tags:ignore_case',
      'field_thesaurus:create_term',
      'field_thesaurus:ignore_case',
      'field_nace_codes:create_term',
      'field_nace_codes:ignore_case',
      'comment',
    ));
  }

  /**
   * Migration machine name.
   *
   * {@inheritdoc}
   */
  protected function generateMachineName() {
    return OSHA_MIGRATION_CONTENT_TYPE_ARTICLE;
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
      'field_thesaurus',
      OSHA_TAXONOMIES_THESAURUS
    );
    if (!empty($row->nace)) {
      $row->nace = explode(',', $row->nace);
      $row->nace = MigrationUtil::findTidByTaxonomyField(
        $row->nace,
        'field_nace_codes',
        OSHA_TAXONOMIES_NACE_CODES
      );
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
        $entity->field_summary[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      if (!empty($row->text[$language])) {
        $entity->body[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->text[$language]);
        $entity->body[$language][0]['format'] = 'full_html';
        $has_translation = TRUE;
      }
      if (!empty($row->relatedItems[$language]) && $language != 'en') {
        $entity->field_image[$language][0]['value'] = $row->relatedItems[$language];
      }
      if ($has_translation) {
        MigrationUtil::setTranslation($translation_handler, $entity, $row, $language);
      }
    }
  }
}

class ArticleMigrateList extends MigrateList {
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
              self::$data[$path]['title'] = $raw_data[$key];
            }
            self::$data[$path]['title_field'][$language] = $raw_data[$key];
            break;

          case 'relatedItems':
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
    if (self::$data) {
      return array_keys(self::$data);
    }
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function computeCount() {
    return count(self::$data);
  }
}

class ArticleMigrateItem extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (!empty(ArticleMigrateList::$data[$item_id])) {
      return (object) ArticleMigrateList::$data[$item_id];
    }
    return NULL;
  }
}
