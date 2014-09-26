<?php
/**
 * @file
 * Osha frontend template functionality
 */

/**
 * Implements theme_links__system_main_menu().
 */
function osha_frontend_links__system_main_menu() {
  return NULL;
}

/**
 * Implements theme_menu_tree__main_menu().
 */
function osha_frontend_menu_tree__main_menu($variables) {
  return '<ul id="main-menu-links" class="menu clearfix">'
    . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_link__menu_block().
 */
function osha_frontend_menu_link__menu_block($variables) {
  $element = &$variables['element'];
  $delta = $element['#bid']['delta'];

  // Get the variable provided by osha_menu module.
  $render_img = variable_get('menu_block_' . $delta . '_' . OSHA_MENU_RENDER_IMG_VAR_NAME, 0);
  if (!$render_img) {
    return theme_menu_link($variables);
  }
  // $element['#attributes']['data-image-url'] = $image_url;
  $output_link = l($element['#title'], $element['#href'], $element['#localized_options']);

  $output_image = "";
  if (!empty($element['#localized_options']['content']['image'])
      && $image_url = file_create_url($element['#localized_options']['content']['image'])) {
    $image = '<img src="' . $image_url . '"/>';
    $output_image = l($image, $element['#href'], array('html' => TRUE));
  }

  return '<li' . drupal_attributes($element['#attributes']) . '>
    <div class="introduction-title">' . $output_link . '</div>
    <div class="introduction-image">' . $output_image . '</div>
    </li>';
}

/**
 * Implements hook_theme().
 */
function osha_frontend_date_display_single(&$variables) {
  $date_theme = '';
  if (!empty($variables['dates']['value']['osha_date_theme'])) {
    $date_theme = $variables['dates']['value']['osha_date_theme'];
  }
  switch ($date_theme) {
    case 'calendar':
      return osha_frontend_date_calendar_icon($variables);

    default:
      return theme_date_display_single($variables);
  }
}

/**
 * Split the date into spans to be formatted as calendar icon.
 */
function osha_frontend_date_calendar_icon($variables) {
  $time = strtotime($variables['date']);
  $month = date('m', $time);
  $day = date('d', $time);
  return
    '<div class="osha-date-calendar">
      <span class="osha-date-calendar-month">' . $month . '</span>
      <span class="osha-date-calendar-day">' . $day . '</span>
    </div>';
}

/**
 * Implements hook_apachesolr_sort_list().
 */
function osha_frontend_apachesolr_sort_list($vars) {
  $items = &$vars['items'];
  unset($items['sort_label']);
  unset($items['bundle']);
  unset($items['sort_name']);
  return theme('item_list', array('items' => $vars['items']));
}

/**
 * Implements hook_preprocess_node().
 */
function osha_frontend_process_node(&$vars) {
  // Change default text of the read more link.
  if ($vars['type'] == 'article') {
    $wiki_articles_no = 0;
    if (isset($vars['field_related_oshwiki_articles'])) {
      $wiki_articles_no = sizeof($vars['field_related_oshwiki_articles']);
    }

    $vars['total_wiki'] = 0;
    if ($wiki_articles_no < 2) {
      $limit = 2 - $wiki_articles_no;
      // get 2-$wiki_articles_no tagged wiki
      $tags_tids = array();
      if (isset($vars['field_tags'])) {
        $tags_tids = $vars['field_tags'][LANGUAGE_NONE];
      }

      if (!empty($tags_tids)) {
        $tids = array();
        foreach ($tags_tids as $tid) {
          array_push($tids, $tid['tid']);
        }

        $query = new EntityFieldQuery();
        $result = $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'wiki_page')
          ->fieldCondition('field_tags', 'tid', $tids, 'IN')
          ->propertyOrderBy('changed', 'DESC')
          ->pager($limit)
          ->execute();
        if (!empty($result)) {
          $vars['total_wiki'] = sizeof($result['node']);
          $vars['tagged_wiki'] = array();
          foreach ($result['node'] as $n) {
            $node = node_load($n->nid);
            $vars['tagged_wiki'][] = node_view($node,'osha_wiki');
          }
        }
      }
    }

  }
  if (isset($vars['content']['links']['node']['#links']['node-readmore'])) {
    $vars['content']['links']['node']['#links']['node-readmore']['title'] = t('Show details');
  }
}

/**
 * Implements hook_form_alter().
 */
function osha_frontend_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#attributes']['placeholder'] = t('Search');
  }
}

/**
 * @todo @Ivan: Edit only below
 */





/**
 * @todo @Ivan: Do not go below this line
 */
