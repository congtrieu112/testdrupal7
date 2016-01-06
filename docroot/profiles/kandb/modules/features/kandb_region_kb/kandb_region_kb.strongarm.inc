<?php
/**
 * @file
 * kandb_region_kb.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kandb_region_kb_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__region_kb';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'selection_contact' => array(
        'custom_settings' => FALSE,
      ),
      'dossier_big_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'search' => array(
        'custom_settings' => FALSE,
      ),
      'selection' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_carrousel_3' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_carrousel_4' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_on_bien' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'domain' => array(
          'weight' => '1',
        ),
        'locations' => array(
          'weight' => '5',
        ),
        'metatags' => array(
          'weight' => '6',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'redirect' => array(
          'weight' => '2',
        ),
        'xmlsitemap' => array(
          'weight' => '3',
        ),
      ),
      'display' => array(
        'domain' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__region_kb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_region_kb';
  $strongarm->value = '0';
  $export['language_content_type_region_kb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_region_kb';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_region_kb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_region_kb';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_region_kb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_region_kb';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_region_kb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_region_kb';
  $strongarm->value = '1';
  $export['node_preview_region_kb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_region_kb';
  $strongarm->value = 1;
  $export['node_submitted_region_kb'] = $strongarm;

  return $export;
}
