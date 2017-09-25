<?php

/**
 * Implments hook_rules_action_info().
 */
function osha_newsletter_rules_action_info() {
  $info['osha_newsletter_rules_add_to_newsletter_action'] = array(
    'label' => t('Add to newsletter'),
    'group' => t('Node'),
    'parameter' => array(
      'node' => array(
        'type' => 'node',
        'label' => t('Node'),
        'description' => t('Node'),
      ),
    ),
  );

  return $info;
}

/**
 * Actual VBO target action defined in hook_action_info above.
 */
function osha_newsletter_rules_add_to_newsletter_action($node) {
  $collection = menu_get_object('entity_collection');
  if ($collection) {
    $item = new EntityCollectionTreeNode('node', $node->nid, $node);
    // TODO: smart selection of $item->position based on $node->type
    entity_collection_append_item($collection, $item);
  }
}
