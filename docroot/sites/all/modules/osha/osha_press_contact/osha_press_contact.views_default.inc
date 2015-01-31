<?php
/**
 * @file
 * osha_press_contact.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_press_contact_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'fop_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FOP Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'FOP Contacts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Country (field_country) */
  $handler->display->display_options['relationships']['field_country_tid']['id'] = 'field_country_tid';
  $handler->display->display_options['relationships']['field_country_tid']['table'] = 'field_data_field_country';
  $handler->display->display_options['relationships']['field_country_tid']['field'] = 'field_country_tid';
  $handler->display->display_options['relationships']['field_country_tid']['required'] = TRUE;
  /* Relationship: Taxonomy term: Content using Country */
  $handler->display->display_options['relationships']['reverse_field_country_node']['id'] = 'reverse_field_country_node';
  $handler->display->display_options['relationships']['reverse_field_country_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_country_node']['field'] = 'reverse_field_country_node';
  $handler->display->display_options['relationships']['reverse_field_country_node']['relationship'] = 'field_country_tid';
  $handler->display->display_options['relationships']['reverse_field_country_node']['required'] = TRUE;
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_press_contact_organization']['id'] = 'field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['table'] = 'field_data_field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['field'] = 'field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_organization']['element_label_colon'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_press_contact_location']['id'] = 'field_press_contact_location';
  $handler->display->display_options['fields']['field_press_contact_location']['table'] = 'field_data_field_press_contact_location';
  $handler->display->display_options['fields']['field_press_contact_location']['field'] = 'field_press_contact_location';
  $handler->display->display_options['fields']['field_press_contact_location']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_location']['element_label_colon'] = FALSE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['label'] = '';
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Personal Title */
  $handler->display->display_options['fields']['field_personal_title']['id'] = 'field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['table'] = 'field_data_field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['field'] = 'field_personal_title';
  $handler->display->display_options['fields']['field_personal_title']['label'] = '';
  $handler->display->display_options['fields']['field_personal_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_personal_title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '[field_personal_title] [title_field]';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Job Title */
  $handler->display->display_options['fields']['field_press_contact_job_title']['id'] = 'field_press_contact_job_title';
  $handler->display->display_options['fields']['field_press_contact_job_title']['table'] = 'field_data_field_press_contact_job_title';
  $handler->display->display_options['fields']['field_press_contact_job_title']['field'] = 'field_press_contact_job_title';
  $handler->display->display_options['fields']['field_press_contact_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_job_title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Country (field_country) */
  $handler->display->display_options['arguments']['field_country_tid']['id'] = 'field_country_tid';
  $handler->display->display_options['arguments']['field_country_tid']['table'] = 'field_data_field_country';
  $handler->display->display_options['arguments']['field_country_tid']['field'] = 'field_country_tid';
  $handler->display->display_options['arguments']['field_country_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['field_country_tid']['default_argument_options']['vocabularies'] = array(
    'country' => 'country',
  );
  $handler->display->display_options['arguments']['field_country_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_country_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_country_tid']['summary_options']['items_per_page'] = '25';
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
    'press_contact' => 'press_contact',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Type (field_contact_type) */
  $handler->display->display_options['filters']['field_contact_type_tid']['id'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['filters']['field_contact_type_tid']['field'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['value'] = array(
    2970 => '2970',
  );
  $handler->display->display_options['filters']['field_contact_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_contact_type_tid']['vocabulary'] = 'contact_type';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['fop_contacts'] = array(
    t('Master'),
    t('FOP Contacts'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('term from field_country'),
    t('field_country'),
    t('[field_personal_title] [title_field]'),
    t('All'),
    t('Block'),
  );
  $export['fop_contacts'] = $view;

  $view = new view();
  $view->name = 'press_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Press Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Press Contacts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'press_contacts_queue' => 'press_contacts_queue',
    'publication_queue' => 0,
    'featured_press_release' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
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
    'press_contact' => 'press_contact',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_press_contact_organization' => 'field_press_contact_organization',
    'field_press_contact_email' => 'field_press_contact_email',
    'edit_node' => 'edit_node',
    'delete_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
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
    'field_press_contact_organization' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_press_contact_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '&emsp;',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::tmgmt_node_ui_tmgmt_nodes_add_items_to_cart' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
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
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
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
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Publish',
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
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unpublish',
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
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_press_contact_organization']['id'] = 'field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['table'] = 'field_data_field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['field'] = 'field_press_contact_organization';
  $handler->display->display_options['fields']['field_press_contact_organization']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_press_contact_organization']['settings'] = array(
    'trim_length' => '100',
  );
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_press_contact_email']['id'] = 'field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['table'] = 'field_data_field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['field'] = 'field_press_contact_email';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
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
    'press_contact' => 'press_contact',
  );
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'word';
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Contact Name';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Email (field_press_contact_email) */
  $handler->display->display_options['filters']['field_press_contact_email_email']['id'] = 'field_press_contact_email_email';
  $handler->display->display_options['filters']['field_press_contact_email_email']['table'] = 'field_data_field_press_contact_email';
  $handler->display->display_options['filters']['field_press_contact_email_email']['field'] = 'field_press_contact_email_email';
  $handler->display->display_options['filters']['field_press_contact_email_email']['operator'] = 'word';
  $handler->display->display_options['filters']['field_press_contact_email_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_press_contact_email_email']['expose']['operator_id'] = 'field_press_contact_email_email_op';
  $handler->display->display_options['filters']['field_press_contact_email_email']['expose']['label'] = 'Email';
  $handler->display->display_options['filters']['field_press_contact_email_email']['expose']['operator'] = 'field_press_contact_email_email_op';
  $handler->display->display_options['filters']['field_press_contact_email_email']['expose']['identifier'] = 'field_press_contact_email_email';
  $handler->display->display_options['filters']['field_press_contact_email_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_press_contact_email_email']['group_info']['label'] = 'Email (field_press_contact_email)';
  $handler->display->display_options['filters']['field_press_contact_email_email']['group_info']['identifier'] = 'field_press_contact_email_email';
  $handler->display->display_options['filters']['field_press_contact_email_email']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_press_contact_email_email']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['path'] = 'admin/content/press-contacts';
  $handler->display->display_options['menu']['title'] = 'Press Contacts';
  $handler->display->display_options['menu']['description'] = 'Press Contacts Administration Interface';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Press contacts';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a class="press-kit-link" href="/node/5428">EU-OSHA Press kit</a>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Job Title */
  $handler->display->display_options['fields']['field_press_contact_job_title']['id'] = 'field_press_contact_job_title';
  $handler->display->display_options['fields']['field_press_contact_job_title']['table'] = 'field_data_field_press_contact_job_title';
  $handler->display->display_options['fields']['field_press_contact_job_title']['field'] = 'field_press_contact_job_title';
  $handler->display->display_options['fields']['field_press_contact_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_job_title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_press_contact_phone']['id'] = 'field_press_contact_phone';
  $handler->display->display_options['fields']['field_press_contact_phone']['table'] = 'field_data_field_press_contact_phone';
  $handler->display->display_options['fields']['field_press_contact_phone']['field'] = 'field_press_contact_phone';
  $handler->display->display_options['fields']['field_press_contact_phone']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_phone']['element_label_colon'] = FALSE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_press_contact_email']['id'] = 'field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['table'] = 'field_data_field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['field'] = 'field_press_contact_email';
  $handler->display->display_options['fields']['field_press_contact_email']['label'] = '';
  $handler->display->display_options['fields']['field_press_contact_email']['element_label_colon'] = FALSE;
  $translatables['press_contacts'] = array(
    t('Master'),
    t('Press Contacts'),
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
    t('queue'),
    t('Page'),
    t('- Choose an operation -'),
    t('Delete'),
    t('Publish'),
    t('Unpublish'),
    t('Name'),
    t('Organization'),
    t('Email'),
    t('Operations'),
    t('Edit'),
    t('Contact Name'),
    t('Email (field_press_contact_email)'),
    t('Block'),
    t('Press contacts'),
    t('<a class="press-kit-link" href="/node/5428">EU-OSHA Press kit</a>'),
  );
  $export['press_contacts'] = $view;

  return $export;
}
