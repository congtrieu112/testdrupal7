<?php
/**
 * @file
 * kandb_view_rh_dernieres_offres_emploi.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function kandb_view_rh_dernieres_offres_emploi_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nos_dernieres_offres_emploi';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Nos dernières offres d\'emploi';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Nos dernières offres d\'emploi';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date de démarrage */
  $handler->display->display_options['fields']['field_annonce_date_debut']['id'] = 'field_annonce_date_debut';
  $handler->display->display_options['fields']['field_annonce_date_debut']['table'] = 'field_data_field_annonce_date_debut';
  $handler->display->display_options['fields']['field_annonce_date_debut']['field'] = 'field_annonce_date_debut';
  $handler->display->display_options['fields']['field_annonce_date_debut']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date de mise en ligne */
  $handler->display->display_options['fields']['field_annonce_date_mise_en_ligne']['id'] = 'field_annonce_date_mise_en_ligne';
  $handler->display->display_options['fields']['field_annonce_date_mise_en_ligne']['table'] = 'field_data_field_annonce_date_mise_en_ligne';
  $handler->display->display_options['fields']['field_annonce_date_mise_en_ligne']['field'] = 'field_annonce_date_mise_en_ligne';
  $handler->display->display_options['fields']['field_annonce_date_mise_en_ligne']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_annonce_description']['id'] = 'field_annonce_description';
  $handler->display->display_options['fields']['field_annonce_description']['table'] = 'field_data_field_annonce_description';
  $handler->display->display_options['fields']['field_annonce_description']['field'] = 'field_annonce_description';
  /* Field: Content: Expérience exigée */
  $handler->display->display_options['fields']['field_annonce_experience']['id'] = 'field_annonce_experience';
  $handler->display->display_options['fields']['field_annonce_experience']['table'] = 'field_data_field_annonce_experience';
  $handler->display->display_options['fields']['field_annonce_experience']['field'] = 'field_annonce_experience';
  /* Field: Content: Fonction */
  $handler->display->display_options['fields']['field_annonce_fonction']['id'] = 'field_annonce_fonction';
  $handler->display->display_options['fields']['field_annonce_fonction']['table'] = 'field_data_field_annonce_fonction';
  $handler->display->display_options['fields']['field_annonce_fonction']['field'] = 'field_annonce_fonction';
  /* Field: Content: Profile requis */
  $handler->display->display_options['fields']['field_annonce_profile']['id'] = 'field_annonce_profile';
  $handler->display->display_options['fields']['field_annonce_profile']['table'] = 'field_data_field_annonce_profile';
  $handler->display->display_options['fields']['field_annonce_profile']['field'] = 'field_annonce_profile';
  /* Field: Content: Service */
  $handler->display->display_options['fields']['field_annonce_service']['id'] = 'field_annonce_service';
  $handler->display->display_options['fields']['field_annonce_service']['table'] = 'field_data_field_annonce_service';
  $handler->display->display_options['fields']['field_annonce_service']['field'] = 'field_annonce_service';
  /* Field: Content: Type de contrat */
  $handler->display->display_options['fields']['field_annonce_type_contrat']['id'] = 'field_annonce_type_contrat';
  $handler->display->display_options['fields']['field_annonce_type_contrat']['table'] = 'field_data_field_annonce_type_contrat';
  $handler->display->display_options['fields']['field_annonce_type_contrat']['field'] = 'field_annonce_type_contrat';
  /* Field: Content: Ville */
  $handler->display->display_options['fields']['field_annonce_ville']['id'] = 'field_annonce_ville';
  $handler->display->display_options['fields']['field_annonce_ville']['table'] = 'field_data_field_annonce_ville';
  $handler->display->display_options['fields']['field_annonce_ville']['field'] = 'field_annonce_ville';
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
    'rh_annonce' => 'rh_annonce',
  );
  /* Filter criterion: Content: Date de démarrage (field_annonce_date_debut) */
  $handler->display->display_options['filters']['field_annonce_date_debut_value']['id'] = 'field_annonce_date_debut_value';
  $handler->display->display_options['filters']['field_annonce_date_debut_value']['table'] = 'field_data_field_annonce_date_debut';
  $handler->display->display_options['filters']['field_annonce_date_debut_value']['field'] = 'field_annonce_date_debut_value';
  $handler->display->display_options['filters']['field_annonce_date_debut_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_annonce_date_debut_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_annonce_date_debut_value']['year_range'] = '-10:+0';

  /* Display: Block Last offers in RH Annonce Page */
  $handler = $view->new_display('block', 'Block Last offers in RH Annonce Page', 'block');
  $translatables['nos_dernieres_offres_emploi'] = array(
    t('Master'),
    t('Nos dernières offres d\'emploi'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Date de démarrage'),
    t('Date de mise en ligne'),
    t('Description'),
    t('Expérience exigée'),
    t('Fonction'),
    t('Profile requis'),
    t('Service'),
    t('Type de contrat'),
    t('Ville'),
    t('Block Last offers in RH Annonce Page'),
  );
  $export['nos_dernieres_offres_emploi'] = $view;

  return $export;
}
