<?php
/**
 * @file
 * kandb_programme.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function kandb_programme_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'contact_block_page';
  $ds_field->label = 'Contact block page';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'kandb_contact|contact_block_page',
    'block_render' => '1',
  );
  $export['contact_block_page'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'contact_on_summary';
  $ds_field->label = 'Contact on summary';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'kandb_contact|contact_on_summary',
    'block_render' => '1',
  );
  $export['contact_on_summary'] = $ds_field;

  return $export;
}
