<?php
/**
 * @file
 * kand_contactus_export_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function kand_contactus_export_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'contact_us_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Contact us export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contact us export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access all webform results';
  $handler->display->display_options['cache']['type'] = 'time_per_domain';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '0';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['label'] = 'IDKP';
  $handler->display->display_options['fields']['value_3']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_3']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value_3']['webform_cid'] = '14';
  $handler->display->display_options['fields']['value_3']['webform_datatype'] = 'number';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['label'] = 'IDKL';
  $handler->display->display_options['fields']['value_2']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_2']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value_2']['webform_cid'] = '15';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_7']['id'] = 'value_7';
  $handler->display->display_options['fields']['value_7']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_7']['field'] = 'value';
  $handler->display->display_options['fields']['value_7']['label'] = 'NOM_PROG';
  $handler->display->display_options['fields']['value_7']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_7']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value_7']['webform_cid'] = '17';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_9']['id'] = 'value_9';
  $handler->display->display_options['fields']['value_9']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_9']['field'] = 'value';
  $handler->display->display_options['fields']['value_9']['label'] = 'VILLE_PROG';
  $handler->display->display_options['fields']['value_9']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_9']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value_9']['webform_cid'] = '18';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_10']['id'] = 'value_10';
  $handler->display->display_options['fields']['value_10']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_10']['field'] = 'value';
  $handler->display->display_options['fields']['value_10']['label'] = 'DEPT_PROG';
  $handler->display->display_options['fields']['value_10']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_10']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value_10']['webform_cid'] = '19';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_4']['id'] = 'value_4';
  $handler->display->display_options['fields']['value_4']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_4']['field'] = 'value';
  $handler->display->display_options['fields']['value_4']['label'] = 'TYPE_CONTACT';
  $handler->display->display_options['fields']['value_4']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_4']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value_4']['webform_cid'] = '16';
  /* Field: Webform submissions: Submitted */
  $handler->display->display_options['fields']['submitted']['id'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['submitted']['field'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['label'] = 'DATE';
  $handler->display->display_options['fields']['submitted']['date_format'] = 'custom';
  $handler->display->display_options['fields']['submitted']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['submitted']['second_date_format'] = 'long';
  /* Field: Webform submissions: Submitted */
  $handler->display->display_options['fields']['submitted_1']['id'] = 'submitted_1';
  $handler->display->display_options['fields']['submitted_1']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['submitted_1']['field'] = 'submitted';
  $handler->display->display_options['fields']['submitted_1']['label'] = 'HEURE';
  $handler->display->display_options['fields']['submitted_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['submitted_1']['custom_date_format'] = 'h:i:s';
  $handler->display->display_options['fields']['submitted_1']['second_date_format'] = 'long';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['label'] = 'NOM';
  $handler->display->display_options['fields']['value']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value']['webform_cid'] = '1';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_5']['id'] = 'value_5';
  $handler->display->display_options['fields']['value_5']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_5']['field'] = 'value';
  $handler->display->display_options['fields']['value_5']['label'] = 'PRENOM';
  $handler->display->display_options['fields']['value_5']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_5']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value_5']['webform_cid'] = '2';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['label'] = 'TELEPHONE';
  $handler->display->display_options['fields']['value_1']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_1']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value_1']['webform_cid'] = '9';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_6']['id'] = 'value_6';
  $handler->display->display_options['fields']['value_6']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_6']['field'] = 'value';
  $handler->display->display_options['fields']['value_6']['label'] = 'EMAIL';
  $handler->display->display_options['fields']['value_6']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_6']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value_6']['webform_cid'] = '10';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_8']['id'] = 'value_8';
  $handler->display->display_options['fields']['value_8']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_8']['field'] = 'value';
  $handler->display->display_options['fields']['value_8']['label'] = 'ADRESSE';
  $handler->display->display_options['fields']['value_8']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_8']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value_8']['webform_cid'] = '3';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_11']['id'] = 'value_11';
  $handler->display->display_options['fields']['value_11']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_11']['field'] = 'value';
  $handler->display->display_options['fields']['value_11']['label'] = 'VILLE';
  $handler->display->display_options['fields']['value_11']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_11']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value_11']['webform_cid'] = '6';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_12']['id'] = 'value_12';
  $handler->display->display_options['fields']['value_12']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_12']['field'] = 'value';
  $handler->display->display_options['fields']['value_12']['label'] = 'CODE_POSTAL';
  $handler->display->display_options['fields']['value_12']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_12']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value_12']['webform_cid'] = '7';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_13']['id'] = 'value_13';
  $handler->display->display_options['fields']['value_13']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_13']['field'] = 'value';
  $handler->display->display_options['fields']['value_13']['label'] = 'PAYS';
  $handler->display->display_options['fields']['value_13']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value_13']['webform_nid'] = '2';
  $handler->display->display_options['fields']['value_13']['webform_cid'] = '8';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_5']['id'] = 'nothing_5';
  $handler->display->display_options['fields']['nothing_5']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_5']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_5']['label'] = 'PROV';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_6']['id'] = 'nothing_6';
  $handler->display->display_options['fields']['nothing_6']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_6']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_6']['label'] = 'MESSAGE';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_7']['id'] = 'nothing_7';
  $handler->display->display_options['fields']['nothing_7']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_7']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_7']['label'] = 'PREFERENCE_HABITAT';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_8']['id'] = 'nothing_8';
  $handler->display->display_options['fields']['nothing_8']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_8']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_8']['label'] = 'DUFLOT';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_9']['id'] = 'nothing_9';
  $handler->display->display_options['fields']['nothing_9']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_9']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_9']['label'] = 'PTZ';
  /* Filter criterion: Webform: Node */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'webform';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'nid';
  $handler->display->display_options['filters']['nid']['value']['value'] = '2';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'contact-us-export';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['segment_size'] = '100';
  $translatables['contact_us_export'] = array(
    t('Master'),
    t('Contact us export'),
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
    t('Webform Node'),
    t('IDKP'),
    t('IDKL'),
    t('NOM_PROG'),
    t('VILLE_PROG'),
    t('DEPT_PROG'),
    t('TYPE_CONTACT'),
    t('DATE'),
    t('HEURE'),
    t('NOM'),
    t('PRENOM'),
    t('TELEPHONE'),
    t('EMAIL'),
    t('ADRESSE'),
    t('VILLE'),
    t('CODE_POSTAL'),
    t('PAYS'),
    t('PROV'),
    t('MESSAGE'),
    t('PREFERENCE_HABITAT'),
    t('DUFLOT'),
    t('PTZ'),
    t('Page'),
    t('Data export'),
  );
  $export['contact_us_export'] = $view;

  return $export;
}
