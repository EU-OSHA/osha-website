<?php

/**
 * @file
 * Feeds mapping implementation for the Flickr module.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see FeedsNodeProcessor::getMappingTargets()
 */
function flickrfield_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {

  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);

    if (in_array($info['type'], array('flickrfield'))) {
      foreach ($info['columns'] as $id => $column) {

        $targets[$name . ':' . $id] = array(
          'name'        => check_plain($instance['label'] . ' ' . t('(@id)', array('@id' => $id))),
          'callback'    => 'flickrfield_feeds_set_target',
          'description' => t('The field instance @label  -column @id.', array(
            '@label' => $instance['label'],
            '@id'    => $id,
          )),
        );
      }
    }
  }
}

/**
 * Callback for mapping.
 *
 * When the callback is invoked, $target contains the name of the field the
 * user has decided to map to and $value contains the value of the feed item
 * element the user has picked as a source.
 *
 * @param $source
 *   A FeedsSource object.
 * @param $entity
 *   The entity to map to.
 * @param $target
 *   The target key on $entity to map to.
 * @param $value
 *   The value to map. MUST be an array.
 */
function flickrfield_feeds_set_target($source, $entity, $target, $value) {

  // Don't do anything if we weren't given any data.
  if (empty($value)) {
    return;
  }

  // Assume that the passed in value could really be any number of values.
  $value = is_array($value) ? $value : array($value);

  // Set the language of the field depending on the mapping.
  $language = isset($mapping['language']) ? $mapping['language'] : LANGUAGE_NONE;

  // Determine the field we are matching against.
  list($target, $match_key) = explode(':', $target, 2);

  // Get some useful field information.
  $info = field_info_field($target);

  // Iterate over all values.
  $i = 0;
  $field = isset($entity->$target) ? $entity->$target : array();
  foreach ($value as $val) {
    // Add the value to the entity field.
    $field[$language][$i][$match_key] = $val;
    // Break out of the loop if this field is single-valued.
    if ($info['cardinality'] == 1) {
      break;
    }
    $i++;
  }

  // Add the field to the entity definition.
  $entity->{$target} = $field;
}
