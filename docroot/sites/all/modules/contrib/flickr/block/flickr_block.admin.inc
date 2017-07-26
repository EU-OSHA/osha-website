<?php
/**
 * @file
 * The admin settings for the Flickr Block module.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function flickr_block_form_flickr_admin_settings_alter(&$form, &$form_state) {
  $form['#validate'][] = 'flickr_block_admin_settings_validate';
  $form['block_settings']['flickr_block_hide_empty'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide empty blocks (no media found)'),
    '#default_value' => variable_get('flickr_block_hide_empty', 0),
    '#description' => t("Uncheck to see the block title and to access the contextual links. That little wheel you see when you hover over blocks to edit them in place."),
  );
  $form['block_settings']['flickr_block_heading'] = array(
    '#type' => 'textfield',
    '#title' => t('Wrap the album title in an HTML heading tag (only for blocks)'),
    '#required' => TRUE,
    '#default_value' => variable_get('flickr_block_heading', 'h2'),
    '#description' => t("Use 'p' for no style, e.g. 'h2' for a heading or 'none' to not display an album title."),
    '#field_prefix' => t('<'),
    '#field_suffix' => t('>'),
    '#size' => 4,
    '#maxlength' => 4,
  );
  $form['block_settings']['flickr_block_refresh_random'] = array(
    '#type' => 'textfield',
    '#field_prefix' => t('Refresh random blocks every'),
    '#required' => TRUE,
    '#default_value' => variable_get('flickr_block_refresh_random', 23),
    '#field_suffix' => t('hours.'),
    '#size' => 3,
    '#maxlength' => 3,
    '#attributes' => array('class' => array('flickr-form-align')),
  );
  $cache_warming = l(t('cache warming'), 'https://drupal.org/node/1576686/', array(
    'attributes' => array(
      'title' => t('Load Page Cache after cron Runs | Drupal.org'),
      'target' => '_blank',
    ),
  ));
  $form['block_settings']['flickr_block_refresh_others'] = array(
    '#type' => 'textfield',
    '#field_prefix' => t('Refresh other blocks every'),
    '#required' => TRUE,
    '#default_value' => variable_get('flickr_block_refresh_others', 31),
    '#description' => t('It is recommended to set two different refresh values to avoid all blocks refresh together. Lower values impact performance negatively. Consider to use !cache_warming.', array('!cache_warming' => $cache_warming)),
    '#field_suffix' => t('hours.'),
    '#size' => 3,
    '#maxlength' => 3,
    '#attributes' => array('class' => array('flickr-form-align')),
  );
  $form['block_settings']['flickr_block_photos_per_set'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of photos per set'),
    '#required' => TRUE,
    '#default_value' => variable_get('flickr_block_photos_per_set', 6),
    '#description' => t('How many photos display per set on blocks that display multiple photosets. Clear the cache on form submit.'),
    '#size' => 2,
    '#maxlength' => 2,
  );
}


/**
 * Validate user input.
 */
function flickr_block_admin_settings_validate($form, &$form_state) {
  // Validate refresh rate random blocks.
  $limit = trim($form_state['values']['flickr_block_refresh_random']);
  if (!is_numeric($limit) || $limit < 2) {
    form_set_error('flickr_block_refresh_random', t('Set a number from 2 to 999.'));
  }
  // Validate refresh rate other blocks.
  $limit = trim($form_state['values']['flickr_block_refresh_others']);
  if (!is_numeric($limit) || $limit < 2) {
    form_set_error('flickr_block_refresh_others', t('Set a number from 2 to 999.'));
  }
  // Validate photos per set.
  $limit = trim($form_state['values']['flickr_block_photos_per_set']);
  if (!ctype_digit($limit) || $limit < 1) {
    form_set_error('flickr_block_photos_per_set', t('Set an integer from 1 to 99.'));
  }
}
