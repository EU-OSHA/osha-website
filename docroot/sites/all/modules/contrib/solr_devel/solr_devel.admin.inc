<?php

/**
 * @file
 * Administrative page callbacks for the Solr Devel module.
 */

/**
 * Displays the admin settings form.
 *
 * @ingroup forms
 */
function solr_devel_settings_form($form, &$form_state) {

  // Arguments for the description.
  $args = array(
    '@permissions-url' => url('admin/people/permissions', array('fragment' => 'module-solr_devel')),
  );

  $form['solr_devel:debug_queries'] = array(
    '#type' => 'checkbox',
    '#title' => t('Debug Solr queries'),
    '#default_value' => variable_get('solr_devel:debug_queries', 1),
    '#description' => t('Display debug information about Solr queries, for example a breakdown of how documents are ranked in search results and information on the Solr request. <strong>Debugging can decrease solr performance substantially</strong>, so make sure to grant the <a href="@permissions-url">view solr_devel information</a> permissions only to administrative users.', $args),
  );

  return system_settings_form($form);
}
