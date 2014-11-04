<?php

/**
 * Implements COMMANDFILE_drush_command().
 */
function osha_workflow_drush_command() {
  $items = array();
  $items['osha-create-users'] = array(
    'description' => 'Generate users for each workflow role',
    'aliases' => array('oshcu'),
    'examples' => array(),
    'arguments' => array(),
    'options' => array(),
    'sections' => array(),
  );
  return $items;
}

/**
 * Implements COMMANDFILE_drush_help().
 */
function osha_workflow_drush_help($section) {
  switch ($section) {
    case 'drush:osha-create-users':
      return 'This command will create a group of test users assigned to the workflow roles';
  }
  return NULL;
}

/**
 * Drush command to create OSHA workflow users.
 *
 * @throws Exception
 */
function drush_osha_workflow_osha_create_users() {
  $users = array(
    'editor1' => 'Editor',
    'editor2' => 'Editor',
    'editor3' => 'Editor',
    'editor4' => 'Editor',
    'review_manager1' => 'Review Manager',
    'review_manager2' => 'Review Manager',
    'review_manager3' => 'Review Manager',
    'review_manager4' => 'Review Manager',
    'project_manager1' => 'Project Manager',
    'project_manager2' => 'Project Manager',
    'project_manager3' => 'Project Manager',
    'project_manager4' => 'Project Manager',
    'approver1' => 'Approver',
    'approver2' => 'Approver',
    'approver3' => 'Approver',
    'approver4' => 'Approver',
    'administrator' => 'administrator',

    'tmanager1' => 'Translation Manager',
    'tmanager2' => 'Translation Manager',

    'tliaison1' => 'Translation Liaison',
    'tliaison2' => 'Translation Liaison',

    'lvalidator1' => 'Layout Validator',
    'lvalidator2' => 'Layout Validator',

    'cvalidator1' => 'Content Validator',
    'cvalidator2' => 'Content Validator',
    'cvalidator3' => 'Content Validator',
    'cvalidator4' => 'Content Validator',
    'cvalidator5' => 'Content Validator',
  );

  foreach ($users as $username => $role_name) {
    if (user_load_by_name($username)) {
      drush_log("$username already exists ...", 'warning');
      continue;
    }
    if ($role = user_role_load_by_name($role_name)) {
      $fields = array(
        'name' => $username,
        'pass' => $username,
        'status' => 1,
        'init' => "$username@localhost",
        'mail' => "$username@example.com",
        'roles' => array(
          DRUPAL_AUTHENTICATED_RID => 'authenticated user',
          $role->rid => $role_name,
        ),
      );
      drush_log('Users created ...');
      user_save(NULL, $fields);
    }
    else {
      drush_log("Cannot find role: $role_name", 'error');
    }
  }
}
