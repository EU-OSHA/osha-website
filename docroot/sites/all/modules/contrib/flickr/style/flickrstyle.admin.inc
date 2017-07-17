<?php
/**
 * @file
 * The admin settings for the Flickr Style module.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function flickrstyle_form_flickr_admin_settings_alter(&$form, &$form_state) {
  $form['#submit'][] = 'flickrstyle_admin_settings_submit';
  // Do not display CSS styling options if the module's CSS is disabled.
  if (variable_get('flickr_css', 1)) {
    $options = array(
      'rounded' => t('Rounded corners'),
      'shadow' => t('Shadow'),
      'border' => t('Border'),
    );
    $form['css_settings']['flickrstyle_styles'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Image styles'),
      '#description' => t('Shadow only = Image with shadow. No space between.<br />Border only = Some space between image and a solid border.<br />Shadow + Border = Some space between image and shadow. No real border.'),
      '#default_value' => variable_get('flickrstyle_styles', array(
        'rounded' => 'rounded',
        'shadow' => 'shadow',
        'border' => 'border',
      )),
      '#options' => $options,
      '#weight' => 8,
    );
    $styles = variable_get('flickrstyle_styles', array(
      'rounded' => 'rounded',
      'shadow' => 'shadow',
      'border' => 'border',
    ));
    if (module_exists('style_settings')) {
      $form['css_settings']['css_variables']['flickrstyle_radius'] = array(
        '#type' => 'fieldset',
        '#title' => t('Rounded corner radius'),
        // Make containing fields align horizontally.
        '#attributes' => array('class' => array('container-inline')),
        '#description' => t('Note: A value of 50% or higher results in round/ellipse images.'),
      );
      // Number field without a '#field_suffix'.
      $form['css_settings']['css_variables']['flickrstyle_radius']['flickrstyle_radius_value'] = array(
        '#type' => 'style_settings_number',
        '#default_value' => variable_get('flickrstyle_radius_value', '1'),
      );
      // A measurement unit select field.
      $form['css_settings']['css_variables']['flickrstyle_radius']['flickrstyle_radius_unit'] = array(
        '#type' => 'select',
        '#options' => array(
          'px' => t('px'),
          'em' => t('em'),
          '%' => t('%'),
        ),
        '#default_value' => variable_get('flickrstyle_radius_unit', 'em'),
        '#required' => TRUE,
      );
      // We need rounded corners before we can use a radius on it.
      if (gettype($styles['rounded']) == 'integer') {
        $form['css_settings']['css_variables']['flickrstyle_radius']['#disabled'] = TRUE;
        $form['css_settings']['css_variables']['flickrstyle_radius']['#description'] = '<span class="grayed-out">' . t('A value of 50% or higher results in round/ellipse images.') . '</span> | ' . t("Disabled until the 'Rounded corners' image style is selected below and saved.");
      }
      $form['css_settings']['css_variables']['flickrstyle_bgcolor'] = array(
        '#type' => 'style_settings_colorpicker',
        '#title' => t('Background color'),
        '#description' => t('Applies on the bordered caption area and the space between image and border.'),
        '#default_value' => variable_get('flickrstyle_bgcolor', 'White'),
        '#weight' => 10,
      );
      // We need a 'Border' or styled caption to have a background to color.
      if (gettype($styles['border']) == 'integer' && !variable_get('flickrstyle_caption', 1)) {
        $form['css_settings']['css_variables']['flickrstyle_bgcolor']['#disabled'] = TRUE;
        $form['css_settings']['css_variables']['flickrstyle_bgcolor']['#description'] = t("Disabled until the 'Border' or a caption style is selected below and saved.");;
      }
      $form['css_settings']['css_variables']['flickrstyle_shadow_color'] = array(
        '#type' => 'style_settings_colorpicker',
        '#title' => t('Shadow color'),
        '#default_value' => variable_get('flickrstyle_shadow_color', '#a5a5a5'),
        '#weight' => 11,
      );
      // We need a shadow before we can use a color for it.
      if (gettype($styles['shadow']) == 'integer') {
        $form['css_settings']['css_variables']['flickrstyle_shadow_color']['#disabled'] = TRUE;
        $form['css_settings']['css_variables']['flickrstyle_shadow_color']['#description'] = t("Disabled until the 'Shadow' image style is selected below and saved.");
      }
      $form['css_settings']['css_variables']['flickrstyle_border_color'] = array(
        '#type' => 'style_settings_colorpicker',
        '#title' => t('Border color'),
        '#default_value' => variable_get('flickrstyle_border_color', 'LightGrey'),
        '#weight' => 12,
      );
      $form['css_settings']['css_variables']['flickrstyle_border_thickness'] = array(
        '#type' => 'style_settings_number',
        '#title' => t('Border width'),
        '#default_value' => floatval(variable_get('flickrstyle_border_thickness', '2px')),
        '#field_suffix' => t('px'),
        '#weight' => 13,
      );
      $form['css_settings']['css_variables']['flickrstyle_spacing'] = array(
        '#type' => 'style_settings_number',
        '#title' => t('Space between image and border'),
        '#default_value' => floatval(variable_get('flickrstyle_spacing', '2px')),
        '#field_suffix' => t('px'),
        '#weight' => 14,
      );
      // We need a 'Border' to space.
      if (gettype($styles['border']) == 'integer') {
        $form['css_settings']['css_variables']['flickrstyle_spacing']['#disabled'] = TRUE;
        $form['css_settings']['css_variables']['flickrstyle_spacing']['#description'] = t("Disabled until the 'Border' image style is selected below and saved.");;
      }
      $form['css_settings']['css_variables']['flickrstyle_scale'] = array(
        '#type' => 'style_settings_slider',
        '#title' => t('Scale factor'),
        '#description' => t('Applies to the enlarge and zoom styles on image hover.'),
        '#default_value' => variable_get('flickrstyle_scale', 1.85),
        '#min' => 1.01,
        '#max' => 2.15,
        '#weight' => 15,
      );
      // We need an 'Enlarge' or 'Zoom' style to scale.
      if (variable_get('flickrstyle_emphasize', 2) < 1 || variable_get('flickrstyle_emphasize', 2) > 3) {
        $form['css_settings']['css_variables']['flickrstyle_scale']['#disabled'] = TRUE;
        $form['css_settings']['css_variables']['flickrstyle_scale']['#description'] = t("Disabled until the 'Enlarge' or 'Zoom' style on hover is selected below and saved.");;
      }
      $form['css_settings']['css_variables']['flickrstyle_magnifier'] = array(
        '#type' => 'fieldset',
        '#title' => t('Magnifier icon'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#weight' => 16,
      );
      $magnifierurl = l(t('http://cdn-img.easyicon.net/png/5053/505399.png'), 'http://cdn-img.easyicon.net/png/5053/505399.png', array(
          'attributes' => array(
            'title' => t('505399.png (128×128)'),
            'target' => '_blank',
          ),
      ));
      $form['css_settings']['css_variables']['flickrstyle_magnifier']['flickrstyle_magnifier_imgfield'] = array(
        '#type' => 'fieldset',
        '#title' => t('IMAGE SOURCE'),
        // Make containing fields align horizontally.
        '#attributes' => array('class' => array('container-inline')),
        '#description' => t("Absolute URL, e.g. !magnifierurl or relative (local) image URL. A relative URL must be given from the base URL (<em>/sites/..</em>).<br />Leave all empty to reset to the default icon.", array('!magnifierurl' => $magnifierurl)),
      );
      // IMAGE UPLOAD.
      $form['css_settings']['css_variables']['flickrstyle_magnifier']['flickrstyle_magnifier_imgfield']['flickrstyle_magnifier_imgupload'] = array(
        '#type' => 'managed_file',
        '#description' => t('Alternatively upload an image. Visible after form submit.'),
        '#default_value' => variable_get('flickrstyle_magnifier_imgupload', ''),
        '#size' => 40,
        '#upload_location' => 'public://flickr/style/',
        '#theme' => 'image_widget',
      );
      if (!variable_get('flickrstyle_magnifier_imgupload', '')) {
        variable_set('flickrstyle_magnifier_imgupload_url', '');
      }
      // IMAGE URL example.
      $uploaded_url = variable_get('flickrstyle_magnifier_imgupload_url', '');
      $default = empty($uploaded_url) ? variable_get('flickrstyle_magnifier_image', '/' . drupal_get_path('module', 'flickrstyle') . '/img/magnifier.png') : $uploaded_url;
      $form['css_settings']['css_variables']['flickrstyle_magnifier']['flickrstyle_magnifier_imgfield']['flickrstyle_magnifier_image'] = array(
        '#type' => 'style_settings_imgurl',
        '#default_value' => $default,
        // In submit handler below we reset an empty field to default URL.
        // This way the user isn't required to know URL of the default image.
      );
      $form['css_settings']['css_variables']['flickrstyle_magnifier']['flickrstyle_magnifier_opacity'] = array(
        '#type' => 'style_settings_slider',
        '#title' => t('Opacity'),
        '#description' => t('0 = transparent. 1 = opaque.'),
        '#default_value' => variable_get('flickrstyle_magnifier_opacity', 0.85),
      );
      $form['css_settings']['css_variables']['flickrstyle_magnifier']['flickrstyle_magnifier_size'] = array(
        '#type' => 'style_settings_number',
        '#title' => t('Size'),
        '#default_value' => floatval(variable_get('flickrstyle_magnifier_size', '50px')),
        '#field_suffix' => t('px'),
      );
      // We need a magnifier icon before styling it.
      if (variable_get('flickrstyle_emphasize', 2) != 4) {
        $form['css_settings']['css_variables']['flickrstyle_magnifier']['#disabled'] = TRUE;
        $form['css_settings']['css_variables']['flickrstyle_magnifier']['#description'] = t("Disabled until the 'Magnifier icon' style on hover is selected below and saved.");;
      }
      // We need a border before we can use a color or thickness for it.
      // Same with a shadow when we don't have a real border.
      if (gettype($styles['shadow']) == 'string' || gettype($styles['border']) == 'integer') {
        $form['css_settings']['css_variables']['flickrstyle_border_color']['#disabled'] = TRUE;
        $form['css_settings']['css_variables']['flickrstyle_border_color']['#description'] = t("Disabled until the 'Border' image style is selected below and saved. 'Shadow' must be unselected as it suppresses a real border.");
        $form['css_settings']['css_variables']['flickrstyle_border_thickness']['#disabled'] = TRUE;
        $form['css_settings']['css_variables']['flickrstyle_border_thickness']['#description'] = t("Disabled until the 'Border' image style is selected below and saved. 'Shadow' must be unselected as it suppresses a real border.");
      }
    }

    // We need a shadow and/or border before we can use a style on the caption
    // and a reset to 'No' of it if so.
    if (gettype($styles['shadow']) == 'integer' && gettype($styles['border']) == 'integer') {
      variable_set('flickrstyle_caption', 0);
      drupal_set_message(t("The caption style has been disabled until you set a 'border' and/or 'shadow' in the 'Image styles'. It will be available again after saving the form."), 'warning', FALSE);
    }
    $form['css_settings']['flickrstyle_caption'] = array(
      '#type' => 'radios',
      '#title' => t('Apply the image style also on the caption?'),
      '#options' => array(
        t('No'),
        t('Yes, separate from the image'),
        t('Yes, wrapped around the image and caption ("Polaroid" effect if applied with a border)'),
      ),
      // Defaults to 'No'
      '#default_value' => variable_get('flickrstyle_caption', 1),
      '#weight' => 10,
    );
    // We need a shadow and/or border before we can use a style on the caption.
    if (gettype($styles['shadow']) == 'integer' && gettype($styles['border']) == 'integer') {
      $form['css_settings']['flickrstyle_caption']['#disabled'] = TRUE;
      $form['css_settings']['flickrstyle_caption']['#description'] = t('Disabled until a shadow and/or border image style is selected. Select above and save the form to make a caption style available.');
    }
    $form['css_settings']['flickrstyle_nostyle'] = array(
      '#type' => 'checkbox',
      '#title' => t("Disable the above styles on a caption with only the text 'Flickr' (simple link)"),
      '#default_value' => variable_get('flickrstyle_nostyle', 1),
      '#weight' => 11,
    );
    // Disable the 'Enlarge' style until a border is set or shadow unselected.
    if (gettype($styles['shadow']) != 'integer' && gettype($styles['border']) == 'integer') {
      if (variable_get('flickrstyle_emphasize', 2) == 2) {
        variable_set('flickrstyle_emphasize', 3);
        drupal_set_message(t("The emphasize style has been set to 'Zoom'. 'Enlarge' has been disabled until you set a 'border' or unselect 'shadow' in the 'Image styles'. It will be available again after saving the form."), 'warning', FALSE);
      }
    }
    $retina = l(t('retina'), 'https://en.wikipedia.org/wiki/Retina_Display', array(
        'attributes' => array(
          'title' => t('Retina Display - Wikipedia, the free encyclopedia'),
          'target' => '_blank',
        ),
    ));
    $form['css_settings']['flickrstyle_emphasize'] = array(
      '#type' => 'radios',
      '#title' => t('Emphasize the image on hover?'),
      '#options' => array(
        t('No'),
        t('Enlarge image + caption (*)'),
        t('Enlarge image (*)'),
        t('Zoom (*)'),
        t('Magnifier icon'),
      ),
      // Defaults to 'Enlarge slightly'.
      '#default_value' => variable_get('flickrstyle_emphasize', 2),
      '#description' => t("(*): The 'Zoom' and 'Enlarge' styles use bigger images to maintain the resolution. This has a slight performance impact and the size 'big square' (q) is not square but 150px on the longest side to avoid distortion on older browsers. Applying the 'enlarge' or 'zoom' style makes images look good on Hi-Res displays (!retina) while using the higher resolution images also on normal screens by enlarging them on mouseover (hover).", array('!retina' => $retina)),
      '#weight' => 12,
    );
    // Disable the 'Enlarge' style until a border is set or shadow unselected.
    if (gettype($styles['shadow']) != 'integer' && gettype($styles['border']) == 'integer') {
      $form['css_settings']['flickrstyle_emphasize'][2]['#disabled'] = TRUE;
    }
  }
  else {
    $form['css_settings']['flickrstyle_suppressed'] = array(
      '#markup' => t("Styling options are not displayed until the module's CSS is enabled again (the checkbox above)."),
    );
  }
}

/**
 * Submit form data.
 */
function flickrstyle_admin_settings_submit($form, &$form_state) {
  if (variable_get('flickr_css', 1) && module_exists('style_settings')) {
    // Rounded corners: concatenate the value and unit.
    variable_set('flickrstyle_radius', $form_state['values']['flickrstyle_radius_value'] . $form_state['values']['flickrstyle_radius_unit']);

    // IMAGE UPLOAD.
    if (!empty($form_state['values']['flickrstyle_magnifier_imgupload'])) {
      $image = file_load($form_state['values']['flickrstyle_magnifier_imgupload']);
      $url = '/' . variable_get('file_public_path', conf_path() . '/files') . '/' . file_uri_target($image->uri);
      variable_set('flickrstyle_magnifier_imgupload_url', $url);
      // If we have an uploaded file, use the URL of it.
      $form_state['values']['flickrstyle_magnifier_image'] = $url;
      $image->status = FILE_STATUS_PERMANENT;
      file_save($image);
      // Add a reference to prevent warnings.
      file_usage_add($image, 'flickrstyle', 'flickrstyle_upload', $image->fid);
    }

    // IMAGE URL: Reset to default if empty. Does not work after a
    // hook_form_FORM_ID_alter(). In that case move it to the submit handler
    // after hook_settings() in the 'parent' form.
    if (trim($form_state['values']['flickrstyle_magnifier_image']) == '') {
      $form_state['values']['flickrstyle_magnifier_image'] = '/' . drupal_get_path('module', 'flickrstyle') . '/img/magnifier.png';
      drupal_set_message(t('The image URL has been reset to the default.'), 'warning', FALSE);
    }

    variable_set('flickrstyle_magnifier_halfsize', '-' . (floatval($form_state['values']['flickrstyle_magnifier_size']) / 2) . 'px');
    variable_set('flickrstyle_border_thickness_doubled', (floatval($form_state['values']['flickrstyle_border_thickness']) * 2) . 'px');
  }
}
