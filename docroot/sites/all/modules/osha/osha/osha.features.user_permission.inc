<?php
/**
 * @file
 * osha.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function osha_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access PDF version'.
  $permissions['access PDF version'] = array(
    'name' => 'access PDF version',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'print_pdf',
  );

  // Exported permission: 'access news feeds'.
  $permissions['access news feeds'] = array(
    'name' => 'access news feeds',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'aggregator',
  );

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'moderate article state from approved to final_draft'.
  $permissions['moderate article state from approved to final_draft'] = array(
    'name' => 'moderate article state from approved to final_draft',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate article state from approved to published'.
  $permissions['moderate article state from approved to published'] = array(
    'name' => 'moderate article state from approved to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate article state from approved to ready_to_publish'.
  $permissions['moderate article state from approved to ready_to_publish'] = array(
    'name' => 'moderate article state from approved to ready_to_publish',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate article state from ready_to_publish to published'.
  $permissions['moderate article state from ready_to_publish to published'] = array(
    'name' => 'moderate article state from ready_to_publish to published',
    'roles' => array(
      'Review Manager' => 'Review Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate calls state from approved to final_draft'.
  $permissions['moderate calls state from approved to final_draft'] = array(
    'name' => 'moderate calls state from approved to final_draft',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate calls state from approved to published'.
  $permissions['moderate calls state from approved to published'] = array(
    'name' => 'moderate calls state from approved to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate calls state from approved to ready_to_publish'.
  $permissions['moderate calls state from approved to ready_to_publish'] = array(
    'name' => 'moderate calls state from approved to ready_to_publish',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate calls state from ready_to_publish to published'.
  $permissions['moderate calls state from ready_to_publish to published'] = array(
    'name' => 'moderate calls state from ready_to_publish to published',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from approved to final_draft'.
  $permissions['moderate content from approved to final_draft'] = array(
    'name' => 'moderate content from approved to final_draft',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from approved to published'.
  $permissions['moderate content from approved to published'] = array(
    'name' => 'moderate content from approved to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from approved to ready_to_publish'.
  $permissions['moderate content from approved to ready_to_publish'] = array(
    'name' => 'moderate content from approved to ready_to_publish',
    'roles' => array(
      'Review Manager' => 'Review Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from ready_to_publish to published'.
  $permissions['moderate content from ready_to_publish to published'] = array(
    'name' => 'moderate content from ready_to_publish to published',
    'roles' => array(
      'Review Manager' => 'Review Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate directive state from approved to final_draft'.
  $permissions['moderate directive state from approved to final_draft'] = array(
    'name' => 'moderate directive state from approved to final_draft',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate directive state from approved to published'.
  $permissions['moderate directive state from approved to published'] = array(
    'name' => 'moderate directive state from approved to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate directive state from approved to ready_to_publish'.
  $permissions['moderate directive state from approved to ready_to_publish'] = array(
    'name' => 'moderate directive state from approved to ready_to_publish',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate directive state from ready_to_publish to published'.
  $permissions['moderate directive state from ready_to_publish to published'] = array(
    'name' => 'moderate directive state from ready_to_publish to published',
    'roles' => array(
      'Review Manager' => 'Review Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate guideline state from approved to final_draft'.
  $permissions['moderate guideline state from approved to final_draft'] = array(
    'name' => 'moderate guideline state from approved to final_draft',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate guideline state from approved to published'.
  $permissions['moderate guideline state from approved to published'] = array(
    'name' => 'moderate guideline state from approved to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate guideline state from approved to ready_to_publish'.
  $permissions['moderate guideline state from approved to ready_to_publish'] = array(
    'name' => 'moderate guideline state from approved to ready_to_publish',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate guideline state from ready_to_publish to published'.
  $permissions['moderate guideline state from ready_to_publish to published'] = array(
    'name' => 'moderate guideline state from ready_to_publish to published',
    'roles' => array(
      'Review Manager' => 'Review Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate highlight state from approved to final_draft'.
  $permissions['moderate highlight state from approved to final_draft'] = array(
    'name' => 'moderate highlight state from approved to final_draft',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate highlight state from approved to published'.
  $permissions['moderate highlight state from approved to published'] = array(
    'name' => 'moderate highlight state from approved to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate highlight state from approved to ready_to_publish'.
  $permissions['moderate highlight state from approved to ready_to_publish'] = array(
    'name' => 'moderate highlight state from approved to ready_to_publish',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate highlight state from ready_to_publish to published'.
  $permissions['moderate highlight state from ready_to_publish to published'] = array(
    'name' => 'moderate highlight state from ready_to_publish to published',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate infographic state from approved to final_draft'.
  $permissions['moderate infographic state from approved to final_draft'] = array(
    'name' => 'moderate infographic state from approved to final_draft',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate infographic state from approved to published'.
  $permissions['moderate infographic state from approved to published'] = array(
    'name' => 'moderate infographic state from approved to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate infographic state from approved to ready_to_publish'.
  $permissions['moderate infographic state from approved to ready_to_publish'] = array(
    'name' => 'moderate infographic state from approved to ready_to_publish',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate infographic state from ready_to_publish to published'.
  $permissions['moderate infographic state from ready_to_publish to published'] = array(
    'name' => 'moderate infographic state from ready_to_publish to published',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate job_vacancies state from approved to final_draft'.
  $permissions['moderate job_vacancies state from approved to final_draft'] = array(
    'name' => 'moderate job_vacancies state from approved to final_draft',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate job_vacancies state from approved to published'.
  $permissions['moderate job_vacancies state from approved to published'] = array(
    'name' => 'moderate job_vacancies state from approved to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate job_vacancies state from approved to ready_to_publish'.
  $permissions['moderate job_vacancies state from approved to ready_to_publish'] = array(
    'name' => 'moderate job_vacancies state from approved to ready_to_publish',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate job_vacancies state from ready_to_publish to published'.
  $permissions['moderate job_vacancies state from ready_to_publish to published'] = array(
    'name' => 'moderate job_vacancies state from ready_to_publish to published',
    'roles' => array(
      'Review Manager' => 'Review Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news state from approved to final_draft'.
  $permissions['moderate news state from approved to final_draft'] = array(
    'name' => 'moderate news state from approved to final_draft',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news state from approved to published'.
  $permissions['moderate news state from approved to published'] = array(
    'name' => 'moderate news state from approved to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news state from approved to ready_to_publish'.
  $permissions['moderate news state from approved to ready_to_publish'] = array(
    'name' => 'moderate news state from approved to ready_to_publish',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news state from ready_to_publish to published'.
  $permissions['moderate news state from ready_to_publish to published'] = array(
    'name' => 'moderate news state from ready_to_publish to published',
    'roles' => array(
      'Review Manager' => 'Review Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate press_release state from approved to final_draft'.
  $permissions['moderate press_release state from approved to final_draft'] = array(
    'name' => 'moderate press_release state from approved to final_draft',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate press_release state from approved to published'.
  $permissions['moderate press_release state from approved to published'] = array(
    'name' => 'moderate press_release state from approved to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate press_release state from approved to ready_to_publish'.
  $permissions['moderate press_release state from approved to ready_to_publish'] = array(
    'name' => 'moderate press_release state from approved to ready_to_publish',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate press_release state from ready_to_publish to published'.
  $permissions['moderate press_release state from ready_to_publish to published'] = array(
    'name' => 'moderate press_release state from ready_to_publish to published',
    'roles' => array(
      'Review Manager' => 'Review Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate publication state from approved to final_draft'.
  $permissions['moderate publication state from approved to final_draft'] = array(
    'name' => 'moderate publication state from approved to final_draft',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate publication state from approved to published'.
  $permissions['moderate publication state from approved to published'] = array(
    'name' => 'moderate publication state from approved to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate publication state from approved to ready_to_publish'.
  $permissions['moderate publication state from approved to ready_to_publish'] = array(
    'name' => 'moderate publication state from approved to ready_to_publish',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate publication state from ready_to_publish to published'.
  $permissions['moderate publication state from ready_to_publish to published'] = array(
    'name' => 'moderate publication state from ready_to_publish to published',
    'roles' => array(
      'Review Manager' => 'Review Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate seminar state from approved to final_draft'.
  $permissions['moderate seminar state from approved to final_draft'] = array(
    'name' => 'moderate seminar state from approved to final_draft',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate seminar state from approved to published'.
  $permissions['moderate seminar state from approved to published'] = array(
    'name' => 'moderate seminar state from approved to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate seminar state from approved to ready_to_publish'.
  $permissions['moderate seminar state from approved to ready_to_publish'] = array(
    'name' => 'moderate seminar state from approved to ready_to_publish',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate seminar state from ready_to_publish to published'.
  $permissions['moderate seminar state from ready_to_publish to published'] = array(
    'name' => 'moderate seminar state from ready_to_publish to published',
    'roles' => array(
      'Project Manager' => 'Project Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'use text format dangerous_substances_minimal'.
  $permissions['use text format dangerous_substances_minimal'] = array(
    'name' => 'use text format dangerous_substances_minimal',
    'roles' => array(
      'OSH DB editor' => 'OSH DB editor',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Approver' => 'Approver',
      'Content Validator' => 'Content Validator',
      'Editor' => 'Editor',
      'Events Coordinator' => 'Events Coordinator',
      'Events Editor' => 'Events Editor',
      'Layout Validator' => 'Layout Validator',
      'Project Manager' => 'Project Manager',
      'Review Manager' => 'Review Manager',
      'Translation Liaison' => 'Translation Liaison',
      'Translation Manager' => 'Translation Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html_minimal'.
  $permissions['use text format full_html_minimal'] = array(
    'name' => 'use text format full_html_minimal',
    'roles' => array(
      'Approver' => 'Approver',
      'Content Validator' => 'Content Validator',
      'Editor' => 'Editor',
      'Events Coordinator' => 'Events Coordinator',
      'Events Editor' => 'Events Editor',
      'Layout Validator' => 'Layout Validator',
      'Project Manager' => 'Project Manager',
      'Review Manager' => 'Review Manager',
      'Translation Liaison' => 'Translation Liaison',
      'Translation Manager' => 'Translation Manager',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
