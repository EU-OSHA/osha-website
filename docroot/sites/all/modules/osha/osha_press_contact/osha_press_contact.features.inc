<?php
/**
 * @file
 * osha_press_contact.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_press_contact_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_press_contact_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function osha_press_contact_node_info() {
  $items = array(
    'press_contact' => array(
      'name' => t('Press Contact'),
      'base' => 'node_content',
      'description' => t('Press Contact for OSHA Project'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
