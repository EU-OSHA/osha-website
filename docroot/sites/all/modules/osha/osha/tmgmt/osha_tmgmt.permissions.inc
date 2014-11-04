<?php

/**
 * Define extra permissions used by this module.
 */
function osha_tmgmt_extra_permissions() {
  $perms = array(
    'osha tmgmt upload translation file' => array(
      'title' => t('Upload translation file to a Job'),
    ),
    'preview layout validation' => array(
      'title' => t('Access node layout validation preview screen'),
      'description' => t('Allows Layout Validators to preview the node before accepting translation'),
    ),
    'view translation job' => array(
      'title' => t('View the list of translation jobs and job details'),
    ),
    'view translation job item' => array(
      'title' => t('View the job item details'),
    ),
    'edit translation job item' => array(
      'title' => t('Can edit job item no matter the state.'),
    ),
    'view translation content validators' => array(
      'title' => t('View the job item Content Validators'),
    ),
    'edit translation content validators' => array(
      'title' => t('Edit the job item Content Validators'),
    ),
    'set job item to translated state' => array(
      'title' => t('View the job to Translated state'),
    ),
    'set job item to require content validation state' => array(
      'title' => t('Can set the job item to Require Content Validation'),
    ),
    'set job item to ready to publish state' => array(
      'title' => t('Can set the job item to Translation Ready to Publish'),
    ),
    'abort job item' => array(
      'title' => t('Can abort a job item.'),
    ),
    'accept job item translation' => array(
      'title' => t('Accept (saves to entity) job item translation!'),
    ),
    'view on translation content list' => array(
      'title' => t('View "On Translation" tab from workbench'),
    ),
    'view needs content validation list' => array(
      'title' => t('View "Needs Content Validation" tab from workbench'),
    ),
    'view untranslated jobs' => array(
      'title' => t('View "Needs Translation" tab from workbench'),
      'description' => t('Applies to translation liaison role'),
    ),
    'manage content in translators group entity collections' => array(
      'title' => t('Manage Content Validators Groups'),
    ),
  );
  return $perms;
}

function osha_tmgmt_workflow_permissions_common() {
  return array(
    'access dashboard',
    'view the administration theme',
    'access toolbar',
    'view translation job',
    // TODO checko why fails on install if access workbench permission added here.
//    'access workbench',

    //@todo: remove
    'access devel information',
  );
}

/**
 * Define the permissions for Translation Manager role.
 *
 * @return array
 *   Array of permissions
 */
function osha_tmgmt_workflow_permissions_role_translation_manager() {
  // translate content
  // translate any entity
  // translate node entities
  // translate taxonomy_term entities
  // accept translation jobs

  // Local Translator??
  return array_merge(
    array(

      'create translation jobs',
      'submit translation jobs',
      'accept translation jobs',

      'preview layout validation',
      'view translation job item',
      'edit translation job item',
      'set job item to translated state',

      'view translation content validators',

      'access user profiles',
      'edit translation content validators',
      'set job item to require content validation state',
      'set job item to ready to publish state',
      'abort job item',
      'osha tmgmt upload translation file',

      // Translate tab on nodes.
      'translate node entities',
      'manage content in translators group entity collections',
    ),
    osha_tmgmt_workflow_permissions_common()
  );
}

/**
 * Define the permissions for Translation Liaison role.
 *
 * @return array
 *   Array of permissions
 */
function osha_tmgmt_workflow_permissions_role_translation_liaison() {
  return array_merge(
    array(
      'view translation job item',
      'view untranslated jobs',
    ),
    osha_tmgmt_workflow_permissions_common()
  );
}

/**
 * Define the permissions for Translation Liaison role.
 *
 * @return array
 *   Array of permissions
 */
function osha_tmgmt_workflow_permissions_role_layout_validator() {
  return array_merge(
    array(
      'abort job item',
      'preview layout validation',
      'set job item to translated state',
      'view translation job item',
      'view on translation content list',
      'osha tmgmt upload translation file',
    ),
    osha_tmgmt_workflow_permissions_common()
  );
}

/**
 * Define the permissions for Content Validator role.
 *
 * @return array
 *   Array of permissions
 */
function osha_tmgmt_workflow_permissions_role_content_validator() {
  return array_merge(
    array(
      'preview layout validation',
      'abort job item',
      'view needs content validation list',
      'view translation job item',
    ),
    osha_tmgmt_workflow_permissions_common());
}

/**
 * Extra permissions for Project Managers (workflow).
 */
function osha_tmgmt_pm_permissions() {
  return array(
    'accept job item translation',
    'view translation job item',
    'view translation job',
  );
}
