<?php
/**
 * @file
 * osha_search.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function osha_search_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-search.
  $menus['menu-search'] = array(
    'menu_name' => 'menu-search',
    'title' => 'Search',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Search');

  return $menus;
}
