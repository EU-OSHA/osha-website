<?php
/**
 * @file
 * osha_blocks.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function osha_blocks_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_calls';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_calls'] = $strongarm;

  return $export;
}
