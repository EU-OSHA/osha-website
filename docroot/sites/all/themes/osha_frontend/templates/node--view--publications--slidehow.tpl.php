<?php
/**
 * @file
 * Returns the HTML for a publication node.
 */
$publication_type = '<strong>' . t('Type') . ': </strong>' . strip_tags(render($content['field_publication_type']));
$pages_count = strip_tags(render($content['field_pages_count']));
if (empty($url_query)) {
  $url_query = [];
}
?>
<div class="left-column">
  <?php print render($content['field_cover_image']); ?>
</div>
<div class="right-column">
    <span class="publication-date"><?php print strip_tags(render($content['field_publication_date'])); ?></span>
    <span class="pages">
    <?php
    if ($pages_count) {
      print $pages_count . ' ' . t('pages');
    } ?>
    </span>
    <h2><?php print strip_tags(render($content['title_field']), '<a>'); ?></h2>
    <span class="label"><?php print $publication_type; ?></span>
  <?php
  print l(t('See more'), $node_url . '/view', array(
    'attributes' => array('class' => ['see-more-arrow']),
    'query' => $url_query,
    'external' => TRUE,
  ));
  ?>
</div>
