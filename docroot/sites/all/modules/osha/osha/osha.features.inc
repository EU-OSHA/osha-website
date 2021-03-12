<?php
/**
 * @file
 * osha.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
  if ($module == "entity_collection" && $api == "entity_collection_bundles_default") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function osha_image_default_styles() {
  $styles = array();

  // Exported image style: 1000x1000.
  $styles['1000x1000'] = array(
    'label' => '1000x1000',
    'effects' => array(
      3 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 500,
          'height' => 150,
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => '1000x1000',
        ),
        'weight' => 0,
      ),
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1000,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: media_thumbnail_preview.
  $styles['media_thumbnail_preview'] = array(
    'label' => 'Media thumbnail preview',
    'effects' => array(
      8 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: medium_crop_220.
  $styles['medium_crop_220'] = array(
    'label' => 'Medium Crop 220',
    'effects' => array(
      17 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 220,
          'height' => 220,
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'medium_crop_220',
        ),
        'weight' => 0,
      ),
      18 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 220,
          'height' => 220,
          'upscale' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: thumbnail_crop_100.
  $styles['thumbnail_crop_100'] = array(
    'label' => 'Thumbnail 100 from Medium crop',
    'effects' => array(
      8 => array(
        'name' => 'manualcrop_reuse',
        'data' => array(
          'reuse_crop_style' => 'medium_crop_220',
          'apply_all_effects' => 1,
        ),
        'weight' => 0,
      ),
      9 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'upscale' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function osha_node_info() {
  $items = array(
    '25th_anniversary' => array(
      'name' => '25th anniversary',
      'base' => 'node_content',
      'description' => '25th anniversary pages',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'article' => array(
      'name' => 'Article',
      'base' => 'node_content',
      'description' => 'Introductions and Sections',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'dvs_survey' => array(
      'name' => 'DVS survey',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'page' => array(
      'name' => 'Basic page',
      'base' => 'node_content',
      'description' => 'Static content, such as an \'About us\' page',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'twitter_tweet_feed' => array(
      'name' => 'Twitter Tweet Feed',
      'base' => 'node_content',
      'description' => 'These are the Tweets collected by the Tweet Feed module.',
      'has_title' => '1',
      'title_label' => 'Tweet Title',
      'help' => '',
    ),
    'twitter_user_profile' => array(
      'name' => 'Twitter User Profile',
      'base' => 'node_content',
      'description' => 'The profile of a person who has made a tweet that has been index by your configuration of Tweet Feed. Includes relevant images and Tweet data.',
      'has_title' => '1',
      'title_label' => 'Name',
      'help' => '',
    ),
    'webform' => array(
      'name' => 'Webform',
      'base' => 'node_content',
      'description' => 'Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
