<?php
/**
 * @file
 * Batch include.
 */

/**
 * Batch processing callback.
 */
function metatag_views_overview_convert_process($view, $instance, &$context) {
  // Update the view with the metatags.
  $context['message'] = t('Converting %name.', array('%name' => $view->instance));
  $metatags = unserialize($view->config);
  $instance[0]->display[$instance[1]]->display_options['metatags'] = $metatags;
  $instance[0]->save();

  // Delete the old metatag_config record.
  db_delete('metatag_config')
    ->condition('cid', $view->cid)
    ->execute();

  // Update the count.
  $context['results'][] = $view->instance;
}

/**
 * Batch finished callcabk.
 */
function _metatag_views_overview_convert_finished($success, $results, $operations) {
  // Delete the main views record. Note the new implementaiton instance
  // is 'view'.
  db_delete('metatag_config')
    ->condition('instance', 'views')
    ->execute();

  if ($success) {
    // Reset the menus so the conversion item goes away.
    menu_cache_clear_all();
    menu_rebuild();
    // Clear the metatag cache so the converted items are recognized.
    cache_clear_all('*', 'cache_metatag', TRUE);

    drupal_set_message(t('Updated %num views metatags.', array('%num' => count($results))));
    drupal_goto('admin/config/search/metatags');
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE),
    ));
    drupal_set_message($message, 'error');
  }
}
