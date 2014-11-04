<?php
/**
 * @file
 * osha_job_vacancies.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_job_vacancies_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'vacancies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Vacancies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Closed job vacancies';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Publication Date */
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
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
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
    'job_vacancies' => 'job_vacancies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Deadline (field_job_vacancies_deadline) */
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['id'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['table'] = 'field_data_field_job_vacancies_deadline';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['field'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['group'] = 1;
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['year_range'] = '-10:+10';

  /* Display: Open job vacancies */
  $handler = $view->new_display('page', 'Open job vacancies', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Open job vacancies';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
    4 => 'OR',
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
    'job_vacancies' => 'job_vacancies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Deadline (field_job_vacancies_deadline) */
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['id'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['table'] = 'field_data_field_job_vacancies_deadline';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['field'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['group'] = 3;
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['year_range'] = '-10:+10';
  /* Filter criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value_1']['id'] = 'field_publication_date_value_1';
  $handler->display->display_options['filters']['field_publication_date_value_1']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value_1']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_publication_date_value_1']['group'] = 2;
  /* Filter criterion: Content: Deadline (field_job_vacancies_deadline) */
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value_1']['id'] = 'field_job_vacancies_deadline_value_1';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value_1']['table'] = 'field_data_field_job_vacancies_deadline';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value_1']['field'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value_1']['group'] = 3;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_expiration_date_value']['group'] = 4;
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value_1']['id'] = 'field_expiration_date_value_1';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['group'] = 4;
  /* Filter criterion: Content: Shortlisted (field_job_vacancies_shortlisted) */
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['id'] = 'field_job_vacancies_shortlisted_value';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['table'] = 'field_data_field_job_vacancies_shortlisted';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['field'] = 'field_job_vacancies_shortlisted_value';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'open_job_vacancies';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Open job vacancies';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Ongoing job vacancies */
  $handler = $view->new_display('page', 'Ongoing job vacancies', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ongoing job vacancies';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
    4 => 'OR',
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
    'job_vacancies' => 'job_vacancies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Deadline (field_job_vacancies_deadline) */
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['id'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['table'] = 'field_data_field_job_vacancies_deadline';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['field'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['group'] = 3;
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['year_range'] = '-10:+10';
  /* Filter criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value_1']['id'] = 'field_publication_date_value_1';
  $handler->display->display_options['filters']['field_publication_date_value_1']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value_1']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_publication_date_value_1']['group'] = 2;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_expiration_date_value']['group'] = 4;
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value_1']['id'] = 'field_expiration_date_value_1';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['group'] = 4;
  /* Filter criterion: Content: Shortlisted (field_job_vacancies_shortlisted) */
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['id'] = 'field_job_vacancies_shortlisted_value';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['table'] = 'field_data_field_job_vacancies_shortlisted';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['field'] = 'field_job_vacancies_shortlisted_value';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'ongoing_job_vacancies';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Ongoing job vacancies';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Shortlisted job vacancies */
  $handler = $view->new_display('page', 'Shortlisted job vacancies', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Shortlisted job vacancies';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
    4 => 'OR',
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
    'job_vacancies' => 'job_vacancies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value_1']['id'] = 'field_publication_date_value_1';
  $handler->display->display_options['filters']['field_publication_date_value_1']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value_1']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_publication_date_value_1']['group'] = 2;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_expiration_date_value']['group'] = 4;
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value_1']['id'] = 'field_expiration_date_value_1';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['group'] = 4;
  /* Filter criterion: Content: Shortlisted (field_job_vacancies_shortlisted) */
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['id'] = 'field_job_vacancies_shortlisted_value';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['table'] = 'field_data_field_job_vacancies_shortlisted';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['field'] = 'field_job_vacancies_shortlisted_value';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'shortlisted_job_vacancies';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Shortlisted job vacancies';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Closed job vacancies */
  $handler = $view->new_display('page', 'Closed job vacancies', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="/articles/careers">Careers</a>';
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
    'job_vacancies' => 'job_vacancies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Deadline (field_job_vacancies_deadline) */
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['id'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['table'] = 'field_data_field_job_vacancies_deadline';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['field'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['group'] = 1;
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['year_range'] = '-10:+10';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Shortlisted (field_job_vacancies_shortlisted) */
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['id'] = 'field_job_vacancies_shortlisted_value';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['table'] = 'field_data_field_job_vacancies_shortlisted';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['field'] = 'field_job_vacancies_shortlisted_value';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'jobs_archive';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Closed job vacancies';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Open Vacancies block */
  $handler = $view->new_display('block', 'Open Vacancies block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Open job vacancies';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
    4 => 'OR',
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
    'job_vacancies' => 'job_vacancies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value_1']['id'] = 'field_publication_date_value_1';
  $handler->display->display_options['filters']['field_publication_date_value_1']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value_1']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_publication_date_value_1']['group'] = 2;
  /* Filter criterion: Content: Deadline (field_job_vacancies_deadline) */
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['id'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['table'] = 'field_data_field_job_vacancies_deadline';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['field'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['group'] = 3;
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['year_range'] = '-10:+10';
  /* Filter criterion: Content: Deadline (field_job_vacancies_deadline) */
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value_1']['id'] = 'field_job_vacancies_deadline_value_1';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value_1']['table'] = 'field_data_field_job_vacancies_deadline';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value_1']['field'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value_1']['group'] = 3;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_expiration_date_value']['group'] = 4;
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value_1']['id'] = 'field_expiration_date_value_1';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['group'] = 4;

  /* Display: Ongoing Vacancies block */
  $handler = $view->new_display('block', 'Ongoing Vacancies block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ongoing job vacancies';
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
    'job_vacancies' => 'job_vacancies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Deadline (field_job_vacancies_deadline) */
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['id'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['table'] = 'field_data_field_job_vacancies_deadline';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['field'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['group'] = 1;
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['year_range'] = '-10:+10';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_expiration_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value_1']['id'] = 'field_expiration_date_value_1';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['group'] = 2;
  /* Filter criterion: Content: Shortlisted (field_job_vacancies_shortlisted) */
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['id'] = 'field_job_vacancies_shortlisted_value';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['table'] = 'field_data_field_job_vacancies_shortlisted';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['field'] = 'field_job_vacancies_shortlisted_value';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['value'] = array(
    0 => '0',
  );

  /* Display: Shortlisted Vacancies block */
  $handler = $view->new_display('block', 'Shortlisted Vacancies block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Shortlisted job vacancies';
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
    'job_vacancies' => 'job_vacancies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Shortlisted (field_job_vacancies_shortlisted) */
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['id'] = 'field_job_vacancies_shortlisted_value';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['table'] = 'field_data_field_job_vacancies_shortlisted';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['field'] = 'field_job_vacancies_shortlisted_value';
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_job_vacancies_shortlisted_value']['group'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_expiration_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value_1']['id'] = 'field_expiration_date_value_1';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['group'] = 2;
  $translatables['vacancies'] = array(
    t('Master'),
    t('Closed job vacancies'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Open job vacancies'),
    t('Ongoing job vacancies'),
    t('Shortlisted job vacancies'),
    t('<a href="/articles/careers">Careers</a>'),
    t('Open Vacancies block'),
    t('Ongoing Vacancies block'),
    t('Shortlisted Vacancies block'),
  );
  $export['vacancies'] = $view;

  return $export;
}
