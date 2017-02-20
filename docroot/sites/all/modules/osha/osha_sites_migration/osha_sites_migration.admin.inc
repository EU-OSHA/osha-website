<?php

function osha_sites_migration_admin_config_form() {
  $form['title'] = array(
    '#markup' => '<h1>OSHA sites migration configuration</h1>',
  );

  // HWC migration
  if (module_exists('migrate')) {
    $form['migration'] = array(
      '#type' => 'fieldset',
      '#title' => 'OSHA websites content migration',
      '#collapsible' => TRUE,
    );
    $note = 'To disable one of the migrations set the URL empty then Save. Endpoints should expose JSON data';
    if (module_exists('migrate_ui')) {
      $note .= ' ' . l('Visit migration status overview', 'admin/content/migrate/groups/ncw');
    }
    $form['migration']['note'] = array(
      '#type' => 'item',
      '#markup' => $note,
    );

    $migration_api = osha_sites_migration_migrate_api();
    $groups = array_keys($migration_api['groups']);

    foreach($migration_api['migrations'] as $name => $meta) {
      $migration = MigrationBase::getInstance($name);
      $machine_name = $migration->getMachineName();
      $group_name = $meta['group_name'];
      if (in_array($group_name, $groups)) {
        $form['migration'][$group_name . "_migration_${machine_name}_url"] = array(
          '#type' => 'textfield',
          '#title' => ucfirst(str_replace('_', ' ', $machine_name)) . ' endpoint URI',
          '#default_value' => variable_get($group_name . "_migration_${machine_name}_url", ''),
          '#description' => 'Uri that will be appended to the Root endpoint URL defined',
          '#size' => 90,
        );
      }
      uksort($form['migration'], 'strcmp');
    }
  }
  foreach ($groups as $group) {
    $form['migration'][$group . "_migration_root_url"] = array(
      '#type' => 'textfield',
      '#title' => $group . ' endpoint URL',
      '#default_value' => variable_get($group . "_migration_root_url", ''),
      '#size' => 90,
    );
  }

  $form = system_settings_form($form);
  return $form;
}

