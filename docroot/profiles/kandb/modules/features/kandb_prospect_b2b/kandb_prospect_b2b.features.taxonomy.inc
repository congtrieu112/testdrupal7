<?php
/**
 * @file
 * kandb_prospect_b2b.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kandb_prospect_b2b_taxonomy_default_vocabularies() {
  return array(
    'caracteristiques' => array(
      'name' => 'Caractéristiques',
      'machine_name' => 'caracteristiques',
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
  );
}
