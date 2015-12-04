<?php
/**
 * @file
 * kandb_recherche.features.inc
 */

/**
 * Implements hook_views_api().
 */
function kandb_recherche_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function kandb_recherche_default_search_api_index() {
  $items = array();
  $items['acquia_solr_index'] = entity_import('search_api_index', '{
    "name" : "Acquia Solr Index",
    "machine_name" : "acquia_solr_index",
    "description" : null,
    "server" : "acquia_solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "bien", "programme" ] },
      "index_directly" : 1,
      "cron_limit" : "-1",
      "fields" : {
        "field_bien_low_tva_price" : { "type" : "decimal" },
        "field_bien_statut" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_caracteristique" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_etage" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_nb_pieces" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_orientation" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_prix_tva_20" : { "type" : "decimal" },
        "field_programme:field_caracteristiques" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_programme:field_program_low_tva_price_min" : { "type" : "integer" },
        "field_programme:field_programme_loc_arr" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_programme:field_programme_loc_cp" : { "type" : "text" },
        "field_programme:field_programme_loc_department" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_programme:field_programme_loc_lat" : { "type" : "text" },
        "field_programme:field_programme_loc_long" : { "type" : "text" },
        "field_programme:field_programme_loc_region" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_programme:field_programme_loc_ville" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_programme:field_programme_price_min" : { "type" : "decimal" },
        "field_programme:field_programme_room_max" : { "type" : "decimal" },
        "field_programme:field_programme_room_min" : { "type" : "decimal" },
        "field_programme:field_programme_statut" : { "type" : "boolean" },
        "field_programme:field_tva" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_programme:nid" : { "type" : "integer" },
        "field_programme:status" : { "type" : "integer" },
        "field_programme:title" : { "type" : "text" },
        "field_programme:type" : { "type" : "string" },
        "field_programme:url" : { "type" : "uri" },
        "field_superficie" : { "type" : "decimal" },
        "field_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_programme:title" : true,
              "field_programme:field_programme_loc_cp" : true,
              "field_programme:field_programme_loc_lat" : true,
              "field_programme:field_programme_loc_long" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_programme:title" : true,
              "field_programme:field_programme_loc_cp" : true,
              "field_programme:field_programme_loc_lat" : true,
              "field_programme:field_programme_loc_long" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "title" : true,
              "field_programme:title" : true,
              "field_programme:field_programme_loc_cp" : true,
              "field_programme:field_programme_loc_lat" : true,
              "field_programme:field_programme_loc_long" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_programme:title" : true,
              "field_programme:field_programme_loc_cp" : true,
              "field_programme:field_programme_loc_lat" : true,
              "field_programme:field_programme_loc_long" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_programme:title" : true,
              "field_programme:field_programme_loc_cp" : true,
              "field_programme:field_programme_loc_lat" : true,
              "field_programme:field_programme_loc_long" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function kandb_recherche_default_search_api_server() {
  $items = array();
  $items['acquia_solr'] = entity_import('search_api_server', '{
    "name" : "Acquia Solr",
    "machine_name" : "acquia_solr",
    "description" : "",
    "class" : "acquia_search_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "euwest1-c7.acquia-search.com",
      "port" : "80",
      "path" : "\\/solr\\/HQTW-93305",
      "edismax" : 0,
      "modify_acquia_connection" : 0,
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 1,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO"
    },
    "enabled" : "1"
  }');
  return $items;
}
