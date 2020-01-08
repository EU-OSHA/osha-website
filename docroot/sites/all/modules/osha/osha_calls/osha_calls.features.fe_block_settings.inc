<?php
/**
 * @file
 * osha_calls.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osha_calls_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['quicktabs-calls_quicktab'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'calls_quicktab',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'quicktabs',
    'node_types' => array(),
    'pages' => 'node/1472',
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
        'region' => 'content',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 22,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-calls-block_archived_calls'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'calls-block_archived_calls',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/1472',
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
        'region' => '',
        'status' => 0,
        'theme' => 'osha_frontend',
        'weight' => 137,
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

  $export['views-calls-block_ongoing_calls'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'calls-block_ongoing_calls',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
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
        'region' => '',
        'status' => 0,
        'theme' => 'osha_frontend',
        'weight' => 138,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-calls-block_open_calls'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'calls-block_open_calls',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/1472',
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
        'region' => '',
        'status' => 0,
        'theme' => 'osha_frontend',
        'weight' => 139,
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
