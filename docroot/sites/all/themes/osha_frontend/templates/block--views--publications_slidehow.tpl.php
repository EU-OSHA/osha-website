<?php
/**
 * @file
 * Returns the HTML for a block.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728246
 *
 */
?>
<?php
$translated = osha_tmgmt_literal_get_translation($title);
$content = str_replace('views-row-last', 'last', $content);
?>
<?php print $content; ?>
