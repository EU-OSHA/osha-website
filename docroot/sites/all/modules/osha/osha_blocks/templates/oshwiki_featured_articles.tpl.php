<?php if (!empty($tagged_wikis)): ?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
<?php
  foreach ($tagged_wikis as $wiki) {
    print render($wiki);
  }
?>
</div>
<?php endif; ?>
