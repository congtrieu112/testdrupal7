<?php
/**
 * @file
 * kandb_tmp_content.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kandb_tmp_content_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'node/4';
  $export['site_frontpage'] = $strongarm;

  return $export;
}
