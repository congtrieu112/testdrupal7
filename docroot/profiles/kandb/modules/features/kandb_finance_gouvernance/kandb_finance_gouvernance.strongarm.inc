<?php
/**
 * @file
 * kandb_finance_gouvernance.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kandb_finance_gouvernance_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__finance_gouvernance';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'domain' => array(
          'weight' => '0',
        ),
        'locations' => array(
          'weight' => '12',
        ),
        'metatags' => array(
          'weight' => '4',
        ),
        'title' => array(
          'weight' => '6',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'redirect' => array(
          'weight' => '1',
        ),
        'xmlsitemap' => array(
          'weight' => '2',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__finance_gouvernance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_finance_gouvernance';
  $strongarm->value = '0';
  $export['language_content_type_finance_gouvernance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_finance_gouvernance';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_finance_gouvernance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_finance_gouvernance';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_finance_gouvernance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_finance_gouvernance';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_finance_gouvernance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_finance_gouvernance';
  $strongarm->value = '1';
  $export['node_preview_finance_gouvernance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_finance_gouvernance';
  $strongarm->value = 1;
  $export['node_submitted_finance_gouvernance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'weight_default_finance_gouvernance';
  $strongarm->value = '0';
  $export['weight_default_finance_gouvernance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'weight_enabled_finance_gouvernance';
  $strongarm->value = '1';
  $export['weight_enabled_finance_gouvernance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'weight_menu_finance_gouvernance';
  $strongarm->value = '0';
  $export['weight_menu_finance_gouvernance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'weight_range_finance_gouvernance';
  $strongarm->value = '20';
  $export['weight_range_finance_gouvernance'] = $strongarm;

  return $export;
}
