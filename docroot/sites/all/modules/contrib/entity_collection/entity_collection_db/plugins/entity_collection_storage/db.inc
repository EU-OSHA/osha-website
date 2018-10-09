<?php
/**
 * @file
 * Sample entity_collection storage database implementation.
 */

/**
 * Entity collection storage backend using the database.
 */
class EntityCollectionStorageDB extends EntityCollectionStorage {

  /**
   * Save an entity collection
   * @see EntityCollectionStorageInterface::save().
   */
  public function save(EntityCollection $collection, EntityCollectionTreeNode $tree, $contexts = array(), $position = 0, $depth = 0) {
    if (isset($collection->contexts) && empty($contexts)) {
      $contexts = $collection->contexts;
    }
    $record = $this->getRecord($collection, $tree, $position, $contexts, $depth);
    $primary_keys = array();
    if ($record) {
      if ($this->itemExists($collection, $record->eid, $record->entity_type, $contexts)) {
        $primary_keys = array('eid', 'name');
      }
      drupal_write_record('entity_collection_storage', $record, $primary_keys);
    }
    $i = 0;
    foreach ($tree->getChildren() as $node) {
      $this->save($collection, $node, $contexts, $i, $depth + 1);
      $i++;
    }
  }

  /**
   * Settings for this storage engine.
   */
  function bundleSettingsForm($bundle, &$form, &$form_state) {
    $form['store_entity'] = array(
      '#type' => 'checkbox',
      '#title' => t('Store full entity'),
      '#default_value' => isset($bundle->settings['store_entity']) ? $bundle->settings['store_entity'] : FALSE,
      '#description' => t('Store the full entity in the entity collection table.
       This is performant in some cases, but it also requires you to set up your
       cache invalidation settings.'),
    );
  }

  /**
   * Append a new item to the entity_collection.
   * @param string $name
   * @param EntityCollectionTreeNode $item
   */
  public function appendItem(EntityCollection $collection, EntityCollectionTreeNode $item, $contexts = array()) {
    // Fetch the last position.
    $query = db_select('entity_collection_storage', 'rs');
    $query->addField('rs', 'position');
    $query->orderBy('position', 'DESC');
    $query->condition('parent', isset($item->parent) && isset($item->parent->entity_id) ? $item->parent->entity_id : 0);
    $query->condition('name', $collection->name);
    if (empty($item->position)) {
      $position = $query->execute()->fetchField();
      if ($position > 0) {
        $position++;
      }
      $item->position = $position;
    }
    $this->save($collection, $item, $contexts, $item->position, 1);
  }

  /**
   * @see EntityCollectionStorageInterface::getRecord().
   */
  protected function getRecord(EntityCollection $collection, EntityCollectionTreeNode $item, $position = 0, $contexts = array(), $depth = 0) {
    if (isset($item->content)) {
      $record = new stdClass();
      $record->name = $collection->name;
      if (!empty($collection->settings->store_entity)) {
        $record->entity = serialize($item->content);
      }
      $record->entity_type = $item->type;
      $record->eid = $item->entity_id;
      $record->depth = $depth;
      $record->style = $item->style;
      $record->hide_summary = $item->hide_summary;
      $record->parent = isset($item->parent) && isset($item->parent->key) ? $item->parent->key : 0;
      $record->position = $item->position;
      $record->contexts = $this->serializeContexts($contexts);
      return $record;
    }
    return FALSE;
  }

  /**
   * Check if an item already exists in the database.
   */
  protected function itemExists(EntityCollection $collection, $entity_id, $type, $contexts = array()) {
    return db_select('entity_collection_storage', 'rs')
      ->fields('rs', array('eid'))
      ->condition('eid', $entity_id)
      ->condition('name', $collection->name)
      ->condition('entity_type', $type)
      ->condition('contexts', $this->serializeContexts($contexts))
      ->execute()->fetchField();
  }

  /**
   * Execute an EntityCollectionQuery
   * @param EntityCollectionQuery a query to execute.
   */
  public function executeQuery(EntityCollectionQuery $query) {
    $db_query = db_select('entity_collection_storage', 'ecs')
      ->fields('ecs', array('name'));
    $bundle_conditions = $query->getBundleConditions();
    $entity_conditions = $query->getEntityConditions();
    $collection_conditions = $query->getCollectionConditions();
    $contexts = $query->getContexts();
    if (!empty($bundle_conditions)) {
      $db_query->innerJoin('entity_collection_collections', 'ec', 'ec.name = ecs.name');
      foreach ($bundle_conditions as $condition) {
        $db_query->condition('ec.bundle', $condition['value'], $condition['operator']);
      }
    }
    if (!empty($contexts)) {
      $db_query->condition('ecs.contexts', $this->serializeContexts($contexts));
    }
    foreach ($entity_conditions as $condition) {
      $and_condition = db_and()
        ->condition('ecs.entity_type', $condition['entity_type'], '=')
        ->condition('ecs.eid', $condition['entity_ids'], $condition['operator']);
      $db_query->condition($and_condition);
    }
    foreach ($collection_conditions as $condition) {
      $db_query->condition('ecs.name', $condition['value'], $condition['operator']);
    }
    return $db_query->execute()->fetchCol();
  }

  /**
   * Retreive a entity_collection.
   * @param string $name
   */
  public function retrieve(EntityCollection $collection, $contexts = NULL) {
    // Serialize the context arguments into a string.
    $query = db_select('entity_collection_storage', 'rs')
      ->fields('rs')
      ->condition('name', $collection->name, '=')
      ->orderBy('depth')
      ->orderBy('position');
    if (!isset($contexts) && isset($collection->contexts)) {
      $contexts = $collection->contexts;
    }
    if (isset($contexts)) {
      $query->condition('contexts', $this->serializeContexts($contexts));
    }
    $result = $query->execute();
    $tree = new EntityCollectionTreeNode();
    $bundle = entity_collection_bundle_load($collection->bundle);
    foreach ($result as $value) {
      $entity = NULL;
      if (!empty($value->parent)) {
        $node = $tree->getChild($value->parent);
      }
      if (empty($node)) {
        $node = $tree;
      }
      if (!empty($bundle->settings['store_entity'])) {
        $entity = unserialize($value->entity);
      }
      $node->addChild($value->entity_type, $value->eid, $entity, $value->style, $value->hide_summary, $value->rsid, $value->position);
    }
    // Load all entities
    // and make sure we only do as few entity_loads as possible.
    if (empty($bundle->settings['store_entity'])) {
      $nodes = $tree->getFlat();
      $entities = array();
      foreach ($nodes as $node) {
        $entities[$node->type][$node->key] = $node->entity_id;
      }
    }
    foreach ($entities as $type => $ids) {
      $loaded_entities = entity_load($type, $ids);
      foreach ($ids as $key => $id) {
        $nodes[$tree->getChildKey($type, $id)]->content = $loaded_entities[$id];
      }
    }
    return $tree;
  }

  /**
   * Serialize contexts so that they form a materialized path as a string.
   */
  protected function serializeContexts($contexts) {
    $serialized = array();
    foreach ($contexts as $context) {
      if (isset($context->argument)) {
        $serialized[] = $context->argument;
      }
    }
    return implode(':', $serialized);
  }

  /**
   * @see EntityCollectionStorageInterface::delete().
   */
  public function delete(EntityCollection $collection, $entity_type, array $entries, $contexts = NULL) {
    $query = db_delete('entity_collection_storage')
      ->condition('name', $collection->name)
      ->condition('entity_type', $entity_type)
      ->condition('eid', $entries);
    if (isset($contexts)) {
      $query->condition('contexts', $this->serializeContexts($contexts));
    }
    $query->execute();
  }

  /**
   * Drop an entire entity_collection.
   * @param type $names
   */
  public function drop(EntityCollection $collection) {
    db_delete('entity_collection_storage')
      ->condition('name', $collection->name)
      ->execute();
  }
}
