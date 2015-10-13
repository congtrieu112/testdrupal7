<?php
/**
 * @file
 * kandb_programme.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kandb_programme_taxonomy_default_vocabularies() {
  return array(
    'marque_commercialisation' => array(
      'name' => 'Marque de Commercialisation',
      'machine_name' => 'marque_commercialisation',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'type_de_programme' => array(
      'name' => 'Type de programme',
      'machine_name' => 'type_de_programme',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'zone_activite' => array(
      'name' => 'Zone d\'activité',
      'machine_name' => 'zone_activite',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
