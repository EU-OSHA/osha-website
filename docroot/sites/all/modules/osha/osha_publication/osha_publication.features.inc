<?php
/**
 * @file
 * osha_publication.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_publication_ctools_plugin_api($module = NULL, $api = NULL) {
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
function osha_publication_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function osha_publication_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: publication_queue
  $nodequeues['publication_queue'] = array(
    'name' => 'publication_queue',
    'title' => 'Publication Slideshow',
    'subqueue_title' => '',
    'size' => 5,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 1,
    'i18n' => 1,
    'insert_at_front' => 0,
    'unique_entries' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'publication',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function osha_publication_node_info() {
  $items = array(
    'publication' => array(
      'name' => 'Publication',
      'base' => 'node_content',
      'description' => 'Publications',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
