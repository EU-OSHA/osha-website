<?php

/**
 * Module's configuration form.
 */
function osha_reminders_admin_form($form, &$form_state) {
  $form['change_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Change settings'),
  );


  $form['change_settings']['osha_reminders_cron_notification_interval_months'] = array(
    '#type' => 'textfield',
    '#title' => 'Months Interval to send PM notifications',
    '#description' => 'Notifications sent to PM to review their sections.',
    '#default_value' => variable_get('osha_reminders_cron_notification_interval_months', 6),
  );

  $form['change_settings']['osha_reminders_cron_notification_heads_months'] = array(
    '#type' => 'textfield',
    '#title' => 'Months Interval to notify Heads after last PM notification',
    '#description' => 'Notifications sent to Head of Units to see the content update status.',
    '#default_value' => variable_get('osha_reminders_cron_notification_heads_months', 1),
  );

  $form['change_settings']['osha_reminders_heads_role'] = array(
    '#title' => 'Head of Unit Role',
    '#type' => 'select',
    '#options' => user_roles(),
    '#default_value' => variable_get('osha_reminders_heads_role', 3),
  );

  $form['change_settings']['pm_email_template'] = array(
    '#type' => 'fieldset',
    '#title' => t('PM email template'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['change_settings']['pm_email_template']['osha_reminder_template_pm_subject'] = array(
    '#type' => 'textfield',
    '#title' => 'PM email subject',
    '#default_value' => variable_get('osha_reminder_template_pm_subject', '[OSHA Website] Reminders: Review your Sections'),
  );
  $form['change_settings']['pm_email_template']['osha_reminder_template_pm_body'] = array(
    '#type' => 'textarea',
    '#title' => 'PM email body',
    '#default_value' => variable_get('osha_reminder_template_pm_body',
        'Dear [user:name],<br/>
<br/>
As project manager of  <a href="[site:url]/admin/config/workbench/access/managers">[site:url]/admin/config/workbench/access/managers</a>, you are kindly invited to review the content of your section twice a year.<br/> 
Please, remember that you need to check that the content is still relevant and up to date, and that all the links work properly.<br/>
You can check the broken links in <a href="[site:url]/admin/content/linkchecker-broken-links">this page</a>.<br/>
<br/>
Thanks a lot for reviewing your contents.<br/>'
    ),
  );

  $form['change_settings']['heads_email_template'] = array(
    '#type' => 'fieldset',
    '#title' => t('Head of Units email template'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['change_settings']['heads_email_template']['osha_reminder_template_heads_subject'] = array(
    '#type' => 'textfield',
    '#title' => 'Head of Units email subject',
    '#default_value' => variable_get('osha_reminder_template_heads_subject', '[OSHA Website] Reminders: Content Update Status'),
  );
  $form['change_settings']['heads_email_template']['osha_reminder_template_heads_body'] = array(
    '#type' => 'textarea',
    '#title' => 'Head of Units email body',
    '#default_value' => variable_get('osha_reminder_template_heads_body',
        'Dear [user:name],<br/>
<br/>
As you know the contents on the website have to be reviewed every 6 months. In principle the project managers of the different sections should have received their reminders one month ago.<br/> This is a reminder for you to check the content status of <a href="[site:url]/admin/config/workbench/access/managers">in this screen</a>.<br/>
You can check the broken links in <a href="[site:url]/admin/content/linkchecker-broken-links">this page</a>.<br/>
<br/>
Thank you,<br/>'
    ),
  );

  $form['change_settings']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $pm_last_run = variable_get('osha_reminders_pm_notify_last_run', NULL);
  if ($pm_last_run) {
    $pm_last_run_info = date('Y-m-d', $pm_last_run);
  }
  else {
    $pm_last_run_info = t('Never');
  }

  $heads_last_run = variable_get('osha_reminders_heads_notify_last_run', NULL);
  if ($heads_last_run) {
    $heads_last_run_info = date('Y-m-d', $heads_last_run);
  }
  else {
    $heads_last_run_info = t('Never');
  }

  $form['change_dates'] = array(
    '#type' => 'fieldset',
    '#title' => t('Change dates'),
    '#description' => 'Use this mostly for testing purposes.',
  );
  $form['change_dates']['osha_reminders_summary'] = array(
    '#type' => 'markup',
    '#markup' => '<p>Last email sent to PM: ' . $pm_last_run_info . '<p>'
    . '<p>Last email sent to Head of Units: ' . $heads_last_run_info . '<p>',
  );

  $form['change_dates']['osha_reminders_pm_notify_last_run'] = array(
    '#type' => 'date',
    '#title' => 'Change date of last mail sent to PM',
  );

  $form['change_dates']['osha_reminders_heads_notify_last_run'] = array(
    '#type' => 'date',
    '#title' => 'Change date of last mail sent to Head of Units',
  );

  $form['change_dates']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Change dates'),
    '#submit' => array('osha_reminders_admin_form_change_dates_submit'),
  );

  $form['change_dates']['notify_pm'] = array(
    '#type' => 'submit',
    '#value' => t('Notify PM now'),
    '#submit' => array('osha_reminders_admin_form_notify_pm_submit'),
  );

  $form['change_dates']['notify_heads'] = array(
    '#type' => 'submit',
    '#value' => t('Notify Head of Units now'),
    '#submit' => array('osha_reminders_admin_form_notify_heads_submit'),
  );

  return $form;
}

/**
 * Submit callback for settings form of the module.
 */
function osha_reminders_admin_form_submit($form, &$form_state) {
  // Unset dates.
  unset($form_state['values']['osha_reminders_pm_notify_last_run']);
  unset($form_state['values']['osha_reminders_heads_notify_last_run']);
  // Save settings
  system_settings_form_submit($form, $form_state);
  drupal_set_message(t('Settings saved successfully'));
}

/**
 * Submit callback for change dates of the module.
 */
function osha_reminders_admin_form_change_dates_submit($form, &$form_submit) {
  // Save dates.
  $last_run = $form_submit['values']['osha_reminders_pm_notify_last_run'];
  $last_run = $last_run['year'] . '-' . $last_run['month'] . '-' . $last_run['day'];
  $last_run = strtotime($last_run);
  variable_set('osha_reminders_pm_notify_last_run', $last_run);

  $heads_last_run = $form_submit['values']['osha_reminders_heads_notify_last_run'];
  $heads_last_run = $heads_last_run['year'] . '-' . $heads_last_run['month'] . '-' . $heads_last_run['day'];
  $heads_last_run = strtotime($heads_last_run);
  variable_set('osha_reminders_heads_notify_last_run', $heads_last_run);

  drupal_set_message(t('Dates changed succesfully!'));
}

/**
 * Submit Callback for button Notify PM now.
 */
function osha_reminders_admin_form_notify_pm_submit($form, &$form_submit) {
  variable_set('osha_reminders_pm_notify_last_run', REQUEST_TIME);
  osha_reminders_notify_pm();
  drupal_set_message(t('PMs are notified!'));
}

/**
 * Submit callback for Notify Head of Units now.
 */
function osha_reminders_admin_form_notify_heads_submit($form, &$form_submit) {
  variable_set('osha_reminders_heads_notify_last_run', REQUEST_TIME);
  osha_reminders_notify_heads();
  drupal_set_message(t('Head of units are notified!'));
}
