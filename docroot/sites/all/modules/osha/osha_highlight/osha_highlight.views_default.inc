<?php
/**
 * @file
 * osha_highlight.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_highlight_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'highlight';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Highlight';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Highlights';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
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
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  /* Filter criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['granularity'] = 'second';
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'highlight' => 'highlight',
  );

  /* Display: Highlights - all */
  $handler = $view->new_display('page', 'Highlights - all', 'page');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '<div class="pager-total"><span>@start - @end / @total</span></div>';
  $handler->display->display_options['path'] = 'highlights';

  /* Display: Latest Highlights */
  $handler = $view->new_display('block', 'Latest Highlights', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Highlights';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all highlights';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'img-highlight';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'home_news',
    'image_link' => 'content',
  );
  /* Field: Field: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title_field']['element_class'] = 'views-field-title';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '110',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '210',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'See more',
    'summary_handler' => 'trim',
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
  $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'views-field views-field-view-node';
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'See more';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_publication_date] == Field: Publication date
[title_field] == Content: Title
[body] == Content: Body
[view_node] == Content: Link
[field_image] == Content: Image';
  $translatables['highlight'] = array(
    t('Master'),
    t('Highlights'),
    t('more'),
    t('Apply'),
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
    t('Highlights - all'),
    t('<div class="pager-total"><span>@start - @end / @total</span></div>'),
    t('Latest Highlights'),
    t('View all highlights'),
    t('See more'),
    t('Custom text'),
    t('[field_publication_date] == Field: Publication date
[title_field] == Content: Title
[body] == Content: Body
[view_node] == Content: Link
[field_image] == Content: Image'),
  );
  $export['highlight'] = $view;

  return $export;
}
