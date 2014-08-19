<?php
// $Id: drush_extras.drush.inc,v 1.4 2010/12/02 23:17:44 greg1anderson Exp $

/**
 * @file
 * drush_extras - A place to put more drush commands
 *
 * Pushkey
 *
 * Drush commands to create a public/private key pair
 * and push the public key to a remote account.
 *
 * Copyright (C) 2010  Greg Anderson <http://drupal.org/user/438598>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

function drush_extras_drush_help($section) {
  switch ($section) {
    case 'meta:drush_extras:title':
      return dt('Drush extras');
    case 'meta:drush_extras:summary':
      return dt('A collection of additional drush commands.');
  }
}

function drush_extras_drush_command() {
  $items = array();

  $items['copy-id'] = array(
    'description' => 'Generate a public/private key pair and push the public key to a remote server.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'options' => array(
      'keyname' => 'Specify which key to use or the name of the key to generate. Defaults to id_rsa.',
      'ssh-options' => 'Any addition options to pass to ssh. If an alias is used as target this option will overwrite any ssh-options defined in the alias.',
    ),
    'arguments' => array(
      'target' => 'Alias for a remote site (@remotesite) or the user and machine to push to ("user@machine.com").',
    ),
    'examples' => array(
      'drush pushkey user@myserver.com' => 'Push your public key to a remote server.',
      'drush pushkey @remotesite' => 'Push your public key to the remote server defined in @remotesite.',
      'drush pushkey user@myserver.com --ssh-options=\"-p 222\"' => 'Push your public key to a remote server where ssh is listening on port 222.',
      'drush pushkey @remotesite --keyname=drupal_rsa' => 'Push your public key named drupal_rsa.pub to the remote server defined in @remotesite.',
    ),
    'aliases' => array('pushkey'),
  );
  $items['sql-hash'] = array(
    'description' => "Output hash values for each table in the database.  Run before and after an operation on a Drupal site to track table usage.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
    'options' => array(
      'tables-key' => 'A key in the $tables array. Optional.',
      'tables-list' => 'A comma-separated list of tables to hash. Optional.',
      'skip-tables-key' => 'A key in the $skip_tables array. @see example.drushrc.php. Optional.',
      'skip-tables-list' => 'A comma-separated list of tables to skip.  Optional.',
      'structure-tables-key' => 'A key in the $structure_tables array. @see example.drushrc.php. Optional.',
    ),
    'aliases' => array('sqlh'),
  );
  $items['sql-compare'] = array(
    'description' => "Show each table that differs in content in any way between two sites.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'site1' => 'First site',
      'site2' => 'Site to compare with',
    ),
    'options' => array(
      'tables-key' => 'A key in the $tables array. Optional.',
      'tables-list' => 'A comma-separated list of tables to hash. Optional.',
      'skip-tables-key' => 'A key in the $skip_tables array. @see example.drushrc.php. Optional.',
      'skip-tables-list' => 'A comma-separated list of tables to skip.  Optional.',
      'structure-tables-key' => 'A key in the $structure_tables array. @see example.drushrc.php. Optional.',
    ),
    'aliases' => array('sqlcmp'),
  );

  return $items;
}

/**
 * Print out an md5 hash for every table in the database.
 */
function drush_drush_extras_sql_hash() {
  // Find out which tables to include or skip.
  $db_spec = _drush_sql_get_db_spec();
  $table_selection = drush_sql_get_expanded_table_selection($db_spec);

  $skip_tables = array_merge($table_selection['skip'], $table_selection['structure']);
  $hash_tables = $table_selection['tables'];
  drush_unset_option('tables-key');
  // Allow args to replace --tables option
  $args = func_get_args();
  if (!empty($args)) {
    $hash_tables = $args;
  }
  $skip_regex = drush_get_option('skip-regex', FALSE);
  $db_spec = _drush_sql_get_db_spec();
  $prefix = isset($db_spec['db_prefix']) ? $db_spec['db_prefix'] : $db_spec['prefix'];
  if (!empty($prefix)) {
    foreach ($hash_tables as $key => $value) {
      $hash_tables[$key] = $prefix . $value;
    }
    foreach ($skip_tables as $key => $value) {
      $skip_tables[$key] = $prefix . $value;
    }
  }

  $hashes = _drush_extras_sql_hash($hash_tables, $skip_tables, $skip_regex);
  drush_print_table(drush_key_value_to_array_table($hashes));

  return $hashes;
}

function _drush_extras_sql_hash($hash_tables = array(), $skip_tables = array(), $skip_regex = '') {
  // We will re-use the same tmp file to store the
  // sql tables in, and also to store every sql dump file.
  $tmp_file = drush_tempnam('sql-hash.sql.');
  drush_set_option('result-file', $tmp_file);
  $tables = _drush_extras_sql_query('show tables;');

  $hashes = array();
  if ($tables !== FALSE) {
    // Drop the first line, as it is always the column header ('tables').
    array_shift($tables);
    foreach($tables as $table) {
      $table = trim($table);
      // Skip this table if it is not selected, or if it is unselected
      if ((empty($hash_tables) || in_array($table, $hash_tables)) && (!in_array($table, $skip_tables) && (($skip_regex === FALSE) || preg_match("/$skip_regex/i", $table) == FALSE))) {
        if (is_file($tmp_file)) {
          unlink($tmp_file);
        }
        $values = drush_invoke_process('@self', 'sql-dump', array(),
          array('result-file' => $tmp_file, 'tables-list' => $table), array('integrate' => FALSE));
        if (is_file($tmp_file)) {
          $data = file_get_contents($tmp_file);
          // Comments (starting with '--') might contain
          // timestamps, so strip them.
          $data = preg_replace('/^--.*/m', '', $data);
          $hashes[$table] = md5($data);
        }
      }
    }
  }
  return $hashes;
}

/**
 * Compare the SQL tables from two sites and print out the ones that are different
 */
function drush_drush_extras_sql_compare($site1, $site2) {
  $hash_options = drush_redispatch_get_options();
  $result1 = drush_invoke_process($site1, 'sql-hash', array(), $hash_options, array('integrate' => FALSE));
  $result2 = drush_invoke_process($site2, 'sql-hash', array(), $hash_options, array('integrate' => FALSE));

  $hashes1 = $result1['object'];
  $hashes2 = $result2['object'];

  $different = array();
  $site1_only = array();
  $site2_only = array();

  foreach($hashes1 as $table => $hash) {
    if (array_key_exists($table, $hashes2)) {
      if ($hash != $hashes2[$table]) {
        $different[] = $table;
      }
    }
    else {
      $site1_only[] = $table;
    }
  }
  foreach($hashes2 as $table => $hash) {
    if (!array_key_exists($table, $hashes1)) {
      $site2_only[] = $table;
    }
  }

  if (!empty($different)) {
    drush_print(dt('Tables that are different: @different', array('@different' => implode(',', $different))));
  }
  if (!empty($site1_only)) {
    drush_print(dt('Tables in @site that are not in @butnot: @only', array('@site' => $site1, '@butnot' => $site2, '@only' => implode(',', $site1_only))));
  }
  if (!empty($site2_only)) {
    drush_print(dt('Tables in @site that are not in @butnot: @only', array('@site' => $site2, '@butnot' => $site1, '@only' => implode(',', $site2_only))));
  }

  if (empty($different) && empty($site1_only) && empty($site2_only)) {
    drush_print(dt('All tables are the same.'));
  }
}

function drush_extras_sql_dump_execute() {
  list($exec, $file) = drush_sql_dump();
  // Avoid the php memory of the $output array in drush_shell_exec().
  $return = drush_op_system($exec);
  return $return;
}


function _drush_extras_sql_query($query, $db_spec = NULL) {
  $scheme = _drush_sql_get_scheme($db_spec);

  // Inject table prefixes as needed.
  if (drush_has_boostrapped(DRUSH_BOOTSTRAP_DRUPAL_DATABASE)) {
    if (drush_drupal_major_version() >= 7) {
      $query = Database::getConnection()->prefixTables($query);
    }
    else {
      $query = db_prefix_tables($query);
    }
  }

  // Convert mysql 'show tables;' query into something pgsql understands
  if (($scheme == 'pgsql') && ($query == 'show tables;')) {
    $query = drush_sql_show_tables_pgsql();
  }

  // Save $query to a tmp file. We will redirect it in.
  if ($filename = drush_save_data_to_temp_file($query)) {
    $exec = drush_sql_build_exec($db_spec, $filename);
    // In --simulate mode, drush_op will show the call to mysql or psql,
    // but the sql query itself is stored in a temp file and not displayed.
    // We will therefore show the query explicitly in the interest of full disclosure.
    if (drush_get_context('DRUSH_SIMULATE')) {
      drush_print('sql-query: ' . $query);
    }
    $result = drush_shell_exec($exec);
    if ($result === TRUE) {
      return drush_shell_exec_output();
    }
  }
  return FALSE;
}

function drush_drush_extras_copy_id($target = NULL) {
  // Make sure that we were called with a parameter
  if ($target == NULL) {
    return drush_set_error('DRUSH_NO_TARGET', dt('No target was specified.'));
  }

  if (is_null(drush_server_home())) {
    return drush_set_error('DRUSH_NO_HOME', dt('Cannot determine appropriate home directory.'));
  }

  $local_machine_name = exec('uname -n');

  //
  // If there is a proxy, then we will first push
  // the key to the proxy, and then we will tell
  // the proxy to push the key to the final target.
  // (This is not supported yet.)
  //
  $proxy = drush_get_option('proxy');
  if (isset($proxy)) {
    $final_target = $target;
    $target = $proxy;
  }

  $target_record = drush_extras_parse_target($target);
  if (!$target_record) {
    return FALSE;
  }
  $remote_user = $target_record['remote-user'];
  $remote_machine = $target_record['remote-host'];
  $ssh_options = drush_get_option('ssh-options', ((array_key_exists('ssh-options', $target_record)) ? $target_record['ssh-options'] : ''));

  // If the user was not specified with the target,
  // then assume that the remote user == local user
  if (!isset($remote_user)) {
    $remote_user = exec('whoami');
  }

  // Figure out where the remote home directory is
  $remote_machine_with_user = "$remote_user@$remote_machine";

  // Make sure that the .ssh directory exists
  $ssh_dir = drush_server_home() . '/.ssh';
  if (!is_dir($ssh_dir)) {
    mkdir($ssh_dir);
  }

  // If we do not have an id_rsa file, then make one
  $private_key_file = $ssh_dir . '/' . drush_get_option('keyname', 'id_rsa');
  $public_key_file = $ssh_dir . '/' . drush_get_option('keyname',  'id_rsa') . '.pub';

  if (!is_file($private_key_file)) {
    drush_op('system', 'ssh-keygen -t rsa -f ' . $private_key_file);
  }

  // Read in the public key data
  if (is_file($public_key_file)) {
    $public_key_data = trim(file_get_contents($public_key_file));
  }
  elseif (drush_get_context('DRUSH_SIMULATE')) {
    $public_key_data = "SIMULATED_PUBLIC_KEY_DATA";
  }

  // Object if we still do not have a public key file
  if (!isset($public_key_data)) {
    return drush_set_error('DRUSH_NO_KEY', dt('Could not find or create a public / private key pair.'));
  }

  // Read in the public key data
  $remote_public_key_file = $local_machine_name . '_' . drush_get_option('keyname', 'id_rsa') . '.pub';

  // Build the command and then run it
  $exec = "ssh-copy-id -i $public_key_file \"$remote_machine_with_user $ssh_options\"";
  $result = drush_op_system($exec);
}

function drush_extras_parse_target($target) {
  $remote_machine = $target;
  $at_pos = strpos($target, '@');
  if ($at_pos !== FALSE) {
    // If the '@' is at the beginning, then the target
    // is an alias.
    if ($at_pos == 0) {
      $alias_record = drush_sitealias_get_record($target);
      if (empty($alias_record)) {
        return drush_set_error('DRUSH_NO_ALIAS', dt('Could not find the alias !alias.', array('!alias' => $alias)));
      }
      if (empty($alias_record)) {
        return drush_set_error('DRUSH_NO_ALIAS', dt('Could not find the alias !alias.', array('!alias' => $alias)));
      }
      if (array_key_exists('remote-user', $alias_record)) {
        $remote_user = $alias_record['remote-user'];
      }
      if (array_key_exists('remote-host', $alias_record)) {
        $remote_machine = $alias_record['remote-host'];
      }
      else {
        return drush_set_error('DRUSH_NOT_REMOTE', dt('The alias !alias is not remote, and therefore cannot be used as a target to pushkey.', array('!alias' => $alias)));
      }
    }
    // If there is an '@' somewhere else, then the username
    // comes before the '@'
    else {
      $remote_user = substr($target, 0, $at_pos);
      $remote_machine = substr($target, $at_pos + 1);
    }
  }

  return array('remote-user' => $remote_user, 'remote-host' => $remote_machine);
}
