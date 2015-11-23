<?php
/**
 * @file
 * kandb_offre.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function kandb_offre_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|offre|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'offre';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'nos_offre' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'view_menu_nos_offres' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|offre|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function kandb_offre_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'nos_offre';
  $ds_field->label = 'Block - Nos offre';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'bean|nos-offers',
    'block_render' => '3',
  );
  $export['nos_offre'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'view_menu_nos_offres';
  $ds_field->label = 'View Menu - Nos offres';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|menu_nos_offres-block',
    'block_render' => '3',
  );
  $export['view_menu_nos_offres'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function kandb_offre_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|offre|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'offre';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'nos_offre',
        2 => 'view_menu_nos_offres',
        3 => 'field_offre_subtitle',
        4 => 'field_offre_view1',
        5 => 'field_offre_title2',
        6 => 'field_offre_subtitle2',
        7 => 'field_offre_view2',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'nos_offre' => 'ds_content',
      'view_menu_nos_offres' => 'ds_content',
      'field_offre_subtitle' => 'ds_content',
      'field_offre_view1' => 'ds_content',
      'field_offre_title2' => 'ds_content',
      'field_offre_subtitle2' => 'ds_content',
      'field_offre_view2' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|offre|default'] = $ds_layout;

  return $export;
}
