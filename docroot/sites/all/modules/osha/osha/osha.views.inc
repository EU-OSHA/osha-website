<?php

/**
 * Alter the view tmgmt_node_selection_view to show latest node state.
 *
 * Alter LEFT JOIN node_revision ON node.vid = node_revision.vid
 * to LEFT JOIN node_revision ON node.nid = node_revision.nid
 */
function osha_views_query_alter(&$view, &$query) {
  if (($view->name == 'related_content') && ($view->current_display == 'block_2')) {
    $node = menu_get_object('node');
    $excluded_nids = array($node->nid);
    $w = entity_metadata_wrapper('node', $node->nid);
    $related_publications = $w->field_related_publications->value();
    if ($related_publications) {
      foreach($related_publications as $publication) {
        $excluded_nids[] = $publication->nid;
      }
    }
    foreach ($query->where as &$condition_group) {
      foreach ($condition_group['conditions'] as &$condition) {
        if (reset($condition) == 'node.nid') {
          $condition = array('field' => 'node.nid', 'value' => $excluded_nids, 'operator' => 'NOT IN');
          break;
        }
      }
    }
  }

  // Switch from JOIN to LEFT JOIN with workbench_moderation_node_history
  // to allow adding content types which are not moderated (i.e. page).
  if ($view->name == 'administration_content') {
    if (isset($query->table_queue['workbench_moderation_node_history']['join']->type)) {
      $query->table_queue['workbench_moderation_node_history']['join']->type = 'LEFT';
    }
    if (isset($query->table_queue['node_revision'])) {
      $query->table_queue['node_revision']['join']->field = 'nid';
      $query->table_queue['node_revision']['join']->left_field = 'nid';
    }
    // Overwrite the view.
    if (in_array('views', arg())) {
      drupal_set_message('Be careful! Overwriting query in osha.views.inc. Changing filters order may affect the view.', 'warning');
    }
    $query->where[3]['conditions'][1]['field'] = 'node.type';
  }
}
