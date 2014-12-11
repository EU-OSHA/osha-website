<?php
/**
 * @file
 * Provides a drush command to simulate translation workflow.
 */
define('NODE_TYPE', 'article');


/**
 * Implements hook_drush_command().
 */
function osha_tmgmt_transl_wf_drush_command(){
  $items = array();
  $items['osha-tmgmt-simulate-translate-workflow'] = array(
    'description' => 'Simulate a translation workflow',
    'aliases' => array('oshstw'),
    'examples' => array(),
    'arguments' => array(),
    'options' => array(),
    'sections' => array(),
  );

  return $items;
}

/**
 * Callback for osha-tmgmt-simulate-translate-workflow.
 */
function drush_osha_tmgmt_transl_wf_osha_tmgmt_simulate_translate_workflow(){
  //create new article
  $node = _drush_osha_create_node();
  //add to cart
  $form_state['tmgmt_cart'] = array(
    'plugin' => 'entity',
    'item_type' => 'node',
    'item_id' => $node->nid,
  );
  drupal_form_submit('tmgmt_ui_source_add_to_cart_submit',$form_state);
  drush_log(dt('Translation job item added to cart'), 'ok');

  //submit cart
  $job_item = current(tmgmt_ui_cart_get()->getJobItemsFromCart());
  $form_state = array();
  $form_state['values'] = array(
    'target_language' => array('ro' => 'ro'),
    'items'           => array($job_item->tjiid => $job_item->tjiid),
  );
  drupal_form_submit('osha_tmgmt_tmgmt_ui_cart_content_submit',$form_state);
  drush_log(dt('Checkout successful. Translation job created.'), 'ok');
}

/**
 * Creates a new article node.
 */
function _drush_osha_create_node(){
  $values = array(
    'type' => NODE_TYPE,
    'uid' => 1,
    'language' => 'en',
  );
  $e = entity_create('node', $values);
  $entity = entity_metadata_wrapper('node',$e);
  $entity->title = 'Test node';
  $entity->field_article_type->set(65);
  $entity->field_summary->set('Test Summary EN');
  $body = 'Body Test Text';
  $entity->body->set(array('value' => $body));
  $entity->save();
  //set workbench_access
  $active = workbench_access_get_active_tree();
  $record = array(
    'nid' => $e->nid,
    'access_id' => 'main-menu',
    'access_scheme' => $active['access_scheme']['access_scheme'],
  );
  drupal_write_record('workbench_access_node', $record);
  //set workbench moderation state
  workbench_moderation_moderate($e, 'ready_to_publish');
  drush_log(dt('Test Node created'), 'ok');
  return $e;
}