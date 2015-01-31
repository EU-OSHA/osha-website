<?php
/**
 * @file
 * osha_fop_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_fop_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'fop_flags';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FOP Flags';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'FOP Flags';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '6';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Country (field_country) */
  $handler->display->display_options['relationships']['field_country_tid']['id'] = 'field_country_tid';
  $handler->display->display_options['relationships']['field_country_tid']['table'] = 'field_data_field_country';
  $handler->display->display_options['relationships']['field_country_tid']['field'] = 'field_country_tid';
  $handler->display->display_options['relationships']['field_country_tid']['required'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Taxonomy term: Flag */
  $handler->display->display_options['fields']['field_flag']['id'] = 'field_flag';
  $handler->display->display_options['fields']['field_flag']['table'] = 'field_data_field_flag';
  $handler->display->display_options['fields']['field_flag']['field'] = 'field_flag';
  $handler->display->display_options['fields']['field_flag']['relationship'] = 'field_country_tid';
  $handler->display->display_options['fields']['field_flag']['label'] = '';
  $handler->display->display_options['fields']['field_flag']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_flag']['alter']['text'] = '[field_flag]';
  $handler->display->display_options['fields']['field_flag']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_flag']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_flag']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_flag']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_flag']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_flag']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'div',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
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
    'fop_page' => 'fop_page',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Entity translation: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'fop_page' => 'fop_page',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 2;
  /* Filter criterion: Entity translation: Language */
  $handler->display->display_options['filters']['language_1']['id'] = 'language_1';
  $handler->display->display_options['filters']['language_1']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language_1']['field'] = 'language';
  $handler->display->display_options['filters']['language_1']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['language_1']['group'] = 2;
  /* Filter criterion: Entity translation: Language */
  $handler->display->display_options['filters']['language_2']['id'] = 'language_2';
  $handler->display->display_options['filters']['language_2']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language_2']['field'] = 'language';
  $handler->display->display_options['filters']['language_2']['operator'] = 'not in';
  $handler->display->display_options['filters']['language_2']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language_2']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'FOP Country Flags';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'FOP Country list';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'div',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  $handler->display->display_options['block_description'] = 'FOP Country List';
  $translatables['fop_flags'] = array(
    t('Master'),
    t('FOP Flags'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('term from field_country'),
    t('[field_flag]'),
    t('Block'),
    t('FOP Country Flags'),
    t('FOP Country list'),
    t('FOP Country List'),
  );
  $export['fop_flags'] = $view;

  $view = new view();
  $view->name = 'fop_links';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'FOP Links';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'FOP Links';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_fop_link_section',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Field collection item: Entity with the Link (field_fop_link) */
  $handler->display->display_options['relationships']['field_fop_link_node']['id'] = 'field_fop_link_node';
  $handler->display->display_options['relationships']['field_fop_link_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_fop_link_node']['field'] = 'field_fop_link_node';
  $handler->display->display_options['relationships']['field_fop_link_node']['required'] = TRUE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['relationship'] = 'field_fop_link_node';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Field: Field collection item: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  /* Field: Field collection item: Section */
  $handler->display->display_options['fields']['field_fop_link_section']['id'] = 'field_fop_link_section';
  $handler->display->display_options['fields']['field_fop_link_section']['table'] = 'field_data_field_fop_link_section';
  $handler->display->display_options['fields']['field_fop_link_section']['field'] = 'field_fop_link_section';
  $handler->display->display_options['fields']['field_fop_link_section']['label'] = '';
  $handler->display->display_options['fields']['field_fop_link_section']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fop_link_section']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fop_link_section']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_fop_link_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['fop_links'] = array(
    t('Master'),
    t('FOP Links'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field_fop_link'),
    t('Get the actual content from a content revision.'),
    t('All'),
    t('Block'),
  );
  $export['fop_links'] = $view;

  return $export;
}
