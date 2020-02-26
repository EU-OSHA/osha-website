<?php
/**
 * @file
 * osha_news.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function osha_news_user_default_roles() {
  $roles = array();

  // Exported role: News Editor.
  $roles['News Editor'] = array(
    'name' => 'News Editor',
    'weight' => 14,
  );

  return $roles;
}
