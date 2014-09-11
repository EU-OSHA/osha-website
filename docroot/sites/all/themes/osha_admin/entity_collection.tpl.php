<?php
if (module_exists('osha_newsletter') && isset($variables['element'])) {
  $module_templates_path = drupal_get_path('module','osha_newsletter').'/templates';
  if ((isset($variables['element']['#entity_type']) && $variables['element']['#entity_type'] == 'entity_collection')
    && (isset($variables['element']['#bundle']) && $variables['element']['#bundle'] == 'newsletter_content_collection')) {
    $source = $variables['element']['#entity_collection'];
    $content = entity_collection_load_content('newsletter_content_collection', $source);
    $items = $content->children;

    // preprocess data
    $elements = array();
    $last_section = NULL;
    $blogs = array();
    $news = array();
    $events = array();

    foreach ($items as $item) {
      if ($item->type == 'taxonomy_term') {
        $term = taxonomy_term_view($item->content, 'token');
        $last_section = $item->content->name_original;
        if ($last_section == 'Blog') {
          $blogs[] = $term;
        } else if ($last_section == 'News') {
          $news[] = $term;
        } else if ($last_section == 'Events') {
          $events[] = $term;
        } else {
          $elements[] = $term;
        }
      } else if ($item->type == 'node') {
        $style = $item->style;
        $node = node_view($item->content,$style);

        if ($last_section == 'Blog') {
          $blogs[] = $node;
        } else if ($last_section == 'News') {
          $news[] = $node;
        } else if ($last_section == 'Events') {
          $events[] = $node;
        } else {
          $elements[] = $node;
        }
      }
    }

    $languages = language_list();

    print theme_render_template($module_templates_path.'/newsletter_header.tpl.php', array('languages' => $languages));
    print theme_render_template($module_templates_path.'/newsletter_body.tpl.php', array('items' => $elements, 'blogs' => $blogs, 'news' => $news, 'events' => $events));
    print theme_render_template($module_templates_path.'/newsletter_footer.tpl.php', array());
  }
} else {
?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($show_title): ?>
    <h2><?php print $title; ?></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php foreach ($collection as $item): ?>
    <div class="container">
      <div class="item">
        <?php print render($item); ?>
      </div>
    </div>
  <?php endforeach; ?>
</div>
<?php
}
?>