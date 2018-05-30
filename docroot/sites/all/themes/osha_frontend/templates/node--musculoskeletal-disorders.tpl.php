<?php
/**
 * @file
 * Returns the HTML for a dangerous-substances node.
 */
?>
<div class="node-type-dangerous-substances">
    <div class="node-dangerous-substances">

<?php if ($page) { ?>
    <div id="page-title" class="page__title title"><?php print t('Musculoskeletal Disorders');?></div>
    <div class="view-header back"><?php print l(t('Back to MSDs and filter'), 'themes/musculoskeletal-disorders/search'); ?></div>
<?php } ?>
<?php
$add_field_group = FALSE;
if ($view_mode == 'musculoskeletal_disorders' || $view_mode == 'dangerous_substances') {
  $page = TRUE;
  $add_field_group = TRUE;
}
if ($page && ($view_mode == 'musculoskeletal_disorders')) { ?>
    <div class="view-header back"><?php print l(t('Back to MSDs'), 'themes/musculoskeletal-disorders/search'); ?></div>
<?php } ?>

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
    'field_sector_industry_covered' => ['title' => t('Other data'), 'id' => 'other_data'],
    'field_external_url' => ['title' => t('Access tool'), 'id' => 'access_tool'],
  ];
  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  // Unset to render below after a div.
  foreach($content as $field_name => $field) {
    if ($add_field_group && isset($map[$field_name])) {
      print '<h3 id="' . $map[$field_name]['id'] . '">' . $map[$field_name]['title'] . '</h3>';
    }
    if ($field && $field['#field_type'] == 'taxonomy_term_reference') {
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
    print render($field);
  }
  print render($content['links']);
  ?>

</article>
    </div>
</div>
