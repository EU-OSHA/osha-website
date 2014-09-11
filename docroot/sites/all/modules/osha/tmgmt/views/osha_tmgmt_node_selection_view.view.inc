<?php

$view = new view();
$view->name = 'tmgmt_node_selection_view';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'OSHA TMGMT node selection';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'OSHA content selection';
$handler->display->display_options['css_class'] = 'tmgmt_node_selection_view';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'create translation jobs';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
$handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 100, 200';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'views_bulk_operations' => 'views_bulk_operations',
  'title' => 'title',
  'type' => 'type',
  'field_workflow_status' => 'field_workflow_status',
  'name' => 'name',
  'changed' => 'changed',
  'edit_node' => 'edit_node',
);
$handler->display->display_options['style_options']['default'] = 'changed';
$handler->display->display_options['style_options']['info'] = array(
  'views_bulk_operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 0,
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
  'field_workflow_status' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
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
  'changed' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'edit_node' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'There are no results. Please broaden your filters above.';
$handler->display->display_options['empty']['area']['format'] = 'full_html';
/* Relationship: Content: Author */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Field: Bulk operations: Content */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
  'rules_component::tmgmt_node_ui_tmgmt_nodes_add_items_to_cart' => array(
    'selected' => 1,
    'skip_confirmation' => 1,
    'override_label' => 0,
    'label' => '',
  ),
  'action::nodequeue_add_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_assign_owner_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::scs_views_create_newsletter_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_delete_item' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_delete_revision' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_script_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_make_sticky_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_make_unsticky_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_modify_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'show_all_tokens' => 1,
      'display_values' => array(
        '_all_' => '_all_',
      ),
    ),
  ),
  'action::views_bulk_operations_argument_selector_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'url' => '',
    ),
  ),
  'action::node_promote_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_publish_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_unpromote_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::nodequeue_remove_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_save_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::system_send_email_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_unpublish_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_unpublish_by_keyword_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::pathauto_node_update_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['label'] = 'Type of content';
/* Field: Content: Workflow status */
$handler->display->display_options['fields']['field_workflow_status']['id'] = 'field_workflow_status';
$handler->display->display_options['fields']['field_workflow_status']['table'] = 'field_data_field_workflow_status';
$handler->display->display_options['fields']['field_workflow_status']['field'] = 'field_workflow_status';
$handler->display->display_options['fields']['field_workflow_status']['label'] = 'Status';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Author';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['label'] = 'Updated';
$handler->display->display_options['fields']['changed']['date_format'] = 'short';
$handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
/* Field: Content: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
/* Field: Content: Bookshop ID */
$handler->display->display_options['fields']['field_publication_bookshop_id']['id'] = 'field_publication_bookshop_id';
$handler->display->display_options['fields']['field_publication_bookshop_id']['table'] = 'field_data_field_publication_bookshop_id';
$handler->display->display_options['fields']['field_publication_bookshop_id']['field'] = 'field_publication_bookshop_id';
$handler->display->display_options['fields']['field_publication_bookshop_id']['label'] = '';
$handler->display->display_options['fields']['field_publication_bookshop_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_publication_bookshop_id']['element_label_colon'] = FALSE;
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
$handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
$handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
$handler->display->display_options['fields']['field_summary']['label'] = '';
$handler->display->display_options['fields']['field_summary']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_summary']['element_label_colon'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['sorts']['created']['exposed'] = TRUE;
$handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
/* Sort criterion: Content: Updated date */
$handler->display->display_options['sorts']['changed']['id'] = 'changed';
$handler->display->display_options['sorts']['changed']['table'] = 'node';
$handler->display->display_options['sorts']['changed']['field'] = 'changed';
$handler->display->display_options['sorts']['changed']['order'] = 'DESC';
$handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
$handler->display->display_options['sorts']['changed']['expose']['label'] = 'Updated date';
/* Sort criterion: User: Name */
$handler->display->display_options['sorts']['name']['id'] = 'name';
$handler->display->display_options['sorts']['name']['table'] = 'users';
$handler->display->display_options['sorts']['name']['field'] = 'name';
$handler->display->display_options['sorts']['name']['relationship'] = 'uid';
$handler->display->display_options['sorts']['name']['exposed'] = TRUE;
$handler->display->display_options['sorts']['name']['expose']['label'] = 'Author name';
/* Sort criterion: Content: Type */
$handler->display->display_options['sorts']['type']['id'] = 'type';
$handler->display->display_options['sorts']['type']['table'] = 'node';
$handler->display->display_options['sorts']['type']['field'] = 'type';
$handler->display->display_options['sorts']['type']['exposed'] = TRUE;
$handler->display->display_options['sorts']['type']['expose']['label'] = 'Type';
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'article' => 'article',
  'page' => 'page',
  'blog' => 'blog',
  'calls' => 'calls',
  'highlight' => 'highlight',
  'job_vacancies' => 'job_vacancies',
  'news' => 'news',
  'press_release' => 'press_release',
  'publication' => 'publication',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type of content';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
/* Filter criterion: Global: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['operator'] = 'contains';
$handler->display->display_options['filters']['combine']['group'] = 1;
$handler->display->display_options['filters']['combine']['exposed'] = TRUE;
$handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['label'] = 'Search text';
$handler->display->display_options['filters']['combine']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
$handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
$handler->display->display_options['filters']['combine']['group_info']['label'] = 'Combine fields filter';
$handler->display->display_options['filters']['combine']['group_info']['identifier'] = 'combine';
$handler->display->display_options['filters']['combine']['group_info']['remember'] = FALSE;
$handler->display->display_options['filters']['combine']['group_info']['group_items'] = array(
  1 => array(),
  2 => array(),
  3 => array(),
);
$handler->display->display_options['filters']['combine']['fields'] = array(
  'title' => 'title',
  'body' => 'body',
  'field_publication_bookshop_id' => 'field_publication_bookshop_id',
  'field_summary' => 'field_summary',
);
/* Filter criterion: Content: Nid */
$handler->display->display_options['filters']['nid']['id'] = 'nid';
$handler->display->display_options['filters']['nid']['table'] = 'node';
$handler->display->display_options['filters']['nid']['field'] = 'nid';
$handler->display->display_options['filters']['nid']['group'] = 1;
$handler->display->display_options['filters']['nid']['exposed'] = TRUE;
$handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
$handler->display->display_options['filters']['nid']['expose']['label'] = 'Node ID';
$handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
$handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
$handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
/* Filter criterion: Content: Activity (field_activity) */
$handler->display->display_options['filters']['field_activity_tid']['id'] = 'field_activity_tid';
$handler->display->display_options['filters']['field_activity_tid']['table'] = 'field_data_field_activity';
$handler->display->display_options['filters']['field_activity_tid']['field'] = 'field_activity_tid';
$handler->display->display_options['filters']['field_activity_tid']['group'] = 1;
$handler->display->display_options['filters']['field_activity_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_activity_tid']['expose']['operator_id'] = 'field_activity_tid_op';
$handler->display->display_options['filters']['field_activity_tid']['expose']['label'] = 'Activity';
$handler->display->display_options['filters']['field_activity_tid']['expose']['operator'] = 'field_activity_tid_op';
$handler->display->display_options['filters']['field_activity_tid']['expose']['identifier'] = 'field_activity_tid';
$handler->display->display_options['filters']['field_activity_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_activity_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
$handler->display->display_options['filters']['field_activity_tid']['group_info']['label'] = 'Activity (field_activity)';
$handler->display->display_options['filters']['field_activity_tid']['group_info']['identifier'] = 'field_activity_tid';
$handler->display->display_options['filters']['field_activity_tid']['group_info']['remember'] = FALSE;
$handler->display->display_options['filters']['field_activity_tid']['group_info']['group_items'] = array(
  1 => array(),
  2 => array(),
  3 => array(),
);
$handler->display->display_options['filters']['field_activity_tid']['vocabulary'] = 'activity';
$handler->display->display_options['filters']['field_activity_tid']['hierarchy'] = 1;
/* Filter criterion: Content: Section (field_section) */
$handler->display->display_options['filters']['field_section_tid']['id'] = 'field_section_tid';
$handler->display->display_options['filters']['field_section_tid']['table'] = 'field_data_field_section';
$handler->display->display_options['filters']['field_section_tid']['field'] = 'field_section_tid';
$handler->display->display_options['filters']['field_section_tid']['value'] = '';
$handler->display->display_options['filters']['field_section_tid']['group'] = 1;
$handler->display->display_options['filters']['field_section_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_section_tid']['expose']['operator_id'] = 'field_section_tid_op';
$handler->display->display_options['filters']['field_section_tid']['expose']['label'] = 'Section';
$handler->display->display_options['filters']['field_section_tid']['expose']['operator'] = 'field_section_tid_op';
$handler->display->display_options['filters']['field_section_tid']['expose']['identifier'] = 'field_section_tid';
$handler->display->display_options['filters']['field_section_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_section_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
$handler->display->display_options['filters']['field_section_tid']['vocabulary'] = 'section';
/* Filter criterion: Field: Nace (field_nace_codes) */
$handler->display->display_options['filters']['field_nace_codes_tid']['id'] = 'field_nace_codes_tid';
$handler->display->display_options['filters']['field_nace_codes_tid']['table'] = 'field_data_field_nace_codes';
$handler->display->display_options['filters']['field_nace_codes_tid']['field'] = 'field_nace_codes_tid';
$handler->display->display_options['filters']['field_nace_codes_tid']['value'] = '';
$handler->display->display_options['filters']['field_nace_codes_tid']['group'] = 1;
$handler->display->display_options['filters']['field_nace_codes_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_nace_codes_tid']['expose']['operator_id'] = 'field_nace_codes_tid_op';
$handler->display->display_options['filters']['field_nace_codes_tid']['expose']['label'] = 'Nace Codes';
$handler->display->display_options['filters']['field_nace_codes_tid']['expose']['operator'] = 'field_nace_codes_tid_op';
$handler->display->display_options['filters']['field_nace_codes_tid']['expose']['identifier'] = 'field_nace_codes_tid';
$handler->display->display_options['filters']['field_nace_codes_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_nace_codes_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
$handler->display->display_options['filters']['field_nace_codes_tid']['vocabulary'] = 'nace_codes';
/* Filter criterion: Field: Thesaurus (field_thesaurus) */
$handler->display->display_options['filters']['field_thesaurus_tid']['id'] = 'field_thesaurus_tid';
$handler->display->display_options['filters']['field_thesaurus_tid']['table'] = 'field_data_field_thesaurus';
$handler->display->display_options['filters']['field_thesaurus_tid']['field'] = 'field_thesaurus_tid';
$handler->display->display_options['filters']['field_thesaurus_tid']['value'] = '';
$handler->display->display_options['filters']['field_thesaurus_tid']['group'] = 1;
$handler->display->display_options['filters']['field_thesaurus_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_thesaurus_tid']['expose']['operator_id'] = 'field_thesaurus_tid_op';
$handler->display->display_options['filters']['field_thesaurus_tid']['expose']['label'] = 'Thesaurus';
$handler->display->display_options['filters']['field_thesaurus_tid']['expose']['operator'] = 'field_thesaurus_tid_op';
$handler->display->display_options['filters']['field_thesaurus_tid']['expose']['identifier'] = 'field_thesaurus_tid';
$handler->display->display_options['filters']['field_thesaurus_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_thesaurus_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
$handler->display->display_options['filters']['field_thesaurus_tid']['vocabulary'] = 'thesaurus';
/* Filter criterion: Content: Workflow status (field_workflow_status) */
$handler->display->display_options['filters']['field_workflow_status_tid']['id'] = 'field_workflow_status_tid';
$handler->display->display_options['filters']['field_workflow_status_tid']['table'] = 'field_data_field_workflow_status';
$handler->display->display_options['filters']['field_workflow_status_tid']['field'] = 'field_workflow_status_tid';
$handler->display->display_options['filters']['field_workflow_status_tid']['value'] = '';
$handler->display->display_options['filters']['field_workflow_status_tid']['group'] = 1;
$handler->display->display_options['filters']['field_workflow_status_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_workflow_status_tid']['expose']['operator_id'] = 'field_workflow_status_tid_op';
$handler->display->display_options['filters']['field_workflow_status_tid']['expose']['label'] = 'Workflow status';
$handler->display->display_options['filters']['field_workflow_status_tid']['expose']['operator'] = 'field_workflow_status_tid_op';
$handler->display->display_options['filters']['field_workflow_status_tid']['expose']['identifier'] = 'field_workflow_status_tid';
$handler->display->display_options['filters']['field_workflow_status_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_workflow_status_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
$handler->display->display_options['filters']['field_workflow_status_tid']['vocabulary'] = 'workflow_status';
/* Filter criterion: User: Name (raw) */
$handler->display->display_options['filters']['name']['id'] = 'name';
$handler->display->display_options['filters']['name']['table'] = 'users';
$handler->display->display_options['filters']['name']['field'] = 'name';
$handler->display->display_options['filters']['name']['relationship'] = 'uid';
$handler->display->display_options['filters']['name']['operator'] = 'contains';
$handler->display->display_options['filters']['name']['group'] = 1;
$handler->display->display_options['filters']['name']['exposed'] = TRUE;
$handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
$handler->display->display_options['filters']['name']['expose']['label'] = 'Author name';
$handler->display->display_options['filters']['name']['expose']['description'] = 'Enter name or part of author\'s name';
$handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
$handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
$handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
/* Filter criterion: Content: Updated date */
$handler->display->display_options['filters']['changed']['id'] = 'changed';
$handler->display->display_options['filters']['changed']['table'] = 'node';
$handler->display->display_options['filters']['changed']['field'] = 'changed';
$handler->display->display_options['filters']['changed']['operator'] = 'between';
$handler->display->display_options['filters']['changed']['group'] = 1;
$handler->display->display_options['filters']['changed']['exposed'] = TRUE;
$handler->display->display_options['filters']['changed']['expose']['operator_id'] = 'changed_op';
$handler->display->display_options['filters']['changed']['expose']['label'] = 'Updated';
$handler->display->display_options['filters']['changed']['expose']['description'] = 'Select an interval for filtering';
$handler->display->display_options['filters']['changed']['expose']['operator'] = 'changed_op';
$handler->display->display_options['filters']['changed']['expose']['identifier'] = 'changed';
$handler->display->display_options['filters']['changed']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);

/* Display: OSHA content selection */
$handler = $view->new_display('page', 'OSHA content selection', 'tmgmt_node_selection_view_page');
$handler->display->display_options['path'] = 'admin/tmgmt/sources/osha';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'OSHA content';
$handler->display->display_options['menu']['weight'] = '-30';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['tmgmt_node_selection_view'] = array(
  t('Master'),
  t('OSHA content selection'),
  t('more'),
  t('Filter'),
  t('Reset'),
  t('Sort by'),
  t('Ascending'),
  t('Descending'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('There are no results. Please broaden your filters above.'),
  t('author'),
  t('- Choose an operation -'),
  t('Type of content'),
  t('Status'),
  t('Author'),
  t('Updated'),
  t('Edit'),
  t('Post date'),
  t('Updated date'),
  t('Author name'),
  t('Type'),
  t('Search text'),
  t('Combine fields filter'),
  t('Node ID'),
  t('Activity'),
  t('Activity (field_activity)'),
  t('Section'),
  t('Nace Codes'),
  t('Thesaurus'),
  t('Workflow status'),
  t('Enter name or part of author\'s name'),
  t('Select an interval for filtering'),
);
