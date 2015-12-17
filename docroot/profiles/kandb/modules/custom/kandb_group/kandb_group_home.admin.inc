<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */

/**
 * Group Home admin form.
 */
function kandb_group_home_admin_form($form, $form_state) {
  global $language;
  $form['fieldset_group_block_finance'] = array(
    '#type' => 'fieldset',
    '#title' => 'BLOCK Finance',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['fieldset_group_block_finance']['image_group_home_block_finance'] = array(
    '#type' => 'managed_file',
    '#title' => 'Image for block finance in Group home page',
    '#default_value' => variable_get('image_group_home_block_finance'),
    '#upload_location' => 'public://',
  );
  $form['fieldset_group_block_finance']['title_group_home_block_finance'] = array(
    '#type' => 'textfield',
    '#title' => t('Title block'),
    '#default_value' => variable_get('title_group_home_block_finance', 'Finance'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );


  $form['#submit'] = array(
    'bkandb_group_settings_cta_link'
  );

  return system_settings_form($form);
}

function bkandb_group_settings_cta_link(&$form, &$form_state) {

}
