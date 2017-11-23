<?php
/**
 * @file
 * The admin settings for the Flickr Tags module.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function flickr_tags_form_flickr_admin_settings_alter(&$form, &$form_state) {
  $form['#validate'][] = 'flickr_tags_admin_settings_validate';
  $form['tags_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tags options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 22,
  );
  $form['tags_settings']['flickr_tags_in_cloud'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of tags in a tag cloud'),
    '#required' => TRUE,
    '#default_value' => variable_get('flickr_tags_in_cloud', 150),
    '#description' => t('Applies on the tag cloud on a user profile pages at <em>flickr/%uid/tags/cloud</em>.'),
    '#size' => 3,
    '#maxlength' => 3,
  );
  $form['tags_settings']['flickr_tags_minfont'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum font size'),
    '#required' => TRUE,
    '#default_value' => variable_get('flickr_tags_minfont', 0.7),
    '#size' => 3,
    '#maxlength' => 3,
    '#field_suffix' => t('em'),
    '#attributes' => array('class' => array('flickr-form-align')),
  );
  $form['tags_settings']['flickr_tags_maxfont'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum font size'),
    '#required' => TRUE,
    '#default_value' => variable_get('flickr_tags_maxfont', 3.5),
    '#size' => 3,
    '#maxlength' => 3,
    '#field_suffix' => t('em'),
    '#attributes' => array('class' => array('flickr-form-align')),
  );
}

/**
 * Validate user input.
 */
function flickr_tags_admin_settings_validate($form, &$form_state) {
  // Validate tags in cloud.
  $limit = trim($form_state['values']['flickr_tags_in_cloud']);
  if (!ctype_digit($limit) || $limit < 1) {
    form_set_error('flickr_tags_in_cloud', t('Set an integer from 1 to 999.'));
  }
  // Validate the tags font size.
  $limit = trim($form_state['values']['flickr_tags_minfont']);
  if (!is_numeric($limit) || $limit < 0) {
    form_set_error('flickr_tags_minfont', t('Set a number from 0 to 999.'));
  }
  $limit = trim($form_state['values']['flickr_tags_maxfont']);
  if (!is_numeric($limit) || $limit < 0) {
    form_set_error('flickr_tags_maxfont', t('Set a number from 0 to 999.'));
  }
}
