<?php
/**
 * @file
 * osha_blocks.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function osha_blocks_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_latest_oshnews';
  $context->description = 'Where portlet Latest news is shown';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
        'events' => 'events',
        'seminar' => 'seminar',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'tools-and-resources/blog' => 'tools-and-resources/blog',
        'node/5445' => 'node/5445',
      ),
    ),
    'views' => array(
      'values' => array(
        'blog' => 'blog',
        'search_blog' => 'search_blog',
        'seminars' => 'seminars',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Where portlet Latest news is shown');
  $export['context_latest_oshnews'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_newsletter';
  $context->description = 'Where to show newsletter and alerts portlets';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
        'calls' => 'calls',
        'events' => 'events',
        'highlight' => 'highlight',
        'news' => 'news',
        'seminar' => 'seminar',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'about-eu-osha/careers' => 'about-eu-osha/careers',
        'node/21' => 'node/21',
        'about-eu-osha/procurement' => 'about-eu-osha/procurement',
        'node/1472' => 'node/1472',
        'tools-and-resources/blog' => 'tools-and-resources/blog',
        'node/5445' => 'node/5445',
        'node/1460' => 'node/1460',
        'node/1411' => 'node/1411',
        'node/1463' => 'node/1463',
        'node/877' => 'node/877',
        'node/2427' => 'node/2427',
        'node/1495' => 'node/1495',
        'node/1464' => 'node/1464',
        'node/1456' => 'node/1456',
        'node/1468' => 'node/1468',
        'node/1457' => 'node/1457',
        'node/1410' => 'node/1410',
        'node/1450' => 'node/1450',
        'node/14993' => 'node/14993',
      ),
    ),
    'views' => array(
      'values' => array(
        'blog' => 'blog',
        'calls' => 'calls',
        'calls:page_1' => 'calls:page_1',
        'highlight' => 'highlight',
        'highlight:page' => 'highlight:page',
        'news' => 'news',
        'news:oshnews_list' => 'news:oshnews_list',
        'search_blog' => 'search_blog',
        'vacancies' => 'vacancies',
        'vacancies:page_1' => 'vacancies:page_1',
        'vacancies:page_2' => 'vacancies:page_2',
        'vacancies:page_3' => 'vacancies:page_3',
        'vacancies:page_4' => 'vacancies:page_4',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Where to show newsletter and alerts portlets');
  $export['context_newsletter'] = $context;

  return $export;
}
