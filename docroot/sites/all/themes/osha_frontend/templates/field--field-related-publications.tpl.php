<div class="container additional">
    <h2><?php print t('Additional publications on this topic'); ?></h2>
<?php
foreach ($items as $delta => $item) {
    print render($item);
} ?>
</div>