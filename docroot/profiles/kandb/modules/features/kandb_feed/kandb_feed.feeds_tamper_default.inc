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
  $feeds_tamper->id = 'document_import_communique_de_presse-categorie-rewrite';
  $feeds_tamper->importer = 'document_import_communique_de_presse';
  $feeds_tamper->source = 'Categorie';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'Communiqué de presse',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['document_import_communique_de_presse-categorie-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'document_import_communique_de_presse-lienfichier-find_replace';
  $feeds_tamper->importer = 'document_import_communique_de_presse';
  $feeds_tamper->source = 'LienFichier';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '/ketbmedia/fr/com',
    'replace' => 'public://import/pdf migration folder',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['document_import_communique_de_presse-lienfichier-find_replace'] = $feeds_tamper;

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
  $feeds_tamper->id = 'migration_bien_import-statutlogement-search_term_by_field';
  $feeds_tamper->importer = 'migration_bien_import';
  $feeds_tamper->source = 'StatutLogement';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'status_logement',
    'field_name' => 'field_id_xls',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Search term by field';
  $export['migration_bien_import-statutlogement-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migration_program_import-bureaudeventedepartement-rewrite';
  $feeds_tamper->importer = 'migration_program_import';
  $feeds_tamper->source = 'BureauDeVenteDepartement';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[bureaudeventeadresse] [bureaudeventeville] [bureaudeventedepartement]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['migration_program_import-bureaudeventedepartement-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migration_program_import-labelbbczone2-rewrite';
  $feeds_tamper->importer = 'migration_program_import';
  $feeds_tamper->source = 'LabelBbcZone2';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[labelbbczone1] [labelbbczone2]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['migration_program_import-labelbbczone2-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migration_program_import-reglementationthermiquezone2-rewrite';
  $feeds_tamper->importer = 'migration_program_import';
  $feeds_tamper->source = 'ReglementationThermiqueZone2';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[reglementationthermiquezone1] [reglementationthermiquezone2]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['migration_program_import-reglementationthermiquezone2-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migration_program_video_import-identifiantprogramme-trim';
  $feeds_tamper->importer = 'migration_program_video_import';
  $feeds_tamper->source = 'IdentifiantProgramme';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '"',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['migration_program_video_import-identifiantprogramme-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migration_program_video_import-youtubeid-rewrite';
  $feeds_tamper->importer = 'migration_program_video_import';
  $feeds_tamper->source = 'YoutubeId';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'http://www.youtube.com/watch?v=[youtubeid]',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Rewrite';
  $export['migration_program_video_import-youtubeid-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'migration_program_video_import-youtubeid-trim';
  $feeds_tamper->importer = 'migration_program_video_import';
  $feeds_tamper->source = 'YoutubeId';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '"',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['migration_program_video_import-youtubeid-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-10-search_term_by_field';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '10';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'orientation',
    'field_name' => 'field_id_orientation',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Search term by field';
  $export['parcel_feed_import-10-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-16-find_replace';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '16';
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
  $export['parcel_feed_import-16-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-17-find_replace';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '17';
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
  $export['parcel_feed_import-17-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-19-find_replace';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '19';
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
  $export['parcel_feed_import-19-find_replace'] = $feeds_tamper;

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
  $feeds_tamper->id = 'parcel_feed_import-21-find_replace';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '21';
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
  $export['parcel_feed_import-21-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-21-find_replace_parking';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '21';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '00000000001-',
    'replace' => '-1',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['parcel_feed_import-21-find_replace_parking'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-22-find_replace';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '22';
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
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['parcel_feed_import-22-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-22-find_replace_character';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '22';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '00000000001-',
    'replace' => '-1',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['parcel_feed_import-22-find_replace_character'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-23-find_replace';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '23';
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
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['parcel_feed_import-23-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-23-find_replace_character';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '23';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '00000000001-',
    'replace' => '-1',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['parcel_feed_import-23-find_replace_character'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-3-find_replace';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '3';
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
  $export['parcel_feed_import-3-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-4-cast_to_int';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '4';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Cast to integer';
  $export['parcel_feed_import-4-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-4-find_replace_special_nb_pieces';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '4';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '2/3',
    'replace' => '3',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^2\\/3$/ui',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Find replace';
  $export['parcel_feed_import-4-find_replace_special_nb_pieces'] = $feeds_tamper;

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
  $feeds_tamper->weight = 5;
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
    'vocabulary' => 'nb_chambres',
    'field_name' => 'field_id_nombre_chambre',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Search term by field';
  $export['parcel_feed_import-6-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-7-find_replace_regex';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '7';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/(?:(?!00[1-9])0([0-9]+)|(00[0-9]+))/',
    'replace' => '\\1',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Find replace REGEX';
  $export['parcel_feed_import-7-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-7-search_term_by_field';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '7';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'etage',
    'field_name' => 'field_id_etage',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Search term by field';
  $export['parcel_feed_import-7-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parcel_feed_import-9-find_replace';
  $feeds_tamper->importer = 'parcel_feed_import';
  $feeds_tamper->source = '9';
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
  $export['parcel_feed_import-9-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-envoiavantpremier-find_replace_avant_non';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'EnvoiAvantPremier';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Non',
    'replace' => '0',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Non$/ui',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-envoiavantpremier-find_replace_avant_non'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-envoiavantpremier-find_replace_avant_qui';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'EnvoiAvantPremier';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Oui',
    'replace' => '1',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Oui$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-envoiavantpremier-find_replace_avant_qui'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-grandeperspective-find_replace_perspect_non';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'GrandePerspective';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Non',
    'replace' => '0',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Non$/ui',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-grandeperspective-find_replace_perspect_non'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-grandeperspective-find_replace_perspect_qui';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'GrandePerspective';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Oui',
    'replace' => '1',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Oui$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-grandeperspective-find_replace_perspect_qui'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-lotplan-find_replace_plan_non';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'LotPlan';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Non',
    'replace' => '0',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Non$/ui',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-lotplan-find_replace_plan_non'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-lotplan-find_replace_plan_qui';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'LotPlan';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Oui',
    'replace' => '1',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Oui$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-lotplan-find_replace_plan_qui'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-transferactif-find_replace_actif_non';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'TransferActif';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Non',
    'replace' => '0',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Non$/ui',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-transferactif-find_replace_actif_non'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-transferactif-find_replace_actif_qui';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'TransferActif';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Oui',
    'replace' => '1',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Oui$/ui',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-transferactif-find_replace_actif_qui'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-typedeflux-find_replace_flux_ancien';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'TypeDeFlux';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Ancien',
    'replace' => '0',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Ancien$/ui',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-typedeflux-find_replace_flux_ancien'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-typedeflux-find_replace_flux_nouveau';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'TypeDeFlux';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Nouveau',
    'replace' => '1',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Nouveau$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-typedeflux-find_replace_flux_nouveau'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-typeexport-find_replace';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'TypeExport';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Sélection de programmes Prescripteurs',
    'replace' => '3',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Sélection de programmes Prescripteurs$/ui',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-typeexport-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-typeexport-find_replace_de_prog';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'TypeExport';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Sélection de programmes Grand Public',
    'replace' => '3',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Sélection de programmes Grand Public$/ui',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-typeexport-find_replace_de_prog'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-typeexport-find_replace_prog_grand';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'TypeExport';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Tous les programmes Grand public',
    'replace' => '1',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Tous les programmes Grand public$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-typeexport-find_replace_prog_grand'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'partenaire_import-typeexport-find_replace_prog_prescript';
  $feeds_tamper->importer = 'partenaire_import';
  $feeds_tamper->source = 'TypeExport';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Tous les programmes Prescripteurs',
    'replace' => '2',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Tous les programmes Prescripteurs$/ui',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['partenaire_import-typeexport-find_replace_prog_prescript'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'programme_feed_import-14-search_term_by_field';
  $feeds_tamper->importer = 'programme_feed_import';
  $feeds_tamper->source = '14';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'type_de_programme',
    'field_name' => 'field_id_type_programme',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Search term by field';
  $export['programme_feed_import-14-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'programme_feed_import-2-search_term_by_field';
  $feeds_tamper->importer = 'programme_feed_import';
  $feeds_tamper->source = '2';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'marque_commercialisation',
    'field_name' => 'field_id_marque_comm',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Search term by field';
  $export['programme_feed_import-2-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'programme_feed_import-3-search_term_by_field';
  $feeds_tamper->importer = 'programme_feed_import';
  $feeds_tamper->source = '3';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'zone_activite',
    'field_name' => 'field_id_zone_activite',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Search term by field';
  $export['programme_feed_import-3-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'programme_feed_import-4-search_term_by_field';
  $feeds_tamper->importer = 'programme_feed_import';
  $feeds_tamper->source = '4';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'ville',
    'field_name' => 'field_idk',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Search term by field';
  $export['programme_feed_import-4-search_term_by_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'programme_feed_import-5-search_term_by_field';
  $feeds_tamper->importer = 'programme_feed_import';
  $feeds_tamper->source = '5';
  $feeds_tamper->plugin_id = 'search_term_by_field';
  $feeds_tamper->settings = array(
    'vocabulary' => 'arrondissement',
    'field_name' => 'field_idka',
    'auto_create' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Search term by field';
  $export['programme_feed_import-5-search_term_by_field'] = $feeds_tamper;

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
