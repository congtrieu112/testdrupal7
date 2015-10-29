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
