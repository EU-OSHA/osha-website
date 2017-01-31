<?php

class OshaTMGMTJobItem extends TMGMTJobItem {

  /**
   * {@inheritdoc}
   */
  public function addTranslatedData($translation, $key = array()) {
    if ($this->item_type != 'node') {
      $this->addTranslatedDataToNonNodes($translation, $key);
      return;
    }
    $this->addTranslatedDataRecursive($translation, $key);
    // There are no unfinished elements left.
    if ($this->getJob()->getTranslator()->getSetting('auto_accept')) {
      // If the job item is going to be auto-accepted, set to review without
      // a message.
      $this->needsReview(FALSE);
    }
    $this->save();
  }

  /**
   * Executes for entities that are not nodes.
   */
  public function addTranslatedDataToNonNodes($translation, $key = array()) {
    $this->addTranslatedDataRecursive($translation, $key);
    // Check if the job item has all the translated data that it needs now.
    // Only attempt to change the status to needs review if it is currently
    // active.
    if ($this->isActive()) {
      $data = tmgmt_flatten_data($this->getData());
      $data = array_filter($data, '_tmgmt_filter_data');
      $finished = TRUE;
      foreach ($data as $item) {
        if (empty($item['#status']) || $item['#status'] == TMGMT_DATA_ITEM_STATE_PENDING) {
          $finished = FALSE;
          break;
        }
      }
      if ($finished) {
        $uri = $this->getSourceUri();
        $this->needsReview(t(
          '!source translation for !entity was imported',
          array(
            '!source' => locale_language_name($this->target_language), '!entity' => l($this->getSourceLabel(), $uri['path']))
          )
        );
      }
    }
    $this->save();
  }

  /**
   * Move the Job Item to Translated state.
   */
  public function toTranslated($message = '') {
    $this->state = TMGMT_JOB_ITEM_STATE_REVIEW;
    global $user;
    $this->save();
    $this->addMessage('@name approved the layout'.
        ' for job item @tjiid, item @item_id (@bundle), language @lang. '.
        'Status is now "@state". Message: @message',
      array(
        '@name' => $user->name,
        '@state' => osha_tmgmt_get_job_item_state_label(TMGMT_JOB_ITEM_STATE_REVIEW),
        '@message' => $message,
        '@tjiid' => $this->tjiid,
        '@item_id' => $this->item_id,
        '@bundle' => $this->item_type,
        '@lang' => strtoupper($this->target_language),
      ));
    OshaWorkflowNotifications::notifyTranslationLayoutApproved($this);
    drupal_set_message(t('You have approved the layout'));
  }

  /**
   * Move the Job Item to On Translation state.
   *
   * When re-enabled the translation by t manager.
   */
  public function toOnTranslation($message = '') {
    // Reset validators.
    $validators = osha_tmgmt_load_validators_by_job_item($this);
    if (!empty($validators)) {
      $index = 0;
      foreach ($validators as $validator) {
        $validator->message = '';
        $validator->approved = NULL;
        $validator->next = 0;
        if ($index == 0) {
          $validator->next = 1;
        }
        entity_save('translation_validator', $validator);
        $index++;
      }
    }
    $this->state = TMGMT_JOB_ITEM_STATE_ACTIVE;
    // Save job.
    global $user;
    $this->save();
    $this->addMessage('@name re-enabled the translation'.
        ' for job item @tjiid, item @item_id (@bundle), language @lang. '.
        'Status is now "@state". Message: @message',
      array(
        '@name' => $user->name,
        '@state' => osha_tmgmt_get_job_item_state_label(TMGMT_JOB_ITEM_STATE_ACTIVE),
        '@message' => $message,
        '@tjiid' => $this->tjiid,
        '@item_id' => $this->item_id,
        '@bundle' => $this->item_type,
        '@lang' => strtoupper($this->target_language),
      ));
    OshaWorkflowNotifications::notifyTranslationLayoutApprovers($this);
    drupal_set_message(t('You have Enabled the Translation'));
  }

  /**
   * Move the Job Item to Translation Validated state.
   */
  public function toTranslationValidated($message = '') {
    $this->state = OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidated;
    global $user;
    $this->save();
    $this->addMessage('@name validated translation content'.
        ' for job item @tjiid, item @item_id (@bundle), language @lang. '.
        'Status is now "@state". Message: @message',
      array(
        '@name' => $user->name,
        '@state' => osha_tmgmt_get_job_item_state_label(OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidated),
        '@message' => $message,
        '@tjiid' => $this->tjiid,
        '@item_id' => $this->item_id,
        '@bundle' => $this->item_type,
        '@lang' => strtoupper($this->target_language),
      ));
    OshaWorkflowNotifications::notifyTranslationValidated($this);
    drupal_set_message(t('You have Validated the translation!'));
  }

  /**
   * Move the Job Item to Translation Validation Required state.
   */
  public function toTranslationValidationRequired($message = '') {
    $this->state = OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidationRequired;
    global $user;
    $this->save();
    $this->addMessage('@name: Content validation required'.
        ' for job item @tjiid, item @item_id (@bundle), language @lang. '.
        'Status is now "@state". Message: @message',
      array(
        '@name' => $user->name,
        '@state' => osha_tmgmt_get_job_item_state_label(OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidationRequired),
        '@message' => $message,
        '@tjiid' => $this->tjiid,
        '@item_id' => $this->item_id,
        '@bundle' => $this->item_type,
        '@lang' => strtoupper($this->target_language),
      ));
    OshaWorkflowNotifications::notifyTranslationValidators($this);
    drupal_set_message(t('You have Required Translation Validation for this translation'));
  }

  /**
   * Move the Job Item to Translation Validation Required state.
   */
  public function toTranslationRejected($message = '') {
    $this->state = TMGMT_JOB_ITEM_STATE_ABORTED;
    global $user;
    $this->save();
    $this->addMessage('@name: Translation rejected'.
        ' for job item @tjiid, item @item_id (@bundle), language @lang. '.
        'Status is now "@state". Message: @message',
      array(
        '@name' => $user->name,
        '@state' => osha_tmgmt_get_job_item_state_label(TMGMT_JOB_ITEM_STATE_ABORTED),
        '@message' => $message,
        '@tjiid' => $this->tjiid,
        '@item_id' => $this->item_id,
        '@bundle' => $this->item_type,
        '@lang' => strtoupper($this->target_language),
      ));
    OshaWorkflowNotifications::notifyTranslationRejected($this);
    drupal_set_message(t('You have Rejected this translation'));
  }

  /**
   * Move the Job Item to Translation Ready to Publish state.
   */
  public function toTranslationReadyToPublish($message = '') {
    $this->state = OSHA_TMGMT_JOB_ITEM_STATE_TranslatedReadyToPublish;
    global $user;
    $this->save();
    $this->addMessage('@name: Translation is ready to be published'.
        ' for job item @tjiid, item @item_id (@bundle), language @lang. '.
        'Status is now "@state". Message: @message',
      array(
        '@name' => $user->name,
        '@state' => osha_tmgmt_get_job_item_state_label(OSHA_TMGMT_JOB_ITEM_STATE_TranslatedReadyToPublish),
        '@message' => $message,
        '@tjiid' => $this->tjiid,
        '@item_id' => $this->item_id,
        '@bundle' => $this->item_type,
        '@lang' => strtoupper($this->target_language),
      ));
    OshaWorkflowNotifications::notifyTranslationProjectManager($this);
    drupal_set_message(
      t('You have set Translation as @state.',
        array(
          '@state' => osha_tmgmt_get_job_item_state_label(OSHA_TMGMT_JOB_ITEM_STATE_TranslatedReadyToPublish),
        )
      )
    );
  }

  public function acceptTranslationIntoEntity($message = '') {
    $controller = $this->getSourceController();
    $controller->saveTranslation($this);
    // Mark node translation dirty to have it re-indexed.
    if ($this->item_type == 'node') {
      global $user;
      $state = osha_tmgmt_get_job_item_state_label(TMGMT_JOB_ITEM_STATE_ACCEPTED);
      $this->addMessage('@name accepted the translation'.
          ' for job item @tjiid, item @item_id (@bundle), language @lang. '.
          'Status is now <strong>@state</strong>. @message',
        array('@name' => $user->name, '@state' => $state, '@message' => 'Message: '.$message,
              '@tjiid' => $this->tjiid, '@item_id' => $this->item_id,
              '@bundle' => $this->item_type, '@lang' => strtoupper($this->target_language)
        )
      );
      $item_id = $this->target_language . '_' . $this->item_id;
      OshaWorkflowNotifications::notifyTranslationAccepted($this);
      search_api_track_item_change('search_api_et_node', array($item_id));
    }
    $this->save();
  }

  /**
   * Recursively writes translated data to the data array of a job item.
   *
   * While doing this the #status of each data item is set to
   * TMGMT_DATA_ITEM_STATE_TRANSLATED.
   *
   * @param $translation
   *   Nested array of translated data. Can either be a single text entry, the
   *   whole data structure or parts of it.
   * @param $key
   *   (Optional) Either a flattened key (a 'key1][key2][key3' string) or a nested
   *   one, e.g. array('key1', 'key2', 'key2'). Defaults to an empty array which
   *   means that it will replace the whole translated data array.
   */
  protected function addTranslatedDataRecursive($translation, $key = array()) {
    if ($this->item_type != 'node') {
      parent::addTranslatedDataRecursive($translation, $key);
      return;
    }
    if (isset($translation['#text'])) {
      $data = $this->getData(tmgmt_ensure_keys_array($key));

      // In case the origin is not set consider it to be remote.
      if (!isset($translation['#origin'])) {
        $translation['#origin'] = 'remote';
      }

      // If we already have a translation text and it hasn't changed, don't
      // update anything unless the origin is remote.
      if (!empty($data['#translation']['#text']) && $data['#translation']['#text'] == $translation['#text'] && $translation['#origin'] != 'remote') {
        return;
      }

      // In case the timestamp is not set consider it to be now.
      if (!isset($translation['#timestamp'])) {
        $translation['#timestamp'] = REQUEST_TIME;
      }
      // If we have a translation text and is different from new one create
      // revision.
      if (!empty($data['#translation']['#text']) && $data['#translation']['#text'] != $translation['#text']) {

        // Copy into $translation existing revisions.
        if (!empty($data['#translation']['#text_revisions'])) {
          $translation['#text_revisions'] = $data['#translation']['#text_revisions'];
        }

        // If current translation was created locally and the incoming one is
        // remote, do not override the local, just create a new revision.
        if (isset($data['#translation']['#origin']) && $data['#translation']['#origin'] == 'local' && $translation['#origin'] == 'remote') {
          $translation['#text_revisions'][] = array(
            '#text' => $translation['#text'],
            '#origin' => $translation['#origin'],
            '#timestamp' => $translation['#timestamp'],
          );
          // Removed as asked in CW-791.
          /*
          $this->addMessage('Translation for customized @key received. Revert your changes if you wish to use it.', array('@key' => tmgmt_ensure_keys_string($key)));
          // Unset text and origin so that the current translation does not
          // get overridden.
          unset($translation['#text'], $translation['#origin'], $translation['#timestamp']);
          */
        }
        // Do the same if the translation was already reviewed and origin is
        // remote.
        elseif ($translation['#origin'] == 'remote' && !empty($data['#status']) && $data['#status'] == TMGMT_DATA_ITEM_STATE_REVIEWED) {
          $translation['#text_revisions'][] = array(
            '#text' => $translation['#text'],
            '#origin' => $translation['#origin'],
            '#timestamp' => $translation['#timestamp'],
          );
          $this->addMessage('Translation for already reviewed @key received and stored as a new revision. Revert to it if you wish to use it.', array('@key' => tmgmt_ensure_keys_string($key)));
          // Unset text and origin so that the current translation does not
          // get overridden.
          unset($translation['#text'], $translation['#origin'], $translation['#timestamp']);
        }
        else {
          $translation['#text_revisions'][] = array(
            '#text' => $data['#translation']['#text'],
            '#origin' => isset($data['#translation']['#origin']) ? $data['#translation']['#origin'] : 'remote',
            '#timestamp' => isset($data['#translation']['#timestamp']) ? $data['#translation']['#timestamp'] : $this->changed,
          );
          // Add a message if the translation update is from remote.
          if ($translation['#origin'] == 'remote') {
            $diff = drupal_strlen($translation['#text']) - drupal_strlen($data['#translation']['#text']);
            $this->addMessage('Updated translation for key @key, size difference: @diff characters.', array('@key' => tmgmt_ensure_keys_string($key), '@diff' => $diff));
          }
        }
      }

      $values = array(
        '#translation' => $translation,
        '#status' => TMGMT_DATA_ITEM_STATE_TRANSLATED,
      );
      $this->updateData($key, $values);
      return;
    }

    foreach (element_children($translation) as $item) {
      $this->addTranslatedDataRecursive($translation[$item], array_merge($key, array($item)));
    }
  }
}


class OshaTMGMTJobItemMetadataController extends TMGMTJobItemMetadataController {

  /**
   * {@inheritdoc}
   */
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    // Add the options list for the available languages.
    $properties['target_language']['options list'] = $properties['source_language']['options list'] = 'entity_metadata_language_list';

    return $info;
  }
}
