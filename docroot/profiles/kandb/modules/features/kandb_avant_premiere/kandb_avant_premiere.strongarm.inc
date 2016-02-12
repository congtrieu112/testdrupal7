<?php
/**
 * @file
 * kandb_avant_premiere.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kandb_avant_premiere_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__avant_premiere';
  $strongarm->value = array(
    'view_modes' => array(
      'selection' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
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
          'weight' => '0',
        ),
        'locations' => array(
          'weight' => '15',
        ),
        'metatags' => array(
          'weight' => '12',
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
          'weight' => '16',
        ),
      ),
      'display' => array(
        'domain' => array(
          'default' => array(
            'weight' => 1,
          ),
          'selection' => array(
            'weight' => 1,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__avant_premiere'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_avant_premiere';
  $strongarm->value = '0';
  $export['language_content_type_avant_premiere'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_avant_premiere';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_avant_premiere'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_avant_premiere';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_avant_premiere'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_avant_premiere';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_avant_premiere'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_avant_premiere';
  $strongarm->value = '1';
  $export['node_preview_avant_premiere'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_avant_premiere';
  $strongarm->value = 1;
  $export['node_submitted_avant_premiere'] = $strongarm;

  return $export;
}
