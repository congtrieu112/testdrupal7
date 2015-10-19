<?php
/**
 * @file
 * kandb_dossier.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function kandb_dossier_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'dossier_big_teaser';
  $ds_view_mode->label = 'Dossier - Big Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['dossier_big_teaser'] = $ds_view_mode;

  return $export;
}
