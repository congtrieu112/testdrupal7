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

  // Exported role: B2B Authentificated User.
  $roles['B2B Authentificated User'] = array(
    'name' => 'B2B Authentificated User',
    'weight' => 8,
    'machine_name' => 'b2b_authentificated_user',
  );

  // Exported role: B2B BackOffice Admin.
  $roles['B2B BackOffice Admin'] = array(
    'name' => 'B2B BackOffice Admin',
    'weight' => 11,
    'machine_name' => 'b2b_backoffice_admin',
  );

  // Exported role: B2B BackOffice Content Contributor.
  $roles['B2B BackOffice Content Contributor'] = array(
    'name' => 'B2B BackOffice Content Contributor',
    'weight' => 10,
    'machine_name' => 'b2b_backoffice_content_contributor',
  );

  // Exported role: B2B BackOffice Content Manager.
  $roles['B2B BackOffice Content Manager'] = array(
    'name' => 'B2B BackOffice Content Manager',
    'weight' => 9,
    'machine_name' => 'b2b_backoffice_content_manager',
  );

  // Exported role: B2C Authentificated User.
  $roles['B2C Authentificated User'] = array(
    'name' => 'B2C Authentificated User',
    'weight' => 7,
    'machine_name' => 'b2c_authentificated_user',
  );

  // Exported role: B2C Not authentificated End user.
  $roles['B2C Not authentificated End user'] = array(
    'name' => 'B2C Not authentificated End user',
    'weight' => 6,
    'machine_name' => 'b2c_not_authentificated_end_user',
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

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
    'machine_name' => '',
  );

  return $roles;
}
