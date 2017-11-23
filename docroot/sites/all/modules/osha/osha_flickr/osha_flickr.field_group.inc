<?php
/**
 * @file
 * osha_flickr.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function osha_flickr_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_album|node|flickr_gallery|form';
  $field_group->group_name = 'group_album';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'flickr_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Album',
    'weight' => '4',
    'children' => array(
      0 => 'field_flickr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-album field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_album|node|flickr_gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cover|node|flickr_gallery|form';
  $field_group->group_name = 'group_cover';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'flickr_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cover photo',
    'weight' => '3',
    'children' => array(
      0 => 'field_cover_flickr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cover field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cover|node|flickr_gallery|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Album');
  t('Cover photo');

  return $field_groups;
}
