<?php
/**
 * @file
 * Metatag include.
 */

/**
 * Implements hook_metatag_config_instance_info().
 */
function metatag_views_overview_metatag_config_instance_info() {
  // Get collection of views having menu callbacks.
  $views = views_get_applicable_views('uses hook menu');

  foreach ($views as $key => $view_info) {
    $info['view:' . $view_info[0]->name . '-' . $view_info[1]] = array(
      'label' => $view_info[0]->human_name . ' - ' . $view_info[0]->display[$view_info[1]]->display_title . ' (' . $view_info[1] . ')',
    );
  }

  return $info;
}
