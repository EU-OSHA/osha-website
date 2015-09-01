<?php

$view = new view();
$view->name = 'tmgmt_node_selection_view';
$view->description = '';
$view->tag = 'Workbench';
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
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
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
  'field_summary' => 'field_summary',
  'body' => 'body',
  'title_1' => 'title_1',
  'type' => 'type',
  'state' => 'state',
  'name' => 'name',
  'changed' => 'changed',
  'field_character_count' => 'field_character_count',
  'field_page_count' => 'field_page_count',
);
$handler->display->display_options['style_options']['default'] = 'changed';
$handler->display->display_options['style_options']['info'] = array(
  'views_bulk_operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_summary' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'body' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title_1' => array(
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
  'state' => array(
    'sortable' => 0,
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
  'field_character_count' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_page_count' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
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
/* Relationship: Content: Entity translation: translations */
$handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
$handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
$handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
$handler->display->display_options['relationships']['entity_translations']['required'] = TRUE;
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
  'rules_component::osha_tmgmt_add_items_to_cart_retranslate' => array(
    'selected' => 1,
    'skip_confirmation' => 1,
    'override_label' => 1,
    'label' => 'Add to cart (retranslation)',
  ),
  'rules_component::tmgmt_node_ui_tmgmt_nodes_add_items_to_cart' => array(
    'selected' => 1,
    'skip_confirmation' => 1,
    'override_label' => 1,
    'label' => 'Add to cart (full translation)',
  ),
  'action::osha_newsletter_add_to_newsletter_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
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
  'action::workbench_moderation_set_state_action' => array(
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
/* Field: Content: Summary */
$handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
$handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
$handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
$handler->display->display_options['fields']['field_summary']['label'] = '';
$handler->display->display_options['fields']['field_summary']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_summary']['element_label_colon'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
/* Field: Content revision: Title */
$handler->display->display_options['fields']['title_1']['id'] = 'title_1';
$handler->display->display_options['fields']['title_1']['table'] = 'node_revision';
$handler->display->display_options['fields']['title_1']['field'] = 'title';
$handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['type'] = 'publication_title_linked';
$handler->display->display_options['fields']['title_field']['settings'] = array(
  'title_style' => '_none',
  'title_link' => 'content',
  'title_class' => '',
);
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['label'] = 'Type of content';
/* Field: Workbench Moderation: State */
$handler->display->display_options['fields']['state']['id'] = 'state';
$handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['fields']['state']['field'] = 'state';
$handler->display->display_options['fields']['state']['label'] = 'Workflow state';
$handler->display->display_options['fields']['state']['machine_name'] = 0;
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
/* Field: Content: Character count */
$handler->display->display_options['fields']['field_character_count']['id'] = 'field_character_count';
$handler->display->display_options['fields']['field_character_count']['table'] = 'field_data_field_character_count';
$handler->display->display_options['fields']['field_character_count']['field'] = 'field_character_count';
$handler->display->display_options['fields']['field_character_count']['settings'] = array(
  'thousand_separator' => ' ',
  'prefix_suffix' => 1,
);
/* Field: Content: Page count */
$handler->display->display_options['fields']['field_page_count']['id'] = 'field_page_count';
$handler->display->display_options['fields']['field_page_count']['table'] = 'field_data_field_page_count';
$handler->display->display_options['fields']['field_page_count']['field'] = 'field_page_count';
$handler->display->display_options['fields']['field_page_count']['settings'] = array(
  'thousand_separator' => ' ',
  'decimal_separator' => '.',
  'scale' => '2',
  'prefix_suffix' => 1,
);
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
  'directive' => 'directive',
  'guideline' => 'guideline',
  'highlight' => 'highlight',
  'job_vacancies' => 'job_vacancies',
  'news' => 'news',
  'press_release' => 'press_release',
  'publication' => 'publication',
  'seminar' => 'seminar',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type of content';
$handler->display->display_options['filters']['type']['expose']['description'] = 'Use CTRL to select multiple items';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
);
/* Filter criterion: Global: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['operator'] = 'contains';
$handler->display->display_options['filters']['combine']['group'] = 1;
$handler->display->display_options['filters']['combine']['exposed'] = TRUE;
$handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['label'] = 'Free text';
$handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
$handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
);
$handler->display->display_options['filters']['combine']['fields'] = array(
  'field_summary' => 'field_summary',
  'body' => 'body',
  'title_1' => 'title_1',
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
/* Filter criterion: Entity translation: Translation exists */
$handler->display->display_options['filters']['translation_exists']['id'] = 'translation_exists';
$handler->display->display_options['filters']['translation_exists']['table'] = 'entity_translation';
$handler->display->display_options['filters']['translation_exists']['field'] = 'translation_exists';
$handler->display->display_options['filters']['translation_exists']['relationship'] = 'entity_translations';
$handler->display->display_options['filters']['translation_exists']['operator'] = 'not in';
$handler->display->display_options['filters']['translation_exists']['value'] = array(
  'bg' => 'bg',
  'cs' => 'cs',
  'da' => 'da',
  'de' => 'de',
  'el' => 'el',
  'es' => 'es',
  'et' => 'et',
  'fi' => 'fi',
  'hr' => 'hr',
  'fr' => 'fr',
  'hu' => 'hu',
  'is' => 'is',
  'it' => 'it',
  'lv' => 'lv',
  'lt' => 'lt',
  'nl' => 'nl',
  'mt' => 'mt',
  'no' => 'no',
  'pl' => 'pl',
  'pt' => 'pt',
  'ro' => 'ro',
  'ru' => 'ru',
  'sk' => 'sk',
  'sl' => 'sl',
  'sv' => 'sv',
  'tr' => 'tr',
);
$handler->display->display_options['filters']['translation_exists']['group'] = 1;
$handler->display->display_options['filters']['translation_exists']['exposed'] = TRUE;
$handler->display->display_options['filters']['translation_exists']['expose']['operator_id'] = 'translation_exists_op';
$handler->display->display_options['filters']['translation_exists']['expose']['label'] = 'Not translated in';
$handler->display->display_options['filters']['translation_exists']['expose']['description'] = 'Use CTRL to select multiple items';
$handler->display->display_options['filters']['translation_exists']['expose']['operator'] = 'translation_exists_op';
$handler->display->display_options['filters']['translation_exists']['expose']['identifier'] = 'translation_exists';
$handler->display->display_options['filters']['translation_exists']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['translation_exists']['expose']['remember_roles'] = array(
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
);
$handler->display->display_options['filters']['translation_exists']['expose']['reduce'] = TRUE;
$handler->display->display_options['filters']['translation_exists']['entity_type'] = 'node';
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
$handler->display->display_options['filters']['field_activity_tid']['expose']['remember_roles'] = array(
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
);
$handler->display->display_options['filters']['field_activity_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_activity_tid']['vocabulary'] = 'activity';
$handler->display->display_options['filters']['field_activity_tid']['hierarchy'] = 1;
/* Filter criterion: Workbench Access: Access filter */
$handler->display->display_options['filters']['access_id']['id'] = 'access_id';
$handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
$handler->display->display_options['filters']['access_id']['field'] = 'access_id';
$handler->display->display_options['filters']['access_id']['group'] = 1;
$handler->display->display_options['filters']['access_id']['exposed'] = TRUE;
$handler->display->display_options['filters']['access_id']['expose']['operator_id'] = 'access_id_op';
$handler->display->display_options['filters']['access_id']['expose']['label'] = 'Section';
$handler->display->display_options['filters']['access_id']['expose']['description'] = 'Use CTRL to select multiple items';
$handler->display->display_options['filters']['access_id']['expose']['operator'] = 'access_id_op';
$handler->display->display_options['filters']['access_id']['expose']['identifier'] = 'access_id';
$handler->display->display_options['filters']['access_id']['expose']['remember_roles'] = array(
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
);
$handler->display->display_options['filters']['access_id']['access_id'] = array();
$handler->display->display_options['filters']['access_id']['size'] = '5';
/* Filter criterion: Content: Page count (field_page_count) */
$handler->display->display_options['filters']['field_page_count_value']['id'] = 'field_page_count_value';
$handler->display->display_options['filters']['field_page_count_value']['table'] = 'field_data_field_page_count';
$handler->display->display_options['filters']['field_page_count_value']['field'] = 'field_page_count_value';
$handler->display->display_options['filters']['field_page_count_value']['operator'] = '>=';
$handler->display->display_options['filters']['field_page_count_value']['group'] = 1;
$handler->display->display_options['filters']['field_page_count_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_page_count_value']['expose']['operator_id'] = 'field_page_count_value_op';
$handler->display->display_options['filters']['field_page_count_value']['expose']['label'] = 'Page count';
$handler->display->display_options['filters']['field_page_count_value']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['field_page_count_value']['expose']['operator'] = 'field_page_count_value_op';
$handler->display->display_options['filters']['field_page_count_value']['expose']['identifier'] = 'field_page_count_value';
$handler->display->display_options['filters']['field_page_count_value']['expose']['remember_roles'] = array(
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
);
/* Filter criterion: Content: Character count (field_character_count) */
$handler->display->display_options['filters']['field_character_count_value']['id'] = 'field_character_count_value';
$handler->display->display_options['filters']['field_character_count_value']['table'] = 'field_data_field_character_count';
$handler->display->display_options['filters']['field_character_count_value']['field'] = 'field_character_count_value';
$handler->display->display_options['filters']['field_character_count_value']['operator'] = '>=';
$handler->display->display_options['filters']['field_character_count_value']['group'] = 1;
$handler->display->display_options['filters']['field_character_count_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_character_count_value']['expose']['operator_id'] = 'field_character_count_value_op';
$handler->display->display_options['filters']['field_character_count_value']['expose']['label'] = 'Character count';
$handler->display->display_options['filters']['field_character_count_value']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['field_character_count_value']['expose']['operator'] = 'field_character_count_value_op';
$handler->display->display_options['filters']['field_character_count_value']['expose']['identifier'] = 'field_character_count_value';
$handler->display->display_options['filters']['field_character_count_value']['expose']['remember_roles'] = array(
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
);
/* Filter criterion: Workbench Moderation: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'ready_to_publish' => 'ready_to_publish',
  'published' => 'published',
);
$handler->display->display_options['filters']['state']['group'] = 1;
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'Workflow state';
$handler->display->display_options['filters']['state']['expose']['description'] = 'Published includes also items without publishing workflow. Use CTRL to select multiple items';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['required'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
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
);
$handler->display->display_options['filters']['state']['expose']['reduce'] = TRUE;
$handler->display->display_options['filters']['state']['group_info']['label'] = 'Workflow state';
$handler->display->display_options['filters']['state']['group_info']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['group_info']['group_items'] = array(
  1 => array(
    'title' => 'Published',
    'operator' => 'in',
    'value' => array(
      'published' => 'published',
      'all' => 0,
      'draft' => 0,
      'rejected' => 0,
      'approved' => 0,
      'final_draft' => 0,
      'needs_review' => 0,
      'to_be_approved' => 0,
      'ready_to_publish' => 0,
    ),
  ),
  2 => array(
    'title' => 'Ready to Publish',
    'operator' => 'in',
    'value' => array(
      'ready_to_publish' => 'ready_to_publish',
      'all' => 0,
      'draft' => 0,
      'rejected' => 0,
      'approved' => 0,
      'final_draft' => 0,
      'needs_review' => 0,
      'to_be_approved' => 0,
      'published' => 0,
    ),
  ),
);
/* Filter criterion: Content revision: Updated date */
$handler->display->display_options['filters']['timestamp_1']['id'] = 'timestamp_1';
$handler->display->display_options['filters']['timestamp_1']['table'] = 'node_revision';
$handler->display->display_options['filters']['timestamp_1']['field'] = 'timestamp';
$handler->display->display_options['filters']['timestamp_1']['operator'] = '>=';
$handler->display->display_options['filters']['timestamp_1']['group'] = 1;
$handler->display->display_options['filters']['timestamp_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['timestamp_1']['expose']['operator_id'] = 'timestamp_1_op';
$handler->display->display_options['filters']['timestamp_1']['expose']['label'] = 'Updated after';
$handler->display->display_options['filters']['timestamp_1']['expose']['operator'] = 'timestamp_1_op';
$handler->display->display_options['filters']['timestamp_1']['expose']['identifier'] = 'from_date';
/* Filter criterion: Content revision: Updated date */
$handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['filters']['timestamp']['table'] = 'node_revision';
$handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['filters']['timestamp']['operator'] = '<=';
$handler->display->display_options['filters']['timestamp']['group'] = 1;
$handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
$handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
$handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Updated before';
$handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
$handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'to_date';

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
  t('Translations'),
  t('- Choose an operation -'),
  t('Add to cart (retranslation)'),
  t('Add to cart (full translation)'),
  t('Title'),
  t('Type of content'),
  t('Workflow state'),
  t('Author'),
  t('Updated'),
  t('Character count'),
  t('Page count'),
  t('Post date'),
  t('Updated date'),
  t('Author name'),
  t('Type'),
  t('Use CTRL to select multiple items'),
  t('Free text'),
  t('Node ID'),
  t('Not translated in'),
  t('Activity'),
  t('Section'),
  t('Published includes also items without publishing workflow. Use CTRL to select multiple items'),
  t('Updated after'),
  t('Updated before'),
);
