<?php
/**
 * @file
 * osha_dangerous_substances.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function osha_dangerous_substances_filter_default_formats() {
  $formats = array();

  // Exported format: Dangerous substances.
  $formats['dangerous_substances'] = array(
    'format' => 'dangerous_substances',
    'name' => 'Dangerous substances',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  return $formats;
}
