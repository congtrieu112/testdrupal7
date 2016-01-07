<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */
define('KANDB_GROUP_KPI_ITEMS_NUM', 20);
define('KANDB_GROUP_NOTEBOOKS_KPI_ITEMS_NUM', 10);
define('KANDB_GROUP_DATA_BLOCK_ITEMS_NUM', 20);
define('KANDB_MENU_ITEM_NUM', 5);

/**
 * Finance admin form.
 */
function kandb_group_finance_header_admin_form($form, $form_state) {
  global $language;
  $form['settings_links'] = array(
    '#markup' => kandb_ground_finance_language_tabs(),
  );

  if (isset($form_state['input']['current_lang']) AND $form_state['input']['current_lang']) {
    $current_lang = $form_state['input']['current_lang'];
  }
  else {
    $query_arr = drupal_get_query_parameters();
    $current_lang = (isset($query_arr['lang']) AND $query_arr['lang']) ? $query_arr['lang'] : 'fr';
  }
//  echo '<pre>';
//  print_r($current_lang);
//  echo '</pre>';
//  die();
  $form['current_lang'] = array('#type' => 'hidden', '#value' => ($current_lang));

  // START Finance presentation speech.
  $form['finance_header'] = array(
    '#type' => 'fieldset',
    '#title' => t('Block Header'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['fieldset_finance_menu']['links_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menu items'),
    '#tree' => TRUE,
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

  $number_cta = KANDB_MENU_ITEM_NUM;
  $default_menu_titles = $current_lang == 'en' ? unserialize(KANDB_GROUP_HEADER_MENU_DEFAULT_TITLES_EN) : unserialize(KANDB_GROUP_HEADER_MENU_DEFAULT_TITLES_FR);
  $default_menu_links = unserialize(KANDB_GROUP_HEADER_MENU_DEFAULT_LINKS);
  for ($i = 0; $i < $number_cta; $i++) {
    $url = $title = '';
    $cta = array();
    $cta = variable_get('cta_menu_item_finance_' . $i . '_' . $current_lang);
    if (isset($cta['url']) && $cta['url'] && isset($cta['title']) && $cta['title']) {
      $url = $cta['url'];
      $title = $cta['title'];
    }
    else {
      $url = $current_lang == 'en' ? $default_menu_links[$i] . '/en' : $default_menu_links[$i];
      $title = $default_menu_titles[$i];
    }
    
    $url_desctiption = $current_lang == 'en' ? $default_menu_links[$i] . '/en' : ($current_lang == 'fr' ? $default_menu_links[$i] . '/fr': $default_menu_links[$i]);
    $description = 'URL should be relative link. EX: /node/{nid}.';
    $description .= '<br /> <br />';
    $description .= 'Please remember to put language code (fr) at the end of the URL.';
    $description .= ' For example: '. $url_desctiption;

    $form['fieldset_finance_menu']['links_fieldset']['cta']['cta_menu_item_finance_' . $i . '_' . $current_lang] = array(
      '#type' => 'link_field',
      '#title' => t('CTA') . ' #' . ($i + 1),
      '#field_parents' => NULL,
      '#description' => $description,

      '#language' => $language->language,
      '#field_name' => 'cta_menu_item_finance_' . $i . '_' . $current_lang,
      '#delta' => 0,
      '#default_value' => array(
        'title' => $title,
        'url' => $url,
      ),
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => FALSE,
    );
  }
  $form['#field_uploads'] = array(
    'finance_header_image_full_' . $current_lang,
    'finance_header_image_small_' . $current_lang

  );

  $form['#submit'] = array(
    'bkandb_menu_cta_link',
    'kandb_finance_header'
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

/*
 * Submit and save variable for CTA link.
 */

function bkandb_menu_cta_link(&$form, &$form_state) {
  $val = $form_state['values'];
  if (isset($val['links_fieldset']['cta'])) {
    foreach ($val['links_fieldset']['cta'] as $key => $item) {
      if (isset($item['url']) && isset($item['title'])) {
        variable_set($key, $item);
      }
    }
  }
}

/**
 * Get value from Form and put to function managed_file_upload
 */
function kandb_finance_header(&$form, &$form_state) {
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