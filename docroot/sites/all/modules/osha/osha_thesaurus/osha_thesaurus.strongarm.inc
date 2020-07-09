<?php
/**
 * @file
 * osha_thesaurus.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function osha_thesaurus_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__thesaurus';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '15',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '14',
        ),
        'redirect' => array(
          'weight' => '13',
        ),
        'workbench_access' => array(
          'weight' => '12',
        ),
        'xmlsitemap' => array(
          'weight' => '12',
        ),
        'language' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__thesaurus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_thesaurus';
  $strongarm->value = '4';
  $export['language_content_type_thesaurus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_thesaurus';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_thesaurus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_thesaurus';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_thesaurus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_thesaurus';
  $strongarm->value = array();
  $export['node_options_thesaurus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_thesaurus';
  $strongarm->value = '1';
  $export['node_preview_thesaurus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_thesaurus';
  $strongarm->value = 1;
  $export['node_submitted_thesaurus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_thesaurus';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_thesaurus'] = $strongarm;

  return $export;
}
