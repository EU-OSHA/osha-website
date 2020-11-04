<?php

/**
 * Ensure if user is approver, add/remove from the default list of approvers.
 *
 * @param $is_approver
 */
function osha_authentication_user_login_approver($user, $is_approver) {
  $approvers_collection = entity_collection_load('approvers');
  /** @var EntityCollectionTreeNode $users */
  $users = $approvers_collection->getTree();
  if ($is_approver && !array_key_exists('user:' . $user->uid, $users->list)) {
    $entity_id = entity_id('user', $user);
    watchdog('osha_authentication', 'Adding !user to the approver list', array('!user' => $user->name), WATCHDOG_WARNING);
    $item = new EntityCollectionTreeNode('user', $entity_id, $user);
    entity_collection_append_item($approvers_collection, $item);
  }
  if (!$is_approver && array_key_exists('user:' . $user->uid, $users->list)) {
    watchdog('osha_authentication', 'Removing !user from approver list', array('!user' => $user->name), WATCHDOG_WARNING);
    entity_collection_content_delete($approvers_collection, 'user', array($user->uid));
  }
}

/**
 * Given an array of Drupal role names, try to load them and return unique list
 * that can be assigned to user.
 *
 * @param array $proposed_roles
 *  List of roles names that to assign.
 *
 * @return array
 *   Array of array($rid => role_name)
 */
function osha_authentication_extract_user_roles($proposed_roles) {
  $ret = array();
  $roles_names = array('authenticated user');
  $roles_names = array_merge($roles_names, array_values($proposed_roles));
  // Load the actual roles from DB
  foreach($roles_names as $role_name) {
    if ($r = user_role_load_by_name($role_name)) {
      $ret[$r->rid] = $role_name;
    }
    else {
      // @todo:
    }
  }
  return $ret;
}

/**
 * Extract a single role and section from the DN of a group.
 *
 * @param string $group_dn
 *
 * @return array
 *  array with role and section. May be null
 */
function osha_authentication_get_role_and_section_from_dn($group_dn) {
  $role = NULL;
  $section_id = NULL;
  $language = NULL;
  $mappings = array(
    // Non-section roles (@todo: read from /admin/config/people/ldap/authorization/edit/drupal_role)
    'ADMIN' => 'administrator',
    'APPROVER' => 'Approver',
    'EVENTCOOR' => 'Events Coordinator',
    'EVENTEDT' => 'Events Editor',
    'NEWSEDT' => 'News Editor',
    'LAYVAL' => 'Layout Validator',
    'READ' => 'authenticated user',
    'OSHCOLL' => 'OSH Collaborator',
    'TRLMN' => 'Translation Manager',
    'TRLIAS' => 'Translation Liaison',
    // Per language
    'CV' => 'Content Validator',
    // Per-section roles
    'EDT' => 'Editor',
    'PM' => 'Project Manager',
    'RVMN' => 'Review Manager',
    'READONLY', OSHA_WORKFLOW_ROLE_READ_ONLY,
  );
  // LDAP group DN patterns:
  // * cn=SECTION_ROLE,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu
  // * cn=ROLE,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu
  if (preg_match('/[A-Z\d\-\_]*/i', $group_dn, $ldap_group_cn, 0, 3) && count($ldap_group_cn) == 1) {
    $section_id = NULL;
    $role = NULL;
    if (strpos($ldap_group_cn[0], '_') > 0) {
      list($section_id, $role) = explode('_', $ldap_group_cn[0]);
    } else {
      $role = $ldap_group_cn[0];
    }
    if($role == 'CV') {
      $language = $section_id;
      $section_id = NULL;
    }
    if($section_id == 'OSHA') {
      // Hard-coded root of workbench_access tree
      $section_id = 'section';
    }
    // Map the role
    if (array_key_exists($role, $mappings)) {
      $role = $mappings[$role];
    }
    else {
      $role = NULL;
      watchdog('osha_authentication',
        'Unable to extract role !role from group DN: !dn, please check naming scheme syntax (cn=$SECTION_$ROLE or cn=$ROLE)',
        array('!role' => $role, '!dn' => $group_dn),
        WATCHDOG_ERROR
      );
    }
  }
  return array($role, $section_id, $language);
}

function osha_authentication_ldap_fetch_user_groups($username, $ldap_server) {
  $ret = array();
  /** @var LDAPServer $ldap_server */
  $ldap_groups = $ldap_server->search('ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu', 'memberUid=' . $username);
  if (!$ldap_groups) {
    return $ret;
  }
  unset($ldap_groups['count']);
  foreach($ldap_groups as $group) {
    $ret[$group['dn']] = $group['dn'];
  }
  return $ret;
}

function osha_authentication_retrieve_ldap_sections($ldap_server) {
  $ret = array();
  /** @var LDAPServer $ldap_server */
  $ldap_groups = $ldap_server->search('ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu', 'cn=*');
  if (!$ldap_groups) {
    return $ret;
  }
  unset($ldap_groups['count']);
  foreach($ldap_groups as $ldap_group) {
    $dn = $ldap_group['dn'];
    // Do not parse Language skills groups
    if(!preg_match('/ou=Languages/', $dn) && strpos($dn, '_') > 0) {
      list($role, $section_id) = osha_authentication_get_role_and_section_from_dn($dn);
      if ($section_id) {
        $cn = NULL;
        // Extract group cn
        preg_match('/[A-Z\_]*/i', $dn, $cn, 0, 3);
        // Ignore all groups ending in _PM and _RVM (handled by _EDT)
        if (!preg_match('/\_PM$/', $cn[0]) && !preg_match('/\_RVMN$/', $cn[0])) {
          $description = $ldap_group['description'][0];
          $description = preg_replace('/\seditor$/i', '', $description);
          $ret[$section_id] = trim($description);
        }
      }
    }
  }
  return $ret;
}

/**
 * Check Drupal users no longer in LDAP and block them.
 *
 * @param $ldap_server
 */
function osha_authentication_block_disabled_ldap_accounts($ldap_server, $ldap_accounts = NULL) {
  if (!$ldap_accounts) {
    $ldap_accounts = osha_authentication_ldap_get_site_users($ldap_server);
  }
  try {
    $local_accounts = entity_load('user');
    foreach ($local_accounts as $account) {
      // Do not touch 'admin' accounts NOT coming from LDAP
      if ($account->uid > 1 && !empty($account->data['ldap_user']['init']['sid'])) {
        // Block LDAP accounts no longer member of any group from ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu
        // Unblock users which are added again
        $status = array_key_exists($account->name, $ldap_accounts) ? 1 : 0;
        if (!$status) {
          // Remove blocked user from the list of approvers
          osha_authentication_user_login_approver($account, FALSE);

          // Remove blocked user from all sections
          workbench_access_rebuild_user($account->uid, array());
          osha_workflow_rebuild_pm_sections($account->uid, array());
          osha_workflow_rebuild_rm_sections($account->uid, array());

          // Remove user roles
          db_delete('users_roles')->condition('uid', $account->uid)->execute();
          if ($account->status == 1) {
            watchdog('osha_authentication', 'Blocking inactive account (no longer in LDAP/part of any group): !user', array('!user' => $account->name), WATCHDOG_WARNING);
          }
        }
        else {
          if ($account->status == 0) {
            watchdog('osha_authentication', 'Reactivating acount: !user', array('!user' => $account->name), WATCHDOG_WARNING);
          }
        }
        $account->status = $status;
        // Set user status
        db_update('users')->fields(array(
          'status' => $status
        ))->condition('uid', $account->uid)->execute();
        // user_save($account, array('roles' => array()));
      }
    }
    return;
  }
  catch(Exception $e) {
    //@todo: Handle exception
  }
}

/**
 * Querying all cn=MainSite groups and extract unique memberUid to build the
 * list of website users
 *
 * @param stdClass $ldap_server
 *   LDAP data provider
 *
 * @return Array of user objects (name, mail) found in the groups keyed by uid
 */
function osha_authentication_ldap_get_site_users($ldap_server) {
  $ret = array();
  /** @var LDAPServer $ldap_server */
  $ldap_groups = $ldap_server->search('ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu', 'cn=*', array('dn', 'memberUid', 'cn'));
  if (!$ldap_groups) {
    throw new Exception('An error has occurred while querying LDAP server');
  }
  unset($ldap_groups['count']);
  $uids = array();
  foreach($ldap_groups as $group) {
    if (isset($group['memberuid']) && $group['memberuid']['count'] > 0) {
      unset($group['memberuid']['count']);
      $uids = array_merge($uids, $group['memberuid']);
    }
  }
  $uids = array_unique($uids);
  foreach($uids as $uid) {
    if ($ldap_account = $ldap_server->search('ou=people,dc=osha,dc=europa,dc=eu', 'uid=' . $uid, array('dn', 'mail'))) {
      if (empty($ldap_account[0]['dn'])) {
        watchdog('osha_authentication', 'uid not found: !uid', array('!uid' => $uid), WATCHDOG_WARNING);
        continue;
      }
      if (empty($ldap_account[0]['mail'][0])) {
        $mail = $uid . '@fake-domain.com';
      }
      else {
        $mail = $ldap_account[0]['mail'][0];
      }
      $dn = $ldap_account[0]['dn'];
      $user = (object) array(
        'dn' => $dn,
        'name' => $uid,
        'mail' => $mail,
      );
      $ret[$uid] = $user;
    }
  }
  return $ret;
}

/**
 * Fetch LDAP data and check if there are new sections to import or update
 * @param stdClass $ldap_server
 *   Server to query
 * @param bool $test
 *   If TRUE do not commit changes to database
 *
 * @throws \EntityMetadataWrapperException
 */
function osha_authentication_sync_ldap_sections($ldap_server, $test = FALSE) {
  $voc = taxonomy_vocabulary_machine_name_load('section');
  $ldap_sections = osha_authentication_retrieve_ldap_sections($ldap_server);
  // Load all terms
  $mappings = db_select('field_data_field_ldap_section_code', 'f')
    ->fields('f', array('field_ldap_section_code_value', 'entity_id'))
    ->execute()
    ->fetchAllKeyed(0);
  foreach($ldap_sections as $sid => $title) {
    if (!array_key_exists($sid, $mappings)) {
      // Save new section coming from LDAP
      // taxonomy_term_save()
      $wrapper = entity_property_values_create_entity('taxonomy_term', array(
        'name' => $title,
        'vocabulary' => $voc,
        'field_ldap_section_code' => $sid,
      ));
      if (!$test) {
        $wrapper->save();
      }
      watchdog(
        'osha_authentication',
        'LDAP provisioned new section <em>!section</em> (<b>!sid</b>)',
        array('!section' => $title, '!sid' => $sid),
        WATCHDOG_WARNING
      );
    }
    else {
      $term = entity_metadata_wrapper('taxonomy_term', $mappings[$sid]);
      $old = $term->name->value();
      if ($old != $title) {
        $term->name->set($title);
        if (!$test) {
          $term->save();
        }
        watchdog(
          'osha_authentication',
          'Updated new section name from <em>!old</em> to <em>!new</em> (<b>!sid</b>)',
          array('!old' => $old, '!new' => $title, '!sid' => $sid)
        );
      }
    }
  }
}

/**
 * Fetch LDAP accounts and membership and synchronize with Drupal accounts.
 * @param stdClass $ldap_server
 *   Server to query
 */
function osha_authentication_ldap_sync($ldap_server) {
  // Synchronize LDAP sections with Drupal sections
  osha_authentication_sync_ldap_sections($ldap_server);

  // Handle LDAP accounts synchronization
  $accounts = osha_authentication_ldap_get_site_users($ldap_server);

  // Block disabled accounts
  osha_authentication_block_disabled_ldap_accounts($ldap_server, $accounts);

  foreach($accounts as $username => $ldap_account) {
    if (!$account = user_load_by_name($username)) {
      // Set a random password
      $ldap_account->password = user_password(32);
      $ldap_account->status = 1;
      if ($account = user_save($ldap_account)) {
        watchdog('osha_authentication', 'Creating Drupal account <em>!uid</em> from LDAP dn: !dn', array(
          '!dn' => $ldap_account->dn,
          '!uid' => $username
        ), WATCHDOG_WARNING);
      }
      else {
        watchdog('osha_authentication', 'Failed to save new Drupal account <em>!uid</em> from LDAP dn: !dn', array(
          '!dn' => $ldap_account->dn,
          '!uid' => $username
        ), WATCHDOG_ERROR);
      }
    }
    if ($account && $account->status == 1) {
      $edit = array();
      // Simulate login to update user data
      user_module_invoke('login', $edit, $account);
    }
  }
}
