<?php
/**
 * @file
 * kandb_feed.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function kandb_feed_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'city_feed_import';
  $feeds_importer->config = array(
    'name' => 'City feed import',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => '',
        'accept_invalid_cert' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'KbFeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 1,
        'total_column' => '5',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => '0',
            'target' => 'field_idk',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => '0',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => '1',
            'target' => 'name',
            'unique' => 0,
          ),
          3 => array(
            'source' => '4',
            'target' => 'field_code_departement',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'ville',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['city_feed_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'district_feed_import';
  $feeds_importer->config = array(
    'name' => 'District feed import',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => '',
        'accept_invalid_cert' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'KbFeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 1,
        'total_column' => '5',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => '0',
            'target' => 'field_idka',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => '0',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => '1',
            'target' => 'field_idk',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => '2',
            'target' => 'name',
            'unique' => 0,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'arrondissement',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['district_feed_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'maison_feed_import';
  $feeds_importer->config = array(
    'name' => 'Maison feed import',
    'description' => 'Import maison content type from MAISON.TXT file',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => '',
        'accept_invalid_cert' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'KbFeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 1,
        'total_column' => '17',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '0',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => '0',
            'target' => 'field_maison_idkm',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => '0',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => '1',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => '2',
            'target' => 'field_maison_point_fort',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => '4',
            'target' => 'field_maison_nb_etage',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => '5',
            'target' => 'field_maison_nb_pieces',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => '6',
            'target' => 'field_maison_nb_chambres',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => '7',
            'target' => 'field_maison_nb_salle_bain',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => '8',
            'target' => 'field_maison_description',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => '10',
            'target' => 'field_maison_surface_sejour',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => '11',
            'target' => 'field_maison_surface_cuisine',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => '12',
            'target' => 'field_maison_surface_totale',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => '13',
            'target' => 'field_maison_url_visite:url',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => '14',
            'target' => 'field_maison_pos_ammenagement',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'maison',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['maison_feed_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'migration_program_video_import';
  $feeds_importer->config = array(
    'name' => 'Migration program video import',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => '',
        'accept_invalid_cert' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'KbEncodingCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'KbFeedsMiNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'related_importer' => 'programme_feed_import',
        'mappings' => array(
          0 => array(
            'source' => 'IdentifiantProgramme',
            'target' => 'field_id_programme',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'IdentifiantProgramme',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'YoutubeId',
            'target' => 'field_quartier_video',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'programme',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['migration_program_video_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'parcel_feed_import';
  $feeds_importer->config = array(
    'name' => 'Parcel feed import',
    'description' => 'Import bien from TXT file',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => '',
        'accept_invalid_cert' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'KbFeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 1,
        'total_column' => '32',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'KbFeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '0',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => '0',
            'target' => 'field_id_bien',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => '0',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => '1',
            'target' => 'field_programme',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => '2',
            'target' => 'field_type',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          4 => array(
            'source' => '3',
            'target' => 'field_prix_tva_20',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => '4',
            'target' => 'field_nb_pieces',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          6 => array(
            'source' => '5',
            'target' => 'field_nb_chambres',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          7 => array(
            'source' => '6',
            'target' => 'field_etage',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          8 => array(
            'source' => '7',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => '8',
            'target' => 'field_superficie',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => '10',
            'target' => 'field_orientation',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          11 => array(
            'source' => '11',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => '16',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => '17',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => '19',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => '21',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => '27',
            'target' => 'field_bien_statut',
            'term_search' => '3',
            'autocreate' => 0,
          ),
        ),
        'update_existing' => '1',
        'update_non_existent' => 'update',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'bien',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['parcel_feed_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'programme_feed_import';
  $feeds_importer->config = array(
    'name' => 'Programme feed import',
    'description' => 'Import programme from TXT file',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => '',
        'accept_invalid_cert' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'KbFeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 1,
        'total_column' => '92',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'KbFeedsMiNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'related_importer' => 'migration_program_video_import',
        'mappings' => array(
          0 => array(
            'source' => '0',
            'target' => 'field_id_programme',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => '0',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => '12',
            'target' => 'field_trimestre',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => '13',
            'target' => 'field_annee',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => '24',
            'target' => 'field_tva_55',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => '49',
            'target' => 'field_nom_conseiller',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => '50',
            'target' => 'field_espace_vente_adresse',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => '51',
            'target' => 'field_espace_vente_adresse',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => '52',
            'target' => 'field_espace_vente_adresse',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => '56',
            'target' => 'field_espace_vente_horaire',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => '58',
            'target' => 'field_espace_vente_longitude',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => '59',
            'target' => 'field_espace_vente_latitude',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'programme',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['programme_feed_import'] = $feeds_importer;

  return $export;
}
