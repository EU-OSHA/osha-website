<?php
/**
 * @file
 * osha_musculoskeletal_disorders.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function osha_musculoskeletal_disorders_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_musculoskeletal_disorders';
  $strongarm->value = '-1';
  $export['comment_anonymous_musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_musculoskeletal_disorders';
  $strongarm->value = 0;
  $export['comment_default_mode_musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_musculoskeletal_disorders';
  $strongarm->value = '50';
  $export['comment_default_per_page_musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_musculoskeletal_disorders';
  $strongarm->value = 0;
  $export['comment_form_location_musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_musculoskeletal_disorders';
  $strongarm->value = '1';
  $export['comment_musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_musculoskeletal_disorders';
  $strongarm->value = '0';
  $export['comment_preview_musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_musculoskeletal_disorders';
  $strongarm->value = 0;
  $export['comment_subject_field_musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__musculoskeletal_disorders';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'osha_slideshow' => array(
        'custom_settings' => TRUE,
      ),
      'dangerous_substances' => array(
        'custom_settings' => TRUE,
      ),
      'highlights_item' => array(
        'custom_settings' => TRUE,
      ),
      'newsletter_item' => array(
        'custom_settings' => TRUE,
      ),
      'osha_resources' => array(
        'custom_settings' => TRUE,
      ),
      'osha_wiki' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'osha_search_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '37',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '35',
        ),
        'redirect' => array(
          'weight' => '36',
        ),
        'workbench_access' => array(
          'weight' => '0',
        ),
        'xmlsitemap' => array(
          'weight' => '38',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_musculoskeletal_disorders';
  $strongarm->value = '0';
  $export['language_content_type_musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_musculoskeletal_disorders';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_musculoskeletal_disorders';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__musculoskeletal_disorders';
  $strongarm->value = TRUE;
  $export['metatag_enable_node__musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_musculoskeletal_disorders';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_musculoskeletal_disorders';
  $strongarm->value = '1';
  $export['node_preview_musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_musculoskeletal_disorders';
  $strongarm->value = 0;
  $export['node_submitted_musculoskeletal_disorders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_musculoskeletal_disorders_pattern';
  $strongarm->value = 'themes/musculoskeletal-disorders/practical-tools-musculoskeletal-disorders/[node:title]';
  $export['pathauto_node_musculoskeletal_disorders_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_musculoskeletal_disorders';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_musculoskeletal_disorders'] = $strongarm;

  return $export;
}
