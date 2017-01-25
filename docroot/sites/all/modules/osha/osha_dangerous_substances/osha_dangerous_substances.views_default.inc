<?php
/**
 * @file
 * osha_dangerous_substances.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_dangerous_substances_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dangerous_substances';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'dangerous-substances';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Dangerous substances';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Available in languages */
  $handler->display->display_options['fields']['field_available_in_languages']['id'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['table'] = 'field_data_field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['field'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['settings'] = array(
    'format' => array(
      'name' => 'name',
      'iso' => 0,
      'name_native' => 0,
    ),
  );
  $handler->display->display_options['fields']['field_available_in_languages']['delta_offset'] = '0';
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_material_country']['id'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['table'] = 'field_data_field_material_country';
  $handler->display->display_options['fields']['field_material_country']['field'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_material_country']['delta_offset'] = '0';
  /* Field: Content: Country other */
  $handler->display->display_options['fields']['field_country_other']['id'] = 'field_country_other';
  $handler->display->display_options['fields']['field_country_other']['table'] = 'field_data_field_country_other';
  $handler->display->display_options['fields']['field_country_other']['field'] = 'field_country_other';
  $handler->display->display_options['fields']['field_country_other']['type'] = 'text_plain';
  /* Field: Content: External URL */
  $handler->display->display_options['fields']['field_external_url']['id'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['table'] = 'field_data_field_external_url';
  $handler->display->display_options['fields']['field_external_url']['field'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_external_url']['type'] = 'link_title_plain';
  /* Field: Content: Provider (English) */
  $handler->display->display_options['fields']['field_provider']['id'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['table'] = 'field_data_field_provider';
  $handler->display->display_options['fields']['field_provider']['field'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['type'] = 'text_plain';
  /* Field: Content: Provider (Original) */
  $handler->display->display_options['fields']['field_provider_original']['id'] = 'field_provider_original';
  $handler->display->display_options['fields']['field_provider_original']['table'] = 'field_data_field_provider_original';
  $handler->display->display_options['fields']['field_provider_original']['field'] = 'field_provider_original';
  /* Field: Content: Provider URL */
  $handler->display->display_options['fields']['field_provider_url']['id'] = 'field_provider_url';
  $handler->display->display_options['fields']['field_provider_url']['table'] = 'field_data_field_provider_url';
  $handler->display->display_options['fields']['field_provider_url']['field'] = 'field_provider_url';
  $handler->display->display_options['fields']['field_provider_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_provider_url']['type'] = 'link_title_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Title (original) */
  $handler->display->display_options['fields']['field_title_original']['id'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['table'] = 'field_data_field_title_original';
  $handler->display->display_options['fields']['field_title_original']['field'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['type'] = 'text_plain';
  /* Field: Content: Type of item */
  $handler->display->display_options['fields']['field_item_type']['id'] = 'field_item_type';
  $handler->display->display_options['fields']['field_item_type']['table'] = 'field_data_field_item_type';
  $handler->display->display_options['fields']['field_item_type']['field'] = 'field_item_type';
  /* Field: Content: Type of provider */
  $handler->display->display_options['fields']['field_provider_type']['id'] = 'field_provider_type';
  $handler->display->display_options['fields']['field_provider_type']['table'] = 'field_data_field_provider_type';
  $handler->display->display_options['fields']['field_provider_type']['field'] = 'field_provider_type';
  $handler->display->display_options['fields']['field_provider_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_provider_type']['delta_offset'] = '0';
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
    'show_remaining_days' => 0,
    'osha_date_theme' => '',
  );
  /* Field: Content: Biological hazard */
  $handler->display->display_options['fields']['field_biological_hazard']['id'] = 'field_biological_hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['table'] = 'field_data_field_biological_hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['field'] = 'field_biological_hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_biological_hazard']['delta_offset'] = '0';
  /* Field: Content: Biological hazard other */
  $handler->display->display_options['fields']['field_biological_hazard_other']['id'] = 'field_biological_hazard_other';
  $handler->display->display_options['fields']['field_biological_hazard_other']['table'] = 'field_data_field_biological_hazard_other';
  $handler->display->display_options['fields']['field_biological_hazard_other']['field'] = 'field_biological_hazard_other';
  $handler->display->display_options['fields']['field_biological_hazard_other']['type'] = 'text_plain';
  /* Field: Content: Exposure route */
  $handler->display->display_options['fields']['field_exposure_route']['id'] = 'field_exposure_route';
  $handler->display->display_options['fields']['field_exposure_route']['table'] = 'field_data_field_exposure_route';
  $handler->display->display_options['fields']['field_exposure_route']['field'] = 'field_exposure_route';
  $handler->display->display_options['fields']['field_exposure_route']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_exposure_route']['delta_offset'] = '0';
  /* Field: Content: Hazard - health effects */
  $handler->display->display_options['fields']['field_hazard_health_effects']['id'] = 'field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['table'] = 'field_data_field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['field'] = 'field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_hazard_health_effects']['delta_offset'] = '0';
  /* Field: Content: Hazard - physical state */
  $handler->display->display_options['fields']['field_hazard_physical_state']['id'] = 'field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['table'] = 'field_data_field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['field'] = 'field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_hazard_physical_state']['delta_offset'] = '0';
  /* Field: Content: Tasks covered */
  $handler->display->display_options['fields']['field_tasks_covered']['id'] = 'field_tasks_covered';
  $handler->display->display_options['fields']['field_tasks_covered']['table'] = 'field_data_field_tasks_covered';
  $handler->display->display_options['fields']['field_tasks_covered']['field'] = 'field_tasks_covered';
  $handler->display->display_options['fields']['field_tasks_covered']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tasks_covered']['delta_offset'] = '0';
  /* Field: Content: Tasks covered other */
  $handler->display->display_options['fields']['field_tasks_other']['id'] = 'field_tasks_other';
  $handler->display->display_options['fields']['field_tasks_other']['table'] = 'field_data_field_tasks_other';
  $handler->display->display_options['fields']['field_tasks_other']['field'] = 'field_tasks_other';
  $handler->display->display_options['fields']['field_tasks_other']['type'] = 'text_plain';
  /* Field: Content: Advertising */
  $handler->display->display_options['fields']['field_advertising']['id'] = 'field_advertising';
  $handler->display->display_options['fields']['field_advertising']['table'] = 'field_data_field_advertising';
  $handler->display->display_options['fields']['field_advertising']['field'] = 'field_advertising';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: CAS Number */
  $handler->display->display_options['fields']['field_cas_number']['id'] = 'field_cas_number';
  $handler->display->display_options['fields']['field_cas_number']['table'] = 'field_data_field_cas_number';
  $handler->display->display_options['fields']['field_cas_number']['field'] = 'field_cas_number';
  $handler->display->display_options['fields']['field_cas_number']['type'] = 'text_plain';
  /* Field: Content: Contact address */
  $handler->display->display_options['fields']['field_contact_address']['id'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['table'] = 'field_data_field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['field'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['type'] = 'text_plain';
  /* Field: Content: Content (original language) */
  $handler->display->display_options['fields']['field_body_original']['id'] = 'field_body_original';
  $handler->display->display_options['fields']['field_body_original']['table'] = 'field_data_field_body_original';
  $handler->display->display_options['fields']['field_body_original']['field'] = 'field_body_original';
  $handler->display->display_options['fields']['field_body_original']['type'] = 'text_plain';
  /* Field: Content: Disclaimer */
  $handler->display->display_options['fields']['field_disclaimer']['id'] = 'field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['table'] = 'field_data_field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['field'] = 'field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['type'] = 'text_plain';
  /* Field: Content: EC number */
  $handler->display->display_options['fields']['field_ec_number']['id'] = 'field_ec_number';
  $handler->display->display_options['fields']['field_ec_number']['table'] = 'field_data_field_ec_number';
  $handler->display->display_options['fields']['field_ec_number']['field'] = 'field_ec_number';
  $handler->display->display_options['fields']['field_ec_number']['type'] = 'text_plain';
  /* Field: Content: Evaluation */
  $handler->display->display_options['fields']['field_evaluation']['id'] = 'field_evaluation';
  $handler->display->display_options['fields']['field_evaluation']['table'] = 'field_data_field_evaluation';
  $handler->display->display_options['fields']['field_evaluation']['field'] = 'field_evaluation';
  $handler->display->display_options['fields']['field_evaluation']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_evaluation']['delta_offset'] = '0';
  /* Field: Content: Format, quality (audio track bit rate, video track bit rate) */
  $handler->display->display_options['fields']['field_media_format']['id'] = 'field_media_format';
  $handler->display->display_options['fields']['field_media_format']['table'] = 'field_data_field_media_format';
  $handler->display->display_options['fields']['field_media_format']['field'] = 'field_media_format';
  $handler->display->display_options['fields']['field_media_format']['type'] = 'text_plain';
  /* Field: Content: Intellectual property rights */
  $handler->display->display_options['fields']['field_intellectual_property_righ']['id'] = 'field_intellectual_property_righ';
  $handler->display->display_options['fields']['field_intellectual_property_righ']['table'] = 'field_data_field_intellectual_property_righ';
  $handler->display->display_options['fields']['field_intellectual_property_righ']['field'] = 'field_intellectual_property_righ';
  /* Field: Content: Length of the video */
  $handler->display->display_options['fields']['field_video_length']['id'] = 'field_video_length';
  $handler->display->display_options['fields']['field_video_length']['table'] = 'field_data_field_video_length';
  $handler->display->display_options['fields']['field_video_length']['field'] = 'field_video_length';
  /* Field: Content: Measurement method */
  $handler->display->display_options['fields']['field_measurement_method']['id'] = 'field_measurement_method';
  $handler->display->display_options['fields']['field_measurement_method']['table'] = 'field_data_field_measurement_method';
  $handler->display->display_options['fields']['field_measurement_method']['field'] = 'field_measurement_method';
  $handler->display->display_options['fields']['field_measurement_method']['type'] = 'text_plain';
  /* Field: Content: Objective of material */
  $handler->display->display_options['fields']['field_material_objective_type']['id'] = 'field_material_objective_type';
  $handler->display->display_options['fields']['field_material_objective_type']['table'] = 'field_data_field_material_objective_type';
  $handler->display->display_options['fields']['field_material_objective_type']['field'] = 'field_material_objective_type';
  $handler->display->display_options['fields']['field_material_objective_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_material_objective_type']['delta_offset'] = '0';
  /* Field: Content: Objective of material other */
  $handler->display->display_options['fields']['field_material_objective_other']['id'] = 'field_material_objective_other';
  $handler->display->display_options['fields']['field_material_objective_other']['table'] = 'field_data_field_material_objective_other';
  $handler->display->display_options['fields']['field_material_objective_other']['field'] = 'field_material_objective_other';
  $handler->display->display_options['fields']['field_material_objective_other']['label'] = 'Other objective of the material';
  $handler->display->display_options['fields']['field_material_objective_other']['type'] = 'text_plain';
  /* Field: Content: Other information */
  $handler->display->display_options['fields']['field_other_information']['id'] = 'field_other_information';
  $handler->display->display_options['fields']['field_other_information']['table'] = 'field_data_field_other_information';
  $handler->display->display_options['fields']['field_other_information']['field'] = 'field_other_information';
  $handler->display->display_options['fields']['field_other_information']['type'] = 'text_plain';
  /* Field: Content: Ownership information */
  $handler->display->display_options['fields']['field_ownership_information']['id'] = 'field_ownership_information';
  $handler->display->display_options['fields']['field_ownership_information']['table'] = 'field_data_field_ownership_information';
  $handler->display->display_options['fields']['field_ownership_information']['field'] = 'field_ownership_information';
  $handler->display->display_options['fields']['field_ownership_information']['type'] = 'text_plain';
  /* Field: Content: Prevention measures */
  $handler->display->display_options['fields']['field_prevention_measure_type']['id'] = 'field_prevention_measure_type';
  $handler->display->display_options['fields']['field_prevention_measure_type']['table'] = 'field_data_field_prevention_measure_type';
  $handler->display->display_options['fields']['field_prevention_measure_type']['field'] = 'field_prevention_measure_type';
  $handler->display->display_options['fields']['field_prevention_measure_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_prevention_measure_type']['delta_offset'] = '0';
  /* Field: Content: Prevention measures other */
  $handler->display->display_options['fields']['field_prevention_measures_other']['id'] = 'field_prevention_measures_other';
  $handler->display->display_options['fields']['field_prevention_measures_other']['table'] = 'field_data_field_prevention_measures_other';
  $handler->display->display_options['fields']['field_prevention_measures_other']['field'] = 'field_prevention_measures_other';
  $handler->display->display_options['fields']['field_prevention_measures_other']['type'] = 'text_plain';
  /* Field: Content: Purpose of the material */
  $handler->display->display_options['fields']['field_material_purpose_type']['id'] = 'field_material_purpose_type';
  $handler->display->display_options['fields']['field_material_purpose_type']['table'] = 'field_data_field_material_purpose_type';
  $handler->display->display_options['fields']['field_material_purpose_type']['field'] = 'field_material_purpose_type';
  $handler->display->display_options['fields']['field_material_purpose_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_material_purpose_type']['delta_offset'] = '0';
  /* Field: Content: Rights description */
  $handler->display->display_options['fields']['field_rights_description']['id'] = 'field_rights_description';
  $handler->display->display_options['fields']['field_rights_description']['table'] = 'field_data_field_rights_description';
  $handler->display->display_options['fields']['field_rights_description']['field'] = 'field_rights_description';
  $handler->display->display_options['fields']['field_rights_description']['type'] = 'text_plain';
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['type'] = 'text_plain';
  /* Field: Content: Target group */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_target_group']['delta_offset'] = '0';
  /* Field: Content: Type of visualisation material */
  $handler->display->display_options['fields']['field_visualisation_material_typ']['id'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['table'] = 'field_data_field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['field'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['delta_offset'] = '0';
  /* Field: Content: Worker groups covered (vulnerable groups etc.) */
  $handler->display->display_options['fields']['field_worker_groups_type']['id'] = 'field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['table'] = 'field_data_field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['field'] = 'field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_worker_groups_type']['delta_offset'] = '0';
  /* Field: Content: Priority area */
  $handler->display->display_options['fields']['field_priority_area']['id'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['table'] = 'field_data_field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['field'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_priority_area']['delta_offset'] = '0';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'contact_file_download_link';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'dangerous_substances' => 'dangerous_substances',
  );
  /* Filter criterion: Content: Available in languages (field_available_in_languages) */
  $handler->display->display_options['filters']['field_available_in_languages_value']['id'] = 'field_available_in_languages_value';
  $handler->display->display_options['filters']['field_available_in_languages_value']['table'] = 'field_data_field_available_in_languages';
  $handler->display->display_options['filters']['field_available_in_languages_value']['field'] = 'field_available_in_languages_value';
  $handler->display->display_options['filters']['field_available_in_languages_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_available_in_languages_value']['expose']['operator_id'] = 'field_available_in_languages_value_op';
  $handler->display->display_options['filters']['field_available_in_languages_value']['expose']['label'] = 'Available in languages';
  $handler->display->display_options['filters']['field_available_in_languages_value']['expose']['operator'] = 'field_available_in_languages_value_op';
  $handler->display->display_options['filters']['field_available_in_languages_value']['expose']['identifier'] = 'field_available_in_languages_value';
  $handler->display->display_options['filters']['field_available_in_languages_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Country (field_material_country) */
  $handler->display->display_options['filters']['field_material_country_tid']['id'] = 'field_material_country_tid';
  $handler->display->display_options['filters']['field_material_country_tid']['table'] = 'field_data_field_material_country';
  $handler->display->display_options['filters']['field_material_country_tid']['field'] = 'field_material_country_tid';
  $handler->display->display_options['filters']['field_material_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_material_country_tid']['expose']['operator_id'] = 'field_material_country_tid_op';
  $handler->display->display_options['filters']['field_material_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_material_country_tid']['expose']['operator'] = 'field_material_country_tid_op';
  $handler->display->display_options['filters']['field_material_country_tid']['expose']['identifier'] = 'field_material_country_tid';
  $handler->display->display_options['filters']['field_material_country_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_material_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_material_country_tid']['vocabulary'] = 'country';
  /* Filter criterion: Content: Sector / Industry covered (field_sector_industry_covered) */
  $handler->display->display_options['filters']['field_sector_industry_covered_tid']['id'] = 'field_sector_industry_covered_tid';
  $handler->display->display_options['filters']['field_sector_industry_covered_tid']['table'] = 'field_data_field_sector_industry_covered';
  $handler->display->display_options['filters']['field_sector_industry_covered_tid']['field'] = 'field_sector_industry_covered_tid';
  $handler->display->display_options['filters']['field_sector_industry_covered_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sector_industry_covered_tid']['expose']['operator_id'] = 'field_sector_industry_covered_tid_op';
  $handler->display->display_options['filters']['field_sector_industry_covered_tid']['expose']['label'] = 'Sector / Industry covered (field_sector_industry_covered)';
  $handler->display->display_options['filters']['field_sector_industry_covered_tid']['expose']['operator'] = 'field_sector_industry_covered_tid_op';
  $handler->display->display_options['filters']['field_sector_industry_covered_tid']['expose']['identifier'] = 'field_sector_industry_covered_tid';
  $handler->display->display_options['filters']['field_sector_industry_covered_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_sector_industry_covered_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sector_industry_covered_tid']['vocabulary'] = 'nace_codes';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Available in languages */
  $handler->display->display_options['fields']['field_available_in_languages']['id'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['table'] = 'field_data_field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['field'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['settings'] = array(
    'format' => array(
      'name' => 'name',
      'iso' => 0,
      'name_native' => 0,
    ),
  );
  $handler->display->display_options['fields']['field_available_in_languages']['delta_offset'] = '0';
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_material_country']['id'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['table'] = 'field_data_field_material_country';
  $handler->display->display_options['fields']['field_material_country']['field'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_material_country']['delta_offset'] = '0';
  /* Field: Content: Country other */
  $handler->display->display_options['fields']['field_country_other']['id'] = 'field_country_other';
  $handler->display->display_options['fields']['field_country_other']['table'] = 'field_data_field_country_other';
  $handler->display->display_options['fields']['field_country_other']['field'] = 'field_country_other';
  $handler->display->display_options['fields']['field_country_other']['type'] = 'text_plain';
  /* Field: Content: External URL */
  $handler->display->display_options['fields']['field_external_url']['id'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['table'] = 'field_data_field_external_url';
  $handler->display->display_options['fields']['field_external_url']['field'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_external_url']['type'] = 'link_title_plain';
  /* Field: Content: Provider (English) */
  $handler->display->display_options['fields']['field_provider']['id'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['table'] = 'field_data_field_provider';
  $handler->display->display_options['fields']['field_provider']['field'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['type'] = 'text_plain';
  /* Field: Content: Provider (Original) */
  $handler->display->display_options['fields']['field_provider_original']['id'] = 'field_provider_original';
  $handler->display->display_options['fields']['field_provider_original']['table'] = 'field_data_field_provider_original';
  $handler->display->display_options['fields']['field_provider_original']['field'] = 'field_provider_original';
  /* Field: Content: Provider URL */
  $handler->display->display_options['fields']['field_provider_url']['id'] = 'field_provider_url';
  $handler->display->display_options['fields']['field_provider_url']['table'] = 'field_data_field_provider_url';
  $handler->display->display_options['fields']['field_provider_url']['field'] = 'field_provider_url';
  $handler->display->display_options['fields']['field_provider_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_provider_url']['type'] = 'link_title_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Title (original) */
  $handler->display->display_options['fields']['field_title_original']['id'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['table'] = 'field_data_field_title_original';
  $handler->display->display_options['fields']['field_title_original']['field'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['type'] = 'text_plain';
  /* Field: Content: Type of item */
  $handler->display->display_options['fields']['field_item_type']['id'] = 'field_item_type';
  $handler->display->display_options['fields']['field_item_type']['table'] = 'field_data_field_item_type';
  $handler->display->display_options['fields']['field_item_type']['field'] = 'field_item_type';
  /* Field: Content: Type of provider */
  $handler->display->display_options['fields']['field_provider_type']['id'] = 'field_provider_type';
  $handler->display->display_options['fields']['field_provider_type']['table'] = 'field_data_field_provider_type';
  $handler->display->display_options['fields']['field_provider_type']['field'] = 'field_provider_type';
  $handler->display->display_options['fields']['field_provider_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_provider_type']['delta_offset'] = '0';
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
    'show_remaining_days' => 0,
    'osha_date_theme' => '',
  );
  /* Field: Content: Biological hazard */
  $handler->display->display_options['fields']['field_biological_hazard']['id'] = 'field_biological_hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['table'] = 'field_data_field_biological_hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['field'] = 'field_biological_hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_biological_hazard']['delta_offset'] = '0';
  /* Field: Content: Biological hazard other */
  $handler->display->display_options['fields']['field_biological_hazard_other']['id'] = 'field_biological_hazard_other';
  $handler->display->display_options['fields']['field_biological_hazard_other']['table'] = 'field_data_field_biological_hazard_other';
  $handler->display->display_options['fields']['field_biological_hazard_other']['field'] = 'field_biological_hazard_other';
  $handler->display->display_options['fields']['field_biological_hazard_other']['type'] = 'text_plain';
  /* Field: Content: Exposure route */
  $handler->display->display_options['fields']['field_exposure_route']['id'] = 'field_exposure_route';
  $handler->display->display_options['fields']['field_exposure_route']['table'] = 'field_data_field_exposure_route';
  $handler->display->display_options['fields']['field_exposure_route']['field'] = 'field_exposure_route';
  $handler->display->display_options['fields']['field_exposure_route']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_exposure_route']['delta_offset'] = '0';
  /* Field: Content: Hazard - health effects */
  $handler->display->display_options['fields']['field_hazard_health_effects']['id'] = 'field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['table'] = 'field_data_field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['field'] = 'field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_hazard_health_effects']['delta_offset'] = '0';
  /* Field: Content: Hazard - physical state */
  $handler->display->display_options['fields']['field_hazard_physical_state']['id'] = 'field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['table'] = 'field_data_field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['field'] = 'field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_hazard_physical_state']['delta_offset'] = '0';
  /* Field: Content: Tasks covered */
  $handler->display->display_options['fields']['field_tasks_covered']['id'] = 'field_tasks_covered';
  $handler->display->display_options['fields']['field_tasks_covered']['table'] = 'field_data_field_tasks_covered';
  $handler->display->display_options['fields']['field_tasks_covered']['field'] = 'field_tasks_covered';
  $handler->display->display_options['fields']['field_tasks_covered']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tasks_covered']['delta_offset'] = '0';
  /* Field: Content: Tasks covered other */
  $handler->display->display_options['fields']['field_tasks_other']['id'] = 'field_tasks_other';
  $handler->display->display_options['fields']['field_tasks_other']['table'] = 'field_data_field_tasks_other';
  $handler->display->display_options['fields']['field_tasks_other']['field'] = 'field_tasks_other';
  $handler->display->display_options['fields']['field_tasks_other']['type'] = 'text_plain';
  /* Field: Content: Advertising */
  $handler->display->display_options['fields']['field_advertising']['id'] = 'field_advertising';
  $handler->display->display_options['fields']['field_advertising']['table'] = 'field_data_field_advertising';
  $handler->display->display_options['fields']['field_advertising']['field'] = 'field_advertising';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: CAS Number */
  $handler->display->display_options['fields']['field_cas_number']['id'] = 'field_cas_number';
  $handler->display->display_options['fields']['field_cas_number']['table'] = 'field_data_field_cas_number';
  $handler->display->display_options['fields']['field_cas_number']['field'] = 'field_cas_number';
  $handler->display->display_options['fields']['field_cas_number']['type'] = 'text_plain';
  /* Field: Content: Contact address */
  $handler->display->display_options['fields']['field_contact_address']['id'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['table'] = 'field_data_field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['field'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['type'] = 'text_plain';
  /* Field: Content: Content (original language) */
  $handler->display->display_options['fields']['field_body_original']['id'] = 'field_body_original';
  $handler->display->display_options['fields']['field_body_original']['table'] = 'field_data_field_body_original';
  $handler->display->display_options['fields']['field_body_original']['field'] = 'field_body_original';
  $handler->display->display_options['fields']['field_body_original']['type'] = 'text_plain';
  /* Field: Content: Disclaimer */
  $handler->display->display_options['fields']['field_disclaimer']['id'] = 'field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['table'] = 'field_data_field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['field'] = 'field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['type'] = 'text_plain';
  /* Field: Content: EC number */
  $handler->display->display_options['fields']['field_ec_number']['id'] = 'field_ec_number';
  $handler->display->display_options['fields']['field_ec_number']['table'] = 'field_data_field_ec_number';
  $handler->display->display_options['fields']['field_ec_number']['field'] = 'field_ec_number';
  $handler->display->display_options['fields']['field_ec_number']['type'] = 'text_plain';
  /* Field: Content: Evaluation */
  $handler->display->display_options['fields']['field_evaluation']['id'] = 'field_evaluation';
  $handler->display->display_options['fields']['field_evaluation']['table'] = 'field_data_field_evaluation';
  $handler->display->display_options['fields']['field_evaluation']['field'] = 'field_evaluation';
  $handler->display->display_options['fields']['field_evaluation']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_evaluation']['delta_offset'] = '0';
  /* Field: Content: Format, quality (audio track bit rate, video track bit rate) */
  $handler->display->display_options['fields']['field_media_format']['id'] = 'field_media_format';
  $handler->display->display_options['fields']['field_media_format']['table'] = 'field_data_field_media_format';
  $handler->display->display_options['fields']['field_media_format']['field'] = 'field_media_format';
  $handler->display->display_options['fields']['field_media_format']['type'] = 'text_plain';
  /* Field: Content: Intellectual property rights */
  $handler->display->display_options['fields']['field_intellectual_property_righ']['id'] = 'field_intellectual_property_righ';
  $handler->display->display_options['fields']['field_intellectual_property_righ']['table'] = 'field_data_field_intellectual_property_righ';
  $handler->display->display_options['fields']['field_intellectual_property_righ']['field'] = 'field_intellectual_property_righ';
  /* Field: Content: Length of the video */
  $handler->display->display_options['fields']['field_video_length']['id'] = 'field_video_length';
  $handler->display->display_options['fields']['field_video_length']['table'] = 'field_data_field_video_length';
  $handler->display->display_options['fields']['field_video_length']['field'] = 'field_video_length';
  /* Field: Content: Measurement method */
  $handler->display->display_options['fields']['field_measurement_method']['id'] = 'field_measurement_method';
  $handler->display->display_options['fields']['field_measurement_method']['table'] = 'field_data_field_measurement_method';
  $handler->display->display_options['fields']['field_measurement_method']['field'] = 'field_measurement_method';
  $handler->display->display_options['fields']['field_measurement_method']['type'] = 'text_plain';
  /* Field: Content: Objective of material */
  $handler->display->display_options['fields']['field_material_objective_type']['id'] = 'field_material_objective_type';
  $handler->display->display_options['fields']['field_material_objective_type']['table'] = 'field_data_field_material_objective_type';
  $handler->display->display_options['fields']['field_material_objective_type']['field'] = 'field_material_objective_type';
  $handler->display->display_options['fields']['field_material_objective_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_material_objective_type']['delta_offset'] = '0';
  /* Field: Content: Objective of material other */
  $handler->display->display_options['fields']['field_material_objective_other']['id'] = 'field_material_objective_other';
  $handler->display->display_options['fields']['field_material_objective_other']['table'] = 'field_data_field_material_objective_other';
  $handler->display->display_options['fields']['field_material_objective_other']['field'] = 'field_material_objective_other';
  $handler->display->display_options['fields']['field_material_objective_other']['label'] = 'Other objective of the material';
  $handler->display->display_options['fields']['field_material_objective_other']['type'] = 'text_plain';
  /* Field: Content: Other information */
  $handler->display->display_options['fields']['field_other_information']['id'] = 'field_other_information';
  $handler->display->display_options['fields']['field_other_information']['table'] = 'field_data_field_other_information';
  $handler->display->display_options['fields']['field_other_information']['field'] = 'field_other_information';
  $handler->display->display_options['fields']['field_other_information']['type'] = 'text_plain';
  /* Field: Content: Ownership information */
  $handler->display->display_options['fields']['field_ownership_information']['id'] = 'field_ownership_information';
  $handler->display->display_options['fields']['field_ownership_information']['table'] = 'field_data_field_ownership_information';
  $handler->display->display_options['fields']['field_ownership_information']['field'] = 'field_ownership_information';
  $handler->display->display_options['fields']['field_ownership_information']['type'] = 'text_plain';
  /* Field: Content: Prevention measures */
  $handler->display->display_options['fields']['field_prevention_measure_type']['id'] = 'field_prevention_measure_type';
  $handler->display->display_options['fields']['field_prevention_measure_type']['table'] = 'field_data_field_prevention_measure_type';
  $handler->display->display_options['fields']['field_prevention_measure_type']['field'] = 'field_prevention_measure_type';
  $handler->display->display_options['fields']['field_prevention_measure_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_prevention_measure_type']['delta_offset'] = '0';
  /* Field: Content: Prevention measures other */
  $handler->display->display_options['fields']['field_prevention_measures_other']['id'] = 'field_prevention_measures_other';
  $handler->display->display_options['fields']['field_prevention_measures_other']['table'] = 'field_data_field_prevention_measures_other';
  $handler->display->display_options['fields']['field_prevention_measures_other']['field'] = 'field_prevention_measures_other';
  $handler->display->display_options['fields']['field_prevention_measures_other']['type'] = 'text_plain';
  /* Field: Content: Purpose of the material */
  $handler->display->display_options['fields']['field_material_purpose_type']['id'] = 'field_material_purpose_type';
  $handler->display->display_options['fields']['field_material_purpose_type']['table'] = 'field_data_field_material_purpose_type';
  $handler->display->display_options['fields']['field_material_purpose_type']['field'] = 'field_material_purpose_type';
  $handler->display->display_options['fields']['field_material_purpose_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_material_purpose_type']['delta_offset'] = '0';
  /* Field: Content: Rights description */
  $handler->display->display_options['fields']['field_rights_description']['id'] = 'field_rights_description';
  $handler->display->display_options['fields']['field_rights_description']['table'] = 'field_data_field_rights_description';
  $handler->display->display_options['fields']['field_rights_description']['field'] = 'field_rights_description';
  $handler->display->display_options['fields']['field_rights_description']['type'] = 'text_plain';
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['type'] = 'text_plain';
  /* Field: Content: Target group */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_target_group']['delta_offset'] = '0';
  /* Field: Content: Type of visualisation material */
  $handler->display->display_options['fields']['field_visualisation_material_typ']['id'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['table'] = 'field_data_field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['field'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['delta_offset'] = '0';
  /* Field: Content: Worker groups covered (vulnerable groups etc.) */
  $handler->display->display_options['fields']['field_worker_groups_type']['id'] = 'field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['table'] = 'field_data_field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['field'] = 'field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_worker_groups_type']['delta_offset'] = '0';
  /* Field: Content: Priority area */
  $handler->display->display_options['fields']['field_priority_area']['id'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['table'] = 'field_data_field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['field'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_priority_area']['delta_offset'] = '0';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'contact_file_download_link';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['path'] = 'dangerous-substances';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'osha_dangerous_substances.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'dangerous-substances/xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['dangerous_substances'] = array(
    t('Master'),
    t('Dangerous substances'),
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
    t('Title'),
    t('Available in languages'),
    t('Country'),
    t('Country other'),
    t('External URL'),
    t('Provider (English)'),
    t('Provider (Original)'),
    t('Provider URL'),
    t('Title (original)'),
    t('Type of item'),
    t('Type of provider'),
    t('Publication date'),
    t('Biological hazard'),
    t('Biological hazard other'),
    t('Exposure route'),
    t('Hazard - health effects'),
    t('Hazard - physical state'),
    t('Tasks covered'),
    t('Tasks covered other'),
    t('Advertising'),
    t('Body'),
    t('CAS Number'),
    t('Contact address'),
    t('Content (original language)'),
    t('Disclaimer'),
    t('EC number'),
    t('Evaluation'),
    t('Format, quality (audio track bit rate, video track bit rate)'),
    t('Intellectual property rights'),
    t('Length of the video'),
    t('Measurement method'),
    t('Objective of material'),
    t('Other objective of the material'),
    t('Other information'),
    t('Ownership information'),
    t('Prevention measures'),
    t('Prevention measures other'),
    t('Purpose of the material'),
    t('Rights description'),
    t('Summary'),
    t('Target group'),
    t('Type of visualisation material'),
    t('Worker groups covered (vulnerable groups etc.)'),
    t('Priority area'),
    t('Image'),
    t('Sector / Industry covered (field_sector_industry_covered)'),
    t('Page'),
    t('Edit link'),
    t('Data export'),
  );
  $export['dangerous_substances'] = $view;

  $view = new view();
  $view->name = 'dangerous_substances_overview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_content_index';
  $view->human_name = 'dangerous substances overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Dangerous substances';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    14 => '14',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['parse_mode'] = 'direct';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'osha_search_teaser';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['search_api_et_id']['id'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  /* Sort criterion: Indexed Content: Publication date */
  $handler->display->display_options['sorts']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['sorts']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_publication_date']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_publication_date']['expose']['label'] = 'Publication date';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  $handler->display->display_options['sorts']['search_api_relevance']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['search_api_relevance']['expose']['label'] = 'Relevance';
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dangerous_substances' => 'dangerous_substances',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'text';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Type of item */
  $handler->display->display_options['filters']['field_item_type']['id'] = 'field_item_type';
  $handler->display->display_options['filters']['field_item_type']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['filters']['field_item_type']['field'] = 'field_item_type';
  $handler->display->display_options['filters']['field_item_type']['value'] = array(
    'MS material' => 'MS material',
    'EU material' => 'EU material',
    'Audiovisual' => 'Audiovisual',
    'Case study' => 'Case study',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'themes/dangerous-substances/search';
  $translatables['dangerous_substances_overview'] = array(
    t('Master'),
    t('Dangerous substances'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹'),
    t('›'),
    t('last »'),
    t('No results'),
    t('Broken handler search_api_index_default_content_index.search_api_et_id'),
    t('Publication date'),
    t('Relevance'),
    t('Page'),
  );
  $export['dangerous_substances_overview'] = $view;

  return $export;
}
