<?php
/**
 * @file
 * Returns the HTML for a publication node.
 */
?>
<?php

if (empty($url_query)) {
  $url_query = [];
}

if ($view_mode == 'full') {
  if (variable_get('allow_tagged_related_publications', FALSE)) {
    foreach ($tagged_related_publications as $rel_related_publication) {
      $content['field_aditional_resources']['#items'][] = [
        'target_id' => $rel_related_publication->nid,
        'entity' => $rel_related_publication,
        'access' => TRUE,
      ];
      $content['field_aditional_resources'][] = [
        'node' => [
          $rel_related_publication->nid => node_view($rel_related_publication, 'osha_resources'),
          '#sorted' => TRUE,
        ],
      ];
    }
  }

  // Append oshwiki in related resources.
  foreach ($content['field_related_oshwiki_articles']['#items'] as $idx => $row) {
    $content['field_aditional_resources']['#items'][] = $row;
    $content['field_aditional_resources'][] = $content['field_related_oshwiki_articles'][$idx];
  }

  $tags = strip_tags(render($content['field_tags']));
  $publication_type = strip_tags(render($content['field_publication_type']));
  $pages_count = strip_tags(render($content['field_pages_count']));
?>
    <div class="container">
        <!-- PUBLICATION DETAIL -->
        <div class="view-header back revamp"><?php print l(t('Back to publications and filter'), 'publications'); ?></div>
        <div class="publications-detail">
            <div class="publications-row">
                <div class="publications-left-column"><?php print render($content['field_cover_image']); ?></div>
                <div class="publications-detail-right-column">
                    <div class="content-publication-info">
                        <span class="date-display-single"><?php print strip_tags(render($content['field_publication_date'])); ?></span>
                        <span class="label"><strong><?php print t('Type') ?>: </strong><?php print $publication_type; ?></span>
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
              <?php
              print render($content['download_form']);
              if ($content['field_banner_publications_office']['#items'][0]['value']) {
                echo theme('osha_publication_bookshop_id_format', ['title' => $node->title]);
              }
              ?>
            </div>
        </div>
    </div>
  <?php
  $items = [];
  foreach (array_keys($content['field_aditional_resources']['#items']) as $key) {
    $items[] = $content['field_aditional_resources'][$key];
  }
  print theme('osha_publications_related_resources', [
    'items' => $items,
  ]);
  if (isset($content['field_aditional_resources'])) {
    hide($content['field_aditional_resources']);
  }

  if (isset($content['field_related_publications'])) {
    print render($content['field_related_publications']);
  }
}
elseif ($view_mode == 'osha_resources') {
  $publication_type = '<strong>' . t('Type') . ': </strong>' . strip_tags(render($content['field_publication_type']));
  $pages_count = strip_tags(render($content['field_pages_count']));
?>
<div class="content-related-publications publications">
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
<?php }
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
