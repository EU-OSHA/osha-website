<?php
/**
 * @file
 * Returns the HTML for a dangerous-substances node.
 */
?>
<?php if ($page) { ?>
    <div id="page-title" class="page__title title"><?php print t('Dangerous substances');?></div>
    <div class="view-header back"><?php print l(t('Back to dangerous substances and filter'), 'themes/dangerous-substances/search'); ?></div>
<?php } ?>
<?php
if ($view_mode == 'dangerous_substances') {
  $page = TRUE;
}
if ($page && ($view_mode == 'dangerous_substances')) { ?>
    <div class="view-header back"><?php print l(t('Back to Practical tools and guidance on dangerous substances'), 'themes/dangerous-substances/ds-tools'); ?></div>
<?php } ?>

<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php
  if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <?php if ( $view_mode != 'osha_search_teaser') { ?>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php } ?>

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
  print render($content);
  ?>
  <?php print render($content['links']); ?>

</article>
