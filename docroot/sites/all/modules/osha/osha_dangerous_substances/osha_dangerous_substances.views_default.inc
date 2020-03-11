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
    14 => '14',
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
  /* Field: Content: Title (original) */
  $handler->display->display_options['fields']['field_title_original']['id'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['table'] = 'field_data_field_title_original';
  $handler->display->display_options['fields']['field_title_original']['field'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['type'] = 'text_plain';
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
  /* Field: Content: Languages other */
  $handler->display->display_options['fields']['field_languages_other']['id'] = 'field_languages_other';
  $handler->display->display_options['fields']['field_languages_other']['table'] = 'field_data_field_languages_other';
  $handler->display->display_options['fields']['field_languages_other']['field'] = 'field_languages_other';
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
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_external_url']['id'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['table'] = 'field_data_field_external_url';
  $handler->display->display_options['fields']['field_external_url']['field'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_external_url']['type'] = 'link_title_plain';
  /* Field: Content: Type of item */
  $handler->display->display_options['fields']['field_item_type']['id'] = 'field_item_type';
  $handler->display->display_options['fields']['field_item_type']['table'] = 'field_data_field_item_type';
  $handler->display->display_options['fields']['field_item_type']['field'] = 'field_item_type';
  /* Field: Content: Date of Publication / Year  */
  $handler->display->display_options['fields']['field_publication_year']['id'] = 'field_publication_year';
  $handler->display->display_options['fields']['field_publication_year']['table'] = 'field_data_field_publication_year';
  $handler->display->display_options['fields']['field_publication_year']['field'] = 'field_publication_year';
  $handler->display->display_options['fields']['field_publication_year']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'osha_date_theme' => '',
  );
  /* Field: Content: Sector / Industry covered other */
  $handler->display->display_options['fields']['field_sector_industry_other']['id'] = 'field_sector_industry_other';
  $handler->display->display_options['fields']['field_sector_industry_other']['table'] = 'field_data_field_sector_industry_other';
  $handler->display->display_options['fields']['field_sector_industry_other']['field'] = 'field_sector_industry_other';
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
  /* Field: Content: Exposure route other */
  $handler->display->display_options['fields']['field_exposure_route_other']['id'] = 'field_exposure_route_other';
  $handler->display->display_options['fields']['field_exposure_route_other']['table'] = 'field_data_field_exposure_route_other';
  $handler->display->display_options['fields']['field_exposure_route_other']['field'] = 'field_exposure_route_other';
  /* Field: Content: Hazard - health effects */
  $handler->display->display_options['fields']['field_hazard_health_effects']['id'] = 'field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['table'] = 'field_data_field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['field'] = 'field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_hazard_health_effects']['delta_offset'] = '0';
  /* Field: Content: Health effects other */
  $handler->display->display_options['fields']['field_hazard_health_other']['id'] = 'field_hazard_health_other';
  $handler->display->display_options['fields']['field_hazard_health_other']['table'] = 'field_data_field_hazard_health_other';
  $handler->display->display_options['fields']['field_hazard_health_other']['field'] = 'field_hazard_health_other';
  /* Field: Content: Hazard - physical state */
  $handler->display->display_options['fields']['field_hazard_physical_state']['id'] = 'field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['table'] = 'field_data_field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['field'] = 'field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_hazard_physical_state']['delta_offset'] = '0';
  /* Field: Content: Hazard - physical state other */
  $handler->display->display_options['fields']['field_hazard_physical_other']['id'] = 'field_hazard_physical_other';
  $handler->display->display_options['fields']['field_hazard_physical_other']['table'] = 'field_data_field_hazard_physical_other';
  $handler->display->display_options['fields']['field_hazard_physical_other']['field'] = 'field_hazard_physical_other';
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
  /* Field: Content: Description (original language) */
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
  /* Field: Content: Evaluation other */
  $handler->display->display_options['fields']['field_evaluation_other']['id'] = 'field_evaluation_other';
  $handler->display->display_options['fields']['field_evaluation_other']['table'] = 'field_data_field_evaluation_other';
  $handler->display->display_options['fields']['field_evaluation_other']['field'] = 'field_evaluation_other';
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
  /* Field: Content: Purpose of the material other */
  $handler->display->display_options['fields']['field_material_purpose_other']['id'] = 'field_material_purpose_other';
  $handler->display->display_options['fields']['field_material_purpose_other']['table'] = 'field_data_field_material_purpose_other';
  $handler->display->display_options['fields']['field_material_purpose_other']['field'] = 'field_material_purpose_other';
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
  /* Field: Content: Target audiences other */
  $handler->display->display_options['fields']['field_target_group_other']['id'] = 'field_target_group_other';
  $handler->display->display_options['fields']['field_target_group_other']['table'] = 'field_data_field_target_group_other';
  $handler->display->display_options['fields']['field_target_group_other']['field'] = 'field_target_group_other';
  /* Field: Content: Type of visualisation material */
  $handler->display->display_options['fields']['field_visualisation_material_typ']['id'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['table'] = 'field_data_field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['field'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['delta_offset'] = '0';
  /* Field: Content: Type of visualisation material other */
  $handler->display->display_options['fields']['field_visualisation_mat_other']['id'] = 'field_visualisation_mat_other';
  $handler->display->display_options['fields']['field_visualisation_mat_other']['table'] = 'field_data_field_visualisation_mat_other';
  $handler->display->display_options['fields']['field_visualisation_mat_other']['field'] = 'field_visualisation_mat_other';
  /* Field: Content: Worker groups covered (vulnerable groups etc.) */
  $handler->display->display_options['fields']['field_worker_groups_type']['id'] = 'field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['table'] = 'field_data_field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['field'] = 'field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_worker_groups_type']['delta_offset'] = '0';
  /* Field: Content: Worker groups covered other */
  $handler->display->display_options['fields']['field_worker_groups_other']['id'] = 'field_worker_groups_other';
  $handler->display->display_options['fields']['field_worker_groups_other']['table'] = 'field_data_field_worker_groups_other';
  $handler->display->display_options['fields']['field_worker_groups_other']['field'] = 'field_worker_groups_other';
  /* Field: Content: Priority area */
  $handler->display->display_options['fields']['field_priority_area']['id'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['table'] = 'field_data_field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['field'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_priority_area']['delta_offset'] = '0';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'contact_file_download_link';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Provider */
  $handler->display->display_options['fields']['field_fc_provider']['id'] = 'field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['table'] = 'field_data_field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['field'] = 'field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['settings'] = array(
    'edit' => 'Edit',
    'delete' => 'Delete',
    'add' => 'Add',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_fc_provider']['delta_offset'] = '0';
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
  $handler->display->display_options['path'] = 'dangerous-substances';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'osha_dangerous_substances_doc';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Title (original) */
  $handler->display->display_options['fields']['field_title_original']['id'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['table'] = 'field_data_field_title_original';
  $handler->display->display_options['fields']['field_title_original']['field'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['ui_name'] = 'Title (original)';
  $handler->display->display_options['fields']['field_title_original']['type'] = 'text_plain';
  /* Field: Available in languages */
  $handler->display->display_options['fields']['field_available_in_languages']['id'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['table'] = 'field_data_field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['field'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['ui_name'] = 'Available in languages';
  $handler->display->display_options['fields']['field_available_in_languages']['settings'] = array(
    'format' => array(
      'name' => 'name',
      'iso' => 0,
      'name_native' => 0,
    ),
  );
  $handler->display->display_options['fields']['field_available_in_languages']['delta_offset'] = '0';
  /* Field: Available in languages (other) */
  $handler->display->display_options['fields']['field_languages_other']['id'] = 'field_languages_other';
  $handler->display->display_options['fields']['field_languages_other']['table'] = 'field_data_field_languages_other';
  $handler->display->display_options['fields']['field_languages_other']['field'] = 'field_languages_other';
  $handler->display->display_options['fields']['field_languages_other']['ui_name'] = 'Available in languages (other)';
  /* Field: Country */
  $handler->display->display_options['fields']['field_material_country']['id'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['table'] = 'field_data_field_material_country';
  $handler->display->display_options['fields']['field_material_country']['field'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['ui_name'] = 'Country';
  $handler->display->display_options['fields']['field_material_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_material_country']['delta_offset'] = '0';
  /* Field: Country other */
  $handler->display->display_options['fields']['field_country_other']['id'] = 'field_country_other';
  $handler->display->display_options['fields']['field_country_other']['table'] = 'field_data_field_country_other';
  $handler->display->display_options['fields']['field_country_other']['field'] = 'field_country_other';
  $handler->display->display_options['fields']['field_country_other']['ui_name'] = 'Country other';
  $handler->display->display_options['fields']['field_country_other']['type'] = 'text_plain';
  /* Field: External URL */
  $handler->display->display_options['fields']['field_external_url']['id'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['table'] = 'field_data_field_external_url';
  $handler->display->display_options['fields']['field_external_url']['field'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['ui_name'] = 'External URL';
  $handler->display->display_options['fields']['field_external_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_external_url']['type'] = 'link_title_plain';
  /* Field: Type of item */
  $handler->display->display_options['fields']['field_item_type']['id'] = 'field_item_type';
  $handler->display->display_options['fields']['field_item_type']['table'] = 'field_data_field_item_type';
  $handler->display->display_options['fields']['field_item_type']['field'] = 'field_item_type';
  $handler->display->display_options['fields']['field_item_type']['ui_name'] = 'Type of item';
  /* Field: Publication year */
  $handler->display->display_options['fields']['field_publication_year']['id'] = 'field_publication_year';
  $handler->display->display_options['fields']['field_publication_year']['table'] = 'field_data_field_publication_year';
  $handler->display->display_options['fields']['field_publication_year']['field'] = 'field_publication_year';
  $handler->display->display_options['fields']['field_publication_year']['ui_name'] = 'Publication year';
  $handler->display->display_options['fields']['field_publication_year']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_publication_year']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'osha_date_theme' => '',
  );
  /* Field: Sector / Industry covered other */
  $handler->display->display_options['fields']['field_sector_industry_other']['id'] = 'field_sector_industry_other';
  $handler->display->display_options['fields']['field_sector_industry_other']['table'] = 'field_data_field_sector_industry_other';
  $handler->display->display_options['fields']['field_sector_industry_other']['field'] = 'field_sector_industry_other';
  $handler->display->display_options['fields']['field_sector_industry_other']['ui_name'] = 'Sector / Industry covered other';
  /* Field: Biological hazard */
  $handler->display->display_options['fields']['field_biological_hazard']['id'] = 'field_biological_hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['table'] = 'field_data_field_biological_hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['field'] = 'field_biological_hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['ui_name'] = 'Biological hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_biological_hazard']['delta_offset'] = '0';
  /* Field: Biological hazard other */
  $handler->display->display_options['fields']['field_biological_hazard_other']['id'] = 'field_biological_hazard_other';
  $handler->display->display_options['fields']['field_biological_hazard_other']['table'] = 'field_data_field_biological_hazard_other';
  $handler->display->display_options['fields']['field_biological_hazard_other']['field'] = 'field_biological_hazard_other';
  $handler->display->display_options['fields']['field_biological_hazard_other']['ui_name'] = 'Biological hazard other';
  $handler->display->display_options['fields']['field_biological_hazard_other']['type'] = 'text_plain';
  /* Field: Exposure route */
  $handler->display->display_options['fields']['field_exposure_route']['id'] = 'field_exposure_route';
  $handler->display->display_options['fields']['field_exposure_route']['table'] = 'field_data_field_exposure_route';
  $handler->display->display_options['fields']['field_exposure_route']['field'] = 'field_exposure_route';
  $handler->display->display_options['fields']['field_exposure_route']['ui_name'] = 'Exposure route';
  $handler->display->display_options['fields']['field_exposure_route']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_exposure_route']['delta_offset'] = '0';
  /* Field: Exposure route other */
  $handler->display->display_options['fields']['field_exposure_route_other']['id'] = 'field_exposure_route_other';
  $handler->display->display_options['fields']['field_exposure_route_other']['table'] = 'field_data_field_exposure_route_other';
  $handler->display->display_options['fields']['field_exposure_route_other']['field'] = 'field_exposure_route_other';
  $handler->display->display_options['fields']['field_exposure_route_other']['ui_name'] = 'Exposure route other';
  /* Field: Hazard - health effects */
  $handler->display->display_options['fields']['field_hazard_health_effects']['id'] = 'field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['table'] = 'field_data_field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['field'] = 'field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['ui_name'] = 'Hazard - health effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_hazard_health_effects']['delta_offset'] = '0';
  /* Field: Hazard - health effects other */
  $handler->display->display_options['fields']['field_hazard_health_other']['id'] = 'field_hazard_health_other';
  $handler->display->display_options['fields']['field_hazard_health_other']['table'] = 'field_data_field_hazard_health_other';
  $handler->display->display_options['fields']['field_hazard_health_other']['field'] = 'field_hazard_health_other';
  $handler->display->display_options['fields']['field_hazard_health_other']['ui_name'] = 'Hazard - health effects other';
  /* Field: Hazard - physical state */
  $handler->display->display_options['fields']['field_hazard_physical_state']['id'] = 'field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['table'] = 'field_data_field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['field'] = 'field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['ui_name'] = 'Hazard - physical state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_hazard_physical_state']['delta_offset'] = '0';
  /* Field: Hazard - physical state other */
  $handler->display->display_options['fields']['field_hazard_physical_other']['id'] = 'field_hazard_physical_other';
  $handler->display->display_options['fields']['field_hazard_physical_other']['table'] = 'field_data_field_hazard_physical_other';
  $handler->display->display_options['fields']['field_hazard_physical_other']['field'] = 'field_hazard_physical_other';
  $handler->display->display_options['fields']['field_hazard_physical_other']['ui_name'] = 'Hazard - physical state other';
  /* Field: Tasks covered */
  $handler->display->display_options['fields']['field_tasks_covered']['id'] = 'field_tasks_covered';
  $handler->display->display_options['fields']['field_tasks_covered']['table'] = 'field_data_field_tasks_covered';
  $handler->display->display_options['fields']['field_tasks_covered']['field'] = 'field_tasks_covered';
  $handler->display->display_options['fields']['field_tasks_covered']['ui_name'] = 'Tasks covered';
  $handler->display->display_options['fields']['field_tasks_covered']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tasks_covered']['delta_offset'] = '0';
  /* Field: Tasks covered other */
  $handler->display->display_options['fields']['field_tasks_other']['id'] = 'field_tasks_other';
  $handler->display->display_options['fields']['field_tasks_other']['table'] = 'field_data_field_tasks_other';
  $handler->display->display_options['fields']['field_tasks_other']['field'] = 'field_tasks_other';
  $handler->display->display_options['fields']['field_tasks_other']['ui_name'] = 'Tasks covered other';
  $handler->display->display_options['fields']['field_tasks_other']['type'] = 'text_plain';
  /* Field: Advertising */
  $handler->display->display_options['fields']['field_advertising']['id'] = 'field_advertising';
  $handler->display->display_options['fields']['field_advertising']['table'] = 'field_data_field_advertising';
  $handler->display->display_options['fields']['field_advertising']['field'] = 'field_advertising';
  $handler->display->display_options['fields']['field_advertising']['ui_name'] = 'Advertising';
  /* Field: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['ui_name'] = 'Body';
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: CAS Number */
  $handler->display->display_options['fields']['field_cas_number']['id'] = 'field_cas_number';
  $handler->display->display_options['fields']['field_cas_number']['table'] = 'field_data_field_cas_number';
  $handler->display->display_options['fields']['field_cas_number']['field'] = 'field_cas_number';
  $handler->display->display_options['fields']['field_cas_number']['ui_name'] = 'CAS Number';
  $handler->display->display_options['fields']['field_cas_number']['type'] = 'text_plain';
  /* Field: Contact address */
  $handler->display->display_options['fields']['field_contact_address']['id'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['table'] = 'field_data_field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['field'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['ui_name'] = 'Contact address';
  $handler->display->display_options['fields']['field_contact_address']['type'] = 'text_plain';
  /* Field: Content (original language) */
  $handler->display->display_options['fields']['field_body_original']['id'] = 'field_body_original';
  $handler->display->display_options['fields']['field_body_original']['table'] = 'field_data_field_body_original';
  $handler->display->display_options['fields']['field_body_original']['field'] = 'field_body_original';
  $handler->display->display_options['fields']['field_body_original']['ui_name'] = 'Content (original language)';
  $handler->display->display_options['fields']['field_body_original']['type'] = 'text_plain';
  /* Field: Disclaimer */
  $handler->display->display_options['fields']['field_disclaimer']['id'] = 'field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['table'] = 'field_data_field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['field'] = 'field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['ui_name'] = 'Disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['type'] = 'text_plain';
  /* Field: EC number */
  $handler->display->display_options['fields']['field_ec_number']['id'] = 'field_ec_number';
  $handler->display->display_options['fields']['field_ec_number']['table'] = 'field_data_field_ec_number';
  $handler->display->display_options['fields']['field_ec_number']['field'] = 'field_ec_number';
  $handler->display->display_options['fields']['field_ec_number']['ui_name'] = 'EC number';
  $handler->display->display_options['fields']['field_ec_number']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_ec_number']['delta_offset'] = '0';
  /* Field: Evaluation */
  $handler->display->display_options['fields']['field_evaluation']['id'] = 'field_evaluation';
  $handler->display->display_options['fields']['field_evaluation']['table'] = 'field_data_field_evaluation';
  $handler->display->display_options['fields']['field_evaluation']['field'] = 'field_evaluation';
  $handler->display->display_options['fields']['field_evaluation']['ui_name'] = 'Evaluation';
  $handler->display->display_options['fields']['field_evaluation']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_evaluation']['delta_offset'] = '0';
  /* Field: Evaluation other */
  $handler->display->display_options['fields']['field_evaluation_other']['id'] = 'field_evaluation_other';
  $handler->display->display_options['fields']['field_evaluation_other']['table'] = 'field_data_field_evaluation_other';
  $handler->display->display_options['fields']['field_evaluation_other']['field'] = 'field_evaluation_other';
  $handler->display->display_options['fields']['field_evaluation_other']['ui_name'] = 'Evaluation other';
  /* Field: Format, quality (audio track bit rate, video track bit rate) */
  $handler->display->display_options['fields']['field_media_format']['id'] = 'field_media_format';
  $handler->display->display_options['fields']['field_media_format']['table'] = 'field_data_field_media_format';
  $handler->display->display_options['fields']['field_media_format']['field'] = 'field_media_format';
  $handler->display->display_options['fields']['field_media_format']['ui_name'] = 'Format, quality (audio track bit rate, video track bit rate)';
  $handler->display->display_options['fields']['field_media_format']['type'] = 'text_plain';
  /* Field: Intellectual property rights */
  $handler->display->display_options['fields']['field_intellectual_property_righ']['id'] = 'field_intellectual_property_righ';
  $handler->display->display_options['fields']['field_intellectual_property_righ']['table'] = 'field_data_field_intellectual_property_righ';
  $handler->display->display_options['fields']['field_intellectual_property_righ']['field'] = 'field_intellectual_property_righ';
  $handler->display->display_options['fields']['field_intellectual_property_righ']['ui_name'] = 'Intellectual property rights';
  /* Field: Length of the video */
  $handler->display->display_options['fields']['field_video_length']['id'] = 'field_video_length';
  $handler->display->display_options['fields']['field_video_length']['table'] = 'field_data_field_video_length';
  $handler->display->display_options['fields']['field_video_length']['field'] = 'field_video_length';
  $handler->display->display_options['fields']['field_video_length']['ui_name'] = 'Length of the video';
  $handler->display->display_options['fields']['field_video_length']['alter']['strip_tags'] = TRUE;
  /* Field: Measurement method */
  $handler->display->display_options['fields']['field_measurement_method']['id'] = 'field_measurement_method';
  $handler->display->display_options['fields']['field_measurement_method']['table'] = 'field_data_field_measurement_method';
  $handler->display->display_options['fields']['field_measurement_method']['field'] = 'field_measurement_method';
  $handler->display->display_options['fields']['field_measurement_method']['ui_name'] = 'Measurement method';
  $handler->display->display_options['fields']['field_measurement_method']['type'] = 'text_plain';
  /* Field: Other information */
  $handler->display->display_options['fields']['field_other_information']['id'] = 'field_other_information';
  $handler->display->display_options['fields']['field_other_information']['table'] = 'field_data_field_other_information';
  $handler->display->display_options['fields']['field_other_information']['field'] = 'field_other_information';
  $handler->display->display_options['fields']['field_other_information']['ui_name'] = 'Other information';
  $handler->display->display_options['fields']['field_other_information']['type'] = 'text_plain';
  /* Field: Ownership information */
  $handler->display->display_options['fields']['field_ownership_information']['id'] = 'field_ownership_information';
  $handler->display->display_options['fields']['field_ownership_information']['table'] = 'field_data_field_ownership_information';
  $handler->display->display_options['fields']['field_ownership_information']['field'] = 'field_ownership_information';
  $handler->display->display_options['fields']['field_ownership_information']['ui_name'] = 'Ownership information';
  $handler->display->display_options['fields']['field_ownership_information']['type'] = 'text_plain';
  /* Field: Prevention measures */
  $handler->display->display_options['fields']['field_prevention_measure_type']['id'] = 'field_prevention_measure_type';
  $handler->display->display_options['fields']['field_prevention_measure_type']['table'] = 'field_data_field_prevention_measure_type';
  $handler->display->display_options['fields']['field_prevention_measure_type']['field'] = 'field_prevention_measure_type';
  $handler->display->display_options['fields']['field_prevention_measure_type']['ui_name'] = 'Prevention measures';
  $handler->display->display_options['fields']['field_prevention_measure_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_prevention_measure_type']['delta_offset'] = '0';
  /* Field: Prevention measures other */
  $handler->display->display_options['fields']['field_prevention_measures_other']['id'] = 'field_prevention_measures_other';
  $handler->display->display_options['fields']['field_prevention_measures_other']['table'] = 'field_data_field_prevention_measures_other';
  $handler->display->display_options['fields']['field_prevention_measures_other']['field'] = 'field_prevention_measures_other';
  $handler->display->display_options['fields']['field_prevention_measures_other']['ui_name'] = 'Prevention measures other';
  $handler->display->display_options['fields']['field_prevention_measures_other']['type'] = 'text_plain';
  /* Field: Purpose of the material */
  $handler->display->display_options['fields']['field_material_purpose_type']['id'] = 'field_material_purpose_type';
  $handler->display->display_options['fields']['field_material_purpose_type']['table'] = 'field_data_field_material_purpose_type';
  $handler->display->display_options['fields']['field_material_purpose_type']['field'] = 'field_material_purpose_type';
  $handler->display->display_options['fields']['field_material_purpose_type']['ui_name'] = 'Purpose of the material';
  $handler->display->display_options['fields']['field_material_purpose_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_material_purpose_type']['delta_offset'] = '0';
  /* Field: Purpose of the material other */
  $handler->display->display_options['fields']['field_material_purpose_other']['id'] = 'field_material_purpose_other';
  $handler->display->display_options['fields']['field_material_purpose_other']['table'] = 'field_data_field_material_purpose_other';
  $handler->display->display_options['fields']['field_material_purpose_other']['field'] = 'field_material_purpose_other';
  $handler->display->display_options['fields']['field_material_purpose_other']['ui_name'] = 'Purpose of the material other';
  /* Field: Rights description */
  $handler->display->display_options['fields']['field_rights_description']['id'] = 'field_rights_description';
  $handler->display->display_options['fields']['field_rights_description']['table'] = 'field_data_field_rights_description';
  $handler->display->display_options['fields']['field_rights_description']['field'] = 'field_rights_description';
  $handler->display->display_options['fields']['field_rights_description']['ui_name'] = 'Rights description';
  $handler->display->display_options['fields']['field_rights_description']['type'] = 'text_plain';
  /* Field: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['ui_name'] = 'Summary';
  $handler->display->display_options['fields']['field_summary']['type'] = 'text_plain';
  /* Field: Target group */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['ui_name'] = 'Target group';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_target_group']['delta_offset'] = '0';
  /* Field: Target group other */
  $handler->display->display_options['fields']['field_target_group_other']['id'] = 'field_target_group_other';
  $handler->display->display_options['fields']['field_target_group_other']['table'] = 'field_data_field_target_group_other';
  $handler->display->display_options['fields']['field_target_group_other']['field'] = 'field_target_group_other';
  $handler->display->display_options['fields']['field_target_group_other']['ui_name'] = 'Target group other';
  /* Field: Type of visualisation material */
  $handler->display->display_options['fields']['field_visualisation_material_typ']['id'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['table'] = 'field_data_field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['field'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['ui_name'] = 'Type of visualisation material';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['delta_offset'] = '0';
  /* Field: Type of visualisation material other */
  $handler->display->display_options['fields']['field_visualisation_mat_other']['id'] = 'field_visualisation_mat_other';
  $handler->display->display_options['fields']['field_visualisation_mat_other']['table'] = 'field_data_field_visualisation_mat_other';
  $handler->display->display_options['fields']['field_visualisation_mat_other']['field'] = 'field_visualisation_mat_other';
  $handler->display->display_options['fields']['field_visualisation_mat_other']['ui_name'] = 'Type of visualisation material other';
  /* Field: Worker groups covered */
  $handler->display->display_options['fields']['field_worker_groups_type']['id'] = 'field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['table'] = 'field_data_field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['field'] = 'field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['ui_name'] = 'Worker groups covered';
  $handler->display->display_options['fields']['field_worker_groups_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_worker_groups_type']['delta_offset'] = '0';
  /* Field: Worker groups covered other */
  $handler->display->display_options['fields']['field_worker_groups_other']['id'] = 'field_worker_groups_other';
  $handler->display->display_options['fields']['field_worker_groups_other']['table'] = 'field_data_field_worker_groups_other';
  $handler->display->display_options['fields']['field_worker_groups_other']['field'] = 'field_worker_groups_other';
  $handler->display->display_options['fields']['field_worker_groups_other']['ui_name'] = 'Worker groups covered other';
  /* Field: Priority area */
  $handler->display->display_options['fields']['field_priority_area']['id'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['table'] = 'field_data_field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['field'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['ui_name'] = 'Priority area';
  $handler->display->display_options['fields']['field_priority_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_priority_area']['delta_offset'] = '0';
  /* Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['ui_name'] = 'Image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'plain_file_url';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Selected for analysis */
  $handler->display->display_options['fields']['field_selected_for_analysis']['id'] = 'field_selected_for_analysis';
  $handler->display->display_options['fields']['field_selected_for_analysis']['table'] = 'field_data_field_selected_for_analysis';
  $handler->display->display_options['fields']['field_selected_for_analysis']['field'] = 'field_selected_for_analysis';
  $handler->display->display_options['fields']['field_selected_for_analysis']['ui_name'] = 'Selected for analysis';
  /* Field: Provider */
  $handler->display->display_options['fields']['field_fc_provider']['id'] = 'field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['table'] = 'field_data_field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['field'] = 'field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['ui_name'] = 'Provider';
  $handler->display->display_options['fields']['field_fc_provider']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_fc_provider']['delta_offset'] = '0';
  $handler->display->display_options['path'] = 'dangerous-substances/doc';
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
    t('Title (original)'),
    t('Available in languages'),
    t('Languages other'),
    t('Country'),
    t('Country other'),
    t('URL'),
    t('Type of item'),
    t('Date of Publication / Year '),
    t('Sector / Industry covered other'),
    t('Biological hazard'),
    t('Biological hazard other'),
    t('Exposure route'),
    t('Exposure route other'),
    t('Hazard - health effects'),
    t('Health effects other'),
    t('Hazard - physical state'),
    t('Hazard - physical state other'),
    t('Tasks covered'),
    t('Tasks covered other'),
    t('Advertising'),
    t('Body'),
    t('CAS Number'),
    t('Contact address'),
    t('Description (original language)'),
    t('Disclaimer'),
    t('EC number'),
    t('Evaluation'),
    t('Evaluation other'),
    t('Format, quality (audio track bit rate, video track bit rate)'),
    t('Intellectual property rights'),
    t('Length of the video'),
    t('Measurement method'),
    t('Other information'),
    t('Ownership information'),
    t('Prevention measures'),
    t('Prevention measures other'),
    t('Purpose of the material'),
    t('Purpose of the material other'),
    t('Rights description'),
    t('Summary'),
    t('Target group'),
    t('Target audiences other'),
    t('Type of visualisation material'),
    t('Type of visualisation material other'),
    t('Worker groups covered (vulnerable groups etc.)'),
    t('Worker groups covered other'),
    t('Priority area'),
    t('Image'),
    t('Provider'),
    t('Sector / Industry covered (field_sector_industry_covered)'),
    t('Page'),
    t('Data export'),
    t('Selected for analysis'),
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
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
  /* Sort criterion: Indexed Content: Year of publication */
  $handler->display->display_options['sorts']['field_publication_year']['id'] = 'field_publication_year';
  $handler->display->display_options['sorts']['field_publication_year']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['sorts']['field_publication_year']['field'] = 'field_publication_year';
  $handler->display->display_options['sorts']['field_publication_year']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_publication_year']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_publication_year']['expose']['label'] = 'Publication year';
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
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = array(
    1 => '1',
    0 => '0',
  );
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'description';
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['status_1']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'themes/dangerous-substances/search';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'osha_dangerous_substances_doc';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  /* Field: Indexed Content: Title (original) */
  $handler->display->display_options['fields']['field_title_original']['id'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_title_original']['field'] = 'field_title_original';
  /* Field: Indexed Content: Available in languages */
  $handler->display->display_options['fields']['field_available_in_languages']['id'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_available_in_languages']['field'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['settings'] = array(
    'format' => array(
      'name' => 'name',
      'iso' => 0,
      'name_native' => 0,
    ),
  );
  $handler->display->display_options['fields']['field_available_in_languages']['delta_offset'] = '0';
  /* Field: Indexed Content: Languages other */
  $handler->display->display_options['fields']['field_languages_other']['id'] = 'field_languages_other';
  $handler->display->display_options['fields']['field_languages_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_languages_other']['field'] = 'field_languages_other';
  /* Field: Indexed Content: Country */
  $handler->display->display_options['fields']['field_material_country']['id'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_material_country']['field'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_material_country']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_material_country']['bypass_access'] = 0;
  /* Field: Indexed Content: Country other */
  $handler->display->display_options['fields']['field_country_other']['id'] = 'field_country_other';
  $handler->display->display_options['fields']['field_country_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_country_other']['field'] = 'field_country_other';
  /* Field: Indexed Content: External URL */
  $handler->display->display_options['fields']['field_external_url']['id'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_external_url']['field'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_external_url']['type'] = 'link_title_plain';
  /* Field: Indexed Content: Type of item */
  $handler->display->display_options['fields']['field_item_type']['id'] = 'field_item_type';
  $handler->display->display_options['fields']['field_item_type']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_item_type']['field'] = 'field_item_type';
  /* Field: Indexed Content: Year of publication */
  $handler->display->display_options['fields']['field_publication_year']['id'] = 'field_publication_year';
  $handler->display->display_options['fields']['field_publication_year']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_publication_year']['field'] = 'field_publication_year';
  $handler->display->display_options['fields']['field_publication_year']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_publication_year']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'osha_date_theme' => '',
  );
  /* Field: Indexed Content: Sector / Industry covered other */
  $handler->display->display_options['fields']['field_sector_industry_other']['id'] = 'field_sector_industry_other';
  $handler->display->display_options['fields']['field_sector_industry_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_sector_industry_other']['field'] = 'field_sector_industry_other';
  /* Field: Indexed Content: Biological hazard */
  $handler->display->display_options['fields']['field_biological_hazard']['id'] = 'field_biological_hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_biological_hazard']['field'] = 'field_biological_hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_biological_hazard']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_biological_hazard']['bypass_access'] = 0;
  /* Field: Indexed Content: Biological hazard other */
  $handler->display->display_options['fields']['field_biological_hazard_other']['id'] = 'field_biological_hazard_other';
  $handler->display->display_options['fields']['field_biological_hazard_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_biological_hazard_other']['field'] = 'field_biological_hazard_other';
  /* Field: Indexed Content: Exposure route */
  $handler->display->display_options['fields']['field_exposure_route']['id'] = 'field_exposure_route';
  $handler->display->display_options['fields']['field_exposure_route']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_exposure_route']['field'] = 'field_exposure_route';
  $handler->display->display_options['fields']['field_exposure_route']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_exposure_route']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_exposure_route']['bypass_access'] = 0;
  /* Field: Indexed Content: Exposure route other */
  $handler->display->display_options['fields']['field_exposure_route_other']['id'] = 'field_exposure_route_other';
  $handler->display->display_options['fields']['field_exposure_route_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_exposure_route_other']['field'] = 'field_exposure_route_other';
  /* Field: Indexed Content: Hazard - health effects */
  $handler->display->display_options['fields']['field_hazard_health_effects']['id'] = 'field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_hazard_health_effects']['field'] = 'field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_hazard_health_effects']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_hazard_health_effects']['bypass_access'] = 0;
  /* Field: Indexed Content: Hazard - health effects other */
  $handler->display->display_options['fields']['field_hazard_health_other']['id'] = 'field_hazard_health_other';
  $handler->display->display_options['fields']['field_hazard_health_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_hazard_health_other']['field'] = 'field_hazard_health_other';
  /* Field: Indexed Content: Hazard - physical state */
  $handler->display->display_options['fields']['field_hazard_physical_state']['id'] = 'field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_hazard_physical_state']['field'] = 'field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_hazard_physical_state']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_hazard_physical_state']['bypass_access'] = 0;
  /* Field: Indexed Content: Hazard - physical state other */
  $handler->display->display_options['fields']['field_hazard_physical_other']['id'] = 'field_hazard_physical_other';
  $handler->display->display_options['fields']['field_hazard_physical_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_hazard_physical_other']['field'] = 'field_hazard_physical_other';
  /* Field: Indexed Content: Tasks covered */
  $handler->display->display_options['fields']['field_tasks_covered']['id'] = 'field_tasks_covered';
  $handler->display->display_options['fields']['field_tasks_covered']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_tasks_covered']['field'] = 'field_tasks_covered';
  $handler->display->display_options['fields']['field_tasks_covered']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_tasks_covered']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_tasks_covered']['bypass_access'] = 0;
  /* Field: Indexed Content: Tasks covered other */
  $handler->display->display_options['fields']['field_tasks_other']['id'] = 'field_tasks_other';
  $handler->display->display_options['fields']['field_tasks_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_tasks_other']['field'] = 'field_tasks_other';
  /* Field: Indexed Content: Advertising */
  $handler->display->display_options['fields']['field_advertising']['id'] = 'field_advertising';
  $handler->display->display_options['fields']['field_advertising']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_advertising']['field'] = 'field_advertising';
  /* Field: Indexed Content: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Indexed Content: CAS Number */
  $handler->display->display_options['fields']['field_cas_number']['id'] = 'field_cas_number';
  $handler->display->display_options['fields']['field_cas_number']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_cas_number']['field'] = 'field_cas_number';
  $handler->display->display_options['fields']['field_cas_number']['delta_offset'] = '0';
  /* Field: Indexed Content: Contact address */
  $handler->display->display_options['fields']['field_contact_address']['id'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_contact_address']['field'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['type'] = 'text_plain';
  /* Field: Indexed Content: Content (original language) */
  $handler->display->display_options['fields']['field_body_original']['id'] = 'field_body_original';
  $handler->display->display_options['fields']['field_body_original']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_body_original']['field'] = 'field_body_original';
  /* Field: Indexed Content: Disclaimer */
  $handler->display->display_options['fields']['field_disclaimer']['id'] = 'field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_disclaimer']['field'] = 'field_disclaimer';
  /* Field: Indexed Content: EC number */
  $handler->display->display_options['fields']['field_ec_number']['id'] = 'field_ec_number';
  $handler->display->display_options['fields']['field_ec_number']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_ec_number']['field'] = 'field_ec_number';
  $handler->display->display_options['fields']['field_ec_number']['delta_offset'] = '0';
  /* Field: Indexed Content: Evaluation */
  $handler->display->display_options['fields']['field_evaluation']['id'] = 'field_evaluation';
  $handler->display->display_options['fields']['field_evaluation']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_evaluation']['field'] = 'field_evaluation';
  $handler->display->display_options['fields']['field_evaluation']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_evaluation']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_evaluation']['bypass_access'] = 0;
  /* Field: Indexed Content: Evaluation other */
  $handler->display->display_options['fields']['field_evaluation_other']['id'] = 'field_evaluation_other';
  $handler->display->display_options['fields']['field_evaluation_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_evaluation_other']['field'] = 'field_evaluation_other';
  /* Field: Indexed Content: Format, quality (audio track bit rate, video track bit rate) */
  $handler->display->display_options['fields']['field_media_format']['id'] = 'field_media_format';
  $handler->display->display_options['fields']['field_media_format']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_media_format']['field'] = 'field_media_format';
  /* Field: Indexed Content: Intellectual property rights */
  $handler->display->display_options['fields']['field_intellectual_property_righ']['id'] = 'field_intellectual_property_righ';
  $handler->display->display_options['fields']['field_intellectual_property_righ']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_intellectual_property_righ']['field'] = 'field_intellectual_property_righ';
  /* Field: Indexed Content: Measurement method */
  $handler->display->display_options['fields']['field_measurement_method']['id'] = 'field_measurement_method';
  $handler->display->display_options['fields']['field_measurement_method']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_measurement_method']['field'] = 'field_measurement_method';
  /* Field: Indexed Content: Other information */
  $handler->display->display_options['fields']['field_other_information']['id'] = 'field_other_information';
  $handler->display->display_options['fields']['field_other_information']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_other_information']['field'] = 'field_other_information';
  /* Field: Indexed Content: Ownership information */
  $handler->display->display_options['fields']['field_ownership_information']['id'] = 'field_ownership_information';
  $handler->display->display_options['fields']['field_ownership_information']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_ownership_information']['field'] = 'field_ownership_information';
  /* Field: Indexed Content: Prevention measures */
  $handler->display->display_options['fields']['field_prevention_measure_type']['id'] = 'field_prevention_measure_type';
  $handler->display->display_options['fields']['field_prevention_measure_type']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_prevention_measure_type']['field'] = 'field_prevention_measure_type';
  $handler->display->display_options['fields']['field_prevention_measure_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_prevention_measure_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_prevention_measure_type']['bypass_access'] = 0;
  /* Field: Indexed Content: Prevention measures other */
  $handler->display->display_options['fields']['field_prevention_measures_other']['id'] = 'field_prevention_measures_other';
  $handler->display->display_options['fields']['field_prevention_measures_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_prevention_measures_other']['field'] = 'field_prevention_measures_other';
  /* Field: Indexed Content: Purpose of the material */
  $handler->display->display_options['fields']['field_material_purpose_type']['id'] = 'field_material_purpose_type';
  $handler->display->display_options['fields']['field_material_purpose_type']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_material_purpose_type']['field'] = 'field_material_purpose_type';
  $handler->display->display_options['fields']['field_material_purpose_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_material_purpose_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_material_purpose_type']['bypass_access'] = 0;
  /* Field: Indexed Content: Purpose of the material other */
  $handler->display->display_options['fields']['field_material_purpose_other']['id'] = 'field_material_purpose_other';
  $handler->display->display_options['fields']['field_material_purpose_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_material_purpose_other']['field'] = 'field_material_purpose_other';
  /* Field: Indexed Content: Rights description */
  $handler->display->display_options['fields']['field_rights_description']['id'] = 'field_rights_description';
  $handler->display->display_options['fields']['field_rights_description']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_rights_description']['field'] = 'field_rights_description';
  /* Field: Indexed Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  /* Field: Indexed Content: Target group */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_target_group']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_target_group']['bypass_access'] = 0;
  /* Field: Indexed Content: Target group other */
  $handler->display->display_options['fields']['field_target_group_other']['id'] = 'field_target_group_other';
  $handler->display->display_options['fields']['field_target_group_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_target_group_other']['field'] = 'field_target_group_other';
  /* Field: Indexed Content: Type of visualisation material */
  $handler->display->display_options['fields']['field_visualisation_material_typ']['id'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['field'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_visualisation_material_typ']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['bypass_access'] = 0;
  /* Field: Indexed Content: Type of visualisation material other */
  $handler->display->display_options['fields']['field_visualisation_mat_other']['id'] = 'field_visualisation_mat_other';
  $handler->display->display_options['fields']['field_visualisation_mat_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_visualisation_mat_other']['field'] = 'field_visualisation_mat_other';
  /* Field: Indexed Content: Worker groups covered (vulnerable groups etc.) */
  $handler->display->display_options['fields']['field_worker_groups_type']['id'] = 'field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_worker_groups_type']['field'] = 'field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_worker_groups_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_worker_groups_type']['bypass_access'] = 0;
  /* Field: Indexed Content: Worker groups covered other */
  $handler->display->display_options['fields']['field_worker_groups_other']['id'] = 'field_worker_groups_other';
  $handler->display->display_options['fields']['field_worker_groups_other']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_worker_groups_other']['field'] = 'field_worker_groups_other';
  /* Field: Indexed Content: Priority area */
  $handler->display->display_options['fields']['field_priority_area']['id'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_priority_area']['field'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_priority_area']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_priority_area']['bypass_access'] = 0;
  /* Field: Indexed Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Indexed Content: Selected for analysis */
  $handler->display->display_options['fields']['field_selected_for_analysis']['id'] = 'field_selected_for_analysis';
  $handler->display->display_options['fields']['field_selected_for_analysis']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_selected_for_analysis']['field'] = 'field_selected_for_analysis';
  /* Field: Indexed Content: Provider */
  $handler->display->display_options['fields']['field_fc_provider']['id'] = 'field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_fc_provider']['field'] = 'field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_fc_provider']['display'] = 'view';
  $handler->display->display_options['fields']['field_fc_provider']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_fc_provider']['bypass_access'] = 0;
  $handler->display->display_options['path'] = 'themes/dangerous-substances/search/doc';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['dangerous_substances_overview'] = array(
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
    t('«'),
    t('‹'),
    t('›'),
    t('»'),
    t('No results'),
    t('Broken handler search_api_index_default_content_index.search_api_et_id'),
    t('Publication year'),
    t('Relevance'),
    t('Search'),
    t('Status'),
    t('Page'),
    t('Data export'),
    t('Title'),
    t('Title (original)'),
    t('Available in languages'),
    t('Languages other'),
    t('Country'),
    t('Country other'),
    t('External URL'),
    t('Type of item'),
    t('Year of publication'),
    t('Sector / Industry covered other'),
    t('Biological hazard'),
    t('Biological hazard other'),
    t('Exposure route'),
    t('Exposure route other'),
    t('Hazard - health effects'),
    t('Hazard - health effects other'),
    t('Hazard - physical state'),
    t('Hazard - physical state other'),
    t('Tasks covered'),
    t('Tasks covered other'),
    t('Advertising'),
    t('The main body text'),
    t('CAS Number'),
    t('Contact address'),
    t('Content (original language)'),
    t('Disclaimer'),
    t('EC number'),
    t('Evaluation'),
    t('Evaluation other'),
    t('Format, quality (audio track bit rate, video track bit rate)'),
    t('Intellectual property rights'),
    t('Measurement method'),
    t('Other information'),
    t('Ownership information'),
    t('Prevention measures'),
    t('Prevention measures other'),
    t('Purpose of the material'),
    t('Purpose of the material other'),
    t('Rights description'),
    t('Summary'),
    t('Target group'),
    t('Target group other'),
    t('Type of visualisation material'),
    t('Type of visualisation material other'),
    t('Worker groups covered (vulnerable groups etc.)'),
    t('Worker groups covered other'),
    t('Priority area'),
    t('Image'),
    t('Selected for analysis'),
    t('Provider'),
  );
  $export['dangerous_substances_overview'] = $view;

  $view = new view();
  $view->name = 'practical_tools_and_guidance_on_dangerous_substances';
  $view->description = 'A number of tools and guidance documents have been developed by Member States, European institutions, business associations, soc';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_content_index';
  $view->human_name = 'Practical tools and guidance on dangerous substances';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Practical tools and guidance on dangerous substances';
  $handler->display->display_options['css_class'] = 'view-search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@order Showing @start - @end from @total';
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<style>
.node-13588 header > .node__title {
    visibility: hidden;
    display: none;
}
</style>';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'practical_tool_title';
  /* Field: Search: Relevance */
  $handler->display->display_options['fields']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['label'] = '';
  $handler->display->display_options['fields']['search_api_relevance']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_relevance']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['search_api_relevance']['alter']['text'] = '<a href=\'[url]?destination=/en/themes/dangerous-substances/practical-tools-and-guidance-on-dangerous-substances\'>See more</a>';
  $handler->display->display_options['fields']['search_api_relevance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_relevance']['link_to_entity'] = 0;
  /* Field: Indexed Content: Country */
  $handler->display->display_options['fields']['field_material_country']['id'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_material_country']['field'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['label'] = '';
  $handler->display->display_options['fields']['field_material_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_material_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_material_country']['alter']['text'] = '<span>[field_material_country]</span>';
  $handler->display->display_options['fields']['field_material_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_material_country']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_material_country']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_material_country']['bypass_access'] = 0;
  /* Field: Indexed Content: Available in languages */
  $handler->display->display_options['fields']['field_available_in_languages']['id'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_available_in_languages']['field'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['label'] = '';
  $handler->display->display_options['fields']['field_available_in_languages']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_available_in_languages']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_available_in_languages']['alter']['text'] = '<span>[field_available_in_languages]</span>';
  $handler->display->display_options['fields']['field_available_in_languages']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_available_in_languages']['settings'] = array(
    'format' => array(
      'name' => 'name',
      'iso' => 0,
      'name_native' => 0,
    ),
  );
  $handler->display->display_options['fields']['field_available_in_languages']['delta_offset'] = '0';
  /* Field: Provider: Provider name (English) (indexed) */
  $handler->display->display_options['fields']['field_fc_provider_field_fc_provider_name']['id'] = 'field_fc_provider_field_fc_provider_name';
  $handler->display->display_options['fields']['field_fc_provider_field_fc_provider_name']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_fc_provider_field_fc_provider_name']['field'] = 'field_fc_provider_field_fc_provider_name';
  $handler->display->display_options['fields']['field_fc_provider_field_fc_provider_name']['label'] = '';
  $handler->display->display_options['fields']['field_fc_provider_field_fc_provider_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fc_provider_field_fc_provider_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_fc_provider_field_fc_provider_name']['alter']['text'] = '<span>[field_fc_provider_field_fc_provider_name]</span>';
  $handler->display->display_options['fields']['field_fc_provider_field_fc_provider_name']['element_label_colon'] = FALSE;
  /* Field: Indexed Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Content: Year of publication */
  $handler->display->display_options['fields']['field_publication_year']['id'] = 'field_publication_year';
  $handler->display->display_options['fields']['field_publication_year']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_publication_year']['field'] = 'field_publication_year';
  $handler->display->display_options['fields']['field_publication_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_year']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'osha_date_theme' => '',
  );
  /* Field: Indexed Content: Type of item */
  $handler->display->display_options['fields']['field_item_type']['id'] = 'field_item_type';
  $handler->display->display_options['fields']['field_item_type']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['field_item_type']['field'] = 'field_item_type';
  $handler->display->display_options['fields']['field_item_type']['label'] = '';
  $handler->display->display_options['fields']['field_item_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_item_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_item_type']['alter']['text'] = '<span>[field_item_type]</span>';
  $handler->display->display_options['fields']['field_item_type']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="av-type">
[field_fc_provider_field_fc_provider_name]
[field_material_country]
[field_available_in_languages]
[field_item_type]
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Indexed Content: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '300',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '1',
    'more_text' => 'See more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Sort criterion: Indexed Content: Year of publication */
  $handler->display->display_options['sorts']['field_publication_year']['id'] = 'field_publication_year';
  $handler->display->display_options['sorts']['field_publication_year']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['sorts']['field_publication_year']['field'] = 'field_publication_year';
  $handler->display->display_options['sorts']['field_publication_year']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_publication_year']['expose']['label'] = 'Year of publication';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['search_api_relevance']['expose']['label'] = 'Relevance';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
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
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:value' => 'body:value',
    'field_title_original' => 'field_title_original',
    'title' => 'title',
    'title_field' => 'title_field',
  );
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dangerous_substances' => 'dangerous_substances',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 2;
  /* Filter criterion: Indexed Content: Item language */
  $handler->display->display_options['filters']['search_api_language_1']['id'] = 'search_api_language_1';
  $handler->display->display_options['filters']['search_api_language_1']['table'] = 'search_api_index_default_content_index';
  $handler->display->display_options['filters']['search_api_language_1']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language_1']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language_1']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['metatags'] = array(
    'description' => array(
      'value' => '[view:description]',
    ),
    'keywords' => array(
      'value' => 'Dangerous substances, Dangerous substances management, Toxicology, Biological hazards, Chemical hazards, Multi-factorial work hazards, Nanoscale materials, practical tools',
    ),
  );
  $handler->display->display_options['path'] = 'themes/dangerous-substances/practical-tools-dangerous-substances';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Practical tools and guidance on dangerous substances';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $translatables['practical_tools_and_guidance_on_dangerous_substances'] = array(
    t('Master'),
    t('Practical tools and guidance on dangerous substances'),
    t('more'),
    t('Apply'),
    t('Reset'),
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
    t('@order Showing @start - @end from @total'),
    t('No results'),
    t('Node ID'),
    t('.'),
    t(','),
    t('<a href=\'[url]?destination=/en/themes/dangerous-substances/practical-tools-and-guidance-on-dangerous-substances\'>See more</a>'),
    t('<span>[field_material_country]</span>'),
    t('<span>[field_available_in_languages]</span>'),
    t('<span>[field_fc_provider_field_fc_provider_name]</span>'),
    t('Year of publication'),
    t('<span>[field_item_type]</span>'),
    t('<div class="av-type">
[field_fc_provider_field_fc_provider_name]
[field_material_country]
[field_available_in_languages]
[field_item_type]
</div>'),
    t('Relevance'),
    t('Search'),
    t('Page'),
  );
  $export['practical_tools_and_guidance_on_dangerous_substances'] = $view;

  return $export;
}
