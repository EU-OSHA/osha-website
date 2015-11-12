<?php
/**
 * @file
 * Returns the HTML for a publication node.
 */
?>
<?php if($page): ?>
  <div id="page-title" class="page__title title">&nbsp;</div>
  <div class="view-header back"><?php print l(t('Back to Infographics'), 'tools-and-publications/infographics'); ?></div>
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

  if($view_mode == 'full'){
    print render($content['title_field']);
    

    // Display thumbnail
    if (isset($content['field_thumbnail'])) {
      print render($content['field_thumbnail']);
    }
    elseif (isset($content['field_image'])) {
      print theme_image_style(array(
        'style_name' => 'medium',
        'path' => $content['field_image']['#items'][0]['uri'],
        'height' => NULL,
        'width' => 220,
      ));
    }

    print render($content['body']);
    print render($content['field_image']);
    print render($content['field_file']);
    print render($content['field_twin_infographics']);
  }elseif($view_mode == 'teaser' || $view_mode == 'osha_resources'){
    print render($content);
  }
  ?>

</article>
