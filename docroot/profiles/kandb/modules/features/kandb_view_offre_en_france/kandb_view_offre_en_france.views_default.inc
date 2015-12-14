<?php
/**
 * @file
 * kandb_view_offre_en_france.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function kandb_view_offre_en_france_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'notre_offre_en_france';
  $view->description = '- create OFFRE page "Notre offre en France", which is to show a list of programmes that have at least 1 available bien';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Notre offre en France';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Notre offre en France';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '200';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_programme_target_id']['id'] = 'field_programme_target_id';
  $handler->display->display_options['relationships']['field_programme_target_id']['table'] = 'field_data_field_programme';
  $handler->display->display_options['relationships']['field_programme_target_id']['field'] = 'field_programme_target_id';
  $handler->display->display_options['relationships']['field_programme_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_promotion_programme_node']['id'] = 'reverse_field_promotion_programme_node';
  $handler->display->display_options['relationships']['reverse_field_promotion_programme_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_promotion_programme_node']['field'] = 'reverse_field_promotion_programme_node';
  $handler->display->display_options['relationships']['reverse_field_promotion_programme_node']['relationship'] = 'field_programme_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_programme_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_programme_target_id';
  /* Field: Content: Départment */
  $handler->display->display_options['fields']['field_programme_loc_department']['id'] = 'field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_loc_department']['table'] = 'field_data_field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_loc_department']['field'] = 'field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_loc_department']['relationship'] = 'field_programme_target_id';
  /* Field: Content: Image Principale */
  $handler->display->display_options['fields']['field_image_principale']['id'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['table'] = 'field_data_field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['field'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['relationship'] = 'field_programme_target_id';
  $handler->display->display_options['fields']['field_image_principale']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_principale']['settings'] = array(
    'image_style' => 'programme_teaser_3',
    'image_link' => '',
  );
  /* Field: Content: Ville */
  $handler->display->display_options['fields']['field_programme_loc_ville']['id'] = 'field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_loc_ville']['table'] = 'field_data_field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_loc_ville']['field'] = 'field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_loc_ville']['relationship'] = 'field_programme_target_id';
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
  /* Field: Content: Mentions Légales */
  $handler->display->display_options['fields']['field_promotion_mention_legale']['id'] = 'field_promotion_mention_legale';
  $handler->display->display_options['fields']['field_promotion_mention_legale']['table'] = 'field_data_field_promotion_mention_legale';
  $handler->display->display_options['fields']['field_promotion_mention_legale']['field'] = 'field_promotion_mention_legale';
  $handler->display->display_options['fields']['field_promotion_mention_legale']['relationship'] = 'reverse_field_promotion_programme_node';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'reverse_field_promotion_programme_node';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Sort criterion: Content: Date de mise en ligne (field_programme_online_date) */
  $handler->display->display_options['sorts']['field_programme_online_date_value']['id'] = 'field_programme_online_date_value';
  $handler->display->display_options['sorts']['field_programme_online_date_value']['table'] = 'field_data_field_programme_online_date';
  $handler->display->display_options['sorts']['field_programme_online_date_value']['field'] = 'field_programme_online_date_value';
  $handler->display->display_options['sorts']['field_programme_online_date_value']['relationship'] = 'field_programme_target_id';
  $handler->display->display_options['sorts']['field_programme_online_date_value']['order'] = 'DESC';
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
    'bien' => 'bien',
  );

  /* Display: Notre offre en France list */
  $handler = $view->new_display('block', 'Notre offre en France list', 'block');
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
    'bien' => 'bien',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $translatables['notre_offre_en_france'] = array(
    t('Master'),
    t('Notre offre en France'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_programme'),
    t('Content referencing Content from field_promotion_programme'),
    t('Nid'),
    t('Départment'),
    t('Image Principale'),
    t('Ville'),
    t('Title'),
    t('Date de début'),
    t('Date de fin'),
    t('Mentions Légales'),
    t('Published'),
    t('Notre offre en France list'),
  );
  $export['notre_offre_en_france'] = $view;

  return $export;
}
