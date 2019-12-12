<?php

/**
 * @file
 * Contains Drupal_SolrDevel_Adapter.
 */

/**
 * Base adapter class to abstract various debug functionality.
 */
abstract class Drupal_SolrDevel_Adapter {

  /**
   * The label of the environment this adapter is associated with.
   *
   * @var string
   */
  protected $_label;

  /**
   * An array of options, usually containing contextual information about the
   * index or server this adapter is associated with.
   *
   * @var array
   */
  protected $_options;

  /**
   * Captures any error encountered during index connections.
   *
   * @var string
   */
  protected $_error = '';

  /**
   * Constructs a Drupal_SolrDevel_Adapter object.
   *
   * @param string $label
   *   The label of the environment this adapter is associated with.
   * @param array $options
   *   An array of options, usually containing contextual information about the
   *   index or server this adapter is associated with.
   */
  public function __construct($label, array $options = array()) {
    $this->_label = $label;
    $this->_options = $options;
  }

  /**
   * Returns the human readable label of the environment associated with this
   * adapter.
   *
   * @return string
   */
  public function getLabel() {
    return $this->_label;
  }

  /**
   * Returns an option or a default value if the option is not set.
   *
   * @param string $name
   *   The name of the option, which is the array key of the class property
   *   Drupal_SolrDevel_Adapter::_options.
   * @param mixed $default
   *   (optional) The default if the option doesn't exist. Defaults to NULL.
   *
   * @return mixed
   *   The option being requested.
   */
  public function getOption($name, $default = NULL) {
    return (isset($this->_options[$name])) ? $this->_options[$name] : $default;
  }

  /**
   * Sets an option for this instance.
   *
   * @param string $name
   *   The name of the option, which is the array key of the class property
   *   Drupal_SolrDevel_Adapter::_options.
   * @param mixed $value
   *   The value being stored as an option.
   *
   * @return Drupal_SolrDevel_Adapter
   *   An instance of this class.
   */
  public function setOption($name, $value) {
    $this->_options[$name] = $value;
    return $this;
  }

  /**
   * Returns any error encountered connecting to the index.
   *
   * @return string
   */
  public function getError() {
    return $this->_error;
  }

  /**
   * Sets an error message.
   *
   * @param string $error
   *   The error being set.
   *
   * @return Drupal_SolrDevel_Adapter
   *   An instance of this class.
   */
  public function setError($error) {
    $this->_error = $error;
    return $this;
  }

  /**
   * Tests whether an entity is indexed.
   *
   * @param int $entity_id
   *   The unique identifier of the entity.
   * @param string $entity_type
   *   The machine name of the entity.
   *
   * @return boolean
   *   TRUE if the entity is indexed, FALSE otherwise.
   */
  abstract public function entityIndexed($entity_id, $entity_type);

  /**
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
  abstract public function getQueue($entity_id, $bundle, $entity_type);

  /**
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
   */
  abstract public function getEntity($entity_id, $entity_type, array $environment);

  /**
   * Returns the document as stored in the Solr index.
   *
   * @param int $entity_id
   *   The unique identifier of the entity.
   * @param string $entity_type
   *   The machine name of the entity.
   *
   * @return mixed
   */
  abstract public function getDocument($entity_id, $entity_type);

  /**
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
  abstract public function analyzeQuery($keys, $page_id, $entity_id, $entity_type);

  /**
   * Returns an array of "search page" options.
   *
   * @param array $environment
   *   The environment definition as returned by solr_devel_environment_load().
   *
   * @return array
   *   An array of sanitized options that can be used directly as the #options
   *   property in a FAPI element.
   */
  abstract public function getSearchPageOptions(array $environment);
}
