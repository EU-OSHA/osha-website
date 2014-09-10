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
      'description' => '',
      'weight' => -8,
    ),
    'draft' => array(
      'name' => 'draft',
      'label' => 'Draft',
      'description' => '',
      'weight' => -10,
    ),
    'final_draft' => array(
      'name' => 'final_draft',
      'label' => 'Final Draft',
      'description' => '',
      'weight' => -7,
    ),
    'needs_review' => array(
      'name' => 'needs_review',
      'label' => 'To Be Reviewed',
      'description' => '',
      'weight' => -6,
    ),
    'published' => array(
      'name' => 'published',
      'label' => 'Published',
      'description' => '',
      'weight' => -4,
    ),
    'rejected' => array(
      'name' => 'rejected',
      'label' => 'Rejected',
      'description' => '',
      'weight' => -9,
    ),
    'to_be_approved' => array(
      'name' => 'to_be_approved',
      'label' => 'To Be Approved',
      'description' => '',
      'weight' => -5,
    ),
  );
  return $items;
}
