<?php
/**
 * @file
 * osha_workflow.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function osha_workflow_workbench_moderation_export_transitions() {
  $items = array(
    'draft:final_draft' => array(
      'from_name' => 'draft',
      'to_name' => 'final_draft',
      'name' => 'Creating Final Draft',
    ),
    'final_draft:draft' => array(
      'from_name' => 'final_draft',
      'to_name' => 'draft',
      'name' => 'Rejecting Draft as Final',
    ),
    'final_draft:needs_review' => array(
      'from_name' => 'final_draft',
      'to_name' => 'needs_review',
      'name' => 'Reviewing Final Draft',
    ),
    'needs_review:draft' => array(
      'from_name' => 'needs_review',
      'to_name' => 'draft',
      'name' => 'Rejecting Final Draft',
    ),
    'needs_review:to_be_approved' => array(
      'from_name' => 'needs_review',
      'to_name' => 'to_be_approved',
      'name' => 'Requesting Approval',
    ),
    'to_be_approved:approved' => array(
      'from_name' => 'to_be_approved',
      'to_name' => 'approved',
      'name' => 'Approving',
    ),
    'to_be_approved:rejected' => array(
      'from_name' => 'to_be_approved',
      'to_name' => 'rejected',
      'name' => 'Rejecting',
    ),
  );
  return $items;
}
