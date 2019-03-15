<?php
/**
 * @file
 * Returns the HTML for an article node.
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php
  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  // Unset to render below after a div.
  if (isset($content['field_related_oshwiki_articles'])) {
    hide($content['field_related_oshwiki_articles']);
  }
  print render($content);
  ?>
  <?php if ($page) { ?>
    <div class="more-link"><?php echo l(t('View all'), 'about-eu-osha/our-story/look-back-future'); ?></div>
  <?php } ?>
</article>