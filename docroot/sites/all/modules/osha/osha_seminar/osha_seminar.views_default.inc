<?php
/**
 * @file
 * osha_seminar.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_seminar_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'search_seminars';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_multilingual_node_index';
  $view->human_name = 'Search seminars';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search seminars';
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
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a class="seminar_back-to-seminars back-to-link" href="/tools-and-resources/seminars">Back to seminars</a>';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
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
  /* Sort criterion: Indexed Multilingual Content: Start date */
  $handler->display->display_options['sorts']['field_seminar_start_date']['id'] = 'field_seminar_start_date';
  $handler->display->display_options['sorts']['field_seminar_start_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_seminar_start_date']['field'] = 'field_seminar_start_date';
  $handler->display->display_options['sorts']['field_seminar_start_date']['order'] = 'DESC';
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
    'seminar' => 'seminar',
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
    'attachments_field_related_resources' => 'attachments_field_related_resources',
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
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['search_api_language']['expose']['operator_id'] = 'search_api_language_op';
  $handler->display->display_options['filters']['search_api_language']['expose']['label'] = 'Item language';
  $handler->display->display_options['filters']['search_api_language']['expose']['operator'] = 'search_api_language_op';
  $handler->display->display_options['filters']['search_api_language']['expose']['identifier'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['search_api_language']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '<span class="result_summary">Displaying @start - @end of @total</span>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'seminar' => 'seminar',
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
    'attachments_field_related_resources' => 'attachments_field_related_resources',
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
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['search_api_language']['expose']['operator_id'] = 'search_api_language_op';
  $handler->display->display_options['filters']['search_api_language']['expose']['label'] = 'Item language';
  $handler->display->display_options['filters']['search_api_language']['expose']['operator'] = 'search_api_language_op';
  $handler->display->display_options['filters']['search_api_language']['expose']['identifier'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['search_api_language']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Multilingual Content: Start date */
  $handler->display->display_options['filters']['field_seminar_start_date']['id'] = 'field_seminar_start_date';
  $handler->display->display_options['filters']['field_seminar_start_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_seminar_start_date']['field'] = 'field_seminar_start_date';
  $handler->display->display_options['filters']['field_seminar_start_date']['operator'] = '>=';
  $handler->display->display_options['filters']['field_seminar_start_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_seminar_start_date']['expose']['operator_id'] = 'field_seminar_start_date_op';
  $handler->display->display_options['filters']['field_seminar_start_date']['expose']['label'] = 'Start date';
  $handler->display->display_options['filters']['field_seminar_start_date']['expose']['operator'] = 'field_seminar_start_date_op';
  $handler->display->display_options['filters']['field_seminar_start_date']['expose']['identifier'] = 'field_seminar_start_date';
  $handler->display->display_options['filters']['field_seminar_start_date']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_seminar_start_date']['widget_type'] = 'date_popup';
  /* Filter criterion: Indexed Multilingual Content: End date */
  $handler->display->display_options['filters']['field_seminar_end_date']['id'] = 'field_seminar_end_date';
  $handler->display->display_options['filters']['field_seminar_end_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_seminar_end_date']['field'] = 'field_seminar_end_date';
  $handler->display->display_options['filters']['field_seminar_end_date']['operator'] = '<=';
  $handler->display->display_options['filters']['field_seminar_end_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_seminar_end_date']['expose']['operator_id'] = 'field_seminar_end_date_op';
  $handler->display->display_options['filters']['field_seminar_end_date']['expose']['label'] = 'End date';
  $handler->display->display_options['filters']['field_seminar_end_date']['expose']['operator'] = 'field_seminar_end_date_op';
  $handler->display->display_options['filters']['field_seminar_end_date']['expose']['identifier'] = 'field_seminar_end_date';
  $handler->display->display_options['filters']['field_seminar_end_date']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_seminar_end_date']['widget_type'] = 'date_popup';
  $handler->display->display_options['path'] = 'search/seminars';

  /* Display: Facets block */
  $handler = $view->new_display('search_api_views_facets_block', 'Facets block', 'search_api_views_facets_block_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Content: Main Tags */
  $handler->display->display_options['fields']['main_tags']['id'] = 'main_tags';
  $handler->display->display_options['fields']['main_tags']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['main_tags']['field'] = 'main_tags';
  $handler->display->display_options['fields']['main_tags']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['main_tags']['view_mode'] = 'full';
  $handler->display->display_options['fields']['main_tags']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Search: Fulltext search */
  $handler->display->display_options['arguments']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['search_api_views_fulltext']['not'] = 0;
  $handler->display->display_options['block_description'] = 'Seminar Topics Facet';
  $handler->display->display_options['linked_path'] = 'search/seminars';
  $handler->display->display_options['facet_field'] = 'main_tags';
  $translatables['search_seminars'] = array(
    t('Master'),
    t('Search seminars'),
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
    t('<a class="seminar_back-to-seminars back-to-link" href="/tools-and-resources/seminars">Back to seminars</a>'),
    t('Displaying @start - @end of @total'),
    t('No results'),
    t('Multilingual ID'),
    t('Free text search'),
    t('Item language'),
    t('Page'),
    t('<span class="result_summary">Displaying @start - @end of @total</span>'),
    t('Start date'),
    t('End date'),
    t('Facets block'),
    t('Main Tags'),
    t('All'),
    t('Seminar Topics Facet'),
  );
  $export['search_seminars'] = $view;

  $view = new view();
  $view->name = 'seminar_pages_count';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'seminar_pages_count';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '250';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
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
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Report */
  $handler->display->display_options['fields']['field_report']['id'] = 'field_report';
  $handler->display->display_options['fields']['field_report']['table'] = 'field_data_field_report';
  $handler->display->display_options['fields']['field_report']['field'] = 'field_report';
  $handler->display->display_options['fields']['field_report']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_report']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_report']['delta_offset'] = '0';
  /* Field: Content: Report (field_report:language) */
  $handler->display->display_options['fields']['language_1']['id'] = 'language_1';
  $handler->display->display_options['fields']['language_1']['table'] = 'field_data_field_report';
  $handler->display->display_options['fields']['language_1']['field'] = 'language';
  /* Field: Content: Number of pages */
  $handler->display->display_options['fields']['field_pages_count']['id'] = 'field_pages_count';
  $handler->display->display_options['fields']['field_pages_count']['table'] = 'field_data_field_pages_count';
  $handler->display->display_options['fields']['field_pages_count']['field'] = 'field_pages_count';
  $handler->display->display_options['fields']['field_pages_count']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Pages count updated */
  $handler->display->display_options['fields']['field_pages_count_updated']['id'] = 'field_pages_count_updated';
  $handler->display->display_options['fields']['field_pages_count_updated']['table'] = 'field_data_field_pages_count_updated';
  $handler->display->display_options['fields']['field_pages_count_updated']['field'] = 'field_pages_count_updated';
  $handler->display->display_options['fields']['field_pages_count_updated']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'osha_date_theme' => '',
  );
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'pubdate_rss';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'year';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
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
    'seminar' => 'seminar',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Report (field_report:fid) */
  $handler->display->display_options['filters']['field_report_fid']['id'] = 'field_report_fid';
  $handler->display->display_options['filters']['field_report_fid']['table'] = 'field_data_field_report';
  $handler->display->display_options['filters']['field_report_fid']['field'] = 'field_report_fid';
  $handler->display->display_options['filters']['field_report_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_report_fid']['group'] = 1;
  /* Filter criterion: Content: Report (field_report:language) */
  $handler->display->display_options['filters']['language_1']['id'] = 'language_1';
  $handler->display->display_options['filters']['language_1']['table'] = 'field_data_field_report';
  $handler->display->display_options['filters']['language_1']['field'] = 'language';
  $handler->display->display_options['filters']['language_1']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['language_1']['group'] = 1;
  $translatables['seminar_pages_count'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('Report'),
    t('Report (field_report:language)'),
    t('Number of pages'),
    t('Pages count updated'),
    t('Updated date'),
  );
  $export['seminar_pages_count'] = $view;

  $view = new view();
  $view->name = 'seminars';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Seminars';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'EU-OSHA Seminars';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_seminar_location']['id'] = 'field_seminar_location';
  $handler->display->display_options['fields']['field_seminar_location']['table'] = 'field_data_field_seminar_location';
  $handler->display->display_options['fields']['field_seminar_location']['field'] = 'field_seminar_location';
  $handler->display->display_options['fields']['field_seminar_location']['label'] = '';
  $handler->display->display_options['fields']['field_seminar_location']['element_label_colon'] = FALSE;
  /* Field: Displayed start date */
  $handler->display->display_options['fields']['field_seminar_start_date']['id'] = 'field_seminar_start_date';
  $handler->display->display_options['fields']['field_seminar_start_date']['table'] = 'field_data_field_seminar_start_date';
  $handler->display->display_options['fields']['field_seminar_start_date']['field'] = 'field_seminar_start_date';
  $handler->display->display_options['fields']['field_seminar_start_date']['ui_name'] = 'Displayed start date';
  $handler->display->display_options['fields']['field_seminar_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_seminar_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_seminar_start_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Grouping start date */
  $handler->display->display_options['fields']['field_seminar_start_date_1']['id'] = 'field_seminar_start_date_1';
  $handler->display->display_options['fields']['field_seminar_start_date_1']['table'] = 'field_data_field_seminar_start_date';
  $handler->display->display_options['fields']['field_seminar_start_date_1']['field'] = 'field_seminar_start_date';
  $handler->display->display_options['fields']['field_seminar_start_date_1']['ui_name'] = 'Grouping start date';
  $handler->display->display_options['fields']['field_seminar_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_seminar_start_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_seminar_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_seminar_start_date_1']['settings'] = array(
    'format_type' => 'year_seminar',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Sort criterion: Content: Start date (field_seminar_start_date) */
  $handler->display->display_options['sorts']['field_seminar_start_date_value']['id'] = 'field_seminar_start_date_value';
  $handler->display->display_options['sorts']['field_seminar_start_date_value']['table'] = 'field_data_field_seminar_start_date';
  $handler->display->display_options['sorts']['field_seminar_start_date_value']['field'] = 'field_seminar_start_date_value';
  $handler->display->display_options['sorts']['field_seminar_start_date_value']['order'] = 'DESC';
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
    'seminar' => 'seminar',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'EU-OSHA Seminars';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_seminar_start_date_1',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-list wysiwyg_accordion';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Start date */
  $handler->display->display_options['fields']['field_seminar_start_date']['id'] = 'field_seminar_start_date';
  $handler->display->display_options['fields']['field_seminar_start_date']['table'] = 'field_data_field_seminar_start_date';
  $handler->display->display_options['fields']['field_seminar_start_date']['field'] = 'field_seminar_start_date';
  $handler->display->display_options['fields']['field_seminar_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_seminar_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_seminar_start_date']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_seminar_location']['id'] = 'field_seminar_location';
  $handler->display->display_options['fields']['field_seminar_location']['table'] = 'field_data_field_seminar_location';
  $handler->display->display_options['fields']['field_seminar_location']['field'] = 'field_seminar_location';
  $handler->display->display_options['fields']['field_seminar_location']['label'] = '';
  $handler->display->display_options['fields']['field_seminar_location']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'publication_title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'h2',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Start date for grouping */
  $handler->display->display_options['fields']['field_seminar_start_date_1']['id'] = 'field_seminar_start_date_1';
  $handler->display->display_options['fields']['field_seminar_start_date_1']['table'] = 'field_data_field_seminar_start_date';
  $handler->display->display_options['fields']['field_seminar_start_date_1']['field'] = 'field_seminar_start_date';
  $handler->display->display_options['fields']['field_seminar_start_date_1']['ui_name'] = 'Start date for grouping';
  $handler->display->display_options['fields']['field_seminar_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_seminar_start_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_seminar_start_date_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_seminar_start_date_1']['alter']['text'] = '[field_seminar_start_date_1] - Seminars';
  $handler->display->display_options['fields']['field_seminar_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_seminar_start_date_1']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '250';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '250',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 'text',
    ),
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'See details';
  $translatables['seminars'] = array(
    t('Master'),
    t('EU-OSHA Seminars'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
    t('[field_seminar_start_date_1] - Seminars'),
    t('See details'),
  );
  $export['seminars'] = $view;

  return $export;
}
