<?php
/**
 * @file
 * kandb_feed.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kandb_feed_taxonomy_default_vocabularies() {
  return array(
    'ville' => array(
      'name' => 'Ville',
      'machine_name' => 'ville',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
