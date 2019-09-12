<?php
/**
 * @file
 * Pagerer - Definition of the Views pager plugin.
 *
 * Drupal core 7.x
 *
 * @package  User interface
 * @author   mondrake <mondrake@mondrake.org>
 */

/**
 * Pagerer pager plugin handler class.
 *
 * Based on Views 'full pager' handler class, just adds the option to select
 * the Pagerer preset to use for rendering the pager, and removes the options
 * to define the text tags.
 */
class PagererViewsPagerPlugin extends views_plugin_pager_full {

  /**
   * Return a string to display as the clickable title.
   */
  public function summary_title() {
    if (!empty($this->options['offset'])) {
      return format_plural(
        $this->options['items_per_page'],
        "Using preset %preset, @count item, skip @skip",
        "Using preset %preset, @count items, skip @skip",
        array(
          '%preset' => $this->options['preset'],
          '@count' => $this->options['items_per_page'],
          '@skip' => $this->options['offset'],
        )
      );
    }
    return format_plural(
      $this->options['items_per_page'],
      "Using preset %preset, @count item",
      "Using preset %preset, @count items",
      array(
        '%preset' => $this->options['preset'],
        '@count' => $this->options['items_per_page'],
      )
    );
  }

  /**
   * Return plugin options.
   *
   * Same as parent, plus preset. Tags are left even if the options form
   * will not present them, as tags in Pagerer are different than in core.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['preset'] = array('default' => 'core');
    return $options;
  }

  /**
   * Provide the form for setting options.
   *
   * Same as parent, plus preset, less tags.
   */
  public function options_form(&$form, &$form_state) {
    $preset_options = _pagerer_list_presets();
    $form['preset'] = array(
      '#type' => 'select',
      '#title' => t('Preset'),
      '#description' => t("Select the Pagerer preset to use to render the pager, or 'Use Drupal core pager'."),
      '#options' => $preset_options,
      '#default_value' => $this->options['preset'],
    );
    parent::options_form($form, $form_state);
    unset($form['tags']);
  }

  /**
   * Render the pager, using theme('pagerer', ...).
   *
   * @param array $input
   *   Any extra GET parameters that should be retained, such as exposed
   *   input.
   */
  public function render($input) {
    $pager_theme = views_theme_functions('pagerer', $this->view, $this->display);
    $output = theme($pager_theme, array(
      'preset' => $this->options['preset'],
      'element' => $this->options['id'],
      'parameters' => $input,
      'quantity' => $this->options['quantity'],
    ));
    return $output;
  }

}
