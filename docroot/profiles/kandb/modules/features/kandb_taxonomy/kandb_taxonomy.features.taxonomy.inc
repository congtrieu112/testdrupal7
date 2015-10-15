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
    'caracteristiques' => array(
      'name' => 'Caractéristiques',
      'machine_name' => 'caracteristiques',
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
    'etage' => array(
      'name' => 'Etage',
      'machine_name' => 'etage',
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
    'nb_chambres' => array(
      'name' => 'Nombre de chambres',
      'machine_name' => 'nb_chambres',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'nb_pieces' => array(
      'name' => 'Nombres de pièces',
      'machine_name' => 'nb_pieces',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'orientation' => array(
      'name' => 'Orientation',
      'machine_name' => 'orientation',
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
    'status_logement' => array(
      'name' => 'Statut du logement',
      'machine_name' => 'status_logement',
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
    'type_de_bien' => array(
      'name' => 'Type de bien',
      'machine_name' => 'type_de_bien',
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
