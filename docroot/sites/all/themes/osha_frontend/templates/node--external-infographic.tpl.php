<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */

global $language;

?>
<div id="page">
  <header class="header" id="header" role="banner">
    <?php require "header.tpl.php"; ?>
  </header>
  <?php 
    drupal_add_css(drupal_get_path('theme', 'osha_frontend') . '/css/external-infographic-css/custom.css'); 
    drupal_add_css(drupal_get_path('theme', 'osha_frontend') . '/css/external-infographic-css/layout.css'); 

    drupal_add_js(drupal_get_path('theme', 'osha_frontend') .'/js/external-infographic-js/ready.min.js');
    drupal_add_js(drupal_get_path('theme', 'osha_frontend') .'/js/external-infographic-js/bootstrap.js');
    drupal_add_js(drupal_get_path('theme', 'osha_frontend') .'/js/external-infographic-js/chart.bundle.js');
    drupal_add_js(drupal_get_path('theme', 'osha_frontend') .'/js/external-infographic-js/script.js');
 ?>
  <div class="breadcrumb">
    <span class="inline odd first">
      <a href="/en">Home</a></span>
      <span class="delimiter">»</span> 
      <span class="inline even">
        <?php print '<a href="/' . $language->language . '/tools-and-publications">'. t("Tools & Publications") .'</a>' ?>
      </span>
      <span class="delimiter">»</span> 
      <span class="inline odd">
        <?php print '<a href="/' . $language->language . '/tools-and-publications/infographics">'. t("Infographics") .'</a>' ?>
      </span> 
      <span class="delimiter">»</span> 
      <span class="inline even last"></span>
       <span class="inline odd">
        <?php print '<a href="/' . $language->language . '/tools-and-publications/infographics/how-manage-dangerous-substances">'. $node->title .'</a>' ?>
      </span> 
      <span class="delimiter">»</span> 
      <span class="inline even last"><?php echo $node->title ?></span>
  </div>
  <div id="main">
    <div id="content" class="one_column"> 
      <?php print render($title_prefix); ?>
      <?php if (@$page['above_title']){ ?>
          <div class="above_title">
            <?php print render($page['above_title']); ?>
        </div>
      <?php } ?>
      <?php if ($title): ?>
        <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <div id="skip-to-content" style="visibility: hidden; height: 0px"><a href="#skip-to-content" rel="nofollow" accesskey="S" style="visibility: hidden;"><?php print t('Skip to content'); ?></a></div>
      <?php print $feed_icons; ?>
    </div>

  <?php include(drupal_get_path('theme', 'osha_frontend').'/templates/external-infographic-tpl/'. $language->language .'-infographic.php'); ?>
    


   
  
  </div>

  <?php print render($page['footer']); ?>

</div>

<?php print render($page['bottom']); ?>
