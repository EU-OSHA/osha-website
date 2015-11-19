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
  $continue = TRUE;
  $accontinue = '';
  while ($continue) {
    $categories_url = 'http://oshwiki.eu/api.php?action=query&list=allcategories&format=json&aclimit=500&acprop=size&accontinue=' . $accontinue;
    $content = file_get_contents($categories_url);
    $categories = json_decode($content);
    foreach ($categories->query->allcategories as $category) {
      $name = $category->{'*'};
      if (!$category->subcats) {
        continue;
      }
    }
    if (isset($categories->{'query-continue'})) {
      $accontinue = $categories->{'query-continue'}->allcategories->accontinue;
    }
    else {
      $continue = FALSE;
    }
  }
}