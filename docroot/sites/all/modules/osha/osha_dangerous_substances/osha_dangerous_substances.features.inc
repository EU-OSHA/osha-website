<?php
/**
 * @file
 * osha_dangerous_substances.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_dangerous_substances_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_dangerous_substances_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function osha_dangerous_substances_node_info() {
  $items = array(
    'dangerous_substances' => array(
      'name' => 'Dangerous substances',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function osha_dangerous_substances_default_search_api_index() {
  $items = array();
  $items['default_content_index'] = entity_import('search_api_index', '{
    "name" : "Dangerous substances index",
    "machine_name" : "default_content_index",
    "description" : null,
    "server" : "solr_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "dangerous_substances" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_advertising" : { "type" : "boolean" },
        "field_available_in_languages:safe_value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_available_in_languages:safe_value_with_native" : { "type" : "list\\u003Ctext\\u003E" },
        "field_available_in_languages:value" : { "type" : "list\\u003Cstring\\u003E" },
        "field_biological_hazard" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_biological_hazard_other" : { "type" : "text" },
        "field_body_original:value" : { "type" : "text" },
        "field_cas_number" : { "type" : "text" },
        "field_contact_address:value" : { "type" : "text" },
        "field_country_other" : { "type" : "text" },
        "field_disclaimer:value" : { "type" : "text" },
        "field_ec_number" : { "type" : "list\\u003Ctext\\u003E" },
        "field_evaluation" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_exposure_route" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_external_url:url" : { "type" : "uri" },
        "field_hazard_health_effects" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_hazard_physical_state" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_intellectual_property_righ" : { "type" : "string" },
        "field_item_type" : { "type" : "string" },
        "field_material_country" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_material_objective_other" : { "type" : "text" },
        "field_material_objective_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_material_purpose_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_measurement_method" : { "type" : "text" },
        "field_media_format" : { "type" : "text" },
        "field_other_information:value" : { "type" : "text" },
        "field_ownership_information:value" : { "type" : "text" },
        "field_prevention_measure_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_prevention_measures_other" : { "type" : "text" },
        "field_provider" : { "type" : "text" },
        "field_provider_original" : { "type" : "text" },
        "field_provider_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_provider_url:url" : { "type" : "uri" },
        "field_publication_date" : { "type" : "date" },
        "field_rights_description" : { "type" : "text" },
        "field_sector_industry_covered" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_target_group" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tasks_covered" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tasks_other" : { "type" : "text" },
        "field_title_original" : { "type" : "text" },
        "field_visualisation_material_typ" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_worker_groups_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "language" : { "type" : "string" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "title_field" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_attachments_alter_settings" : {
          "status" : 0,
          "weight" : "0",
          "settings" : {
            "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv",
            "number_indexed" : "0"
          }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 1, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "title_field" : true,
              "field_summary" : true,
              "field_title_original" : true,
              "field_provider" : true,
              "field_provider_original" : true,
              "field_tasks_other" : true,
              "field_biological_hazard_other" : true,
              "field_cas_number" : true,
              "field_ec_number" : true,
              "field_measurement_method" : true,
              "field_prevention_measures_other" : true,
              "field_material_objective_other" : true,
              "field_media_format" : true,
              "field_rights_description" : true,
              "field_country_other" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_summary" : true,
              "field_title_original" : true,
              "field_provider" : true,
              "field_provider_original" : true,
              "field_tasks_other" : true,
              "field_biological_hazard_other" : true,
              "field_cas_number" : true,
              "field_ec_number" : true,
              "field_measurement_method" : true,
              "field_prevention_measures_other" : true,
              "field_material_objective_other" : true,
              "field_media_format" : true,
              "field_rights_description" : true,
              "field_country_other" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_summary" : true,
              "field_title_original" : true,
              "field_provider" : true,
              "field_provider_original" : true,
              "field_tasks_other" : true,
              "field_biological_hazard_other" : true,
              "field_cas_number" : true,
              "field_ec_number" : true,
              "field_measurement_method" : true,
              "field_prevention_measures_other" : true,
              "field_material_objective_other" : true,
              "field_media_format" : true,
              "field_rights_description" : true,
              "field_country_other" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_summary" : true,
              "field_title_original" : true,
              "field_provider" : true,
              "field_provider_original" : true,
              "field_tasks_other" : true,
              "field_biological_hazard_other" : true,
              "field_cas_number" : true,
              "field_ec_number" : true,
              "field_measurement_method" : true,
              "field_prevention_measures_other" : true,
              "field_material_objective_other" : true,
              "field_media_format" : true,
              "field_rights_description" : true,
              "field_country_other" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
