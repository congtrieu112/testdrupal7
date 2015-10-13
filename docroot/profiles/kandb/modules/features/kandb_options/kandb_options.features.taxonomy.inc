<?php
/**
 * @file
 * kandb_options.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kandb_options_taxonomy_default_vocabularies() {
  return array(
    'status_logement' => array(
      'name' => 'Statut du logement',
      'machine_name' => 'status_logement',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
