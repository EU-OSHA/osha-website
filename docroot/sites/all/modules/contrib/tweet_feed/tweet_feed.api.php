<?php
/**
 * @file
 * Describe hooks provided by the Tweet Feed module.
 */

/**
 * Alter twitter feed tweet node before saving.
 *
 * You can populate custom fields in the new node and handle data unsupported
 * natively by the module.
 *
 * @param $node
 *   the node about to be created.
 *
 * @param $tweet
 *   the raw tweet data retreived from the twitter api.
 *
 */
function hook_tweet_feed_tweet_save_alter(&$node, &$tweet) {
  // This example populates a custom field with the name of the original tweet
  // user:
  $node->retweeted_from[$node->language][] = $tweet->retweeted_status->user->name;
}
