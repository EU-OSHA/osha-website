<?php
/**
 * @file
 * osha_note_to_editor.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_note_to_editor_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_note_to_editor_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function osha_note_to_editor_node_info() {
  $items = array(
    'note_to_editor' => array(
      'name' => t('Note to editor'),
      'base' => 'node_content',
      'description' => t('Notes to the editor'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
