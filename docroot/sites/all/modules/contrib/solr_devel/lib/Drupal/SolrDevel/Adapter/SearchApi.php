<?php

/**
 * @file
 * Contains Drupal_SolrDevel_SearchApi_Adapter.
 */

/**
 * Search API's implementation of the Solr Devel adapter.
 */
class Drupal_SolrDevel_Adapter_SearchApi extends Drupal_SolrDevel_Adapter {

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
    $server = search_api_server_load($this->getOption('server_id'));
    $site_hash = !empty($server->options['site_hash']) ? search_api_solr_site_hash() . '-' : '';
    $id = $site_hash . $this->getOption('index_id') . '-' . $entity_id;
    $connection = $server->getSolrConnection();
    $params = array(
      'fq' => array('id:' . $id)
    );
    $result = $connection->search(NULL, $params);
    return $result;
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
   * Returns the entity as it built for indexing.
   *
   * @param int $entity_id
   *   The unique identifier of the entity.
   * @param string $entity_type
   *   The machine name of the entity.
   * @param array $environment
   *   The environment definition as returned by solr_devel_environment_load().
   *
   * @return mixed
   *
   * @see apachesolr_devel().
   */
  public function getEntity($entity_id, $entity_type, array $environment) {
    // Intialize the "entity".
    // Get documents being indexed.
    $debug = array();
    $index = search_api_index_load($this->getOption('index_id'));
    $items = $index->loadItems(array($entity_id));

    $documents = $items;

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
   * Returns an array of "search page" options.
   *
   * @param array $environment
   *   The environment definition as returned by solr_devel_environment_load().
   *
   * @return array
   *   An array of sanitized options that can be used directly as the #options
   *   property in a FAPI element.
   */
  public function getSearchPageOptions(array $environment) {
    // TODO: Implement getSearchPageOptions() method.
    $options = array();
    return $options;
  }

  /**
   * Implements Drupal_SolrDevel_Adapter::analyzeQuery().
   *
   * Executes a search and anylizes a document.
   *
   * @param string $keys
   *   The keywords submitted through the form.
   * @param string $page_id
   *   The unique identifier of the search page.
   * @param int $entity_id
   *   The unique identifier of the entity.
   * @param string $entity_type
   *   The machine name of the entity.
   *
   * @return array
   *   The results, an empty array of the search did not match the node.
   */
  public function analyzeQuery($keys, $page_id, $entity_id, $entity_type) {
    // TODO: Implement analyzeQuery() method.
    return array();
  }

  /**
   * Implements Drupal_SolrDevel_Adapter::getQueue().
   *
   * Gets the queue object for the passed entity.
   *
   * The queue object check's the backend's queue for the passed entity and
   * returns debug information to help determing why the item is or isn't queued
   * for indexing.
   *
   * @param int $entity_id
   *   The unique identifier of the entity.
   * @param string $bundle
   *   The entity's bundle.
   * @param string $entity_type
   *   The machine name of the entity.
   *
   * @return Drupal_SolrDevel_Queue
   *   The queue object.
   */
  public function getQueue($entity_id, $bundle, $entity_type) {
    return new Drupal_SolrDevel_Queue_SearchApi($this, $entity_id, $bundle, $entity_type);
  }

}
