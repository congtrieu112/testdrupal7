<?php
/**
 * @file
 * kandb_bien.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function kandb_bien_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description_option|node|bien|form';
  $field_group->group_name = 'group_description_option';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bien';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description et options',
    'weight' => '5',
    'children' => array(
      0 => 'field_description',
      1 => 'field_caracteristiques',
      2 => 'field_documents',
      3 => 'field_plaquette_commerciale',
      4 => 'field_fiche_renseignement',
      5 => 'field_plan_batiment',
      6 => 'field_kit_fiscal',
      7 => 'field_orientation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-description-option field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_description_option|node|bien|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_summary_bloc|node|bien|form';
  $field_group->group_name = 'group_summary_bloc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bien';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Résumé du bien',
    'weight' => '4',
    'children' => array(
      0 => 'field_type',
      1 => 'field_image_principale',
      2 => 'field_superficie',
      3 => 'field_nb_pieces',
      4 => 'field_nb_chambres',
      5 => 'field_numero_lot',
      6 => 'field_prix_tva_20',
      7 => 'field_etage',
      8 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-summary-bloc field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_summary_bloc|node|bien|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_visite|node|bien|form';
  $field_group->group_name = 'group_visite';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bien';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Visite virtuel',
    'weight' => '6',
    'children' => array(
      0 => 'field_visite_3d',
      1 => 'field_visite_titre',
      2 => 'field_visite_texte',
      3 => 'field_visite_plan_3d',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-visite field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_visite|node|bien|form'] = $field_group;

  return $export;
}
