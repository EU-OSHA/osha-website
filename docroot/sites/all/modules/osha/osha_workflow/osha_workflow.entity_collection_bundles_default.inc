<?php
/**
 * @file
 * osha_workflow.entity_collection_bundles_default.inc
 */

/**
 * Implements hook_entity_collection_bundles_default().
 */
function osha_workflow_entity_collection_bundles_default() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'moderators_group';
  $preset->storage = 'entity_collection_storage_db';
  $preset->label = 'Moderators Group';
  $preset->description = 'Group of users that can be assigned to the content publishing workflow';
  $preset->settings = array();
  $export['moderators_group'] = $preset;

  return $export;
}
