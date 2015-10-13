<?php
/**
 * @file
 * kandb_feed.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function kandb_feed_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-etage-search_term_by_field';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = 'etage';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'etage',
    'field_name' => 'field_id_etage',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Search term by field';
  $export['parcel_feed_import-etage-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-idko-search_term_by_field';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = 'idko';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'orientation',
    'field_name' => 'field_id_orientation',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Search term by field';
  $export['parcel_feed_import-idko-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-idktl-search_term_by_field';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = 'idktl';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'type_de_bien',
    'field_name' => 'field_id_type_bien',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Search term by field';
  $export['parcel_feed_import-idktl-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-nbre_chambres-search_term_by_field';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = 'nbre_chambres';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'nb_chambres',
    'field_name' => 'field_id_nombre_chambre',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Search term by field';
  $export['parcel_feed_import-nbre_chambres-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-nbre_pieces-search_term_by_field';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = 'nbre_pieces';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'nb_pieces',
    'field_name' => 'field_id_nombre_pieces',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Search term by field';
  $export['parcel_feed_import-nbre_pieces-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'programme_feed_import-bdv_city-rewrite';
  $feeds_tamper->importer = 'programme_feed_import';
  $feeds_tamper->source = 'bdv_city';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[bdv_address], [bdv_dept], [bdv_city]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['programme_feed_import-bdv_city-rewrite'] = $feeds_tamper;

  return $export;
}
