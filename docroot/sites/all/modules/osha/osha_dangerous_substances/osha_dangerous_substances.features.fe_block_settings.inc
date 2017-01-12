<?php
/**
 * @file
 * osha_dangerous_substances.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osha_dangerous_substances_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['osha_dangerous_substances-block_osha_dangerous_substances'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'block_osha_dangerous_substances',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_dangerous_substances',
    'node_types' => array(),
    'pages' => 'themes/dangerous-substances/search
themes/dangerous-substances/search/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => 'before_footer',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
