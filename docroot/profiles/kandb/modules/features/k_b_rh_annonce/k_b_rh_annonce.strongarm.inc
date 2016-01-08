<?php
/**
 * @file
 * k_b_rh_annonce.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function k_b_rh_annonce_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__rh_annonce';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'teaser_inline' => array(
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
          'weight' => '7',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '2',
        ),
        'redirect' => array(
          'weight' => '3',
        ),
        'xmlsitemap' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(
        'domain' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'teaser_inline' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__rh_annonce'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_rh_annonce';
  $strongarm->value = '0';
  $export['language_content_type_rh_annonce'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_rh_annonce';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_rh_annonce'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_rh_annonce';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_rh_annonce'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_rh_annonce';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_rh_annonce'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_rh_annonce';
  $strongarm->value = '1';
  $export['node_preview_rh_annonce'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_rh_annonce';
  $strongarm->value = 1;
  $export['node_submitted_rh_annonce'] = $strongarm;

  return $export;
}
