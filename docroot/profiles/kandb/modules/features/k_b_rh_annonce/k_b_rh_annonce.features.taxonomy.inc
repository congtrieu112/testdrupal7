<?php
/**
 * @file
 * k_b_rh_annonce.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function k_b_rh_annonce_taxonomy_default_vocabularies() {
  return array(
    'rh_experience_exigee' => array(
      'name' => 'RH Expérience exigée',
      'machine_name' => 'rh_experience_exigee',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'rh_fonction' => array(
      'name' => 'RH Fonction',
      'machine_name' => 'rh_fonction',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'rh_type_contrat' => array(
      'name' => 'RH Type de contrat',
      'machine_name' => 'rh_type_contrat',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
