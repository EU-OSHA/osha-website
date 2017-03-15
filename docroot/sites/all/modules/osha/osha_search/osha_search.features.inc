<?php
/**
 * @file
 * osha_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function osha_search_default_search_api_index() {
  $items = array();
  $items['default_multilingual_node_index'] = entity_import('search_api_index', '{
    "name" : "Default multilingual node index",
    "machine_name" : "default_multilingual_node_index",
    "description" : "An automatically created search index for indexing multilingual node data. Might be configured to specific needs.",
    "server" : "solr_server",
    "item_type" : "search_api_et_node",
    "options" : {
      "datasource" : { "bundles" : [
          "article",
          "page",
          "blog",
          "calls",
          "press_contact",
          "dangerous_substances",
          "directive",
          "e_guide",
          "events",
          "fop_page",
          "guideline",
          "highlight",
          "infographic",
          "job_vacancies",
          "news",
          "press_release",
          "publication",
          "seminar",
          "wiki_page"
        ]
      },
      "index_directly" : 0,
      "cron_limit" : "50",
      "search_api_et" : {
        "include" : "incomplete",
        "restrict undefined" : 1,
        "fallback language" : "en"
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "1",
            "bundles" : {
              "banner" : "banner",
              "press_contact" : "press_contact",
              "dvs_survey" : "dvs_survey",
              "newsletter_article" : "newsletter_article",
              "note_to_editor" : "note_to_editor"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_attachments_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv",
            "number_indexed" : "0"
          }
        },
        "search_api_alter_language_control" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_et_remove_language" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "uuid" : true,
              "field_summary" : true,
              "field_author" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_tags:name" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "uuid" : true,
              "field_summary" : true,
              "field_author" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_tags:name" : true
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
              "uuid" : true,
              "field_summary" : true,
              "field_author" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_tags:name" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "uuid" : true,
              "field_summary" : true,
              "field_author" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_tags:name" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "200",
            "exclude_fields" : {
              "field_author" : "field_author",
              "field_tags:name" : "field_tags:name",
              "field_wiki_page_url:title" : "field_wiki_page_url:title",
              "title" : "title",
              "title_field" : "title_field",
              "uuid" : "uuid"
            },
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "attachments_field_file" : { "type" : "text" },
        "attachments_field_publication_related_res" : { "type" : "text" },
        "attachments_field_related_documents" : { "type" : "text" },
        "attachments_field_related_resources" : { "type" : "text" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_activity" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_aditional_resources" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_aditional_resources:body:summary" : { "type" : "list\\u003Ctext\\u003E" },
        "field_aditional_resources:body:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_aditional_resources:field_summary" : { "type" : "list\\u003Ctext\\u003E" },
        "field_aditional_resources:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_aditional_resources:title_field" : { "type" : "list\\u003Ctext\\u003E" },
        "field_article_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_author" : { "type" : "text" },
        "field_country_code" : { "type" : "string" },
        "field_date_of_directive" : { "type" : "date" },
        "field_file:description" : { "type" : "text" },
        "field_file:file" : { "type" : "integer", "entity_type" : "file" },
        "field_nace_codes" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_publication_date" : { "type" : "date" },
        "field_publication_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_satisfaction_rate" : { "type" : "integer" },
        "field_seminar_end_date" : { "type" : "date" },
        "field_seminar_start_date" : { "type" : "date" },
        "field_start_date:value" : { "type" : "date" },
        "field_start_date:value2" : { "type" : "date" },
        "field_summary" : { "type" : "text" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_thesaurus" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_updated" : { "type" : "date" },
        "field_wiki_categories" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_wiki_page_url:title" : { "type" : "text" },
        "field_wiki_page_url:url" : { "type" : "uri" },
        "language" : { "type" : "string" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_et_id" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_api_url" : { "type" : "uri" },
        "source" : { "type" : "integer", "entity_type" : "node" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text", "boost" : "2.0" },
        "title_field" : { "type" : "text", "boost" : "2.0" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" },
        "uuid" : { "type" : "text" },
        "vid" : { "type" : "integer" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
