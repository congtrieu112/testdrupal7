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

  return $export;
}
