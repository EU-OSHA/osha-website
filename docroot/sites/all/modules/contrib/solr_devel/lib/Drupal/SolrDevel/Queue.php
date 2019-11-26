<?php

/**
 * @file
 * Contains Drupal_SolrDevel_Queue.
 */

/**
 * Interface that interacts with a backend module's queue.
 */
abstract class Drupal_SolrDevel_Queue {

  /**
   * The machine name of the environment.
   *
   * @var Drupal_SolrDevel_Adapter
   */
  protected $_adapter;

  /**
   * The unique identifier of the entity.
   *
   * @var int
   */
  protected $_entityId;

  /**
   * The entity's bundle.
   *
   * @var string
   */
  protected $_bundle;

  /**
   * The machine name of the entity.
   *
   * @var string
   */
  protected $_entityType;

  /**
   * Stores debug information.
   *
   * @var array
   */
  protected $_debug = array();

  /**
   * TRUE if the entity is queued for indexing, FALSE if not.
   *
   * @var boolean
   */
  protected $_status;

  /**
   * Constructs a Drupal_SolrDevel_Queue object.
   *
   * @param Drupal_SolrDevel_Adapter
   *   The adapter that instantiated this class.
   * @param int $entity_id
   *   The unique identifier of the entity.
   * @param string $bundle
   *   The entity's bundle.
   * @param string $entity_type
   *   The machine name of the entity.
   */
  public function __construct(Drupal_SolrDevel_Adapter $adapter, $entity_id, $bundle, $entity_type) {
    $this->_adapter = $adapter;
    $this->_entityId = $entity_id;
    $this->_bundle = $bundle;
    $this->_entityType = $entity_type;

    // Runs the queue for the entity.
    $this->_status = $this->run();
  }

  /**
   * Returns TRUE if the entity is queued for indexing, FALSE if not.
   *
   * @return array
   *   An associative array containing the debug information.
   */
  public function getStatus() {
    return $this->_status;
  }

  /**
   * Gets the debug information about the entity's status in the queue.
   *
   * @return array|string
   *   An associative array containing the debug information, or a string
   *   containing the HTML output.
   */
  public function getDebug() {
    return $this->_debug;
  }

  /**
   * Runs the queue for the entity.
   *
   * @return boolean
   *   Whether the entity is queued for indexing.
   */
  abstract public function run();
}
