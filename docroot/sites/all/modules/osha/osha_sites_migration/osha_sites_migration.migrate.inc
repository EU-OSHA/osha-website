<?php

/**
 * Implements hook_migrate_api().
 *
 * Set the API level to 2, for migration classes to be recognized by Migrate.
 */

/////////////////////////// Migration abstract classes /////////////////////////

function ncw_migration_debug($message, $message_args = array(), $level = 'notice') {
  if (function_exists('drush_get_option')) {
    // Message appear when running 'drush -d migrate-import events'.
    if ($debug = drush_get_option('debug')) {
      $str = format_string($message, $message_args);
      drush_log($str, $level);
    }
  }
}

/**
 * Class AbstractNCWNodeMigration is used to migrate nodes from NCW.
 */
abstract class AbstractNCWTaxonomyTermMigration extends AbstractNCWNodeMigration {

  public function __construct($arguments, $source_klass, $bundle) {
    parent::__construct($arguments, $source_klass, $bundle);
    $this->bundle = $bundle;
    if (!empty($arguments['dependencies'])) {
      $this->dependencies = $arguments['dependencies'];
    }
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'tid' => array(
          'type'        => 'varchar',
          'length'      => 255,
          'not null'    => TRUE,
          'description' => 'Original tid in the NCW website',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );
    $options = array(
      'endpoint_url' => $this->endpoint_url,
      'track_changes' => TRUE,
    );
    if (!empty($arguments['skip_ids'])) {
      $options['skip_ids'] = $arguments['skip_ids'];
    }
    $this->source = new $source_klass($options);
    $this->destination = new MigrateDestinationTerm($bundle, array('language' => 'en'));
    $this->ignoreMetatagMigration();
  }

  /**
   * Configure field mappings, reads bundle field information.
   *
   * @param array $ignore
   *   Ignore these fields during mapping (or handle manually in derived class).
   */
  protected function addFieldMappings() {
    // Taxnomy term base fields.
    $this->addSimpleMappings(array('name', 'description', 'format', 'weight'));

    // Handle field migration in a generic way.
    $fields = field_info_instances('taxonomy_term', $this->bundle);
    $exposed = $this->source->fields();
    foreach ($fields as $field_name => $field_info) {
      if (array_key_exists($field_name, $exposed) && !in_array($field_name, $this->getManuallyMigratedFields())) {
        $this->addFieldMapping($field_name, $field_name);
        // Extra mappings depending on field type.
        $fi = field_info_field($field_name);
        if ($fi['translatable'] == 1 && $fi['type'] != 'taxonomy_term_reference' /* field_organised_by */) {
          $this->addFieldMapping("$field_name:language", $field_name . '_language');
        }
        if ($fi['type'] == 'taxonomy_term_reference') {
          $this->addFieldMapping("$field_name:create_term")->defaultValue(TRUE);
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
          $this->addFieldMapping("$field_name:file_replace")->defaultValue(TRUE);
        }
      }
    }
  }

  /**
   * Implements Migration::prepareRow() to adapt JSON fields data to what migrate expects in the field.
   */
  public function prepareRow($row) {
    try {
      ncw_migration_debug('!klass:      * Preparing source term: !id', array('!klass' => get_class($this), '!id' => $row->tid));
      $row->language = 'en';
      $row->path = !empty($row->path['alias']) ? $row->path['alias'] : NULL;
      // Normalize JSON structure, to match migrate expectations for field data.
      $fields = field_info_instances('taxonomy_term', $this->bundle);
      foreach ($fields as $field_name => $field_info) {
        if (in_array($field_name, $this->getManuallyMigratedFields())) {
          continue;
        }
        $fi = field_info_field($field_name);
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
          watchdog('ncw_migration', "[BUG][$name] Cannot find normalization '$normalizer', skipping field $field_name", array(), WATCHDOG_ERROR);
          $row->{$field_name} = array();
        }
      }

      // Remove invalid values so we don't get field validation errors (ie. blog).
      if (!empty($row->field_excluded_from) && is_array($row->field_excluded_from)) {
        $whitelist = array(
          'article',
          'page',
          'job_vacancies',
          'news',
          'press_release',
          'publication',
          'infographic',
        );
        foreach ($row->field_excluded_from as $k => $v) {
          if (!in_array($v, $whitelist)) {
            unset($row->field_excluded_from[$k]);
          }
        }
      }
    }
    catch (Exception $e) {
      ncw_migration_debug("Exception while preparing the row: {$row->tid}", 'error');
      return FALSE;
    }
    return TRUE;
  }

  /**
   * Implements Migration::complete() to configure translations.
   */
  public function complete($entity, stdClass $row) {
    unset($row->translations['data']['en']);
    if (!empty($row->translations['data'])) {
      $handler = entity_translation_get_handler('taxonomy_term', $entity);
      foreach ($row->translations['data'] as $language => $data) {
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
}

/**
 * Class AbstractNCWTaxonomyTermSource - base for NCW taxonomy migration.
 */
abstract class AbstractNCWTaxonomyTermSource extends AbstractNCWNodeSource {

  public function itemIdentifier($ob) {
    return $ob->tid;
  }

  public function itemURL($id) {
    return ncw_migration_datasource_url($this->site_source) . '/export/taxonomy_term/' . $id;
  }

  public function fields() {
    return array(
      'tid' => 'tid',
      'name' => 'name',
      'name_field_language' => 'name_field:language',
      'name_field' => 'name_field',
      'format' => 'format',
      'weight' => 'weight',
      'description' => 'description',
      'description_field' => 'description_field',
      'description_field_language' => 'description_field:language',
      'description_field_format' => 'description_field:format',
      'description_field_summary' => 'description_field:summary',
      'field_excluded_from' => 'field_excluded_from',
      ) + $this->contentFields();
  }
}
