<?php

/**
 * Module's configuration form.
 */
function osha_alert_service_admin_form($form, &$form_state) {
  $entity = entity_get_info('osha_alert_service');
  $token_types = array();
  $token_types['osha_alert_service'] = $entity;
  $form['osha_alert_service_mail'] = array(
    '#title' => 'Email Templates',
    '#type' => 'fieldset',
  );
  $form['osha_alert_service_mail']['osha_alert_service_alert_subject'] = array(
    '#title' => 'Alert email subject',
    '#type' => 'textfield',
    '#default_value' => variable_get('osha_alert_service_alert_subject',
      'EU-OSHA alert'),
  );
  $form['osha_alert_service_mail']['osha_alert_service_alert_body'] = array(
    '#title' => t('Alert email body'),
    '#type' => 'textarea',
    '#default_value' => variable_get('osha_alert_service_alert_body', <<<EOT
[osha_alert_service:alert_content]
<p><span style="font-size:11px"><span style="color:#A9A9A9">If you don&#39;t want to receive this alert, you can&nbsp;</span><strong><a href="[unsubscribe_link]"><span style="color:#A9A9A9">unsubscribe</span></a><span style="color:#A9A9A9">.</span></strong></span></p>
EOT
    )
  );
  $form['osha_alert_service_mail']['osha_alert_service_subscribe_subject'] = array(
    '#title' => 'Subscribe email subject',
    '#type' => 'textfield',
    '#default_value' => variable_get('osha_alert_service_subscribe_subject',
      'Your subscription to OSHA Alert Service'),
  );
  $form['osha_alert_service_mail']['osha_alert_service_subscribe_body'] = array(
    '#title' => t('Subscribe email body'),
    '#type' => 'textarea',
    '#default_value' => variable_get('osha_alert_service_subscribe_body', <<<EOT
<p>EU-OSHA received a request to start sending alerts to <strong>[osha_alert_service:email]</strong>.</p>

<p>Verify this EU-OSHA alert request: [osha_alert_service:subscribe_conf_link]</p>

<p>Cancel this EU-OSHA alert request: [osha_alert_service:unsubscribe_link]</p>

<p>If you are not able to click on the link, you can cut and paste it into your browser&#39;s address bar.</p>

<p>If you did not initiate this request or believe it was sent in error you can safely ignore this message.</p>

<p>Thanks,</p>
<p><strong>The EU-OSHA alerts Team</strong></p>
EOT
    )
  );

  $form['osha_alert_service_mail']['osha_alert_service_edit_info_subject'] = array(
    '#title' => 'Edit alerts email subject',
    '#type' => 'textfield',
    '#default_value' => variable_get('osha_alert_service_edit_info_subject',
      'Information about your subscriptions to EU-OSHA alert service'),
  );
  $form['osha_alert_service_mail']['osha_alert_service_edit_info_body'] = array(
    '#title' => t('Edit alerts email body'),
    '#type' => 'textarea',
    '#default_value' => variable_get('osha_alert_service_edit_info_body',
<<<EOT
<p>You have requested information about alerts registered for <strong>[osha_alert_service:email]</strong>.</p>
[osha_alert_service:subscriptions]
<p>If you did not initiate this request or believe it was sent in error you can safely ignore this message.</p>

<p>Thanks,</p>
<p><strong>The EU-OSHA alerts Team</strong></p>
EOT
    )
  );

  if (module_exists('token')) {
    $form['tokens'] = array(
      '#title' => 'Replacement tokens',
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['tokens']['token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('osha_alert_service'),
    );
  }
  else {
    $form['token_tree'] = array(
      '#markup' => '<p>' . t('Enable the <a href="@drupal-token">Token module</a> to view the available token browser.', array('@drupal-token' => 'http://drupal.org/project/token')) . '</p>',
    );
  }

  $form['test'] = array(
    '#title' => 'Test',
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['test']['osha_alert_service_test_reset_days'] = array(
    '#title' => 'Days to reset',
    '#type' => 'textfield',
    '#description' => 'Number of days to reset back your last sent alert date.',
    '#default_value' => variable_get('osha_alert_service_test_reset_days', 30),
  );
  $form['test']['test_submit'] = array(
    '#value' => 'Test your alerts',
    '#type' => 'submit',
    '#suffix' => 'This will reset your alerts\' last sent time to X days ago and send your alerts!',
    '#submit' => array('osha_alert_service_test_my_email_submit'),
  );
  $form['test']['info'] = array(
    '#markup' => '<p>You can also use drush command: ' . htmlentities('drush osha-alert-service-test <id> <days>') . '</p>',
  );

  return system_settings_form($form);
}

/**
 * Submit callback to test current user alerts.
 */
function osha_alert_service_test_my_email_submit($form, &$form_state) {
  global $user;
  $result = db_select('osha_alert_service', 'a')
    ->fields('a')
    ->condition('email', $user->mail)
    ->execute()
    ->fetchAllKeyed(0);

  if (empty($result)) {
    drupal_set_message('You don\'t have a subscription for alert service! Please subscribe in order to test!', 'warning');
    return;
  }

  $days = $form_state['values']['osha_alert_service_test_reset_days'];
  $item_ids = array_keys($result);
  foreach ($item_ids as $item_id) {
    if ($entity = entity_load_single('osha_alert_service', $item_id)) {
      $entity->last_alert = date('U') - ($days * 24 * 3600);
      entity_save('osha_alert_service', $entity);
      osha_alert_service_send_alert($item_id);
    }
  }
  drupal_set_message('Your alerts have been sent!');
}
