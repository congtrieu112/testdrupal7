<?php
/**
 * @file
 * kandb_geolocation.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kandb_geolocation_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smart_ip_allowed_pages';
  $strongarm->value = '';
  $export['smart_ip_allowed_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smart_ip_auto_update';
  $strongarm->value = '1';
  $export['smart_ip_auto_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smart_ip_maxmind_bin_db_auto_update';
  $strongarm->value = '1';
  $export['smart_ip_maxmind_bin_db_auto_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smart_ip_maxmind_bin_edition';
  $strongarm->value = '133';
  $export['smart_ip_maxmind_bin_edition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smart_ip_maxmind_bin_version';
  $strongarm->value = '0';
  $export['smart_ip_maxmind_bin_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smart_ip_maxmind_key';
  $strongarm->value = '';
  $export['smart_ip_maxmind_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smart_ip_maxmind_license';
  $strongarm->value = '';
  $export['smart_ip_maxmind_license'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smart_ip_maxmind_service';
  $strongarm->value = 'country';
  $export['smart_ip_maxmind_service'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smart_ip_roles_to_geolocate';
  $strongarm->value = array(
    0 => 1,
    1 => 2,
  );
  $export['smart_ip_roles_to_geolocate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'smart_ip_save_user_location_creation';
  $strongarm->value = 0;
  $export['smart_ip_save_user_location_creation'] = $strongarm;

  return $export;
}
