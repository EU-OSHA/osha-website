<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?><?php
$providers = $row->_entity_properties['entity object']->field_msd_provider;
$original_language = $row->_entity_properties['entity object']->field_original_desc_language['und'][0]['value'];
$names = [];
if ($providers) {
  foreach($providers[LANGUAGE_NONE] as $provider) {
    $entity = field_collection_field_get_entity($provider);
    $name = osha_musculoskeletal_disorders_get_provider_name($original_language, $entity);
    if ($name) {
      $names[] = $name;
    }
  }
}
if ($names) { ?>
  <span class="views-label"><?php echo  t('Provider'); ?></span><span><?php print implode(', ', $names); ?></span>
  <?php
}
// double end div(opened in global custom text).
?>
</div>
</div>
