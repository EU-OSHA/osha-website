<?php
/**
 * @file
 * osha_publication.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function osha_publication_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_summary_resources|node|publication|default';
  $field_group->group_name = 'group_summary_resources';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Summary & Resources',
    'weight' => '13',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Summary & Resources',
      'instance_settings' => array(
        'classes' => 'group-summary-resources field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h3',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_summary_resources|node|publication|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_summary_resources|node|publication|form';
  $field_group->group_name = 'group_summary_resources';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Summary & Resources',
    'weight' => '18',
    'children' => array(
      0 => 'field_publication_related_res',
      1 => 'field_related_publications',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Summary & Resources',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_summary_resources|node|publication|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Summary & Resources');

  return $field_groups;
}
