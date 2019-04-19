<?php
/**
 * @file
 * osha_homepage.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function osha_homepage_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_banner';
  $strongarm->value = '0';
  $export['comment_anonymous_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_banner';
  $strongarm->value = '1';
  $export['comment_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_banner';
  $strongarm->value = 0;
  $export['comment_default_mode_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_banner';
  $strongarm->value = '50';
  $export['comment_default_per_page_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_banner';
  $strongarm->value = 0;
  $export['comment_form_location_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_banner';
  $strongarm->value = '0';
  $export['comment_preview_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_banner';
  $strongarm->value = 0;
  $export['comment_subject_field_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_banner';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__banner';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'osha_slideshow' => array(
        'custom_settings' => TRUE,
      ),
      'highlights_item' => array(
        'custom_settings' => FALSE,
      ),
      'newsletter_item' => array(
        'custom_settings' => FALSE,
      ),
      'osha_wiki' => array(
        'custom_settings' => FALSE,
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
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'osha_resources' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'dangerous_substances' => array(
        'custom_settings' => TRUE,
      ),
      'osha_search_teaser' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '10',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '8',
        ),
        'redirect' => array(
          'weight' => '9',
        ),
        'language' => array(
          'weight' => '0',
        ),
        'xmlsitemap' => array(
          'weight' => '13',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_banner';
  $strongarm->value = '4';
  $export['language_content_type_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_banner';
  $strongarm->value = array();
  $export['menu_options_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_banner';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_banner';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_banner';
  $strongarm->value = '1';
  $export['node_preview_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_banner';
  $strongarm->value = 0;
  $export['node_submitted_banner'] = $strongarm;

  return $export;
}
