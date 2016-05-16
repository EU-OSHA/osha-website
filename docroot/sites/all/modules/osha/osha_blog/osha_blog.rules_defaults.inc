<?php
/**
 * @file
 * osha_blog.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function osha_blog_default_rules_configuration() {
  $items = array();
  $items['rules_send_email_on_new_blog_comment'] = entity_import('rules_config', '{ "rules_send_email_on_new_blog_comment" : {
      "LABEL" : "Send Email on New Blog Comment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "osha_blog", "comment" ],
      "ON" : { "comment_insert--comment_node_blog" : { "bundle" : "comment_node_blog" } },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "comment:node" ],
            "type" : "node",
            "bundle" : { "value" : { "blog" : "blog" } }
          }
        }
      ],
      "DO" : [
        { "osha_blog_mail_to_blog_pm" : {
            "comment" : [ "comment" ],
            "subject" : "A new comment on \\u0022[comment:node]\\u0022 was submitted",
            "message" : "A comment on \\u0022[comment:node]\\u0022 has been posted here: [comment:url]\\u003Cbr \\/\\u003E\\r\\n--\\u003Cbr \\/\\u003E\\u003Cbr \\/\\u003E\\u003Cbr \\/\\u003E\\r\\n[comment:body] \\u003Cbr \\/\\u003E\\r\\n--\\u003Cbr \\/\\u003EDelete comment:\\u003Cbr \\/\\u003E[site:url]\\/comment\\/[comment:cid]\\/delete\\u003Cbr \\/\\u003EReply:\\u003Cbr \\/\\u003E[site:url]\\/comment\\/reply\\/[comment:node:nid]\\/[comment:cid]\\/delete"
          }
        }
      ]
    }
  }');
  return $items;
}
