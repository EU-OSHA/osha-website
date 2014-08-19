<?php

/**
 * @file
 * drush_give - Drush commands to give ownership of nodes and comments to specified users.
 *
 * Copyright (C) 2010 by the original authors
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
 */

/**
 * Implementation of hook_drush_command().
 */
function drush_give_drush_command() {
  $items = array();

  $items['give-node'] = array(
    'description' => 'Give ownership of a node and its most recent revision to the specified user.',
    'examples' => array(
      'drush give-node 27 3' => 'Give node 27 and its revisions to user with uid 3',
      'drush give-node 27 bob --revision-only' => 'Give only the revisions of node 27 to user with username "bob"',
      'drush give-node 27 bob --revision-count=3' => 'Give the last three revisions of node 27 to user with username "bob"',
    ),
    'arguments' => array(
      'nid' => 'Specify the nid of the node whose ownership you wish to reassign.',
      'account' => 'Specify the uid or username of the user who should gain ownership.',
    ),
    'options' => array(
      '--revision-only' => 'Node ownership will be left unchanged.',
      '--revision-count' => 'Specify the number of recent revisions to be reassigned. Set to "0" to only reassign node ownership.',
      '--ignore-access' => 'Do not check user permissions before assigning the node.',
    ),
    'aliases' => array('gn'),
  );
  $items['give-comment'] = array(
    'description' => 'Give ownership of a comment to the specified user.',
    'examples' => array(
      'drush give-comment 7 3' => 'Give comment cid 7 to user with uid 3.',
      'drush give-comment 7 bob' => 'Give comment cid 7 to user with username "bob".',
    ),
    'arguments' => array(
      'cid' => 'Specify the cid of the comment whose ownership you wish to reassign.',
      'account' => 'Specify the uid or username of the user who should gain ownership.',
    ),
    'options' => array(
      '--ignore-access' => 'Do not check user permissions before assigning the comment.',
    ),
    'aliases' => array('gc'),
  );
  return $items;
}

/**
 * Implementation of hook_drush_help().
 */
function drush_give_drush_help($section) {
  switch ($section) {
    case 'drush:give-node':
      return dt("Reassign ownership of a node and/or it's revisions to the specified user.");
    case 'drush:give-comment':
      return dt('Reassign ownership of a comment to the specified user.');
  }
}

/**
 * give-node command implementation.
 * Reassign node & node_revision ownership.
 */
function drush_drush_give_give_node($nid, $account) {
  $account = _drush_give_get_user($account);
  if (empty($account)) {
    drush_set_error('DRUSH_BAD_ACCOUNT', dt('Bad account.'));
  }
  if (!is_numeric($nid)) {
    drush_set_error('DRUSH_BAD_ACCOUNT', dt('Bad nid.'));
  }
  $node = node_load($nid);

  $access = node_access('edit', $node, $account);
  // Update node object to new author. Note: Does this generate a revision? That's bad if so.
  if (!drush_get_option('revision-only', NULL)) {
    $node->uid = $account->uid;
    if (!drush_get_option('ignore-access', NULL) || $access) {
      node_save($node);
      drush_log(dt('Node "!title" <!nid> ownership updated to "!name" <!uid>.', array('!title' => $node->title, '!nid' => $node->nid, '!name' => $account->name, '!uid' => $account->uid)), 'success');
    }
    else {
      drush_set_error('DRUSH_ACCESS_DENIED', dt('Access denied [node]: User cannot edit the specified node. Rerun with --ignore-access to override.'));
    }
  }

  // Update node revisions.
  if (!drush_get_option('ignore-access', NULL) || $access) {
    $sql = "UPDATE {node_revisions} SET uid = %d WHERE nid = %d ORDER BY vid DESC";
    $limit = drush_get_option('revision-count', NULL);
    if (is_numeric($limit)) {
      $sql .= " LIMIT %d";
      db_query($sql, $account->uid, $nid, $limit);
    }
    db_query($sql, $account->uid, $nid);
    drush_log(dt('Node revision(s) ownership updated for Node "!title" <!nid>.', array('!title' => $node->title, '!nid' => $node->nid)), 'success');
  }
  else {
    drush_set_error('DRUSH_ACCESS_DENIED', 'Access denied [node revision]: User cannot have edited the specified node with current permissions. Rerun with --ignore-access to override.');
  }
}

/**
 * give-comment command implementation.
 * Reassign comment ownership.
 */
function drush_drush_give_give_comment($cid, $account) {
  $account = _drush_give_get_user($account);
  if (empty($account)) {
    drush_set_error('DRUSH_BAD_ACCOUNT', dt('Bad account.'));
  }
  if (!is_numeric($cid)) {
    drush_set_error('DRUSH_BAD_COMMENT_ID', dt('Bad cid.'));
  }
  if (!drush_get_option('ignore-access') || user_access('post comments', $account)) {
    $sql = "UPDATE comments SET uid = %d, name = '%s' WHERE cid = %d";
    db_query($sql, $account->uid, $account->name, $cid);
    drush_log(dt('Comment <!cid> ownership updated to User "!name" <!uid>', array('!cid' => $cid, '!name' => $account->name, '!uid' => $account->uid)), 'success');
  }
  else {
    drush_set_error('DRUSH_ACCESS_DENIED', 'Access denied [comment]: User cannot post comments, so could not have posted the specified comment. Rerun with --ignore-access to override.');
  }
}

/**
 * Will attempt to retrieve a user object.
 *
 * @param
 *  The uid or username of a user account.
 */
function _drush_give_get_user($account) {
  if (is_numeric($account)) {
    return user_load($account);
  }
  return user_load(array('name' => $account));
}
