<?php
/**
 * @file
 * osha_linkchecker.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function osha_linkchecker_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_action_status_code_301';
  $strongarm->value = '0';
  $export['linkchecker_action_status_code_301'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_action_status_code_404';
  $strongarm->value = '0';
  $export['linkchecker_action_status_code_404'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_check_connections_max';
  $strongarm->value = '8';
  $export['linkchecker_check_connections_max'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_check_library';
  $strongarm->value = 'core';
  $export['linkchecker_check_library'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_check_links_interval';
  $strongarm->value = '2419200';
  $export['linkchecker_check_links_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_check_links_types';
  $strongarm->value = '0';
  $export['linkchecker_check_links_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_check_useragent';
  $strongarm->value = 'Drupal (+http://drupal.org/)';
  $export['linkchecker_check_useragent'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_disable_link_check_for_urls';
  $strongarm->value = 'example.com
example.net
example.org';
  $export['linkchecker_disable_link_check_for_urls'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_a';
  $strongarm->value = 1;
  $export['linkchecker_extract_from_a'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_audio';
  $strongarm->value = 0;
  $export['linkchecker_extract_from_audio'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_embed';
  $strongarm->value = 0;
  $export['linkchecker_extract_from_embed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_iframe';
  $strongarm->value = 0;
  $export['linkchecker_extract_from_iframe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_img';
  $strongarm->value = 0;
  $export['linkchecker_extract_from_img'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_object';
  $strongarm->value = 0;
  $export['linkchecker_extract_from_object'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_video';
  $strongarm->value = 0;
  $export['linkchecker_extract_from_video'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_filter_blacklist';
  $strongarm->value = array(
    'filter_autop' => 'filter_autop',
    'media_filter' => 0,
    'filter_url' => 0,
    'pathologic' => 0,
    'filter_htmlcorrector' => 0,
    'filter_html_escape' => 0,
    'media_filter_paragraph_fix' => 0,
    'filter_html' => 0,
    'osha_tmgmt_filter_oiraurl' => 0,
    'osha_tmgmt_filter_id' => 0,
    'spamspan' => 0,
  );
  $export['linkchecker_filter_blacklist'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_ignore_response_codes';
  $strongarm->value = '200
206
302
304
401
403
301';
  $export['linkchecker_ignore_response_codes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_impersonate_user';
  $strongarm->value = 'admin';
  $export['linkchecker_impersonate_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_scan_blocks';
  $strongarm->value = 0;
  $export['linkchecker_scan_blocks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_scan_comments';
  $strongarm->value = 0;
  $export['linkchecker_scan_comments'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_scan_nodetypes';
  $strongarm->value = array(
    'article' => 'article',
    'banner' => 'banner',
    'page' => 'page',
    'blog' => 'blog',
    'calls' => 'calls',
    'press_contact' => 'press_contact',
    'dangerous_substances' => 'dangerous_substances',
    'directive' => 'directive',
    'events' => 'events',
    'external_url' => 'external_url',
    'file' => 'file',
    'flickr' => 'flickr',
    'guideline' => 'guideline',
    'highlight' => 'highlight',
    'job_vacancies' => 'job_vacancies',
    'musculoskeletal_disorders' => 'musculoskeletal_disorders',
    'news' => 'news',
    'newsletter_article' => 'newsletter_article',
    'note_to_editor' => 'note_to_editor',
    'press_release' => 'press_release',
    'publication' => 'publication',
    'seminar' => 'seminar',
    'slideshare' => 'slideshare',
    'youtube' => 'youtube',
    '25th_anniversary' => 0,
    'dvs_survey' => 0,
    'e_guide' => 0,
    'fop_page' => 0,
    'flickr_gallery' => 0,
    'infographic' => 0,
    'twitter_tweet_feed' => 0,
    'twitter_user_profile' => 0,
    'webform' => 0,
    'wiki_page' => 0,
  );
  $export['linkchecker_scan_nodetypes'] = $strongarm;

  return $export;
}
