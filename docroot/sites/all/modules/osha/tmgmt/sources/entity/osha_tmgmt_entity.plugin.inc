<?php

class OSHATMGMTEntitySourcePluginController extends TMGMTEntitySourcePluginController {
  /**
   * Overwrite parent function to set the language from job item not job id.
   */
  public function saveTranslation(TMGMTJobItem $job_item) {
    $entity = entity_load_single($job_item->item_type, $job_item->item_id);
    $job = tmgmt_job_load($job_item->tjid);

    tmgmt_field_populate_entity($job_item->item_type, $entity, $job_item->target_language, $job_item->getData());

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
