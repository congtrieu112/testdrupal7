<?php

function kandb_finance_archives_admin_form() {
  $form = array();
  $form['page_title_archives_en'] = array(
    '#type' => 'textfield',
    '#title' => 'Page title of archives page in English',
    '#description' => t('Enter page title of archives page in English.'),
    '#default_value' => variable_get('page_title_archives_en', ''),
    '#required' => TRUE,
  );
  $form['page_title_archives_fr'] = array(
    '#type' => 'textfield',
    '#title' => 'Page title of archives page in French',
    '#description' => t('Enter page title of archives page in French.'),
    '#default_value' => variable_get('page_title_archives_fr', ''),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}