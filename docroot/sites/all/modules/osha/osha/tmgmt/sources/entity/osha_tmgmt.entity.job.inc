<?php

class OshaTMGMTJob extends TMGMTJob {

  /**
   * {@inheritdoc}
   */
  public function addTranslatedData($data, $key = NULL) {
    $key = tmgmt_ensure_keys_array($key);
    $items = $this->getItems();
    // If there is a key, get the specific item and forward the call.
    if (!empty($key)) {
      $item_id = array_shift($key);
      if (isset($items[$item_id])
          && $this->allowRewriteTranslationData($items[$item_id])) {
        $job_item = $items[$item_id];
        $job_item->addTranslatedData($data, $key);
        if ($job_item->isAborted()) {
          $job_item->toOnTranslation();
        }
      }
    }
    else {
      foreach ($data as $key => $value) {
        if (isset($items[$key])
            && $this->allowRewriteTranslationData($items[$key])) {
          $job_item = $items[$key];
          $job_item->addTranslatedData($value);
          if ($job_item->isAborted()) {
            $job_item->toOnTranslation();
          }
        }
      }
    }
  }

  /**
   * Check if job is in progress.
   */
  public function allowRewriteTranslationData($job_item) {
    if ($job_item->isActive() || $job_item->isAborted()) {
      return TRUE;
    }
    else {
      drupal_set_message(
        t('The translation of @job_item was skipped.',
          array('@job_item' => $job_item->label())));
      return FALSE;
    }
  }

  /**
   * Get the number of job items in a state.
   */
  public function getCountofState($state) {
    return osha_tmgmt_job_statistic_items($this, $state);
  }


  /**
   * Adds an item to the translation job.
   *
   * @param $plugin
   *   The plugin name.
   * @param $item_type
   *   The source item type.
   * @param $item_id
   *   The source item id.
   *
   * @return TMGMTJobItem
   *   The job item that was added to the job or FALSE if it couldn't be saved.
   * @throws TMGMTException
   *   On zero item word count.
   */
  public function addItem($plugin, $item_type, $item_id,
                          $source_language = NULL, $target_language = NULL,
                          $is_full_translation = FALSE,
                          $retranslation_data = NULL) {

    $transaction = db_transaction();
    $is_new = FALSE;

    if (empty($this->tjid)) {
      $this->save();
      $is_new = TRUE;
    }
    $item = tmgmt_job_item_create($plugin, $item_type, $item_id, array('tjid' => $this->tjid));
    if ($item_type == 'node') {
      $item->is_full_translation = $is_full_translation;
      $node = node_load($item_id);
      $current_rev = workbench_moderation_node_current_load($node);
      $item->vid = $current_rev->vid;
      $item->retranslation_data = $retranslation_data;
    }
    $item->source_language = $source_language;
    $item->target_language = $target_language;

    $item->save();

    if ($item->getWordCount() == 0) {
      $transaction->rollback();

      // In case we got word count 0 for the first job item, NULL tjid so that
      // if there is another addItem() call the rolled back job object will get
      // persisted.
      if ($is_new) {
        $this->tjid = NULL;
      }

      throw new TMGMTException('Job item @label (@type) has no translatable content in language @target_lang.',
        array('@label' => $item->label(), '@type' => $item->getSourceType(), '@target_lang' => strtoupper($target_language)));
    }

    return $item;
  }
}
