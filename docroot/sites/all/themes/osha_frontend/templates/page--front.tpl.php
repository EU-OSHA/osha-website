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
<script language="JavaScript">
	image = new Array(2);
	link = new Array(2);
	image[0] = '/sites/all/themes/osha_frontend/images/banner_home1.png'
	image[1] = '/sites/all/themes/osha_frontend/images/banner_home2.png'
	image[2] = '/sites/all/themes/osha_frontend/images/banner_home3.png'
	image[3] = '/sites/all/themes/osha_frontend/images/banner_home4.png'
	image[4] = '/sites/all/themes/osha_frontend/images/banner_home5.png'
	index = Math.floor(Math.random() * image.length);
</script>
  <?php if (isset($page['header'])) : ?>
    <?php print render($page['header']); ?>
  <?php endif; ?>
  <div class="page_front"> 
	<div class="left_column">
		<div class="banner_home">
			<script>
				document.write("<IMG SRC="+image[index]+" border='0' align='right'>");
			</script>
		</div>
		<div class="highlights_row">
			<?php print render($page['content']); ?>
		</div>
		
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
  <?php if (isset($page['footer'])) : ?>
    <?php print render($page['footer']); ?>
  <?php endif; ?>
</div>