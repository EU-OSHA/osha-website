<?php
/**
 * @file
 * osha_newsletter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_newsletter_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "entity_collection" && $api == "entity_collection_bundles_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_newsletter_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function osha_newsletter_image_default_styles() {
  $styles = array();

  // Exported image style: highlight_image.
  $styles['highlight_image'] = array(
    'label' => 'Highlight image (crop)',
    'effects' => array(
      4 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 300,
          'height' => 200,
          'keepproportions' => 1,
          'reuse_crop_style' => '',
          'style_name' => 'highlight_image',
        ),
        'weight' => 0,
      ),
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => 200,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: newsletter_highlight.
  $styles['newsletter_highlight'] = array(
    'label' => 'Newsletter highlight (reuse crop highlight)',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function osha_newsletter_node_info() {
  $items = array(
    'newsletter_article' => array(
      'name' => 'Newsletter article',
      'base' => 'node_content',
      'description' => 'Ad-hoc content for newsletter (such as Coming soon...)',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
