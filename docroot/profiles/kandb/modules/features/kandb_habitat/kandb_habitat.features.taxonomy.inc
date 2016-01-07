<?php
/**
 * @file
 * kandb_habitat.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kandb_habitat_taxonomy_default_vocabularies() {
  return array(
    'type_de_habitat' => array(
      'name' => 'Type de habitat',
      'machine_name' => 'type_de_habitat',
      'description' => 'Type (Maison, Appartements, Residences gerees)',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
