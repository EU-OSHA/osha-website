<?php
/**
 * @file
 * osha_newsletter.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_newsletter_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'newsletter_node_selection';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Newsletter node selection';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Newsletter content selection';
  $handler->display->display_options['css_class'] = 'newsletter_node_selection_view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage content in newsletter_content_collection entity collections';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 100, 200';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
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
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a class="form-submit" href="/admin/structure/entity_collection/add/newsletter_content_collection">Create another newsletter</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
    'contact_topic' => 0,
    'contact_type_of_sender' => 0,
    'flickr_tags' => 0,
    'newsletter_sections' => 0,
    'organised_by' => 0,
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
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['skip_batching'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_add_to_newsletter' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Type of content';
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
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
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
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
    'events' => 'events',
    'highlight' => 'highlight',
    'news' => 'news',
    'newsletter_article' => 'newsletter_article',
    'press_release' => 'press_release',
    'publication' => 'publication',
    'wiki_page' => 'wiki_page',
    'youtube' => 'youtube',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type of content';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['required'] = TRUE;
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
    13 => 0,
    14 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
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
    12 => 0,
  );

  /* Display: Newsletter content selection */
  $handler = $view->new_display('page', 'Newsletter content selection', 'newsletter_selection_view_page');
  $handler->display->display_options['path'] = 'admin/newsletter/content_selection';
  $handler->display->display_options['menu']['title'] = 'OSHA content';
  $handler->display->display_options['menu']['weight'] = '-30';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['newsletter_node_selection'] = array(
    t('Master'),
    t('Newsletter content selection'),
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
    t('<a class="form-submit" href="/admin/structure/entity_collection/add/newsletter_content_collection">Create another newsletter</a>'),
    t('There are no results. Please broaden your filters above.'),
    t('author'),
    t('term'),
    t('Translations'),
    t('Get the actual content from a content revision.'),
    t('- Choose an operation -'),
    t('Title'),
    t('Type of content'),
    t('Author'),
    t('Updated'),
    t('Published'),
    t('Edit'),
    t('Post date'),
    t('Updated date'),
    t('Author name'),
    t('Type'),
    t('Node ID'),
    t('Activity'),
    t('Activity (field_activity)'),
    t('Nace Codes'),
    t('Thesaurus'),
    t('Enter name or part of author\'s name'),
    t('Select an interval for filtering'),
    t('Vocabulary'),
  );
  $export['newsletter_node_selection'] = $view;

  $view = new view();
  $view->name = 'newsletters_overview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entity_collection_collections';
  $view->human_name = 'Newsletters overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'List of newsletters';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage content in newsletter_content_collection entity collections';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'rendered_entity_2' => 'rendered_entity_2',
    'rendered_entity' => 'rendered_entity',
    'field_newsletter_sent' => 'field_newsletter_sent',
    'field_publication_date' => 'field_publication_date',
    'field_created' => 'field_created',
    'field_newsletter_author' => 'field_newsletter_author',
    'rendered_entity_1' => 'rendered_entity_1',
  );
  $handler->display->display_options['style_options']['default'] = 'field_publication_date';
  $handler->display->display_options['style_options']['info'] = array(
    'rendered_entity_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rendered_entity' => array(
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_newsletter_sent' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_publication_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_newsletter_author' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rendered_entity_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p>
<a href="/admin/structure/entity_collection/add/newsletter_content_collection">Create newsletter</a>
</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Entity Collection: Rendered Entity Collection */
  $handler->display->display_options['fields']['rendered_entity_2']['id'] = 'rendered_entity_2';
  $handler->display->display_options['fields']['rendered_entity_2']['table'] = 'views_entity_entity_collection';
  $handler->display->display_options['fields']['rendered_entity_2']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity_2']['label'] = 'ID';
  $handler->display->display_options['fields']['rendered_entity_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_2']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity_2']['display'] = 'id';
  $handler->display->display_options['fields']['rendered_entity_2']['view_mode'] = 'block';
  $handler->display->display_options['fields']['rendered_entity_2']['bypass_access'] = 0;
  /* Field: Entity Collection: Rendered Entity Collection */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_entity_collection';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = 'Title';
  $handler->display->display_options['fields']['rendered_entity']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity']['alter']['path'] = 'entity-collection/[rendered_entity_2]';
  $handler->display->display_options['fields']['rendered_entity']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'block';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Entity Collection: Newsletter sent? */
  $handler->display->display_options['fields']['field_newsletter_sent']['id'] = 'field_newsletter_sent';
  $handler->display->display_options['fields']['field_newsletter_sent']['table'] = 'field_data_field_newsletter_sent';
  $handler->display->display_options['fields']['field_newsletter_sent']['field'] = 'field_newsletter_sent';
  $handler->display->display_options['fields']['field_newsletter_sent']['label'] = 'Was sent?';
  /* Field: Field: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Entity Collection: Created */
  $handler->display->display_options['fields']['field_created']['id'] = 'field_created';
  $handler->display->display_options['fields']['field_created']['table'] = 'field_data_field_created';
  $handler->display->display_options['fields']['field_created']['field'] = 'field_created';
  $handler->display->display_options['fields']['field_created']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Entity Collection: Author */
  $handler->display->display_options['fields']['field_newsletter_author']['id'] = 'field_newsletter_author';
  $handler->display->display_options['fields']['field_newsletter_author']['table'] = 'field_data_field_newsletter_author';
  $handler->display->display_options['fields']['field_newsletter_author']['field'] = 'field_newsletter_author';
  $handler->display->display_options['fields']['field_newsletter_author']['settings'] = array(
    'link' => 0,
  );
  /* Field: Entity Collection: Rendered Entity Collection */
  $handler->display->display_options['fields']['rendered_entity_1']['id'] = 'rendered_entity_1';
  $handler->display->display_options['fields']['rendered_entity_1']['table'] = 'views_entity_entity_collection';
  $handler->display->display_options['fields']['rendered_entity_1']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity_1']['label'] = 'Actions';
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['text'] = '<a href="/entity-collection/[rendered_entity_1]/content">Manage content</a> | <a href="/entity-collection/[rendered_entity_1]/edit">Settings</a> | <a href="/entity-collection/[rendered_entity_1]/delete">Delete</a>';
  $handler->display->display_options['fields']['rendered_entity_1']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['display'] = 'id';
  $handler->display->display_options['fields']['rendered_entity_1']['view_mode'] = 'block';
  $handler->display->display_options['fields']['rendered_entity_1']['bypass_access'] = 0;
  /* Filter criterion: Entity Collection: Newsletter sent? (field_newsletter_sent) */
  $handler->display->display_options['filters']['field_newsletter_sent_value']['id'] = 'field_newsletter_sent_value';
  $handler->display->display_options['filters']['field_newsletter_sent_value']['table'] = 'field_data_field_newsletter_sent';
  $handler->display->display_options['filters']['field_newsletter_sent_value']['field'] = 'field_newsletter_sent_value';
  $handler->display->display_options['filters']['field_newsletter_sent_value']['value'] = array(
    0 => '0',
    1 => '1',
  );

  /* Display: List of newsletters */
  $handler = $view->new_display('page', 'List of newsletters', 'page');
  $handler->display->display_options['path'] = 'admin/content/newsletter';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Newsletter';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['newsletters_overview'] = array(
    t('Master'),
    t('List of newsletters'),
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
    t('<p>
<a href="/admin/structure/entity_collection/add/newsletter_content_collection">Create newsletter</a>
</p>'),
    t('ID'),
    t('Title'),
    t('Was sent?'),
    t('Publication date'),
    t('Created'),
    t('Author'),
    t('Actions'),
    t('<a href="/entity-collection/[rendered_entity_1]/content">Manage content</a> | <a href="/entity-collection/[rendered_entity_1]/edit">Settings</a> | <a href="/entity-collection/[rendered_entity_1]/delete">Delete</a>'),
  );
  $export['newsletters_overview'] = $view;

  return $export;
}
