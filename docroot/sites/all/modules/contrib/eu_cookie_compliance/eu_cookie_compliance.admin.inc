<?php

/**
 * @file
 * This file provides administration form for the module.
 */

/**
 * Provides form for cookie control banner.
 *
 * @param array $form
 *   Form array.
 * @param array $form_state
 *   For state array.
 *
 * @return array
 *   Admin form render array.
 */
function eu_cookie_compliance_admin_form(array $form, array $form_state) {
  ctools_include('plugins');

  $form = array();

  $popup_settings = eu_cookie_compliance_get_settings();

  $default_filter_format = filter_default_format();
  if ($default_filter_format == 'filtered_html' && filter_format_load('full_html')) {
    $default_filter_format = 'full_html';
  }

  $consent_storage_options = array();
  $consent_storage_options['do_not_store'] = t('Do not store');
  $consent_storage_plugins = ctools_get_plugins('eu_cookie_compliance', 'consent_storage');
  foreach ($consent_storage_plugins as $key => $consent_storage_plugin) {
    $consent_storage_options[$key] = $consent_storage_plugin['title'];
  }

  $form['eu_cookie_compliance'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
  );

  $form['eu_cookie_compliance']['info'] = array(
    '#markup' => '<p>' . t('<strong>Note:</strong> In order for the module to work, <code>$scripts</code> needs to be output before <code>$page_bottom</code> in your <code>html.tpl.php</code>.') . '</p>',
  );

  $form['eu_cookie_compliance']['popup_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable banner'),
    '#default_value' => isset($popup_settings['popup_enabled']) ? $popup_settings['popup_enabled'] : 0,
  );

  $role_values = array();

  $permission = 'display EU Cookie Compliance popup';

  $roles = user_roles();
  $role_permissions = user_role_permissions($roles);
  foreach ($roles as $rid => $role_name) {
    // Indicate whether the checkbox should be ticked.
    if (array_key_exists($permission, $role_permissions[$rid])) {
      $role_values[] = $rid;
    }
  }

  // Store $role_names for use when saving the data.
  $form['role_names'] = array(
    '#type' => 'value',
    '#value' => $roles,
  );

  $form['permissions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Permissions'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['permissions']['see_the_banner'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Display the banner for'),
    '#options' => $roles,
    '#default_value' => $role_values,
  );

  $form['consent_option'] = array(
    '#type' => 'fieldset',
    '#title' => t('Consent for processing of personal information'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['consent_option']['eu_cookie_compliance'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
  );

  $form['consent_option']['eu_cookie_compliance']['info'] = array(
    '#type' => 'markup',
    '#markup' => t("The EU General Data Protection Regulation (GDPR) (see <a href=\"https://www.eugdpr.org/\" target=\"_blank\">https://www.eugdpr.org/</a>) comes into enforcement from 25 May 2018 and introduces new requirements for web sites which handle information that can be used to identify individuals. The regulation underlines that consent must be <strong>unambiguous</strong> and involve a <strong>clear affirmative action</strong>. When evaluating how to best handle the requirements in the GDPR, remember that if you have a basic web site where the visitors don't log in, you always have the option to <strong>not process data that identifies individuals</strong>, in which case you may not need this module. Also note that GDPR applies to any electronic processing or storage of personal data that your organization may do, and simply installing a module may not be enough to become fully GDPR compliant."),
  );

  $form['consent_option']['eu_cookie_compliance']['method'] = array(
    '#type' => 'radios',
    '#title' => t('Consent method'),
    '#options' => array(
      'default' => t("Consent by default. Don't provide any option to opt out."),
      'opt_in' => t("Opt-in. Don't track visitors unless they specifically give consent. (GDPR compliant)"),
      'categories' => t('Opt-in with categories. Let visitors choose which cookie categories they want to opt-in for (GDPR compliant).'),
      'opt_out' => t('Opt-out. Track visitors by default, unless they choose to opt out.'),
      'auto' => t('Automatic. Respect the DNT (Do not track) setting in the browser, if present. Uses opt-in when DNT is 1 or not set, and consent by default when DNT is 0.'),
    ),
    '#default_value' => isset($popup_settings['method']) ? $popup_settings['method'] : 'opt_in',
  );

  $form['consent_per_category'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cookie categories'),
    '#open' => TRUE,
    '#states' => array(
      'visible' => array(
        "input[name='eu_cookie_compliance[method]']" => array('value' => 'categories'),
      ),
    ),
  );

  $form['consent_per_category']['eu_cookie_compliance'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
  );

  $form['consent_per_category']['eu_cookie_compliance']['cookie_categories'] = array(
    '#type' => 'textarea',
    '#title' => t('Cookie categories with separate consent'),
    '#description' => t('List of cookie categories that require separate consent. E.g. Functional cookies, Advertisement cookies, …') .
      '<br />' . t('Enter one value per line, in the following format: "key|label" or "key|label|description". Description is optional.'),
    '#default_value' => isset($popup_settings['cookie_categories']) ? $popup_settings['cookie_categories'] : '',
  );

  $form['consent_per_category']['eu_cookie_compliance']['enable_save_preferences_button'] = array(
    '#type' => 'checkbox',
    '#title' => t('Replace the Agree button with "Save preferences" and "Accept all categories" buttons.'),
    '#default_value' => isset($popup_settings['enable_save_preferences_button']) ? $popup_settings['enable_save_preferences_button'] : TRUE,
  );

  $form['consent_per_category']['eu_cookie_compliance']['save_preferences_button_label'] = array(
    '#type' => 'textfield',
    '#title' => t('"Save preferences" button label'),
    '#default_value' => isset($popup_settings['save_preferences_button_label']) ? $popup_settings['save_preferences_button_label'] : 'Save preferences',
    '#states' => array(
      'visible' => array(
        "input[name='eu_cookie_compliance[enable_save_preferences_button]']" => array('checked' => TRUE),
      ),
      'required' => array(
        "input[name='eu_cookie_compliance[enable_save_preferences_button]']" => array('checked' => TRUE),
      ),
    ),
  );

  $form['consent_per_category']['eu_cookie_compliance']['accept_all_categories_button_label'] = array(
    '#type' => 'textfield',
    '#title' => t('"Accept all categories" button label'),
    '#default_value' => isset($popup_settings['accept_all_categories_button_label']) ? $popup_settings['accept_all_categories_button_label'] : 'Accept all cookies',
    '#states' => array(
      'visible' => array(
        "input[name='eu_cookie_compliance[enable_save_preferences_button]']" => array('checked' => TRUE),
      ),
      'required' => array(
        "input[name='eu_cookie_compliance[enable_save_preferences_button]']" => array('checked' => TRUE),
      ),
    ),
  );

  $form['consent_per_category']['eu_cookie_compliance']['fix_first_cookie_category'] = array(
    '#type' => 'checkbox',
    '#title' => t('Tick the first checkbox and mark it read only.'),
    '#default_value' => isset($popup_settings['fix_first_cookie_category']) ? $popup_settings['fix_first_cookie_category'] : TRUE,
  );

  $form['consent_per_category']['eu_cookie_compliance']['select_all_categories_by_default'] = array(
    '#type' => 'checkbox',
    '#title' => t('Tick all category checkboxes by default.'),
    '#default_value' => isset($popup_settings['select_all_categories_by_default']) ? $popup_settings['select_all_categories_by_default'] : FALSE,
  );

  // The info_template element is initialized in function
  // eu_cookie_compliance_update_7009().
  $default_value = (!empty($popup_settings['info_template'])) ? $popup_settings['info_template'] : 'new';
  $form['consent_option']['eu_cookie_compliance']['info_template'] = array(
    '#type' => 'radios',
    '#title' => t('Info banner template'),
    '#options' => array(
      'legacy' => t('Cookie policy button in popup-buttons section and styled similarly to the Agree button, 
        as in earlier versions of this module'),
      'new' => t('Cookie policy button in popup-text section, styled differently than the Agree button.'),
    ),
    '#default_value' => $default_value,
    '#states' => array(
      'visible' => array(
        "input[name='eu_cookie_compliance[method]']" => array('value' => 'default'),
      ),
    ),
  );

  $form['javascripts'] = array(
    '#type' => 'fieldset',
    '#title' => t("Disable the following JavaScripts when consent isn't given"),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#states' => array(
      'visible' => array(
        "input[name='eu_cookie_compliance[method]']" => array('!value' => 'default'),
      ),
    ),
  );

  $form['javascripts']['eu_cookie_compliance'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
  );

  $form['javascripts']['eu_cookie_compliance']['disabled_javascripts'] = array(
    '#type' => 'textarea',
    '#title' => t('Disable JavaScripts'),
    '#default_value' => isset($popup_settings['disabled_javascripts']) ? $popup_settings['disabled_javascripts'] : '',
    '#description' => t("<span style='word-break: break-word;'>Include the full path of JavaScripts, each on a separate line. When using the opt-in or opt-out consent options, you can block certain JavaScript files from being loaded when consent isn't given. The on-site JavaScripts should be written as root relative paths <strong>without the leading slash</strong>, you can use public://path/to/file.js and private://path/to/file.js, and off-site JavaScripts should be written as complete URLs <strong>with the leading http(s)://</strong>. Note that after the user gives consent, the scripts will be executed in the order you enter here.<br /><br />Libraries and scripts that attach to Drupal.behaviors are supported. To indicate a behavior that needs to be loaded on consent, append the behavior name after the script with a | (vertical bar). If you also want to conditionally load a library, place that as the third parameter, following another | (vertical bar). <strong>Example: modules/custom/custom_module/js/custom.js|customModule|custom_module/custom_module</strong>.<br />If your script file does not attach to Drupal.attributes, you may skip the second parameter. <strong>Example: modules/custom/custom_module/js/custom.js||custom_module/custom_module</strong><br /><strong>Note that Drupal behavior name and library parameters are both optional</strong>, but may be required to achieve your objective.</span>") .
      '<br /><br />' . t('When using the consent method "Opt-in with categories", you can link the script to a specific category by using the format: "category:path/to/the/script.js".'),
  );

  $form['cookies'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cookie handling'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#states' => array(
      'visible' => array(
        "input[name='eu_cookie_compliance[method]']" => array('!value' => 'default'),
      ),
    ),
  );

  $form['cookies']['eu_cookie_compliance'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
  );

  $form['cookies']['eu_cookie_compliance']['whitelisted_cookies'] = array(
    '#type' => 'textarea',
    '#title' => t('Whitelisted cookies'),
    '#default_value' => isset($popup_settings['whitelisted_cookies']) ? $popup_settings['whitelisted_cookies'] : '',
    '#description' => t("Include the name of cookies, each on a separate line. When using the opt-in or opt-out consent options, this module will <strong>delete cookies that are not on the whitelist</strong> every few seconds when consent isn't given. PHP session cookies and the cookie for this module are always whitelisted.") .
      '<br /><br />' . t('When using the consent method "Opt-in with categories", you can link the cookie to a specific consent category by using the format: "category:cookie_name".  Only when consent is given for the given category, will the cookie be whitelisted.'),
  );

  $form['consent_storage'] = array(
    '#type' => 'fieldset',
    '#title' => t('Store record of consent'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['consent_storage']['eu_cookie_compliance'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
  );

  $form['consent_storage']['eu_cookie_compliance']['info'] = array(
    '#type' => 'markup',
    '#markup' => t('Depending on your implementation of GDPR, you may have to store a record when the user consents. This module comes with a basic consent storage plugin that writes a record to the database. Note that if your site has significant traffic, the basic consent storage may become a bottleneck, as every consent action will require a write to the database. You can easily create your own module with a consent_storage ctools plugin that implements a consent_storage_callback, using basic.inc from this module as a template. If you create a highly performant consent storage plugin, please consider contributing it back to the Drupal community as a contrib module.'),
  );

  $form['consent_storage']['eu_cookie_compliance']['consent_storage_method'] = array(
    '#type' => 'radios',
    '#title' => t('Consent storage method'),
    '#default_value' => isset($popup_settings['consent_storage_method']) ? $popup_settings['consent_storage_method'] : 'do_not_store',
    '#options' => $consent_storage_options,
  );

  $form['popup_message'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cookie information banner message'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['popup_message']['eu_cookie_compliance'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
  );

  $form['popup_message']['eu_cookie_compliance']['popup_clicking_confirmation'] = array(
    '#type' => 'checkbox',
    '#title' => t('Consent by clicking'),
    '#description' => t('By default by clicking any link or button on the website the visitor accepts the cookie policy. Uncheck this box if you do not require this functionality. You may want to edit the banner message below accordingly.'),
    '#default_value' => isset($popup_settings['popup_clicking_confirmation']) ? $popup_settings['popup_clicking_confirmation'] : 1,
    '#states' => array(
      'visible' => array(
        'input[name="eu_cookie_compliance[method]"]' => array('value' => 'default'),
      ),
    ),
  );

  $form['popup_message']['eu_cookie_compliance']['popup_info'] = array(
    '#type' => 'text_format',
    '#title' => t('Cookie information banner message'),
    '#default_value' => isset($popup_settings['popup_info']['value']) ? $popup_settings['popup_info']['value'] : '',
    '#required' => TRUE,
    '#format' => isset($popup_settings['popup_info']['format']) ? $popup_settings['popup_info']['format'] : $default_filter_format,
  );

  $form['popup_message']['eu_cookie_compliance']['use_mobile_message'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use a different message for mobile phones.'),
    '#default_value' => isset($popup_settings['use_mobile_message']) ? $popup_settings['use_mobile_message'] : 0,
  );

  $form['popup_message']['eu_cookie_compliance']['container'] = array(
    '#type' => 'container',
    '#states' => array('visible' => array('input[name="eu_cookie_compliance[use_mobile_message]"]' => array('checked' => TRUE))),
  );

  $form['popup_message']['eu_cookie_compliance']['container']['mobile_popup_info'] = array(
    '#type' => 'text_format',
    '#title' => t('Cookie information banner message - mobile'),
    '#default_value' => isset($popup_settings['mobile_popup_info']['value']) ? $popup_settings['mobile_popup_info']['value'] : '',
    '#required' => FALSE,
    '#format' => isset($popup_settings['mobile_popup_info']['format']) ? $popup_settings['mobile_popup_info']['format'] : $default_filter_format,
    '#parents' => array('eu_cookie_compliance', 'mobile_popup_info'),
  );

  $form['popup_message']['eu_cookie_compliance']['mobile_breakpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile breakpoint'),
    '#default_value' => isset($popup_settings['mobile_breakpoint']) ? $popup_settings['mobile_breakpoint'] : 768,
    '#field_suffix' => t('px'),
    '#size' => 4,
    '#maxlength' => 4,
    '#required' => FALSE,
    '#description' => t('The mobile message will be used when the window width is below or equal to the given value.'),
    '#states' => array(
      'visible' => array(
        "input[name='eu_cookie_compliance[use_mobile_message]']" => array('checked' => TRUE),
      ),
    ),
  );

  $form['popup_message']['eu_cookie_compliance']['popup_agree_button_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Agree button label'),
    '#default_value' => isset($popup_settings['popup_agree_button_message']) ? $popup_settings['popup_agree_button_message'] : t('Accept'),
    '#size' => 30,
    '#states' => array(
      'visible' => array(
        array(
          "input[name='eu_cookie_compliance[enable_save_preferences_button]']" => array('checked' => FALSE),
          "input[name='eu_cookie_compliance[method]']" => array('value' => 'categories'),
        ),
        array(
          "input[name='eu_cookie_compliance[method]']" => array('!value' => 'categories'),
        ),
      ),
      'required' => array(
        array(
          ":input[name='eu_cookie_compliance[enable_save_preferences_button]']" => array('checked' => FALSE),
          ":input[name='eu_cookie_compliance[method]']" => array('value' => 'categories'),
        ),
        array(
          "input[name='eu_cookie_compliance[method]']" => array('!value' => 'categories'),
        ),
      ),
    ),
  );

  $form['popup_message']['eu_cookie_compliance']['show_disagree_button'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show "Cookie policy" and "More info" buttons'),
    '#description' => t('If this option is checked, the Cookie policy button will be shown on the site. Disabling this option will hide both the "Cookie policy" button on the information banner and the "More info" button on the "Thank you" banner.'),
    '#default_value' => isset($popup_settings['show_disagree_button']) ? $popup_settings['show_disagree_button'] : TRUE,
    '#states' => array(
      'visible' => array(
        "input[name='eu_cookie_compliance[method]']" => array('value' => 'default'),
      ),
    ),
  );

  $form['popup_message']['eu_cookie_compliance']['popup_disagree_button_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Cookie policy button label'),
    '#default_value' => isset($popup_settings['popup_disagree_button_message']) ? $popup_settings['popup_disagree_button_message'] : t('More info'),
    '#size' => 30,
    '#states' => array(
      'visible' => array(
        array('input[name="eu_cookie_compliance[show_disagree_button]"]' => array('checked' => TRUE)),
        array('input[name="eu_cookie_compliance[method]"]' => array('!value' => 'default')),
      ),
      'required' => array(
        array('input[name="eu_cookie_compliance[show_disagree_button]"]' => array('checked' => TRUE)),
        array('input[name="eu_cookie_compliance[method]"]' => array('!value' => 'default')),
      ),
    ),
  );

  $form['popup_message']['eu_cookie_compliance']['disagree_button_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Disagree button label'),
    '#default_value' => isset($popup_settings['disagree_button_label']) ? $popup_settings['disagree_button_label'] : t('Decline'),
    '#size' => 30,
    '#states' => array(
      'visible' => array(
        'input[name="eu_cookie_compliance[method]"]' => array('!value' => 'default'),
      ),
      'required' => array(
        'input[name="eu_cookie_compliance[method]"]' => array('!value' => 'default'),
      ),
    ),
  );

  $form['withdraw_consent'] = array(
    '#type' => 'fieldset',
    '#title' => t('Withdraw consent'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#states' => array(
      'visible' => array(
        "input[name='eu_cookie_compliance[method]']" => array('!value' => 'default'),
      ),
    ),
  );

  $form['withdraw_consent']['eu_cookie_compliance'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
  );

  $form['withdraw_consent']['eu_cookie_compliance']['info'] = array(
    '#type' => 'markup',
    '#markup' => t('GDPR requires that withdrawing consent for handling personal information should be as easy as giving consent. This module offers a tab button that when clicked brings up a message and a button that can be used to withdraw consent.'),
  );

  $form['withdraw_consent']['eu_cookie_compliance']['withdraw_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable floating privacy settings tab and withdraw consent banner'),
    '#default_value' => isset($popup_settings['withdraw_enabled']) ? $popup_settings['withdraw_enabled'] : '',
  );

  $form['withdraw_consent']['eu_cookie_compliance']['withdraw_button_on_info_popup'] = array(
    '#type' => 'checkbox',
    '#title' => t('Put the "Withdraw consent" button on the cookie information banner.'),
    '#default_value' => isset($popup_settings['withdraw_button_on_info_popup']) ? $popup_settings['withdraw_button_on_info_popup'] : FALSE,
  );

  $form['withdraw_consent']['eu_cookie_compliance']['container'] = array(
    '#type' => 'container',
    '#states' => array('visible' => array('input[name="eu_cookie_compliance[withdraw_button_on_info_popup]"]' => array('checked' => FALSE))),
  );

  $form['withdraw_consent']['eu_cookie_compliance']['container']['withdraw_message'] = array(
    '#type' => 'text_format',
    '#title' => t('Withdraw consent banner message'),
    '#default_value' => isset($popup_settings['withdraw_message']['value']) ? $popup_settings['withdraw_message']['value'] : '',
    '#description' => t('Text that will be displayed in the banner that appears when the privacy settings tab is clicked.'),
    '#format' => isset($popup_settings['withdraw_message']['format']) ? $popup_settings['withdraw_message']['format'] : $default_filter_format,
    '#parents' => array('eu_cookie_compliance', 'withdraw_message'),
  );

  $form['withdraw_consent']['eu_cookie_compliance']['withdraw_tab_button_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Privacy settings tab label'),
    '#default_value' => isset($popup_settings['withdraw_tab_button_label']) ? $popup_settings['withdraw_tab_button_label'] : '',
    '#description' => t('Tab button that reveals/hides the withdraw message and action button when clicked.'),
  );

  $form['withdraw_consent']['eu_cookie_compliance']['withdraw_action_button_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Withdraw consent button label'),
    '#default_value' => isset($popup_settings['withdraw_action_button_label']) ? $popup_settings['withdraw_action_button_label'] : '',
    '#description' => t('This button will withdraw consent when clicked.'),
  );

  $form['thank_you'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Thank you banner'),
  );

  $form['thank_you']['eu_cookie_compliance'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
  );

  $form['thank_you']['eu_cookie_compliance']['popup_agreed_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable "Thank you" banner.'),
    '#default_value' => isset($popup_settings['popup_agreed_enabled']) ? $popup_settings['popup_agreed_enabled'] : 1,
  );

  $form['thank_you']['eu_cookie_compliance']['popup_hide_agreed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Clicking hides "Thank you" banner.'),
    '#default_value' => isset($popup_settings['popup_hide_agreed']) ? $popup_settings['popup_hide_agreed'] : 0,
    '#description' => t('Clicking a link or button hides the thank you message automatically.'),
  );

  $form['thank_you']['eu_cookie_compliance']['popup_agreed'] = array(
    '#type' => 'text_format',
    '#title' => t('Thank you banner message'),
    '#default_value' => isset($popup_settings['popup_agreed']['value']) ? $popup_settings['popup_agreed']['value'] : '',
    '#required' => TRUE,
    '#format' => isset($popup_settings['popup_agreed']['format']) ? $popup_settings['popup_agreed']['format'] : $default_filter_format,
  );

  $form['thank_you']['eu_cookie_compliance']['popup_find_more_button_message'] = array(
    '#type' => 'textfield',
    '#title' => t('More info button label'),
    '#default_value' => isset($popup_settings['popup_find_more_button_message']) ? $popup_settings['popup_find_more_button_message'] : t('More info'),
    '#size' => 30,
    '#required' => TRUE,
    '#states' => array(
      'visible' => array(
        array('input[name="eu_cookie_compliance[show_disagree_button]"]' => array('checked' => TRUE)),
        array('input[name="eu_cookie_compliance[method]"]' => array('!value' => 'default')),
      ),
      'required' => array(
        array('input[name="eu_cookie_compliance[show_disagree_button]"]' => array('checked' => TRUE)),
        array('input[name="eu_cookie_compliance[method]"]' => array('!value' => 'default')),
      ),
    ),
  );

  $form['thank_you']['eu_cookie_compliance']['popup_hide_button_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Hide button label'),
    '#default_value' => isset($popup_settings['popup_hide_button_message']) ? $popup_settings['popup_hide_button_message'] : t('Hide'),
    '#size' => 30,
    '#required' => TRUE,
  );

  $form['privacy'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Privacy policy'),
  );

  $form['privacy']['eu_cookie_compliance'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
  );

  $form['privacy']['eu_cookie_compliance']['popup_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Privacy policy link'),
    '#default_value' => isset($popup_settings['popup_link']) ? $popup_settings['popup_link'] : '',
    '#size' => 60,
    '#maxlength' => 220,
    '#required' => TRUE,
    '#description' => t('Enter link to your privacy policy or other page that will explain cookies to your users. For external links prepend http://. The field supports tokens.'),
  );
  if (module_exists('token')) {
    $form['privacy']['eu_cookie_compliance']['popup_link']['#element_validate'][] = 'token_element_validate';
    $form['privacy']['eu_cookie_compliance']['popup_link']['#token_types'][] = 'node';

    $form['privacy']['eu_cookie_compliance']['popup_link_token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('node'),
      '#dialog' => TRUE,
    );
  }

  $form['privacy']['eu_cookie_compliance']['popup_link_new_window'] = array(
    '#type' => 'checkbox',
    '#title' => t('Open privacy policy link in a new window.'),
    '#default_value' => isset($popup_settings['popup_link_new_window']) ? $popup_settings['popup_link_new_window'] : 1,
  );

  $form['appearance'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Appearance'),
  );

  $form['appearance']['eu_cookie_compliance'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
  );

  $form_color_picker_type = 'textfield';

  if (module_exists('jquery_colorpicker')) {
    $form_color_picker_type = 'jquery_colorpicker';
  }

  $popup_position_options = array(
    'bottom' => 'Bottom',
    'top' => 'Top',
  );

  $popup_position_value = ($popup_settings['popup_position'] === TRUE ? 'top' : ($popup_settings['popup_position'] === FALSE ? 'bottom' : $popup_settings['popup_position']));

  $form['appearance']['eu_cookie_compliance']['popup_position'] = array(
    '#type' => 'radios',
    '#title' => t('Position'),
    '#default_value' => $popup_position_value,
    '#options' => $popup_position_options,
  );

  $form['appearance']['eu_cookie_compliance']['use_bare_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include minimal CSS, I want to style the banner in the theme CSS.'),
    '#default_value' => isset($popup_settings['use_bare_css']) ? check_plain($popup_settings['use_bare_css']) : 0,
    '#description' => t('This may be useful if you want the banner to share the button style of your theme. Note that you will have to configure values like the banner width, text color and background color in your CSS file.'),
  );

  $form['appearance']['eu_cookie_compliance']['popup_text_hex'] = array(
    '#type' => $form_color_picker_type,
    '#title' => t('Text color'),
    '#default_value' => isset($popup_settings['popup_text_hex']) ? check_plain($popup_settings['popup_text_hex']) : 'ffffff',
    '#description' => t('Change the text color of the banner. Provide HEX value without the #.'),
    '#element_validate' => array('eu_cookie_compliance_validate_hex'),
    '#states' => array(
      'visible' => array(
        "input[name='eu_cookie_compliance[use_bare_css]']" => array('checked' => FALSE),
      ),
    ),
  );

  $form['appearance']['eu_cookie_compliance']['popup_bg_hex'] = array(
    '#type' => $form_color_picker_type,
    '#title' => t('Background color'),
    // Garland colors => 0779BF.
    '#default_value' => isset($popup_settings['popup_bg_hex']) ? check_plain($popup_settings['popup_bg_hex']) : '0779bf',
    '#description' => t('Change the background color of the banner. Provide HEX value without the #.'),
    '#element_validate' => array('eu_cookie_compliance_validate_hex'),
    '#states' => array(
      'visible' => array(
        "input[name='eu_cookie_compliance[use_bare_css]']" => array('checked' => FALSE),
      ),
    ),
  );

  $form['appearance']['eu_cookie_compliance']['popup_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Banner height'),
    '#default_value' => isset($popup_settings['popup_height']) ? $popup_settings['popup_height'] : '',
    '#field_suffix' => t('px'),
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => FALSE,
    '#description' => t('Enter an integer value for a desired height in pixels or leave empty for automatically adjusted height. Do not set this value if you are using responsive theme.'),
    '#states' => array(
      'visible' => array(
        "input[name='eu_cookie_compliance[use_bare_css]']" => array('checked' => FALSE),
      ),
    ),
  );

  $form['appearance']['eu_cookie_compliance']['popup_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Banner width in pixels or a percentage value'),
    '#default_value' => isset($popup_settings['popup_width']) ? $popup_settings['popup_width'] : '100%',
    '#field_suffix' => t('px or %'),
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => FALSE,
    '#description' => t('Set the width of the banner. This can be either an integer value or percentage of the screen width. For example: 200 or 50%.'),
    '#states' => array(
      'visible' => array(
        "input[name='eu_cookie_compliance[use_bare_css]']" => array('checked' => FALSE),
      ),
    ),
  );

  $form['eu_only'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('EU countries'),
  );

  $form['eu_only']['eu_cookie_compliance'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
  );

  if (module_exists('geoip') || module_exists('smart_ip') || extension_loaded('geoip')) {
    $form['eu_only']['eu_cookie_compliance']['eu_only'] = array(
      '#type' => 'checkbox',
      '#title' => t('Only display banner in EU countries.'),
      '#default_value' => isset($popup_settings['eu_only']) ? $popup_settings['eu_only'] : 0,
      '#description' => t('You can limit the number of countries for which the banner is displayed by checking this option. If you want to provide a list of countries other than current EU states, you may place an array in <code>$conf[\'eu_cookie_compliance_eu_countries\']</code> in your <code>settings.php</code> file. Using the <a href="http://drupal.org/project/geoip">geoip</a> module or the <a href="http://drupal.org/project/smart_ip">smart_ip</a> module or the <a href="http://www.php.net/manual/en/function.geoip-country-code-by-name.php">geoip_country_code_by_name()</a> PHP function.'),
    );
    $form['eu_only']['eu_cookie_compliance']['eu_only_js'] = array(
      '#type' => 'checkbox',
      '#title' => t('JavaScript-based (for Varnish): Only display banner in EU countries.'),
      '#default_value' => isset($popup_settings['eu_only_js']) ? $popup_settings['eu_only_js'] : 0,
      '#description' => t('This option also works for visitors that bypass Varnish. You can limit the number of countries for which the banner is displayed by checking this option. If you want to provide a list of countries other than current EU states, you may place an array in <code>$conf[\'eu_cookie_compliance_eu_countries\']</code> in your <code>settings.php</code> file. Using the <a href="http://drupal.org/project/geoip">geoip</a> module or the <a href="http://drupal.org/project/smart_ip">smart_ip</a> module or the <a href="http://www.php.net/manual/en/function.geoip-country-code-by-name.php">geoip_country_code_by_name()</a> PHP function.'),
    );
  }
  else {
    $form['eu_only']['info'] = array(
      '#markup' => t('You can choose to show the banner only to visitors from EU countries. In order to achieve this, you need to install the <a href="http://drupal.org/project/geoip">geoip</a> module or the <a href="http://drupal.org/project/smart_ip">smart_ip</a> module or enable the <a href="http://www.php.net/manual/en/function.geoip-country-code-by-name.php">geoip_country_code_by_name()</a> PHP function.'),
    );
  }

  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Advanced'),
  );

  $form['advanced']['eu_cookie_compliance'] = array(
    '#type' => 'item',
    '#tree' => TRUE,
  );

  $form['advanced']['eu_cookie_compliance']['fixed_top_position'] = array(
    '#type' => 'checkbox',
    '#title' => t("If the banner is at the top, don't scroll the banner with the page."),
    '#default_value' => isset($popup_settings['fixed_top_position']) ? $popup_settings['fixed_top_position'] : 0,
    '#description' => t('Use position:fixed for the banner when displayed at the top.'),
  );

  $form['advanced']['eu_cookie_compliance']['popup_delay'] = array(
    '#type' => 'textfield',
    '#title' => t('Banner sliding animation time'),
    '#field_suffix' => t('ms'),
    '#default_value' => isset($popup_settings['popup_delay']) ? $popup_settings['popup_delay'] : 1000,
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => TRUE,
  );

  $form['advanced']['eu_cookie_compliance']['disagree_do_not_show_popup'] = array(
    '#type' => 'checkbox',
    '#title' => t('Do not show cookie policy when the user clicks the "Cookie policy" button.'),
    '#default_value' => isset($popup_settings['disagree_do_not_show_popup']) ? $popup_settings['disagree_do_not_show_popup'] : 0,
    '#description' => t('Enabling this will make it possible to record the fact that the user disagrees without the user having to see the privacy policy.'),
  );

  $form['advanced']['eu_cookie_compliance']['reload_page'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reload page after user clicks the "Agree" button.'),
    '#default_value' => isset($popup_settings['reload_page']) ? $popup_settings['reload_page'] : 0,
  );

  $form['advanced']['eu_cookie_compliance']['popup_scrolling_confirmation'] = array(
    '#type' => 'checkbox',
    '#title' => t('Consent by scrolling'),
    '#default_value' => isset($popup_settings['popup_scrolling_confirmation']) ? $popup_settings['popup_scrolling_confirmation'] : 0,
    '#description' => t('Scrolling makes the visitors to accept the cookie policy. In some countries, like Italy, it is permitted.'),
    '#states' => array(
      'visible' => array(
        array('input[name="eu_cookie_compliance[method]"]' => array('value' => 'default')),
      ),
    ),
  );

  $form['advanced']['eu_cookie_compliance_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Domain'),
    '#default_value' => variable_get('eu_cookie_compliance_domain', ''),
    '#description' => t('Sets the domain of the cookie to a specific url. Used when you need consistency across domains. This is language independent. Note: Make sure you actually enter a domain that the browser can make use of. For example if your site is accessible at both www.domain.com and domain.com, you will not be able to hide the banner at domain.com if your value for this field is www.domain.com.'),
  );

  $form['advanced']['eu_cookie_compliance_domain_all_sites'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow the cookie to be set for all sites on the same domain.'),
    '#default_value' => variable_get('eu_cookie_compliance_domain_all_sites', 0),
    '#description' => t("Sets the path of the cookie to '/' so that the cookie works across all sites on the domain."),
  );

  $form['advanced']['eu_cookie_compliance']['cookie_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Cookie name'),
    '#default_value' => isset($popup_settings['cookie_name']) ? $popup_settings['cookie_name'] : '',
    '#description' => t('Sets the cookie name that is used to check whether the user has agreed or not. This option is useful when policies change and the user needs to agree again.'),
  );

  $form['advanced']['eu_cookie_compliance_cookie_lifetime'] = array(
    '#type' => 'textfield',
    '#title' => t('Cookie lifetime'),
    '#default_value' => variable_get('eu_cookie_compliance_cookie_lifetime', 100),
    '#field_suffix' => t('days'),
    '#description' => t("How many days the system remember the user's choice."),
    '#states' => array(
      'enabled' => array(
        "input[name='eu_cookie_compliance[cookie_session]']" => array('checked' => FALSE),
      ),
    ),
  );

  // Adding option to add/remove banner on specified domains.
  $exclude_domains_option_active = array(
    0 => t('Add'),
    1 => t('Remove'),
  );
  $form['advanced']['eu_cookie_compliance']['domains_option'] = array(
    '#type' => 'radios',
    '#title' => t('Add/Remove banner on specified domains'),
    '#default_value' => isset($popup_settings['domains_option']) ? $popup_settings['domains_option'] : 1,
    '#options' => $exclude_domains_option_active,
    '#description' => t('Specify if you want to add or remove banner on the listed below domains.'),
  );
  $form['advanced']['eu_cookie_compliance']['domains_list'] = array(
    '#type' => 'textarea',
    '#title' => t('Domains list'),
    '#default_value' => isset($popup_settings['domains_list']) ? $popup_settings['domains_list'] : '',
    '#description' => t('Specify domains with protocol (e.g. http or https). Enter one domain per line.'),
  );

  $form['advanced']['eu_cookie_compliance']['exclude_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Exclude paths'),
    '#default_value' => isset($popup_settings['exclude_paths']) ? $popup_settings['exclude_paths'] : '',
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array(
      '%blog' => 'blog',
      '%blog-wildcard' => 'blog/*',
      '%front' => '<front>',
    )),
  );

  $form['advanced']['eu_cookie_compliance']['exclude_admin_pages'] = array(
    '#type' => 'checkbox',
    '#title' => t('Exclude admin pages.'),
    '#default_value' => isset($popup_settings['exclude_admin_pages']) ? $popup_settings['exclude_admin_pages'] : '',
  );

  $form['advanced']['eu_cookie_compliance']['exclude_uid_1'] = array(
    '#type' => 'checkbox',
    '#title' => t("Don't show the banner for UID 1."),
    '#default_value' => isset($popup_settings['exclude_uid_1']) ? $popup_settings['exclude_uid_1'] : 0,
  );

  $form['advanced']['eu_cookie_compliance']['script_scope'] = array(
    '#type' => 'select',
    '#title' => t('Script scope'),
    '#options' => array(
      'header' => t('Header (Scripts variable)'),
      'footer' => t('Footer (Page bottom variable)'),
    ),
    '#default_value' => isset($popup_settings['script_scope']) ? $popup_settings['script_scope'] : 'footer',
    '#description' => t('If you want to use the hasAgreed() function from other scripts, you may want to change this to header.'),
  );

  $form['advanced']['eu_cookie_compliance']['better_support_for_screen_readers'] = array(
    '#type' => 'checkbox',
    '#title' => t('Let screen readers see the banner before other links on the page.'),
    '#default_value' => isset($popup_settings['better_support_for_screen_readers']) ? $popup_settings['better_support_for_screen_readers'] : 0,
    '#description' => t('Enable this if you want to place the banner as the first HTML element on the page. This will make it possible for screen readers to close the banner without tabbing through all links on the page.'),
  );

  $form['advanced']['eu_cookie_compliance']['cookie_session'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prompt for consent (from the same user) at every new browser session.'),
    '#description' => t("This sets cookie lifetime to 0, invalidating the cookie at the end of the browser session. To set a cookie lifetime greater than 0, uncheck this option. Note that some users will find this behavior highly annoying, and it's recommended to double-check with the legal advisor whether you really need this option enabled."),
    '#default_value' => isset($popup_settings['cookie_session']) ? $popup_settings['cookie_session'] : FALSE,
  );

  $form = system_settings_form($form);
  $form['#submit'][] = 'eu_cookie_compliance_admin_form_submit';

  return $form;
}

/**
 * Validates form for cookie control banner.
 *
 * @param array $form
 *   Form array.
 * @param array $form_state
 *   Form state array.
 */
function eu_cookie_compliance_admin_form_validate(array $form, array &$form_state) {
  if ((!preg_match('/^[1-9][0-9]{0,4}$/', $form_state['values']['eu_cookie_compliance']['popup_delay'])) && ($form_state['values']['eu_cookie_compliance']['popup_delay'] != '0')) {
    form_set_error('eu_cookie_compliance][popup_delay', t('Delay must be an integer value.'));
  }
  if (empty($form_state['values']['eu_cookie_compliance']['use_bare_css'])) {
    if (!preg_match('/^[1-9][0-9]{0,4}$/', $form_state['values']['eu_cookie_compliance']['popup_height']) && !empty($form_state['values']['eu_cookie_compliance']['popup_height'])) {
      form_set_error('eu_cookie_compliance][popup_height', t('Height must be an integer value .'));
    }
    if (!preg_match('/^[1-9][0-9]{1,4}\%?$/', $form_state['values']['eu_cookie_compliance']['popup_width'])) {
      form_set_error('eu_cookie_compliance][popup_width', t('Width must be an integer or a percentage value.'));
    }
  }
  else {
    $form_state['values']['eu_cookie_compliance']['popup_width'] = '';
    $form_state['values']['eu_cookie_compliance']['popup_height'] = '';
    $form_state['values']['eu_cookie_compliance']['popup_bg_hex'] = '';
    $form_state['values']['eu_cookie_compliance']['popup_text_hex'] = '';
  }
  $popup_link = $form_state['values']['eu_cookie_compliance']['popup_link'];
  // If the link contains a fragment then check if it validates then rewrite
  // link with full url.
  if ((strpos($popup_link, '#') !== FALSE) && (strpos($popup_link, 'http') === FALSE)) {
    $fragment = explode('#', $popup_link);
    $popup_link = url($fragment[0], array('fragment' => $fragment[1], 'absolute' => TRUE));
    form_set_error('eu_cookie_compliance][popup_link', t('Looks like your privacy policy link contains a fragment #. You should make this an absolute url, e.g. @link', array('@link' => $popup_link)));
  }

  if ($popup_link == '<front>' && $form_state['values']['eu_cookie_compliance']['show_disagree_button']) {
    drupal_set_message(t('Your privacy policy link is pointing at the front page. This is the default value after installation, and unless your privacy policy is actually posted at the front page, you will need to create a separate page for the privacy policy and link to that page.'), 'error');
  }

  // Handle legacy settings for popup_position:
  if ($form_state['values']['eu_cookie_compliance']['popup_position'] == 'top') {
    $form_state['values']['eu_cookie_compliance']['popup_position'] = TRUE;
  }
  elseif ($form_state['values']['eu_cookie_compliance']['popup_position'] == 'bottom') {
    $form_state['values']['eu_cookie_compliance']['popup_position'] = FALSE;
  }

  $method = $form_state['values']['eu_cookie_compliance']['method'];

  if ($method != 'default') {
    $form_state['values']['eu_cookie_compliance']['show_disagree_button'] = TRUE;
    $form_state['values']['eu_cookie_compliance']['popup_clicking_confirmation'] = FALSE;
    $form_state['values']['eu_cookie_compliance']['popup_scrolling_confirmation'] = FALSE;
    $form_state['values']['eu_cookie_compliance']['info_template'] = 'new';
  }
  else {
    $form_state['values']['eu_cookie_compliance']['whitelisted_cookies'] = '';
    $form_state['values']['eu_cookie_compliance']['disabled_javascripts'] = '';
    $form_state['values']['eu_cookie_compliance']['withdraw_enabled'] = FALSE;
  }

  // Validate cookie name against valid characters.
  if (preg_match('/[&\'\x00-\x20\x22\x28-\x29\x2c\x2f\x3a-\x40\x5b-\x5d\x7b\x7d\x7f]/', $form_state['values']['eu_cookie_compliance']['cookie_name'])) {
    form_set_error('eu_cookie_compliance][cookie_name', t('Invalid cookie name, please remove any special characters and try again.'));
  }

  eu_cookie_compliance_clear_caches();
}

/**
 * Submit handler for cookie control banner.
 *
 * @param array $form
 *   Form array.
 * @param array $form_state
 *   Form state array.
 */
function eu_cookie_compliance_admin_form_submit(array $form, array &$form_state) {
  $permission = 'display EU Cookie Compliance popup';
  $roles = $form_state['values']['see_the_banner'];
  foreach ($roles as $rid => $value) {
    if ($value) {
      user_role_grant_permissions($rid, array($permission));
    }
    else {
      user_role_revoke_permissions($rid, array($permission));
    }
  }
}

/**
 * Validate field for a HEX value if a value is set.
 *
 * @param array $element
 *   Form element.
 * @param array $form_state
 *   Form state array.
 */
function eu_cookie_compliance_validate_hex(array $element, array &$form_state) {
  if (!empty($element['#value']) && !preg_match('/^[0-9a-fA-F]{3,6}$/', $element['#value'])) {
    form_error($element, t('%name must be a HEX value (without leading #) or empty.', array('%name' => $element['#title'])));
  }
}
