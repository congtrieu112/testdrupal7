<?php

function kandb_finance_assemblies_admin_form() {
  $form = array();
  $form['page_title_assemblies_en'] = array(
    '#type' => 'textfield',
    '#title' => 'Page title of assemblies page in English',
    '#description' => t('Enter page title of assemblies page in English.'),
    '#default_value' => variable_get('page_title_assemblies_en', ''),
    '#required' => TRUE,
  );
  $form['page_title_assemblies_fr'] = array(
    '#type' => 'textfield',
    '#title' => 'Page title of assemblies page in French',
    '#description' => t('Enter page title of assemblies page in French.'),
    '#default_value' => variable_get('page_title_assemblies_fr', ''),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}