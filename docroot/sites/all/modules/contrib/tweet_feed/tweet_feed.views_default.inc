<?php

function tweet_feed_views_default_views() {
  $view = new view();
  $view->name = 'sample_tweet_feed';
  $view->description = 'Sample views utilizing the functionality of the Tweet Feed module.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sample Tweet Feed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = TRUE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sample Tweet Feed';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Profile Image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';


  /* Field: Content: Tweet Author */
  $handler->display->display_options['fields']['field_tweet_author']['id'] = 'field_tweet_author';
  $handler->display->display_options['fields']['field_tweet_author']['table'] = 'field_data_field_tweet_author';
  $handler->display->display_options['fields']['field_tweet_author']['field'] = 'field_tweet_author';
  $handler->display->display_options['fields']['field_tweet_author']['label'] = '';
  $handler->display->display_options['fields']['field_tweet_author']['element_label_colon'] = FALSE;
  /* Field: Content: Tweet Contents */
  $handler->display->display_options['fields']['field_tweet_contents']['id'] = 'field_tweet_contents';
  $handler->display->display_options['fields']['field_tweet_contents']['table'] = 'field_data_field_tweet_contents';
  $handler->display->display_options['fields']['field_tweet_contents']['field'] = 'field_tweet_contents';
  $handler->display->display_options['fields']['field_tweet_contents']['label'] = '';
  $handler->display->display_options['fields']['field_tweet_contents']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tweet_contents']['type'] = 'emoji_formatter';
  /* Field: Content: Creation Date */
  $handler->display->display_options['fields']['field_tweet_creation_date']['id'] = 'field_tweet_creation_date';
  $handler->display->display_options['fields']['field_tweet_creation_date']['table'] = 'field_data_field_tweet_creation_date';
  $handler->display->display_options['fields']['field_tweet_creation_date']['field'] = 'field_tweet_creation_date';
  $handler->display->display_options['fields']['field_tweet_creation_date']['label'] = '';
  $handler->display->display_options['fields']['field_tweet_creation_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tweet_creation_date']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_tweet_creation_date']['settings'] = array(
    'interval' => '2',
    'interval_display' => 'time ago',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Tweet Feed Id (field_tweet_feed_id) */
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['id'] = 'field_tweet_feed_id_value';
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['table'] = 'field_data_field_tweet_feed_id';
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['field'] = 'field_tweet_feed_id_value';
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'twitter_tweet_feed' => 'twitter_tweet_feed',
  );

  /* Display: By Feed ID */
  $handler = $view->new_display('page', 'By Feed ID', 'page');
  $handler->display->display_options['path'] = 'by-feed-id/%';

  /* Display: By User ID */
  $handler = $view->new_display('page', 'By User ID', 'page_1');
  $handler->display->display_options['display_description'] = 'Searches by user id across all imported feeds';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Tweet Author (field_tweet_author) */
  $handler->display->display_options['arguments']['field_tweet_author_value']['id'] = 'field_tweet_author_value';
  $handler->display->display_options['arguments']['field_tweet_author_value']['table'] = 'field_data_field_tweet_author';
  $handler->display->display_options['arguments']['field_tweet_author_value']['field'] = 'field_tweet_author_value';
  $handler->display->display_options['arguments']['field_tweet_author_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tweet_author_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tweet_author_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tweet_author_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_tweet_author_value']['limit'] = '0';
  $handler->display->display_options['path'] = 'tweet-feed-by-user/%';

  /* Display: By Feed By User Id */
  $handler = $view->new_display('page', 'By Feed By User Id', 'page_2');
  $handler->display->display_options['display_description'] = 'Searches by user id across all specified feed ID';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Tweet Feed Id (field_tweet_feed_id) */
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['id'] = 'field_tweet_feed_id_value';
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['table'] = 'field_data_field_tweet_feed_id';
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['field'] = 'field_tweet_feed_id_value';
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tweet_feed_id_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Tweet Author (field_tweet_author) */
  $handler->display->display_options['arguments']['field_tweet_author_value']['id'] = 'field_tweet_author_value';
  $handler->display->display_options['arguments']['field_tweet_author_value']['table'] = 'field_data_field_tweet_author';
  $handler->display->display_options['arguments']['field_tweet_author_value']['field'] = 'field_tweet_author_value';
  $handler->display->display_options['arguments']['field_tweet_author_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tweet_author_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tweet_author_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tweet_author_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_tweet_author_value']['limit'] = '0';
  $handler->display->display_options['path'] = 'tweet-feed-by-user/%/%';
  
  $views[$view->name] = $view;
  return $views;
}