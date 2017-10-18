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


  if ($view->name == 'osh_workflow_admin') {
    // Alter the query for views from Workflow Dashboard.
    // Get the latest state of nodes, not just the published ones.
    if (!empty($query->table_queue['node_revision'])
        && $view->current_display != 'my_content_non_moderated') {
      $query->table_queue['node_revision']['join']->field = 'nid';
      $query->table_queue['node_revision']['join']->left_field = 'nid';
    }
    if ($view->current_display == 'my_content') {
      // Fix My Content View - Add conditions to show distinct content that has
      // some transitions made by current user
      // Fix to show current revisions Title (revision published or not).
      $new_join = new views_join();
      $new_join->table = 'workbench_moderation_node_history';
      $new_join->left_table = 'workbench_moderation_node_history';
      $new_join->left_field = 'nid';
      $new_join->field = 'nid';
      $new_join->type = 'INNER';
      $query->table_queue['workbench_moderation_node_history_workbench_moderation_node_history'] = array(
        'table' => 'workbench_moderation_node_history',
        'alias' => 'workbench_moderation_node_history_workbench_moderation_node_history',
        'num' => 1,
        'join' => $new_join,
      );
      global $user;
      $query->where[1]['conditions'][] = array(
        'field' => 'workbench_moderation_node_history_workbench_moderation_node_history.uid',
        'value' => $user->uid,
        'operator' => '=',
      );
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
      if (!empty($row->users_node_uid)) {
        $row->users_node_uid = osha_workflow_get_node_owner($row->nid, $row->users_node_uid);
        $row->users_node_name = user_load($row->users_node_uid)->name;
      }
    }
  }
}

/**
 * Implements hook_views_data_alter().
 */
function osha_workflow_views_data_alter(&$data) {
  $data['workbench_moderation_node_history']['uid']['filter'] = array(
    'title' => t('Moderation Author'),
    'handler' => 'views_handler_filter_user_current',
    'real field' => 'uid',
  );

  // Define group.
  $data['osha_workflow']['table']['group'] = t('Osha workflow');
  $data['osha_workflow']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );
  // Filters nodes that are in current users RM section.
  $data['osha_workflow']['section_in_rm_section'] = array(
    'title' => t('If section in rm section'),
    'help' => t('If section in rm section'),
    'filter' => array(
      'label' => t('Section in RM section'),
      'handler' => 'osha_workflow_handler_filter_section_in_rm_section',
    ),
  );
}


/**
 * Filters nodes that are in current users RM sections.
 */
class osha_workflow_handler_filter_section_in_rm_section extends views_handler_filter_boolean_operator {

  /**
   * Overrides views_handler_field::query().
   */
  function query() {
    global $user;
    global $workflow_notification_user;
    if (!empty($workflow_notification_user)) {
      $sections = osha_workflow_access_get_rm_sections($workflow_notification_user->uid);
    }
    else {
      $sections = osha_workflow_access_get_rm_sections($user->uid);
    }
    $group = $this->query->set_where_group('AND');
    $subquery = db_select('workbench_access_node', 'workbench_access_node');
    $subquery->addField('workbench_access_node', 'nid');
    $subquery->distinct();
    $subquery->condition('workbench_access_node.access_id', $sections, 'IN');
    $this->query->add_where($group, "{$this->query->base_table}.nid", $subquery, 'IN');
  }
}
