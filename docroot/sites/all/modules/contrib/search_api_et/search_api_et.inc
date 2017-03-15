<?php
/**
 * @file
 * Defines some helper functions for the Search API ET module.
 */

/**
 * Get all enabled language for the site.
 *
 * This reflects the "all site languages" settings when determining which
 * languages that should get indexed.
 *
 * @return array
 *   An array of applicable language codes.
 */
function search_api_et_item_languages_all() {
  return array_keys(search_api_et_languages(TRUE, TRUE));
}


/**
 * Get the languages for an entity.
 *
 * This reflects the "all entity languages" settings when determining which
 * languages that should get indexed.
 *
 * @param object $entity
 *   The entity for which languages should be determined.
 * @param string $entity_type
 *   The entity type of the entity.
 * @return array An array with language codes.
 * An array of applicable language codes.
 */
function search_api_et_item_languages_entity($entity, $entity_type) {
  // Get the translations for this entity, and return the languages.
  $translations = entity_translation_get_handler($entity_type, $entity)->getTranslations();
  return array_keys($translations->data);
}


/**
 * Get the languages that has been fully translated for an entity.
 *
 * This reflects the "completed entity languages" settings when determining
 * which languages that should get indexed.
 *
 * @param object $entity
 *   The entity for which languages should be determined.
 * @param string $entity_type
 *   The entity type of the entity.
 * @return array
 *   An array of applicable language codes.
 */
function search_api_et_item_languages_complete($entity, $entity_type) {
  $return = array();

  // Get the field instances for this entity.
  list(, , $bundle) = entity_extract_ids($entity_type, $entity);
  $field_instances = field_info_instances($entity_type, $bundle);

  // Check the field values for every translation for this entity.
  foreach (search_api_et_item_languages_entity($entity, $entity_type) as $language) {
    foreach ($field_instances as $field_name => $field_instance) {
      $field_info = field_info_field($field_name);

      // If this field isn't translatable, skip to the next field.
      if (!$field_info['translatable']) {
        continue;
      }

      // Optional fields may be left blank, and the translation not stored: for
      // such fields the value of "$entity->{$field_name}[$language]" is empty
      // and we can not rely of such fields to spot a missing translation.
      if ($field_instance['required'] && !isset($entity->{$field_name}[$language])) {
        // There is no language for this required field, skip to the next language.
        continue 2;
      }
    }

    // Every translatable field has been translated for this language, add the
    // language to the return values.
    $return[] = $language;
  }

  // Return the languages that we found.
  return $return;
}


