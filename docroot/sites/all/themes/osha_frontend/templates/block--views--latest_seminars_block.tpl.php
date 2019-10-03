<?php
/**
 * @file
 * Returns the HTML for a block.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728246
 *
 */
?>
<?php
$translated = osha_tmgmt_literal_get_translation($title);
?>
<div id="<?php print $block_html_id; ?>" class="content-fluid events <?php print $classes; ?>"<?php print $attributes; ?>>
<div class="container">
  <?php if ($translated): ?>
    <h2><?php print $translated; ?></h2>
  <?php endif; ?>
  <?php print $content; ?>
</div>
</div>
