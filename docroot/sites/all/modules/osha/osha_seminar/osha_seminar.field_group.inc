<?php
/**
 * @file
 * osha_seminar.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function osha_seminar_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_seminar_event_details|node|seminar|default';
  $field_group->group_name = 'group_seminar_event_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'seminar';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_seminar_end_date',
      1 => 'field_seminar_location',
      2 => 'field_seminar_start_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Event Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-seminar-event-details field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_seminar_event_details|node|seminar|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Event Details');

  return $field_groups;
}
