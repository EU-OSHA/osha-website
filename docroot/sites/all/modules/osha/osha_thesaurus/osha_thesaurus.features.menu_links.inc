<?php
/**
 * @file
 * osha_thesaurus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function osha_thesaurus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_eu-osha-hierarchical:tools-and-resources/eu-osha-thesaurus/hierarchical.
  $menu_links['main-menu_eu-osha-hierarchical:tools-and-resources/eu-osha-thesaurus/hierarchical'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'tools-and-resources/eu-osha-thesaurus/hierarchical',
    'router_path' => 'tools-and-resources/eu-osha-thesaurus/hierarchical',
    'link_title' => 'EU-OSHA hierarchical',
    'options' => array(
      'copyright' => array(
        'copyright' => '',
        'author' => '',
      ),
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_eu-osha-hierarchical:tools-and-resources/eu-osha-thesaurus/hierarchical',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tools--resources:node/20',
  );
  // Exported menu link: main-menu_eu-osha-thesaurus-alphabetical:tools-and-resources/eu-osha-thesaurus/alphabetical.
  $menu_links['main-menu_eu-osha-thesaurus-alphabetical:tools-and-resources/eu-osha-thesaurus/alphabetical'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'tools-and-resources/eu-osha-thesaurus/alphabetical',
    'router_path' => 'tools-and-resources/eu-osha-thesaurus/alphabetical',
    'link_title' => 'EU-OSHA thesaurus alphabetical',
    'options' => array(
      'copyright' => array(
        'copyright' => '',
        'author' => '',
      ),
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_eu-osha-thesaurus-alphabetical:tools-and-resources/eu-osha-thesaurus/alphabetical',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tools--resources:node/20',
  );
  // Exported menu link: main-menu_eu-osha-thesaurus:tools-and-resources/eu-osha-thesaurus/search.
  $menu_links['main-menu_eu-osha-thesaurus:tools-and-resources/eu-osha-thesaurus/search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'tools-and-resources/eu-osha-thesaurus/search',
    'router_path' => 'tools-and-resources/eu-osha-thesaurus/search',
    'link_title' => 'EU-OSHA thesaurus',
    'options' => array(
      'alter' => TRUE,
      'copyright' => array(
        'copyright' => '',
        'author' => '',
      ),
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_eu-osha-thesaurus:tools-and-resources/eu-osha-thesaurus/search',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tools--resources:node/20',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('EU-OSHA hierarchical');
  t('EU-OSHA thesaurus');
  t('EU-OSHA thesaurus alphabetical');

  return $menu_links;
}
