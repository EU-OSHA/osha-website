<?php

define('EU_COOKIE_COMPLIANCE_BASE_TABLE', 'eu_cookie_compliance_basic_consent');

/**
 * @file
 * Provides views data for eu_cookie_compliance.module.
 */

/**
 * Implements hook_views_data().
 */
function eu_cookie_compliance_views_data() {
  $data[EU_COOKIE_COMPLIANCE_BASE_TABLE] = array();

  $data[EU_COOKIE_COMPLIANCE_BASE_TABLE]['table']['base'] = array(
    'field' => 'cid',
    'title' => t('EU Cookie Compliance Consents'),
    'help' => t('EU Cookie Compliance consent data from the database.'),
    'weight' => -10,
  );

  $data[EU_COOKIE_COMPLIANCE_BASE_TABLE]['table']['group'] = t('EU Cookie Compliance');

  $data[EU_COOKIE_COMPLIANCE_BASE_TABLE]['uid'] = array(
    'title' => t('User ID'),
    'help' => t('User ID.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'relationship' => array(
      // ID of relationship handler plugin to use.
      'handler' => 'views_handler_relationship',
      // Views name of the table to join to for the relationship.
      'base' => 'users',
      // Database field name in the user table to join on.
      'base field' => 'uid',
      // Default label for relationship in the UI.
      'title' => t('Consent User'),
      'label' => t('consent user'),
      'help' => t('The User ID of the consent.'),
    ),
  );

  $data[EU_COOKIE_COMPLIANCE_BASE_TABLE]['timestamp'] = array(
    'title' => t('Timestamp'),
    'help' => t('Time of consent.'),
    'real field' => 'timestamp',
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data[EU_COOKIE_COMPLIANCE_BASE_TABLE]['ip_address'] = array(
    'title' => t('IP address'),
    'help' => t('The IP address.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data[EU_COOKIE_COMPLIANCE_BASE_TABLE]['consent_type'] = array(
    'title' => t('Consent Type'),
    'help' => t('The type of consent, such as "banner" for the banner and form_id for forms.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data[EU_COOKIE_COMPLIANCE_BASE_TABLE]['revision_id'] = array(
    'title' => t('Revision ID'),
    'help' => t('Revision of the privacy policy at the time of consent.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  return $data;
}
