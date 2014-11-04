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

/**
 * Function to retrieve default Project Manager for a section.
 *
 *   It searches UP in the section tree for an assigned PM.
 *
 * @param int|string $section
 *   Section ID
 *
 * @return object|FALSE
 *   User Object
 */
function osha_workflow_get_default_project_manager($section) {
  $section_tree = workbench_access_get_active_tree();
  if (osha_workflow_access_pm_check_root()) {
    if (!empty($section_tree['tree'])) {
      $users = osha_workflow_access_find_pm($section_tree, $section);
      if (!empty($users)) {
        return current($users);
      }
    }
  }
  return FALSE;
}

/**
 * Recursion Function to get the project manager from sections tree.
 *
 * @param array $section_tree
 *   active tree array
 * @param int|string $section_id
 *   Id of the section to search PM for
 *
 * @return array
 *   Array of Users Objects
 */
function osha_workflow_access_find_pm(&$section_tree, $section_id) {
  $access = $section_tree['tree'][$section_id];
  $users = osha_workflow_access_pm_get_pm($access['access_id'],
    $section_tree['access_scheme']['access_scheme']);
  if (empty($users)&& !empty($access['parent'])) {
    $users = osha_workflow_access_find_pm($section_tree, $access['parent']);
  }
  else {
    return $users;
  }
  return $users;
}

/**
 * Get PM of a section.
 */
function osha_workflow_access_pm_get_pm($access_id, $access_scheme) {
  $users = db_select('osha_workflow_access_pm', 'owa')
    ->fields('owa', array('uid'))
    ->condition('access_id', $access_id)
    ->condition('access_scheme', $access_scheme)
    ->execute()
    ->fetchAllAssoc('uid');
  return user_load_multiple(array_keys($users));
}

/**
 * Checks for PM to be assigned to root Section.
 *
 * @return bool
 *   If a PM is assigned for root Section or not.
 */
function osha_workflow_access_pm_check_root() {
  $section_tree = workbench_access_get_active_tree();
  $access = current($section_tree['tree']);
  if (!empty($access)) {
    $users = osha_workflow_access_pm_get_pm($access['access_id'],
      $section_tree['access_scheme']['access_scheme']);
    if (!empty($users)) {
      return TRUE;
    }
    else {
      drupal_set_message(t("Workflow: You haven't assigned a PM for root Section"), 'error');
      return FALSE;
    }
  }
  return FALSE;
}
/**
 * Assign project manager to a node.
 *
 * @param object $nid
 *   Node ID
 * @param int $uid
 *   User account
 */
function osha_workflow_set_project_manager($nid, $uid) {
  try {
    db_merge('osha_workflow_node_project_managers')
      ->key(array(
        'nid' => $nid,
      ))
      ->fields(array(
        'nid' => $nid,
        'uid' => $uid,
      ))->execute();
  }
  catch(Exception $e) {
    drupal_set_message($e->getMessage(), 'error');
  }
}

/**
 * Get the current project manager of a node.
 *
 * @param int $nid
 *   Node ID
 *
 * @return object
 *   User object
 */
function osha_workflow_get_project_manager($nid) {
  $result = db_query('SELECT a.* FROM {osha_workflow_node_project_managers} a WHERE a.nid = :nid', array(':nid' => $nid));
  if ($row = $result->fetchAssoc()) {
    $user = user_load($row['uid']);
    $user->osha_workflow['project_manager'][$nid] = (object) $row;
    return $user;
  }
  return NULL;
}

/**
 * Get the current project manager of a node.
 *
 * @param int $nid
 *   Node ID
 *
 * @return object
 *   User object
 */
function osha_workflow_is_assigned_project_manager($nid) {
  if ($project_manager = osha_workflow_get_project_manager($nid)) {
    global $user;
    return $project_manager->uid == $user->uid;
  }
  return FALSE;
}

/**
 * This method creates the user roles required by the workflow.
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
function osha_workflow_approve($node, $vote, $message = NULL, $voter = NULL) {
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
        if ($row->uid == $voter->uid && $row->next == 1) {
          $mark_next = TRUE;
          $row->next = 0;
          $row->approved = $vote;
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
      // $current = $node->workbench_moderation['current'];
      // $state = $current->state;
      return
        self::userHasRole(OSHA_WORKFLOW_ROLE_REVIEW_MANAGER, $user)
        || self::userHasRole(OSHA_WORKFLOW_ROLE_ADMINISTRATOR, $user);
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
      // $current = $node->workbench_moderation['current'];
      // $state = $current->state;

      if (self::userHasRole(OSHA_WORKFLOW_ROLE_ADMINISTRATOR, $user)
          || self::userHasRole(OSHA_WORKFLOW_ROLE_REVIEW_MANAGER, $user)) {
        return TRUE;
      }
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
    return in_array($role, $user->roles);
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
    return self::userHasRole(OSHA_WORKFLOW_ROLE_ADMINISTRATOR, $user) || $user->uid == 1;
  }

  /**
   * Get the users by role name.
   *
   * @param string $role_name
   *   Role name
   *
   * @return mixed
   *   FALSE or array of user object.
   */
  public static function getUsersByRole($role_name) {
    $role = user_role_load_by_name($role_name);
    $query = db_select('users', 'u');
    $query->fields('u', array('uid'));
    $query->join('users_roles', 'ur', 'ur.uid = u.uid');
    $query->condition('ur.rid', $role->rid);
    $result = $query->execute()->fetchAllAssoc('uid');
    $uids = array_keys($result);
    return user_load_multiple($uids);
  }
}

/**
 * Class OshaWorkflowNotifications sends notifications for workflow transitions.
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
    $users = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_REVIEW_MANAGER);
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
    $user = osha_workflow_get_project_manager($node->nid);
    OshaWorkflowNotifications::sendEmail($user, array('node' => $node), 'osha_workflow');
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
    $users = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_REVIEW_MANAGER);
    $users[] = osha_workflow_get_project_manager($node->nid);
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
    $users = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_REVIEW_MANAGER);
    $users[] = osha_workflow_get_project_manager($node->nid);
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
    $users = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_REVIEW_MANAGER);
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
    $users = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_ADMINISTRATOR);
    OshaWorkflowNotifications::sendEmail($users, array('node' => $node), 'osha_workflow');

    $users = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_TRANSLATION_MANAGER);
    OshaWorkflowNotifications::sendEmail($users, array('node' => $node), 'osha_tmgmt', 'notifyNodeIsReadyToPublish');
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
    $users = OshaWorkflowPermissions::getUsersByRole(OSHA_WORKFLOW_ROLE_TRANSLATION_MANAGER);
    OshaWorkflowNotifications::sendEmail($users, array('tmgmt_job' => $tmgmt_job), 'osha_tmgmt');
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
   * Notify Project Manager that translation is ready to publish..
   *
   * @param TMGMTJobItem|OshaTMGMTJobItem $tmgmt_job_item
   *   Job created
   */
  public static function notifyTranslationProjectManager($tmgmt_job_item) {
    $project_manager = osha_workflow_get_project_manager($tmgmt_job_item->item_id);
    if (empty($project_manager)) {
      drupal_set_message(t('The node does not have a PM assigned. Please contact an administrator!'), 'warning');
    }
    OshaWorkflowNotifications::sendEmail($project_manager, array('tmgmt_job_item' => $tmgmt_job_item), 'osha_tmgmt');
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
    if (empty($users)) {
      drupal_set_message('There are no users to notify about your action. Please report this to system administrator.', 'warning');
      return;
    }
    if (!is_array($users)) {
      $users = array($users);
    }
    foreach ($users as $user) {
      if (self::userAllowsEmailNotifications($user)) {
        $params['user'] = $user;
        drupal_mail($module, $key, $user->mail, user_preferred_language($user), $params);
      }
    }
  }
}
