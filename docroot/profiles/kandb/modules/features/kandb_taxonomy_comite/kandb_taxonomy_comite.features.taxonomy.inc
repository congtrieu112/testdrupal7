<?php
/**
 * @file
 * kandb_taxonomy_comite.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kandb_taxonomy_comite_taxonomy_default_vocabularies() {
  return array(
    'comite' => array(
      'name' => 'Comité',
      'machine_name' => 'comite',
      'description' => 'A simple taxonomy called "Comité" (machine name : comite), with a criteria to display complete description of the CT Finance Gou',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
