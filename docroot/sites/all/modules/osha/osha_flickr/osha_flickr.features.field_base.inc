<?php
/**
 * @file
 * osha_flickr.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function osha_flickr_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_cover_flickr'.
  $field_bases['field_cover_flickr'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cover_flickr',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'flickrfield',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'flickrfield',
  );

  return $field_bases;
}
