<?php
/**
 * @file
 * osha_register_records.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function osha_register_records_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_resources|node|register_records|default';
  $field_group->group_name = 'group_related_resources';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'register_records';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Resources:',
    'weight' => '2',
    'children' => array(
      0 => 'field_documentation',
      1 => 'field_events_and_meetings',
      2 => 'field_finance_and_procurement',
      3 => 'field_general_services',
      4 => 'field_governance',
      5 => 'field_human_resources',
      6 => 'field_ict',
      7 => 'field_missions',
      8 => 'field_relationship_management',
      9 => 'field_research_activities',
      10 => 'field_staff_committee',
      11 => 'field_websites_online_services',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Related Resources:',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-related-resources field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_related_resources|node|register_records|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Related Resources:');

  return $field_groups;
}
