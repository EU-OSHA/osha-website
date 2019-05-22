<?php
/**
 * @file
 * Returns the HTML for a publication node.
 */
?>
<?php
if ($view_mode == 'full') {
    // Append oshwiki in related resources.
    foreach ($content['field_related_oshwiki_articles']['#items'] as $idx => $row) {
      $content['field_aditional_resources']['#items'][] = $row;
      $content['field_aditional_resources'][] = $content['field_related_oshwiki_articles'][$idx];
    }

    $tags = strip_tags(render($content['field_tags']));
    $publication_type = '<strong>' . t('Type') . ': </strong>' . strip_tags(render($content['field_publication_type']));
    $pages_count = strip_tags(render($content['field_pages_count']));
?>
    <div class="container">
        <!-- PUBLICATION DETAIL -->
        <div class="view-header back revamp"><?php print l(t('Back to publications and filter'), 'tools-and-publications/publications'); ?></div>
        <div class="publications-detail">
            <div class="publications-row">
                <div class="publications-left-column"><?php print render($content['field_cover_image']); ?></div>
                <div class="publications-detail-right-column">
                    <div class="content-publication-info">
                        <span class="date-display-single"><?php print strip_tags(render($content['field_publication_date'])); ?></span>
                        <span class="label"><?php print $publication_type; ?></span>
                        <span class="pages">
                            <?php
                            if ($pages_count) {
                              print $pages_count . ' ' . t('pages');
                            } ?>
                        </span>
                    </div>
                    <h1><?php print strip_tags(render($content['title_field']), '<a>'); ?></h1>
                    <?php if ($tags) { ?>
                    <div class="keywords">
                        <span><?php print t('Keywords') ?>:</span><span><?php print $tags ?></span>
                    </div>
                    <?php } ?>
                    <div class="pub-text"><?php print render($content['body']) ?></div>
                </div>
            </div>
            <div class="content-downloads">
                <span class="title-download">Downloads</span>
                <div class="content-languages-download">
                    <span class="title-select">Publication</span>
                    <select id="edit-search-api-language" name="search_api_language" class="form-select new-select-style">
                    </select>
                    <a href=""><img alt="download" src="<?php print drupal_get_path('theme', 'osha_frontend'); ?>/images/content/download-ico.png"></a>
                </div>
                <?php
                if ($content['field_banner_publications_office']['#items'][0]['value']) {
                    echo theme('osha_publication_bookshop_id_format', ['title' => $node->title]);
                }
                ?>
            </div>
        </div>
    </div>
  <?php
  if (isset($content['field_aditional_resources'])) {
    print render($content['field_aditional_resources']);
  }
  if (isset($content['field_related_publications'])) {
    print render($content['field_related_publications']);
  }
}
elseif ($view_mode != 'osha_search_teaser') {
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
  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  // Unset to render below after a div.
  if (isset($content['field_related_oshwiki_articles'])) {
    hide($content['field_related_oshwiki_articles']);
  }
  if (isset($content['field_aditional_resources'])) {
    hide($content['field_aditional_resources']);
  }
  foreach ($content as $key => $item) {
    if (($view_mode == 'full') && ($key == 'field_banner_publications_office')) {
        hide($content[$key]);
        if ($item['#items'][0]['value']) {
          echo '<div class="field field-name-field-publication-bookshop-id field-type-text field-label-hidden"><div class="field-items"><div class="field-item even">';
          echo theme('osha_publication_bookshop_id_format', ['title' => $node->title]);
          echo '</div></div></div>';
        }
    }
    elseif ($key != 'links') {
      print render($item);
    }
  }
  // Render related publications(dynamic from template preprocess_node).
  if ($view_mode == 'full') {
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
<?php
}
else {
  $publication_type = '<strong>' . t('Type') . ': </strong>' . strip_tags(render($content['field_publication_type']));
  $pages_count = strip_tags(render($content['field_pages_count']));
?>
<div class="revamp-row">
    <div class="publications-left-column"><?php print render($content['field_cover_image']); ?></div>
    <div class="publications-right-column">
        <div class="content-publication-info">
            <span class="date-display-single"><?php print strip_tags(render($content['field_publication_date'])); ?></span>
            <span class="label"><?php print $publication_type; ?></span>
            <span class="pages">
            <?php
            if ($pages_count) {
              print $pages_count . ' ' . t('pages');
            } ?>
            </span>
        </div>
        <h2><?php print strip_tags(render($content['title_field']), '<a>'); ?></h2>
<?php
  print l(t('See more'), $node_url . '/view', array(
    'attributes' => array('class' => ['see-more-arrow']),
    'query' => $url_query,
    'external' => TRUE,
  ));
?>
    </div>
</div>
<?php
}
