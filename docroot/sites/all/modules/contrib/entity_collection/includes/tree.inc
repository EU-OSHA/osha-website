<?php
/**
 * @file
 * This file contains an implementation of a tree.
 */

/**
 * This class is an implementation of a tree of entities.
 */
class EntityCollectionTreeNode {
  public $type;
  public $entity_id;
  public $key;
  public $parent;
  public $root;
  public $content;
  public $style;
  public $position = 0;
  public $children = array();
  public $list = array();

  /**
   * Construct a tree node object.
   * @param $type
   *   The entity type
   * @param $entity_id
   *   The entity id.
   * @param content
   *   The entity object.
   * @param style
   *   The style to render with.
   */
  public function __construct($type = NULL, $entity_id = NULL, $content = NULL, $style = NULL) {
    $this->type = $type;
    $this->root = $this;
    $this->entity_id = $entity_id;
    $this->content = $content;
    $this->style = $style;
    if (isset($entity_id) && isset($type)) {
      $this->key = $type . ':' . $entity_id;
    }
  }

  /**
   * Clone the tree node object.
   */
  public function __clone() {
    $this->root = $this;
  }

  /**
   * Add a child to this node. This is a helper for addChildNode.
   * @param string $name
   * @param stdClass $content
   */
  public function addChild($type, $entity_id, $content, $style = NULL, $hide_summary = NULL, $key = NULL, $position = NULL) {
    $node = new EntityCollectionTreeNode($type, $entity_id, $content, $style);
    $node->position = isset($position) ? $position : count($this->children);
    $node->hide_summary = $hide_summary;
    $node->parent = $this;
    return $this->addChildNode($node);
  }

  /**
   * Add a node as a child to this node.
   * @param EntityCollectionTreeNode $child
   */
  public function addChildNode(EntityCollectionTreeNode $child) {
    if (!isset($this->children)) {
      $this->children = array();
    }
    $child->root = $this->root;
    $child->key = $key = $this->getNodeKey($child);
    $this->root->list[$key] = $child;
    $this->children[$key] = $child;
    return $child;
  }

  /**
   * Remove a child from the tree.
   */
  public function removeChild(EntityCollectionTreeNode $child) {
    $key = $this->getNodeKey($child);
    unset($this->root->list[$key]);
    unset($this->children[$key]);
  }

  /**
   * Get a child by key.
   * Use EntityCollcetionTreeNode::getChildKey() to get a key.
   */
  public function getChild($key, $deep_search = TRUE) {
    // Return the child if it exists.
    if (isset($this->children[$key])) {
      return $this->children[$key];
    }
    // Return FALSE if this branch has no children
    // or if we don't want to travserse the tree.
    if (!$deep_search || !count($this->children)) {
      return FALSE;
    }
    foreach ($this->children as $node) {
      $result = $node->getChild($key);
      if (!empty($result)) {
        return $result;
      }
    }
    return FALSE;
  }

  /**
   * Return a flat list of the tree.
   * @return array<EntityCollectionTreeNode>
   *   A list of tree nodes.
   */
  public function getFlat($offset = 0, $length = NULL) {
    return array_slice($this->list, $offset, $length == 0 ? NULL : $length);
  }

  /**
   * Slice away items in tree to the offset and length provided.
   * @return array<EntityCollectionTreeNode>
   */
  public function splice($offset = 0, $length = NULL) {
    $marked_remove = array_diff_key($this->list, $this->getFlat($offset, $length));
    foreach($marked_remove as $child) {
      $this->removeChild($child);
      $key = $this->getNodeKey($child);
      unset($this->list[$key]);
    }
    return $this;
  }

  /**
   * Get the last child in the tree.
   */
  public function getLastChild() {
    return end($this->children);
  }

  /**
   * Get a child key based on entity type and entity id.
   */
  public function getChildKey($entity_type, $entity_id) {
    return $entity_type . ':' . $entity_id;
  }

  /**
   * Get a node key.
   */
  public function getNodeKey(EntityCollectionTreeNode $node) {
    return $node->type . ':' . $node->entity_id;
  }

  /**
   * Get the key of the last child.
   */
  public function getLastChildKey() {
    return end(array_keys($this->children));
  }

  /**
   * Truncate the tree.
   */
  public function truncate() {
    $this->children = array();
  }

  /**
   * Get the children of the this node.
   */
  public function getChildren() {
    return $this->children;
  }

  /**
   * Get the total count of items in this tree.
   * @return the total number of items in this tree.
   */
  function totalCount() {
    return count($this->list);
  }

  /**
   * Return this node as an array.
   */
  public function toArray() {
    $tree = array();
    foreach ($this->children as $key => $child) {
      $tree[$key]['content'] = $child->content;
      $tree[$key]['children'] = $child->toArray();
    }
    return $tree;
  }
}
