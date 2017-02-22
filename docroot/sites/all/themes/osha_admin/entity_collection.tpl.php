<?php

if (module_exists('osha_newsletter') && isset($variables['element'])) {
  $module_templates_path = drupal_get_path('module','osha_newsletter').'/templates';
  if ((isset($variables['element']['#entity_type']) && $variables['element']['#entity_type'] == 'entity_collection')
    && (isset($variables['element']['#bundle']) && $variables['element']['#bundle'] == 'newsletter_content_collection')) {
    ?>
    <div class="newsletter-wrapper" style="width: 800px;">
      <?php
        $source = $variables['element']['#entity_collection'];
        $full_newsletter = OSHNewsletter::render($source);
        print $full_newsletter['header'];
        print $full_newsletter['body'];
        print $full_newsletter['footer'];
      ?>
    </div><?php
  }
} else {
?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($show_title): ?>
    <h2><?php print $title; ?></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php foreach ($collection as $item): ?>
    <div class="container">
      <div class="item">
        <?php print render($item); ?>
      </div>
    </div>
  <?php endforeach; ?>
</div>
<?php
}
?>
