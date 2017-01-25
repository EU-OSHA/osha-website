<?php
/**
 * @file
 * osha_dangerous_substances.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function osha_dangerous_substances_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create dangerous_substances content'.
  $permissions['create dangerous_substances content'] = array(
    'name' => 'create dangerous_substances content',
    'roles' => array(
      'Dangerous substances' => 'Dangerous substances',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own dangerous_substances content'.
  $permissions['delete own dangerous_substances content'] = array(
    'name' => 'delete own dangerous_substances content',
    'roles' => array(
      'Dangerous substances' => 'Dangerous substances',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own dangerous_substances content'.
  $permissions['edit own dangerous_substances content'] = array(
    'name' => 'edit own dangerous_substances content',
    'roles' => array(
      'Dangerous substances' => 'Dangerous substances',
    ),
    'module' => 'node',
  );

  // Exported permission: 'use text format dangerous_substances'.
  $permissions['use text format dangerous_substances'] = array(
    'name' => 'use text format dangerous_substances',
    'roles' => array(
      'Dangerous substances' => 'Dangerous substances',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
