<?php
/**
 * @file
 * kandb_recherche.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function kandb_recherche_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'block_search_b2c';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Block search B2C';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Block search B2C';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
    'bien' => 'bien',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['block_search_b2c'] = array(
    t('Master'),
    t('Block search B2C'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
  );
  $export['block_search_b2c'] = $view;

  $view = new view();
  $view->name = 'search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Test If Programme Beggining by Exists';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title_1' => 'title_1',
    'title' => 'title',
    'field_type' => 'field_type',
    'field_prix_tva_20' => 'field_prix_tva_20',
    'field_nb_pieces' => 'field_nb_pieces',
    'field_superficie' => 'field_superficie',
    'field_caracteristique' => 'field_caracteristique',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_prix_tva_20' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_nb_pieces' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_superficie' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_caracteristique' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_programme_node']['id'] = 'reverse_field_programme_node';
  $handler->display->display_options['relationships']['reverse_field_programme_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_programme_node']['field'] = 'reverse_field_programme_node';
  $handler->display->display_options['relationships']['reverse_field_programme_node']['label'] = 'Bien referencing Programme on CT Bien';
  $handler->display->display_options['relationships']['reverse_field_programme_node']['required'] = TRUE;
  /* Relationship: Content: Ville (field_programme_loc_ville) */
  $handler->display->display_options['relationships']['field_programme_loc_ville_tid']['id'] = 'field_programme_loc_ville_tid';
  $handler->display->display_options['relationships']['field_programme_loc_ville_tid']['table'] = 'field_data_field_programme_loc_ville';
  $handler->display->display_options['relationships']['field_programme_loc_ville_tid']['field'] = 'field_programme_loc_ville_tid';
  $handler->display->display_options['relationships']['field_programme_loc_ville_tid']['label'] = 'Term from field_programme_loc_ville';
  /* Relationship: Content: Region (field_programme_loc_region) */
  $handler->display->display_options['relationships']['field_programme_loc_region_tid']['id'] = 'field_programme_loc_region_tid';
  $handler->display->display_options['relationships']['field_programme_loc_region_tid']['table'] = 'field_data_field_programme_loc_region';
  $handler->display->display_options['relationships']['field_programme_loc_region_tid']['field'] = 'field_programme_loc_region_tid';
  $handler->display->display_options['relationships']['field_programme_loc_region_tid']['label'] = 'Term from field_programme_loc_region';
  /* Relationship: Content: Départment (field_programme_loc_department) */
  $handler->display->display_options['relationships']['field_programme_loc_department_tid']['id'] = 'field_programme_loc_department_tid';
  $handler->display->display_options['relationships']['field_programme_loc_department_tid']['table'] = 'field_data_field_programme_loc_department';
  $handler->display->display_options['relationships']['field_programme_loc_department_tid']['field'] = 'field_programme_loc_department_tid';
  $handler->display->display_options['relationships']['field_programme_loc_department_tid']['label'] = 'Term from field_programme_loc_department';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Statut du bien (field_bien_statut) */
  $handler->display->display_options['filters']['field_bien_statut_tid']['id'] = 'field_bien_statut_tid';
  $handler->display->display_options['filters']['field_bien_statut_tid']['table'] = 'field_data_field_bien_statut';
  $handler->display->display_options['filters']['field_bien_statut_tid']['field'] = 'field_bien_statut_tid';
  $handler->display->display_options['filters']['field_bien_statut_tid']['relationship'] = 'reverse_field_programme_node';
  $handler->display->display_options['filters']['field_bien_statut_tid']['value'] = array(
    0 => '207',
  );
  $handler->display->display_options['filters']['field_bien_statut_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_bien_statut_tid']['vocabulary'] = 'status_logement';
  /* Filter criterion: Content: Statut du programme (field_programme_statut) */
  $handler->display->display_options['filters']['field_programme_statut_value']['id'] = 'field_programme_statut_value';
  $handler->display->display_options['filters']['field_programme_statut_value']['table'] = 'field_data_field_programme_statut';
  $handler->display->display_options['filters']['field_programme_statut_value']['field'] = 'field_programme_statut_value';
  $handler->display->display_options['filters']['field_programme_statut_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_programme_statut_value']['group'] = 1;
  /* Filter criterion: Content: Type de Bien (field_type) */
  $handler->display->display_options['filters']['field_type_tid']['id'] = 'field_type_tid';
  $handler->display->display_options['filters']['field_type_tid']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_tid']['field'] = 'field_type_tid';
  $handler->display->display_options['filters']['field_type_tid']['relationship'] = 'reverse_field_programme_node';
  $handler->display->display_options['filters']['field_type_tid']['value'] = '';
  $handler->display->display_options['filters']['field_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_tid']['expose']['operator_id'] = 'field_type_tid_op';
  $handler->display->display_options['filters']['field_type_tid']['expose']['label'] = 'Type de Bien (field_type)';
  $handler->display->display_options['filters']['field_type_tid']['expose']['operator'] = 'field_type_tid_op';
  $handler->display->display_options['filters']['field_type_tid']['expose']['identifier'] = 'field_type_tid';
  $handler->display->display_options['filters']['field_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_type_tid']['vocabulary'] = 'type_de_bien';
  $handler->display->display_options['filters']['field_type_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Nombre de pièces (field_nb_pieces) */
  $handler->display->display_options['filters']['field_nb_pieces_tid']['id'] = 'field_nb_pieces_tid';
  $handler->display->display_options['filters']['field_nb_pieces_tid']['table'] = 'field_data_field_nb_pieces';
  $handler->display->display_options['filters']['field_nb_pieces_tid']['field'] = 'field_nb_pieces_tid';
  $handler->display->display_options['filters']['field_nb_pieces_tid']['relationship'] = 'reverse_field_programme_node';
  $handler->display->display_options['filters']['field_nb_pieces_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_nb_pieces_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_nb_pieces_tid']['expose']['operator_id'] = 'field_nb_pieces_tid_op';
  $handler->display->display_options['filters']['field_nb_pieces_tid']['expose']['label'] = 'Nombre de pièces (field_nb_pieces)';
  $handler->display->display_options['filters']['field_nb_pieces_tid']['expose']['operator'] = 'field_nb_pieces_tid_op';
  $handler->display->display_options['filters']['field_nb_pieces_tid']['expose']['identifier'] = 'field_nb_pieces_tid';
  $handler->display->display_options['filters']['field_nb_pieces_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_nb_pieces_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_nb_pieces_tid']['group_info']['label'] = 'Nombre de pièces (field_nb_pieces)';
  $handler->display->display_options['filters']['field_nb_pieces_tid']['group_info']['identifier'] = 'field_nb_pieces_tid';
  $handler->display->display_options['filters']['field_nb_pieces_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_nb_pieces_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_nb_pieces_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_nb_pieces_tid']['vocabulary'] = 'nb_pieces';
  $handler->display->display_options['filters']['field_nb_pieces_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Superficie (field_superficie) */
  $handler->display->display_options['filters']['field_superficie_value']['id'] = 'field_superficie_value';
  $handler->display->display_options['filters']['field_superficie_value']['table'] = 'field_data_field_superficie';
  $handler->display->display_options['filters']['field_superficie_value']['field'] = 'field_superficie_value';
  $handler->display->display_options['filters']['field_superficie_value']['relationship'] = 'reverse_field_programme_node';
  $handler->display->display_options['filters']['field_superficie_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_superficie_value']['group'] = 1;
  $handler->display->display_options['filters']['field_superficie_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_superficie_value']['expose']['operator_id'] = 'field_superficie_value_op';
  $handler->display->display_options['filters']['field_superficie_value']['expose']['label'] = 'Superficie (field_superficie)';
  $handler->display->display_options['filters']['field_superficie_value']['expose']['operator'] = 'field_superficie_value_op';
  $handler->display->display_options['filters']['field_superficie_value']['expose']['identifier'] = 'field_superficie_value';
  $handler->display->display_options['filters']['field_superficie_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  /* Filter criterion: Content: Caractéristique (field_caracteristique) */
  $handler->display->display_options['filters']['field_caracteristique_tid']['id'] = 'field_caracteristique_tid';
  $handler->display->display_options['filters']['field_caracteristique_tid']['table'] = 'field_data_field_caracteristique';
  $handler->display->display_options['filters']['field_caracteristique_tid']['field'] = 'field_caracteristique_tid';
  $handler->display->display_options['filters']['field_caracteristique_tid']['relationship'] = 'reverse_field_programme_node';
  $handler->display->display_options['filters']['field_caracteristique_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_caracteristique_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_caracteristique_tid']['expose']['operator_id'] = 'field_caracteristique_tid_op';
  $handler->display->display_options['filters']['field_caracteristique_tid']['expose']['label'] = 'Caractéristique (field_caracteristique)';
  $handler->display->display_options['filters']['field_caracteristique_tid']['expose']['operator'] = 'field_caracteristique_tid_op';
  $handler->display->display_options['filters']['field_caracteristique_tid']['expose']['identifier'] = 'field_caracteristique_tid';
  $handler->display->display_options['filters']['field_caracteristique_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_caracteristique_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_caracteristique_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_caracteristique_tid']['vocabulary'] = 'caracteristiques';
  $handler->display->display_options['filters']['field_caracteristique_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['group'] = 2;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  /* Filter criterion: Content: Code Postal (field_programme_loc_cp) */
  $handler->display->display_options['filters']['field_programme_loc_cp_value']['id'] = 'field_programme_loc_cp_value';
  $handler->display->display_options['filters']['field_programme_loc_cp_value']['table'] = 'field_data_field_programme_loc_cp';
  $handler->display->display_options['filters']['field_programme_loc_cp_value']['field'] = 'field_programme_loc_cp_value';
  $handler->display->display_options['filters']['field_programme_loc_cp_value']['group'] = 2;
  $handler->display->display_options['filters']['field_programme_loc_cp_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_loc_cp_value']['expose']['operator_id'] = 'field_programme_loc_cp_value_op';
  $handler->display->display_options['filters']['field_programme_loc_cp_value']['expose']['label'] = 'Code Postal (field_programme_loc_cp)';
  $handler->display->display_options['filters']['field_programme_loc_cp_value']['expose']['operator'] = 'field_programme_loc_cp_value_op';
  $handler->display->display_options['filters']['field_programme_loc_cp_value']['expose']['identifier'] = 'field_programme_loc_cp_value';
  $handler->display->display_options['filters']['field_programme_loc_cp_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_programme_loc_ville_tid';
  $handler->display->display_options['filters']['name']['group'] = 2;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  /* Filter criterion: Taxonomy term: Code departement (field_code_departement) */
  $handler->display->display_options['filters']['field_code_departement_value']['id'] = 'field_code_departement_value';
  $handler->display->display_options['filters']['field_code_departement_value']['table'] = 'field_data_field_code_departement';
  $handler->display->display_options['filters']['field_code_departement_value']['field'] = 'field_code_departement_value';
  $handler->display->display_options['filters']['field_code_departement_value']['relationship'] = 'field_programme_loc_department_tid';
  $handler->display->display_options['filters']['field_code_departement_value']['group'] = 2;
  $handler->display->display_options['filters']['field_code_departement_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_code_departement_value']['expose']['operator_id'] = 'field_code_departement_value_op';
  $handler->display->display_options['filters']['field_code_departement_value']['expose']['label'] = 'Code departement (field_code_departement)';
  $handler->display->display_options['filters']['field_code_departement_value']['expose']['operator'] = 'field_code_departement_value_op';
  $handler->display->display_options['filters']['field_code_departement_value']['expose']['identifier'] = 'field_code_departement_value';
  $handler->display->display_options['filters']['field_code_departement_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['relationship'] = 'field_programme_loc_department_tid';
  $handler->display->display_options['filters']['name_1']['group'] = 2;
  $handler->display->display_options['filters']['name_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_1']['expose']['operator_id'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name_1']['expose']['operator'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['identifier'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_2']['id'] = 'name_2';
  $handler->display->display_options['filters']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_2']['field'] = 'name';
  $handler->display->display_options['filters']['name_2']['relationship'] = 'field_programme_loc_region_tid';
  $handler->display->display_options['filters']['name_2']['group'] = 2;
  $handler->display->display_options['filters']['name_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_2']['expose']['operator_id'] = 'name_2_op';
  $handler->display->display_options['filters']['name_2']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name_2']['expose']['operator'] = 'name_2_op';
  $handler->display->display_options['filters']['name_2']['expose']['identifier'] = 'name_2';
  $handler->display->display_options['filters']['name_2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );

  /* Display: Search Bien B2C */
  $handler = $view->new_display('block', 'Search Bien B2C', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_programme_node';
  $handler->display->display_options['fields']['title']['label'] = 'Bien';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Type de Bien */
  $handler->display->display_options['fields']['field_type']['id'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['table'] = 'field_data_field_type';
  $handler->display->display_options['fields']['field_type']['field'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['relationship'] = 'reverse_field_programme_node';
  /* Field: Content: Nombre de pièces */
  $handler->display->display_options['fields']['field_nb_pieces']['id'] = 'field_nb_pieces';
  $handler->display->display_options['fields']['field_nb_pieces']['table'] = 'field_data_field_nb_pieces';
  $handler->display->display_options['fields']['field_nb_pieces']['field'] = 'field_nb_pieces';
  $handler->display->display_options['fields']['field_nb_pieces']['relationship'] = 'reverse_field_programme_node';
  /* Field: Content: Superficie */
  $handler->display->display_options['fields']['field_superficie']['id'] = 'field_superficie';
  $handler->display->display_options['fields']['field_superficie']['table'] = 'field_data_field_superficie';
  $handler->display->display_options['fields']['field_superficie']['field'] = 'field_superficie';
  $handler->display->display_options['fields']['field_superficie']['relationship'] = 'reverse_field_programme_node';
  $handler->display->display_options['fields']['field_superficie']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_superficie']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Caractéristique */
  $handler->display->display_options['fields']['field_caracteristique']['id'] = 'field_caracteristique';
  $handler->display->display_options['fields']['field_caracteristique']['table'] = 'field_data_field_caracteristique';
  $handler->display->display_options['fields']['field_caracteristique']['field'] = 'field_caracteristique';
  $handler->display->display_options['fields']['field_caracteristique']['relationship'] = 'reverse_field_programme_node';
  $handler->display->display_options['fields']['field_caracteristique']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_caracteristique']['delta_offset'] = '0';

  /* Display: Search Programme B2C */
  $handler = $view->new_display('block', 'Search Programme B2C', 'block_1');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'test';
  $translatables['search'] = array(
    t('Master'),
    t('Test If Programme Beggining by Exists'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Bien referencing Programme on CT Bien'),
    t('Term from field_programme_loc_ville'),
    t('Term from field_programme_loc_region'),
    t('Term from field_programme_loc_department'),
    t('Type de Bien (field_type)'),
    t('Nombre de pièces (field_nb_pieces)'),
    t('Superficie (field_superficie)'),
    t('Caractéristique (field_caracteristique)'),
    t('Title'),
    t('Code Postal (field_programme_loc_cp)'),
    t('Name'),
    t('Code departement (field_code_departement)'),
    t('Search Bien B2C'),
    t('Bien'),
    t('Type de Bien'),
    t('Nombre de pièces'),
    t('Superficie'),
    t('Caractéristique'),
    t('Search Programme B2C'),
    t('Page'),
  );
  $export['search'] = $view;

  $view = new view();
  $view->name = 'search_solr';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_local_index';
  $view->human_name = 'Search Solr';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'B2C - Bien - Search Solr';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_programme_nid',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'nid' => 'nid',
    'field_type' => 'field_type',
    'field_bien_statut' => 'field_bien_statut',
    'field_nb_pieces' => 'field_nb_pieces',
    'field_superficie' => 'field_superficie',
    'field_caracteristique' => 'field_caracteristique',
    'field_programme_nid' => 'field_programme_nid',
    'field_programme_title' => 'field_programme_title',
    'field_programme_field_programme_loc_lat' => 'field_programme_field_programme_loc_lat',
    'field_programme_field_programme_loc_long' => 'field_programme_field_programme_loc_long',
    'field_programme_field_programme_loc_cp_1' => 'field_programme_field_programme_loc_cp_1',
    'field_programme_field_programme_loc_ville' => 'field_programme_field_programme_loc_ville',
    'field_programme_field_programme_loc_department' => 'field_programme_field_programme_loc_department',
    'field_programme_field_programme_loc_region' => 'field_programme_field_programme_loc_region',
    'field_programme_status' => 'field_programme_status',
    'field_programme_field_programme_statut' => 'field_programme_field_programme_statut',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_bien_statut' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_nb_pieces' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_superficie' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_caracteristique' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_programme_nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_programme_title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_programme_field_programme_loc_lat' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_programme_field_programme_loc_long' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_programme_field_programme_loc_cp_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_programme_field_programme_loc_ville' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_programme_field_programme_loc_department' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_programme_field_programme_loc_region' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_programme_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_programme_field_programme_statut' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Indexed Node: Programme */
  $handler->display->display_options['relationships']['field_programme']['id'] = 'field_programme';
  $handler->display->display_options['relationships']['field_programme']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['relationships']['field_programme']['field'] = 'field_programme';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Node: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Type de Bien */
  $handler->display->display_options['fields']['field_type']['id'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_type']['field'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Statut du bien */
  $handler->display->display_options['fields']['field_bien_statut']['id'] = 'field_bien_statut';
  $handler->display->display_options['fields']['field_bien_statut']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_bien_statut']['field'] = 'field_bien_statut';
  $handler->display->display_options['fields']['field_bien_statut']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_bien_statut']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_bien_statut']['bypass_access'] = 0;
  /* Field: Indexed Node: Nombre de pièces */
  $handler->display->display_options['fields']['field_nb_pieces']['id'] = 'field_nb_pieces';
  $handler->display->display_options['fields']['field_nb_pieces']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_nb_pieces']['field'] = 'field_nb_pieces';
  $handler->display->display_options['fields']['field_nb_pieces']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_nb_pieces']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_nb_pieces']['bypass_access'] = 0;
  /* Field: Indexed Node: Superficie */
  $handler->display->display_options['fields']['field_superficie']['id'] = 'field_superficie';
  $handler->display->display_options['fields']['field_superficie']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_superficie']['field'] = 'field_superficie';
  $handler->display->display_options['fields']['field_superficie']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Indexed Node: Etage */
  $handler->display->display_options['fields']['field_etage']['id'] = 'field_etage';
  $handler->display->display_options['fields']['field_etage']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_etage']['field'] = 'field_etage';
  $handler->display->display_options['fields']['field_etage']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_etage']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_etage']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_etage']['bypass_access'] = 0;
  /* Field: Indexed Node: Orientation */
  $handler->display->display_options['fields']['field_orientation']['id'] = 'field_orientation';
  $handler->display->display_options['fields']['field_orientation']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_orientation']['field'] = 'field_orientation';
  $handler->display->display_options['fields']['field_orientation']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_orientation']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_orientation']['bypass_access'] = 0;
  /* Field: Indexed Node: Caractéristique */
  $handler->display->display_options['fields']['field_caracteristique']['id'] = 'field_caracteristique';
  $handler->display->display_options['fields']['field_caracteristique']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_caracteristique']['field'] = 'field_caracteristique';
  $handler->display->display_options['fields']['field_caracteristique']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_caracteristique']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_caracteristique']['bypass_access'] = 0;
  /* Field: Programme: Node ID (indexed) */
  $handler->display->display_options['fields']['field_programme_nid']['id'] = 'field_programme_nid';
  $handler->display->display_options['fields']['field_programme_nid']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_programme_nid']['field'] = 'field_programme_nid';
  $handler->display->display_options['fields']['field_programme_nid']['separator'] = '';
  $handler->display->display_options['fields']['field_programme_nid']['link_to_entity'] = 0;
  /* Field: Programme: Title (indexed) */
  $handler->display->display_options['fields']['field_programme_title']['id'] = 'field_programme_title';
  $handler->display->display_options['fields']['field_programme_title']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_programme_title']['field'] = 'field_programme_title';
  $handler->display->display_options['fields']['field_programme_title']['link_to_entity'] = 0;
  /* Field: Programme: Latitude (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_loc_lat']['id'] = 'field_programme_field_programme_loc_lat';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_lat']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_lat']['field'] = 'field_programme_field_programme_loc_lat';
  /* Field: Programme: Longitude (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_loc_long']['id'] = 'field_programme_field_programme_loc_long';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_long']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_long']['field'] = 'field_programme_field_programme_loc_long';
  /* Field: Programme: Code Postal (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_loc_cp_1']['id'] = 'field_programme_field_programme_loc_cp_1';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_cp_1']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_cp_1']['field'] = 'field_programme_field_programme_loc_cp';
  /* Field: Programme: Ville (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_loc_ville']['id'] = 'field_programme_field_programme_loc_ville';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_ville']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_ville']['field'] = 'field_programme_field_programme_loc_ville';
  /* Field: Programme: Départment (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_loc_department']['id'] = 'field_programme_field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_department']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_department']['field'] = 'field_programme_field_programme_loc_department';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_department']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_programme_field_programme_loc_department']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_department']['bypass_access'] = 0;
  /* Field: Programme: Region (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['id'] = 'field_programme_field_programme_loc_region';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['field'] = 'field_programme_field_programme_loc_region';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['bypass_access'] = 0;
  /* Field: Programme: Status (indexed) */
  $handler->display->display_options['fields']['field_programme_status']['id'] = 'field_programme_status';
  $handler->display->display_options['fields']['field_programme_status']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_programme_status']['field'] = 'field_programme_status';
  $handler->display->display_options['fields']['field_programme_status']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_programme_status']['format_name'] = 1;
  /* Field: Programme: Statut du programme (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_statut']['id'] = 'field_programme_field_programme_statut';
  $handler->display->display_options['fields']['field_programme_field_programme_statut']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['fields']['field_programme_field_programme_statut']['field'] = 'field_programme_field_programme_statut';
  $handler->display->display_options['fields']['field_programme_field_programme_statut']['type'] = 'list_key';
  /* Sort criterion: Programme: Node ID (indexed) */
  $handler->display->display_options['sorts']['field_programme_nid']['id'] = 'field_programme_nid';
  $handler->display->display_options['sorts']['field_programme_nid']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['sorts']['field_programme_nid']['field'] = 'field_programme_nid';
  $handler->display->display_options['sorts']['field_programme_nid']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bien' => 'bien',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Programme: Title (indexed) */
  $handler->display->display_options['filters']['field_programme_title']['id'] = 'field_programme_title';
  $handler->display->display_options['filters']['field_programme_title']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['field_programme_title']['field'] = 'field_programme_title';
  $handler->display->display_options['filters']['field_programme_title']['group'] = 2;
  $handler->display->display_options['filters']['field_programme_title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_title']['expose']['operator_id'] = 'field_programme_title_op';
  $handler->display->display_options['filters']['field_programme_title']['expose']['label'] = 'Title (indexed)';
  $handler->display->display_options['filters']['field_programme_title']['expose']['operator'] = 'field_programme_title_op';
  $handler->display->display_options['filters']['field_programme_title']['expose']['identifier'] = 'field_programme_title';
  $handler->display->display_options['filters']['field_programme_title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  /* Filter criterion: Programme: Code Postal (indexed) */
  $handler->display->display_options['filters']['field_programme_field_programme_loc_cp']['id'] = 'field_programme_field_programme_loc_cp';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_cp']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_cp']['field'] = 'field_programme_field_programme_loc_cp';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_cp']['group'] = 2;
  $handler->display->display_options['filters']['field_programme_field_programme_loc_cp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_field_programme_loc_cp']['expose']['operator_id'] = 'field_programme_field_programme_loc_cp_op';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_cp']['expose']['label'] = 'Code Postal (indexed)';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_cp']['expose']['operator'] = 'field_programme_field_programme_loc_cp_op';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_cp']['expose']['identifier'] = 'field_programme_field_programme_loc_cp';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_cp']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  /* Filter criterion: Programme: Ville (indexed) */
  $handler->display->display_options['filters']['field_programme_field_programme_loc_ville']['id'] = 'field_programme_field_programme_loc_ville';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_ville']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_ville']['field'] = 'field_programme_field_programme_loc_ville';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_ville']['value'] = array();
  $handler->display->display_options['filters']['field_programme_field_programme_loc_ville']['group'] = 2;
  $handler->display->display_options['filters']['field_programme_field_programme_loc_ville']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_field_programme_loc_ville']['expose']['operator_id'] = 'field_programme_field_programme_loc_ville_op';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_ville']['expose']['label'] = 'Ville (indexed)';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_ville']['expose']['operator'] = 'field_programme_field_programme_loc_ville_op';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_ville']['expose']['identifier'] = 'field_programme_field_programme_loc_ville';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_ville']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_programme_field_programme_loc_ville']['expose']['reduce'] = 0;
  /* Filter criterion: Programme: Départment (indexed) */
  $handler->display->display_options['filters']['field_programme_field_programme_loc_department']['id'] = 'field_programme_field_programme_loc_department';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_department']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_department']['field'] = 'field_programme_field_programme_loc_department';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_department']['value'] = array();
  $handler->display->display_options['filters']['field_programme_field_programme_loc_department']['group'] = 2;
  $handler->display->display_options['filters']['field_programme_field_programme_loc_department']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_field_programme_loc_department']['expose']['operator_id'] = 'field_programme_field_programme_loc_department_op';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_department']['expose']['label'] = 'Départment (indexed)';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_department']['expose']['operator'] = 'field_programme_field_programme_loc_department_op';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_department']['expose']['identifier'] = 'field_programme_field_programme_loc_department';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_department']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_programme_field_programme_loc_department']['expose']['reduce'] = 0;
  /* Filter criterion: Programme: Region (indexed) */
  $handler->display->display_options['filters']['field_programme_field_programme_loc_region']['id'] = 'field_programme_field_programme_loc_region';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_region']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_region']['field'] = 'field_programme_field_programme_loc_region';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_region']['value'] = array();
  $handler->display->display_options['filters']['field_programme_field_programme_loc_region']['group'] = 2;
  $handler->display->display_options['filters']['field_programme_field_programme_loc_region']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_field_programme_loc_region']['expose']['operator_id'] = 'field_programme_field_programme_loc_region_op';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_region']['expose']['label'] = 'Region (indexed)';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_region']['expose']['operator'] = 'field_programme_field_programme_loc_region_op';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_region']['expose']['identifier'] = 'field_programme_field_programme_loc_region';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_region']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_programme_field_programme_loc_region']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Statut du bien */
  $handler->display->display_options['filters']['field_bien_statut']['id'] = 'field_bien_statut';
  $handler->display->display_options['filters']['field_bien_statut']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['field_bien_statut']['field'] = 'field_bien_statut';
  $handler->display->display_options['filters']['field_bien_statut']['value'] = array(
    207 => '207',
  );
  /* Filter criterion: Indexed Node: Type de Bien */
  $handler->display->display_options['filters']['field_type']['id'] = 'field_type';
  $handler->display->display_options['filters']['field_type']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['field_type']['field'] = 'field_type';
  $handler->display->display_options['filters']['field_type']['value'] = array();
  $handler->display->display_options['filters']['field_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type']['expose']['operator_id'] = 'field_type_op';
  $handler->display->display_options['filters']['field_type']['expose']['label'] = 'Type de Bien';
  $handler->display->display_options['filters']['field_type']['expose']['operator'] = 'field_type_op';
  $handler->display->display_options['filters']['field_type']['expose']['identifier'] = 'field_type';
  $handler->display->display_options['filters']['field_type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_type']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Nombre de pièces */
  $handler->display->display_options['filters']['field_nb_pieces']['id'] = 'field_nb_pieces';
  $handler->display->display_options['filters']['field_nb_pieces']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['field_nb_pieces']['field'] = 'field_nb_pieces';
  $handler->display->display_options['filters']['field_nb_pieces']['value'] = array();
  $handler->display->display_options['filters']['field_nb_pieces']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_nb_pieces']['expose']['operator_id'] = 'field_nb_pieces_op';
  $handler->display->display_options['filters']['field_nb_pieces']['expose']['label'] = 'Nombre de pièces';
  $handler->display->display_options['filters']['field_nb_pieces']['expose']['operator'] = 'field_nb_pieces_op';
  $handler->display->display_options['filters']['field_nb_pieces']['expose']['identifier'] = 'field_nb_pieces';
  $handler->display->display_options['filters']['field_nb_pieces']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_nb_pieces']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_nb_pieces']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Superficie */
  $handler->display->display_options['filters']['field_superficie']['id'] = 'field_superficie';
  $handler->display->display_options['filters']['field_superficie']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['field_superficie']['field'] = 'field_superficie';
  $handler->display->display_options['filters']['field_superficie']['operator'] = '>=';
  $handler->display->display_options['filters']['field_superficie']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_superficie']['expose']['operator_id'] = 'field_superficie_op';
  $handler->display->display_options['filters']['field_superficie']['expose']['label'] = 'Superficie';
  $handler->display->display_options['filters']['field_superficie']['expose']['operator'] = 'field_superficie_op';
  $handler->display->display_options['filters']['field_superficie']['expose']['identifier'] = 'field_superficie';
  $handler->display->display_options['filters']['field_superficie']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  /* Filter criterion: Indexed Node: Caractéristique */
  $handler->display->display_options['filters']['field_caracteristique']['id'] = 'field_caracteristique';
  $handler->display->display_options['filters']['field_caracteristique']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['field_caracteristique']['field'] = 'field_caracteristique';
  $handler->display->display_options['filters']['field_caracteristique']['value'] = array();
  $handler->display->display_options['filters']['field_caracteristique']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_caracteristique']['expose']['operator_id'] = 'field_caracteristique_op';
  $handler->display->display_options['filters']['field_caracteristique']['expose']['label'] = 'Caractéristique';
  $handler->display->display_options['filters']['field_caracteristique']['expose']['operator'] = 'field_caracteristique_op';
  $handler->display->display_options['filters']['field_caracteristique']['expose']['identifier'] = 'field_caracteristique';
  $handler->display->display_options['filters']['field_caracteristique']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_caracteristique']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_caracteristique']['expose']['reduce'] = 0;
  /* Filter criterion: Programme: Node ID (indexed) */
  $handler->display->display_options['filters']['field_programme_nid']['id'] = 'field_programme_nid';
  $handler->display->display_options['filters']['field_programme_nid']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['field_programme_nid']['field'] = 'field_programme_nid';
  $handler->display->display_options['filters']['field_programme_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_nid']['expose']['operator_id'] = 'field_programme_nid_op';
  $handler->display->display_options['filters']['field_programme_nid']['expose']['label'] = 'Node ID (indexed)';
  $handler->display->display_options['filters']['field_programme_nid']['expose']['operator'] = 'field_programme_nid_op';
  $handler->display->display_options['filters']['field_programme_nid']['expose']['identifier'] = 'field_programme_nid';
  $handler->display->display_options['filters']['field_programme_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  /* Filter criterion: Programme: Statut du programme (indexed) */
  $handler->display->display_options['filters']['field_programme_field_programme_statut']['id'] = 'field_programme_field_programme_statut';
  $handler->display->display_options['filters']['field_programme_field_programme_statut']['table'] = 'search_api_index_local_index';
  $handler->display->display_options['filters']['field_programme_field_programme_statut']['field'] = 'field_programme_field_programme_statut';
  $handler->display->display_options['filters']['field_programme_field_programme_statut']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['search_solr'] = array(
    t('Master'),
    t('B2C - Bien - Search Solr'),
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
    t('Programme'),
    t('Title'),
    t('Content type'),
    t('Node ID'),
    t('.'),
    t('Type de Bien'),
    t('Statut du bien'),
    t('Nombre de pièces'),
    t('Superficie'),
    t('Etage'),
    t('Orientation'),
    t('Caractéristique'),
    t('Node ID (indexed)'),
    t('Title (indexed)'),
    t('Latitude (indexed)'),
    t('Longitude (indexed)'),
    t('Code Postal (indexed)'),
    t('Ville (indexed)'),
    t('Départment (indexed)'),
    t('Region (indexed)'),
    t('Status (indexed)'),
    t('Statut du programme (indexed)'),
    t('Block'),
  );
  $export['search_solr'] = $view;

  return $export;
}
