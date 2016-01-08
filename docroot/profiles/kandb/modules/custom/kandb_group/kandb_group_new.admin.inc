<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */

/**
 * Group Actualités admin form.
 */
function kandb_group_new_admin_form($form, $form_state) {
  global $language;
  
  $form['fieldset_group_new'] = array(
    '#type' => 'fieldset',
    '#title' => 'BLOCK #1',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $form['fieldset_group_new']['title_news'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('title_news'),
    '#required' => TRUE,
  );
  
  $form['fieldset_group_new']['sub_title_news'] = array(
    '#type' => 'textfield',
    '#title' => t('Sub Title'),
    '#default_value' => variable_get('sub_title_news'),
  );
  
  $description_news = variable_get('description_news', array('format' => 'full_html'));
  $form['fieldset_group_new']['description_news'] = array(
    '#type' => 'text_format',
    '#format' => $description_news['format'],
    '#title' => t('Description'),
    '#default_value' => $description_news['value'],
    '#required' => TRUE,
  );
  
  $form['fieldset_group_new']['image_group_new'] = array(
    '#type' => 'managed_file',
    '#title' => 'Image in Group Actualités page',
    '#default_value' => variable_get('image_group_new'),
    '#upload_location' => 'public://',
    '#required' => TRUE,
  );
  
  $form['#field_uploads'] = array(
    'image_group_new',
  );
  
  $form['#submit'] = array(
    'kandb_group_new'
  );
  
  $form['group_actualites_module_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Module Title'),
    '#default_value' => variable_get('group_actualites_module_title'),
    '#required' => TRUE,
  );
  $form['group_actualites_document_type'] = array(
    '#type' => 'select',
    '#title' => t('Document Type'),
    '#options' => taxonomy_allowed_values(field_info_field('field_document_type')),
    '#default_value' => variable_get('group_actualites_document_type'),
    '#required' => TRUE,
  );
  
  return system_settings_form($form);
}

 /**
 * Get value from Form and put to function managed_file_upload
 */
function kandb_group_new(&$form, &$form_state) {
  module_load_include('inc', 'kandb_development_durable', 'kandb_development_durable.admin');
  $field_uploads = $form['#field_uploads'];
  foreach ($field_uploads as $field) {
    $fid_form = $form_state['values'][$field];
    $fid_variable = variable_get($field, FALSE);
    $module_name = 'kandb_group';
    $type = $field;
    group_page_managed_file_upload($fid_form, $fid_variable, $module_name, $type);
  }
}