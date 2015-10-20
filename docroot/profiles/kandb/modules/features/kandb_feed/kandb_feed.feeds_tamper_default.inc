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
  $feeds_tamper->id = 'maison_feed_import-10-find_replace';
  $feeds_tamper->importer = 'maison_feed_import';
  $feeds_tamper->source = '10';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => ',',
    'replace' => '.',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['maison_feed_import-10-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'maison_feed_import-11-find_replace';
  $feeds_tamper->importer = 'maison_feed_import';
  $feeds_tamper->source = '11';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => ',',
    'replace' => '.',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['maison_feed_import-11-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'maison_feed_import-12-find_replace';
  $feeds_tamper->importer = 'maison_feed_import';
  $feeds_tamper->source = '12';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => ',',
    'replace' => '.',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['maison_feed_import-12-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-2-search_term_by_field';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '2';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'type_de_bien',
    'field_name' => 'field_id_type_bien',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Search term by field';
  $export['parcel_feed_import-2-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-4-cast_to_int';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '4';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Cast to integer';
  $export['parcel_feed_import-4-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-4-search_term_by_field';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '4';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'nb_pieces',
    'field_name' => 'field_id_nombre_pieces',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Search term by field';
  $export['parcel_feed_import-4-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-5-cast_to_int';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '5';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Cast to integer';
  $export['parcel_feed_import-5-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-5-search_term_by_field';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '5';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'nb_chambres',
    'field_name' => 'field_id_nombre_chambre',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Search term by field';
  $export['parcel_feed_import-5-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-6-cast_to_int';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '6';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Cast to integer';
  $export['parcel_feed_import-6-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-6-search_term_by_field';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '6';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'etage',
    'field_name' => 'field_id_etage',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Search term by field';
  $export['parcel_feed_import-6-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'programme_feed_import-52-rewrite';
  $feeds_tamper->importer = 'programme_feed_import';
  $feeds_tamper->source = '52';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[50], [51], [52]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['programme_feed_import-52-rewrite'] = $feeds_tamper;

  return $export;
}
