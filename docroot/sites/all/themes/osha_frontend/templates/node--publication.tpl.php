<?php
/**
 * @file
 * Returns the HTML for a publication node.
 */
?>
<?php if($page): ?>
  <div id="page-title" class="page__title title"><?php print t('Publications');?></div>
  <div class="view-header back"><?php print l(t('Back to publications and filter'), 'tools-and-publications/publications'); ?></div>
<?php endif; ?>

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
  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  // unset to render below after a div
  if (isset($content['field_related_oshwiki_articles'])) {
    hide($content['field_related_oshwiki_articles']);
  }
  if (isset($content['field_aditional_resources'])) {
    hide($content['field_aditional_resources']);
  }
  foreach ($content as $key => $item) {
    print render($item);
    if (($view_mode == 'full') && ($key == 'field_banner_publications_office')) {
        hide($content[$key]);
        if ($item['#items'][0]['value']) {
          echo '<div class="field field-name-field-publication-bookshop-id field-type-text field-label-hidden"><div class="field-items"><div class="field-item even">';
          echo theme('osha_publication_bookshop_id_format', ['title' => $title]);
          echo '</div></div></div>';
        }
    }
  }
  // render related publications(dynamic from template preprocess_node
  if ( $view_mode == 'full') {
    if ($total_related_publications > 0) { ?>
      <div id="related-publications">
        <div class="related_publications_head"><span><?php print t('Related publications');?><span></div>
      <div>
    <?php
      foreach ($tagged_related_publications as $related_pub) {
        print render($related_pub);
      }
      echo '<div class="more-link">' . $view_all . '</div>';
    }
    if (isset($content['field_aditional_resources'])) {
      print render($content['field_aditional_resources']);
    }
  }?>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
