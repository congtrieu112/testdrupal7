<?php
/**
 * @file
 * k_b_rh_annonce.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function k_b_rh_annonce_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nos_derni_res_offres_d_emploi';
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
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '';
  $handler->display->display_options['pager']['options']['tags']['next'] = '';
  $handler->display->display_options['pager']['options']['tags']['last'] = '';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser_inline';
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_annonce_date_mise_en_ligne|field_annonce_date_mise_en_ligne_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser_inline';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Date de mise en ligne (field_annonce_date_mise_en_ligne) */
  $handler->display->display_options['sorts']['field_annonce_date_mise_en_ligne_value']['id'] = 'field_annonce_date_mise_en_ligne_value';
  $handler->display->display_options['sorts']['field_annonce_date_mise_en_ligne_value']['table'] = 'field_data_field_annonce_date_mise_en_ligne';
  $handler->display->display_options['sorts']['field_annonce_date_mise_en_ligne_value']['field'] = 'field_annonce_date_mise_en_ligne_value';
  $handler->display->display_options['sorts']['field_annonce_date_mise_en_ligne_value']['order'] = 'DESC';
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
  /* Filter criterion: Content: Expérience exigée (field_annonce_experience) */
  $handler->display->display_options['filters']['field_annonce_experience_tid']['id'] = 'field_annonce_experience_tid';
  $handler->display->display_options['filters']['field_annonce_experience_tid']['table'] = 'field_data_field_annonce_experience';
  $handler->display->display_options['filters']['field_annonce_experience_tid']['field'] = 'field_annonce_experience_tid';
  $handler->display->display_options['filters']['field_annonce_experience_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_annonce_experience_tid']['expose']['operator_id'] = 'field_annonce_experience_tid_op';
  $handler->display->display_options['filters']['field_annonce_experience_tid']['expose']['label'] = 'Expérience';
  $handler->display->display_options['filters']['field_annonce_experience_tid']['expose']['operator'] = 'field_annonce_experience_tid_op';
  $handler->display->display_options['filters']['field_annonce_experience_tid']['expose']['identifier'] = 'field_annonce_experience_tid';
  $handler->display->display_options['filters']['field_annonce_experience_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_annonce_experience_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_annonce_experience_tid']['vocabulary'] = 'rh_experience_exigee';
  $handler->display->display_options['filters']['field_annonce_experience_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Fonction (field_annonce_fonction) */
  $handler->display->display_options['filters']['field_annonce_fonction_tid']['id'] = 'field_annonce_fonction_tid';
  $handler->display->display_options['filters']['field_annonce_fonction_tid']['table'] = 'field_data_field_annonce_fonction';
  $handler->display->display_options['filters']['field_annonce_fonction_tid']['field'] = 'field_annonce_fonction_tid';
  $handler->display->display_options['filters']['field_annonce_fonction_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_annonce_fonction_tid']['expose']['operator_id'] = 'field_annonce_fonction_tid_op';
  $handler->display->display_options['filters']['field_annonce_fonction_tid']['expose']['label'] = 'Fonction';
  $handler->display->display_options['filters']['field_annonce_fonction_tid']['expose']['operator'] = 'field_annonce_fonction_tid_op';
  $handler->display->display_options['filters']['field_annonce_fonction_tid']['expose']['identifier'] = 'field_annonce_fonction_tid';
  $handler->display->display_options['filters']['field_annonce_fonction_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_annonce_fonction_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_annonce_fonction_tid']['vocabulary'] = 'rh_fonction';
  $handler->display->display_options['filters']['field_annonce_fonction_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type de contrat (field_annonce_type_contrat) */
  $handler->display->display_options['filters']['field_annonce_type_contrat_tid']['id'] = 'field_annonce_type_contrat_tid';
  $handler->display->display_options['filters']['field_annonce_type_contrat_tid']['table'] = 'field_data_field_annonce_type_contrat';
  $handler->display->display_options['filters']['field_annonce_type_contrat_tid']['field'] = 'field_annonce_type_contrat_tid';
  $handler->display->display_options['filters']['field_annonce_type_contrat_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_annonce_type_contrat_tid']['expose']['operator_id'] = 'field_annonce_type_contrat_tid_op';
  $handler->display->display_options['filters']['field_annonce_type_contrat_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_annonce_type_contrat_tid']['expose']['operator'] = 'field_annonce_type_contrat_tid_op';
  $handler->display->display_options['filters']['field_annonce_type_contrat_tid']['expose']['identifier'] = 'field_annonce_type_contrat_tid';
  $handler->display->display_options['filters']['field_annonce_type_contrat_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_annonce_type_contrat_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_annonce_type_contrat_tid']['vocabulary'] = 'rh_type_contrat';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nos-dernieres-offres-d-emploi';
  $translatables['nos_derni_res_offres_d_emploi'] = array(
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
    t('Expérience'),
    t('Fonction'),
    t('Type'),
    t('Page'),
  );
  $export['nos_derni_res_offres_d_emploi'] = $view;

  return $export;
}
