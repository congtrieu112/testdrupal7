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
  /* Field: Content: Image Principale */
  $handler->display->display_options['fields']['field_image_principale']['id'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['table'] = 'field_data_field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['field'] = 'field_image_principale';
  $handler->display->display_options['fields']['field_image_principale']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_principale']['settings'] = array(
    'image_style' => '',
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
  $handler->display->display_options['filters']['field_programme_online_date_value']['operator'] = '>=';
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
  $handler->display->display_options['filters']['field_programme_online_date_value']['default_date'] = 'now - 30 day';

  /* Display: Block Nouveaute */
  $handler = $view->new_display('block', 'Block Nouveaute', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Nouveaute';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
    t('Date de mise en ligne (field_programme_online_date)'),
    t('Block Nouveaute'),
  );
  $export['nouveaute'] = $view;

  return $export;
}
