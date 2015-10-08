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
