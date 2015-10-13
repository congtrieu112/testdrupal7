<?php
/**
 * @file
 * kandb_bien.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kandb_bien_taxonomy_default_vocabularies() {
  return array(
    'etage' => array(
      'name' => 'Etage',
      'machine_name' => 'etage',
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
    'status_logement' => array(
      'name' => 'Statut du logement',
      'machine_name' => 'status_logement',
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
  );
}
