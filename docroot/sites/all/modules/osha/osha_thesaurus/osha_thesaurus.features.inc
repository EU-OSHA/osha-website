<?php
/**
 * @file
 * osha_thesaurus.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_thesaurus_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_thesaurus_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function osha_thesaurus_node_info() {
  $items = array(
    'thesaurus' => array(
      'name' => 'Thesaurus',
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
function osha_thesaurus_default_search_api_index() {
  $items = array();
  $items['thesaurus'] = entity_import('search_api_index', '{
    "name" : "Thesaurus term index",
    "machine_name" : "thesaurus",
    "description" : null,
    "server" : "solr_server",
    "item_type" : "search_api_et_node",
    "options" : {
      "datasource" : { "bundles" : [ "thesaurus" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "search_api_et" : {
        "include" : "incomplete",
        "restrict undefined" : 0,
        "fallback language" : "en"
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_context:value" : { "type" : "text" },
        "field_definition:value" : { "type" : "text" },
        "field_father" : { "type" : "integer", "entity_type" : "node" },
        "field_full_url" : { "type" : "text" },
        "field_glossary_the" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_synonyms" : { "type" : "list\\u003Ctext\\u003E" },
        "field_term_id" : { "type" : "text" },
        "field_term_reference:value" : { "type" : "text" },
        "language" : { "type" : "string" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_aggregation_2" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "title_field" : { "type" : "text" }
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
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_2" : {
                "name" : "Thesaurus title order",
                "type" : "fulltext",
                "fields" : [ "title_field" ],
                "description" : "A Fulltext aggregation of the following fields: Title."
              }
            }
          }
        },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 1, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "title_field" : true,
              "field_synonyms" : true,
              "field_definition:value" : true
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
              "field_synonyms" : true,
              "field_definition:value" : true
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
              "field_synonyms" : true,
              "field_definition:value" : true
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
              "field_synonyms" : true,
              "field_definition:value" : true
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

/**
 * Implements hook_search_autocomplete_config_features_default_settings().
 */
function osha_thesaurus_search_autocomplete_config_features_default_settings() {
  return array(
    0 => array(
      'fid' => 4,
      'title' => 'Thesaurus',
      'selector' => '#edit-search-api-views-fulltext',
      'weight' => 0,
      'enabled' => 1,
      'parent_fid' => 0,
      'min_char' => 3,
      'max_sug' => 10,
      'no_results' => '{"label":"No results found for [search-phrase]. Click to perform full search.","value":"[search-phrase]","link":"","group":{"group_id":"no_results"}}',
      'auto_submit' => 1,
      'auto_redirect' => 1,
      'translite' => 1,
      'data_source' => 'callback',
      'data_callback' => 'thesaurus-search-autocomplete',
      'data_static' => '',
      'data_view' => '',
      'theme' => 'basic-blue.css',
      'all_results' => '{"label":"View all results for [search-phrase].","value":"[search-phrase]","link":"","group":{"group_id":"all_results"}}',
    ),
  );
}
