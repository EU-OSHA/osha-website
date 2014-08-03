<?php

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
   * @param string $vocabulary_name
   *   Vocabulary machine name
   * @param string $field_match
   *   Name of the field to match against (i.e. name)
   * @param array $terms
   *   Array of field values to match
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
    if (empty($terms)) {
      return array();
    }
    $ret = array();
    $terms = array_map('trim', $terms);
    $terms = array_filter($terms, 'strlen');
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
      drupal_set_message(
        t('Could not find term(s) "@terms" in @voc vocabulary',
          array('@terms' => implode(', ', $misses), '@voc' => $vocabulary_name)
        ),
        'warning'
      );
    }
    return $ret;
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
        if (!empty($term->{$field_name}[$language][0]['value'])) {
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
   */
  public static function decodeTagsTerms($terms_str, $term_field = 'field_tags_code') {
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
      'young_people::educators_mainstreaming' => 'mainstream-ing_osh_into_education',
    );
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
  public static function parseRelatedItemsString($field_value, $supported_extensions = 'pdf|doc|docx|ppt|pptx|xls|xlsx') {
    $ret = array('items' => NULL, 'files' => NULL);
    if (empty($field_value)) {
      return $ret;
    }
    $items = array_map('trim', explode(',', $field_value));
    foreach ($items as $item) {
      $file_match = sprintf('/^.*\.(%s)$/i', $supported_extensions);
      if (preg_match($file_match, $item)) {
        $ret['files'][] = $item;
      }
      else {
        $path = preg_replace('/^\/en\//i', '', $item);
        $ret['items'][] = $path;
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
      array(
        'group_name' => 'OSHA TEST MIGRATIONS',
        'file_name' => $file,
      )
    );
    $migration = Migration::getInstance($machine_name);
    return $migration->processImport();
  }

  /**
   * Check and remove invalid files to be migrated from the given field.
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
    $migration = Migration::currentMigration();
    /* Validate file path length */
    $valid = array();
    foreach ($row->{$field} as $language => $path) {
      if (is_string($path)) {
        if (strlen($path_prefix) + strlen($path) > 255) {
          $migration->saveMessage(
            "File path cannot be larger than 255 characters, ignoring {$row->file}",
            MigrationBase::MESSAGE_WARNING
          );
        }
        else {
          $valid[$language] = $path;
        }
      }
      else {
        $valid_inner = array();
        foreach ($path as $file) {
          if (strlen($path_prefix) + strlen($file) > 255) {
            $migration->saveMessage(
              "File path cannot be larger than 255 characters, ignoring {$file}",
              MigrationBase::MESSAGE_WARNING
            );
          }
          else {
            $valid_inner[] = $file;
          }
        }
        $valid[$language] = $valid_inner;
      }
    }
    $row->{$field} = $valid;
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
}
