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
  $handler->display->display_options['title'] = 'Reserve lists';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  $handler->display->display_options['relationships']['vid']['required'] = TRUE;
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
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'vacancies-teaser-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Show details';
  /* Sort criterion: Field: Publication date (field_publication_date) */
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
  /* Filter criterion: Field: Publication date (field_publication_date) */
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

  /* Display: Open job vacancies TAB */
  $handler = $view->new_display('page', 'Open job vacancies TAB', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Open job vacancies';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No Results Message';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Currently, there are no vacancies available in this section.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
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
  $handler->display->display_options['filters']['published']['relationship'] = 'vid';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_publication_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Deadline (field_job_vacancies_deadline) */
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['id'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['table'] = 'field_data_field_job_vacancies_deadline';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['field'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['default_date'] = 'now';
  /* Filter criterion: Content: Reserve List (field_reserve_list) */
  $handler->display->display_options['filters']['field_reserve_list_value']['id'] = 'field_reserve_list_value';
  $handler->display->display_options['filters']['field_reserve_list_value']['table'] = 'field_data_field_reserve_list';
  $handler->display->display_options['filters']['field_reserve_list_value']['field'] = 'field_reserve_list_value';
  $handler->display->display_options['filters']['field_reserve_list_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_reserve_list_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'open_job_vacancies';

  /* Display: Closed job vacancies PAGE */
  $handler = $view->new_display('page', 'Closed job vacancies PAGE', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Completed vacancies';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<a href="<?php print url(\'about-eu-osha/careers\'); ?>">Careers</a>';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No Results Messege';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Currently, there are no vacancies available in this section.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  $handler->display->display_options['relationships']['vid']['required'] = TRUE;
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
  $handler->display->display_options['filters']['published']['relationship'] = 'vid';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  $handler->display->display_options['filters']['published']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['published']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['published']['expose']['operator'] = 'published_op';
  $handler->display->display_options['filters']['published']['expose']['identifier'] = 'published';
  $handler->display->display_options['filters']['published']['expose']['required'] = TRUE;
  /* Filter criterion: Content: Expiration date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_expiration_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_expiration_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'about-eu-osha/careers/jobs_archive';

  /* Display: Evaluation underway job vacancies TAB */
  $handler = $view->new_display('page', 'Evaluation underway job vacancies TAB', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Open job vacancies';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No Results Message';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Currently, there are no vacancies available in this section.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
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
  $handler->display->display_options['filters']['published']['relationship'] = 'vid';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Expiration date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_expiration_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_expiration_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Expiration date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value_1']['id'] = 'field_expiration_date_value_1';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['group'] = 2;
  $handler->display->display_options['filters']['field_expiration_date_value_1']['granularity'] = 'minute';
  /* Filter criterion: Content: Deadline (field_job_vacancies_deadline) */
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['id'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['table'] = 'field_data_field_job_vacancies_deadline';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['field'] = 'field_job_vacancies_deadline_value';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['group'] = 1;
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_job_vacancies_deadline_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'open_job_vacancies';

  /* Display: Closed job vacancies TAB */
  $handler = $view->new_display('page', 'Closed job vacancies TAB', 'page_4');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="inside-eu-osha/careers">Careers</a>';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No Results Messege';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Currently, there are no vacancies available in this section.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  $handler->display->display_options['relationships']['vid']['required'] = TRUE;
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
  $handler->display->display_options['filters']['published']['relationship'] = 'vid';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  $handler->display->display_options['filters']['published']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['published']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['published']['expose']['operator'] = 'published_op';
  $handler->display->display_options['filters']['published']['expose']['identifier'] = 'published';
  $handler->display->display_options['filters']['published']['expose']['required'] = TRUE;
  /* Filter criterion: Content: Expiration date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_expiration_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_expiration_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'closed-jobs-preview';

  /* Display: Reserve list TAB */
  $handler = $view->new_display('page', 'Reserve list TAB', 'page_5');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p id="tmgmt-1">Reserve lists are composed of the candidates who came for an interview at the time of the recruitment procedure for the posts listed and who obtained the best overall marks. Candidates in the reserve list may be offered contracts at a later date without subsequent selection procedure.</p><p id="tmgmt-2">For some Contract Agent positions, EU-OSHA may use the EPSO database.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html_minimal';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Currently, there are no vacancies available in this section.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html_minimal';
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
  /* Filter criterion: Field: Publication date (field_publication_date) */
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
  /* Filter criterion: Content: Reserve List (field_reserve_list) */
  $handler->display->display_options['filters']['field_reserve_list_value']['id'] = 'field_reserve_list_value';
  $handler->display->display_options['filters']['field_reserve_list_value']['table'] = 'field_data_field_reserve_list';
  $handler->display->display_options['filters']['field_reserve_list_value']['field'] = 'field_reserve_list_value';
  $handler->display->display_options['filters']['field_reserve_list_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'open_job_reserve_list';
  $translatables['vacancies'] = array(
    t('Master'),
    t('Reserve lists'),
    t('View all'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Get the actual content from a content revision.'),
    t('Show details'),
    t('Open job vacancies TAB'),
    t('Open job vacancies'),
    t('more'),
    t('No Results Message'),
    t('Currently, there are no vacancies available in this section.'),
    t('Closed job vacancies PAGE'),
    t('Completed vacancies'),
    t('No Results Messege'),
    t('Published'),
    t('Evaluation underway job vacancies TAB'),
    t('Closed job vacancies TAB'),
    t('<a href="inside-eu-osha/careers">Careers</a>'),
    t('Reserve list TAB'),
    t('<p id="tmgmt-1">Reserve lists are composed of the candidates who came for an interview at the time of the recruitment procedure for the posts listed and who obtained the best overall marks. Candidates in the reserve list may be offered contracts at a later date without subsequent selection procedure.</p><p id="tmgmt-2">For some Contract Agent positions, EU-OSHA may use the EPSO database.</p>'),
  );
  $export['vacancies'] = $view;

  return $export;
}
