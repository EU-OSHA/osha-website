<?php
/**
 * @file
 * osha_flickr.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_flickr_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'flickr_albums';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Flickr albums';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photo gallery';
  $handler->display->display_options['css_class'] = 'photo-gallery container';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'gallery-row col-md-4 col-sm-6 col-xs-12';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Cover photo */
  $handler->display->display_options['fields']['field_cover_flickr']['id'] = 'field_cover_flickr';
  $handler->display->display_options['fields']['field_cover_flickr']['table'] = 'field_data_field_cover_flickr';
  $handler->display->display_options['fields']['field_cover_flickr']['field'] = 'field_cover_flickr';
  $handler->display->display_options['fields']['field_cover_flickr']['label'] = '';
  $handler->display->display_options['fields']['field_cover_flickr']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cover_flickr']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cover_flickr']['click_sort_column'] = 'id';
  $handler->display->display_options['fields']['field_cover_flickr']['type'] = 'album_detail';
  /* Field: Content: Flickr */
  $handler->display->display_options['fields']['field_flickr']['id'] = 'field_flickr';
  $handler->display->display_options['fields']['field_flickr']['table'] = 'field_data_field_flickr';
  $handler->display->display_options['fields']['field_flickr']['field'] = 'field_flickr';
  $handler->display->display_options['fields']['field_flickr']['label'] = '';
  $handler->display->display_options['fields']['field_flickr']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_flickr']['click_sort_column'] = 'id';
  $handler->display->display_options['fields']['field_flickr']['type'] = 'album_list';
  $handler->display->display_options['fields']['field_flickr']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h1';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'osha_date_theme' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="gallery_list_detail_container">[field_publication_date][title]</span>';
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['preserve_tags'] = '<span> <a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'flickr_gallery' => 'flickr_gallery',
  );
  /* Filter criterion: Content: Flickr (field_flickr:type) */
  $handler->display->display_options['filters']['field_flickr_type']['id'] = 'field_flickr_type';
  $handler->display->display_options['filters']['field_flickr_type']['table'] = 'field_data_field_flickr';
  $handler->display->display_options['filters']['field_flickr_type']['field'] = 'field_flickr_type';
  $handler->display->display_options['filters']['field_flickr_type']['value'] = 'id';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'photo-gallery';
  $translatables['flickr_albums'] = array(
    t('Master'),
    t('Photo gallery'),
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
    t('<span class="gallery_list_detail_container">[field_publication_date][title]</span>'),
    t('Page'),
  );
  $export['flickr_albums'] = $view;

  return $export;
}
