<?php
/**
 * @file
 * osha_legislation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_legislation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'legislation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Legislation Directives';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Legislation';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_directive_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Legislation category (field_legislation_category) */
  $handler->display->display_options['relationships']['field_legislation_category_tid']['id'] = 'field_legislation_category_tid';
  $handler->display->display_options['relationships']['field_legislation_category_tid']['table'] = 'field_data_field_legislation_category';
  $handler->display->display_options['relationships']['field_legislation_category_tid']['field'] = 'field_legislation_category_tid';
  $handler->display->display_options['relationships']['field_legislation_category_tid']['required'] = TRUE;
  /* Relationship: Content: Directive Type (field_directive_type) */
  $handler->display->display_options['relationships']['field_directive_type_tid']['id'] = 'field_directive_type_tid';
  $handler->display->display_options['relationships']['field_directive_type_tid']['table'] = 'field_data_field_directive_type';
  $handler->display->display_options['relationships']['field_directive_type_tid']['field'] = 'field_directive_type_tid';
  $handler->display->display_options['relationships']['field_directive_type_tid']['required'] = TRUE;
  /* Relationship: Workbench Moderation: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['relationships']['nid_1']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid_1']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid_1']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Directive Type */
  $handler->display->display_options['fields']['field_directive_type']['id'] = 'field_directive_type';
  $handler->display->display_options['fields']['field_directive_type']['table'] = 'field_data_field_directive_type';
  $handler->display->display_options['fields']['field_directive_type']['field'] = 'field_directive_type';
  $handler->display->display_options['fields']['field_directive_type']['label'] = '';
  $handler->display->display_options['fields']['field_directive_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_directive_type']['element_label_colon'] = FALSE;
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_summary']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Published */
  $handler->display->display_options['sorts']['status']['id'] = 'status';
  $handler->display->display_options['sorts']['status']['table'] = 'node';
  $handler->display->display_options['sorts']['status']['field'] = 'status';
  $handler->display->display_options['sorts']['status']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Directive Category Code (field_directive_category_code) */
  $handler->display->display_options['arguments']['field_directive_category_code_value']['id'] = 'field_directive_category_code_value';
  $handler->display->display_options['arguments']['field_directive_category_code_value']['table'] = 'field_data_field_directive_category_code';
  $handler->display->display_options['arguments']['field_directive_category_code_value']['field'] = 'field_directive_category_code_value';
  $handler->display->display_options['arguments']['field_directive_category_code_value']['relationship'] = 'field_legislation_category_tid';
  $handler->display->display_options['arguments']['field_directive_category_code_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_directive_category_code_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_directive_category_code_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_directive_category_code_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_directive_category_code_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['current']['id'] = 'current';
  $handler->display->display_options['filters']['current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['current']['field'] = 'current';
  $handler->display->display_options['filters']['current']['relationship'] = 'nid';
  $handler->display->display_options['filters']['current']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'legislation/directives/%';
  $translatables['legislation'] = array(
    t('Master'),
    t('Legislation'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('term from field_legislation_category'),
    t('term from field_directive_type'),
    t('Node'),
    t('Get the actual content from a content revision.'),
    t('All'),
    t('Page'),
  );
  $export['legislation'] = $view;

  $view = new view();
  $view->name = 'legislation_guidelines';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Legislation Guidelines';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Legislation';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Content: Legislation category (field_legislation_category) */
  $handler->display->display_options['relationships']['field_legislation_category_tid']['id'] = 'field_legislation_category_tid';
  $handler->display->display_options['relationships']['field_legislation_category_tid']['table'] = 'field_data_field_legislation_category';
  $handler->display->display_options['relationships']['field_legislation_category_tid']['field'] = 'field_legislation_category_tid';
  $handler->display->display_options['relationships']['field_legislation_category_tid']['required'] = TRUE;
  /* Relationship: Workbench Moderation: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['relationships']['nid_1']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid_1']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid_1']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Legislation category */
  $handler->display->display_options['fields']['field_legislation_category']['id'] = 'field_legislation_category';
  $handler->display->display_options['fields']['field_legislation_category']['table'] = 'field_data_field_legislation_category';
  $handler->display->display_options['fields']['field_legislation_category']['field'] = 'field_legislation_category';
  $handler->display->display_options['fields']['field_legislation_category']['label'] = '';
  $handler->display->display_options['fields']['field_legislation_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_legislation_category']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Guideline Category Code (field_guideline_category_code) */
  $handler->display->display_options['arguments']['field_guideline_category_code_value']['id'] = 'field_guideline_category_code_value';
  $handler->display->display_options['arguments']['field_guideline_category_code_value']['table'] = 'field_data_field_guideline_category_code';
  $handler->display->display_options['arguments']['field_guideline_category_code_value']['field'] = 'field_guideline_category_code_value';
  $handler->display->display_options['arguments']['field_guideline_category_code_value']['relationship'] = 'field_legislation_category_tid';
  $handler->display->display_options['arguments']['field_guideline_category_code_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_guideline_category_code_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_guideline_category_code_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_guideline_category_code_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_guideline_category_code_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['current']['id'] = 'current';
  $handler->display->display_options['filters']['current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['current']['field'] = 'current';
  $handler->display->display_options['filters']['current']['relationship'] = 'nid';
  $handler->display->display_options['filters']['current']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'guideline' => 'guideline',
  );
  /* Filter criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'legislation/guidelines/%';
  $translatables['legislation_guidelines'] = array(
    t('Master'),
    t('Legislation'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('term from field_legislation_category'),
    t('Node'),
    t('Get the actual content from a content revision.'),
    t('All'),
    t('Page'),
  );
  $export['legislation_guidelines'] = $view;

  $view = new view();
  $view->name = 'search_directives';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_multilingual_node_index';
  $view->human_name = 'Search Directives';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search Directives';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  /* Field: Indexed Multilingual Node: Multilingual ID */
  $handler->display->display_options['fields']['search_api_et_id']['id'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Sort criterion: Indexed Multilingual Node: Date of directive */
  $handler->display->display_options['sorts']['field_date_of_directive']['id'] = 'field_date_of_directive';
  $handler->display->display_options['sorts']['field_date_of_directive']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_date_of_directive']['field'] = 'field_date_of_directive';
  $handler->display->display_options['sorts']['field_date_of_directive']['order'] = 'DESC';
  /* Filter criterion: Indexed Multilingual Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Multilingual Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'directive' => 'directive',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Free text search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'filter';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:summary' => 'body:summary',
    'body:value' => 'body:value',
    'title_field' => 'title_field',
  );
  /* Filter criterion: Indexed Multilingual Node: Publication date */
  $handler->display->display_options['filters']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['filters']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['filters']['field_publication_date']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date']['value'] = 'now';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['id'] = 'search_api_views_fulltext_1';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['expose']['operator_id'] = 'search_api_views_fulltext_1_op';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['expose']['label'] = 'Directive number';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['expose']['operator'] = 'search_api_views_fulltext_1_op';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['expose']['identifier'] = 'filter-title';
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext_1']['fields'] = array(
    'title_field' => 'title_field',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'search/directives';
  $translatables['search_directives'] = array(
    t('Master'),
    t('Search Directives'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No results'),
    t('Multilingual ID'),
    t('Free text search'),
    t('Directive number'),
    t('Page'),
  );
  $export['search_directives'] = $view;

  return $export;
}
