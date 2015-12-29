<?php
/**
 * @file
 * kandb_doclib_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kandb_doclib_feature_taxonomy_default_vocabularies() {
  return array(
    'sous_type_document' => array(
      'name' => 'Sous-type Document',
      'machine_name' => 'sous_type_document',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'type_de_document' => array(
      'name' => 'Type de document',
      'machine_name' => 'type_de_document',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
