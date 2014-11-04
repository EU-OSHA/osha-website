<?php

/**
 * Implements hook_views_query_alter().
 *
 * {@inheritdoc}
 */
function osha_workflow_views_query_alter(&$view, &$query) {
  if ($view->name == 'workbench_moderation' && $view->current_display == 'drafts_page') {
    $query->where[1]['conditions'][2]['value'][0] = OSHA_WORKFLOW_STATE_DRAFT;
    $query->where[1]['conditions'][2]['operator'] = 'in';
  }
  // Alter the query for Content tab form Workflow Dashboard.
  // Get the latest state of nodes.
  elseif ($view->name == 'osh_workflow_admin' && $view->current_display == 'content') {
    if (!empty($query->table_queue['node_revision'])) {
      $query->table_queue['node_revision']['join']->field = 'nid';
      $query->table_queue['node_revision']['join']->left_field = 'nid';
    }
  }
}

/**
 * Implements hook_views_post_execute().
 */
function osha_workflow_views_post_execute(&$view) {
  if ($view->name == 'osh_workflow_admin') {
    // Add correct author of the node.
    foreach ($view->result as &$row) {
      $row->users_node_uid = osha_workflow_get_node_owner($row->nid, $row->users_node_uid);
      $row->users_node_name = user_load($row->users_node_uid)->name;
    }
  }
}
