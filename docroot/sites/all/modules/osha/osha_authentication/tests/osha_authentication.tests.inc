<?php

/**
 * Class OSHALDAPTests tests LDAP use cases.
 *
 * Prerequisites:
 *
 * 1. Have a read test user: uid=TEST_READ,ou=Contractors,ou=people,dc=osha,dc=europa,dc=eu
 */
class OSHALDAPTests {

  private static $USER_DN = 'uid=%s,ou=Contractors,ou=people,dc=osha,dc=europa,dc=eu';
  /** @var LDAPServer $ldap_server */
  private $ldap_server = NULL;

  function all_tests($testName = NULL, $debug = FALSE) {
    $ldap_servers = ldap_servers_get_servers('osha-write');
    /** @var LDAPServer $ldap_server */
    $this->ldap_server = $ldap_servers['osha-write'];
    foreach (get_class_methods('OSHALDAPTests') as $method) {
      if ((!$testName && strpos($method, 'test_') !== FALSE) || ($testName && $method == $testName)) {
        $username = 'TEST';
        $this->logout();
        try {
          // Perform cleanup before starting the test
          if (!$debug) {
            $this->deleteLDAPUser($username);
            $this->deleteDrupalUser($username);
          }
          $this->$method($username);
          drush_log($method, 'ok');
          $this->logout();
        }
        catch(Exception $e) {
          drush_set_error('ldap', $method . ' failed (' . $e->getMessage() . ')');
        }
      }
    }
  }

  function ldapCreateUser($uid, $groups = array(), $language_groups = array()) {
    $ldap_server = $this->ldap_server;
    $result = $ldap_server->search('ou=people,dc=osha,dc=europa,dc=eu', 'uid=' . $uid);
    $udn = sprintf(self::$USER_DN, $uid);
    if (!$result['count']) {
      $entry = array();
      $entry['objectClass'][0] = 'top';
      $entry['objectClass'][1] = 'posixaccount';
      $entry['objectClass'][2] = 'inetOrgPerson';
      $entry['cn'] = $uid;
      $entry['mail'] = user_password() . '@eaudeweb.ro';
      $entry['userpassword'] = 'test';
      $entry['sn'] = $uid;
      $entry['uid'] = $uid;
      $entry['gidNumber'] = 9991;
      $entry['uidNumber'] = 9992;
      $entry['homeDirectory'] = 'TEST';
      drush_log('@todo: Disabled createLdapEntry($entry);', 'error');
      // $result = $ldap_server->createLdapEntry($entry, $udn);
      if (!$result) {
        drush_set_error(ldap_errno($ldap_server->connection));
        throw new Exception('Cannot create LDAP user:' . $uid);
      }
    }
    $this->ldapSetUserGroups($uid, $groups);
  }

  function ldapDeleteUser($uid) {
    $this->ldapSetUserGroups($uid, array());
    $user = $this->getLDAPUser($uid);
    if (!ldap_delete($this->ldap_server->connection, $user['dn'])) {
      throw new Exception('Failed to remove user from LDAP:' . $uid);
    }
  }

  function getLDAPUser($uid) {
    $ret = FALSE;
    $result = $this->ldap_server->search('ou=people,dc=osha,dc=europa,dc=eu', 'uid=' . $uid);
    if ($result['count']) {
      $ret = $result[0];
    }
    return $ret;
  }

  function ldapSetUserGroups($uid, array $new_groups) {
    $ldap_server = $this->ldap_server;
    // Detach from all groups
    $groups = $ldap_server->search('ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu', '(&(objectClass=posixGroup)(memberuid=' . $uid . '))');
    if ($groups['count'] > 0) {
      unset($groups['count']);
      foreach ($groups as $group) {
        $dn= $group['dn'];
        $members = $group['memberuid'];
        unset($members['count']);
        $members = array_filter($members, function ($v) use ($uid) {
          return $v != $uid;
        });
        // Reindex array
        $members = sort($members);
        if (!ldap_modify($ldap_server->connection, $dn, array('memberuid' => $members))) {
          throw new Exception('Failed to remove user from LDAP group, user:' . $uid . ', group:' . $group['cn'][0]);
        }
      }
    }
    if (!empty($new_groups)) {
      $q = '';
      foreach($new_groups as $cn) {
        $q .= sprintf('(cn=%s)', $cn);
      }
      $q = '(&(objectClass=posixGroup)(|' . $q . '))';
      $groups = $ldap_server->search('ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu', $q);
      if ($groups['count'] > 0) {
        unset($groups['count']);
        foreach ($groups as $group) {
          if (in_array($group['cn'][0], $new_groups)) {
            $members = $group['memberuid'];
            unset($members['count']);
            if (!$members) {
              $members = array($uid);
            }
            else {
              $members[] = $uid;
            }
            if (!ldap_modify($ldap_server->connection, $group['dn'], array('memberuid' => $members))) {
              throw new Exception('Failed to remove user from LDAP group, user:' . $uid, ', group:' . $group['cn']);
            }
          }
        }
      }
    }
  }


  function login($username, $password = 'test') {
    global $user;
    $form_state = array(
      'values' => array(
        'name' => $username,
        'pass' => $password,
      )
    );
    drupal_form_submit('user_login', $form_state);
    if ($user->uid < 2) {
      throw new Exception('Failed to login user: ' . $username);
    }
  }

  function deleteDrupalUser($username) {
    $user = user_load_by_name($username);
    if (!empty($user->uid)) {
      user_delete($user->uid);
    }
  }

  function deleteLDAPUser($uid) {
    $this->ldapSetUserGroups($uid, array());
    $users = $this->ldap_server->search('ou=Contractors,ou=people,dc=osha,dc=europa,dc=eu', 'uid=' . $uid);
    if ($users['count'] > 0) {
      $dn = sprintf(self::$USER_DN, $uid);
      if (!$this->ldap_server->delete($dn)) {
        throw new Exception('Failed to delete user from LDAP:' . $uid);
      }
    }
  }

  function logout() {
    global $user;
    $tmp = NULL;
    user_module_invoke('logout', $tmp, $user);
    $user = drupal_anonymous_user();
  }


  function test_ldapCreateUser($username = 'TEST') {
    $user_groups = array('CAREER_EDT', 'CONTUS_EDT');
    $this->ldapCreateUser($username, $user_groups);
    $user = $this->ldap_server->search('ou=Contractors,ou=people,dc=osha,dc=europa,dc=eu', 'uid=' . $username);
    if ($user['count'] == 0) {
      throw new Exception('User not created');
    }

    $groups = $this->ldap_server->search('ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu', 'memberuid=' . $username);
    if ($groups['count'] != 2
        && !in_array($groups[0]['cn'], $user_groups)
        && !in_array($groups[1]['cn'], $user_groups)) {
      throw new Exception('User groups are not set correctly: ' . print_r($groups, TRUE));
    }

    $user_groups = array('ALBANIAN_CV');
    $this->ldapSetUserGroups($username, $user_groups);
    $groups = $this->ldap_server->search('ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu', 'memberuid=' . $username);
    if ($groups['count'] != 1 && !in_array($groups[0]['cn'], $user_groups)) {
      throw new Exception('User groups are not set correctly: ' . print_r($groups, TRUE));
    }

    $user_groups = array();
    $this->ldapSetUserGroups($username, $user_groups);
    $groups = $this->ldap_server->search('ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu', 'memberuid=' . $username);
    if ($groups['count'] != 0) {
      throw new Exception('User groups are not set correctly: ' . print_r($groups, TRUE));
    }
  }

  function test_LDAP_US_US_01($username = 'TEST') {
    $this->ldapCreateUser($username);
    $this->login($username);
  }

  function test_LDAP_US_US_02($username = 'TEST') {
    $this->ldapCreateUser($username);
    // Login with the user so the account can be provisioned inside Drupal
    $this->login($username);
    $this->logout();
    $this->deleteLDAPUser($username);
    // Try to authenticated when the user no longer exists in LDAP
    global $user;
    try {
      $this->login($username);
    }
    catch(Exception $e) {
      // Expected.
    }
    if ($user->uid != 0) {
      throw new ErrorException('User was still able to login');
    }
  }

  function test_LDAP_APPRV_US_01($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('APPROVER'));
    $this->login($username);
    // User has gained Approver role in Drupal
    if (!in_array('Approver', $user->roles)) {
      throw new Exception('User is missing Approver role');
    }
  }

  function test_LDAP_APPRV_US_02($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('APPROVER'));
    $this->login($username);

    // User has gained Approver role in Drupal
    if (!in_array('Approver', $user->roles)) {
      throw new Exception('User is missing Approver role');
    }
    $count = db_select('entity_collection_storage', NULL)
      ->condition('name', 'approvers')->condition('eid', $user->uid)->countQuery()
      ->execute()->fetchField();
    if ($count != 1 ) {
      throw new Exception('User is NOT in the "approvers" entity collection');
    }

    $this->logout();
    $this->ldapSetUserGroups($username, array());

    // Reset the entity collection static cache and entity cache
    drupal_static_reset('entity_collection_load');
    entity_get_controller('entity_collection')->resetCache();

    // User revoked Approver is removed from the approvers entity_collection
    $this->login($username);
    if (in_array('Approver', $user->roles)) {
      throw new Exception('User has Approver role after being revoked from LDAP');
    }

    $count = db_select('entity_collection_storage', NULL)
      ->condition('name', 'approvers')->condition('eid', $user->uid)->countQuery()
      ->execute()->fetchField();
    if ($count != 0) {
      throw new Exception('User was left in the list of approvers');
    }
    $this->logout();
  }

  function test_LDAP_EDT_US_01($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('CAREER_EDT', 'CONTUS_EDT'));
    $this->login($username);
    // User has gained Editor role in Drupal
    if (count($user->roles) != 2 || !in_array('Editor', $user->roles) || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }
  }

  function test_LDAP_EDT_US_02($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('CAREER_EDT', 'CONTUS_EDT'));
    $this->login($username);
    // User has gained Editor role in Drupal
    if (count($user->roles) != 2 || !in_array('Editor', $user->roles) || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }
    // Check sections assignment
    module_load_include('admin.inc', 'workbench_access');
    workbench_access_user_load_data($user);
    $sections = $user->workbench_access;
    foreach($sections as $tid => &$conf) {
      $conf = taxonomy_term_load($tid);
      $conf = $conf->name;
    }
    if (count($sections) != 2 || !in_array('Careers', $sections) || !in_array('Contact us', $sections)) {
      throw new Exception('User assigned to wrong sections:' . print_r(array_values($sections), TRUE));
    }
    $this->logout();

    $this->ldapSetUserGroups($username, array('STRNET_EDT'));
    $this->login($username);
    if (count($user->roles) != 2 || !in_array('Editor', $user->roles) || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }

    // Check new sections assignment
    workbench_access_user_load_data($user);
    $sections = $user->workbench_access;
    foreach($sections as $tid => &$conf) {
      $conf = taxonomy_term_load($tid);
      $conf = $conf->name;
    }
    if (count($sections) != 1 || !in_array('Strategic Networking', $sections)) {
      throw new Exception('User assigned to wrong sections:' . print_r(array_values($sections), TRUE));
    }
  }

  function test_LDAP_EDT_US_04($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('CAREER_EDT', 'CONTUS_EDT'));
    $this->login($username);
    // User has gained Editor role in Drupal
    if (count($user->roles) != 2 || !in_array('Editor', $user->roles) || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }

    $this->logout();
    $this->deleteLDAPUser($username);
    $this->ldapCreateUser($username);
    $this->login($username);
    // User has gained Editor role in Drupal
    if (count($user->roles) != 1 || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }
  }

  function test_LDAP_RVMN_US_02($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('OSHA_RVMN', 'SEMIN_RVMN'));
    $this->login($username);

    // User has gained Review Manager role in Drupal
    if (count($user->roles) != 2 || !in_array('Review Manager', $user->roles) || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }
    // Check Review manager section assignment
    $sections = osha_workflow_access_get_rm_sections($user->uid);
    if (count($sections) != 2 || !in_array('section', $sections)) {
      throw new Exception('User assigned to wrong sections:' . print_r(array_values($sections), TRUE));
    }
    $this->logout();

    // User is removed from RVMN LDAP group no longer has Review manager role
    global $user;
    $this->ldapCreateUser($username);

    $this->login($username);
    if (count($user->roles) != 1 || in_array('Review Manager', $user->roles)) {
      throw new Exception('User is still Review Manager:' . print_r(array_values($user->roles), TRUE));
    }
  }

  function test_LDAP_CV_US_02($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('ALBANIAN_CV', 'ROMANIAN_CV'));
    $this->login($username);
    // User has gained Content Validator role in Drupal
    if (count($user->roles) != 2 || !in_array('Content Validator', $user->roles) || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }
    $albanians = osha_tmgmt_get_content_validators_by_skill('sq');
    if ($user->uid != current($albanians)->uid) {
      throw new Exception('Translation skills are wrong:' . $user->id);
    }
    $romanians = osha_tmgmt_get_content_validators_by_skill('ro');
    // User has gained Content Validator role in Drupal
    if ($user->uid != current($romanians)->uid) {
      throw new Exception('Translation skills are wrong:' . $user->id);
    }
  }

  function test_LDAP_CV_US_04($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('ALBANIAN_CV', 'ROMANIAN_CV'));
    $this->login($username);
    // User has gained Content Validator role in Drupal
    if (count($user->roles) != 2 || !in_array('Content Validator', $user->roles) || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }
    // User has Albanian and Romanian skill in Drupal
    $albanians = osha_tmgmt_get_content_validators_by_skill('sq');
    if ($user->uid != current($albanians)->uid) {
      throw new Exception('Translation skills are wrong:' . $user->id);
    }
    $romanians = osha_tmgmt_get_content_validators_by_skill('ro');
    if ($user->uid != current($romanians)->uid) {
      throw new Exception('Translation skills are wrong:' . $user->id);
    }
    $this->logout();

    $lang_dn = 'cn=ALBANIAN_CV,ou=Languages,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu';
    ldap_modify($this->ldap_server->connection, $lang_dn, array('memberuid' => array()));
    $this->login($username);
    // User has no longer Albanian language skill
    $albanians = osha_tmgmt_get_content_validators_by_skill('sq');
    if ($user->uid == current($albanians)->uid) {
      throw new Exception('Translation skill was not removed:' . $user->id);
    }
  }


  function test_LDAP_TRLMN_US_01($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('TRLMN'));
    $this->login($username);
    // User has gained Translation Manager role in Drupal
    if (count($user->roles) != 2 || !in_array(OSHA_WORKFLOW_ROLE_TRANSLATION_MANAGER, $user->roles) || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }
  }

  function test_LDAP_TRLMN_US_02($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('TRLMN'));
    $this->login($username);
    // User has gained Translation Manager role in Drupal
    if (count($user->roles) != 2 || !in_array(OSHA_WORKFLOW_ROLE_TRANSLATION_MANAGER, $user->roles) || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }

    $this->logout();
    $this->deleteLDAPUser($username);
    $this->ldapCreateUser($username);
    $this->login($username);
    // User has gained Editor role in Drupal
    if (count($user->roles) != 1 || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }
  }

  function test_LDAP_TRLIAS_US_01($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('TRLIAS'));
    $this->login($username);
    // User has gained Translation Manager role in Drupal
    if (count($user->roles) != 2 || !in_array(OSHA_WORKFLOW_ROLE_TRANSLATION_LIAISON, $user->roles) || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }
  }

  function test_LDAP_TRLIAS_US_02($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('TRLIAS'));
    $this->login($username);
    // User has gained Translation Manager role in Drupal
    if (count($user->roles) != 2 || !in_array(OSHA_WORKFLOW_ROLE_TRANSLATION_LIAISON, $user->roles) || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }

    $this->logout();
    $this->deleteLDAPUser($username);
    $this->ldapCreateUser($username);
    $this->login($username);
    // User has gained Editor role in Drupal
    if (count($user->roles) != 1 || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }
  }

  function LDAP_LAYVAL_US_01($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('LAYVAL'));
    $this->login($username);
    // User has gained Translation Manager role in Drupal
    if (count($user->roles) != 2 || !in_array(OSHA_WORKFLOW_ROLE_LAYOUT_VALIDATOR, $user->roles) || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }
  }

  function LDAP_LAYVAL_US_02($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('LAYVAL'));
    $this->login($username);
    // User has gained Translation Manager role in Drupal
    if (count($user->roles) != 2 || !in_array(OSHA_WORKFLOW_ROLE_LAYOUT_VALIDATOR, $user->roles) || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }

    $this->logout();
    $this->deleteLDAPUser($username);
    $this->ldapCreateUser($username);
    $this->login($username);
    // User has gained Editor role in Drupal
    if (count($user->roles) != 1 || !in_array('authenticated user', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }
  }

  /**
   * Test blocking of users which are no longer member of any MainSite group
   */
  function test_osha_authentication_block_disabled_ldap_accounts($username = 'TEST') {
    global $user;
    $this->ldapCreateUser($username, array('LAYVAL'));
    osha_authentication_block_disabled_ldap_accounts($this->ldap_server);
    $this->login($username);

    if ($user->status != 1) {
      throw new Exception('User is disabled:' . print_r($user, TRUE));
    }
    if (count($user->roles) != 2 || !in_array('Layout Validator', $user->roles)) {
      throw new Exception('User has wrong roles:' . print_r(array_values($user->roles), TRUE));
    }

    $uid = $user->uid;
    $this->logout();
    $this->ldapDeleteUser($username);

    osha_authentication_block_disabled_ldap_accounts($this->ldap_server);

    // User is still in Drupal
    $user = user_load($uid);
    if ($user->status != 0) {
      throw new Exception('Account is not blocked:' . print_r($user, TRUE));
    }
  }

  function test_password_change($username = 'TEST') {

    throw new Exception('Not implemented');

    global $user;
    $this->createLDAPUser($username, array('OSHA_RVMN', 'SEMIN_RVMN'));
    $this->login($username);

    module_load_include('pages.inc', 'user');
    // Change the password from the profile edit form
    $form_state = array();
    $form = drupal_get_form('user_profile_form', $user);
    var_dump($form);

    return;
    drupal_form_submit('user_profile_form', $form_state, $user, 'account');
    $this->logout();

    return;
    $this->login($username);
    $ldapu = $this->getLDAPUser($username);

    var_dump($user->mail);
    var_dump($ldapu['mail']);

  }

  function test_osha_authentication_sync_ldap_sections() {
    $ldap_section['dn'] = 'cn=TEST2_EDT,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu';
    $ldap_section['cn'] = 'TEST2_EDT';
    $ldap_section['objectClass'] = array('posixGroup', 'top');
    $ldap_section['gidNumber'] = array(9999);
    $ldap_section['description'] = array('Test sync ldap sections');
    $result = $this->ldap_server->search('ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu', 'cn=TEST2_EDT');
    $section = osha_workflow_get_section_term_by_ldap_id('TEST');
    if (!empty($section)) {
      taxonomy_term_delete($section->tid);
    }
    if ($result['count']) {
      $this->ldap_server->delete($ldap_section['dn']);
    }
    drush_log('@todo: Disabled createLdapEntry($ldap_section);', 'error');
    //$this->ldap_server->createLdapEntry($ldap_section);
    osha_authentication_sync_ldap_sections($this->ldap_server);
    $section = osha_workflow_get_section_term_by_ldap_id('TEST2');
    if (empty($section)) {
      throw new Exception('Section was not imported.');
    }
  }

  function test_serbo_croatian_cv_group_name() {
    $group = osha_authentication_get_role_and_section_from_dn('cn=SERBO-CROATIAN_CV,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu');
    if ($group[0] != 'Content Validator') {
      throw new Exception('Wrong group');
    }
    if ($group[2] != 'SERBO-CROATIAN') {
      throw new Exception('Wrong language');
    }
  }
}
