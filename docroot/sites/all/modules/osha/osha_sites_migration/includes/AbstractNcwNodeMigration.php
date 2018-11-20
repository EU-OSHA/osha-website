<?php

/**
 * Class AbstractNCWNodeMigration is used to migrate nodes from NCW.
 */
abstract class AbstractNCWNodeMigration extends Migration {

  protected $endpoint_url = NULL;
  protected $bundle = NULL;
  protected $missingUrl = TRUE;
  protected $site_source;

  public function __construct($arguments, $source_klass, $bundle) {
    parent::__construct(MigrateGroup::getInstance($arguments['group_name']));

    $this->highwaterField = ['name' => 'changed'];

    /** Disable linkchecker globally to avoid failures during migration */
    global $linkchecker_disable_scan;
    $linkchecker_disable_scan = TRUE;

    $this->bundle = $bundle;
    if (!empty($arguments['dependencies'])) {
      $this->dependencies = $arguments['dependencies'];
    }

    if (!empty($arguments['site_source'])) {
      $this->site_source = $arguments['site_source'];
    }

    $this->endpoint_url = $this->getMigrationURL();
    if ($this->validateEndpointURL()) {
      $this->missingUrl = FALSE;
    }
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type'        => 'varchar',
          'length'      => 255,
          'not null'    => TRUE,
          'description' => 'Original nid in the NCW website',
        ),
      ),
      MigrateDestinationNode::getKeySchema(),
      'default',
      array('track_last_imported' => TRUE)
    );
    $options = array(
      'cache_counts' => FALSE,
      'endpoint_url' => $this->endpoint_url,
      'site_source' => $this->site_source,
      'track_changes' => TRUE,
    );
    if (!empty($arguments['skip_ids'])) {
      $options['skip_ids'] = $arguments['skip_ids'];
    }
    $this->source = new $source_klass($options);
    $node_options = MigrateDestinationNode::options('en', 'full_html');
    $this->destination = new MigrateDestinationNode($bundle, $node_options);
    $this->addFieldMappings();
  }

  /**
   * Configure field mappings, reads bundle field information
   */
  protected function addFieldMappings() {
    // Node base fields
    $this->addFieldMapping('comment')->defaultValue(0);
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('changed', 'changed');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('promote', 'promote');
    $this->addFieldMapping('sticky', 'sticky');
    $this->addFieldMapping('log', 'log');
    $this->addFieldMapping('language', 'language');

    $this->addFieldMapping('field_source_url', 'full_url');
    $this->addFieldMapping('field_migration_source', 'field_migration_source');
    $this->addFieldMapping('field_show_in_ncw', 'field_show_in_ncw');
//    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('workbench_access')->defaultValue('section'); // Assign default section

    // Handle field migration in a generic way
    $fields = field_info_instances('node', $this->bundle);
    $exposed = $this->source->fields();
    foreach($fields as $field_name => $field_info) {
      $field_base = field_info_field($field_name);
      if (array_key_exists($field_name, $exposed) && !in_array($field_name, $this->getManuallyMigratedFields())) {
        $this->addFieldMapping($field_name, $field_name);

        // Extra mappings depending on field type
        $fi = field_info_field($field_name);
        if ($fi['translatable'] == 1
          && $fi['type'] != 'taxonomy_term_reference' /* field_organised_by */) {
          $this->addFieldMapping("$field_name:language", $field_name . '_language');
        }
        if ($fi['type'] == 'taxonomy_term_reference') {
          $this->addFieldMapping("$field_name:create_term")->defaultValue(FALSE);
        }
        if ($fi['type'] == 'link_field') {
          $this->addFieldMapping("$field_name:title", $field_name . '_title');
          $this->addFieldMapping("$field_name:attributes", $field_name . '_attributes');
        }
        if ($fi['type'] == 'text_with_summary') {
          $this->addFieldMapping("$field_name:summary", $field_name . '_summary');
          $this->addFieldMapping("$field_name:format", $field_name . '_format');
        }
        if ($fi['type'] == 'text_long') {
          $this->addFieldMapping("$field_name:format", $field_name . '_format');
        }
        if ($fi['type'] == 'datetime') {
          $this->addFieldMapping("$field_name:to", $field_name . '_value2');
          $this->addFieldMapping("$field_name:timezone", $field_name . '_timezone');
        }
        if ($fi['type'] == 'file' || $fi['type'] == 'image') {
          $field_settings = $field_info['settings'];
          $this->addFieldMapping("$field_name:file_class")->defaultValue('OSHAMigrateFileUri');
          $this->addFieldMapping("$field_name:site_source")->defaultValue($this->site_source);
//          $this->addFieldMapping('field_related_resources:description', 'file_descriptions');
          $this->addFieldmapping("$field_name:preserve_files")->defaultValue(TRUE);
          $this->addFieldMapping("$field_name:file_replace")->defaultValue(FILE_EXISTS_RENAME);
//    $this->addFieldMapping('field_related_resources:source_dir')->defaultValue($data_path . '/export/');
          $this->addFieldMapping("$field_name:destination_dir")->defaultValue('public://'. $field_settings['file_directory']);
          $this->addFieldMapping("$field_name:multilingual")->defaultValue($field_base['translatable']);
        }
      }
    }
    $this->addUnmigratedDestinations(
      array(
        'revision', 'tnid', 'translate', 'revision_uid', 'is_new', 'path',
      )
    );
  }

  protected function getManuallyMigratedFields() {
    return array('field_migration_source');
  }

  protected function ignoreMetatagMigration() {
    $this->addUnmigratedDestinations(array(
      'metatag_title',
      'metatag_description',
      'metatag_abstract',
      'metatag_keywords',
      'metatag_robots',
      'metatag_news_keywords',
      'metatag_standout',
      'metatag_generator',
      'metatag_rights',
      'metatag_image_src',
      'metatag_canonical',
      'metatag_shortlink',
      'metatag_publisher',
      'metatag_author',
      'metatag_original-source',
      'metatag_revisit-after',
      'metatag_content-language',
      'metatag_dcterms.title',
      'metatag_dcterms.creator',
      'metatag_dcterms.subject',
      'metatag_dcterms.description',
      'metatag_dcterms.publisher',
      'metatag_dcterms.contributor',
      'metatag_dcterms.date',
      'metatag_dcterms.modified',
      'metatag_dcterms.type',
      'metatag_dcterms.format',
      'metatag_dcterms.identifier',
      'metatag_dcterms.source',
      'metatag_dcterms.language',
      'metatag_dcterms.relation',
      'metatag_dcterms.coverage',
      'metatag_dcterms.rights',
    ));
  }

  /**
   * Implements Migration::prepareRow() to adapt JSON fields data to what migrate expects in the field.
   */
  public function prepareRow($row) {
    try {
      osha_sites_migration_debug('!klass:      * Preparing source node: !id', array(
        '!klass' => get_class($this),
        '!id' => $row->nid
      ));
      $row->field_migration_source = $this->site_source;
      $row->path = !empty($row->path['alias']) ? $row->path['alias'] : NULL;
      // Normalize JSON structure, to match migrate expectations for field data
      $fields = field_info_instances('node', $this->bundle);
      foreach ($fields as $field_name => $field_info) {
        if (in_array($field_name, $this->getManuallyMigratedFields())) {
          continue;
        }
        $fi = field_info_field($field_name);
        if ($fi['type'] == 'entityreference') {
          // Entity references will be manually handled by each migration
          continue;
        }
        $normalizer = 'osha_migration_normalize_field_' . $fi['type'];
        if (function_exists($normalizer)) {
          $filter_languages = array();
          if (!$this->allowMigrateTranslation()) {
            $filter_languages = array('en');
          }
          $normalizer($row, $field_name, $fi, $filter_languages);
        }
        else {
          $name = $this->currentMigration()->getMachineName();
          osha_sites_migration_debug("[BUG][$name] Cannot find normalization '$normalizer', skipping field $field_name");
          $row->{$field_name} = array();
        }
      }
    } catch(Exception $e) {
      osha_sites_migration_debug("Exception while preparing the row: {$row->nid}", 'error');
      return FALSE;
    }
    return TRUE;
  }

  /**
   * Implements Migration::prepare()
   */
  public function prepare($entity, stdClass $row) {
    $entity->workbench_moderation_state_new = OSHA_WORKFLOW_STATE_DRAFT;
    if (!empty($row->field_show_in_ncw[0])) {
      $entity->status = 1;
      $entity->workbench_moderation_state_new = OSHA_WORKFLOW_STATE_PUBLISHED;
    }
  }

  public function allowMigrateTranslation() {
    return TRUE;
  }

  /**
   * Implements Migration::complete() to configure translations
   */
  public function complete($entity, stdClass $row) {
    unset($row->translations['data']['en']);
    if (!empty($row->translations['data']) && $this->allowMigrateTranslation()) {
      $handler = entity_translation_get_handler('node', $entity);
      foreach($row->translations['data'] as $language => $data) {
        $handler->setTranslation(array(
          'language' => $data['language'],
          'source' => $data['source'],
          'status' => $data['status'],
          'translate' => $data['translate'],
          'uid' => $this->osha_migration_author_uid(),
        ));
      }
      $handler->saveTranslations();
    }
  }

  /**
   * Default author uid.
   */
  function osha_migration_author_uid() {
    return 0;
  }

  /**
   * Executes before Import.
   */
  public function preImport() {
    MigrationUtil::activateOshaFilesHandler();
  }

  /**
   * Executes post Import.
   */
  public function postImport() {
    MigrationUtil::deactivateOshaFilesHandler();
    $this->removeNeedsUpdateItems();
  }

  /**
   * Migration URL.
   */
  public function getMigrationURL() {
    $group = $this->getGroup()->getName();
    $root = variable_get($group . '_migration_root_url', '');
    $source_uri = variable_get($group . '_migration_' . $this->getMachineName() . '_url');
    return $root . $source_uri;
  }

  public function validateEndpointURL() {
    if (empty($this->endpoint_url)) {
      return FALSE;
    }
    return TRUE;
  }

  protected function createStub($migration, array $source_id) {
    $node = new stdClass();
    node_submit($node);
    // Do not delete/change this marker unless you know what you are doing!
    $node->title = format_string(MIGRATE_STUB_MARKER . ' stub for original nid: !id', array('!id' => $source_id[0]));
    $node->language = 'en';
    $node->type = $this->destination->getBundle();
    $node->uid = 0;
    $node->status = 1;
    $node->path['pathauto'] = 0;
    $node->path['alias'] = '';
    node_save($node);
    if (isset($node->nid)) {
      return array($node->nid);
    }
    else {
      return FALSE;
    }
  }

  /**
   * Remove nodes that are not in the source anymore.
   */
  protected function removeNeedsUpdateItems() {
    $map = $this->getMap();
    $source = $this->getSource();
    $removed = $map->getRowsNeedingUpdate(10000);
    $to_be_removed = array();
    if (!empty($removed)) {
      // Check if the needs review nodes are indeed missing in source.
      foreach ($removed as $to_remove) {
        $url = $source->itemURL($to_remove->sourceid1);
        $curl = curl_init();
        curl_setopt($curl, CURLOPT_URL, $url);
        curl_setopt($curl, CURLOPT_NOBODY, true);
        curl_setopt($curl, CURLOPT_CONNECTTIMEOUT, 5);
        curl_setopt($curl, CURLOPT_FOLLOWLOCATION, true);
        $result = curl_exec($curl);
        $info = curl_getinfo($curl);
        curl_close($curl);
        if (!empty($info['http_code']) && in_array($info['http_code'], [404, 403])) {
          node_delete($to_remove->destid1);
          $this->getMap()->delete(array($to_remove->sourceid1));
          watchdog('osha_sites_migration', 'Deleting NODE that are not in the source anymore (@migration): !nids.',
            array('!nids' => $to_remove->destid1, '@migration' => $this->getMachineName()), WATCHDOG_INFO);
        }
      }
    }
  }
}

