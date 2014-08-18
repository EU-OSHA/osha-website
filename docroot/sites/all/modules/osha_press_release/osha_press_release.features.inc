<?php
/**
 * @file
 * osha_press_release.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_press_release_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function osha_press_release_node_info() {
  $items = array(
    'press_release' => array(
      'name' => t('Press release'),
      'base' => 'node_content',
      'description' => t('Press release content type - OSHA Project'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
