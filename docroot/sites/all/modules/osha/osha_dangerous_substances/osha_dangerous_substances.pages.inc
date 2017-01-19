<?php
define('SOLR_DANGEROUS_SUBSTANCES_INDEX', 'default_content_index');

function osha_dangerous_substances_menu_dangerous_substances_form($form, $form_state) {
  drupal_set_title(t('Dangerous substances'));

  $text = osha_dangerous_substances_req_param($form_state, 'text');
  $sort = osha_dangerous_substances_req_param($form_state, 'sort_by', 'search_api_relevance');
  $direction = osha_dangerous_substances_req_param($form_state, 'direction', 'desc');

  $languages = osha_dangerous_substances_req_param($form_state, 'languages', array());
  $item_type = osha_dangerous_substances_req_param($form_state, 'item_type', array());

  $provider_type = osha_dangerous_substances_req_param($form_state, 'provider_type', array());
  $material_country = osha_dangerous_substances_req_param($form_state, 'material_country', array());
  $tasks_covered = osha_dangerous_substances_req_param($form_state, 'tasks_covered', array());

  $worker_groups_type = osha_dangerous_substances_req_param($form_state, 'worker_groups_type', array());
  $material_purpose_type = osha_dangerous_substances_req_param($form_state, 'material_purpose_type', array());
  $target_group = osha_dangerous_substances_req_param($form_state, 'target_group', array());


  $form = array(
    '#action' => url('themes/dangerous-substances/search_old'),
    '#method' => 'GET',
    'left-column' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('dangerous-substances-sidebar-first'))
    ),
    'content' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('two_column dangerous-substances-search-list')),
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
    '#attributes' => array('placeholder' => t('Search')),
    '#prefix' => '<div id="dangerous-substances-search">',
  );

  $sorts = array('search_api_relevance' => t('Relevance'), 'field_publication_date' => t('Publication date'));
  $form['content']['sort_by'] = array(
    '#title' => t('Sort by'),
    '#type' => 'select',
    '#default_value' => $sort,
    '#options' => $sorts,
  );
  $order = array('desc' => t('Desc'), 'asc' => t('Asc'));
  $form['content']['direction'] = array(
    '#title' => t('Order'),
    '#type' => 'select',
    '#default_value' => $direction,
    '#options' => $order,
  );
  $form['content']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#suffix' => '</div>',
  );


  // todo Country other - field_country_other - ?
  // todo Tasks other  - field_tasks_other - ?

  $form['left-column']['item_type'] = array(
    '#type' => 'checkboxes',
    '#options' => _osha_dangerous_substances_item_type_options_list(),
    '#default_value' => $item_type,
    '#title' => t('Type of item'),
  );

  $form['left-column']['provider_type'] = array(
    '#type' => 'checkboxes',
    '#options' => _osha_dangerous_substances_provider_type_options_list(),
    '#default_value' => $provider_type,
    '#title' => t('Type of provider'),
  );

  $form['left-column']['material_country'] = array(
    '#type' => 'checkboxes',
    '#options' => _osha_dangerous_substances_material_country_options_list(),
    '#default_value' => $material_country,
    '#title' => t('Country'),
  );

  $form['left-column']['tasks_covered'] = array(
    '#type' => 'checkboxes',
    '#options' => _osha_dangerous_substances_tasks_covered_options_list(),
    '#default_value' => $tasks_covered,
    '#title' => t('Tasks covered'),
  );

  $form['left-column']['languages'] = array(
    '#type' => 'checkboxes',
    '#options' => _osha_dangerous_substances_available_in_languages_options_list(),
    '#default_value' => $languages,
    '#title' => t('Available in languages'),
  );

  $form['left-column']['worker_groups_type'] = array(
    '#type' => 'checkboxes',
    '#options' => _osha_dangerous_substances_worker_groups_type_options_list(),
    '#default_value' => $worker_groups_type,
    '#title' => t('Worker groups covered'),
  );

  $form['left-column']['material_purpose_type'] = array(
    '#type' => 'checkboxes',
    '#options' => _osha_dangerous_substances_material_purpose_type_options_list(),
    '#default_value' => $material_purpose_type,
    '#title' => t('Purpose of the material'),
  );

  $form['left-column']['target_group'] = array(
    '#type' => 'checkboxes',
    '#options' => _osha_dangerous_substances_target_group_options_list(),
    '#default_value' => $target_group,
    '#title' => t('Target group'),
  );

  if (empty($form_state['input'])) {
    $form['content']['results-native'] = osha_dangerous_substances_menu_dangerous_substances_search_native($form_state);
  }
  if (!empty($form_state['#results-native'])) {
    $form['content']['results-native'] = $form_state['#results-native'];
  }

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'osha_dangerous_substances') . '/js/search-auto-submit.js',
  );

  $get_params = array('text', 'sort_by', 'direction');
  drupal_add_js(array('osha_dangerous_substances' => array('get_params' => $get_params)), 'setting');

  return $form;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function osha_dangerous_substances_form_osha_dangerous_substances_menu_dangerous_substances_form_alter(&$form, $form_state) {
  // Unset the form_id and build_id in order not to have nasty urls.
  unset($form['form_id']);
  unset($form['form_build_id']);
}

function osha_dangerous_substances_menu_dangerous_substances_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $form_state['redirect'] = FALSE;
  $form_state['#results-native'] = osha_dangerous_substances_menu_dangerous_substances_search_native($form_state);
}

function osha_dangerous_substances_menu_dangerous_substances_search_native($form_state) {
  global $language;
  $languages = osha_dangerous_substances_req_param($form_state, 'languages', array());
  $text = osha_dangerous_substances_req_param($form_state, 'text');
  $sort = osha_dangerous_substances_req_param($form_state, 'sort_by', 'search_api_relevance');
  $direction = osha_dangerous_substances_req_param($form_state, 'direction', 'desc');

  $item_type = osha_dangerous_substances_req_param($form_state, 'item_type', array());

  $provider_type = osha_dangerous_substances_req_param($form_state, 'provider_type', array());
  $material_country = osha_dangerous_substances_req_param($form_state, 'material_country', array());
  $tasks_covered = osha_dangerous_substances_req_param($form_state, 'tasks_covered', array());

  $worker_groups_type = osha_dangerous_substances_req_param($form_state, 'worker_groups_type', array());
  $material_purpose_type = osha_dangerous_substances_req_param($form_state, 'material_purpose_type', array());
  $target_group = osha_dangerous_substances_req_param($form_state, 'target_group', array());

  $is_search = !empty($text);
  $restrict = array();
  if ($is_search) {
    /** @var SearchApiQuery $query */
    /** @var SearchApiSolrService $server */
    list($server, $query) = osha_dangerous_substances_menu_dangerous_substances_get_query();
    $query->condition('status', 1);
    $query->condition('type', 'dangerous_substances');
    $query->keys($text);
    $query->fields(array('title_field', 'body:value'));
    if (!empty($sort)) {
      $query->sort($sort, $direction);
    }

    $results = $server->search($query);
    if (!empty($results['results'])) {
      foreach ($results['results'] as $result) {
        list($lng, $nid) = explode('_', $result['id'], 2);
        $restrict[] = $nid;
      }
    }
    if (empty($restrict)) {
      return array(
        '#nids' => '',
      );
    }
  }

  $provider_type_ids = _osha_dangerous_substances_get_terms_by_code($provider_type, 'provider_type_code');
  $material_country_ids = $material_country;//_osha_dangerous_substances_get_terms_by_code($material_country, 'material_country_code');
  $tasks_covered_ids = $tasks_covered;//_osha_dangerous_substances_get_terms_by_code($tasks_covered, 'tasks_covered_code');

  $worker_groups_type_ids = $worker_groups_type;//_osha_dangerous_substances_get_terms_by_code($worker_groups_type, 'worker_groups_type_code');
  $material_purpose_type_ids = $material_purpose_type;//_osha_dangerous_substances_get_terms_by_code($material_purpose_type, 'material_purpose_type_code');
  $target_group_ids = _osha_dangerous_substances_get_terms_by_code($target_group, 'target_group_code');

  // Select all dangerous_substances having field_file available in filtered languages.
  $q = db_select('node', 'a')->distinct();
  $q->leftJoin('field_data_field_item_type', 'b', 'a.nid = b.entity_id');

  $q->innerJoin('field_data_field_publication_date', 'c', 'a.nid = c.entity_id');

  $q->fields('a', array('nid', 'vid'));
  $q->condition('a.type', 'dangerous_substances');
  $q->condition('a.status', 1);

  $q->orderBy('field_publication_date_value', 'DESC');

  if (!empty($restrict)) {
    $q->condition('a.nid', $restrict, 'IN');
  }

  if (!empty($item_type)) {
    $q->condition('b.field_item_type_value', $item_type, 'IN');
  }

  $q->leftJoin('field_data_field_available_in_languages', 't0', 'a.nid = t0.entity_id');
  if (!empty($languages)) {
    $q->condition('t0.field_available_in_languages_value', $languages, 'IN');
  }

  $q->leftJoin('field_data_field_provider_type', 't1', 'a.nid = t1.entity_id');
  if (!empty($provider_type_ids)) {
    $q->condition('t1.field_provider_type_tid', $provider_type_ids, 'IN');
  }
  $q->leftJoin('field_data_field_material_country', 't2', 'a.nid = t2.entity_id');
  if (!empty($material_country_ids)) {
    $q->condition('t2.field_material_country_tid', $material_country_ids, 'IN');
  }
  $q->leftJoin('field_data_field_worker_groups_type', 't3', 'a.nid = t3.entity_id');
  if (!empty($worker_groups_type_ids)) {
    $q->condition('t3.field_worker_groups_type_tid', $worker_groups_type_ids, 'IN');
  }

  $q->leftJoin('field_data_field_tasks_covered', 't4', 'a.nid = t4.entity_id');
  if (!empty($tasks_covered_ids)) {
    $q->condition('t4.field_tasks_covered_tid', $tasks_covered_ids, 'IN');
  }
  $q->leftJoin('field_data_field_material_purpose_type', 't5', 'a.nid = t5.entity_id');
  if (!empty($material_purpose_type_ids)) {
    $q->condition('t5.field_material_purpose_type_tid', $material_purpose_type_ids, 'IN');
  }
  $q->leftJoin('field_data_field_target_group', 't6', 'a.nid = t6.entity_id');
  if (!empty($target_group_ids)) {
    $q->condition('t6.field_target_group_tid', $target_group_ids, 'IN');
  }

  $nids = $q->execute()->fetchCol();
  if (empty($nids)) {
    return array();
  }
  $nids = array_unique($nids);
  if (!empty($restrict)) {
    $nids = array_intersect(array_unique($restrict), $nids);
  }

  $per_page = 7;
  $current_page = pager_default_initialize(count($nids), $per_page);
  $page = array_chunk($nids, $per_page, TRUE);
  $nodes = node_load_multiple($page[$current_page]);
  $pager_params = array();
  if ($is_search) {
    $pager_params['text'] = $text;
  }
  if (!empty($sort)) {
    $pager_params['sort_by'] = $sort;
    $pager_params['direction'] = $direction;
  }

  $ret = array(
    '#nids' => $nids,
    '#prefix' => '<h2 class="h4-title">' . t('Dangerous substances available') . '</h2>',
    'results-native' => node_view_multiple($nodes, 'osha_search_teaser', 0, $language->language),
    '#suffix' => theme('pager', array(
      'tags' => array('<', '<', '', '>', '>'),
      'quantity' => 9,
      'parameters' => $pager_params,
    ))
  );
  return $ret;
}

function osha_dangerous_substances_menu_dangerous_substances_get_query() {
  $server = search_api_server_load('solr_server');
  $index = search_api_index_load(SOLR_DANGEROUS_SUBSTANCES_INDEX);
  $query = new SearchApiQuery($index);
  $query->fields(array()); // Avoid PHP notice
  $solr = new SearchApiSolrService($server);
  return array($solr, $query);
}

function _osha_dangerous_substances_item_type_options_list() {
  $return = array();
  $q = db_select('field_data_field_item_type', 't')
    ->distinct();
  $q->fields('t', array('field_item_type_value'));
  $q->condition('entity_type', 'node');
  $q->condition('bundle', 'dangerous_substances');
  $q->orderBy('t.field_item_type_value', 'ASC');
  $item_types = $q->execute()->fetchCol();
  foreach($item_types as $item_type) {
    $return[$item_type] = $item_type;
  }
  return $return;
}

function _osha_dangerous_substances_provider_type_options_list() {
  $return = array();
  $q = db_select('field_data_field_provider_type', 't')
    ->distinct();
  $q->fields('t', array('field_provider_type_tid'));
  $q->condition('entity_type', 'node');
  $q->condition('bundle', 'dangerous_substances');
  $q->innerJoin('taxonomy_term_data', 'td', 'td.tid = t.field_provider_type_tid');
  $q->orderBy('td.name', 'ASC');
  $tids = $q->execute()->fetchCol();
  $terms = taxonomy_term_load_multiple($tids);
  if (!empty($terms)) {
    foreach ($terms as $key => $term) {
      if (!empty($term->field_provider_type_code[LANGUAGE_NONE][0]['value'])) {
        $return[$term->field_provider_type_code[LANGUAGE_NONE][0]['value']] = $term->name;
      }
      else {
        $return[$term->tid] = $term->name;
      }
    }
  }
  return $return;
}

function _osha_dangerous_substances_material_country_options_list() {
  $return = array();
  $q = db_select('field_data_field_material_country', 't')
    ->distinct();
  $q->fields('t', array('field_material_country_tid'));
  $q->condition('entity_type', 'node');
  $q->condition('bundle', 'dangerous_substances');
  $q->innerJoin('taxonomy_term_data', 'td', 'td.tid = t.field_material_country_tid');
  $q->orderBy('td.name', 'ASC');
  $tids = $q->execute()->fetchCol();
  $terms = taxonomy_term_load_multiple($tids);
  if (!empty($terms)) {
    foreach ($terms as $key => $term) {
      if (!empty($term->field_material_country_code[LANGUAGE_NONE][0]['value'])) {
        $return[$term->field_material_country_code[LANGUAGE_NONE][0]['value']] = $term->name;
      }
      else {
        $return[$term->tid] = $term->name;
      }
    }
  }
  return $return;
}

function _osha_dangerous_substances_tasks_covered_options_list() {
  $return = array();
  $q = db_select('field_data_field_tasks_covered', 't')
    ->distinct();
  $q->fields('t', array('field_tasks_covered_tid'));
  $q->condition('entity_type', 'node');
  $q->condition('bundle', 'dangerous_substances');
  $q->innerJoin('taxonomy_term_data', 'td', 'td.tid = t.field_tasks_covered_tid');
  $q->orderBy('td.name', 'ASC');
  $tids = $q->execute()->fetchCol();
  $terms = taxonomy_term_load_multiple($tids);
  if (!empty($terms)) {
    foreach ($terms as $key => $term) {
      if (!empty($term->field_tasks_covered_code[LANGUAGE_NONE][0]['value'])) {
        $return[$term->field_tasks_covered_code[LANGUAGE_NONE][0]['value']] = $term->name;
      }
      else {
        $return[$term->tid] = $term->name;
      }
    }
  }
  return $return;
}

function _osha_dangerous_substances_worker_groups_type_options_list() {
  $return = array();
  $q = db_select('field_data_field_worker_groups_type', 't')
    ->distinct();
  $q->fields('t', array('field_worker_groups_type_tid'));
  $q->condition('entity_type', 'node');
  $q->condition('bundle', 'dangerous_substances');
  $q->innerJoin('taxonomy_term_data', 'td', 'td.tid = t.field_worker_groups_type_tid');
  $q->orderBy('td.name', 'ASC');
  $tids = $q->execute()->fetchCol();
  $terms = taxonomy_term_load_multiple($tids);
  if (!empty($terms)) {
    foreach ($terms as $key => $term) {
      if (!empty($term->field_worker_groups_type_code[LANGUAGE_NONE][0]['value'])) {
        $return[$term->field_worker_groups_type_code[LANGUAGE_NONE][0]['value']] = $term->name;
      }
      else {
        $return[$term->tid] = $term->name;
      }
    }
  }
  return $return;
}

function _osha_dangerous_substances_material_purpose_type_options_list() {
  $return = array();
  $q = db_select('field_data_field_material_purpose_type', 't')
    ->distinct();
  $q->fields('t', array('field_material_purpose_type_tid'));
  $q->condition('entity_type', 'node');
  $q->condition('bundle', 'dangerous_substances');
  $q->innerJoin('taxonomy_term_data', 'td', 'td.tid = t.field_material_purpose_type_tid');
  $q->orderBy('td.name', 'ASC');
  $tids = $q->execute()->fetchCol();
  $terms = taxonomy_term_load_multiple($tids);
  if (!empty($terms)) {
    foreach ($terms as $key => $term) {
      if (!empty($term->field_material_purpose_type_code[LANGUAGE_NONE][0]['value'])) {
        $return[$term->field_material_purpose_type_code[LANGUAGE_NONE][0]['value']] = $term->name;
      }
      else {
        $return[$term->tid] = $term->name;
      }
    }
  }
  return $return;
}

function _osha_dangerous_substances_target_group_options_list() {
  $return = array();
  $q = db_select('field_data_field_target_group', 't')
    ->distinct();
  $q->fields('t', array('field_target_group_tid'));
  $q->condition('entity_type', 'node');
  $q->condition('bundle', 'dangerous_substances');
  $q->innerJoin('taxonomy_term_data', 'td', 'td.tid = t.field_target_group_tid');
  $q->orderBy('td.name', 'ASC');
  $tids = $q->execute()->fetchCol();
  $terms = taxonomy_term_load_multiple($tids);
  if (!empty($terms)) {
    foreach ($terms as $key => $term) {
      if (!empty($term->field_target_group_code[LANGUAGE_NONE][0]['value'])) {
        $return[$term->field_target_group_code[LANGUAGE_NONE][0]['value']] = $term->name;
      }
      else {
        $return[$term->tid] = $term->name;
      }
    }
  }
  return $return;
}

function _osha_dangerous_substances_get_terms_by_code($codes, $type) {
  $ids = array();
  if (!empty($codes)) {
    foreach ($codes as $code) {
      if (is_int($code)) {
        $ids[] = $code;
      }
      else {
        $tid = _osha_dangerous_substances_get_term_by_code($code, $type);
        if (!empty($tid)) {
          $ids[] = $tid;
        }
      }
    }
    return $ids;
  }
}

function _osha_dangerous_substances_get_term_by_code($code, $type) {
  $tid = FALSE;
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term')
    ->fieldCondition('field_' . $type, 'value', $code, '=')
    ->range(0, 1);
  $result = $query->execute();
  if (isset($result['taxonomy_term'])) {
    $tid = current(array_keys($result['taxonomy_term']));
  }
  return $tid;
}
