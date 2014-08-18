<?php

/**
 * @file
 * Theming preprocesses
 */

/**
 * Theme the node selection form.
 */
function theme_scs_sortable_table($form) {
  $form = $form['form'];
  $headers = array(t('Node title'), t('Weight'));
  $rows = array();

  $nids = element_children($form['nodes']);

  // Fetch the titles for each nid
  $titles = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('nid', array_values($nids))
    ->execute()
    ->fetchAllKeyed();

  foreach ($nids as $nid) {
    $row = array();
    $row[] = $titles[$nid];
    $row[] = drupal_render($form['nodes'][$nid]['weight']);
    $rows[] = array(
      'data' => $row,
      'class' => array('draggable'),
    );
  }
  $output = theme('table', array('header' => $headers, 'rows' => $rows, 'attributes' => array('id' => 'scs-sort-nodes')));
  $info = '';
  if (isset($form['scs_title']) && isset($form['scs_toc'])) {
    $info = drupal_render($form['scs_title']) . drupal_render($form['scs_toc']);
  }
  $output = $info . $output . drupal_render_children($form);
  drupal_add_tabledrag('scs-sort-nodes', 'order', 'sibling', 'node-weight');
  return $output;
}

/**
 * Preprocess for scs_newsletter.
 */
function scs_preprocess_scs_newsletter(&$vars) {
  // Add Table of Contents (if required)
  if ($vars['toc']) {
    $vars['toc'] = theme('scs_toc', array('nodes' => $vars['nodes']));
  }

  // Render each node using the correct view mode
  $view_mode = variable_get('scs_view_mode', 'scs');
  foreach ($vars['nodes'] as $nid => $node) {
    $build = node_view($node, $view_mode);

    // Strip out contextual links
    unset($build['#contextual_links']['node']);

    $vars['nodes'][$nid] = $build;
  }
}

/**
 * Theme the Table of Contents.
 */
function theme_scs_toc($vars) {
  $titles = array();
  foreach ($vars['nodes'] as $node) {
    $titles[] = $node->title;
  }
  return theme('item_list', array(
    'items' => $titles,
    'title' => t('Table of Contents'),
  ));
}
