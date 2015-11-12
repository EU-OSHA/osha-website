<?php

function osha_workflow_node_pm_assign_form($form, &$form_state, $node) {
  global $user;
  $form =  array();
  $form['#tree'] = TRUE;
  $form['#theme'] = 'osha_workflow_node_pm_assign_form';

  if (empty($node->workbench_access)) {
    drupal_set_message('No section assigned to the node.');
    return $form;
  }
  $can_edit = _osha_workflow_can_edit_pm($node);
  $form['#node'] = $node;
  $form['#can_edit'] = $can_edit;
  $section = current($node->workbench_access);
  $section_pms = osha_workflow_access_get_section_pm($section);
  $options = array('' => t('-- Please select --'));
  foreach ($section_pms as $uid => $pm) {
    $options[$uid] = $pm->name;
  }
  $pm_entries = osha_workflow_get_pms_entries($node->nid);
  $project_managers = osha_workflow_get_pms_users($node->nid);
  if (!empty($pm_entries)) {
    $weight = 0;
    $form['rows']['#tree'] = TRUE;
    foreach ($pm_entries as $uid => $pm) {
      $form['rows'][$uid]['name'] = array(
        '#markup' => $project_managers[$uid]->name,
      );
      $form['rows'][$uid]['weight'] = array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#title_display' => 'invisible',
        '#default_value' => $weight,
        '#access' => $can_edit,
        '#attributes' => array('class' => array('user-weight')),
      );
      $form['rows'][$uid]['uid'] = array(
        '#type' => 'hidden',
        '#value' => $uid,
      );
      $form['rows'][$uid]['approved'] = array(
        '#markup' => 'Waiting for approval',
      );
      if (!empty($pm->approved)) {
        $form['rows'][$uid]['approved']['#markup'] = ($pm->approved == 'approved') ? 'Approved' : 'Rejected';
      }
      $form['rows'][$uid]['message'] = array(
        '#markup' => $pm->message,
      );
      $form['rows'][$uid]['remove'] = array(
        '#type' => 'submit',
        '#name' => $uid,
        '#value' => t('Remove'),
        '#access' => $can_edit,
        '#submit' => array('osha_workflow_admin_approvers_remove_row_submit'),
      );
      $weight++;
    }
  }
  $form['add']['uid'] = array(
    '#type' => 'select',
    '#title' => t('Add a Project Manager'),
    '#options' => $options,
    '#access' => $can_edit,
  );
  $form['add']['submit'] = array(
    '#type' => 'submit',
    '#name' => 'adduser',
    '#value' => t('Add to queue'),
    '#access' => $can_edit,
    '#attributes' => array('class' => array('container-inline')),
    '#submit' => array('osha_workflow_admin_approvers_add_row_submit'),
  );
  $form['help'] = array(
    '#type' => 'markup',
    '#markup' =>
      t('<div><strong>Tip:</strong> Use the drag handlers to sort the users in the order you want them to have the content reviewed.
<br />Press Save to confirm your reordering!</div>'),
    '#access' => $can_edit,
  );
  $form['content'] = array(
    'actions' => array(
      '#type' => 'actions',
      '#weight' => 20,
      'submit' => array(
        '#type' => 'submit',
        '#value' => t('Save'),
        '#access' => $can_edit,
      ),
    ),
  );

  osha_workflow_node_pm_actions_append($form, $node);

  return $form;
}

function osha_workflow_node_pm_actions_append(&$form, $node) {
  global $user;
  if ($current_approver = _osha_workflow_get_current_pm_approver($node->nid)) {
    // Approval settings.
    $form['pm_actions'] = array(
      '#type' => 'container',
      '#access' => _osha_workflow_can_approve($node),
    );
    $form['pm_actions']['approve'] = array(
      '#type' => 'submit',
      '#value' => 'Approve',
      '#submit' => array('osha_workflow_pm_approve_submit'),
    );
    if ($current_approver->uid != $user->uid) {
      $form['pm_actions']['approve']['#suffix'] = t('You can approve on behalf of %user', array('%user' => $current_approver->name));
    }
    $form['pm_actions']['reject'] = array(
      '#type' => 'submit',
      '#value' => 'Reject',
      '#submit' => array('osha_workflow_pm_reject_submit'),
      '#access' => $current_approver->uid == $user->uid,
    );
  }
}

function osha_workflow_node_pm_assign_form_submit($form, $form_state) {
  if (!empty($form_state['input']['rows'])) {
    $entries = osha_workflow_get_pms_entries($form['#node']->nid);
    foreach ($form_state['input']['rows'] as $row) {
      if (!empty($entries[$row['uid']])) {
        $entries[$row['uid']]->weight = $row['weight'];
        _osha_workflow_pm_save_row($entries[$row['uid']]);
      }
    }
  }
}

/**
 * CPM Reject button callback.
 */
function osha_workflow_pm_reject_submit($form, &$form_submit) {
  global $user;
  $row = _osha_workflow_get_current_pm_approver_entry($form['#node']->nid);
  if (!empty($row)) {
    $row->approved = 'rejected';
    $row->message = t('!user rejected on !date', array('!user' => $user->name, '!date' => date('d-m-Y H:i:s')));
    _osha_workflow_pm_save_row($row);
    workbench_moderation_moderate($form['#node'], 'draft');
  }
  else {
    drupal_set_message('No current approver found.');
  }
}

/**
 * CPM Approve button.
 */
function osha_workflow_pm_approve_submit($form, &$form_submit) {
  global $user;
  $row = _osha_workflow_get_current_pm_approver_entry($form['#node']->nid);
  if (!empty($row)) {
    $row->approved = 'approved';
    if ($user->uid == $row->uid) {
      $message = t('!user approved on !date', array('!user' => $user->name, '!date' => date('d-m-Y H:i:s')));
    }
    else {
      $curr_approver = user_load($row->uid);
      $message = t('!user approved on behalf of !approver on !date', array('!user' => $user->name, '!date' => date('d-m-Y H:i:s'), '!approver' => $curr_approver->name));
    }
    $row->message = $message;
    _osha_workflow_pm_save_row($row);

    $next_approver = _osha_workflow_get_current_pm_approver($form['#node']->nid);
    if (empty($next_approver)) {
      // Do something or not.
    }
    else {
      $remaining_approvers = _osha_workflow_get_remaining_pm_approvers($form['#node']->nid);
      reset($remaining_approvers);
      $next_approver = array_shift($remaining_approvers);
      // Send notifications
      OshaWorkflowNotifications::sendEmail(array($next_approver), array('node' => $form['#node']), 'osha_workflow');
    }
  }
  else {
    drupal_set_message('No current approver found.');
  }
}

/**
 * Form theme callback
 */
function theme_osha_workflow_node_pm_assign_form($variables) {
  $form = $variables['form'];

  // Initialize the variable which will store our table rows.
  $rows = array();

  // Iterate over each element in our $form['example_items'] array.
  foreach (element_children($form['rows']) as $id) {
    $form['rows'][$id]['weight']['#attributes']['class'] = array('user-item-weight');
    $rows[] = array(
      'data' => array(
        // Add our 'name' column.
        drupal_render($form['rows'][$id]['name']),
        // Add our 'weight' column.
        drupal_render($form['rows'][$id]['approved']),

        drupal_render($form['rows'][$id]['message']),

        drupal_render($form['rows'][$id]['remove']),

        drupal_render($form['rows'][$id]['weight']),

      ),
      'class' => array('draggable'),
    );
  }
  $header = array(t('Name'), t('Approval'), t('Message'), t('Actions'), t('Weight'));

  $table_id = 'users-items-table';

  // We can render our tabledrag table for output.
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => $table_id),
  ));

  $output .= drupal_render_children($form);
  if ($form['#can_edit']) {
    drupal_add_tabledrag($table_id, 'order', 'sibling', 'user-item-weight');
  }


  return $output;
}

/**
 * Submit callback for remove button from a row.
 */
function osha_workflow_admin_approvers_remove_row_submit($form, &$form_state) {
  if (isset($form_state['triggering_element'])) {
    $triggering_element = $form_state['triggering_element'];
    if (isset($triggering_element['#name'])) {
      $uid = $triggering_element['#name'];
      db_delete('osha_workflow_node_project_managers')
        ->condition('nid', $form['#node']->nid)
        ->condition('uid', $uid)
        ->execute();
    }
  }
}

/**
 * Submit callback for Add user button.
 */
function osha_workflow_admin_approvers_add_row_submit($form, &$form_state) {
  if (!empty($form_state['values']['add']['uid'])) {
    $moderator = user_load($form_state['input']['add']['uid']);
    if (!empty($moderator)) {
      $existing_entries = osha_workflow_get_pms_entries($form['#node']->nid);
      if ($existing_entries[$moderator->uid]) {
        drupal_set_message('This user is already assigned', 'warning');
        return;
      }
      $weight = 0;
      if (!empty($existing_entries)) {
        $last = end($existing_entries);
        $weight = $last->weight > 0 ? $last->weight + 1 : $last->weight -1;
      }
      $row = array(
        'nid' => $form['#node']->nid,
        'uid' => $moderator->uid,
        'weight' => $weight,
      );
      _osha_workflow_pm_save_row($row);
    }
  }
}

function _osha_workflow_node_has_pm($node, $account) {
  $pms = osha_workflow_get_pms_entries($node->nid);
  return in_array($account->uid, array_keys($pms));
}

function _osha_workflow_can_edit_pm($node, $account = NULL) {
  if (!empty($node->workbench_moderation['current']) && $node->workbench_moderation['current']->state != OSHA_WORKFLOW_STATE_FINAL_DRAFT) {
    return FALSE;
  }
  if (empty($account)) {
    global $user;
    $account = $user;
  }
  return user_access('assign pm to node' ,$account);
}

function _osha_workflow_get_current_pm_approver($nid) {
  $entry = _osha_workflow_get_current_pm_approver_entry($nid);
  if (!empty($entry)) {
    return user_load($entry->uid);
  }
  return NULL;
}

function _osha_workflow_get_current_pm_approver_entry($nid) {
  $entries = osha_workflow_get_pms_entries($nid);
  foreach ($entries as $entry) {
    if (empty($entry->approved)) {
      return $entry;
    }
  }
  return NULL;
}

function _osha_workflow_get_remaining_pm_approvers($nid) {
  $remaining = db_select('osha_workflow_node_project_managers', 'pm')
    ->fields('pm')
    ->condition('nid', $nid)
    ->isNull('approved')
    ->execute()
    ->fetchAllAssoc('uid');
  if (!empty($remaining)) {
    return user_load_multiple(array_keys($remaining));
  }
  return NULL;
}

function _hwc_workflow_cpm_reset_votes($nid) {
  db_update('osha_workflow_node_project_managers')
    ->fields(array(
      'approved' => NULL,
      'message' => NULL,
      )
    )
    ->condition('nid', $nid)
    ->execute();
}

function _osha_workflow_can_approve($node, $account = NULL) {
  // Presume that who has access to the Review tab are admin, RM or node\s PMs.
  if (empty($node->workbench_moderation['current'])
    || $node->workbench_moderation['current']->state == OSHA_WORKFLOW_STATE_TO_BE_REVIEWED) {
    return TRUE;
  }
  return FALSE;
}
