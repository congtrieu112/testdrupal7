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
    'weight' => '10',
    'children' => array(
      0 => 'field_espace_vente_adresse',
      1 => 'field_espace_vente_dpt',
      2 => 'field_espace_vente_email',
      3 => 'field_espace_vente_horaire',
      4 => 'field_espace_vente_latitude',
      5 => 'field_espace_vente_longitude',
      6 => 'field_espace_vente_tel',
      7 => 'field_espace_vente_tel2',
      8 => 'field_espace_vente_ville',
      9 => 'field_nom_conseiller',
      10 => 'field_photo_conseiller',
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
    'weight' => '6',
    'children' => array(
      0 => 'field_en_quelques_mots',
      1 => 'field_en_quelques_mots_b2b',
      2 => 'field_nouveau',
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
    'weight' => '9',
    'children' => array(
      0 => 'field_autre_documents',
      1 => 'field_bail_commercial',
      2 => 'field_bon_commande_mobilier',
      3 => 'field_contrat_reservation',
      4 => 'field_etat_des_risques',
      5 => 'field_fiche_renseignement',
      6 => 'field_kit_fiscal',
      7 => 'field_lettre_de_banque',
      8 => 'field_mandat_gestion_locative',
      9 => 'field_plan_batiment',
      10 => 'field_plan_masse_sous_sol',
      11 => 'field_plaquette_commerciale',
      12 => 'field_prestations_programme',
      13 => 'field_visuel_grande_taille',
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
  $field_group->identifier = 'group_localisation|node|programme|form';
  $field_group->group_name = 'group_localisation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Localisation',
    'weight' => '12',
    'children' => array(
      0 => 'field_programme_loc_arr',
      1 => 'field_programme_loc_cp',
      2 => 'field_programme_loc_department',
      3 => 'field_programme_loc_lat',
      4 => 'field_programme_loc_long',
      5 => 'field_programme_loc_num',
      6 => 'field_programme_loc_region',
      7 => 'field_programme_loc_rue',
      8 => 'field_programme_loc_type',
      9 => 'field_programme_loc_ville',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-localisation field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_localisation|node|programme|form'] = $field_group;

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
    'weight' => '39',
    'children' => array(
      0 => 'field_slider_exterieur_desc',
      1 => 'field_slider_exterieur_image',
      2 => 'field_slider_exterieur_titre',
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
    'weight' => '40',
    'children' => array(
      0 => 'field_slider_interieur_desc',
      1 => 'field_slider_interieur_image',
      2 => 'field_slider_interieur_titre',
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
    'label' => 'RT 2012 / BBC',
    'weight' => '42',
    'children' => array(
      0 => 'field_slider_rt2012_bbc',
      1 => 'field_slider_rt2012_desc',
      2 => 'field_slider_rt2012_echelle',
      3 => 'field_slider_rt2012_image',
      4 => 'field_slider_rt2012_titre',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'RT 2012 / BBC',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-pres-slider-rt2012 field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
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
    'weight' => '41',
    'children' => array(
      0 => 'field_slider_securite_desc',
      1 => 'field_slider_securite_image',
      2 => 'field_slider_securite_titre',
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
      2 => 'group_pres_slider_rt2012',
      3 => 'group_pres_slider_securite',
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
    'weight' => '8',
    'children' => array(
      0 => 'field_prestations_plan_masse_3d',
      1 => 'field_prestations_sous_titre',
      2 => 'field_prestations_titre',
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
  $field_group->identifier = 'group_programme_hide|node|programme|form';
  $field_group->group_name = 'group_programme_hide';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Données cachées',
    'weight' => '13',
    'children' => array(
      0 => 'field_marque_comm',
      1 => 'field_program_low_tva_price_max',
      2 => 'field_program_low_tva_price_min',
      3 => 'field_programme_avg_price',
      4 => 'field_programme_flat_available',
      5 => 'field_programme_habiteo_id',
      6 => 'field_programme_min_price',
      7 => 'field_programme_online_date',
      8 => 'field_programme_price_max',
      9 => 'field_programme_price_min',
      10 => 'field_programme_room_max',
      11 => 'field_programme_room_min',
      12 => 'field_programme_statut',
      13 => 'field_programme_stock',
      14 => 'field_type_programme',
      15 => 'field_zone_activite',
      16 => 'field_programme_habiteo_bon_plan',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-programme-hide field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_programme_hide|node|programme|form'] = $field_group;

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
    'weight' => '7',
    'children' => array(
      0 => 'field_quartier_sous_titre',
      1 => 'field_quartier_titre',
      2 => 'field_quartier_video',
      3 => 'field_quartier_video_desc',
      4 => 'field_quartier_video_titre',
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
    'weight' => '5',
    'children' => array(
      0 => 'field_annee',
      1 => 'field_image_principale',
      2 => 'field_trimestre',
      3 => 'field_tva',
      4 => 'field_tva_55',
      5 => 'title',
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
