<?php

/**
 * @file
 * Sample template for sending user password reset messages with HTML Mail
 *
 * The following variables are available in this template:
 *
 *  - $message_id: The email message id, which is 'user_password_reset'
 *  - $module: The sending module, which is 'user'.
 *  - $key: The user email action, which is 'password_reset'.
 *  - $headers: An array of email (name => value) pairs.
 *  - $from: The configured sender address.
 *  - $to: The recipient email address.
 *  - $subject: The message subject line.
 *  - $body: The formatted message body.
 *  - $language: The language object for this message.
 *  - $params: An array containing the following keys:
 *    - account: The user object whose password is being requested, which
 *      contains the following useful properties:
 *      - uid: The user-id number.
 *      - name: The user login name.
 *      - mail: The user email address.  Should be the same as $to.
 *      - theme: The user-chosen theme, or a blank string if unset.
 *      - signature: The user signature block.
 *      - signature_format: The text input filter used to format the signature.
 *      - created: Account creation date, as a unix timestamp.
 *      - access: Account access date, as a unix timestamp.
 *      - login: Account login date, as a unix timestamp.
 *      - status: Integer 0 = disabled; 1 = enabled.
 *      - timezone: User timezone, or NULL if unset.
 *      - language: User language, or blank string if unset.
 *      - picture: Path to user picture, or blank string if unset.
 *      - init: The email address used to initially register this account.
 *      - data: User profile data, as a serialized string.
 *      - roles: Array of roles assigned to this user, as (rid => role_name)
 *        pairs.
 *  - $template_path: The relative path to the template directory.
 *  - $template_url: The absolute url to the template directory.
 *  - $theme: The name of the selected Email theme.
 *  - $theme_path: The relative path to the Email theme directory.
 *  - $theme_url: The absolute url to the Email theme directory.
 */
  $template_name = basename(__FILE__);
  $current_path = realpath(NULL);
  $current_len = strlen($current_path);
  $template_path = realpath(dirname(__FILE__));
  if (!strncmp($template_path, $current_path, $current_len)) {
    $template_path = substr($template_path, $current_len + 1);
  }
  $template_url = url($template_path, array('absolute' => TRUE));
?>
<div class="htmlmail-user-password-reset-body htmlmail-user-body htmlmail-body">
<?php echo $body; ?>
<br/>
<br/>
<?php
  $directory = drupal_get_path('theme', 'osha_frontend');
  global $base_url; // TODO: should link to node
  print l(theme('image', array(
    'path' => $directory . '/images/signature-euosha.jpg',
    'width' => 808,
    'height' => 154,
    'attributes' => array('style' => 'border: 0px;')
    )), $base_url, array(
    'html' => TRUE,
    'external' => TRUE
  ));
?>
</div>
