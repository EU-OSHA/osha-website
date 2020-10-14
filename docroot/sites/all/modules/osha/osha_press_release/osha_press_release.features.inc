<?php
/**
 * @file
 * osha_press_release.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_press_release_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_press_release_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function osha_press_release_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: featured_press_release
  $nodequeues['featured_press_release'] = array(
    'name' => 'featured_press_release',
    'title' => 'Featured Press Release',
    'subqueue_title' => '',
    'size' => 1,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'insert_at_front' => 0,
    'unique_entries' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'highlight',
      1 => 'press_release',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function osha_press_release_node_info() {
  $items = array(
    'press_release' => array(
      'name' => 'Press release',
      'base' => 'node_content',
      'description' => 'Press releases',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
