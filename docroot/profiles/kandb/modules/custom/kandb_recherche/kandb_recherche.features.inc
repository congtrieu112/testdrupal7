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
  $items['solr_index'] = entity_import('search_api_index', '{
    "name" : "Solr index",
    "machine_name" : "solr_index",
    "description" : null,
    "server" : "solr_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "bien", "programme", "promotion" ] },
      "index_directly" : 1,
      "cron_limit" : "-1",
      "fields" : {
        "field_bien_low_tva_price" : { "type" : "integer" },
        "field_bien_statut" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_caracteristique" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_etage" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_nb_pieces" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_orientation" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_prix_tva_20" : { "type" : "integer" },
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
  $items['solr_server'] = entity_import('search_api_server', '{
    "name" : "Solr Server",
    "machine_name" : "solr_server",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/solr",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 1,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "4",
      "http_method" : "AUTO"
    },
    "enabled" : "1"
  }');
  return $items;
}
