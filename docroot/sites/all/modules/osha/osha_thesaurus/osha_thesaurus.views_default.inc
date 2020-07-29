<?php
/**
 * @file
 * osha_thesaurus.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_thesaurus_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'thesaurus';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Thesaurus';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Thesaurus';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
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
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Offset label';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = 'Código de país';
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
  $handler->display->display_options['fields']['field_start_date']['label'] = 'Fecha';
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
  $handler->display->display_options['fields']['field_website_of_event']['label'] = 'Sitio web del evento';
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
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['label'] = 'Agency confirmed response';
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
  $handler->display->display_options['fields']['field_agency_contact_reply']['label'] = 'Agency contact/reply';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'thesaurus' => 'thesaurus',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Thesaurus */
  $handler = $view->new_display('page', 'Thesaurus', 'page');
  $handler->display->display_options['field_language_add_to_query'] = 0;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 50, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Offset label';
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
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Total: @total';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '<span class="result_summary">Displaying @start - @end of @total</span>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Content: Father */
  $handler->display->display_options['fields']['field_father']['id'] = 'field_father';
  $handler->display->display_options['fields']['field_father']['table'] = 'field_data_field_father';
  $handler->display->display_options['fields']['field_father']['field'] = 'field_father';
  $handler->display->display_options['fields']['field_father']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_father']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Full URL */
  $handler->display->display_options['fields']['field_full_url']['id'] = 'field_full_url';
  $handler->display->display_options['fields']['field_full_url']['table'] = 'field_data_field_full_url';
  $handler->display->display_options['fields']['field_full_url']['field'] = 'field_full_url';
  $handler->display->display_options['fields']['field_full_url']['element_label_colon'] = FALSE;
  /* Field: Content: ID */
  $handler->display->display_options['fields']['field_term_id']['id'] = 'field_term_id';
  $handler->display->display_options['fields']['field_term_id']['table'] = 'field_data_field_term_id';
  $handler->display->display_options['fields']['field_term_id']['field'] = 'field_term_id';
  $handler->display->display_options['fields']['field_term_id']['label'] = 'Term ID';
  $handler->display->display_options['fields']['field_term_id']['element_label_colon'] = FALSE;
  /* Field: Content: Definition */
  $handler->display->display_options['fields']['field_definition']['id'] = 'field_definition';
  $handler->display->display_options['fields']['field_definition']['table'] = 'field_data_field_definition';
  $handler->display->display_options['fields']['field_definition']['field'] = 'field_definition';
  $handler->display->display_options['fields']['field_definition']['element_label_colon'] = FALSE;
  /* Field: Content: Context */
  $handler->display->display_options['fields']['field_context']['id'] = 'field_context';
  $handler->display->display_options['fields']['field_context']['table'] = 'field_data_field_context';
  $handler->display->display_options['fields']['field_context']['field'] = 'field_context';
  $handler->display->display_options['fields']['field_context']['element_label_colon'] = FALSE;
  /* Field: Content: Synonyms */
  $handler->display->display_options['fields']['field_synonyms']['id'] = 'field_synonyms';
  $handler->display->display_options['fields']['field_synonyms']['table'] = 'field_data_field_synonyms';
  $handler->display->display_options['fields']['field_synonyms']['field'] = 'field_synonyms';
  $handler->display->display_options['fields']['field_synonyms']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_synonyms']['delta_offset'] = '0';
  /* Field: Content: Term reference */
  $handler->display->display_options['fields']['field_term_reference']['id'] = 'field_term_reference';
  $handler->display->display_options['fields']['field_term_reference']['table'] = 'field_data_field_term_reference';
  $handler->display->display_options['fields']['field_term_reference']['field'] = 'field_term_reference';
  $handler->display->display_options['fields']['field_term_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Glossary */
  $handler->display->display_options['fields']['field_glossary_the']['id'] = 'field_glossary_the';
  $handler->display->display_options['fields']['field_glossary_the']['table'] = 'field_data_field_glossary_the';
  $handler->display->display_options['fields']['field_glossary_the']['field'] = 'field_glossary_the';
  $handler->display->display_options['fields']['field_glossary_the']['element_label_colon'] = FALSE;
  /* Field: Content: Notes */
  $handler->display->display_options['fields']['field_notes']['id'] = 'field_notes';
  $handler->display->display_options['fields']['field_notes']['table'] = 'field_data_field_notes';
  $handler->display->display_options['fields']['field_notes']['field'] = 'field_notes';
  $handler->display->display_options['fields']['field_notes']['element_label_colon'] = FALSE;
  /* Field: Content: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Link to delete content */
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'thesaurus' => 'thesaurus',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
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
    14 => 0,
    15 => 0,
  );
  /* Filter criterion: Content: Glossary (field_glossary_the) */
  $handler->display->display_options['filters']['field_glossary_the_tid']['id'] = 'field_glossary_the_tid';
  $handler->display->display_options['filters']['field_glossary_the_tid']['table'] = 'field_data_field_glossary_the';
  $handler->display->display_options['filters']['field_glossary_the_tid']['field'] = 'field_glossary_the_tid';
  $handler->display->display_options['filters']['field_glossary_the_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_glossary_the_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['operator_id'] = 'field_glossary_the_tid_op';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['label'] = 'Glossary (field_glossary_the)';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['operator'] = 'field_glossary_the_tid_op';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['identifier'] = 'field_glossary_the_tid';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['remember_roles'] = array(
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
    15 => 0,
  );
  $handler->display->display_options['filters']['field_glossary_the_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_glossary_the_tid']['vocabulary'] = 'glossary_the';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['metatags'] = array(
    'und' => array(
      'title' => array(
        'value' => '[view:title] | [current-page:pager][site:name]',
        'default' => '[view:title] | [current-page:pager][site:name]',
      ),
      'description' => array(
        'value' => '[view:description]',
        'default' => '[view:description]',
      ),
      'abstract' => array(
        'value' => '',
        'default' => '',
      ),
      'keywords' => array(
        'value' => 'eu osha, eu-osha, osha, regulations, standards, legislation, surveys, risk assessment, accident prevention, european agency, safety and health, health at work, safety at work, statistics, workplace safety, frequent hazards, occupational health and safety, assessment tools, eu, esener, napo, oshwiki, oira, healthy workplaces, information, emerging risks',
        'default' => 'eu osha, eu-osha, osha, regulations, standards, legislation, surveys, risk assessment, accident prevention, european agency, safety and health, health at work, safety at work, statistics, workplace safety, frequent hazards, occupational health and safety, assessment tools, eu, esener, napo, oshwiki, oira, healthy workplaces, information, emerging risks',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
        'default' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
        'default' => '',
      ),
      'standout' => array(
        'value' => '',
        'default' => '',
      ),
      'rating' => array(
        'value' => '',
      ),
      'referrer' => array(
        'value' => '',
      ),
      'rights' => array(
        'value' => '',
        'default' => '',
      ),
      'image_src' => array(
        'value' => '',
        'default' => '',
      ),
      'canonical' => array(
        'value' => '[view:url]',
        'default' => '[view:url]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
        'default' => '[current-page:url:unaliased]',
      ),
      'original-source' => array(
        'value' => '',
        'default' => '',
      ),
      'prev' => array(
        'value' => '',
      ),
      'next' => array(
        'value' => '',
      ),
      'content-language' => array(
        'value' => '',
        'default' => '',
      ),
      'geo.position' => array(
        'value' => '',
      ),
      'geo.placename' => array(
        'value' => '',
      ),
      'geo.region' => array(
        'value' => '',
      ),
      'icbm' => array(
        'value' => '',
      ),
      'refresh' => array(
        'value' => '',
      ),
      'revisit-after' => array(
        'value' => '',
        'period' => '',
        'default' => '',
      ),
      'pragma' => array(
        'value' => '',
      ),
      'cache-control' => array(
        'value' => '',
      ),
      'expires' => array(
        'value' => '',
      ),
      'dcterms.title' => array(
        'value' => '',
      ),
      'dcterms.creator' => array(
        'value' => '',
      ),
      'dcterms.subject' => array(
        'value' => '',
      ),
      'dcterms.description' => array(
        'value' => '',
      ),
      'dcterms.publisher' => array(
        'value' => '',
      ),
      'dcterms.contributor' => array(
        'value' => '',
      ),
      'dcterms.date' => array(
        'value' => '',
      ),
      'dcterms.type' => array(
        'value' => '',
      ),
      'dcterms.format' => array(
        'value' => '',
      ),
      'dcterms.identifier' => array(
        'value' => '',
      ),
      'dcterms.source' => array(
        'value' => '',
      ),
      'dcterms.language' => array(
        'value' => '',
      ),
      'dcterms.relation' => array(
        'value' => '',
      ),
      'dcterms.coverage' => array(
        'value' => '',
      ),
      'dcterms.rights' => array(
        'value' => '',
      ),
    ),
  );
  $handler->display->display_options['path'] = 'admin/content/thesaurus';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Thesaurus';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'thesaurus.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Father */
  $handler->display->display_options['fields']['field_father']['id'] = 'field_father';
  $handler->display->display_options['fields']['field_father']['table'] = 'field_data_field_father';
  $handler->display->display_options['fields']['field_father']['field'] = 'field_father';
  $handler->display->display_options['fields']['field_father']['ui_name'] = 'Father';
  $handler->display->display_options['fields']['field_father']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Full URL */
  $handler->display->display_options['fields']['field_full_url']['id'] = 'field_full_url';
  $handler->display->display_options['fields']['field_full_url']['table'] = 'field_data_field_full_url';
  $handler->display->display_options['fields']['field_full_url']['field'] = 'field_full_url';
  $handler->display->display_options['fields']['field_full_url']['ui_name'] = 'Full URL';
  /* Field: ID */
  $handler->display->display_options['fields']['field_term_id']['id'] = 'field_term_id';
  $handler->display->display_options['fields']['field_term_id']['table'] = 'field_data_field_term_id';
  $handler->display->display_options['fields']['field_term_id']['field'] = 'field_term_id';
  $handler->display->display_options['fields']['field_term_id']['ui_name'] = 'ID';
  $handler->display->display_options['fields']['field_term_id']['type'] = 'text_plain';
  /* Field: Definition */
  $handler->display->display_options['fields']['field_definition']['id'] = 'field_definition';
  $handler->display->display_options['fields']['field_definition']['table'] = 'field_data_field_definition';
  $handler->display->display_options['fields']['field_definition']['field'] = 'field_definition';
  $handler->display->display_options['fields']['field_definition']['ui_name'] = 'Definition';
  $handler->display->display_options['fields']['field_definition']['type'] = 'text_plain';
  /* Field: Context */
  $handler->display->display_options['fields']['field_context']['id'] = 'field_context';
  $handler->display->display_options['fields']['field_context']['table'] = 'field_data_field_context';
  $handler->display->display_options['fields']['field_context']['field'] = 'field_context';
  $handler->display->display_options['fields']['field_context']['ui_name'] = 'Context';
  $handler->display->display_options['fields']['field_context']['type'] = 'text_plain';
  /* Field: Synonyms */
  $handler->display->display_options['fields']['field_synonyms']['id'] = 'field_synonyms';
  $handler->display->display_options['fields']['field_synonyms']['table'] = 'field_data_field_synonyms';
  $handler->display->display_options['fields']['field_synonyms']['field'] = 'field_synonyms';
  $handler->display->display_options['fields']['field_synonyms']['ui_name'] = 'Synonyms';
  $handler->display->display_options['fields']['field_synonyms']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_synonyms']['delta_offset'] = '0';
  /* Field: Term reference */
  $handler->display->display_options['fields']['field_term_reference']['id'] = 'field_term_reference';
  $handler->display->display_options['fields']['field_term_reference']['table'] = 'field_data_field_term_reference';
  $handler->display->display_options['fields']['field_term_reference']['field'] = 'field_term_reference';
  $handler->display->display_options['fields']['field_term_reference']['ui_name'] = 'Term reference';
  $handler->display->display_options['fields']['field_term_reference']['type'] = 'text_plain';
  /* Field: Glossary */
  $handler->display->display_options['fields']['field_glossary_the']['id'] = 'field_glossary_the';
  $handler->display->display_options['fields']['field_glossary_the']['table'] = 'field_data_field_glossary_the';
  $handler->display->display_options['fields']['field_glossary_the']['field'] = 'field_glossary_the';
  $handler->display->display_options['fields']['field_glossary_the']['ui_name'] = 'Glossary';
  $handler->display->display_options['fields']['field_glossary_the']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Notes */
  $handler->display->display_options['fields']['field_notes']['id'] = 'field_notes';
  $handler->display->display_options['fields']['field_notes']['table'] = 'field_data_field_notes';
  $handler->display->display_options['fields']['field_notes']['field'] = 'field_notes';
  $handler->display->display_options['fields']['field_notes']['ui_name'] = 'Notes';
  $handler->display->display_options['fields']['field_notes']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'thesaurus' => 'thesaurus',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
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
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Filter criterion: Content: Glossary (field_glossary_the) */
  $handler->display->display_options['filters']['field_glossary_the_tid']['id'] = 'field_glossary_the_tid';
  $handler->display->display_options['filters']['field_glossary_the_tid']['table'] = 'field_data_field_glossary_the';
  $handler->display->display_options['filters']['field_glossary_the_tid']['field'] = 'field_glossary_the_tid';
  $handler->display->display_options['filters']['field_glossary_the_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_glossary_the_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['operator_id'] = 'field_glossary_the_tid_op';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['label'] = 'Glossary';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['operator'] = 'field_glossary_the_tid_op';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['identifier'] = 'field_glossary_the_tid';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['remember_roles'] = array(
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
    15 => 0,
  );
  $handler->display->display_options['filters']['field_glossary_the_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_glossary_the_tid']['vocabulary'] = 'glossary_the';
  $handler->display->display_options['path'] = 'admin/content/thesaurus-export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    'block_1' => 0,
  );

  /* Display: Thesaurus List with Tree */
  $handler = $view->new_display('page', 'Thesaurus List with Tree', 'page_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'tree';
  $handler->display->display_options['style_options']['main_field'] = 'nid';
  $handler->display->display_options['style_options']['parent_field'] = 'field_father';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Total: @total';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '<span class="result_summary">Displaying @start - @end of @total</span>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Content: Father */
  $handler->display->display_options['fields']['field_father']['id'] = 'field_father';
  $handler->display->display_options['fields']['field_father']['table'] = 'field_data_field_father';
  $handler->display->display_options['fields']['field_father']['field'] = 'field_father';
  $handler->display->display_options['fields']['field_father']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_father']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_father']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'thesaurus' => 'thesaurus',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Título';
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
    14 => 0,
    15 => 0,
  );
  /* Filter criterion: Content: Glossary (field_glossary_the) */
  $handler->display->display_options['filters']['field_glossary_the_tid']['id'] = 'field_glossary_the_tid';
  $handler->display->display_options['filters']['field_glossary_the_tid']['table'] = 'field_data_field_glossary_the';
  $handler->display->display_options['filters']['field_glossary_the_tid']['field'] = 'field_glossary_the_tid';
  $handler->display->display_options['filters']['field_glossary_the_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_glossary_the_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['operator_id'] = 'field_glossary_the_tid_op';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['label'] = 'Glossary (field_glossary_the)';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['operator'] = 'field_glossary_the_tid_op';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['identifier'] = 'field_glossary_the_tid';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['remember_roles'] = array(
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
    15 => 0,
  );
  $handler->display->display_options['filters']['field_glossary_the_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_glossary_the_tid']['vocabulary'] = 'glossary_the';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/content/thesaurus-tree';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Thesaurus - Tree';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Entity Reference View Widget */
  $handler = $view->new_display('entityreference_view_widget', 'Entity Reference View Widget', 'entityreference_view_widget_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'tree';
  $handler->display->display_options['style_options']['main_field'] = 'nid';
  $handler->display->display_options['style_options']['parent_field'] = 'field_father';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity Reference View Widget Checkbox: Content */
  $handler->display->display_options['fields']['entityreference_view_widget']['id'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['table'] = 'node';
  $handler->display->display_options['fields']['entityreference_view_widget']['field'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['label'] = '';
  $handler->display->display_options['fields']['entityreference_view_widget']['exclude'] = TRUE;
  $handler->display->display_options['fields']['entityreference_view_widget']['alter']['path'] = 'node/2';
  $handler->display->display_options['fields']['entityreference_view_widget']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['entityreference_view_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['force_single'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Father */
  $handler->display->display_options['fields']['field_father']['id'] = 'field_father';
  $handler->display->display_options['fields']['field_father']['table'] = 'field_data_field_father';
  $handler->display->display_options['fields']['field_father']['field'] = 'field_father';
  $handler->display->display_options['fields']['field_father']['label'] = '';
  $handler->display->display_options['fields']['field_father']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_father']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_father']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="thesaurus_element_select">[entityreference_view_widget]</div><div class="thesaurus_element_select title">[title_field]</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'thesaurus' => 'thesaurus',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value_1']['id'] = 'title_field_value_1';
  $handler->display->display_options['filters']['title_field_value_1']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value_1']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value_1']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value_1']['expose']['operator_id'] = 'title_field_value_1_op';
  $handler->display->display_options['filters']['title_field_value_1']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value_1']['expose']['operator'] = 'title_field_value_1_op';
  $handler->display->display_options['filters']['title_field_value_1']['expose']['identifier'] = 'title_field_value_1';
  $handler->display->display_options['filters']['title_field_value_1']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Filter criterion: Content: Glossary (field_glossary_the) */
  $handler->display->display_options['filters']['field_glossary_the_tid']['id'] = 'field_glossary_the_tid';
  $handler->display->display_options['filters']['field_glossary_the_tid']['table'] = 'field_data_field_glossary_the';
  $handler->display->display_options['filters']['field_glossary_the_tid']['field'] = 'field_glossary_the_tid';
  $handler->display->display_options['filters']['field_glossary_the_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_glossary_the_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['operator_id'] = 'field_glossary_the_tid_op';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['label'] = 'Glossary';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['operator'] = 'field_glossary_the_tid_op';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['identifier'] = 'field_glossary_the_tid';
  $handler->display->display_options['filters']['field_glossary_the_tid']['expose']['remember_roles'] = array(
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
    15 => 0,
  );
  $handler->display->display_options['filters']['field_glossary_the_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_glossary_the_tid']['vocabulary'] = 'glossary_the';
  $translatables['thesaurus'] = array(
    t('Master'),
    t('Thesaurus'),
    t('más'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset label'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('For the web / Public'),
    t('Organisation'),
    t('Código de país'),
    t('City'),
    t('Fecha'),
    t('Sitio web del evento'),
    t('Ares/Adonis'),
    t('Unit Ref'),
    t('Agency role'),
    t('Agency initial contact'),
    t('Agency confirmed response'),
    t('Organized by EU-OSHA'),
    t('Event in AMP'),
    t('Agency contact/reply'),
    t('Comments'),
    t('Number of attendees'),
    t('Satisfaction rate'),
    t('more'),
    t('Total: @total'),
    t('<span class="result_summary">Displaying @start - @end of @total</span>'),
    t('Title'),
    t('Father'),
    t('Full URL'),
    t('Term ID'),
    t('Definition'),
    t('Context'),
    t('Synonyms'),
    t('Term reference'),
    t('Glossary'),
    t('Notes'),
    t('Action'),
    t('<ul class="links inline">
<li>[edit_node]</li>
<li>[delete_node]</li>
</ul>'),
    t('Glossary (field_glossary_the)'),
    t('Data export'),
    t('ID'),
    t('Thesaurus List with Tree'),
    t('Título'),
    t('Entity Reference View Widget'),
    t('<div class="thesaurus_element_select">[entityreference_view_widget]</div><div class="thesaurus_element_select title">[title_field]</div>'),
  );
  $export['thesaurus'] = $view;

  return $export;
}
