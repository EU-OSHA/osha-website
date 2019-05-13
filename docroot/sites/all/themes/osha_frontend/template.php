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

function osha_frontend_implode_comma_and_join($names) {
  $last = array_pop($names);
  if ($names) {
    return implode(', ', $names) . ' ' . t('and') . ' ' . $last;
  }
  return $last;
}

/**
 * Returns HTML for a set of checkbox form elements.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #children, #attributes.
 *
 * @ingroup themeable
 */
function osha_frontend_checkboxes($variables) {
  if ($variables['element']['#name'] == 'publication_type') {
    $map = osha_publication_get_main_publication_types_map();
    foreach ($variables['element']['#options'] as $tid => $title) {
      $sub_tids = [];
      foreach ($map as $sub_tid => $main_tid) {
        if ($tid == $main_tid) {
          $sub_tids[$sub_tid] = $sub_tid;
        }
      }
      if (count($sub_tids) > 1) {
        foreach ($sub_tids as $sub_tid) {
          $term = taxonomy_term_load($sub_tid);
          $sub_tids[$sub_tid] = $term->name;
        }
        $search = 'for="edit-publication-type-' . $tid . '"';
        $attr = drupal_attributes(['title' => $title . ' ' . t('include') . ' ' . osha_frontend_implode_comma_and_join($sub_tids)]);
        $variables['element']['#children'] = str_replace($search, $search . ' ' . $attr, $variables['element']['#children']);;
      }
    }
  }

  $element = $variables['element'];
  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  $attributes['class'][] = 'form-checkboxes';
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = array_merge($attributes['class'], $element['#attributes']['class']);
  }
  if (isset($element['#attributes']['title'])) {
    $attributes['title'] = $element['#attributes']['title'];
  }
  return '<div' . drupal_attributes($attributes) . '>' . (!empty($element['#children']) ? $element['#children'] : '') . '</div>';
}

function osha_frontend_preprocess_views_view_row_rss(&$vars) {
  $item = &$vars['row'];

  $map = [
    'feed_1' => 'rss_publication',
    'feed_2' => 'rss_news',
    'feed_3' => 'rss_events',
    'feed_7' => 'rss_directive',
    'feed_9' => 'rss_press_release',

    'feed_4' => 'rss_blog',
    'feed_5' => 'rss_calls',
    'feed_6' => 'rss_vacancies',
    'feed_8' => 'rss_seminars',
    'feed_10' => 'rss_guidlines',
  ];

  if ($vars['view']->current_display == 'feed_1') {
    $item->link .= '/view';
  }

  if (isset($map[$vars['view']->current_display])) {
    $item->link .= '?pk_campaign=' . $map[$vars['view']->current_display];
  }

  $vars['title'] = check_plain($item->title);
  $vars['link'] = check_url($item->link);
  $vars['description'] = check_plain($item->description);

  if ($vars['view']->current_display == 'commission_feed') {
    $nid = intval($item->elements[2]['value']);
    $item->elements[2]['value'] = l($vars['title'], 'node/' . $nid);
    foreach ($vars['view']->result as $row) {
      if ($row->nid == $nid) {
        $item->elements[0]['value'] = date('d/m/Y', $row->node_created);
        $item->elements[1]['value'] = 'EU-OSHA';
      }
    }
  }
  $vars['item_elements'] = empty($item->elements) ? '' : format_xml_elements($item->elements);
}

/**
 * Implements theme_menu_tree__main_menu().
 */
function osha_frontend_menu_tree__main_menu($variables) {
  $random = strlen($variables['tree']);
  global $osha_menu_counter;
  $osha_menu_counter++;
  return '<ul id="main-menu-links-'.$random.'-'.$osha_menu_counter.'" class="menu clearfix">'
    . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_tree__search_menu().
 *
 * Add classes to search menu to style like tabs.
 */
function osha_frontend_menu_tree__menu_search($variables) {
  return '<ul id="search_menu_tabs" class="tabs-primary tabs primary">'
  . $variables['tree'] . '</ul>';
}

/**
 * Implements hook_menu_link__menu_search().
 *
 * Add classes to search menu to style like tabs.
 */
function osha_frontend_menu_link__menu_search($variables) {
  $element = $variables['element'];
  $active = '';

  if (in_array('active-trail', $element['#attributes']['class'])) {
    $active = 'is-active active';
  }

  if (empty($element['#localized_options'])) {
    $element['#localized_options'] = array();
  }

  $query_parameters = drupal_get_query_parameters();
  if (!empty($query_parameters['search_block_form'])) {
    $element['#localized_options']['query']['search_block_form'] = $query_parameters['search_block_form'];
  }

  $element['#attributes']['class'] = array(
    'tabs-primary__tab', $active,
  );
  $element['#localized_options']['attributes']['class'] = array(
    'tabs-primary__tab-link', $active,
  );
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";
}

/**
 * Implements theme_menu_link__menu_block().
 */
function osha_frontend_menu_link__menu_block($variables) {
  $element = &$variables['element'];
  $delta = $element['#bid']['delta'];

  // Add homepage Icon.
  $element = $variables['element'];
  $attr = drupal_attributes($element['#attributes']);
  if (isset($variables['element']['#href']) &&
    $variables['element']['#href'] == '<front>' &&
    isset($element['#localized_options']['content']['image'])
  ) {
    $path = file_create_url($element['#localized_options']['content']['image']);
    $link = l('<img src="' . $path . '" alt="' . $element['#title'] . '"/>', $element['#href'],
      array('html' => TRUE, 'attributes' => $element['#localized_options']['attributes'])
    );
    return sprintf("\n<li %s>%s</li>", $attr, $link);
  }

  // Render or not the Menu Image.
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
    // $image = '<img src="' . $image_url . '" alt=""/>';
    // We should in fact use empty alt because the image is only decorative (the text is already present in the link).
    $image = '<img src="' . $image_url . '" alt="' . $element['#title'] . '"/>';
    
    if (!empty($element['#localized_options']['copyright']['author']) || !empty($element['#localized_options']['copyright']['copyright']) ) {   
     $image .= '<blockquote class="image-field-caption">'; 
        if (!empty($element['#localized_options']['copyright']['author'])) {
          $image .= check_markup($element['#localized_options']['copyright']['author'], 'full_html');
        }
        if (!empty($element['#localized_options']['copyright']['author']) && !empty($element['#localized_options']['copyright']['copyright']) ) {  
           $image .= '<span>&nbsp;/&nbsp;</span>';
        }
        if (!empty($element['#localized_options']['copyright']['copyright'])) {
          $image .= '<span class="blockquote-copyright">' . $element['#localized_options']['copyright']['copyright'] . '</span>';
        }
      $image .= '</blockquote>'; 
    }

    $output_image = l($image, $element['#href'], array('html' => TRUE));
  }

  $output_copyright = "";
  if (!empty($element['#localized_options']['copyright']['copyright'])) {
    $output_copyright = '<div class="introduction-copyright">' . $element['#localized_options']['copyright']['copyright'] . '</div>';
  }
  return '<li' . drupal_attributes($element['#attributes']) . '>
    <div class="introduction-title">' . $output_link . '</div>
    <div class="introduction-image">' . $output_image . '</div>
    </li>';
}

function osha_frontend_menu_link__menu_block__menu_footer_menu($variables) {
  $element = &$variables['element'];
  $delta = $element['#bid']['delta'];
  // Render or not the Menu Image.
  // Get the variable provided by osha_menu module.
  $render_img = variable_get('menu_block_' . $delta . '_' . OSHA_MENU_RENDER_IMG_VAR_NAME, 0);
  if (!$render_img) {
    return theme_menu_link($variables);
  }

  if (!empty($element['#localized_options']['content']['image'])
    && $image_url = file_create_url($element['#localized_options']['content']['image'])) {
    $image = '<img src="' . $image_url . '" alt="'.$element['#title'].'"/>';
    $output_image = l($image, $element['#href'],
      array('html' => TRUE, 'attributes' => $element['#localized_options']['attributes']));
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output_image . '</li>';
  } else {
    $output_link = l($element['#title'], $element['#href'], $element['#localized_options']);
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output_link . '</li>';
  }
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
 * Called from hook_preprocess_node
 */
function fill_related_publications(&$vars) {
  $vars['total_related_publications'] = 0;
  // get 3 related publications by common tags
  $tags_tids = array();
  if (!empty($vars['field_tags'])) {
    $tags_tids = $vars['field_tags'][LANGUAGE_NONE];
  }

  if (!empty($tags_tids)) {
    // query all publications with the same tags
    $tids = array();
    foreach ($tags_tids as $tid) {
      array_push($tids, $tid['tid']);
    }

    $query = new EntityFieldQuery();
    // exclude self
    $excluded_nids = array();
    array_push($excluded_nids, $vars['node']->nid);
    if (($vars['node']->type == 'publication') && $vars['node']->field_related_publications) {
      foreach($vars['node']->field_related_publications as $related_publications) {
        foreach($related_publications as $related_publication) {
          array_push($excluded_nids, $related_publication['target_id']);
        }
      }
    }

    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'publication')
      ->entityCondition('entity_id', $excluded_nids, 'NOT IN')
      ->fieldCondition('field_tags', 'tid', $tids, 'IN')
      ->fieldOrderBy('field_publication_date', 'value', 'DESC');

    $result = $query->execute();
    $limit = 3;
    global $user;
    if (!empty($result)) {
      $vars['total_related_publications'] = sizeof($result['node']);
      $vars['tagged_related_publications'] = array();
      $count = 0;
      foreach ($result['node'] as $n) {
        $node = node_load($n->nid);
        if ($node->status == 0 ) {
          // add unpublished only for admin, do not include in count
          if (OshaWorkflowPermissions::userHasRole('administrator', $user)) {
            $vars['tagged_related_publications'][] = node_view($node,'teaser');
          }
        } else {
          $vars['tagged_related_publications'][] = node_view($node,'teaser');
          $count++;
        }
        if ($count == $limit) {
          // max 3 related publications
          break;
        }
      }
      $vars['view_all'] = l(t('View all'), 'related-content/' . $vars['node']->nid . '/publication/' . implode('+', $tids));
    }
  }
}

/**
 * Implements hook_preprocess_node().
 */
function osha_frontend_preprocess_node(&$vars) {
  $node = $vars['node'];
  // $node is the published node, not the draft
  if ( isset($node->field_archived[LANGUAGE_NONE][0]['value']) && $node->field_archived[LANGUAGE_NONE][0]['value'] == 1 ) {
    $vars['classes_array'][] = 'osha-archived-content-node';
  }
}


/**
 * Implements hook_process_node().
 */
function osha_frontend_process_node(&$vars) {
  // Change default text of the read more link.
  if ($vars['type'] != 'press_release' && $vars['view_mode'] == 'full') {
    if (isset($vars['content']['links']['print_pdf'])) {
      // only press release could be downloaded as pdf
      unset($vars['content']['links']['print_pdf']);
    }
  }
  if ($vars['type'] == 'publication' && $vars['view_mode'] == 'full' ) {
    fill_related_publications($vars);
  }
  // CW-1087 - publications opens at alias/view link.
  if ($vars['type'] == 'publication'
    && !empty($vars['content']['links']['node']['#links']['node-readmore'])) {
    $url = &$vars['content']['links']['node']['#links']['node-readmore']['href'];
    $path = path_load($url);
    if (!empty($path)) {
      $url = $path['alias'] . '/view';
    }
    else {
      $url .= '/view';
    }
  }

  if (isset($vars['content']['links']['node']['#links']['node-readmore'])) {
    $vars['content']['links']['node']['#links']['node-readmore']['title'] = t('Show details');
  }

  /*insert views blocks - disabled for the moment
  add_blocks_inside_content($vars);*/
}

/**
 * Implements hook_block_view_alter().
 */
function osha_frontend_block_view_alter(&$data, $block) {
  if ($block->module == 'quicktabs' && isset($data['content']['content']['divs'])) {
    foreach ($data['content']['content']['divs'] as $index => $div) {
      if (isset($div['content']['#bundle']) && $div['content']['#bundle'] == 'article') {
        // Hide "Show details" link for articles used in quicktabs.
        unset($data['content']['content']['divs'][$index]['content']['links']['node']['#links']['node-readmore']);
      }
    }
  }
}

/**
 * Implements hook_preprocess_page().
 */
function osha_frontend_preprocess_page(&$variables) {
  // Template node--external-infographic.tpl.php - MDR-2351.
  $n = menu_get_object('node');
  if ($n) {
    switch ($n->type) {
      case "article":
        $external_infographic = variable_get('ncw_external_infographic_nid', 14885);
        if ($n->nid == $external_infographic) {
          $variables['theme_hook_suggestions'][] = 'node__external_infographic';
        }
    }
  }


  $variables['blog'] = FALSE;
  $bundle = '';

  if (isset($variables['page']['content']['system_main']['comment_form']['#bundle'])) {
    $bundle = $variables['page']['content']['system_main']['comment_form']['#bundle'];
  }

  if (preg_match('/(.)*(blog)(.)*/', $_SERVER['REQUEST_URI']) || $bundle == 'comment_node_blog') {
    $variables['blog'] = TRUE;
  }

  // MC-123 Open all languages with one click
  if (isset($variables['node'])) {
    $node = $variables['node'];
    drupal_add_js(array(
      'osha' => array(
        'node_nid' => $node->nid,
        'node_translations' => array_keys($node->translations->data),
        'is_publication_node' => $node->type == 'publication',
        'path_alias' => drupal_get_path_alias('node/' . $node->nid),
      ),
    ), array('type' => 'setting'));
    drupal_add_js(drupal_get_path('module', 'osha') . '/js/open_all_translations.js');
  }

  // add back to links (e.g. Back to news)
  if (isset($variables['node'])) {
    $node = $variables['node'];
    $tag_vars = array(
      'element' => array(
        '#tag' => 'h1',
        '#attributes' => array(
          'class' => array('page-header'),
        ),
      ),
    );

    if ($node->type == 'flickr_gallery') {
      if (!@$variables['page']['content']['system_main']['nodes'][$variables['node']->nid]['field_cover_flickr']) {
        $primary = osha_flickr_album_primary();
        $formatter = 'h';
        $markup = theme('osha_flickr_photo', array(
          'format' => NULL,
          'attribs' => NULL,
          'size' => $formatter,
          'photo' => flickr_photos_getinfo($primary),
          'settings' => [],
          'wrapper_class' => !empty($element['#settings']['image_class']) ? $element['#settings']['image_class'] : '',
        ));
        $cover_flickr = [
          '#theme' => 'field',
          '#weight' => 2,
          '#field_name' => 'field_cover_flickr',
          '#formatter' => 'album_cover',
          '#field_type' => 'flickrfield',
          '#label_display' => 'hidden',
          '#object' => $variables['node'],
          '#items' => [
            [
              'id' => $primary,
            ],
          ],
          ['#markup' => $markup],
        ];
        $variables['page']['content']['system_main']['nodes'][$variables['node']->nid]['field_cover_flickr'] = $cover_flickr;
      }

      drupal_set_title(t('Photo gallery'));
      $link_title = t('Back to gallery');
      $link_href = 'photo-gallery';
      $variables['page']['above_title']['back-to-link'] = array(
        '#type' => 'item',
        '#markup' => l($link_title, $link_href, array('attributes' => array('class' => array('back-to-link pull-right')))),
      );
    }
  }
}

/**
 * Implements hook_preprocess_html().
 */
function osha_frontend_preprocess_html(&$variables) {
  if (drupal_is_front_page()) {
    $variables['classes_array'][] = 'revamp';
  }
}

/**
 * Implements hook_page_alter().
 */
function osha_frontend_page_alter(&$page) {
  // Move share links to bottom of the page.
  if (!empty($page['content']['system_main']['nodes'])
    && count(element_children($page['content']['system_main']['nodes']) == 1)) {
    $keys = element_children($page['content']['system_main']['nodes']);
    $node = &$page['content']['system_main']['nodes'][current($keys)];
    if (!empty($node['links']['osha_share'])) {
      $links = $node['links']['osha_share'];
      unset($node['links']['osha_share']);
      $page['content']['osha_share'] = array(
        '#markup' => $links['#markup'],
        '#prefix' => '<div class="osha_share_bottom_container">',
        '#suffix' => '</div>',
      );
    }
  }
}

/**
 * Called from hook_preprocess_node()
 * Insert view or custom blocks in node when meet a specific markup
 * The markup is like <!--[name-of-the-block]-->
 */
function add_blocks_inside_content(&$vars){
  $body = $vars['content']['body'][0]['#markup'];
  $pattern = '/(<!--\[)([(\w+)(\-+)(\_+)(\d+)]+)(\]-->)/';

  if(preg_match_all($pattern, $body, $matches)){
    $blocks = $matches[2];

    foreach($blocks as $block){
      //try load a view block
      $block_object = block_load('views', $block);
      //load a custom block
      if(!isset($block_object->bid))
        $block_object = block_load('block', $block);

      if(isset($block_object->bid)){
        $render_array =  _block_get_renderable_array(_block_render_blocks(array($block_object)));
        $body = str_replace('<!--['.$block.']-->', render($render_array), $body);
      }
    }
    $vars['content']['body'][0]['#markup'] = $body;
  }
}

/**
 * Implements hook_form_alter().
 */
function osha_frontend_form_alter(&$form, &$form_state, $form_id) {
  switch($form_id){
    case 'search_block_form':
      $form['search_block_form']['#attributes']['placeholder'] = t('Search');
      break;
    case 'comment_node_blog_form':
      $form['author']['homepage']['#access'] = FALSE;
      break;
  }
}

/**
 * Implements hook_preprocess_HOOK() for theme_file_icon().
 *
 * Change the icon directory to use icons from this theme.
 */
function osha_frontend_preprocess_file_icon(&$variables) {
  $variables['icon_directory'] = drupal_get_path('theme', 'osha_frontend') . '/images/file_icons';
}

/**
 * Implements theme_on_the_web_image().
 *
 * @param $variables
 *   An associative array with generated variables.
 *
 * @return
 *   HTML for a social media icon.
 */
function osha_frontend_on_the_web_image($variables) {
  $service = $variables['service'];
  $title   = $variables['title'];
  $size    = variable_get('on_the_web_size', 'sm');

  $variables = array(
    'alt'   => $title,
    'path'  => drupal_get_path('theme', 'osha_frontend') . '/images/social-icons/' . $size . '/' . $service . '.png',
    'title' => $title
  );

  return theme('image', $variables);
}

/**
 * Returns HTML for an individual feed item for display in the block.
 *
 * @param $variables
 *   An associative array containing:
 *   - item: The item to be displayed.
 *   - feed: Not used.
 *
 * @ingroup themeable
 */
function osha_frontend_aggregator_block_item($variables) {
  // Display the external link to the item.
  $item = $variables['item'];

  $element = '<span class="feed-item-date">'. format_date($item->timestamp, 'custom', variable_get('date_format_osha_day_only', 'd/m/Y')) .'</span>';
  $element .= '<br/>';
  $element .= '<a href="' . check_url($item->link) . '">' . check_plain($variables['item']->title) . "</a>\n";
  return $element;
}

/**
 * Override or insert variables into the block template.
 */
function osha_frontend_preprocess_block(&$vars) {
  $block = $vars['block'];
  if ($block->delta == 'osha_homepage_tweets') {
    $vars['title_attributes_array']['class'][] = 'home';
  }
  if ($block->delta == 'oshwiki_featured_articles') {
    $vars['block_html_id'] = 'related-wiki';
    $vars['title_attributes_array']['class'][] = 'related_wiki_head';
  }

  if ($block->delta == 'osha_newsletter_subscribe') {
    $vars['title_attributes_array']['class'][] = 'home';
  }
  if ($block->delta == 'highlight-block_2') {
    $vars['title_attributes_array']['class'][] = 'home';
  }
}

/**
 * Implements theme_pager().
 */
function osha_frontend_pager($variables) {
  // Overwrite pager links.
  $variables['tags'][0] = '«';
  $variables['tags'][1] = '‹';
  $variables['tags'][3] = '›';
  $variables['tags'][4] = '»';
  return theme_pager($variables);
}

/**
 * Implements hook_pager_link().
 *
 * @see theme_pager_link().
 */
function osha_frontend_pager_link($variables) {
  global $language;
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  // Set pagination url for publication search pretty path.
  $req_uri = request_path();
  $is_pretty_search = FALSE;
  if (strpos($req_uri, 'tools-and-publications/publications') >= 0) {
    $is_pretty_search = TRUE;
    $req_uri = preg_replace('/^' . $language->language . '\//', '', $req_uri);
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if (!$is_pretty_search) {
    if ($query_pager = pager_get_query_parameters()) {
      $query = array_merge($query, $query_pager);
    }
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  $url = $_GET['q'];
  if ($is_pretty_search) {
    $url = $req_uri;
  }
  $attributes['href'] = url($url, array('query' => $query));
  return '<a' . drupal_attributes($attributes) . '>' . check_plain($text) . '</a>';
}

function osha_frontend_node_bundle($row) {
    if (!empty($row->_entity_properties['entity object']->type)) {
        return $row->_entity_properties['entity object']->type;
    }
    return NULL;
}

function osha_frontend_node_title($row) {
    return _osha_frontend_get_field_value($row, 'title_field', 'value');
}

function osha_frontend_external_resource_url($row) {
    $bundle = osha_frontend_node_bundle($row);
    if ($bundle == 'slideshare') {
        return _osha_frontend_get_field_value($row, 'field_slideshare', 'slide_url');
    } else if ($bundle == 'youtube') {
        return _osha_frontend_get_field_value($row, 'field_youtube', 'input');
    } else if ($bundle == 'external_url') {
        return _osha_frontend_get_field_value($row, 'field_external_url', 'url');
    } else if ($bundle == 'flickr') {
        $type = _osha_frontend_get_field_value($row, 'field_flickr', 'type');
        $id = _osha_frontend_get_field_value($row, 'field_flickr', 'id');
        if ($type == 'photo_id') {
            $photo_data = flickr_photo_get_info($id);
            return $photo_data['urls']['url'][0]['_content'];
        } else if ($type == 'id') {
            $photo_data = flickr_photoset_get_info($id);
            return flickr_photoset_page_url($photo_data['owner'], $photo_data['id']);
        }
    }
    return NULL;
}

function _osha_frontend_get_field_value($row, $field1, $field2) {
    if (!empty($row->_entity_properties['entity object']->$field1)) {
        $field_obj = $row->_entity_properties['entity object']->$field1;
        global $language;
        $lang = $language->language;
        if (!empty($field_obj[$language->language][0][$field2])) {
          return $field_obj[$language->language][0][$field2];
        } else if (!empty($field_obj['en'][0][$field2])) {
          return $field_obj['en'][0][$field2];
        }
    }
    return NULL;
}

function osha_frontend_menu_local_tasks_alter(&$data, $router_item, $root_path) {
  if (empty($data['tabs'])) {
    return;
  }

  $item = menu_get_object();
  if ($item && $item->type == 'dangerous_substances') {
    $new_tabs = [];
    foreach($data['tabs'][0]['output'] as $k => $v) {
      if (in_array($v['#link']['path'], ['node/%/open_all_translations', 'node/%/view_all_translations', 'node/%/short_message'])) {
        continue;
      }
      $new_tabs[] = $v;
    }
    $data['tabs'][0]['output'] = $new_tabs;
  }

  foreach ($data['tabs'][0]['output'] as &$tab) {
    if ($tab['#link']['path'] == 'node/%/open_all_translations') {
      $tab['#link']['path'] = '#';
      $tab['#link']['localized_options']['attributes']['id'][] = 'menu_local_task_open_all_translations';
    }
    elseif ($tab['#link']['path'] == 'node/%/view_all_translations') {
      $tab['#link']['path'] = '#';
      $tab['#link']['localized_options']['attributes']['id'][] = 'menu_local_task_view_all_translations';
    }
  }
}