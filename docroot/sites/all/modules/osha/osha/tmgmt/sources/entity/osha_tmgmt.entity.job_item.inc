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
        // There are no unfinished elements left.
        if ($this->getJob()->getTranslator()->getSetting('auto_accept')) {
          // If the job item is going to be auto-accepted, set to review without
          // a message.
          $this->needsReview(FALSE);
        }
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
    $this->addMessage('@name approved the Layout. Job item is now "@state". Message: @message',
    array(
      '@name' => $user->name,
      '@state' => osha_tmgmt_get_job_item_state_label(TMGMT_JOB_ITEM_STATE_REVIEW),
      '@message' => $message,
    ));
    OshaWorkflowNotifications::notifyTranslationLayoutApproved($this);
    drupal_set_message(t('You have Approved the Layout'));
  }

  /**
   * Move the Job Item to Translation Validated state.
   */
  public function toTranslationValidated($message = '') {
    $this->state = OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidated;
    global $user;
    $this->save();
    $this->addMessage('@name validated translation content. Job item is now "@state". Message: @message',
      array(
        '@name' => $user->name,
        '@state' => osha_tmgmt_get_job_item_state_label(OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidated),
        '@message' => $message,
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
    $this->addMessage('@name: Translation requires Content Validation. Job item is now "@state". Message: @message',
      array(
        '@name' => $user->name,
        '@state' => osha_tmgmt_get_job_item_state_label(OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidationRequired),
        '@message' => $message,
      ));
    OshaWorkflowNotifications::notifyTranslationValidators($this);
    drupal_set_message(t('You have Required Translation Validation for this translation'));
  }

  /**
   * Move the Job Item to Translation Validation Required state.
   */
  public function toTranslationRejected($message = '') {
    $this->state = TMGMT_JOB_ITEM_STATE_ABORTED;
    $this->setTranslationDataStatusPendingRecursive($this->data);
    global $user;
    $this->save();
    $this->addMessage('@name: Translation Rejected. Job item is now "@state". Message: @message',
      array(
        '@name' => $user->name,
        '@state' => osha_tmgmt_get_job_item_state_label(OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidationRequired),
        '@message' => $message,
      ));
    OshaWorkflowNotifications::notifyTranslationValidators($this);
    drupal_set_message(t('You have Rejected this translation'));
  }


  private function setTranslationDataStatusPendingRecursive($translation, $key = array()) {
    if (isset($translation['#text']) && isset($translation['#status'])) {
      $values = array(
        '#translation' => $translation,
        '#status' => TMGMT_DATA_ITEM_STATE_PENDING,
      );
      $this->updateData($key, $values);
    }
    foreach (element_children($translation) as $item) {
      $this->setTranslationDataStatusPendingRecursive($translation[$item], array_merge($key, array($item)));
    }
  }

  /**
   * Move the Job Item to Translation Validation Required state.
   */
  public function toTranslationReadyToPublish($message = '') {
    $this->state = OSHA_TMGMT_JOB_ITEM_STATE_TranslatedReadyToPublish;
    global $user;
    $this->save();
    $this->addMessage('@name: Translation is ready to be published. Job item is now "@state". Message: @message',
      array(
        '@name' => $user->name,
        '@state' => osha_tmgmt_get_job_item_state_label(OSHA_TMGMT_JOB_ITEM_STATE_TranslatedReadyToPublish),
        '@message' => $message,
      ));
    OshaWorkflowNotifications::notifyTranslationProjectManager($this);
    drupal_set_message(t('You have set Translation as Ready to Publish.'));
  }

  public function acceptTranslationIntoEntity($message = '') {
    $controller = $this->getSourceController();
    $controller->saveTranslation($this);

    global $user;
    $this->addMessage('@name: Translation is now accepted and saved to node. Job item is now "@state". Message: @message',
      array(
        '@name' => $user->name,
        '@state' => osha_tmgmt_get_job_item_state_label(TMGMT_JOB_ITEM_STATE_ACCEPTED),
        '@message' => $message,
      ));
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
          $this->addMessage('Translation for customized @key received. Revert your changes if you wish to use it.', array('@key' => tmgmt_ensure_keys_string($key)));
          // Unset text and origin so that the current translation does not
          // get overridden.
          unset($translation['#text'], $translation['#origin'], $translation['#timestamp']);
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
