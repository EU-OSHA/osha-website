<?php
/**
 * @file
 * osha_workflow.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function osha_workflow_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access';
  $strongarm->value = 'taxonomy';
  $export['workbench_access'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_allow_multiple';
  $strongarm->value = 0;
  $export['workbench_access_allow_multiple'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_auto_assign';
  $strongarm->value = 1;
  $export['workbench_access_auto_assign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_custom_form';
  $strongarm->value = 1;
  $export['workbench_access_custom_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_label';
  $strongarm->value = 'Section';
  $export['workbench_access_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_menu';
  $strongarm->value = array(
    'devel' => 0,
    'features' => 0,
    'menu-footer-menu' => 0,
    'main-menu' => 0,
    'management' => 0,
    'navigation' => 0,
    'menu-search' => 0,
    'user-menu' => 0,
  );
  $export['workbench_access_menu'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_menu_limit';
  $strongarm->value = 1;
  $export['workbench_access_menu_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_article';
  $strongarm->value = 1;
  $export['workbench_access_node_type_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_banner';
  $strongarm->value = 0;
  $export['workbench_access_node_type_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_blog';
  $strongarm->value = 1;
  $export['workbench_access_node_type_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_calls';
  $strongarm->value = 1;
  $export['workbench_access_node_type_calls'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_highlight';
  $strongarm->value = 1;
  $export['workbench_access_node_type_highlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_job_vacancies';
  $strongarm->value = 1;
  $export['workbench_access_node_type_job_vacancies'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_news';
  $strongarm->value = 1;
  $export['workbench_access_node_type_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_newsletter_article';
  $strongarm->value = 0;
  $export['workbench_access_node_type_newsletter_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_page';
  $strongarm->value = 0;
  $export['workbench_access_node_type_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_press_release';
  $strongarm->value = 1;
  $export['workbench_access_node_type_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_publication';
  $strongarm->value = 1;
  $export['workbench_access_node_type_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_seminar';
  $strongarm->value = 1;
  $export['workbench_access_node_type_seminar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_simplenews';
  $strongarm->value = 1;
  $export['workbench_access_node_type_simplenews'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_wiki_page';
  $strongarm->value = 0;
  $export['workbench_access_node_type_wiki_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_taxonomy';
  $strongarm->value = array(
    'section' => 'section',
    'activity' => 0,
    'article_types' => 0,
    'directive_type' => 0,
    'legislation_category' => 0,
    'esener' => 0,
    'nace_codes' => 0,
    'attachment_file_type' => 0,
    'banner_links' => 0,
    'contact_topic' => 0,
    'contact_type' => 0,
    'contact_type_of_sender' => 0,
    'country' => 0,
    'country_status' => 0,
    'flickr_tags' => 0,
    'fop_link_sections' => 0,
    'newsletter_sections' => 0,
    'organised_by' => 0,
    'publication_types' => 0,
    'relevant_for' => 0,
    'tags' => 0,
    'thesaurus' => 0,
    'wg_category' => 0,
    'wg_role_1' => 0,
    'wg_role_2' => 0,
    'wiki_categories' => 0,
    'workflow_status' => 0,
  );
  $export['workbench_access_taxonomy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_article';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_calls';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_calls'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_news';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_page';
  $strongarm->value = '';
  $export['workbench_moderation_default_state_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_press_release';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_publication';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_publication'] = $strongarm;

  return $export;
}
