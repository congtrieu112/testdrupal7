<?php
/**
 * @file
 * Admin function for kandb_selection module
 */

/**
 * Page Callback
 */
function kandb_selection_page_admin_form(){
  $form = array();

  $form['kandb_selection_photo'] = array(
    '#type' => 'managed_file',
    '#title' => t('Photo du block header de mon projet'),
    '#default_value' => variable_get('kandb_selection_photo'),
    '#upload_location' => 'public://',
  );
  $form['kandb_selection_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Titre du bloc header de mon projet'),
    '#default_value' => variable_get('kandb_selection_title'),
    '#required' => TRUE,
  );
  $form['kandb_selection_sub_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Sous titre du bloc header de mon projet'),
    '#default_value' => variable_get('kandb_selection_sub_title'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * hook_form_validate()
 */
function kandb_selection_page_admin_validate($form, &$form_state) {

}

/**
 * hook_form_submit()
 */
function kandb_selection_page_admin_submit($form, &$form_state) {

}