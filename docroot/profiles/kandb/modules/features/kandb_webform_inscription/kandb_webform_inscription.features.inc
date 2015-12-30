<?php
/**
 * @file
 * kandb_webform_inscription.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_webform_inscription_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
