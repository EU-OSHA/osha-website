<?php

/**
 * Administration form for the OSHA newsletter module.
 *
 * @return array
 *   Form array
 */
function osha_newsletter_admin_form() {
  $form = array();
  $form['osha_newsletter_listserv'] = array(
    '#type' => 'textfield',
    '#title' => t('Listserv e-mail address'),
    '#default_value' => variable_get('osha_newsletter_listserv', 'listserv@list.osha.europa.eu'),
    '#size' => 40,
    '#attributes' => array('tabindex' => 1),
    '#maxlength' => 60,
    '#description' => t('Destination listserv account to send the subscribe/unsubscribe newsletter requests'),
    '#required' => TRUE,
  );

  $form['osha_newsletter_listserv_from'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail author'),
    '#default_value' => variable_get('osha_newsletter_listserv_from', 'oshmail@osha.europa.eu'),
    '#attributes' => array('tabindex' => 2),
    '#size' => 40,
    '#maxlength' => 40,
    '#description' => t('E-mail sender as it will appear in the "From" header of the e-mail'),
    '#required' => TRUE,
  );

  $form['osha_newsletter_list_name'] = array(
    '#type' => 'textfield',
    '#title' => t('List name'),
    '#default_value' => variable_get('osha_newsletter_list_name', 'OSHMail-Test'),
    '#attributes' => array('tabindex' => 2),
    '#size' => 40,
    '#maxlength' => 40,
    '#description' => t('The newsletter list name'),
    '#required' => TRUE,
  );

  $entity_info = entity_get_info('node');
  if (isset($entity_info['view modes'])) {
    $options = array();
    foreach ($entity_info['view modes'] as $machine_name => $info) {
      $options[$machine_name] = $info['label'];
    }
    $form['osha_newsletter_node_view_mode'] = array(
      '#type' => 'select',
      '#attributes' => array('tabindex' => 4),
      '#title' => t('Default view mode'),
      '#options' => $options,
      '#default_value' => variable_get('osha_newsletter_node_view_mode', 'newsletter_item'),
      '#description' => t('Default view mode when render nodes in newsletter'),
      '#required' => FALSE,
    );
  }

  $form['osha_newsletter_after_max_nodes'] = array(
    '#type' => 'textfield',
    '#title' => t('Max number of nodes after creation'),
    '#default_value' => variable_get('osha_newsletter_after_max_nodes', 30),
    '#attributes' => array('tabindex' => 4),
    '#size' => 40,
    '#maxlength' => 40,
    '#description' => t('Add the maximum number of nodes of each content type should be added when using "after creation" functionality.'),
    '#required' => TRUE,
  );

  $active_sections = variable_get('osha_newsletter_active_sections', []);
  $options = array();

  $voc = taxonomy_vocabulary_machine_name_load('newsletter_sections');
  $term_tree = taxonomy_get_tree($voc->vid);
  foreach ($term_tree as $term) {
    $options[$term->tid] = $term->name . ' ' . l(t('(edit)'), "taxonomy/term/{$term->tid}/edit");
  }
  $form['osha_newsletter_active_sections'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Active newsletter sections'),
    '#options' => $options,
    '#default_value' => $active_sections,
  );

  $allowed_bundles = variable_get(
    'osha_newsletter_allowed_bundles',
    array(
      // TODO:EDW: check 'event' - non existing for now.
      'publication', 'blog', 'news', 'press_release', 'highlight', 'newsletter_article'
    )
  );
  $entity_info = entity_get_info();

  $options = array();
  foreach ($entity_info['node']['bundles'] as $machine_name => $setting) {
    $options[$machine_name] = $setting['label'];
  }

  $form['osha_newsletter_allowed_bundles'] = array(
    '#attributes' => array('tabindex' => 5),
    '#type' => 'checkboxes',
    '#title' => t('Add to newsletter items of the following types'),
    '#options' => $options,
    '#default_value' => $allowed_bundles,
  );

  $form['osha_newsletter_term_ct_map'] = array(
    '#title' => t('Mapping'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#tree' => TRUE,
  );

  $term_ct_map = variable_get('osha_newsletter_term_ct_map', array());
  $tax = taxonomy_get_tree($voc->vid);
  $options_tax = array('' => '-- Please select --');
  foreach ($tax as $term) {
    $options_tax[$term->uuid] = $term->name;
  }

  $options_view_modes = array('' => '-- Please select --');
  if (isset($entity_info['node']['view modes'])) {
    foreach ($entity_info['node']['view modes'] as $machine_name => $info) {
      $options_view_modes[$machine_name] = $info['label'];
    }
  }

  foreach ($options as $content_type => $title) {
    $form['osha_newsletter_term_ct_map'][$content_type] = array(
      '#type' => 'select',
      '#title' => $title,
      '#options' => $options_tax,
      '#default_value' => !empty($term_ct_map[$content_type]) ? $term_ct_map[$content_type] : '',
    );
    $form['osha_newsletter_term_ct_map']['view_mode_'.$content_type] = array(
      '#type' => 'select',
      '#title' => t('View mode for ').$title,
      '#options' => $options_view_modes,
      '#default_value' => !empty($term_ct_map['view_mode_'.$content_type]) ? $term_ct_map['view_mode_'.$content_type] : _default_view_mode($content_type),
      '#description' => t('Default view mode when render this content type in newsletter'),
    );
  }

  // Set tabindex on submit button.
  $ret = system_settings_form($form);
  if (isset($ret['actions']['submit'])) {
    $ret['actions']['submit']['#attributes'] = array('tabindex' => 5);
  }

  return $ret;
}

function _default_view_mode($content_type){
  if ($content_type == 'highlight') {
    return 'highlights_item';
  } else {
    return 'newsletter_item';
  }
}

