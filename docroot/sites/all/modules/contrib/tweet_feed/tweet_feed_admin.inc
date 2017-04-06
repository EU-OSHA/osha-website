<?php

/**
 * Administrative Portal
 *
 * When the root Tweet Feed option is selected, it presents a list of the tools available
 * to be configured.
 */
function tweet_feed_menu_page() {
  $all_blocks = array();
  $blocks = system_admin_menu_block(
    array('tab_root' => 'admin/config/services/tweet_feed',
          'path' => 'admin/config/services/tweet_feed')
  );
  foreach($blocks as $key=>$block) {
    $new_block = $block;
    $new_block['show'] = TRUE;
    $all_blocks[] = $new_block;
  }
  $block_out['content'] = theme('admin_block_content', array('content' => $all_blocks));
  $block_out['title'] = t('Tweet Feed Configuration');
  $block_out['show'] = TRUE;

  return theme('admin_page', array('blocks' => array($block_out)));
}

/**
 * Accounts Table
 *
 * A table to list the Twitter accounts associated with this install that can be used
 * to bring in feeds to the database.
 */
function tweet_feed_accounts_table() {
  $rows = array();
  $header = array(
    'account_name' => array('data' => t('Account name'), 'style' => 'text-align: center;'),
    'uses' => array('data' => t('# Uses'), 'style' => 'text-align: center;'),
    'consumer_key' => array('data' => t('Consumer Key'), 'style' => 'text-align: center;'),
    'oauth_token' => array('data' => t('Oauth Token'), 'style' => 'text-align: center;'),
    'edit' => array('data' => t('Edit'), 'style' => 'text-align: center;'),
    'delete' => array('data' => t('Delete'), 'style' => 'text-align: center;'),
  );
  $result = db_select('tweet_accounts', 'a')
              ->fields('a')
              ->orderBy('account_name', 'ASC')
              ->execute();
  while ($data = $result->fetchObject()) {
    // Determine how many queries this feed is responsible for
    $cresult = db_select('tweet_feeds', 'f')
                 ->fields('f')
                 ->condition('f.aid', $data->aid)
                 ->execute();
    $count = $cresult->rowCount();
    $row = array();
    $row[] = $data->account_name;
    $row[] = (array('data' => $count, 'align' => 'center'));
    $row[] = (array('data' => $data->consumer_key, 'align' => 'center'));
    $row[] = (array('data' => $data->oauth_token, 'align' => 'center'));
    $row[] = (array('data' => l(t('Edit'), 'admin/config/services/tweet_feed/accounts/edit/' . $data->aid), 'align' => 'center'));
    $row[] = (array('data' => l(t('Delete'), 'admin/config/services/tweet_feed/accounts/delete/' . $data->aid), 'align' => 'center'));
    $rows[] = $row;
  }

  if (count($rows) == 0) {
    $rows = array(
      array(
        'data' => array(array('align' => 'center', 'colspan' => 6, 'data' => t('THERE ARE CURRENTLY NO CONFIGURED TWITTER ACCOUNTS.')))
      ),
    );
  }
  $output = theme('table', array('header' => $header, 'rows' => $rows));
  return $output;
}

/**
 * Feeds Table
 *
 * A table of configured feeds we will pull on each cron run or drush command. Each feed
 * can be tied to a specific feed account above.
 */
function tweet_feed_feeds_table() {
  $rows = array();
  $header = array(
    'feed_name' => array('data' => t('Feed name'), 'style' => 'text-align: center;'),
    'feed_type' => array('data' => t('Type'), 'style' => 'text-align: center;'),
    'feed_criteria' => array('data' => t('Feed Criteria'), 'style' => 'text-align: center;'),
    'number_per_pull' => array('data' => t('# Per Pull'), 'style' => 'text-align: center;'),
    'new_window' => array('data' => t('New Window'), 'style' => 'text-align: center;'),
    'truncate' => array('data' => t('Truncate'), 'style' => 'text-align: center;'),
    'edit' => array('data' => t('Edit'), 'style' => 'text-align: center;'),
    'delete' => array('data' => t('Delete'), 'style' => 'text-align: center;'),
    'import' => array('data' => t('Import'), 'style' => 'text-align: center;'),
  );

  $result = db_select('tweet_feeds', 'f')
              ->fields('f')
              ->orderBy('feed_name', 'ASC')
              ->execute();
  while ($data = $result->fetchObject()) {

    switch ($data->query_type) {
      case QUERY_SEARCH:
        $query_type = 'Timeline Search';
        $feed_criteria = $data->search_term;
        break;
      case QUERY_TIMELINE:
        $query_type = 'User Timeline';
        $feed_criteria = $data->timeline_id;
        break;
      case QUERY_LIST:
        $query_type = 'User List';
        $feed_criteria = $data->timeline_id . '/' . $data->list_name;
        break;
      default:
        $query_type = t('Unknown');
        $feed_criteria = t('Unknown');
    }

    $row = array();
    $row[] = $data->feed_name;
    $row[] = (array('data' => $query_type, 'align' => 'center'));
    $row[] = (array('data' => $feed_criteria, 'align' => 'center'));
    $row[] = (array('data' => number_format($data->pull_count * 100), 'align' => 'center'));
    $row[] = (array('data' => $data->new_window, 'align' => 'center'));
    $row[] = (array('data' => $data->clear_prior, 'align' => 'center'));
    $row[] = (array('data' => l(t('Edit'), 'admin/config/services/tweet_feed/feeds/edit/' . $data->fid), 'align' => 'center'));
    $row[] = (array('data' => l(t('Delete'), 'admin/config/services/tweet_feed/feeds/delete/' . $data->fid), 'align' => 'center'));
    $row[] = (array('data' => l(t('Import'), 'admin/config/services/tweet_feed/feeds/run/' . $data->fid), 'align' => 'center'));
    $rows[] = $row;
  }

  if (count($rows) == 0) {
    $rows = array(
      array(
        'data' => array(array('align' => 'center', 'colspan' => 9, 'data' => t('THERE ARE CURRENTLY NO CONFIGURED TWITTER FEEDS.')))
      ),
    );
  }
  $output = theme('table', array('header' => $header, 'rows' => $rows));
  return $output;
}

/**
 * Twitter Feed Accounts form callback.
 * 
 * Our settings for for oauth tokens and search queries.
 *
 * @param int $aid
 *   The tweet feed account id (from the configured twitter accounts). Only provided
 *   if we are updating an existing account.
 */
function tweet_feed_account_form($form, &$form_state, $aid = 0) {
  // If we are being passed an aid, then we are updating the form and need to repopulate
  // the values and tell the processor that we are updating and not creating new.
  if (!empty($aid)) {
    $result = db_select('tweet_accounts', 'a')
                ->fields('a')
                ->condition('a.aid', $aid)
                ->execute()
                ->fetchObject();
    $account_name = $result->account_name;
    $consumer_key = $result->consumer_key;
    $consumer_secret = $result->consumer_secret;
    $oauth_token = $result->oauth_token;
    $oauth_token_secret = $result->oauth_token_secret;
  }
  else {
    // Otherwise just initialize the form so we do not have a swath of errors
    $aid = $account_name = $consumer_key = $consumer_secret = NULL;
    $oauth_token = $oauth_token_secret = NULL;
  }

  // Set up our settings form for this particular account (new or update)
  if (!empty($aid)) {
    $form['aid'] = array(
      '#type' => 'hidden',
      '#value' => $aid,
    );
  }
  $form['tweet_feed_account'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tweet Feed Account Information Form'),
    '#description' => t('Provide information about the Twitter account you wish to add. These can be used to get the feeds for any of our configurable options.'),
  );
  $form['tweet_feed_account']['account_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Account Name'),
    '#max_length' => 128,
    '#required' => TRUE,
    '#default_value' => $account_name,
  );
  $form['tweet_feed_account']['consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer Key'),
    '#max_length' => 255,
    '#required' => TRUE,
    '#default_value' => $consumer_key,
  );
  $form['tweet_feed_account']['consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer Secret'),
    '#max_length' => 255,
    '#required' => TRUE,
    '#default_value' => $consumer_secret,
  );
  $form['tweet_feed_account']['oauth_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth Token'),
    '#max_length' => 255,
    '#required' => TRUE,
    '#default_value' => $oauth_token,
  );
  $form['tweet_feed_account']['oauth_token_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth Token Secret'),
    '#max_length' => 255,
    '#required' => TRUE,
    '#default_value' => $oauth_token_secret,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Form'),
  );
  return $form;
}

/**
 * Submit handler for accounts form
 *
 * Take the account information and either save it to a new record or update
 * an existing one
 */
function tweet_feed_account_form_submit($form, &$form_state) {
  // Get a shortcut for our $form_state['values'] array
  $values = $form_state['values'];

  // Define our array of data provided by the form
  $data = array(
    'account_name' => $values['account_name'],
    'consumer_key' => $values['consumer_key'],
    'consumer_secret' => $values['consumer_secret'],
    'oauth_token' => $values['oauth_token'],
    'oauth_token_secret' => $values['oauth_token_secret'],
  );

  // If aid is empty then we're creating a new record. Otherwise we are updating an
  // existing one and need to call the proper drupal_write_record function accordingly.
  if (!empty($values['aid'])) {
    $data['aid'] = $values['aid'];
    $status = drupal_write_record('tweet_accounts', $data, array('aid'));
  }
  else {
    $status = drupal_write_record('tweet_accounts', $data);
  }

  // Go back to the list of accounts when we are done.
  $form_state['redirect'] = 'admin/config/services/tweet_feed/accounts';

  // Set the status message based on the result we get from writing our record.
  switch ($status) {
    case SAVED_NEW:
      drupal_set_message('New Twitter account has been successfully added.', 'status');
      break;
    case SAVED_UPDATED:
      drupal_set_message('Twitter account has been successfully updated.', 'status');
      break;
    case FALSE:
    default:
      drupal_set_message('The Twitter details provided could not be properly saved to the database.', 'error');
      break;
  }
}

/**
 * Twitter Feed Form Callback
 *
 * This is where we configure our feed and the type of feed that it is.
 *
 * @param int $fid
 *   The feed id of the feed being updated (only provided on feed update).
 */
function tweet_feed_feeds_form($form, &$form_state, $fid = 0) {
  // If we are being passed an aid, then we are updating the form and need to repopulate
  // the values and tell the processor that we are updating and not creating new.
  if (!empty($fid)) {
    $result = db_select('tweet_feeds', 'f')
                ->fields('f')
                ->condition('f.fid', $fid)
                ->execute()
                ->fetchObject();
    $fid = $result->fid;
    $aid = $result->aid;
    $feed_name = $result->feed_name;
    $query_type = $result->query_type;
    $timeline_id = $result->timeline_id;
    $search_term = $result->search_term;
    $list_name = $result->list_name;
    $pull_count = $result->pull_count;
    $clear_prior = $result->clear_prior;
    $new_window = $result->new_window;
    $hash_taxonomy = $result->hash_taxonomy;
  }
  else {
    // Otherwise just initialize the form so we do not have a swath of errors
    $fid = $aid = $query_type = $search_term = $list_name = $feed_name = NULL;
    $twitter_user_id = $pull_count = $new_window = $clear_prior = $timeline_id = NULL;
    $hash_taxonomy = NULL;
  }

  // Set up our settings for this particular feed (or update if it already exists)
  if (!empty($fid)) {
    $form['fid'] = array(
      '#type' => 'hidden',
      '#value' => $fid,
    );
  }
  $form['tweet_feed_query_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter Query Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#weight' => 2,
  );
  $form['tweet_feed_query_settings']['feed_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Feed Name'),
    '#description' => t('The name of the feed as it will appear on administrative forms'),
    '#default_value' => $feed_name,
    '#required' => TRUE,
  );

  // Get a list of the configured accounts so we can assign this feed to a particular
  // API account for pulling and allow user to select which one to use.
  $accounts = array();
  $result = db_select('tweet_accounts', 'a')
              ->fields('a', array('aid', 'account_name'))
              ->orderBy('account_name', 'ASC')
              ->execute();
  while($adata = $result->fetchObject()) {
    $accounts[$adata->aid] = $adata->account_name;
  }

  // You must have an account to add a feed. If you don't then everything falls apart.
  // Warn the user here if they are trying to add a feed without an account.
  if (count($accounts) < 1) {
    drupal_set_message('You cannot create a feed until you have added an account. Please add an account here before proceeding to add a feed.', 'error');
    drupal_goto('admin/config/services/tweet_feed/accounts');
  }

  $form['tweet_feed_query_settings']['aid'] = array(
    '#type' => 'select',
    '#title' => t('API Account To Use For Pulling This Feed'),
    '#options' => $accounts,
    '#default_value' => $aid,
    '#required' => TRUE,
  );

  $form['tweet_feed_query_settings']['query_type'] = array(
    '#type' => 'radios',
    '#title' => t('Type of Twitter Query'),
    '#options' => array(
      QUERY_SEARCH => t('Twitter Search'),
      QUERY_TIMELINE => t('User Timeline Display'),
      QUERY_LIST => t('User List Display'),
    ),
    '#required' => TRUE,
    '#default_value' => $query_type,
  );
  $form['tweet_feed_query_settings']['search_term'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Search Term'),
    '#max_length' => 64,
    '#default_value' => $search_term,
    '#states' => array(
      'visible' => array(
        ':input[name="query_type"]' => array('value' => QUERY_SEARCH),
      ),
    ),
  );
  $form['tweet_feed_query_settings']['timeline_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Exact Twitter User ID For Timline Query'),
    '#description' => t('You can get this by going to mytwitterid.com'),
    '#max_length' => 64,
    '#default_value' => $timeline_id,
    '#states' => array(
      'visible' => array(
        ':input[name="query_type"]' => array(
          array('value' => QUERY_TIMELINE),
          array('value' => QUERY_LIST),
        ),
      ),
    ),
  );
  $form['tweet_feed_query_settings']['list_name'] = array(
    '#type' => 'textfield',
    '#title' => t('List name'),
    '#description' => t('Enter the list name exactly as it appears on twitter.com'),
    '#max_length' => 64,
    '#default_value' => $list_name,
    '#states' => array(
      'visible' => array(
        ':input[name="query_type"]' => array('value' => QUERY_LIST),
      ),
    ),
  );
  $form['tweet_feed_query_settings']['pull_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Items to Pull x 100'),
    '#maxlength' => 3,
    '#size' => 3,
    '#description' => t('Twitter limits tweet pulling to 1500 every 15 minutes for Timeline and List queries and 18,000 for searches. Keep this in mind when setting the pull count in conjunction with the frequency of cron/drush runs. To say nothing of PHP memory :)'),
    '#required' => TRUE,
    '#default_value' => $pull_count,
  );
  $form['tweet_feed_query_settings']['new_window'] = array(
    '#type' => 'checkbox',
    '#title' => t('Open tweeted links, hashtags and mentions in a new window.'),
    '#default_value' => $new_window,
  );
  /*
  $form['tweet_feed_query_settings']['hash_taxonomy'] = array(
    '#type' => 'checkbox',
    '#title' => t('Link hashtags to taxonomy terms instead of Twitter.'),
    '#default_value' => $hash_taxonomy,
  );
  */
  $form['tweet_feed_query_settings']['clear_prior'] = array(
    '#type' => 'checkbox',
    '#title' => t('Remove all tweets in this feed prior to import.'),
    '#default_value' => $clear_prior,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit Settings Form'),
    '#weight' => 3,
  );
  return $form;
}

/**
 * Validation callback for the Tweet Feeds feed form
 *
 * So far all we really need to do is make sure the number of pull requests x 100 to
 * not exceed the amount Twitter will give us for the type of query being done. This is
 * 18,000 for searches and 1,500 for Timeline and List queries.
 */
function tweet_feed_feeds_form_validate($form, &$form_state) {
  $pull_count = $form_state['values']['pull_count'];
  $query_type = $form_state['values']['query_type'];

  if ($query_type == QUERY_SEARCH) {
    if ($pull_count > 180) {
      form_set_error('pull_count', t('The pull count for search queries cannot exceed 180 per update interval.'));
    }
  }
  else {
    if ($pull_count > 15) {
      form_set_error('pull_count', t('The pull count for timeline/list queries cannot exceed 15 per update interval.'));
    }
  }
}

/**
 * Submit handler for accounts form
 *
 * Take the account information and either save it to a new record or update
 * an existing one
 */
function tweet_feed_feeds_form_submit($form, &$form_state) {
  // Get a shortcut for our $form_state['values'] array
  $values = $form_state['values'];

  // Define our array of data provided by the form
  $data = array(
    'aid' => $values['aid'],
    'feed_name' => $values['feed_name'],
    'query_type' => $values['query_type'],
    'timeline_id' => $values['timeline_id'],
    'search_term' => $values['search_term'],
    'list_name' => $values['list_name'],
    'pull_count' => $values['pull_count'],
    'clear_prior' => $values['clear_prior'],
    'new_window' => $values['new_window'],
    'hash_taxonomy' => 0,
  );

  // If aid is empty then we're creating a new record. Otherwise we are updating an
  // existing one and need to call the proper drupal_write_record function accordingly.
  if (!empty($values['fid'])) {
    $data['fid'] = $values['fid'];
    $status = drupal_write_record('tweet_feeds', $data, array('fid'));
  }
  else {
    $status = drupal_write_record('tweet_feeds', $data);
  }

  // Go back to the list of accounts when we are done.
  $form_state['redirect'] = 'admin/config/services/tweet_feed/feeds';

  // Set the status message based on the result we get from writing our record.
  switch ($status) {
    case SAVED_NEW:
      drupal_set_message('New Twitter feed has been successfully added.', 'status');
      break;
    case SAVED_UPDATED:
      drupal_set_message('Twitter feed has been successfully updated.', 'status');
      break;
    case FALSE:
    default:
      drupal_set_message('The Twitter feed details provided could not be properly saved to the database.', 'error');
      break;
  }
}

/**
 * General Settings Form
 *
 * A place to set up various global options for all tweet feeds
 */
function tweet_feed_settings_form($form, &$form_state) {
  $form['tweet_feed_get_tweeter_profiles'] = array(
    '#type' => 'checkbox',
    '#title' => t('Save user profile information for each unique tweeter in feeds.'),
    '#description' => t('This will create a node record for every person who tweets in your feed.'),
    '#default_value' => variable_get('tweet_feed_get_tweeter_profiles', 0),
  );
  $form['tweet_feed_fetch_images'] = array(
    '#type' => 'checkbox',
    '#title' => t('Download images that are used in tweets to the local file system.'),
    '#description' => t('This will fetch images so you can re-use them in other content.'),
    '#default_value' => variable_get('tweet_feed_fetch_images', 1),
  );
  $form['tweet_feed_disable_cron'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable running Tweet Feed cron jobs when the general cron is run.'),
    '#description' => t('Doing this will disable Drupal from doing imports during cron runs. You can still import tweets on a cron using Tweet Feed\'s drush commands.'),
    '#default_value' => variable_get('tweet_feed_disable_cron', 0),
  );
 
  return system_settings_form($form);
}

/**
 * The confirm dialog for deleting a feed
 */
function tweet_feed_delete_feed_form($form, &$form_state, $fid) {
  $form['fid'] = array(
    '#type' => 'hidden',
    '#value' => $fid,
  );

  return confirm_form(
    $form,
    t('Are you sure that you wish to delete this feed?'),
    'admin/config/services/tweet_feed/feeds',
    t('There is no way to undo this action once it has been taken. Consider that carefully before proceeding.'),
    t('Delete Feed'),
    t('Cancel')
  );
}

/**
 * Delete feed callback form
 */
function tweet_feed_delete_feed_form_submit($form, &$form_state) {
  $fid = $form_state['values']['fid'];
  if (!empty($fid)) {
    $number_deleted = db_delete('tweet_feeds')
      ->condition('fid', $fid)
      ->execute();
    if ($number_deleted > 0) {
      drupal_set_message('You have successfully deleted the selected feed.', 'status');
      $form_state['redirect'] = 'admin/config/services/tweet_feed/feeds';
    }
    else {
      drupal_set_message('The selected feed could not be deleted.', 'error');
      $form_state['redirect'] = 'admin/config/services/tweet_feed/feeds';
    }
  }
  else {
    drupal_set_message('There was an internal error and the request could not be processed.', 'error');
    $form_state['redirect'] = 'admin/config/services/tweet_feed/feeds';
  }
}

/**
 * The confirm dialog for deleting a users api account credentials
 */
function tweet_feed_delete_account_form($form, &$form_state, $aid) {
  $form['aid'] = array(
    '#type' => 'hidden',
    '#value' => $aid,
  );

  return confirm_form(
    $form,
    t('Are you sure that you wish to delete this account?'),
    'admin/config/services/tweet_feed/accounts',
    t('There is no way to undo this action once it has been taken. Consider that carefully before proceeding.'),
    t('Delete Account'),
    t('Cancel')
  );
}

/**
 * Delete account callback form
 */
function tweet_feed_delete_account_form_submit($form, &$form_state) {
  $aid = $form_state['values']['aid'];
  if (!empty($aid)) {
    $number_deleted = db_delete('tweet_accounts')
      ->condition('aid', $aid)
      ->execute();
    if ($number_deleted > 0) {
      drupal_set_message('You have successfully deleted the selected account.', 'status');
      $form_state['redirect'] = 'admin/config/services/tweet_feed/accounts';
    }
    else {
      drupal_set_message('The selected account could not be deleted.', 'error');
      $form_state['redirect'] = 'admin/config/services/tweet_feed/accounts';
    }
  }
  else {
    drupal_set_message('There was an internal error and the request could not be processed.', 'error');
    $form_state['redirect'] = 'admin/config/services/tweet_feed/accounts';
  }
}

/**
 * Run the Import
 *
 * Handled through the web interface using the batch API
 */
function tweet_feed_run_import($fid) {
  // Get all of the tweets to be imported
  $tweets = tweet_feed_pull_data_from_feed($fid, TRUE);
  // Get the feed info for our display
  $feed = tweet_feed_get_feed_object($fid);
  switch ($feed->query_type) {
    case QUERY_SEARCH:
      $query_type = 'Timeline Search';
      $feed_criteria = $feed->search_term;
      break;
    case QUERY_TIMELINE:
      $query_type = 'User Timeline';
      $feed_criteria = $feed->timeline_id;
      break;
    case QUERY_LIST:
      $query_type = 'User List';
      $feed_criteria = $feed->timeline_id . '/' . $feed->list_name;
      break;
    default:
      $query_type = t('Unknown');
      $feed_criteria = t('Unknown');
  }

  // Now that we have the tweets, put them in the queue
   $batch = array(
    'title' => t('Tweet Feed Import Batch: Feed: ' . $query_type . ': ' . $feed_criteria),
    'init_message' => t('Loading tweets...'),
    'operations' => array(),
    'finished' => 'tweet_feed_run_import_finish',
  );

  foreach($tweets as $key => $tweet) {
    // Initialize our update_node_id
    $update_node_id = 0;
    $hash = NULL;
    // find out if we already have this tweet, if we do, add the update primary key (pk)
    $result = db_select('tweet_hashes', 't')
                ->fields('t', array('nid', 'tid', 'hash'))
                ->condition('t.tid', $tweet->id)
                ->execute();
    if ($result->rowCount() > 0) {
      $tdata = $result->fetchObject();
      $hash = md5(serialize($tweet));
      // If our hashes are equal, we have nothing to update and can move along
      if ($hash == $tdata->hash) {
        continue;
      }
      else {
        $update_node_id = $tdata->nid;
      }
    }
    $batch['operations'][] = array('tweet_feed_save_tweet', array($tweet, $feed, $update_node_id, $hash));
  }

  batch_set($batch);
  batch_process('admin/config/services/tweet_feed/feeds');
}