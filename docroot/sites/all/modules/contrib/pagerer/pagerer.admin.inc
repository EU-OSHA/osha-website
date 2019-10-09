<?php
/**
 * @file
 * Pagerer administration
 *
 * Drupal core 7.x
 *
 * @package  User interface
 * @author   mondrake <mondrake@mondrake.org>
 */

/**
 * Main Pagerer settings admin form.
 */
function pagerer_settings_form($form, &$form_state) {
  // Add Pagerer's css.
  drupal_add_css(drupal_get_path('module', 'pagerer') . '/pagerer.css');

  // Prepare fake pager for previews.
  pager_default_initialize(47884, 50);

  // Presets table.
  $form['presets'] = array(
    '#theme' => 'pagerer_preset_list',
  );

  // Container for global options.
  $form['pagerer'] = array(
    '#type' => 'fieldset',
    '#title' => t("General"),
  );
  // Global option for pager override.
  $options = array(
    t('Default:') => array('core' => t('No - use Drupal core pager')),
    t('Replace with:') => _pagerer_list_presets(),
  );
  $form['pagerer']['core_override_preset'] = array(
    '#type' => 'select',
    '#title' => t("Replace standard pager"),
    '#description' => t("Core pager theme requests can be overridden with any Pagerer preset. Select whether they need to be fulfilled by Drupal core pager, or the Pagerer preset to use."),
    '#options' => $options,
    '#default_value' => _pagerer_get_variable('core_override_preset'),
  );

  // Save configuration.
  $form['save'] = array(
    '#type' => 'submit',
    '#name' => 'save',
    '#value' => t("Save configuration"),
  );

  return $form;
}

/**
 * Main Pagerer settings admin form - submission.
 */
function pagerer_settings_form_submit($form, &$form_state) {
  $v = $form_state['values'];
  // Set variable.
  _pagerer_set_variable('core_override_preset', $v['core_override_preset']);
  drupal_set_message(t('The configuration options have been saved.'), 'status');
}

/**
 * Render a table with the presets lists.
 *
 * Including links to edit and delete operations.
 */
function theme_pagerer_preset_list() {
  $header = array(
    t('Preset name'),
    t('Preview'), array('data' => t('Operations'), 'colspan' => 2),
  );
  $rows = array();
  foreach (_pagerer_list_presets() as $key => $value) {
    $row = array();
    $row[] = l($key, _PAGERER_CONFIG_PATH . '/edit/' . $key);
    $row[] = array(
      'data' => theme('pagerer', array('preset' => $key)),
      'class' => array('pagerer-admin-preset-preview'),
    );
    $row[] = l(t('edit'), _PAGERER_CONFIG_PATH . '/edit/' . $key);
    $row[] = l(t('delete'), _PAGERER_CONFIG_PATH . '/delete/' . $key);
    $rows[] = $row;
  }
  if (empty($rows)) {
    $rows[] = array(
      array(
        'colspan' => 4,
        'data' => t(
          'There are currently no presets. <a href="!url">Add a new one</a>.',
          array('!url' => url(_PAGERER_CONFIG_PATH . '/add'))
        ),
      ),
    );
  }
  return theme(
    'table',
    array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array('class' => array('pagerer-admin-preset-list')),
    )
  );
}

/**
 * Preset edit form.
 */
function pagerer_preset_form($form, &$form_state) {

  // Add Pagerer's css.
  drupal_add_css(drupal_get_path('module', 'pagerer') . '/pagerer.css');

  // Get pagerer preset.
  $preset = _pagerer_get_preset($form_state['build_info']['args'][0]);

  // Check if jQuery update is installed.
  if (module_exists('jquery_update')) {
    $js_enabled = TRUE;
  }
  else {
    $js_enabled = FALSE;
    drupal_set_message(
      t("To enable the jQuery based themes 'pagerer_mini', 'pagerer_slider' and 'pagerer_scrollpane', Pagerer requires the 'jQuery update' module to be installed and enabled."),
      'status',
      FALSE
    );
  }

  // List of the themes available for panes.
  $options = array(
    'none',
    'pagerer_standard',
    'pagerer_progressive',
    'pagerer_adaptive',
  );
  // Mini, Slider and Scrollpane are only available with jQuery update
  // installed.
  if ($js_enabled) {
    $options = array_merge($options, array(
        'pagerer_mini',
        'pagerer_slider',
        'pagerer_scrollpane',
      )
    );
  }
  $options = drupal_map_assoc($options);

  // Panes configuration.
  $form['panes_container'] = array(
    '#type' => 'fieldset',
    '#title' => t("Panes configuration"),
    '#description' => t("Select the themes to be rendered in each Pagerer pane. Click 'Configure' to change each theme behaviour. Click 'Reset' to reset a pane configuration to its theme's default."),
  );

  // Table container to render the 3 pane config boxes inline.
  $form['panes_container']['panes'] = array(
    '#tree'          => TRUE,
    '#title'         => t("Panes"),
    '#theme'         => 'table',
    '#header'        => array(),
    '#rows'          => array(),
    '#attributes'    => array('class' => array('pagerer_admin_panes_config')),
  );
  // Left pane.
  $left_pane = array(
    '#type' => 'fieldset',
    '#title' => t("Left pane"),
  );
  $left_pane['theme_name'] = array(
    '#type' => 'select',
    '#title' => t("Theme"),
    '#options' => $options,
    '#default_value' => $preset['left_pane']['theme_name'],
  );
  $left_pane['configure'] = array(
    '#type' => 'submit',
    '#name' => 'config_left',
    '#value' => t("Configure"),
  );
  $left_pane['reset'] = array(
    '#type' => 'submit',
    '#name' => 'reset_left',
    '#value' => t("Reset"),
  );
  // Center pane.
  $center_pane = array(
    '#type' => 'fieldset',
    '#title' => t("Center pane"),
  );
  $center_pane['theme_name'] = array(
    '#type' => 'select',
    '#title' => t("Theme"),
    '#options' => $options,
    '#default_value' => $preset['center_pane']['theme_name'],
  );
  $center_pane['configure'] = array(
    '#type' => 'submit',
    '#name' => 'config_center',
    '#value' => t("Configure"),
  );
  $center_pane['reset'] = array(
    '#type' => 'submit',
    '#name' => 'reset_center',
    '#value' => t("Reset"),
  );
  // Right pane.
  $right_pane = array(
    '#type' => 'fieldset',
    '#title' => t("Right pane"),
  );
  $right_pane['theme_name'] = array(
    '#type' => 'select',
    '#title' => t("Theme"),
    '#options' => $options,
    '#default_value' => $preset['right_pane']['theme_name'],
  );
  $right_pane['configure'] = array(
    '#type' => 'submit',
    '#name' => 'config_right',
    '#value' => t("Configure"),
  );
  $right_pane['reset'] = array(
    '#type' => 'submit',
    '#name' => 'reset_right',
    '#value' => t("Reset"),
  );
  // Container elements - FAPI accessible.
  $form['panes_container']['panes']['e'] = array(
    'left' => array('data' => &$left_pane),
    'center' => array('data' => &$center_pane),
    'right' => array('data' => &$right_pane),
  );
  // Container elements - to render the table.
  $form['panes_container']['panes']['#rows'][0] = array(
    array('data' => &$left_pane),
    array('data' => &$center_pane),
    array('data' => &$right_pane),
  );

  // Pagerer's preview.
  pager_default_initialize(47884, 50);
  $form['preview'] = array(
    '#type' => 'fieldset',
    '#title' => t("Pagerer preview"),
  );
  $form['preview']['pagerer'] = array(
    '#markup' => theme('pagerer', array(
                        'left_pane'   => $preset['left_pane'],
                        'center_pane' => $preset['center_pane'],
                        'right_pane' => $preset['right_pane'],
                      )),
  );

  // Save configuration.
  $form['save'] = array(
    '#type' => 'submit',
    '#name' => 'save',
    '#value' => t("Update"),
  );
  $form['save_return'] = array(
    '#type' => 'submit',
    '#name' => 'save_return',
    '#value' => t("Save and return"),
  );

  return $form;
}

/**
 * Preset edit form - validation.
 */
function pagerer_preset_form_validate($form, &$form_state) {
  $v = &$form_state['values'];
  // Check 'Config' was invoked without selecting a theme.
  if (strpos($form_state['triggering_element']['#name'], 'config', 0) === 0) {
    $e = explode('_', $form_state['triggering_element']['#name']);
    $pane = $e[1];
    if ($v['panes']['e'][$pane]['data']['theme_name'] == 'none') {
      form_set_error(
        'panes][e][' . $pane . '][data',
        t("Select a theme before clicking 'Configure'.")
      );
    }
  }
}

/**
 * Preset edit form - submission.
 */
function pagerer_preset_form_submit($form, &$form_state) {
  $preset_name = $form_state['build_info']['args'][0];
  $preset = _pagerer_get_preset($preset_name);
  $trigger = $form_state['triggering_element']['#name'];
  $v = $form_state['values'];

  // Set variables.
  $preset['left_pane']['theme_name'] = $v['panes']['e']['left']['data']['theme_name'];
  $preset['center_pane']['theme_name'] = $v['panes']['e']['center']['data']['theme_name'];
  $preset['right_pane']['theme_name'] = $v['panes']['e']['right']['data']['theme_name'];
  _pagerer_save_preset($preset_name, $preset);

  // Hands over to pane configuration or theme reset if requested.
  if (strpos($trigger, 'config', 0) === 0) {
    $e = explode('_', $trigger);
    $pane = $e[1];
    $form_state['redirect'] = _PAGERER_CONFIG_PATH . '/edit/' . $preset_name . '/' . $pane;
  }
  elseif (strpos($trigger, 'reset', 0) === 0) {
    $e = explode('_', $trigger);
    $pane = $e[1];
    $form_state['redirect'] = _PAGERER_CONFIG_PATH . '/edit/' . $preset_name . '/' . $pane . '/reset';
  }
  elseif ($trigger == 'save') {
    drupal_set_message(t('Preset %preset has been saved.', array('%preset' => $preset_name)), 'status');
  }
  else {
    drupal_set_message(t('Preset %preset has been saved.', array('%preset' => $preset_name)), 'status');
    $form_state['redirect'] = _PAGERER_CONFIG_PATH;
  }
}

/**
 * Preset add form.
 */
function pagerer_preset_add_form($form, &$form_state) {
  $form['name'] = array(
    '#type' => 'textfield',
    '#size' => '64',
    '#title' => t('New preset name'),
    '#default_value' => '',
    '#description' => t("Use only lowercase alphanumeric characters, underscores (_), and hyphens (-). Preset name 'core' is reserved for internal use."),
    '#element_validate' => array('pagerer_preset_name_validate'),
    '#required' => TRUE,
  );

  return confirm_form(
    $form,
    t('Add preset'),
    _PAGERER_CONFIG_PATH,
    '',
    t('Create preset'),
    t('Cancel')
  );
}

/**
 * Preset add form - submission.
 */
function pagerer_preset_add_form_submit($form, &$form_state) {
  $preset_name = $form_state['values']['name'];
  $theme_registry = theme_get_registry();
  $preset = $theme_registry['pagerer']['variables'];
  _pagerer_save_preset($preset_name, $preset);
  drupal_set_message(t('Preset %name was created.', array('%name' => $preset_name)));
  $form_state['redirect'] = _PAGERER_CONFIG_PATH . '/edit/' . $preset_name;
}

/**
 * Preset name validation.
 */
function pagerer_preset_name_validate($element, $form_state) {
  // 'core' preset name is reserved.
  if ($element['#value'] == 'core') {
    form_set_error($element['#name'], t("The preset name 'core' is reserved for internal use."));
  }

  // Check for duplicates.
  $list = _pagerer_list_presets();
  if (isset($list[$element['#value']])) {
    form_set_error($element['#name'], t('The preset name %name is already in use.', array('%name' => $element['#value'])));
  }

  // Check for illegal characters in preset names.
  if (preg_match('/[^0-9a-z_\-]/', $element['#value'])) {
    form_set_error($element['#name'], t('Please only use lowercase alphanumeric characters, underscores (_), and hyphens (-) for preset names.'));
  }
}

/**
 * Preset delete form.
 */
function pagerer_preset_delete_form($form, &$form_state) {
  $preset_name = $form_state['build_info']['args'][0];
  return confirm_form(
    $form,
    t('Delete preset %preset', array('%preset' => $preset_name)),
    _PAGERER_CONFIG_PATH,
    t('Are you sure you want to delete preset %preset ?', array('%preset' => $preset_name)),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Preset delete form - submission.
 */
function pagerer_preset_delete_form_submit($form, &$form_state) {
  $preset_name = $form_state['build_info']['args'][0];
  if (_pagerer_get_variable('core_override_preset') == $preset_name) {
    _pagerer_set_variable('core_override_preset', 'core');
    drupal_set_message(t("Preset %preset was being used as replacement of Drupal's core pager. Drupal's core pager has been reset as main pager to allow for deletion of the preset.", array('%preset' => $preset_name)), 'warning');
  }
  _pagerer_delete_preset($preset_name);
  drupal_set_message(t('Preset %preset has been deleted.', array('%preset' => $preset_name)), 'status');
  $form_state['redirect'] = _PAGERER_CONFIG_PATH;
}

/**
 * Pane level settings form.
 */
function pagerer_pane_form($form, &$form_state) {

  // Check if jQuery update is installed.
  if (module_exists('jquery_update')) {
    $js_enabled = TRUE;
  }
  else {
    $js_enabled = FALSE;
    drupal_set_message(
      t("To enable the jQuery elements 'widget', 'slider' and 'scrollpane' for current page, Pagerer requires the 'jQuery update' module to be installed and enabled."),
      'status',
      FALSE
    );
  }

  // Get pagerer preset.
  $preset = _pagerer_get_preset($form_state['build_info']['args'][0]);

  // Pane to be configured.
  $pane = $form_state['build_info']['args'][1];

  // Merge configuration variables with those coming from default theme
  // variables.
  $theme = $preset[$pane . '_pane']['theme_name'];
  if (isset($preset[$pane . '_pane']['theme_variables'])) {
    $theme_vars = $preset[$pane . '_pane']['theme_variables'];
  }
  else {
    $theme_vars = array();
  }
  $theme_registry = theme_get_registry();
  $default_theme_vars = $theme_registry[$theme]['variables'];
  $v = array_merge($default_theme_vars, $theme_vars);

  // Pane theme.
  switch ($pane) {
    case 'left':
      $pane_title = t("Left pane theme");
      break;

    case 'center':
      $pane_title = t("Center pane theme");
      break;

    case 'right':
      $pane_title = t("Right pane theme");
      break;
  }
  $form['theme_name'] = array(
    '#type' => 'textfield',
    '#title' => check_plain($pane_title),
    '#default_value' => $theme,
    '#description' => t("To change the pane theme, go back to the 'Edit preset' form."),
    '#disabled' => TRUE,
  );

  $options = drupal_map_assoc(array('pages', 'items', 'item_ranges'));
  $form['display'] = array(
    '#type' => 'select',
    '#title' => t("Display"),
    '#options' => $options,
    '#default_value' => $v['display'],
    '#description' => t("Select whether to display pages, or items, or item ranges."),
    '#required' => TRUE,
  );
  $form['quantity'] = array(
    '#type' => 'textfield',
    '#title' => t("Quantity"),
    '#default_value' => $v['quantity'],
    '#description' => t("The number of pages in the pager list."),
    '#required' => TRUE,
    '#size' => 3,
    '#maxlength' => 3,
  );
  if ($theme == 'pagerer_progressive') {
    $form['factors'] = array(
      '#type' => 'textfield',
      '#title' => t("Scale factors"),
      '#default_value' => $v['factors'],
      '#description' => t("Comma delimited string of factors to use to determine progressive links."),
      '#required' => TRUE,
    );
  }

  // Display configuration.
  $form['display_container'] = array(
    '#type' => 'fieldset',
    '#title' => t("Main elements"),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t("Configure main pager elements as 'label', 'current page' and 'total'."),
  );
  $options = drupal_map_assoc(array('none', 'before_current', 'first', 'last'));
  $form['display_container']['label_display'] = array(
    '#type' => 'select',
    '#title' => t("Label"),
    '#options' => $options,
    '#default_value' => $v['label_display'],
    '#description' => t("Select whether and where to render a text 'label' element (e.g. 'Page'). Options are 'none' (not displayed), 'before_current' (in front of current page), 'first' (at the beginning), 'last' (at the end)."),
    '#required' => TRUE,
  );
  $options = array('none', 'normal');
  // Widget, Slider and Scrollpane are only available with jQuery update
  // installed.
  if ($js_enabled) {
    $options = array_merge($options, array('widget', 'slider', 'scrollpane'));
  }
  $options = drupal_map_assoc($options);
  $form['display_container']['current_display'] = array(
    '#type' => 'select',
    '#title' => t("Current page"),
    '#options' => $options,
    '#default_value' => $v['current_display'],
    '#description' => t("Select how the current page is rendered in the pager. Options are 'none' (not displayed), 'normal' (as a text), 'widget' (an active input box for users to enter directly a page to go to), 'slider' (as a slider), 'scrollpane' (as a scrolling pane embedding a full pager)."),
    '#required' => TRUE,
  );
  $options = drupal_map_assoc(array('none', 'after_current', 'first', 'last'));
  $form['display_container']['total_display'] = array(
    '#type' => 'select',
    '#title' => t("Total pages/items"),
    '#options' => $options,
    '#default_value' => $v['total_display'],
    '#description' => t("Select whether and where to render a text element indicating the total pages (or items). Options are 'none' (not displayed), 'after_current' (just after current page), 'first' (at the beginning), 'last' (at the end)."),
    '#required' => TRUE,
  );

  // Links configuration.
  $form['links_container'] = array(
    '#type' => 'fieldset',
    '#title' => t("Links"),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t("Configure link elements like '<< first', '< previous', 'next >' and 'last >>'."),
  );
  $options = drupal_map_assoc(array('never', 'not_on_first', 'always'));
  $form['links_container']['first_link'] = array(
    '#type' => 'select',
    '#title' => t("First"),
    '#options' => $options,
    '#default_value' => $v['first_link'],
    '#description' => t("Select when to render a link to the first page (e.g. '<< first'). Options are 'never' (not displayed), 'not_on_first' (not displayed if current page is the first), 'always' (always displayed)."),
    '#required' => TRUE,
  );
  $options = drupal_map_assoc(array('never', 'not_on_first', 'always'));
  $form['links_container']['previous_link'] = array(
    '#type' => 'select',
    '#title' => t("Previous"),
    '#options' => $options,
    '#default_value' => $v['previous_link'],
    '#description' => t("Select when to render a link to the previous page (e.g. '<< previous'). Options are 'never' (not displayed), 'not_on_first' (not displayed if current page is the first), 'always' (always displayed)."),
    '#required' => TRUE,
  );
  $options = drupal_map_assoc(array('never', 'not_on_last', 'always'));
  $form['links_container']['next_link'] = array(
    '#type' => 'select',
    '#title' => t("Next"),
    '#options' => $options,
    '#default_value' => $v['next_link'],
    '#description' => t("Select when to render a link to the next page (e.g. 'next >'). Options are 'never' (not displayed), 'not_on_last' (not displayed if current page is the last), 'always' (always displayed)."),
    '#required' => TRUE,
  );
  $options = drupal_map_assoc(array('never', 'not_on_last', 'always'));
  $form['links_container']['last_link'] = array(
    '#type' => 'select',
    '#title' => t("Last"),
    '#options' => $options,
    '#default_value' => $v['last_link'],
    '#description' => t("Select when to render a link to the last page (e.g. 'last >>'). Options are 'never' (not displayed), 'not_on_last' (not displayed if current page is the last), 'always' (always displayed)."),
    '#required' => TRUE,
  );
  if ($theme == 'pagerer_adaptive' or $theme == 'pagerer_progressive') {
    $options = drupal_map_assoc(array('relative', 'absolute'));
    $form['links_container']['progr_links'] = array(
      '#type' => 'select',
      '#title' => t("Outer pages"),
      '#options' => $options,
      '#default_value' => $v['progr_links'],
      '#description' => t("Progressive and Adaptive pagers render links to pages far from the current. Select whether to render these links as 'absolute' page numbers (or items/item ranges) or as 'relative' offsets from current (e.g. +10 +100 +1000)."),
      '#required' => TRUE,
    );
  }

  // Separators configuration.
  $form['separators_container'] = array(
    '#type' => 'fieldset',
    '#title' => t("Separators"),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t("Configure separators text."),
  );
  $form['separators_container']['pager_breaker'] = array(
    '#type' => 'textfield',
    '#title' => t("Breaker"),
    '#default_value' => $v['pager_breaker'],
    '#description' => t("Text to render a break in the page sequence."),
  );
  $form['separators_container']['pager_separator'] = array(
    '#type' => 'textfield',
    '#title' => t("Element separator"),
    '#default_value' => $v['pager_separator'],
    '#description' => t("Text to fill between contiguous pages. 'none' will prevent creating any filler."),
  );
  $form['separators_container']['range_separator'] = array(
    '#type' => 'textfield',
    '#title' => t("Range separator"),
    '#default_value' => $v['range_separator'],
    '#description' => t("Text to place between first and last item in a range."),
  );

  // Advanced options configuration.
  $form['advanced_options_container'] = array(
    '#type' => 'fieldset',
    '#title' => t("Advanced options"),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t("Configure advanced options."),
  );
  $form['advanced_options_container']['widget'] = array(
    '#type' => 'fieldset',
    '#title' => t("Widget"),
    '#collapsible' => FALSE,
    '#description' => t("jQuery widget options."),
  );
  $form['advanced_options_container']['widget']['widget_resize'] = array(
    '#type' => 'checkbox',
    '#title' => t("Automatic width adjustment"),
    '#default_value' => $v['widget_resize'],
    '#description' => t("If set, the widget's width will be adjusted dynamically based on the total number of pages/items. When unset, style width will prevail."),
  );
  $form['advanced_options_container']['slider'] = array(
    '#type' => 'fieldset',
    '#title' => t("Slider"),
    '#collapsible' => FALSE,
    '#description' => t("jQuery slider options."),
  );
  $options = drupal_map_assoc(array('tickmark', 'timelapse', 'auto'));
  $form['advanced_options_container']['slider']['slider_action'] = array(
    '#type' => 'select',
    '#title' => t("Action confirmation method"),
    '#options' => $options,
    '#default_value' => $v['slider_action'],
    '#description' => t("Select how the page relocation should be triggered after it has been selected through the slider. Options are: 'tickmark' (page relocation only occurs after user clicks a tickmark on the slider handle), 'timelapse' (page relocation occurs after a grace time has elapsed), 'auto' (the timelapse method is automatically selected based on the accuracy of the slider)."),
    '#required' => TRUE,
  );
  $form['advanced_options_container']['slider']['slider_action_timelapse'] = array(
    '#type' => 'textfield',
    '#title' => t("Confirmation timelapse"),
    '#default_value' => $v['slider_action_timelapse'],
    '#description' => t("The grace time (in milliseconds) to wait before the page is relocated, in case 'timelapse' confirmation method is selected. '0' will trigger relocation immediately."),
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => TRUE,
  );
  $options = drupal_map_assoc(array('yes', 'no', 'auto'));
  $form['advanced_options_container']['slider']['slider_navigation_icons'] = array(
    '#type' => 'select',
    '#title' => t("Display navigation icons"),
    '#options' => $options,
    '#default_value' => $v['slider_navigation_icons'],
    '#description' => t("Select whether to display +/- navigation icons on the sides of the slider. Options are 'yes', 'no', 'auto' (the icons are automatically displayed based on the accuracy of the slider)."),
    '#required' => TRUE,
  );

  // Save configuration.
  $form['save'] = array(
    '#type' => 'submit',
    '#name' => 'save',
    '#value' => t("Save pane"),
  );

  return $form;
}

/**
 * Pane level settings form - submission.
 */
function pagerer_pane_form_submit($form, &$form_state) {

  // Get pagerer preset.
  $preset_name = $form_state['build_info']['args'][0];
  $preset = _pagerer_get_preset($preset_name);

  // Pane to be configured.
  $pane = $form_state['build_info']['args'][1];

  $p = $pane . '_pane';
  $v = $form_state['values'];

  $preset[$p]['theme_variables']['pager_breaker'] = $v['pager_breaker'];
  $preset[$p]['theme_variables']['pager_separator'] = $v['pager_separator'];
  $preset[$p]['theme_variables']['range_separator'] = $v['range_separator'];
  $preset[$p]['theme_variables']['display'] = $v['display'];
  $preset[$p]['theme_variables']['quantity'] = $v['quantity'];
  $preset[$p]['theme_variables']['label_display'] = $v['label_display'];
  $preset[$p]['theme_variables']['current_display'] = $v['current_display'];
  $preset[$p]['theme_variables']['total_display'] = $v['total_display'];
  $preset[$p]['theme_variables']['first_link'] = $v['first_link'];
  $preset[$p]['theme_variables']['previous_link'] = $v['previous_link'];
  $preset[$p]['theme_variables']['next_link'] = $v['next_link'];
  $preset[$p]['theme_variables']['last_link'] = $v['last_link'];
  if (isset($v['progr_links'])) {
    $preset[$p]['theme_variables']['progr_links'] = $v['progr_links'];
  }
  if (isset($v['factors'])) {
    $preset[$p]['theme_variables']['factors'] = $v['factors'];
  }
  $preset[$p]['theme_variables']['widget_resize'] = $v['widget_resize'];
  $preset[$p]['theme_variables']['slider_action'] = $v['slider_action'];
  $preset[$p]['theme_variables']['slider_action_timelapse'] = $v['slider_action_timelapse'];
  $preset[$p]['theme_variables']['slider_navigation_icons'] = $v['slider_navigation_icons'];
  _pagerer_save_preset($preset_name, $preset);
  drupal_set_message(t('The pane configuration has been saved.'), 'status');
  $form_state['redirect'] = _PAGERER_CONFIG_PATH . '/edit/' . $preset_name;
}

/**
 * Pane level settings reset form.
 */
function pagerer_pane_theme_reset_form($form, &$form_state) {
  $preset_name = $form_state['build_info']['args'][0];
  $pane = $form_state['build_info']['args'][1];
  $preset = _pagerer_get_preset($preset_name);
  $theme_name = $preset[$pane . '_pane']['theme_name'];
  return confirm_form(
    $form,
    t('Reset theme variables'),
    _PAGERER_CONFIG_PATH . '/edit/' . $preset_name,
    t('Are you sure you want to reset %pane pane of preset %preset to %theme default theme variables?',
      array(
        '%preset' => $preset_name,
        '%pane' => $pane,
        '%theme' => $theme_name,
      )
    ),
    t('Reset'),
    t('Cancel')
  );
}

/**
 * Pane level settings reset form - submission.
 */
function pagerer_pane_theme_reset_form_submit($form, &$form_state) {
  $preset_name = $form_state['build_info']['args'][0];
  $pane = $form_state['build_info']['args'][1];
  $preset = _pagerer_get_preset($preset_name);
  $theme_name = $preset[$pane . '_pane']['theme_name'];
  $theme_registry = theme_get_registry();
  $preset[$pane . '_pane']['theme_variables'] = $theme_registry[$theme_name]['variables'];
  unset(
    $preset[$pane . '_pane']['theme_variables']['element'],
    $preset[$pane . '_pane']['theme_variables']['parameters']
  );
  _pagerer_save_preset($preset_name, $preset);
  drupal_set_message(
    t('The %pane pane configuration has been reset to default %theme theme variables.', array('%theme' => $theme_name, '%pane' => $pane)),
    'status'
  );
  $form_state['redirect'] = _PAGERER_CONFIG_PATH . '/edit/' . $preset_name;
}
