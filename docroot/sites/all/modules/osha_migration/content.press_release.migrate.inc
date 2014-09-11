<?php

/**
 * Class MigrateOshaNews migrates news.txt contents. The data
 * is stored inside the <em>News</em> content type.
 */
class MigrateOshaPressRelease extends OSHADynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Content types'));
    $this->description = 'Import "Press release" contents from CSV file';
    $this->dependencies = array(
      OSHA_MIGRATION_TAXONOMY_TAGS,
    );

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $data_path = osha_migration_get_data_dir();
    $source_file = MigrationUtil::getSourceFile($arguments);
    $this->source = new MigrateSourceList(
      new PressReleaseMigrateList($source_file),
      new PressReleaseMigrateItem(),
      array(
        'id' => 'Primary Key (URL pattern)',
        'path' => 'URL pattern without language',
        'language' => 'Row language',
        'workflow_state' => '',
        'creation_date' => '',
        'modification_date' => '',
        'publication_date' => '',
        'releaseDate' => '',
        'creator' => 'Author user id from the old website',
        'title' => '',
        'description' => '',
        'text' => 'Body of the news',
        'subject' => 'Categories/Tags',
        'relatedLinks' => 'The link related with the press release',
        'location' => 'Not imported',
        'country' => 'Not imported',
        'canonical' => 'The path to the press release in english',
        'releaseTiming' => '',
        'subHead' => 'Not imported',
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

    $node_options = MigrateDestinationNode::options('en', 'full_html');
    $this->destination = new MigrateDestinationNode(OSHA_PRESS_RELEASE_CONTENT_TYPE_PRESS_RELEASE, $node_options);

    $this->addFieldMapping('title', 'title');

    $this->addFieldMapping('field_tags', 'subject');
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_pr_release_date', 'releaseDate');
    $this->addFieldMapping('field_publication_date', 'publication_date');

    $this->addFieldMapping('created', 'creation_date');
    $this->addFieldMapping('changed', 'modification_date');
    $this->addFieldMapping('uid')->defaultValue(1);

    $this->addUnmigratedSources(array(
      'path',
      'language',
      'workflow_state',
      'creator',
      'country',
      'location',
      'country',
      'canonical',
      'releaseTiming',
      'subHead',
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
      'title_field',
      'body:summary',
      'field_pr_notes_to_editor',
      'field_pr_notes_to_editor:format',
      'field_summary:format',
      'field_summary',
      'field_publication_date:timezone',
      'field_publication_date:rrule',
      'field_publication_date:to',
      'field_tags:create_term',
      'field_tags:ignore_case',
      'field_thesaurus',
      'field_thesaurus:create_term',
      'field_thesaurus:source_type',
      'field_thesaurus:ignore_case',
      'field_nace_codes',
      'field_nace_codes:create_term',
      'field_nace_codes:ignore_case',
      'field_nace_codes:source_type',
      'field_pr_release_date:timezone',
      'field_pr_release_date:rrule',
      'field_pr_release_date:to',
      'field_pr_related_links:title',
      'field_pr_related_links:attributes',
      'comment',
    ));
  }

  /**
   * Migration machine name.
   *
   * {@inheritdoc}
   */
  protected function generateMachineName() {
    return OSHA_MIGRATION_CONTENT_TYPE_PRESS_RELEASE;
  }

  /**
   * Prepare raw data pulled from source.
   *
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    $row->language = 'en';
    if (MigrationUtil::entityRowValidator($row, $this) === FALSE) {
      return FALSE;
    }

    $row->subject = MigrationUtil::decodeTagsTerms($row->subject);
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
      if (!empty($row->notesToEditors[$language])) {
        $entity->field_pr_notes_to_editor[$language][0]['value'] = MigrationUtil::decodeHTMLText($row->notesToEditors[$language]);
        $entity->field_pr_notes_to_editor[$language][0]['format'] = 'full_html';
      }
      if (!empty($row->relatedLinks[$language])) {
        $entity->field_pr_related_links[$language]
          = array_map(
            function($link) {
              return array('url' => $link);
            },
            explode(",", $row->relatedLinks[$language])
          );
      }
      if ($has_translation) {
        MigrationUtil::setTranslation($translation_handler, $entity, $row, $language);
      }
    }
  }
}

class PressReleaseMigrateList extends MigrateList {

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
      $path = MigrationUtil::getIDFromSourceRow($raw_data);
      $language = !empty($raw_data[1]) ? $raw_data[1] : 'en';
      $path_parts = explode('/', $path);

      self::$data[$path]['id'] = $path;
      foreach ($fields as $key => $field) {
        switch ($field) {
          case 'title':
            if ($language == 'en') {
              self::$data[$path]['title'] = $raw_data[$key];
            }
            self::$data[$path]['title_field'][$language] = $raw_data[$key];
            break;

          case 'description':
          case 'text':
          case 'notesToEditors':
          case 'relatedLinks':
            self::$data[$path][$field][$language] = $raw_data[$key];
            break;

          case 'path':
            $path_language = explode('/', $raw_data[$key], 3);
            self::$data[$path][$field][$language] = $path_language[2];
            continue;

          default:
            self::$data[$path][$field] = $raw_data[$key];
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

class PressReleaseMigrateItem extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (array_key_exists($item_id, PressReleaseMigrateList::$data)) {
      return (object) PressReleaseMigrateList::$data[$item_id];
    }
    return NULL;
  }
}
