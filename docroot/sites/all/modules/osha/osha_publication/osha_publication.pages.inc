<?php

function osha_publication_menu_publications_form($form, $form_state) {
  global $language;
  drupal_set_title(t('Publications'));
  $text = osha_publication_req_param($form_state, 'text');
  $sort_by = osha_publication_req_param($form_state, 'sort_by', 'field_publication_date');
  $publication_type = osha_publication_req_param($form_state, 'publication_type', array());
  $languages = osha_publication_req_param($form_state, 'languages', array($language->language));
  $form = array(
    '#action' => url('publications'),
    '#method' => 'GET',
    'left-column' => array(
      '#type' => 'container',
      '#attributes' => array('class' => ['content-filters']),
      '#prefix' => '<aside class="sidebars_first">',
      '#suffix' => '</aside>',
    ),
    'content' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('two_column publications-search-list')),
    ),
    '#token' => FALSE,
  );
  $form['content']['text'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Search'),
    '#maxlength' => 200,
    '#default_value' => $text,
    '#title_display' => 'invisible',
    '#attributes' => array('placeholder' => t('Search'), 'class' => ['search-new-design']),
    '#prefix' => '<div class="views-exposed-widgets clearfix"><div id="edit-search-api-views-fulltext-wrapper" class="views-exposed-widget">',
  );
  $form['content']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#suffix' => '</div>',
  );
  $sorts = [
    'field_publication_date' => t('Publication date'),
    'alphabetically' => t('Alphabetically'),
  ];
  $form['content']['sort_by'] = array(
    '#title' => t('Sort by'),
    '#type' => 'select',
    '#default_value' => $sort_by,
    '#attributes' => array('class' => ['new-select-style']),
    '#options' => $sorts,
    '#prefix' => '<div class="views-exposed-widget">',
    '#suffix' => '</div>',
  );

  $q = db_select('field_data_field_file', 'b');
  $q->fields('b', array('language'));
  $q->innerJoin('node', 'a', 'a.nid = b.entity_id AND a.vid = b.revision_id');
  $q->condition('b.bundle', 'publication');
  $q->condition('a.status', 1);
  $q->distinct();
  $used_languages = $q->execute()->fetchAllKeyed(0, 0);

  $enabled_lang = language_list();
  $enabled_lang = osha_sort_language_list($enabled_lang);
  if (isset($enabled_lang['sh'])) {
    $enabled_lang['sh']->name = t('Serbian');
  }

  $lang_options = [];
  foreach ($enabled_lang as $lang => $lang_obj) {
    if (!isset($used_languages[$lang])) {
      continue;
    }
    if ($lang_obj->enabled) {
      $lang_options[$lang] = $lang_obj->name;
    }
  }

  $form['content']['languages'] = array(
    '#type' => 'select',
    '#options' => $lang_options,
    '#default_value' => $languages,
    '#title' => t('Available in languages'),
    '#attributes' => array('class' => ['new-select-style']),
    '#chosen' => TRUE,
    '#multiple' => TRUE,
    '#prefix' => '<div class="views-exposed-widget">',
    '#suffix' => '</div></div>',
  );

  $query_params = drupal_get_query_parameters();
  if (!empty($query_params['sort_by'])) {
    unset($query_params['sort_by']);
  }
  if (empty($query_params['text'])) {
    unset($query_params['text']);
  }

  if (!empty($query_params) || $publication_type) {
    $form['content']['link'] = [
      '#type' => 'markup',
      '#markup' => l(t('Clear filter'), current_path()),
    ];
  }

  $form['left-column']['publication_type'] = array(
    '#type' => 'checkboxes',
    '#options' => _publication_type_options_list(TRUE),
    '#default_value' => $publication_type,
    '#title' => t('Type'),
  );

  if (empty($form_state['input'])) {
    $form['content']['results-native'] = osha_publication_menu_publications_search_native($form_state);
    $native_nids = $form['content']['results-native']['#nids'];
    $form['content']['results-related'] = [];
  }
  if (!empty($form_state['#results-native'])) {
    $form['content']['results-native'] = $form_state['#results-native'];
    $form['content']['results-related'] = $form_state['#results-related'];
  }

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'osha_publication') . '/js/search-auto-submit.js',
  );

  $get_params = array('text', 'sort_by');
  drupal_add_js(array('osha_publication' => array('get_params' => $get_params)), 'setting');
  return $form;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function osha_publication_form_osha_publication_menu_publications_form_alter(&$form, $form_state) {
  // Unset the form_id and build_id in order not to have nasty urls.
  unset($form['form_id']);
  unset($form['form_build_id']);
}

function osha_publication_menu_publications_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $form_state['redirect'] = FALSE;
  $form_state['#results-native'] = osha_publication_menu_publications_search_native($form_state);
  $native_nids = array();
  if (!empty($form_state['#results-native']['#nids'])) {
    $native_nids = $form_state['#results-native']['#nids'];
  }
  $form_state['#results-related'] = osha_publication_menu_publications_search_related($form_state, $native_nids);
}

function osha_publication_menu_publications_search_native($form_state) {
  global $language;
  $languages = osha_publication_req_param($form_state, 'languages', array($language->language));
  $text = osha_publication_req_param($form_state, 'text');
  $sort_by = osha_publication_req_param($form_state, 'sort_by', 'field_publication_date');
  $publication_type = osha_publication_req_param($form_state, 'publication_type', array());

  $is_search = !empty($text);
  $restrict = array();
  if ($is_search) {
    /** @var SearchApiQuery $query */
    /** @var SearchApiSolrService $server */
    list($server, $query) = osha_publication_menu_publications_get_query();
    $query->condition('status', 1);
    $query->condition('type', 'publication');
    $query->condition('field_file:file', 0, '>');

    $query->condition('field_publication_date', time(), '<');

    $query->keys($text);
    $query->fields(array('title_field', 'body:value', 'field_tags:name'));

    if ($sort_by == 'field_publication_date') {
      $query->sort('field_publication_date', 'DESC');
    }
    else {
      $query->sort('title2', 'ASC');
    }

    $results = $server->search($query);
    if (!empty($results['results'])) {
      foreach ($results['results'] as $result) {
        list($nid, $lng) = explode('/', $result['id'], 2);
        $restrict[] = $nid;
      }
    }
    if (empty($restrict)) {
      return array(
        '#nids' => '',
      );
    }
  }

  $types_map = osha_publication_get_main_publication_types_map(FALSE);
  $publication_type_ids = array();
  if (!empty($publication_type)) {
    foreach ($publication_type as $pubt) {
      if ($pubt) {
        $publication_type_ids[] = $pubt;
        foreach ($types_map as $tid => $main_tid) {
          if ($pubt == $main_tid) {
            $publication_type_ids[] = $tid;
          }
        }
      }
    }
  }

  // Select all publications having field_file available in filtered languages.
  $q = db_select('node', 'a');
  $q->innerJoin('field_data_field_publication_type', 'b', 'a.nid = b.entity_id');
  $q->innerJoin('field_data_field_publication_date', 'c', 'a.nid = c.entity_id');
  $q->fields('a', array('nid', 'vid'));
  $q->condition('a.type', 'publication');
  $q->condition('a.status', 1);

  if ($sort_by == 'field_publication_date') {
    $q->orderBy('field_publication_date_value', 'DESC');
  }
  else {
    $q->orderBy('title', 'ASC');
  }

  if (!empty($restrict)) {
    $q->condition('a.nid', $restrict, 'IN');
  }
  if (!empty($publication_type_ids)) {
    $q->condition('b.field_publication_type_tid', $publication_type_ids, 'IN');
  }
  $pnids = $q->execute()->fetchCol();
  $nids = array();
  foreach ($pnids as $pnid) {
    $q = db_select('field_data_field_file', 'b');
    $q->fields('b', array('entity_id'));
    $q->innerJoin('node', 'a', 'a.nid = b.entity_id AND a.vid = b.revision_id');
    $q->condition('b.bundle', 'publication');
    $q->condition('b.entity_id', $pnid);
    if (!empty($languages)) {
      $q->condition('b.language', $languages, 'IN');
    }
    $c = $q->countQuery()->execute()->fetchField();
    if ($c >= count($languages)) {
      $nids[] = $pnid;
    }
  }
  if (empty($nids)) {
    return array();
  }
  $nids = array_unique($nids);
  if (!empty($restrict)) {
    $nids = array_intersect(array_unique($restrict), $nids);
  }
  $total = count($nids);
  $per_page = 5;
  $current_page = pager_default_initialize(count($nids), $per_page);
  $page = array_chunk($nids, $per_page, TRUE);
  $nodes = node_load_multiple($page[$current_page]);
  foreach ($nodes as $node) {
    $node->filter_languages = $languages;
  }
  $pager_params = array();
  if ($is_search) {
    $pager_params['text'] = $text;
  }
  if (!empty($sort_by)) {
    $pager_params['sort_by'] = $sort_by;
  }

  $showing_lang = $language->language;
  if (count($languages) == 1) {
    $showing_lang = current($languages);
  }
  $ret = array(
    '#nids' => $nids,
    '#prefix' => '<h2>' . t('Publications available') . ' (' . $total . ')</h2>',
    'results-native' => node_view_multiple($nodes, 'osha_search_teaser', 0, $showing_lang),
    '#suffix' => $suffix,
  );
  return $ret;
}

function osha_publication_menu_publications_get_query() {
  $server = search_api_server_load('solr_server');
  $index = search_api_index_load(SOLR_SEARCH_INDEX);
  $query = new SearchApiQuery($index);
  // Avoid PHP notice.
  $query->fields(array());
  $solr = new SearchApiSolrService($server);
  return array($solr, $query);
}

/**
 * Get options for publication type filter.
 */
function _publication_type_options_list($map_only = FALSE) {
  $map = osha_publication_get_main_publication_types_map();
  $return = array();
  $vocabulary = taxonomy_vocabulary_machine_name_load('publication_types');
  if (!empty($vocabulary)) {
    $terms = taxonomy_get_tree($vocabulary->vid);
    foreach ($terms as $key => $term) {
      if ($map_only) {
        if (!empty($map[$term->tid])) {
          $term = taxonomy_term_load($map[$term->tid]);
          if (!$term->field_main_category) {
            continue;
          }
          if (!$term->field_main_category[LANGUAGE_NONE][0]['value']) {
            continue;
          }
          $return[$term->tid] = $term->name;
        }
        else {
          $term = taxonomy_term_load($term->tid);
          if (!$term->field_main_category) {
            continue;
          }
          if (!$term->field_main_category[LANGUAGE_NONE][0]['value']) {
            continue;
          }
          $return[$term->tid] = $term->name;
        }
      }
      else {
        $return[$term->tid] = $term->name;
      }
    }
  }
  return $return;
}
