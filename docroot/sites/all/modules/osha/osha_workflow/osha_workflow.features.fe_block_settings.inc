<?php
/**
 * @file
 * osha_workflow.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osha_workflow_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['osha_workflow-osha_workflow_info'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'osha_workflow_info',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_workflow',
    'node_types' => array(),
    'pages' => 'node/*',
    'roles' => array(
      'authenticated user' => 2,
    ),
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
        'weight' => -99,
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

  $export['workbench-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'workbench',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -99,
      ),
      'osha_admin' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'osha_admin',
        'weight' => -99,
      ),
      'osha_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_frontend',
        'weight' => -63,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -99,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
