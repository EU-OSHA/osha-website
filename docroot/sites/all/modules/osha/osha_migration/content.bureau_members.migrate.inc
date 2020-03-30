<?php
/**
 * Class MigrateOshaBlog migrates blog.txt contents. The data
 * is stored inside the <em>Blog</em> content type.
 */
class MigrateOshaBureauMembers extends OSHADynamicMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct(MigrateGroup::getInstance('OSHA Content types'));
    $this->description = 'Import "Bureau" contents from CSV file';

    /* Remove limits on time/memory, slower machines will fail */
    $this->timeLimit = 0;
    $this->memoryLimit = PHP_INT_MAX;

    $source_file_bureau = MigrationUtil::getSourceFileByKey($arguments, 'file_name');
    $this->source = new MigrateSourceList(
      new BoardBureauMembersListXML($source_file_bureau),
      new BoardBureauMembersItemXML(),
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

    $voc = taxonomy_vocabulary_machine_name_load('contact_type');
    $types = array('Bureau of the Governing Board');
    foreach ($types as $type) {
      $term = taxonomy_get_term_by_name($type, 'contact_type');
      if (empty($term)) {
        $term = new stdClass();
        $term->vid = $voc->vid;
        $term->name = $type;
        taxonomy_term_save($term);
      }
    }

    $node_options = MigrateDestinationNode::options('en', 'full_html');
    $this->destination = new MigrateDestinationNode('press_contact', $node_options);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_personal_title', 'field_personal_title');
    $this->addFieldMapping('title_field', 'title_field');
    $this->addFieldMapping('field_wg_role_1', 'field_wg_role_1');
    $this->addFieldMapping('field_wg_role_2', 'field_wg_role_2');
    $this->addFieldMapping('field_wg_category', 'field_wg_category');
    $this->addFieldMapping('field_contact_uuid', 'field_contact_uuid');
    $this->addFieldMapping('field_contact_type', 'field_contact_type');
    $this->addFieldMapping('uid')->defaultValue(1);

    $this->addUnmigratedSources(array(
      'path',
      'language',
      'workflow_state',
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
      //'body:summary',
      'field_image:language',
      'field_image:destination_dir',
      'field_image:title',
      'field_image:alt',
      'field_nace_codes:create_term',
      'field_nace_codes:ignore_case',
      'field_publication_date:timezone',
      'field_publication_date:rrule',
      'field_publication_date:to',
      'field_summary',
      'field_summary:format',
      'field_tags:create_term',
      'field_tags:ignore_case',
      'field_thesaurus:create_term',
      'field_thesaurus:ignore_case',
      'field_country',
      'field_zip_code',
      'field_city',
      'field_press_contact_phone',
      'field_press_contact_location',
      'field_press_contact_organization',
      'field_contact_uuid:language',
      'comment',
    ));
  }

  /**
   * Migration machine name.
   *
   * {@inheritdoc}
   */
  protected function generateMachineName() {
    return OSHA_MIGRATION_CONTENT_TYPE_BUREAU;
  }

  /**
   * Prepare raw data pulled from source.
   *
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    if (empty($row->field_contact_uuid)) {
      $this->saveMessage('Skipping contact without uuid',
        MigrationBase::MESSAGE_WARNING);
      return FALSE;
    }
    // Create the terms if not exists.
    // Migration will set terms if name found.
    if (!empty($row->field_wg_category)) {
      MigrationUtil::getOrCreateTaxonomyTerm('wg_category', $row->field_wg_category, array('language' => 'en'));
    }
    if (!empty($row->field_wg_role_1)) {
      $roles = explode('.', $row->field_wg_role_1);
      MigrationUtil::getOrCreateTaxonomyTerm('wg_role_1', $roles[0], array('language' => 'en'));
      if (!empty($roles[1])) {
        $row->field_wg_role_1 = trim($roles[0]);
        MigrationUtil::getOrCreateTaxonomyTerm('wg_role_2', $roles[1], array('language' => 'en'));
        $row->field_wg_role_2 = trim($roles[1]);
      }
      elseif ($roles[0] == 'Observer') {
        $row->field_wg_role_1 = strtolower($row->field_wg_role_1);
      }
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
    $entity->path['pathauto'] = 0;
  }

  public function complete($entity, $row) {
  }

  /**
   * Executes after import.
   */
  public function postImport() {
    parent::postImport();
    $this->removeNeedsUpdateItems();
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
      'field_contact_uuid' => '',
      'path' => 'URL pattern without language',
      'language' => 'Row language',
      'workflow_state' => '',
      'creation_date' => '',
      'modification_date' => '',
      'publication_date' => '',
      'creator' => 'Author user id from the old website',
      'title' => '',
      'description' => '',
      'text' => 'Body of the blog',
      'image' => 'Path to image file',
      'imageCaption' => 'Image tooltip',
      'subject' => 'Categories/Tags',
      'country' => '',
      'subcategory' => 'Merged into categories',
      'multilingual_thesaurus' => '',
      'nace' => 'Nace codes taxonomy',
      'archived' => '',
      'expiration_date' => '',
    );
  }
}

class BoardBureauMembersListXML extends MigrateList {
  protected $file = '';
  public static $data = array();

  /**
   * {@inheritdoc}
   */
  public function __construct($file) {
    parent::__construct($file);
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
   * Parse the XML file and populate the local cache.
   */
  protected function parseSourceFile() {
    self::$data = array();
    if (!is_readable($this->file)) {
      return;
    }
    if ($xml = simplexml_load_file($this->file,  'SimpleXMLElement', LIBXML_COMPACT | LIBXML_PARSEHUGE)) {
      // To be used for board and bureau memebers, to merge the details.
      // Contact fields are attributes of Detail.
      foreach ($xml->xpath('//Detail') as $member) {
        $data = new stdClass();
        $attributes = $member->attributes();
        $data->title = (string) $attributes['Table0_Details2'];
        $data->title_field = (string) $attributes['Table0_Details2'];
        $data->field_personal_title = (string) $attributes['Table0_Details1'];
        $data->field_wg_role_1 = (string) $attributes['Table0_Details3'];
        $data->field_wg_category = (string) $attributes['Table0_Details4'];
        $data->field_contact_uuid = (string) $attributes['Textbox8'];
        $data->field_contact_type = 'Bureau of the Governing Board';
        self::$data[$data->field_contact_uuid] = $data;
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

class BoardBureauMembersItemXML extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (array_key_exists($item_id, BoardBureauMembersListXML::$data)) {
      return (object) BoardBureauMembersListXML::$data[$item_id];
    }
    return NULL;
  }
}
