<?php
/**
 * @file
 * kandb_region.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kandb_region_taxonomy_default_vocabularies() {
  return array(
    'region' => array(
      'name' => 'Région',
      'machine_name' => 'region',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
