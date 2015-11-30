<?php
/**
 * @file
 * osha_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function osha_events_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_description|node|events|default';
  $field_group->group_name = 'group_events_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '2',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Description',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-events-description field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_events_description|node|events|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_event_details|node|events|default';
  $field_group->group_name = 'group_events_event_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event details',
    'weight' => '1',
    'children' => array(
      0 => 'field_city',
      1 => 'field_country_code',
      2 => 'field_organization',
      3 => 'field_start_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Event details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-events-event-details field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_events_event_details|node|events|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_links|node|events|default';
  $field_group->group_name = 'group_events_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '3',
    'children' => array(
      0 => 'field_website_of_event',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Links',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-events-links field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_events_links|node|events|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_related_documents|node|events|default';
  $field_group->group_name = 'group_events_related_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related resources',
    'weight' => '4',
    'children' => array(
      0 => 'field_related_documents',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Related resources',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-events-related-documents field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_events_related_documents|node|events|default'] = $field_group;

  return $export;
}
