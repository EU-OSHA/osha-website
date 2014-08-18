<?php

/**
 * Implements hook_drush_command().
 */
function menu_drush_command() {
  $items = array();

  $items['menu-create'] = array(
    'description' => "Create a menu in the Drupal database.",
    // Describe the arguments for this command.  Delete
    // this seciton if command takes no arguments.
    'arguments' => array(
      'menu_name' => 'The machine name of the new menu.',
      'title' => 'The menu title.',
      'description' => 'The menu description.'
    ),
    'options' => array(
      'title' => array(
        'description' => 'The menu title.',
      ),
      'description' => array(
        'description' => 'The menu description.',
      ),
    ),
    // Give one or more example commandline usages for this command
    'examples' => array(
      'drush menu-create new_menu "New Menu" "This is my new menu."' => 'Create a new menu in the database with the specified title and description.',
    ),
    'aliases' => array('mcrt'),
  );

  $items['add-menu-item'] = array(
    'description' => "Add a menu item to an existing menu in the Drupal database.",
    // Describe the arguments for this command.  Delete
    // this seciton if command takes no arguments.
    'arguments' => array(
      'menu_name' => 'The name of the menu to add the link to.',
      'title' => 'The menu item title.',
      'path' => 'The menu item target path.'
    ),
    'options' => array(
      'menu' => array(
        'description' => 'The name of the menu to add the link to.',
      ),
      'title' => array(
        'description' => 'The menu item title.',
      ),
      'path' => array(
        'description' => 'The menu item target path.',
      ),
      'weight' => array(
        'description' => 'The menu item weight. Optional; default is 0.',
      ),
      'expanded' => array(
        'description' => 'Set the "expanded" flag on the menu item. Default is not expanded.',
      ),
    ),
    // Give one or more example commandline usages for this command
    'examples' => array(
      'drush add-menu-item menu_name "New Link Title" "http://external.com/link/target"' => 'Create a new menu item in an existing menu in the database.',
    ),
    'aliases' => array('ami'),
  );

  $items['menu-list'] = array(
    'description' => "List all of the menus in the database.",
    'outputformat' => array(
      'default' => 'table',
      'pipe-format' => 'list',
      'field-labels' => array('menu_name' => 'Menu Name', 'title' => 'Title', 'description' => 'Description', ),
      'output-data-type' => 'format-table',
    ),
    'options' => array(
      'system' => array(
        'description' => 'Include system menus.  Default is to list only user-defined menus.',
      ),
    ),
    'aliases' => array('mlst'),
  );

  $items['menu-links'] = array(
    'description' => "List all of the links in the specified menu.",
    'outputformat' => array(
      'default' => 'table',
      'pipe-format' => 'list',
      'field-labels' => array('link_title' => 'Title', 'link_path' => 'Path', 'weight' => 'Weight', 'expanded' => 'Expanded', ),
      'output-data-type' => 'format-table',
    ),
    'aliases' => array('mlnk'),
  );

  // Commandfiles may also add topics.  These will appear in
  // the list of topics when `drush topic` is executed.
  $topic_file = dirname(__FILE__) . '/menu-create-topic.txt';
  if (file_exists($topic_file)) {
    $items['docs-menu-create'] = array(
      'description' => 'Description of command topic.',
      'hidden' => TRUE,
      'topic' => TRUE,
      'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
      'callback' => 'drush_print_file',
      'callback arguments' => array($topic_file),
    );
  }

  return $items;
}

/**
 * Implements hook_drush_help().
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function menu_drush_help($section) {
  switch ($section) {
    case 'drush:menu-create':
      return dt("Create a new menu in the Drupal database.");
    // The 'title' meta item is used to name a group of
    // commands in `drush help`.  If a title is not defined,
    // the default is "All commands in ___", with the
    // specific name of the commandfile (e.g. menu).
    // Command files with less than four commands will
    // be placed in the "Other commands" section, _unless_
    // they define a title.  It is therefore preferable
    // to not define a title unless the file defines a lot
    // of commands.
  }
}

/**
 * Implementation of drush_hook_COMMAND().
 *
 * Main command implementation goes here.
 */
function drush_menu_create($menu_name, $menu_title = '', $menu_description = '') {
  if (empty($menu_title)) {
    $menu_title = $menu_name;
  }
  // We allow the user to specify title and description either via argument
  // (less typing) or via option (more explicity, not order-dependant).
  $menu_title = drush_get_option('title', $menu_title);
  $menu_description = drush_get_option('description', $menu_description);

  $menu = array(
   'menu_name' => $menu_name,
   'title' => $menu_title,
   'description' => $menu_description,
  );

  // Try to load the specified menu name to find out if it already
  // exists.
  if (menu_load($menu_name)) {
    return drush_set_error('MENU_EXISTS', dt("The menu '!menu' already exists.", array("!menu" => $menu_name)));
  }
  menu_save($menu);
  drush_log(dt("Created menu !menu", array("!menu" => $menu_name)), 'success');
}

function drush_menu_list() {
  $include_system_menus = drush_get_option('system', FALSE);
  $menu_names = menu_get_menus($include_system_menus);
  $result = array();

  foreach ($menu_names as $menu_name => $menu_title) {
    $menu = menu_load($menu_name);
    $result[$menu_name] = $menu;
  }

  return $result;
}

function drush_menu_links($menu_name) {
  $links = menu_load_links($menu_name);

  $result = array();
  foreach ($links as $link_info) {
    $result[$link_info['mlid']] = array(
      'link_title' => $link_info['link_title'],
      'link_path' => $link_info['link_path'],
      'weight' => $link_info['weight'],
      'expanded' => $link_info['expanded'],
    );
  }
  return $result;
}
function drush_menu_add_menu_item($menu_name = '', $link_title = '', $link_path = '') {
  $link['menu_name'] = drush_get_option('menu', $menu_name);
  $link['link_title'] = drush_get_option('title', $link_title);
  $link['link_path'] = drush_get_option('title', $link_path);
  $link['weight'] = drush_get_option('weight', 0);
  $link['expanded'] = drush_get_option('expanded', 0);

  if (!menu_load($link['menu_name'])) {
    return drush_set_error('MENU_DOES_NOT_EXISTS', dt("The menu '!menu' does not exist.", array("!menu" => $link['menu_name'])));
  }

  $mlid = menu_link_save($link);
  drush_log(dt("Created menu link '!title' with mlid !mlid", array("!title" => $link['link_title'], '!mlid' => $mlid)), 'success');
}
