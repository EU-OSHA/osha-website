<?php

/**
 * @file
 * Hooks provided by the Solr Devel module.
 */

/**
 * Defines search environments and the adapters they use.
 *
 * @return array
 *   An associative array keyed by the machine name of the environment, usually
 *   in `module`:`environment` format, to an array containing:
 *   - label: The human readable label of the environment.
 *   - adapter: The class name of the adapter.
 *   - adapter options: (optional) An array of options passed as arguments to
 *     the adapter's constructor. See Drupal_SolrDevel_Adapter::__construct().
 */
function hook_solr_devel_environment_info() {
  return array(
    'apachesolr:solr' => array(
      'label' => t('Localhost'),
      'adapter' => 'Drupal_SolrDevel_Adapter_ApacheSolr',
      'adapter options' => array(),
    ),
  );
}
