<?php
/**
 * @file
 * osha_musculoskeletal_disorders.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_musculoskeletal_disorders_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'musculoskeletal_disorders_overview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_musculoskeletal_disorders_index';
  $view->human_name = 'Musculoskeletal Disorders overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Musculoskeletal Disorders';
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
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  /* Sort criterion: Indexed Content: Year of publication */
  $handler->display->display_options['sorts']['field_publication_year']['id'] = 'field_publication_year';
  $handler->display->display_options['sorts']['field_publication_year']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['sorts']['field_publication_year']['field'] = 'field_publication_year';
  $handler->display->display_options['sorts']['field_publication_year']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_publication_year']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_publication_year']['expose']['label'] = 'Publication year';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  $handler->display->display_options['sorts']['search_api_relevance']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['search_api_relevance']['expose']['label'] = 'Relevance';
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'musculoskeletal_disorders' => 'musculoskeletal_disorders',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_musculoskeletal_disorders_index';
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
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'search_api_index_musculoskeletal_disorders_index';
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
  $handler->display->display_options['path'] = 'themes/musculoskeletal-disorders/search';

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
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  /* Field: Indexed Content: Title (original) */
  $handler->display->display_options['fields']['field_title_original']['id'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_title_original']['field'] = 'field_title_original';
  /* Field: Indexed Content: Available in languages */
  $handler->display->display_options['fields']['field_available_in_languages']['id'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_available_in_languages']['field'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['settings'] = array(
    'format' => array(
      'name' => 'name',
      'iso' => 0,
      'name_native' => 0,
    ),
  );
  $handler->display->display_options['fields']['field_available_in_languages']['delta_offset'] = '0';
  /* Field: Indexed Content: Language other */
  $handler->display->display_options['fields']['field_languages_other']['id'] = 'field_languages_other';
  $handler->display->display_options['fields']['field_languages_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_languages_other']['field'] = 'field_languages_other';
  /* Field: Indexed Content: Country */
  $handler->display->display_options['fields']['field_material_country']['id'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_material_country']['field'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_material_country']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_material_country']['bypass_access'] = 0;
  /* Field: Indexed Content: Country other */
  $handler->display->display_options['fields']['field_country_other']['id'] = 'field_country_other';
  $handler->display->display_options['fields']['field_country_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_country_other']['field'] = 'field_country_other';
  /* Field: Indexed Content: External URL */
  $handler->display->display_options['fields']['field_external_url']['id'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_external_url']['field'] = 'field_external_url';
  $handler->display->display_options['fields']['field_external_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_external_url']['type'] = 'link_title_plain';
  /* Field: Indexed Content: Type of item */
  $handler->display->display_options['fields']['field_item_type']['id'] = 'field_item_type';
  $handler->display->display_options['fields']['field_item_type']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_item_type']['field'] = 'field_item_type';
  /* Field: Indexed Content: Year of publication */
  $handler->display->display_options['fields']['field_publication_year']['id'] = 'field_publication_year';
  $handler->display->display_options['fields']['field_publication_year']['table'] = 'search_api_index_musculoskeletal_disorders_index';
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
  $handler->display->display_options['fields']['field_sector_industry_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_sector_industry_other']['field'] = 'field_sector_industry_other';
  /* Field: Indexed Content: Biological hazard */
  $handler->display->display_options['fields']['field_biological_hazard']['id'] = 'field_biological_hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_biological_hazard']['field'] = 'field_biological_hazard';
  $handler->display->display_options['fields']['field_biological_hazard']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_biological_hazard']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_biological_hazard']['bypass_access'] = 0;
  /* Field: Indexed Content: Biological hazard other */
  $handler->display->display_options['fields']['field_biological_hazard_other']['id'] = 'field_biological_hazard_other';
  $handler->display->display_options['fields']['field_biological_hazard_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_biological_hazard_other']['field'] = 'field_biological_hazard_other';
  /* Field: Indexed Content: Exposure route */
  $handler->display->display_options['fields']['field_exposure_route']['id'] = 'field_exposure_route';
  $handler->display->display_options['fields']['field_exposure_route']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_exposure_route']['field'] = 'field_exposure_route';
  $handler->display->display_options['fields']['field_exposure_route']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_exposure_route']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_exposure_route']['bypass_access'] = 0;
  /* Field: Indexed Content: Exposure route other */
  $handler->display->display_options['fields']['field_exposure_route_other']['id'] = 'field_exposure_route_other';
  $handler->display->display_options['fields']['field_exposure_route_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_exposure_route_other']['field'] = 'field_exposure_route_other';
  /* Field: Indexed Content: Hazard - health effects */
  $handler->display->display_options['fields']['field_hazard_health_effects']['id'] = 'field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_hazard_health_effects']['field'] = 'field_hazard_health_effects';
  $handler->display->display_options['fields']['field_hazard_health_effects']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_hazard_health_effects']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_hazard_health_effects']['bypass_access'] = 0;
  /* Field: Indexed Content: Hazard - health effects other */
  $handler->display->display_options['fields']['field_hazard_health_other']['id'] = 'field_hazard_health_other';
  $handler->display->display_options['fields']['field_hazard_health_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_hazard_health_other']['field'] = 'field_hazard_health_other';
  /* Field: Indexed Content: Hazard - physical state */
  $handler->display->display_options['fields']['field_hazard_physical_state']['id'] = 'field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_hazard_physical_state']['field'] = 'field_hazard_physical_state';
  $handler->display->display_options['fields']['field_hazard_physical_state']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_hazard_physical_state']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_hazard_physical_state']['bypass_access'] = 0;
  /* Field: Indexed Content: Hazard - physical state other */
  $handler->display->display_options['fields']['field_hazard_physical_other']['id'] = 'field_hazard_physical_other';
  $handler->display->display_options['fields']['field_hazard_physical_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_hazard_physical_other']['field'] = 'field_hazard_physical_other';
  /* Field: Indexed Content: Tasks covered */
  $handler->display->display_options['fields']['field_tasks_covered']['id'] = 'field_tasks_covered';
  $handler->display->display_options['fields']['field_tasks_covered']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_tasks_covered']['field'] = 'field_tasks_covered';
  $handler->display->display_options['fields']['field_tasks_covered']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_tasks_covered']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_tasks_covered']['bypass_access'] = 0;
  /* Field: Indexed Content: Tasks covered other */
  $handler->display->display_options['fields']['field_tasks_other']['id'] = 'field_tasks_other';
  $handler->display->display_options['fields']['field_tasks_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_tasks_other']['field'] = 'field_tasks_other';
  /* Field: Indexed Content: Advertising */
  $handler->display->display_options['fields']['field_advertising']['id'] = 'field_advertising';
  $handler->display->display_options['fields']['field_advertising']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_advertising']['field'] = 'field_advertising';
  /* Field: Indexed Content: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Indexed Content: CAS Number */
  $handler->display->display_options['fields']['field_cas_number']['id'] = 'field_cas_number';
  $handler->display->display_options['fields']['field_cas_number']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_cas_number']['field'] = 'field_cas_number';
  $handler->display->display_options['fields']['field_cas_number']['delta_offset'] = '0';
  /* Field: Indexed Content: Contact address */
  $handler->display->display_options['fields']['field_contact_address']['id'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_contact_address']['field'] = 'field_contact_address';
  $handler->display->display_options['fields']['field_contact_address']['type'] = 'text_plain';
  /* Field: Indexed Content: Content (original language) */
  $handler->display->display_options['fields']['field_body_original']['id'] = 'field_body_original';
  $handler->display->display_options['fields']['field_body_original']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_body_original']['field'] = 'field_body_original';
  /* Field: Indexed Content: Disclaimer */
  $handler->display->display_options['fields']['field_disclaimer']['id'] = 'field_disclaimer';
  $handler->display->display_options['fields']['field_disclaimer']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_disclaimer']['field'] = 'field_disclaimer';
  /* Field: Indexed Content: EC number */
  $handler->display->display_options['fields']['field_ec_number']['id'] = 'field_ec_number';
  $handler->display->display_options['fields']['field_ec_number']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_ec_number']['field'] = 'field_ec_number';
  $handler->display->display_options['fields']['field_ec_number']['delta_offset'] = '0';
  /* Field: Indexed Content: Evaluation */
  $handler->display->display_options['fields']['field_evaluation']['id'] = 'field_evaluation';
  $handler->display->display_options['fields']['field_evaluation']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_evaluation']['field'] = 'field_evaluation';
  $handler->display->display_options['fields']['field_evaluation']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_evaluation']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_evaluation']['bypass_access'] = 0;
  /* Field: Indexed Content: Evaluation other */
  $handler->display->display_options['fields']['field_evaluation_other']['id'] = 'field_evaluation_other';
  $handler->display->display_options['fields']['field_evaluation_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_evaluation_other']['field'] = 'field_evaluation_other';
  /* Field: Indexed Content: Format, quality (audio track bit rate, video track bit rate) */
  $handler->display->display_options['fields']['field_media_format']['id'] = 'field_media_format';
  $handler->display->display_options['fields']['field_media_format']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_media_format']['field'] = 'field_media_format';
  /* Field: Indexed Content: Intellectual property rights */
  $handler->display->display_options['fields']['field_intellectual_property_righ']['id'] = 'field_intellectual_property_righ';
  $handler->display->display_options['fields']['field_intellectual_property_righ']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_intellectual_property_righ']['field'] = 'field_intellectual_property_righ';
  /* Field: Indexed Content: Measurement method */
  $handler->display->display_options['fields']['field_measurement_method']['id'] = 'field_measurement_method';
  $handler->display->display_options['fields']['field_measurement_method']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_measurement_method']['field'] = 'field_measurement_method';
  /* Field: Indexed Content: Other information */
  $handler->display->display_options['fields']['field_other_information']['id'] = 'field_other_information';
  $handler->display->display_options['fields']['field_other_information']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_other_information']['field'] = 'field_other_information';
  /* Field: Indexed Content: Ownership information */
  $handler->display->display_options['fields']['field_ownership_information']['id'] = 'field_ownership_information';
  $handler->display->display_options['fields']['field_ownership_information']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_ownership_information']['field'] = 'field_ownership_information';
  /* Field: Indexed Content: Prevention measures */
  $handler->display->display_options['fields']['field_prevention_measure_type']['id'] = 'field_prevention_measure_type';
  $handler->display->display_options['fields']['field_prevention_measure_type']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_prevention_measure_type']['field'] = 'field_prevention_measure_type';
  $handler->display->display_options['fields']['field_prevention_measure_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_prevention_measure_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_prevention_measure_type']['bypass_access'] = 0;
  /* Field: Indexed Content: Prevention measures other */
  $handler->display->display_options['fields']['field_prevention_measures_other']['id'] = 'field_prevention_measures_other';
  $handler->display->display_options['fields']['field_prevention_measures_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_prevention_measures_other']['field'] = 'field_prevention_measures_other';
  /* Field: Indexed Content: Purpose of the material */
  $handler->display->display_options['fields']['field_material_purpose_type']['id'] = 'field_material_purpose_type';
  $handler->display->display_options['fields']['field_material_purpose_type']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_material_purpose_type']['field'] = 'field_material_purpose_type';
  $handler->display->display_options['fields']['field_material_purpose_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_material_purpose_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_material_purpose_type']['bypass_access'] = 0;
  /* Field: Indexed Content: Purpose of the material other */
  $handler->display->display_options['fields']['field_material_purpose_other']['id'] = 'field_material_purpose_other';
  $handler->display->display_options['fields']['field_material_purpose_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_material_purpose_other']['field'] = 'field_material_purpose_other';
  /* Field: Indexed Content: Rights description */
  $handler->display->display_options['fields']['field_rights_description']['id'] = 'field_rights_description';
  $handler->display->display_options['fields']['field_rights_description']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_rights_description']['field'] = 'field_rights_description';
  /* Field: Indexed Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  /* Field: Indexed Content: Target group */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_target_group']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_target_group']['bypass_access'] = 0;
  /* Field: Indexed Content: Target group other */
  $handler->display->display_options['fields']['field_target_group_other']['id'] = 'field_target_group_other';
  $handler->display->display_options['fields']['field_target_group_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_target_group_other']['field'] = 'field_target_group_other';
  /* Field: Indexed Content: Type of visualisation material */
  $handler->display->display_options['fields']['field_visualisation_material_typ']['id'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['field'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_visualisation_material_typ']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['bypass_access'] = 0;
  /* Field: Indexed Content: Type of visualisation material other */
  $handler->display->display_options['fields']['field_visualisation_mat_other']['id'] = 'field_visualisation_mat_other';
  $handler->display->display_options['fields']['field_visualisation_mat_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_visualisation_mat_other']['field'] = 'field_visualisation_mat_other';
  /* Field: Indexed Content: Worker groups covered (vulnerable groups etc.) */
  $handler->display->display_options['fields']['field_worker_groups_type']['id'] = 'field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_worker_groups_type']['field'] = 'field_worker_groups_type';
  $handler->display->display_options['fields']['field_worker_groups_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_worker_groups_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_worker_groups_type']['bypass_access'] = 0;
  /* Field: Indexed Content: Worker groups covered other */
  $handler->display->display_options['fields']['field_worker_groups_other']['id'] = 'field_worker_groups_other';
  $handler->display->display_options['fields']['field_worker_groups_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_worker_groups_other']['field'] = 'field_worker_groups_other';
  /* Field: Indexed Content: Priority area */
  $handler->display->display_options['fields']['field_priority_area']['id'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_priority_area']['field'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_priority_area']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_priority_area']['bypass_access'] = 0;
  /* Field: Indexed Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Indexed Content: Selected for analysis */
  $handler->display->display_options['fields']['field_selected_for_analysis']['id'] = 'field_selected_for_analysis';
  $handler->display->display_options['fields']['field_selected_for_analysis']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_selected_for_analysis']['field'] = 'field_selected_for_analysis';
  /* Field: Indexed Content: Provider */
  $handler->display->display_options['fields']['field_fc_provider']['id'] = 'field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_fc_provider']['field'] = 'field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_fc_provider']['display'] = 'view';
  $handler->display->display_options['fields']['field_fc_provider']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_fc_provider']['bypass_access'] = 0;
  $handler->display->display_options['path'] = 'themes/musculoskeletal-disorders/search/doc';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['musculoskeletal_disorders_overview'] = array(
    t('Master'),
    t('Musculoskeletal Disorders'),
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
    t('‹'),
    t('›'),
    t('last »'),
    t('No results'),
    t('Broken handler search_api_index_musculoskeletal_disorders_index.search_api_et_id'),
    t('Publication year'),
    t('Relevance'),
    t('Search'),
    t('Status'),
    t('Page'),
    t('Data export'),
    t('Title'),
    t('Title (original)'),
    t('Available in languages'),
    t('Language other'),
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
  $export['musculoskeletal_disorders_overview'] = $view;

  return $export;
}
