<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
if ($view_mode == 'osha_resources') {
  if ($slideshare = $node->field_slideshare['en'][0]) {
    $slideshare_url = $slideshare['slide_url'];
    $slideshare_id = $slideshare['slide_id'];
    $oembed = get_slideshare_oembed($slideshare_id, $slideshare_url);
    $wrapper = entity_metadata_wrapper('node', $node);
    $thumbnail = '';
    $thumbnails = $wrapper->field_thumbnail->value();
    if ($thumbnails) {
      $thumbnail = $thumbnails[0];
    }
  }
  ?>
    <div class="box">
        <?php print get_slideshare_img($slideshare_id, $thumbnail); ?>
        <span class="date-display-single"></span>
        <span class="time-video"><?php print $oembed['total_slides'] . ' ' . t('slides') ?></span>
        <h2><?php print strip_tags(render($content['title_field']), '<a>'); ?></h2>
      <?php
      print l(t('View'), '#', array(
        'attributes' => array(
          'class' => ['see-more-arrow', 'view-slideshare'],
          'data-id' => $slideshare_id,
          'data-url' => $slideshare_url,
        ),
        'query' => $url_query,
        'external' => TRUE,
      ));
      if ($slideshare_url) {
        print l(t('Download'), $slideshare_url, array(
          'attributes' => array(
            'class' => ['see-more-arrow'],
            'target' => "_blank",
          ),
          'query' => $url_query,
          'external' => TRUE,
        ));
      }
      ?>
    </div>
<?php
}
else { ?>
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
    print render($content);
  ?>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
<?php } ?>
