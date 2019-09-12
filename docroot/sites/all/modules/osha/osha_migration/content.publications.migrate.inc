<?php

/**
 * Class OshaMigratePublications migrates publication data
 */
class OshaMigratePublications extends OSHADynamicMigration {

  /*path pattern*/
  const PATH_PATTERN = '/publications\/([\w\d\.\-_\/]+)/';

  public $migrateMapFiles;

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {
    parent::__construct(MigrateGroup::getInstance('OSHA Content types'));
    $this->description = 'Import "Publications" taxonomy from CSV file';
    $this->dependencies = array(
//      OSHA_MIGRATION_TAXONOMY_TAGS,
      OSHA_MIGRATION_TAXONOMY_THESAURUS,
      OSHA_MIGRATION_TAXONOMY_NACE_CODES,
//      OSHA_MIGRATION_TAXONOMY_PUBLICATION_TYPES,
      OSHA_MIGRATION_FILES,
    );

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $data_export_path = osha_migration_get_data_dir(OSHA_MIGRATION_EXPORT_DIRECTORY);
    $source_file = MigrationUtil::getSourceFile($arguments);

    $this->source = new MigrateSourceList(
      new PublicationMigrateList($source_file),
      new PublicationMigrateItem(),
      array(
        'id' => 'Unique entity path, language independent',
        'path' => 'URL pattern without language',
        'creation_date' => 'Node creation date',
        'modification_date' => 'Last modification date',
        'publication_date' => 'Node publication date',
        'title' => 'Node title',
        'description' => 'Node body',
        'author' => 'Publication author',
        'order_id' => 'Publication Order ID',
        'cover_image' => 'Publication cover image',
        'subject' => 'Item tags',
        'file' => 'Publication document file',
        'relatedItems' => 'Is broken into related_publications and related_resources',
        'related_publications' => 'Comes from relatedItems - Related publications',
        'related_resources' => 'Comes from relatedItems - Files with extensions',
        'multilingual_thesaurus' => 'Item Tesaurus tags merged into tags',
        'nace' => 'Item NACE Codes',
        'publication_type' => 'Publication type taxonomy',
        'archived' => '',
        'expiration_date' => '',
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
    $this->destination = new MigrateDestinationNode(OSHA_PUBLICATION_CONTENT_TYPE_PUBLICATION, $node_options);

    $this->addFieldMapping('field_tags', 'subject');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_publication_bookshop_id', 'order_id');
    $this->addFieldMapping('field_thesaurus', 'multilingual_thesaurus');
    $this->addFieldMapping('field_thesaurus:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_nace_codes', 'nace');
    $this->addFieldMapping('field_nace_codes:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_publication_type', 'publication_type');
    $this->addFieldMapping('field_publication_type:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_author', 'author');
    $this->addFieldMapping('field_publication_date', 'publication_date');
    $this->addFieldMapping('field_archived', 'archived');
    $this->addFieldMapping('field_expiration_date', 'expiration_date');

//    $this->addFieldMapping('field_cover_image', 'cover_image');
//    $this->addFieldMapping('field_cover_image:source_dir')->defaultValue($data_export_path . DIRECTORY_SEPARATOR);
//    $this->addFieldMapping('field_cover_image:destination_file', 'cover_image');
//    $this->addFieldMapping('field_cover_image:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
//    $this->addFieldMapping('field_cover_image:multilingual')->defaultValue(TRUE);

    $this->addFieldMapping('field_file', 'file');
    $this->addFieldMapping('field_file:source_dir')->defaultValue($data_export_path . DIRECTORY_SEPARATOR);
    $this->addFieldMapping('field_file:destination_file', 'replaced_file');
    $this->addFieldMapping('field_file:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_file:multilingual')->defaultValue(TRUE);

    $this->addFieldMapping('field_related_publications', 'related_publications');
    $this->addFieldMapping('body', 'description');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('created', 'creation_date');
    $this->addFieldMapping('changed', 'modification_date');
    $this->addFieldMapping('uid')->defaultValue(1);

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
      'field_cover_image',
      'field_nace_codes:create_term',
      'field_nace_codes:ignore_case',
      'field_tags:create_term',
      'field_tags:ignore_case',
      'field_thesaurus:create_term',
      'field_thesaurus:ignore_case',
      'field_author:language',
      'field_cover_image:alt',
      'field_cover_image:title',
      'field_publication_date:timezone',
      'field_publication_date:rrule',
      'field_publication_date:to',
      'field_publication_type:create_term',
      'field_publication_type:ignore_case',
      'comment',
    ));

    $this->addUnmigratedSources(array(
      'path'
    ));

    $this->migrateMapFiles = db_select('migrate_map_files', 'f')
      ->fields('f', array('sourceid1', 'destid1'))
      ->execute()->fetchAllKeyed(0);
  }

  /**
   * {@inheritdoc}
   */
  protected function generateMachineName() {
    return OSHA_MIGRATION_CONTENT_TYPE_PUBLICATION;
  }

  /**
   * Handle migration of publication_type field.
   */
  protected function handlePublicationType($row) {
    if (!empty($row->publication_type)) {
      $types = MigrationUtil::findTidByTaxonomyField(
        array($row->publication_type),
        'field_publication_type_code',
        OSHA_TAXONOMIES_PUBLICATION_TYPES
      );
      if (!empty($types)) {
        return $types[0];
      }
      else {
        drupal_set_message(
          sprintf('Cannot decode publication type %s', $row->publication_type),
          'warning'
        );
      }
    }
    return NULL;
  }

  /**
   * Prepares the source row before migration.
   *
   * @param object $row
   *   One source $row as returned by getItem
   *
   * @return bool
   *   TRUE if row is valid
   */
  public function prepareRow($row) {
    if (MigrationUtil::entityRowValidator($row, $this) === FALSE) {
      return FALSE;
    }

    //format date according to UTC timezone
    $row->publication_date = MigrationUtil::getUTCTimestamp($row->publication_date);
    $row->expiration_date = MigrationUtil::getUTCTimestamp($row->expiration_date);

    $row->language = 'en';
    $tags = $row->subject . ',' . $row->subcategory;
    $row->subject = MigrationUtil::decodeTagsTerms($tags, 'field_tags_code', TRUE);
    $row->publication_type = $this->handlePublicationType($row);
    $row->multilingual_thesaurus = MigrationUtil::findTidByTaxonomyField(
      explode(',', $row->multilingual_thesaurus),
      'field_thesaurus_code',
      OSHA_TAXONOMIES_THESAURUS
    );
    if (!empty($row->nace) || $row->nace == '0') {
      $row->nace = explode(',', $row->nace);
      $row->nace = MigrationUtil::findTidByTaxonomyField(
        $row->nace,
        'field_nace_code',
        OSHA_TAXONOMIES_NACE_CODES
      );
    }

    $row->related_publications = array();
    if (!empty($row->related_publications_path)) {
      foreach ($row->related_publications_path as $path) {
        $related_item_nid = $this->getPublicationNid($path);
        if (empty($related_item_nid)) {
          $related_item_nid = $this->handleSourceMigration($this->generateMachineName(), $path);
        }
        if (!empty($related_item_nid)) {
          $row->related_publications[] = $related_item_nid;
        }
        else {
          $this->saveMessage("Failed to migrate related publication: {$path}", MigrationBase::MESSAGE_WARNING);
        }
      }
    }
    if (!empty($row->related_resources)) {
      $files = array();
      foreach ($row->related_resources as $path) {
        if (!empty($this->migrateMapFiles[$path])) {
          $files[] = $this->migrateMapFiles[$path];
        }
        else {
          $existing_file = file_load_multiple(array(), array('uri' => $path));
          if (!empty($existing_file)) {
            $files[] = current($existing_file)->fid;
          }
          else {
            $this->saveMessage("Could not find publication related imported file: {$path}", MigrationBase::MESSAGE_WARNING);
          }
        }
      }
      $row->related_resources = $files;
    }

    MigrationUtil::cleanMigratedFileField($row, 'file', 'public://publications/documents');
//    MigrationUtil::cleanMigratedFileField($row, 'cover_image', 'public://publications/cover_images');
    //MigrationUtil::cleanMigratedFileField($row, 'related_resources', 'public://publications/related_resources');
    return TRUE;
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
    $node = new stdClass();
    $node->language = 'en';
    $node->title_field['en'][0]['value'] = t('Stub for @code', array('@code' => $source[0]));
    $node->type = OSHA_PUBLICATION_CONTENT_TYPE_PUBLICATION;
    $node->uid = 1;
    $node->path['pathauto'] = 0;
    node_save($node);

    return array($node->nid);
  }

  /**
   * Look for related publication in the current migration map.
   *
   * @param string $source_id
   *   Source item code
   *
   * @return array
   *   Target publication nid
   */
  private static function getPublicationNid($source_id) {
    $result = db_query('
      SELECT m.destid1
      FROM {migrate_map_publication} m
      WHERE m.sourceid1 = :source',
      array(':source' => $source_id));
    foreach ($result as $r) {
      return $r->destid1;
    }
    return NULL;
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
    $mlid = db_query("SELECT mlid FROM {menu_links} WHERE menu_name = 'main-menu' AND link_title = 'Publications'")->fetchField();
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
        $has_translation = TRUE;
      }
      if (!empty($row->order_id[$language])) {
        $entity->field_publication_bookshop_id[$language][0]['value'] = $row->order_id[$language];
      }
      if ($has_translation) {
        MigrationUtil::setTranslation($translation_handler, $entity, $row, $language);
      }
    }
    if (!empty($row->related_resources)) {
      foreach ($row->related_resources as $fid) {
        $file = file_load($fid);
        if (!empty($file)) {
          if (!empty($file->field_language[LANGUAGE_NONE][0]['value'])) {
            $file_lang = $file->field_language[LANGUAGE_NONE][0]['value'];
          }
          else {
            $file_lang = 'en';
          }
          $entity->field_publication_related_res[$file_lang][] = array(
            'fid' => $file->fid,
            'display' => 1,
          );
        }
        else {
          drupal_set_message(
            sprintf('Could not find publication related migrated file fid %s', $fid),
            'warning'
          );
        }
      }
    }
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
    if (preg_match(self::PATH_PATTERN, $row->id, $matches)) {
      $tmp_path = $row->path;
      $languages = array_keys($entity->translations->data);
      foreach($languages as $language){
        $row->path[$language] = 'publications/' . $matches[1];
      }
      MigrationUtil::createAliases($entity, $row, 'node', 'nid');
      $row->path = $tmp_path;

      // create redirect
      MigrationUtil::createRedirects($entity, $row->id);
      self::createRedirectsFromAliases($entity, $row);
    }else {
      // Call MigrationUtil::createAliases
      parent::complete($entity, $row);
    }
  }
}

/**
 * Class PublicationMigrateList
 */
class PublicationMigrateList extends MigrateList {

  private $fileURL;
  protected $multilingualFields;
  public static $data;

  /**
   * {@inheritdoc}
   *
   * @param string $file_url
   *   The location of the file with source raw data
   */
  public function __construct($file_url) {
    parent::__construct();
    $this->fileURL = $file_url;
    if (!file_exists($this->fileURL)) {
      Migration::displayMessage(
        t(
          'Failed to load data file from !fileUrl:',
          array('!fileUrl' => $this->fileURL)
        )
      );
    }
    $this->parseSourceFile();
  }

  /**
   * {@inheritdoc}
   */
  public function __toString() {
    return $this->fileURL;
  }

  /**
   * Parse the source file and populate the local cache.
   */
  protected function parseSourceFile() {
    if (!is_readable($this->fileURL)) {
      return array();
    }
    $handle = fopen($this->fileURL, 'r');
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
      // Skip the private translations.
      if (!in_array($raw_data[$work_flow_key],
        array('published', 'checked', 'to_amend'))) {
        continue;
      }

      self::$data[$path]['publication_type'] = !empty($path_parts[1]) ? $path_parts[1] : NULL;
      foreach ($fields as $key => $field) {
        switch ($field) {
          case 'title':
            if ($language == 'en') {
              self::$data[$path]['title'] = MigrationUtil::decodeHTMLText($raw_data[$key]);
            }
            self::$data[$path]['title_field'][$language] = $raw_data[$key];
            break;

          case 'description':
          case 'aliases':
          case 'order_id':
          case 'file':
          case 'cover_image':
            self::$data[$path][$field][$language] = $raw_data[$key];
            break;

          case 'path':
            $path_language = explode('/', $raw_data[$key], 3);
            self::$data[$path][$field][$language] = $path_language[2];
            continue;

          case 'relatedItems':
            /* Related files and publications */
            $items = MigrationUtil::parseRelatedItemsString($raw_data[$key], 'publications');
            if (!empty($items['items'])) {
              self::$data[$path]['related_publications_path'] = $items['items'];
            }
            else {
              self::$data[$path]['related_publications_path'] = array();
            }
            if (!empty($items['files'])) {
              self::$data[$path]['related_resources'] = $items['files'];
            }
            else {
              self::$data[$path]['related_resources'] = array();
            }
            if (isset($items['paths'])) {
                self::$data[$path]['paths'] = $items['paths'];
            }
            break;

          default:
            if ($language == 'en') {
              self::$data[$path][$field] = $raw_data[$key];
            }
        }
      }
    }
    foreach (self::$data as $path => $row) {
      if (!isset($row['related_publications_path'])) {
        continue;
      }
      foreach ($row['related_publications_path'] as $key => $publication) {
        if (!isset(self::$data[$publication])) {
          self::$data[$path]['related_resources'][] =  self::$data[$path]['paths'][$publication];
          unset(self::$data[$path]['related_publications_path'][$key]);
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
   * Counts the number of source rows.
   *
   * @return int
   *   Number of rows to be migrated from source
   */
  public function computeCount() {
    return count(self::$data);
  }
}

/**
 * Class PublicationMigrateItem
 */
class PublicationMigrateItem extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (!empty(PublicationMigrateList::$data[$item_id])) {
      return (object) PublicationMigrateList::$data[$item_id];
    }
    return NULL;
  }
}
