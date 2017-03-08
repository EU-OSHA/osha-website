<?php

/**
 * @file
 * Contains the SearchApiEtDatasourceController class.
 */

/**
 * Provides multilingual versions of all entity types.
 */
class SearchApiEtDatasourceController extends SearchApiEntityDataSourceController {

  /**
   * Overrides SearchApiEntityDataSourceController::$table.
   *
   * Needed because we have a string ID, instead of a numerical one.
   *
   * @var string
   */
  protected $table = 'search_api_et_item';

  /**
   * {@inheritdoc}
   */
  public function getIdFieldInfo() {
    return array(
      'key' => 'search_api_et_id',
      'type' => 'string',
    );
  }

  /**
   * {@inheritdoc}
   */
  public function loadItems(array $ids) {
    $item_languages = array();
    foreach ($ids as $id) {
      // This method might receive two different types of item IDs depending on
      // where it is being called from. For example, when called from
      // search_api_index_specific_items(), it will receive multilingual IDs
      // (with language prefix, like "2/en"). On the other hand, when called from
      // a processor (for example from SearchApiHighlight::getFulltextFields()),
      // the IDs won't be multilingual (no language prefix), just standard
      // entity IDs instead. Therefore we need to account for both cases here.

      // Case 1 - language is in item ID.
      if (SearchApiEtHelper::isValidItemId($id)) {
        $entity_id = SearchApiEtHelper::splitItemId($id, SearchApiEtHelper::ITEM_ID_ENTITY_ID);
        $item_languages[$entity_id][] = SearchApiEtHelper::splitItemId($id, SearchApiEtHelper::ITEM_ID_LANGUAGE);
      }
      // Case 2 - no language in item ID.
      else {
        $item_languages[$id][] = NULL;
      }
    }

    $entities = entity_load($this->entityType, array_keys($item_languages));

    // If some items could not be loaded, remove them from tracking.
    if (count($entities) != count($item_languages)) {
      $unknown = array_keys(array_diff_key($item_languages, $entities));
      if ($unknown) {
        $deleted = array();
        foreach ($unknown as $entity_id) {
          foreach ($item_languages[$entity_id] as $language) {
            $deleted[] = SearchApiEtHelper::buildItemId($entity_id, $language);
          }
        }
        search_api_track_item_delete($this->type, $deleted);
      }
    }

    // Now arrange them according to our IDs again, with language.
    $items = array();
    foreach ($item_languages as $entity_id => $languages) {
      if (!empty($entities[$entity_id])) {
        foreach ($languages as $language) {
          // Following on the two cases described above, we should return
          // the same item IDs (with or without language prefix) as received.
          $entity = clone $entities[$entity_id];
          $id = !empty($language) ? SearchApiEtHelper::buildItemId($entity_id, $language) : $entity_id;
          $entity->search_api_et_id = $id;
          $entity->language = $language;
          $items[$id] = $entity;
        }
      }
    }

    return $items;
  }

  /**
   * {@inheritdoc}
   */
  public function getMetadataWrapper($item = NULL, array $info = array()) {
    // Since this is usually called with a "property info alter" callback
    // already in place (and only one value is allowed), we have to call
    // the existing callback from within our own callback to make it work.
    $property_info_alter = isset($info['property info alter']) ? $info['property info alter'] : NULL;
    $callback = new SearchApiEtPropertyInfoAlter($property_info_alter);
    $info['property info alter'] = array($callback, 'propertyInfoAlter');

    // If the item isn't the object and a multilingual id is provided
    // extract the entity id to load and wrap the entity.
    if (SearchApiEtHelper::isValidItemId($item)) {
      $item = SearchApiEtHelper::splitItemId($item, SearchApiEtHelper::ITEM_ID_ENTITY_ID);
    }

    $wrapper = entity_metadata_wrapper($this->entityType, $item, $info);

    // If the item's language is set, let's set it on all wrapper fields,
    // so that their translated values get indexed.
    if (!empty($item->search_api_language)) {
      // Set language on the wrapper as a whole.
      $wrapper->language($item->search_api_language);
      // Also try to set language on all wrapper fields, recursively.
      if (!empty($item->search_api_index)) {
        $this->setLanguage($wrapper, $item->search_api_index->options['fields'], $item->search_api_language);
      }
    }

    return $wrapper;
  }

  /**
   * Sets language of specific fields on an EntityMetadataWrapper object.
   *
   * This is essentially a copy of search_api_extract_fields(), just slightly
   * adapted to set language on the wrapper fields instead of extracting them.
   *
   * @param EntityMetadataWrapper $wrapper
   *   The wrapper on which fields to set language on.
   * @param array $fields
   *   The fields to set language on, as stored in an index. I.e., the array
   *   keys are field names, the values are arrays with at least a "type" key
   *   present.
   * @param array $langcode
   *   A code of the language to set to wrapper fields.
   *
   * @return array
   *   The $fields array with additional "value" and "original_type" keys set.
   *
   * @see SearchApiEtDatasourceController::getMetadataWrapper()
   * @see SearchApiEtDatasourceController::setLanguage()
   */
  protected function setLanguage($wrapper, $fields, $langcode) {
    // If $wrapper is a list of entities, we have to aggregate their field values.
    $wrapper_info = $wrapper->info();
    if (search_api_is_list_type($wrapper_info['type'])) {
      foreach ($fields as &$info) {
        $info['value'] = array();
        $info['original_type'] = $info['type'];
      }
      unset($info);
      try {
        foreach ($wrapper as $w) {
          $nested_fields = $this->setLanguage($w, $fields, $langcode);
          foreach ($nested_fields as $field => $info) {
            if (isset($info['value'])) {
              $fields[$field]['value'][] = $info['value'];
            }
            if (isset($info['original_type'])) {
              $fields[$field]['original_type'] = $info['original_type'];
            }
          }
        }
      }
      catch (EntityMetadataWrapperException $e) {
        // Catch exceptions caused by not set list values.
      }
      return $fields;
    }

    $nested = array();
    foreach ($fields as $field => $info) {
      $pos = strpos($field, ':');
      if ($pos === FALSE) {
        if (isset($wrapper->$field) && method_exists($wrapper->$field, 'language')) {
          $wrapper->$field->language($langcode);
        }
      }
      else {
        list($prefix, $key) = explode(':', $field, 2);
        $nested[$prefix][$key] = $info;
      }
    }
    foreach ($nested as $prefix => $nested_fields) {
      if (isset($wrapper->$prefix)) {
        $nested_fields = $this->setLanguage($wrapper->$prefix, $nested_fields, $langcode);
        foreach ($nested_fields as $field => $info) {
          $fields["$prefix:$field"] = $info;
        }
      }
      else {
        foreach ($nested_fields as &$info) {
          $info['value'] = NULL;
          $info['original_type'] = $info['type'];
        }
      }
    }
    return $fields;
  }

  /**
   * {@inheritdoc}
   */
  public function getItemId($item) {
    return isset($item->search_api_et_id) ? $item->search_api_et_id : NULL;
  }

  /**
   * Overrides SearchApiEntityDataSourceController::startTracking().
   *
   * Reverts the behavior to always use getAllItemIds(), instead of taking a
   * shortcut via "base table".
   *
   * This method will also be called when the multilingual configuration of an
   * index changes, to take care of new and/or out-dated IDs.
   */
  public function startTracking(array $indexes) {
    if (!$this->table) {
      return;
    }
    // We first clear the tracking table for all indexes, so we can just insert
    // all items again without any key conflicts.
    $this->stopTracking($indexes);

    $operations = array();

    // Find out number of all entities to be processed.
    foreach ($indexes as $index) {
      $entity_ids = $this->getTrackableEntityIds($index);
      $steps = ceil(count($entity_ids) / $index->options['cron_limit']);

      for ($step = 0; $step < $steps; $step++) {
        $operations[] = array(
          'search_api_et_batch_queue_entities',
          array($index, $entity_ids, $step),
        );
      }
    }

    // This might be called both from web interface as well as from drush.
    $t = drupal_is_cli() ? 'dt' : 't';

    $batch = array(
      'title' => $t('Adding items to the index queue'),
      'operations' => $operations,
      'finished' => 'search_api_et_batch_queue_entities_finished',
      'progress_message' => $t('Completed about @percentage% of the queueing operation.'),
      'file' => drupal_get_path('module', 'search_api_et') . '/search_api_et.batch.inc',
    );
    batch_set($batch);

    if (drupal_is_cli()) {
      // Calling drush_backend_batch_process() to start batch execution directly
      // from here doesn't work for some unknown reason, so we need to call it
      // from a shutdown function instead.
      drupal_register_shutdown_function('search_api_et_shutdown_batch_process');
    }
    else {
      batch_process();
    }
  }

  /**
   * {@inheritdoc}
   */
  public function trackItemInsert(array $item_ids, array $indexes) {
    $ret = array();
    foreach ($indexes as $index_id => $index) {
      // Sometimes we get item_ids not meant to be tracked, just filter them out.
      $ids = $this->filterTrackableIds($index, $item_ids);
      if ($ids) {
        // Some times the item could be already in the index, let try to remove
        // them before inserting.
        parent::trackItemDelete($ids, array($index));

        // Actually add the items to the index.
        parent::trackItemInsert($ids, array($index));
        $ret[$index_id] = $index;
      }
    }
    return $ret;
  }

  /**
   * {@inheritdoc}
   * @param $item_ids array|string
   * @param $indexes SearchApiIndex[]
   * @param $dequeue bool
   */
  public function trackItemChange($item_ids, array $indexes, $dequeue = FALSE) {
    // If this method was called from _search_api_index_reindex(), $item_ids
    // will be set to FALSE, which means we need to reindex all items, so no
    // need for any other processing below.
    if ($item_ids === FALSE) {
      parent::trackItemChange($item_ids, $indexes, $dequeue);
      return NULL;
    }

    $ret = array();
    foreach ($indexes as $index_id => $index) {
      // The $item_ids can contain a single EntityID if we get invoked from the
      // hook: search_api_et_entity_update(). In this case we need to, for each
      // Index, identify the set of ItemIDs that need to be marked as changed.
      // Check if we get Entity IDs or Item IDs.
      $ids = $this->getTrackableItemIdsFromMixedSource($index, $item_ids);

      if (!empty($ids)) {
        parent::trackItemChange($ids, array($index), $dequeue);
        $ret[$index_id] = $index;
      }
    }
    return $ret;
  }

  /**
   * Retrieves all Item IDs from the given index, filtered by the Entity IDs.
   *
   * Is used instead of SearchApiAbstractDataSourceController::getAllItemIds(),
   * since available items depend on the index configuration.
   *
   * @param SearchApiIndex $index
   *   The index for which item IDs should be retrieved.
   *
   * @param array $entity_ids
   *   The Entity IDs to get the ItemIDs for.
   *
   * @return array
   *   An array with all item IDs for a given index, with keys and values both
   *   being the IDs.
   */
  public function getTrackableItemIds(SearchApiIndex $index, $entity_ids = NULL) {
    $entity_ids = $this->getTrackableEntityIds($index, $entity_ids);

    if (empty($entity_ids)) {
      return array();
    }

    $ids = array();
    $entity_type = $index->getEntityType();
    $entities = entity_load($entity_type, $entity_ids);
    foreach ($entities as $entity_id => $entity) {
      foreach (search_api_et_item_languages($entity, $entity_type, $index) as $lang) {
        $item_id = SearchApiEtHelper::buildItemId($entity_id, $lang);
        $ids[$item_id] = $item_id;
      }
    }
    return $ids;
  }

  /**
   * {@inheritdoc}
   */
  public function trackItemDelete(array $item_ids, array $indexes) {
    $ret = array();
    foreach ($indexes as $index_id => $index) {
      // The $item_ids can contain also single EntityID if we get invoked from the
      // hook: search_api_et_entity_delete(). In this case we need to, for each
      // Index, identify the set of ItemIDs that need to be marked as changed.
      $ids = $this->getTrackableItemIdsFromMixedSource($index, $item_ids);

      if ($ids) {
        parent::trackItemDelete($ids, array($index));
        $ret[$index_id] = $index;
      }
    }
    return $ret;
  }

  /**
   * Helper function to return the list of ItemIDs, fiven
   * @param \SearchApiIndex $index
   * @param $mixed_ids
   * @return array
   */
  protected function getTrackableItemIdsFromMixedSource(SearchApiIndex $index, $mixed_ids) {
    // Check if we get Entity IDs or Item IDs.
    $first_item_id = reset($mixed_ids);
    $is_valid_item_id = SearchApiEtHelper::isValidItemId($first_item_id);
    if (!$is_valid_item_id) {
      $entity_id = $first_item_id;
      $ids = $this->getTrackableItemIds($index, $entity_id);
    }
    else {
      // Filter the item_ids that need to be tracked by this index.
      $ids = $this->filterTrackableIds($index, $mixed_ids);
    }

    return $ids;
  }

  /**
   * @param SearchApiIndex $index
   *   The index for which item IDs should be retrieved.
   * @param array $entity_ids
   *   The entity ids to get the trackable entity ids for.
   *
   * @return array
   *   An array with all trackable Entity IDs for a given index.
   */
  public function getTrackableEntityIds(SearchApiIndex $index, $entity_ids = NULL) {
    $entity_type = $index->getEntityType();
    if (!empty($this->entityInfo['base table']) && $this->idKey) {
      // Assumes that all entities use the "base table" property and the
      // "entity keys[id]" in the same way as the default controller.
      $table = $this->entityInfo['base table'];

      // Select all entity ids.
      $query = db_select($table, 't');
      $query->addField('t', $this->idKey);
      if ($bundles = $this->getIndexBundles($index)) {
        $query->condition($this->bundleKey, $bundles);
      }
      if ($entity_ids) {
        $query->condition($this->idKey, $entity_ids);
      }
      $ids = $query->execute()->fetchCol();
    }
    else {
      // In the absence of a 'base table', load the entities.
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', $entity_type);
      if ($bundles = $this->getIndexBundles($index)) {
        $query->entityCondition('bundle', $bundles);
      }
      if ($entity_ids) {
        $query->entityCondition('entity_id', $entity_ids);
      }
      $entities = $query->execute();
      $ids = array_keys($entities[$entity_type]);
    }
    return $ids;
  }

  /**
   * Filters the given Item IDs to include only the ones handled by the Index.
   *
   * @param SearchApiIndex $index
   *   The SearchAPI index to use
   * @param array $item_ids
   *   A list of trackable ItemID (in the form "{id}/{language}) to filter
   * @return array
   *   The filtered list of trackable ItemID
   */
  protected function filterTrackableIds(SearchApiIndex $index, $item_ids) {
    if (empty($item_ids)) {
      return array();
    }

    // Group the given ItemIds by their EntityId.
    $grouped_item_ids = SearchApiEtHelper::getGroupedItemsIdsByEntity($item_ids);
    if (empty($grouped_item_ids)) {
      return array();
    }

    // Generate the list of candidate ItemIDs from the current EntityIDs
    $trackable_item_ids = $this->getTrackableItemIds($index, array_keys($grouped_item_ids));

    // The $trackable_item_ids will contain all ItemIDs that should be indexed.
    // Additional translations, other than the one provided in $item_ids, will
    // be taken into account, to cover the case when a non-translatable field is
    // changed on one translation and such change must be reflected to all other
    // indexed translations.
    return $trackable_item_ids;
  }
}
