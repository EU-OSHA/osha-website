<?php
$translated = osha_tmgmt_literal_get_translation($title);
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if ($translated): ?>
    <h2<?php print $title_attributes; ?>>
      <?php print l($translated, '/oshmail-newsletter'); ?>
    </h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php print $content; ?>
</div>
