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
  $feeds_importer->id = 'programme_feed_import';
  $feeds_importer->config = array(
    'name' => 'Programme Feed Import',
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
