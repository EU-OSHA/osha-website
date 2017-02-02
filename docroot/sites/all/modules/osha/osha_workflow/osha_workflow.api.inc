<?php

/**
 * Retrieve the list of default moderators stored in entity_collection.
 *
 * @return mixed
 *   Array of user accounts, ordered by weight in the collection.
 */
function osha_workflow_get_default_approvers() {
  $entity_collection = entity_collection_load('approvers');
  $contexts = _entity_collection_get_contexts($entity_collection);
  $tree = EntityCollectionStorage::getBundleStorage($entity_collection->bundle)->retrieve($entity_collection, $contexts);
  $rows = $tree->getFlat();
  $uids = array();
  foreach ($rows as $row) {
    $uids[] = $row->entity_id;
  }
  $users = user_load_multiple($uids);
  foreach ($users as &$user) {
    $user->osha_workflow_node_approval_saved = FALSE;
  }
  return $users;
}

function osha_workflow_rebuild_pm_sections($uid, $sections) {
  $workbench_access_scheme = variable_get('workbench_access');
  db_delete('osha_workflow_access_pm')
    ->condition('access_scheme', $workbench_access_scheme)
    ->condition('uid', $uid)
    ->execute();
  foreach($sections as $sid) {
    $record = array(
      'uid' => $uid,
      'access_id' => $sid,
      'access_scheme' => $workbench_access_scheme,
    );
    drupal_write_record('osha_workflow_access_pm', $record);
  }
}

function osha_workflow_rebuild_rm_sections($uid, $sections) {
  $workbench_access_scheme = variable_get('workbench_access');
  db_delete('osha_workflow_access_rm')
    ->condition('access_scheme', $workbench_access_scheme)
    ->condition('uid', $uid)
    ->execute();
  foreach($sections as $sid) {
    $record = array(
      'uid' => $uid,
      'access_id' => $sid,
      'access_scheme' => $workbench_access_scheme,
    );
    drupal_write_record('osha_workflow_access_rm', $record);
  }
}

/**
 * Get PMs for a section (currently one per section, but we return array).
 * @return array
 *   User objects
 */
function osha_workflow_access_get_section_pm($section_id) {
  $ret = array();
  $section_tree = workbench_access_get_active_tree();
  $access = $section_tree['tree'][$section_id];
  $access_id = $access['access_id'];
  $access_scheme = $section_tree['access_scheme']['access_scheme'];

  $users = db_select('osha_workflow_access_pm', 'owa')
    ->fields('owa', array('uid'))
    ->condition('access_id', $access_id, '=')
    ->condition('access_scheme', $access_scheme)
    ->execute()
    ->fetchAllAssoc('uid');
  if (!empty($users)) {
    $ret = user_load_multiple(array_keys($users));
  }
  return $ret;
}

/**
 * Get sections ids of a pm.
 */
function osha_workflow_access_get_pm_sections($uid) {
  $sections = db_select('osha_workflow_access_pm', 'owa')
    ->fields('owa', array('access_id'))
    ->condition('uid', $uid)
    ->execute()
    ->fetchAllAssoc('access_id');
  return array_keys($sections);
}

/**
 * This method creates the user roles required by the workflow.
 * @codeCoverageIgnore
 */
function osha_workflow_create_roles() {
  module_load_include('inc', 'osha_workflow', 'osha_workflow.permissions');
  $roles = array(
    'Editor' => osha_workflow_permissions_role_editor(),
    'Review Manager' => osha_workflow_permissions_role_review_manager(),
    'Project Manager' => osha_workflow_permissions_role_project_manager(),
    'Approver' => osha_workflow_permissions_role_approver(),
  );

  foreach ($roles as $role_name => $permissions) {
    if ($role = user_role_load_by_name($role_name)) {
      // Nothing to do, really ...
    }
    else {
      $role = new stdClass();
      $role->name = $role_name;
      user_role_save($role);
    }
    user_role_grant_permissions($role->rid, $permissions);
    // Grant workbench access for this role.
    workbench_access_role_section_save($role->rid, 'main-menu', 'menu');
  }
}

/**
 * Check if user has access to the node.
 *
 * This function matches node section(s) against user sections.
 *
 * @param object $node
 *   Queried node
 *
 * @return bool
 *   TRUE if at least one section is matched
 */
function osha_workflow_user_has_access($node) {
  $user_sections = workbench_access_get_user_tree();
  return count(array_intersect(array_keys($user_sections), $node->workbench_access)) > 0;
}

/**
 * Retrieve the list of moderators for a node.
 *
 * @param int $nid
 *   Node ID
 * @param bool $default
 *   If not set yet, return the default values stored in the entity collection.
 *
 * @return array|mixed
 *   Array of users.
 */
function osha_workflow_get_node_approvers($nid, $default = TRUE) {
  $ret = array();
  $query = new EntityFieldQuery();
  $moderators = $query->entityCondition('entity_type', 'node_approval')
    ->propertyCondition('nid', $nid)
    ->propertyOrderBy('weight')
    ->execute();
  if (!empty($moderators['node_approval'])) {
    $ids = array_keys($moderators['node_approval']);
    $rows = osha_workflow_node_approval_load_multiple($ids);
    $uids = array();
    $rows_by_uid = array();
    foreach ($rows as $row) {
      $rows_by_uid[$row->uid] = $row;
      $uids[] = $row->uid;
    }
    $users = user_load_multiple($uids);
    foreach ($users as &$user) {
      $user->osha_workflow_node_approval = $rows_by_uid[$user->uid];
      $user->osha_workflow_node_approval_saved = TRUE;
    }
    reset($users);
    return $users;
  }
  elseif ($default) {
    $ret = osha_workflow_get_default_approvers();
  }
  return $ret;
}

/**
 * Assign the list of moderators to a node.
 *
 * @param object $nid
 *   Node ID
 * @param array $moderators
 *   Associative array of user accounts. Keys are weights, values are uids.
 */
function osha_workflow_set_node_approvers($nid, $moderators) {
  $transaction = db_transaction();
  try {
    // Delete old records for this node.
    db_delete('osha_workflow_node_approval')
      ->condition('nid', $nid)
      ->execute();
    $query = db_insert('osha_workflow_node_approval')
      ->fields(array('nid', 'uid', 'next', 'weight'));
    $i = 0;
    foreach ($moderators as $weight => $uid) {
      $record = array(
        'nid' => $nid,
        'uid' => $uid,
        'next' => $i == 0 ? 1 : 0,
        'weight' => $weight,
      );
      $query->values($record);
      $i++;
    }
    $query->execute();
  }
  catch(Exception $e) {
    $transaction->rollback();
    drupal_set_message($e->getMessage(), 'error');
  }
}

/**
 * Reset voting status and next in line approval queue.
 *
 * @param int $nid
 *   Affected node ID
 */
function osha_workflow_reset_node_approvers($nid) {
  $transaction = db_transaction();
  try {
    $rows = osha_workflow_get_node_approvers($nid, FALSE);
    $first = NULL;
    if (!empty($rows)) {
      $first = current($rows);
    }
    // Reset all of them to defaults.
    db_update('osha_workflow_node_approval')
      ->fields(array(
        'approved' => NULL,
        'next' => 0,
      ))
      ->condition('nid', $nid)
      ->execute();

    if ($first) {
      // Assign 'next' to first one in line.
      db_update('osha_workflow_node_approval')
        ->fields(array(
          'next' => 1,
        ))
        ->condition('nid', $nid)
        ->condition('uid', $first->uid)
        ->execute();
    }
  }
  catch(Exception $e) {
    $transaction->rollback();
    drupal_set_message($e->getMessage(), 'error');
  }
}

/**
 * Find the next moderator in the line for a node/revision.
 *
 * @param object $node
 *   Node to retrieve info.
 *
 * @return mixed|null
 *   User account
 */
function osha_workflow_get_next_approver($nid) {
  $ret = NULL;
  $query = new EntityFieldQuery();
  $moderators = $query->entityCondition('entity_type', 'node_approval')
    ->propertyCondition('nid', $nid)
    ->propertyCondition('next', 1)
    ->range(0, 1)
    ->execute();
  if (!empty($moderators['node_approval'])) {
    $rows = osha_workflow_node_approval_load_multiple(array_keys($moderators['node_approval']));
    $task = current($rows);
    $ret = user_load($task->uid);
  }
  return $ret;
}

function osha_workflow_is_next_approver($nid, $user=NULL) {
  if (empty($user)) {
    global $user;
  }
  $query = new EntityFieldQuery();
  $rows = $query->entityCondition('entity_type', 'node_approval')
    ->propertyCondition('nid', $nid)
    ->propertyCondition('uid', $user->uid)
    ->propertyCondition('next', 1)
    ->execute();
  return !empty($rows['node_approval']);
}

/**
 * Check if the user is the last approver.
 *
 * @param object $node
 *   Node to check
 * @param object $user
 *   User to check. If NULL, assuming current user.
 *
 * @return bool
 *   TRUE if it's the last in the queue.
 */
function osha_workflow_is_last_approver($node, $user = NULL) {
  $ret = FALSE;
  if (empty($user)) {
    global $user;
  }
  $all_users = osha_workflow_get_node_approvers($node->nid, FALSE);
  if (!empty($all_users)) {
    $last = array_pop($all_users);
    $ret = $user->uid == $last->uid;
  }
  return $ret;
}

function osha_workflow_needs_last_approver($node, $user = NULL) {
  $ret = FALSE;
  $query = new EntityFieldQuery();
  $miids = $query->entityCondition('entity_type', 'node_approval')
    ->propertyCondition('nid', $node->nid)
    ->propertyOrderBy('weight')
    ->execute();
  if (isset($miids['node_approval'])) {
    $rows = osha_workflow_node_approval_load_multiple(array_keys($miids['node_approval']));
    reset($rows);
    $last = array_pop($rows);
    $ret = $last->next == 1;
  }
  return $ret;
}

/**
 * Verifies if user has approved the workflow.
 * @param $nid
 * @param $uid
 * @return bool
 */
function osha_workflow_has_approved($nid, $uid) {
  $query = new EntityFieldQuery();
  $rows = $query->entityCondition('entity_type', 'node_approval')
    ->propertyCondition('nid', $nid)
    ->propertyCondition('uid', $uid)
    ->propertyCondition('approved', array(OSHA_WORKFLOW_STATE_APPROVED, OSHA_WORKFLOW_STATE_REJECTED))
    ->execute();
  return !empty($rows['node_approval']);
}


/**
 * Record the user's vote and move the record to the next in queue.
 *
 * @param object $node
 *   Node object
 * @param int $vote
 *   User's vote (accepted, rejected)
 * @param string $message
 *   User's message
 * @param object $voter
 *   User who vote, if NULL assuming current user.
 */
function osha_workflow_approve($node, $vote, $message = '', $voter = NULL) {
  if (empty($voter)) {
    global $user;
    $voter = $user;
  }
  $transaction = db_transaction();
  try {
    $query = new EntityFieldQuery();
    $miids = $query->entityCondition('entity_type', 'node_approval')
      ->propertyCondition('nid', $node->nid)
      ->propertyOrderBy('weight')
      ->execute();
    if (isset($miids['node_approval'])) {
      $rows = osha_workflow_node_approval_load_multiple(array_keys($miids['node_approval']));
      reset($rows);
      $mark_next = FALSE;
      foreach ($rows as $row) {
        if (($row->uid == $voter->uid || user_access('moderate content from ready_to_publish to published'))
          && $row->next == 1) {
          $mark_next = TRUE;
          $row->next = 0;
          $row->approved = $vote;
          if ($row->uid != $voter->uid) {
            $message .= $voter->name . 'approved the content.';
          }
          $row->mesage = $message;
          entity_save('node_approval', $row);
          continue;
        }
        if ($mark_next) {
          $row->next = 1;
          entity_save('node_approval', $row);
          break;
        }
      }
    }
  }
  catch(Exception $e) {
    $transaction->rollback();
    drupal_set_message($e->getMessage(), 'error');
  }
}

/**
 * Make an HTML select options from the list of users assigned to a role.
 *
 * @param string $role_name
 *   Name of the Role
 *
 * @see osha_workflow_users_get_review_managers
 * @return array
 *   HTML select options
 */
function osha_workflow_users_get_users_from_role_as_options($role_name) {
  $users = osha_workflow_users_get_users_from_role($role_name);
  $ret = array();
  foreach ($users as $uid => $u) {
    $ret[$uid] = $u->name;
  }
  return $ret;
}

/**
 * Retrieve the list of users from a role, ordered by name.
 *
 * @param string $role_name
 *   Name of the Role
 *
 * @return array
 *   Array of user objects
 */
function osha_workflow_users_get_users_from_role($role_name) {
  $ret = array();
  if ($role = user_role_load_by_name($role_name)) {
    $query = db_select('users', 'u')->fields('u', array('uid'));
    $query->join('users_roles', 'ur', 'ur.uid = u.uid');
    $uids = $query->condition('ur.rid', $role->rid)
      ->orderBy('u.name')
      ->groupBy('u.uid')
      ->execute()->fetchCol();
    $ret = user_load_multiple($uids);
  }
  return $ret;
}

/**
 * Class OshaWorkflowPermissions handles permission check for the workflow.
 */
class OshaWorkflowPermissions {

  /**
   * Implemented rules.
   *
   * REV_RM_US_02
   * REV_RM_US_03
   * REV_RM_US_04
   * REV_RM_US_05
   * REV_RM_US_07
   *
   * @return bool
   *   TRUE if the user has permission.
   */
  public static function userCanAccessReviewScreen($node, $user = NULL) {
    if (!$user) {
      global $user;
    }
    if (isset($node->workbench_moderation)) {
      $node_in_rm_section = FALSE;
      if (self::userHasRole(OSHA_WORKFLOW_ROLE_REVIEW_MANAGER, $user)) {
        $node_in_rm_section = osha_workflow_node_in_rm_section($node, $user);
      }
      $is_pm = FALSE;
      if (self::userHasRole(OSHA_WORKFLOW_ROLE_PROJECT_MANAGER, $user) && _osha_workflow_node_has_pm($node, $user)) {
        $is_pm = TRUE;
      }
      $is_admin = self::userHasRole(OSHA_WORKFLOW_ROLE_ADMINISTRATOR, $user);
      return $is_pm || $is_admin || $node_in_rm_section;
    }
    return FALSE;
  }


  /**
   * User has access to the approval screen (tab on node).
   *
   * @param object $node
   *   Node to check
   * @param null $user
   *   User to check. If NULL assuming current user
   *
   * @return bool
   *   TRUE if user has access.
   */
  public static function userCanAccessApprovalScreen($node, $user = NULL) {
    if (!$user) {
      global $user;
    }
    if (isset($node->workbench_moderation)) {
      $node_in_rm_section = osha_workflow_node_in_rm_section($node, $user);
      $is_admin = self::userHasRole(OSHA_WORKFLOW_ROLE_ADMINISTRATOR, $user);
      return $is_admin || $node_in_rm_section;
    }
    return FALSE;
  }

  /**
   * User can manage the approvers.
   *
   * @param object $node
   *   Node to check
   * @param null $user
   *   User to check. If NULL assuming current user
   *
   * @return bool
   *   TRUE if user has access.
   */
  public static function userCanEditApprovers($node, $user = NULL) {
    if (!$user) {
      global $user;
    }
    if (isset($node->workbench_moderation)) {
      $current = $node->workbench_moderation['current'];
      $state = $current->state;

      if (self::userHasRole(OSHA_WORKFLOW_ROLE_ADMINISTRATOR, $user)) {
        return TRUE;
      }
      return
        self::userHasRole(OSHA_WORKFLOW_ROLE_REVIEW_MANAGER, $user)
        &&
        (
          $state == OSHA_WORKFLOW_STATE_TO_BE_REVIEWED
          || $state == OSHA_WORKFLOW_STATE_FINAL_DRAFT
        );
    }
    return FALSE;
  }


  /**
   * Check user has a specified role.
   *
   * @param string $role
   *   Existing user role
   * @param array $user
   *   Existing user role
   *
   * @return bool
   *   TRUE if user has role
   */
  public static function userHasRole($role, $user) {
    if (isset($user->roles)) {
      return in_array($role, $user->roles);
    }
    return FALSE;
  }

  /**
   * Check the user has Administrator role or is user/1.
   *
   * @param object $user
   *   User to check
   *
   * @return bool
   *   TRUE if user is admin or Administrator role.
   */
  public static function userIsAdministrator($user) {
    if (isset($user->uid) && $user->uid == 1) {
      return TRUE;
    }
    else {
      return self::userHasRole(OSHA_WORKFLOW_ROLE_ADMINISTRATOR, $user);
    }
  }

  /**
   * Get the users by role name.
   *
   * @param string|int $role
   *   Role name on rid
   *
   * @return mixed
   *   FALSE or array of user object.
   */
  public static function getUsersByRole($role) {
    if (is_numeric($role)) {
      $rid = $role;
    }
    else {
      $role = user_role_load_by_name($role);
      $rid = $role->rid;
    }

    $query = db_select('users', 'u');
    $query->fields('u', array('uid'));
    $query->join('users_roles', 'ur', 'ur.uid = u.uid');
    $query->condition('ur.rid', $rid);
    $result = $query->execute()->fetchAllAssoc('uid');
    $uids = array_keys($result);
    return user_load_multiple($uids);
  }
}

/**
 * Class OshaWorkflowNotifications sends notifications for workflow transitions.
 * @codeCoverageIgnore
 */
class OshaWorkflowNotifications {

  /**
   * Notify Review Manager the content was set to Final Draft.
   *
   * REV_EE_US_03
   *
   * @param object $node
   *   Affected node
   */
  public static function notifyOnChangeFromDraftToFinalDraft($node) {
    // Get RM of node's section.
    $users = osha_workflow_get_node_rm($node);
    OshaWorkflowNotifications::sendEmail($users, array('node' => $node), 'osha_workflow');
  }

  /**
   * Notify Editor the content was set to Draft.
   *
   * REV_EE_US_05
   *
   * @param object $node
   *   Affected node
   */
  public static function notifyOnChangeToDraft($node) {
    $user = user_load($node->uid);
    OshaWorkflowNotifications::sendEmail($user, array('node' => $node), 'osha_workflow');
  }

  /**
   * Notify PM that content was set to ToBeReviewd..
   *
   * REV_EE_US_05
   *
   * @param object $node
   *   Affected node
   */
  public static function notifyOnChangeFromDraftOrFinalDraftToBeReviewed($node) {
    $users = osha_workflow_get_node_rm($node);
    $users[] = _osha_workflow_get_current_pm_approver($node->nid);
    OshaWorkflowNotifications::sendEmail($users, array('node' => $node), 'osha_workflow');
  }

  /**
   * Send notification to the next approver (after the previous marked as done).
   *
   * @param object $node
   *   Affected node
   */
  public static function notifyNextApproverToTakeAction($node) {
    $next_approval = osha_workflow_get_next_approver($node->nid);
    OshaWorkflowNotifications::sendEmail($next_approval, array('node' => $node), 'osha_workflow');
  }

  /**
   * Notification sent when Node was accepted by the last approver.
   *
   * Notify RMs, PM for that section
   * (ToBeApproved => Approved)
   *
   * @param object $node
   *   Affected node
   */
  public static function notifyOnNodeApproved($node) {
    $users = osha_workflow_get_node_rm($node);
    $pms = osha_workflow_get_pms_users($node->nid);
    if (!empty($pms)) {
      $users = array_merge($users, $pms);
    }
    OshaWorkflowNotifications::sendEmail($users, array('node' => $node), 'osha_workflow');
  }

  /**
   * Notification sent when Node was rejected by the last approver.
   *
   * (ToBeApproved => Rejected)
   *
   * @param object $node
   *   Affected node
   */
  public static function notifyOnNodeRejected($node) {
    $users = osha_workflow_get_node_rm($node);
    if (!empty($pms)) {
      $users = array_merge($users, $pms);
    }
    OshaWorkflowNotifications::sendEmail($users, array('node' => $node), 'osha_workflow');
  }

  /**
   * Notification sent when the node was rejected by PM (set in FinalDraft).
   *
   * (Approved => FinalDraft)
   *
   * @param object $node
   *   Affected node
   */
  public static function notifyNodeRejectedFromApprovedToFinalDraft($node) {
    $users = osha_workflow_get_node_rm($node);
    OshaWorkflowNotifications::sendEmail($users, array('node' => $node), 'osha_workflow');
  }

  /**
   * Notification sent when the node is ready to be published.
   *
   * Notify Administrators (web team) that PM set in ReadyToPublish
   *
   * (Approved => ReadyToPublish)
   *
   * @param object $node
   *   Affected node
   */
  public static function notifyNodeIsReadyToPublish($node) {
    $review_managers = osha_workflow_get_node_rm($node);
    OshaWorkflowNotifications::sendEmail($review_managers, array('node' => $node), 'osha_workflow');

    // No longer needed, see MDR-351
    //$translation_managers = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_TRANSLATION_MANAGER);
    //OshaWorkflowNotifications::sendEmail($translation_managers, array('node' => $node), 'osha_tmgmt', 'notifyNodeIsReadyToPublish');
  }

  /**
   * REV_RM_US_15 Notification sent to WebTeam when a node had status changed.
   */
  public static function notifyWebTeamStatusChanged($node, $from_state, $to_state) {
    if ($from_state != $to_state) {
      $params = array(
        'node' => $node,
        'from' => $from_state,
        'to' => $to_state,
      );
      $users = osha_workflow_get_node_rm($node);
      OshaWorkflowNotifications::sendEmail($users, $params, 'osha_workflow', 'osha_workflow_notification_admin');
    }
  }

  /**
   * Notification First approver that the approval workflow begins.
   *
   * (Approved => ReadyToPublish)
   *
   * @param object $node
   *   Affected node
   */
  public static function notifyFirstApprover($node) {
    $next_approval = osha_workflow_get_next_approver($node->nid);
    OshaWorkflowNotifications::sendEmail($next_approval, array('node' => $node), 'osha_workflow');
  }

  /**
   * TRANS_T_US_01 Notify Translation Liaison there is content to translate.
   *
   * @param TMGMTJob $tmgmt_job
   *   Job created
   */
  public static function notifyTranslationJobCreated($tmgmt_job) {
    $users = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_TRANSLATION_LIAISON);
    OshaWorkflowNotifications::sendEmail($users, array('tmgmt_job' => $tmgmt_job), 'osha_tmgmt');
  }

  /**
   * TRANS_TM_US_13 Notify Translation Manager when a new file is uplaoded.
   *
   * @param TMGMTJob $tmgmt_job
   *   Job created
   */
  public static function notifyTranslationUploadedFile($tmgmt_job) {
    // See CW-696 (Notification not needed)
    // $users = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_TRANSLATION_MANAGER);
    // OshaWorkflowNotifications::sendEmail($users, array('tmgmt_job' => $tmgmt_job), 'osha_tmgmt');
  }

  /**
   * Notify Layout Approvers.
   */
  public static function notifyTranslationLayoutApprovers($tmgmt_job_item) {
    $users = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_LAYOUT_VALIDATOR);
    OshaWorkflowNotifications::sendEmail($users, array('tmgmt_job_item' => $tmgmt_job_item), 'osha_tmgmt');
  }

  /**
   * Notify Translation Manager that Layout is Approved.
   *
   * @param TMGMTJobItem|OshaTMGMTJobItem $tmgmt_job_item
   *   Job created
   */
  public static function notifyTranslationLayoutApproved($tmgmt_job_item) {
    $users = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_TRANSLATION_MANAGER);
    OshaWorkflowNotifications::sendEmail($users, array('tmgmt_job_item' => $tmgmt_job_item), 'osha_tmgmt');
  }

  /**
   * Notify Translation Manager the content translation was validated.
   *
   * @param TMGMTJobItem|OshaTMGMTJobItem $tmgmt_job_item
   *   Job created
   */
  public static function notifyTranslationValidated($tmgmt_job_item) {
    $users = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_TRANSLATION_MANAGER);
    OshaWorkflowNotifications::sendEmail($users, array('tmgmt_job_item' => $tmgmt_job_item), 'osha_tmgmt');
  }

  /**
   * Notify Translation Manager the content translation was rejected.
   *
   * @param TMGMTJobItem|OshaTMGMTJobItem $tmgmt_job_item
   *   Job created
   */
  public static function notifyTranslationRejected($tmgmt_job_item) {
    $tmanagers = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_TRANSLATION_MANAGER);
    $tliaisons = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_TRANSLATION_LIAISON);
    $users = array_merge($tmanagers, $tliaisons);
    OshaWorkflowNotifications::sendEmail($users, array('tmgmt_job_item' => $tmgmt_job_item), 'osha_tmgmt');
  }

  /**
   * Notify Next Translation Content Validator the content needs validation..
   *
   * @param TMGMTJobItem|OshaTMGMTJobItem $tmgmt_job_item
   *   Job created
   */
  public static function notifyTranslationValidators($tmgmt_job_item) {
    $validators = osha_tmgmt_load_validators_by_job_item($tmgmt_job_item);
    $next_validator = osha_tmgmt_load_validators_next($validators);
    OshaWorkflowNotifications::sendEmail($next_validator, array('tmgmt_job_item' => $tmgmt_job_item), 'osha_tmgmt');
  }

  /**
   * CW-1766 Notify Content Validator that his action is no longer needed.
   */
  public static function notifyTranslationValidatorsRemoved($validator, $tmgmt_job_item) {
    OshaWorkflowNotifications::sendEmail($validator, array('tmgmt_job_item' => $tmgmt_job_item), 'osha_tmgmt', 'osha_tmgmt_content_validator_removed');
  }

  /**
   * Notify Project Manager that translation is ready to publish..
   *
   * @param TMGMTJobItem|OshaTMGMTJobItem $tmgmt_job_item
   *   Job created
   */
  public static function notifyTranslationProjectManager($tmgmt_job_item) {
    $project_manager = _osha_workflow_get_current_pm_approver($tmgmt_job_item->item_id);
    if (empty($project_manager)) {
      drupal_set_message(t('The node does not have a PM assigned. Please contact an administrator!'), 'warning');
    }
    OshaWorkflowNotifications::sendEmail($project_manager, array('tmgmt_job_item' => $tmgmt_job_item), 'osha_tmgmt');
  }

  /**
   * Notify Translation Manager and Review managers when a translation is published/merged/accepted.
   *
   * @param TMGMTJobItem|OshaTMGMTJobItem $tmgmt_job_item
   *   Job created
   */
  public static function notifyTranslationAccepted($tmgmt_job_item) {
    $tmanagers = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_TRANSLATION_MANAGER);
    $rmanagers = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_REVIEW_MANAGER);
    $users = array_unique(array_merge($tmanagers, $rmanagers), SORT_REGULAR);
    OshaWorkflowNotifications::sendEmail($users, array('tmgmt_job_item' => $tmgmt_job_item), 'osha_tmgmt');
  }

  /**
   * Check user preference to receive notifications from the workflow.
   *
   * @param mixed $user
   *   User account or User ID
   *
   * @return bool
   *   TRUE if user has checked out the option
   */
  public static function userAllowsEmailNotifications($user) {
    if (is_int($user)) {
      $user = user_load($user);
    }
    return !empty($user->field_cmw_mail_notifications[LANGUAGE_NONE][0]['value']);
  }

  /**
   * Send e-mails to recipients. Filters out users who opted out.
   *
   * @param array $users
   *   Array of recipients accounts objects.
   * @param array $params
   *   Array of tokens to replace in the subject and body of the email
   * @param string $module
   *   Module name which builds the template (implements hook_mail).
   * @param string $key
   *   (Optional) Identifier for email type  to allow choosing proper template.
   */
  public static function sendEmail($users, $params, $module, $key = 'osha_workflow_notification') {
    global $osha_workflow_block_mail;
    if ($osha_workflow_block_mail == TRUE) {
      return;
    }
    if (empty($users)) {
      drupal_set_message('There are no users to notify about your action. Please report this to system administrator.', 'warning');
      return;
    }
    if (drupal_is_cli()) {
      drupal_set_message('Not sending emails from cli.', 'status');
      return;
    }
    if (!is_array($users)) {
      $users = array($users);
    }

    foreach ($users as $user) {
      if (self::userAllowsEmailNotifications($user) && variable_get('osha_workflow_send_mail')) {
        $params['user'] = $user;
        drupal_mail($module, $key, $user->mail, user_preferred_language($user), $params);
      }
    }
  }
}
