<div class="view-content"><?php
$options['html'] = TRUE;
foreach ($rows as $i => $row) {
  print '
      <div class="views-row views-row-' . $i . ' gallery-row col-md-4 col-sm-6 col-xs-12">
        <div class="views-field views-field-field-flickr">
          <div class="field-content">' . l($row['image'], $row['url'], $options) . '</div>
        </div>
        <div class="views-field views-field-nothing">
            <span class="field-content"><span class="gallery_list_detail_container">' . l($row['name'], $row['url']) . '</span></span>
        </div>
      </div>';
}
?></div>
