<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
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
  $query = db_select('node', 'n');
  $query->leftJoin('node_revision', 'r', 'n.nid = r.nid');
  $query->addField('n', 'vid', 'live_revision');
  $query->condition('r.vid', $node->vid)
    ->fields('r', array('nid', 'vid', 'title', 'log', 'timestamp'));
  $revisions = $query->execute()->fetchAllAssoc('vid');

  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  print render($content['title_field']);
  hide($content['title_field']);
  $latest_update_format = variable_get('latest_update_format', 'd/m/Y');
  echo '<div class="latest-update">' . t('Latest update: !changed', array('!changed' => date($latest_update_format, $revisions[$node->vid]->timestamp))) . '</div>';
  print render($content);
  ?>
  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>
</article>
