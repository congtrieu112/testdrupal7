<?php
/**
 * @file
 * kandb_dossier.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function kandb_dossier_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|dossier|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dossier';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'nos_conseils' => array(
      'weight' => '0',
      'label' => 'above',
      'format' => 'default',
    ),
    'view_menu_nos_conseils' => array(
      'weight' => '0',
      'label' => 'above',
      'format' => 'default',
    ),
  );
  $export['node|dossier|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function kandb_dossier_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'nos_conseils';
  $ds_field->label = 'Block - Nos conseils';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'bean|nos-conseils',
    'block_render' => '2',
  );
  $export['nos_conseils'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'view_menu_nos_conseils';
  $ds_field->label = 'View Menu - Nos conseils';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|kandb_menu_our_advice-block',
    'block_render' => '2',
  );
  $export['view_menu_nos_conseils'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function kandb_dossier_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dossier|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dossier';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'view_menu_nos_conseils',
        1 => 'nos_conseils',
        2 => 'field_dossier_sous_titre',
        3 => 'field_dossier_image',
        4 => 'field_dossier_introduction',
        5 => 'field_dossier_block1_image',
        6 => 'field_dossier_block1_title',
        7 => 'field_dossier_block1_text',
        8 => 'field_dossier_block2_image',
        9 => 'field_dossier_block2_title',
        10 => 'field_dossier_block2_text',
        11 => 'field_dossier_block3_image',
        12 => 'field_dossier_block3_title',
        13 => 'field_dossier_block4_image',
        14 => 'field_dossier_block4_title',
        15 => 'field_dossier_block4_text',
        16 => 'field_dossier_block5_image',
        17 => 'field_dossier_block5_title',
        18 => 'field_dossier_block5_text',
        19 => 'field_dossier_articles_title',
        20 => 'field_articles_block1_title',
        21 => 'field_articles_block1_ref',
        22 => 'field_articles_block2_title',
        23 => 'field_articles_block2_ref',
        24 => 'field_articles_block3_title',
        25 => 'field_articles_block3_ref',
        26 => 'field_dossier_block3_text',
        27 => 'field_dossier_articles_intro',
      ),
    ),
    'fields' => array(
      'view_menu_nos_conseils' => 'ds_content',
      'nos_conseils' => 'ds_content',
      'field_dossier_sous_titre' => 'ds_content',
      'field_dossier_image' => 'ds_content',
      'field_dossier_introduction' => 'ds_content',
      'field_dossier_block1_image' => 'ds_content',
      'field_dossier_block1_title' => 'ds_content',
      'field_dossier_block1_text' => 'ds_content',
      'field_dossier_block2_image' => 'ds_content',
      'field_dossier_block2_title' => 'ds_content',
      'field_dossier_block2_text' => 'ds_content',
      'field_dossier_block3_image' => 'ds_content',
      'field_dossier_block3_title' => 'ds_content',
      'field_dossier_block4_image' => 'ds_content',
      'field_dossier_block4_title' => 'ds_content',
      'field_dossier_block4_text' => 'ds_content',
      'field_dossier_block5_image' => 'ds_content',
      'field_dossier_block5_title' => 'ds_content',
      'field_dossier_block5_text' => 'ds_content',
      'field_dossier_articles_title' => 'ds_content',
      'field_articles_block1_title' => 'ds_content',
      'field_articles_block1_ref' => 'ds_content',
      'field_articles_block2_title' => 'ds_content',
      'field_articles_block2_ref' => 'ds_content',
      'field_articles_block3_title' => 'ds_content',
      'field_articles_block3_ref' => 'ds_content',
      'field_dossier_block3_text' => 'ds_content',
      'field_dossier_articles_intro' => 'ds_content',
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
  $export['node|dossier|default'] = $ds_layout;

  return $export;
}

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
