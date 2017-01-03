<?php
/**
 * @file
 * osha_dangerous_substances.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_dangerous_substances_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_dangerous_substances_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function osha_dangerous_substances_node_info() {
  $items = array(
    'dangerous_substances' => array(
      'name' => 'Dangerous substances',
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
