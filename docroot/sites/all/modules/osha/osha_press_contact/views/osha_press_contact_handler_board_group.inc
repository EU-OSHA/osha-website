<?php

/**
 * Provides a custom views field.
 */
class osha_press_contact_handler_board_group extends views_handler_field {

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
        $is_observer = $wrapper->field_is_observer->value();
        $wg_category = $wrapper->field_wg_category->value();
        if (!empty($is_observer)) {
          $output = t('Observers');
        }
        elseif (!empty($wg_category) && $wg_category->name_field['en'][0]['value'] == 'European Commission') {
          $output = t('European Commission');
        }
        elseif (variable_get('expert_nominated_title', '') && !empty($wg_category) && $wg_category->name_field['en'][0]['value'] == 'expert nominated by the european parliament') {
          $output = t(variable_get('expert_nominated_title', ''));
        }
        else {
          $output = $wrapper->field_country->value()->name;
        }
      }
    }
    return $output;
  }
}
