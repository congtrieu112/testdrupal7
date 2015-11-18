<?php
/**
 * @file
 * kandb_views_avant_premiere.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function kandb_views_avant_premiere_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'avant_premiere_check';
  $view->description = 'Avant Première with Grande ouverture checked';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Avant Première';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Avant Première';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_promotion_avant_premiere_node']['id'] = 'reverse_field_promotion_avant_premiere_node';
  $handler->display->display_options['relationships']['reverse_field_promotion_avant_premiere_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_promotion_avant_premiere_node']['field'] = 'reverse_field_promotion_avant_premiere_node';
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
  $handler->display->display_options['fields']['field_avant_premiere_image_princ']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_avant_premiere_image_princ']['settings'] = array(
    'image_style' => 'programme_teaser_3',
    'image_link' => '',
  );
  /* Field: Content: Ville */
  $handler->display->display_options['fields']['field_avant_premiere_ville']['id'] = 'field_avant_premiere_ville';
  $handler->display->display_options['fields']['field_avant_premiere_ville']['table'] = 'field_data_field_avant_premiere_ville';
  $handler->display->display_options['fields']['field_avant_premiere_ville']['field'] = 'field_avant_premiere_ville';
  /* Field: Content: Département */
  $handler->display->display_options['fields']['field_avant_premiere_department']['id'] = 'field_avant_premiere_department';
  $handler->display->display_options['fields']['field_avant_premiere_department']['table'] = 'field_data_field_avant_premiere_department';
  $handler->display->display_options['fields']['field_avant_premiere_department']['field'] = 'field_avant_premiere_department';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_promotion_avant_premiere_node';
  $handler->display->display_options['fields']['title_1']['label'] = 'Title Promotion';
  /* Field: Content: Date de début */
  $handler->display->display_options['fields']['field_promotion_start']['id'] = 'field_promotion_start';
  $handler->display->display_options['fields']['field_promotion_start']['table'] = 'field_data_field_promotion_start';
  $handler->display->display_options['fields']['field_promotion_start']['field'] = 'field_promotion_start';
  $handler->display->display_options['fields']['field_promotion_start']['relationship'] = 'reverse_field_promotion_avant_premiere_node';
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
  $handler->display->display_options['fields']['field_promotion_stop']['relationship'] = 'reverse_field_promotion_avant_premiere_node';
  $handler->display->display_options['fields']['field_promotion_stop']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_promotion_avant_premiere_node';
  $handler->display->display_options['fields']['nid']['label'] = 'Nid promotion';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'reverse_field_promotion_avant_premiere_node';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Mentions Légales */
  $handler->display->display_options['fields']['field_promotion_mention_legale']['id'] = 'field_promotion_mention_legale';
  $handler->display->display_options['fields']['field_promotion_mention_legale']['table'] = 'field_data_field_promotion_mention_legale';
  $handler->display->display_options['fields']['field_promotion_mention_legale']['field'] = 'field_promotion_mention_legale';
  $handler->display->display_options['fields']['field_promotion_mention_legale']['relationship'] = 'reverse_field_promotion_avant_premiere_node';
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
    'avant_premiere' => 'avant_premiere',
  );
  /* Filter criterion: Content: Grande ouverture (field_avant_premiere_grande_ouve) */
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['id'] = 'field_avant_premiere_grande_ouve_value';
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['table'] = 'field_data_field_avant_premiere_grande_ouve';
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['field'] = 'field_avant_premiere_grande_ouve_value';
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['value'] = array(
    1 => '1',
  );

  /* Display: Avant Première by checked */
  $handler = $view->new_display('block', 'Avant Première by checked', 'block');
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
  /* Filter criterion: Content: Grande ouverture (field_avant_premiere_grande_ouve) */
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['id'] = 'field_avant_premiere_grande_ouve_value';
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['table'] = 'field_data_field_avant_premiere_grande_ouve';
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['field'] = 'field_avant_premiere_grande_ouve_value';
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['value'] = array(
    1 => '1',
  );

  /* Display: Avant Première by unchecked */
  $handler = $view->new_display('block', 'Avant Première by unchecked', 'block_1');
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
  /* Filter criterion: Content: Grande ouverture (field_avant_premiere_grande_ouve) */
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['id'] = 'field_avant_premiere_grande_ouve_value';
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['table'] = 'field_data_field_avant_premiere_grande_ouve';
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['field'] = 'field_avant_premiere_grande_ouve_value';
  $handler->display->display_options['filters']['field_avant_premiere_grande_ouve_value']['value'] = array(
    0 => '0',
  );
  $translatables['avant_premiere_check'] = array(
    t('Master'),
    t('Avant Première'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content referencing Content from field_promotion_avant_premiere'),
    t('Image Principale'),
    t('Ville'),
    t('Département'),
    t('Title Promotion'),
    t('Date de début'),
    t('Date de fin'),
    t('Nid promotion'),
    t('Published'),
    t('Mentions Légales'),
    t('Avant Première by checked'),
    t('Avant Première by unchecked'),
  );
  $export['avant_premiere_check'] = $view;

  return $export;
}
