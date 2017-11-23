<?php
/**
 * @file
 * osha.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function osha_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[current-page:title] - [site:name]',
      ),
      'description' => array(
        'value' => 'EU OSHA information about occupational health and safety across EU countries. Find surveys, regulations and standards, risk assessment tools, frequent hazards at work and more about workplace safety and health.',
      ),
      'abstract' => array(
        'value' => '',
      ),
      'keywords' => array(
        'value' => 'eu osha, eu-osha, osha, regulations, standards, legislation, surveys, risk assessment, accident prevention, european agency, safety and health, health at work, safety at work, statistics, workplace safety, frequent hazards, occupational health and safety, assessment tools, eu, esener, napo, oshwiki, oira, healthy workplaces, information, emerging risks',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'standout' => array(
        'value' => '',
      ),
      'generator' => array(
        'value' => 'Drupal 7 (http://drupal.org)',
      ),
      'rights' => array(
        'value' => '',
      ),
      'image_src' => array(
        'value' => '',
      ),
      'canonical' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
      ),
      'publisher' => array(
        'value' => '',
      ),
      'author' => array(
        'value' => '',
      ),
      'original-source' => array(
        'value' => '',
      ),
      'revisit-after' => array(
        'value' => '',
        'period' => '',
      ),
      'content-language' => array(
        'value' => '',
      ),
    ),
  );

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[node:title] - [site:name]',
      ),
      'description' => array(
        'value' => '[node:summary]',
      ),
      'keywords' => array(
        'value' => '[node:field_tags] [node:field_thesaurus]',
      ),
    ),
  );

  return $config;
}
