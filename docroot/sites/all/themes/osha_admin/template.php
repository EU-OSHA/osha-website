<?php
/**
 * @file template.php
 */


/**
 * Implements hook_preprocess_HOOK() for theme_file_icon().
 *
 * Change the icon directory to use icons from this theme.
 */
function osha_admin_preprocess_file_icon(&$variables) {
  $variables['icon_directory'] = drupal_get_path('theme', 'osha_frontend') . '/images/file_icons';
}

function osha_admin_preprocess_views_view(&$vars) {
  $view = &$vars['view'];
  // Make sure it's the correct view
  if ($view->name == 'events') {
    // add needed javascript
    drupal_add_js(drupal_get_path('theme', 'osha_admin') . '/../osha_frontend/js/color_events_backend.js');
  }
}

function osha_admin_menu_local_tasks_alter(&$data, $router_item, $root_path) {
  foreach ($data['tabs'][0]['output'] as &$tab) {
    if ($tab['#link']['path'] == 'node/%/open_all_translations') {
      $tab['#link']['path'] = '#';
      $tab['#link']['localized_options']['attributes']['id'][] = 'menu_local_task_open_all_translations';
    }
    elseif ($tab['#link']['path'] == 'node/%/view_all_translations') {
      $tab['#link']['path'] = '#';
      $tab['#link']['localized_options']['attributes']['id'][] = 'menu_local_task_view_all_translations';
    }
  }
}

/**
 * Implements hook_preprocess_page
 */
function osha_admin_preprocess_page(&$variables){
  // MC-123 Open all languages with one click
  if (isset($variables['node'])) {
    $node = $variables['node'];
    drupal_add_js(array(
      'osha' => array(
        'node_nid' => $node->nid,
        'node_translations' => array_keys($node->translations->data),
        'is_publication_node' => $node->type == 'publication',
        'path_alias' => drupal_get_path_alias('node/' . $node->nid),
      ),
    ), array('type' => 'setting'));
    drupal_add_js(drupal_get_path('module', 'osha') . '/js/open_all_translations.js');
  }
}
