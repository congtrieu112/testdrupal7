<?php
/**
 * @file
 * kandb_partenaire.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kandb_partenaire_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__partenaire';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'domain' => array(
          'weight' => '11',
        ),
        'locations' => array(
          'weight' => '12',
        ),
        'metatags' => array(
          'weight' => '16',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '14',
        ),
        'redirect' => array(
          'weight' => '13',
        ),
        'xmlsitemap' => array(
          'weight' => '15',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__partenaire'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_partenaire';
  $strongarm->value = '0';
  $export['language_content_type_partenaire'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_partenaire';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_partenaire'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_partenaire';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_partenaire'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_partenaire';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_partenaire'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_partenaire';
  $strongarm->value = '1';
  $export['node_preview_partenaire'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_partenaire';
  $strongarm->value = 1;
  $export['node_submitted_partenaire'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_fields_partenaire';
  $strongarm->value = array(
    0 => 'field_id_partenaire',
  );
  $export['unique_field_fields_partenaire'] = $strongarm;

  return $export;
}
