<?php
/**
 * @file
 * Returns the HTML for a publication node.
 */
?>
<?php if($page): ?>
  <h1 id="page-title" class="page__title title"><?php print t('Publications');?></h1>
  <div class="view-header"><?php print l(t('Back to publications and filter'), 'publications'); ?></div>
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
  if (isset($content['field_related_man_pubs'])) {
    hide($content['field_related_man_pubs']);
  }
  if (isset($content['field_related_oshwiki_articles'])) {
    hide($content['field_related_oshwiki_articles']);
  }
  print render($content);
  // render related publications(both manual + dynamic from template preprocess_node
  if ( $view_mode == 'full') {
    if (!empty($field_related_man_pubs) || $total_related_publications > 0) { ?>
      <div id="related-publications">
        <div class="related_publications_head"><span><?php print t('Related publications');?><span></div>
      <div>
    <?php
      print render($content['field_related_man_pubs']);
      if ($total_related_publications > 0) {
        foreach ($tagged_related_publications as $related_pub) {
          print render($related_pub);
        }
      }
    }?>

  <?php
  // render related wiki articles (both manual + dynamic from template preprocess_node
    if ( !empty($field_related_oshwiki_articles) || $total_wiki > 0) { ?>
      <div id="related-wiki-publications">
        <div class="related_wiki_head"><span><?php print t('OSHWiki featured articles');?><span></div>
      <div>
    <?php
      print render($content['field_related_oshwiki_articles']);
      if ($total_wiki > 0) {
        foreach ($tagged_wiki as $wiki) {
          print render($wiki);
        }
      }
    }
  } ?>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
