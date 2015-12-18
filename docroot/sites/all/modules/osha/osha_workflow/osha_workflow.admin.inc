<?php

/**
 * @param $form
 * @param $form_state
 * @return array
 */
function osha_workflow_workbench_project_managers_form($form, $form_state) {
  // Set proper breadcrumb trails.
  $breadcrumb[] = t('Project Managers');
  $current = drupal_get_breadcrumb();
  $current = array_merge($current, $breadcrumb);
  drupal_set_breadcrumb($current);
  $form = array(
    '#submit' => array('osha_workflow_workbench_project_managers_form_submit'),
  );

  // Ensure that we have configured access controls.
  if (!$active = workbench_access_get_active_tree()) {
    $form['error'] = array('#markup' => workbench_access_configuration_needed_message());
    return $form;
  }

  $form['help'] = array(
    '#markup' => '<h1>' . t('Default project managers') . '</h1>' . '<p>' . t('Use this form to assign the default project managers to each section.') . '<p>',
    '#weight' => -10,
    '#attributes' => array('class' => array('container-inline')),
  );
  foreach ($active['tree'] as $access_id => $section) {
    if (!isset($active['active'][$access_id])) {
      continue;
    }
    $options = array('' => '-- Please select --') + osha_workflow_users_get_users_from_role_as_options(OSHA_WORKFLOW_ROLE_PROJECT_MANAGER);
    $form['rows'][$section['access_type_id']][$access_id] = array(
      '#title' => str_repeat('-', $section['depth']) . ' ' . $section['name'],
      '#title_display' => 'after',
      '#type' => 'select',
      '#name' => $access_id,
      '#options' => $options,
    );
  }
  $form['actions'] = array(
    '#type' => 'actions',
    '#attributes' => array('class' => array('container-inline')),
    '#weight' => 20,
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save changes'),
    ),
  );
  return $form;
}

function osha_workflow_workbench_project_managers_form_submit($form, $form_state) {
  drupal_set_message('Saving not implemented', 'error');
}


function osha_workflow_workbench_project_managers($access_type = NULL, $access_type_id = NULL) {
  if (is_null($access_type) || is_null($access_type_id)) {
    // Set proper breadcrumb trails.
    $breadcrumb[] = t('Project Managers');
    $current = drupal_get_breadcrumb();
    $current = array_merge($current, $breadcrumb);
    drupal_set_breadcrumb($current);

    // Ensure that we have configured access controls.
    if (!$active = workbench_access_get_active_tree()) {
      return workbench_access_configuration_needed_message();
    }
    $active['access_scheme']['access_id'] = NULL;
    $output = '<h2>' . t('Editorial assignments by editor') . '</h2>';
    $output .= '<p>' . t('The following sections are currently active.');
    if (user_access('administer workbench access')) {
      $output .= ' ' . t('You may <a href="!url">enable or disable sections</a>.', array('!url' => url('admin/config/workbench/access/sections'))) . '</p>';
    }
    $rows = array();
    foreach ($active['tree'] as $access_id => $section) {
      if (!isset($active['active'][$access_id])) {
        continue;
      }
      // Nest the children so the user understands the hierarchy.
      if ($section['depth'] == 0 || !isset($active['active'][$section['parent']])) {
        $parent = $section['name'];
      }
      $row = array(
        str_repeat('-', $section['depth'] ) . ' ' . $section['name'],
      );
      $roles = workbench_access_get_roles('access workbench access by role');
      if (empty($roles)) {
        if (user_access('administer permissions')) {
          return t('To continue, at least one role must be have the <a href="!url">Allow all members of this role to be assigned to Workbench Access sections</a> permission', array('!url' => url('admin/people/permissions', array('fragment' => 'module-workbench_access'))));
        }
        else {
          return t('There are no roles who have permission to edit sections. Please contact a site administrator.');
        }
      }
      if (!isset($roles[DRUPAL_AUTHENTICATED_RID])) {
        $pms = db_query("SELECT wau.uid as uid, us.name as name FROM {osha_workflow_access_pm} wau
            INNER JOIN {users_roles} ur ON wau.uid = ur.uid
            INNER JOIN {users} us ON wau.uid = us.uid
            WHERE wau.access_scheme = :access_scheme AND wau.access_id = :access_id
            AND ur.rid IN (:rids)",
          array(':access_scheme' => $active['access_scheme']['access_type'], ':access_id' => $access_id, ':rids' => array_keys($roles))
        )->fetchAllKeyed();
      }
      else {
        $pms = db_query("SELECT wau.uid as uid, us.name as name FROM {osha_workflow_access_pm} wau
            INNER JOIN {users} us ON wau.uid = us.uid
            WHERE wau.access_scheme = :access_scheme AND wau.access_id = :access_id",
          array(':access_scheme' => $active['access_scheme']['access_type'], ':access_id' => $access_id)
        )->fetchAllKeyed();
      }
      $count = count($pms);
      $new_row = format_plural($count, '1 Project Manager', '@count Project Managers');
      if (user_access('assign workbench access')) {
        $new_row = $new_row;
      }
      if (!empty($pms)) {
        $new_row .= ' (' . implode(', ',$pms ) . ') ';
      }
      $row[] = $new_row;

      $review = osha_workflow_get_section_reviews($access_id);

      if (empty($review)) {
        $row[] = l(t('Not reviewed yet.'), 'admin/config/workbench/access/managers/review/' . $active['access_scheme']['access_type'] . '/' . $access_id);
      }
      else {
        $review = current($review);
        $user = user_load($review->uid);
        $last_review = new DateTime(date("c", $review->created));
        $now = new DateTime();
        $since_last_review = $now->diff($last_review);
        $row[] = l(
          t('Last reviewed by @name on @created (@months months ago)',
            array(
              '@name' => $user->name,
              '@created' => date('d-m-Y', $review->created),
              '@months' => $since_last_review->m,
            )
          ),
          'admin/config/workbench/access/managers/review/' . $active['access_scheme']['access_type'] . '/' . $access_id);
      }

      $row[] = l(t('See the broken links'),
        'admin/content/linkchecker-broken-links',
        array('query' => array('access_id[]' => $access_id))
      );

      $rows[] = $row;
    }
    $header = array(t('Section'), t('Managers'), t('Review'), t('Broken Links'));
    $output .= theme('table', array('header' => $header, 'rows' => $rows));
    $build['content']['#markup'] = $output;
    return $build;
  }
  return drupal_get_form('osha_workflow_access_pm_form', $access_type, $access_type_id);
}

function osha_workflow_access_pm_form($form, &$form_state, $access_type, $access_type_id) {
  // Set proper breadcrumb trails.
  $breadcrumb[] = l(t('Workbench Access'), 'admin/config/workbench/access');
  $breadcrumb[] = l(t('Project Managers'), 'admin/config/workbench/access/managers');
  $current = drupal_get_breadcrumb();
  $current = array_merge($current, $breadcrumb);
  drupal_set_breadcrumb($current);

  $form = array();
  $form['#access'] = user_access('assign workbench access');
  $active = workbench_access_get_active_tree();
  $active['access_scheme']['access_id'] = $access_type_id;
  if ($active['access_scheme']['access_type'] != $access_type || !isset($active['active'][$access_type_id])) {
    drupal_access_denied();
    drupal_exit();
  }

  // Get the list of user roles that can be assigned workbench access.
  $roles = workbench_access_get_roles('access workbench access by role');

  $query = db_select('users', 'u')
    ->fields('u', array('uid', 'name'));
  $query->join('osha_workflow_access_pm', 'wau', 'u.uid = wau.uid');
  $query->condition('wau.access_scheme', $access_type)
    ->condition('wau.access_id', $access_type_id)
    ->extend('PagerDefault')->limit(25);
  $result = $query->execute();
  $form['users']['#tree'] = TRUE;
  foreach ($result as $account) {
    $form['users'][$account->uid]['name'] = array('#markup' => l($account->name, 'user/' . $account->uid));
    $form['users'][$account->uid]['remove'] = array(
      '#type' => 'checkbox',
      '#title' => t('Remove'),
    );
  }
  $options = array('' => "Select a Project Manager");
  $options += osha_workflow_users_get_users_from_role_as_options(OSHA_WORKFLOW_ROLE_PROJECT_MANAGER);
  $form['add_user'] = array(
    '#type' => 'select',
    '#title' => t('Add Project Manager'),
    '#options' => $options,
    '#default_value' => "",
  );
  $form['workbench_access'] = array(
    '#type' => 'value',
    '#value' => $active['access_scheme'],
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update Project Manager'),
  );
  return $form;
}

/**
 * Process form submission for adding editors.
 */
function osha_workflow_access_pm_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  // User handling.
  if (!empty($values['add_user'])) {
    $account = user_load($values['add_user']);
    $existing_users = osha_workflow_access_get_section_pm($values['workbench_access']['access_id']);
    if (empty($account)) {
      form_set_error('add_user', t('The selected user does not exist.'));
    }
    else {
      if (!OshaWorkflowPermissions::userHasRole(
        OSHA_WORKFLOW_ROLE_PROJECT_MANAGER, $account)) {
        form_set_error('add_user', t('You can assign here only Project Managers.'));
      }
      elseif (!empty($existing_users)) {
        foreach ($values['users'] as $user) {
          if (empty($user['remove'])) {
            form_set_error('add_user', t('You can assign only one PM per section.'));
          }
        }
      }
    }
  }
}

/**
 * Process form submission for adding editors.
 */
function osha_workflow_access_pm_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  // User handling.
  if (!empty($values['add_user'])) {
    $account = user_load($values['add_user']);
    $sections = $account->workbench_access;
    if (!empty($account->workbench_access_by_role)) {
      foreach ($account->workbench_access_by_role as $key) {
        unset($sections[$key]);
      }
    }
    if (!empty($account->status)) {
      // Add the access section.
      $record['uid'] = $account->uid;
      $record['access_id'] = $values['workbench_access']['access_id'];
      $record['access_scheme'] = $values['workbench_access']['access_scheme'];
      drupal_write_record('osha_workflow_access_pm', $record);
    }
  }
  if (!empty($values['users'])) {
    foreach ($values['users'] as $key => $value) {
      if (!empty($value['remove'])) {
        // Remove the access section.
        db_delete('osha_workflow_access_pm')
          ->condition('access_id', $values['workbench_access']['access_id'])
          ->condition('access_scheme', $values['workbench_access']['access_scheme'])
          ->condition('uid', $key)
          ->execute();
      }
    }
  }
}

/**
 * Theme the editor list form.
 */
function theme_osha_workflow_access_pm_form($variables) {
  $form = $variables['form'];
  $scheme = $form['workbench_access']['#value'];
  $access_info = workbench_access_load_access_info($scheme);
  $output = '<h2>' . t('%name project managers by account', array('%name' => $access_info['name'])) . '</h2>';
  $header = array(t('Project manager'), t('Actions'));
  $rows = array();
  foreach (element_children($form['users']) as $key) {
    $rows[] = array(
      drupal_render($form['users'][$key]['name']),
      drupal_render($form['users'][$key]['remove']),
    );
  }
  $variables = array(
    'header' => $header,
    'rows' => $rows,
    'empty' => t('No active project managers have been found.'),
  );
  $output .= theme('table', $variables);
  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Form validation for osha_workflow_node_review_form.
 */
function osha_workflow_node_review_form_validate($form, $form_state) {
  if (empty($form_state['values']['project_manager'])) {
    form_set_error('', t('Please assign a project manager'));
  }
}

/**
 * Form builder for workflow_moderation_form (approval).
 *
 * @param array $form
 *   Form to modify
 * @param array $form_state
 *   Form state
 * @param object $node
 *   Current node
 *
 * @return array
 *   Form array
 */
function osha_workflow_node_approval_form($form, &$form_state, $node) {
  module_load_include('inc', 'osha_workflow', 'osha_workflow.api');
  $can_edit = OshaWorkflowPermissions::userCanEditApprovers($node);
  $form_state['node'] = $node;
  $form['#can_edit']  = $can_edit;
  $form['#tree'] = TRUE;
  $form['#theme'] = 'osha_workflow_approval_form';
  if (isset($form_state['rows'])) {
    $rows = $form_state['rows'];
  }
  else {
    $rows = osha_workflow_get_node_approvers($node->nid, FALSE);
  }
  $form_state['rows'] = $rows;
  $weight = 0;
  foreach ($rows as $uid => $row) {
    $form['rows'][$uid]['#row'] = $row;
    $form['rows'][$uid]['weight'] = array(
      '#type' => 'weight',
      '#title' => t('Weight'),
      '#title_display' => 'invisible',
      '#default_value' => (-10 + $weight),
      '#access' => $can_edit,
      '#attributes' => array('class' => array('user-weight')),
    );
    $form['rows'][$uid]['uid'] = array(
      '#type' => 'hidden',
      '#value' => $uid,
    );
    $form['rows'][$uid]['remove'] = array(
      '#type' => 'submit',
      '#name' => $uid,
      '#value' => t('Remove'),
      '#access' => $can_edit,
      '#submit' => array('osha_workflow_admin_approvers_remove_row'),
    );
    $weight++;
  }
  $form['add']['uid'] = array(
    '#type' => 'select',
    '#multiple' => FALSE,
    '#options' => osha_workflow_users_get_users_from_role_as_options(OSHA_WORKFLOW_ROLE_APPROVER),
    '#title' => t('Add another approver'),
    '#title_display' => 'invisible',
    '#access' => $can_edit,
  );
  $form['add']['submit'] = array(
    '#type' => 'submit',
    '#name' => 'adduser',
    '#value' => t('Add to queue'),
    '#access' => $can_edit,
    '#attributes' => array('class' => array('container-inline')),
    '#submit' => array('osha_workflow_admin_approvers_add_row'),
  );
  $form['help'] = array(
    '#type' => 'markup',
    '#markup' =>
      t('<div><strong>Tip:</strong> Use the drag handlers to sort the users in the order you want them to have the content reviewed. <br />** - Temporary, not yet saved</div>'),
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
  return $form;
}

function osha_workflow_admin_approvers_remove_row($form, &$form_state) {
  if (isset($form_state['triggering_element'])) {
    $triggering_element = $form_state['triggering_element'];
    if (isset($triggering_element['#name'])) {
      $uid = $triggering_element['#name'];
      unset($form_state['rows'][$uid]);
      unset($form_state['values']['rows'][$uid]);
      drupal_set_message(t('Changes made in this table will not be saved until you press Save'), 'warning');
      $form_state['rebuild'] = TRUE;
    }
  }
}

function osha_workflow_admin_approvers_add_row($form, &$form_state) {
  if (!empty($form_state['input']['add']['uid'])) {
    $moderator = user_load($form_state['input']['add']['uid']);
    $moderator->osha_workflow_node_approval_saved = FALSE;
    $form_state['rows'][$moderator->uid] = $moderator;
    drupal_set_message(t('Changes made in this table will not be saved until you press Save'), 'warning');
    $form_state['rebuild'] = TRUE;
  }
}

/**
 * Themes the workflow_moderation_form form.
 *
 * @param array $variables
 *   Form variables
 *
 * @return string
 *   Form HTML
 */
function theme_osha_workflow_approval_form($variables) {
  $output = '';
  $form = $variables['form'];
  $rows = array();
  if (!empty($form['rows'])) {
    $items = element_children($form['rows']);
    $last = end($items);
    reset($items);
    foreach ($items as $uid) {
      $moderator = $form['rows'][$uid]['#row'];
      $status = '';
      if (isset($moderator->osha_workflow_node_approval)) {
        $val = $moderator->osha_workflow_node_approval->approved;
        if ($val === NULL) {
          // NULL - not reviewed yet.
          // $status = t('Waiting to approve');
        }
        else {
          $status = ($last == $uid) ? ucfirst($val) : t('User created a new revision');
        }
      }
      $row = array();
      $name = check_plain($moderator->name);
      if (empty($moderator->osha_workflow_node_approval_saved)) {
        $name .= '<sup>**</sup>';
      }
      $row[] = $name;
      $row[] = check_plain($moderator->mail);
      $row[] = $status;
      $row[] = drupal_render($form['rows'][$uid]['remove']);
      $row[] = drupal_render($form['rows'][$uid]['weight']);
      $rows[] = array('data' => $row, 'class' => array('draggable'));
    }
  }
  $row = array(
    drupal_render($form['add']['uid']),
    drupal_render($form['add']['submit']),
    '',
    '',
    '',
  );
  $rows[] = $row;
  $caption = t('List of approvers');

  $header = array(
    t('User'),
    t('Mail'),
    t('Status'),
    '',
  );
  if ($form['#can_edit']) {
    array_push($header, t('Order of notification'));
  }
  $table = array(
    '#theme' => 'table',
    '#caption' => $caption,
    '#header' => $header,
    '#attributes' => array(
      'id' => 'approvers_table',
    ),
    '#rows' => $rows,
  );
  if (isset($form['moderation'])) {
    $output .= drupal_render($form['moderation']);
  }
  $output .= drupal_render($table);
  $output .= drupal_render_children($form);
  if ($form['#can_edit']) {
    drupal_add_tabledrag('approvers_table', 'order', 'sibling', 'user-weight');
  }
  return $output;
}

/**
 * Implements hook_form_validate().
 */
function osha_workflow_node_approval_form_validate($form, $form_state) {
  if (empty($form_state['rows']) && $form_state['triggering_element']['#name'] != 'adduser') {
    form_set_error('enabled', t('Cannot have an empty moderation queue. Add at least one user or switch to another state!'));
  }
}


/**
 * Implements hook_form_submit().
 */
function osha_workflow_node_approval_form_submit($form, $form_state) {
  $users = array();
  $node = $form_state['node'];
  if (!empty($form_state['values']['rows'])) {
    $data = $form_state['values']['rows'];
    foreach ($data as $uid => $cfg) {
      $weight = $cfg['weight'];
      $users[$weight] = $uid;
    }
    ksort($users);
  }
  osha_workflow_set_node_approvers($node->nid, $users);
}

/**
 * PM Review Section form.
 */
function osha_workflow_access_section_review_form($form, &$form_state, $access_type, $access_type_id) {
  $access_info = workbench_access_load($access_type, $access_type_id);
  $output = '<h2>' . t('%name PM section review', array('%name' => $access_info['name'])) . '</h2>';
//  drupal_set_message(t("The children sections that does not have a PM assigned will be marked as reviewed!"), 'warning');
  $form_state['access_id'] = $access_type_id;
  $form_state['access_scheme'] = $access_type;
  $form['title'] = array(
    '#markup' => $output,
  );

  $form['actions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Reviews'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#access' => array('mark access section as reviewed'),
  );
  $form['actions']['review_message'] = array(
    '#type' => 'textarea',
    '#title' => 'Message',
    '#description' => t('You can enter a message for your review.'),
  );
  $form['actions']['mark_as_reviewed'] = array(
    '#type' => 'submit',
    '#submit' => array('osha_workflow_access_section_review_form_submit'),
    '#validate' => array(),
    '#value' => 'Mark this section as Reviewed',
    '#access' => array('mark access section as reviewed'),
  );
  $form['go_back'] = array(
    '#theme' => 'link',
    '#text' => t('Go back'),
    '#path' => 'admin/config/workbench/access/managers',
    '#options' => array(
      'attributes' => array(),
      'html' => FALSE,
    ),
  );

  global $user;
  $form['actions']['#access'] = FALSE;
  if (in_array('administrator', $user->roles)) {
    $form['actions']['#access'] = TRUE;
  }
  if ($pms = osha_workflow_access_get_section_pm($access_type_id)) {
    // Current user is among the PMs for this section
    if (array_key_exists($user->uid, $pms)) {
      $form['actions']['#access'] = TRUE;
    }
  }

  // Add review history.
  $form['reviews'] = array(
    '#type' => 'fieldset',
    '#title' => t('Reviews'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $reviews = osha_workflow_get_section_reviews($access_type_id);
  $rows = array();
  foreach ($reviews as $review) {
    $reviewer = user_load($review->uid);
    $rows[] = array(
      $reviewer->name,
      date('d-m-Y', $review->created),
      $review->message,
    );
  }
  $header = array('Reviewer', 'Data', 'Mesaj');
  $form['reviews']['table'] = array(
    '#markup' => theme('table', array('header' => $header, 'rows' => $rows)),
  );

  return $form;
}

/**
 * Submit callback for PM Review Section.
 */
function osha_workflow_access_section_review_form_submit($form, &$form_state) {
  global $user;
  $access_id = $form_state['access_id'];
  $message = $form_state['values']['review_message'];
  $review = array(
    'uid' => $user->uid,
    'access_id' => $access_id,
    'message' => $message,
    'created' => REQUEST_TIME,
  );
  // Add the review.
  drupal_write_record('osha_workflow_sections_review', $review);

  $active_tree = workbench_access_get_active_tree();
  if (!empty($active_tree['tree'][$access_id]['children'])) {
    // Get the access ids that have PM assigned.
    $aids = db_select('osha_workflow_access_pm', 'owa')
      ->fields('owa')
      ->execute()
      ->fetchAllAssoc('access_id');
    $aids = array_keys($aids);

    // Mark as reviewed all children section that have no PM assigned.
    foreach ($active_tree['tree'][$access_id]['children'] as $access) {
      if (!in_array($access, $aids)) {
        unset($review['srid']);
        $review['access_id'] = $access;
        drupal_write_record('osha_workflow_sections_review', $review);
      }
    }
  }
  drupal_set_message(t('Section reviewed successfully!'));
  $form_state['redirect'] = 'admin/config/workbench/access/managers';
}

/**
 * Get the reviews of a section.
 */
function osha_workflow_get_section_reviews($access_id) {
  $review = db_select('osha_workflow_sections_review', 'sr')
    ->fields('sr')
    ->condition('sr.access_id', $access_id)
    ->orderBy('sr.srid', 'DESC')
    ->execute()
    ->fetchAllAssoc('srid');
  return $review;
}
