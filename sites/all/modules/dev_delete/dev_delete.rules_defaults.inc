<?php
/**
 * @file
 * dev_delete.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dev_delete_default_rules_configuration() {
  $items = array();
  $items['rules_add_today_s_date_to_library_importer'] = entity_import('rules_config', '{ "rules_add_today_s_date_to_library_importer" : {
      "LABEL" : "Add today\\u0027s date to Library importer",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "feeds" ],
      "ON" : { "feeds_import_library_importer" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "library_document" : "library_document" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-import-date" ], "value" : "now" } }
      ]
    }
  }');
  return $items;
}
