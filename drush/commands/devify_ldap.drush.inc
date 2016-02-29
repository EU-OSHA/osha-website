<?php
/**
 * @file
 * Implements some developer commands.
 */


/**
 * Implements hook_drush_command().
 */
function devify_ldap_drush_command() {
  $items = array();

  $items['devify_ldap'] = array(
    'description' => 'Updates ldap servers from config file.',
    'callback' => '_drush_devify_ldap',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Executes the build commands.
 */
function _drush_devify_ldap() {
  drush_log('Devify Solr Server', 'success');

  $ldap_read = drush_get_option('ldap-read');
  $ldap_write = drush_get_option('ldap-write');

  if (!empty($ldap_read)) {
    $ldap_read = array_merge($ldap_read, array('sid' => 'osha', 'name' => 'osha-ldap'));
    $read_values = _devify_ldap_get_server_values($ldap_read);
    $ldap_write = array_merge($ldap_write, array('sid' => 'osha-write', 'name' => 'osha-write'));
    $write_values = _devify_ldap_get_server_values($ldap_write);

    db_delete('ldap_servers')->execute();
    variable_set('ldap_servers_encryption' , LDAP_SERVERS_ENC_TYPE_CLEARTEXT);
    $result = drupal_write_record('ldap_servers', $read_values);
    if (!empty($result)) {
      drush_log(dt('Ldap read devified!'), 'success');
    }
    else {
      drush_log(dt('Error saving ldap read server!'), 'error');
    }
    $result = drupal_write_record('ldap_servers', $write_values);
    if (!empty($result)) {
      drush_log(dt('Ldap write devified!'), 'success');
    }
    else {
      drush_log(dt('Error saving ldap write server!'), 'error');
    }

    ldap_servers_cache_clear();
  }
  else {
    drush_log('No LDAP config found in config.json - Keeping existing configuration.', 'success');
  }
}

function _devify_ldap_get_server_values($ldap_read) {
  $read = array(
    'disabled' => FALSE, /* Edit this to true to make a default ldap_servers_conf disabled initially */
    'api_version' => 1,
    'status' => TRUE,
    'ldap_type' => 'openldap',
    'address' => 'simshab.eaudeweb.ro',
    'port' => 389,
    'tls' => FALSE,
    'followrefs' => FALSE,
    'bind_method' => 1,
    'binddn' => 'cn=admin,dc=osha,dc=europa,dc=eu',
    'basedn' => array(
      'ou=people,dc=osha,dc=europa,dc=eu',
      'ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu',
    ),
    'user_attr' => 'uid',
    'account_name_attr' => '',
    'mail_attr' => 'mail',
    'mail_template' => '',
    'picture_attr' => '',
    'unique_persistent_attr' => 'dn',
    'unique_persistent_attr_binary' => FALSE,
    'user_dn_expression' => '',
    'ldap_to_drupal_user' => '',
    'testing_drupal_username' => 'CRomanescu',
    'testing_drupal_user_dn' => 'uid=CRomanescu,ou=Contractors,ou=people,dc=osha,dc=europa,dc=eu',
    'grp_unused' => FALSE,
    'grp_object_cat' => 'posixgroup',
    'grp_nested' => FALSE,
    'grp_user_memb_attr_exists' => FALSE,
    'grp_user_memb_attr' => '',
    'grp_memb_attr' => 'memberuid',
    'grp_memb_attr_match_user_attr' => 'uid',
    'grp_derive_from_dn' => FALSE,
    'grp_derive_from_dn_attr' => '',
    'grp_test_grp_dn' => 'cn=admin,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu',
    'grp_test_grp_dn_writeable' => 'cn=admin,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu',
    'search_pagination' => FALSE,
    'search_page_size' => 1000,
    'weight' => 0,
  );
  $new_values = array_merge($read, $ldap_read);
  ldap_servers_module_load_include('php', 'ldap_servers', 'LdapServerAdmin.class');
  $server = new LdapServerAdmin($new_values);
  _devify_ldap_prepare_from_values($server, $new_values);
  $values = new stdClass();
  foreach ($server->field_to_properties_map() as $field_name => $property_name) {
    $field_name_lcase = drupal_strtolower($field_name);
    $values->{$field_name_lcase} = $server->{$property_name};
  }
  $values->bindpw = $new_values['bindpw'];

  $values->tls = (int)$server->tls;
  $values->followrefs = (int)$server->followrefs;

  return $values;
}



function _devify_ldap_prepare_from_values($server, $values) {
  $server->inDatabase = 1;
  $server->sid = trim($values['sid']);
  $server->name = trim($values['name']);
  $server->status = ($values['status']) ? 1 : 0;
  $server->ldap_type = trim($values['ldap_type']);
  $server->address = trim($values['address']);
  $server->port = trim($values['port']);
  $server->tls = trim($values['tls']);
  $server->followrefs = trim($values['followrefs']);
  $server->bind_method = trim($values['bind_method']);
  $server->binddn = trim($values['binddn']);
  if (trim($values['bindpw'])) {
    $server->bindpw_new = trim($values['bindpw']);
  }
  $server->user_dn_expression = trim($values['user_dn_expression']);
  $server->basedn = $values['basedn'];
  $server->user_attr = drupal_strtolower(trim($values['user_attr']));
  $server->picture_attr = drupal_strtolower(trim($values['picture_attr']));
  $server->account_name_attr = drupal_strtolower(trim($values['account_name_attr']));
  $server->mail_attr = drupal_strtolower(trim($values['mail_attr']));
  $server->mail_template = trim($values['mail_template']);
  $server->unique_persistent_attr = drupal_strtolower(trim($values['unique_persistent_attr']));
  $server->unique_persistent_attr_binary = trim($values['unique_persistent_attr_binary']);
  $server->ldapToDrupalUserPhp = $values['ldap_to_drupal_user'];
  $server->testingDrupalUsername = trim($values['testing_drupal_username']);
  $server->testingDrupalUserDn = trim($values['testing_drupal_user_dn']);
  $server->groupFunctionalityUnused = $values['grp_unused'];
  $server->groupObjectClass = drupal_strtolower(trim($values['grp_object_cat']));
  $server->groupNested = trim($values['grp_nested']);

  $server->groupUserMembershipsAttrExists = trim($values['grp_user_memb_attr_exists']);
  $server->groupUserMembershipsAttr =  drupal_strtolower(trim($values['grp_user_memb_attr']));

  $server->groupMembershipsAttr = drupal_strtolower(trim($values['grp_memb_attr']));

  $server->groupMembershipsAttrMatchingUserAttr =  drupal_strtolower(trim($values['grp_memb_attr_match_user_attr']));

  $server->groupDeriveFromDn = trim($values['grp_derive_from_dn']);
  $server->groupDeriveFromDnAttr = drupal_strtolower(trim($values['grp_derive_from_dn_attr']));
  $server->groupTestGroupDn = trim($values['grp_test_grp_dn']);
  $server->groupTestGroupDnWriteable = trim($values['grp_test_grp_dn_writeable']);


  $server->searchPagination = ($values['search_pagination']) ? 1 : 0;
  $server->searchPageSize = trim($values['search_page_size']);
}


