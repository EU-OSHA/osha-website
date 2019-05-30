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
  <?php if ($breadcrumb) print '<div class="breadcrumb-fluid">' . $breadcrumb . '</div>'; ?>
    <?php
    // Render the sidebars to see if there's anything in them.
    $sidebar_first = render($page['sidebar_first']);
    // Andrei: remove sidebar_second from introduction pages.
    $show_25th = FALSE;
    $node = menu_get_object();
    if (isset($node) && isset($node->article_type_code) && $node->article_type_code != 'section') {
        unset($page['sidebar_second']);
    }
    $sidebar_second = render($page['sidebar_second']);
    if (isset($node) && ($node->type == '25th_anniversary')) {
      $show_25th = TRUE;
    }
    ?>
    <?php if ($sidebar_first): ?>
      <aside class="sidebars_first">
        <?php print $sidebar_first; ?>
      </aside>
    <?php endif; ?>

    <?php print render($page['highlighted']); ?>
      <a id="main-content"></a>
    <div class="container">
      <?php print render($title_prefix); ?>
    <?php if (@$page['above_title']){ ?>
        <div class="above_title">
          <?php print render($page['above_title']); ?>
        </div>
    <?php } ?>
      <?php if ($title) { ?>
        <h1 class="revamp"><?php print $title; ?></h1>
      <?php }; ?>
      <?php print render($title_suffix); ?>

      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <div id="skip-to-content" style="visibility: hidden; height: 0px"><a href="#skip-to-content" rel="nofollow" accesskey="S" style="visibility: hidden;"><?php print t('Skip to content'); ?></a></div>
      <?php
      $content = render($page['content']);
      print str_replace('<div class="content-fluid">', '</div><div class="content-fluid">', $content);
      ?>

    <div class="container">
    <?php if (isset($page['before_footer'])): ?>
      <div class="before_footer">
        <?php
        $output = render($page['before_footer']);
        $output = str_replace('edit-content', 'content', $output);
        print $output; ?>
      </div>
    <?php endif; ?>
    </div>

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
