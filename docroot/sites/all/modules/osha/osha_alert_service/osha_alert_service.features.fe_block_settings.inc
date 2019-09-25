<?php
/**
 * @file
 * osha_alert_service.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osha_alert_service_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['osha_alert_service-osha_alert_block_front_view'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'osha_alert_block_front_view',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => -28,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => -28,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 1,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -28,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['osha_alert_service-osha_alert_service_subscribe'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'osha_alert_service_subscribe',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'alertservice
node/5432',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'osha_admin' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'osha_admin',
        'weight' => 0,
      ),
      'osha_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['osha_alert_service-osha_blog_rss'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'osha_blog_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => -5,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => -5,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => -5,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -5,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['osha_alert_service-osha_calls_rss'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'osha_calls_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'node/1472',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => -5,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => -5,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => -5,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -5,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_alert_service-osha_directives_rss'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'osha_directives_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'node/11',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => -5,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => -5,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => -5,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -5,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_alert_service-osha_events_rss'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'osha_events_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'oshevents
node/5322',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 1,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 1,
      ),
      'osha_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 1,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_alert_service-osha_guidelines_rss'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'osha_guidelines_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'node/2544',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => -5,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => -5,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => -5,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -5,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_alert_service-osha_job_vacancies_rss'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'osha_job_vacancies_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'node/21',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 1,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => 1,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => -5,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 1,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_alert_service-osha_news_rss'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'osha_news_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'oshnews
highlights',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => -5,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => -5,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => -5,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -5,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_alert_service-osha_seminar_rss'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'osha_seminar_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'node/2427',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => -5,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => -5,
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
        'weight' => -5,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_alert_service-press_release_rss'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'press_release_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'about-eu-osha/press-room
about-eu-osha/press-releases',
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
        'weight' => -8,
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
