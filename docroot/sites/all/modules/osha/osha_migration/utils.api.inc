<?php

/**
 * Class OshaWebTestCase is the base class for OSHA tests.
 *
 * Correctly enables all instance modules in the appropriate order.
 */
abstract class OshaWebTestCase extends DrupalWebTestCase {

  /**
   * {@inheritdoc}
   */

  public $modulePath;
  public $dataPath;
  protected $userAdmin;
  protected $permissionsAdmin = array();

  /**
   * {@inheritdoc}
   */
  public function setUp() {
    $modules = func_get_args();
    if (isset($modules[0]) && is_array($modules[0])) {
      $modules = $modules[0];
    }
    $modules = array_merge(array('file', 'file_entity'), $modules);
    parent::setUp($modules);
    require DRUPAL_ROOT . '/../drush/drushrc.php';
    if (!empty($options['init-modules'])) {

      $modules = $options['init-modules'];
      $modules[] = 'osha_taxonomies_uuid';
      unset($modules[array_search('file_entity', $modules)]);
      unset($modules[array_search('osha_search', $modules)]);

      if (!module_enable($modules)) {
        foreach ($modules as $module) {
          if (!module_enable(array($module))) {
            drupal_set_message('Cannot enable module: ' . $module, 'error');
          }
        }
      }
    }

    $this->setDataDirTestData();
    $this->modulePath = drupal_get_path('module', 'osha_migration');
  }

  /**
   * Set the data directory to test directory.
   */
  protected function setDataDirTestData() {
    $data_path = drupal_realpath(drupal_get_path('module', 'osha_migration') . '/data/test');
    variable_set('osha_data_dir', $data_path);
    $this->dataPath = $data_path;
  }

  /**
   * Set the data directory to exported OSHA data.
   */
  protected function setDataDirExportedData() {
    $cfg = MigrationUtil::getProjectConfig();
    variable_set('osha_data_dir', $cfg['variables']['osha_data_dir']);
  }

  public static function oshaAssertEqualTaxonomyTerms($entity, $entity_taxon_field, $taxon_field, $raw_taxonomy_terms) {
    $terms = array();
    $raw_values = array_unique(array_map('trim', explode(',', $raw_taxonomy_terms)));
    $entity_values = array();
    if (!empty($entity->{$entity_taxon_field}[LANGUAGE_NONE])) {
      foreach ($entity->{$entity_taxon_field}[LANGUAGE_NONE] as $term) {
        $terms[] = $term['tid'];
      }
      $terms = taxonomy_term_load_multiple($terms);
      $entity_values = array();
      foreach ($terms as $term) {
        $entity_values[] = $term->{$taxon_field}[LANGUAGE_NONE][0]['value'];
      }
    }
    $diff = array_diff($entity_values, $raw_values);
    return empty($diff);
  }

  public function oshaAssertEqualFileMultilingual($entity, $entity_field_name, $source, $source_field_name, $destination_path = "public://") {
    foreach ($source[$source_field_name] as $language => $image) {
      if (!empty($image)) {
        $file_name = $entity->{$entity_field_name}[$language][0]['uri'];
        $file_name = str_replace($destination_path, '', $file_name);
        $this->assertEqual($file_name, $image);
      }
    }
  }

  public function oshaAssertEqualFileMultilingMultival($entity, $entity_field_name, $source, $source_field_name, $destination_path = "public://") {
    foreach ($source[$source_field_name] as $language => $images) {
      if (!empty($images)) {
        $images = explode(',', $images);
        $images = array_map('trim', $images);
        if (count($images) > 1) {
          foreach ($images as $index => $path) {
            $file_name = $entity->{$entity_field_name}[$language][$index]['uri'];
            $file_name = str_replace($destination_path, '', $file_name);
            $this->assertEqual($file_name, $path);
          }
        }
        else {
          $file_name = $entity->{$entity_field_name}[$language][0]['uri'];
          $file_name = str_replace($destination_path, '', $file_name);
          $this->assertEqual($file_name, current($images));
        }
      }
    }
  }

  /**
   * Will create a user with admin permissions and log it in.
   *
   * @param array $additional_permissions
   *   Additional permissions that will be granted to admin user.
   * @param boolean $reset_permissions
   *   Flag to determine if default admin permissions will be replaced by
   *   $additional_permissions.
   *
   * @return object
   *   Newly created and logged in user object.
   */
  protected function loginAsAdmin($additional_permissions = array(), $reset_permissions = FALSE) {
    $permissions = $this->permissionsAdmin;

    if ($reset_permissions) {
      $permissions = $additional_permissions;
    }
    elseif (!empty($additional_permissions)) {
      $permissions = array_merge($permissions, $additional_permissions);
    }

    $this->userAdmin = $this->drupalCreateUser($permissions);
    $this->drupalLogin($this->userAdmin);
    return $this->userAdmin;
  }
}


/**
 * Class MigrationUtil provides generic utility functionality to migrations.
 */
class MigrationUtil {

  /**
   * Extract source file for the migration.
   *
   * @param array $arguments
   *   Migration arguments
   *
   * @return string
   *   Path to the migration data file
   * @throws Exception If the file is not accessible
   */
  public static function getSourceFile($arguments) {
    $file = NULL;
    if (isset($arguments['file_name'])) {
      $file = $arguments['file_name'];
      if (!file_exists($file) || !is_readable($file)) {
        throw new Exception(
          t('Cannot read migration file @file', array('@file' => $file))
        );
      }
    }
    else {
      throw new Exception(
        t('Invalid migration setup: missing `file_name` parameter (source)')
      );
    }
    return $file;
  }


  /**
   * Find terms in the given vocabulary by matching on its fields (i.e. name).
   *
   * @param array $terms
   *   Array of field values to match
   * @param string $field_match
   *   Name of the field to match against (i.e. name)
   * @param string $vocabulary_name
   *   Vocabulary machine name
   * @param string $language
   *   Field will be inspected on this language
   *
   * @return array
   *   Array of tids. An warning is shown if the number of returned
   * terms does not match the input
   *
   * Note: This method does static caching and loads entire vocabulary for reuse
   * thus is recommended to use when taxonomy does not change during migration.
   */
  public static function findTidByTaxonomyField($terms, $field_match, $vocabulary_name, $language = LANGUAGE_NONE) {
    if (!is_array($terms)) {
      return array();
    }
    $ret = array();
    $terms = array_map('trim', $terms);
    $terms = array_filter($terms, 'strlen');
    if (empty($terms)) {
      return array();
    }
    $terms = array_unique($terms);
    $field_values = self::cacheVocabularyTermsFields($vocabulary_name, $field_match, $language);
    $misses = array();
    foreach ($terms as $t) {
      if (array_key_exists($t, $field_values)) {
        $ret[] = $field_values[$t];
      }
      else {
        $misses[] = $t;
      }
    }
    if (count($misses)) {
      $error = sprintf('Could not find term(s) "%s" in %s vocabulary',
        implode(',', $misses), $vocabulary_name
      );
      drupal_set_message($error);
    }
    return $ret;
  }

  /**
   * Find terms by inspecting field value. Not multilingual.
   *
   * @param array $term_name
   *   Field value to match
   * @param string $field_match
   *   Name of the field to match against (i.e. name)
   *
   * @return array
   *   Term ID or NULL.
   *
   * Note: This method does not cache results, queries the vocabularies
   */
  public static function findTermByFieldValue($term_name, $field_match, $is_property = FALSE) {
    $query = new EntityFieldQuery();
    try {
      $result = $query
        ->entityCondition('entity_type', 'taxonomy_term');
      if ($is_property) {
        $query->propertyCondition($field_match, $term_name, '=');
      }
      else {
        $query->fieldCondition($field_match, 'value', $term_name, '=');
      }
      $result = $query->execute();
    }
    catch(Exception $e) {
      drupal_set_message(
        sprintf('Cannot find term due to error: %s', $e->getMessage()),
        'warning'
      );
    }
    return !empty($result['taxonomy_term']) ? current(array_keys($result['taxonomy_term'])) : NULL;
  }

  /**
   * Cache vocabulary terms mapped to tid. Use to find tid.
   *
   * @param string $vocabulary_name
   *   Vocabulary name
   * @param string $field_name
   *   Field name (to inspect the term's field)
   * @param string $language
   *   (Optional) Language, default Language none.
   *
   * @return array
   *   Array of tids. Empty if no term was found in that language
   */
  protected static function cacheVocabularyTermsFields($vocabulary_name, $field_name, $language = LANGUAGE_NONE) {
    static $cache = array();
    if (empty($cache[$vocabulary_name][$field_name][$language])) {
      $voc = taxonomy_vocabulary_machine_name_load($vocabulary_name);
      $terms = taxonomy_get_tree($voc->vid, 0, NULL, TRUE);
      foreach ($terms as $term) {
        if (!empty($term->{$field_name}[$language][0]['value']) ||
            (isset($term->{$field_name}[$language])
              && $term->{$field_name}[$language][0]['value'] == '0')) {
          $value = $term->{$field_name}[$language][0]['value'];
          $cache[$vocabulary_name][$field_name][$language][$value] = $term->tid;
        }
      }
    }
    if (isset($cache[$vocabulary_name][$field_name][$language])) {
      return $cache[$vocabulary_name][$field_name][$language];
    }
    return array();
  }

  /**
   * Transform given term names in tids using hard-coded OSHA mappings.
   * Note that mappings for publication content type is slightly different, hence the third parameter
   *
   * Read the tech specs to see how mappings are handled.
   *
   * @param string $terms_str
   *   Comma-separated string containing terms
   * @param string $term_field
   *   (Optional) Arbitrary term field to match. Default field_tags_code
   *
   * @return array
   *   Array of tids
   * @todo REVIEW THIS FUNCTION
   */
  public static function decodeTagsTerms($terms_str, $term_field = 'field_tags_code', $is_publication = FALSE) {
    if (empty($terms_str)) {
      return array();
    }
    $terms = explode(',', $terms_str);
    $terms = array_unique($terms);
    $terms = array_map('trim', $terms);

    $ret = array();
    $replace = array(
      'accident_prevention' => 'accident_prevention',
      'ageing' => 'ageing_and_osh',
      'businessOSH' => 'good_osh_is_good_for_business',
      'campaign_2014_15' => 'campaign_2014_2015',
      'dangerous_substances' => 'dangerous_substances',
      'economic_incentives' => 'good_osh_is_good_for_business',
      'education' => 'mainstreaming_osh_into_education',
      'osh_education' => 'mainstreaming_osh_into_education',
      'osheducation' => 'mainstreaming_osh_into_education',
      'esener' => 'esener',
      'foresight' => 'emerging_risks',
      'gender' => 'women_and_osh',
      'green_jobs' => 'green_jobs',
      'legislation' => 'legislation',
      'management_leadership' => 'leadership',
      'msd' => 'musculoskeletal_disorders',
      'nanotechnology' => 'nanomaterials',
      'prevention' => 'accident_prevention',
      'risk_observatory' => 'emerging_risks',
      'risks' => 'emerging_risks',
      'stress' => 'psychosocial_risks_and_stress',
      'young_people' => 'osh_and_young_people',
      'young_people::educators_mainstreaming' => 'mainstreaming_osh_into_education',
    );
    if ($is_publication) {
        unset($replace['campaign_2014_15']);
        unset($replace['legislation']);
        $replace['agriculture'] = 'agriculture';
        $replace['cleaners'] = 'cleaning_workers';
        $replace['construction'] = 'construction';
        $replace['csr'] = 'corporate_social_responsibility';
        $replace['disability'] = 'disabled_people';
        $replace['disabled_people'] = 'disabled_people';
        $replace['fisheries'] = 'fisheries';
        $replace['health_care'] = 'health_care';
        $replace['healthcare'] = 'health_care';
        $replace['horeca'] = 'horeca';
        $replace['maintenance'] = 'maintenance';
        $replace['migrant_workers'] = 'migrant_workers';
        $replace['noise'] = 'noise';
        $replace['risk_assessment'] = 'risk_assessment';
        $replace['road_transport'] = 'road_transport';
        $replace['statistics'] = 'statistics';
        $replace['transport'] = 'transport';
        $replace['worker_participation'] = 'worker_participation';
        $replace['whp'] = 'workplace_health_promotion';
    }
    foreach ($terms as $term) {
      if (array_key_exists($term, $replace)) {
        $ret[] = $replace[$term];
      }
      else {
        $exp = explode('::', $term);
        if (count($exp) == 2) {
          $cat = $exp[0];
          if (array_key_exists($cat, $replace)) {
            $ret[] = $replace[$cat];
          }
        }
      }
    }
    return self::findTidByTaxonomyField($ret, $term_field, OSHA_TAXONOMIES_TAGS, LANGUAGE_NONE);
  }

  /**
   * Parse 'related items' field (i.e. related_publications).
   *
   * Extract the values as entities (i.e. related publications) and physical
   * files (i.e. /local/storage/path/file.pptx)
   *
   * @param string $field_value
   *   Value to parse
   * @param string $supported_extensions
   *   (Optional) Supported file extensions.
   *   Default: PDF,DOC,DOCX,PPT,PPTX,XLS,XLSX
   *
   * @return array
   *   Array with two keys (`items` and `files`) of related content
   */
  public static function parseRelatedItemsString($field_value, $item_url_diff = 'publications', $supported_extensions = 'pdf|doc|docx|ppt|pptx|xls|xlsx') {
    $languages = implode('|', array_keys(language_list()));
    $ret = array('items' => NULL, 'files' => NULL);
    if (empty($field_value)) {
      return $ret;
    }
    $items = array_map('trim', explode(',', $field_value));
    foreach ($items as $item) {
      // $extension_match = sprintf('/^.*\.(%s)$/i', $supported_extensions);
      $item_url_match = '/\/' . $item_url_diff . '\//';
      $path_match = sprintf('/^\/(%s)\//i', $languages);
      if (preg_match($item_url_match, $item)) {
        $path = preg_replace($path_match, '', $item);
        $ret['items'][] = $path;
        $ret['paths'][$path] = $item;
      }
      else {
        $ret['files'][] = $item;
        $ret['paths'][$item] = $item;
      }
    }
    if (count($ret['items']) + count($ret['files']) != count($items)) {
      drupal_set_message(
        t('Could not extract all related items from string: @input (Possible unsupported file extensions: @ext)',
          array('@input' => $field_value, '@ext' => $supported_extensions)
        ),
        'warning'
      );
    }
    return $ret;
  }

  /**
   * Transform custom escapes like <@#&> and <&#@> in HTML text.
   *
   * @return text
   *     Decoded text
   */
  public static function decodeHTMLText($text) {
    $search  = array('<@#&>', '<&#@>');
    $replace = array('"', ',');
    return str_replace($search, $replace, $text);
  }

  /**
   * Register and run a migration.
   *
   * @param string $machine_name
   *   Unique migration machine name
   * @param string $klass
   *   Migration class
   * @param string $file
   *   Migration file, argument passed to migration
   *
   * @return object
   *   Migration instance
   */
  public static function runMigration($machine_name, $klass, $file) {
    Migration::registerMigration(
      $klass,
      $machine_name,
      array('file_name' => $file)
    );
    $migration = Migration::getInstance($machine_name);
    return $migration->processImport();
  }

  /**
   * Check and replace invalid files to be migrated from the given field.
   *
   * File paths that exceed the 255 character limit are replaced with their
   * corespondent from an hardcoded file located at osha_migration/data/
   * named renamed_files.json
   *
   * The function populates:
   *   $row->{$field} with the old values, this value will be stored as an alias
   *   $row->{OSHA_MIGRATION_REPLACED_PATH_PREFIX . $field}, with the new values
   *      this value will be stored in file_managed.uri
   *      with valid values,
   *
   * This system was made with the purpose of keeping the old paths while
   * complying with the restriction of 255 chars for the uri.
   *
   * @param object $row
   *   Migrated source row
   * @param string $field
   *   File field from the object
   * @param string $path_prefix
   *   Additional path added to 'sites/default/files' ...
   */
  public static function cleanMigratedFileField(&$row, $field, $path_prefix = 'public://') {
    if (empty($row->{$field})) {
      return;
    }
    /* Container for valid paths (< 255 chars) */
    $valid = array();
    /* Container for old paths */
    $old_paths = array();
    foreach ($row->{$field} as $language => $path) {
      if (is_string($path)) {
        $destination = self::getFileDestination($path, $path_prefix);
        if (!empty($destination)) {
          $valid[$language] = $destination;
          $old_paths[$language] = $path;
        }
      }
      else {
        foreach ($path as $file_path) {
          $destination = self::getFileDestination($file_path, $path_prefix);
          if (!empty($destination)) {
            $valid[$language][] = $destination;
            $old_paths[$language][] = $file_path;
          }
        }
      }
    }

    $row->{$field} = $old_paths;
    $row->{OSHA_MIGRATION_REPLACED_PATH_PREFIX . $field} = $valid;
  }

  public static function cleanMigratedFile(&$row, $field, $path_prefix = 'public://') {
    if (empty($row->{$field})) {
      return;
    }
    $destination = self::getFileDestination($row->{$field}, $path_prefix);
    if (!empty($destination)) {
      $row->{OSHA_MIGRATION_REPLACED_PATH_PREFIX . $field} = $destination;
      return $destination;
    }
    else {
      return NULL;
    }
  }

  /**
   * Function that returns a valid destination name.
   *
   * If the old path is found as a key then it returns the new_path name.
   *
   * @param string $old_path
   *   The old path
   * @param string $path_prefix
   *   The path prefix
   *
   * @return string
   *   Returns the truncated string from a file if old path can be found or the
   *   old path otherwise
   */
  public static function getFileDestination($old_path, $path_prefix) {
    $file = drupal_get_path('module', 'osha_migration') . "/data/renamed_files.json";
    static $data;
    if (empty($data)) {
      $data = json_decode(file_get_contents($file), TRUE);
    }
    if (strlen($path_prefix) + strlen($old_path) > 255) {
      if (!isset($data[$old_path])) {
        drupal_set_message(
          "File path cannot be larger than 255 characters, ignoring " . $old_path,
          'warning'
        );
        return NULL;
      }
      else {
        drupal_set_message(
          "File path larger than 255 characters, replacing " . $old_path . "with " . $data[$old_path],
          'status'
        );

        return $data[$old_path];
      }
    }
    return $old_path;
  }

  /**
   * Retrieve the project's config from JSON file.
   *
   * @return array
   *   JSON array with project configuration
   */
  public static function getProjectConfig() {
    return json_decode(file_get_contents(DRUPAL_ROOT . '/../conf/config.json'), TRUE);
  }

  /**
   * Removes language prefix from ID
   * @param object $row
   *   Migrated source row
   * @return string
   *   Unique row ID
   */
  public static function getIDFromSourceRow($row) {
    $url = !empty($row[2]) ? $row[2] : $row[0];
    return substr($url, 4);
  }

  /**
   * Filter a row by checking default translation, workflow status and title length
   *
   * @param object $row
   *   Migrated source row
   * @param $class
   *   Instance of the migration class
   * @return bool
   *   TRUE if row is valid, FALSE otherwise
   */
  public static function entityRowValidator($row, $class) {
    if (empty($row->title)) {
      $class->saveMessage('Skipping node without english title', MigrationBase::MESSAGE_WARNING);
      return FALSE;
    }
    if (!in_array($row->workflow_state, array('published', 'checked', 'to_amend'))) {
      $class->saveMessage(
        sprintf('Skipping node with workflow_state: %s', $row->workflow_state),
        MigrationBase::MESSAGE_WARNING);
      return FALSE;
    }
    foreach ($row->title_field as $language => $value) {
      if (strlen($value) > 768) {
        $class->saveMessage(
          sprintf('Skipping node with long title (%s): %s chars', $language, strlen($value)),
          MigrationBase::MESSAGE_WARNING
        );
        return FALSE;
      }
    }

    return TRUE;
  }

  /**
   *  Activate Osha files handler
   */
  public static function activateOshaFilesHandler() {
    // Remove default Handlers for Field and Image and let OSHA Handlers to take
    // care of these fields.
    $default_file_handler = 'MigrateFileFieldHandler';
    $default_image_handler = 'MigrateImageFieldHandler';
    $handlers = unserialize(variable_get('migrate_disabled_handlers', ''));
    if (!is_array($handlers)) {
      $handlers[] = $default_file_handler;
      $handlers[] = $default_image_handler;

    }
    else {
      if (!in_array($default_file_handler, $handlers)) {
        $handlers[] = $default_file_handler;
      }
      if (!in_array($default_image_handler, $handlers)) {
        $handlers[] = $default_image_handler;
      }
    }
    variable_set('migrate_disabled_handlers', serialize($handlers));
  }

  /**
   * Deactivate Osha files handler
   */
  public static function deactivateOshaFilesHandler() {
    // Reset migrate_disabled_handlers variable.
    $default_file_handler = 'MigrateFileFieldHandler';
    $handlers = unserialize(variable_get('migrate_disabled_handlers', ''));
    if (is_array($handlers)) {
      $key = array_search($default_file_handler, $handlers);
      if ($key !== FALSE) {
        unset($handlers[$key]);
      }
      $default_image_handler = 'MigrateImageFieldHandler';
      $key = array_search($default_image_handler, $handlers);
      if ($key !== FALSE) {
        unset($handlers[$key]);
      }
      variable_set('migrate_disabled_handlers', serialize($handlers));
    }
  }

  public static function setTranslation(&$translation_handler, $entity, $row, $language) {
    /* Don't translate en (default) */
    if ($language != $row->language
        && !isset($entity->translations->data[$language])) {
      $translation_handler->setTranslation(array(
        'translate' => 0, 'status' => 1, 'uid' => 1,
        'language' => $language,
        'source' => $row->language,
      ));
    }
  }

  public static function createAliases($entity, $row, $entity_type, $id_key) {
    $languages = array_keys($entity->translations->data);
    if (!in_array($row->language, $languages)) {
      $languages[] = $row->language;
    }
    foreach ($languages as $language) {
      if (isset($row->path[$language])) {
        $path = $row->path[$language];
        if (substr($row->path[$language], 1, 2) == $language) {
          $path = substr($row->path[$language], 4);
        }
      }
      else {
        $path = $row->id;
      }
      $args = array(
        'source' => $entity_type . '/' . $entity->{$id_key},
        'alias' => $path,
        'language' => $language,
      );
      path_save($args);
    }
  }
}

class OSHAMigrationListJSON extends MigrateListJSON {

  protected $codeFieldName;

  /**
   * {@inheritdoc}
   *
   * @param string $code_field_name
   *   Key field that identifies unique items in the given data
   */
  public function __construct($list_url, $code_field_name) {
    parent::__construct($list_url);
    $this->codeFieldName = $code_field_name;
  }


  /**
   * {@inheritdoc}
   */
  protected function getIDsFromJSON(array $data) {
    $ids = array();
    foreach ($data as $item) {
      $ids[] = $item[$this->codeFieldName];
    }
    return $ids;
  }
}

class OSHATaxonomyMigrationItemJSON extends MigrateItemJSON {

  protected $data = array();
  protected $assoc = FALSE;
  protected $field = NULL;

  /**
   * {@inheritdoc}
   *
   * @param string $source_file
   *   Path to the data file
   * @param string $field
   *   Field to use as key
   * @param bool $assoc
   *   Parse the JSON as associative array and store it that way
   */
  public function __construct($source_file, $field = 'code', $assoc = FALSE) {
    $this->itemUrl = $source_file;
    $this->assoc = $assoc;
    $this->field = $field;
  }

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (empty($this->data)) {
      $rows = $this->loadJSONUrl($this->itemUrl, $this->assoc);
      if ($rows) {
        foreach ($rows as $row) {
          $field = $this->field;
          if (!$this->assoc) {
            if (!empty($row->{$field})) {
              $this->data[$row->{$field}] = $row;
            }
          }
          else {
            if (!empty($row[$field])) {
              $this->data[$row[$field]] = $row;
            }
          }
        }
      }
    }
    if (isset($this->data[$item_id])) {
      return $this->assoc ? (object) $this->data[$item_id] : $this->data[$item_id];
    }
    return NULL;
  }
}

class OSHADynamicMigration extends DynamicMigration {
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

  public function prepare($entity, $row) {
    $entity->path['pathauto'] = 0;
    if (isset($entity->field_publication_date) && empty($entity->field_publication_date[LANGUAGE_NONE][0]['value'])) {
      unset($entity->field_publication_date[LANGUAGE_NONE]);
    }
    if (isset($row->workflow_state)) {
      switch ($row->workflow_state) {
        case 'published':
          $entity->workbench_moderation_state_new = 'published';
          break;

        default:
          $entity->workbench_moderation_state_new = 'to_be_approved';
          break;
      }
    }
    $entity->workbench_access = array('main-menu', 'main-menu');
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
    MigrationUtil::createAliases($entity, $row, 'node', 'nid');
  }
}
