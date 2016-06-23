<?php

/**
 * Hook menu that allows to see a preview of the job item.
 *
 * @param object $job_item
 *   Associated job item
 *
 * @return string
 *   Renderable array
 */
function osha_tmgmt_job_items_preview($tjid) {
  return array(
    '#type' => 'markup',
    '#markup' => views_embed_view('osha_job_overview_job_items', 'job_preview')
  );
}
