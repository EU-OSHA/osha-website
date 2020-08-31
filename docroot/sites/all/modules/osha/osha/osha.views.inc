<?php

function osha_msd_get_term_usage($tid) {
  global $language;
  static $usage;
  if (!$usage) {
    $result = views_get_view_result('msd_used_terms', 'target_audience');
    foreach ($result as $row) {
      @$usage[$row->tid][$row->field_target_audience_taxonomy_term_data_nid]++;
    }
    $result = views_get_view_result('msd_used_terms', 'worker_groups');
    foreach ($result as $row) {
      @$usage[$row->tid][$row->field_worker_groups_covered_taxonomy_term_data_nid]++;
    }
    $result = views_get_view_result('msd_used_terms', 'prevention_measures');
    foreach ($result as $row) {
      @$usage[$row->tid][$row->field_prevention_measures_taxonomy_term_data_nid]++;
    }
    $result = views_get_view_result('msd_used_terms', 'hazards');
    foreach ($result as $row) {
      @$usage[$row->tid][$row->field_hazards_taxonomy_term_data_nid]++;
    }
    $result = views_get_view_result('msd_used_terms', 'sector');
    foreach ($result as $row) {
      @$usage[$row->tid][$row->field_sector_industry_covered_taxonomy_term_data_nid]++;
    }
  }
  if (empty($tid)) {
    return array_keys($usage);
  }
  if (!empty($usage[$tid])) {
    $term = taxonomy_term_load($tid);
    $lang = variable_get('msd_term_usage_lang', 'sl');
    if ($language->language != 'en') {
      $lang = $language->language;
    }
    if (!empty($term->name_field[$lang][0]['value'])) {
      return $term->name_field[$lang][0]['value'];
    }
  }
  return '';
}

function osha_get_nace_usage($tid) {
  static $usage;
  if (!$usage) {
    $result = views_get_view_result('used_nace_codes', 'block_1');
    foreach ($result as $row) {
      @$usage[$row->tid][$row->field_nace_codes_taxonomy_term_data_nid]++;
    }
    $result = views_get_view_result('used_nace_codes', 'block_2');
    foreach ($result as $row) {
      @$usage[$row->tid][$row->field_sector_industry_covered_taxonomy_term_data_nid]++;
    }
  }
  if (empty($tid)) {
    return array_keys($usage);
  }
  if (!empty($usage[$tid])) {
    return count($usage[$tid]);
  }
  return '';
}

/**
 * Alter the view tmgmt_node_selection_view to show latest node state.
 *
 * Alter LEFT JOIN node_revision ON node.vid = node_revision.vid
 * to LEFT JOIN node_revision ON node.nid = node_revision.nid
 */
function osha_views_query_alter(&$view, &$query) {

  if (($view->name == 'msd_used_terms') && ($view->current_display == 'page')) {
    $query->where[1]['conditions'][1]['value'] = osha_msd_get_term_usage('');
    $query->where[1]['conditions'][1]['operator'] = 'in';
  }
  if (($view->name == 'msd_used_terms') && ($view->current_display == 'export')) {
    $query->where[1]['conditions'][1]['value'] = osha_msd_get_term_usage('');
    $query->where[1]['conditions'][1]['operator'] = 'in';
  }

  if (($view->name == 'used_nace_codes') && ($view->current_display == 'page')) {
    $query->where[1]['conditions'][1]['value'] = osha_get_nace_usage('');
    $query->where[1]['conditions'][1]['operator'] = 'in';
  }
  if (($view->name == 'used_nace_codes') && ($view->current_display == 'views_data_export_1')) {
    $query->where[1]['conditions'][1]['value'] = osha_get_nace_usage('');
    $query->where[1]['conditions'][1]['operator'] = 'in';
  }

  if ($view->name == 'related_content') {
    if (($view->current_display == 'topic')||($view->current_display == 'type')) {
      $codes = arg(2);
      $tids = [];
      $names = [];
      foreach (explode('+', $codes) as $code) {
        if ($view->current_display == 'topic') {
          $tid = _osha_publication_get_tag_by_code($code);
        }
        else {
          $tid = _osha_publication_get_publication_type_by_code($code);
        }
        if ($tid) {
          $term = taxonomy_term_load($tid);
          $names[] = $term->name;
          $tids[] = $tid;
        }
      }
      $exclude_nid = intval(arg(3));
      if ($exclude_nid) {
        $query->where[1]['conditions'][] = array(
          'field' => 'node.nid',
          'value' => $exclude_nid,
          'operator' => '!=',
        );
      }
      if ($tids) {
        if ($view->current_display == 'topic') {
          $query->where[1]['conditions'][] = array(
            'field' => 'taxonomy_term_data_field_data_field_tags.tid',
            'value' => $tids,
            'operator' => 'IN',
          );
        }
        else {
          $query->where[1]['conditions'][] = array(
            'field' => 'taxonomy_term_data_field_data_field_publication_type.tid',
            'value' => $tids,
            'operator' => 'IN',
          );
        }
      }
      $view->display_handler->set_option('title', 'Publication tagged with "' . implode(' + ', $names) . '"');
    }
  }

  if ($view->name == 'press_releases') {
    if (!empty($query->table_queue['field_data_field_show_on'])) {
      $query->table_queue['field_data_field_show_on']['join']->type = "LEFT";
    }
  }

  if (($view->name == 'news') && ($view->current_display == 'front')) {
    $items = osha_homepage_get_news_and_events_limit();
    if ($items['news']) {
      $view->set_items_per_page($items['news']);
    }
  }
  if (($view->name == 'homepage_events') && ($view->current_display == 'block')) {
    $items = osha_homepage_get_news_and_events_limit();
    if ($items['events']) {
      $view->set_items_per_page($items['events']);
    }
  }
  if ($view->name == 'related_content') {
    if (in_array($view->current_display, ['page_1', 'block_1'])) {
      if ($view->current_display == 'page_1') {
        $value = [];
        foreach (explode('+', arg(4)) as $nid) {
          $value[] = intval($nid);
        }
        if ($value) {
          $query->where[0]['conditions'][] = [
            'field' => 'node.nid',
            'value' => $value,
            'operator' => 'NOT IN',
          ];
        }
      }
      if ($query->where[0]['conditions'][1]['value'] == 'news') {
        $query->where[0]['conditions'][1]['value'] = ['highlight', 'news'];
        $query->where[0]['conditions'][1]['operator'] = 'IN';
      }
    }

    foreach ($query->where[0]['conditions'] as $idx => $condition) {
      if ($condition['field'] instanceof DatabaseCondition) {
        $conditions =& $condition['field']->conditions();
        if (count($conditions) == 2) {
          $query->where[0]['conditions'][$idx] = $conditions[0];
        }
      }
    }
  }
  if (($view->name == 'related_content') && ($view->current_display == 'block_2')) {
    // Related Content - Publication Block.
    $node = menu_get_object('node');
    if ($node && $node->type == 'publication') {
      $excluded_nids = array($node->nid);
      $w = entity_metadata_wrapper('node', $node->nid);
      $related_publications = $w->field_related_publications->value();
      if ($related_publications) {
        foreach ($related_publications as $publication) {
          $excluded_nids[] = $publication->nid;
        }
      }

      foreach ($query->where as $i => $conditions) {
        foreach ($conditions['conditions'] as $idx => $condition) {
          if ($condition['field'] == 'node.nid') {
            $query->where[$i]['conditions'][$idx] = array('field' => 'node.nid', 'value' => $excluded_nids, 'operator' => 'NOT IN');
            break;
          }
        }
      }
    }
  }

  // Switch from JOIN to LEFT JOIN with workbench_moderation_node_history
  // to allow adding content types which are not moderated (i.e. page).
  if ($view->name == 'administration_content') {
    if (isset($query->table_queue['workbench_moderation_node_history']['join']->type)) {
      $query->table_queue['workbench_moderation_node_history']['join']->type = 'LEFT';
    }
    if (isset($query->table_queue['node_revision'])) {
      $query->table_queue['node_revision']['join']->field = 'nid';
      $query->table_queue['node_revision']['join']->left_field = 'nid';
    }
    // Overwrite the view.
    if (in_array('views', arg())) {
      drupal_set_message('Be careful! Overwriting query in osha.views.inc. Changing filters order may affect the view.', 'warning');
    }
    $query->where[3]['conditions'][1]['field'] = 'node.type';
  }
}
