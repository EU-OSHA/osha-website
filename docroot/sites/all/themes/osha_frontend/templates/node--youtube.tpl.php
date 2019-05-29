<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
if ($view_mode == 'osha_resources') {
    $video_ids = osha_resources_video();
    $video_id = $content['field_youtube'][0]['#video_id'];
    $i = array_search($video_id, $video_ids, TRUE) + 1;
  ?>
    <div class="video">
        <?php print strip_tags(render($content['field_youtube']), '<img>'); ?>
        <img id="myBtn<?php print $i; ?>" class="icon-play" alt="play" src="/sites/all/themes/osha_frontend/images/icon-play.png">
        <span class="date-display-single"><?php print strip_tags(render($content['field_publication_date'])); ?></span>
        <span class="time-video"><?php print strip_tags(render($content['field_video_length'])); ?></span>
        <h2><?php print strip_tags(render($content['title_field']), '<a>'); ?></h2>
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