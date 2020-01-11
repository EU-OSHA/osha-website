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
    6 => '6',
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
  /* Field: Indexed Content: Type of item */
  $handler->display->display_options['fields']['field_type_of_item']['id'] = 'field_type_of_item';
  $handler->display->display_options['fields']['field_type_of_item']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_type_of_item']['field'] = 'field_type_of_item';
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  /* Field: Indexed Content: Title (original) */
  $handler->display->display_options['fields']['field_title_original']['id'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_title_original']['field'] = 'field_title_original';
  /* Field: Indexed Content: Priority area */
  $handler->display->display_options['fields']['field_priority_area']['id'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_priority_area']['field'] = 'field_priority_area';
  $handler->display->display_options['fields']['field_priority_area']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_priority_area']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_priority_area']['bypass_access'] = 0;
  /* Field: Indexed Content: Available in languages */
  $handler->display->display_options['fields']['field_available_in_languages']['id'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_available_in_languages']['field'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['label'] = 'Languages';
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
  /* Field: Indexed Content: Provider */
  $handler->display->display_options['fields']['field_fc_provider']['id'] = 'field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_fc_provider']['field'] = 'field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_fc_provider']['display'] = 'view';
  $handler->display->display_options['fields']['field_fc_provider']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_fc_provider']['bypass_access'] = 0;
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
  /* Field: Indexed Content: Prevention measures other */
  $handler->display->display_options['fields']['field_prevention_measures_other']['id'] = 'field_prevention_measures_other';
  $handler->display->display_options['fields']['field_prevention_measures_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_prevention_measures_other']['field'] = 'field_prevention_measures_other';
  /* Field: Indexed Content: Purpose of the material other */
  $handler->display->display_options['fields']['field_material_purpose_other']['id'] = 'field_material_purpose_other';
  $handler->display->display_options['fields']['field_material_purpose_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_material_purpose_other']['field'] = 'field_material_purpose_other';
  /* Field: Indexed Content: Worker groups covered (vulnerable groups etc.) */
  $handler->display->display_options['fields']['field_worker_groups_covered']['id'] = 'field_worker_groups_covered';
  $handler->display->display_options['fields']['field_worker_groups_covered']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_worker_groups_covered']['field'] = 'field_worker_groups_covered';
  $handler->display->display_options['fields']['field_worker_groups_covered']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_worker_groups_covered']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_worker_groups_covered']['bypass_access'] = 0;
  /* Field: Indexed Content: Worker groups covered other */
  $handler->display->display_options['fields']['field_worker_groups_other']['id'] = 'field_worker_groups_other';
  $handler->display->display_options['fields']['field_worker_groups_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_worker_groups_other']['field'] = 'field_worker_groups_other';
  /* Field: Indexed Content: Hazards */
  $handler->display->display_options['fields']['field_hazards']['id'] = 'field_hazards';
  $handler->display->display_options['fields']['field_hazards']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_hazards']['field'] = 'field_hazards';
  $handler->display->display_options['fields']['field_hazards']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_hazards']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_hazards']['bypass_access'] = 0;
  /* Field: Indexed Content: Hazards other */
  $handler->display->display_options['fields']['field_hazards_other']['id'] = 'field_hazards_other';
  $handler->display->display_options['fields']['field_hazards_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_hazards_other']['field'] = 'field_hazards_other';
  /* Field: Indexed Content: Health effects */
  $handler->display->display_options['fields']['field_health_effects']['id'] = 'field_health_effects';
  $handler->display->display_options['fields']['field_health_effects']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_health_effects']['field'] = 'field_health_effects';
  $handler->display->display_options['fields']['field_health_effects']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_health_effects']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_health_effects']['bypass_access'] = 0;
  /* Field: Indexed Content: Hazard - health effects other */
  $handler->display->display_options['fields']['field_hazard_health_other']['id'] = 'field_hazard_health_other';
  $handler->display->display_options['fields']['field_hazard_health_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_hazard_health_other']['field'] = 'field_hazard_health_other';
  /* Field: Indexed Content: Prevention measures */
  $handler->display->display_options['fields']['field_prevention_measures']['id'] = 'field_prevention_measures';
  $handler->display->display_options['fields']['field_prevention_measures']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_prevention_measures']['field'] = 'field_prevention_measures';
  $handler->display->display_options['fields']['field_prevention_measures']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_prevention_measures']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_prevention_measures']['bypass_access'] = 0;
  /* Field: Indexed Content: Purpose of the material */
  $handler->display->display_options['fields']['field_purpose_of_the_material']['id'] = 'field_purpose_of_the_material';
  $handler->display->display_options['fields']['field_purpose_of_the_material']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_purpose_of_the_material']['field'] = 'field_purpose_of_the_material';
  $handler->display->display_options['fields']['field_purpose_of_the_material']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_purpose_of_the_material']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_purpose_of_the_material']['bypass_access'] = 0;
  /* Field: Indexed Content: Target audience */
  $handler->display->display_options['fields']['field_target_audience']['id'] = 'field_target_audience';
  $handler->display->display_options['fields']['field_target_audience']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_target_audience']['field'] = 'field_target_audience';
  $handler->display->display_options['fields']['field_target_audience']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_target_audience']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_target_audience']['bypass_access'] = 0;
  /* Field: Indexed Content: Type of visual resource */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_resource_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_resource_type']['bypass_access'] = 0;
  /* Field: Indexed Content: Type of visual resource other */
  $handler->display->display_options['fields']['field_resource_type_other']['id'] = 'field_resource_type_other';
  $handler->display->display_options['fields']['field_resource_type_other']['table'] = 'search_api_index_musculoskeletal_disorders_index';
  $handler->display->display_options['fields']['field_resource_type_other']['field'] = 'field_resource_type_other';
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
    t('«'),
    t('‹'),
    t('›'),
    t('»'),
    t('No results'),
    t('Broken handler search_api_index_musculoskeletal_disorders_index.search_api_et_id'),
    t('Publication year'),
    t('Relevance'),
    t('Search'),
    t('Status'),
    t('Page'),
    t('Data export'),
    t('Type of item'),
    t('Title'),
    t('Title (original)'),
    t('Priority area'),
    t('Languages'),
    t('Languages other'),
    t('Country'),
    t('Country other'),
    t('External URL'),
    t('Provider'),
    t('Year of publication'),
    t('Sector / Industry covered other'),
    t('Prevention measures other'),
    t('Purpose of the material other'),
    t('Worker groups covered (vulnerable groups etc.)'),
    t('Worker groups covered other'),
    t('Hazards'),
    t('Hazards other'),
    t('Health effects'),
    t('Hazard - health effects other'),
    t('Prevention measures'),
    t('Purpose of the material'),
    t('Target audience'),
    t('Type of visual resource'),
    t('Type of visual resource other'),
  );
  $export['musculoskeletal_disorders_overview'] = $view;

  return $export;
}
