<?php
/**
 * @file
 * osha_blocks.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_blocks_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function osha_blocks_image_default_styles() {
  $styles = array();

  // Exported image style: relres.
  $styles['relres'] = array(
    'label' => 'relres',
    'effects' => array(),
  );

  return $styles;
}
