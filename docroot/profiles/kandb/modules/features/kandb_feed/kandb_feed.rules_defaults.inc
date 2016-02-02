<?php
/**
 * @file
 * kandb_feed.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function kandb_feed_default_rules_configuration() {
  $items = array();
  $items['rules_run_parcel_import_importer'] = entity_import('rules_config', '{ "rules_run_parcel_import_importer" : {
      "LABEL" : "Run parcel import importer",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "kb_import" ],
      "ON" : { "daily_import_importer_finish" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "kb-importer-finish" ],
            "op" : "IN",
            "value" : { "value" : [ "maison_feed_import", "programme_feed_import" ] }
          }
        },
        { "status_of_daily_import" : { "kb_var_name" : "start_daily_import", "kb_var_val" : "1" } },
        { "NOT status_of_daily_import" : { "kb_var_name" : "maison_feed_import_status", "kb_var_val" : "0" } },
        { "status_of_daily_import" : { "kb_var_name" : "programme_feed_import_status", "kb_var_val" : "1" } }
      ],
      "DO" : [
        { "kb_import_run_importer" : { "kb_importer" : "parcel_feed_import" } }
      ]
    }
  }');
  $items['rules_run_programme_import_importer'] = entity_import('rules_config', '{ "rules_run_programme_import_importer" : {
      "LABEL" : "Run programme import importer",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "kb_import" ],
      "ON" : { "daily_import_importer_finish" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "kb-importer-finish" ],
            "op" : "IN",
            "value" : { "value" : [ "city_feed_import", "district_feed_import" ] }
          }
        },
        { "status_of_daily_import" : { "kb_var_name" : "start_daily_import", "kb_var_val" : "1" } },
        { "NOT status_of_daily_import" : { "kb_var_name" : "city_feed_import_status", "kb_var_val" : "0" } },
        { "NOT status_of_daily_import" : { "kb_var_name" : "district_feed_import_status", "kb_var_val" : "0" } }
      ],
      "DO" : [
        { "kb_import_run_importer" : { "kb_importer" : "programme_feed_import" } }
      ]
    }
  }');
  $items['rules_starting_daily_import'] = entity_import('rules_config', '{ "rules_starting_daily_import" : {
      "LABEL" : "Start daily import",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "kb_import" ],
      "ON" : { "starting_daily_import" : [] },
      "IF" : [
        { "status_of_daily_import" : { "kb_var_name" : "start_daily_import", "kb_var_val" : "1" } }
      ],
      "DO" : [
        { "kb_import_run_importer" : { "kb_importer" : "maison_feed_import" } },
        { "kb_import_run_importer" : { "kb_importer" : "city_feed_import" } },
        { "kb_import_run_importer" : { "kb_importer" : "district_feed_import" } }
      ]
    }
  }');
  $items['rules_stop_daily_import'] = entity_import('rules_config', '{ "rules_stop_daily_import" : {
      "LABEL" : "Stop daily import",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "kb_import", "rules" ],
      "ON" : { "daily_import_importer_finish" : [] },
      "IF" : [
        { "status_of_daily_import" : { "kb_var_name" : "start_daily_import", "kb_var_val" : "1" } },
        { "OR" : [
            { "AND" : [
                { "data_is" : { "data" : [ "kb-importer-finish" ], "value" : "programme_feed_import" } },
                { "status_of_daily_import" : { "kb_var_name" : "programme_feed_import_status", "kb_var_val" : "-1" } }
              ]
            },
            { "AND" : [
                { "data_is" : { "data" : [ "kb-importer-finish" ], "value" : "parcel_feed_import" } },
                { "NOT status_of_daily_import" : { "kb_var_name" : "parcel_feed_import_status", "kb_var_val" : "0" } }
              ]
            }
          ]
        }
      ],
      "DO" : [ { "kb_import_finish_daily_import" : [] } ]
    }
  }');
  return $items;
}
