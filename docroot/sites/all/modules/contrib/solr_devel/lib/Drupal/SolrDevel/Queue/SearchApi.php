<?php

/**
 * @file
 * Contains Drupal_SolrDevel_Queue_SearchApi.
 */

/**
 * Search API's implementation of the Solr Devel adapter.
 */
class Drupal_SolrDevel_Queue_SearchApi extends Drupal_SolrDevel_Queue {

  /**
   * Implements Drupal_SolrDevel_Queue::run().
   */
  public function run() {
    $queued = FALSE;

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
          'data' => ($this->_debug['in_table']) ? t('Yes') : t('Nod'),
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
