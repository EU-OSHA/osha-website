<?php

/**
 * @file
 * Configuration for translations.
 */

/**
 * Implements hook_variable_info().
 */
function eu_cookie_compliance_variable_info($options) {
  $variable['eu_cookie_compliance'] = array(
    'title' => t('EU Cookie Compliance'),
    'description' => t('Settings for the EU Cookie Compliance module.'),
    'type' => 'array',
    'access' => 'administer EU Cookie Compliance popup',
    'localize' => TRUE,
    'multidomain' => TRUE,
  );

  return $variable;
}
