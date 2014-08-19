<?php
/**
 * @file
 * osha_calls.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_calls_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function osha_calls_node_info() {
  $items = array(
    'calls' => array(
      'name' => t('Calls'),
      'base' => 'node_content',
      'description' => t('Calls content type - OSHA Project'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
