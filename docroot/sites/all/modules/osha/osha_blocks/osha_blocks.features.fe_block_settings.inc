<?php
/**
 * @file
 * osha_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osha_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['osha_blocks-article_related_icons'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'article_related_icons',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_blocks',
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
    'title' => 'Related resources',
    'visibility' => 0,
  );

  $export['osha_blocks-osha_archived_content'] = array(
    'cache' => 6,
    'custom' => 0,
    'delta' => 'osha_archived_content',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_blocks',
    'node_types' => array(
      0 => 'article',
      1 => 'calls',
      2 => 'directive',
      3 => 'highlight',
      4 => 'infographic',
      5 => 'job_vacancies',
      6 => 'news',
      7 => 'press_release',
      8 => 'publication',
      9 => 'seminar',
    ),
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
        'region' => 'content',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 7,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['osha_blocks-osha_block_group_related'] = array(
    'cache' => 6,
    'custom' => 0,
    'delta' => 'osha_block_group_related',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_blocks',
    'node_types' => array(),
    'pages' => 'node/13937
node/13962
node/18240',
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
        'weight' => 18,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Related',
    'visibility' => 0,
  );

  $export['osha_blocks-osha_transl_extra_links'] = array(
    'cache' => 6,
    'custom' => 0,
    'delta' => 'osha_transl_extra_links',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_blocks',
    'node_types' => array(
      0 => 'article',
      1 => 'calls',
      2 => 'directive',
      3 => 'fop_page',
      4 => 'infographic',
      5 => 'press_release',
      6 => 'seminar',
    ),
    'pages' => 'node/880
node/880/*
node/1455
node/7299',
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
        'weight' => 15,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['osha_blocks-oshwiki_featured_articles'] = array(
    'cache' => 6,
    'custom' => 0,
    'delta' => 'oshwiki_featured_articles',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_blocks',
    'node_types' => array(
      0 => 'article',
      1 => 'publication',
    ),
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
        'region' => 'content',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 42,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'OSHwiki featured articles',
    'visibility' => 0,
  );

  $export['osha_wiki-osha_wiki_notopic'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'osha_wiki_notopic',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_wiki',
    'node_types' => array(),
    'pages' => 'node/875',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => -3,
      ),
      'osha_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'osha_admin',
        'weight' => -3,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 16,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -3,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_wiki-osha_wiki_related_content'] = array(
    'cache' => 4,
    'custom' => 0,
    'delta' => 'osha_wiki_related_content',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_wiki',
    'node_types' => array(
      0 => 'article',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -30,
      ),
      'osha_admin' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'osha_admin',
        'weight' => -30,
      ),
      'osha_frontend' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'osha_frontend',
        'weight' => 17,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -30,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
