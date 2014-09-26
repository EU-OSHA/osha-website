<?php
/**
 * @file
 * osha_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function osha_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_2012-13-working-together:<front>
  $menu_links['main-menu_2012-13-working-together:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => '2012-13 “Working Together”',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_2012-13-working-together:<front>',
      'content' => array(
        'image' => 'public://menuimage/working_together.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_campaigns:node/15',
  );
  // Exported menu link: main-menu_2014-15-psychosocial-risks:<front>
  $menu_links['main-menu_2014-15-psychosocial-risks:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => '2014-15 “Psychosocial Risks”',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_2014-15-psychosocial-risks:<front>',
      'content' => array(
        'image' => 'public://menuimage/campaign-2014-15.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_campaigns:node/15',
  );
  // Exported menu link: main-menu_ageing-and-osh:node/1
  $menu_links['main-menu_ageing-and-osh:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Ageing and OSH',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_ageing-and-osh:node/1',
      'content' => array(
        'image' => 'public://menuimage/ageing.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => '106bb0f7-5519-42a4-8310-5773d228a335',
    'parent_identifier' => 'main-menu_themes:node/14',
  );
  // Exported menu link: main-menu_awards:node/4
  $menu_links['main-menu_awards:node/4'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/4',
    'router_path' => 'node/%',
    'link_title' => 'Awards',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_awards:node/4',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => '2c1489e8-077b-4b33-8e6b-f842f4363cba',
    'parent_identifier' => 'main-menu_campaigns:<nolink>',
  );
  // Exported menu link: main-menu_campaigns:<nolink>
  $menu_links['main-menu_campaigns:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Campaigns',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_campaigns:<nolink>',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_campaigns:node/15
  $menu_links['main-menu_campaigns:node/15'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/15',
    'router_path' => 'node/%',
    'link_title' => 'Campaigns',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_campaigns:node/15',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => 'd5745241-8849-44c4-8adb-2a07d1407afb',
    'parent_identifier' => 'main-menu_campaigns:<nolink>',
  );
  // Exported menu link: main-menu_careers:node/19
  $menu_links['main-menu_careers:node/19'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/19',
    'router_path' => 'node/%',
    'link_title' => 'Careers',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_careers:node/19',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => 'f4afeb3b-6a7f-4e28-ac56-0d1b9746c5b3',
    'parent_identifier' => 'main-menu_inside-eu-osha:node/12',
  );
  // Exported menu link: main-menu_costs-and-benefits-of-osh:node/20
  $menu_links['main-menu_costs-and-benefits-of-osh:node/20'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/20',
    'router_path' => 'node/%',
    'link_title' => 'Costs and benefits of OSH',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_costs-and-benefits-of-osh:node/20',
      'content' => array(
        'image' => 'public://menuimage/benefits-of-osh.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => 'fd81ac64-3deb-4118-b4aa-b499e0e2e576',
    'parent_identifier' => 'main-menu_themes:node/14',
  );
  // Exported menu link: main-menu_country-specific-legislation:<front>
  $menu_links['main-menu_country-specific-legislation:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Country-specific Legislation',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_country-specific-legislation:<front>',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => 1,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'main-menu_legislation:<nolink>',
  );
  // Exported menu link: main-menu_dangerous-substances:<front>
  $menu_links['main-menu_dangerous-substances:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Dangerous substances',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_dangerous-substances:<front>',
      'content' => array(
        'image' => 'public://menuimage/dangerous-substances.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_themes:node/14',
  );
  // Exported menu link: main-menu_emerging-risks:<nolink>
  $menu_links['main-menu_emerging-risks:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Emerging Risks',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_emerging-risks:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_emerging-risks:node/3
  $menu_links['main-menu_emerging-risks:node/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Emerging Risks',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_emerging-risks:node/3',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => '20e2c054-60f4-41a6-beaf-9c083ff05a63',
    'parent_identifier' => 'main-menu_emerging-risks:<nolink>',
  );
  // Exported menu link: main-menu_enterprise-survey-esener:<front>
  $menu_links['main-menu_enterprise-survey-esener:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Enterprise Survey (ESENER)',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_enterprise-survey-esener:<front>',
      'content' => array(
        'image' => 'public://menuimage/esener.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_surveys--statistics:node/5',
  );
  // Exported menu link: main-menu_eu-directives:node/10
  $menu_links['main-menu_eu-directives:node/10'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/10',
    'router_path' => 'node/%',
    'link_title' => 'EU Directives',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_eu-directives:node/10',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => '6f6f90f0-e453-40af-b0bd-593af4da286f',
    'parent_identifier' => 'main-menu_european-legislation:node/13',
  );
  // Exported menu link: main-menu_eu-guidelines:<front>
  $menu_links['main-menu_eu-guidelines:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'EU Guidelines',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_eu-guidelines:<front>',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_european-legislation:node/13',
  );
  // Exported menu link: main-menu_eu-osh-standards:node/7
  $menu_links['main-menu_eu-osh-standards:node/7'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => 'EU OSH Standards',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_eu-osh-standards:node/7',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => '57d9e0dc-976e-4e5d-b792-ba007ccb98a9',
    'parent_identifier' => 'main-menu_european-legislation:node/13',
  );
  // Exported menu link: main-menu_european-legislation:node/13
  $menu_links['main-menu_european-legislation:node/13'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/13',
    'router_path' => 'node/%',
    'link_title' => 'European Legislation',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_european-legislation:node/13',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => 'a940a49d-3ea0-4dee-b487-d301ce495610',
    'parent_identifier' => 'main-menu_legislation:<nolink>',
  );
  // Exported menu link: main-menu_film-awards:<front>
  $menu_links['main-menu_film-awards:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Film Awards',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_film-awards:<front>',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 1,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'main-menu_awards:node/4',
  );
  // Exported menu link: main-menu_former-campaigns:<front>
  $menu_links['main-menu_former-campaigns:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Former Campaigns',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_former-campaigns:<front>',
      'content' => array(
        'image' => 'public://menuimage/former-campaign.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_campaigns:node/15',
  );
  // Exported menu link: main-menu_further-themes-via-oshwiki:<front>
  $menu_links['main-menu_further-themes-via-oshwiki:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Further themes via OSHWiki',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_further-themes-via-oshwiki:<front>',
      'content' => array(
        'image' => 'public://menuimage/oshwiki.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -38,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_themes:node/14',
  );
  // Exported menu link: main-menu_future-campaigns:<front>
  $menu_links['main-menu_future-campaigns:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Future Campaigns',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_future-campaigns:<front>',
      'content' => array(
        'image' => 'public://menuimage/future-campaign.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_campaigns:node/15',
  );
  // Exported menu link: main-menu_good-practice-awards:<front>
  $menu_links['main-menu_good-practice-awards:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Good Practice Awards',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_good-practice-awards:<front>',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'main-menu_awards:node/4',
  );
  // Exported menu link: main-menu_governance:<front>
  $menu_links['main-menu_governance:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Governance',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_governance:<front>',
      'content' => array(
        'image' => 'public://menuimage/governance.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_inside-eu-osha:node/12',
  );
  // Exported menu link: main-menu_green-jobs:node/17
  $menu_links['main-menu_green-jobs:node/17'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/17',
    'router_path' => 'node/%',
    'link_title' => 'Green jobs',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_green-jobs:node/17',
      'content' => array(
        'image' => 'public://menuimage/green-jobs.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => 'e454a870-6856-42df-9fe9-dba700f05282',
    'parent_identifier' => 'main-menu_emerging-risks:node/3',
  );
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_inside-eu-osha:<nolink>
  $menu_links['main-menu_inside-eu-osha:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Inside EU-OSHA',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_inside-eu-osha:<nolink>',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -43,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_inside-eu-osha:node/12
  $menu_links['main-menu_inside-eu-osha:node/12'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/12',
    'router_path' => 'node/%',
    'link_title' => 'Inside EU-OSHA',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_inside-eu-osha:node/12',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => 'a065ac76-7af7-4164-b44a-596287e6eb65',
    'parent_identifier' => 'main-menu_inside-eu-osha:<nolink>',
  );
  // Exported menu link: main-menu_leadership--worker-participation:node/16
  $menu_links['main-menu_leadership--worker-participation:node/16'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/16',
    'router_path' => 'node/%',
    'link_title' => 'Leadership & worker participation',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_leadership--worker-participation:node/16',
      'content' => array(
        'image' => 'public://menuimage/leadership.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => 'dc21d794-563b-4ef2-aaac-d0e2dcdfb18f',
    'parent_identifier' => 'main-menu_themes:node/14',
  );
  // Exported menu link: main-menu_legislation:<nolink>
  $menu_links['main-menu_legislation:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Legislation',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_legislation:<nolink>',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_mainstreaming-osh-into-education:<front>
  $menu_links['main-menu_mainstreaming-osh-into-education:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Mainstreaming OSH into education',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_mainstreaming-osh-into-education:<front>',
      'content' => array(
        'image' => 'public://menuimage/mainstreaming-education.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_themes:node/14',
  );
  // Exported menu link: main-menu_micro-enterprises:<front>
  $menu_links['main-menu_micro-enterprises:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Micro enterprises',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_micro-enterprises:<front>',
      'content' => array(
        'image' => 'public://menuimage/micro-enterprise.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_themes:node/14',
  );
  // Exported menu link: main-menu_musculoskeletal-disorders:<front>
  $menu_links['main-menu_musculoskeletal-disorders:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Musculoskeletal disorders',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_musculoskeletal-disorders:<front>',
      'content' => array(
        'image' => 'public://menuimage/muskoloeskeletal_disorders.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_themes:node/14',
  );
  // Exported menu link: main-menu_nanomaterials:<front>
  $menu_links['main-menu_nanomaterials:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Nanomaterials',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_nanomaterials:<front>',
      'content' => array(
        'image' => 'public://menuimage/nanomaterial.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -43,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_themes:node/14',
  );
  // Exported menu link: main-menu_napo:<front>
  $menu_links['main-menu_napo:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Napo',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_napo:<front>',
      'content' => array(
        'image' => 'public://menuimage/napo.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tools--resources:node/18',
  );
  // Exported menu link: main-menu_national-osh-systems:node/6
  $menu_links['main-menu_national-osh-systems:node/6'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/6',
    'router_path' => 'node/%',
    'link_title' => 'National OSH Systems',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_national-osh-systems:node/6',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => '4e4c748b-77be-443c-843e-194de4e7a3c1',
    'parent_identifier' => 'main-menu_country-specific-legislation:<front>',
  );
  // Exported menu link: main-menu_oira---risk-assessment:<front>
  $menu_links['main-menu_oira---risk-assessment:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'OiRA - Risk Assessment',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_oira---risk-assessment:<front>',
      'content' => array(
        'image' => 'public://menuimage/oira.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tools--resources:node/18',
  );
  // Exported menu link: main-menu_online-tools:<front>
  $menu_links['main-menu_online-tools:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Online tools',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_online-tools:<front>',
      'content' => array(
        'image' => 'public://menuimage/online_tools.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tools--resources:node/18',
  );
  // Exported menu link: main-menu_organisation:<front>
  $menu_links['main-menu_organisation:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Organisation',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_organisation:<front>',
      'content' => array(
        'image' => 'public://menuimage/organisation.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_inside-eu-osha:node/12',
  );
  // Exported menu link: main-menu_oshwiki:<front>
  $menu_links['main-menu_oshwiki:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'OSHwiki',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_oshwiki:<front>',
      'content' => array(
        'image' => 'public://menuimage/oshwiki.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tools--resources:node/18',
  );
  // Exported menu link: main-menu_pan-eu-poll-on-safety--health:<front>
  $menu_links['main-menu_pan-eu-poll-on-safety--health:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Pan-EU poll on Safety & Health',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_pan-eu-poll-on-safety--health:<front>',
      'content' => array(
        'image' => 'public://menuimage/poll.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_surveys--statistics:node/5',
  );
  // Exported menu link: main-menu_press:<front>
  $menu_links['main-menu_press:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Press',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_press:<front>',
      'content' => array(
        'image' => 'public://menuimage/press.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_inside-eu-osha:node/12',
  );
  // Exported menu link: main-menu_procurement:<front>
  $menu_links['main-menu_procurement:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Procurement',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_procurement:<front>',
      'content' => array(
        'image' => 'public://menuimage/procurement.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_inside-eu-osha:node/12',
  );
  // Exported menu link: main-menu_psychosocial-risks-and-stress:<front>
  $menu_links['main-menu_psychosocial-risks-and-stress:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Psychosocial risks and stress',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_psychosocial-risks-and-stress:<front>',
      'content' => array(
        'image' => 'public://menuimage/stress.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -42,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_themes:node/14',
  );
  // Exported menu link: main-menu_publications:publications
  $menu_links['main-menu_publications:publications'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'publications',
    'router_path' => 'publications',
    'link_title' => 'Publications',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_publications:publications',
      'content' => array(
        'image' => 'public://menuimage/publications.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tools--resources:node/18',
  );
  // Exported menu link: main-menu_surveys--statistics:<nolink>
  $menu_links['main-menu_surveys--statistics:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Surveys & Statistics',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_surveys--statistics:<nolink>',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_surveys--statistics:node/5
  $menu_links['main-menu_surveys--statistics:node/5'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/5',
    'router_path' => 'node/%',
    'link_title' => 'Surveys & Statistics',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_surveys--statistics:node/5',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => '387191b6-0baf-4823-906d-55c6b560c388',
    'parent_identifier' => 'main-menu_surveys--statistics:<nolink>',
  );
  // Exported menu link: main-menu_themes:<nolink>
  $menu_links['main-menu_themes:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Themes',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_themes:<nolink>',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_themes:node/14
  $menu_links['main-menu_themes:node/14'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/14',
    'router_path' => 'node/%',
    'link_title' => 'Themes',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_themes:node/14',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => 'bf53c93b-3db2-40dc-9f76-79de045897d2',
    'parent_identifier' => 'main-menu_themes:<nolink>',
  );
  // Exported menu link: main-menu_tools--resources:<nolink>
  $menu_links['main-menu_tools--resources:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Tools & Resources',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_tools--resources:<nolink>',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_tools--resources:node/18
  $menu_links['main-menu_tools--resources:node/18'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/18',
    'router_path' => 'node/%',
    'link_title' => 'Tools & Resources',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_tools--resources:node/18',
      'content' => array(
        'image' => 'public://menuimage/publications.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => 'f3fc72f9-56f7-4026-a707-9b45dccef67a',
    'parent_identifier' => 'main-menu_tools--resources:<nolink>',
  );
  // Exported menu link: main-menu_what-we-do:node/11
  $menu_links['main-menu_what-we-do:node/11'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/11',
    'router_path' => 'node/%',
    'link_title' => 'What we do',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_what-we-do:node/11',
      'content' => array(
        'image' => 'public://menuimage/what-we-do.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'item_uuid' => '857d1fbe-f8cc-4359-8cd7-8a2ebcfdd17c',
    'parent_identifier' => 'main-menu_inside-eu-osha:node/12',
  );
  // Exported menu link: main-menu_women-and-osh:<front>
  $menu_links['main-menu_women-and-osh:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Women and OSH',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_women-and-osh:<front>',
      'content' => array(
        'image' => 'public://menuimage/women-and-OSH.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -41,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_themes:node/14',
  );
  // Exported menu link: main-menu_work-related-diseases:<front>
  $menu_links['main-menu_work-related-diseases:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Work-related diseases',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_work-related-diseases:<front>',
      'content' => array(
        'image' => 'public://menuimage/work-related-diseases.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -40,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_themes:node/14',
  );
  // Exported menu link: main-menu_young-people-and-osh:<front>
  $menu_links['main-menu_young-people-and-osh:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Young people and OSH',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_young-people-and-osh:<front>',
      'content' => array(
        'image' => 'public://menuimage/young-people.jpg',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -39,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_themes:node/14',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('2012-13 “Working Together”');
  t('2014-15 “Psychosocial Risks”');
  t('Ageing and OSH');
  t('Awards');
  t('Campaigns');
  t('Careers');
  t('Costs and benefits of OSH');
  t('Country-specific Legislation');
  t('Dangerous substances');
  t('EU Directives');
  t('EU Guidelines');
  t('EU OSH Standards');
  t('Emerging Risks');
  t('Enterprise Survey (ESENER)');
  t('European Legislation');
  t('Film Awards');
  t('Former Campaigns');
  t('Further themes via OSHWiki');
  t('Future Campaigns');
  t('Good Practice Awards');
  t('Governance');
  t('Green jobs');
  t('Home');
  t('Inside EU-OSHA');
  t('Leadership & worker participation');
  t('Legislation');
  t('Mainstreaming OSH into education');
  t('Micro enterprises');
  t('Musculoskeletal disorders');
  t('Nanomaterials');
  t('Napo');
  t('National OSH Systems');
  t('OSHwiki');
  t('OiRA - Risk Assessment');
  t('Online tools');
  t('Organisation');
  t('Pan-EU poll on Safety & Health');
  t('Press');
  t('Procurement');
  t('Psychosocial risks and stress');
  t('Publications');
  t('Surveys & Statistics');
  t('Themes');
  t('Tools & Resources');
  t('What we do');
  t('Women and OSH');
  t('Work-related diseases');
  t('Young people and OSH');


  return $menu_links;
}
