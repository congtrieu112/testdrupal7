<?php
/**
 * @file
 * kandb_avant_premiere.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kandb_avant_premiere_taxonomy_default_vocabularies() {
  return array(
    'ville_autocomplete' => array(
      'name' => 'Ville autocomplete',
      'machine_name' => 'ville_autocomplete',
      'description' => 'Ville autocomplete for Offre',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
