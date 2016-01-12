<?php
/**
 * @file
 * kandb_views_habitat_carousel.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function kandb_views_habitat_carousel_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'habitat_carrousel';
  $view->description = 'Add the new carrousel at the bottom of the homepage to display Habitat. ';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Habitat carrousel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Habitat carousel';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_habitat_image']['id'] = 'field_habitat_image';
  $handler->display->display_options['fields']['field_habitat_image']['table'] = 'field_data_field_habitat_image';
  $handler->display->display_options['fields']['field_habitat_image']['field'] = 'field_habitat_image';
  $handler->display->display_options['fields']['field_habitat_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_habitat_image']['settings'] = array(
    'image_style' => 'programme_selection_medium',
    'image_link' => '',
  );
  /* Field: Content: Departement */
  $handler->display->display_options['fields']['field_habitat_departement']['id'] = 'field_habitat_departement';
  $handler->display->display_options['fields']['field_habitat_departement']['table'] = 'field_data_field_habitat_departement';
  $handler->display->display_options['fields']['field_habitat_departement']['field'] = 'field_habitat_departement';
  /* Field: Content: Ville */
  $handler->display->display_options['fields']['field_habitat_ville']['id'] = 'field_habitat_ville';
  $handler->display->display_options['fields']['field_habitat_ville']['table'] = 'field_data_field_habitat_ville';
  $handler->display->display_options['fields']['field_habitat_ville']['field'] = 'field_habitat_ville';
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
    'habitat' => 'habitat',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['habitat_carrousel'] = array(
    t('Master'),
    t('Habitat carousel'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Image'),
    t('Departement'),
    t('Ville'),
    t('Block'),
  );
  $export['habitat_carrousel'] = $view;

  return $export;
}
