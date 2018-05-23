<?php

/**
 * @file
 * Musculoskeletal Disorders command for Drush
 */

/**
 * Implements hook_drush_command().
 */
function osha_musculoskeletal_disorders_drush_command() {
  $items = array();
  $items['musculoskeletal_disorders'] = array(
    'description' => "Musculoskeletal Disorders terms install",
    'examples' => array(
      'drush musculoskeletal_disorders' => 'musculoskeletal_disorders',
    ),
    'aliases' => array('musculoskeletal_disorders'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  return $items;
}

/**
 * Actual function run by the musculoskeletal_disorders command.
 */
function drush_osha_musculoskeletal_disorders_musculoskeletal_disorders($source = NULL, $destination = NULL) {
  print "Musculoskeletal Disorders terms install\n";
  osha_musculoskeletal_disorders_add_taxonomy();
}
