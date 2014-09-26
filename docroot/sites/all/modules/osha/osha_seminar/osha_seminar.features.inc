<?php
/**
 * @file
 * osha_seminar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_seminar_ctools_plugin_api($module = NULL, $api = NULL) {
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
function osha_seminar_node_info() {
  $items = array(
    'seminar' => array(
      'name' => t('Seminar'),
      'base' => 'node_content',
      'description' => t('Seminar content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
