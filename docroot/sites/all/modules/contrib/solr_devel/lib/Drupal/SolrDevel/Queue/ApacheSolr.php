<?php

/**
 * @file
 * Contains Drupal_SolrDevel_Queue_ApacheSolr.
 */

/**
 * Debugs an entity's status in the indexing queue.
 *
 * Breaks up the queue process into parts so we can analyze it. Stores debug
 * data so developers can determined why an entity is or isn't queued for
 * indexing.
 */
class Drupal_SolrDevel_Queue_ApacheSolr extends Drupal_SolrDevel_Queue {

  /**
   * Implements Drupal_SolrDevel_Queue::run().
   */
  public function run() {
    $queued = TRUE;
    $env_id = $this->_adapter->getOption('env_id');

    // Initialize the debug array.
    $this->_debug = array(
      'read_only' => FALSE,
      'bundle_excluded' => FALSE,
      'in_table' => TRUE,
      'processed' => FALSE,
      'status_callbacks' => array(),
      'status_callbacks_skipped' => array(),
      'exclude_hooks' => array(),
    );

    // Return FALSE if index is read only.
    if (variable_get('apachesolr_read_only', 0)) {
      $this->_debug['read_only'] = TRUE;
      $queued = FALSE;
    }

    // Get bundles that are allowed to be indexed.
    $bundles = drupal_map_assoc(
      apachesolr_get_index_bundles($env_id, $this->_entityType)
    );

    // Checks whether the bundle is excluded.
    if (!isset($bundles[$this->_bundle])) {
      $this->_debug['bundle_excluded'] = TRUE;
      $queued = FALSE;
    }

    // Get $last_entity_id and $last_changed.
    extract(apachesolr_get_last_index_position($env_id, $this->_entityType));
    $table = apachesolr_get_indexer_table($this->_entityType);

    // Build the queue query.
    $query = db_select($table, 'aie')
      ->fields('aie')
      ->condition('aie.bundle', $bundles)
      ->condition('entity_id', $this->_entityId)
      ->condition(db_or()
        ->condition('aie.changed', $last_changed, '>')
        ->condition(db_and()
          ->condition('aie.changed', $last_changed, '<=')
          ->condition('aie.entity_id', $last_entity_id, '>')
         )
       );

    // Entity-specific tables don't need this condition.
    if ($table == 'apachesolr_index_entities') {
      $query->condition('aie.entity_type', $this->_entityType);
    }

    // If no records are returned, the item has been processed.
    if (!$record = $query->execute()->fetch()) {
      $this->_debug['processed'] = TRUE;
      $queued = FALSE;
    }

    // Loads index include, which is where the default status callbacks live.
    module_load_include('inc', 'apachesolr', 'apachesolr.index');

    // Ensure entry is in table. If not, we have a problem.
    $query = db_select($table, 'aie')
      ->fields('aie', array('status'))
      ->condition('aie.entity_type', $this->_entityType)
      ->condition('aie.entity_id', $this->_entityId);

    // Invokes status callback to check whether entity should be excluded. For
    // example, the apachesolr_index_node_status_callback() tests if the node
    // status is 0, meaning it is unpublished.
    if ($record = $query->execute()->fetch()) {
      $status_callbacks = apachesolr_entity_get_callback($this->_entityType, 'status callback');
      if (is_array($status_callbacks)) {
        foreach ($status_callbacks as $status_callback) {
          if (is_callable($status_callback)) {
            $callback_value = $status_callback($this->_entityId, $this->_entityType);
            $record->status = $record->status && $callback_value;
            $this->_debug['status_callbacks'][$status_callback] = (!$callback_value); // FALSE
          }
          else {
            $this->_debug['status_callbacks_skipped'][$status_callback] = TRUE;
          }
        }
      }
    }
    else {
      // There is a problem with the queue if the data is not here.
      $this->_debug['in_table'] = FALSE;
      $queued = FALSE;
    }

    // Invoke hook_apachesolr_exclude().
    foreach (module_implements('apachesolr_exclude') as $module) {
      $function = $module . '_apachesolr_exclude';
      $exclude = module_invoke($module, 'apachesolr_exclude', $record->entity_id, $this->_entityType, $record, $env_id);
      if (!empty($exclude)) {
        $this->_debug['exclude_hooks'][$function] = TRUE;
        $queued = FALSE;
      }
      else {
        $this->_debug['exclude_hooks'][$function] = FALSE;
      }
    }

    // Invoke hook_apachesolr_ENTITY_TYPE_exclude().
    foreach (module_implements('apachesolr_' . $this->_entityType . '_exclude') as $module) {
      $function = $module . '_apachesolr_' . $this->_entityType . '_exclude';
      $exclude = module_invoke($module, 'apachesolr_' . $this->_entityType . '_exclude', $record->entity_id, $record, $env_id);
      if (!empty($exclude)) {
        $this->_debug['exclude_hooks'][$function] = TRUE;
        $queued = FALSE;
      }
      else {
        $this->_debug['exclude_hooks'][$function] = FALSE;
      }
    }

    return $queued;
  }

  /**
   * Overrides Drupal_SolrDevel_Queue::getDebug().
   *
   * Converts the debug data into a nicer table display.
   */
  public function getDebug() {

    // Initialize table variables.
    $variables = array(
      'attributes' => array(
        'class' => array('solr-devel-queue'),
      ),
      'header' => array(
        t('Criteria'),
        t('Status'),
        t('Description'),
      ),
      'rows' => array(),
    );

    $variables['rows'][] = array(
      array(
        'data' => '<strong>' . t('Index settings') . '</strong>',
        'colspan' => 3,
      )
    );

    $variables['rows'][] = array(
      'class' => (!$this->_debug['read_only']) ? array('solr-devel-ok') : array('solr-devel-error'),
      'data' => array(
        array(
          'data' => t('Index in read only mode'),
          'class' => array('solr-devel-criteria'),
        ),
        array(
          'data' => ($this->_debug['read_only']) ? t('Yes') : t('No'),
          'class' => array('solr-devel-status'),
        ),
        t('If the index is in <em>read only</em> mode, no content will be queued for indexing.')
      ),
    );

    $variables['rows'][] = array(
      'class' => (!$this->_debug['bundle_excluded']) ? array('solr-devel-ok') : array('solr-devel-error'),
      'data' => array(
        array(
          'data' => t('Bundle excluded from indexing'),
          'class' => array('solr-devel-criteria'),
        ),
        array(
          'data' => ($this->_debug['bundle_excluded']) ? t('Yes') : t('No'),
          'class' => array('solr-devel-status'),
        ),
        t('If the bundle is excluded from indexing, this entity will not be queued for indexing.')
      ),
    );

    $variables['rows'][] = array(
      'class' => ($this->_debug['in_table']) ? array('solr-devel-ok') : array('solr-devel-error'),
      'data' => array(
        array(
          'data' => t('Entity present in queue table'),
          'class' => array('solr-devel-criteria'),
        ),
        array(
          'data' => ($this->_debug['in_table']) ? t('Yes') : t('No'),
          'class' => array('solr-devel-status'),
        ),
        t('Apache Solr Search Integration stores its index queues in database tables. If this entity is not in the appropriate queue table, its entity type is either not configured to be indexed or the queue is corrupt.'),
      ),
    );

    $variables['rows'][] = array(
      array(
        'data' => '<strong>' . t('Index status') . '</strong>',
        'colspan' => 3,
      )
    );

    $variables['rows'][] = array(
      'class' => (!$this->_debug['processed']) ? array('solr-devel-ok') : array('solr-devel-error'),
      'data' => array(
        array(
          'data' => t('Entity sent to Solr for indexing'),
          'class' => array('solr-devel-criteria'),
        ),
        array(
          'data' => ($this->_debug['processed']) ? t('Yes') : t('No'),
          'class' => array('solr-devel-status'),
        ),
        t('Entities that have already been sent to Solr are no longer queued for indexing.')
      ),
    );

    if ($this->_debug['status_callbacks_skipped']) {
      $variables['rows'][] = array(
        array(
          'data' => '<strong>' . t('Status callbacks skipped') . '</strong>',
          'colspan' => 2,
        ),
        t('Some status callbacks could not be checked because the include file containing them is not loaded.'),
      );
      foreach ($this->_debug['status_callbacks_skipped'] as $callback => $skipped) {
        $variables['rows'][] = array(
          'class' => array('solr-devel-warning'),
          'data' => array(
            array(
              'data' => check_plain($callback) . '()',
              'class' => array('solr-devel-criteria'),
            ),
            array(
              'data' => t('Skipped'),
              'class' => array('solr-devel-status'),
            ),
            '',
          ),
        );
      }
    }

    if ($this->_debug['status_callbacks']) {
      $variables['rows'][] = array(
        array(
          'data' => '<strong>' . t('Status callbacks') . '</strong>',
          'colspan' => 2,
        ),
        t('Status callbacks determine the status of the entity, for example whether a node is published or not. If the status callback returns <em>0</em>, the entity will not be queued for indexing.'),
      );
      foreach ($this->_debug['status_callbacks'] as $callback => $excluded) {
        $variables['rows'][] = array(
          'class' => (!$excluded) ? array('solr-devel-ok') : array('solr-devel-error'),
          'data' => array(
            array(
              'data' => check_plain($callback) . '()',
              'class' => array('solr-devel-criteria'),
            ),
            array(
              'data' => ($excluded) ? t('Excluded') : t('Not excluded'),
              'class' => array('solr-devel-status'),
            ),
            '',
          ),
        );
      }
    }

    if ($this->_debug['exclude_hooks']) {
      $variables['rows'][] = array(
        array(
          'data' => '<strong>' . t('Exclude hooks') . '</strong>',
          'colspan' => 2,
        ),
        t('Exclude hooks allow modules to exclude entities from being indexed at index time.'),
      );
      foreach ($this->_debug['exclude_hooks'] as $hook => $excluded) {
        $variables['rows'][] = array(
          'class' => (!$excluded) ? array('solr-devel-ok') : array('solr-devel-error'),
          'data' => array(
            array(
              'data' => check_plain($hook) . '()',
              'class' => array('solr-devel-criteria'),
            ),
            array(
              'data' => ($excluded) ? t('Excluded') : t('Not excluded'),
              'class' => array('solr-devel-status'),
            ),
            '',
          ),
        );
      }
    }

    return theme('table', $variables);
  }
}
