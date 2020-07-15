<?php

/**
 * @file
 * Basic consent storage.
 */

$plugin = array(
  'title' => t('Basic storage'),
  'consent_storage_callback' => 'eu_cookie_compliance_store_consent_basic',
);

/**
 * Store record of consent in the database.
 *
 * If you make your own plugin, you are free to define what information to
 * store and how to store it. This basic method stores the following in the
 * database:
 *  - The UID.
 *  - The IP Address.
 *  - Time of consent.
 *  - Revision of the privacy policy at the time of consent.
 *
 * @param string $type
 *   The consent type (for example banner or form ID).
 *
 * @return bool
 *   Returns TRUE on storage success.
 *
 * @throws \Exception
 */
function eu_cookie_compliance_store_consent_basic($type) {
  global $user;

  $revision_id = _eu_cookie_compliance_get_current_policy_node_revision();
  $timestamp = time();
  $ip_address = ip_address();
  $uid = $user->uid;

  db_insert('eu_cookie_compliance_basic_consent')
    ->fields(array(
      'uid' => $uid,
      'ip_address' => $ip_address,
      'timestamp' => $timestamp,
      'revision_id' => $revision_id ? $revision_id : 0,
      'consent_type' => $type,
    ))
    ->execute();

  return TRUE;
}
