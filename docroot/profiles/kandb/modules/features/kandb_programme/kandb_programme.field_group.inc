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
    'weight' => '9',
    'children' => array(
      0 => 'field_espace_vente_adresse',
      1 => 'field_espace_vente_email',
      2 => 'field_espace_vente_horaire',
      3 => 'field_espace_vente_latitude',
      4 => 'field_espace_vente_longitude',
      5 => 'field_espace_vente_tel',
      6 => 'field_espace_vente_tel2',
      7 => 'field_nom_conseiller',
      8 => 'field_photo_conseiller',
      9 => 'field_espace_vente_label',
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
    'weight' => '5',
    'children' => array(
      0 => 'field_caracteristique_chauffage',
      1 => 'field_caracteristique_etages',
      2 => 'field_caracteristiques',
      3 => 'field_en_quelques_mots',
      4 => 'field_en_quelques_mots_b2b',
      5 => 'field_nouveau',
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
    'weight' => '8',
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
    'weight' => '11',
    'children' => array(
      0 => 'field_programme_loc_arr',
      1 => 'field_programme_loc_cp',
      2 => 'field_programme_loc_department',
      3 => 'field_programme_loc_lat',
      4 => 'field_programme_loc_long',
      5 => 'field_programme_loc_region',
      6 => 'field_programme_loc_rue',
      7 => 'field_programme_loc_ville',
      8 => 'field_programme_loc_num',
      9 => 'field_programme_loc_type',
      10 => 'field_programme_loc_region_kb',
      11 => 'field_field_programme_loc_lat',
      12 => 'field_field_programme_loc_long',
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
    'weight' => '23',
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
    'weight' => '24',
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
    'weight' => '26',
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
    'weight' => '25',
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
    'weight' => '27',
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
    'weight' => '7',
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
  $field_group->identifier = 'group_programme_bien_images|node|programme|form';
  $field_group->group_name = 'group_programme_bien_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images des types de Lots',
    'weight' => '13',
    'children' => array(
      0 => 'field_image_2_piece',
      1 => 'field_image_3_piece',
      2 => 'field_image_4_piece',
      3 => 'field_image_5_piece',
      4 => 'field_image_studio',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-programme-bien-images field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_programme_bien_images|node|programme|form'] = $field_group;

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
    'weight' => '12',
    'children' => array(
      0 => 'field_marque_comm',
      1 => 'field_program_low_tva_price_max',
      2 => 'field_program_low_tva_price_min',
      3 => 'field_programme_avg_price',
      4 => 'field_programme_flat_available',
      5 => 'field_programme_habiteo_bon_plan',
      6 => 'field_programme_habiteo_id',
      7 => 'field_programme_min_price',
      8 => 'field_programme_online_date',
      9 => 'field_programme_price_max',
      10 => 'field_programme_price_min',
      11 => 'field_programme_room_max',
      12 => 'field_programme_room_min',
      13 => 'field_programme_statut',
      14 => 'field_programme_stock',
      15 => 'field_type_programme',
      16 => 'field_zone_activite',
      17 => 'field_programme_gamme',
      18 => 'field_program_low_tva_price_maxb',
      19 => 'field_program_low_tva_price_minb',
      20 => 'field_programme_flat_available_b',
      21 => 'field_programme_price_max_b',
      22 => 'field_programme_price_min_b',
      23 => 'field_programme_room_max_b',
      24 => 'field_programme_room_min_b',
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
    'weight' => '6',
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
    'weight' => '4',
    'children' => array(
      0 => 'field_annee',
      1 => 'field_image_principale',
      2 => 'field_trimestre',
      3 => 'field_tva',
      4 => 'field_affichage_double_grille',
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
