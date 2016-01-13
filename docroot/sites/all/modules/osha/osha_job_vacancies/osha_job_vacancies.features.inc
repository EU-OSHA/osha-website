<?php
/**
 * @file
 * osha_job_vacancies.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_job_vacancies_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_job_vacancies_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function osha_job_vacancies_node_info() {
  $items = array(
    'job_vacancies' => array(
      'name' => 'Job vacancies',
      'base' => 'node_content',
      'description' => 'Job vacancies',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
