<?php
/**
 * @file
 * osha_workflow.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function osha_workflow_workbench_moderation_export_states() {
  $items = array(
    'approved' => array(
      'name' => 'approved',
      'label' => 'Approved',
      'description' => 'Last Approver can set the status to Approved or Rejected',
      'weight' => -8,
    ),
    'draft' => array(
      'name' => 'draft',
      'label' => 'Draft',
      'description' => 'Editors can add and edit content in state draft',
      'weight' => -10,
    ),
    'final_draft' => array(
      'name' => 'final_draft',
      'label' => 'Final Draft',
      'description' => 'Editors, when done set the status to Final Draft',
      'weight' => -7,
    ),
    'needs_review' => array(
      'name' => 'needs_review',
      'label' => 'To Be Reviewed',
      'description' => 'Review Manager can set the Final Draft to To Be Reviewed or To Be Approved ',
      'weight' => -6,
    ),
    'published' => array(
      'name' => 'published',
      'label' => 'Published',
      'description' => 'Web team set the content from Ready To Publish to Published',
      'weight' => -3,
    ),
    'ready_to_publish' => array(
      'name' => 'ready_to_publish',
      'label' => 'Ready To Publish',
      'description' => 'When Review/Approval is done, content is ready to be published',
      'weight' => -4,
    ),
    'rejected' => array(
      'name' => 'rejected',
      'label' => 'Rejected',
      'description' => 'Review manager and Project manager can Reject the content',
      'weight' => -9,
    ),
    'to_be_approved' => array(
      'name' => 'to_be_approved',
      'label' => 'To Be Approved',
      'description' => 'Review Manager can set the Final Draft to To Be Reviewed or To Be Approved ',
      'weight' => -5,
    ),
  );
  return $items;
}
