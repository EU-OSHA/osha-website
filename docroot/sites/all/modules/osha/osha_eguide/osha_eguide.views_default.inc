<?php
/**
 * @file
 * osha_eguide.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_eguide_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'e_guides';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'E-Guides';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ACCESS TO THE NATIONAL VERSIONS OF THE E-GUIDE';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Find the e-guide version that is relevant for you by filtering by country and / or language';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  /* Field: Field: Language */
  $handler->display->display_options['fields']['field_language']['id'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['table'] = 'field_data_field_language';
  $handler->display->display_options['fields']['field_language']['field'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['label'] = '';
  $handler->display->display_options['fields']['field_language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_language']['settings'] = array(
    'format' => array(
      'iso' => 'iso',
      'name' => 0,
      'name_native' => 0,
    ),
  );
  /* Field: Content: External URL */
  $handler->display->display_options['fields']['field_external_url']['id'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['table'] = 'field_data_field_external_url';
  $handler->display->display_options['fields']['field_external_url']['field'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['label'] = '';
  $handler->display->display_options['fields']['field_external_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_external_url']['click_sort_column'] = 'url';
  /* Field: Field: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  /* Sort criterion: Content: Country (field_country_code) */
  $handler->display->display_options['sorts']['field_country_code_value']['id'] = 'field_country_code_value';
  $handler->display->display_options['sorts']['field_country_code_value']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['sorts']['field_country_code_value']['field'] = 'field_country_code_value';
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
    'e_guide' => 'e_guide',
  );
  /* Filter criterion: Content: Country (field_country_code) */
  $handler->display->display_options['filters']['field_country_code_value']['id'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['filters']['field_country_code_value']['field'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_country_code_value']['expose']['operator_id'] = 'field_country_code_value_op';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['operator'] = 'field_country_code_value_op';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['identifier'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_country_code_value']['group_info']['label'] = 'Country (field_country_code)';
  $handler->display->display_options['filters']['field_country_code_value']['group_info']['identifier'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => 'or',
      'value' => array(),
    ),
    2 => array(
      'title' => '',
      'operator' => 'or',
      'value' => array(),
    ),
    3 => array(
      'title' => '',
      'operator' => 'or',
      'value' => array(),
    ),
  );
  /* Filter criterion: Field: Language (field_language) */
  $handler->display->display_options['filters']['field_language_value']['id'] = 'field_language_value';
  $handler->display->display_options['filters']['field_language_value']['table'] = 'field_data_field_language';
  $handler->display->display_options['filters']['field_language_value']['field'] = 'field_language_value';
  $handler->display->display_options['filters']['field_language_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_language_value']['expose']['operator_id'] = 'field_language_value_op';
  $handler->display->display_options['filters']['field_language_value']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['field_language_value']['expose']['operator'] = 'field_language_value_op';
  $handler->display->display_options['filters']['field_language_value']['expose']['identifier'] = 'field_language_value';
  $handler->display->display_options['filters']['field_language_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_language_value']['group_info']['label'] = 'Language (field_language)';
  $handler->display->display_options['filters']['field_language_value']['group_info']['identifier'] = 'field_language_value';
  $handler->display->display_options['filters']['field_language_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_language_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['e_guides'] = array(
    t('Master'),
    t('ACCESS TO THE NATIONAL VERSIONS OF THE E-GUIDE'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Find the e-guide version that is relevant for you by filtering by country and / or language'),
    t('Country'),
    t('Country (field_country_code)'),
    t('Language'),
    t('Language (field_language)'),
    t('Block'),
  );
  $export['e_guides'] = $view;

  return $export;
}
