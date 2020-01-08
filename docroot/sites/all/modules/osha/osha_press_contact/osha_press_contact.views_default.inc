<?php
/**
 * @file
 * osha_press_contact.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_press_contact_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'advisory_groups';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Advisory groups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advisory groups';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_contact_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Category (field_wg_category) */
  $handler->display->display_options['relationships']['field_wg_category_tid']['id'] = 'field_wg_category_tid';
  $handler->display->display_options['relationships']['field_wg_category_tid']['table'] = 'field_data_field_wg_category';
  $handler->display->display_options['relationships']['field_wg_category_tid']['field'] = 'field_wg_category_tid';
  $handler->display->display_options['relationships']['field_wg_category_tid']['required'] = TRUE;
  /* Relationship: Content: WG Role 1 (field_wg_role_1) */
  $handler->display->display_options['relationships']['field_wg_role_1_tid']['id'] = 'field_wg_role_1_tid';
  $handler->display->display_options['relationships']['field_wg_role_1_tid']['table'] = 'field_data_field_wg_role_1';
  $handler->display->display_options['relationships']['field_wg_role_1_tid']['field'] = 'field_wg_role_1_tid';
  $handler->display->display_options['relationships']['field_wg_role_1_tid']['required'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_contact_type']['id'] = 'field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['field'] = 'field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['label'] = '';
  $handler->display->display_options['fields']['field_contact_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_contact_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_contact_type']['delta_offset'] = '0';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_wg_category']['id'] = 'field_wg_category';
  $handler->display->display_options['fields']['field_wg_category']['table'] = 'field_data_field_wg_category';
  $handler->display->display_options['fields']['field_wg_category']['field'] = 'field_wg_category';
  $handler->display->display_options['fields']['field_wg_category']['label'] = '';
  $handler->display->display_options['fields']['field_wg_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_wg_category']['alter']['text'] = '([field_wg_category])';
  $handler->display->display_options['fields']['field_wg_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wg_category']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: WG Role 1 */
  $handler->display->display_options['fields']['field_wg_role_1']['id'] = 'field_wg_role_1';
  $handler->display->display_options['fields']['field_wg_role_1']['table'] = 'field_data_field_wg_role_1';
  $handler->display->display_options['fields']['field_wg_role_1']['field'] = 'field_wg_role_1';
  $handler->display->display_options['fields']['field_wg_role_1']['label'] = '';
  $handler->display->display_options['fields']['field_wg_role_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_wg_role_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wg_role_1']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_3']['label'] = '';
  $handler->display->display_options['fields']['nothing_3']['alter']['text'] = '[field_wg_category] - [field_wg_role_1]';
  $handler->display->display_options['fields']['nothing_3']['element_type'] = 'span';
  $handler->display->display_options['fields']['nothing_3']['element_class'] = 'advisory-role1';
  $handler->display->display_options['fields']['nothing_3']['element_label_colon'] = FALSE;
  /* Field: Content: Personal Title */
  $handler->display->display_options['fields']['field_personal_title']['id'] = 'field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['table'] = 'field_data_field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['field'] = 'field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['label'] = '';
  $handler->display->display_options['fields']['field_personal_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_personal_title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_wrapper_type'] = 'strong';
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => '',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: WG Role 2 */
  $handler->display->display_options['fields']['field_wg_role_2']['id'] = 'field_wg_role_2';
  $handler->display->display_options['fields']['field_wg_role_2']['table'] = 'field_data_field_wg_role_2';
  $handler->display->display_options['fields']['field_wg_role_2']['field'] = 'field_wg_role_2';
  $handler->display->display_options['fields']['field_wg_role_2']['label'] = '';
  $handler->display->display_options['fields']['field_wg_role_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_wg_role_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_wg_role_2']['alter']['text'] = '([field_wg_role_2])';
  $handler->display->display_options['fields']['field_wg_role_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_wg_role_2']['alter']['path'] = 'about-eu-osha/governance-eu-osha/composition-bureau';
  $handler->display->display_options['fields']['field_wg_role_2']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_wg_role_2']['element_class'] = 'advisory-role2';
  $handler->display->display_options['fields']['field_wg_role_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wg_role_2']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<strong>[field_personal_title] [title_field]</strong> [field_wg_role_2]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: CV */
  $handler->display->display_options['fields']['field_press_contact_cv']['id'] = 'field_press_contact_cv';
  $handler->display->display_options['fields']['field_press_contact_cv']['table'] = 'field_data_field_press_contact_cv';
  $handler->display->display_options['fields']['field_press_contact_cv']['field'] = 'field_press_contact_cv';
  $handler->display->display_options['fields']['field_press_contact_cv']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_cv']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_press_contact_cv']['alter']['text'] = ' | [field_press_contact_cv]';
  $handler->display->display_options['fields']['field_press_contact_cv']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_contact_cv']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_press_contact_cv']['type'] = 'contact_file_download_link';
  $handler->display->display_options['fields']['field_press_contact_cv']['settings'] = array(
    'text' => 'CV',
  );
  /* Field: Content: Declaration of Interests */
  $handler->display->display_options['fields']['field_press_contact_declaration']['id'] = 'field_press_contact_declaration';
  $handler->display->display_options['fields']['field_press_contact_declaration']['table'] = 'field_data_field_press_contact_declaration';
  $handler->display->display_options['fields']['field_press_contact_declaration']['field'] = 'field_press_contact_declaration';
  $handler->display->display_options['fields']['field_press_contact_declaration']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_declaration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_press_contact_declaration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_contact_declaration']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_press_contact_declaration']['type'] = 'contact_file_download_link';
  $handler->display->display_options['fields']['field_press_contact_declaration']['settings'] = array(
    'text' => 'Declaration of interests',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[field_press_contact_declaration][field_press_contact_cv]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_press_contact_organization']['id'] = 'field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['table'] = 'field_data_field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['field'] = 'field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_organization']['element_label_colon'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_press_contact_location']['id'] = 'field_press_contact_location';
  $handler->display->display_options['fields']['field_press_contact_location']['table'] = 'field_data_field_press_contact_location';
  $handler->display->display_options['fields']['field_press_contact_location']['field'] = 'field_press_contact_location';
  $handler->display->display_options['fields']['field_press_contact_location']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_location']['element_label_colon'] = FALSE;
  /* Field: Content: Zip Code */
  $handler->display->display_options['fields']['field_zip_code']['id'] = 'field_zip_code';
  $handler->display->display_options['fields']['field_zip_code']['table'] = 'field_data_field_zip_code';
  $handler->display->display_options['fields']['field_zip_code']['field'] = 'field_zip_code';
  $handler->display->display_options['fields']['field_zip_code']['label'] = '';
  $handler->display->display_options['fields']['field_zip_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_zip_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_zip_code']['type'] = 'text_plain';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_city']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_city']['alter']['text'] = ', [field_city]';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_city']['type'] = 'text_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_zip_code][field_city] ';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['label'] = '';
  $handler->display->display_options['fields']['field_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_country']['alter']['text'] = '[field_country]';
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_wg_category_tid';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight_1']['relationship'] = 'field_wg_role_1_tid';
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_contact' => 'press_contact',
  );
  /* Filter criterion: Content: Is advisory (field_is_advisory) */
  $handler->display->display_options['filters']['field_is_advisory_value']['id'] = 'field_is_advisory_value';
  $handler->display->display_options['filters']['field_is_advisory_value']['table'] = 'field_data_field_is_advisory';
  $handler->display->display_options['filters']['field_is_advisory_value']['field'] = 'field_is_advisory_value';
  $handler->display->display_options['filters']['field_is_advisory_value']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['advisory_groups'] = array(
    t('Master'),
    t('Advisory groups'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Ascending'),
    t('Descending'),
    t('term from field_wg_category'),
    t('term from field_wg_role_1'),
    t('([field_wg_category])'),
    t('[field_wg_category] - [field_wg_role_1]'),
    t('([field_wg_role_2])'),
    t('<strong>[field_personal_title] [title_field]</strong> [field_wg_role_2]'),
    t(' | [field_press_contact_cv]'),
    t('[field_press_contact_declaration][field_press_contact_cv]'),
    t(', [field_city]'),
    t('[field_zip_code][field_city] '),
    t('[field_country]'),
    t('Block'),
  );
  $export['advisory_groups'] = $view;

  $view = new view();
  $view->name = 'board_members';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Board members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Board members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'board_group',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_wg_category',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Category (field_wg_category) */
  $handler->display->display_options['relationships']['field_wg_category_tid']['id'] = 'field_wg_category_tid';
  $handler->display->display_options['relationships']['field_wg_category_tid']['table'] = 'field_data_field_wg_category';
  $handler->display->display_options['relationships']['field_wg_category_tid']['field'] = 'field_wg_category_tid';
  /* Relationship: Content: WG Role 1 (field_wg_role_1) */
  $handler->display->display_options['relationships']['field_wg_role_1_tid']['id'] = 'field_wg_role_1_tid';
  $handler->display->display_options['relationships']['field_wg_role_1_tid']['table'] = 'field_data_field_wg_role_1';
  $handler->display->display_options['relationships']['field_wg_role_1_tid']['field'] = 'field_wg_role_1_tid';
  /* Relationship: Content: Country (field_country) */
  $handler->display->display_options['relationships']['field_country_tid']['id'] = 'field_country_tid';
  $handler->display->display_options['relationships']['field_country_tid']['table'] = 'field_data_field_country';
  $handler->display->display_options['relationships']['field_country_tid']['field'] = 'field_country_tid';
  $handler->display->display_options['relationships']['field_country_tid']['required'] = TRUE;
  /* Relationship: Taxonomy term: Country Status (field_country_status) */
  $handler->display->display_options['relationships']['field_country_status_tid']['id'] = 'field_country_status_tid';
  $handler->display->display_options['relationships']['field_country_status_tid']['table'] = 'field_data_field_country_status';
  $handler->display->display_options['relationships']['field_country_status_tid']['field'] = 'field_country_status_tid';
  $handler->display->display_options['relationships']['field_country_status_tid']['relationship'] = 'field_country_tid';
  /* Field: Osha press contact: Board members group field */
  $handler->display->display_options['fields']['board_group']['id'] = 'board_group';
  $handler->display->display_options['fields']['board_group']['table'] = 'osha_press_contact';
  $handler->display->display_options['fields']['board_group']['field'] = 'board_group';
  $handler->display->display_options['fields']['board_group']['label'] = '';
  $handler->display->display_options['fields']['board_group']['exclude'] = TRUE;
  $handler->display->display_options['fields']['board_group']['element_label_colon'] = FALSE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['label'] = '';
  $handler->display->display_options['fields']['field_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_wg_category']['id'] = 'field_wg_category';
  $handler->display->display_options['fields']['field_wg_category']['table'] = 'field_data_field_wg_category';
  $handler->display->display_options['fields']['field_wg_category']['field'] = 'field_wg_category';
  $handler->display->display_options['fields']['field_wg_category']['label'] = '';
  $handler->display->display_options['fields']['field_wg_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_wg_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wg_category']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: WG Role 1 */
  $handler->display->display_options['fields']['field_wg_role_1']['id'] = 'field_wg_role_1';
  $handler->display->display_options['fields']['field_wg_role_1']['table'] = 'field_data_field_wg_role_1';
  $handler->display->display_options['fields']['field_wg_role_1']['field'] = 'field_wg_role_1';
  $handler->display->display_options['fields']['field_wg_role_1']['label'] = '';
  $handler->display->display_options['fields']['field_wg_role_1']['alter']['text'] = ' - [field_wg_role_1]';
  $handler->display->display_options['fields']['field_wg_role_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wg_role_1']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Personal Title */
  $handler->display->display_options['fields']['field_personal_title']['id'] = 'field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['table'] = 'field_data_field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['field'] = 'field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['label'] = '';
  $handler->display->display_options['fields']['field_personal_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_personal_title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => '',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: WG Role 2 for CSS */
  $handler->display->display_options['fields']['field_wg_role_2_1']['id'] = 'field_wg_role_2_1';
  $handler->display->display_options['fields']['field_wg_role_2_1']['table'] = 'field_data_field_wg_role_2';
  $handler->display->display_options['fields']['field_wg_role_2_1']['field'] = 'field_wg_role_2';
  $handler->display->display_options['fields']['field_wg_role_2_1']['ui_name'] = 'WG Role 2 for CSS';
  $handler->display->display_options['fields']['field_wg_role_2_1']['label'] = '';
  $handler->display->display_options['fields']['field_wg_role_2_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_wg_role_2_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_wg_role_2_1']['alter']['text'] = 'wg-role2-[field_wg_role_2_1-tid]';
  $handler->display->display_options['fields']['field_wg_role_2_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wg_role_2_1']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: WG Role 2 */
  $handler->display->display_options['fields']['field_wg_role_2']['id'] = 'field_wg_role_2';
  $handler->display->display_options['fields']['field_wg_role_2']['table'] = 'field_data_field_wg_role_2';
  $handler->display->display_options['fields']['field_wg_role_2']['field'] = 'field_wg_role_2';
  $handler->display->display_options['fields']['field_wg_role_2']['label'] = '';
  $handler->display->display_options['fields']['field_wg_role_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_wg_role_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_wg_role_2']['alter']['text'] = '([field_wg_role_2])';
  $handler->display->display_options['fields']['field_wg_role_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_wg_role_2']['alter']['path'] = 'about-eu-osha/governance-eu-osha/composition-bureau';
  $handler->display->display_options['fields']['field_wg_role_2']['alter']['link_class'] = '[field_wg_role_2_1]';
  $handler->display->display_options['fields']['field_wg_role_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wg_role_2']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<strong>[field_personal_title] [title_field]</strong> [field_wg_role_2]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content: CV */
  $handler->display->display_options['fields']['field_press_contact_cv']['id'] = 'field_press_contact_cv';
  $handler->display->display_options['fields']['field_press_contact_cv']['table'] = 'field_data_field_press_contact_cv';
  $handler->display->display_options['fields']['field_press_contact_cv']['field'] = 'field_press_contact_cv';
  $handler->display->display_options['fields']['field_press_contact_cv']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_cv']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_press_contact_cv']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_contact_cv']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_press_contact_cv']['type'] = 'contact_file_download_link';
  $handler->display->display_options['fields']['field_press_contact_cv']['settings'] = array(
    'text' => 'CV',
  );
  /* Field: Content: Declaration of Interests */
  $handler->display->display_options['fields']['field_press_contact_declaration']['id'] = 'field_press_contact_declaration';
  $handler->display->display_options['fields']['field_press_contact_declaration']['table'] = 'field_data_field_press_contact_declaration';
  $handler->display->display_options['fields']['field_press_contact_declaration']['field'] = 'field_press_contact_declaration';
  $handler->display->display_options['fields']['field_press_contact_declaration']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_declaration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_press_contact_declaration']['alter']['text'] = '[field_press_contact_declaration] |';
  $handler->display->display_options['fields']['field_press_contact_declaration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_contact_declaration']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_press_contact_declaration']['type'] = 'contact_file_download_link';
  $handler->display->display_options['fields']['field_press_contact_declaration']['settings'] = array(
    'text' => 'Declaration of interests',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[field_press_contact_declaration][field_press_contact_cv]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_press_contact_organization']['id'] = 'field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['table'] = 'field_data_field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['field'] = 'field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_organization']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_contact_organization']['type'] = 'text_plain';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_press_contact_location']['id'] = 'field_press_contact_location';
  $handler->display->display_options['fields']['field_press_contact_location']['table'] = 'field_data_field_press_contact_location';
  $handler->display->display_options['fields']['field_press_contact_location']['field'] = 'field_press_contact_location';
  $handler->display->display_options['fields']['field_press_contact_location']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_contact_location']['type'] = 'text_plain';
  /* Field: Content: Zip Code */
  $handler->display->display_options['fields']['field_zip_code']['id'] = 'field_zip_code';
  $handler->display->display_options['fields']['field_zip_code']['table'] = 'field_data_field_zip_code';
  $handler->display->display_options['fields']['field_zip_code']['field'] = 'field_zip_code';
  $handler->display->display_options['fields']['field_zip_code']['label'] = '';
  $handler->display->display_options['fields']['field_zip_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_zip_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_zip_code']['type'] = 'text_plain';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_city']['alter']['text'] = '[field_zip_code] [field_city]';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_city']['type'] = 'text_plain';
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_1']['id'] = 'field_country_1';
  $handler->display->display_options['fields']['field_country_1']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country_1']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country_1']['label'] = '';
  $handler->display->display_options['fields']['field_country_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country_1']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'field_country_tid';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_wg_category_tid';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight_1']['relationship'] = 'field_wg_role_1_tid';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_contact' => 'press_contact',
  );
  /* Filter criterion: Content: Type (field_contact_type) */
  $handler->display->display_options['filters']['field_contact_type_tid']['id'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['filters']['field_contact_type_tid']['field'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['value'] = array(
    2971 => '2971',
  );
  $handler->display->display_options['filters']['field_contact_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_contact_type_tid']['vocabulary'] = 'contact_type';
  /* Filter criterion: Taxonomy term: Country Status (field_country_status) */
  $handler->display->display_options['filters']['field_country_status_tid']['id'] = 'field_country_status_tid';
  $handler->display->display_options['filters']['field_country_status_tid']['table'] = 'field_data_field_country_status';
  $handler->display->display_options['filters']['field_country_status_tid']['field'] = 'field_country_status_tid';
  $handler->display->display_options['filters']['field_country_status_tid']['relationship'] = 'field_country_tid';
  $handler->display->display_options['filters']['field_country_status_tid']['value'] = array(
    3016 => '3016',
  );
  $handler->display->display_options['filters']['field_country_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_country_status_tid']['vocabulary'] = 'country_status';
  /* Filter criterion: Content: Is Observer (field_is_observer) */
  $handler->display->display_options['filters']['field_is_observer_value']['id'] = 'field_is_observer_value';
  $handler->display->display_options['filters']['field_is_observer_value']['table'] = 'field_data_field_is_observer';
  $handler->display->display_options['filters']['field_is_observer_value']['field'] = 'field_is_observer_value';
  $handler->display->display_options['filters']['field_is_observer_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_is_observer_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Content: Category (field_wg_category) */
  $handler->display->display_options['filters']['field_wg_category_tid']['id'] = 'field_wg_category_tid';
  $handler->display->display_options['filters']['field_wg_category_tid']['table'] = 'field_data_field_wg_category';
  $handler->display->display_options['filters']['field_wg_category_tid']['field'] = 'field_wg_category_tid';
  $handler->display->display_options['filters']['field_wg_category_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_wg_category_tid']['value'] = array(
    3027 => '3027',
  );
  $handler->display->display_options['filters']['field_wg_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_wg_category_tid']['vocabulary'] = 'wg_category';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_contact' => 'press_contact',
  );
  /* Filter criterion: Content: Type (field_contact_type) */
  $handler->display->display_options['filters']['field_contact_type_tid']['id'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['filters']['field_contact_type_tid']['field'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['value'] = array(
    2971 => '2971',
  );
  $handler->display->display_options['filters']['field_contact_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_contact_type_tid']['vocabulary'] = 'contact_type';
  /* Filter criterion: Taxonomy term: Country Status (field_country_status) */
  $handler->display->display_options['filters']['field_country_status_tid']['id'] = 'field_country_status_tid';
  $handler->display->display_options['filters']['field_country_status_tid']['table'] = 'field_data_field_country_status';
  $handler->display->display_options['filters']['field_country_status_tid']['field'] = 'field_country_status_tid';
  $handler->display->display_options['filters']['field_country_status_tid']['relationship'] = 'field_country_tid';
  $handler->display->display_options['filters']['field_country_status_tid']['value'] = array(
    3016 => '3016',
  );
  $handler->display->display_options['filters']['field_country_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_country_status_tid']['vocabulary'] = 'country_status';
  /* Filter criterion: Content: Is Observer (field_is_observer) */
  $handler->display->display_options['filters']['field_is_observer_value']['id'] = 'field_is_observer_value';
  $handler->display->display_options['filters']['field_is_observer_value']['table'] = 'field_data_field_is_observer';
  $handler->display->display_options['filters']['field_is_observer_value']['field'] = 'field_is_observer_value';
  $handler->display->display_options['filters']['field_is_observer_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_is_observer_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Content: Category (field_wg_category) */
  $handler->display->display_options['filters']['field_wg_category_tid']['id'] = 'field_wg_category_tid';
  $handler->display->display_options['filters']['field_wg_category_tid']['table'] = 'field_data_field_wg_category';
  $handler->display->display_options['filters']['field_wg_category_tid']['field'] = 'field_wg_category_tid';
  $handler->display->display_options['filters']['field_wg_category_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_wg_category_tid']['value'] = array(
    4859 => '4859',
    3027 => '3027',
  );
  $handler->display->display_options['filters']['field_wg_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_wg_category_tid']['vocabulary'] = 'wg_category';

  /* Display: Block EFTA */
  $handler = $view->new_display('block', 'Block EFTA', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_contact' => 'press_contact',
  );
  /* Filter criterion: Content: Type (field_contact_type) */
  $handler->display->display_options['filters']['field_contact_type_tid']['id'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['filters']['field_contact_type_tid']['field'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['value'] = array(
    2971 => '2971',
  );
  $handler->display->display_options['filters']['field_contact_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_contact_type_tid']['vocabulary'] = 'contact_type';
  /* Filter criterion: Taxonomy term: Country Status (field_country_status) */
  $handler->display->display_options['filters']['field_country_status_tid']['id'] = 'field_country_status_tid';
  $handler->display->display_options['filters']['field_country_status_tid']['table'] = 'field_data_field_country_status';
  $handler->display->display_options['filters']['field_country_status_tid']['field'] = 'field_country_status_tid';
  $handler->display->display_options['filters']['field_country_status_tid']['relationship'] = 'field_country_tid';
  $handler->display->display_options['filters']['field_country_status_tid']['value'] = array(
    3017 => '3017',
  );
  $handler->display->display_options['filters']['field_country_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_country_status_tid']['vocabulary'] = 'country_status';
  /* Filter criterion: Content: Is Observer (field_is_observer) */
  $handler->display->display_options['filters']['field_is_observer_value']['id'] = 'field_is_observer_value';
  $handler->display->display_options['filters']['field_is_observer_value']['table'] = 'field_data_field_is_observer';
  $handler->display->display_options['filters']['field_is_observer_value']['field'] = 'field_is_observer_value';
  $handler->display->display_options['filters']['field_is_observer_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_is_observer_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Content: Category (field_wg_category) */
  $handler->display->display_options['filters']['field_wg_category_tid']['id'] = 'field_wg_category_tid';
  $handler->display->display_options['filters']['field_wg_category_tid']['table'] = 'field_data_field_wg_category';
  $handler->display->display_options['filters']['field_wg_category_tid']['field'] = 'field_wg_category_tid';
  $handler->display->display_options['filters']['field_wg_category_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_wg_category_tid']['value'] = array(
    4859 => '4859',
    3027 => '3027',
  );
  $handler->display->display_options['filters']['field_wg_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_wg_category_tid']['vocabulary'] = 'wg_category';

  /* Display: Block EC - Obs */
  $handler = $view->new_display('block', 'Block EC - Obs', 'block_2');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_wg_category_tid';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight_1']['relationship'] = 'field_wg_role_1_tid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_contact' => 'press_contact',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Type (field_contact_type) */
  $handler->display->display_options['filters']['field_contact_type_tid']['id'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['filters']['field_contact_type_tid']['field'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['value'] = array(
    2971 => '2971',
  );
  $handler->display->display_options['filters']['field_contact_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_contact_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_contact_type_tid']['vocabulary'] = 'contact_type';
  /* Filter criterion: Content: Is Observer (field_is_observer) */
  $handler->display->display_options['filters']['field_is_observer_value']['id'] = 'field_is_observer_value';
  $handler->display->display_options['filters']['field_is_observer_value']['table'] = 'field_data_field_is_observer';
  $handler->display->display_options['filters']['field_is_observer_value']['field'] = 'field_is_observer_value';
  $handler->display->display_options['filters']['field_is_observer_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_observer_value']['group'] = 2;
  /* Filter criterion: Content: Category (field_wg_category) */
  $handler->display->display_options['filters']['field_wg_category_tid']['id'] = 'field_wg_category_tid';
  $handler->display->display_options['filters']['field_wg_category_tid']['table'] = 'field_data_field_wg_category';
  $handler->display->display_options['filters']['field_wg_category_tid']['field'] = 'field_wg_category_tid';
  $handler->display->display_options['filters']['field_wg_category_tid']['value'] = array(
    3027 => '3027',
  );
  $handler->display->display_options['filters']['field_wg_category_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_wg_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_wg_category_tid']['vocabulary'] = 'wg_category';

  /* Display: Block Expert nominated by the european parliament */
  $handler = $view->new_display('block', 'Block Expert nominated by the european parliament', 'block_3');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_wg_category_tid';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight_1']['relationship'] = 'field_wg_role_1_tid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_contact' => 'press_contact',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Type (field_contact_type) */
  $handler->display->display_options['filters']['field_contact_type_tid']['id'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['filters']['field_contact_type_tid']['field'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['value'] = array(
    2971 => '2971',
  );
  $handler->display->display_options['filters']['field_contact_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_contact_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_contact_type_tid']['vocabulary'] = 'contact_type';
  /* Filter criterion: Content: Category (field_wg_category) */
  $handler->display->display_options['filters']['field_wg_category_tid']['id'] = 'field_wg_category_tid';
  $handler->display->display_options['filters']['field_wg_category_tid']['table'] = 'field_data_field_wg_category';
  $handler->display->display_options['filters']['field_wg_category_tid']['field'] = 'field_wg_category_tid';
  $handler->display->display_options['filters']['field_wg_category_tid']['value'] = array(
    4859 => '4859',
  );
  $handler->display->display_options['filters']['field_wg_category_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_wg_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_wg_category_tid']['vocabulary'] = 'wg_category';
  $translatables['board_members'] = array(
    t('Master'),
    t('Board members'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Ascending'),
    t('Descending'),
    t('term from field_wg_category'),
    t('term from field_wg_role_1'),
    t('term from field_country'),
    t('term from field_country_status'),
    t(' - [field_wg_role_1]'),
    t('wg-role2-[field_wg_role_2_1-tid]'),
    t('([field_wg_role_2])'),
    t('<strong>[field_personal_title] [title_field]</strong> [field_wg_role_2]'),
    t('[field_press_contact_declaration] |'),
    t('[field_press_contact_declaration][field_press_contact_cv]'),
    t('[field_zip_code] [field_city]'),
    t('Block'),
    t('Block EFTA'),
    t('Block EC - Obs'),
    t('Block Expert nominated by the european parliament'),
  );
  $export['board_members'] = $view;

  $view = new view();
  $view->name = 'bureau_members';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Bureau Members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Composition of the Bureau of the Governing Board';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_wg_role_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: WG Role 1 (field_wg_role_1) */
  $handler->display->display_options['relationships']['field_wg_role_1_tid']['id'] = 'field_wg_role_1_tid';
  $handler->display->display_options['relationships']['field_wg_role_1_tid']['table'] = 'field_data_field_wg_role_1';
  $handler->display->display_options['relationships']['field_wg_role_1_tid']['field'] = 'field_wg_role_1_tid';
  $handler->display->display_options['relationships']['field_wg_role_1_tid']['required'] = TRUE;
  /* Relationship: Content: Category (field_wg_category) */
  $handler->display->display_options['relationships']['field_wg_category_tid']['id'] = 'field_wg_category_tid';
  $handler->display->display_options['relationships']['field_wg_category_tid']['table'] = 'field_data_field_wg_category';
  $handler->display->display_options['relationships']['field_wg_category_tid']['field'] = 'field_wg_category_tid';
  $handler->display->display_options['relationships']['field_wg_category_tid']['required'] = TRUE;
  /* Relationship: Content: WG Role 2 (field_wg_role_2) */
  $handler->display->display_options['relationships']['field_wg_role_2_tid']['id'] = 'field_wg_role_2_tid';
  $handler->display->display_options['relationships']['field_wg_role_2_tid']['table'] = 'field_data_field_wg_role_2';
  $handler->display->display_options['relationships']['field_wg_role_2_tid']['field'] = 'field_wg_role_2_tid';
  /* Field: Content: WG Role 1 */
  $handler->display->display_options['fields']['field_wg_role_1']['id'] = 'field_wg_role_1';
  $handler->display->display_options['fields']['field_wg_role_1']['table'] = 'field_data_field_wg_role_1';
  $handler->display->display_options['fields']['field_wg_role_1']['field'] = 'field_wg_role_1';
  $handler->display->display_options['fields']['field_wg_role_1']['label'] = '';
  $handler->display->display_options['fields']['field_wg_role_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_wg_role_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wg_role_1']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_wg_category']['id'] = 'field_wg_category';
  $handler->display->display_options['fields']['field_wg_category']['table'] = 'field_data_field_wg_category';
  $handler->display->display_options['fields']['field_wg_category']['field'] = 'field_wg_category';
  $handler->display->display_options['fields']['field_wg_category']['label'] = '';
  $handler->display->display_options['fields']['field_wg_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_wg_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wg_category']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Personal Title */
  $handler->display->display_options['fields']['field_personal_title']['id'] = 'field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['table'] = 'field_data_field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['field'] = 'field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['label'] = '';
  $handler->display->display_options['fields']['field_personal_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_personal_title']['element_label_colon'] = FALSE;
  /* Field: Content: WG Role 2 */
  $handler->display->display_options['fields']['field_wg_role_2']['id'] = 'field_wg_role_2';
  $handler->display->display_options['fields']['field_wg_role_2']['table'] = 'field_data_field_wg_role_2';
  $handler->display->display_options['fields']['field_wg_role_2']['field'] = 'field_wg_role_2';
  $handler->display->display_options['fields']['field_wg_role_2']['label'] = '';
  $handler->display->display_options['fields']['field_wg_role_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_wg_role_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_wg_role_2']['alter']['text'] = ', [field_wg_role_2]';
  $handler->display->display_options['fields']['field_wg_role_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wg_role_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_wg_role_2']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<strong>[field_personal_title] [title]</strong> ([field_wg_category])[field_wg_role_2]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_wg_role_1_tid';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight_2']['id'] = 'weight_2';
  $handler->display->display_options['sorts']['weight_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight_2']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight_2']['relationship'] = 'field_wg_role_2_tid';
  $handler->display->display_options['sorts']['weight_2']['order'] = 'DESC';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight_1']['relationship'] = 'field_wg_category_tid';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_contact' => 'press_contact',
  );
  /* Filter criterion: Content: Type (field_contact_type) */
  $handler->display->display_options['filters']['field_contact_type_tid']['id'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['filters']['field_contact_type_tid']['field'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['value'] = array(
    3024 => '3024',
  );
  $handler->display->display_options['filters']['field_contact_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_contact_type_tid']['vocabulary'] = 'contact_type';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['bureau_members'] = array(
    t('Master'),
    t('Composition of the Bureau of the Governing Board'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Ascending'),
    t('Descending'),
    t('term from field_wg_role_1'),
    t('term from field_wg_category'),
    t('term from field_wg_role_2'),
    t(', [field_wg_role_2]'),
    t('<strong>[field_personal_title] [title]</strong> ([field_wg_category])[field_wg_role_2]'),
    t('Block'),
  );
  $export['bureau_members'] = $view;

  $view = new view();
  $view->name = 'fop_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FOP Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Focal points\' contact details';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Country (field_country) */
  $handler->display->display_options['relationships']['field_country_tid']['id'] = 'field_country_tid';
  $handler->display->display_options['relationships']['field_country_tid']['table'] = 'field_data_field_country';
  $handler->display->display_options['relationships']['field_country_tid']['field'] = 'field_country_tid';
  $handler->display->display_options['relationships']['field_country_tid']['required'] = TRUE;
  /* Relationship: Taxonomy term: Content using Country */
  $handler->display->display_options['relationships']['reverse_field_country_node']['id'] = 'reverse_field_country_node';
  $handler->display->display_options['relationships']['reverse_field_country_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_country_node']['field'] = 'reverse_field_country_node';
  $handler->display->display_options['relationships']['reverse_field_country_node']['relationship'] = 'field_country_tid';
  $handler->display->display_options['relationships']['reverse_field_country_node']['required'] = TRUE;
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_press_contact_organization']['id'] = 'field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['table'] = 'field_data_field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['field'] = 'field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_organization']['element_label_colon'] = FALSE;
  /* Field: Content: Job title */
  $handler->display->display_options['fields']['field_press_contact_job_title']['id'] = 'field_press_contact_job_title';
  $handler->display->display_options['fields']['field_press_contact_job_title']['table'] = 'field_data_field_press_contact_job_title';
  $handler->display->display_options['fields']['field_press_contact_job_title']['field'] = 'field_press_contact_job_title';
  $handler->display->display_options['fields']['field_press_contact_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_contact_job_title']['hide_empty'] = TRUE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_press_contact_location']['id'] = 'field_press_contact_location';
  $handler->display->display_options['fields']['field_press_contact_location']['table'] = 'field_data_field_press_contact_location';
  $handler->display->display_options['fields']['field_press_contact_location']['field'] = 'field_press_contact_location';
  $handler->display->display_options['fields']['field_press_contact_location']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_location']['element_label_colon'] = FALSE;
  /* Field: Content: Zip Code */
  $handler->display->display_options['fields']['field_zip_code']['id'] = 'field_zip_code';
  $handler->display->display_options['fields']['field_zip_code']['table'] = 'field_data_field_zip_code';
  $handler->display->display_options['fields']['field_zip_code']['field'] = 'field_zip_code';
  $handler->display->display_options['fields']['field_zip_code']['label'] = '';
  $handler->display->display_options['fields']['field_zip_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_zip_code']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_zip_code']['alter']['text'] = '[field_zip_code] ';
  $handler->display->display_options['fields']['field_zip_code']['element_label_colon'] = FALSE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_city']['alter']['text'] = '[field_zip_code][field_city]';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['label'] = '';
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Personal Title */
  $handler->display->display_options['fields']['field_personal_title']['id'] = 'field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['table'] = 'field_data_field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['field'] = 'field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['label'] = '';
  $handler->display->display_options['fields']['field_personal_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_personal_title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Contact person';
  $handler->display->display_options['fields']['title_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '[field_personal_title] [title_field]';
  $handler->display->display_options['fields']['title_field']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title_field']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_press_contact_phone']['id'] = 'field_press_contact_phone';
  $handler->display->display_options['fields']['field_press_contact_phone']['table'] = 'field_data_field_press_contact_phone';
  $handler->display->display_options['fields']['field_press_contact_phone']['field'] = 'field_press_contact_phone';
  $handler->display->display_options['fields']['field_press_contact_phone']['label'] = 'Tel';
  $handler->display->display_options['fields']['field_press_contact_phone']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_press_contact_phone']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_press_contact_phone']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_press_contact_phone']['delta_offset'] = '0';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_press_contact_email']['id'] = 'field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['table'] = 'field_data_field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['field'] = 'field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['label'] = 'E-mail address';
  $handler->display->display_options['fields']['field_press_contact_email']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_press_contact_email']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_press_contact_email']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_press_contact_email']['type'] = 'email_spamspan';
  /* Field: Content: Web Site */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = 'Web';
  $handler->display->display_options['fields']['field_website']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_website']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_website']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_url';
  /* Contextual filter: Content: Country (field_country) */
  $handler->display->display_options['arguments']['field_country_tid']['id'] = 'field_country_tid';
  $handler->display->display_options['arguments']['field_country_tid']['table'] = 'field_data_field_country';
  $handler->display->display_options['arguments']['field_country_tid']['field'] = 'field_country_tid';
  $handler->display->display_options['arguments']['field_country_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_options']['vocabularies'] = array(
    'country' => 'country',
  );
  $handler->display->display_options['arguments']['field_country_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_country_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_country_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_contact' => 'press_contact',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Type (field_contact_type) */
  $handler->display->display_options['filters']['field_contact_type_tid']['id'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['filters']['field_contact_type_tid']['field'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['value'] = array(
    2970 => '2970',
  );
  $handler->display->display_options['filters']['field_contact_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_contact_type_tid']['vocabulary'] = 'contact_type';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['fop_contacts'] = array(
    t('Master'),
    t('Focal points\' contact details'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Ascending'),
    t('Descending'),
    t('term from field_country'),
    t('field_country'),
    t('[field_zip_code] '),
    t('[field_zip_code][field_city]'),
    t('Contact person'),
    t('[field_personal_title] [title_field]'),
    t('Tel'),
    t('E-mail address'),
    t('Web'),
    t('All'),
    t('Block'),
  );
  $export['fop_contacts'] = $view;

  $view = new view();
  $view->name = 'press_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Press contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Press contacts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'press_contacts_queue' => 'press_contacts_queue',
    'publication_queue' => 0,
    'featured_press_release' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_contact' => 'press_contact',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_press_contact_organization' => 'field_press_contact_organization',
    'field_press_contact_email' => 'field_press_contact_email',
    'edit_node' => 'edit_node',
    'delete_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_press_contact_organization' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_press_contact_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '&emsp;',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Publish',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unpublish',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nume';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_press_contact_organization']['id'] = 'field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['table'] = 'field_data_field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['field'] = 'field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['label'] = 'Organizație';
  $handler->display->display_options['fields']['field_press_contact_organization']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_press_contact_organization']['settings'] = array(
    'trim_length' => '100',
  );
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_press_contact_email']['id'] = 'field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['table'] = 'field_data_field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['field'] = 'field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['label'] = 'E-mail address';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_contact' => 'press_contact',
  );
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'word';
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Contact Name';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Email (field_press_contact_email) */
  $handler->display->display_options['filters']['field_press_contact_email_email']['id'] = 'field_press_contact_email_email';
  $handler->display->display_options['filters']['field_press_contact_email_email']['table'] = 'field_data_field_press_contact_email';
  $handler->display->display_options['filters']['field_press_contact_email_email']['field'] = 'field_press_contact_email_email';
  $handler->display->display_options['filters']['field_press_contact_email_email']['operator'] = 'word';
  $handler->display->display_options['filters']['field_press_contact_email_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_press_contact_email_email']['expose']['operator_id'] = 'field_press_contact_email_email_op';
  $handler->display->display_options['filters']['field_press_contact_email_email']['expose']['label'] = 'E-mail address';
  $handler->display->display_options['filters']['field_press_contact_email_email']['expose']['operator'] = 'field_press_contact_email_email_op';
  $handler->display->display_options['filters']['field_press_contact_email_email']['expose']['identifier'] = 'field_press_contact_email_email';
  $handler->display->display_options['filters']['field_press_contact_email_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_press_contact_email_email']['group_info']['label'] = 'Email (field_press_contact_email)';
  $handler->display->display_options['filters']['field_press_contact_email_email']['group_info']['identifier'] = 'field_press_contact_email_email';
  $handler->display->display_options['filters']['field_press_contact_email_email']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_press_contact_email_email']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['path'] = 'admin/content/press-contacts';
  $handler->display->display_options['menu']['title'] = 'Press contacts';
  $handler->display->display_options['menu']['description'] = 'Press contacts Administration Interface';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Press contacts';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['empty'] = TRUE;
  $handler->display->display_options['footer']['php']['php_output'] = '<?php print l(t(\'EU-OSHA Press kit\'), \'about-eu-osha/press-room/press-kit\', array(\'attributes\' => array(\'class\' => \'press-kit-link\'))); ?>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Job title */
  $handler->display->display_options['fields']['field_press_contact_job_title']['id'] = 'field_press_contact_job_title';
  $handler->display->display_options['fields']['field_press_contact_job_title']['table'] = 'field_data_field_press_contact_job_title';
  $handler->display->display_options['fields']['field_press_contact_job_title']['field'] = 'field_press_contact_job_title';
  $handler->display->display_options['fields']['field_press_contact_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_job_title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_press_contact_phone']['id'] = 'field_press_contact_phone';
  $handler->display->display_options['fields']['field_press_contact_phone']['table'] = 'field_data_field_press_contact_phone';
  $handler->display->display_options['fields']['field_press_contact_phone']['field'] = 'field_press_contact_phone';
  $handler->display->display_options['fields']['field_press_contact_phone']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_phone']['element_label_colon'] = FALSE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_press_contact_email']['id'] = 'field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['table'] = 'field_data_field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['field'] = 'field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_email']['element_label_colon'] = FALSE;
  $translatables['press_contacts'] = array(
    t('Master'),
    t('Press contacts'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Ascending'),
    t('Descending'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('queue'),
    t('Page'),
    t('- Choose an operation -'),
    t('Delete'),
    t('Publish'),
    t('Unpublish'),
    t('Nume'),
    t('Organizație'),
    t('E-mail address'),
    t('Operations'),
    t('Edit'),
    t('Contact Name'),
    t('Email (field_press_contact_email)'),
    t('Block'),
  );
  $export['press_contacts'] = $view;

  return $export;
}
