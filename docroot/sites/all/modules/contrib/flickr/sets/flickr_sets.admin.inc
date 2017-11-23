<?php
/**
 * @file
 * The admin settings for the Flickr Sets module.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function flickr_sets_form_flickr_admin_settings_alter(&$form, &$form_state) {
  $form['#validate'][] = 'flickr_sets_admin_settings_validate';
  $form['photoset_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Photoset options'),
    '#description' => t('Clear the cache on form submit.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 20,
  );
  $form['photoset_settings']['flickr_sets_thumb_default_size'] = array(
    '#type' => 'select',
    '#title' => t('Size for the photo representing a set'),
    '#default_value' => variable_get('flickr_sets_thumb_default_size', 's'),
    '#options' => array(
      's' => t('s: 75 px square'),
      't' => t('t: 100 px on longest side'),
      'q' => t('q: 150 px square'),
      'm' => t('m: 240 px on longest side'),
      'n' => t('n: 320 px on longest side (!)'),
      '-' => t('-: 500 px on longest side'),
      'z' => t('z: 640 px on longest side'),
      'c' => t('c: 800 px on longest side (!)'),
      'b' => t('b: 1024 px on longest side'),
    ),
    '#description' => t("!: TAKE CARE, the 'c' size (800px) is missing on Flickr images uploaded before March 1, 2012!"),
  );
  $form['photoset_settings']['flickr_sets_per_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of photosets per page'),
    '#required' => TRUE,
    '#default_value' => variable_get('flickr_sets_per_page', 8),
    '#description' => t('How many photosets display on user profile pages at <em>flickr/%uid/sets</em>. Clear the cache on form submit.'),
    '#size' => 2,
    '#maxlength' => 2,
  );
  $form['photoset_settings']['flickr_sets_photos_per_set'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of photos per set'),
    '#required' => TRUE,
    '#default_value' => variable_get('flickr_sets_photos_per_set', 6),
    '#description' => t('How many photos display in a set on user profile pages at <em>flickr/%uid/sets/%nsid</em>. Clear the cache on form submit.'),
    '#size' => 2,
    '#maxlength' => 2,
  );
}

/**
 * Validate user input.
 */
function flickr_sets_admin_settings_validate($form, &$form_state) {
  // Validate sets per page.
  $limit = trim($form_state['values']['flickr_sets_per_page']);
  if (!ctype_digit($limit) || $limit < 1) {
    form_set_error('flickr_sets_per_page', t('Set an integer from 1 to 99.'));
  }
  // Validate photos per set.
  $limit = trim($form_state['values']['flickr_sets_photos_per_set']);
  if (!ctype_digit($limit) || $limit < 1) {
    form_set_error('flickr_sets_photos_per_set', t('Set an integer from 1 to 99.'));
  }
}
