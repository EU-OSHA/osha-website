<?php
/**
 * @file
 * osha.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function osha_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access PDF version'.
  $permissions['access PDF version'] = array(
    'name' => 'access PDF version',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'print_pdf',
  );

  // Exported permission: 'access news feeds'.
  $permissions['access news feeds'] = array(
    'name' => 'access news feeds',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'aggregator',
  );

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'use text format dangerous_substances_minimal'.
  $permissions['use text format dangerous_substances_minimal'] = array(
    'name' => 'use text format dangerous_substances_minimal',
    'roles' => array(
      'Dangerous substances' => 'Dangerous substances',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Approver' => 'Approver',
      'Content Validator' => 'Content Validator',
      'Editor' => 'Editor',
      'Events Coordinator' => 'Events Coordinator',
      'Events Editor' => 'Events Editor',
      'Layout Validator' => 'Layout Validator',
      'Project Manager' => 'Project Manager',
      'Review Manager' => 'Review Manager',
      'Translation Liaison' => 'Translation Liaison',
      'Translation Manager' => 'Translation Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html_minimal'.
  $permissions['use text format full_html_minimal'] = array(
    'name' => 'use text format full_html_minimal',
    'roles' => array(
      'Approver' => 'Approver',
      'Content Validator' => 'Content Validator',
      'Editor' => 'Editor',
      'Events Coordinator' => 'Events Coordinator',
      'Events Editor' => 'Events Editor',
      'Layout Validator' => 'Layout Validator',
      'Project Manager' => 'Project Manager',
      'Review Manager' => 'Review Manager',
      'Translation Liaison' => 'Translation Liaison',
      'Translation Manager' => 'Translation Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
