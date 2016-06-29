<?php

$view = new view();
$view->name = 'osha_job_overview_job_items';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'tmgmt_job_item';
$view->human_name = 'Osha Job Overview Job Items';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Osha Job Overview Job Items';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'mini';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'title_field-revision_id' => 'title_field-revision_id',
  'label' => 'label',
  'source_language' => 'source_language',
  'target_language' => 'target_language',
  'page_count' => 'page_count',
  'character_count' => 'character_count',
  'type' => 'type',
  'section' => 'section',
  'field_activity-revision_id' => 'field_activity-revision_id',
  'state' => 'state',
  'changed' => 'changed',
  'name' => 'name',
  'operations' => 'operations',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'title_field-revision_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'label' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'source_language' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'target_language' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'page_count' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'character_count' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'type' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'section' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_activity-revision_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'state' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'changed' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['label'] = 'No results';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'No job items found for your search.';
$handler->display->display_options['empty']['area']['format'] = 'full_html';
/* Relationship: Translation Management Job Item: Content */
$handler->display->display_options['relationships']['job_item_to_node_revision']['id'] = 'job_item_to_node_revision';
$handler->display->display_options['relationships']['job_item_to_node_revision']['table'] = 'tmgmt_job_item';
$handler->display->display_options['relationships']['job_item_to_node_revision']['field'] = 'job_item_to_node_revision';
/* Relationship: Content revision: User */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
$handler->display->display_options['relationships']['uid']['relationship'] = 'job_item_to_node_revision';
/* Relationship: Translation Management Job Item: Content */
$handler->display->display_options['relationships']['job_item_to_node']['id'] = 'job_item_to_node';
$handler->display->display_options['relationships']['job_item_to_node']['table'] = 'tmgmt_job_item';
$handler->display->display_options['relationships']['job_item_to_node']['field'] = 'job_item_to_node';
/* Field: Content (historical data): Title */
$handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
$handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
$handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
$handler->display->display_options['fields']['title_field-revision_id']['relationship'] = 'job_item_to_node_revision';
$handler->display->display_options['fields']['title_field-revision_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['title_field-revision_id']['type'] = 'title_linked';
$handler->display->display_options['fields']['title_field-revision_id']['settings'] = array(
  'title_style' => '_none',
  'title_link' => 'content',
  'title_class' => '',
);
/* Field: Translation Management Job Item: Label */
$handler->display->display_options['fields']['label']['id'] = 'label';
$handler->display->display_options['fields']['label']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['label']['field'] = 'label';
$handler->display->display_options['fields']['label']['empty'] = '[title_field-revision_id]';
/* Field: Translation Management Job Item: Source language */
$handler->display->display_options['fields']['source_language']['id'] = 'source_language';
$handler->display->display_options['fields']['source_language']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['source_language']['field'] = 'source_language';
/* Field: Translation Management Job Item: Job Item Target Language */
$handler->display->display_options['fields']['target_language']['id'] = 'target_language';
$handler->display->display_options['fields']['target_language']['table'] = 'views_entity_tmgmt_job_item';
$handler->display->display_options['fields']['target_language']['field'] = 'target_language';
$handler->display->display_options['fields']['target_language']['label'] = 'Target Language';
$handler->display->display_options['fields']['target_language']['link_to_entity'] = 0;
$handler->display->display_options['fields']['target_language']['format_name'] = 1;
/* Field: Translation Management Job Item: Page count */
$handler->display->display_options['fields']['page_count']['id'] = 'page_count';
$handler->display->display_options['fields']['page_count']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['page_count']['field'] = 'page_count';
$handler->display->display_options['fields']['page_count']['set_precision'] = TRUE;
$handler->display->display_options['fields']['page_count']['precision'] = '2';
$handler->display->display_options['fields']['page_count']['decimal'] = ',';
$handler->display->display_options['fields']['page_count']['separator'] = '';
/* Field: Translation Management Job Item: Character count */
$handler->display->display_options['fields']['character_count']['id'] = 'character_count';
$handler->display->display_options['fields']['character_count']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['character_count']['field'] = 'character_count';
/* Field: Translation Management Job Item: Type */
$handler->display->display_options['fields']['type_1']['id'] = 'type_1';
$handler->display->display_options['fields']['type_1']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['type_1']['field'] = 'type';
/* Field: Workbench Access: Section */
$handler->display->display_options['fields']['section']['id'] = 'section';
$handler->display->display_options['fields']['section']['table'] = 'workbench_access';
$handler->display->display_options['fields']['section']['field'] = 'section';
$handler->display->display_options['fields']['section']['relationship'] = 'job_item_to_node';
/* Field: Content (historical data): Activity */
$handler->display->display_options['fields']['field_activity-revision_id']['id'] = 'field_activity-revision_id';
$handler->display->display_options['fields']['field_activity-revision_id']['table'] = 'field_revision_field_activity';
$handler->display->display_options['fields']['field_activity-revision_id']['field'] = 'field_activity-revision_id';
$handler->display->display_options['fields']['field_activity-revision_id']['relationship'] = 'job_item_to_node_revision';
$handler->display->display_options['fields']['field_activity-revision_id']['type'] = 'taxonomy_term_reference_plain';
/* Field: Translation Management Job Item: State */
$handler->display->display_options['fields']['state']['id'] = 'state';
$handler->display->display_options['fields']['state']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['state']['field'] = 'state';
/* Field: Translation Management Job Item: Changed date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['date_format'] = 'osha_day_only';
$handler->display->display_options['fields']['changed']['second_date_format'] = 'year';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
/* Field: Translation Management Job Item: Operations */
$handler->display->display_options['fields']['operations']['id'] = 'operations';
$handler->display->display_options['fields']['operations']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['operations']['field'] = 'operations';
/* Contextual filter: Translation Management Job Item: Tjid */
$handler->display->display_options['arguments']['tjid']['id'] = 'tjid';
$handler->display->display_options['arguments']['tjid']['table'] = 'tmgmt_job_item';
$handler->display->display_options['arguments']['tjid']['field'] = 'tjid';
$handler->display->display_options['arguments']['tjid']['default_action'] = 'default';
$handler->display->display_options['arguments']['tjid']['default_argument_type'] = 'raw';
$handler->display->display_options['arguments']['tjid']['default_argument_options']['index'] = '3';
$handler->display->display_options['arguments']['tjid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['tjid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['tjid']['summary_options']['items_per_page'] = '25';
/* Contextual filter: Translation Management Job Item: State */
$handler->display->display_options['arguments']['state']['id'] = 'state';
$handler->display->display_options['arguments']['state']['table'] = 'tmgmt_job_item';
$handler->display->display_options['arguments']['state']['field'] = 'state';
$handler->display->display_options['arguments']['state']['exception']['value'] = 'any';
$handler->display->display_options['arguments']['state']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['state']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['state']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['state']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['state']['specify_validation'] = TRUE;
/* Contextual filter: Content: Activity (field_activity) */
$handler->display->display_options['arguments']['field_activity_tid']['id'] = 'field_activity_tid';
$handler->display->display_options['arguments']['field_activity_tid']['table'] = 'field_data_field_activity';
$handler->display->display_options['arguments']['field_activity_tid']['field'] = 'field_activity_tid';
$handler->display->display_options['arguments']['field_activity_tid']['relationship'] = 'job_item_to_node';
$handler->display->display_options['arguments']['field_activity_tid']['exception']['value'] = 'any';
$handler->display->display_options['arguments']['field_activity_tid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_activity_tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_activity_tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_activity_tid']['summary_options']['items_per_page'] = '25';
/* Contextual filter: Translation Management Job Item: Target language */
$handler->display->display_options['arguments']['target_language']['id'] = 'target_language';
$handler->display->display_options['arguments']['target_language']['table'] = 'tmgmt_job_item';
$handler->display->display_options['arguments']['target_language']['field'] = 'target_language';
$handler->display->display_options['arguments']['target_language']['exception']['value'] = 'any';
$handler->display->display_options['arguments']['target_language']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['target_language']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['target_language']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['target_language']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['target_language']['limit'] = '0';
$handler->display->display_options['filter_groups']['operator'] = 'OR';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'job_job_items');
$handler->display->display_options['path'] = 'admin/tmgmt/job-items';

/* Display: Job preview */
$handler = $view->new_display('page', 'Job preview', 'job_preview');
$handler->display->display_options['defaults']['group_by'] = FALSE;
$handler->display->display_options['field_language'] = 'en';
$handler->display->display_options['defaults']['query'] = FALSE;
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Translation Management Job Item: Content */
$handler->display->display_options['relationships']['job_item_to_node_revision']['id'] = 'job_item_to_node_revision';
$handler->display->display_options['relationships']['job_item_to_node_revision']['table'] = 'tmgmt_job_item';
$handler->display->display_options['relationships']['job_item_to_node_revision']['field'] = 'job_item_to_node_revision';
/* Relationship: Content revision: User */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
$handler->display->display_options['relationships']['uid']['relationship'] = 'job_item_to_node_revision';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Translation Management Job Item: Item_id */
$handler->display->display_options['fields']['item_id']['id'] = 'item_id';
$handler->display->display_options['fields']['item_id']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['item_id']['field'] = 'item_id';
$handler->display->display_options['fields']['item_id']['label'] = 'item_id';
$handler->display->display_options['fields']['item_id']['exclude'] = TRUE;
/* Field: Translation Management Job Item: Item type */
$handler->display->display_options['fields']['item_type']['id'] = 'item_type';
$handler->display->display_options['fields']['item_type']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['item_type']['field'] = 'item_type';
$handler->display->display_options['fields']['item_type']['exclude'] = TRUE;
/* Field: Content (historical data): Title */
$handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
$handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
$handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
$handler->display->display_options['fields']['title_field-revision_id']['relationship'] = 'job_item_to_node_revision';
$handler->display->display_options['fields']['title_field-revision_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['title_field-revision_id']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['title_field-revision_id']['type'] = 'text_plain';
/* Field: Translation Management Job Item: Label */
$handler->display->display_options['fields']['label']['id'] = 'label';
$handler->display->display_options['fields']['label']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['label']['field'] = 'label';
$handler->display->display_options['fields']['label']['label'] = '';
$handler->display->display_options['fields']['label']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['label']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['label']['empty'] = '[title_field-revision_id]';
/* Field: Content (historical data): Summary */
$handler->display->display_options['fields']['field_summary-revision_id']['id'] = 'field_summary-revision_id';
$handler->display->display_options['fields']['field_summary-revision_id']['table'] = 'field_revision_field_summary';
$handler->display->display_options['fields']['field_summary-revision_id']['field'] = 'field_summary-revision_id';
$handler->display->display_options['fields']['field_summary-revision_id']['relationship'] = 'job_item_to_node_revision';
$handler->display->display_options['fields']['field_summary-revision_id']['label'] = '';
$handler->display->display_options['fields']['field_summary-revision_id']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['field_summary-revision_id']['alter']['preserve_tags'] = '<a>';
$handler->display->display_options['fields']['field_summary-revision_id']['element_label_colon'] = FALSE;
/* Field: Content (historical data): Body */
$handler->display->display_options['fields']['body-revision_id']['id'] = 'body-revision_id';
$handler->display->display_options['fields']['body-revision_id']['table'] = 'field_revision_body';
$handler->display->display_options['fields']['body-revision_id']['field'] = 'body-revision_id';
$handler->display->display_options['fields']['body-revision_id']['relationship'] = 'job_item_to_node_revision';
$handler->display->display_options['fields']['body-revision_id']['label'] = '';
$handler->display->display_options['fields']['body-revision_id']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['body-revision_id']['alter']['preserve_tags'] = '<a>';
$handler->display->display_options['fields']['body-revision_id']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Translation Management Job Item: Tjid */
$handler->display->display_options['arguments']['tjid']['id'] = 'tjid';
$handler->display->display_options['arguments']['tjid']['table'] = 'tmgmt_job_item';
$handler->display->display_options['arguments']['tjid']['field'] = 'tjid';
$handler->display->display_options['arguments']['tjid']['default_action'] = 'default';
$handler->display->display_options['arguments']['tjid']['default_argument_type'] = 'raw';
$handler->display->display_options['arguments']['tjid']['default_argument_options']['index'] = '3';
$handler->display->display_options['arguments']['tjid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['tjid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['tjid']['summary_options']['items_per_page'] = '25';
/* Contextual filter: Translation Management Job Item: Target language */
$handler->display->display_options['arguments']['target_language']['id'] = 'target_language';
$handler->display->display_options['arguments']['target_language']['table'] = 'tmgmt_job_item';
$handler->display->display_options['arguments']['target_language']['field'] = 'target_language';
$handler->display->display_options['arguments']['target_language']['exception']['value'] = 'any';
$handler->display->display_options['arguments']['target_language']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['target_language']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['target_language']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['target_language']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['target_language']['limit'] = '0';
$handler->display->display_options['path'] = 'admin/tmgmt/job-items/preview';
$translatables['osha_job_overview_job_items'] = array(
  t('Master'),
  t('Osha Job Overview Job Items'),
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
  t('No results'),
  t('No job items found for your search.'),
  t('Content Revision'),
  t('revision user'),
  t('Content'),
  t('Title'),
  t('Label'),
  t('[title_field-revision_id]'),
  t('Source language'),
  t('Target Language'),
  t('Page count'),
  t(','),
  t('Character count'),
  t('Type'),
  t('Section'),
  t('Activity'),
  t('State'),
  t('Changed date'),
  t('Name'),
  t('Operations'),
  t('All'),
  t('Page'),
  t('Job preview'),
  t('item_id'),
  t('Item type'),
);
