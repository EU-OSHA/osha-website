<?php

$view = new view();
$view->name = 'osha_needs_translation_workbench';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'tmgmt_job';
$view->human_name = 'Osha Needs Translation Workbench';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Osha Needs Translation Workbench';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view untranslated jobs';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'label' => 'label',
  'priority' => 'priority',
  'state' => 'state',
  'changed' => 'changed',
  'url' => 'url',
);
$handler->display->display_options['style_options']['default'] = 'changed';
$handler->display->display_options['style_options']['info'] = array(
  'label' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'priority' => array(
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
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'url' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Relationship: Translation Management Job: Job items */
$handler->display->display_options['relationships']['job_item']['id'] = 'job_item';
$handler->display->display_options['relationships']['job_item']['table'] = 'tmgmt_job';
$handler->display->display_options['relationships']['job_item']['field'] = 'job_item';
$handler->display->display_options['relationships']['job_item']['required'] = TRUE;
/* Field: Translation Management Job: Label */
$handler->display->display_options['fields']['label']['id'] = 'label';
$handler->display->display_options['fields']['label']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['label']['field'] = 'label';
/* Field: Translation Management Job: Priority */
$handler->display->display_options['fields']['priority']['id'] = 'priority';
$handler->display->display_options['fields']['priority']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['priority']['field'] = 'priority';
/* Field: Translation Management Job: State */
$handler->display->display_options['fields']['state']['id'] = 'state';
$handler->display->display_options['fields']['state']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['state']['field'] = 'state';
/* Field: Translation Management Job: Changed */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
/* Field: Translation Management Job: URL */
$handler->display->display_options['fields']['url']['id'] = 'url';
$handler->display->display_options['fields']['url']['table'] = 'views_entity_tmgmt_job';
$handler->display->display_options['fields']['url']['field'] = 'url';
$handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['url']['alter']['text'] = 'View';
$handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
$handler->display->display_options['fields']['url']['link_to_entity'] = 1;
/* Sort criterion: Translation Management Job: Changed */
$handler->display->display_options['sorts']['changed']['id'] = 'changed';
$handler->display->display_options['sorts']['changed']['table'] = 'tmgmt_job';
$handler->display->display_options['sorts']['changed']['field'] = 'changed';
$handler->display->display_options['sorts']['changed']['order'] = 'DESC';
$handler->display->display_options['sorts']['changed']['granularity'] = 'minute';
/* Filter criterion: Translation Management Job Item: Count_pending */
$handler->display->display_options['filters']['count_pending']['id'] = 'count_pending';
$handler->display->display_options['filters']['count_pending']['table'] = 'tmgmt_job_item';
$handler->display->display_options['filters']['count_pending']['field'] = 'count_pending';
$handler->display->display_options['filters']['count_pending']['relationship'] = 'job_item';
$handler->display->display_options['filters']['count_pending']['operator'] = '>';
$handler->display->display_options['filters']['count_pending']['value']['value'] = '0';
/* Filter criterion: Translation Management Job Item: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'tmgmt_job_item';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['relationship'] = 'job_item';
$handler->display->display_options['filters']['state']['value'] = array(
  1 => '1',
  4 => '4',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/workbench/needs-translation-job';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Needs Translation';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['osha_needs_translation_workbench'] = array(
  t('Master'),
  t('Osha Needs Translation Workbench'),
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
  t('Job items'),
  t('Label'),
  t('Priority'),
  t('State'),
  t('Changed'),
  t('URL'),
  t('View'),
  t('Page'),
);
