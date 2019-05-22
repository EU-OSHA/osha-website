<div class="content-fluid related-reources">
    <div class="container">
        <h2><?php print t('Related resources'); ?></h2>
<?php
$bundles = array(
  'youtube' => 'YouTube',
  'slideshare' => 'SlideShare',
  'flickr' => 'Flickr',
  'infographic' => 'Infographics',
  'external_url' => t('External resources'),
  'file' => t('Files'),
  'publication' => t('Publications'),
  'news' => t('News'),
  'highlights' => t('Highlights'),
  'events' => t('Events'),
  'wiki-page' => t('OSHwiki featured articles'),
);
$node_type = '';
foreach ($items as $delta => $item) {
    if (isset($item['node'])) {
        $value = reset($item['node']);
      if ($node_type != $value['#bundle']) {
        // This is a new bundle type.
        $node_type = $value['#bundle'];
        print '<h3><span>' . $bundles[$node_type] . '</span></h3>';
      }
    }
  ?>
  <?php
      print render($item);
} ?>
    </div>
</div>
