<?php

/**
 * @file
 * Views hook implementations for the Search API ET module.
 */

/**
 * Implements hook_views_plugins_alter().
 *
 * Extend search_api_views module's SearchApiViewsQuery class to use our own
 * addResults() method to correctly process multilingual search item IDs.
 */
function search_api_et_views_plugins_alter(&$plugins) {
  $plugins['query']['search_api_views_query']['handler'] = 'SearchApiEtViewsQuery';
}
