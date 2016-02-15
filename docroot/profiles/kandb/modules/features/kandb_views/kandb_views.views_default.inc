<?php
/**
 * @file
 * kandb_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function kandb_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'b2b_nos_dernieres_offres';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'B2B Nos dernières offres';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Les dernières offers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time_per_domain';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_promotion_programme_target_id']['id'] = 'field_promotion_programme_target_id';
  $handler->display->display_options['relationships']['field_promotion_programme_target_id']['table'] = 'field_data_field_promotion_programme';
  $handler->display->display_options['relationships']['field_promotion_programme_target_id']['field'] = 'field_promotion_programme_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Image Principale */
  $handler->display->display_options['fields']['field_image_principale']['id'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['table'] = 'field_data_field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['field'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['label'] = '';
  $handler->display->display_options['fields']['field_image_principale']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_principale']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_principale']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_principale']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'programme' => 'programme',
  );
  /* Filter criterion: Content: Statut du programme (field_programme_statut) */
  $handler->display->display_options['filters']['field_programme_statut_value']['id'] = 'field_programme_statut_value';
  $handler->display->display_options['filters']['field_programme_statut_value']['table'] = 'field_data_field_programme_statut';
  $handler->display->display_options['filters']['field_programme_statut_value']['field'] = 'field_programme_statut_value';
  $handler->display->display_options['filters']['field_programme_statut_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Les dernières offres */
  $handler = $view->new_display('block', 'Les dernières offres', 'block');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image Principale */
  $handler->display->display_options['fields']['field_image_principale']['id'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['table'] = 'field_data_field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['field'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['label'] = '';
  $handler->display->display_options['fields']['field_image_principale']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_principale']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_principale']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_principale']['settings'] = array(
    'image_style' => 'programme_teaser_3',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image_principale']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Ville */
  $handler->display->display_options['fields']['field_programme_loc_ville']['id'] = 'field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_loc_ville']['table'] = 'field_data_field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_loc_ville']['field'] = 'field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_loc_ville']['label'] = '';
  $handler->display->display_options['fields']['field_programme_loc_ville']['element_label_colon'] = FALSE;
  /* Field: Content: Départment */
  $handler->display->display_options['fields']['field_programme_loc_department']['id'] = 'field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_loc_department']['table'] = 'field_data_field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_loc_department']['field'] = 'field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_loc_department']['label'] = '';
  $handler->display->display_options['fields']['field_programme_loc_department']['element_label_colon'] = FALSE;
  /* Field: Content: En quelques mots B2B */
  $handler->display->display_options['fields']['field_en_quelques_mots_b2b']['id'] = 'field_en_quelques_mots_b2b';
  $handler->display->display_options['fields']['field_en_quelques_mots_b2b']['table'] = 'field_data_field_en_quelques_mots_b2b';
  $handler->display->display_options['fields']['field_en_quelques_mots_b2b']['field'] = 'field_en_quelques_mots_b2b';
  $handler->display->display_options['fields']['field_en_quelques_mots_b2b']['label'] = '';
  $handler->display->display_options['fields']['field_en_quelques_mots_b2b']['element_label_colon'] = FALSE;
  /* Field: Content: Nouveauté */
  $handler->display->display_options['fields']['field_nouveau']['id'] = 'field_nouveau';
  $handler->display->display_options['fields']['field_nouveau']['table'] = 'field_data_field_nouveau';
  $handler->display->display_options['fields']['field_nouveau']['field'] = 'field_nouveau';
  $handler->display->display_options['fields']['field_nouveau']['label'] = '';
  $handler->display->display_options['fields']['field_nouveau']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_nouveau']['type'] = 'list_key';
  /* Field: Content: Date de livraison */
  $handler->display->display_options['fields']['field_programme_livraison_date']['id'] = 'field_programme_livraison_date';
  $handler->display->display_options['fields']['field_programme_livraison_date']['table'] = 'field_data_field_programme_livraison_date';
  $handler->display->display_options['fields']['field_programme_livraison_date']['field'] = 'field_programme_livraison_date';
  $handler->display->display_options['fields']['field_programme_livraison_date']['label'] = '';
  $handler->display->display_options['fields']['field_programme_livraison_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_livraison_date']['settings'] = array(
    'format_type' => 'dd_mm_yyyy',
    'fromto' => '',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date d’actabilité */
  $handler->display->display_options['fields']['field_programme_actabilite_date']['id'] = 'field_programme_actabilite_date';
  $handler->display->display_options['fields']['field_programme_actabilite_date']['table'] = 'field_data_field_programme_actabilite_date';
  $handler->display->display_options['fields']['field_programme_actabilite_date']['field'] = 'field_programme_actabilite_date';
  $handler->display->display_options['fields']['field_programme_actabilite_date']['label'] = '';
  $handler->display->display_options['fields']['field_programme_actabilite_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_actabilite_date']['settings'] = array(
    'format_type' => 'dd_mm_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'programme' => 'programme',
  );
  /* Filter criterion: Content: Statut du programme (field_programme_statut) */
  $handler->display->display_options['filters']['field_programme_statut_value']['id'] = 'field_programme_statut_value';
  $handler->display->display_options['filters']['field_programme_statut_value']['table'] = 'field_data_field_programme_statut';
  $handler->display->display_options['filters']['field_programme_statut_value']['field'] = 'field_programme_statut_value';
  $handler->display->display_options['filters']['field_programme_statut_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter criterion: Content: Nouveauté (field_nouveau) */
  $handler->display->display_options['filters']['field_nouveau_value']['id'] = 'field_nouveau_value';
  $handler->display->display_options['filters']['field_nouveau_value']['table'] = 'field_data_field_nouveau';
  $handler->display->display_options['filters']['field_nouveau_value']['field'] = 'field_nouveau_value';
  $handler->display->display_options['filters']['field_nouveau_value']['value'] = array(
    1 => '1',
  );

  /* Display: Les offres spéciales  */
  $handler = $view->new_display('block', 'Les offres spéciales ', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image Principale */
  $handler->display->display_options['fields']['field_image_principale']['id'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['table'] = 'field_data_field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['field'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['label'] = '';
  $handler->display->display_options['fields']['field_image_principale']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_principale']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_principale']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_principale']['settings'] = array(
    'image_style' => 'programme_teaser_3',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image_principale']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Ville */
  $handler->display->display_options['fields']['field_programme_loc_ville']['id'] = 'field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_loc_ville']['table'] = 'field_data_field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_loc_ville']['field'] = 'field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_loc_ville']['label'] = '';
  $handler->display->display_options['fields']['field_programme_loc_ville']['element_label_colon'] = FALSE;
  /* Field: Content: Départment */
  $handler->display->display_options['fields']['field_programme_loc_department']['id'] = 'field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_loc_department']['table'] = 'field_data_field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_loc_department']['field'] = 'field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_loc_department']['label'] = '';
  $handler->display->display_options['fields']['field_programme_loc_department']['element_label_colon'] = FALSE;
  /* Field: Content: En quelques mots B2B */
  $handler->display->display_options['fields']['field_en_quelques_mots_b2b']['id'] = 'field_en_quelques_mots_b2b';
  $handler->display->display_options['fields']['field_en_quelques_mots_b2b']['table'] = 'field_data_field_en_quelques_mots_b2b';
  $handler->display->display_options['fields']['field_en_quelques_mots_b2b']['field'] = 'field_en_quelques_mots_b2b';
  $handler->display->display_options['fields']['field_en_quelques_mots_b2b']['label'] = '';
  $handler->display->display_options['fields']['field_en_quelques_mots_b2b']['element_label_colon'] = FALSE;
  /* Field: Content: Nouveauté */
  $handler->display->display_options['fields']['field_nouveau']['id'] = 'field_nouveau';
  $handler->display->display_options['fields']['field_nouveau']['table'] = 'field_data_field_nouveau';
  $handler->display->display_options['fields']['field_nouveau']['field'] = 'field_nouveau';
  $handler->display->display_options['fields']['field_nouveau']['label'] = '';
  $handler->display->display_options['fields']['field_nouveau']['element_label_colon'] = FALSE;
  /* Field: Content: Date de livraison */
  $handler->display->display_options['fields']['field_programme_livraison_date']['id'] = 'field_programme_livraison_date';
  $handler->display->display_options['fields']['field_programme_livraison_date']['table'] = 'field_data_field_programme_livraison_date';
  $handler->display->display_options['fields']['field_programme_livraison_date']['field'] = 'field_programme_livraison_date';
  $handler->display->display_options['fields']['field_programme_livraison_date']['label'] = '';
  $handler->display->display_options['fields']['field_programme_livraison_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_livraison_date']['settings'] = array(
    'format_type' => 'dd_mm_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date d’actabilité */
  $handler->display->display_options['fields']['field_programme_actabilite_date']['id'] = 'field_programme_actabilite_date';
  $handler->display->display_options['fields']['field_programme_actabilite_date']['table'] = 'field_data_field_programme_actabilite_date';
  $handler->display->display_options['fields']['field_programme_actabilite_date']['field'] = 'field_programme_actabilite_date';
  $handler->display->display_options['fields']['field_programme_actabilite_date']['label'] = '';
  $handler->display->display_options['fields']['field_programme_actabilite_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_actabilite_date']['settings'] = array(
    'format_type' => 'dd_mm_yyyy',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'programme' => 'programme',
  );
  /* Filter criterion: Content: Statut du programme (field_programme_statut) */
  $handler->display->display_options['filters']['field_programme_statut_value']['id'] = 'field_programme_statut_value';
  $handler->display->display_options['filters']['field_programme_statut_value']['table'] = 'field_data_field_programme_statut';
  $handler->display->display_options['filters']['field_programme_statut_value']['field'] = 'field_programme_statut_value';
  $handler->display->display_options['filters']['field_programme_statut_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Content: Nouveauté (field_nouveau) */
  $handler->display->display_options['filters']['field_nouveau_value']['id'] = 'field_nouveau_value';
  $handler->display->display_options['filters']['field_nouveau_value']['table'] = 'field_data_field_nouveau';
  $handler->display->display_options['filters']['field_nouveau_value']['field'] = 'field_nouveau_value';
  $handler->display->display_options['filters']['field_nouveau_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Nouveautés et avant premières */
  $handler = $view->new_display('block', 'Nouveautés et avant premières', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Nouveautés et avant premières';
  $handler->display->display_options['display_description'] = 'avant_premiere_date_fin >= now()';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Image Principale */
  $handler->display->display_options['fields']['field_avant_premiere_image_princ']['id'] = 'field_avant_premiere_image_princ';
  $handler->display->display_options['fields']['field_avant_premiere_image_princ']['table'] = 'field_data_field_avant_premiere_image_princ';
  $handler->display->display_options['fields']['field_avant_premiere_image_princ']['field'] = 'field_avant_premiere_image_princ';
  $handler->display->display_options['fields']['field_avant_premiere_image_princ']['label'] = '';
  $handler->display->display_options['fields']['field_avant_premiere_image_princ']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_avant_premiere_image_princ']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_avant_premiere_image_princ']['settings'] = array(
    'image_style' => 'programme_teaser_3',
    'image_link' => '',
  );
  /* Field: Content: Ville */
  $handler->display->display_options['fields']['field_avant_premiere_ville']['id'] = 'field_avant_premiere_ville';
  $handler->display->display_options['fields']['field_avant_premiere_ville']['table'] = 'field_data_field_avant_premiere_ville';
  $handler->display->display_options['fields']['field_avant_premiere_ville']['field'] = 'field_avant_premiere_ville';
  $handler->display->display_options['fields']['field_avant_premiere_ville']['label'] = '';
  $handler->display->display_options['fields']['field_avant_premiere_ville']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_avant_premiere_ville']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Département */
  $handler->display->display_options['fields']['field_avant_premiere_department']['id'] = 'field_avant_premiere_department';
  $handler->display->display_options['fields']['field_avant_premiere_department']['table'] = 'field_data_field_avant_premiere_department';
  $handler->display->display_options['fields']['field_avant_premiere_department']['field'] = 'field_avant_premiere_department';
  $handler->display->display_options['fields']['field_avant_premiere_department']['label'] = '';
  $handler->display->display_options['fields']['field_avant_premiere_department']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_avant_premiere_department']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'avant_premiere' => 'avant_premiere',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Content: Grande ouverture (field_avant_premiere_grande_ouve) */
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['id'] = 'field_avant_premiere_grande_ouve_value';
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['table'] = 'field_data_field_avant_premiere_grande_ouve';
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['field'] = 'field_avant_premiere_grande_ouve_value';
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Date fin lancement (field_avant_premiere_date_fin) */
  $handler->display->display_options['filters']['field_avant_premiere_date_fin_value']['id'] = 'field_avant_premiere_date_fin_value';
  $handler->display->display_options['filters']['field_avant_premiere_date_fin_value']['table'] = 'field_data_field_avant_premiere_date_fin';
  $handler->display->display_options['filters']['field_avant_premiere_date_fin_value']['field'] = 'field_avant_premiere_date_fin_value';
  $handler->display->display_options['filters']['field_avant_premiere_date_fin_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_avant_premiere_date_fin_value']['default_date'] = 'now';
  $translatables['b2b_nos_dernieres_offres'] = array(
    t('Master'),
    t('Les dernières offers'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_promotion_programme'),
    t('Les dernières offres'),
    t('Les offres spéciales '),
    t('Nouveautés et avant premières'),
    t('avant_premiere_date_fin >= now()'),
  );
  $export['b2b_nos_dernieres_offres'] = $view;

  $view = new view();
  $view->name = 'nos_dernieres_offres';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Nos dernières offres';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Nos dernières offres';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time_per_domain';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_promotion_programme_node']['id'] = 'reverse_field_promotion_programme_node';
  $handler->display->display_options['relationships']['reverse_field_promotion_programme_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_promotion_programme_node']['field'] = 'reverse_field_promotion_programme_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Image Principale */
  $handler->display->display_options['fields']['field_image_principale']['id'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['table'] = 'field_data_field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['field'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_principale']['settings'] = array(
    'image_style' => 'programme_teaser_3',
    'image_link' => '',
  );
  /* Field: Content: Départment */
  $handler->display->display_options['fields']['field_programme_loc_department']['id'] = 'field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_loc_department']['table'] = 'field_data_field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_loc_department']['field'] = 'field_programme_loc_department';
  /* Field: Content: Ville */
  $handler->display->display_options['fields']['field_programme_loc_ville']['id'] = 'field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_loc_ville']['table'] = 'field_data_field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_loc_ville']['field'] = 'field_programme_loc_ville';
  /* Field: Content: Programme lié */
  $handler->display->display_options['fields']['field_promotion_programme']['id'] = 'field_promotion_programme';
  $handler->display->display_options['fields']['field_promotion_programme']['table'] = 'field_data_field_promotion_programme';
  $handler->display->display_options['fields']['field_promotion_programme']['field'] = 'field_promotion_programme';
  $handler->display->display_options['fields']['field_promotion_programme']['relationship'] = 'reverse_field_promotion_programme_node';
  $handler->display->display_options['fields']['field_promotion_programme']['label'] = 'Programme lié:';
  $handler->display->display_options['fields']['field_promotion_programme']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Date de début */
  $handler->display->display_options['fields']['field_promotion_start']['id'] = 'field_promotion_start';
  $handler->display->display_options['fields']['field_promotion_start']['table'] = 'field_data_field_promotion_start';
  $handler->display->display_options['fields']['field_promotion_start']['field'] = 'field_promotion_start';
  $handler->display->display_options['fields']['field_promotion_start']['relationship'] = 'reverse_field_promotion_programme_node';
  $handler->display->display_options['fields']['field_promotion_start']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date de fin */
  $handler->display->display_options['fields']['field_promotion_stop']['id'] = 'field_promotion_stop';
  $handler->display->display_options['fields']['field_promotion_stop']['table'] = 'field_data_field_promotion_stop';
  $handler->display->display_options['fields']['field_promotion_stop']['field'] = 'field_promotion_stop';
  $handler->display->display_options['fields']['field_promotion_stop']['relationship'] = 'reverse_field_promotion_programme_node';
  $handler->display->display_options['fields']['field_promotion_stop']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Mentions Légales */
  $handler->display->display_options['fields']['field_promotion_mention_legale']['id'] = 'field_promotion_mention_legale';
  $handler->display->display_options['fields']['field_promotion_mention_legale']['table'] = 'field_data_field_promotion_mention_legale';
  $handler->display->display_options['fields']['field_promotion_mention_legale']['field'] = 'field_promotion_mention_legale';
  $handler->display->display_options['fields']['field_promotion_mention_legale']['relationship'] = 'reverse_field_promotion_programme_node';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_promotion_programme_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_promotion_programme_node';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'reverse_field_promotion_programme_node';
  $handler->display->display_options['fields']['status']['label'] = 'Published promotion';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  /* Sort criterion: Content: Promoted to front page */
  $handler->display->display_options['sorts']['promote']['id'] = 'promote';
  $handler->display->display_options['sorts']['promote']['table'] = 'node';
  $handler->display->display_options['sorts']['promote']['field'] = 'promote';
  $handler->display->display_options['sorts']['promote']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'programme' => 'programme',
  );
  /* Filter criterion: Content: Statut du programme (field_programme_statut) */
  $handler->display->display_options['filters']['field_programme_statut_value']['id'] = 'field_programme_statut_value';
  $handler->display->display_options['filters']['field_programme_statut_value']['table'] = 'field_data_field_programme_statut';
  $handler->display->display_options['filters']['field_programme_statut_value']['field'] = 'field_programme_statut_value';
  $handler->display->display_options['filters']['field_programme_statut_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Block Carrousel in homepage */
  $handler = $view->new_display('block', 'Block Carrousel in homepage', 'block');

  /* Display: Block bottom carrousel in programme Page */
  $handler = $view->new_display('block', 'Block bottom carrousel in programme Page', 'block_1');
  $handler->display->display_options['display_description'] = 'Having the carrousel nottom of programm page  on the program page the carousel display the other program from the same "region" ';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  $translatables['nos_dernieres_offres'] = array(
    t('Master'),
    t('Nos dernières offres'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content referencing Content from field_promotion_programme'),
    t('Image Principale'),
    t('Départment'),
    t('Ville'),
    t('Programme lié:'),
    t('Date de début'),
    t('Date de fin'),
    t('Mentions Légales'),
    t('Nid'),
    t('Title'),
    t('Published promotion'),
    t('Block Carrousel in homepage'),
    t('Block bottom carrousel in programme Page'),
    t('Having the carrousel nottom of programm page  on the program page the carousel display the other program from the same "region" '),
    t('All'),
  );
  $export['nos_dernieres_offres'] = $view;

  return $export;
}
