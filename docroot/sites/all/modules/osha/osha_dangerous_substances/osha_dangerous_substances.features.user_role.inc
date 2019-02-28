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

  // Exported role: OSH DB editor.
  $roles['OSH DB editor'] = array(
    'name' => 'OSH DB editor',
    'weight' => 13,
  );

  return $roles;
}
