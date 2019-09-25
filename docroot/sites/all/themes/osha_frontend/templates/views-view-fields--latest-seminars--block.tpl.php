<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
$nid = '';
if ($row) {
  $nid = $row->nid;
}
$country_code = $row->field_field_country_code[0]['raw']['value'];
if ($row->field_field_show_eu_flag[0]['raw']['value']) {
  $country_code = 'eu';
}
?>
<div class="left-column">
  <div class="event_country code_<?php print strtolower($country_code); ?>"> </div>
</div>
<div class="right-column">
  <span class="publication-date"><?php print $fields['field_seminar_start_date']->content; ?></span>
  <span class="event-country"><?php print $fields['field_seminar_location']->content; ?></span>
  <h2><?php print strip_tags($fields['title_field']->content, '<a>'); ?></h2>
  <p class="summary"><?php print $fields['body']->content; ?></p>
  <?php
  print l(t('See more'), 'node/' . $nid, array(
    'attributes' => array('class' => ['see-more-arrow']),
    'external' => TRUE,
  ));
  ?>
  <?php if ($fields['field_pages_count']->content) { ?>
    <a class="report-available" href="<?php print $fields['field_report']->content; ?>"><?php print t('Report available'); ?> (<?php print $fields['field_pages_count']->content; ?>)</a>
  <?php } ?>
</div>
