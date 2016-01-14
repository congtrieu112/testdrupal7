<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */

/**
 * Group Home RH admin form.
 */
function kandb_seo_logement_admin_form($form, $form_state) {
  global $language;
  $form['fieldset_seo_logement_block'] = array(
    '#type' => 'fieldset',
    '#title' => 'BLOCK SEO LOGEMENT',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Header
  $form['fieldset_seo_logement_block']['header_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Header'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['fieldset_seo_logement_block']['header_fieldset']['header_title_seo_logement_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('header_title_seo_logement_block'),
  );

  $form['fieldset_seo_logement_block']['header_fieldset']['header_resume_seo_logement_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Resume'),
    '#default_value' => variable_get('header_resume_seo_logement_block'),
  );

  $form['fieldset_seo_logement_block']['header_fieldset']['header_image_seo_logement_block'] = array(
    '#type' => 'managed_file',
    '#title' => t('Image Full'),
    '#default_value' => variable_get('header_image_seo_logement_block'),
    '#upload_location' => 'public://',
  );

  // Heading
  $form['fieldset_seo_logement_block']['heading_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Heading'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['fieldset_seo_logement_block']['heading_fieldset']['heading_title_seo_logement_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('heading_title_seo_logement_block'),
  );
  $form['fieldset_seo_logement_block']['heading_fieldset']['heading_subtitle_seo_logement_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Sub Title'),
    '#default_value' => variable_get('heading_subtitle_seo_logement_block'),
  );

  // Typelogement
  $form['fieldset_seo_logement_block']['typelogement_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Type Logement'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['fieldset_seo_logement_block']['typelogement_fieldset']['typelogement_title_seo_logement_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('typelogement_title_seo_logement_block'),
  );
  $typelogement_description = variable_get('typelogement_description_seo_logement_block', array('value' => '', 'format' => NULL));
  $form['fieldset_seo_logement_block']['typelogement_fieldset']['typelogement_description_seo_logement_block'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#format' => isset($typelogement_description['format']) ? $typelogement_description['format'] : 'simple',
    '#default_value' => isset($typelogement_description['value']) ? $typelogement_description['value'] : '',
  );


  $form['#field_uploads'] = array(
    'header_image_seo_logement_block',
  );

  $form['#submit'] = array(
    'kandb_seo_logement_manage_form_update_status_managed_filed'
  );
  return system_settings_form($form);
}

/**
 * Get value from Form and put to function managed_file_upload
 */
function kandb_seo_logement_manage_form_update_status_managed_filed(&$form, &$form_state) {
  $field_uploads = $form['#field_uploads'];
  foreach ($field_uploads as $field) {
    $fid_form = $form_state['values'][$field];
    $fid_variable = variable_get($field, FALSE);
    $module_name = 'kandb_development_durable';
    $type = $field;
    seo_logement_managed_file_upload($fid_form, $fid_variable, $module_name, $type);
  }
}

/**
 * Managed file when users upload or delete.
 */
function seo_logement_managed_file_upload($fid_form, $fid_variable, $module_name, $type) {
  if ($fid_form != 0 && $fid_form != $fid_variable) {
    $file = file_load($fid_form);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, $module_name, $type, 1);
  } elseif ($fid_form == 0) {
    if ($fid_variable) {
      $delete_file = file_load($fid_variable);
      if ($delete_file) {
        file_usage_delete($delete_file, $module_name, $type, 1);
        $status = file_delete($delete_file);
      }
    }
  }
}
