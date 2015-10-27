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
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
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
  /* Field: Content: Département */
  $handler->display->display_options['fields']['field_espace_vente_dpt']['id'] = 'field_espace_vente_dpt';
  $handler->display->display_options['fields']['field_espace_vente_dpt']['table'] = 'field_data_field_espace_vente_dpt';
  $handler->display->display_options['fields']['field_espace_vente_dpt']['field'] = 'field_espace_vente_dpt';
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
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
    t('Département'),
    t('Ville'),
    t('Programme lié:'),
    t('Date de début'),
    t('Date de fin'),
    t('Mentions Légales'),
    t('Nid'),
    t('Title'),
    t('Block'),
  );
  $export['nos_dernieres_offres'] = $view;

  return $export;
}
