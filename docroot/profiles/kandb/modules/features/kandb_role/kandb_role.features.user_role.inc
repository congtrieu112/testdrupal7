<?php
/**
 * @file
 * kandb_role.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function kandb_role_user_default_roles() {
  $roles = array();

  // Exported role: Administrateur Général.
  $roles['Administrateur Général'] = array(
    'name' => 'Administrateur Général',
    'weight' => 12,
    'machine_name' => 'administrateur_general',
  );

  // Exported role: Administrateur Régional.
  $roles['Administrateur Régional'] = array(
    'name' => 'Administrateur Régional',
    'weight' => 13,
    'machine_name' => 'administrateur_regional',
  );

  // Exported role: Conseiller(ère) en gestion de patrimoine.
  $roles['Conseiller(ère) en gestion de patrimoine'] = array(
    'name' => 'Conseiller(ère) en gestion de patrimoine',
    'weight' => 14,
    'machine_name' => 'conseiller_gestion_patrimoine',
  );

  // Exported role: Particulier.
  $roles['Particulier'] = array(
    'name' => 'Particulier',
    'weight' => 15,
    'machine_name' => 'particulier',
  );

  return $roles;
}
