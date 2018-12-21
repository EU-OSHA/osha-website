<?php
/**
 * @file
 * Returns the HTML for a publication node.
 */

global $language;
// Show image in thumbnail.
$wrapper = entity_metadata_wrapper('node', $node);
if (!isset($content['field_thumbnail']) && !empty($node->field_image)) {
  $content['field_thumbnail'] = [
    '#type' => 'item',
    '#prefix' => '<div class="field-name-field-thumbnail">',
    '#suffix' => '</div>',
    '#markup' => theme('image_style', array(
      'style_name' => 'medium_crop_220',
      'path' => $wrapper->language($language->language)->field_image->value()['uri'],
      'height' => NULL,
      'width' => 220,
      'alt' => $content['title_field']['#items'][0]['value'],
      'title' => $content['title_field']['#items'][0]['value'],
    )),
  ];
  // TODO WEIGHT of the field ?!
}

?>
<?php if($page): ?>
  <div id="page-title" class="page__title title">&nbsp;</div>
  <div class="view-header back"><?php print l(t('Back to Infographics'), 'tools-and-publications/infographics'); ?></div>
<?php endif; ?>

<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if ($display_submitted): ?>
        <p class="submitted">
          <?php print $user_picture; ?>
          <?php print $submitted; ?>
        </p>
      <?php endif; ?>

      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php
  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);

  if($view_mode == 'full'){
    print render($content['title_field']);

    print render($content['field_thumbnail']);
    print render($content['body']);

    if ($content['field_image']):
      print '<div class="download-img">';
        print render($content['field_image']);
      print '</div>';
    endif;
    
    if ($content['field_file']):
      print '<div class="download-pdf">';
         print render($content['field_file']);
      print '</div>';
    endif;
    
  ?>
  
  <?php if ($content['field_external_url']['#items'][0]['url']): ?>
    <div class="infographics-url-title external">
      <span class="label_multilang_file"><?php echo t("Access the infographic in:"); ?></span>
      <span class="infographic-lang">
      <?php
        foreach ($node->field_external_url as $key => $value) {

      ?>
          <a href='/<?php print  $key ?><?php print $content['field_external_url']['#items'][0]['url'] ?>?lan=<?php echo $key ?>'><?php echo $key ?> | </a>     
      <?php   
        }
      ?>
      </span>
    </div>
  <?php endif; ?>
  
  <?php
    print render($content['field_twin_infographics']);
  }
  else {
    print render($content);
  }
  ?>

</article>
