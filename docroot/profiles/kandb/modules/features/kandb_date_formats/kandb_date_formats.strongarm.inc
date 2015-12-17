<?php
/**
 * @file
 * kandb_date_formats.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kandb_date_formats_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_date_format_dd_mm_yyyy';
  $strongarm->value = 'd.m.Y';
  $export['date_format_date_format_dd_mm_yyyy'] = $strongarm;

  return $export;
}
