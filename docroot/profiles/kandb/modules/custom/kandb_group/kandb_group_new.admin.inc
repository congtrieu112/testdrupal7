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
  
  return system_settings_form($form);
}