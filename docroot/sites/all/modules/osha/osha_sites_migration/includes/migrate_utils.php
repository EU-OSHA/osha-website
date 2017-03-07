<?php

function ncw_migration_datasource_url($site_source) {
  $ret = NULL;
  $var_name = $site_source . '_migration_root_url';
  $ret = variable_get($var_name, '');
  return $ret;
}



function osha_migration_url_files($site_source, $suffix = '') {
  return ncw_migration_datasource_url($site_source) . '/sites/default/files/' . $suffix;
}

function ncw_migration_file_get_contents($url) {
  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL, $url);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 5);
  curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);
  $result = curl_exec($ch);
  curl_close($ch);
  return $result;
}


function osha_migration_author_uid() {
  return 0;
}


////////////////////////////// Normalization functions /////////////////////////
function osha_migration_normalize_field_list_text($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $language => $values) {
      if (!empty($filter_languages) && !in_array($language, $filter_languages)) {
        continue;
      }
      foreach($values as $v) {
        $field[] = $v['value'];
      }
    }
  }
  $row->{$field_name} = $field;
}

function osha_migration_normalize_field_number_integer($row, $field_name, $field_info, $filter_languages) {
  osha_migration_normalize_field_list_text($row, $field_name, $field_info, $filter_languages);
}

function osha_migration_normalize_field_number_decimal($row, $field_name, $field_info, $filter_languages) {
  osha_migration_normalize_field_number_integer($row, $field_name, $field_info, $filter_languages);
}

function osha_migration_normalize_field_list_boolean($row, $field_name, $field_info, $filter_languages) {
  osha_migration_normalize_field_number_integer($row, $field_name, $field_info, $filter_languages);
}

function osha_migration_normalize_field_text_long($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  $languages = array();
  $format = array();
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $language => $values) {
      if (!empty($filter_languages) && !in_array($language, $filter_languages)) {
        continue;
      }
      foreach($values as $v) {
        $field[] = $v['value'];
        $languages[] = $language;
        $format[] = $v['format'];
      }
    }
  }
  $row->{$field_name} = $field;
  $row->{$field_name . '_language'} = $languages;
  $row->{$field_name . '_format'} = $format;
}

function osha_migration_normalize_field_text_with_summary($row, $field_name, $field_info, $filter_languages) {
  osha_migration_normalize_field_text_long($row, $field_name, $field_info, $filter_languages);
}

function osha_migration_normalize_field_link_field($row, $field_name, $field_info, $filter_languages) {
  $field = array(
    'url' => array(),
    'title' => array(),
    'language' => array(),
  );
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    if ($field_info['translatable'] == 0) {
      $data = array_pop($row->{$field_name});
      foreach ($data as $link) {
        $field['url'][] = $link['url'];
        $field['title'][] = $link['title'];
        $field['attributes'][] = $link['attributes'];
      }
    }
    else {
      foreach ($row->{$field_name} as $lang => $data) {
        foreach ($data as $link) {
          $field['url'][] = $link['url'];
          $field['title'][] = $link['title'];
          $field['attributes'][] = $link['attributes'];
          $field['language'][] = $lang;
        }
      }
    }
  }
  $row->{$field_name} = $field['url'];
  $row->{$field_name . '_title'} = $field['title'];
  $row->{$field_name . '_attributes'} = $field['attributes'];//@todo not tested
  $row->{$field_name . '_language'} = $field['language'];
}

function osha_migration_normalize_field_text($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  $languages = array();
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $language => $values) {
      if (!empty($filter_languages) && !in_array($language, $filter_languages)) {
        continue;
      }
      foreach($values as $v) {
        $field[] = $v['value'];
        $languages[] = $language;
      }
    }
  }
  $row->{$field_name} = $field;
  $row->{$field_name . '_language'} = $languages;
}

function osha_migration_normalize_field_email($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  $languages = array();
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $language => $values) {
      if (!empty($filter_languages) && !in_array($language, $filter_languages)) {
        continue;
      }
      foreach($values as $v) {
        $field[] = $v['email'];
        $languages[] = $language;
      }
    }
  }
  $row->{$field_name} = $field;
  $row->{$field_name . '_language'} = $languages;
}

function osha_migration_normalize_field_datetime($row, $field_name, $field_info, $filter_languages) {
  $field = array(
    'value' => NULL,
    'timezone' => NULL,
    'value2' => NULL,
  );
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    $field = array_pop($row->{$field_name});
    if (!empty($field[0])) {
      $field = $field[0];
    }
  }
  $row->{$field_name} = $field['value'];
  $row->{$field_name . '_value2'} = !empty($field['value2']) ? $field['value2'] : NULL;
  $row->{$field_name . '_timezone'} = !empty($field['timezone']) ? $field['timezone'] : NULL;
}

function osha_migration_normalize_field_taxonomy_term_reference($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  if (isset($row->{$field_name}['name_original'])) { // cardinality 1
    $field[] = $row->{$field_name}['name_original'];
  }
  else if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $value) {
      if (isset($value['name_original'])) {
        $field[] = $value['name_original'];
      }
    }
  }
  else if (empty($row->{$field_name})) {
    // Do nothing ...
  }
  else {
    watchdog('ncw_migration', '[normalize_field_taxonomy_term_reference] Failed to extract value from !field', array('!field' => $field_name), WATCHDOG_WARNING);
  }
  $row->{$field_name} = $field;
}

function osha_migration_normalize_field_entityreference($row, $field_name, $field_info) {
  $field = array();
  //@todo cardinality -1 (multiple) not implemented
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $value) {
      foreach($value as $arr) {
        if (isset($arr['target_id'])) {
          $field[] = $arr['target_id'];
        }
      }
    }
  }
  else if (empty($row->{$field_name})) {
    // Do nothing ...
  }
  else {
    watchdog('ncw_migration', '[osha_migration_normalize_field_entityreference] Failed to extract value from !field', array('!field' => $field_name), WATCHDOG_WARNING);
  }
  $row->{$field_name} = $field;
}

function osha_migration_normalize_field_file($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  $languages = array();
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $language => $values) {
      if (!empty($filter_languages) && !in_array($language, $filter_languages)) {
        continue;
      }
      foreach($values as $f) {
        $field[$language][] = osha_migration_url_files($row->field_migration_source, str_replace('public://', '', $f['uri']));
        $languages[] = $language;
      }
    }
  }
  $row->{$field_name} = $field;
//  $row->{$field_name . '_language'} = $languages;
}

function osha_migration_normalize_field_image($row, $field_name, $field_info, $filter_languages) {
  osha_migration_normalize_field_file($row, $field_name, $field_info, $filter_languages);
}

/**
 * Not used automatically by normalizing
 */
function osha_migration_normalize_migrated_term_reference(&$original, $source_migration_name) {
  if (empty($original)) {
    return array();
  }
  $ret = array();
  if ($migration = Migration::getInstance($source_migration_name)) {
    foreach ($original as $term) {
      $tid = NULL;
      if (is_numeric($term)) {
        $tid = $term;
        if ($tid && $dest = $migration->getMap()->getRowBySource(array($tid))) {
          $ret = $dest['destid1'];
        }
      }
      else if (!empty($term['tid'])) {
        $tid = $term['tid'];
        if ($tid && $dest = $migration->getMap()->getRowBySource(array($tid))) {
          $ret[] = $dest['destid1'];
        }
      }
    }
  }
  return $ret;
}

/**
 * Not used automatically by normalizing
 */
function osha_migration_normalize_code_term_reference(&$original, $field_code, $voc_name) {
  if (empty($original)) {
    return array();
  }
  $ret = array();
  foreach ($original as $term) {
    if (!empty($term[$field_code][LANGUAGE_NONE][0]['value'])) {
      $existing_term = osha_migration_get_term_by_code($voc_name, $field_code, $term[$field_code][LANGUAGE_NONE][0]['value']);
      if (!empty($existing_term)) {
        $ret[] = $existing_term;
      }
    }
  }
  return $ret;
}

function osha_migration_get_term_by_code($voc_name, $field_code, $code) {
  $voc = taxonomy_vocabulary_machine_name_load($voc_name);
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term')
    ->propertyCondition('vid', $voc->vid)
    ->fieldCondition($field_code, 'value', $code);
  $result = $query->execute();

  if (isset($result['taxonomy_term'])) {
    $term = current(array_keys($result['taxonomy_term']));
    return $term;
  }
  return FALSE;
}


function ncw_migration_find_additional_resource($source_nid) {
  $migrations = array(
    'publications_add_res', 'news_add_res',
    'press_releases_add_res', 'highlights_add_res'
  );
  foreach($migrations as $machine_name) {
    $migration = Migration::getInstance($machine_name);
    /** @var MigrateMap $map */
    $map = $migration->getMap();
    if ($destid1 = $map->lookupDestinationID(array($source_nid))) {
      // @todo add some debugging here
      osha_sites_migration_debug(
        'Linking additional resource from !machine (src=!src:dest=!dest',
        array('!machine' => $machine_name, '!src' => $source_nid, '!dest' => $destid1['destid1'])
      );
      return $destid1['destid1'];
    }
  }
  return NULL;
}

function ncw_migration_find_migrated_item_id($source_nid, $migration_name) {
  $migration = Migration::getInstance($migration_name);
  /** @var MigrateMap $map */
  $map = $migration->getMap();
  if ($destid1 = $map->lookupDestinationID(array($source_nid))) {
    osha_sites_migration_debug(
      'Linking additional resource from !machine (src=!src:dest=!dest',
      array('!machine' => $migration_name, '!src' => $source_nid, '!dest' => $destid1['destid1'])
    );
    return $destid1['destid1'];
  }
  return NULL;
}