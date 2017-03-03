<?php

function tweet_feed_create_entities_and_bundles() {
  $types = array();
  $types[] =
    array(
      'type' => 'twitter_tweet_feed',
      'name' => 'Twitter Tweet Feed',
      'base' => 'node_content',
      'module' => 'tweet_feed_types',
      'description' => 'These are the Tweets collected by the Tweet Feed module.',
      'help' => '',
      'has_title' => '1',
      'title_label' => 'Tweet Title',
      'custom' => '1',
      'modified' => '0',
      'locked' => '0',
      'disabled' => '0',
      'orig_type' => 'twitter_tweet_feed',
      'disabled_changed' => '',
    );
  
  $types[] =
    array(
      'type' => 'twitter_user_profile',
      'name' => 'Twitter User Profile',
      'base' => 'node_content',
      'module' => 'tweet_feed_types',
      'description' => 'The profile of a person who has made a tweet that has been index by your configuration of Tweet Feed. Includes relevant images and Tweet data.',
      'help' => '',
      'has_title' => '1',
      'title_label' => 'Name',
      'custom' => '1',
      'modified' => '0',
      'locked' => '0',
      'disabled' => '0',
      'orig_type' => 'twitter_user_profile',
      'disabled_changed' => '',
    );
  
  foreach ($types as $type) {
    if (node_type_load($type['type']) == FALSE) {
      $type = node_type_set_defaults($type);
      node_type_save($type);
    }
  }
  
  if (taxonomy_vocabulary_machine_name_load('hashtag_terms') == FALSE) {
    taxonomy_vocabulary_save((object) array(
      'name' => 'Hashtag Terms',
      'description' => '',
      'machine_name' => 'hashtag_terms'
    ));
  }

  if (taxonomy_vocabulary_machine_name_load('user_mention_terms') == FALSE) {
    taxonomy_vocabulary_save((object) array(
      'name' => 'User Mention Terms',
      'description' => 'All of the users\'s mentioned in tweets.',
      'machine_name' => 'user_mention_terms'
    ));
  }

  $node = node_type_load('twitter_user_profile');
  node_add_body_field($node, 'Description');

  if (field_info_field('field_profile_image') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('uri_scheme' => 'public','default_image' => '0',),'field_name' => 'field_profile_image','type' => 'image','module' => 'image','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed','1' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_profile_image', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Profile Image','required' => '0','widget' => array('active' => '1','module' => 'image','type' => 'image_image','weight' => '7','settings' => array('preview_image_style' => 'thumbnail','progress_indicator' => 'throbber',),),'settings' => array('file_extensions' => 'png gif jpg jpeg','file_directory' => '','max_filesize' => '','alt_field' => '0','title_field' => '0','max_resolution' => '','min_resolution' => '','default_image' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'image','weight' => '0','settings' => array('image_style' => '','image_link' => '',),'module' => 'image',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','field_name' => 'field_profile_image','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }
  if (field_info_instance('node', 'field_profile_image', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Profile Image','required' => '0','widget' => array('active' => '1','module' => 'image','type' => 'image_image','weight' => '8','settings' => array('preview_image_style' => 'thumbnail','progress_indicator' => 'throbber',),),'settings' => array('file_extensions' => 'png gif jpg jpeg','file_directory' => '','max_filesize' => '','alt_field' => '0','title_field' => '0','max_resolution' => '','min_resolution' => '','default_image' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'image','settings' => array('image_style' => '','image_link' => '',),'module' => 'image','weight' => '1',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','field_name' => 'field_profile_image','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_geographic_coordinates') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_geographic_coordinates','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_geographic_coordinates', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Geographic Coordinates','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '16','settings' => array('size' => '60',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','weight' => '1','settings' => array(),'module' => 'text',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_geographic_coordinates','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_geographic_place') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_geographic_place','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_geographic_place', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Geographic Place','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '18','settings' => array('size' => '60',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','weight' => '2','settings' => array(),'module' => 'text',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_geographic_place','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_link_to_tweet') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_link_to_tweet','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_link_to_tweet', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Link To Tweet','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '19','settings' => array('size' => '60',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','weight' => '3','settings' => array(),'module' => 'text',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_link_to_tweet','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_tweet_author') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_tweet_author','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_tweet_author', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Tweet Author','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '3','settings' => array('size' => '60',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','weight' => '4','settings' => array(),'module' => 'text',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_tweet_author','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_tweet_author_id') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_tweet_author_id','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_tweet_author_id', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Tweet Author ID','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '6','settings' => array('size' => '60',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','weight' => '5','settings' => array(),'module' => 'text',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_tweet_author_id','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_tweet_contents') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array(),'field_name' => 'field_tweet_contents','type' => 'text_long','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_tweet_contents', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Tweet Contents','required' => '0','widget' => array('weight' => '9','type' => 'text_textarea','module' => 'text','active' => '1','settings' => array('rows' => '3',),),'settings' => array('text_processing' => '1','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'emoji_formatter','weight' => '6','settings' => array(),'module' => 'tweet_feed',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_tweet_contents','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_tweet_creation_date') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('todate' => '','granularity' => array('year' => 'year','month' => 'month','day' => 'day','hour' => 'hour','minute' => 'minute',),'tz_handling' => 'site','timezone_db' => 'UTC',),'field_name' => 'field_tweet_creation_date','type' => 'datetime','module' => 'date','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_tweet_creation_date', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Creation Date','required' => '0','widget' => array('active' => '1','module' => 'date','type' => 'date_text','weight' => '15','settings' => array('increment' => '15','input_format' => 'm/d/Y - H:i:s','input_format_custom' => '','label_position' => 'above','text_parts' => array(),'year_range' => '-3:+3',),),'settings' => array('default_value' => 'now','default_value_code' => '','default_value2' => 'same','default_value_code2' => '','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'date_default','weight' => '7','settings' => array('format_type' => 'long','multiple_number' => '','multiple_from' => '','multiple_to' => '','fromto' => 'both',),'module' => 'date',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','field_name' => 'field_tweet_creation_date','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_tweet_feed_id') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array(),'field_name' => 'field_tweet_feed_id','type' => 'number_integer','module' => 'number','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_tweet_feed_id', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Tweet Feed Id','required' => '0','widget' => array('weight' => '1','type' => 'number','module' => 'number','active' => '0','settings' => array(),),'settings' => array('min' => '','max' => '','prefix' => '','suffix' => '','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'number_integer','weight' => '8','settings' => array('thousand_separator' => ' ','decimal_separator' => '.','scale' => '0','prefix_suffix' => '1',),'module' => 'number',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_tweet_feed_id','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_tweet_id') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_tweet_id','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_tweet_id', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Tweet ID','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '2','settings' => array('size' => '60',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','weight' => '9','settings' => array(),'module' => 'text',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_tweet_id','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_tweet_source') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_tweet_source','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_tweet_source', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Source','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '17','settings' => array('size' => '60',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','weight' => '10','settings' => array(),'module' => 'text',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_tweet_source','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_twitter_favorite_count') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array(),'field_name' => 'field_twitter_favorite_count','type' => 'number_integer','module' => 'number','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_twitter_favorite_count', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Favorite Count','required' => '0','widget' => array('active' => '0','module' => 'number','type' => 'number','weight' => '14','settings' => array(),),'settings' => array('min' => '','max' => '','prefix' => '','suffix' => '','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'number_integer','weight' => '11','settings' => array('thousand_separator' => ' ','decimal_separator' => '.','scale' => '0','prefix_suffix' => '1',),'module' => 'number',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_twitter_favorite_count','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_twitter_hashtags') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('target_type' => 'taxonomy_term','handler' => 'base','handler_settings' => array('target_bundles' => array('hashtag_terms' => 'hashtag_terms',),'sort' => array('type' => 'none',),'behaviors' => array('views-select-list' => array('status' => '0',),),),),'field_name' => 'field_twitter_hashtags','type' => 'entityreference','module' => 'entityreference','active' => '1','locked' => '0','cardinality' => '-1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_twitter_hashtags', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Hashtags Used','required' => '0','widget' => array('weight' => '11','type' => 'entityreference_autocomplete_tags','module' => 'entityreference','active' => '1','settings' => array('match_operator' => 'CONTAINS','size' => '60','path' => '',),),'settings' => array('behaviors' => array('taxonomy-index' => array('status' => '1',),'prepopulate' => array('status' => '0',),),'user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'entityreference_label','weight' => '12','settings' => array('link' => '',),'module' => 'entityreference',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','default_value_function' => '','field_name' => 'field_twitter_hashtags','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_twitter_retweet_count') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array(),'field_name' => 'field_twitter_retweet_count','type' => 'number_integer','module' => 'number','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_twitter_retweet_count', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Retweet Count','required' => '0','widget' => array('active' => '0','module' => 'number','type' => 'number','weight' => '13','settings' => array(),),'settings' => array('min' => '','max' => '','prefix' => '','suffix' => '','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'number_integer','weight' => '13','settings' => array('thousand_separator' => ' ','decimal_separator' => '.','scale' => '0','prefix_suffix' => '1',),'module' => 'number',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_twitter_retweet_count','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_tweet_user_mentions') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array(),'field_name' => 'field_tweet_user_mentions','type' => 'tweet_feed_user_mention','module' => 'tweet_feed','active' => '1','locked' => '0','cardinality' => '-1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_tweet_user_mentions', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'User Mentions','widget' => array('weight' => '10','type' => 'tweet_feed_textfield','module' => 'tweet_feed','active' => '0','settings' => array(),),'settings' => array('user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'tweet_feed_user_mentions','weight' => '14','settings' => array(),'module' => 'tweet_feed',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'required' => '0','description' => '','default_value' => '','field_name' => 'field_tweet_user_mentions','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_tweet_linked_images') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('uri_scheme' => 'public','default_image' => '0',),'field_name' => 'field_tweet_linked_images','type' => 'image','module' => 'image','active' => '1','locked' => '0','cardinality' => '-1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_tweet_linked_images', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Linked Images','widget' => array('weight' => '8','type' => 'image_image','module' => 'image','active' => '1','settings' => array('progress_indicator' => 'throbber','preview_image_style' => 'thumbnail',),),'settings' => array('file_directory' => '','file_extensions' => 'png gif jpg jpeg','max_filesize' => '','max_resolution' => '','min_resolution' => '','alt_field' => '0','title_field' => '0','default_image' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'image','settings' => array('image_style' => '','image_link' => '',),'module' => 'image','weight' => '15',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'required' => '0','description' => '','field_name' => 'field_tweet_linked_images','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_twitter_mentions_in_tweet') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('target_type' => 'taxonomy_term','handler' => 'base','handler_settings' => array('target_bundles' => array('user_mention_terms' => 'user_mention_terms',),'sort' => array('type' => 'none',),'behaviors' => array('views-select-list' => array('status' => '0',),),),),'field_name' => 'field_twitter_mentions_in_tweet','type' => 'entityreference','module' => 'entityreference','active' => '1','locked' => '0','cardinality' => '-1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_twitter_mentions_in_tweet', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Mentions In Tweet','widget' => array('weight' => '12','type' => 'entityreference_autocomplete_tags','module' => 'entityreference','active' => '1','settings' => array('match_operator' => 'CONTAINS','size' => '60','path' => '',),),'settings' => array('behaviors' => array('taxonomy-index' => array('status' => '1',),'prepopulate' => array('status' => '0',),),'user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'entityreference_label','settings' => array('link' => '',),'module' => 'entityreference','weight' => '16',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'required' => '0','description' => '','default_value' => '','default_value_function' => '','field_name' => 'field_twitter_mentions_in_tweet','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_tweet_author_name') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_tweet_author_name','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_tweet_author_name', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Tweet Author Name','widget' => array('weight' => '4','type' => 'text_textfield','module' => 'text','active' => '1','settings' => array('size' => '60',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','settings' => array(),'module' => 'text','weight' => '17',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'required' => '0','description' => '','default_value' => '','field_name' => 'field_tweet_author_name','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_tweet_author_verified') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('allowed_values' => array('0' => '','1' => '',),'allowed_values_function' => '',),'field_name' => 'field_tweet_author_verified','type' => 'list_boolean','module' => 'list','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_tweet_feed','1' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_tweet_author_verified', 'twitter_tweet_feed') == NULL) {
    $instance = array('label' => 'Tweet Author Verified','widget' => array('weight' => '5','type' => 'options_onoff','module' => 'options','active' => '1','settings' => array('display_label' => '1',),),'settings' => array('user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'list_default','settings' => array(),'module' => 'list','weight' => '18',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'required' => '0','description' => '','default_value' => array('0' => array('value' => '0',),),'field_name' => 'field_tweet_author_verified','entity_type' => 'node','bundle' => 'twitter_tweet_feed','deleted' => '0',);
    field_create_instance($instance);
  }
  if (field_info_instance('node', 'field_tweet_author_verified', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Tweet Author Verified','widget' => array('weight' => '3','type' => 'options_onoff','module' => 'options','active' => '1','settings' => array('display_label' => '1',),),'settings' => array('user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'list_default','settings' => array(),'module' => 'list','weight' => '18',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'required' => '0','description' => '','default_value' => array('0' => array('value' => '0',),),'field_name' => 'field_tweet_author_verified','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_banner_image') == FALSE) {
    $field = array('entity_types' => array(),'settings' => array('default_image' => '0','uri_scheme' => 'public',),'translatable' => '0','field_name' => 'field_banner_image','type' => 'image','module' => 'image','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'basic_page','1' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_banner_image', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Banner Image','required' => '0','widget' => array('active' => '1','module' => 'image','type' => 'image_image','weight' => '11','settings' => array('preview_image_style' => 'thumbnail','progress_indicator' => 'throbber',),),'settings' => array('file_extensions' => 'png gif jpg jpeg','file_directory' => '','max_filesize' => '','alt_field' => '0','title_field' => '0','max_resolution' => '','min_resolution' => '','default_image' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'image','settings' => array('image_style' => '','image_link' => '',),'module' => 'image','weight' => '4',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','field_name' => 'field_banner_image','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_background_color') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_background_color','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_background_color', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Background Color','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '13','settings' => array('size' => '6',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','settings' => array(),'module' => 'text','weight' => '2',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_background_color','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_background_image') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('uri_scheme' => 'public','default_image' => '0',),'field_name' => 'field_background_image','type' => 'image','module' => 'image','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_background_image', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Background Image','required' => '0','widget' => array('active' => '1','module' => 'image','type' => 'image_image','weight' => '7','settings' => array('preview_image_style' => 'thumbnail','progress_indicator' => 'throbber',),),'settings' => array('file_extensions' => 'png gif jpg jpeg','file_directory' => '','max_filesize' => '','alt_field' => '0','title_field' => '0','max_resolution' => '','min_resolution' => '','default_image' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'image','settings' => array('image_style' => '','image_link' => '',),'module' => 'image','weight' => '3',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','field_name' => 'field_background_image','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_link_color') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_link_color','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_link_color', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Link Color','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '16','settings' => array('size' => '6',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','settings' => array(),'module' => 'text','weight' => '5',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_link_color','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_profile_text_color') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_profile_text_color','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_profile_text_color', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Profile Text Color','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '15','settings' => array('size' => '6',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','settings' => array(),'module' => 'text','weight' => '6',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_profile_text_color','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_sidebar_border_color') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_sidebar_border_color','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_sidebar_border_color', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Sidebar Border Color','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '17','settings' => array('size' => '6',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','settings' => array(),'module' => 'text','weight' => '7',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_sidebar_border_color','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_sidebar_fill_color') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_sidebar_fill_color','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_sidebar_fill_color', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Sidebar Fill Color','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '18','settings' => array('size' => '6',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','settings' => array(),'module' => 'text','weight' => '8',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_sidebar_fill_color','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_twitter_a_profile_url') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_twitter_a_profile_url','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_twitter_a_profile_url', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Profile Url','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '5','settings' => array('size' => '60',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','settings' => array(),'module' => 'text','weight' => '9',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_twitter_a_profile_url','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_twitter_a_screen_name') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_twitter_a_screen_name','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_twitter_a_screen_name', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Twitter Screen Name','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '2','settings' => array('size' => '60',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','settings' => array(),'module' => 'text','weight' => '10',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_twitter_a_screen_name','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_twitter_favorites_count') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array(),'field_name' => 'field_twitter_favorites_count','type' => 'number_integer','module' => 'number','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_twitter_favorites_count', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Favorites Count','required' => '0','widget' => array('active' => '0','module' => 'number','type' => 'number','weight' => '12','settings' => array(),),'settings' => array('min' => '','max' => '','prefix' => '','suffix' => '','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'number_integer','settings' => array('thousand_separator' => ' ','decimal_separator' => '.','scale' => '0','prefix_suffix' => '1',),'module' => 'number','weight' => '11',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_twitter_favorites_count','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_twitter_followers') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array(),'field_name' => 'field_twitter_followers','type' => 'number_integer','module' => 'number','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_twitter_followers', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Followers','required' => '0','widget' => array('active' => '0','module' => 'number','type' => 'number','weight' => '9','settings' => array(),),'settings' => array('min' => '','max' => '','prefix' => '','suffix' => '','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'number_integer','settings' => array('thousand_separator' => ' ','decimal_separator' => '.','scale' => '0','prefix_suffix' => '1',),'module' => 'number','weight' => '12',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_twitter_followers','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_twitter_following') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array(),'field_name' => 'field_twitter_following','type' => 'number_integer','module' => 'number','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_twitter_following', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Following','required' => '0','widget' => array('active' => '0','module' => 'number','type' => 'number','weight' => '10','settings' => array(),),'settings' => array('min' => '','max' => '','prefix' => '','suffix' => '','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'number_integer','settings' => array('thousand_separator' => ' ','decimal_separator' => '.','scale' => '0','prefix_suffix' => '1',),'module' => 'number','weight' => '13',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_twitter_following','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_twitter_location') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_twitter_location','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_twitter_location', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Location','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '4','settings' => array('size' => '60',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','settings' => array(),'module' => 'text','weight' => '14',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_twitter_location','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_twitter_profile_url') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_twitter_profile_url','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_twitter_profile_url', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Display Url','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '6','settings' => array('size' => '60',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','settings' => array(),'module' => 'text','weight' => '15',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_twitter_profile_url','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_twitter_tweet_count') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array(),'field_name' => 'field_twitter_tweet_count','type' => 'number_integer','module' => 'number','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_twitter_tweet_count', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Tweet Count','required' => '0','widget' => array('active' => '0','module' => 'number','type' => 'number','weight' => '14','settings' => array(),),'settings' => array('min' => '','max' => '','prefix' => '','suffix' => '','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'number_integer','settings' => array('thousand_separator' => ' ','decimal_separator' => '.','scale' => '0','prefix_suffix' => '1',),'module' => 'number','weight' => '16',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_twitter_tweet_count','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  if (field_info_field('field_twitter_user_id') == FALSE) {
    $field = array('translatable' => '0','entity_types' => array(),'settings' => array('max_length' => '255',),'field_name' => 'field_twitter_user_id','type' => 'text','module' => 'text','active' => '1','locked' => '0','cardinality' => '1','deleted' => '0','bundles' => array('node' => array('0' => 'twitter_user_profile',),),);
    $field = field_create_field($field);
  }
  if (field_info_instance('node', 'field_twitter_user_id', 'twitter_user_profile') == NULL) {
    $instance = array('label' => 'Twitter User ID','required' => '0','widget' => array('active' => '1','module' => 'text','type' => 'text_textfield','weight' => '1','settings' => array('size' => '60',),),'settings' => array('text_processing' => '0','user_register_form' => '',),'display' => array('default' => array('label' => 'above','type' => 'text_default','settings' => array(),'module' => 'text','weight' => '17',),'teaser' => array('type' => 'hidden','label' => 'above','settings' => array(),'weight' => '0',),),'description' => '','default_value' => '','field_name' => 'field_twitter_user_id','entity_type' => 'node','bundle' => 'twitter_user_profile','deleted' => '0',);
    field_create_instance($instance);
  }

  // Field groupings for the fields we are exporting.
  // Prepare storage with ctools.
  ctools_include('export');


  cache_clear_all();
}
