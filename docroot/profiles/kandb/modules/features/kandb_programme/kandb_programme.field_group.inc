<?php
/**
 * @file
 * kandb_programme.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function kandb_programme_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|programme|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '11',
    'children' => array(
      0 => 'field_photo_conseiller',
      1 => 'field_nom_conseiller',
      2 => 'field_espace_vente_adresse',
      3 => 'field_espace_vente_horaire',
      4 => 'field_espace_vente_longitude',
      5 => 'field_espace_vente_latitude',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contact|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description_option|node|programme|form';
  $field_group->group_name = 'group_description_option';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description et options',
    'weight' => '7',
    'children' => array(
      0 => 'field_options',
      1 => 'field_description',
      2 => 'field_en_quelques_mots',
      3 => 'field_nouveau',
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
  $export['group_description_option|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_documents|node|programme|form';
  $field_group->group_name = 'group_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '10',
    'children' => array(
      0 => 'field_plaquette_commerciale',
      1 => 'field_fiche_renseignement',
      2 => 'field_plan_batiment',
      3 => 'field_kit_fiscal',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-documents field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_documents|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pres_slider_exterieur|node|programme|form';
  $field_group->group_name = 'group_pres_slider_exterieur';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_prestations_slider';
  $field_group->data = array(
    'label' => 'Exterieur',
    'weight' => '23',
    'children' => array(
      0 => 'field_slider_exterieur_titre',
      1 => 'field_slider_exterieur_image',
      2 => 'field_slider_exterieur_desc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pres-slider-exterieur field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pres_slider_exterieur|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pres_slider_interieur|node|programme|form';
  $field_group->group_name = 'group_pres_slider_interieur';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_prestations_slider';
  $field_group->data = array(
    'label' => 'Intérieur',
    'weight' => '24',
    'children' => array(
      0 => 'field_slider_interieur_titre',
      1 => 'field_slider_interieur_image',
      2 => 'field_slider_interieur_desc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pres-slider-interieur field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pres_slider_interieur|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pres_slider_rt2012|node|programme|form';
  $field_group->group_name = 'group_pres_slider_rt2012';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_prestations_slider';
  $field_group->data = array(
    'label' => 'RT 2012',
    'weight' => '26',
    'children' => array(
      0 => 'field_slider_rt2012_titre',
      1 => 'field_slider_rt2012_image',
      2 => 'field_slider_rt2012_desc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pres-slider-rt2012 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pres_slider_rt2012|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pres_slider_securite|node|programme|form';
  $field_group->group_name = 'group_pres_slider_securite';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_prestations_slider';
  $field_group->data = array(
    'label' => 'Sécurité',
    'weight' => '25',
    'children' => array(
      0 => 'field_slider_securite_titre',
      1 => 'field_slider_securite_image',
      2 => 'field_slider_securite_desc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pres-slider-securite field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pres_slider_securite|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prestations_slider|node|programme|form';
  $field_group->group_name = 'group_prestations_slider';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_prestations';
  $field_group->data = array(
    'label' => 'Slider',
    'weight' => '22',
    'children' => array(
      0 => 'group_pres_slider_exterieur',
      1 => 'group_pres_slider_interieur',
      2 => 'group_pres_slider_securite',
      3 => 'group_pres_slider_rt2012',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-prestations-slider field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_prestations_slider|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prestations|node|programme|form';
  $field_group->group_name = 'group_prestations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Prestations',
    'weight' => '9',
    'children' => array(
      0 => 'field_prestations_titre',
      1 => 'field_prestations_sous_titre',
      2 => 'field_prestations_plan_masse_3d',
      3 => 'group_prestations_slider',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-prestations field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_prestations|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quartier|node|programme|form';
  $field_group->group_name = 'group_quartier';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Quartier',
    'weight' => '8',
    'children' => array(
      0 => 'field_quartier_titre',
      1 => 'field_quartier_sous_titre',
      2 => 'field_quartier_video_titre',
      3 => 'field_quartier_video',
      4 => 'field_quartier_video_desc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-quartier field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_quartier|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_summary_bloc|node|programme|form';
  $field_group->group_name = 'group_summary_bloc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Résumé du programme',
    'weight' => '6',
    'children' => array(
      0 => 'field_image_principale',
      1 => 'field_trimestre',
      2 => 'field_annee',
      3 => 'field_tva_55',
      4 => 'title',
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
  $export['group_summary_bloc|node|programme|form'] = $field_group;

  return $export;
}
