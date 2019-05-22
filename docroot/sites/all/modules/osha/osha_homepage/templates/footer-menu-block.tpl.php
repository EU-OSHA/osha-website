<?php
$skip = variable_get('footer_menu_skip_empty', FALSE);
$exclude_url = explode("\n", variable_get('footer_menu_exclude_url', ''));
?>
<div class="footer footer-line footer-site-map container"><ul>
<?php foreach ($menu_data as $menu) {
  if ((!$menu['below'] && $skip) || (in_array($menu['link']['href'], $exclude_url))) {
    continue;
  }
  ?>
  <li class="parent">
    <ul>
      <li><?php  print l($menu['link']['title'], $menu['link']['href']); ?></li>
      <li><ul>
<?php foreach ($menu['below'] as $submenu) {
    if (in_array($submenu['link']['href'], $exclude_url)) {
        continue;
    }
    ?>
      <li><?php print l($submenu['link']['title'], $submenu['link']['href']); ?></li>
<?php } ?>
        </ul>
      </li>
    </ul>
  </li>
<?php } ?>
</ul>
</div>