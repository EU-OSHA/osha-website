<?php

$view = new view();
$view->name = 'osha_translation_workbench';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'tmgmt_job_item';
$view->human_name = 'Osha Translation Workbench';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'On Translation';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view on translation content list';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
/* Field: Translation Management Job Item: Translation management job item ID */
$handler->display->display_options['fields']['tjiid']['id'] = 'tjiid';
$handler->display->display_options['fields']['tjiid']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['tjiid']['field'] = 'tjiid';
$handler->display->display_options['fields']['tjiid']['label'] = 'Job Item ID';
$handler->display->display_options['fields']['tjiid']['exclude'] = TRUE;
/* Field: Translation Management Job Item: Label */
$handler->display->display_options['fields']['label']['id'] = 'label';
$handler->display->display_options['fields']['label']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['label']['field'] = 'label';
/* Field: Translation Management Job Item: Item type */
$handler->display->display_options['fields']['item_type']['id'] = 'item_type';
$handler->display->display_options['fields']['item_type']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['item_type']['field'] = 'item_type';
/* Field: Translation Management Job Item: Source language */
$handler->display->display_options['fields']['source_language']['id'] = 'source_language';
$handler->display->display_options['fields']['source_language']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['source_language']['field'] = 'source_language';
/* Field: Translation Management Job Item: Target language */
$handler->display->display_options['fields']['target_language']['id'] = 'target_language';
$handler->display->display_options['fields']['target_language']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['target_language']['field'] = 'target_language';
/* Field: Translation Management Job Item: URL */
$handler->display->display_options['fields']['url']['id'] = 'url';
$handler->display->display_options['fields']['url']['table'] = 'views_entity_tmgmt_job_item';
$handler->display->display_options['fields']['url']['field'] = 'url';
$handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['url']['alter']['text'] = 'View';
$handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
$handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
$handler->display->display_options['fields']['url']['link_to_entity'] = 1;
/* Sort criterion: Translation Management Job Item: Changed */
$handler->display->display_options['sorts']['changed']['id'] = 'changed';
$handler->display->display_options['sorts']['changed']['table'] = 'tmgmt_job_item';
$handler->display->display_options['sorts']['changed']['field'] = 'changed';
$handler->display->display_options['sorts']['changed']['order'] = 'DESC';
$handler->display->display_options['sorts']['changed']['granularity'] = 'minute';
/* Filter criterion: Translation Management Job Item: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'tmgmt_job_item';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  2 => '2',
  6 => '6',
);

/* Display: On Translation */
$handler = $view->new_display('page', 'On Translation', 'page');
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Translation Management Job Item: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'tmgmt_job_item';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  1 => '1',
);
$handler->display->display_options['path'] = 'admin/workbench/on-translation';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'On Translation';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Content Validation */
$handler = $view->new_display('page', 'Content Validation', 'page_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Needs Content Validation';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view needs content validation list';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Translation Management Job Item: Translation Validators */
$handler->display->display_options['relationships']['osha_tmgmt_job_trans_validators']['id'] = 'osha_tmgmt_job_trans_validators';
$handler->display->display_options['relationships']['osha_tmgmt_job_trans_validators']['table'] = 'tmgmt_job_item';
$handler->display->display_options['relationships']['osha_tmgmt_job_trans_validators']['field'] = 'osha_tmgmt_job_trans_validators';
$handler->display->display_options['relationships']['osha_tmgmt_job_trans_validators']['required'] = TRUE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Translation Validators: User uid */
$handler->display->display_options['arguments']['user']['id'] = 'user';
$handler->display->display_options['arguments']['user']['table'] = 'osha_tmgmt_job_trans_validators';
$handler->display->display_options['arguments']['user']['field'] = 'user';
$handler->display->display_options['arguments']['user']['relationship'] = 'osha_tmgmt_job_trans_validators';
$handler->display->display_options['arguments']['user']['default_action'] = 'default';
$handler->display->display_options['arguments']['user']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Translation Management Job Item: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'tmgmt_job_item';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  5 => '5',
);
/* Filter criterion: Translation Validators: Next */
$handler->display->display_options['filters']['next']['id'] = 'next';
$handler->display->display_options['filters']['next']['table'] = 'osha_tmgmt_job_trans_validators';
$handler->display->display_options['filters']['next']['field'] = 'next';
$handler->display->display_options['filters']['next']['relationship'] = 'osha_tmgmt_job_trans_validators';
$handler->display->display_options['filters']['next']['value']['value'] = '1';
/* Filter criterion: Translation Validators: Deleted vote */
$handler->display->display_options['filters']['deleted']['id'] = 'deleted';
$handler->display->display_options['filters']['deleted']['table'] = 'osha_tmgmt_job_trans_validators';
$handler->display->display_options['filters']['deleted']['field'] = 'deleted';
$handler->display->display_options['filters']['deleted']['relationship'] = 'osha_tmgmt_job_trans_validators';
$handler->display->display_options['filters']['deleted']['value']['value'] = '0';
$handler->display->display_options['path'] = 'admin/workbench/needs-content-validation';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Needs Content Validation';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Needs Review TM */
$handler = $view->new_display('page', 'Needs Review TM', 'page_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Needs Review TM';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'create translation jobs';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Translation Management Job Item: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'tmgmt_job_item';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  2 => '2',
  6 => '6',
);
$handler->display->display_options['path'] = 'admin/workbench/needs-review-tm';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Needs Review TM';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Needs Review PM */
$handler = $view->new_display('page', 'Needs Review PM', 'page_3');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Translations Needs Review PM';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'accept job item translation';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Translation Management Job Item: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'tmgmt_job_item';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  7 => '7',
);
$handler->display->display_options['path'] = 'admin/workbench/translation-ready-to-publish';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Translations Needs Review PM';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Translation Overview */
$handler = $view->new_display('page', 'Translation Overview', 'page_4');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Translation Overview';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'create translation jobs';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Translation Management Job Item: Tjid */
$handler->display->display_options['relationships']['tjid']['id'] = 'tjid';
$handler->display->display_options['relationships']['tjid']['table'] = 'tmgmt_job_item';
$handler->display->display_options['relationships']['tjid']['field'] = 'tjid';
$handler->display->display_options['relationships']['tjid']['required'] = TRUE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Translation Management Job Item: Translation management job item ID */
$handler->display->display_options['fields']['tjiid']['id'] = 'tjiid';
$handler->display->display_options['fields']['tjiid']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['tjiid']['field'] = 'tjiid';
$handler->display->display_options['fields']['tjiid']['label'] = 'Job Item ID';
$handler->display->display_options['fields']['tjiid']['exclude'] = TRUE;
/* Field: Translation Management Job Item: Label */
$handler->display->display_options['fields']['label']['id'] = 'label';
$handler->display->display_options['fields']['label']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['label']['field'] = 'label';
/* Field: Translation Management Job: Label */
$handler->display->display_options['fields']['label_1']['id'] = 'label_1';
$handler->display->display_options['fields']['label_1']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['label_1']['field'] = 'label';
$handler->display->display_options['fields']['label_1']['relationship'] = 'tjid';
$handler->display->display_options['fields']['label_1']['label'] = 'Job';
/* Field: Translation Management Job Item: Item type */
$handler->display->display_options['fields']['item_type']['id'] = 'item_type';
$handler->display->display_options['fields']['item_type']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['item_type']['field'] = 'item_type';
/* Field: Translation Management Job Item: Source language */
$handler->display->display_options['fields']['source_language']['id'] = 'source_language';
$handler->display->display_options['fields']['source_language']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['source_language']['field'] = 'source_language';
/* Field: Translation Management Job Item: Target language */
$handler->display->display_options['fields']['target_language']['id'] = 'target_language';
$handler->display->display_options['fields']['target_language']['table'] = 'tmgmt_job_item';
$handler->display->display_options['fields']['target_language']['field'] = 'target_language';
/* Field: Translation Management Job Item: URL */
$handler->display->display_options['fields']['url']['id'] = 'url';
$handler->display->display_options['fields']['url']['table'] = 'views_entity_tmgmt_job_item';
$handler->display->display_options['fields']['url']['field'] = 'url';
$handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['url']['alter']['text'] = 'View';
$handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
$handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
$handler->display->display_options['fields']['url']['link_to_entity'] = 1;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Translation Management Job: State */
$handler->display->display_options['filters']['state_1']['id'] = 'state_1';
$handler->display->display_options['filters']['state_1']['table'] = 'tmgmt_job';
$handler->display->display_options['filters']['state_1']['field'] = 'state';
$handler->display->display_options['filters']['state_1']['relationship'] = 'tjid';
$handler->display->display_options['filters']['state_1']['value'] = array(
  0 => '0',
  1 => '1',
);
$handler->display->display_options['path'] = 'admin/workbench/translation-overview';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Translation Overview';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['osha_translation_workbench'] = array(
  t('Master'),
  t('On Translation'),
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
  t('Job Item ID'),
  t('.'),
  t(','),
  t('Label'),
  t('Item type'),
  t('Source language'),
  t('Target language'),
  t('URL'),
  t('View'),
  t('Content Validation'),
  t('Needs Content Validation'),
  t('Translation Validators'),
  t('All'),
  t('Needs Review TM'),
  t('Needs Review PM'),
  t('Translations Needs Review PM'),
  t('Translation Overview'),
  t('Translation Management Job'),
  t('Job'),
);
