<?php

/**
 * Implements hook_views_handlers().
 */
function osha_press_contact_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'osha_press_contact'),
    ),
    'handlers' => array(
      'osha_press_contact_handler_board_group' => array(
        'parent' => 'views_handler_field',
      ),
      'osha_press_contact_handler_bureau_group' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function osha_press_contact_views_data() {
  $data = array();
  // Define group.
  $data['osha_press_contact']['table']['group'] = t('Osha press contact');
  $data['osha_press_contact']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );
  // Add custom fields.
  $data['osha_press_contact']['board_group'] = array(
    'title' => t('Board members group field'),
    'help' => t('Country and Observer, EC'),
    'field' => array(
      'handler' => 'osha_press_contact_handler_board_group',
    ),
  );
  $data['osha_press_contact']['bureau_group'] = array(
    'title' => t('Bureau members group field'),
    'help' => t('Executive Board'),
    'field' => array(
      'handler' => 'osha_press_contact_handler_bureau_group',
    ),
  );
  return $data;
}
