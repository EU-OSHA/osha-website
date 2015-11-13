<?php

/**
 * Implements hook_pathauto_punctuation_chars_alter().
 */
function osha_pathauto_punctuation_chars_alter(array &$punctuation) {
  // Add the trademark symbol.
  $punctuation['trademark'] = array('value' => '™', 'name' => t('Trademark symbol'));
  $punctuation['U+00BF'] = array('value' => '¿', 'name' => t('Inverted Question Mark'));
  $punctuation['U+00B8'] = array('value' => '¸', 'name' => t('Cedilla'));
  $punctuation['U+00B7'] = array('value' => '·', 'name' => t('Middle dot'));
  $punctuation['U+00A8'] = array('value' => '¨', 'name' => t('Diaeresis'));
  $punctuation['U+00B4'] = array('value' => '´', 'name' => t('Acute accent'));
  $punctuation['8222'] = array('value' => '„', 'name' => t('Quote open'));
  $punctuation['8220'] = array('value' => '“', 'name' => t('Quote close'));
  $punctuation['8218'] = array('value' => '‚', 'name' => t('Single quote open'));
  $punctuation['8216'] = array('value' => '‘', 'name' => t('Single quote close'));
  $punctuation['8249'] = array('value' => '‹', 'name' => t('Single chevron close'));
  $punctuation['8250'] = array('value' => '›', 'name' => t('Single chevron close'));
  $punctuation['0171'] = array('value' => '«', 'name' => t('Double chevron open'));
  $punctuation['0187'] = array('value' => '»', 'name' => t('Double chevron close'));
  $punctuation['en-dash'] = array('value' => '–', 'name' => t('En dash'));
  $punctuation['em-dash'] = array('value' => '—', 'name' => t('Em dash'));
  $punctuation['apostrophe'] = array('value' => '’', 'name' => t('Apostrophe'));
  $punctuation['double-exclamation-mark'] = array('value' => '‼', 'name' => t('Double exclamation mark'));
  $punctuation['overline'] = array('value' => '‾', 'name' => t('Overline'));
}
