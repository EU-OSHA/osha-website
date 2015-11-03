<?php
/**
 * @file
 * osha_eguide.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_eguide_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function osha_eguide_node_info() {
  $items = array(
    'e_guide' => array(
      'name' => 'e-Guide',
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
