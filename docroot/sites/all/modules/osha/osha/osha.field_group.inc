<?php
/**
 * @file
 * osha.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function osha_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_resources|field_collection_item|field_colection_related_resource|form';
  $field_group->group_name = 'group_related_resources';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_colection_related_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '1',
    'children' => array(
      0 => 'field_related_resource_title',
      1 => 'field_related_resources_files',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-resources field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_related_resources|field_collection_item|field_colection_related_resource|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Group');

  return $field_groups;
}
