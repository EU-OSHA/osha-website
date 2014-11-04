<?php
/**
 * @file
 * Implements some developer commands.
 */


/**
 * Implements hook_drush_command().
 */
function build_drush_command() {
  $items = array();

  $items['build'] = array(
    'description' => 'Runs database updates, reverts features and clears caches.',
    'callback' => '_drush_build',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  $items['init'] = array(
    'description' => 'Initialize the Drupal project instance in the current docroot/',
    'callback' => '_drush_init',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'options' => array(
        'debug-modules' => 'If enabled, modules are enabled one by one'
    )
  );

  $items['devify'] = array(
    'description' => 'Configures the current database for development.',
    'callback' => '_drush_devify',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'options' => array(
      'enable-modules' => 'A comma separated list of modules to enable.',
      'disable-modules' => 'A comma separated list of modules to disable.',
      'delete-variables' => 'A comma separated list of variables to delete.',
      'reset-variables' => 'A comma separated list of variables to reset with ' .
                           'the format foo=var,hey=ho.',
    ),
    'examples' => array(
      'drush devify' => 'Uses command default values to set up a database for development.',
      'drush devify --enable-modules=xhprof,devel' => 'Enables XHProf and Devel modules',
      'drush devify --reset-variables=site_mail=local@local.com,file_temporary_path=/tmp'
        => 'Resets site_mail and file_temporary_path variables.',
    ),
  );

  return $items;
}

/**
 * Executes the build commands.
 */
function _drush_build() {
  $modules = drush_get_option('init-modules', array());
  _drush_enable_modules($modules);

  drush_invoke('updatedb');
  drush_invoke_process('@self', 'features-revert-all', array(), array(
    'force' => TRUE,
    'yes' => TRUE,
  ));
  drush_invoke('cc', array('type' => 'all'));
  drush_log(dt('Built!'), 'success');
}

/**
 * Callback for drush devify.
 */
function _drush_devify() {
  // Disable modules.
  $modules = drush_get_option('disable-modules', array('update'));
  if (is_string($modules)) {
    $modules = explode(',', $modules);
  }
  module_disable($modules);

  // Enable modules.
  $modules = drush_get_option('enable-modules', array());
  if (is_string($modules)) {
    $modules = explode(',', $modules);
  }
  module_enable($modules);

  // Delete variables.
  $variables = drush_get_option('delete-variables', array(
    'googleanalytics_account',
  ));
  if (is_string($variables)) {
    $variables = explode(',', $variables);
  }
  foreach ($variables as $variable) {
    variable_del($variable);
  }

  // Reset variables.
  $variables = drush_get_option('reset-variables', array(
    'preprocess_css' => 0,
    'preprocess_js' => 0,
    'cache' => 0,
    'page_compression' => 0,
  ));
  if (is_string($variables)) {
    // Explode a=b,c=d into an associative array.
    $variables_raw = explode(',', $variables);
    $variables = array();
    foreach ($variables_raw as $value) {
      $variable = explode('=', $value);
      if (count($variable) == 2) {
        $variables[$variable[0]] = $variable[1];
      }
    }
  }
  foreach ($variables as $name => $value) {
    variable_set($name, $value);
  }

  // Sanitize database.
  // @see sql_drush_sql_sync_sanitize() to add your sanitize queries.
  drush_sql_sanitize();

  drush_log(dt('Devified!'), 'success');
}

function _drush_init() {
    drush_log(dt('Enabling the required modules'), 'success');
    // Enable modules.
    $modules = drush_get_option('init-modules', array());
    _drush_enable_modules($modules);

    // Enable themes.
    drush_log(dt('Enabling the required themes'), 'success');

    $themes = drush_get_option('init-themes', array());
    _drush_enable_themes($themes);
}


function _drush_enable_modules($modules) {
    if(empty($modules)) {
        return;
    }
    if (is_string($modules)) {
        $modules = explode(',', $modules);
    }
    $debug = drush_get_option('debug-modules', FALSE);
    if(!$debug) {
        if(!module_enable($modules, TRUE)) {
            drush_log(dt('Failed to enable one ore more modules'), 'error');
        }
    } else {
        foreach($modules as $module) {
            if(!module_enable(array($module))) {
                drush_log(dt('Failed to enable @module', array('@module' => $module)), 'error');
            } else {
              drush_log("Enabling $module ...\n", 'ok');
            }
        }
    }
}

function _drush_enable_themes($themes) {
  if(empty($themes)) {
    return;
  }

  $debug = drush_get_option('debug-themes', FALSE);
  if(!$debug){
    theme_enable($themes);

    $drupal_themes = list_themes();
    foreach ($themes as $theme) {
      if (!theme_exists($theme)) {
        drush_log(dt('Failed to enable one ore more themes'), 'error');
      }
    }
  } else {
    foreach ($themes as $theme) {
      if (!theme_exists($theme)) {
        drush_log(dt('Failed to enable @theme', array('@theme' => $theme)), 'error');
      }
    }
  }
}

/**
 * Check if a theme exists and is enabled.
 */
function theme_exists($theme_name) {
  $themes = list_themes();
  return isset($themes[$theme_name]) && $themes[$theme_name]->status == 1;
}
