<?php

/**
 * Reads config from file.
 * @return bool|mixed
 */
function osha_get_config() {
  $config_file = sprintf('%s/../conf/config.json', dirname(__FILE__));
  if (!is_readable($config_file)) {
    drupal_set_message("Cannot read configuration file!", 'warning');
    return FALSE;
  }
  static $cfg;
  if (empty($cfg)) {
    $cfg = json_decode(file_get_contents($config_file), TRUE);
    if (empty($cfg)) {
      drupal_set_message('Configuration file was empty, nothing to do here', 'warning');
      return FALSE;
    }
  }
  return $cfg;
}
