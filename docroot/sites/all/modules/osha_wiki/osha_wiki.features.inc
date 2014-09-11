<?php
/**
 * @file
 * osha_wiki.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_wiki_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function osha_wiki_node_info() {
  $items = array(
    'wiki_page' => array(
      'name' => t('Wiki Page'),
      'base' => 'node_content',
      'description' => t('Selected Wiki page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
