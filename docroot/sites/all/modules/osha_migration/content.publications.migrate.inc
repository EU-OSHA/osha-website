<?php

/**
 * Class OshaMigratePublications migrates publication data
 */
class OshaMigratePublications extends DynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments = array()) {
    parent::__construct(MigrateGroup::getInstance('OSHA Content types'));
    $this->description = 'Import "Publications" taxonomy from CSV file';
    $this->dependencies = array(
      OSHA_MIGRATION_TAXONOMY_TAGS,
      OSHA_MIGRATION_TAXONOMY_THESAURUS,
      OSHA_MIGRATION_TAXONOMY_NACE_CODES,
      OSHA_MIGRATION_TAXONOMY_PUBLICATION_TYPES,
    );
    $data_path = osha_migration_get_data_dir();
    $source_file = MigrationUtil::getSourceFile($arguments);

    $this->source = new MigrateSourceList(
      new PublicationMigrateList($source_file),
      new PublicationMigrateItem(),
      array(
        'id' => 'Unique entity path, language independent',
        'creation_date' => 'Node creation date',
        'modification_date' => 'Last modification date',
        'publication_date' => 'Node publication date',
        'title' => 'Node title',
        'description' => 'Node body',
        'author' => 'Publication author',
        'order_id' => 'Publication Order ID',
        'subject' => 'Item tags',
        'file' => 'Publication document file',
        'relatedItems' => 'Related publications',
        'related_resources' => 'Comes from relatedItems - Files with extensions',
        'multilingual_thesaurus' => 'Item Tesaurus tags merged into tags',
        'nace' => 'Item NACE Codes',
        'publication_type' => 'Publication type taxonomy',
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
    $this->destination = new MigrateDestinationNode(OSHA_PUBLICATION_CONTENT_TYPE_PUBLICATION);

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
    $this->addFieldMapping('field_publication_author', 'author');
    $this->addFieldMapping('field_publication_date', 'publication_date');

    $this->addFieldMapping('field_publication_file', 'file');
    $this->addFieldMapping('field_publication_file:source_dir')->defaultValue($data_path . '/export/');
    $this->addFieldMapping('field_publication_file:destination_file', 'file');
    $this->addFieldMapping('field_publication_file:file_replace')->defaultValue(FILE_EXISTS_REPLACE);

    /*
    $this->addFieldMapping('field_publication_related_res', 'related_resources');
    $this->addFieldMapping('field_publication_related_res:source_dir')->defaultValue($data_path . '/export/');
    $this->addFieldMapping('field_publication_related_res:destination_file', 'related_resources');
    $this->addFieldMapping('field_publication_related_res:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    */

    $this->addFieldMapping('body', 'description');
    $this->addFieldMapping('body:format')->defaultValue('plain_text');
    $this->addFieldMapping('created', 'creation_date');
    $this->addFieldMapping('changed', 'modification_date');
    $this->addFieldMapping('uid')->defaultValue(1);
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
  protected static function handlePublicationType($row) {
    $migration = Migration::currentMigration();
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
        $migration->saveMessage("Cannot decode publication type with identifier: {$row->publication_type}", MigrationBase::MESSAGE_WARNING);
        $row->publication_type = NULL;
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
    $migration = Migration::currentMigration();
    if (empty($row->title)) {
      $migration->saveMessage("Skipping record without english title {$row->id}", MigrationBase::MESSAGE_WARNING);
      return FALSE;
    }
    $row->language = 'en';
    $tags = $row->subject . ',' . $row->subcategory;
    $row->subject = MigrationUtil::decodeTagsTerms($tags);
    $row->publication_type = self::handlePublicationType($row);
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
        OSHA_TAXONOMIES_NACE_CODES);
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
          $migration->saveMessage("Failed to migrate related publication: {$path}", MigrationBase::MESSAGE_WARNING);
        }
      }
    }
    MigrationUtil::cleanMigratedFileField($row, 'file', 'public://publications/documents');
    // MigrationUtil::cleanMigratedFileField($row, 'related_resources', 'public://publications/related_resources');
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
    $migration = Migration::currentMigration();
    $languages = array_keys(language_list());
    $entity_type = $migration->getDestination()->getEntityType();
    $translation_handler = entity_translation_get_handler($entity_type, $entity);

    $entity->translations = $translation_handler->getTranslations();
    foreach ($languages as $language) {
      if (!empty($row->title_field[$language])) {
        $entity->title_field[$language][0]['value'] = $row->title_field[$language];
      }
      if (!empty($row->order_id[$language])) {
        $entity->field_publication_bookshop_id[$language][0]['value'] = $row->order_id[$language];
      }
      if (!empty($row->field_publication_file[$language]) && $language != 'en') {
        $entity->field_publication_file[$language][0]['value'] = $row->file[$language];
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
   * Sets the node aliases after the migration, nid is available.
   *
   * @param object $entity
   *   Entity to be saved
   * @param object $row
   *   Source row
   */
  public function complete($entity, $row) {
    $languages = array_keys($row->path);
    foreach ($languages as $language) {
      $args = array(
        'source' => 'node/' . $entity->nid,
        'alias' => $row->id,
        'language' => $language,
      );
      path_save($args);
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
   * Retrieve unique ID from path. Removes language.
   */
  protected static function getIDFromSourceRow($row) {
    $url = !empty($row[2]) ? $row[2] : $row[0];
    return preg_replace('/^\/en\//', '', $url);
  }

  /**
   * Parse the source file and populate the local cache.
   */
  protected function parseSourceFile() {
    $handle = fopen($this->fileURL, 'r');
    $fields = $data = fgetcsv($handle, NULL, ';');

    $final = array();
    while (($data = fgetcsv($handle, NULL, ';')) !== FALSE) {
      $path = self::getIDFromSourceRow($data);
      $language = !empty($data[1]) ? $data[1] : 'en';
      $path_parts = explode('/', $path);

      $final[$path]['id'] = $path;
      $final[$path]['publication_type'] = !empty($path_parts[1]) ? $path_parts[1] : NULL;
      foreach ($fields as $key => $field) {
        switch ($field) {
          case 'title':
            if ($language == 'en') {
              $final[$path]['title'] = $data[$key];
            }
            $final[$path]['title_field'][$language] = $data[$key];
            break;

          case 'description':
          case 'order_id':
          case 'file':
          case 'cover_image':
            $final[$path][$field][$language] = $data[$key];
            break;

          case 'path':
            $path_language = explode('/', $data[$key], 3);
            $final[$path][$field][$language] = $path_language[2];
            continue;

          case 'relatedItems':
            /* Related files and publications */
            $items = MigrationUtil::parseRelatedItemsString($data[$key]);
            if (!empty($items['items'])) {
              $final[$path]['related_publications_path'] = $items['items'];
            }
            if (!empty($items['files'])) {
              /* @todo: cannot migrate this multi-valued field
               $final[$path]['related_resources'] = $items['files'];
               */
            }
            break;

          default:
            $final[$path][$field] = $data[$key];
        }
      }
    }
    self::$data = $final;
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
