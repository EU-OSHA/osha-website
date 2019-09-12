<?php
/**
 * @file
 * osha_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function osha_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_events';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
        'highlight' => 'highlight',
        'news' => 'news',
        'seminar' => 'seminar',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'tools-and-resources/blog' => 'tools-and-resources/blog',
        'node/5445' => 'node/5445',
      ),
    ),
    'views' => array(
      'values' => array(
        'blog' => 'blog',
        'events' => 'events',
        'highlight' => 'highlight',
        'news' => 'news',
        'search_blog' => 'search_blog',
        'seminars' => 'seminars',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;
  $export['context_events'] = $context;

  return $export;
}
