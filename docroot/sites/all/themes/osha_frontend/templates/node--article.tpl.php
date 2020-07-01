<?php
/**
 * @file
 * Returns the HTML for an article node.
 */
?>

<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if ($display_submitted): ?>
        <p class="submitted">
          <?php print $user_picture; ?>
          <?php print $submitted; ?>
        </p>
      <?php endif; ?>

      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php
  $publications_related_resources = [];
  // Move Additional Resources into Related resources.
  if (!empty($content['field_aditional_resources'])) {
    $publications_related_resources = $content['field_aditional_resources'];
    unset($content['field_aditional_resources']);
  }
  if (isset($content['field_aditional_resources'])) {
    hide($content['field_aditional_resources']);
  }
  if ($nid == 20) {
    $content['title_field'][0]['#markup'] = str_replace('<h1>', '<h1 class="revamp">', $content['title_field'][0]['#markup']);
  }
  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  // Unset to render below after a div.
  if (isset($content['field_related_oshwiki_articles'])) {
    hide($content['field_related_oshwiki_articles']);
  }
  print render($content);

  if ($publications_related_resources) {
    $related_resources = [];
    foreach (array_keys($publications_related_resources['#items']) as $key) {
      $related_resources[] = $publications_related_resources[$key];
    }
    if ($related_resources) {
      print theme('osha_publications_related_resources', [
        'items' => $related_resources,
        'type' => $node->type,
      ]);
    }
  }
  ?>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
