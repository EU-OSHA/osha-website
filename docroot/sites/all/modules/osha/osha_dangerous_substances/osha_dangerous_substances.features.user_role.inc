<?php
/**
 * @file
 * osha_dangerous_substances.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function osha_dangerous_substances_user_default_roles() {
  $roles = array();

  // Exported role: Dangerous substances.
  $roles['Dangerous substances'] = array(
    'name' => 'Dangerous substances',
    'weight' => 13,
  );

  return $roles;
}
