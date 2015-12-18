<?php
/**
 * @file
 * osha_job_vacancies.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function osha_job_vacancies_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'closed_job_vacancies_view';
  $path_breadcrumb->name = 'Closed job vacancies View';
  $path_breadcrumb->path = 'jobs_archive';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'About EU-OSHA',
      1 => 'Careers',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'about-eu-osha',
      1 => 'about-eu-osha/careers',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['closed_job_vacancies_view'] = $path_breadcrumb;

  return $export;
}
