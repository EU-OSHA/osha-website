<?php

/**
 * @file
 * Contains functions to handle batch processing.
 */

/**
 * Batch API callback for the item queueing functionality.
 *
 * @param SearchApiIndex $index
 *   The index for which items should be queued.
 * @param integer $entity_ids
 *   The EntityIDs to be handled.
 * @param integer $step
 *   The step number.
 * @param $context
 *   The batch context.
 */
function search_api_et_batch_queue_entities($index, $entity_ids, $step, &$context) {
  // Persistent data among batch runs for results.
  if (!isset($context['results']['indexes'][$index->id])) {
    $context['results']['indexes'][$index->id] = $index;
    $context['results']['queued'][$index->id] = 0;
    if (drupal_is_cli() === TRUE) {
      drush_log(dt('Adding items to the !index queue.', array('!index' => $index->name)), 'ok');
    }
  }

  // Load only specific sub-set of all entities to be processed.
  $controller = search_api_get_datasource_controller($index->item_type);
  $entity_type = $index->getEntityType();
  $limit = $index->options['cron_limit'];
  $offset = $step * $limit;
  $entities_to_process = entity_load($entity_type, array_slice($entity_ids, $offset, $limit));

  // Generate item IDs for each entity being processed.
  $ids = array();
  foreach ($entities_to_process as $id => $entity) {
    foreach (search_api_et_item_languages($entity, $entity_type, $index) as $lang) {
      $item_id = SearchApiEtHelper::buildItemId($id, $lang);
      $ids[$item_id] = $item_id;
    }
  }

  // Insert item IDs into the database queue.
  $controller->trackItemInsert($ids, array($index));
  $context['results']['queued'][$index->id] += count($ids);

  // Display progress message.
  $format_plural = drupal_is_cli() === TRUE ? '_search_api_drush_format_plural' : 'format_plural';
  $context['message'] = $format_plural($context['results']['queued'][$index->id],
    'Index "!index": successfully queued 1 item.',
    'Index "!index": successfully queued @count items.',
    array('!index' => $index->name)
  );
}

/**
 * Batch API finishing callback for the indexing functionality.
 *
 * @param boolean $success
 *   Result of the batch operation.
 * @param array $results
 *   Results.
 * @param array $operations
 *   Remaining batch operation to process.
 */
function search_api_et_batch_queue_entities_finished($success, $results, $operations) {
  // Check if called from drush.
  if (drupal_is_cli() === TRUE) {
    $drupal_set_message = 'drush_log';
    $format_plural = '_search_api_drush_format_plural';
    $t = 'dt';
    $success_message = 'success';
  }
  else {
    $drupal_set_message = 'drupal_set_message';
    $format_plural = 'format_plural';
    $t = 't';
    $success_message = 'status';
  }

  // Default redirect.
  $redirect = 'admin/config/search/search_api';

  // Display result messages.
  if ($success) {
    // We've just processed multiple indexes.
    if (count($results['indexes']) > 1) {
      // Show confirmation message for each index.
      foreach ($results['indexes'] as $index) {
        if (!empty($results['queued'][$index->id])) {
          $drupal_set_message($format_plural($results['queued'][$index->id], 'Successfully added 1 item to the @index index queue.', 'Successfully added @count items to the @index index queue.', array('@index' => $index->name)), $success_message);
        }
      }
    }
    // Only one index was processed, we can redirect to index-specific page.
    else {
      $index = reset($results['indexes']);
      if (!empty($results['queued'][$index->id])) {
        $drupal_set_message($format_plural($results['queued'][$index->id], 'Successfully added 1 item to the @index index queue.', 'Successfully added @count items to the @index index queue.', array('@index' => $index->name)), $success_message);
      }
      $redirect = 'admin/config/search/search_api/index/' . $index->machine_name;

      // If the queueing was run on a freshly created index, the fields has not
      // been configured yet, therefore redirecting to index's View page would
      // cause an error, so let's redirect to index's Fields configuration page
      // instead, as search_api_admin_add_index_submit() would do normally.
      // (It doesn't in this case, as we are already too late in page execution
      // process, doing the queueing from the shutdown function, so the redirect
      // defined at the end of search_api_admin_add_index_submit() is not being
      // used. That's the unfortunate downside of queueing using Drupal's batch,
      // and the difference between this datasource controller and standard
      // SearchApiEntityDataSourceController.)
      if (empty($index->options['fields'])) {
        $redirect .= '/fields';
        $drupal_set_message($t('The index was successfully created. Please set up its indexed fields now.'));
      }
    }
  }
  else {
    $drupal_set_message($t("An error occurred while trying to add items to the index queue. Check the logs for details."), 'error');
  }

  // Execute redirect if not run through Drush.
  if (drupal_is_cli() === FALSE) {
    drupal_goto($redirect);
  }
}
