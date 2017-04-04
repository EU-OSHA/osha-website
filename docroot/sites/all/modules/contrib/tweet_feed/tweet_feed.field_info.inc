<?php

/**
 * Implements hook_field_info().
 */
function tweet_feed_field_info() {
  return array(
    'tweet_feed_user_mention' => array(
      'label' => t('Tweet Feed: User Mentions'),
      'description' => t('Stores data on users mentioned in a tweet'),
      'default_widget' => 'tweet_feed_textfield',
      'default_formatter' => 'tweet_feed_default',
    ),
  );
}

/**
 * Implements hook_field_is_empty().
 */
function tweet_feed_field_is_empty($item, $field) {
  if ($field['type'] == 'tweet_feed_user_mention') {
    if (empty($item['tweet_feed_mention_id'])) {
      return TRUE;
    }
    return FALSE;
  }
}

/**
 * Implements hook_field_presave().
 *
 * PDO throws an error when attempting to insert an empty string into a float
 * field. Go through all values and convert empty strings to NULL.
 */
function tweet_feed_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  if ($field['type'] === 'tweet_feed_user_mention') {
    foreach ($items as $delta => $item) {
      if (!empty($item)) {
        foreach ($item as $k => $v) {
          if ($v === '') {
            $item[$k] = NULL;
          }
        }
        $items[$delta] = $item;
      }
    }
  }
}

/**
 * Implements hook_field_widget_info().
 */
function tweet_feed_field_widget_info() {
  $widget = array();
  $widget['tweet_feed_textfield'] = array(
    'label' => t('Text field'),
    'description' => t('Widget for Tweet Feed file field'),
    'field types' => array('tweet_feed_user_mention'),
  );
  return $widget;
}

/**
 * Implements hook_field_formatter_info().
 */
function tweet_feed_field_formatter_info() {
  return array(
    'tweet_feed_user_mentions' => array(
      'label' => t('User Mentions'),
      'field types' => array('tweet_feed_user_mention'),
    ),
    'emoji_formatter' => array(
      'label' => t('Emoji Formatter'),
      'field types' => array('text_with_summary', 'text', 'text_long'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function tweet_feed_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = $mentions = array();
  switch ($display['type']) {
    // Override check plain
    case 'tweet_feed_user_mentions':
      foreach ($items as $delta => $item) {
        $mentions[] = $item['tweet_feed_mention_name'] . ' (' . $item['tweet_feed_mention_screen_name'] . '): ' . $item['tweet_feed_mention_id'];
      }
      if (!empty($delta)) {
        $mentions = implode('<br />', $mentions);
        $element[$delta] = array(
          '#markup' => $mentions,
        );
      }
      break;
    // Give us a way to display emoji.
    case 'emoji_formatter':
      foreach ($items as $delta=>$item) {
        $element[$delta] = array(
          '#markup' => utf8_decode($item['value']),
        );
      }
      break;
  }
  return $element;
}

/**
 * Implements hook_field_widget_form().
 */
function tweet_feed_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  if ($field['type'] == 'tweet_feed_user_mention') {
    $element['tweet_feed_mention_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#default_value' => isset($items[$delta]['tweet_feed_mention_name']) ? $items[$delta]['tweet_feed_mention_name'] : '' ,
      '#size' => 60,
      '#maxlength' => 255,
    );
    $element['tweet_feed_mention_screen_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Screen Name'),
      '#default_value' => isset($items[$delta]['tweet_feed_mention_screen_name']) ? $items[$delta]['tweet_feed_mention_screen_name'] : '' ,
      '#size' => 60,
      '#maxlength' => 255,
    );
    $element['tweet_feed_mention_id'] = array(
      '#type' => 'textfield',
      '#title' => t('ID'),
      '#default_value' => isset($items[$delta]['tweet_feed_mention_id']) ? $items[$delta]['tweet_feed_mention_id'] : '' ,
      '#size' => 60,
      '#maxlength' => 255,
    );
  }
  return $element;
}
