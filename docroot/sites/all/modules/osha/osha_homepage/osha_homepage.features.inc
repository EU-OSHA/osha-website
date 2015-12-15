<?php
/**
 * @file
 * osha_homepage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_homepage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_homepage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function osha_homepage_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: esener_carousel
  $nodequeues['esener_carousel'] = array(
    'name' => 'esener_carousel',
    'title' => 'Esener Carousel',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 1,
    'subqueues' => 1,
    'types' => array(
      0 => 'banner',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function osha_homepage_node_info() {
  $items = array(
    'banner' => array(
      'name' => 'Banner',
      'base' => 'node_content',
      'description' => 'Banners for home page',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
