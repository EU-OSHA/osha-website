<?php

/**
 * @file
 * Contains Drupal_SolrDevel_ApacheSolr_Adapter.
 */

/**
 * Apache Solr Search Integration's implementation of the Solr Devel adapter.
 */
class Drupal_SolrDevel_Adapter_ApacheSolr extends Drupal_SolrDevel_Adapter {

  /**
   * Helper function to search by unique identifier.
   *
   * @param int $entity_id
   *   The unique identifier of the entity.
   * @param string $entity_type
   *   The machine name of the entity.
   *
   * @return stdClass
   *   The response object.
   */
  public function searchByIdentifier($entity_id, $entity_type) {
    $solr = apachesolr_get_solr($this->getOption('env_id'));
    $id = apachesolr_document_id($entity_id, $entity_type);
    $params = array('fq' => 'id:' . $id);
    return $solr->search('', $params);
  }

  /**
   * Extracts the Apache Solr Search Integration environment ID from the Solr
   * Devel environment name.
   *
   * @param array $environment
   *   The environment definition as returned by solr_devel_environment_load().
   *
   * @return string
   *   The Apache Solr Search Integration environment ID.
   */
  public function getEnvId(array $environment) {
    return ltrim(strstr($environment['name'], ':'), ':');
  }

  /**
   * Implements Drupal_SolrDevel_Adapter::entityIndexed().
   */
  public function entityIndexed($entity_id, $entity_type) {
    try {
      $response = $this->searchByIdentifier($entity_id, $entity_type);
      return (bool) $response->response->numFound;
    }
    catch (Exception $e) {
      $this->setError($e->getMessage());
      return FALSE;
    }
  }

  /**
   * Implements Drupal_SolrDevel_Adapter::getEntity().
   *
   * @see apachesolr_devel().
   */
  public function getEntity($entity_id, $entity_type, array $environment) {
    module_load_include('inc', 'apachesolr', 'apachesolr.index');

    // Intialize the "entity".
    $item = new stdClass();
    $item->entity_id = $entity_id;
    $item->entity_type = $entity_type;

    // Get documents being indexed.
    $debug = array();
    $documents = apachesolr_index_entity_to_documents($item, $this->getEnvId($environment));
    foreach ($documents as $document) {
      $debug_data = array();
      foreach ($document as $key => $value) {
        $debug_data[$key] = $value;
      }
      $debug[] = $debug_data;
    }

    // Don't next the array if we don't have to.
    return (!isset($debug[1])) ? $debug[0] : $debug;
  }

  /**
   * Implements Drupal_SolrDevel_Adapter::getDocument().
   */
  public function getDocument($entity_id, $entity_type) {
    try {
      $response = $this->searchByIdentifier($entity_id, $entity_type);
      $doc_returned = isset($response->response->docs[0]);
      return ($doc_returned) ? $response->response->docs[0] : FALSE;
    }
    catch (Exception $e) {
      $this->setError($e->getMessage());
      return FALSE;
    }
  }

  /**
   * Implements Drupal_SolrDevel_Adapter::getSearchPageOptions().
   */
  public function getSearchPageOptions(array $environment) {
    $options = array();
    $sql = 'SELECT page_id, label FROM {apachesolr_search_page} WHERE env_id = :env_id';
    $result = db_query($sql, array(':env_id' => $this->getEnvId($environment)));
    foreach ($result as $record) {
      $options[$record->page_id] = check_plain($record->label);
    }
    return $options;
  }

  /**
   * Implements Drupal_SolrDevel_Adapter::analyzeQuery().
   */
  public function analyzeQuery($keys, $page_id, $entity_id, $entity_type) {
    $search_page = apachesolr_search_page_load($page_id);
    $conditions = apachesolr_search_conditions_default($search_page);
    $solr = apachesolr_get_solr($search_page['env_id']);

    // Sets default parameters.
    $params = array(
      'q' => $keys,
      'fq' => isset($conditions['fq']) ? $conditions['fq'] : array(),
      'rows' => 1,
    );
    $params['fq'][] = 'id:' . apachesolr_document_id($entity_id, $entity_type);

    $results = apachesolr_search_run('apachesolr', $params, '', '', 0, $solr);
    return isset($results[0]) ? $results[0] : array();
  }

  /**
   * Implements Drupal_SolrDevel_Adapter::getQueue().
   */
  public function getQueue($entity_id, $bundle, $entity_type) {
    return new Drupal_SolrDevel_Queue_ApacheSolr($this, $entity_id, $bundle, $entity_type);
  }
}
