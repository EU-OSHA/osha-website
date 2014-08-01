<?php
/**
 * @file
 * pdf_document.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pdf_document_node_info() {
  $items = array(
    'document' => array(
      'name' => t('Document'),
      'base' => 'node_content',
      'description' => t('A PDF document, with preview.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
