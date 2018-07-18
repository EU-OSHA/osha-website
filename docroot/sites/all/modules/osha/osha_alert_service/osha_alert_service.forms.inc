<?php
/**
 * @file
 * Module forms.
 */

/**
 * Alert service subscription form.
 *
 * @return array
 *   Form to subscribe
 */
function osha_alert_service_subscribe_form($form, &$form_state) {
  $form = array(
    '#tree' => FALSE,
  );
  global $user;
  $email = '';
  if (!empty($user->mail)) {
    $email = $user->mail;
  }
  $sections = array();
  if ($voc = taxonomy_vocabulary_machine_name_load('tags')) {
    $terms = taxonomy_get_tree($voc->vid);
    foreach ($terms as $term) {
      $w = entity_metadata_wrapper('taxonomy_term', $term->tid);
      $sections[$term->tid] = $w->label();
    }
  }
  if (empty($sections)) {
    drupal_set_message(
      t(
        "Internal error due to missing categories. Self-destructing in 3 .. 2 .."),
        'error'
    );
    if ($site_email = variable_get('site_mail', FALSE)) {
      drupal_mail('osha_alert_service', 'broken_subscription', $site_email, 'en', array());
    }
    return $form;
  }

  $form['edit_alerts'] = array(
    '#type' => 'item',
    '#markup' => t('If you are already subscribed and you want to edit your subscription, please use <a href="@link">this edit link</a>.', array('@link' => url('alertservice/edit'))),
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail'),
    '#default_value' => $email,
    '#required' => TRUE,
  );

  $form['section'] = array(
    '#type' => 'select',
    '#multiple' => TRUE, '#size' => 10,
    '#title' => t('Subjects of interest'),
    '#required' => TRUE,
    '#options' => $sections,
  );

  $types = array();

  $allowed = array(
    'publication', 'news', 'calls', 'job_vacancies', 'blog', 'events', 'directive', 'guideline', 'seminar',
  );

  $alltypes = node_type_get_types();
  foreach ($allowed as $machine_name) {
    $types[$machine_name] = t($alltypes[$machine_name]->name);
  }

  $form['type'] = array(
    '#type' => 'select',
    '#multiple' => TRUE, '#size' => 10,
    '#title' => t('Item type'),
    '#required' => TRUE,
    '#options' => $types,
  );

  $form['schedule'] = array(
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Schedule'),
    '#options' => array(
      'daily' => t('Daily'),
      'weekly' => t('Weekly'),
      'monthly' => t('Monthly'),
    ),
    '#default_value' => 'monthly',
  );

  $languages = array();
  $alllanguages = osha_language_list(TRUE);
  unset($alllanguages['en']);
  foreach ($alllanguages as $code => $language) {
    $languages[$code] = $language->native;
  }
  $form['languages'] = array(
    '#type' => 'select',
    '#multiple' => TRUE, '#size' => 10,
    '#title' => t('Additional languages'),
    '#options' => $languages,
    '#description' => t('Alerts are sent in English. If the content is translated, you can choose to receive it in additional languages.'),
  );

  $form['newsletter'] = array(
    '#type' => 'checkbox',
    '#title' => t('I also want to receive OSHMail'),
    '#default_value' => 1,
  );

  $form['help'] = array(
    '#type' => 'item',
    '#markup' => t('<b>Note</b>: In order to choose more than one item from the list, press the key CTRL on your keyboard (CMD on Mac), and select the item with your mouse.'),
  );

  if (user_is_anonymous()) {
    $form['captcha'] = array(
      '#type' => 'captcha',
      '#captcha_type' => 'default',
    );
  }

  $form['agree_processing_personal_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('I agree to the processing of my personal data'),
    '#default_value' => 0,
  );

  $link_label = t(variable_get('subscribe_block_details_link_label', 'Privacy notice'));
  $link_url = variable_get('osha_alert_service_privacy_policy_url', OSHA_ALERT_SERVICE_PRIVACY_PAGE_URL);
  $form['details_link'] = array(
    '#markup' => '<a class="privacy-policy-oshmail" href=' . url($link_url) . '>' . $link_label . '</a><br/>',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#name' => 'subscribe',
    '#value' => t('Subscribe'),
    '#attributes' => array('class' => array('container-inline')),
  );

  $form['unsubscribe'] = array(
    '#type' => 'item',
    '#markup' => t('If you would like to unsubscribe, please use the unsubscribe link from the footer of an alert sent to you.'),
  );

  if (!empty($_GET['token'])) {
    $alert = osha_alert_service_osha_alert_service_load_by_token($_GET['token']);
    if (!empty($alert)) {
      // Set stored values.
      $filters = json_decode($alert->filters, TRUE);
      $form['section']['#default_value'] = $filters['section'];
      $form['languages']['#default_value'] = $filters['languages'];
      $form['type']['#default_value'] = $filters['type'];
      $form['schedule']['#default_value'] = $alert->schedule;
      $form['email']['#default_value'] = $alert->email;
      $form['email']['#attributes']['readonly'] = 'readonly';

      $form['token'] = array(
        '#type' => 'hidden',
        '#value' => $_GET['token'],
      );

      $form['actions']['submit']['#value'] = t('Update subscription');
      $form['actions']['cancel'] = array(
        '#type' => 'markup',
        '#markup' => l(t('Cancel'), 'alertservice', array(
            'attributes' => array('class' => array('alert-service-cancel'))
        )),
      );
      $form['actions']['unsubscribe'] = array(
        '#type' => 'markup',
        '#markup' => l(t('Unsubscribe'), 'alertservice/remove_alert', array(
            'query' => array('token' => $alert->token),
            'attributes' => array('class' => array('alert-service-unsubscribe')),
        ))
      );

      // Hide the unsubscribe message.
      unset($form['unsubscribe']);
      // Hide the edit alerts message.
      unset($form['edit_alerts']);
    }
    else {
      drupal_set_message(t('Subscription not found. Please create one!'), 'warning');
      drupal_goto('alertservice');
    }
  }

  return $form;
}

function osha_alert_service_edit_form($form, &$form_state) {
  global $user;
  $email = '';
  if (!empty($user->mail)) {
    $email = $user->mail;
  }

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail'),
    '#default_value' => $email,
    '#required' => TRUE,
  );

  if (user_is_anonymous()) {
    $form['captcha'] = array(
      '#type' => 'captcha',
      '#captcha_type' => 'default',
    );
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#name' => 'subscribe',
    '#value' => t('Edit your alerts'),
    '#attributes' => array('class' => array('container-inline')),
  );
  return $form;
}

/**
 * Drupal form_validate handler.
 *
 * {@inheritdoc}
 */
function osha_alert_service_subscribe_form_validate($form, $form_state) {
  $agree = trim($form_state['values']['agree_processing_personal_data']);
  if (!$agree) {
    form_set_error('agree_processing_personal_data', t('Please, tick the box to agree in order to submit your email.'));
  }

  if (empty($form_state['values']['email']) || !valid_email_address($form_state['values']['email'])) {
    form_set_error('email', t('Please enter a valid email address'));
  };
}

/**
 * Drupal form_submit handler.
 *
 * {@inheritdoc}
 */
function osha_alert_service_subscribe_form_submit($form, $form_state) {
  $values = $form_state['values'];
  $filters = array(
    'section' => array_values($values['section']),
    'type' => array_values($values['type']),
    'languages' => array_values($values['languages']),
  );
  $created = time();
  $email = $values['email'];
  // If token present, than try find the existing alert.
  if (!empty($values['token']) && $entity = osha_alert_service_osha_alert_service_load_by_token($values['token'])) {
    $token = $values['token'];
    $entity->filters = json_encode($filters);
    $entity->schedule = $values['schedule'];
    $entity->changed = time();
    entity_save('osha_alert_service', $entity);
    drupal_set_message(t('Your alert settings have been changed.'));
  }
  else {
    // Create alert.
    $token = sha1('TIMESTAMP:' . $created);
    $entity = entity_create(
      'osha_alert_service',
      array(
        'email' => $email,
        'filters' => json_encode($filters),
        'schedule' => $values['schedule'],
        'created' => $created,
        'token' => $token,
        'confirmed' => 0,
        'last_alert' => $created,
      )
    );
    entity_save('osha_alert_service', $entity);
    drupal_set_message(t('Your request has been registered. Please check your email for further instructions'));

    global $language;
    $params = array(
      'osha_alert_service' => $entity,
      'language' => $language->language,
    );
    drupal_mail('osha_alert_service', 'subscribe', $email, $language->language, $params);
  }

  // Subscribe to OSHMail.
  if ($values['newsletter']) {
    osha_newsletter_block_subscribe_captcha_form_submit($form, $form_state);
  }
  drupal_goto('alertservice', array('query' => array('token' => $token)));
}

function osha_alert_service_edit_form_validate($form, $form_state) {
  osha_alert_service_subscribe_form_validate($form, $form_state);
  if (!empty($form_state['values']['email']) && valid_email_address($form_state['values']['email'])) {
    $alerts = osha_alert_service_osha_alert_service_load_by_email($form_state['values']['email']);
    if (empty($alerts)) {
      form_set_error('email', t('No alerts registered for this email address.'));
    }
  }
}

function osha_alert_service_edit_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $email = $values['email'];
  $alerts = osha_alert_service_osha_alert_service_load_by_email($email);
  if (!empty($alerts)) {
    global $language;
    $params = array(
      'osha_alert_service' => current($alerts),
      'osha_subscriptions' => $alerts,
      'language' => $language->language,
    );
    drupal_mail('osha_alert_service', 'edit', $email, $language->language, $params);
    drupal_set_message(t('Your subscription\'s information has been sent to your email.'));
  }
}

/**
 * Menu handler for unsubscription.
 */
function osha_alert_service_remove_alert_form($form, &$form_state) {
  $form = array(
    '#tree' => FALSE,
  );
  $request = drupal_get_query_parameters();
  if (isset($request['token']) && $entity = osha_alert_service_osha_alert_service_load_by_token($request['token'])) {
    $form_state['entity'] = $entity;
    $form['email'] = array(
      '#type' => 'item',
      '#markup' => t(
        'Unsubscribe !email from receiving EU-OSHA alert service notifications?',
        array('!email' => $entity->email)
      ),
    );
    $form['actions']['submit'] = array(
      '#type'       => 'submit',
      '#name'       => 'unsubscribe',
      '#value'      => t('Unsubscribe'),
      '#attributes' => array('class' => array('container-inline')),
    );
  }
  else {
    drupal_set_message(t('Invalid alert subscription token'), 'error');
  }
  return $form;
}

/**
 * Drupal form_submit handler.
 *
 * {@inheritdoc}
 */
function osha_alert_service_remove_alert_form_submit($form, $form_state) {
  if (isset($form_state['entity'])) {
    $entity = $form_state['entity'];
    $entity->confirmed = 1;
    entity_delete('osha_alert_service', $form_state['entity']->id);
    drupal_set_message(t('You have been successfully un-subscribed from alert'));
    drupal_goto('<front>');
  }
}

/**
 * Menu handler for confirmation.
 */
function osha_alert_service_verify_alert_form() {
  $request = drupal_get_query_parameters();
  if (isset($request['token']) && $entity = osha_alert_service_osha_alert_service_load_by_token($request['token'])) {
    if ($entity->confirmed <> 1) {
      $entity->confirmed = 1;
      if (entity_save('osha_alert_service', $entity)) {
        drupal_set_message(t('Your subscription has been confirmed, thank you'));
      }
    }
    else {
      drupal_set_message(t("Your subscription is already confirmed, there's nothing you need to do"), 'warning');
    }
  }
  else {
    drupal_set_message(t("Hmm ... an invalid request, I hope that's a test!"), 'error');
  }
  drupal_goto('<front>');
}
