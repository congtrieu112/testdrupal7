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
  $items['rules_run_bien_map_pdf_files'] = entity_import('rules_config', '{ "rules_run_bien_map_pdf_files" : {
      "LABEL" : "Run \\u0022Bien map PDF files\\u0022",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Migration" ],
      "REQUIRES" : [ "kb_import", "rules" ],
      "ON" : { "migration_importer_finish" : [] },
      "IF" : [
        { "status_of_migration" : { "kb_var_name" : "start_migration", "kb_var_val" : "1" } },
        { "data_is" : {
            "data" : [ "kb-migration-importer-finish" ],
            "value" : "migration_program_video_import"
          }
        },
        { "status_of_migration" : {
            "kb_var_name" : "migration_program_video_import_status",
            "kb_var_val" : "1"
          }
        }
      ],
      "DO" : [ { "kb_import_run_importer" : { "kb_importer" : "import_bien_pdf" } } ]
    }
  }');
  $items['rules_run_document_import_communique_de_presse_importer'] = entity_import('rules_config', '{ "rules_run_document_import_communique_de_presse_importer" : {
      "LABEL" : "Run \\u0022Document import communique de presse\\u0022 importer",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Migration" ],
      "REQUIRES" : [ "rules", "kb_import" ],
      "ON" : { "migration_importer_finish" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "kb-migration-importer-finish" ],
            "value" : "document_import"
          }
        },
        { "status_of_migration" : { "kb_var_name" : "start_migration", "kb_var_val" : "1" } }
      ],
      "DO" : [
        { "kb_import_run_importer" : { "kb_importer" : "document_import_communique_de_presse" } }
      ]
    }
  }');
  $items['rules_run_kb_patrimoine_import_importer'] = entity_import('rules_config', '{ "rules_run_kb_patrimoine_import_importer" : {
      "LABEL" : "Run \\u0022Kb Patrimoine Import\\u0022 importer",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Migration" ],
      "REQUIRES" : [ "rules", "kb_import" ],
      "ON" : { "migration_importer_finish" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "kb-migration-importer-finish" ],
            "value" : "migration_program_import"
          }
        },
        { "status_of_migration" : { "kb_var_name" : "start_migration", "kb_var_val" : "1" } },
        { "status_of_migration" : { "kb_var_name" : "migration_program_import_status", "kb_var_val" : "1" } }
      ],
      "DO" : [
        { "kb_import_run_importer" : { "kb_importer" : "kb_patrimoine_import" } }
      ]
    }
  }');
  $items['rules_run_migration_bien_import_importer'] = entity_import('rules_config', '{ "rules_run_migration_bien_import_importer" : {
      "LABEL" : "Run \\u0022Migration bien import\\u0022 importer",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Migration" ],
      "REQUIRES" : [ "rules", "kb_import" ],
      "ON" : { "migration_importer_finish" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "kb-migration-importer-finish" ],
            "op" : "IN",
            "value" : { "value" : [ "migration_program_import", "maison_feed_import" ] }
          }
        },
        { "status_of_migration" : { "kb_var_name" : "start_migration", "kb_var_val" : "1" } },
        { "status_of_migration" : { "kb_var_name" : "migration_program_import_status", "kb_var_val" : "1" } },
        { "status_of_migration" : { "kb_var_name" : "maison_feed_import_status", "kb_var_val" : "1" } }
      ],
      "DO" : [
        { "kb_import_run_importer" : { "kb_importer" : "migration_bien_import" } }
      ]
    }
  }');
  $items['rules_run_migration_program_import_importer'] = entity_import('rules_config', '{ "rules_run_migration_program_import_importer" : {
      "LABEL" : "Run \\u0022Migration program import\\u0022 importer",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Migration" ],
      "REQUIRES" : [ "rules", "kb_import" ],
      "ON" : { "migration_importer_finish" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "kb-migration-importer-finish" ],
            "op" : "IN",
            "value" : { "value" : [ "city_feed_import", "district_feed_import" ] }
          }
        },
        { "status_of_migration" : { "kb_var_name" : "start_migration", "kb_var_val" : "1" } },
        { "status_of_migration" : { "kb_var_name" : "city_feed_import_status", "kb_var_val" : "1" } },
        { "status_of_migration" : { "kb_var_name" : "district_feed_import_status", "kb_var_val" : "1" } }
      ],
      "DO" : [
        { "kb_import_run_importer" : { "kb_importer" : "migration_program_import" } }
      ]
    }
  }');
  $items['rules_run_migration_program_video_import_importer'] = entity_import('rules_config', '{ "rules_run_migration_program_video_import_importer" : {
      "LABEL" : "Run \\u0022Migration program video import\\u0022 importer",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Migration" ],
      "REQUIRES" : [ "kb_import", "rules" ],
      "ON" : { "migration_importer_finish" : [] },
      "IF" : [
        { "status_of_migration" : { "kb_var_name" : "start_migration", "kb_var_val" : "1" } },
        { "data_is" : {
            "data" : [ "kb-migration-importer-finish" ],
            "value" : "parcel_feed_import"
          }
        },
        { "status_of_migration" : { "kb_var_name" : "parcel_feed_import_status", "kb_var_val" : "1" } }
      ],
      "DO" : [
        { "kb_import_run_importer" : { "kb_importer" : "migration_program_video_import" } }
      ]
    }
  }');
  $items['rules_run_parcel_feed_import_importer'] = entity_import('rules_config', '{ "rules_run_parcel_feed_import_importer" : {
      "LABEL" : "Run \\u0022Parcel feed import\\u0022 importer",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Migration" ],
      "REQUIRES" : [ "rules", "kb_import" ],
      "ON" : { "migration_importer_finish" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "kb-migration-importer-finish" ],
            "value" : "migration_bien_import"
          }
        },
        { "status_of_migration" : { "kb_var_name" : "start_migration", "kb_var_val" : "1" } },
        { "status_of_migration" : { "kb_var_name" : "migration_bien_import_status", "kb_var_val" : "1" } }
      ],
      "DO" : [
        { "kb_import_run_importer" : { "kb_importer" : "parcel_feed_import" } }
      ]
    }
  }');
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
  $items['rules_start_migration_import'] = entity_import('rules_config', '{ "rules_start_migration_import" : {
      "LABEL" : "Start migration import",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Migration" ],
      "REQUIRES" : [ "kb_import" ],
      "ON" : { "start_migration_import" : [] },
      "IF" : [
        { "status_of_migration" : { "kb_var_name" : "start_migration", "kb_var_val" : "1" } }
      ],
      "DO" : [
        { "kb_import_run_importer" : { "kb_importer" : "maison_feed_import" } },
        { "kb_import_run_importer" : { "kb_importer" : "city_feed_import" } },
        { "kb_import_run_importer" : { "kb_importer" : "district_feed_import" } },
        { "kb_import_run_importer" : { "kb_importer" : "document_import" } }
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
  $items['rules_stop_bien_migration'] = entity_import('rules_config', '{ "rules_stop_bien_migration" : {
      "LABEL" : "Stop bien migration",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Migration" ],
      "REQUIRES" : [ "kb_import", "rules" ],
      "ON" : { "migration_importer_finish" : [] },
      "IF" : [
        { "status_of_migration" : { "kb_var_name" : "start_migration", "kb_var_val" : "1" } },
        { "OR" : [
            { "AND" : [
                { "data_is" : {
                    "data" : [ "kb-migration-importer-finish" ],
                    "value" : "migration_bien_import"
                  }
                },
                { "status_of_migration" : { "kb_var_name" : "migration_bien_import_status", "kb_var_val" : "-1" } }
              ]
            },
            { "AND" : [
                { "data_is" : {
                    "data" : [ "kb-migration-importer-finish" ],
                    "value" : "import_bien_pdf"
                  }
                },
                { "NOT status_of_migration" : { "kb_var_name" : "import_bien_pdf_status", "kb_var_val" : "0" } }
              ]
            },
            { "AND" : [
                { "data_is" : {
                    "data" : [ "kb-migration-importer-finish" ],
                    "value" : "migration_program_video_import"
                  }
                },
                { "status_of_migration" : {
                    "kb_var_name" : "migration_program_video_import_status",
                    "kb_var_val" : "-1"
                  }
                }
              ]
            },
            { "AND" : [
                { "data_is" : {
                    "data" : [ "kb-migration-importer-finish" ],
                    "value" : "parcel_feed_import"
                  }
                },
                { "status_of_migration" : { "kb_var_name" : "migration_bien_import_status", "kb_var_val" : "-1" } }
              ]
            }
          ]
        }
      ],
      "DO" : [ { "kb_bien_migration_finish" : [] } ]
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
  $items['rules_stop_document_migration'] = entity_import('rules_config', '{ "rules_stop_document_migration" : {
      "LABEL" : "Stop document migration",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Migration" ],
      "REQUIRES" : [ "rules", "kb_import" ],
      "ON" : { "migration_importer_finish" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "kb-migration-importer-finish" ],
            "value" : "document_import_communique_de_presse"
          }
        },
        { "status_of_migration" : { "kb_var_name" : "start_migration", "kb_var_val" : "1" } },
        { "status_of_migration" : {
            "kb_var_name" : "document_import_communique_de_presse_status",
            "kb_var_val" : "1"
          }
        }
      ],
      "DO" : [ { "kb_document_migration_finish" : [] } ]
    }
  }');
  $items['rules_stop_programme_migration'] = entity_import('rules_config', '{ "rules_stop_programme_migration" : {
      "LABEL" : "Stop programme migration",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Migration" ],
      "REQUIRES" : [ "kb_import", "rules" ],
      "ON" : { "migration_importer_finish" : [] },
      "IF" : [
        { "status_of_migration" : { "kb_var_name" : "start_migration", "kb_var_val" : "1" } },
        { "OR" : [
            { "AND" : [
                { "data_is" : {
                    "data" : [ "kb-migration-importer-finish" ],
                    "value" : "migration_program_import"
                  }
                },
                { "status_of_migration" : { "kb_var_name" : "migration_program_import_status", "kb_var_val" : "-1" } }
              ]
            },
            { "AND" : [
                { "data_is" : {
                    "data" : [ "kb-migration-importer-finish" ],
                    "value" : "kb_patrimoine_import"
                  }
                },
                { "NOT status_of_migration" : { "kb_var_name" : "kb_patrimoine_import_status", "kb_var_val" : "0" } }
              ]
            }
          ]
        }
      ],
      "DO" : [ { "kb_programme_migration_finish" : [] } ]
    }
  }');
  return $items;
}
