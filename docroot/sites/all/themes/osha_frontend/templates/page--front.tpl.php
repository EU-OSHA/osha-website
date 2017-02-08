<?php
/**
 * @file
 * Alpha's theme implementation to display a single Drupal page.
 */
?>
<?php
  // This will remove the 'No front page content has been created yet.'
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
	<div class="left_column">
		<div class="highlights_row">
			<?php print render($page['content']); ?>
		</div>
	</div>
	<?php
      // Render the sidebars to see if there's anything in them.
      $sidebar_second = render($page['sidebar_second']);
    ?>
	<?php if ($sidebar_second): ?>
      <aside class="sidebars_second sidebars_second_home">
        <?php print $sidebar_second; ?>
      </aside>
    <?php endif; ?>
  </div>
   <?php if (isset($page['triptych_first'])) : ?>
    <?php print render($page['triptych_first']); ?>
  <?php endif; ?>
  
  <?php if (isset($page['footer'])) : ?>
    <?php print render($page['footer']); ?>
  <?php endif; ?>
</div>
