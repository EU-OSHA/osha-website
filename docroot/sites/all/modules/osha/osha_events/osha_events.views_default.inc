<?php
/**
 * @file
 * osha_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    7 => '7',
    11 => '11',
    4 => '4',
    12 => '12',
    13 => '13',
    6 => '6',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: For the web / Public */
  $handler->display->display_options['fields']['field_for_the_web']['id'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['table'] = 'field_data_field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['field'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['element_label_colon'] = FALSE;
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = 'Country code';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Website of event */
  $handler->display->display_options['fields']['field_website_of_event']['id'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['table'] = 'field_data_field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['field'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_of_event']['click_sort_column'] = 'url';
  /* Field: Content: Ares/Adonis */
  $handler->display->display_options['fields']['field_adonis']['id'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['table'] = 'field_data_field_adonis';
  $handler->display->display_options['fields']['field_adonis']['field'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['element_label_colon'] = FALSE;
  /* Field: Content: Unit Ref */
  $handler->display->display_options['fields']['field_unit_ref']['id'] = 'field_unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['table'] = 'field_data_field_unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['field'] = 'field_unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['element_label_colon'] = FALSE;
  /* Field: Content: Agency role */
  $handler->display->display_options['fields']['field_agency_role']['id'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['table'] = 'field_data_field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['field'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_role']['delta_offset'] = '0';
  /* Field: Content: Agency initial contact */
  $handler->display->display_options['fields']['field_agency_initial_contact']['id'] = 'field_agency_initial_contact';
  $handler->display->display_options['fields']['field_agency_initial_contact']['table'] = 'field_data_field_agency_initial_contact';
  $handler->display->display_options['fields']['field_agency_initial_contact']['field'] = 'field_agency_initial_contact';
  $handler->display->display_options['fields']['field_agency_initial_contact']['element_label_colon'] = FALSE;
  /* Field: Content: Agency rep confirmed */
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['id'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['table'] = 'field_data_field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['field'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['element_label_colon'] = FALSE;
  /* Field: Content: Organized by EU-OSHA */
  $handler->display->display_options['fields']['field_organized_by_eu_osha']['id'] = 'field_organized_by_eu_osha';
  $handler->display->display_options['fields']['field_organized_by_eu_osha']['table'] = 'field_data_field_organized_by_eu_osha';
  $handler->display->display_options['fields']['field_organized_by_eu_osha']['field'] = 'field_organized_by_eu_osha';
  $handler->display->display_options['fields']['field_organized_by_eu_osha']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organized_by_eu_osha']['type'] = 'boolean_yes_no';
  $handler->display->display_options['fields']['field_organized_by_eu_osha']['settings'] = array(
    'format' => 'yes-no',
    'custom_on' => '',
    'custom_off' => '',
    'reverse' => 0,
  );
  /* Field: Content: Event in AMP */
  $handler->display->display_options['fields']['field_event_in_amp']['id'] = 'field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['table'] = 'field_data_field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['field'] = 'field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['element_label_colon'] = FALSE;
  /* Field: Content: Agency contact / reply */
  $handler->display->display_options['fields']['field_agency_contact_reply']['id'] = 'field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['table'] = 'field_data_field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['field'] = 'field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['element_label_colon'] = FALSE;
  /* Field: Content: Comments */
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['id'] = 'field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['table'] = 'field_data_field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['field'] = 'field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['element_label_colon'] = FALSE;
  /* Field: Content: Number of attendees */
  $handler->display->display_options['fields']['field_number_of_attendees']['id'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['table'] = 'field_data_field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['field'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_number_of_attendees']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Satisfaction rate */
  $handler->display->display_options['fields']['field_satisfaction_rate']['id'] = 'field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['table'] = 'field_data_field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['field'] = 'field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_satisfaction_rate']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Date -  start date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );

  /* Display: Events */
  $handler = $view->new_display('page', 'Events', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 50, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_for_the_web' => 'field_for_the_web',
    'field_activity' => 'field_activity',
    'field_event_type' => 'field_event_type',
    'field_organization' => 'field_organization',
    'title_field' => 'title_field',
    'field_country_code' => 'field_country_code',
    'field_city' => 'field_city',
    'field_start_date' => 'field_start_date',
    'field_start_date_1' => 'field_start_date_1',
    'field_website_of_event' => 'field_website_of_event',
    'field_agenda' => 'field_agenda',
    'field_agency_role' => 'field_agency_role',
    'field_agency_rep_confirmed' => 'field_agency_rep_confirmed',
    'field_publications_exhibition_su' => 'field_publications_exhibition_su',
    'field_media_promotion' => 'field_media_promotion',
    'field_comments_summary_after_eve' => 'field_comments_summary_after_eve',
    'field_key_performance' => 'field_key_performance',
    'field_adonis' => 'field_adonis',
    'field_number_of_attendees' => 'field_number_of_attendees',
    'name' => 'name',
    'status' => 'status',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_for_the_web' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_event_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organization' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_country_code' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_start_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_start_date_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_website_of_event' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agenda' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agency_role' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agency_rep_confirmed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_publications_exhibition_su' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_media_promotion' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_comments_summary_after_eve' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_key_performance' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_adonis' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_number_of_attendees' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
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
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p>
<a href="/en/node/add/events">Add event</a>
</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Total: @total';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'Colours';
  $handler->display->display_options['header']['area_1']['empty'] = TRUE;
  $handler->display->display_options['header']['area_1']['content'] = '<div class="colours">
<div class="red"></div><p">TBD - TBC<p>
<div class="black"></div><p>Confirmed<p>
<div class="grey"></div><p>Only web or not attendance<p>
</div>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '<span class="result_summary">Displaying @start - @end of @total</span>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Color */
  $handler->display->display_options['fields']['field_color']['id'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['table'] = 'field_data_field_color';
  $handler->display->display_options['fields']['field_color']['field'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['alter']['text'] = '[field_color]';
  $handler->display->display_options['fields']['field_color']['element_label_colon'] = FALSE;
  /* Field: Content: For the web / Public */
  $handler->display->display_options['fields']['field_for_the_web']['id'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['table'] = 'field_data_field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['field'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['element_label_colon'] = FALSE;
  /* Field: Content: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_event_type']['id'] = 'field_event_type';
  $handler->display->display_options['fields']['field_event_type']['table'] = 'field_data_field_event_type';
  $handler->display->display_options['fields']['field_event_type']['field'] = 'field_event_type';
  $handler->display->display_options['fields']['field_event_type']['label'] = 'Type of event';
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = 'Start date';
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'osha_date_theme' => '',
  );
  /* Field: Event end date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['ui_name'] = 'Event end date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = 'End date';
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'osha_date_theme' => '',
  );
  /* Field: Content: Website of event */
  $handler->display->display_options['fields']['field_website_of_event']['id'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['table'] = 'field_data_field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['field'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_of_event']['click_sort_column'] = 'url';
  /* Field: Content: Agenda */
  $handler->display->display_options['fields']['field_agenda']['id'] = 'field_agenda';
  $handler->display->display_options['fields']['field_agenda']['table'] = 'field_data_field_agenda';
  $handler->display->display_options['fields']['field_agenda']['field'] = 'field_agenda';
  /* Field: Content: Agency role */
  $handler->display->display_options['fields']['field_agency_role']['id'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['table'] = 'field_data_field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['field'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_role']['delta_offset'] = '0';
  /* Field: Content: Agency rep confirmed */
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['id'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['table'] = 'field_data_field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['field'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['element_label_colon'] = FALSE;
  /* Field: Content: Publications/exhibition support */
  $handler->display->display_options['fields']['field_publications_exhibition_su']['id'] = 'field_publications_exhibition_su';
  $handler->display->display_options['fields']['field_publications_exhibition_su']['table'] = 'field_data_field_publications_exhibition_su';
  $handler->display->display_options['fields']['field_publications_exhibition_su']['field'] = 'field_publications_exhibition_su';
  /* Field: Content: Media/promotion */
  $handler->display->display_options['fields']['field_media_promotion']['id'] = 'field_media_promotion';
  $handler->display->display_options['fields']['field_media_promotion']['table'] = 'field_data_field_media_promotion';
  $handler->display->display_options['fields']['field_media_promotion']['field'] = 'field_media_promotion';
  /* Field: Content: Comments */
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['id'] = 'field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['table'] = 'field_data_field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['field'] = 'field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['element_label_colon'] = FALSE;
  /* Field: Content: Key Performance Indicator */
  $handler->display->display_options['fields']['field_key_performance']['id'] = 'field_key_performance';
  $handler->display->display_options['fields']['field_key_performance']['table'] = 'field_data_field_key_performance';
  $handler->display->display_options['fields']['field_key_performance']['field'] = 'field_key_performance';
  /* Field: Content: Ares/Adonis */
  $handler->display->display_options['fields']['field_adonis']['id'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['table'] = 'field_data_field_adonis';
  $handler->display->display_options['fields']['field_adonis']['field'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['element_label_colon'] = FALSE;
  /* Field: Content: Number of attendees */
  $handler->display->display_options['fields']['field_number_of_attendees']['id'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['table'] = 'field_data_field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['field'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['label'] = 'Number of participants';
  $handler->display->display_options['fields']['field_number_of_attendees']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_number_of_attendees']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Created by';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul class="links inline">
<li>[edit_node]</li>
<li>[delete_node]</li>
</ul>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Color (field_color) */
  $handler->display->display_options['filters']['field_color_value']['id'] = 'field_color_value';
  $handler->display->display_options['filters']['field_color_value']['table'] = 'field_data_field_color';
  $handler->display->display_options['filters']['field_color_value']['field'] = 'field_color_value';
  $handler->display->display_options['filters']['field_color_value']['group'] = 1;
  $handler->display->display_options['filters']['field_color_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_color_value']['expose']['operator_id'] = 'field_color_value_op';
  $handler->display->display_options['filters']['field_color_value']['expose']['label'] = 'Color';
  $handler->display->display_options['filters']['field_color_value']['expose']['operator'] = 'field_color_value_op';
  $handler->display->display_options['filters']['field_color_value']['expose']['identifier'] = 'field_color_value';
  $handler->display->display_options['filters']['field_color_value']['expose']['remember_roles'] = array(
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
    12 => 0,
    13 => 0,
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
  /* Filter criterion: Content: Organization (field_organization) */
  $handler->display->display_options['filters']['field_organization_value']['id'] = 'field_organization_value';
  $handler->display->display_options['filters']['field_organization_value']['table'] = 'field_data_field_organization';
  $handler->display->display_options['filters']['field_organization_value']['field'] = 'field_organization_value';
  $handler->display->display_options['filters']['field_organization_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_organization_value']['group'] = 1;
  $handler->display->display_options['filters']['field_organization_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organization_value']['expose']['operator_id'] = 'field_organization_value_op';
  $handler->display->display_options['filters']['field_organization_value']['expose']['label'] = 'Organization';
  $handler->display->display_options['filters']['field_organization_value']['expose']['operator'] = 'field_organization_value_op';
  $handler->display->display_options['filters']['field_organization_value']['expose']['identifier'] = 'field_organization_value';
  $handler->display->display_options['filters']['field_organization_value']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Content: Country (field_country_code) */
  $handler->display->display_options['filters']['field_country_code_value']['id'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['filters']['field_country_code_value']['field'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['group'] = 1;
  $handler->display->display_options['filters']['field_country_code_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_country_code_value']['expose']['operator_id'] = 'field_country_code_value_op';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['operator'] = 'field_country_code_value_op';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['identifier'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Content: City (field_city) */
  $handler->display->display_options['filters']['field_city_value']['id'] = 'field_city_value';
  $handler->display->display_options['filters']['field_city_value']['table'] = 'field_data_field_city';
  $handler->display->display_options['filters']['field_city_value']['field'] = 'field_city_value';
  $handler->display->display_options['filters']['field_city_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_city_value']['group'] = 1;
  $handler->display->display_options['filters']['field_city_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_city_value']['expose']['operator_id'] = 'field_city_value_op';
  $handler->display->display_options['filters']['field_city_value']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_city_value']['expose']['operator'] = 'field_city_value_op';
  $handler->display->display_options['filters']['field_city_value']['expose']['identifier'] = 'field_city_value';
  $handler->display->display_options['filters']['field_city_value']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Content: Date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator_id'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['label'] = 'Start date';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['identifier'] = 'field_start_date_value';
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
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Date - end date (field_start_date:value2) */
  $handler->display->display_options['filters']['field_start_date_value2']['id'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value2']['field'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['operator'] = '<=';
  $handler->display->display_options['filters']['field_start_date_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_start_date_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator_id'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['label'] = 'End date';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['identifier'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_start_date_value2']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Ares/Adonis (field_adonis) */
  $handler->display->display_options['filters']['field_adonis_value']['id'] = 'field_adonis_value';
  $handler->display->display_options['filters']['field_adonis_value']['table'] = 'field_data_field_adonis';
  $handler->display->display_options['filters']['field_adonis_value']['field'] = 'field_adonis_value';
  $handler->display->display_options['filters']['field_adonis_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_adonis_value']['group'] = 1;
  $handler->display->display_options['filters']['field_adonis_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_adonis_value']['expose']['operator_id'] = 'field_adonis_value_op';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['label'] = 'Ares/Adonis';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['operator'] = 'field_adonis_value_op';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['identifier'] = 'field_adonis_value';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['remember_roles'] = array(
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
    12 => 0,
  );
  $handler->display->display_options['filters']['field_activity_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_tid']['vocabulary'] = 'activity';
  $handler->display->display_options['filters']['field_activity_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Agency role (field_agency_role) */
  $handler->display->display_options['filters']['field_agency_role_value']['id'] = 'field_agency_role_value';
  $handler->display->display_options['filters']['field_agency_role_value']['table'] = 'field_data_field_agency_role';
  $handler->display->display_options['filters']['field_agency_role_value']['field'] = 'field_agency_role_value';
  $handler->display->display_options['filters']['field_agency_role_value']['group'] = 1;
  $handler->display->display_options['filters']['field_agency_role_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['operator_id'] = 'field_agency_role_value_op';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['label'] = 'Agency role';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['operator'] = 'field_agency_role_value_op';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['identifier'] = 'field_agency_role_value';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Agenda (field_agenda) */
  $handler->display->display_options['filters']['field_agenda_value']['id'] = 'field_agenda_value';
  $handler->display->display_options['filters']['field_agenda_value']['table'] = 'field_data_field_agenda';
  $handler->display->display_options['filters']['field_agenda_value']['field'] = 'field_agenda_value';
  $handler->display->display_options['filters']['field_agenda_value']['group'] = 1;
  $handler->display->display_options['filters']['field_agenda_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agenda_value']['expose']['operator_id'] = 'field_agenda_value_op';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['label'] = 'Agenda';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['operator'] = 'field_agenda_value_op';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['identifier'] = 'field_agenda_value';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Publications/exhibition support (field_publications_exhibition_su) */
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['id'] = 'field_publications_exhibition_su_value';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['table'] = 'field_data_field_publications_exhibition_su';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['field'] = 'field_publications_exhibition_su_value';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['group'] = 1;
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['operator_id'] = 'field_publications_exhibition_su_value_op';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['label'] = 'Publications/exhibition support';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['operator'] = 'field_publications_exhibition_su_value_op';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['identifier'] = 'field_publications_exhibition_su_value';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Media/promotion (field_media_promotion) */
  $handler->display->display_options['filters']['field_media_promotion_value']['id'] = 'field_media_promotion_value';
  $handler->display->display_options['filters']['field_media_promotion_value']['table'] = 'field_data_field_media_promotion';
  $handler->display->display_options['filters']['field_media_promotion_value']['field'] = 'field_media_promotion_value';
  $handler->display->display_options['filters']['field_media_promotion_value']['group'] = 1;
  $handler->display->display_options['filters']['field_media_promotion_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['operator_id'] = 'field_media_promotion_value_op';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['label'] = 'Media/promotion';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['operator'] = 'field_media_promotion_value_op';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['identifier'] = 'field_media_promotion_value';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Key Performance Indicator (field_key_performance) */
  $handler->display->display_options['filters']['field_key_performance_value']['id'] = 'field_key_performance_value';
  $handler->display->display_options['filters']['field_key_performance_value']['table'] = 'field_data_field_key_performance';
  $handler->display->display_options['filters']['field_key_performance_value']['field'] = 'field_key_performance_value';
  $handler->display->display_options['filters']['field_key_performance_value']['group'] = 1;
  $handler->display->display_options['filters']['field_key_performance_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['operator_id'] = 'field_key_performance_value_op';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['label'] = 'Key Performance Indicator';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['operator'] = 'field_key_performance_value_op';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['identifier'] = 'field_key_performance_value';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Agency rep confirmed (field_agency_rep_confirmed) */
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['id'] = 'field_agency_rep_confirmed_value';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['table'] = 'field_data_field_agency_rep_confirmed';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['field'] = 'field_agency_rep_confirmed_value';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['group'] = 1;
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['operator_id'] = 'field_agency_rep_confirmed_value_op';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['label'] = 'Agency rep confirmed';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['operator'] = 'field_agency_rep_confirmed_value_op';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['identifier'] = 'field_agency_rep_confirmed_value';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Content: Type (field_event_type) */
  $handler->display->display_options['filters']['field_event_type_value']['id'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['table'] = 'field_data_field_event_type';
  $handler->display->display_options['filters']['field_event_type_value']['field'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_type_value']['expose']['operator_id'] = 'field_event_type_value_op';
  $handler->display->display_options['filters']['field_event_type_value']['expose']['label'] = 'Type of event';
  $handler->display->display_options['filters']['field_event_type_value']['expose']['operator'] = 'field_event_type_value_op';
  $handler->display->display_options['filters']['field_event_type_value']['expose']['identifier'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Migration Source (field_migration_source) */
  $handler->display->display_options['filters']['field_migration_source_value']['id'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['table'] = 'field_data_field_migration_source';
  $handler->display->display_options['filters']['field_migration_source_value']['field'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_migration_source_value']['value'] = array(
    'hwc' => 'hwc',
  );
  $handler->display->display_options['filters']['field_migration_source_value']['group'] = 1;
  $handler->display->display_options['filters']['field_migration_source_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['operator_id'] = 'field_migration_source_value_op';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['label'] = 'Not from';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['operator'] = 'field_migration_source_value_op';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['identifier'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['group_info']['label'] = 'Source';
  $handler->display->display_options['filters']['field_migration_source_value']['group_info']['identifier'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'HWC',
      'operator' => 'or',
      'value' => array(
        'hwc' => 'hwc',
      ),
    ),
    2 => array(
      'title' => 'Osha',
      'operator' => 'empty',
      'value' => array(
        'hwc' => 'hwc',
      ),
    ),
  );
  /* Filter criterion: Content: For the web / Public (field_for_the_web) */
  $handler->display->display_options['filters']['field_for_the_web_value']['id'] = 'field_for_the_web_value';
  $handler->display->display_options['filters']['field_for_the_web_value']['table'] = 'field_data_field_for_the_web';
  $handler->display->display_options['filters']['field_for_the_web_value']['field'] = 'field_for_the_web_value';
  $handler->display->display_options['filters']['field_for_the_web_value']['group'] = 1;
  $handler->display->display_options['filters']['field_for_the_web_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['operator_id'] = 'field_for_the_web_value_op';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['label'] = 'For the web';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['operator'] = 'field_for_the_web_value_op';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['identifier'] = 'field_for_the_web_value';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_for_the_web_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field: Tags (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator_id'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['label'] = 'Tag';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['identifier'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['path'] = 'admin/content/events';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_start_date_1',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-list wysiwyg_accordion';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = 'Location';
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Start date for grouping */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['ui_name'] = 'Start date for grouping';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['alter']['text'] = '[field_start_date_1] - Events';
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['order'] = 'DESC';
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

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'events.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: For the web */
  $handler->display->display_options['fields']['field_for_the_web']['id'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['table'] = 'field_data_field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['field'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['ui_name'] = 'For the web';
  $handler->display->display_options['fields']['field_for_the_web']['element_label_colon'] = FALSE;
  /* Field: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['ui_name'] = 'Activity';
  $handler->display->display_options['fields']['field_activity']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_activity']['delta_offset'] = '0';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_event_type']['id'] = 'field_event_type';
  $handler->display->display_options['fields']['field_event_type']['table'] = 'field_data_field_event_type';
  $handler->display->display_options['fields']['field_event_type']['field'] = 'field_event_type';
  $handler->display->display_options['fields']['field_event_type']['label'] = 'Type of event';
  /* Field: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['ui_name'] = 'Organization';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['ui_name'] = 'Country';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  /* Field: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['ui_name'] = 'City';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Event date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['ui_name'] = 'Event date';
  $handler->display->display_options['fields']['field_start_date']['label'] = 'Start date';
  $handler->display->display_options['fields']['field_start_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_start_date']['alter']['text'] = '[field_start_date-value]';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Event end date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['ui_name'] = 'Event end date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = 'End date';
  $handler->display->display_options['fields']['field_start_date_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['alter']['text'] = '[field_start_date_1-value2]';
  $handler->display->display_options['fields']['field_start_date_1']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Website of event */
  $handler->display->display_options['fields']['field_website_of_event']['id'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['table'] = 'field_data_field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['field'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['ui_name'] = 'Website of event';
  $handler->display->display_options['fields']['field_website_of_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_of_event']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website_of_event']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_website_of_event']['delta_offset'] = '0';
  /* Field: Content: Agenda */
  $handler->display->display_options['fields']['field_agenda']['id'] = 'field_agenda';
  $handler->display->display_options['fields']['field_agenda']['table'] = 'field_data_field_agenda';
  $handler->display->display_options['fields']['field_agenda']['field'] = 'field_agenda';
  /* Field: Agency role */
  $handler->display->display_options['fields']['field_agency_role']['id'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['table'] = 'field_data_field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['field'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['ui_name'] = 'Agency role';
  $handler->display->display_options['fields']['field_agency_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_role']['delta_offset'] = '0';
  /* Field: Agency rep confirmed */
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['id'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['table'] = 'field_data_field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['field'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['ui_name'] = 'Agency rep confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['element_label_colon'] = FALSE;
  /* Field: Content: Publications/exhibition support */
  $handler->display->display_options['fields']['field_publications_exhibition_su']['id'] = 'field_publications_exhibition_su';
  $handler->display->display_options['fields']['field_publications_exhibition_su']['table'] = 'field_data_field_publications_exhibition_su';
  $handler->display->display_options['fields']['field_publications_exhibition_su']['field'] = 'field_publications_exhibition_su';
  /* Field: Content: Media/promotion */
  $handler->display->display_options['fields']['field_media_promotion']['id'] = 'field_media_promotion';
  $handler->display->display_options['fields']['field_media_promotion']['table'] = 'field_data_field_media_promotion';
  $handler->display->display_options['fields']['field_media_promotion']['field'] = 'field_media_promotion';
  /* Field: Comments / Summary after event */
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['id'] = 'field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['table'] = 'field_data_field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['field'] = 'field_comments_summary_after_eve';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['ui_name'] = 'Comments / Summary after event';
  $handler->display->display_options['fields']['field_comments_summary_after_eve']['element_label_colon'] = FALSE;
  /* Field: Content: Key Performance Indicator */
  $handler->display->display_options['fields']['field_key_performance']['id'] = 'field_key_performance';
  $handler->display->display_options['fields']['field_key_performance']['table'] = 'field_data_field_key_performance';
  $handler->display->display_options['fields']['field_key_performance']['field'] = 'field_key_performance';
  /* Field: Adonis */
  $handler->display->display_options['fields']['field_adonis']['id'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['table'] = 'field_data_field_adonis';
  $handler->display->display_options['fields']['field_adonis']['field'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['ui_name'] = 'Adonis';
  $handler->display->display_options['fields']['field_adonis']['element_label_colon'] = FALSE;
  /* Field: Number of attendees */
  $handler->display->display_options['fields']['field_number_of_attendees']['id'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['table'] = 'field_data_field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['field'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['ui_name'] = 'Number of attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['label'] = 'Number of participants';
  $handler->display->display_options['fields']['field_number_of_attendees']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_number_of_attendees']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Username */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['ui_name'] = 'Username';
  $handler->display->display_options['fields']['name']['label'] = 'Created by';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['ui_name'] = 'Published';
  $handler->display->display_options['fields']['status']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Color (field_color) */
  $handler->display->display_options['filters']['field_color_value']['id'] = 'field_color_value';
  $handler->display->display_options['filters']['field_color_value']['table'] = 'field_data_field_color';
  $handler->display->display_options['filters']['field_color_value']['field'] = 'field_color_value';
  $handler->display->display_options['filters']['field_color_value']['group'] = 1;
  $handler->display->display_options['filters']['field_color_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_color_value']['expose']['operator_id'] = 'field_color_value_op';
  $handler->display->display_options['filters']['field_color_value']['expose']['label'] = 'Color (field_color)';
  $handler->display->display_options['filters']['field_color_value']['expose']['operator'] = 'field_color_value_op';
  $handler->display->display_options['filters']['field_color_value']['expose']['identifier'] = 'field_color_value';
  $handler->display->display_options['filters']['field_color_value']['expose']['remember_roles'] = array(
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
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Content: Organization (field_organization) */
  $handler->display->display_options['filters']['field_organization_value']['id'] = 'field_organization_value';
  $handler->display->display_options['filters']['field_organization_value']['table'] = 'field_data_field_organization';
  $handler->display->display_options['filters']['field_organization_value']['field'] = 'field_organization_value';
  $handler->display->display_options['filters']['field_organization_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_organization_value']['group'] = 1;
  $handler->display->display_options['filters']['field_organization_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organization_value']['expose']['operator_id'] = 'field_organization_value_op';
  $handler->display->display_options['filters']['field_organization_value']['expose']['label'] = 'Organization';
  $handler->display->display_options['filters']['field_organization_value']['expose']['operator'] = 'field_organization_value_op';
  $handler->display->display_options['filters']['field_organization_value']['expose']['identifier'] = 'field_organization_value';
  $handler->display->display_options['filters']['field_organization_value']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Content: Country (field_country_code) */
  $handler->display->display_options['filters']['field_country_code_value']['id'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['filters']['field_country_code_value']['field'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['group'] = 1;
  $handler->display->display_options['filters']['field_country_code_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_country_code_value']['expose']['operator_id'] = 'field_country_code_value_op';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['operator'] = 'field_country_code_value_op';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['identifier'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Content: City (field_city) */
  $handler->display->display_options['filters']['field_city_value']['id'] = 'field_city_value';
  $handler->display->display_options['filters']['field_city_value']['table'] = 'field_data_field_city';
  $handler->display->display_options['filters']['field_city_value']['field'] = 'field_city_value';
  $handler->display->display_options['filters']['field_city_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_city_value']['group'] = 1;
  $handler->display->display_options['filters']['field_city_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_city_value']['expose']['operator_id'] = 'field_city_value_op';
  $handler->display->display_options['filters']['field_city_value']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_city_value']['expose']['operator'] = 'field_city_value_op';
  $handler->display->display_options['filters']['field_city_value']['expose']['identifier'] = 'field_city_value';
  $handler->display->display_options['filters']['field_city_value']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Content: Date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator_id'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['label'] = 'Start date';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['identifier'] = 'field_start_date_value';
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
    13 => 0,
  );
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Date - end date (field_start_date:value2) */
  $handler->display->display_options['filters']['field_start_date_value2']['id'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value2']['field'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['operator'] = '<=';
  $handler->display->display_options['filters']['field_start_date_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_start_date_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator_id'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['label'] = 'End date';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['identifier'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_start_date_value2']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Ares/Adonis (field_adonis) */
  $handler->display->display_options['filters']['field_adonis_value']['id'] = 'field_adonis_value';
  $handler->display->display_options['filters']['field_adonis_value']['table'] = 'field_data_field_adonis';
  $handler->display->display_options['filters']['field_adonis_value']['field'] = 'field_adonis_value';
  $handler->display->display_options['filters']['field_adonis_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_adonis_value']['group'] = 1;
  $handler->display->display_options['filters']['field_adonis_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_adonis_value']['expose']['operator_id'] = 'field_adonis_value_op';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['label'] = 'Adonis';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['operator'] = 'field_adonis_value_op';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['identifier'] = 'field_adonis_value';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['remember_roles'] = array(
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
    12 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_activity_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_tid']['vocabulary'] = 'activity';
  $handler->display->display_options['filters']['field_activity_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Agency role (field_agency_role) */
  $handler->display->display_options['filters']['field_agency_role_value']['id'] = 'field_agency_role_value';
  $handler->display->display_options['filters']['field_agency_role_value']['table'] = 'field_data_field_agency_role';
  $handler->display->display_options['filters']['field_agency_role_value']['field'] = 'field_agency_role_value';
  $handler->display->display_options['filters']['field_agency_role_value']['group'] = 1;
  $handler->display->display_options['filters']['field_agency_role_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['operator_id'] = 'field_agency_role_value_op';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['label'] = 'Agency role';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['operator'] = 'field_agency_role_value_op';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['identifier'] = 'field_agency_role_value';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Content: Agenda (field_agenda) */
  $handler->display->display_options['filters']['field_agenda_value']['id'] = 'field_agenda_value';
  $handler->display->display_options['filters']['field_agenda_value']['table'] = 'field_data_field_agenda';
  $handler->display->display_options['filters']['field_agenda_value']['field'] = 'field_agenda_value';
  $handler->display->display_options['filters']['field_agenda_value']['group'] = 1;
  $handler->display->display_options['filters']['field_agenda_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agenda_value']['expose']['operator_id'] = 'field_agenda_value_op';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['label'] = 'Agenda';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['operator'] = 'field_agenda_value_op';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['identifier'] = 'field_agenda_value';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Publications/exhibition support (field_publications_exhibition_su) */
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['id'] = 'field_publications_exhibition_su_value';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['table'] = 'field_data_field_publications_exhibition_su';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['field'] = 'field_publications_exhibition_su_value';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['group'] = 1;
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['operator_id'] = 'field_publications_exhibition_su_value_op';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['label'] = 'Publications/exhibition support';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['operator'] = 'field_publications_exhibition_su_value_op';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['identifier'] = 'field_publications_exhibition_su_value';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Media/promotion (field_media_promotion) */
  $handler->display->display_options['filters']['field_media_promotion_value']['id'] = 'field_media_promotion_value';
  $handler->display->display_options['filters']['field_media_promotion_value']['table'] = 'field_data_field_media_promotion';
  $handler->display->display_options['filters']['field_media_promotion_value']['field'] = 'field_media_promotion_value';
  $handler->display->display_options['filters']['field_media_promotion_value']['group'] = 1;
  $handler->display->display_options['filters']['field_media_promotion_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['operator_id'] = 'field_media_promotion_value_op';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['label'] = 'Media/promotion';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['operator'] = 'field_media_promotion_value_op';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['identifier'] = 'field_media_promotion_value';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Key Performance Indicator (field_key_performance) */
  $handler->display->display_options['filters']['field_key_performance_value']['id'] = 'field_key_performance_value';
  $handler->display->display_options['filters']['field_key_performance_value']['table'] = 'field_data_field_key_performance';
  $handler->display->display_options['filters']['field_key_performance_value']['field'] = 'field_key_performance_value';
  $handler->display->display_options['filters']['field_key_performance_value']['group'] = 1;
  $handler->display->display_options['filters']['field_key_performance_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['operator_id'] = 'field_key_performance_value_op';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['label'] = 'Key Performance Indicator';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['operator'] = 'field_key_performance_value_op';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['identifier'] = 'field_key_performance_value';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Agency rep confirmed (field_agency_rep_confirmed) */
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['id'] = 'field_agency_rep_confirmed_value';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['table'] = 'field_data_field_agency_rep_confirmed';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['field'] = 'field_agency_rep_confirmed_value';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['group'] = 1;
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['operator_id'] = 'field_agency_rep_confirmed_value_op';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['label'] = 'Agency rep confirmed';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['operator'] = 'field_agency_rep_confirmed_value_op';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['identifier'] = 'field_agency_rep_confirmed_value';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Content: Type (field_event_type) */
  $handler->display->display_options['filters']['field_event_type_value']['id'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['table'] = 'field_data_field_event_type';
  $handler->display->display_options['filters']['field_event_type_value']['field'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_type_value']['expose']['operator_id'] = 'field_event_type_value_op';
  $handler->display->display_options['filters']['field_event_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_event_type_value']['expose']['operator'] = 'field_event_type_value_op';
  $handler->display->display_options['filters']['field_event_type_value']['expose']['identifier'] = 'field_event_type_value';
  $handler->display->display_options['filters']['field_event_type_value']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Content: Migration Source (field_migration_source) */
  $handler->display->display_options['filters']['field_migration_source_value']['id'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['table'] = 'field_data_field_migration_source';
  $handler->display->display_options['filters']['field_migration_source_value']['field'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_migration_source_value']['value'] = array(
    'hwc' => 'hwc',
    'oira' => 'oira',
    'napo' => 'napo',
  );
  $handler->display->display_options['filters']['field_migration_source_value']['group'] = 1;
  $handler->display->display_options['filters']['field_migration_source_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['operator_id'] = 'field_migration_source_value_op';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['label'] = 'Source not in';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['operator'] = 'field_migration_source_value_op';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['identifier'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['group_info']['label'] = 'Source';
  $handler->display->display_options['filters']['field_migration_source_value']['group_info']['identifier'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'HWC',
      'operator' => 'or',
      'value' => array(
        'hwc' => 'hwc',
      ),
    ),
    2 => array(
      'title' => 'Osha',
      'operator' => 'empty',
      'value' => array(
        'hwc' => 'hwc',
        'oira' => 'oira',
        'napo' => 'napo',
      ),
    ),
  );
  /* Filter criterion: Content: For the web / Public (field_for_the_web) */
  $handler->display->display_options['filters']['field_for_the_web_value']['id'] = 'field_for_the_web_value';
  $handler->display->display_options['filters']['field_for_the_web_value']['table'] = 'field_data_field_for_the_web';
  $handler->display->display_options['filters']['field_for_the_web_value']['field'] = 'field_for_the_web_value';
  $handler->display->display_options['filters']['field_for_the_web_value']['group'] = 1;
  $handler->display->display_options['filters']['field_for_the_web_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['operator_id'] = 'field_for_the_web_value_op';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['label'] = 'For the web / Public';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['operator'] = 'field_for_the_web_value_op';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['identifier'] = 'field_for_the_web_value';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Field: Tags (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator_id'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['identifier'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['filters']['field_tags_tid']['error_message'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/events-export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    'block_1' => 0,
  );
  $translatables['events'] = array(
    t('Master'),
    t('Events'),
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
    t('For the web / Public'),
    t('Organization'),
    t('Country code'),
    t('City'),
    t('Date'),
    t('Website of event'),
    t('Ares/Adonis'),
    t('Unit Ref'),
    t('Agency role'),
    t('Agency initial contact'),
    t('Agency rep confirmed'),
    t('Organized by EU-OSHA'),
    t('Event in AMP'),
    t('Agency contact / reply'),
    t('Comments'),
    t('Number of attendees'),
    t('Satisfaction rate'),
    t('Published'),
    t('<p>
<a href="/en/node/add/events">Add event</a>
</p>'),
    t('Total: @total'),
    t('Colours'),
    t('<div class="colours">
<div class="red"></div><p">TBD - TBC<p>
<div class="black"></div><p>Confirmed<p>
<div class="grey"></div><p>Only web or not attendance<p>
</div>'),
    t('<span class="result_summary">Displaying @start - @end of @total</span>'),
    t('Color'),
    t('[field_color]'),
    t('Activity'),
    t('Type of event'),
    t('Title'),
    t('Country'),
    t('Start date'),
    t('End date'),
    t('Agenda'),
    t('Publications/exhibition support'),
    t('Media/promotion'),
    t('Key Performance Indicator'),
    t('Number of participants'),
    t('Created by'),
    t('Action'),
    t('<ul class="links inline">
<li>[edit_node]</li>
<li>[delete_node]</li>
</ul>'),
    t('Not from'),
    t('Source'),
    t('For the web'),
    t('Tag'),
    t('Block'),
    t('Location'),
    t('[field_start_date_1] - Events'),
    t('Data export'),
    t('[field_start_date-value]'),
    t('[field_start_date_1-value2]'),
    t('Color (field_color)'),
    t('Adonis'),
    t('Type'),
    t('Source not in'),
    t('Tags'),
  );
  $export['events'] = $view;

  $view = new view();
  $view->name = 'events_index';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_multilingual_node_index';
  $view->human_name = 'Events Index';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Multilingual Content: Multilingual ID */
  $handler->display->display_options['fields']['search_api_et_id']['id'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  /* Sort criterion: Indexed Multilingual Content: Publication date */
  $handler->display->display_options['sorts']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_publication_date']['field'] = 'field_publication_date';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming events';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Content: Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Indexed Multilingual Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_country_code']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_country_code']['element_class'] = 'country';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country_code']['settings'] = array(
    'title_style' => 'div',
    'title_link' => '',
    'title_class' => 'country',
  );
  /* Field: Indexed Multilingual Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_city']['element_class'] = 'city';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_city']['settings'] = array(
    'title_style' => '_none',
    'title_link' => '',
    'title_class' => 'city',
  );
  /* Field: Indexed Multilingual Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_type'] = 'div';
  $handler->display->display_options['fields']['title_field']['element_class'] = 'title';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'h2',
    'title_link' => 'content',
    'title_class' => 'title events-teaser-title',
  );
  /* Field: Indexed Multilingual Content: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '150',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Date: Start date (indexed) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Multilingual Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  /* Filter criterion: Indexed Multilingual Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Date: End date (indexed) */
  $handler->display->display_options['filters']['field_start_date_value2']['id'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_start_date_value2']['field'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value2']['value'] = 'now';
  $handler->display->display_options['block_description'] = 'Upcoming events';
  $translatables['events_index'] = array(
    t('Master'),
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
    t('Multilingual ID'),
    t('Block'),
    t('Upcoming events'),
    t('View all'),
    t('No results'),
  );
  $export['events_index'] = $view;

  $view = new view();
  $view->name = 'oshevents';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear filter';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_start_date_2',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '<span class="result_summary">Displaying @start - @end of @total</span>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="view-empty">No results</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Start date excluded from display */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['ui_name'] = 'Start date excluded from display';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date']['alter']['text'] = '[field_start_date-value] - [field_start_date-value2]';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Start date - End date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['ui_name'] = 'Start date - End date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['alter']['text'] = '[field_start_date] - [field_start_date_1]';
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'h2',
    'title_link' => 'content',
    'title_class' => 'events-teaser-title',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = 'COUNTRY';
  $handler->display->display_options['fields']['field_country_code']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_country_code']['alter']['text'] = '[field_country_code]';
  $handler->display->display_options['fields']['field_country_code']['hide_empty'] = TRUE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = 'CITY';
  $handler->display->display_options['fields']['field_city']['hide_empty'] = TRUE;
  /* Field: Content: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = 'ORGANIZER';
  $handler->display->display_options['fields']['field_organization']['hide_empty'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'See details';
  /* Field: Start date for grouping */
  $handler->display->display_options['fields']['field_start_date_2']['id'] = 'field_start_date_2';
  $handler->display->display_options['fields']['field_start_date_2']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_2']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_2']['ui_name'] = 'Start date for grouping';
  $handler->display->display_options['fields']['field_start_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_2']['alter']['text'] = '[field_start_date_2] - Events';
  $handler->display->display_options['fields']['field_start_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_2']['settings'] = array(
    'format_type' => 'year_and_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Sort criterion: Content: Date -  start date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
    3 => 'OR',
  );
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
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
  );
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Country (field_country_code) */
  $handler->display->display_options['filters']['field_country_code_value']['id'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['filters']['field_country_code_value']['field'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['group'] = 1;
  $handler->display->display_options['filters']['field_country_code_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_country_code_value']['expose']['operator_id'] = 'field_country_code_value_op';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['label'] = 'Search by country';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['operator'] = 'field_country_code_value_op';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['identifier'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Content: Date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator_id'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['label'] = 'From date';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['identifier'] = 'field_start_date_value';
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
    13 => 0,
  );
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_start_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Date - end date (field_start_date:value2) */
  $handler->display->display_options['filters']['field_start_date_value2']['id'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value2']['field'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['operator'] = '<=';
  $handler->display->display_options['filters']['field_start_date_value2']['group'] = 2;
  $handler->display->display_options['filters']['field_start_date_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator_id'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['label'] = 'To date';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['identifier'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_start_date_value2']['form_type'] = 'date_popup';
  /* Filter criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['group'] = 3;
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Field: Publication date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value_1']['id'] = 'field_publication_date_value_1';
  $handler->display->display_options['filters']['field_publication_date_value_1']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value_1']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_publication_date_value_1']['group'] = 3;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'oshevents';
  $translatables['oshevents'] = array(
    t('Master'),
    t('Events'),
    t('more'),
    t('Search'),
    t('Clear filter'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('«'),
    t('‹'),
    t('›'),
    t('»'),
    t('<span class="result_summary">Displaying @start - @end of @total</span>'),
    t('<div class="view-empty">No results</div>'),
    t('[field_start_date-value] - [field_start_date-value2]'),
    t('[field_start_date] - [field_start_date_1]'),
    t('COUNTRY'),
    t('[field_country_code]'),
    t('CITY'),
    t('ORGANIZER'),
    t('See details'),
    t('[field_start_date_2] - Events'),
    t('Search by country'),
    t('From date'),
    t('To date'),
    t('Page'),
  );
  $export['oshevents'] = $view;

  $view = new view();
  $view->name = 'reporting_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Reporting View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Reporting View';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_activity',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<?php

$tot_attend = 0;
$tot_satisf = 0;
$rate_satisfaction = 0;
$average_attend = 0;
$tot_results = count($results);

for ($i=0; $i < $tot_results; $i++) {
	if(isset($results[$i]->field_field_number_of_attendees[0][\'raw\'][\'value\'])){
		$tot_attend +=  $results[$i]->field_field_number_of_attendees[0][\'raw\'][\'value\'];
	}
}


for ($j=0; $j < $tot_results; $j++){

	if(isset($results[$j]->field_field_satisfaction_rate[0][\'raw\'][\'value\'])){
		$tot_satisf += $results[$j]->field_field_satisfaction_rate[0][\'raw\'][\'value\'];
	}

}

$rate_satisfaction = $tot_satisf / $tot_results;
$rate_satisfaction = round($rate_satisfaction, 2);

$average_attend = $tot_attend / $tot_results;
$average_attend = round($average_attend, 2);

?>

<h2>Results: <?php print $tot_results;  ?> events</h2>
<ul class="list-reports">
  <li><h4>Total number of attendees: <span><?php print $tot_attend; ?></span></h4></li>
  <li><h4>Satisfaction rate: <span><?php print $rate_satisfaction; ?>%</span></h4></li>
  <li><h4>Average attendance: <span><?php print $average_attend; ?></span></h4></li>
</ul>

';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Total: @end
';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['label'] = '';
  $handler->display->display_options['fields']['field_activity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_activity']['element_label_colon'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = 'Start date:';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => '',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Event in AMP */
  $handler->display->display_options['fields']['field_event_in_amp']['id'] = 'field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['table'] = 'field_data_field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['field'] = 'field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['label'] = 'In the AMP: ';
  $handler->display->display_options['fields']['field_event_in_amp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_in_amp']['type'] = 'i18n_list_default';
  /* Field: Content: Number of attendees */
  $handler->display->display_options['fields']['field_number_of_attendees']['id'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['table'] = 'field_data_field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['field'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_number_of_attendees']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Satisfaction rate */
  $handler->display->display_options['fields']['field_satisfaction_rate']['id'] = 'field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['table'] = 'field_data_field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['field'] = 'field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_satisfaction_rate']['alter']['text'] = '[field_satisfaction_rate]%';
  $handler->display->display_options['fields']['field_satisfaction_rate']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Activity (field_activity) */
  $handler->display->display_options['sorts']['field_activity_tid']['id'] = 'field_activity_tid';
  $handler->display->display_options['sorts']['field_activity_tid']['table'] = 'field_data_field_activity';
  $handler->display->display_options['sorts']['field_activity_tid']['field'] = 'field_activity_tid';
  $handler->display->display_options['sorts']['field_activity_tid']['order'] = 'DESC';
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
  $handler->display->display_options['filters']['type']['group'] = 1;
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
    12 => 0,
  );
  $handler->display->display_options['filters']['field_activity_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_tid']['vocabulary'] = 'activity';
  $handler->display->display_options['filters']['field_activity_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Event in AMP (field_event_in_amp) */
  $handler->display->display_options['filters']['field_event_in_amp_value']['id'] = 'field_event_in_amp_value';
  $handler->display->display_options['filters']['field_event_in_amp_value']['table'] = 'field_data_field_event_in_amp';
  $handler->display->display_options['filters']['field_event_in_amp_value']['field'] = 'field_event_in_amp_value';
  $handler->display->display_options['filters']['field_event_in_amp_value']['value'] = array(
    'Yes' => 'Yes',
  );
  $handler->display->display_options['filters']['field_event_in_amp_value']['group'] = 1;
  $handler->display->display_options['filters']['field_event_in_amp_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_in_amp_value']['expose']['operator_id'] = 'field_event_in_amp_value_op';
  $handler->display->display_options['filters']['field_event_in_amp_value']['expose']['label'] = 'Event in AMP';
  $handler->display->display_options['filters']['field_event_in_amp_value']['expose']['operator'] = 'field_event_in_amp_value_op';
  $handler->display->display_options['filters']['field_event_in_amp_value']['expose']['identifier'] = 'field_event_in_amp_value';
  $handler->display->display_options['filters']['field_event_in_amp_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator_id'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['identifier'] = 'field_start_date_value';
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
  $handler->display->display_options['filters']['field_start_date_value']['group_info']['label'] = 'Start date (field_start_date)';
  $handler->display->display_options['filters']['field_start_date_value']['group_info']['identifier'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_start_date_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_popup';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/reporting-view';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Events-reports';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['reporting_view'] = array(
    t('Master'),
    t('Reporting View'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Total: @end
'),
    t('Start date:'),
    t('In the AMP: '),
    t('Number of attendees'),
    t('Satisfaction rate'),
    t('[field_satisfaction_rate]%'),
    t('Activity'),
    t('Event in AMP'),
    t('Start date (field_start_date)'),
    t('Page'),
    t('Block'),
  );
  $export['reporting_view'] = $view;

  $view = new view();
  $view->name = 'upcoming_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Upcoming events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Upcoming events';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_country_code']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_country_code']['element_class'] = 'country';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_city']['element_class'] = 'city';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_type'] = 'div';
  $handler->display->display_options['fields']['title_field']['element_class'] = 'title';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => 'title',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Sort criterion: Content: Date -  start date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
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
  /* Filter criterion: Content: Date - end date (field_start_date:value2) */
  $handler->display->display_options['filters']['field_start_date_value2']['id'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value2']['field'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value2']['default_date'] = 'now';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Upcoming events';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'events';
  $translatables['upcoming_events'] = array(
    t('Master'),
    t('Upcoming events'),
    t('View all'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No results'),
    t('Block'),
    t('more'),
    t('Page'),
  );
  $export['upcoming_events'] = $view;

  return $export;
}
