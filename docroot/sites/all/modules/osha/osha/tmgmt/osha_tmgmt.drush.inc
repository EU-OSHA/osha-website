<?php

/**
 * Implements COMMANDFILE_drush_command().
 */
function osha_tmgmt_drush_command()
{
  $items = array();
  $items['osha-tmgmt-statistics'] = array(
    'description' => 'Generate character/page count statistics for nodes',
    'aliases' => array('oshstats'),
    'examples' => array(),
    'arguments' => array(),
    'options' => array(),
    'sections' => array(),
  );
  $items['osha-tmgmt-retranslate-validate'] = array(
    'description' => 'Check if all translations of node have the same structure',
    'aliases' => array('oshrtv'),
    'examples' => array(),
    'arguments' => array('bundle' => 'The node bundle'),
    'options' => array('nids' => 'List of nids separated by comma'),
    'sections' => array(),
  );
  $items['osha-tmgmt-refresh-literals'] = array(
    'description' => 'Feed the list of string literals into the locale system to make it available for translation',
    'aliases' => array('oshrl'),
  );
  $items['osha-tmgmt-blacklist-literals'] = array(
    'description' => 'Blacklist the strings which are not currently whitelisted in *.tranlate.inc',
  );
  $items['osha-tmgmt-clean-blacklist-literals'] = array(
    'description' => 'Remove single blacklisted lid or clean the entire table',
  );
  $items['test-osha-tmgmt-literals'] = array(
    'description' => 'Add translation X23456789X to all OSHA translatable strings in romanian language',
  );
  $items['osha-migrate-literals'] = array(
    'description' => 'Migrate old literals from Plone',
    'arguments' => array(
      'locales_dir' => 'Directory of Plone translations (i.e $gitroot/src/osha/translations/locales)',
    ),
  );
  $items['osha-tmgmt-test'] = array(
    'description' => 'Runs tests for tmgmt',
  );
  return $items;
}

/**
 * Implements COMMANDFILE_drush_help().
 */
function osha_tmgmt_drush_help($section)
{
  switch ($section) {
    case 'osha-tmgmt-statistics':
      return 'This command will create a group of test users assigned to the workflow roles';
    case 'osha-tmgmt-retranslate-validate':
      return 'This command will check if all translations of a node have a the same HTML structure of the body field';
  }
  return NULL;
}

function drush_osha_tmgmt_statistics()
{
  $rows = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('type', array(
        'article', 'banner', 'page', 'blog', 'calls', 'highlight',
        'job_vacancies', 'news', 'press_release', 'publication', 'seminar',
      )
    )
    ->execute()
    ->fetchAllAssoc('nid');
  drush_log(
    sprintf(
      'Computing character/page count for %s nodes, this might take a while ...',
      count($rows)
    ), 'warning'
  );
  foreach ($rows as $row) {
    $node = node_load($row->nid);
    $node = workbench_moderation_node_current_load($node);
    OshaTMGMTStatistics::computeEntityStatistics($node, 'node');
    $fake = new stdClass();
    $fake->id = $node->nid;
    $fake->nid = $node->nid;
    $fake->vid = $node->vid;
    $fake->field_character_count[LANGUAGE_NONE][0]['value'] = $node->character_count;
    $fake->field_page_count[LANGUAGE_NONE][0]['value'] = $node->page_count;
    $fake->bundle = $node->type;
    $fake->type = $node->type;
    field_attach_update('node', $fake);
  }
}

function drush_osha_tmgmt_retranslate_validate($bundle)
{
  $nids = drush_get_option('nids');
  if (!$nids) {
    // Load all
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $bundle)
      ->propertyOrderBy('nid')
      ->execute();
    $nids = array_keys($result['node']);
  } else {
    $nids = explode(',', $nids);
  }
  if (empty($nids)) {
    drush_log('No node found', 'warning');
    return;
  }
  print("Checking " . count($nids) . " nodes\n");
  foreach ($nids as $nid) {
    $messages = array();
    $valid_languages = array();
    $invalid_languages = array();
    $node = new stdClass();
    $node->nid = $nid;
    OshaTMGMTRetranslate::validate_can_retranslate($node, $messages, $valid_languages, $invalid_languages);
    drush_log(sprintf("Checking node %s (%s)", $node->nid, $node->path['alias']), 'success');
    foreach ($messages as $severity => $message_list) {
      foreach ($message_list as $message) {
        drush_log("  " . $message, $severity);
      }
    }
    foreach ($invalid_languages as $lang => $data) {
      $info = sprintf("Different HTML starting at id = '%s', <%s> in %s, <%s> in %s",
        $data['id'],
        $data[$data['source']], strtoupper($data['source']),
        $data[$lang], strtoupper($lang), TRUE);
      drush_log($info, 'warning');
    }
  }
}

function drush_osha_tmgmt_refresh_literals() {
  osha_tmgmt_refresh_string_list();
}

function drush_osha_tmgmt_test_osha_tmgmt_literals() {
  module_load_include('inc', 'i18n_string', 'i18n_string.pages');
  $strings = osha_tmgmt_get_osha_tmgmt_i18n_string_list();

  $lids = db_query("SELECT lid, source FROM {locales_source} WHERE textgroup NOT IN ('default', 'menu', 'taxonomy')")->fetchAllKeyed();
  foreach($lids as $lid => $source) {
    $form_state = array(
      'values' => array(
        'lid' => $lid,
        'textgroup' => 'default',
        'location' => '/index.php',
        'translations' => array(
          'ro' => '#ro#' . $source . '#/ro#',
        )
      )
    );
    i18n_string_locale_translate_edit_form_submit(array(), $form_state);
  }
  drush_log('Found ' . count($lids) . ' non built-in interace translated', 'success');

  drush_log('Found ' . count($strings) . ' OSHA strings registereed in hook_osha_tmgmt_i18n_string_list', 'success');
  foreach ($strings as $string) {
    osha_tmgmt_locale_add_translation($string, 'ro', '#ro#' . $string . '#/ro#');
  }
}

function drush_osha_tmgmt_osha_migrate_literals($locales_dir) {
  // $directory = drush_get_option('directory', '/Users/cristiroma/Work/osha/translations/src/osha/translations/locales');
  $directory = $locales_dir;

  // Load the POT file and extract all strings
  $msgids = array();
  $handle = fopen($directory . '/osha.pot', "r");
  if ($handle) {
    while (($line = fgets($handle)) !== false) {
      if(preg_match('/^msgid/', $line)) {
        $line = str_replace(array('msgid', '"', "\n"), '', $line);
        $line = trim($line);
        if(strlen($line)) {
          $msgids[] = $line;
        }
      }
    }
    fclose($handle);
  } else {
    // error opening the file.
  }
  $english = array();
  foreach($msgids as $msgid) {
    $en = osha_tmgmt_gettext_get_translation($msgid, 'en', $directory);
    $english[$msgid] = $en;
  }
  $strings = osha_tmgmt_get_osha_tmgmt_i18n_string_list();
  $common = array();
  foreach($english as $msgid => $msg) {
    if(in_array($msg, $strings)) {
      $common[$msgid] = $msg;
    }
  }


  $languages = language_list();
  echo "Common strings: " . count($common) . "\n";
  foreach($common as $msgid => $en) {
    // echo "en: $en\n";
    foreach ($languages as $id => $language) {
      if ($id == 'en') {
        continue;
      }
      $string = osha_tmgmt_gettext_get_translation($msgid, $id, $directory);
      if ($string != $en) {
        // echo "$id: $string\n";
        osha_tmgmt_locale_add_translation($msgid, $id, $string);
      }
    }
  }
}

function osha_tmgmt_gettext_get_translation($string, $language, $directory, $domain = 'osha') {
  setlocale(LC_ALL, $language);
  putenv('LC_ALL=' . $language);
  bindtextdomain($domain, $directory);
  textdomain($domain);
  return gettext($string);
}

function drush_osha_tmgmt_blacklist_literals() {
  $count = db_select('osha_locales_source_blacklist')->fields(NULL, array('lid'))->execute()->rowCount();
  if ($count) {
    drush_set_error('Cowardly refusing to repopulate the blacklist table. Clean the table first!');
    return;
  }
  $strings = module_invoke_all('osha_tmgmt_i18n_string_list');
  $lids = db_select('locales_source')->fields(NULL, array('lid'))->condition('source', $strings, 'NOT IN')->execute()->fetchCol();
  $insert = db_insert('osha_locales_source_blacklist')->fields(array('lid'));
  foreach ($lids as $lid) {
    if ($lid) {
      $insert->values(array($lid));
    }
  }
  $insert->execute();
  drupal_set_message(dt('Congratulations! You have just blacklisted !count strings', array('!count' => count($lids))));
}

function drush_osha_tmgmt_clean_blacklist_literals() {
  if (drush_confirm('Remove all blacklisted strings with a chance on blowing the entire planet to smithereens?')) {
    db_delete('osha_locales_source_blacklist')->execute();
  }
  else {
    drush_user_abort();
  }
}

function drush_osha_tmgmt_test() {
  OshaTMGMTRetranslationTest::run_tests();
}
