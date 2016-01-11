<?php
/**
 * @file
 * kandb_homepage.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function kandb_homepage_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hp_block_conseil|node|homepage|form';
  $field_group->group_name = 'group_hp_block_conseil';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bloc conseil',
    'weight' => '6',
    'children' => array(
      0 => 'field_hp_block_conseil_stitre',
      1 => 'field_hp_block_conseil_titre',
      2 => 'field_hp_block_conseil_titre2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Bloc conseil',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-hp-block-conseil field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_hp_block_conseil|node|homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hp_block_offre|node|homepage|form';
  $field_group->group_name = 'group_hp_block_offre';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bloc offre',
    'weight' => '5',
    'children' => array(
      0 => 'field_hp_block_offer_stitre',
      1 => 'field_hp_block_offer_titre',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-hp-block-offre field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_hp_block_offre|node|homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hp_block_ref|node|homepage|form';
  $field_group->group_name = 'group_hp_block_ref';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bloc Référence',
    'weight' => '7',
    'children' => array(
      0 => 'field_hp_block_ref_stitre',
      1 => 'field_hp_block_ref_titre',
      2 => 'field_hp_block_document',
      3 => 'field_hp_block_cta_habitat',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Bloc Référence',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-hp-block-ref field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_hp_block_ref|node|homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hp_block_search|node|homepage|form';
  $field_group->group_name = 'group_hp_block_search';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bloc search',
    'weight' => '3',
    'children' => array(
      0 => 'field_hp_block_search_img_des',
      1 => 'field_hp_block_search_img_mob',
      2 => 'field_hp_block_search_stitle',
      3 => 'field_hp_block_search_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-hp-block-search field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_hp_block_search|node|homepage|form'] = $field_group;

  return $export;
}
