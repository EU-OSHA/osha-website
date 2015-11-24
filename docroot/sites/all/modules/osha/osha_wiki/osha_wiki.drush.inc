<?php
/**
 * Implements hook_drush_command().
 */
function osha_wiki_drush_command() {
  $items = array();

  $items['osha_wiki_categories_sync'] = array(
    'description' => 'Synchronize Wiki Categories dictionary.',
    'aliases' => array('osha-wcs'),
  );

  return $items;
}

function drush_osha_wiki_categories_sync() {
  $voc = taxonomy_vocabulary_machine_name_load('wiki_categories');
  $continue = TRUE;
  $accontinue = '';
  $pages_to_migrate = array();
  while ($continue) {
    $categories_url = 'http://oshwiki.eu/api.php?action=query&list=allcategories&format=json&aclimit=500&acprop=size&accontinue=' . $accontinue;
    $content = file_get_contents($categories_url);
    $categories = json_decode($content);
    foreach ($categories->query->allcategories as $category) {
      if (!$category->subcats) {
        continue;
      }
      $name = $category->{'*'};
      $term = reset(taxonomy_get_term_by_name($name, $voc->machine_name));
      if (!$term) {
        $term = array(
          'name' => $name,
          'vid' => $voc->vid,
          'language' => 'en',
        );
        taxonomy_term_save((object)$term);
        drupal_set_message("Created new term: '{$name}'", "ok");
        if (function_exists('drush_log')) {
          drush_log("Created new term: '{$name}'", "ok");
        }
      }
      $term = reset(taxonomy_get_term_by_name($name, $voc->machine_name));
      $categorymembers_url = 'http://oshwiki.eu/api.php?action=query&list=categorymembers&format=json&cmtitle=Category:' . urlencode($name) . '&cmprop=title|type|ids&cmlimit=500';
      $content_2 = file_get_contents($categorymembers_url);
      $categorymembers = json_decode($content_2);
      foreach ($categorymembers->query->categorymembers as $child) {
        if ($child->type != 'subcat') {
          if ($child->type == 'page') {
            $pages_to_migrate[$child->title] = $child->title;
          }
          continue;
        }
        if (!$term->tid) {
          drupal_set_message("Could not get the tid of '{$name}'", "error");
          if (function_exists('drush_log')) {
            drush_log("Could not get the tid of '{$name}'", "error");
          }
          continue;
        }
        $child_name = str_replace('Category:', '', $child->title);
        $child_term = reset(taxonomy_get_term_by_name($child_name, $voc->machine_name));
        if (!$child_term) {
          $child_term = array(
            'name' => $child_name,
            'vid' => $voc->vid,
            'parent' => $term->tid,
            'language' => 'en',
          );
          taxonomy_term_save((object) $child_term);
          drupal_set_message("Created new child term of '{$name}': '{$child_name}'", "ok");
          if (function_exists('drush_log')) {
            drush_log("Created new child term of '{$name}': '{$child_name}'", "ok");
          }

          // If creating new term, we search for pages tagged with it
          $categorymembers_child_url = 'http://oshwiki.eu/api.php?action=query&list=categorymembers&format=json&cmtitle=Category:' . urlencode($child_name) . '&cmprop=title|type|ids&cmlimit=500';
          $content_3 = file_get_contents($categorymembers_child_url);
          $categorymembers_child = json_decode($content_3);
          foreach ($categorymembers_child->query->categorymembers as $child_lvl2) {
            if ($child_lvl2->type == 'page') {
              $pages_to_migrate[$child_lvl2->title] = $child_lvl2->title;
            }
          }
        }
      }
    }
    if (isset($categories->{'query-continue'})) {
      $accontinue = $categories->{'query-continue'}->allcategories->accontinue;
    }
    else {
      $continue = FALSE;
    }
  }

  if(!empty($pages_to_migrate)) {
    // Remove existing pages.
    $query = db_select('field_data_title_field', 'a')
      ->fields('a', array('title_field_value','entity_id'))
      ->condition('a.bundle', 'wiki_page')
      ->condition('a.title_field_value', $pages_to_migrate, 'IN');

    $entities = $query->execute()->fetchAllKeyed();
    foreach ($entities as $pagetitle => $nid) {
      unset($pages_to_migrate[$pagetitle]);
    }

    foreach ($pages_to_migrate as $page) {
      drupal_set_message("Migrating page: '{$page}'", "status");
      if (function_exists('drush_log')) {
        drush_log("Migrating page: '{$page}'", "status");
      }
      // MediaWiki won't work if too many titles are given at once so we need
      // to run the migration for every page separately
      osha_wiki_migrate_wikipages_by_title(array($page));
    }
  }
}