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
      'plugin_key' => 'KbFeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => '',
        'accept_invalid_cert' => 0,
        'kb_url' => 'sites/default/files/import/VILLE.TXT',
        'kb_url_type' => '0',
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
      'plugin_key' => 'KbFeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => '',
        'accept_invalid_cert' => 0,
        'kb_url' => 'sites/default/files/import/ARRONDISSEMENT.TXT',
        'kb_url_type' => '0',
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
  $feeds_importer->id = 'document_import';
  $feeds_importer->config = array(
    'name' => 'Document import',
    'description' => 'Import pdf contents from DocBibliotheque.csv',
    'fetcher' => array(
      'plugin_key' => 'KbFeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => 'http',
        'accept_invalid_cert' => 0,
        'kb_url' => 'sites/default/files/import/DocBibliotheque.csv',
        'kb_url_type' => '0',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'KbFeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'IdentifiantDocBibliotheque',
            'target' => 'field_document_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'TitreDuDocument',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Categorie',
            'target' => 'field_document_type',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'DATE',
            'target' => 'field_document_date:start',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Statut',
            'target' => 'status',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Statut',
            'target' => 'sticky',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'LienFichier',
            'target' => 'field_document_file:uri',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'update_non_existent' => 'update',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'document',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  $export['document_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'document_import_communique_de_presse';
  $feeds_importer->config = array(
    'name' => 'Document import communique de presse',
    'description' => 'Import document from CommuniqueDePresse.csv file',
    'fetcher' => array(
      'plugin_key' => 'KbFeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => '',
        'accept_invalid_cert' => 0,
        'kb_url' => 'sites/default/files/import/CommuniqueDePresse.csv',
        'kb_url_type' => '0',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'KbDocCommuniqueCSVParser',
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
            'source' => 'IdentifiantCommunique',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'IdentifiantCommunique',
            'target' => 'field_document_id',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'TitreDuCommunique',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'DATE',
            'target' => 'field_document_date:start',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'ContenuLienTxt',
            'target' => 'field_document_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Contact1AffichageParDefaut',
            'target' => 'field_contact1_display',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Contact1Titre',
            'target' => 'field_contact1_title',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Contact1Texte',
            'target' => 'field_contact1_text',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Contact1Email',
            'target' => 'field_contact1_email',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Contact2AffichageParDefaut',
            'target' => 'field_contact2_display',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Contact2Titre',
            'target' => 'field_contact2_title',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Contact2Texte',
            'target' => 'field_contact2_text',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Contact2Email',
            'target' => 'field_contact2_email',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Statut',
            'target' => 'status',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'LienFichier',
            'target' => 'field_document_file:uri',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Categorie',
            'target' => 'field_document_type',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'Sticky',
            'target' => 'sticky',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'document',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['document_import_communique_de_presse'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'maison_feed_import';
  $feeds_importer->config = array(
    'name' => 'Maison feed import',
    'description' => 'Import maison content type from MAISON.TXT file',
    'fetcher' => array(
      'plugin_key' => 'KbFeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => '',
        'accept_invalid_cert' => 0,
        'kb_url' => 'sites/default/files/import/MAISON.TXT',
        'kb_url_type' => '0',
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
      'plugin_key' => 'KbFeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => '',
        'accept_invalid_cert' => 0,
        'kb_url' => 'sites/default/files/import/ProgrammeVideo.csv',
        'kb_url_type' => '0',
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
      'plugin_key' => 'KbFeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => '',
        'accept_invalid_cert' => 0,
        'kb_url' => 'sites/default/files/import/LOT.TXT',
        'kb_url_type' => '0',
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
        'author' => 0,
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
            'source' => '1',
            'target' => 'field_tva',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => '2',
            'target' => 'field_type',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          5 => array(
            'source' => '3',
            'target' => 'field_prix_tva_20',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => '4',
            'target' => 'field_nb_pieces',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          7 => array(
            'source' => '5',
            'target' => 'field_nb_chambres',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          8 => array(
            'source' => '6',
            'target' => 'field_etage',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          9 => array(
            'source' => '7',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => '8',
            'target' => 'field_superficie',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => '10',
            'target' => 'field_orientation',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          12 => array(
            'source' => '11',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => '16',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => '17',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => '19',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => '21',
            'target' => 'field_caracteristiques',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => '27',
            'target' => 'field_bien_statut',
            'term_search' => '3',
            'autocreate' => 0,
          ),
        ),
        'update_existing' => '2',
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
      'plugin_key' => 'KbFeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => '',
        'accept_invalid_cert' => 0,
        'kb_url' => 'sites/default/files/import/PROGRAMME.TXT',
        'kb_url_type' => '0',
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
            'source' => '2',
            'target' => 'field_marque_comm',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          3 => array(
            'source' => '3',
            'target' => 'field_zone_activite',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          4 => array(
            'source' => '4',
            'target' => 'field_programme_loc_ville',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          5 => array(
            'source' => '5',
            'target' => 'field_programme_loc_arr',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          6 => array(
            'source' => '7',
            'target' => 'field_programme_loc_num',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => '8',
            'target' => 'field_programme_loc_type',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => '9',
            'target' => 'field_programme_loc_rue',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => '10',
            'target' => 'field_programme_loc_cp',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => '12',
            'target' => 'field_trimestre',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => '13',
            'target' => 'field_annee',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => '14',
            'target' => 'field_type_programme',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          13 => array(
            'source' => '18',
            'target' => 'field_programme_loc_long',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => '19',
            'target' => 'field_programme_loc_lat',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => '24',
            'target' => 'field_tva_55',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => '24',
            'target' => 'field_tva',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => '49',
            'target' => 'field_nom_conseiller',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => '50',
            'target' => 'field_espace_vente_adresse',
            'format' => 'plain_text',
          ),
          19 => array(
            'source' => '51',
            'target' => 'field_espace_vente_adresse',
            'format' => 'plain_text',
          ),
          20 => array(
            'source' => '52',
            'target' => 'field_espace_vente_adresse',
            'format' => 'plain_text',
          ),
          21 => array(
            'source' => '56',
            'target' => 'field_espace_vente_horaire',
            'format' => 'plain_text',
          ),
          22 => array(
            'source' => '58',
            'target' => 'field_espace_vente_longitude',
            'unique' => FALSE,
          ),
          23 => array(
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
