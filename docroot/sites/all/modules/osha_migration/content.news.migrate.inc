<?php

/**
 * Class MigrateOshaNews migrates news.txt contents. The data
 * is stored inside the <em>News</em> content type.
 */
class MigrateOshaNews extends DynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Content types'));
    $this->description = 'Import "News" contents from CSV file';

    $this->dependencies = array(OSHA_MIGRATION_TAXONOMY_THESAURUS, OSHA_MIGRATION_TAXONOMY_TAGS);

    $source_file = MigrationUtil::getSourceFile($arguments);
    $this->source = new MigrateSourceList(
      new NewsContentListCSV($source_file, array('title', 'description', 'text')),
      new NewsContentItemCSV(),
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

    $node_options = MigrateDestinationNode::options('en', 'text');
    $this->destination = new MigrateDestinationNode(OSHA_NEWS_CONTENT_TYPE_NEWS, $node_options);

    $this->addFieldMapping('field_news_image', 'image');
    $this->addFieldMapping('field_news_image:title', 'imageCaption');
    $this->addFieldMapping('field_news_image:file_replace')->defaultValue(MigrateFile::FILE_EXISTS_REUSE);
    $this->addFieldmapping('field_news_image:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('field_news_image:source_dir')->defaultValue(osha_migration_get_data_dir() . '/export/');

    $this->addFieldMapping('field_tags', 'subject');
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_thesaurus', 'multilingual_thesaurus');
    $this->addFieldMapping('field_thesaurus:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_news_publication_date', 'publication_date');

    $this->addFieldMapping('path', 'id');
    $this->addFieldMapping('created', 'creation_date');
    $this->addFieldMapping('changed', 'modification_date');

    $this->addUnmigratedSources(array(
      'path',
      'language',
      'workflow_state',
      'creator',
      'country',
      'nace',
    ));

    $this->addUnmigratedDestinations(array(
      'uid',
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
      'field_news_image:file_class',
      'field_news_image:language',
      'field_news_image:destination_dir',
      'field_news_image:destination_file',
      'field_news_image:alt',
      'field_news_publication_date:timezone',
      'field_news_publication_date:rrule',
      'field_news_publication_date:to',
      'field_news_summary',
      'field_news_summary:format',
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
    return OSHA_MIGRATION_CONTENT_TYPE_NEWS;
  }

  /**
   * Prepare raw data pulled from source.
   *
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    $row->language = 'en';
    $tags = $row->subject . ', ' . $row->subcategory;
    $row->subject = MigrationUtil::decodeTagsTerms($tags);
    $row->multilingual_thesaurus = MigrationUtil::findTidByTaxonomyField(
      OSHA_TAXONOMIES_THESAURUS,
      'field_thesaurus_code',
      explode(',', $row->multilingual_thesaurus)
    );
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
    $entity->title = $row->title['en'];
    foreach ($languages as $language) {
      if (!empty($row->title[$language])) {
        $entity->title_field[$language][0]['value'] = $row->title[$language];
        $entity->field_news_summary[$language][0]['value'] = str_replace('<@#&>', '"', $row->description[$language]);
        $entity->field_news_summary[$language][0]['format'] = 'full_html';
        $entity->body[$language][0]['value'] = str_replace('<@#&>', '"', $row->text[$language]);
        $entity->body[$language][0]['format'] = 'full_html';
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
      'text' => 'Body of the news',
      'image' => 'Path to image file',
      'imageCaption' => 'Image tooltip',
      'subject' => 'Categories/Tags',
      'country' => '',
      'subcategory' => 'Merged into categories',
      'multilingual_thesaurus' => '',
      'nace' => 'Nace codes taxonomy',
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

class NewsContentListCSV extends MigrateList {
  protected $file = '';
  protected $multilingualFields;
  public static $data = array();

  /**
   * {@inheritdoc}
   */
  public function __construct($file, $multilingual_fields = array()) {
    parent::__construct();
    $this->file = $file;
    $this->multilingualFields = $multilingual_fields;
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
  protected function parseMultilingualCSV() {
    $handle = fopen($this->file, 'r');
    $fields = $data = fgetcsv($handle, 1000, ';');
    $final = array();
    while (($data = fgetcsv($handle, 100000, ';')) !== FALSE) {
      $language = $data[1];
      $path = $data[2];
      if (empty($path)) {
        $path = $data[0];
      }
      $path = preg_replace('/^\/en\//', '', $path);
      foreach ($fields as $key => $field) {
        if (in_array($field, $this->multilingualFields)) {
          $final[$path][$field][$language] = $data[$key];
          continue;
        }
        $final[$path][$field] = $data[$key];
      }
      $final[$path]['id'] = $path;
    }

    foreach ($final as $id => $row) {
      if (isset($row['title']['en'])) {
        self::$data[$id] = $final[$id];
      }
      else {
        drupal_set_message(
          sprintf('No english translation for row:%s', $id),
          'warning'
        );
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getIdList() {
    if (empty(self::$data)) {
      $this->parseMultilingualCSV();
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

class NewsContentItemCSV extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (array_key_exists($item_id, NewsContentListCSV::$data)) {
      return (object) NewsContentListCSV::$data[$item_id];
    }
    return NULL;
  }
}
