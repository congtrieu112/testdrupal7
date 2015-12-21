<?php
/**
 * @file
 * kandb_programme.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function kandb_programme_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|programme|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'programme';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'price_tva_max' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
    ),
    'price_tva_min' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
    ),
    'service_links' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
    ),
    'anchor' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
    ),
    'contact_block_page' => array(
      'weight' => '1',
      'label' => 'inline',
      'format' => 'default',
    ),
    'contact_on_summary' => array(
      'weight' => '2',
      'label' => 'inline',
      'format' => 'default',
    ),
    'document_block' => array(
      'weight' => '3',
      'label' => 'inline',
      'format' => 'default',
    ),
  );
  $export['node|programme|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|programme|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'programme';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'anchor' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'default',
    ),
    'document_block' => array(
      'weight' => '6',
      'label' => 'inline',
      'format' => 'default',
    ),
    'logement_block' => array(
      'weight' => '5',
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
      'weight' => '3',
      'label' => 'inline',
      'format' => 'default',
    ),
    'contact_block_page' => array(
      'weight' => '7',
      'label' => 'inline',
      'format' => 'default',
    ),
    'contact_on_summary' => array(
      'weight' => '2',
      'label' => 'inline',
      'format' => 'default',
    ),
  );
  $export['node|programme|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|programme|selection';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'programme';
  $ds_fieldsetting->view_mode = 'selection';
  $ds_fieldsetting->settings = array(
    'price_tva_min' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|programme|selection'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function kandb_programme_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'anchor';
  $ds_field->label = 'Anchor';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array();
  $export['anchor'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'contact_block_page';
  $ds_field->label = 'Contact block page';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'kandb_contact|contact_block_page',
    'block_render' => '1',
  );
  $export['contact_block_page'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'contact_on_summary';
  $ds_field->label = 'Contact on summary';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'kandb_contact|contact_on_summary',
    'block_render' => '1',
  );
  $export['contact_on_summary'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'document_block';
  $ds_field->label = 'Document block ';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'kandb_programme|document_block',
    'block_render' => '1',
  );
  $export['document_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'logement_block';
  $ds_field->label = 'Logement block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'kandb_programme|logement_block',
    'block_render' => '1',
  );
  $export['logement_block'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function kandb_programme_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|programme|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'programme';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'price_tva_min',
        1 => 'service_links',
        2 => 'price_tva_max',
        3 => 'anchor',
        4 => 'contact_block_page',
        5 => 'contact_on_summary',
        6 => 'document_block',
        7 => 'field_image_principale',
        8 => 'field_trimestre',
        9 => 'field_en_quelques_mots',
        10 => 'field_quartier_titre',
        11 => 'field_quartier_video_titre',
        12 => 'field_prestations_titre',
        13 => 'field_prestations_sous_titre',
        14 => 'field_slider_exterieur_titre',
        15 => 'field_slider_exterieur_image',
        16 => 'field_slider_interieur_titre',
        17 => 'field_slider_interieur_image',
        18 => 'field_slider_securite_titre',
        19 => 'field_slider_securite_image',
        20 => 'field_slider_rt2012_titre',
        21 => 'field_slider_rt2012_image',
        22 => 'field_prestations_plan_masse_3d',
        23 => 'field_plaquette_commerciale',
        24 => 'field_fiche_renseignement',
        25 => 'field_plan_batiment',
        26 => 'field_kit_fiscal',
        27 => 'field_photo_conseiller',
        28 => 'field_nom_conseiller',
        29 => 'field_espace_vente_adresse',
        30 => 'field_espace_vente_horaire',
        31 => 'field_nouveau',
        32 => 'field_slider_rt2012_desc',
        33 => 'field_slider_securite_desc',
        34 => 'field_slider_interieur_desc',
        35 => 'field_slider_exterieur_desc',
        36 => 'field_quartier_video_desc',
        37 => 'field_id_programme',
        38 => 'field_annee',
        39 => 'field_tva_55',
        40 => 'field_espace_vente_longitude',
        41 => 'field_espace_vente_latitude',
        42 => 'field_marque_comm',
        43 => 'field_zone_activite',
        44 => 'field_type_programme',
        45 => 'field_en_quelques_mots_b2b',
        46 => 'field_quartier_video',
        47 => 'field_slider_rt2012_bbc',
        48 => 'field_slider_rt2012_echelle',
        49 => 'field_contrat_reservation',
        50 => 'field_etat_des_risques',
        51 => 'field_lettre_de_banque',
        52 => 'field_prestations_programme',
        53 => 'field_mandat_gestion_locative',
        54 => 'field_plan_masse_sous_sol',
        55 => 'field_visuel_grande_taille',
        56 => 'field_bail_commercial',
        57 => 'field_bon_commande_mobilier',
        58 => 'field_autre_documents',
        59 => 'field_espace_vente_tel',
        60 => 'field_espace_vente_tel2',
        61 => 'field_espace_vente_email',
        62 => 'field_espace_vente_ville',
        63 => 'field_espace_vente_dpt',
        64 => 'field_programme_mtn_legale',
        65 => 'field_programme_loc_rue',
        66 => 'field_programme_loc_cp',
        67 => 'field_programme_loc_long',
        68 => 'field_programme_loc_lat',
        69 => 'field_programme_online_date',
        70 => 'field_programme_statut',
        71 => 'field_programme_stock',
        72 => 'field_programme_avg_price',
        73 => 'field_programme_min_price',
        74 => 'field_programme_flat_available',
        75 => 'field_programme_price_min',
        76 => 'field_programme_price_max',
        77 => 'field_programme_room_min',
        78 => 'field_programme_room_max',
        79 => 'field_programme_loc_ville',
        80 => 'field_programme_loc_arr',
        81 => 'field_tva',
        82 => 'field_program_low_tva_price_min',
        83 => 'field_programme_habiteo_id',
        84 => 'field_programme_loc_department',
        85 => 'field_program_low_tva_price_max',
        86 => 'field_programme_loc_region',
        87 => 'field_quartier_sous_titre',
        88 => 'field_programme_loc_num',
        89 => 'field_programme_loc_type',
      ),
    ),
    'fields' => array(
      'price_tva_min' => 'ds_content',
      'service_links' => 'ds_content',
      'price_tva_max' => 'ds_content',
      'anchor' => 'ds_content',
      'contact_block_page' => 'ds_content',
      'contact_on_summary' => 'ds_content',
      'document_block' => 'ds_content',
      'field_image_principale' => 'ds_content',
      'field_trimestre' => 'ds_content',
      'field_en_quelques_mots' => 'ds_content',
      'field_quartier_titre' => 'ds_content',
      'field_quartier_video_titre' => 'ds_content',
      'field_prestations_titre' => 'ds_content',
      'field_prestations_sous_titre' => 'ds_content',
      'field_slider_exterieur_titre' => 'ds_content',
      'field_slider_exterieur_image' => 'ds_content',
      'field_slider_interieur_titre' => 'ds_content',
      'field_slider_interieur_image' => 'ds_content',
      'field_slider_securite_titre' => 'ds_content',
      'field_slider_securite_image' => 'ds_content',
      'field_slider_rt2012_titre' => 'ds_content',
      'field_slider_rt2012_image' => 'ds_content',
      'field_prestations_plan_masse_3d' => 'ds_content',
      'field_plaquette_commerciale' => 'ds_content',
      'field_fiche_renseignement' => 'ds_content',
      'field_plan_batiment' => 'ds_content',
      'field_kit_fiscal' => 'ds_content',
      'field_photo_conseiller' => 'ds_content',
      'field_nom_conseiller' => 'ds_content',
      'field_espace_vente_adresse' => 'ds_content',
      'field_espace_vente_horaire' => 'ds_content',
      'field_nouveau' => 'ds_content',
      'field_slider_rt2012_desc' => 'ds_content',
      'field_slider_securite_desc' => 'ds_content',
      'field_slider_interieur_desc' => 'ds_content',
      'field_slider_exterieur_desc' => 'ds_content',
      'field_quartier_video_desc' => 'ds_content',
      'field_id_programme' => 'ds_content',
      'field_annee' => 'ds_content',
      'field_tva_55' => 'ds_content',
      'field_espace_vente_longitude' => 'ds_content',
      'field_espace_vente_latitude' => 'ds_content',
      'field_marque_comm' => 'ds_content',
      'field_zone_activite' => 'ds_content',
      'field_type_programme' => 'ds_content',
      'field_en_quelques_mots_b2b' => 'ds_content',
      'field_quartier_video' => 'ds_content',
      'field_slider_rt2012_bbc' => 'ds_content',
      'field_slider_rt2012_echelle' => 'ds_content',
      'field_contrat_reservation' => 'ds_content',
      'field_etat_des_risques' => 'ds_content',
      'field_lettre_de_banque' => 'ds_content',
      'field_prestations_programme' => 'ds_content',
      'field_mandat_gestion_locative' => 'ds_content',
      'field_plan_masse_sous_sol' => 'ds_content',
      'field_visuel_grande_taille' => 'ds_content',
      'field_bail_commercial' => 'ds_content',
      'field_bon_commande_mobilier' => 'ds_content',
      'field_autre_documents' => 'ds_content',
      'field_espace_vente_tel' => 'ds_content',
      'field_espace_vente_tel2' => 'ds_content',
      'field_espace_vente_email' => 'ds_content',
      'field_espace_vente_ville' => 'ds_content',
      'field_espace_vente_dpt' => 'ds_content',
      'field_programme_mtn_legale' => 'ds_content',
      'field_programme_loc_rue' => 'ds_content',
      'field_programme_loc_cp' => 'ds_content',
      'field_programme_loc_long' => 'ds_content',
      'field_programme_loc_lat' => 'ds_content',
      'field_programme_online_date' => 'ds_content',
      'field_programme_statut' => 'ds_content',
      'field_programme_stock' => 'ds_content',
      'field_programme_avg_price' => 'ds_content',
      'field_programme_min_price' => 'ds_content',
      'field_programme_flat_available' => 'ds_content',
      'field_programme_price_min' => 'ds_content',
      'field_programme_price_max' => 'ds_content',
      'field_programme_room_min' => 'ds_content',
      'field_programme_room_max' => 'ds_content',
      'field_programme_loc_ville' => 'ds_content',
      'field_programme_loc_arr' => 'ds_content',
      'field_tva' => 'ds_content',
      'field_program_low_tva_price_min' => 'ds_content',
      'field_programme_habiteo_id' => 'ds_content',
      'field_programme_loc_department' => 'ds_content',
      'field_program_low_tva_price_max' => 'ds_content',
      'field_programme_loc_region' => 'ds_content',
      'field_quartier_sous_titre' => 'ds_content',
      'field_programme_loc_num' => 'ds_content',
      'field_programme_loc_type' => 'ds_content',
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
  $export['node|programme|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|programme|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'programme';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'price_tva_min',
        1 => 'price_tva_max',
        2 => 'contact_on_summary',
        3 => 'service_links',
        4 => 'anchor',
        5 => 'logement_block',
        6 => 'document_block',
        7 => 'contact_block_page',
        8 => 'field_image_principale',
        9 => 'field_trimestre',
        10 => 'field_en_quelques_mots',
        11 => 'field_quartier_titre',
        12 => 'field_quartier_sous_titre',
        13 => 'field_quartier_video_titre',
        14 => 'field_prestations_titre',
        15 => 'field_prestations_sous_titre',
        16 => 'field_slider_exterieur_titre',
        17 => 'field_slider_exterieur_image',
        18 => 'field_slider_interieur_titre',
        19 => 'field_slider_interieur_image',
        20 => 'field_slider_securite_titre',
        21 => 'field_slider_securite_image',
        22 => 'field_slider_rt2012_titre',
        23 => 'field_slider_rt2012_image',
        24 => 'field_prestations_plan_masse_3d',
        25 => 'field_plaquette_commerciale',
        26 => 'field_fiche_renseignement',
        27 => 'field_plan_batiment',
        28 => 'field_kit_fiscal',
        29 => 'field_photo_conseiller',
        30 => 'field_nom_conseiller',
        31 => 'field_espace_vente_adresse',
        32 => 'field_espace_vente_horaire',
        33 => 'field_nouveau',
        34 => 'field_slider_rt2012_desc',
        35 => 'field_slider_securite_desc',
        36 => 'field_slider_interieur_desc',
        37 => 'field_slider_exterieur_desc',
        38 => 'field_quartier_video_desc',
        39 => 'field_id_programme',
        40 => 'field_annee',
        41 => 'field_tva_55',
        42 => 'field_espace_vente_longitude',
        43 => 'field_espace_vente_latitude',
        44 => 'field_marque_comm',
        45 => 'field_zone_activite',
        46 => 'field_type_programme',
        47 => 'field_en_quelques_mots_b2b',
        48 => 'field_quartier_video',
        49 => 'field_slider_rt2012_bbc',
        50 => 'field_slider_rt2012_echelle',
        51 => 'field_contrat_reservation',
        52 => 'field_etat_des_risques',
        53 => 'field_lettre_de_banque',
        54 => 'field_prestations_programme',
        55 => 'field_mandat_gestion_locative',
        56 => 'field_plan_masse_sous_sol',
        57 => 'field_visuel_grande_taille',
        58 => 'field_bail_commercial',
        59 => 'field_bon_commande_mobilier',
        60 => 'field_autre_documents',
        61 => 'field_espace_vente_tel',
        62 => 'field_espace_vente_tel2',
        63 => 'field_espace_vente_email',
        64 => 'field_espace_vente_ville',
        65 => 'field_espace_vente_dpt',
        66 => 'field_programme_mtn_legale',
        67 => 'field_programme_loc_num',
        68 => 'field_programme_loc_type',
        69 => 'field_programme_loc_rue',
        70 => 'field_programme_loc_cp',
        71 => 'field_programme_loc_long',
        72 => 'field_programme_loc_lat',
        73 => 'field_programme_online_date',
        74 => 'field_programme_statut',
        75 => 'field_programme_stock',
        76 => 'field_programme_avg_price',
        77 => 'field_programme_min_price',
        78 => 'field_programme_flat_available',
        79 => 'field_programme_price_min',
        80 => 'field_programme_price_max',
        81 => 'field_programme_room_min',
        82 => 'field_programme_room_max',
        83 => 'field_programme_loc_ville',
        84 => 'field_programme_loc_arr',
        85 => 'field_tva',
        86 => 'field_caracteristique',
        87 => 'field_programme_habiteo_id',
        88 => 'field_program_low_tva_price_min',
        89 => 'field_programme_loc_department',
        90 => 'field_program_low_tva_price_max',
        91 => 'field_programme_loc_region',
      ),
    ),
    'fields' => array(
      'price_tva_min' => 'ds_content',
      'price_tva_max' => 'ds_content',
      'contact_on_summary' => 'ds_content',
      'service_links' => 'ds_content',
      'anchor' => 'ds_content',
      'logement_block' => 'ds_content',
      'document_block' => 'ds_content',
      'contact_block_page' => 'ds_content',
      'field_image_principale' => 'ds_content',
      'field_trimestre' => 'ds_content',
      'field_en_quelques_mots' => 'ds_content',
      'field_quartier_titre' => 'ds_content',
      'field_quartier_sous_titre' => 'ds_content',
      'field_quartier_video_titre' => 'ds_content',
      'field_prestations_titre' => 'ds_content',
      'field_prestations_sous_titre' => 'ds_content',
      'field_slider_exterieur_titre' => 'ds_content',
      'field_slider_exterieur_image' => 'ds_content',
      'field_slider_interieur_titre' => 'ds_content',
      'field_slider_interieur_image' => 'ds_content',
      'field_slider_securite_titre' => 'ds_content',
      'field_slider_securite_image' => 'ds_content',
      'field_slider_rt2012_titre' => 'ds_content',
      'field_slider_rt2012_image' => 'ds_content',
      'field_prestations_plan_masse_3d' => 'ds_content',
      'field_plaquette_commerciale' => 'ds_content',
      'field_fiche_renseignement' => 'ds_content',
      'field_plan_batiment' => 'ds_content',
      'field_kit_fiscal' => 'ds_content',
      'field_photo_conseiller' => 'ds_content',
      'field_nom_conseiller' => 'ds_content',
      'field_espace_vente_adresse' => 'ds_content',
      'field_espace_vente_horaire' => 'ds_content',
      'field_nouveau' => 'ds_content',
      'field_slider_rt2012_desc' => 'ds_content',
      'field_slider_securite_desc' => 'ds_content',
      'field_slider_interieur_desc' => 'ds_content',
      'field_slider_exterieur_desc' => 'ds_content',
      'field_quartier_video_desc' => 'ds_content',
      'field_id_programme' => 'ds_content',
      'field_annee' => 'ds_content',
      'field_tva_55' => 'ds_content',
      'field_espace_vente_longitude' => 'ds_content',
      'field_espace_vente_latitude' => 'ds_content',
      'field_marque_comm' => 'ds_content',
      'field_zone_activite' => 'ds_content',
      'field_type_programme' => 'ds_content',
      'field_en_quelques_mots_b2b' => 'ds_content',
      'field_quartier_video' => 'ds_content',
      'field_slider_rt2012_bbc' => 'ds_content',
      'field_slider_rt2012_echelle' => 'ds_content',
      'field_contrat_reservation' => 'ds_content',
      'field_etat_des_risques' => 'ds_content',
      'field_lettre_de_banque' => 'ds_content',
      'field_prestations_programme' => 'ds_content',
      'field_mandat_gestion_locative' => 'ds_content',
      'field_plan_masse_sous_sol' => 'ds_content',
      'field_visuel_grande_taille' => 'ds_content',
      'field_bail_commercial' => 'ds_content',
      'field_bon_commande_mobilier' => 'ds_content',
      'field_autre_documents' => 'ds_content',
      'field_espace_vente_tel' => 'ds_content',
      'field_espace_vente_tel2' => 'ds_content',
      'field_espace_vente_email' => 'ds_content',
      'field_espace_vente_ville' => 'ds_content',
      'field_espace_vente_dpt' => 'ds_content',
      'field_programme_mtn_legale' => 'ds_content',
      'field_programme_loc_num' => 'ds_content',
      'field_programme_loc_type' => 'ds_content',
      'field_programme_loc_rue' => 'ds_content',
      'field_programme_loc_cp' => 'ds_content',
      'field_programme_loc_long' => 'ds_content',
      'field_programme_loc_lat' => 'ds_content',
      'field_programme_online_date' => 'ds_content',
      'field_programme_statut' => 'ds_content',
      'field_programme_stock' => 'ds_content',
      'field_programme_avg_price' => 'ds_content',
      'field_programme_min_price' => 'ds_content',
      'field_programme_flat_available' => 'ds_content',
      'field_programme_price_min' => 'ds_content',
      'field_programme_price_max' => 'ds_content',
      'field_programme_room_min' => 'ds_content',
      'field_programme_room_max' => 'ds_content',
      'field_programme_loc_ville' => 'ds_content',
      'field_programme_loc_arr' => 'ds_content',
      'field_tva' => 'ds_content',
      'field_caracteristique' => 'ds_content',
      'field_programme_habiteo_id' => 'ds_content',
      'field_program_low_tva_price_min' => 'ds_content',
      'field_programme_loc_department' => 'ds_content',
      'field_program_low_tva_price_max' => 'ds_content',
      'field_programme_loc_region' => 'ds_content',
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
  $export['node|programme|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|programme|selection';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'programme';
  $ds_layout->view_mode = 'selection';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'price_tva_min',
        2 => 'field_caracteristiques',
        3 => 'field_image_principale',
        4 => 'field_plaquette_commerciale',
        5 => 'field_programme_flat_available',
        6 => 'field_programme_price_min',
        7 => 'field_programme_room_min',
        8 => 'field_programme_room_max',
        9 => 'field_programme_loc_ville',
        10 => 'field_tva',
        11 => 'field_programme_loc_department',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'price_tva_min' => 'ds_content',
      'field_caracteristiques' => 'ds_content',
      'field_image_principale' => 'ds_content',
      'field_plaquette_commerciale' => 'ds_content',
      'field_programme_flat_available' => 'ds_content',
      'field_programme_price_min' => 'ds_content',
      'field_programme_room_min' => 'ds_content',
      'field_programme_room_max' => 'ds_content',
      'field_programme_loc_ville' => 'ds_content',
      'field_tva' => 'ds_content',
      'field_programme_loc_department' => 'ds_content',
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
  $export['node|programme|selection'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|programme|teaser_on_bien';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'programme';
  $ds_layout->view_mode = 'teaser_on_bien';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image_principale',
        1 => 'field_programme_price_min',
        2 => 'field_programme_room_min',
        3 => 'field_programme_room_max',
      ),
    ),
    'fields' => array(
      'field_image_principale' => 'ds_content',
      'field_programme_price_min' => 'ds_content',
      'field_programme_room_min' => 'ds_content',
      'field_programme_room_max' => 'ds_content',
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
  $export['node|programme|teaser_on_bien'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function kandb_programme_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_on_bien';
  $ds_view_mode->label = 'Teaser on bien';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['teaser_on_bien'] = $ds_view_mode;

  return $export;
}
