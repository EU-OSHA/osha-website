<?php
/**
 * @file
 * osha_tmgmt.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_tmgmt_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "entity_collection" && $api == "entity_collection_bundles_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_tmgmt_views_api($module = NULL, $api = NULL) {
  return array(
    "api" => "3.0",
    'path' => drupal_get_path('module', 'osha_tmgmt') . '/views/',
  );
}

/**
 * Implements hook_default_entity_collection().
 */
function osha_tmgmt_default_entity_collection() {
  $items = array();
  $items['translators_group_1'] = entity_import('entity_collection', '{
    "type" : null,
    "name" : "translators_group_1",
    "bid" : null,
    "title" : "translators_group_1",
    "cache" : null,
    "requiredcontexts" : [],
    "contexts" : [],
    "bundle" : "translators_group",
    "style" : "entity_collection_style_flat",
    "row" : "entity_collection_row_view_mode",
    "settings" : {
      "row_settings" : { "style_per_row" : 1 },
      "style_settings" : [],
      "allowed_bundles" : {
        "node" : [],
        "taxonomy_term" : [],
        "comment" : [],
        "entity_collection" : [],
        "i18n_translation" : [],
        "redirect" : [],
        "search_api_server" : [],
        "search_api_index" : [],
        "file" : [],
        "taxonomy_vocabulary" : [],
        "tmgmt_job" : [],
        "tmgmt_job_item" : [],
        "tmgmt_message" : [],
        "tmgmt_translator" : [],
        "tmgmt_remote" : [],
        "tmgmt_local_task" : [],
        "tmgmt_local_task_item" : [],
        "user" : [ "user" ],
        "wysiwyg_profile" : [],
        "workbench_moderation_transition" : [],
        "translation_validator" : [],
        "node_project_managers" : [],
        "node_approval" : [],
        "rules_config" : []
      }
    },
    "rdf_mapping" : []
  }');
  $items['translators_group_2'] = entity_import('entity_collection', '{
    "type" : null,
    "name" : "translators_group_2",
    "bid" : null,
    "title" : "translators_group_2",
    "cache" : null,
    "requiredcontexts" : [],
    "contexts" : [],
    "bundle" : "translators_group",
    "style" : "entity_collection_style_flat",
    "row" : "entity_collection_row_view_mode",
    "settings" : {
      "row_settings" : { "style_per_row" : 1 },
      "style_settings" : [],
      "allowed_bundles" : {
        "node" : [],
        "taxonomy_term" : [],
        "comment" : [],
        "entity_collection" : [],
        "i18n_translation" : [],
        "redirect" : [],
        "search_api_server" : [],
        "search_api_index" : [],
        "file" : [],
        "taxonomy_vocabulary" : [],
        "tmgmt_job" : [],
        "tmgmt_job_item" : [],
        "tmgmt_message" : [],
        "tmgmt_translator" : [],
        "tmgmt_remote" : [],
        "tmgmt_local_task" : [],
        "tmgmt_local_task_item" : [],
        "user" : [ "user" ],
        "wysiwyg_profile" : [],
        "workbench_moderation_transition" : [],
        "translation_validator" : [],
        "node_project_managers" : [],
        "node_approval" : [],
        "rules_config" : []
      }
    },
    "rdf_mapping" : []
  }');
  $items['translators_group_3'] = entity_import('entity_collection', '{
    "type" : null,
    "name" : "translators_group_3",
    "bid" : null,
    "title" : "translators_group_3",
    "cache" : null,
    "requiredcontexts" : [],
    "contexts" : [],
    "bundle" : "translators_group",
    "style" : "entity_collection_style_flat",
    "row" : "entity_collection_row_view_mode",
    "settings" : {
      "row_settings" : { "style_per_row" : 1 },
      "style_settings" : [],
      "allowed_bundles" : {
        "node" : [],
        "taxonomy_term" : [],
        "comment" : [],
        "entity_collection" : [],
        "i18n_translation" : [],
        "redirect" : [],
        "search_api_server" : [],
        "search_api_index" : [],
        "file" : [],
        "taxonomy_vocabulary" : [],
        "tmgmt_job" : [],
        "tmgmt_job_item" : [],
        "tmgmt_message" : [],
        "tmgmt_translator" : [],
        "tmgmt_remote" : [],
        "tmgmt_local_task" : [],
        "tmgmt_local_task_item" : [],
        "user" : [ "user" ],
        "wysiwyg_profile" : [],
        "workbench_moderation_transition" : [],
        "translation_validator" : [],
        "node_project_managers" : [],
        "node_approval" : [],
        "rules_config" : []
      }
    },
    "rdf_mapping" : []
  }');
  return $items;
}
