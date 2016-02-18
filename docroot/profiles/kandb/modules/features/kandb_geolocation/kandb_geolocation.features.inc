<?php
/**
 * @file
 * kandb_geolocation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_geolocation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
