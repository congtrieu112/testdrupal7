<?php
/**
 * @file
 * kandb_prospect_b2b.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function kandb_prospect_b2b_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_detail_prospect|node|prospect_b2b|form';
  $field_group->group_name = 'group_detail_prospect';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'prospect_b2b';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Détails du prospect',
    'weight' => '4',
    'children' => array(
      0 => 'field_prospect_nom',
      1 => 'field_prospect_prenom',
      2 => 'field_prospect_adresse',
      3 => 'field_prospect_code_postal',
      4 => 'field_prospect_ville',
      5 => 'field_prospect_pays',
      6 => 'field_prospect_telephone',
      7 => 'field_prospect_mail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-detail-prospect field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_detail_prospect|node|prospect_b2b|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_detail_souhait|node|prospect_b2b|form';
  $field_group->group_name = 'group_detail_souhait';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'prospect_b2b';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Détails de ses souhaits',
    'weight' => '5',
    'children' => array(
      0 => 'field_souhait_regions_dpt_ville',
      1 => 'field_souhait_type_bien',
      2 => 'field_souhait_nb_pieces',
      3 => 'field_souhait_livraison',
      4 => 'field_souhait_budget',
      5 => 'field_souhait_tva',
      6 => 'field_souhait_caracteristiques',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-detail-souhait field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_detail_souhait|node|prospect_b2b|form'] = $field_group;

  return $export;
}
