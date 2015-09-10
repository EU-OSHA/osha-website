<?php
/**
 * @file
 * osha_alert_service.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function osha_alert_service_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_alert_service_alert_body';
  $strongarm->value = '<p>Hello [osha_alert_service:email],</p>
<p></p>
<p>This is the content for the alert that you\'ve created:</p>
[osha_alert_service:alert_content]
<p><a href="[osha_alert_service:privacy_policy_url]">Privacy notice</a></p>
<p  style="color:#A9A9A9; font-size:13px;">You can read our here our <strong><a href="[osha_alert_service:privacy_policy_url]"><span style="color:#A9A9A9">Privacy notice</span></a>.</p>
<p><span style="font-size:11px"><span style="color:#A9A9A9">If you don&#39;t want to receive this alert, you can&nbsp;</span><strong><a href="[osha_alert_service:unsubscribe_link]"><span style="color:#A9A9A9">unsubscribe</span></a><span style="color:#A9A9A9">.</span></strong></span></p>';
  $export['osha_alert_service_alert_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_alert_service_alert_subject';
  $strongarm->value = 'EU-OSHA alert';
  $export['osha_alert_service_alert_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_alert_service_privacy_policy_url';
  $strongarm->value = 'alertservice/privacy-statement-alerts';
  $export['osha_alert_service_privacy_policy_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_alert_service_subscribe_body';
  $strongarm->value = '<p>EU-OSHA received a request to start sending alerts to <strong>[osha_alert_service:email]</strong>.</p>

<p>Verify this EU-OSHA alert request: [osha_alert_service:subscribe_conf_link]</p>

<p>Cancel this EU-OSHA alert request: [osha_alert_service:unsubscribe_link]</p>

<p>If you are not able to click on the link, you can cut and paste it into your browser&#39;s address bar.</p>

<p>If you did not initiate this request or believe it was sent in error you can safely ignore this message.</p>

<p>Thanks,</p>
<p><strong>The EU-OSHA alerts Team</strong></p>
<p></p>
<p  style="color:#A9A9A9; font-size:13px;">You can read our here our <strong><a href="[osha_alert_service:privacy_policy_url]"><span style="color:#A9A9A9">Privacy notice</span></a>.</p>';
  $export['osha_alert_service_subscribe_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_alert_service_subscribe_subject';
  $strongarm->value = 'Your subscription to EU-OSHA Alert Service';
  $export['osha_alert_service_subscribe_subject'] = $strongarm;

  return $export;
}
