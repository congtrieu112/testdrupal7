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
    'departement' => array(
      'name' => 'Département',
      'machine_name' => 'departement',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'region' => array(
      'name' => 'Région',
      'machine_name' => 'region',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'type_de_habitat' => array(
      'name' => 'Type de habitat',
      'machine_name' => 'type_de_habitat',
      'description' => 'Type (Maison, Appartements, Residences gerees)',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
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
