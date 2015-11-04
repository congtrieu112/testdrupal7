<?php
/**
 * @file
 * kandb_bien.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function kandb_bien_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|bien|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'bien';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'appartements_disponibles' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'default',
    ),
    'contact_block_with_sales_office' => array(
      'weight' => '6',
      'label' => 'inline',
      'format' => 'default',
    ),
    'price_tva_max' => array(
      'weight' => '1',
      'label' => 'inline',
      'format' => 'default',
    ),
    'price_tva_min' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
    ),
    'service_links' => array(
      'weight' => '2',
      'label' => 'inline',
      'format' => 'default',
    ),
    'contact_on_summary' => array(
      'weight' => '3',
      'label' => 'inline',
      'format' => 'default',
    ),
  );
  $export['node|bien|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function kandb_bien_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'appartements_disponibles';
  $ds_field->label = 'Appartements disponibles';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'kandb_bien|appartements_disponibles',
    'block_render' => '2',
  );
  $export['appartements_disponibles'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'contact_block_with_sales_office';
  $ds_field->label = 'Contact block with sales office';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'kandb_contact|contact_block_with_sales_office',
    'block_render' => '3',
  );
  $export['contact_block_with_sales_office'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'price_tva_max';
  $ds_field->label = 'Price tva max';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array();
  $export['price_tva_max'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'price_tva_min';
  $ds_field->label = 'Price tva min';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array();
  $export['price_tva_min'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'service_links';
  $ds_field->label = 'Service links';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'service_links|service_links',
    'block_render' => '3',
  );
  $export['service_links'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function kandb_bien_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|bien|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'bien';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'price_tva_min',
        1 => 'price_tva_max',
        2 => 'service_links',
        3 => 'contact_on_summary',
        4 => 'appartements_disponibles',
        5 => 'field_programme',
        6 => 'contact_block_with_sales_office',
      ),
    ),
    'fields' => array(
      'price_tva_min' => 'ds_content',
      'price_tva_max' => 'ds_content',
      'service_links' => 'ds_content',
      'contact_on_summary' => 'ds_content',
      'appartements_disponibles' => 'ds_content',
      'field_programme' => 'ds_content',
      'contact_block_with_sales_office' => 'ds_content',
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
  $export['node|bien|full'] = $ds_layout;

  return $export;
}
