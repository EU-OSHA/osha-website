<?php
/**
 * @file
 * osha_dangerous_substances.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function osha_dangerous_substances_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: view:practical_tools_and_guidance_on_dangerous_substances-page.
  $config['view:practical_tools_and_guidance_on_dangerous_substances-page'] = array(
    'instance' => 'view:practical_tools_and_guidance_on_dangerous_substances-page',
    'config' => array(),
  );

  return $config;
}
