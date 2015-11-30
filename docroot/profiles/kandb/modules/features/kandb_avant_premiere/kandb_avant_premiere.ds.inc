<?php
/**
 * @file
 * kandb_avant_premiere.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function kandb_avant_premiere_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|avant_premiere|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'avant_premiere';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_avant_premiere_image_princ',
        1 => 'field_avant_premiere_grande_ouve',
        2 => 'field_avant_premiere_date_debut',
        3 => 'field_avant_premiere_date_fin',
        4 => 'field_avant_premiere_ville',
        5 => 'field_avant_premiere_department',
        6 => 'field_avant_premiere_en_quelques',
        7 => 'field_avant_premiere_description',
      ),
    ),
    'fields' => array(
      'field_avant_premiere_image_princ' => 'ds_content',
      'field_avant_premiere_grande_ouve' => 'ds_content',
      'field_avant_premiere_date_debut' => 'ds_content',
      'field_avant_premiere_date_fin' => 'ds_content',
      'field_avant_premiere_ville' => 'ds_content',
      'field_avant_premiere_department' => 'ds_content',
      'field_avant_premiere_en_quelques' => 'ds_content',
      'field_avant_premiere_description' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|avant_premiere|default'] = $ds_layout;

  return $export;
}
