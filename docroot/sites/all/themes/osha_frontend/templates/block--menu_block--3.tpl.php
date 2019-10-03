<?php
/**
 * @file
 * Returns the HTML for a block.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728246
 */
?>
<?php 
    $node = menu_get_object();
    if ($node && $node->nid == 20) {
      $content = str_replace(['<ul id="main-menu-links-3183-17" class="menu clearfix">', '</ul>'], ['', ''], $content);
      $content = str_replace('menu-block-wrapper menu-block-3 menu-name-main-menu parent-mlid-0 menu-level-3', 'sub-home', $content);
      print $content;
    }
    elseif (isset($node) && isset($node->article_type_code) && $node->article_type_code == 'introduction') {
    ?>
        <div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

          <?php print render($title_prefix); ?>
          <?php if ($title): ?>
            <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
          <?php endif; ?>
          <?php print render($title_suffix); ?>

            <?php print $content; ?>

        </div>
<?php } ?>

