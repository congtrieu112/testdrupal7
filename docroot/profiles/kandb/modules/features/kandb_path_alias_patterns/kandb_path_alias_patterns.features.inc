<?php
/**
 * @file
 * kandb_path_alias_patterns.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_path_alias_patterns_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
