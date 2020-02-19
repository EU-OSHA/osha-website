<?php
/**
 * @file
 * Returns the HTML for a musculoskeletal-disorders node.
 */
?>
<div class="node-type-dangerous-substances">
    <div class="node-dangerous-substances">

<?php if ($page) { ?>
<!--    <div id="page-title" class="page__title title">--><?php //print t('Musculoskeletal Disorders');?><!--</div>-->
  <div class="view-header back"><?php print l(t('Back to MSDs and filter'), 'themes/musculoskeletal-disorders/search'); ?></div>
<?php } ?>
<?php
if (!empty($content['field_type_of_item'])) {
  $content['field_type_of_item']['#title'] = t('Type');
}
if (!empty($content['body'])) {
  $content['body']['#title'] = t('Description');
}
if (!empty($content['field_body_original'])) {
  $content['field_body_original']['#title'] = t('Description');
}
if ($node->field_original_desc_language && $node->field_original_desc_language['und'][0]['value']) {
  $original_language = $node->field_original_desc_language['und'][0]['value'];
}
$show_title = '';
$add_field_group = FALSE;
$exclude_fields = osha_musculoskeletal_disorders_get_exclude_fields($original_language);
$map = [
  'title_field' => 'field_title_original',
  'field_title_original' => 'title_field',
];
foreach ($exclude_fields as $exclude_field) {
  if (!empty($map[$exclude_field])) {
    $show_title = $map[$exclude_field];
  }
  unset($content[$exclude_field]);
}
if ($view_mode == 'dangerous_substances') {
  $page = TRUE;
  $add_field_group = TRUE;
}
if ($page && ($view_mode == 'dangerous_substances')) { ?>
  <div class="view-header back"><?php print l(t('Back to MSDs and filter'), MUSCULOSKELETAL_DISORDERS_PATH); ?></div>
<?php
}
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php
  if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <?php if ($view_mode != 'osha_search_teaser') { ?>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php } ?>

      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php
  $map = [
    'body' => ['title' => t('Description'), 'id' => 'description'],
    'field_body_original' => ['title' => t('Description'), 'id' => 'description'],
    'field_sector_industry_covered' => ['title' => t('Other data'), 'id' => 'other_data'],
    'field_external_url' => ['title' => t('Access tool'), 'id' => 'access_tool'],
  ];
  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  if ($show_title) {
    hide($content[$show_title]);
  }
  // Unset to render below after a div.
  foreach($content as $field_name => $field) {
    if ($add_field_group && isset($map[$field_name])) {
      print '<h3 id="' . $map[$field_name]['id'] . '">' . $map[$field_name]['title'] . '</h3>';
    }
    if (isset($field['#field_type']) && ($field['#field_type'] == 'taxonomy_term_reference')) {
        $skip = FALSE;
        foreach ($field['#items'] as $item) {
            if ($item['taxonomy_term']->name == 'Not applicable') {
              $skip = TRUE;
              break;
            }
        }
        if ($skip) {
            continue;
        }
    }
    $output = render($field);
    if (in_array($field_name, ['field_type_of_item', 'field_material_country', 'field_available_in_languages', 'field_msd_provider'])) {
      //      $output = str_replace(':&nbsp;</div>', '</div>', $output);
    }
    print $output;
  }
?>
</article>
    </div>
</div>
