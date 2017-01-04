<?php

/**
 * @file
 * Dangerous substances command for Drush
 */

/**
 * Implements hook_drush_command().
 */
function dangerous_substances_drush_command() {
  $items = array();
  $items['dangerous_substances'] = array(
    'description' => "Dangerous substances terms install",
    'examples' => array(
      'drush dangerous_substances' => 'dangerous_substances',
    ),
    'aliases' => array('dangerous_substances'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  return $items;
}

/**
 * Actual function run by the dangerous_substances command.
 */
function drush_dangerous_substances($source = NULL, $destination = NULL) {
  print "Dangerous substances terms install\n";
  osha_dangerous_substances_add_taxonomy();
}
