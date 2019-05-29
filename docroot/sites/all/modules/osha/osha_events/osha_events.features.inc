<?php
/**
 * @file
 * osha_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
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
function osha_events_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function osha_events_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: homepage_news_and_events
  $nodequeues['homepage_news_and_events'] = array(
    'name' => 'homepage_news_and_events',
    'title' => 'Homepage news and events',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 1,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'events',
      1 => 'news',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function osha_events_node_info() {
  $items = array(
    'events' => array(
      'name' => 'Events',
      'base' => 'node_content',
      'description' => 'Events',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
