<?php
/**
 * @file
 * osha_flickr.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function osha_flickr_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create flickr_gallery content'.
  $permissions['create flickr_gallery content'] = array(
    'name' => 'create flickr_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any flickr_gallery content'.
  $permissions['delete any flickr_gallery content'] = array(
    'name' => 'delete any flickr_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own flickr_gallery content'.
  $permissions['delete own flickr_gallery content'] = array(
    'name' => 'delete own flickr_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any flickr_gallery content'.
  $permissions['edit any flickr_gallery content'] = array(
    'name' => 'edit any flickr_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own flickr_gallery content'.
  $permissions['edit own flickr_gallery content'] = array(
    'name' => 'edit own flickr_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
