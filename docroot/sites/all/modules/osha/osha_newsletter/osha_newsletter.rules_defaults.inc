<?php
/**
 * @file
 * osha_newsletter.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function osha_newsletter_default_rules_configuration() {
  $items = array();
  $items['rules_add_to_newsletter'] = entity_import('rules_config', '{ "rules_add_to_newsletter" : {
      "LABEL" : "Add to newsletter",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "osha" ],
      "REQUIRES" : [ "osha_newsletter" ],
      "USES VARIABLES" : { "nodes" : { "label" : "Nodes", "type" : "list\\u003Cnode\\u003E" } },
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "nodes" ] },
            "ITEM" : { "node" : "Current list item" },
            "DO" : [
              { "osha_newsletter_rules_add_to_newsletter_action" : { "node" : [ "node" ] } }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
