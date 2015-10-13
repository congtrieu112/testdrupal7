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
            'source' => '1',
            'target' => 'name',
            'unique' => 1,
          ),
          2 => array(
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
            'source' => '1',
            'target' => 'field_idk',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => '2',
            'target' => 'name',
            'unique' => 1,
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
  $feeds_importer->id = 'parcel_feed_import';
  $feeds_importer->config = array(
    'name' => 'Parcel feed import',
    'description' => 'Import bien from TXT file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'KbFeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'idkl',
            'target' => 'field_id_bien',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'idkl',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'idkp',
            'target' => 'field_programme:etid',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'idktl',
            'target' => 'field_type',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          4 => array(
            'source' => 'prix',
            'target' => 'field_prix_tva_20',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'nbre_pieces',
            'target' => 'field_nb_pieces',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          6 => array(
            'source' => 'nbre_chambres',
            'target' => 'field_nb_chambres',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          7 => array(
            'source' => 'etage',
            'target' => 'field_etage',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          8 => array(
            'source' => 'duplex',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'surface',
            'target' => 'field_superficie',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'idko',
            'target' => 'field_orientation',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          11 => array(
            'source' => 'descriptif_fr',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'jardin',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'balcon',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'terrasse',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'parking',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
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
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'KbFeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'idkp',
            'target' => 'field_id_programme',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'idkp',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'delivery_quarter',
            'target' => 'field_trimestre',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'delivery_year',
            'target' => 'field_annee',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'reduced_vat',
            'target' => 'field_tva_55',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'bdv_seller_nom',
            'target' => 'field_nom_conseiller',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'bdv_address',
            'target' => 'field_espace_vente_adresse',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'bdv_dept',
            'target' => 'field_espace_vente_adresse',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'bdv_city',
            'target' => 'field_espace_vente_adresse',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'bdv_hours_fr',
            'target' => 'field_espace_vente_horaire',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'bdv_x',
            'target' => 'field_espace_vente_longitude',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'bdv_y',
            'target' => 'field_espace_vente_latitude',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
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
