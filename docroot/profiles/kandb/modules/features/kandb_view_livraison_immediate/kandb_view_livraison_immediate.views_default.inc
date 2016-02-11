<?php
/**
 * @file
 * kandb_view_livraison_immediate.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function kandb_view_livraison_immediate_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'livraison_immediate';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Livraison Immediate';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Livraison Immediate';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time_per_domain';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '0';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '200';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Image Principale */
  $handler->display->display_options['fields']['field_image_principale']['id'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['table'] = 'field_data_field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['field'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_principale']['settings'] = array(
    'image_style' => 'programme_teaser_3',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Ville */
  $handler->display->display_options['fields']['field_programme_loc_ville']['id'] = 'field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_loc_ville']['table'] = 'field_data_field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_loc_ville']['field'] = 'field_programme_loc_ville';
  /* Field: Content: Départment */
  $handler->display->display_options['fields']['field_programme_loc_department']['id'] = 'field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_loc_department']['table'] = 'field_data_field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_loc_department']['field'] = 'field_programme_loc_department';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_promotion_programme_node';
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
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'reverse_field_promotion_programme_node';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_promotion_programme_node';
  /* Field: Content: Mentions Légales */
  $handler->display->display_options['fields']['field_promotion_mention_legale']['id'] = 'field_promotion_mention_legale';
  $handler->display->display_options['fields']['field_promotion_mention_legale']['table'] = 'field_data_field_promotion_mention_legale';
  $handler->display->display_options['fields']['field_promotion_mention_legale']['field'] = 'field_promotion_mention_legale';
  $handler->display->display_options['fields']['field_promotion_mention_legale']['relationship'] = 'reverse_field_promotion_programme_node';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Content: Année (field_annee) */
  $handler->display->display_options['filters']['field_annee_value']['id'] = 'field_annee_value';
  $handler->display->display_options['filters']['field_annee_value']['table'] = 'field_data_field_annee';
  $handler->display->display_options['filters']['field_annee_value']['field'] = 'field_annee_value';
  $handler->display->display_options['filters']['field_annee_value']['value']['value'] = '2015';
  $handler->display->display_options['filters']['field_annee_value']['group'] = 1;
  $handler->display->display_options['filters']['field_annee_value']['expose']['operator_id'] = 'field_annee_value_op';
  $handler->display->display_options['filters']['field_annee_value']['expose']['label'] = 'Année (field_annee)';
  $handler->display->display_options['filters']['field_annee_value']['expose']['operator'] = 'field_annee_value_op';
  $handler->display->display_options['filters']['field_annee_value']['expose']['identifier'] = 'field_annee_value';
  $handler->display->display_options['filters']['field_annee_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_annee_value']['group_info']['label'] = 'Année (field_annee)';
  $handler->display->display_options['filters']['field_annee_value']['group_info']['identifier'] = 'field_annee_value';
  $handler->display->display_options['filters']['field_annee_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_annee_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Trimestre (field_trimestre) */
  $handler->display->display_options['filters']['field_trimestre_value']['id'] = 'field_trimestre_value';
  $handler->display->display_options['filters']['field_trimestre_value']['table'] = 'field_data_field_trimestre';
  $handler->display->display_options['filters']['field_trimestre_value']['field'] = 'field_trimestre_value';
  $handler->display->display_options['filters']['field_trimestre_value']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_trimestre_value']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Année (field_annee) */
  $handler->display->display_options['filters']['field_annee_value_1']['id'] = 'field_annee_value_1';
  $handler->display->display_options['filters']['field_annee_value_1']['table'] = 'field_data_field_annee';
  $handler->display->display_options['filters']['field_annee_value_1']['field'] = 'field_annee_value';
  $handler->display->display_options['filters']['field_annee_value_1']['value']['value'] = '2016';
  $handler->display->display_options['filters']['field_annee_value_1']['group'] = 2;
  /* Filter criterion: Content: Trimestre (field_trimestre) */
  $handler->display->display_options['filters']['field_trimestre_value_1']['id'] = 'field_trimestre_value_1';
  $handler->display->display_options['filters']['field_trimestre_value_1']['table'] = 'field_data_field_trimestre';
  $handler->display->display_options['filters']['field_trimestre_value_1']['field'] = 'field_trimestre_value';
  $handler->display->display_options['filters']['field_trimestre_value_1']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_trimestre_value_1']['group'] = 2;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 2;

  /* Display: Livraison Immediate */
  $handler = $view->new_display('block', 'Livraison Immediate', 'block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Année (field_annee) */
  $handler->display->display_options['filters']['field_annee_value']['id'] = 'field_annee_value';
  $handler->display->display_options['filters']['field_annee_value']['table'] = 'field_data_field_annee';
  $handler->display->display_options['filters']['field_annee_value']['field'] = 'field_annee_value';
  $handler->display->display_options['filters']['field_annee_value']['value']['value'] = '2015';
  $handler->display->display_options['filters']['field_annee_value']['group'] = 1;
  $handler->display->display_options['filters']['field_annee_value']['expose']['operator_id'] = 'field_annee_value_op';
  $handler->display->display_options['filters']['field_annee_value']['expose']['label'] = 'Année (field_annee)';
  $handler->display->display_options['filters']['field_annee_value']['expose']['operator'] = 'field_annee_value_op';
  $handler->display->display_options['filters']['field_annee_value']['expose']['identifier'] = 'field_annee_value';
  $handler->display->display_options['filters']['field_annee_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_annee_value']['group_info']['label'] = 'Année (field_annee)';
  $handler->display->display_options['filters']['field_annee_value']['group_info']['identifier'] = 'field_annee_value';
  $handler->display->display_options['filters']['field_annee_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_annee_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Trimestre (field_trimestre) */
  $handler->display->display_options['filters']['field_trimestre_value']['id'] = 'field_trimestre_value';
  $handler->display->display_options['filters']['field_trimestre_value']['table'] = 'field_data_field_trimestre';
  $handler->display->display_options['filters']['field_trimestre_value']['field'] = 'field_trimestre_value';
  $handler->display->display_options['filters']['field_trimestre_value']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_trimestre_value']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  /* Filter criterion: Content: Année (field_annee) */
  $handler->display->display_options['filters']['field_annee_value_1']['id'] = 'field_annee_value_1';
  $handler->display->display_options['filters']['field_annee_value_1']['table'] = 'field_data_field_annee';
  $handler->display->display_options['filters']['field_annee_value_1']['field'] = 'field_annee_value';
  $handler->display->display_options['filters']['field_annee_value_1']['value']['value'] = '2016';
  $handler->display->display_options['filters']['field_annee_value_1']['group'] = 2;
  /* Filter criterion: Content: Trimestre (field_trimestre) */
  $handler->display->display_options['filters']['field_trimestre_value_1']['id'] = 'field_trimestre_value_1';
  $handler->display->display_options['filters']['field_trimestre_value_1']['table'] = 'field_data_field_trimestre';
  $handler->display->display_options['filters']['field_trimestre_value_1']['field'] = 'field_trimestre_value';
  $handler->display->display_options['filters']['field_trimestre_value_1']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_trimestre_value_1']['group'] = 2;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 2;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all_1']['id'] = 'current_all_1';
  $handler->display->display_options['filters']['current_all_1']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all_1']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all_1']['value'] = '1';
  $handler->display->display_options['filters']['current_all_1']['group'] = 2;
  $translatables['livraison_immediate'] = array(
    t('Master'),
    t('Livraison Immediate'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Image Principale'),
    t('Ville'),
    t('Départment'),
    t('Title'),
    t('Date de début'),
    t('Date de fin'),
    t('Published'),
    t('Nid'),
    t('Mentions Légales'),
    t('Année (field_annee)'),
  );
  $export['livraison_immediate'] = $view;

  return $export;
}
