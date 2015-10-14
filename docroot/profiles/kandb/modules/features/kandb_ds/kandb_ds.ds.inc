<?php
/**
 * @file
 * kandb_ds.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function kandb_ds_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'search';
  $ds_view_mode->label = 'Search';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['search'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_carrousel_3';
  $ds_view_mode->label = 'Teaser Carrousel 3';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['teaser_carrousel_3'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_carrousel_4';
  $ds_view_mode->label = 'Teaser Carrousel 4';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['teaser_carrousel_4'] = $ds_view_mode;

  return $export;
}
