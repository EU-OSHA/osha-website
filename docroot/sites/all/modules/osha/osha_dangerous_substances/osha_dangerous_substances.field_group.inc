<?php
/**
 * @file
 * osha_dangerous_substances.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function osha_dangerous_substances_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access_condition|node|dangerous_substances|form';
  $field_group->group_name = 'group_access_condition';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dangerous_substances';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access condition',
    'weight' => '54',
    'children' => array(
      0 => 'field_contact_address',
      1 => 'field_disclaimer',
      2 => 'field_other_information',
      3 => 'field_ownership_information',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-access-condition field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_access_condition|node|dangerous_substances|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access condition');

  return $field_groups;
}
