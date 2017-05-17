<?php

class OSHATMGMTEntitySourcePluginController extends TMGMTEntitySourcePluginController {

  /**
   * {@inheritdoc}
   *
   * Returns the data from the fields as a structure that can be processed by
   * the Translation Management system.
   */
  public function getData(TMGMTJobItem $job_item) {
    if (!isset($job_item->target_language)) {
      return FALSE;
    }
    if ($job_item->item_type == 'node') {
      $entity = node_load($job_item->item_id);
      $entity = workbench_moderation_node_current_load($entity);
    }
    else {
      $entity = entity_load_single($job_item->item_type, $job_item->item_id);
    }
    if (!$entity) {
      throw new TMGMTException(t('Unable to load entity %type with id %id', array('%type' => $job_item->item_type, $job_item->item_id)));
    }
    return osha_tmgmt_field_get_source_data($job_item, $entity, TRUE);
  }

  /**
   * Overwrite parent function to set the language from job item not job id.
   */
  public function saveTranslation(TMGMTJobItem $job_item) {
    $entity = entity_load_single($job_item->item_type, $job_item->item_id);
    if ($job_item->item_type == 'node') {
      // load the latest revision
      $entity = workbench_moderation_node_current_load($entity);
      // apply re-translation
      $new_job_data = OshaTMGMTRetranslate::apply_partial_translation(
        $entity, $job_item->getData(), $job_item->source_language, $job_item->target_language);
      self::osha_tmgmt_field_populate_entity($job_item->item_type, $entity, $job_item->target_language, $new_job_data);
      //$entity->field_needs_retranslation[LANGUAGE_NONE][0]['value'] = 0;
    } else {
      $data = $job_item->getData();
      if ($this->valid_translation($data)) {
        self::osha_tmgmt_field_populate_entity($job_item->item_type, $entity, $job_item->target_language, $data);
      }
      else {

        // Do not accept an invalid translation
        return;
      }
    }

    // Change the active language of the entity to the target language.
    $handler = entity_translation_get_handler($job_item->item_type, $entity);
    $handler->setFormLanguage($job_item->target_language);

    if ( $job_item->item_type == 'node' && workbench_moderation_node_type_moderated($entity->type) ) {
      // Force the same state in order to avoid creation of new weird transitions.
      $entity->workbench_moderation_state_new = $entity->workbench_moderation['current']->state;
      $entity->workbench_moderation_state_new = OSHA_WORKFLOW_STATE_READY_TO_PUBLISH;
      // Create a new revision to prevent unpublishing the published version if we translate a draft.
      $entity->revision = TRUE;
    }
    // Unset the pid so that the alias is created for current language.
    if (!empty($entity->path['pid'])) {
      unset($entity->path['pid']);
    }
    entity_save($job_item->item_type, $entity);
    $translation = array(
      // @todo Improve hardcoded values.
      'translate' => 0,
      'status' => TRUE,
      'language' => $job_item->target_language,
      'source' => $job_item->source_language,
    );
    $handler->setTranslation($translation);
    $handler->saveTranslations();
    // save() to set new job item state, otherwise job is not properly closed
    // when this job item is the latest one accepted.
    $job_item->save();
    $job_item->accepted();
  }

  /**
   * Populate entity fields with translated data coming from translation (XML).
   * Overriden in order to provide support for metatags.
   *
   * @param string $entity_type
   *   Entity type like node, menu_link etc.
   * @param object $entity
   *   Actual entity
   * @param string $langcode
   *   Target language - translation language for $data
   * @param $data
   *   Translation data
   * @param bool $use_field_translation
   *   TRUE if field translation is being used.
   * @throws EntityMalformedException
   * @see tmgmt_field_populate_entity
   */
  public static function osha_tmgmt_field_populate_entity($entity_type, $entity, $langcode, $data, $use_field_translation = TRUE) {
    tmgmt_field_populate_entity($entity_type, $entity, $langcode, $data, $use_field_translation);
    foreach(element_children($data) as $field_name) {
      if ($field_name == 'metatags') {
        $metatags = array();
        foreach (element_children($data[$field_name]) as $delta) {
          $translation = $data[$field_name][$delta];
          if (!empty($translation['value']['#translation']['#text'])) {
            $metatags[$delta]['value'] = $translation['value']['#translation']['#text'];
          }
        }
        $entity->{$field_name}[$langcode] = $metatags;
      }
    }
  }

  /**
   * @return boolean
   *   Returns TRUE if there was a non-empty translation sent and we have received a non-empty translation.
   * Required to detect a partial import (import of a single language in a multi-language job).
   */
  public static function valid_translation($data) {
    foreach(element_children($data) as $field_name) {
      foreach (element_children($data[$field_name]) as $delta) {
        foreach (element_children($data[$field_name][$delta]) as $column) {
          $translation = $data[$field_name][$delta][$column];
          if ($translation['#translate'] == TRUE
              && empty($translation['#translation']['#text']) && !empty($translation['#text'])) {
            // There was a translation #text sent, but returned empty (i.e. loading a single language).
            return FALSE;
          }
        }
      }
    }
    return TRUE;
  }
}

/**
 * Helper function for retrieving all translatable field values from an entity.
 *
 * @see tmgmt_field_get_source_data
 */
function osha_tmgmt_field_get_source_data($job_item, $entity, $only_translatable = FALSE) {

  $entity_type = $job_item->item_type;
  $langcode = $job_item->source_language;
  try {
    list(, , $bundle) = entity_extract_ids($entity_type, $entity);
  }
  catch (Exception $e) {
    watchdog_exception('tmgmt field', $e);
    return array();
  }

  $fields = array();
  // Static reset because it returns LANGUAGE_NONE for field_author because of a previous call
  drupal_static_reset('field_language');
  foreach (field_info_instances($entity_type, $bundle) as $field_name => $instance) {
    $field = field_info_field($field_name);
    $items = field_get_items($entity_type, $entity, $field_name, $langcode);
    if ((!$only_translatable || $field['translatable']) && $items) {
      if ($data = module_invoke('osha_tmgmt', 'tmgmt_source_translation_structure', $job_item, $entity, $field, $instance, $items)) {
        $fields[$field_name] = $data;
      }

    }
  }
  // Add node metatags to the translation job.
  if (isset($entity->metatags['en'])) {
    $configs = ctools_export_crud_load_all('metatag_config');
    $global = $configs['global'];

    $meta = $entity->metatags['en'];
    $data_metatags = array();
    $translatable = array('title', 'description', 'abstract', 'rights');
    foreach ($translatable as $metatag) {
      if (!empty($meta[$metatag]['value'])) {
        $default_value = $global->config[$metatag]['value'];
        if ($meta[$metatag]['value'] != $default_value) {
          $info = metatag_get_info('tags', 'title');
          $description = $info['label'];
          $data_metatags[$metatag] = array(
            '#label' => 'DELTA #0',
            'value' => array(
              '#label' => $description,
              '#text' => $meta[$metatag]['value'],
              '#translate' => TRUE,
            ),
          );
        }
      }
    }
    if (!empty($data_metatags)) {
      $data_metatags['format'] = array(
        '#label' => '',
        '#text' => 'plain_text',
        '#translate' => FALSE,
      );
      $data_metatags['#label'] = 'Metatags';
      $fields['metatags'] = $data_metatags;
    }
  }
  return $fields;
}
