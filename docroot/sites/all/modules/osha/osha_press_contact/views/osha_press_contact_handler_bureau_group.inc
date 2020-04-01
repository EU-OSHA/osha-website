<?php

/**
 * Provides a custom views field.
 */
class osha_press_contact_handler_bureau_group extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    // Do nothing -- to override the parent query.
  }

  /**
   * {@inheritdoc}
   */
  public function render($data) {
    $output = NULL;
    if (!empty($data->_field_data)) {
      reset($data->_field_data);
      $field = current($data->_field_data);
      $node = $field['entity'];
      if (!empty($node->nid)) {
        $wrapper = entity_metadata_wrapper('node', $node);
        return ucfirst($wrapper->field_wg_role_1->value()->name);
      }
    }
    return $output;
  }
}
