<?php

/**
 * @file
 * Documentation for the EU Cookie Compliance module.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup EU Cookie Compliance hooks
 *
 * @{
 * Hooks that can be implemented to externally extend the EU Cookie Compliance
 * module.
 */

/**
 * Alter the geo_ip_match variable.
 *
 * @param bool &$geoip_match
 *   Whether to show the cookie compliance banner.
 */
function hook_eu_cookie_compliance_geoip_match_alter(&$geoip_match) {
  $geoip_match = FALSE;
}

/**
 * Take control of EU Cookie Compliance path exclusion.
 *
 * @param bool $excluded
 *   Whether this path is excluded from cookie compliance behavior.
 * @param string $path
 *   Current string path.
 * @param string $setting
 *   Admin variable of excluded paths.
 */
function hook_eu_cookie_compliance_path_match_alter(&$excluded, $path, $setting) {
  $node = menu_get_object('node');
  if ($node && $node->type === 'my_type') {
    $excluded = TRUE;
  }
}

/**
 * Alter hook to provide advanced logic for hiding the banner.
 *
 * @param bool $show_popup
 *   Whether to show the banner.
 */
function hook_eu_cookie_compliance_show_popup_alter(&$show_popup) {
  $node = menu_get_object('node');
  if ($node && $node->type === 'my_type') {
    $show_popup = FALSE;
  }
}

/**
 * @}
 * End hook documentation.
 */
