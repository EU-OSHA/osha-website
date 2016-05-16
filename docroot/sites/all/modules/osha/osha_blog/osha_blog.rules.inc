<?php

/**
 * Implements hook_rules_action_info() on behalf of the system module.
 */
function osha_blog_rules_action_info() {
  return array(
    'osha_blog_mail_to_blog_pm' => array(
      'label' => t('Send mail to PM of Blog section'),
      'group' => t('OSHA workflow'),
      'parameter' => array(
        'comment' => array(
          'type' => 'comment',
          'label' => t('Comment'),
          'description' => t("A comment"),
        ),
        'subject' => array(
          'type' => 'text',
          'label' => t('Subject'),
          'description' => t("The mail's subject."),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("The mail's message body."),
        ),
      ),
      'base' => 'osha_blog_rules_mail_to_pm',
      'access callback' => 'rules_system_integration_access',
    ),
  );
}

/**
 * Action: Send mail to PM of a comment's blog section and from field PM.
 */
function osha_blog_rules_mail_to_pm($comment, $subject, $message, $settings, RulesState $state, RulesPlugin $element) {
  $node = node_load($comment->nid);
  if (!empty($node->workbench_access)) {
    reset($node->workbench_access);
    $section_id = current($node->workbench_access);
    $pm_of_node = array();
    if (!empty($node->field_project_manager[LANGUAGE_NONE])) {
      foreach($node->field_project_manager[LANGUAGE_NONE] as $usr) {
        $pm_of_node[] = $usr['target_id'];
      }
      $pm_of_node = user_load_multiple($pm_of_node);
    }
    if ($section_id != 'section') {
      $pm_of_section = osha_workflow_access_get_section_pm($section_id);
    }
    $users = $pm_of_section + $pm_of_node;
    if (!empty($users)) {
      $params = array(
        'subject' => $subject,
        'message' => $message,
      );
      // Set a unique key for this mail.
      $name = isset($element->root()->name) ? $element->root()->name : 'unnamed';
      $key = 'rules_action_osha_workflow_rules_mail_to_blog_pm_' . $name . '_' . $element->elementId();  $languages = language_list();

      $message = array('result' => TRUE);
      foreach ($users as $user) {
        $message = drupal_mail('rules', $key, $user->mail, language_default(), $params);
        // If $message['result'] is FALSE, then it's likely that email sending is
        // failing at the moment, and we should just abort sending any more. If
        // however, $mesage['result'] is NULL, then it's likely that a module has
        // aborted sending this particular email to this particular user, and we
        // should just keep on sending emails to the other users.
        // For more information on the result value, see drupal_mail().
        if ($message['result'] === FALSE) {
          break;
        }
      }
      if ($message['result'] !== FALSE) {
        watchdog('rules', 'Successfully sent email to PM of the Blog %title.', array('%title' => $node->title));
      }
    }
  }
}