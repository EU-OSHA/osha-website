<?php
$classes = ['block-related-resources', 'content-fluid', 'related-resources'];
if ($type) {
  $classes[] = $type . '_related_resources';
}
?>
<div class="<?php echo implode(' ', $classes); ?>">
    <div class="container">
        <h2><?php print t('Related resources'); ?></h2>
      <?php
      $bundles = array(
        'publication' => t('Related publications'),
        'slideshare' => t('Presentations'),
        'infographic' => t('Infographics'),
        'youtube' => t('Videos'),
        'wiki_page' => t('OSHwiki featured articles'),

        'flickr' => 'Flickr',
        'external_url' => t('External resources'),
        'file' => t('Files'),
        'news' => t('News'),
        'highlights' => t('Highlights'),
        'events' => t('Events'),
      );
      $slideshare_html = [];
      $node_type = '';
      $rows = [];

      foreach ($items as $j => $item) {
        if (isset($item['node'])) {
          $value = reset($item['node']);
        }
        if ($value['#bundle'] == 'slideshare') {
          $value = reset($item['node']);
          if ($slideshare = $value['field_slideshare']['#items'][0]) {
            $slideshare_id = $slideshare['slide_id'];
            $oembed = get_slideshare_oembed($slideshare_id, $slideshare['slide_url']);
            $slideshare_html[$slideshare_id] = $oembed['html'];
          }
        }
        if ($value['#bundle'] == 'youtube') {
          $value = reset($item['node']);
          if ($youtube = $value['field_youtube']['#items'][0]) {
            $video_ids[] = $youtube['video_id'];
          }
        }
        $rows[$value['#bundle']][] = $item;
      }
      osha_resources_video($video_ids);
      if ($slideshare_html) {
        drupal_add_js(array('osha_slideshare' => array('html' => $slideshare_html)), 'setting');
      }

      foreach ($rows as $node_type => $items) {
        print '<h3><span>' . $bundles[$node_type] . '</span></h3>';
        $class = "content-related-boxes";
        if (in_array($node_type, ['slideshare'])) {
          $class = "content-related-boxes slideshare";
        }
        elseif ($node_type == 'infographic') {
          $class = "content-related-boxes infographic";
        }
        elseif ($node_type == 'youtube') {
          $class = "content-related-videos";
        }

        if ($class) {
          print '<div class="' . $class . '">';
        }

        foreach ($items as $item) {
          print render($item);
        }

        if ($class) {
          if ($class == "content-related-videos") {
            if ($video_ids) {
              foreach($video_ids as $i => $video_id) { ?>
                  <!-- The Modal -->
                  <div id="myModal<?php print ($i + 1) ?>" class="modal">
                      <!-- Modal content -->
                      <div class="modal-content">
                          <span class="close close<?php print ($i + 1) ?>">&times;</span>
                          <iframe class="videoIframe js-videoIframe videoModal-<?php print ($i + 1)?>" src="https://www.youtube-nocookie.com/embed/<?php print $video_id ?>"  allowfullscreen></iframe>
                      </div>

                  </div>

                  <!-- End Modal -->
                <?php
              }
            }
          }
          print '</div>';
        }
      }
      ?>
    </div>
</div>
