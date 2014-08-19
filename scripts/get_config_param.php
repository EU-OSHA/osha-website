<?php
/**
 * Author: Cristian Romanescu <cristi _at_ eaudeweb dot ro>
 * Created: 201407171712
 */

$config_file = sprintf('%s/../conf/config.json', dirname(__FILE__));
if (!is_readable($config_file)) {
  die("Cannot read config file! ($config_file). Please configure your project correctly");
}
$json = json_decode(file_get_contents($config_file), TRUE);
global $argv, $argc;
$ret = NULL;
if ($argc == 6) {
  $arg = strpos($arg, '.') ? explode('.', $argv[5]) : $argv[5];
  if (is_array($arg)) {
    foreach ($arg as $property) {
      $json = $json[$property];
    }
    $ret = $json;
  }
  else {
    $ret = $json[$arg];
  }
  if (!empty($ret)) {
    echo is_array($ret) ? implode(',', $ret) : $ret;
  }
}
