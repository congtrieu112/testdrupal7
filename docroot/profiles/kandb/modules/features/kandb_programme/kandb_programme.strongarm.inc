<?php
/**
 * @file
 * kandb_programme.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kandb_programme_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__programme';
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
      'search_programme' => array(
        'custom_settings' => TRUE,
      ),
      'selection_contact' => array(
        'custom_settings' => FALSE,
      ),
      'dossier_big_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_on_bien' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '2',
        ),
        'title' => array(
          'weight' => '11',
        ),
        'path' => array(
          'weight' => '0',
        ),
        'locations' => array(
          'weight' => '15',
        ),
        'redirect' => array(
          'weight' => '14',
        ),
        'domain' => array(
          'weight' => '1',
        ),
      ),
      'display' => array(
        'domain' => array(
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'search_programme' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'teaser_on_bien' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__programme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_programme';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_programme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_programme';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_programme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_programme';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_programme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_programme';
  $strongarm->value = '1';
  $export['node_preview_programme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_programme';
  $strongarm->value = 1;
  $export['node_submitted_programme'] = $strongarm;

  return $export;
}
