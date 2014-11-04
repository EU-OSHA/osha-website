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
    $job = tmgmt_job_load($job_item->tjid);

    if ($job_item->item_type == 'node') {
      // load the latest revision
      $entity = workbench_moderation_node_current_load($entity);
      // apply re-translation
      $new_job_data = OshaTMGMTRetranslate::apply_partial_translation(
        $entity, $job_item->getData(), $job_item->source_language, $job_item->target_language);
      tmgmt_field_populate_entity($job_item->item_type, $entity, $job_item->target_language, $new_job_data);
      $entity->field_needs_retranslation[LANGUAGE_NONE][0]['value'] = 0;
    } else {
      tmgmt_field_populate_entity($job_item->item_type, $entity, $job_item->target_language, $job_item->getData());
    }

    // Change the active language of the entity to the target language.
    $handler = entity_translation_get_handler($job_item->item_type, $entity);
    $handler->setFormLanguage($job_item->target_language);

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
    $job_item->accepted();
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
  foreach (field_info_instances($entity_type, $bundle) as $field_name => $instance) {
    $field = field_info_field($field_name);
    $items = field_get_items($entity_type, $entity, $field_name, $langcode);
    if ((!$only_translatable || $field['translatable']) && $items) {
      if ($data = module_invoke('osha_tmgmt', 'tmgmt_source_translation_structure', $job_item, $entity, $field, $instance, $items)) {
        $fields[$field_name] = $data;
      }

    }
  }
  return $fields;
}
