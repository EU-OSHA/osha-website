<?php
/**
 * @file
 * osha_newsletter.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osha_newsletter_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['osha_newsletter-osha_newsletter_image'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'osha_newsletter_image',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_newsletter',
    'node_types' => array(),
    'pages' => 'oshmail-newsletter
node/9',
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
        'weight' => 2,
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

  $export['osha_newsletter-osha_newsletter_latest'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'osha_newsletter_latest',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_newsletter',
    'node_types' => array(),
    'pages' => 'oshmail-newsletter
node/9',
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
        'region' => 'sidebar_second',
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
    'title' => 'Display the latest newsletters',
    'visibility' => 1,
  );

  $export['osha_newsletter-osha_newsletter_subscribe'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'osha_newsletter_subscribe',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_newsletter',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => -30,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => -30,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -30,
      ),
    ),
    'title' => 'OSHMail newsletter',
    'visibility' => 0,
  );

  $export['osha_newsletter-osha_newsletter_subscribe_extra'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'osha_newsletter_subscribe_extra',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_newsletter',
    'node_types' => array(),
    'pages' => 'oshmail-newsletter
node/9',
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
        'weight' => 1,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'OSHMail newsletter',
    'visibility' => 1,
  );

  return $export;
}
