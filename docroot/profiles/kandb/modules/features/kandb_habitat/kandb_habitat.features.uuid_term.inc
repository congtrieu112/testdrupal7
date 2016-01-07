<?php
/**
 * @file
 * kandb_habitat.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function kandb_habitat_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Residences gerees',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '025127ef-8a80-448f-af95-13ac3eef1f68',
    'vocabulary_machine_name' => 'type_de_habitat',
  );
  $terms[] = array(
    'name' => 'Appartements',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6cab8b1a-bbb7-4334-8009-1d41e785fa97',
    'vocabulary_machine_name' => 'type_de_habitat',
  );
  $terms[] = array(
    'name' => 'Maison',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e33ca9e6-807c-4b51-bf2d-de290a05461a',
    'vocabulary_machine_name' => 'type_de_habitat',
  );
  return $terms;
}
