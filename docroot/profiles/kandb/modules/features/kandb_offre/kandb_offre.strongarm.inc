<?php
/**
 * @file
 * kandb_offre.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kandb_offre_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__offre';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'domain' => array(
          'weight' => '1',
        ),
        'locations' => array(
          'weight' => '30',
        ),
        'metatags' => array(
          'weight' => '40',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__offre'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_offre';
  $strongarm->value = '0';
  $export['language_content_type_offre'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_offre';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_offre'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_offre';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_offre'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_offre';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_offre'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_offre';
  $strongarm->value = '1';
  $export['node_preview_offre'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_offre';
  $strongarm->value = 1;
  $export['node_submitted_offre'] = $strongarm;

  return $export;
}
