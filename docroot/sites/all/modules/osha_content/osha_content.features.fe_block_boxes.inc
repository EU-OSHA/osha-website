<?php
/**
 * @file
 * osha_content.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function osha_content_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'OSHWiki intro block';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'osha_wiki_intro';
  $fe_block_boxes->body = '<div class="OSHWiki"><div class="separatorOsHWiki">&nbsp;</div><div id="OSHWikiDivTit"><div class="imgOSHWiki"><img src="/sites/all/themes/osha_frontend/images/OSHwiki.png" alt="" width="26" height="26" /></div><div class="OSHWikiTitle">OSHWiki</div></div><div class="p1"><img src="/sites/all/themes/osha_frontend/images/content/blocks/oshwikiright.jpg" alt="" /></div><div class="p2">Find more information on our OSHWiki<span><br /></span></div><div class="p3"><a href="http://oshwiki.eu/wiki/Main_Page" target="_blank">Go to OSHWiki <img src="/sites/all/themes/osha_frontend/images/flecha.png" alt="Go to OSHWiki" width="19" height="11" /></a></div></div>';

  $export['osha_wiki_intro'] = $fe_block_boxes;

  return $export;
}
