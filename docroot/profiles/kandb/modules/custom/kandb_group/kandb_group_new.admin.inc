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
  
  return system_settings_form($form);
}

 /**
 * Get value from Form and put to function managed_file_upload
 */
function kandb_group_new(&$form, &$form_state) {
  $field_uploads = $form['#field_uploads'];
  foreach ($field_uploads as $field) {
    $fid_form = $form_state['values'][$field];
    $fid_variable = variable_get($field, FALSE);
    $module_name = 'kandb_group';
    $type = $field;
    group_page_new_managed_file_upload($fid_form, $fid_variable, $module_name, $type);
  }
}

/**
 * Managed file when users upload or delete.
 */
function group_page_new_managed_file_upload($fid_form, $fid_variable, $module_name, $type) {
  if ($fid_form != 0 && $fid_form != $fid_variable) {
    $file = file_load($fid_form);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, $module_name, $type, 1);
  }
  elseif ($fid_form == 0) {
    if ($fid_variable) {
      $delete_file = file_load($fid_variable);
      if($delete_file) {
        file_usage_delete($delete_file, $module_name, $type, 1);
        $status = file_delete($delete_file);
      }
    }
  }
}