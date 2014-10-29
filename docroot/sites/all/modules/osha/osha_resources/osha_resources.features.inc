<?php
/**
 * @file
 * osha_resources.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_resources_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function osha_resources_node_info() {
  $items = array(
    'resources' => array(
      'name' => t('Resources'),
      'base' => 'node_content',
      'description' => t('Additional resources for other content types'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
