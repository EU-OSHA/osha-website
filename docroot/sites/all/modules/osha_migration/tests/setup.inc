<?php
/**
 * Author: Cristian Romanescu <cristi _at_ eaudeweb dot ro>
 * Created: 201408141819
 */

/**
 * Enables all module required during test setup.
 */
function osha_migration_enable_modules_simpletest() {
  require DRUPAL_ROOT . '/../drush/drushrc.php';
  if (!empty($options['init-modules'])) {
    $modules = $options['init-modules'];
    if (!module_enable($modules)) {
      foreach ($modules as $module) {
        if (!module_enable(array($module))) {
          drupal_set_message('Cannot enable module: ' . $module, 'error');
        }
      }
    }
  }
}
