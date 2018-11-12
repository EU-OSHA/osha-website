<?php

/**
 * This method creates the user roles required by the workflow.
 */
function osha_tmgmt_workflow_create_roles() {
  module_load_include('inc', 'osha_tmgmt', 'osha_tmgmt.permissions');
  module_load_include('module', 'osha_workflow');

  $roles = array(
    OSHA_WORKFLOW_ROLE_TRANSLATION_MANAGER => osha_tmgmt_workflow_permissions_role_translation_manager(),
    OSHA_WORKFLOW_ROLE_TRANSLATION_LIAISON => osha_tmgmt_workflow_permissions_role_translation_liaison(),
    OSHA_WORKFLOW_ROLE_LAYOUT_VALIDATOR => osha_tmgmt_workflow_permissions_role_layout_validator(),
    OSHA_WORKFLOW_ROLE_CONTENT_VALIDATOR => osha_tmgmt_workflow_permissions_role_content_validator(),
    OSHA_WORKFLOW_ROLE_PROJECT_MANAGER => osha_tmgmt_pm_permissions(),
    'administrator' => array_keys(osha_tmgmt_extra_permissions()),
  );

  foreach ($roles as $role_name => $permissions) {
    if ($role = user_role_load_by_name($role_name)) {
      // Nothing to do, really ...
    }
    else {
      $role = new stdClass();
      $role->name = $role_name;
      user_role_save($role);
    }
    user_role_grant_permissions($role->rid, $permissions);
  }
}

/**
 * Check if current user can edit the job item.
 */
function osha_tmgmt_user_can_edit_job_item($job_item) {
  global $user;
  if (OshaWorkflowPermissions::userHasRole('administrator', $user)) {
    return TRUE;
  }

  switch ($job_item->state) {
    case OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidationRequired:
      // If next Content Validator -> can edit.
      $validators = osha_tmgmt_load_validators_by_job_item($job_item);
      if (array_key_exists($user->uid, $validators)
        && $validators[$user->uid]->next == 1) {
        return TRUE;
      }
      if (user_access('set job item to ready to publish state')) {
        return TRUE;
      }
      break;

    case TMGMT_JOB_ITEM_STATE_ACTIVE:
      if (user_access('set job item to translated state')) {
        return TRUE;
      }
      break;

    case OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidated:
      if (user_access('set job item to ready to publish state')) {
        return TRUE;
      }
      break;

    case TMGMT_JOB_ITEM_STATE_REVIEW:
      if (user_access('set job item to require content validation state')
      || user_access('set job item to ready to publish state')) {
        return TRUE;
      }
      break;

    case OSHA_TMGMT_JOB_ITEM_STATE_TranslatedReadyToPublish:
      if (user_access('accept job item translation')) {
        return TRUE;
      }
      break;
  }
  return FALSE;
}

/**
 * Hook menu that allows to see layout validation of a node from a job item.
 *
 * @param object $node
 *   Node to render
 * @param object $job_item
 *   Associated job item
 *
 * @return string
 *   Renderable array
 */
function osha_tmgmt_layout_validation_node_preview($nid, $job_item) {
  $target_language = $job_item->target_language;
  $source_language = $job_item->source_language;
  $node = entity_load_single($job_item->item_type, $job_item->item_id);
  $node = workbench_moderation_node_current_load($node);

  $new_job_data = OshaTMGMTRetranslate::apply_partial_translation(
    $node, $job_item->getData(), $source_language, $target_language);
  tmgmt_field_populate_entity($node->type, $node, $target_language, $new_job_data);
  foreach (element_children($new_job_data) as $field_name) {
    // re-sanitize all fields otherwise the old translated safe_value is displayed on preview
    if (isset($node->{$field_name}[$target_language][0])) {
      $field = $node->{$field_name}[$target_language][0];
      if (empty($field['value'])) {
        drupal_set_message('There is no translated text for '.$field_name, 'warning');
        $field['value'] = '';
      }
      if (empty($field['format'])) {
        // empty string causes check_markup not to work properly
        $field['format'] = NULL;
      }
      // Re-sanitize text after tmgmt_field_populate_entity
      // ['safe_value'] is rendered instead if different than ['value']
      // This can happen when node had a translation (re-translation)
      $node->{$field_name}[$target_language][0]['safe_value'] =
        check_markup($field['value'], $field['format'], $target_language);
    }
  }

  if (empty($node->title_field[$target_language][0]['value'])) {
    drupal_set_message(t('There is no translated text for Title'), 'warning');
    $node->title_field[$target_language][0]['value'] = '';
  }
  // set also the title safe_value (causes warning on preview)
  if (isset($node->title_field[$target_language][0])) {
    $node->title_field[$target_language][0]['safe_value'] =
      $node->title_field[$target_language][0]['value'];
  }

  /* @todo: fix the preview when the node has a Published and a ReadyToPublish version without translations
  see also https://www.drupal.org/node/2020325
  if (!isset($node->translations->data[$target_language])) {
    // tmgmt_field_populate_entity does not add the translation if not present before
    $handler = entity_translation_get_handler($job_item->item_type, $node);
    $handler->setFormLanguage($job_item->target_language);
    $translation = array(
      // @todo Improve hardcoded values.
      'entity_type' => $job_item->item_type,
      'entity_id' => $node->nid,
      'translate' => 0,
      'status' => 1,
      'language' => $job_item->target_language,
      'source' => $job_item->source_language,
    );
    $handler->setTranslation($translation, $node);
    $node->translations->data[$target_language] = $translation;
    //$handler->saveTranslations();
  }
  */
  $renderable_node = node_view($node, 'full', $target_language);
  /* No need to show the title, it is already included
  $title = field_get_items('node', $node, 'title_field', $target_language);
  if (!empty($title[0]['value'])) {
    // @todo: Title hard-coded in template 'Manage Display' hides the title.
    $renderable_node['title_field'] = array(
      '#type' => 'item',
      '#markup' => sprintf('<h1 class="page__title title" id="page-title">%s</h1>', $title[0]['value']),
    );
  }
  */
  return drupal_render($renderable_node);
}

function osha_tmgmt_translation_validation_options() {
  return array(
    'approved' => 'Approved',
    'rejected' => 'Rejected',
  );
}

function osha_tmgmt_job_item_target_language_options() {
  $languages = language_list();
  $return = array();
  foreach ($languages as $lang_code => $language) {
    $return[$lang_code] = $languages->name;
  }
}

/**
 * Get Groups of Translation Validators.
 */
function osha_tmgmt_get_translators_groups() {
  $entities = entity_collection_load_all();
  $return = array();
  foreach ($entities as $entity) {
    if ($entity->bundle == OSHA_TMGMT_TRANS_VALID_GROUP) {
      $return[] = $entity;
    }
  }
  return $return;
}

/**
 * Returns options array for select forms.
 */
function osha_tmgmt_get_translators_groups_as_options() {
  $translators_groups = osha_tmgmt_get_translators_groups();
  $options = array();
  foreach ($translators_groups as $group) {
    $options[$group->eid] = $group->name;
  }
  return $options;
}

/**
 * Get users of a Collection Translation Validators.
 */
function osha_tmgmt_get_users_from_collection($tg_eid) {
  $entity_group = entity_collection_load($tg_eid);
  $users_tree_node = entity_collection_load_content(OSHA_TMGMT_TRANS_VALID_GROUP, $entity_group)->list;
  $users = array();
  foreach ($users_tree_node as $user) {
    $users[$user->content->uid] = $user->content;
  }
  return $users;
}

/**
 * Submit callback for Add Translation Validators Group.
 */
function osha_tmgmt_translation_validators_submit($form, &$form_state) {
  if (!empty($form_state['values']['translation_validators']['translation_group'])) {
    /* @var TMGMTJobItem $job */
    $job = $form_state['tmgmt_job'];
    $job_items = $job->getItems();
    foreach ($job_items as $job_item) {
      if ($job_item->state != OSHA_TMGMT_JOB_ITEM_STATE_TranslatedReadyToPublish) {
        $group_id = $form_state['values']['translation_validators']['translation_group'];
        $entity_group = entity_collection_load($group_id);
        $users = osha_tmgmt_get_users_from_collection($group_id);
        $users = osha_workflow_users_group_by_lang_skills($users, $job_item->source_language);
        // CW-1766: Notify the current validator if his action is no longer required
        if ($job_item->state == OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidationRequired) {
          $removed_validators = osha_tmgmt_load_validators_by_job_item($job_item);
          $old_current_validator = osha_tmgmt_load_validators_next($removed_validators);
          $new_current_validator = $users[$job_item->target_language][0];
          if (!empty($old_current_validator) && $old_current_validator->uid != $new_current_validator->uid) {
            OshaWorkflowNotifications::notifyTranslationValidatorsRemoved($old_current_validator, $job_item);
            OshaWorkflowNotifications::sendEmail($new_current_validator, array('tmgmt_job_item' => $job_item), 'osha_tmgmt');
          }
        }

        // Cancel existing validators.
        osha_tmgmt_remove_current_translation_validators($job_item);
        if (!empty($users[$job_item->target_language])) {
          $users_name = array();
          foreach ($users[$job_item->target_language] as $idx => $u) {
            $next = 0;
            if ($idx == 0) {
              $next = 1;
            }
            $users_name[] = $u->name;
            osha_tmgmt_add_translation_validator($u->uid, $job_item, $idx, $next);
          }
          global $user;
          $msg = t('@name assigned validators: @validators to @language',
            array(
              '@name' => $user->name,
              '@language' => locale_language_name($job_item->target_language),
              '@group' => $entity_group->name,
              '@validators' => implode(', ', $users_name),
            ));
          drupal_set_message($msg);
          $job_item->addMessage($msg);
        }
        else {
          drupal_set_message(
            t(
              'No translator available for @language',
              array('@language' => locale_language_name($job_item->target_language))
            ),
            'warning'
          );
        }
        $job_item->eid = $group_id;
        $job_item->save();
      }
    }
  }
}

function osha_tmgmt_add_translation_validator($uid, $job_item, $weight, $next = 0) {
  $validator = array(
    'tjiid' => $job_item->tjiid,
    'uid' => $uid,
    'nid' => $job_item->item_id,
    'next' => $next,
    'weight' => $weight,
  );
  entity_save('translation_validator', (object) $validator);
}

function osha_tmgmt_remove_current_translation_validators($job_item, $uid = NULL){
  $query = db_update('osha_tmgmt_job_trans_validators')
    ->fields(array(
      'deleted' => 1,
    ))
    ->condition('tjiid', $job_item->tjiid)
    ->condition('deleted', 0);
  if (!empty($uid)) {
    $query->condition('uid', $uid);
  }
  $query->execute();
  return;
}

function osha_tmgmt_translation_validators_reset_order($job_item){
  db_update('osha_tmgmt_job_trans_validators')
    ->fields(array(
      'next' => 0,
    ))
    ->condition('tjiid', $job_item->tjiid)
    ->condition('deleted', 0)
    ->execute();
  return;
}

function osha_tmgmt_load_validators_by_job_item($job_item) {
  $entities = entity_load('translation_validator', FALSE, array(
    'tjiid' => $job_item->tjiid,
    'deleted' => 0,
  ));
  $uids = array();
  foreach ($entities as $entity) {
    $uids[] = $entity->uid;
  }
  $return = array();
  $users = user_load_multiple($uids);
  $weight = array();
  foreach ($entities as &$entity) {
    $weight[$entity->weight] = $entity;
  }
  ksort($weight);
  foreach ($weight as &$entity) {
    if (!empty($users[$entity->uid])) {
      $return[$entity->uid] = (object) array_merge((array) $entity, (array) $users[$entity->uid]);
    }
  }
  return $return;
}

function osha_tmgmt_load_validators_last($validators) {
  $weight = array();
  foreach ($validators as &$validator) {
    $weight[$validator->weight] = $validator;
  }
  ksort($weight);
  return end($weight);
}

function osha_tmgmt_load_validators_next($validators) {
  foreach ($validators as &$validator) {
    if ($validator->next == 1) {
      return $validator;
    }
  }
  return array();
}

/**
 * Get translation validator group.
 */
function osha_tmgmt_get_job_translation_validators_group($eid) {
  return entity_collection_load($eid);
}

/**
 * Retrieve the list of content validators with  a certain translation skill.
 *
 * @param string $target_language
 *   Language to translate to
 * @param string $source_language
 *   Language to translate from
 *
 * @return array
 *   Array of users with the required skills.
 */
function osha_tmgmt_get_content_validators_by_skill($target_language, $source_language = 'en', $group_id = NULL) {
  $ret = array();
  if ($group_id) {
    $users = osha_tmgmt_get_users_from_collection($group_id);
  }
  else {
    $users = osha_workflow_users_get_users_from_role(OSHA_WORKFLOW_ROLE_CONTENT_VALIDATOR);
  }
  foreach ($users as $user) {
    if (!empty($user->tmgmt_translation_skills[LANGUAGE_NONE])) {
      foreach ($user->tmgmt_translation_skills[LANGUAGE_NONE] as $skill) {
        if ($skill['language_from'] == $source_language && $skill['language_to'] == $target_language) {
          $ret[] = $user;
          break;
        }
      }
    }
  }
  return $ret;
}

/**
 * List of content validators with certain skill as select options.
 *
 * @see osha_tmgmt_get_content_validators_by_skill
 * @return array
 *   Array rendered as options
 */
function osha_tmgmt_get_content_validators_by_skill_as_options($target_language, $source_language = 'en', $group = NULL) {
  $ret = array();
  $users = osha_tmgmt_get_content_validators_by_skill($target_language, $source_language, $group);
  foreach ($users as $user) {
    $ret[$user->uid] = $user->name;
  }
  return $ret;
}


/**
 * Group an array of users by their language skills.
 *
 * return array
 *   Indexed by target language
 */
function osha_workflow_users_group_by_lang_skills($users, $from_lang = 'en') {
  $return = array();
  if (!empty($users)) {
    foreach ($users as $user) {
      if (!empty($user->tmgmt_translation_skills)) {
        foreach ($user->tmgmt_translation_skills[LANGUAGE_NONE] as $skill) {
          if ($skill['language_from'] == $from_lang) {
            $return[$skill['language_to']][] = $user;
          }
        }
      }
    }
  }
  return $return;
}

/**
 * Callback for Layout Approve Submit.
 */
function osha_tmgmt_layout_validator_approve_submit($form, &$form_state) {
  $job_item = $form_state['item'];
  $message = '';
  if (!empty($form_state['values']['action_message'])) {
    $message = $form_state['values']['action_message'];
  }
  $job_item->toTranslated($message);
}

/**
 * Form for Managing Content Validators of a Job Item.
 */
function osha_tmgmt_job_item_validators_form($form, &$form_state, $job_item) {
  module_load_include('inc', 'osha_workflow', 'osha_workflow.api');
  module_load_include('inc', 'osha_workflow', 'osha_workflow.admin');
  if (empty($job_item->eid)) {
    drupal_set_message('Please set a content validators group to the job!', 'warning');
    return;
  }
  $cvalidators = osha_tmgmt_get_content_validators_by_skill_as_options($job_item->target_language, $job_item->source_language, $job_item->eid);
  if (empty($cvalidators)) {
    $group = entity_collection_load($job_item->eid);
    drupal_set_message(t('There are no users in group @group having @from to @to translation skill!',
      array(
        '@group' => $group->name,
        '@from' => locale_language_name($job_item->source_language),
        '@to' => locale_language_name($job_item->target_language),
      )), 'warning');
    return;
  }
  $form_state['jobItem'] = $job_item;
  $can_edit = user_access('edit translation content validators');
  $form['#can_edit']  = $can_edit;
  $form['#tree'] = TRUE;
  $form['#theme'] = 'osha_tmgmt_job_item_validators_form_table';
  if (isset($form_state['rows'])) {
    $rows = $form_state['rows'];
  }
  else {
    $rows = osha_tmgmt_load_validators_by_job_item($job_item);
    foreach ($rows as $row) {
      $row->osha_tmgmt_validators_saved = TRUE;
    }
  }
  $form_state['rows'] = $rows;
  $weight = 0;
  foreach ($rows as $uid => $row) {
    $form['rows'][$uid]['#row'] = $row;
    $form['rows'][$uid]['weight'] = array(
      '#type' => 'weight',
      '#title' => t('Weight'),
      '#title_display' => 'invisible',
      '#default_value' => $weight,
      '#access' => $can_edit,
      '#attributes' => array('class' => array('user-weight')),
    );
    $form['rows'][$uid]['uid'] = array(
      '#type' => 'hidden',
      '#value' => $uid,
    );
    $form['rows'][$uid]['remove'] = array(
      '#type' => 'submit',
      '#name' => $uid,
      '#value' => t('Remove'),
      '#access' => $can_edit,
      '#submit' => array('osha_tmgmt_job_item_validators_remove'),
    );
    $weight++;
  }
  $form['add']['uid'] = array(
    '#type' => 'select',
    '#title' => t('Add validator'),
    '#description' => t(
      'Select a content validator having !from to !to translation skill',
      array(
        '!from' => locale_language_name($job_item->source_language),
        '!to' => locale_language_name($job_item->target_language),
      )
    ),
    '#title_display' => 'before',
    '#access' => $can_edit,
    '#options' => $cvalidators,
  );
  $form['add']['submit'] = array(
    '#type' => 'submit',
    '#name' => 'adduser',
    '#value' => t('Add to queue'),
    '#access' => $can_edit,
    '#attributes' => array('class' => array('container-inline')),
    '#validate' => array('osha_tmgmt_job_item_validators_add_validate'),
    '#submit' => array('osha_tmgmt_job_item_validators_add'),
  );
  $form['help'] = array(
    '#type' => 'markup',
    '#markup' => t(
      '<div><strong>Tip:</strong> Use the drag handlers to sort the users in the order you want them to have the content reviewed. <br />** - Temporary, not yet saved</div>'
    ),
    '#access' => $can_edit,
  );
  $form['content'] = array(
    'actions' => array(
      '#type' => 'actions',
      '#weight' => 20,
      'submit' => array(
        '#type' => 'submit',
        '#value' => t('Save'),
        '#access' => $can_edit,
      ),
    ),
  );
  return $form;
}


/**
 * Callback for Validation of Add Content Validator form.
 */
function osha_tmgmt_job_item_validators_add_validate($form, &$form_state) {
  if (!empty($form_state['values']['add']['uid'])) {
    $user = user_load($form_state['values']['add']['uid']);
    if (empty($user)) {
      form_set_error('add][uid', t('User does not exist!'));
    }
    elseif (!empty($form_state['rows'])
      && in_array($user->uid, array_keys($form_state['rows']))) {
      form_set_error('add][uid', t('User is already validator for this translation'));
    }
  }
}

/**
 * Callback for Add Content Validator form.
 *
 * It adds the user to form_state.
 * The form must be saved in order to add them to DB.
 */
function osha_tmgmt_job_item_validators_add($form, &$form_state) {
  $user = user_load($form_state['values']['add']['uid']);
  if (!empty($user)) {
    $form_state['rows'][$user->uid] = $user;
    $form_state['rows'][$user->uid]->osha_tmgmt_validators_saved = FALSE;
    $form_state['values']['add']['uid'] = "";
    $form_state['input']['add']['uid'] = "";
    $form_state['rebuild'] = TRUE;
    drupal_set_message(t('Changes made in this table will not be saved until you press Save'), 'warning');
  }
}

/**
 * Callback for Remove Content Validator Button.
 *
 * Removes just from form state.
 */
function osha_tmgmt_job_item_validators_remove($form, &$form_state) {
  if (!empty($form_state['triggering_element']['#name'])) {
    $remove_uid = $form_state['triggering_element']['#name'];
    unset($form_state['rows'][$remove_uid]);
    foreach ($form_state['rows'] as &$row) {
      $row->osha_tmgmt_validators_saved = FALSE;
    }
  }
  $form_state['rebuild'] = TRUE;
  drupal_set_message(t('Changes made in this table will not be saved until you press Save'), 'warning');
}

/**
 * Validate callback for Content Validators Save.
 */
function osha_tmgmt_job_item_validators_form_validate($form, &$form_state) {
  if (empty($form_state['values']['rows'])) {
    form_set_error('add][uid', t('Cannot have an empty queue! Add another validator first'));
  }
}

/**
 * Callback form Content Validators Submit.
 *
 * Removes old Content Validators.
 * Inserts Content validators for the job items.
 */
function osha_tmgmt_job_item_validators_form_submit($form, &$form_state) {
  if (!empty($form_state['values']['rows'])) {
    $validators = array();
    $removed_validators = osha_tmgmt_load_validators_by_job_item($form_state['jobItem']);
    $old_current_validator = osha_tmgmt_load_validators_next($removed_validators);
    foreach ($form_state['values']['rows'] as $row) {
      $validators[$row['weight']] = $row;
      unset($removed_validators[$row['uid']]);
    }
    osha_tmgmt_remove_current_translation_validators($form_state['jobItem']);
    if ($form_state['jobItem']->state == OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidationRequired) {
      foreach ($removed_validators as $removed_validator) {
        // CW-1766: Notify the current content validator that is no longer required to do anything
        if ($removed_validator->next) {
            OshaWorkflowNotifications::notifyTranslationValidatorsRemoved($removed_validator, $form_state['jobItem']);
        }
      }
    }
    ksort($validators);
    $idx = 0;
    $validators_name = array();
    foreach ($validators as $validator) {
      $next = 0;
      if ($idx == 0) {
        $next = 1;
        // if current state is translation validation required, notify the new "current" (if different)
        if ($form_state['jobItem']->state == OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidationRequired && $old_current_validator->uid != $validator['uid']) {
          $current_user = user_load($validator['uid']);
          OshaWorkflowNotifications::sendEmail($current_user, array('tmgmt_job_item' => $form_state['jobItem']), 'osha_tmgmt');
        }
      }
      $idx++;
      $validators_name[] = $form_state['rows'][$validator['uid']]->name;
      osha_tmgmt_add_translation_validator($validator['uid'], $form_state['jobItem'], $validator['weight'], $next);
    }

    // Save message to job item.
    global $user;
    $form_state['jobItem']->addMessage('@name assigned content validators: @validators',
      array(
        '@name' => $user->name,
        '@validators' => implode(', ', $validators_name),
      )
    );
  }
}

/**
 * Validate callback for accept translation for Content Validator.
 */
function osha_tmgmt_translation_validators_accept_validate($form, &$form_state) {
  $result = OshaTMGMTRetranslate::validate_translation_structure($form_state['item']);
  if ($result) {
    form_set_error('actions][cvalidator_approve', $result);
  }
}

/**
 * Callback for accept translation for Content Validator.
 */
function osha_tmgmt_translation_validators_accept($form, &$form_state) {
  $job_item = $form_state['item'];
  $message = $form_state['values']['action_message'];
  $validators = osha_tmgmt_load_validators_by_job_item($job_item);
  global $user;
  while ($validator = each($validators)) {
    if ($validator[1]->uid == $user->uid) {
      $validator[1]->message = $message;
      $validator[1]->approved = OSHA_TMGMT_CONTENT_VALIDATOR_STATUS_APPROVED;
      $validator[1]->next = 0;
      entity_save('translation_validator', $validator[1]);
      drupal_set_message(t('You have validated this translation.'));
      if ($next_validator = current($validators)) {
        $next_validator->next = 1;
        entity_save('translation_validator', $next_validator);
        drupal_set_message(
          t(
            '@name is the next one to validate',
            array('@name' => $next_validator->name)
          )
        );

        // Save log message (no job item state change required).
        $log_entry = sprintf('%s validated the translation. Next to validate is %s', $user->name, $next_validator->name);
        if (!empty($message)) {
          $log_entry .= ' Messsage: ' . $message;
        }
        $job_item->addMessage($log_entry);
        // Notify next approval.
        OshaWorkflowNotifications::notifyTranslationValidators($job_item);
      }
      else {
        // Last Validator.
        $log_entry = sprintf('%s validated the translation.', $user->name);
        if (!empty($message)) {
          $log_entry .= ' Messsage: ' . $message;
        }
        $job_item->addMessage($log_entry);
        $job_item->toTranslationValidated();
        // This notification is already sent in $job_item->toTranslationValidated().
        // OshaWorkflowNotifications::notifyTranslationValidated($job_item);
      }
      break;
    }
  }
}

/**
 * Callback for reject translation for Content Validator.
 */
function osha_tmgmt_job_item_translation_reject($form, &$form_state) {
  global $user;
  $job_item = $form_state['item'];
  if ($job_item->state == OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidationRequired) {
    $validators = osha_tmgmt_load_validators_by_job_item($job_item);
    $last = end($validators);
    if ($user->uid == $last->uid && $last->next == 1) {
      $last->message = $form_state['values']['action_message'];
      $last->approved = OSHA_TMGMT_TRANS_VALID_REJECTED;
      $last->next = 0;
      entity_save('translation_validator', $last);
      OshaWorkflowNotifications::notifyTranslationRejected($job_item);
    }
  }
  $log_entry = '';
  if (!empty($form_state['values']['action_message'])) {
    $log_entry = ' Messsage: ' . $form_state['values']['action_message'];
  }
  $job_item->toTranslationRejected($log_entry);
}

/**
 * Validation Callback for Approve Layout button.
 */
function osha_tmgmt_layout_validator_approve_validate($form, &$form_state) {
  $result = OshaTMGMTRetranslate::validate_translation_structure($form_state['item']);
  if ($result) {
    form_set_error('actions][accept_layout', $result);
  }
}

/**
 * Validation Callback for Request Content Validation button.
 */
function osha_tmgmt_require_content_validation_validate($form, &$form_state) {
  $validators = osha_tmgmt_load_validators_by_job_item($form_state['item']);
  if (empty($validators)) {
    form_set_error('actions][require_content_validation', t('There are no Content Validators assigned to this job item!'));
  }
  $result = OshaTMGMTRetranslate::validate_translation_structure($form_state['item']);
  if ($result) {
    form_set_error('actions][require_content_validation', $result);
  }
}

/**
 * Submit callback for  Request Content Validation button.
 */
function osha_tmgmt_require_content_validation_submit($form, &$form_state) {
  $job_item = $form_state['item'];
  $message = '';
  if (!empty($form_state['values']['action_message'])) {
    $message = $form_state['values']['action_message'];
  }
  $job_item->toTranslationValidationRequired($message);
}

/**
 * Validation callback for Ready to publish form.
 */
function osha_tmgmt_ready_to_publish_validate($form, &$form_state) {
  if (!user_access('set job item to ready to publish state')) {
    form_set_error('actions][ready_to_publish', t('You do not have the rights to make this action'));
  }
  $result = OshaTMGMTRetranslate::validate_translation_structure($form_state['item']);
  if ($result) {
    form_set_error('actions][ready_to_publish', $result);
  }
}

/**
 * Callback for Ready to Publish button.
 */
function osha_tmgmt_ready_to_publish_submit($form, &$form_state) {
  $job_item = $form_state['item'];
  $message = '';
  if (!empty($form_state['values']['action_message'])) {
    $message = $form_state['values']['action_message'];
  }
  $job_item->toTranslationReadyToPublish($message);
}

/**
 * Validation Callback for Save as Completed action.
 */
function osha_tmgmt_job_item_accept_validate($form, &$form_state) {
  if (!user_access('accept job item translation')) {
    form_set_error('actions][accept', t('You do not have the rights to make this action'));
  }
}

/**
 * Callback for Save as Cpmpleted button.
 */
function osha_tmgmt_job_item_accept_submit($form, &$form_state) {
  $job_item = $form_state['item'];
  $message = '';
  if (!empty($form_state['values']['action_message'])) {
    $message = $form_state['values']['action_message'];
  }
  $job_item->acceptTranslationIntoEntity($message);
  if ($job_item->isAccepted()) {
    $uri = $job_item->uri();
    $form_state['redirect'] = $uri['path'];
  }
}

/**
 * Callback for Enable Translation
 */
function osha_tmgmt_job_item_translation_enable($form, &$form_state) {
  $job_item = $form_state['item'];
  $message = '';
  if (!empty($form_state['values']['action_message'])) {
    $message = $form_state['values']['action_message'];
  }
  $job_item->toOnTranslation($message);
}

/**
 * Update hwc external links language.
 */
function osha_tmgtm_update_external_links(&$data, $items) {
  $url = 'healthy-workplaces.eu/';
  foreach ($data as $nid => $fields) {
    $lang = $items[$nid]->target_language;
    foreach ($fields as $field => $values) {
      foreach ($values as $i => $value) {
        if (!is_array($value) || empty($value['value'])) {
          continue;
        }
        $old_text = $value['value']['#text'];
        $new_text = str_replace($url . 'en/', $url . $lang . '/', $old_text);
        $data[$nid][$field][$i]['value']['#text'] = $new_text;
      }
    }
  }
}

/**
 * Extra callback for Uploading XML file on a job.
 */
function osha_tmgmt_file_translation_upload_submit($form, &$form_state) {
  // Ensure we have the file uploaded.
  $job = $form_state['tmgmt_job'];
  $supported_formats = array_keys(tmgmt_file_format_plugin_info());
  if ($file = file_save_upload('file', array('file_validate_extensions' => array(implode(' ', $supported_formats))))) {
    $extension = pathinfo($file->uri, PATHINFO_EXTENSION);
    $controller = tmgmt_file_format_controller($extension);
    if ($controller) {
      // Validate the file.
      $validated_job = $controller->validateImport($file->uri);
      if (!$validated_job) {
        $job->addMessage('Failed to validate file, import aborted.', array(), 'error');
      }
      elseif ($validated_job->tjid != $job->tjid) {
        $uri = $validated_job->uri();
        $label = $validated_job->label();
        $job->addMessage('Import file is from job <a href="@url">@label</a>, import aborted.', array('@url' => url($uri['path']), '@label' => $label), 'error');
      }
      else {
        try {
          // Validation successful, start import.
          $data = $controller->import($file->uri);
          $items = $job->getItems();
          osha_tmgtm_update_external_links($data, $items);
          $job->addTranslatedData($data);
          $job->addMessage('Successfully imported file.'.$file->uri);
          OshaWorkflowNotifications::notifyTranslationUploadedFile($form_state['tmgmt_job']);
          $job->has_file_uploaded = 1;
          $job->save();

          // CW-1299, MC-20
          // Except nodes and menu_links, the others should be directly published.
          foreach($job->getItems() as $job_item) {
            if (!in_array($job_item->item_type, array('menu_link', 'node'))) {
              $job_item->acceptTranslationIntoEntity();
          }
          }
        } catch (Exception $e) {
          $job->addMessage('File import failed with the following message: @message', array('@message' => $e->getMessage()), 'error');
        }
      }
    }
    // Remove the XML after upload.
    file_delete($file);
  }
  foreach ($job->getMessagesSince() as $message) {
    // Ignore debug messages.
    if ($message->type == 'debug') {
      continue;
    }
    if ($text = $message->getMessage()) {
      drupal_set_message(filter_xss($text), $message->type);
    }
  }
}

  /**
   * Themes the workflow_moderation_form form.
   *
   * @param array $variables
   *   Form variables
   *
   * @return string
   *   Form HTML
   */
function theme_osha_tmgmt_job_item_validators_form_table($variables) {
  $output = '';
  $form = $variables['form'];
  $rows = array();
  if (!empty($form['rows'])) {
    $items = element_children($form['rows']);
    reset($items);
    foreach ($items as $uid) {
      $moderator = $form['rows'][$uid]['#row'];
      $status = '';
      if (!empty($moderator->approved)) {
        $status = '<strong>' . $moderator->approved . '</strong>';
        if (!empty($moderator->message)) {
          $status .= '<p>' . $moderator->message . '</p>';
        }
      }
      $row = array();
      $name = check_plain($moderator->name);
      if (empty($moderator->osha_tmgmt_validators_saved)) {
        $name .= '<sup>**</sup>';
      }
      $row[] = $name;
      $row[] = check_plain($moderator->mail);
      $row[] = $status;
      $row[] = drupal_render($form['rows'][$uid]['remove']);
      $row[] = drupal_render($form['rows'][$uid]['weight']);
      $rows[] = array('data' => $row, 'class' => array('draggable'));
    }
  }
  $row = array(
    drupal_render($form['add']['uid']),
    drupal_render($form['add']['submit']),
    '',
    '',
    '',
  );
  $rows[] = $row;
  $caption = t('List of approvers');

  $header = array(
    t('User'),
    t('Mail'),
    t('Status'),
    '',
  );
  if ($form['#can_edit']) {
    array_push($header, t('Order of notification'));
  }
  $table = array(
    '#theme' => 'table',
    '#caption' => $caption,
    '#header' => $header,
    '#attributes' => array(
      'id' => 'approvers_table',
    ),
    '#rows' => $rows,
  );
  if (isset($form['moderation'])) {
    $output .= drupal_render($form['moderation']);
  }
  $output .= drupal_render($table);
  $output .= drupal_render_children($form);
  if ($form['#can_edit']) {
    drupal_add_tabledrag('approvers_table', 'order', 'sibling', 'user-weight');
  }
  return $output;
}


function theme_osha_tmgmt_ui_translator_review_form($variables) {
  $element = $variables['element'];
  $result = '';
  $labels = '';
  $parent_label = '';
  $element_groups = array();
  $element_group = '';
  foreach (element_children($element) as $key) {
    // Label of all element groups.
    $parent_label = array_shift($element[$key]['#parent_label']);
    $element[$key]['#top_label'] = $parent_label;
    $element[$key]['#leave_label'] = array_pop($element[$key]['#parent_label']);
    // Start a new element group.
    if ($labels != $element[$key]['#parent_label']) {
      $labels = $element[$key]['#parent_label'];
      if (!empty($labels)) {
        // Append to previous group to the group collection.
        if (!empty($element_group)) {
          // commented this because it creates duplicate rows for multiple value fields like field_publication_related_res
          //$element_groups[] = '<tbody>' . $element_group . '</tbody>';
        }
      }
    }
    $element[$key]['#theme'] = 'osha_tmgmt_ui_translator_review_form_element';
    $element_group .= drupal_render($element[$key]);
  }

  // Append the last group to the group collection.
  $element_groups[] = '<tbody>' . $element_group . '</tbody>';

  // Display the label of all element groups inside a table header.
  if (!empty($parent_label)) {
    $cell = array(
      'data' => $parent_label,
      'colspan' => 4,
    );
    $result = '<thead><tr>' . _theme_table_cell($cell, TRUE) . '</tr></thead>' . implode('', $element_groups);
  }
  $table = '<table class="tmgmt-ui-review"><colgroup width="100" /><colgroup width="*" span="2" /><colgroup width="100" />' . $result . '</table>';
  return '<div id="' . $element['#ajaxid'] . '">' . $table . '</div>';
}

function theme_osha_tmgmt_ui_translator_review_form_element($variables) {
  $element = $variables['element'];
  // Label of all element groups.
  if (!isset($element['#top_label'])) {
    $element['#top_label'] = array_shift($element['#parent_label']);
  }
  // Label of the current data item.
  if (!isset($element['#leave_label'])) {
    $element['#leave_label'] = array_pop($element['#parent_label']);
  }
  // Do not repeat labels inside the same hierarchy.
  if ($element['#top_label'] == $element['#leave_label']) {
    $element['#leave_label'] = '';
  }
  $result = '<tr' . drupal_attributes(array('class' => $element['#zebra'])) . '>';
  $row = array();
  $row[] = array(
    'data' => '&nbsp;',
    'class' => 'tmgmt-ui-data-item-label',
  );
  $row[] = array(
    'data' => drupal_render($element['source']),
    'class' => 'tmgmt-ui-data-item-source',
  );
  $row[] = array(
    'data' => drupal_render($element['translation']),
    'class' => 'tmgmt-ui-data-item-translation',
  );
  $row[] = array(
    'data' => drupal_render($element['actions']),
    'class' => 'tmgmt-ui-data-item-actions',
  );
  foreach ($row as $cell) {
    $result .= _theme_table_cell($cell);
  }
  $result .= '</tr>';

  if (!empty($element['below'])) {
    $result .= '<tr' . drupal_attributes(array('class' => $element['#zebra'])) . '>';
    $result .= _theme_table_cell(array(
      'data' => drupal_render($element['below']),
      'colspan' => '4',
    ));
    $result .= '</tr>';
  }
  return $result;
}
