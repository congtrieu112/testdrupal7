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
  $handler->display->display_options['cache']['type'] = 'time_per_domain';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
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
  $view->name = 'solr_views';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_acquia_solr_index';
  $view->human_name = 'Solr Views';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Solr Views';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'time_per_domain';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Content: Type de Bien */
  $handler->display->display_options['fields']['field_type']['id'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_type']['field'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['label'] = '';
  $handler->display->display_options['fields']['field_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_type']['bypass_access'] = 0;
  /* Field: Indexed Content: Prix TVA réduit */
  $handler->display->display_options['fields']['field_bien_low_tva_price']['id'] = 'field_bien_low_tva_price';
  $handler->display->display_options['fields']['field_bien_low_tva_price']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_bien_low_tva_price']['field'] = 'field_bien_low_tva_price';
  $handler->display->display_options['fields']['field_bien_low_tva_price']['label'] = '';
  $handler->display->display_options['fields']['field_bien_low_tva_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bien_low_tva_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 0,
  );
  /* Field: Indexed Content: Prix */
  $handler->display->display_options['fields']['field_prix_tva_20']['id'] = 'field_prix_tva_20';
  $handler->display->display_options['fields']['field_prix_tva_20']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_prix_tva_20']['field'] = 'field_prix_tva_20';
  $handler->display->display_options['fields']['field_prix_tva_20']['label'] = '';
  $handler->display->display_options['fields']['field_prix_tva_20']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_prix_tva_20']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 0,
  );
  /* Field: Indexed Content: Nombre de pièces */
  $handler->display->display_options['fields']['field_nb_pieces']['id'] = 'field_nb_pieces';
  $handler->display->display_options['fields']['field_nb_pieces']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_nb_pieces']['field'] = 'field_nb_pieces';
  $handler->display->display_options['fields']['field_nb_pieces']['label'] = '';
  $handler->display->display_options['fields']['field_nb_pieces']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_nb_pieces']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_nb_pieces']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_nb_pieces']['bypass_access'] = 0;
  /* Field: Indexed Content: Superficie */
  $handler->display->display_options['fields']['field_superficie']['id'] = 'field_superficie';
  $handler->display->display_options['fields']['field_superficie']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_superficie']['field'] = 'field_superficie';
  $handler->display->display_options['fields']['field_superficie']['label'] = '';
  $handler->display->display_options['fields']['field_superficie']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_superficie']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 0,
  );
  /* Field: Indexed Content: Etage */
  $handler->display->display_options['fields']['field_etage']['id'] = 'field_etage';
  $handler->display->display_options['fields']['field_etage']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_etage']['field'] = 'field_etage';
  $handler->display->display_options['fields']['field_etage']['label'] = '';
  $handler->display->display_options['fields']['field_etage']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_etage']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_etage']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_etage']['bypass_access'] = 0;
  /* Field: Indexed Content: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Content: Caractéristique */
  $handler->display->display_options['fields']['field_caracteristique']['id'] = 'field_caracteristique';
  $handler->display->display_options['fields']['field_caracteristique']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_caracteristique']['field'] = 'field_caracteristique';
  $handler->display->display_options['fields']['field_caracteristique']['label'] = '';
  $handler->display->display_options['fields']['field_caracteristique']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_caracteristique']['list']['separator'] = '##';
  $handler->display->display_options['fields']['field_caracteristique']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_caracteristique']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_caracteristique']['bypass_access'] = 0;
  /* Field: Indexed Content: Orientation */
  $handler->display->display_options['fields']['field_orientation']['id'] = 'field_orientation';
  $handler->display->display_options['fields']['field_orientation']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_orientation']['field'] = 'field_orientation';
  $handler->display->display_options['fields']['field_orientation']['label'] = '';
  $handler->display->display_options['fields']['field_orientation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_orientation']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_orientation']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_orientation']['bypass_access'] = 0;
  /* Field: Indexed Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Programme: Node ID (indexed) */
  $handler->display->display_options['fields']['field_programme_nid']['id'] = 'field_programme_nid';
  $handler->display->display_options['fields']['field_programme_nid']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_nid']['field'] = 'field_programme_nid';
  $handler->display->display_options['fields']['field_programme_nid']['separator'] = '';
  $handler->display->display_options['fields']['field_programme_nid']['link_to_entity'] = 0;
  /* Field: Programme: Title (indexed) */
  $handler->display->display_options['fields']['field_programme_title']['id'] = 'field_programme_title';
  $handler->display->display_options['fields']['field_programme_title']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_title']['field'] = 'field_programme_title';
  $handler->display->display_options['fields']['field_programme_title']['link_to_entity'] = 0;
  /* Field: Programme: URL (indexed) */
  $handler->display->display_options['fields']['field_programme_url']['id'] = 'field_programme_url';
  $handler->display->display_options['fields']['field_programme_url']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_url']['field'] = 'field_programme_url';
  $handler->display->display_options['fields']['field_programme_url']['label'] = '';
  $handler->display->display_options['fields']['field_programme_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['field_programme_url']['link_to_entity'] = 0;
  /* Field: Programme: Nombre de pièce min (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_room_min']['id'] = 'field_programme_field_programme_room_min';
  $handler->display->display_options['fields']['field_programme_field_programme_room_min']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_field_programme_room_min']['field'] = 'field_programme_field_programme_room_min';
  $handler->display->display_options['fields']['field_programme_field_programme_room_min']['label'] = '';
  $handler->display->display_options['fields']['field_programme_field_programme_room_min']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_field_programme_room_min']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_programme_field_programme_room_min']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Programme: Nombre de pièce max (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_room_max']['id'] = 'field_programme_field_programme_room_max';
  $handler->display->display_options['fields']['field_programme_field_programme_room_max']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_field_programme_room_max']['field'] = 'field_programme_field_programme_room_max';
  $handler->display->display_options['fields']['field_programme_field_programme_room_max']['label'] = '';
  $handler->display->display_options['fields']['field_programme_field_programme_room_max']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_field_programme_room_max']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_programme_field_programme_room_max']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Programme: TVA (indexed) */
  $handler->display->display_options['fields']['field_programme_field_tva']['id'] = 'field_programme_field_tva';
  $handler->display->display_options['fields']['field_programme_field_tva']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_field_tva']['field'] = 'field_programme_field_tva';
  $handler->display->display_options['fields']['field_programme_field_tva']['label'] = '';
  $handler->display->display_options['fields']['field_programme_field_tva']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_field_tva']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_programme_field_tva']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_programme_field_tva']['bypass_access'] = 0;
  /* Field: Programme: Prix min (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_price_min']['id'] = 'field_programme_field_programme_price_min';
  $handler->display->display_options['fields']['field_programme_field_programme_price_min']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_field_programme_price_min']['field'] = 'field_programme_field_programme_price_min';
  $handler->display->display_options['fields']['field_programme_field_programme_price_min']['label'] = '';
  $handler->display->display_options['fields']['field_programme_field_programme_price_min']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_field_programme_price_min']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Programme: Prix min TVA reduit (indexed) */
  $handler->display->display_options['fields']['field_programme_field_program_low_tva_price_min']['id'] = 'field_programme_field_program_low_tva_price_min';
  $handler->display->display_options['fields']['field_programme_field_program_low_tva_price_min']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_field_program_low_tva_price_min']['field'] = 'field_programme_field_program_low_tva_price_min';
  $handler->display->display_options['fields']['field_programme_field_program_low_tva_price_min']['label'] = '';
  $handler->display->display_options['fields']['field_programme_field_program_low_tva_price_min']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_field_program_low_tva_price_min']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Field: Programme: Code Postal (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_loc_cp']['id'] = 'field_programme_field_programme_loc_cp';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_cp']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_cp']['field'] = 'field_programme_field_programme_loc_cp';
  /* Field: Programme: Arrondissement (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_loc_arr']['id'] = 'field_programme_field_programme_loc_arr';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_arr']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_arr']['field'] = 'field_programme_field_programme_loc_arr';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_arr']['label'] = '';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_arr']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_field_programme_loc_arr']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_programme_field_programme_loc_arr']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_arr']['bypass_access'] = 0;
  /* Field: Programme: Region (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['id'] = 'field_programme_field_programme_loc_region';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['field'] = 'field_programme_field_programme_loc_region';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['label'] = '';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_region']['bypass_access'] = 0;
  /* Field: Programme: Latitude (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_loc_lat']['id'] = 'field_programme_field_programme_loc_lat';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_lat']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_lat']['field'] = 'field_programme_field_programme_loc_lat';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_lat']['label'] = '';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_lat']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_field_programme_loc_lat']['type'] = 'text_plain';
  /* Field: Programme: Longitude (indexed) */
  $handler->display->display_options['fields']['field_programme_field_programme_loc_long']['id'] = 'field_programme_field_programme_loc_long';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_long']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_long']['field'] = 'field_programme_field_programme_loc_long';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_long']['label'] = '';
  $handler->display->display_options['fields']['field_programme_field_programme_loc_long']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_field_programme_loc_long']['type'] = 'text_plain';
  /* Field: Programme: Caractéristiques (indexed) */
  $handler->display->display_options['fields']['field_programme_field_caracteristiques']['id'] = 'field_programme_field_caracteristiques';
  $handler->display->display_options['fields']['field_programme_field_caracteristiques']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_field_caracteristiques']['field'] = 'field_programme_field_caracteristiques';
  $handler->display->display_options['fields']['field_programme_field_caracteristiques']['label'] = '';
  $handler->display->display_options['fields']['field_programme_field_caracteristiques']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_field_caracteristiques']['list']['separator'] = '##';
  $handler->display->display_options['fields']['field_programme_field_caracteristiques']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_programme_field_caracteristiques']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_programme_field_caracteristiques']['bypass_access'] = 0;
  /* Field: Indexed Content: My Domain Access Information */
  $handler->display->display_options['fields']['kandb_recherche_domain_access']['id'] = 'kandb_recherche_domain_access';
  $handler->display->display_options['fields']['kandb_recherche_domain_access']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['kandb_recherche_domain_access']['field'] = 'kandb_recherche_domain_access';
  $handler->display->display_options['fields']['kandb_recherche_domain_access']['separator'] = '';
  $handler->display->display_options['fields']['kandb_recherche_domain_access']['link_to_entity'] = 0;
  /* Field: Programme: My Domain Access Information (indexed) */
  $handler->display->display_options['fields']['field_programme_kandb_recherche_domain_access']['id'] = 'field_programme_kandb_recherche_domain_access';
  $handler->display->display_options['fields']['field_programme_kandb_recherche_domain_access']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_kandb_recherche_domain_access']['field'] = 'field_programme_kandb_recherche_domain_access';
  $handler->display->display_options['fields']['field_programme_kandb_recherche_domain_access']['link_to_entity'] = 0;
  /* Field: Programme: Number of the department (indexed) */
  $handler->display->display_options['fields']['field_programme_departement_number']['id'] = 'field_programme_departement_number';
  $handler->display->display_options['fields']['field_programme_departement_number']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_departement_number']['field'] = 'field_programme_departement_number';
  $handler->display->display_options['fields']['field_programme_departement_number']['label'] = '';
  $handler->display->display_options['fields']['field_programme_departement_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_departement_number']['link_to_entity'] = 0;
  /* Field: Programme: Town Name (indexed) */
  $handler->display->display_options['fields']['field_programme_ville_text']['id'] = 'field_programme_ville_text';
  $handler->display->display_options['fields']['field_programme_ville_text']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_ville_text']['field'] = 'field_programme_ville_text';
  $handler->display->display_options['fields']['field_programme_ville_text']['label'] = '';
  $handler->display->display_options['fields']['field_programme_ville_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_ville_text']['link_to_entity'] = 0;
  /* Field: Programme: Programme Image (indexed) */
  $handler->display->display_options['fields']['field_programme_programme_image']['id'] = 'field_programme_programme_image';
  $handler->display->display_options['fields']['field_programme_programme_image']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['fields']['field_programme_programme_image']['field'] = 'field_programme_programme_image';
  $handler->display->display_options['fields']['field_programme_programme_image']['label'] = '';
  $handler->display->display_options['fields']['field_programme_programme_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_programme_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_programme_programme_image']['link_to_entity'] = 0;
  /* Sort criterion: Programme: Number of the department (indexed) */
  $handler->display->display_options['sorts']['field_programme_departement_number']['id'] = 'field_programme_departement_number';
  $handler->display->display_options['sorts']['field_programme_departement_number']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['sorts']['field_programme_departement_number']['field'] = 'field_programme_departement_number';
  /* Sort criterion: Programme: Town Name (indexed) */
  $handler->display->display_options['sorts']['field_programme_ville_text']['id'] = 'field_programme_ville_text';
  $handler->display->display_options['sorts']['field_programme_ville_text']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['sorts']['field_programme_ville_text']['field'] = 'field_programme_ville_text';
  /* Sort criterion: Programme: Title for sorting (indexed) */
  $handler->display->display_options['sorts']['field_programme_title_sort']['id'] = 'field_programme_title_sort';
  $handler->display->display_options['sorts']['field_programme_title_sort']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['sorts']['field_programme_title_sort']['field'] = 'field_programme_title_sort';
  /* Sort criterion: Indexed Content: Type of Bien for sorting */
  $handler->display->display_options['sorts']['bien_type_sort']['id'] = 'bien_type_sort';
  $handler->display->display_options['sorts']['bien_type_sort']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['sorts']['bien_type_sort']['field'] = 'bien_type_sort';
  /* Sort criterion: Indexed Content: Number room for sorting */
  $handler->display->display_options['sorts']['room_sort']['id'] = 'room_sort';
  $handler->display->display_options['sorts']['room_sort']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['sorts']['room_sort']['field'] = 'room_sort';
  /* Sort criterion: Indexed Content: Prix */
  $handler->display->display_options['sorts']['field_prix_tva_20']['id'] = 'field_prix_tva_20';
  $handler->display->display_options['sorts']['field_prix_tva_20']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['sorts']['field_prix_tva_20']['field'] = 'field_prix_tva_20';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
    3 => 'OR',
    4 => 'OR',
  );
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bien' => 'bien',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Statut du bien */
  $handler->display->display_options['filters']['field_bien_statut']['id'] = 'field_bien_statut';
  $handler->display->display_options['filters']['field_bien_statut']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['filters']['field_bien_statut']['field'] = 'field_bien_statut';
  $handler->display->display_options['filters']['field_bien_statut']['value'] = array(
    220 => '220',
  );
  $handler->display->display_options['filters']['field_bien_statut']['group'] = 1;
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Content: Type de Bien */
  $handler->display->display_options['filters']['field_type']['id'] = 'field_type';
  $handler->display->display_options['filters']['field_type']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['filters']['field_type']['field'] = 'field_type';
  $handler->display->display_options['filters']['field_type']['value'] = array();
  $handler->display->display_options['filters']['field_type']['group'] = 1;
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
  /* Filter criterion: Indexed Content: Nombre de pièces */
  $handler->display->display_options['filters']['field_nb_pieces']['id'] = 'field_nb_pieces';
  $handler->display->display_options['filters']['field_nb_pieces']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['filters']['field_nb_pieces']['field'] = 'field_nb_pieces';
  $handler->display->display_options['filters']['field_nb_pieces']['value'] = array();
  $handler->display->display_options['filters']['field_nb_pieces']['group'] = 1;
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
  /* Filter criterion: Indexed Content: Superficie */
  $handler->display->display_options['filters']['field_superficie']['id'] = 'field_superficie';
  $handler->display->display_options['filters']['field_superficie']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['filters']['field_superficie']['field'] = 'field_superficie';
  $handler->display->display_options['filters']['field_superficie']['operator'] = '>=';
  $handler->display->display_options['filters']['field_superficie']['group'] = 1;
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
  /* Filter criterion: Indexed Content: Caractéristique */
  $handler->display->display_options['filters']['field_caracteristique']['id'] = 'field_caracteristique';
  $handler->display->display_options['filters']['field_caracteristique']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['filters']['field_caracteristique']['field'] = 'field_caracteristique';
  $handler->display->display_options['filters']['field_caracteristique']['value'] = array();
  $handler->display->display_options['filters']['field_caracteristique']['group'] = 1;
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
  /* Filter criterion: Programme: Arrondissement (indexed) */
  $handler->display->display_options['filters']['field_programme_field_programme_loc_arr']['id'] = 'field_programme_field_programme_loc_arr';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_arr']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_arr']['field'] = 'field_programme_field_programme_loc_arr';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_arr']['value'] = array();
  $handler->display->display_options['filters']['field_programme_field_programme_loc_arr']['group'] = 1;
  $handler->display->display_options['filters']['field_programme_field_programme_loc_arr']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_field_programme_loc_arr']['expose']['operator_id'] = 'field_programme_field_programme_loc_arr_op';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_arr']['expose']['label'] = 'Arrondissement (indexed)';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_arr']['expose']['operator'] = 'field_programme_field_programme_loc_arr_op';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_arr']['expose']['identifier'] = 'field_programme_field_programme_loc_arr';
  $handler->display->display_options['filters']['field_programme_field_programme_loc_arr']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  $handler->display->display_options['filters']['field_programme_field_programme_loc_arr']['expose']['reduce'] = 0;
  /* Filter criterion: Programme: Status (indexed) */
  $handler->display->display_options['filters']['field_programme_status']['id'] = 'field_programme_status';
  $handler->display->display_options['filters']['field_programme_status']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['filters']['field_programme_status']['field'] = 'field_programme_status';
  $handler->display->display_options['filters']['field_programme_status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_programme_status']['group'] = 1;
  /* Filter criterion: Programme: Title (indexed) */
  $handler->display->display_options['filters']['field_programme_title']['id'] = 'field_programme_title';
  $handler->display->display_options['filters']['field_programme_title']['table'] = 'search_api_index_acquia_solr_index';
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
  $handler->display->display_options['filters']['field_programme_field_programme_loc_cp']['table'] = 'search_api_index_acquia_solr_index';
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
  $handler->display->display_options['filters']['field_programme_field_programme_loc_ville']['table'] = 'search_api_index_acquia_solr_index';
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
  $handler->display->display_options['filters']['field_programme_field_programme_loc_department']['table'] = 'search_api_index_acquia_solr_index';
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
  $handler->display->display_options['filters']['field_programme_field_programme_loc_region']['table'] = 'search_api_index_acquia_solr_index';
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
  /* Filter criterion: Indexed Content: Prix */
  $handler->display->display_options['filters']['field_prix_tva_20']['id'] = 'field_prix_tva_20';
  $handler->display->display_options['filters']['field_prix_tva_20']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['filters']['field_prix_tva_20']['field'] = 'field_prix_tva_20';
  $handler->display->display_options['filters']['field_prix_tva_20']['operator'] = '>=';
  $handler->display->display_options['filters']['field_prix_tva_20']['group'] = 3;
  $handler->display->display_options['filters']['field_prix_tva_20']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_prix_tva_20']['expose']['operator_id'] = 'field_prix_tva_20_op';
  $handler->display->display_options['filters']['field_prix_tva_20']['expose']['label'] = 'Prix min tva 20';
  $handler->display->display_options['filters']['field_prix_tva_20']['expose']['operator'] = 'field_prix_tva_20_op';
  $handler->display->display_options['filters']['field_prix_tva_20']['expose']['identifier'] = 'field_prix_tva_20';
  $handler->display->display_options['filters']['field_prix_tva_20']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  /* Filter criterion: Indexed Content: Prix TVA réduit */
  $handler->display->display_options['filters']['field_bien_low_tva_price']['id'] = 'field_bien_low_tva_price';
  $handler->display->display_options['filters']['field_bien_low_tva_price']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['filters']['field_bien_low_tva_price']['field'] = 'field_bien_low_tva_price';
  $handler->display->display_options['filters']['field_bien_low_tva_price']['operator'] = '>=';
  $handler->display->display_options['filters']['field_bien_low_tva_price']['group'] = 3;
  $handler->display->display_options['filters']['field_bien_low_tva_price']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_bien_low_tva_price']['expose']['operator_id'] = 'field_bien_low_tva_price_op';
  $handler->display->display_options['filters']['field_bien_low_tva_price']['expose']['label'] = 'Prix min TVA réduit';
  $handler->display->display_options['filters']['field_bien_low_tva_price']['expose']['operator'] = 'field_bien_low_tva_price_op';
  $handler->display->display_options['filters']['field_bien_low_tva_price']['expose']['identifier'] = 'field_bien_low_tva_price';
  $handler->display->display_options['filters']['field_bien_low_tva_price']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  /* Filter criterion: Indexed Content: Prix */
  $handler->display->display_options['filters']['field_prix_tva_20_1']['id'] = 'field_prix_tva_20_1';
  $handler->display->display_options['filters']['field_prix_tva_20_1']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['filters']['field_prix_tva_20_1']['field'] = 'field_prix_tva_20';
  $handler->display->display_options['filters']['field_prix_tva_20_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_prix_tva_20_1']['group'] = 4;
  $handler->display->display_options['filters']['field_prix_tva_20_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_prix_tva_20_1']['expose']['operator_id'] = 'field_prix_tva_20_1_op';
  $handler->display->display_options['filters']['field_prix_tva_20_1']['expose']['label'] = 'Prix max';
  $handler->display->display_options['filters']['field_prix_tva_20_1']['expose']['operator'] = 'field_prix_tva_20_1_op';
  $handler->display->display_options['filters']['field_prix_tva_20_1']['expose']['identifier'] = 'field_prix_tva_20_1';
  $handler->display->display_options['filters']['field_prix_tva_20_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );
  /* Filter criterion: Indexed Content: Prix TVA réduit */
  $handler->display->display_options['filters']['field_bien_low_tva_price_1']['id'] = 'field_bien_low_tva_price_1';
  $handler->display->display_options['filters']['field_bien_low_tva_price_1']['table'] = 'search_api_index_acquia_solr_index';
  $handler->display->display_options['filters']['field_bien_low_tva_price_1']['field'] = 'field_bien_low_tva_price';
  $handler->display->display_options['filters']['field_bien_low_tva_price_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_bien_low_tva_price_1']['group'] = 4;
  $handler->display->display_options['filters']['field_bien_low_tva_price_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_bien_low_tva_price_1']['expose']['operator_id'] = 'field_bien_low_tva_price_1_op';
  $handler->display->display_options['filters']['field_bien_low_tva_price_1']['expose']['label'] = 'Prix max TVA réduit';
  $handler->display->display_options['filters']['field_bien_low_tva_price_1']['expose']['operator'] = 'field_bien_low_tva_price_1_op';
  $handler->display->display_options['filters']['field_bien_low_tva_price_1']['expose']['identifier'] = 'field_bien_low_tva_price_1';
  $handler->display->display_options['filters']['field_bien_low_tva_price_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    81728063 => 0,
    175053426 => 0,
    144435657 => 0,
    42676763 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'solr-view-page';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'solr-view-page-1';
  $translatables['solr_views'] = array(
    t('Master'),
    t('Solr Views'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('.'),
    t('Content type'),
    t('Title'),
    t('Node ID (indexed)'),
    t('Title (indexed)'),
    t('Code Postal (indexed)'),
    t('My Domain Access Information'),
    t('My Domain Access Information (indexed)'),
    t(','),
    t('Type de Bien'),
    t('Nombre de pièces'),
    t('Superficie'),
    t('Caractéristique'),
    t('Arrondissement (indexed)'),
    t('Ville (indexed)'),
    t('Départment (indexed)'),
    t('Region (indexed)'),
    t('Prix min tva 20'),
    t('Prix min TVA réduit'),
    t('Prix max'),
    t('Prix max TVA réduit'),
    t('Page'),
  );
  $export['solr_views'] = $view;

  return $export;
}
