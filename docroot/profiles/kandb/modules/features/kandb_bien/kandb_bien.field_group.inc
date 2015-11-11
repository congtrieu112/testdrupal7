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
  $field_group->identifier = 'group_bien_hide|node|bien|form';
  $field_group->group_name = 'group_bien_hide';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bien';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Données cachées',
    'weight' => '10',
    'children' => array(
      0 => 'field_bien_habiteo_id',
      1 => 'field_tva',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Données cachées',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-bien-hide field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_bien_hide|node|bien|form'] = $field_group;

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
    'weight' => '4',
    'children' => array(
      0 => 'field_bien_plan',
      1 => 'field_caracteristique',
      2 => 'field_description',
      3 => 'field_documents',
      4 => 'field_orientation',
      5 => 'field_caracteristique_jardin',
      6 => 'field_caracteristique_balcon',
      7 => 'field_caracteristique_terrasse',
      8 => 'field_caracteristique_parking',
      9 => 'field_caracteristique_box',
      10 => 'field_caracteristique_cave',
      11 => 'field_parking_description',
      12 => 'field_cave_description',
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
    'weight' => '3',
    'children' => array(
      0 => 'field_etage',
      1 => 'field_image_principale',
      2 => 'field_nb_chambres',
      3 => 'field_nb_pieces',
      4 => 'field_numero_lot',
      5 => 'field_type',
      6 => 'field_superficie',
      7 => 'field_prix_tva_20',
      8 => 'field_bien_low_tva_price',
      9 => 'title',
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
    'weight' => '5',
    'children' => array(
      0 => 'field_visite_3d',
      1 => 'field_visite_plan_3d',
      2 => 'field_visite_texte',
      3 => 'field_visite_titre',
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
