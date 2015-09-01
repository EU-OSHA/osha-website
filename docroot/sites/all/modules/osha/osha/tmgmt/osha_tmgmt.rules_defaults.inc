<?php

/*
 * @file
 * Contains default rules.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function osha_tmgmt_default_rules_configuration() {
  $data = '{ "osha_tmgmt_add_items_to_cart_retranslate" : {
      "LABEL" : "Add to cart (retranslation)",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "osha_tmgmt", "tmgmt", "rules", "tmgmt_ui" ],
      "USES VARIABLES" : { "nodes" : { "label" : "Nodes", "type" : "list\u003Cnode\u003E" } },
      "DO" : [
        { "tmgmt_get_first_from_node_list" : {
            "USING" : { "list" : [ "nodes" ] },
            "PROVIDE" : { "first_node" : { "first_node" : "Node" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "nodes" ] },
            "ITEM" : { "node" : "Node" },
            "DO" : [
              { "tmgmt_ui_rules_source_add_item_to_cart" : { "plugin" : "entity", "item_type" : "node", "item_id" : "[node:nid]" } }
            ]
          }
        }
      ]
    }
  }';
  $rule = rules_import($data);
  $configs[$rule->name] = $rule;
  $data = '{ "tmgmt_node_ui_tmgmt_nodes_add_items_to_cart" : {
      "LABEL" : "Add to cart",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "tmgmt", "rules", "tmgmt_ui" ],
      "USES VARIABLES" : { "nodes" : { "label" : "Nodes", "type" : "list\u003Cnode\u003E" } },
      "DO" : [
        { "tmgmt_get_first_from_node_list" : {
            "USING" : { "list" : [ "nodes" ] },
            "PROVIDE" : { "first_node" : { "first_node" : "Node" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "nodes" ] },
            "ITEM" : { "node" : "Node" },
            "DO" : [
              { "tmgmt_ui_rules_source_add_item_to_cart" : { "plugin" : "entity", "item_type" : "node", "item_id" : "[node:nid]" } }
            ]
          }
        }
      ]
    }
  }';
  $rule = rules_import($data);
  $configs[$rule->name] = $rule;
  return $configs;
}
