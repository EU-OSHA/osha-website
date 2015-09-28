<?php

function search_and_replace_undo_page($node = NULL) {
  $page = array();
  $query = db_select('search_and_replace', 'sr')
    ->fields('sr');
  if (!empty($node)) {
    $query->condition('sr.nid', $node->nid);
  }
  $results = $query->extend('PagerDefault')
    ->limit(25)
    ->orderBy('sr.id', 'desc')
    ->execute();

  $header = array('Search', 'Replace', 'Settings', 'User', 'Date', 'Undone', 'Operations');
  $table_rows = array();
  $idx = 0;
  while ($row = $results->fetchAssoc()) {
    $author = user_load($row['uid']);
    $table_rows[$row['id']] = array(
      check_plain($row['search']),
      check_plain($row['replaced']),
      _search_and_replace_settings_to_text((array) json_decode($row['options'])),
      $author->name,
      date('d-m-Y H:i', $row['created']),
    );
    $table_rows[$row['id']][] = empty($row['undone']) ? 'No' : 'Yes';

    if (empty($row['undone'])) {
      if (empty($node)) {
        $operations = '';
        if ($idx == 0) {
          $operations .= l('Undo revisions', 'admin/content/search_replace/undo/' . $row['id'])
          . ' | ';
        }
        $operations .= l('Reverse search', 'admin/content/search_replace', array('query' => array('undo_id' => $row['id'])));
        $table_rows[$row['id']][] = $operations;
      } else {
        $operations = '';
        if ($idx == 0) {
          $operations .= l('Undo revisions', 'node/' . $node->nid . '/search_replace/undo/' . $row['id'])
            . ' | ';
        }
        $operations .= l('Reverse search', 'node/' . $node->nid . '/search_replace', array('query' => array('undo_id' => $row['id'])));
        $table_rows[$row['id']][] = $operations;
      }
    }
    $idx++;
  }

  $page['table'] = array(
    '#markup' => theme('table', array('header' => $header, 'rows' => $table_rows)),
  );
  $page['pagination'] = array(
    '#markup' => theme('pager'),
  );
  return $page;
}

function search_and_replace_load_operation($id) {
  $result = db_select('search_and_replace', 'sr')
    ->fields('sr')
    ->condition('id', $id)
    ->execute()
    ->fetchAssoc();
  return $result;
}

function search_and_replace_undo_form($form, &$form_state, $id, $node = NULL) {
  $operation = search_and_replace_load_operation($id);
  $form_state['#operation'] = $operation;
  $undo_data = json_decode($operation['undo_data'], true);
  $form_state['#undo_data'] = $undo_data;
  $form = confirm_form($form, t('Undo revisions of search and replace operation'),
    current_path(),
    t('Are you sure you want to revert @count nodes to their previous revisions?', array('@count' => count($undo_data)))
  );
  $form['actions']['cancel']['#href'] = 'admin/content/search_replace/undo';
  return $form;
}

function search_and_replace_undo_form_submit($form, &$form_state) {
  $batch = array(
    'operations' => array(
      array('search_and_replace_batch_operation_undo', array($form_state['#undo_data'], $form_state['#operation'])),
    ),
    'finished' => 'search_and_replace_batch_undo_finished',
    'title' => t('Processing Replace Batch'),
    'init_message' => t('Replace Batch is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Replace Batch has encountered an error.'),
  );
  batch_set($batch);
  $url = 'admin/content/search_replace/undo';
  if (!empty($form_state['build_info']['args'][1]->nid)) {
    $url = 'node/' . $form_state['build_info']['args'][1]->nid . '/search_replace/undo';
  }
  batch_process($url);
}

/**
 * Batch operation for replacing.
 */
function search_and_replace_batch_operation_undo($results, $operation, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = count($results);
    $context['results']['results'] = array();
    $context['results']['operation'] = $operation;
  }
  $limit = 3;
  $to_process = array_slice($results, $context['sandbox']['current_node'], $limit);

  foreach ($to_process as $result) {
    $reset_current = array();
    // Load revision that was before search and replace.
    $node = node_load($result['nid'], $result['vid']);
    $node->revision = TRUE;
    $node->log = t('Search and replace undo operation - reverting to version @vid', array('@vid' => $result['vid']));
    $node->status = $result['st'];
    if (!empty($result['moderation_state'])) {
      // Load current node as it is.
      $node_current = node_load($result['nid']);
      $node->workbench_moderation_state_new = $result['moderation_state'];
      // If node has an existing draft, we will recreate it after saving the node.
      if ($node_current->vid != $node_current->workbench_moderation['current']->vid) {
        $reset_current = $node_current->workbench_moderation['current'];
      }
    }
    node_save($node);
    if (!empty($reset_current)) {
      // Recreate the existing draft.
      $current_version = node_load($reset_current->nid, $reset_current->vid);
      $current_version->workbench_moderation_state_new = $reset_current->state;
      $current_version->revision = 1;
      $current_version->log = t('Copy of the existing draft that was before undo the search for the published version');
      node_save($current_version);
    }

    // Update our progress information.
    $context['results']['results'][$node->nid] = $node->title;
    $context['sandbox']['progress']++;
    $context['sandbox']['current_node']++;
    $context['message'] = t('Now processing %node', array('%node' => $node->title));
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Batch 'finished' callback for replace..
 */
function search_and_replace_batch_undo_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('@count nodes processed.', array('@count' => count ($results['results']))));
    if (!empty($results['operation'])) {
      $search_op = $results['operation'];
      $search_op['undone'] = 1;
      drupal_write_record('search_and_replace', $search_op, array('id'));
    }
  }
  else {
    $error_operation = reset($operations);
    drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array(
      '@operation' => $error_operation[0],
      '@args' => print_r($error_operation[0], TRUE),
    )));
  }
}
