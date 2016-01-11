<?php
/**
 * @file
 * kandb_homepage.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function kandb_homepage_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|homepage|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'homepage';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'habitat_carousel' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'hp_block_conseil_big' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'hp_block_conseil_small' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'hp_block_offre' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'hp_block_search' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|homepage|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function kandb_homepage_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'habitat_carousel';
  $ds_field->label = 'Habitat Carousel';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'bean' => 'bean',
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|habitat_carrousel-block',
    'block_render' => '3',
  );
  $export['habitat_carousel'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'hp_block_conseil_big';
  $ds_field->label = 'Dossier - Big teaser';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|dossier-block',
    'block_render' => '3',
  );
  $export['hp_block_conseil_big'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'hp_block_conseil_small';
  $ds_field->label = 'Dossier - Small teaser';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|dossier-block_1',
    'block_render' => '3',
  );
  $export['hp_block_conseil_small'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'hp_block_offre';
  $ds_field->label = 'Nos dernières offres';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|nos_dernieres_offres-block',
    'block_render' => '3',
  );
  $export['hp_block_offre'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'hp_block_search';
  $ds_field->label = 'Recherche Simple';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'kandb_recherche|recherche_simple',
    'block_render' => '3',
  );
  $export['hp_block_search'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function kandb_homepage_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|homepage|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'homepage';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'hp_block_search',
        1 => 'hp_block_conseil_big',
        2 => 'hp_block_conseil_small',
        3 => 'hp_block_offre',
        4 => 'habitat_carousel',
        5 => 'field_hp_block_offer_titre',
        6 => 'field_hp_block_offer_stitre',
        7 => 'field_hp_block_conseil_titre',
        8 => 'field_hp_block_conseil_stitre',
        9 => 'field_hp_block_conseil_titre2',
        10 => 'field_hp_block_ref_titre',
        11 => 'field_hp_block_ref_stitre',
        12 => 'field_hp_block_search_img_des',
        13 => 'field_hp_block_search_img_mob',
        14 => 'field_hp_block_search_title',
        15 => 'field_hp_block_search_stitle',
        16 => 'field_hp_block_document',
        17 => 'field_hp_block_cta_habitat',
      ),
    ),
    'fields' => array(
      'hp_block_search' => 'ds_content',
      'hp_block_conseil_big' => 'ds_content',
      'hp_block_conseil_small' => 'ds_content',
      'hp_block_offre' => 'ds_content',
      'habitat_carousel' => 'ds_content',
      'field_hp_block_offer_titre' => 'ds_content',
      'field_hp_block_offer_stitre' => 'ds_content',
      'field_hp_block_conseil_titre' => 'ds_content',
      'field_hp_block_conseil_stitre' => 'ds_content',
      'field_hp_block_conseil_titre2' => 'ds_content',
      'field_hp_block_ref_titre' => 'ds_content',
      'field_hp_block_ref_stitre' => 'ds_content',
      'field_hp_block_search_img_des' => 'ds_content',
      'field_hp_block_search_img_mob' => 'ds_content',
      'field_hp_block_search_title' => 'ds_content',
      'field_hp_block_search_stitle' => 'ds_content',
      'field_hp_block_document' => 'ds_content',
      'field_hp_block_cta_habitat' => 'ds_content',
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
  $export['node|homepage|default'] = $ds_layout;

  return $export;
}
