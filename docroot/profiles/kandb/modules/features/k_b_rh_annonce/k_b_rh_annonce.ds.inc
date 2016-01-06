<?php
/**
 * @file
 * k_b_rh_annonce.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function k_b_rh_annonce_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|rh_annonce|teaser_inline';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'rh_annonce';
  $ds_layout->view_mode = 'teaser_inline';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_annonce_fonction',
        2 => 'field_annonce_profile',
        3 => 'field_annonce_service',
        4 => 'field_annonce_experience',
        5 => 'field_annonce_description',
        6 => 'field_annonce_date_debut',
        7 => 'field_annonce_date_mise_en_ligne',
        8 => 'field_annonce_type_contrat',
        9 => 'field_annonce_ville',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_annonce_fonction' => 'ds_content',
      'field_annonce_profile' => 'ds_content',
      'field_annonce_service' => 'ds_content',
      'field_annonce_experience' => 'ds_content',
      'field_annonce_description' => 'ds_content',
      'field_annonce_date_debut' => 'ds_content',
      'field_annonce_date_mise_en_ligne' => 'ds_content',
      'field_annonce_type_contrat' => 'ds_content',
      'field_annonce_ville' => 'ds_content',
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
  $export['node|rh_annonce|teaser_inline'] = $ds_layout;

  return $export;
}
