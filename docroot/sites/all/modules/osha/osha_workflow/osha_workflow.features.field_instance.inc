<?php
/**
 * @file
 * osha_workflow.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function osha_workflow_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-section-field_ldap_section_code'.
  $field_instances['taxonomy_term-section-field_ldap_section_code'] = array(
    'bundle' => 'section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_ldap_section_code',
    'label' => 'LDAP Code',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 41,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('LDAP Code');

  return $field_instances;
}
