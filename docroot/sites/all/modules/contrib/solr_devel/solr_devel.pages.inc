<?php

/**
 * @file
 * Page callbacks for the Solr Devel module.
 */

/**
 * Initializes the render array for analysis pages.
 *
 * @param string $title
 *   The title of the page.
 *
 * @return array
 *   The initialized render array.
 */
function solr_devel_init_build($title = '') {
  $build = array(
    '#attached' => array(
      'css' => array(drupal_get_path('module', 'solr_devel') . '/solr_devel.css')
    ),
  );

  // Adds link to return to overview page.
  if ($return = solr_devel_get_return()) {
    $build['link'] = array(
      '#type' => 'link',
      '#title' => t('Go back to Solr index overview'),
      '#href' => $return,
      '#attributes' => array('class' => array('solr-devel-overview-link')),
      '#weight' => -100,
    );
  }

  return $build;
}

/**
 * Helper function to safely get the "return" attribute.
 *
 * @return string|FALSE
 *   The return attribute, FALSE if it doesn't exist or is external.
 */
function solr_devel_get_return() {
  return (isset($_GET['return']) && !url_is_external($_GET['return'])) ? $_GET['return'] : FALSE;
}

/**
 * Node debugging page callback.
 *
 * @param $node
 *   The node being rendered.
 *
 * @return array
 *   The render array.
 */
function solr_devel_node_overview_page(stdClass $node) {
  return solr_devel_get_entity_table($node->nid, $node->type, 'node');
}

/**
 * Gets Solr devel information for an entity.
 *
 * @param int $entity_id
 *   The unique identifier of the entity.
 * @param string $bundle
 *   The entity's bundle.
 * @param string $entity_type
 *   The machine name of the entity.
 */
function solr_devel_get_entity_table($entity_id, $bundle, $entity_type) {
  $build = solr_devel_init_build();

  $rows = array();
  $environments = solr_devel_get_environment_info();
  foreach ($environments as $id => $environment) {
    $adapter = solr_devel_adapter_load($environment);

    $indexed = $adapter->entityIndexed($entity_id, $entity_type);
    $queued = $adapter->getQueue($entity_id, $bundle, $entity_type)->getStatus();

    $row = array(
      'environment' => check_plain($adapter->getLabel()),
      'indexed' => $indexed ? t('Yes') : t('No'),
      'queued' => $queued ? t('Yes') : t('No'),
      'operations' => '',
    );

    // Initialize operations, get the return path.
    $operations = array();
    $return = array('return' => current_path());

    $operations['entity'] = array(
      'title' => t('analyze entity'),
      'href' => $entity_type . '/' . $entity_id . '/devel/solr/' . $id . '/entity',
      'query' => $return,
    );

    if ($indexed) {
      $operations['document'] = array(
        'title' => t('analyze document'),
        'href' => $entity_type . '/' . $entity_id . '/devel/solr/' . $id . '/document',
        'query' => $return,
      );
    }

    $operations['query'] = array(
      'title' => t('analyze query'),
      'href' => $entity_type . '/' . $entity_id . '/devel/solr/' . $id . '/query',
      'query' => $return,
    );

    $operations['queue'] = array(
      'title' => t('analyze queue'),
      'href' => $entity_type . '/' . $entity_id . '/devel/solr/' . $id . '/queue',
      'query' => $return,
    );

    $row['operations'] = array(
      'data' => array(
        '#theme' => 'links__node_operations',
        '#links' => $operations,
        '#attributes' => array('class' => array('links', 'inline')),
      ),
    );

    $rows[] = $row;
  }

  $header = array(
    'environment' => t('Environment'),
    'indexed' => t('Indexed'),
    'queued' => t('Queued for indexing'),
    'operations' => t('Operations'),
  );

  $build['index_stats'] = array(
    '#theme' => 'table',
    '#rows' => $rows,
    '#header' => $header,
    '#attributes' => array('class' => array('solr-devel-overview')),
  );

  return $build;
}

/**
 * Prints debug information about the queue.
 *
 * @param stdClass $node
 *   The node being rendered.
 * @param array $environment
 *   The environment definition.
 *
 * @return array
 *   The render array.
 */
function solr_devel_node_queue_analysis_page(stdClass $node, array $environment) {
  $build = solr_devel_init_build();

  $adapter = solr_devel_adapter_load($environment);
  $debug = $adapter->getQueue($node->nid, $node->type, 'node')->getDebug();
  $markup = (is_array($debug)) ? kprint_r($debug, TRUE) : $debug;
  $build['debug'] = array('#markup' => $markup);

  return $build;
}

/**
 * Prints debug information about the document in the Solr index related to the
 * node.
 *
 * @param stdClass $node
 *   The node being rendered.
 * @param array $environment
 *   The environment definition.
 *
 * @return array
 *   The render array.
 */
function solr_devel_node_document_analysis_page(stdClass $node, array $environment) {
  $build = solr_devel_init_build();

  $adapter = solr_devel_adapter_load($environment);
  $document = $adapter->getDocument($node->nid, 'node');
  $build['document'] = array('#markup' => kprint_r($document, TRUE));

  return $build;
}

/**
 * Allows users to enter a search query for analysis on how the results would
 * be returned.
 *
 * @param stdClass $node
 *   The node being rendered.
 * @param array $environment
 *   The environment definition.
 *
 * @ingroup forms.
 */
function solr_devel_node_query_analysis_form($form, &$form_state, stdClass $node, array $environment) {
  $form += solr_devel_init_build();

  $adapter = solr_devel_adapter_load($environment);
  $query = (isset($_GET['query'])) ? $_GET['query'] : '';
  $page = (isset($_GET['page'])) ? $_GET['page'] : '';

  $page_options = $adapter->getSearchPageOptions($environment);
  $form['page'] = array(
    '#title' => t('Search page'),
    '#access' => !empty($page_options),
    '#type' => 'select',
    '#options' => $page_options,
    '#default_value' => $page,
    '#weight' => -50,
  );

  $form['query'] = array(
    '#title' => t('Search query'),
    '#type' => 'textfield',
    '#default_value' => $query,
    '#weight' => -40,
  );

  $form['actions'] = array(
    '#type' => 'actions',
    '#weight' => -30,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit query'),
    '#submit' => array('solr_devel_node_query_analysis_form_submit'),
  );

  $return = solr_devel_get_return();
  $options = ($return) ? array('query' => array('return' => $return)) : array();
  $form['actions']['clear'] = array(
    '#type' => 'link',
    '#title' => t('Clear query'),
    '#href' => 'node/' . $node->nid . '/devel/solr/' . $environment['name'] . '/query',
    '#options' => $options,
  );

  $form['return'] = array(
    '#type' => 'value',
    '#value' => $return,
  );

  // Executes Solr query.
  if ($query && $page) {
    // Force the debugQuery parameter to be set.
    $force = &drupal_static('solr_devel_force_query_alter', FALSE);
    $force = TRUE;

    // Executes search query that targets this entity specifically.
    if ($results = $adapter->analyzeQuery($query, $page, $node->nid, 'node')) {
      $form['results'] = array('#markup' => kprint_r($results, TRUE));
    }
    else {
      $form['results'] = array('#markup' => '<p>' . t('The search query did not match this entity.') . '</p>');
    }
  }

  return $form;
}

/**
 * Allows users to see how the node is rendered for indexing.
 *
 * @param stdClass $node
 *   The node being rendered.
 * @param array $environment
 *   The environment definition.
 *
 * @ingroup forms.
 */
function solr_devel_node_entity_analysis_page(stdClass $node, array $environment) {
  $build = solr_devel_init_build();

  $adapter = solr_devel_adapter_load($environment);
  $entity = $adapter->getEntity($node->nid, 'node', $environment);
  $build['entity'] = array('#markup' => kprint_r($entity, TRUE));

  return $build;
}

/**
 * Form submission handler for solr_devel_node_query_analysis_form().
 */
function solr_devel_node_query_analysis_form_submit($form, &$form_state) {
  $options = array();

  if (!empty($form_state['values']['page'])) {
    $options['query']['page'] = $form_state['values']['page'];
  }
  if (!empty($form_state['values']['query'])) {
    $options['query']['query'] = $form_state['values']['query'];
  }
  if (!empty($form_state['values']['return'])) {
    $options['query']['return'] = $form_state['values']['return'];
  }

  $form_state['redirect'] = array(current_path(), $options);
}
