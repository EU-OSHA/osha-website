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
$node = $row->_entity_properties['entity object'];
$date = $node->field_start_date[LANGUAGE_NONE][0];
$country_code = strtolower($node->field_country_code[LANGUAGE_NONE][0]['value']);
$nid = '';
if ($row) {
  $nid = $row->entity;
}
if ($date) {
  $date_object = new DateObject($date['value'], new DateTimeZone($date['timezone_db']));
  $date_object->setTimezone(new DateTimeZone($date['timezone']));
  $start_date = date_format_date($date_object, 'custom', 'm/d/Y H:i:s');
  $date_object = new DateObject($date['value2'], new DateTimeZone($date['timezone_db']));
  $date_object->setTimezone(new DateTimeZone($date['timezone']));
  $end_date = date_format_date($date_object, 'custom', 'm/d/Y H:i:s');
  if ($start_date == $end_date) {
    $end_date = '';
  }
}
if ($node->field_show_eu_flag && $node->field_show_eu_flag['und'][0]['value']) {
  $country_code = 'eu';
}

?>
<div class="box-events-summary">
  <div class="left-column">
    <div class="event_country code_<?php print $country_code; ?>"> </div>
  </div>
  <div class="right-column">
    <span class="publication-date"><?php print $fields['field_start_date_1']->content; ?></span>
    <span class="event-country"><?php print $fields['field_city']->content; ?>, <?php print $fields['field_country_code']->content; ?></span>
    <h2><?php print strip_tags($fields['title_field']->content, '<a>'); ?></h2>
    <p class="summary"><?php print $fields['body']->content; ?></p>
    <?php print l(t('See more'), '/node/' . $nid, array(
      'attributes' => array('class' => ['see-more-arrow']),
    ));
    ?>
    <?php if ($end_date) {
        $description = strip_tags($fields['body']->content);
        $description = str_replace("'", "", $description);
        ?>
      <span class="add-to-my-calendar" id="add-to-calendar-<?php print $nid; ?>" href="#"></span>
      <script>
          var myCalendar<?php print $nid; ?> = createCalendar({
              options: {
              },
              data: {
                  title: '<?php print strip_tags($fields['title_field']->content); ?>',
                  start: new Date('<?php print $start_date; ?>'),
                  end: new Date('<?php print $end_date; ?>'),
                  description: '<?php print $description; ?>'
              }
          });
          document.querySelector('#add-to-calendar-<?php print $nid; ?>').appendChild(myCalendar<?php print $nid; ?>);
      </script>
    <?php } ?>
  </div>
</div>
