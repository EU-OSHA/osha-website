<?php
/**
 * @file
 * osha_register_records.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_register_records_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function osha_register_records_node_info() {
  $items = array(
    'register_records' => array(
      'name' => 'Register of records Article',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
