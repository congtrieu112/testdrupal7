<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */
define('KANDB_GROUP_KPI_ITEMS_NUM', 20);

/**
 * Finance admin form.
 */
function kandb_group_finance_presentation_admin_form($form, $form_state) {
  $form['settings_links'] = array(
    '#markup' => kandb_ground_finance_language_tabs(),
  );

  if (preg_match('/file\/ajax/i', $_GET['q'])) {
    $current_lang = $form_state['input']['current_lang'];
  }
  else {
    $query_arr = drupal_get_query_parameters();
    $current_lang = (isset($query_arr['lang']) AND $query_arr['lang']) ? $query_arr['lang'] : 'fr';
  }
  $form['current_lang'] = array('#type' => 'hidden', '#value' => ($current_lang));

  // START Finance presentation speech.
  $form['finance_presentation_speech'] = array(
    '#type' => 'fieldset',
    '#title' => t('Speech'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['finance_presentation_speech']['finance_presentation_speech_module_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Module Title'),
    '#default_value' => variable_get('finance_presentation_speech_module_title_' . $current_lang),
    '#required' => TRUE,
  );
  $form['finance_presentation_speech']['finance_presentation_speech_image_' . $current_lang] = array(
    '#type' => 'managed_file',
    '#title' => t('Image'),
    '#default_value' => variable_get('finance_presentation_speech_image_' . $current_lang),
    '#upload_location' => 'public://',
  );
  $form['finance_presentation_speech']['finance_presentation_speech_quote_' . $current_lang] = array(
    '#title' => t('Quote'),
    '#type' => 'textarea',
    '#default_value' => variable_get('finance_presentation_speech_quote_' . $current_lang),
    '#required' => TRUE,
  );
  $form['finance_presentation_speech']['finance_presentation_speech_author_name_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Author Name'),
    '#default_value' => variable_get('finance_presentation_speech_author_name_' . $current_lang),
    '#required' => TRUE,
  );
  $form['finance_presentation_speech']['finance_presentation_speech_job_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Job Title'),
    '#default_value' => variable_get('finance_presentation_speech_job_title_' . $current_lang),
    '#required' => TRUE,
  );
  $form['finance_presentation_speech']['finance_presentation_speech_buton_url_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Button URL'),
    '#default_value' => variable_get('finance_presentation_speech_buton_url_' . $current_lang),
    '#required' => TRUE,
  );
  // END Finance presentation speech.
  // START Finance presentation SPI.
  $form['finance_presentation_kpi'] = array(
    '#type' => 'fieldset',
    '#title' => t('KPI'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['finance_presentation_kpi']['finance_presentation_kpi_module_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Module Title'),
    '#default_value' => variable_get('finance_presentation_kpi_module_title'),
    '#required' => TRUE,
  );
  for ($i = 0; $i < KANDB_GROUP_KPI_ITEMS_NUM; $i++) {
    
  }
  // END Finance presentation SPI.

  return system_settings_form($form);
}

/**
 * Render finance language tabs.
 */
function kandb_ground_finance_language_tabs() {
  $result = '';
  $lang_list = array(
    'fr' => t('French'),
    'en' => t('English'),
  );

  $i = 0;
  foreach ($lang_list as $key => $value) {
    $link = '<a href="' . (url(current_path(), array('query' => array('lang' => $key)))) . '">' . $value . '</a>';
    $result .= ($i == 0) ? $link : (' | ' . $link);
    $i++;
  }

  return $result;
}
