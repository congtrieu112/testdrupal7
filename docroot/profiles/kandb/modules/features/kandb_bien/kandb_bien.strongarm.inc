<?php
/**
 * @file
 * kandb_bien.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kandb_bien_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__bien';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'alternate' => array(
        'custom_settings' => TRUE,
      ),
      'thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'featured' => array(
        'custom_settings' => TRUE,
      ),
      'search' => array(
        'custom_settings' => TRUE,
      ),
      'selection' => array(
        'custom_settings' => TRUE,
      ),
      'teaser_carrousel_3' => array(
        'custom_settings' => TRUE,
      ),
      'teaser_carrousel_4' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_on_bien' => array(
        'custom_settings' => FALSE,
      ),
      'selection_contact' => array(
        'custom_settings' => FALSE,
      ),
      'dossier_big_teaser' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '2',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '0',
        ),
        'locations' => array(
          'weight' => '11',
        ),
        'redirect' => array(
          'weight' => '10',
        ),
        'domain' => array(
          'weight' => '1',
        ),
        'xmlsitemap' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'domain' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '44',
            'visible' => FALSE,
          ),
          'selection' => array(
            'visible' => TRUE,
            'weight' => 1,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__bien'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_bien';
  $strongarm->value = '0';
  $export['language_content_type_bien'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_bien';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_bien'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_bien';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_bien'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_bien';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_bien'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_bien';
  $strongarm->value = '1';
  $export['node_preview_bien'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_bien';
  $strongarm->value = 1;
  $export['node_submitted_bien'] = $strongarm;

  return $export;
}
