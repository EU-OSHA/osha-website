<?php
/**
 * @file
 * osha_homepage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_homepage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_homepage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function osha_homepage_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: esener_carousel
  $nodequeues['esener_carousel'] = array(
    'name' => 'esener_carousel',
    'title' => 'Esener Carousel',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 1,
    'subqueues' => 1,
    'types' => array(
      0 => 'banner',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: home_page_main_carousel
  $nodequeues['home_page_main_carousel'] = array(
    'name' => 'home_page_main_carousel',
    'title' => 'Home page main carousel',
    'subqueue_title' => '',
    'size' => 10,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'banner',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: home_page_recommended_resources
  $nodequeues['home_page_recommended_resources'] = array(
    'name' => 'home_page_recommended_resources',
    'title' => 'Home page recommended resources',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'banner',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function osha_homepage_image_default_styles() {
  $styles = array();

  // Exported image style: banner_195_160.
  $styles['banner_195_160'] = array(
    'label' => 'Banner (195 X 160)',
    'effects' => array(
      5 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 195,
          'height' => 160,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'banner_195_160',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: banner_825_x_255.
  $styles['banner_825_x_255'] = array(
    'label' => 'Banner (825 X 255)',
    'effects' => array(
      4 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 825,
          'height' => 255,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'banner_825_x_255',
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function osha_homepage_node_info() {
  $items = array(
    'banner' => array(
      'name' => 'Banner',
      'base' => 'node_content',
      'description' => 'Banners for home page',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
