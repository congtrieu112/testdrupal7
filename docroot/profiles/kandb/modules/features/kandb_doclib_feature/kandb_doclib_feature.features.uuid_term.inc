<?php
/**
 * @file
 * kandb_doclib_feature.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function kandb_doclib_feature_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Résultat estimé au 3ème trimestre',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '0c7291f0-46d5-47aa-aec2-7d7dc40197ca',
    'vocabulary_machine_name' => 'sous_type_document',
  );
  $terms[] = array(
    'name' => 'Résultats annuel',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '20fd7b9c-ac98-47c6-b369-8d251c5b28fa',
    'vocabulary_machine_name' => 'sous_type_document',
  );
  $terms[] = array(
    'name' => 'Autres informations',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '43f300ef-e6f6-41bc-9183-612d13d6bd6f',
    'vocabulary_machine_name' => 'sous_type_document',
  );
  $terms[] = array(
    'name' => 'Résultats du premier trimestre',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '5b8d5eb0-aab2-46ff-a9cb-8dac13423405',
    'vocabulary_machine_name' => 'sous_type_document',
  );
  $terms[] = array(
    'name' => 'Actionnaires de Kaufman & Broad',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => '6b279a6f-5c1b-4cf4-bf14-c08ad494ff52',
    'vocabulary_machine_name' => 'sous_type_document',
  );
  $terms[] = array(
    'name' => 'Rapports',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'a9ce1720-0071-4442-bd5a-7e0571fd2108',
    'vocabulary_machine_name' => 'sous_type_document',
  );
  $terms[] = array(
    'name' => 'Résultats estimés au 3ème trimestre',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bee6cf02-11ed-4b73-be66-15e9b20c60f0',
    'vocabulary_machine_name' => 'sous_type_document',
  );
  $terms[] = array(
    'name' => 'Résultats du premier semestre',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => 'e4d551ff-55ea-4610-8564-8d3431239f64',
    'vocabulary_machine_name' => 'sous_type_document',
  );
  return $terms;
}
