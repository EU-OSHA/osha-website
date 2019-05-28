<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>
<div id="page">
    <header class="header" id="header" role="banner">
      <?php require "header.tpl.php"; ?>
    </header>
  <?php print $breadcrumb; ?>
<!--    <div id="main">-->
      <?php print render($page['highlighted']); ?>
        <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (@$page['above_title']){ ?>
          <div class="above_title">
            <?php print render($page['above_title']); ?>
          </div>
      <?php } ?>
      <?php if ($title) { ?>
          <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
      <?php }; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
        <div id="skip-to-content" style="visibility: hidden; height: 0px"><a href="#skip-to-content" rel="nofollow" accesskey="S" style="visibility: hidden;"><?php print t('Skip to content'); ?></a></div>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>

      <?php if (isset($page['before_footer'])): ?>
          <div class="before_footer">
            <?php print render($page['before_footer']); ?>
          </div>
      <?php endif; ?>

<!--    </div>-->

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

<?php print render($page['bottom']); ?>
