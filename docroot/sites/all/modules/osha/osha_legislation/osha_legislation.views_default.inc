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
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_directive_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_summary' => 'field_summary',
    'field_directive_type' => 'field_directive_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_summary' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_directive_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_summary']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_summary']['alter']['text'] = '[title_field]
[field_summary]';
  $handler->display->display_options['fields']['field_summary']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_summary']['type'] = 'text_plain';
  /* Field: Content: Directive Type */
  $handler->display->display_options['fields']['field_directive_type']['id'] = 'field_directive_type';
  $handler->display->display_options['fields']['field_directive_type']['table'] = 'field_data_field_directive_type';
  $handler->display->display_options['fields']['field_directive_type']['field'] = 'field_directive_type';
  $handler->display->display_options['fields']['field_directive_type']['label'] = '';
  $handler->display->display_options['fields']['field_directive_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_directive_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_directive_type']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight_1']['relationship'] = 'field_directive_type_tid';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_legislation_category_tid';
  /* Sort criterion: Content: Date of directive (field_date_of_directive) */
  $handler->display->display_options['sorts']['field_date_of_directive_value']['id'] = 'field_date_of_directive_value';
  $handler->display->display_options['sorts']['field_date_of_directive_value']['table'] = 'field_data_field_date_of_directive';
  $handler->display->display_options['sorts']['field_date_of_directive_value']['field'] = 'field_date_of_directive_value';
  $handler->display->display_options['sorts']['field_date_of_directive_value']['order'] = 'DESC';
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
  /* Filter criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[title_field]
[body]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_summary']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_summary']['alter']['text'] = '[title_field]
[field_summary]';
  $handler->display->display_options['fields']['field_summary']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_summary']['empty'] = '[title_field]
[body]';
  $handler->display->display_options['fields']['field_summary']['type'] = 'text_plain';
  /* Field: Content: Directive Type */
  $handler->display->display_options['fields']['field_directive_type']['id'] = 'field_directive_type';
  $handler->display->display_options['fields']['field_directive_type']['table'] = 'field_data_field_directive_type';
  $handler->display->display_options['fields']['field_directive_type']['field'] = 'field_directive_type';
  $handler->display->display_options['fields']['field_directive_type']['label'] = '';
  $handler->display->display_options['fields']['field_directive_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_directive_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_directive_type']['type'] = 'taxonomy_term_reference_plain';
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
    t('No results'),
    t('term from field_legislation_category'),
    t('term from field_directive_type'),
    t('[title_field]
[field_summary]'),
    t('All'),
    t('Page'),
    t('[title_field]
[body]'),
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
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
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
  /* Sort criterion: Field: Publication date (field_publication_date) */
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'guideline' => 'guideline',
  );
  /* Filter criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'legislation/guidelines/%';

  /* Display: Guidelines by topics */
  $handler = $view->new_display('block', 'Guidelines by topics', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Guidelines by topics';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_guideline_category_code' => 'field_guideline_category_code',
    'field_legislation_category' => 'field_legislation_category',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_guideline_category_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_legislation_category' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Guideline Category Code */
  $handler->display->display_options['fields']['field_guideline_category_code']['id'] = 'field_guideline_category_code';
  $handler->display->display_options['fields']['field_guideline_category_code']['table'] = 'field_data_field_guideline_category_code';
  $handler->display->display_options['fields']['field_guideline_category_code']['field'] = 'field_guideline_category_code';
  $handler->display->display_options['fields']['field_guideline_category_code']['relationship'] = 'field_legislation_category_tid';
  $handler->display->display_options['fields']['field_guideline_category_code']['label'] = '';
  $handler->display->display_options['fields']['field_guideline_category_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_guideline_category_code']['element_label_colon'] = FALSE;
  /* Field: Content: Legislation category */
  $handler->display->display_options['fields']['field_legislation_category']['id'] = 'field_legislation_category';
  $handler->display->display_options['fields']['field_legislation_category']['table'] = 'field_data_field_legislation_category';
  $handler->display->display_options['fields']['field_legislation_category']['field'] = 'field_legislation_category';
  $handler->display->display_options['fields']['field_legislation_category']['label'] = '';
  $handler->display->display_options['fields']['field_legislation_category']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_legislation_category']['alter']['path'] = 'legislation/guidelines/[field_guideline_category_code]';
  $handler->display->display_options['fields']['field_legislation_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_legislation_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_legislation_category_tid';
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
    t('Guidelines by topics'),
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
  $handler->display->display_options['title'] = 'Search directives';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['parse_mode'] = 'direct';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '<span class="result_summary">Displaying @start - @end of @total</span>';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  /* Field: Indexed Multilingual Content: Multilingual ID */
  $handler->display->display_options['fields']['search_api_et_id']['id'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Sort criterion: Indexed Multilingual Content: Date of directive */
  $handler->display->display_options['sorts']['field_date_of_directive']['id'] = 'field_date_of_directive';
  $handler->display->display_options['sorts']['field_date_of_directive']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_date_of_directive']['field'] = 'field_date_of_directive';
  $handler->display->display_options['sorts']['field_date_of_directive']['order'] = 'DESC';
  /* Filter criterion: Indexed Multilingual Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Multilingual Content: Content type */
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
  /* Filter criterion: Indexed Multilingual Content: Publication date */
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
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'en' => 'en',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'search/directives';
  $translatables['search_directives'] = array(
    t('Master'),
    t('Search directives'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('«'),
    t('‹'),
    t('›'),
    t('»'),
    t('<span class="result_summary">Displaying @start - @end of @total</span>'),
    t('No results'),
    t('Multilingual ID'),
    t('Free text search'),
    t('Directive number'),
    t('Page'),
  );
  $export['search_directives'] = $view;

  $view = new view();
  $view->name = 'search_guidelines';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_multilingual_node_index';
  $view->human_name = 'Search Guidelines';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search guidelines';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['parse_mode'] = 'direct';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '<span class="result_summary">Displaying @start - @end of @total</span>';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  /* Field: Indexed Multilingual Content: Multilingual ID */
  $handler->display->display_options['fields']['search_api_et_id']['id'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Sort criterion: Indexed Multilingual Content: Publication date */
  $handler->display->display_options['sorts']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['order'] = 'DESC';
  /* Filter criterion: Indexed Multilingual Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'guideline' => 'guideline',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Free text search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'filter';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:value' => 'body:value',
    'field_summary' => 'field_summary',
    'title_field' => 'title_field',
  );
  /* Filter criterion: Indexed Multilingual Content: Publication date */
  $handler->display->display_options['filters']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['filters']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['filters']['field_publication_date']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date']['value'] = 'now';
  $handler->display->display_options['filters']['field_publication_date']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'search/guidelines';
  $translatables['search_guidelines'] = array(
    t('Master'),
    t('Search guidelines'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('«'),
    t('‹'),
    t('›'),
    t('»'),
    t('<span class="result_summary">Displaying @start - @end of @total</span>'),
    t('No results'),
    t('Multilingual ID'),
    t('Free text search'),
    t('Page'),
  );
  $export['search_guidelines'] = $view;

  return $export;
}
