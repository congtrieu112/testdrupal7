<?php
/**
 * @file
 * kandb_dashboard_b2c.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function kandb_dashboard_b2c_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'selection_contact';
  $ds_view_mode->label = 'Selection Contact';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['selection_contact'] = $ds_view_mode;

  return $export;
}
