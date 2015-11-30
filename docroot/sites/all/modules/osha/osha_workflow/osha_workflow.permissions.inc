<?php

function osha_workflow_permissions_download_file_entities() {
  return array(
    'download any audio files',
    'download any document files',
    'download any image files',
    'download any video files',
    'download own audio files',
    'download own document files',
    'download own image files',
    'download own video files',
  );
}

function osha_workflow_permissions_manage_content() {
  return array(
    'create article content',
    'create blog content',
    'create calls content',
    'create files',
    'create highlight content',
    'create job_vacancies content',
    'create news content',
    'create newsletter_article content',
    'create page content',
    'create press_release content',
    'create publication content',
    'create seminar content',
    'create url aliases',
    'create wiki_page content',
    'delete own audio files',
    'delete own document files',
    'delete own image files',
    'delete own video files',
    'edit any article content',
    'edit any audio files',
    'edit any blog content',
    'edit any calls content',
    'edit any document files',
    'edit any highlight content',
    'edit any image files',
    'edit any job_vacancies content',
    'edit any news content',
    'edit any newsletter_article content',
    'edit any page content',
    'edit any press_release content',
    'edit any publication content',
    'edit any seminar content',
    'edit any video files',
    'edit any wiki_page content',
    'edit meta tags',
    'edit own article content',
    'edit own audio files',
    'edit own blog content',
    'edit own calls content',
    'edit own document files',
    'edit own highlight content',
    'edit own image files',
    'edit own job_vacancies content',
    'edit own news content',
    'edit own newsletter_article content',
    'edit own page content',
    'edit own press_release content',
    'edit own publication content',
    'edit own seminar content',
    'edit own video files',
    'edit own wiki_page content',

    'access media browser',

    'view files',
    'view own files',

    'view private files',
    'view own private files',
  );
}

function osha_workflow_permissions_common() {
  return array(
    'access content',
    'view osh content tab',

    'search content',
    'use advanced search',
    'use Search Autocomplete',

    'use text format filtered_html',
    'use text format full_html',

  );
}

function osha_worfklow_permissions_moderator() {
  return array(
    // Important for everyone (editor ... to ... admin) to have it, otherwise
    // they cannot access unpublished content.
    'access workbench access by role',

    'access administration pages',
    'access contextual links',
    'access dashboard',
    'access toolbar',
    'view the administration theme',

    'access workbench',
    'use workbench_moderation my drafts tab',
    'view moderation messages',
    'view revisions',
    'view workbench access information',
    'view moderation history',

    'view own unpublished content',
    'view all unpublished content',

    // Temporary for debugging
    'access devel information',
  );
}

/**
 * Array of permissions for the Editor role.
 * @return array
 *   Permissions
 */
function osha_workflow_permissions_role_editor() {
  $ret = array_merge(
    array(
      'edit any content in draft',
      'edit any content in published',

      'moderate content from draft to final_draft',
    ),
    osha_workflow_permissions_common(),
    osha_workflow_permissions_manage_content(),
    osha_workflow_permissions_download_file_entities(),
    osha_worfklow_permissions_moderator()
  );
  return $ret;
}

/**
 * Array of permissions for the Review Manager role.
 * @return array
 *   Permissions
 */
function osha_workflow_permissions_role_review_manager() {
  $ret = array_merge(
    array(
      'view osh review manager needs review tab',
      'access content overview',
      'assign workbench access',

      'access site in maintenance mode',
      'accept translation jobs',
      'administer files',
      'administer nodes',
      'administer taxonomy',
      'bypass workbench moderation',
      'create translation jobs',
      'submit translation jobs',

      'edit any content in draft',
      'edit any content in final_draft',
      'edit any content in ready_to_publish',
      'edit any content in published',
      'edit any content in to_be_approved',
      'edit any content in needs_review',
      'edit any content in rejected',
      'edit any content in approved',

      'moderate content from draft to final_draft',
      'moderate content from final_draft to ready_to_publish',
      'moderate content from final_draft to draft',
      'moderate content from final_draft to needs_review',
      'moderate content from final_draft to to_be_approved',
      'moderate content from approved to ready_to_publish',
      'moderate content from rejected to ready_to_publish',
      'moderate content from ready_to_publish to published',
      'edit any content in ready_to_publish',
    ),
    osha_workflow_permissions_common(),
    osha_workflow_permissions_manage_content(),
    osha_workflow_permissions_download_file_entities(),
    osha_worfklow_permissions_moderator()
  );
  return $ret;
}


/**
 * Array of permissions for the Project Manager role.
 * @return array
 *   Permissions
 */
function osha_workflow_permissions_role_project_manager() {
  $ret = array_merge(
    array(
      'edit any content in needs_review',
      'view osh project manager needs review tab',
      'mark access section as reviewed',

      'moderate content from needs_review to final_draft',
      'edit any content in approved',
      'edit any content in rejected',
      'edit any content in draft',
      'edit any content in final_draft',
      'edit any content in to_be_approved',
      'edit any content in ready_to_publish',
      'edit any content in published',

      'moderate content from final_draft to draft',
      'moderate content from rejected to final_draft',
      'moderate content from rejected to to_be_approved',
      'moderate content from needs_review to to_be_approved',
      'moderate content from needs_review to ready_to_publish',
      'moderate content from needs_review to to_be_approved',
      'moderate content from approved to ready_to_publish',
      'moderate content from approved to final_draft',

      'moderate content from draft to final_draft',
      'moderate content from final_draft to needs_review',
      'moderate content from final_draft to to_be_approved',
      'moderate content from final_draft to ready_to_publish',
      'moderate content from ready_to_publish to published',
    ),
    osha_workflow_permissions_common(),
    osha_workflow_permissions_manage_content(),
    osha_workflow_permissions_download_file_entities(),
    osha_worfklow_permissions_moderator()
  );
  return $ret;
}

/**
 * Array of permissions for the Approver role.
 * @return array
 *   Permissions
 */
function osha_workflow_permissions_role_approver() {
  $ret = array_merge(
    array(
      'edit any content in to_be_approved',
      'view osh approver needs review tab',

      'moderate content from to_be_approved to approved',
      'moderate content from to_be_approved to rejected',
    ),
    osha_workflow_permissions_common(),
    osha_workflow_permissions_manage_content(),
    osha_workflow_permissions_download_file_entities(),
    osha_worfklow_permissions_moderator()
  );
  return $ret;
}
