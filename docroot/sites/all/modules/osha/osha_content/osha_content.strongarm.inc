<?php
/**
 * @file
 * osha_content.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function osha_content_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'no_translation_exceptions';
  $strongarm->value = '5445
7665
7666
7667
7668
7669
5846
1486
1487
1488
1447
1501
1502
1503
7690
2424
8131
9189
7332
9317';
  $export['no_translation_exceptions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'no_translation_nid';
  $strongarm->value = '7702';
  $export['no_translation_nid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'no_translation_type_exceptions';
  $strongarm->value = 'page
blog
events
seminar
job_vacancies
calls
press_contact
banner
news
directive
guideline
publication';
  $export['no_translation_type_exceptions'] = $strongarm;

  return $export;
}
