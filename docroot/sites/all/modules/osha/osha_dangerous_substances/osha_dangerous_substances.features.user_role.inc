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

  // Exported role: OSH Collaborator.
  $roles['OSH Collaborator'] = array(
    'name' => 'OSH Collaborator',
    'weight' => 13,
  );

  return $roles;
}
