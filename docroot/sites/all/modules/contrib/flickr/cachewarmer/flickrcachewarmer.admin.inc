<?php
/**
 * @file
 * The admin settings for the Flickr Cache Warmer module.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function flickrcachewarmer_form_flickr_admin_settings_alter(&$form, &$form_state) {
  $form['#validate'][] = 'flickrcachewarmer_admin_settings_validate';
  $form['#submit'][] = 'flickrcachewarmer_admin_settings_submit';
  if (variable_get('cache_lifetime', 0) != 0) {
    $disable_cachelifetime = l(t("set the 'Minimum cache lifetime' to 'none'"), 'admin/config/development/performance', array(
      'attributes' => array(
        'title' => t('Admin > Configuration > Development > Performance'),
      ),
      'query' => array('destination' => 'admin/config/media/flickr'),
    ));
    $lifetime = format_interval(variable_get('cache_lifetime', 0), 2);
    $message = t("NOTE: The Flickr Cache Warmer only seems to work well if you !disable_cachelifetime. Currently it is set to %lifetime.", array('!disable_cachelifetime' => $disable_cachelifetime, '%lifetime' => $lifetime));
    drupal_set_message($message, 'warning', FALSE);
  }
  $cache_warming = l(t('cache warming'), 'https://drupal.org/node/1576686/', array(
    'attributes' => array(
      'title' => t('Load Page Cache after cron Runs | Drupal.org'),
      'target' => '_blank',
    ),
  ));
  $form['cachewarmer_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cache Warmer'),
    '#description' => t('Rebuilds the page cache after cron runs for selected content types also known as !cache_warming. It avoids long page loads for the first visitor after a cron run.', array('!cache_warming' => $cache_warming)),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 14,
  );
  // Cache warming once a day is enough, but leave it up to the
  // site owner to decide.
  $names = node_type_get_names();
  $form['cachewarmer_settings']['flickrcachewarmer_nodetypes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types to warm'),
    '#default_value' => variable_get('flickrcachewarmer_nodetypes', array()),
    '#options' => array_map('check_plain', $names),
    '#description' => t('Enable cache warming for the selected node type(s). Leave empty to warm all content types.'),
  );
  if (variable_get('cache_lifetime', 0) != 0) {
    $form['cachewarmer_settings']['flickrcachewarmer_nodetypes']['#description'] = t('Enable cache warming for the selected node type(s). Leave empty to warm all content types.') . '<br />' . t("NOTE: The Flickr Cache Warmer only seems to work well if you !disable_cachelifetime. Currently it is set to %lifetime.", array('!disable_cachelifetime' => $disable_cachelifetime, '%lifetime' => $lifetime));
  }
  $runcron = l(t("run cron separately"), 'admin/config/system/cron', array(
    'attributes' => array(
      'title' => t('Admin > Configuration > System > Cron'),
    ),
    'query' => array('destination' => 'admin/config/media/flickr'),
  ));
  variable_set('flickrcachewarmer_run', 0);
  $form['flickrcachewarmer_run'] = array(
    '#type' => 'checkbox',
    '#title' => t("Rebuild the cache on form submit to enhance performance for all page visits after saving this form."),
    '#default_value' => variable_get('flickrcachewarmer_run', 0),
    '#description' => t("Note that form submit will be very slow. The cache will be rebuilt for the nodes of the selected content types for cache warming.") . '<br />' . t("If you get errors, try to !runcron.", array('!runcron' => $runcron)),
    '#weight' => 98,
  );
}

/**
 * Validate user input.
 */
function flickrcachewarmer_admin_settings_validate($form, &$form_state) {
  // Put validation rules here.
}

/**
 * Submit form data.
 */
function flickrcachewarmer_admin_settings_submit($form, &$form_state) {
  if ($form_state['values']['flickrcachewarmer_run']) {
    $content_types = array_filter(variable_get('flickrcachewarmer_nodetypes', array()));
    // If no content types are selected in the settings, use all.
    if (empty($content_types)) {
      $names = node_type_get_names();
      $content_types = array_flip(array_map('check_plain', $names));
    }
    // Returns an array of nid's for selected content types.
    $nids = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->fields('n', array('type'))
      ->condition('n.type', array_filter($content_types), 'IN')
      ->execute()
      ->fetchCol();
    flickrcachewarmer_run($nids);
    drupal_set_message(t('All caches are rebuilt.'), 'status', FALSE);
  }
}
