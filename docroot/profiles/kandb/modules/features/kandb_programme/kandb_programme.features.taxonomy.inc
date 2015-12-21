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
    'arrondissement' => array(
      'name' => 'Arrondissement',
      'machine_name' => 'arrondissement',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'caracteristiques_programme' => array(
      'name' => 'Caractéristiques Programme',
      'machine_name' => 'caracteristiques_programme',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'chauffage' => array(
      'name' => 'Chauffage',
      'machine_name' => 'chauffage',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'departement' => array(
      'name' => 'Département',
      'machine_name' => 'departement',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'marque_commercialisation' => array(
      'name' => 'Marque de Commercialisation',
      'machine_name' => 'marque_commercialisation',
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
    'tva' => array(
      'name' => 'TVA',
      'machine_name' => 'tva',
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
    'type_voie' => array(
      'name' => 'Type de voie',
      'machine_name' => 'type_voie',
      'description' => '',
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
