<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php
if ($rows) {
  print '<div class="row">';
}
foreach ($rows as $id => $row):
  if ($id == 4) {
    print '</div><div class="row">';
  }
  ?>
  <div<?php if ($classes_array[$id]): ?> class="<?php print $classes_array[$id]; ?>"<?php endif; ?>>
    <?php print $row; ?>
  </div>
<?php endforeach;
if ($rows) {
  print '</div>';
}

