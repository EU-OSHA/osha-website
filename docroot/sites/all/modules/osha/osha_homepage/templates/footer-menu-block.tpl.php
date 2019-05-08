<div class="footer footer-line footer-site-map container"><ul>
<?php foreach ($menu_data as $menu) {
  if (!$menu['below']) {
    continue;
  }
  ?>
  <li class="parent">
    <ul>
      <li><?php  print l($menu['link']['title'], $menu['link']['href']); ?></li>
      <li><ul>
<?php foreach ($menu['below'] as $submenu) { ?>
      <li><?php print l($submenu['link']['title'], $submenu['link']['href']); ?></li>
<?php } ?>
        </ul>
      </li>
    </ul>
  </li>
<?php } ?>
</ul>
</div>