<?php
/**
 * @file
 * kandb_path_alias_patterns.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kandb_path_alias_patterns_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_dossier_pattern';
  $strongarm->value = 'nos-conseils/[node:title]';
  $export['pathauto_node_dossier_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_standard_page_pattern';
  $strongarm->value = '[node:title]';
  $export['pathauto_node_standard_page_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_transliterate';
  $strongarm->value = 1;
  $export['pathauto_transliterate'] = $strongarm;

  return $export;
}