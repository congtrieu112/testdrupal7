<?php
/**
 * @file
 * kandb_view_nouveaute.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function kandb_view_nouveaute_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nouveaute';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Nouveaute';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Nouveaute';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
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
  $handler->display->display_options['fields']['field_image_principale']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_principale']['settings'] = array(
    'image_style' => 'programme_teaser_3',
    'image_link' => '',
  );
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
  /* Filter criterion: Content: Date de mise en ligne (field_programme_online_date) */
  $handler->display->display_options['filters']['field_programme_online_date_value']['id'] = 'field_programme_online_date_value';
  $handler->display->display_options['filters']['field_programme_online_date_value']['table'] = 'field_data_field_programme_online_date';
  $handler->display->display_options['filters']['field_programme_online_date_value']['field'] = 'field_programme_online_date_value';
  $handler->display->display_options['filters']['field_programme_online_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_programme_online_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_online_date_value']['expose']['operator_id'] = 'field_programme_online_date_value_op';
  $handler->display->display_options['filters']['field_programme_online_date_value']['expose']['label'] = 'Date de mise en ligne (field_programme_online_date)';
  $handler->display->display_options['filters']['field_programme_online_date_value']['expose']['operator'] = 'field_programme_online_date_value_op';
  $handler->display->display_options['filters']['field_programme_online_date_value']['expose']['identifier'] = 'field_programme_online_date_value';
  $handler->display->display_options['filters']['field_programme_online_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_programme_online_date_value']['default_date'] = 'now - 60 day';
  $handler->display->display_options['filters']['field_programme_online_date_value']['default_to_date'] = 'now';

  /* Display: Block Nouveaute */
  $handler = $view->new_display('block', 'Block Nouveaute', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Nouveaute';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '200';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
  /* Filter criterion: Content: Date de mise en ligne (field_programme_online_date) */
  $handler->display->display_options['filters']['field_programme_online_date_value']['id'] = 'field_programme_online_date_value';
  $handler->display->display_options['filters']['field_programme_online_date_value']['table'] = 'field_data_field_programme_online_date';
  $handler->display->display_options['filters']['field_programme_online_date_value']['field'] = 'field_programme_online_date_value';
  $handler->display->display_options['filters']['field_programme_online_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_programme_online_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_online_date_value']['expose']['operator_id'] = 'field_programme_online_date_value_op';
  $handler->display->display_options['filters']['field_programme_online_date_value']['expose']['label'] = 'Date de mise en ligne (field_programme_online_date)';
  $handler->display->display_options['filters']['field_programme_online_date_value']['expose']['operator'] = 'field_programme_online_date_value_op';
  $handler->display->display_options['filters']['field_programme_online_date_value']['expose']['identifier'] = 'field_programme_online_date_value';
  $handler->display->display_options['filters']['field_programme_online_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_programme_online_date_value']['default_date'] = 'now - 60 day';
  $handler->display->display_options['filters']['field_programme_online_date_value']['default_to_date'] = 'now';
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $translatables['nouveaute'] = array(
    t('Master'),
    t('Nouveaute'),
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
    t('Image Principale'),
    t('Ville'),
    t('Départment'),
    t('Title'),
    t('Date de début'),
    t('Date de fin'),
    t('Published'),
    t('Nid'),
    t('Mentions Légales'),
    t('Date de mise en ligne (field_programme_online_date)'),
    t('Block Nouveaute'),
  );
  $export['nouveaute'] = $view;

  return $export;
}
