<?php
/**
 * @file
 * osha_job_vacancies.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function osha_job_vacancies_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = '_careers_accordion';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 2;
  $quicktabs->title = 'Careers accordion';
  $quicktabs->tabs = array(
    0 => array(
      'nid' => '5330',
      'view_mode' => 'teaser',
      'hide_title' => 1,
      'title' => 'Who we employ',
      'weight' => '-100',
      'type' => 'node',
    ),
    1 => array(
      'nid' => '5331',
      'view_mode' => 'teaser',
      'hide_title' => 1,
      'title' => 'Reserve lists',
      'weight' => '-99',
      'type' => 'node',
    ),
    2 => array(
      'vid' => 'vacancies',
      'display' => 'page_2',
      'args' => '',
      'title' => 'Open vacancies',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'vacancies',
      'display' => 'page_3',
      'args' => '',
      'title' => 'Evaluation underway vacancies',
      'weight' => '-97',
      'type' => 'view',
    ),
    4 => array(
      'vid' => 'vacancies',
      'display' => 'page_1',
      'args' => '',
      'title' => 'Closed vacancies',
      'weight' => '-96',
      'type' => 'view',
    ),
    5 => array(
      'nid' => '5332',
      'view_mode' => 'teaser',
      'hide_title' => 1,
      'title' => 'Spontaneous applications',
      'weight' => '-95',
      'type' => 'node',
    ),
    6 => array(
      'nid' => '5333',
      'view_mode' => 'teaser',
      'hide_title' => 1,
      'title' => 'Enquiries',
      'weight' => '-94',
      'type' => 'node',
    ),
  );
  $quicktabs->renderer = 'accordion';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 0,
    'jquery_ui' => array(
      'autoHeight' => 1,
      'collapsible' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Careers accordion');
  t('Closed vacancies');
  t('Enquiries');
  t('Evaluation underway vacancies');
  t('Open vacancies');
  t('Reserve lists');
  t('Spontaneous applications');
  t('Who we employ');

  $export['_careers_accordion'] = $quicktabs;

  return $export;
}
