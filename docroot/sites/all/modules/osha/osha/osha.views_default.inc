<?php
/**
 * @file
 * osha.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'administration_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Administration content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Administration content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view the administration theme';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'name' => 'name',
    'state' => 'state',
    'status' => 'status',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nothing' => 'nothing',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
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
    'name' => array(
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
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
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
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Workbench Moderation: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'activity' => 0,
    'article_types' => 0,
    'directive_type' => 0,
    'legislation_category' => 0,
    'esener' => 0,
    'nace_codes' => 0,
    'section' => 0,
    'attachment_file_type' => 0,
    'flickr_tags' => 0,
    'newsletter_sections' => 0,
    'publication_types' => 0,
    'tags' => 0,
    'thesaurus' => 0,
    'wiki_categories' => 0,
    'workflow_status' => 0,
  );
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
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
  /* Field: Workbench Access: Section */
  $handler->display->display_options['fields']['section']['id'] = 'section';
  $handler->display->display_options['fields']['section']['table'] = 'workbench_access';
  $handler->display->display_options['fields']['section']['field'] = 'section';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content Type';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Workflow';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'year';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'edit';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'edit';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '[edit_node] [delete_node]';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] [delete_node]';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'banner' => 'banner',
    'page' => 'page',
    'blog' => 'blog',
    'calls' => 'calls',
    'press_contact' => 'press_contact',
    'directive' => 'directive',
    'external_url' => 'external_url',
    'file' => 'file',
    'flickr' => 'flickr',
    'fop_page' => 'fop_page',
    'guideline' => 'guideline',
    'highlight' => 'highlight',
    'infographic' => 'infographic',
    'job_vacancies' => 'job_vacancies',
    'news' => 'news',
    'newsletter_article' => 'newsletter_article',
    'note_to_editor' => 'note_to_editor',
    'press_release' => 'press_release',
    'publication' => 'publication',
    'seminar' => 'seminar',
    'slideshare' => 'slideshare',
    'wiki_page' => 'wiki_page',
    'youtube' => 'youtube',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
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
    12 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
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
    12 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['vid']['group'] = 1;
  $handler->display->display_options['filters']['vid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['vid']['expose']['operator_id'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['label'] = 'Vocabulary';
  $handler->display->display_options['filters']['vid']['expose']['operator'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['identifier'] = 'vid';
  $handler->display->display_options['filters']['vid']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Entity translation: Translation exists */
  $handler->display->display_options['filters']['translation_exists']['id'] = 'translation_exists';
  $handler->display->display_options['filters']['translation_exists']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['translation_exists']['field'] = 'translation_exists';
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
    'sk' => 'sk',
    'sl' => 'sl',
    'sv' => 'sv',
  );
  $handler->display->display_options['filters']['translation_exists']['group'] = 1;
  $handler->display->display_options['filters']['translation_exists']['exposed'] = TRUE;
  $handler->display->display_options['filters']['translation_exists']['expose']['operator_id'] = 'translation_exists_op';
  $handler->display->display_options['filters']['translation_exists']['expose']['label'] = 'Not translated in';
  $handler->display->display_options['filters']['translation_exists']['expose']['operator'] = 'translation_exists_op';
  $handler->display->display_options['filters']['translation_exists']['expose']['identifier'] = 'translation_exists';
  $handler->display->display_options['filters']['translation_exists']['expose']['remember'] = TRUE;
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
  /* Filter criterion: Workbench Access: Access filter */
  $handler->display->display_options['filters']['access_id']['id'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['table'] = 'workbench_access';
  $handler->display->display_options['filters']['access_id']['field'] = 'access_id';
  $handler->display->display_options['filters']['access_id']['group'] = 1;
  $handler->display->display_options['filters']['access_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['access_id']['expose']['operator_id'] = 'access_id_op';
  $handler->display->display_options['filters']['access_id']['expose']['label'] = 'Section';
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
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
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
  $handler->display->display_options['filters']['state']['group_info']['label'] = 'State';
  $handler->display->display_options['filters']['state']['group_info']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['state']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['current']['id'] = 'current';
  $handler->display->display_options['filters']['current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['current']['field'] = 'current';
  $handler->display->display_options['filters']['current']['value'] = '1';
  $handler->display->display_options['filters']['current']['group'] = 2;
  /* Filter criterion: Workbench Moderation: Type is moderated */
  $handler->display->display_options['filters']['workbench_moderation_moderated_type']['id'] = 'workbench_moderation_moderated_type';
  $handler->display->display_options['filters']['workbench_moderation_moderated_type']['table'] = 'node';
  $handler->display->display_options['filters']['workbench_moderation_moderated_type']['field'] = 'workbench_moderation_moderated_type';
  $handler->display->display_options['filters']['workbench_moderation_moderated_type']['value'] = '0';
  $handler->display->display_options['filters']['workbench_moderation_moderated_type']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'main_page');
  $handler->display->display_options['path'] = 'admin/content';
  $translatables['administration_content'] = array(
    t('Master'),
    t('Administration content'),
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
    t('author'),
    t('Node'),
    t('term'),
    t('Translations'),
    t('Select'),
    t('- Choose an operation -'),
    t('Delete'),
    t('Title'),
    t('Section'),
    t('Content Type'),
    t('Author'),
    t('Published'),
    t('Workflow'),
    t('Updated date'),
    t('edit'),
    t('[edit_node] [delete_node]'),
    t('Operations'),
    t('Type'),
    t('Vocabulary'),
    t('Not translated in'),
    t('State'),
    t('Page'),
  );
  $export['administration_content'] = $view;

  $view = new view();
  $view->name = 'data_export';
  $view->description = 'Data exported as machine compatible (JSON, XML etc.)';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Data export services';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['content_type'] = 'text/json';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 1;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Relationship: Field: Tags (field_tags) */
  $handler->display->display_options['relationships']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['relationships']['field_tags_tid']['field'] = 'field_tags_tid';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'title';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['label'] = 'summary';
  $handler->display->display_options['fields']['field_summary']['type'] = 'text_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = 'image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Field: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = 'publication_date';
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Expiration date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = 'expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Field: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = 'tags';
  $handler->display->display_options['fields']['field_tags']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['multi_type'] = 'ul';
  /* Field: Field: Thesaurus */
  $handler->display->display_options['fields']['field_thesaurus']['id'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['table'] = 'field_data_field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['field'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['label'] = 'thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_thesaurus']['multi_type'] = 'ol';
  /* Field: Content: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['label'] = 'activity';
  $handler->display->display_options['fields']['field_activity']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_activity']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity']['multi_type'] = 'ol';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'post_date';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'year';
  /* Field: Content: Embargo date */
  $handler->display->display_options['fields']['field_pr_embargo_date']['id'] = 'field_pr_embargo_date';
  $handler->display->display_options['fields']['field_pr_embargo_date']['table'] = 'field_data_field_pr_embargo_date';
  $handler->display->display_options['fields']['field_pr_embargo_date']['field'] = 'field_pr_embargo_date';
  $handler->display->display_options['fields']['field_pr_embargo_date']['label'] = 'pr_embargo_date';
  $handler->display->display_options['fields']['field_pr_embargo_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Field: Nace */
  $handler->display->display_options['fields']['field_nace_codes']['id'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['table'] = 'field_data_field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['field'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['label'] = 'nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['delta_offset'] = '0';
  /* Contextual filter: Taxonomy term: Code (field_tags_code) */
  $handler->display->display_options['arguments']['field_tags_code_value']['id'] = 'field_tags_code_value';
  $handler->display->display_options['arguments']['field_tags_code_value']['table'] = 'field_data_field_tags_code';
  $handler->display->display_options['arguments']['field_tags_code_value']['field'] = 'field_tags_code_value';
  $handler->display->display_options['arguments']['field_tags_code_value']['relationship'] = 'field_tags_tid';
  $handler->display->display_options['arguments']['field_tags_code_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_tags_code_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tags_code_value']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['field_tags_code_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tags_code_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tags_code_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_tags_code_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_tags_code_value']['break_phrase'] = TRUE;
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
    'events' => 'events',
    'news' => 'news',
  );

  /* Display: News */
  $handler = $view->new_display('page', 'News', 'page_news');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Tags (field_tags) */
  $handler->display->display_options['relationships']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['relationships']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'title';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['label'] = 'summary';
  $handler->display->display_options['fields']['field_summary']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_summary']['hide_alter_empty'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = 'image';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Field: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = 'publication_date';
  $handler->display->display_options['fields']['field_publication_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Expiration date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = 'expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Field: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = 'tags';
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['separator'] = '\\n';
  /* Field: Field: Thesaurus */
  $handler->display->display_options['fields']['field_thesaurus']['id'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['table'] = 'field_data_field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['field'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['label'] = 'thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_thesaurus']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thesaurus']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_thesaurus']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_thesaurus']['separator'] = '\\n';
  /* Field: Content: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['label'] = 'activity';
  $handler->display->display_options['fields']['field_activity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_activity']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity']['separator'] = '\\n';
  /* Field: Field: Nace */
  $handler->display->display_options['fields']['field_nace_codes']['id'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['table'] = 'field_data_field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['field'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['label'] = 'nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_nace_codes']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_nace_codes']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_nace_codes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_nace_codes']['separator'] = '\\n';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Code (field_tags_code) */
  $handler->display->display_options['arguments']['field_tags_code_value']['id'] = 'field_tags_code_value';
  $handler->display->display_options['arguments']['field_tags_code_value']['table'] = 'field_data_field_tags_code';
  $handler->display->display_options['arguments']['field_tags_code_value']['field'] = 'field_tags_code_value';
  $handler->display->display_options['arguments']['field_tags_code_value']['relationship'] = 'field_tags_tid';
  $handler->display->display_options['arguments']['field_tags_code_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_tags_code_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tags_code_value']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['field_tags_code_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tags_code_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tags_code_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_tags_code_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_tags_code_value']['break_phrase'] = TRUE;
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
    'highlight' => 'highlight',
    'news' => 'news',
  );
  /* Filter criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'services/hw/news';

  /* Display: Events */
  $handler = $view->new_display('page', 'Events', 'page_events');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Tags (field_tags) */
  $handler->display->display_options['relationships']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['relationships']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'title';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = 'organization';
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = 'country';
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code_1']['id'] = 'field_country_code_1';
  $handler->display->display_options['fields']['field_country_code_1']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code_1']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code_1']['label'] = 'country_code';
  $handler->display->display_options['fields']['field_country_code_1']['type'] = 'list_key';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = 'start_date';
  $handler->display->display_options['fields']['field_start_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_start_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = 'end_date';
  $handler->display->display_options['fields']['field_start_date_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: For the web */
  $handler->display->display_options['fields']['field_for_the_web']['id'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['table'] = 'field_data_field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['field'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['label'] = 'for_the_web';
  /* Field: Content: Website of event */
  $handler->display->display_options['fields']['field_website_of_event']['id'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['table'] = 'field_data_field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['field'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['label'] = 'website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website_of_event']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_website_of_event']['delta_offset'] = '0';
  /* Field: Field: Tags */
  $handler->display->display_options['fields']['field_tags_1']['id'] = 'field_tags_1';
  $handler->display->display_options['fields']['field_tags_1']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags_1']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags_1']['label'] = 'category';
  $handler->display->display_options['fields']['field_tags_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tags_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tags_1']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags_1']['separator'] = '\\n';
  /* Field: Content: Adonis */
  $handler->display->display_options['fields']['field_adonis']['id'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['table'] = 'field_data_field_adonis';
  $handler->display->display_options['fields']['field_adonis']['field'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['label'] = 'adonis';
  /* Field: Content: Unit Ref */
  $handler->display->display_options['fields']['field_unit_ref']['id'] = 'field_unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['table'] = 'field_data_field_unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['field'] = 'field_unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['label'] = 'unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['delta_offset'] = '0';
  /* Field: Content: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['label'] = 'activity';
  $handler->display->display_options['fields']['field_activity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_activity']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity']['separator'] = '\\n';
  /* Field: Content: Agency role */
  $handler->display->display_options['fields']['field_agency_role']['id'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['table'] = 'field_data_field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['field'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['label'] = 'agency_role';
  $handler->display->display_options['fields']['field_agency_role']['delta_offset'] = '0';
  /* Field: Content: Agency initial contact */
  $handler->display->display_options['fields']['field_agency_initial_contact']['id'] = 'field_agency_initial_contact';
  $handler->display->display_options['fields']['field_agency_initial_contact']['table'] = 'field_data_field_agency_initial_contact';
  $handler->display->display_options['fields']['field_agency_initial_contact']['field'] = 'field_agency_initial_contact';
  $handler->display->display_options['fields']['field_agency_initial_contact']['label'] = 'agency_initial_contact';
  /* Field: Content: Agency rep confirmed */
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['id'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['table'] = 'field_data_field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['field'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['label'] = 'agency_rep_confirmed';
  /* Field: Content: Organised by */
  $handler->display->display_options['fields']['field_organised_by']['id'] = 'field_organised_by';
  $handler->display->display_options['fields']['field_organised_by']['table'] = 'field_data_field_organised_by';
  $handler->display->display_options['fields']['field_organised_by']['field'] = 'field_organised_by';
  $handler->display->display_options['fields']['field_organised_by']['label'] = 'organised_by';
  $handler->display->display_options['fields']['field_organised_by']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_organised_by']['delta_offset'] = '0';
  /* Field: Content: Satisfaction rate */
  $handler->display->display_options['fields']['field_satisfaction_rate']['id'] = 'field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['table'] = 'field_data_field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['field'] = 'field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['label'] = 'satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_satisfaction_rate']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_satisfaction_rate']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_satisfaction_rate']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Event in AMP */
  $handler->display->display_options['fields']['field_event_in_amp']['id'] = 'field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['table'] = 'field_data_field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['field'] = 'field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['label'] = 'event_in_amp';
  /* Field: Content: Agency contact / reply */
  $handler->display->display_options['fields']['field_agency_contact_reply']['id'] = 'field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['table'] = 'field_data_field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['field'] = 'field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['label'] = 'agency_contact_reply';
  /* Field: Content: Comments */
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['id'] = 'field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['table'] = 'field_data_field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['field'] = 'field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['label'] = 'comments_summary_after_eve';
  /* Field: Content: Number of attendees */
  $handler->display->display_options['fields']['field_number_of_attendees']['id'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['table'] = 'field_data_field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['field'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['label'] = 'number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Content: Related documents */
  $handler->display->display_options['fields']['field_related_documents']['id'] = 'field_related_documents';
  $handler->display->display_options['fields']['field_related_documents']['table'] = 'field_data_field_related_documents';
  $handler->display->display_options['fields']['field_related_documents']['field'] = 'field_related_documents';
  $handler->display->display_options['fields']['field_related_documents']['label'] = 'related_documents';
  $handler->display->display_options['fields']['field_related_documents']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_related_documents']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_related_documents']['delta_offset'] = '0';
  /* Field: Content: Color */
  $handler->display->display_options['fields']['field_color']['id'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['table'] = 'field_data_field_color';
  $handler->display->display_options['fields']['field_color']['field'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['label'] = 'color';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Code (field_tags_code) */
  $handler->display->display_options['arguments']['field_tags_code_value']['id'] = 'field_tags_code_value';
  $handler->display->display_options['arguments']['field_tags_code_value']['table'] = 'field_data_field_tags_code';
  $handler->display->display_options['arguments']['field_tags_code_value']['field'] = 'field_tags_code_value';
  $handler->display->display_options['arguments']['field_tags_code_value']['relationship'] = 'field_tags_tid';
  $handler->display->display_options['arguments']['field_tags_code_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_tags_code_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tags_code_value']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['field_tags_code_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tags_code_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tags_code_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_tags_code_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_tags_code_value']['break_phrase'] = TRUE;
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
    'events' => 'events',
  );
  /* Filter criterion: Content: Date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator_id'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['label'] = 'start_date';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['identifier'] = 'start_date';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['remember_roles'] = array(
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
    12 => 0,
  );
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_start_date_value']['year_range'] = '1900:+3';
  $handler->display->display_options['path'] = 'services/hw/events';

  /* Display: Press releases */
  $handler = $view->new_display('page', 'Press releases', 'page_pr');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'title';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['label'] = 'summary';
  $handler->display->display_options['fields']['field_summary']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_summary']['hide_alter_empty'] = FALSE;
  /* Field: Field: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = 'publication_date';
  $handler->display->display_options['fields']['field_publication_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Embargo date */
  $handler->display->display_options['fields']['field_pr_embargo_date']['id'] = 'field_pr_embargo_date';
  $handler->display->display_options['fields']['field_pr_embargo_date']['table'] = 'field_data_field_pr_embargo_date';
  $handler->display->display_options['fields']['field_pr_embargo_date']['field'] = 'field_pr_embargo_date';
  $handler->display->display_options['fields']['field_pr_embargo_date']['label'] = 'pr_embargo_date';
  $handler->display->display_options['fields']['field_pr_embargo_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_pr_embargo_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pr_embargo_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Expiration date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = 'expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = 'image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Field: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = 'tags';
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['separator'] = '\\n';
  /* Field: Field: Nace */
  $handler->display->display_options['fields']['field_nace_codes']['id'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['table'] = 'field_data_field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['field'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['label'] = 'nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_nace_codes']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_nace_codes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_nace_codes']['separator'] = '\\n';
  /* Field: Field: Thesaurus */
  $handler->display->display_options['fields']['field_thesaurus']['id'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['table'] = 'field_data_field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['field'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['label'] = 'thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_thesaurus']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thesaurus']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_thesaurus']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_thesaurus']['separator'] = '\\n';
  /* Field: Content: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['label'] = 'activity';
  $handler->display->display_options['fields']['field_activity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_activity']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity']['separator'] = '\\n';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
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
    'press_release' => 'press_release',
  );
  /* Filter criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'services/hw/pr';

  /* Display: Publications */
  $handler = $view->new_display('page', 'Publications', 'page_publication');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Tags (field_tags) */
  $handler->display->display_options['relationships']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['relationships']['field_tags_tid']['field'] = 'field_tags_tid';
  /* Relationship: Content: File (field_file:fid) */
  $handler->display->display_options['relationships']['field_file_fid']['id'] = 'field_file_fid';
  $handler->display->display_options['relationships']['field_file_fid']['table'] = 'field_data_field_file';
  $handler->display->display_options['relationships']['field_file_fid']['field'] = 'field_file_fid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Publication Type */
  $handler->display->display_options['fields']['field_publication_type']['id'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['table'] = 'field_data_field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['field'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['label'] = 'publication_type';
  $handler->display->display_options['fields']['field_publication_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'title';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Cover image */
  $handler->display->display_options['fields']['field_cover_image']['id'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['table'] = 'field_data_field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['field'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['label'] = 'cover_image';
  $handler->display->display_options['fields']['field_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cover_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Cover image */
  $handler->display->display_options['fields']['field_cover_image_1']['id'] = 'field_cover_image_1';
  $handler->display->display_options['fields']['field_cover_image_1']['table'] = 'field_data_field_cover_image';
  $handler->display->display_options['fields']['field_cover_image_1']['field'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image_1']['label'] = 'cover_image_thumbnail';
  $handler->display->display_options['fields']['field_cover_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cover_image_1']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Field: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = 'publication_date';
  $handler->display->display_options['fields']['field_publication_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Expiration date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = 'expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Field: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = 'tags';
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['separator'] = '\\n';
  /* Field: Field: Thesaurus */
  $handler->display->display_options['fields']['field_thesaurus']['id'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['table'] = 'field_data_field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['field'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['label'] = 'thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_thesaurus']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thesaurus']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_thesaurus']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_thesaurus']['separator'] = '\\n';
  /* Field: Field: Nace */
  $handler->display->display_options['fields']['field_nace_codes']['id'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['table'] = 'field_data_field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['field'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['label'] = 'nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_nace_codes']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_nace_codes']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_nace_codes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_nace_codes']['separator'] = '\\n';
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['label'] = 'author';
  /* Field: Content: Bookshop ID */
  $handler->display->display_options['fields']['field_publication_bookshop_id']['id'] = 'field_publication_bookshop_id';
  $handler->display->display_options['fields']['field_publication_bookshop_id']['table'] = 'field_data_field_publication_bookshop_id';
  $handler->display->display_options['fields']['field_publication_bookshop_id']['field'] = 'field_publication_bookshop_id';
  /* Field: Content: File */
  $handler->display->display_options['fields']['field_file']['id'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['table'] = 'field_data_field_file';
  $handler->display->display_options['fields']['field_file']['field'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['label'] = 'file';
  $handler->display->display_options['fields']['field_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_file']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file']['type'] = 'file_url_plain';
  /* Field: Content: Resources (files) */
  $handler->display->display_options['fields']['field_publication_related_res']['id'] = 'field_publication_related_res';
  $handler->display->display_options['fields']['field_publication_related_res']['table'] = 'field_data_field_publication_related_res';
  $handler->display->display_options['fields']['field_publication_related_res']['field'] = 'field_publication_related_res';
  $handler->display->display_options['fields']['field_publication_related_res']['label'] = 'resources';
  $handler->display->display_options['fields']['field_publication_related_res']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_related_res']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_publication_related_res']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_publication_related_res']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_publication_related_res']['separator'] = '\\n';
  /* Field: Content: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['label'] = 'activity';
  $handler->display->display_options['fields']['field_activity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_activity']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity']['separator'] = '\\n';
  /* Field: File: Size */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['relationship'] = 'field_file_fid';
  $handler->display->display_options['fields']['filesize']['label'] = 'file_size';
  /* Field: File: Mime type */
  $handler->display->display_options['fields']['filemime']['id'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filemime']['field'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['relationship'] = 'field_file_fid';
  $handler->display->display_options['fields']['filemime']['label'] = 'file_mime_type';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
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
    'publication' => 'publication',
  );
  /* Filter criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: File (field_file:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_file';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'services/hw/publications';

  /* Display: News - single item */
  $handler = $view->new_display('page', 'News - single item', 'page_news_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'title';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['label'] = 'summary';
  $handler->display->display_options['fields']['field_summary']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_summary']['hide_alter_empty'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = 'image';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Field: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = 'publication_date';
  $handler->display->display_options['fields']['field_publication_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Expiration date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = 'expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Field: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = 'tags';
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['separator'] = '\\n';
  /* Field: Field: Thesaurus */
  $handler->display->display_options['fields']['field_thesaurus']['id'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['table'] = 'field_data_field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['field'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['label'] = 'thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_thesaurus']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thesaurus']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_thesaurus']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_thesaurus']['separator'] = '\\n';
  /* Field: Content: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['label'] = 'activity';
  $handler->display->display_options['fields']['field_activity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_activity']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity']['separator'] = '\\n';
  /* Field: Field: Nace */
  $handler->display->display_options['fields']['field_nace_codes']['id'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['table'] = 'field_data_field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['field'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['label'] = 'nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_nace_codes']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_nace_codes']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_nace_codes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_nace_codes']['separator'] = '\\n';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'highlight' => 'highlight',
    'news' => 'news',
  );
  /* Filter criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'services/hw/news1';

  /* Display: Events - single item */
  $handler = $view->new_display('page', 'Events - single item', 'page_events_1');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Tags (field_tags) */
  $handler->display->display_options['relationships']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['relationships']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'title';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = 'organization';
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = 'country';
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code_1']['id'] = 'field_country_code_1';
  $handler->display->display_options['fields']['field_country_code_1']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code_1']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code_1']['label'] = 'country_code';
  $handler->display->display_options['fields']['field_country_code_1']['type'] = 'list_key';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = 'start_date';
  $handler->display->display_options['fields']['field_start_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_start_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = 'end_date';
  $handler->display->display_options['fields']['field_start_date_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: For the web */
  $handler->display->display_options['fields']['field_for_the_web']['id'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['table'] = 'field_data_field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['field'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['label'] = 'for_the_web';
  /* Field: Content: Website of event */
  $handler->display->display_options['fields']['field_website_of_event']['id'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['table'] = 'field_data_field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['field'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['label'] = 'website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website_of_event']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_website_of_event']['delta_offset'] = '0';
  /* Field: Field: Tags */
  $handler->display->display_options['fields']['field_tags_1']['id'] = 'field_tags_1';
  $handler->display->display_options['fields']['field_tags_1']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags_1']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags_1']['label'] = 'category';
  $handler->display->display_options['fields']['field_tags_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tags_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tags_1']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags_1']['separator'] = '\\n';
  /* Field: Content: Adonis */
  $handler->display->display_options['fields']['field_adonis']['id'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['table'] = 'field_data_field_adonis';
  $handler->display->display_options['fields']['field_adonis']['field'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['label'] = 'adonis';
  /* Field: Content: Unit Ref */
  $handler->display->display_options['fields']['field_unit_ref']['id'] = 'field_unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['table'] = 'field_data_field_unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['field'] = 'field_unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['label'] = 'unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['delta_offset'] = '0';
  /* Field: Content: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['label'] = 'activity';
  $handler->display->display_options['fields']['field_activity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_activity']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity']['separator'] = '\\n';
  /* Field: Content: Agency role */
  $handler->display->display_options['fields']['field_agency_role']['id'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['table'] = 'field_data_field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['field'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['label'] = 'agency_role';
  $handler->display->display_options['fields']['field_agency_role']['delta_offset'] = '0';
  /* Field: Content: Agency initial contact */
  $handler->display->display_options['fields']['field_agency_initial_contact']['id'] = 'field_agency_initial_contact';
  $handler->display->display_options['fields']['field_agency_initial_contact']['table'] = 'field_data_field_agency_initial_contact';
  $handler->display->display_options['fields']['field_agency_initial_contact']['field'] = 'field_agency_initial_contact';
  $handler->display->display_options['fields']['field_agency_initial_contact']['label'] = 'agency_initial_contact';
  /* Field: Content: Agency rep confirmed */
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['id'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['table'] = 'field_data_field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['field'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['label'] = 'agency_rep_confirmed';
  /* Field: Content: Organised by */
  $handler->display->display_options['fields']['field_organised_by']['id'] = 'field_organised_by';
  $handler->display->display_options['fields']['field_organised_by']['table'] = 'field_data_field_organised_by';
  $handler->display->display_options['fields']['field_organised_by']['field'] = 'field_organised_by';
  $handler->display->display_options['fields']['field_organised_by']['label'] = 'organised_by';
  $handler->display->display_options['fields']['field_organised_by']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_organised_by']['delta_offset'] = '0';
  /* Field: Content: Satisfaction rate */
  $handler->display->display_options['fields']['field_satisfaction_rate']['id'] = 'field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['table'] = 'field_data_field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['field'] = 'field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['label'] = 'satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Event in AMP */
  $handler->display->display_options['fields']['field_event_in_amp']['id'] = 'field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['table'] = 'field_data_field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['field'] = 'field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['label'] = 'event_in_amp';
  /* Field: Content: Agency contact / reply */
  $handler->display->display_options['fields']['field_agency_contact_reply']['id'] = 'field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['table'] = 'field_data_field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['field'] = 'field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['label'] = 'agency_contact_reply';
  /* Field: Content: Comments */
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['id'] = 'field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['table'] = 'field_data_field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['field'] = 'field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['label'] = 'comments_summary_after_eve';
  /* Field: Content: Number of attendees */
  $handler->display->display_options['fields']['field_number_of_attendees']['id'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['table'] = 'field_data_field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['field'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['label'] = 'number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Content: Related documents */
  $handler->display->display_options['fields']['field_related_documents']['id'] = 'field_related_documents';
  $handler->display->display_options['fields']['field_related_documents']['table'] = 'field_data_field_related_documents';
  $handler->display->display_options['fields']['field_related_documents']['field'] = 'field_related_documents';
  $handler->display->display_options['fields']['field_related_documents']['label'] = 'related_documents';
  $handler->display->display_options['fields']['field_related_documents']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_related_documents']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_related_documents']['delta_offset'] = '0';
  /* Field: Content: Color */
  $handler->display->display_options['fields']['field_color']['id'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['table'] = 'field_data_field_color';
  $handler->display->display_options['fields']['field_color']['field'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['label'] = 'color';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'events' => 'events',
  );
  /* Filter criterion: Content: Date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator_id'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['label'] = 'start_date';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['identifier'] = 'start_date';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['remember_roles'] = array(
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
    12 => 0,
  );
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_start_date_value']['year_range'] = '1900:+3';
  $handler->display->display_options['path'] = 'services/hw/events1';

  /* Display: Press releases - single item */
  $handler = $view->new_display('page', 'Press releases - single item', 'page_pr_1');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'title';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['label'] = 'summary';
  $handler->display->display_options['fields']['field_summary']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_summary']['hide_alter_empty'] = FALSE;
  /* Field: Field: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = 'publication_date';
  $handler->display->display_options['fields']['field_publication_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Embargo date */
  $handler->display->display_options['fields']['field_pr_embargo_date']['id'] = 'field_pr_embargo_date';
  $handler->display->display_options['fields']['field_pr_embargo_date']['table'] = 'field_data_field_pr_embargo_date';
  $handler->display->display_options['fields']['field_pr_embargo_date']['field'] = 'field_pr_embargo_date';
  $handler->display->display_options['fields']['field_pr_embargo_date']['label'] = 'pr_embargo_date';
  $handler->display->display_options['fields']['field_pr_embargo_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_pr_embargo_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pr_embargo_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_pr_embargo_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Expiration date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = 'expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_expiration_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_expiration_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = 'image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  /* Field: Field: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = 'tags';
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['separator'] = '\\n';
  /* Field: Field: Nace */
  $handler->display->display_options['fields']['field_nace_codes']['id'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['table'] = 'field_data_field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['field'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['label'] = 'nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_nace_codes']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_nace_codes']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_nace_codes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_nace_codes']['separator'] = '\\n';
  /* Field: Field: Thesaurus */
  $handler->display->display_options['fields']['field_thesaurus']['id'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['table'] = 'field_data_field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['field'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['label'] = 'thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_thesaurus']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thesaurus']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_thesaurus']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_thesaurus']['separator'] = '\\n';
  /* Field: Content: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['label'] = 'activity';
  $handler->display->display_options['fields']['field_activity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_activity']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity']['separator'] = '\\n';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'press_release' => 'press_release',
  );
  /* Filter criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'services/hw/pr1';

  /* Display: Publications - single item */
  $handler = $view->new_display('page', 'Publications - single item', 'page_publications_1');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Tags (field_tags) */
  $handler->display->display_options['relationships']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['relationships']['field_tags_tid']['field'] = 'field_tags_tid';
  /* Relationship: Content: File (field_file:fid) */
  $handler->display->display_options['relationships']['field_file_fid']['id'] = 'field_file_fid';
  $handler->display->display_options['relationships']['field_file_fid']['table'] = 'field_data_field_file';
  $handler->display->display_options['relationships']['field_file_fid']['field'] = 'field_file_fid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Publication Type */
  $handler->display->display_options['fields']['field_publication_type']['id'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['table'] = 'field_data_field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['field'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['label'] = 'publication_type';
  $handler->display->display_options['fields']['field_publication_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'title';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Cover image */
  $handler->display->display_options['fields']['field_cover_image']['id'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['table'] = 'field_data_field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['field'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['label'] = 'cover_image';
  $handler->display->display_options['fields']['field_cover_image']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cover_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cover_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cover_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Cover image */
  $handler->display->display_options['fields']['field_cover_image_1']['id'] = 'field_cover_image_1';
  $handler->display->display_options['fields']['field_cover_image_1']['table'] = 'field_data_field_cover_image';
  $handler->display->display_options['fields']['field_cover_image_1']['field'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image_1']['label'] = 'cover_image_thumbnail';
  $handler->display->display_options['fields']['field_cover_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cover_image_1']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Field: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = 'publication_date';
  $handler->display->display_options['fields']['field_publication_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Expiration date */
  $handler->display->display_options['fields']['field_expiration_date']['id'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['field'] = 'field_expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['label'] = 'expiration_date';
  $handler->display->display_options['fields']['field_expiration_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Field: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = 'tags';
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['separator'] = '\\n';
  /* Field: Field: Thesaurus */
  $handler->display->display_options['fields']['field_thesaurus']['id'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['table'] = 'field_data_field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['field'] = 'field_thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['label'] = 'thesaurus';
  $handler->display->display_options['fields']['field_thesaurus']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_thesaurus']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thesaurus']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_thesaurus']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_thesaurus']['separator'] = '\\n';
  /* Field: Field: Nace */
  $handler->display->display_options['fields']['field_nace_codes']['id'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['table'] = 'field_data_field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['field'] = 'field_nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['label'] = 'nace_codes';
  $handler->display->display_options['fields']['field_nace_codes']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_nace_codes']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_nace_codes']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_nace_codes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_nace_codes']['separator'] = '\\n';
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['label'] = 'author';
  /* Field: Content: Bookshop ID */
  $handler->display->display_options['fields']['field_publication_bookshop_id']['id'] = 'field_publication_bookshop_id';
  $handler->display->display_options['fields']['field_publication_bookshop_id']['table'] = 'field_data_field_publication_bookshop_id';
  $handler->display->display_options['fields']['field_publication_bookshop_id']['field'] = 'field_publication_bookshop_id';
  /* Field: Content: File */
  $handler->display->display_options['fields']['field_file']['id'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['table'] = 'field_data_field_file';
  $handler->display->display_options['fields']['field_file']['field'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['label'] = 'file';
  $handler->display->display_options['fields']['field_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_file']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file']['type'] = 'file_url_plain';
  /* Field: Content: Resources (files) */
  $handler->display->display_options['fields']['field_publication_related_res']['id'] = 'field_publication_related_res';
  $handler->display->display_options['fields']['field_publication_related_res']['table'] = 'field_data_field_publication_related_res';
  $handler->display->display_options['fields']['field_publication_related_res']['field'] = 'field_publication_related_res';
  $handler->display->display_options['fields']['field_publication_related_res']['label'] = 'resources';
  $handler->display->display_options['fields']['field_publication_related_res']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_publication_related_res']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_publication_related_res']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_publication_related_res']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_publication_related_res']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_publication_related_res']['separator'] = '\\n';
  /* Field: Content: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['label'] = 'activity';
  $handler->display->display_options['fields']['field_activity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_activity']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_activity']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity']['separator'] = '\\n';
  /* Field: File: Size */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['relationship'] = 'field_file_fid';
  $handler->display->display_options['fields']['filesize']['label'] = 'file_size';
  /* Field: File: Mime type */
  $handler->display->display_options['fields']['filemime_1']['id'] = 'filemime_1';
  $handler->display->display_options['fields']['filemime_1']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filemime_1']['field'] = 'filemime';
  $handler->display->display_options['fields']['filemime_1']['relationship'] = 'field_file_fid';
  $handler->display->display_options['fields']['filemime_1']['label'] = 'mime_type';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'publication' => 'publication',
  );
  /* Filter criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: File (field_file:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_file';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'services/hw/publications1';
  $translatables['data_export'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('term from field_tags'),
    t('path'),
    t('nid'),
    t('title'),
    t('summary'),
    t('image'),
    t('publication_date'),
    t('expiration_date'),
    t('body'),
    t('tags'),
    t('thesaurus'),
    t('activity'),
    t('post_date'),
    t('pr_embargo_date'),
    t('nace_codes'),
    t('All'),
    t('News'),
    t('Events'),
    t('organization'),
    t('country'),
    t('country_code'),
    t('City'),
    t('start_date'),
    t('end_date'),
    t('for_the_web'),
    t('website_of_event'),
    t('category'),
    t('adonis'),
    t('unit_ref'),
    t('agency_role'),
    t('agency_initial_contact'),
    t('agency_rep_confirmed'),
    t('organised_by'),
    t('satisfaction_rate'),
    t('event_in_amp'),
    t('agency_contact_reply'),
    t('comments_summary_after_eve'),
    t('number_of_attendees'),
    t('related_documents'),
    t('color'),
    t('Press releases'),
    t('Publications'),
    t('file from field_file'),
    t('publication_type'),
    t('cover_image'),
    t('cover_image_thumbnail'),
    t('author'),
    t('Bookshop ID'),
    t('file'),
    t('resources'),
    t('file_size'),
    t('file_mime_type'),
    t('News - single item'),
    t('Events - single item'),
    t('Press releases - single item'),
    t('Publications - single item'),
    t('mime_type'),
  );
  $export['data_export'] = $view;

  $view = new view();
  $view->name = 'hcw_data_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'HWC Data Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'HWC Data Export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'items';
  $handler->display->display_options['style_options']['top_child_object'] = 'item';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 1;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Relationship: Field: Tags (field_tags) */
  $handler->display->display_options['relationships']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['relationships']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Contextual filter: Content: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  /* Contextual filter: Taxonomy term: Code (field_tags_code) */
  $handler->display->display_options['arguments']['field_tags_code_value']['id'] = 'field_tags_code_value';
  $handler->display->display_options['arguments']['field_tags_code_value']['table'] = 'field_data_field_tags_code';
  $handler->display->display_options['arguments']['field_tags_code_value']['field'] = 'field_tags_code_value';
  $handler->display->display_options['arguments']['field_tags_code_value']['relationship'] = 'field_tags_tid';
  $handler->display->display_options['arguments']['field_tags_code_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_tags_code_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tags_code_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tags_code_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tags_code_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_tags_code_value']['limit'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'export/list';

  /* Display: Note to editor */
  $handler = $view->new_display('page', 'Note to editor', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'HCW Data Export - Note to editor';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'note_to_editor' => 'note_to_editor',
  );
  $handler->display->display_options['path'] = 'export/notetoeditor';

  /* Display: Press Contact */
  $handler = $view->new_display('page', 'Press Contact', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'HCW Data Export - Press Contact';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'press_contact' => 'press_contact',
  );
  /* Filter criterion: Content: Type (field_contact_type) */
  $handler->display->display_options['filters']['field_contact_type_tid']['id'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['filters']['field_contact_type_tid']['field'] = 'field_contact_type_tid';
  $handler->display->display_options['filters']['field_contact_type_tid']['value'] = array(
    2969 => '2969',
  );
  $handler->display->display_options['filters']['field_contact_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_contact_type_tid']['vocabulary'] = 'contact_type';
  $handler->display->display_options['filters']['field_contact_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'export/presscontact';

  /* Display: Additional resources */
  $handler = $view->new_display('page', 'Additional resources', 'page_3');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_aditional_resources_node']['id'] = 'reverse_field_aditional_resources_node';
  $handler->display->display_options['relationships']['reverse_field_aditional_resources_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_aditional_resources_node']['field'] = 'reverse_field_aditional_resources_node';
  $handler->display->display_options['relationships']['reverse_field_aditional_resources_node']['required'] = TRUE;
  /* Relationship: Field: Tags (field_tags) */
  $handler->display->display_options['relationships']['field_tags_tid_1']['id'] = 'field_tags_tid_1';
  $handler->display->display_options['relationships']['field_tags_tid_1']['table'] = 'field_data_field_tags';
  $handler->display->display_options['relationships']['field_tags_tid_1']['field'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid_1']['relationship'] = 'reverse_field_aditional_resources_node';
  $handler->display->display_options['relationships']['field_tags_tid_1']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Code (field_tags_code) */
  $handler->display->display_options['arguments']['field_tags_code_value']['id'] = 'field_tags_code_value';
  $handler->display->display_options['arguments']['field_tags_code_value']['table'] = 'field_data_field_tags_code';
  $handler->display->display_options['arguments']['field_tags_code_value']['field'] = 'field_tags_code_value';
  $handler->display->display_options['arguments']['field_tags_code_value']['relationship'] = 'field_tags_tid_1';
  $handler->display->display_options['arguments']['field_tags_code_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_tags_code_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tags_code_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tags_code_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tags_code_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_tags_code_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_aditional_resources_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'highlight' => 'highlight',
    'news' => 'news',
    'press_release' => 'press_release',
    'publication' => 'publication',
  );
  $handler->display->display_options['path'] = 'export/list-additional-resources/%';
  $translatables['hcw_data_export'] = array(
    t('Master'),
    t('HWC Data Export'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('term from field_tags'),
    t('All'),
    t('Page'),
    t('Note to editor'),
    t('HCW Data Export - Note to editor'),
    t('Press Contact'),
    t('HCW Data Export - Press Contact'),
    t('Additional resources'),
    t('Content referencing Content from field_aditional_resources'),
  );
  $export['hcw_data_export'] = $view;

  $view = new view();
  $view->name = 'hcw_taxonomy_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'HCW taxonomy export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'HCW taxonomy export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'items';
  $handler->display->display_options['style_options']['top_child_object'] = 'item';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 1;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'tid';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Contextual filter: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['arguments']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['arguments']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['machine_name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['machine_name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['machine_name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['machine_name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['machine_name']['limit'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'export/taxonomy';
  $translatables['hcw_taxonomy_export'] = array(
    t('Master'),
    t('HCW taxonomy export'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('tid'),
    t('.'),
    t('All'),
    t('Page'),
  );
  $export['hcw_taxonomy_export'] = $view;

  return $export;
}
