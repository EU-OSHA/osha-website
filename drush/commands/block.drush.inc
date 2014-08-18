<?php

/**
 * @file
 * block - Configure or disable a block.
 *
 * Copyright (C) 2010 by the original authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/**
 * Implementation of block_drush_command().
 */
function block_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  $items['block-configure'] = array(
    // the name of the function implementing your command.
    'callback' => 'drush_block_configure_save',
    // a short description of your command
    'description' => "Saves single block configuration (ie move block to a region)",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('block',),
    'options' => array(
      'theme'  => 'Which theme this block is being configured for. Optional. Defaults to default site theme.',
      'module' => 'Module that defines the block.',
      'delta'  => 'Block delta.',
      'region' => 'Region where to place block. Optional. Defaults to BLOCK_REGION_NONE which means disabled.',
      'weight' => 'Block weight. Optional. Defaults to 0.',
    ),
    'examples' => array(
      'drush block-configure login sidebar_first 10' => 'Blocks may be identified via sequential arguments rather than named options in instances where the identifier is unique. Numeric options always specify the block weight. Negative weights must be specified via --weight=-10, as -10 is interpreted as an option.',
    ),
  );
  $items['block-disable'] = array(
    'description' => 'Quickly disable a single block',
    'bootstrap'   => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('block', ),
    'options' => array(
      'theme'  => 'Which theme this block is being configured for. Optional. Defaults to default site theme.',
      'module' => 'Module that defines the block.',
      'delta'  => 'Block delta.',
    ),
  );
  $items['block-show'] = array(
    'description' => 'Show the configuration options for one or more blocks',
    'bootstrap'   => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('block', ),
    'options' => array(
      'theme'  => 'Which theme to select blocks from. Optional. Defaults to default site theme.',
      'module' => 'Only show blocks defined by the specified module.',
      'delta'  => 'Only show blocks with the specified delta.',
      'region' => 'Only show blocks in a particular region.',
      'configured' => 'Only show blocks that have been configured to appear in some region.',
      'disabled' => 'Only show blocks that have not been configured to appear in any region.',
      'weight' => 'Filter by weight.',
    ),
    'examples' => array(
      'drush block-show views' => 'Show all of the views blocks; same as `drush block-show --module=views`.',
      'drush block-show sidebar_first' => 'Show all of the blocks in sidebar_first; same as `drush block-show --region=sidebar_first`.',
    ),
  );

  return $items;
}

/**
 * Implementation of block_drush_help().
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function block_drush_help($section) {
  switch ($section) {
    case 'drush:block-configure':
      return dt("Saves single block configuration.");
    case 'drush:block-show':
      return dt("Show all blocks.");
    case 'drush:block-disable':
      return dt("Disable a single block.");
  }
}

/**
 * Example drush command callback.
 *
 * This is where the action takes place.
 *
 * In this function, all of Drupals API is (usually) available, including
 * any functions you have added in your own modules/themes.
 *
 * To print something to the terminal window, use drush_print().
 *
 */
function drush_block_configure_save() {
  if (drush_drupal_major_version() < 7) {
    init_theme();
  }
  else {
    drupal_theme_initialize();
  }
  global $theme_key;
  $theme  = drush_get_option('theme', $theme_key);

  $options['module'] = drush_get_option('module', NULL);
  $options['delta']  = drush_get_option('delta', NULL);
  $options['region'] = drush_get_option('region', BLOCK_REGION_NONE);
  $options['weight'] = drush_get_option('weight', 0);

  module_load_include('inc', 'block', 'block.admin');
  $blocks = _block_rehash($theme);

  if (!_drush_block_interpret_arguments($options, $blocks, func_get_args())) {
    return FALSE;
  }

  if (!isset($options['delta']) ) {
    return drush_set_error("BLOCK_NO_DELTA", dt("You must set the block delta."));
  }

  if (!isset($options['module'])) {
    $found_module = FALSE;
    foreach ($blocks as $block) {
      if ($block['delta'] == $options['delta']) {
        if (!isset($options['module'])) {
          $options['module'] = $block['module'];
        }
        else {
          return drush_set_error('BLOCK_AMBIGUOUS_DELTA', dt('Block is ambiguous; !delta appears in both !one and !theother. Please specify both module and delta to disambiguate.', array('!delta' => $optons['delta'], '!one' => $block['module'], '!theother' => $options['module'])));
        }
      }
    }
    if (!isset($options['module'])) {
      return drush_set_error("BLOCK_NO_DELTA", dt("Block delta !delta not found", array('!delta' => $optons['delta'])));
    }
  }

  if ( !count( $blocks ) ) {
    return drush_set_error("BLOCK_NOT_FOUND", dt("Specified theme blocks were not found"));
  }

  $values = array(
    'region' => $options['region'],
    'theme'  => $theme,
    'weight' => $options['weight'],
  );

  if (drush_drupal_major_version() < 7) {
    $form_state['values'][$options['module'] .'_'. $options['delta']] = $values;
    drupal_execute('block_admin_display_form', $form_state, $blocks, $theme);
  }
  else {
    $values['module'] = $options['module'];
    $values['delta'] = $options['delta'];
    $form_state['values']['blocks'][$options['module'] .'_'. $options['delta']] = $values;
    drupal_form_submit('block_admin_display_form', $form_state, $blocks, $theme);
  }
}

function drush_block_show() {
  global $theme_key;
  $theme  = drush_get_option('theme', $theme_key);
  $configured = drush_get_option('configured', FALSE);
  $disabled = drush_get_option('disabled', FALSE);

  $filters['module'] = drush_get_option('module', NULL);
  $filters['delta']  = drush_get_option('delta', NULL);
  $filters['region'] = drush_get_option('region', NULL);
  $filters['weight'] = drush_get_option('weight', NULL);

  module_load_include('inc', 'block', 'block.admin');
  $blocks = _block_rehash($theme);

  if (!_drush_block_interpret_arguments($filters, $blocks, func_get_args())) {
    return FALSE;
  }

  $table[] = array('Module', 'Delta', 'Region', 'Weight');

  foreach ($blocks as $block) {
    $include_block = TRUE;
    foreach ($filters as $key => $filter) {
      if (isset($filter)) {
        if ($block[$key] != $filter) {
	        $include_block = FALSE;
	      }
      }
      if ($configured && ($block['region'] == -1)) {
	      $include_block = FALSE;
      }
      if ($disabled && ($block['region'] != -1)) {
	      $include_block = FALSE;
      }
    }

    if ($include_block) {
      $table[] = array($block['module'], $block['delta'], $block['region'], $block['weight']);
    }
  }

  drush_print_table($table, TRUE);
}

/**
 * Implement block_disable()
 *
 * Disables single block
 */
function drush_block_disable() {
  drush_set_option('region', BLOCK_REGION_NONE);
  call_user_func_array('drush_block_configure_save', func_get_args());
}

/**
 * Search through all of the blocks, and determine if each of the
 * provided arguments can unambiguously be interpreted as one and
 * only one of the provided options.  For example, you may specify
 * a block by its delta using `drush block-show blockdelta` instead
 * of using --delta=blockdelta as long as there is no module or
 * region that is also named "blockdelta".
 */
function _drush_block_interpret_arguments(&$options, $blocks, $args) {
  $found_key = array();
  foreach ($args as $arg) {
    if (is_numeric($arg)) {
      $options['weight'] = $arg;
    }
    elseif (module_exists($arg) && array_key_exists('module', $options)) {
      $found_key[$arg] = 'module';
      $options['module'] = $arg;
    }
    else {
      foreach ($blocks as $block) {
        foreach ($options as $key => $filter) {
          if ($block[$key] == $arg) {
            if (!array_key_exists($arg, $found_key)) {
              $found_key[$arg] = $key;
              $options[$key] = $arg;
            }
            elseif ($found_key[$arg] != $key) {
              return drush_set_error('BLOCK_AMBIGUOUS_KEY', dt('!arg is ambiguous; could be --!one=!arg or --!theother=!arg.', array('!arg' => $arg, '!one' => $key, '!theother' => $found_key[$arg])));
            }
          }
        }
      }
    }
    if (!array_key_exists($arg, $found_key)) {
      return drush_set_error('BLOCK_UNMATCHED_ARG', dt('!arg does not match any field of any block.', array('!arg' => $arg)));
    }
    else {
      drush_log(dt("Interpreted !arg as --!key=!arg", array('!arg' => $arg, '!key' => $found_key[$arg])), 'notice');
    }
  }
  return TRUE;
}
