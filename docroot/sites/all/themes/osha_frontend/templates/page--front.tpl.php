<?php
/**
 * @file
 * Alpha's theme implementation to display a single Drupal page.
 */
?>
<?php
  // This will remove the 'No front page content has been created yet.
  if($is_front) {
    $page['content']['system_main']['default_message'] = array();
  }
?>
<div id="page">
  <div id="header">
  <?php if (isset($page['header'])) : ?>
    <?php print render($page['header']); ?>
  <?php endif; ?>
  </div>
  <div class="page_front">
    <?php print $messages; ?>

    <!-- Home intro Boxes -->
    <div class="home-intro">
        <?php print render($page['home_intro']); ?>
    </div>
    <!-- END Home intro Boxes -->
    <div class="left_column">
       <?php print render($page['content']); ?>
    </div>
    <?php
    // Render the sidebars to see if there's anything in them.
    $sidebar_second = render($page['sidebar_second']);
    if ($sidebar_second): ?>
      <aside class="sidebars_second sidebars_second_home">
        <?php print $sidebar_second; ?>
      </aside>
    <?php endif; ?>
  </div>
   <?php if (isset($page['triptych_first'])) : ?>
    <?php
     $recommended_resources = render($page['triptych_first']);
     $recommended_resources = str_replace('class="block ', 'class="block recomended-resources ', $recommended_resources);
     print $recommended_resources;
    ?>
   <?php endif; ?>
  <?php if (isset($page['footer'])) : ?>
  <footer id="footer" class="<?php print $classes; ?>">
    <?php if (isset($page['footer_subscribe'])) : ?>
      <?php print render($page['footer_subscribe']); ?>
    <?php endif; ?>
    <?php if (isset($page['footer_sitemap'])) : ?>
      <?php print render($page['footer_sitemap']); ?>
    <?php endif; ?>
    <?php print render($page['footer']); ?>
  </footer>
  <?php endif; ?>
</div>