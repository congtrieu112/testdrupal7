<?php
/**
 * @file
 * kandb_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kandb_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'departement' => array(
      'name' => 'Département',
      'machine_name' => 'departement',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
