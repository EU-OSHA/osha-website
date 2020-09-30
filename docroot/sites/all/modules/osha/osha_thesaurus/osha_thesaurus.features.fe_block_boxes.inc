<?php
/**
 * @file
 * osha_thesaurus.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function osha_thesaurus_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Introductory text to be used on the Thesaurus pages';
  $fe_block_boxes->format = 'full_html_minimal';
  $fe_block_boxes->machine_name = 'thesaurus_intro_text';
  $fe_block_boxes->body = '<p>EU-OSHA’s multilingual thesaurus of occupational safety and health terminology lists words grouped together in a hierarchy. It includes synonyms and antonyms of those words and some definitions.</p>';

  $export['thesaurus_intro_text'] = $fe_block_boxes;

  return $export;
}
