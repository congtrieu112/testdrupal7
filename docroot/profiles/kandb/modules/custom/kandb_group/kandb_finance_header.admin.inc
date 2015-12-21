<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */
define('KANDB_GROUP_KPI_ITEMS_NUM', 20);
define('KANDB_GROUP_NOTEBOOKS_KPI_ITEMS_NUM', 10);
define('KANDB_GROUP_DATA_BLOCK_ITEMS_NUM', 20);

/**
 * Finance admin form.
 */
function kandb_group_finance_header_admin_form($form, $form_state) {
  $form['settings_links'] = array(
    '#markup' => kandb_ground_finance_language_tabs(),
  );

  if (isset($form_state['input']['current_lang']) AND $form_state['input']['current_lang']) {
    $current_lang = $form_state['input']['current_lang'];
  } else {
    $query_arr = drupal_get_query_parameters();
    $current_lang = (isset($query_arr['lang']) AND $query_arr['lang']) ? $query_arr['lang'] : 'fr';
  }
  $form['current_lang'] = array('#type' => 'hidden', '#value' => ($current_lang));

  // START Finance presentation speech.
  $form['finance_header'] = array(
    '#type' => 'fieldset',
    '#title' => t('Block Header'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['finance_header']['finance_header_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('finance_header_title_' . $current_lang),
    '#required' => TRUE,
  );
  $form['finance_header']['finance_header_sub_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('SubTitle'),
    '#default_value' => variable_get('finance_header_sub_title_' . $current_lang),
    '#required' => TRUE,
  );
  $form['finance_header']['finance_header_image_full_' . $current_lang] = array(
    '#type' => 'managed_file',
    '#title' => t('Image Full'),
    '#default_value' => variable_get('finance_header_image_full_' . $current_lang),
    '#upload_location' => 'public://',
  );
  $form['finance_header']['finance_header_image_small_' . $current_lang] = array(
    '#type' => 'managed_file',
    '#title' => t('Image for mobile'),
    '#default_value' => variable_get('finance_header_image_small_' . $current_lang),
    '#upload_location' => 'public://',
  );

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
