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
  $pages_to_migrate = array();
  $continue = TRUE;
  $accontinue = '';
  while ($continue) {
    $categories_url = 'http://oshwiki.eu/api.php?action=query&list=allcategories&format=json&aclimit=500&acprop=size&accontinue=' . $accontinue;
    $content = file_get_contents($categories_url);
    $categories = json_decode($content);
    foreach ($categories->query->allcategories as $category) {
      if (!$category->subcats) {
        continue;
      }
      $name = $category->{'*'};
      $term = reset(taxonomy_get_term_by_name($name));
      if (!$term) {
        $term = array(
          'name' => $name,
          'vid' => $voc->vid,
          'language' => 'en',
        );
        taxonomy_term_save((object)$term);
        if (function_exists('drush_log')) {
          drush_log("Created new term: '{$name}'", "ok");
        }
      }
      $term = reset(taxonomy_get_term_by_name($name));
      $categorymembers_url = 'http://oshwiki.eu/api.php?action=query&list=categorymembers&format=json&cmtitle=Category:' . urlencode($name) . '&cmprop=title|type|ids';
      $content_2 = file_get_contents($categorymembers_url);
      $categorymembers = json_decode($content_2);
      foreach ($categorymembers->query->categorymembers as $child) {
        if ($child->type != 'subcat') {
          if ($child->type == 'page') {
            $pages_to_migrate[] = $child->title;
          }
          continue;
        }
        if (!$term->tid) {
          if (function_exists('drush_log')) {
            drush_log("Could not get the tid of '{$name}'", "error");
          }
          continue;
        }
        $child_name = str_replace('Category:', '', $child->title);
        $child_term = reset(taxonomy_get_term_by_name($child_name));
        if (!$child_term) {
          $child_term = array(
            'name' => $child_name,
            'vid' => $voc->vid,
            'parent' => $term->tid,
            'language' => 'en',
          );
          taxonomy_term_save((object)$child_term);
          if (function_exists('drush_log')) {
            drush_log("Created new child term of '{$name}': '{$child_name}'", "ok");
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
  osha_wiki_migrate_wikipages_by_title($pages_to_migrate);
}