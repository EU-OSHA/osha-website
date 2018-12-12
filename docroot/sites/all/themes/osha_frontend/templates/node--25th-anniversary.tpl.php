<?php
/**
 * @file
 * Returns the HTML for an article node.
 */
global $language;
global $base_url;

?>

<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>


      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php
  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  // unset to render below after a div
  if (isset($content['field_related_oshwiki_articles'])) {
    hide($content['field_related_oshwiki_articles']);
  }
  print render($content);
  ?>


  <?php
  //View with the content of the 25th aniversary nids 
  $vista25th = views_get_view_result('our_story','block_1');
  $number = count($vista25th);
  ?>
  <div class="key-next-prev-buttons">
  <?php
  $trimat = 40;//Trim the title if it is longer than $trimat
  if ($number >0){ //There are content of 25th aniversary
    foreach ($vista25th as $key => $value) {
      if($value->nid == $node->nid){
        $number25 = $key;
        break;
      }
    }
  
    if($number25==0){//Is the first content so we avoid to show the previous button
      $nextC =$number25 +1;
      $next_url = $base_url ."/" .$language->language ."/" . drupal_get_path_alias('node/'.$vista25th[$nextC]->nid,$language->language);
      $next_title = truncate($vista25th[$nextC]->node_title,$trimat);
      
      ?>
      <span class="next-button blue"><a href="<?php print($next_url)?>" class="nexting-button"><span class="nav-info">Next content</span>    
      <span class="nav-title"> <?php print $next_title?></span></a></span>
     <?php
    }
    elseif($number25 == $number-1) {//Is the last content so we avoid to show the next button
      $prevC =$number25 -1;
      $prev_title = truncate($vista25th[$prevC]->node_title,$trimat);
      $prev_url = $base_url ."/" .$language->language ."/" . drupal_get_path_alias('node/'.$vista25th[$prevC]->nid,$language->language); 
      ?>
      <span class="prev-button blue"><a href="<?php print($prev_url)?>" class="previous-button"><span class="nav-info">Previous content</span>
      <span class="nav-title"> <?php print $prev_title?></span></a></span>
      <?php
    }
    else{
      $prevC =$number25 -1;  
      $nextC =$number25 +1;
      $next_title = truncate($vista25th[$nextC]->node_title,$trimat);
      $next_url = $base_url ."/" .$language->language ."/" . drupal_get_path_alias('node/'.$vista25th[$nextC]->nid,$language->language);
      $prev_title = truncate($vista25th[$prevC]->node_title,$trimat);
      $prev_url = $base_url ."/" .$language->language ."/" . drupal_get_path_alias('node/'.$vista25th[$prevC]->nid,$language->language);
      ?>
      <span class="prev-button blue"><a href="<?php print($prev_url)?>" class="previous-button"><span class="nav-info">Previous content</span>
      <span class="nav-title"> <?php print $prev_title?></span></a></span>
     
      <span class="next-button blue"><a href="<?php print($next_url)?>" class="nexting-button"><span class="nav-info">Next content</span>
      <span class="nav-title"> <?php print $next_title?></span></a></span>
      <?php
    }
  }
  ?>
 </div>
  <?php print render($content['links']); ?>
  <?php

  function truncate($string, $length, $stopanywhere=false) {
    //truncates a string to a certain char length, stopping on a word if not specified otherwise.
    if (strlen($string) > $length) {
        //limit hit!
        $string = substr($string,0,($length -3));
        if ($stopanywhere) {
            //stop anywhere
            $string .= '...';
        } else{
            //stop on a word.
            $string = substr($string,0,strrpos($string,' ')).'...';
        }
    }
    return $string;
  }
  ?>
 
</article>
