<?php

/**
 * Implements hook_drush_command().
 */
function tweet_feed_drush_command() {
  $items = array();
  $items['tf-import-tweets'] = array(
    'description' => t('Import Tweets'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'options' => array(
      'fid' => array(
        'description' => 'The numberic ID of the feed you wish to process. Omit to process all feeds.',
      ),
      'all' => array(
        'description' => 'Update all available feeds.',
      ),
    ),
    'examples' => array(
      'tf-import-tweets' => 'Load the tweets for all configured feeds.',
      'tf-import-tweets --fid=1' => 'Load the tweets for feed ID 1',
    ),
  );
  return $items;
}

/**
 * Import Tweets
 *
 * Drush command to import all tweets from all feeds or just the one specified. 
 * TODO: Allow specifying import by machine name
 *
 * Implements drush_HOOK_COMMAND().
 */
function drush_tweet_feed_tf_import_tweets() {
  $fid = drush_get_option('fid');
  $all = drush_get_option('all');
  $run = FALSE;
  
  // If we have not specified anything, present a list of available configured feeds to
  // update. Of course, if we only have one feed, then just roll with that
  if (empty($fid) && empty($all)) {
    // If we have one, then roll with it, if we have more, then present a list
    $result = db_query("SELECT fid, feed_name, query_type FROM {tweet_feeds}
                        ORDER BY feed_name");
    if ($result->rowCount() > 1) {
      $option = array();
      while ($fdata = $result->fetchObject()) {
        switch ($fdata->query_type) {
          case 1:
            $query_type = 'Search';
            break;
          case 2:
            $query_type = 'Timeline';
            break;
          case 3: 
            $query_type = 'List';
            break;
        }
        $option[$fdata->fid] = $fdata->feed_name . ' (' . $query_type . ')';
      }
      
      $choice = drush_choice($option, dt('Which feed would you like to input?')); 
      if ($choice && array_key_exists($choice, $option)) {
        tweet_feed_process_feed($choice);
        $run = TRUE;
      }
      else {
        tweet_feed_set_message('Unable to process feed. Illegal feed id specified.', 'fatal');
        $run = TRUE;
        
      }
    }
    else {
      $feed = $result->fetchObject();
      tweet_feed_process_feed($feed->fid);
      $run = TRUE;
    }
  }

  // If we're processing all, then pass null to the feeds processor  
  if (!empty($all) && $run == FALSE) {
    tweet_feed_process_feeds(NULL);
    $run = TRUE;
  }
   
  if ($run == FALSE) { 
    $fid = (!empty($fid)) ? $fid : NULL;
    tweet_feed_process_feed($fid);
  }
}