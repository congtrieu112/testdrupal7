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

  $form['fieldset_group_block_header']['links_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('CTA Links'),
    '#tree' => TRUE,
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

  $number_cta = NUMBER_CTA_NEWS;
  $default_menu_titles = unserialize(KANDB_GROUP_NEWS_HEADER_MENU_DEFAULT_TITLES);
  $default_menu_links = unserialize(KANDB_GROUP_NEWS_HEADER_MENU_DEFAULT_LINKS);
  for ($i = 0; $i < $number_cta; $i++) {
    $url = $title = '';
    $cta = array();
    $cta = variable_get('cta_group_news_block_header_' . $i);
    if (isset($cta['url']) && $cta['url'] && isset($cta['title']) && $cta['title']) {
      $url = $cta['url'];
      $title = $cta['title'];
    } else {
      $url = $default_menu_links[$i];
      $title = $default_menu_titles[$i];
    }
    $form['fieldset_group_block_header']['links_fieldset']['cta']['cta_group_news_block_header_' . $i] = array(
      '#type' => 'link_field',
      '#title' => t('CTA') . ' #' . ($i + 1),
      '#field_parents' => NULL,
      '#description' => 'URL should be relative link. EX: /node/{nid}',
      '#language' => $language->language,
      '#field_name' => 'cta_group_news_block_header_' . $i,
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

  $form['group_actualites_module_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Module Title'),
    '#default_value' => variable_get('group_actualites_module_title'),
    '#required' => TRUE,
  );
  $form['group_actualites_document_type'] = array(
    '#type' => 'select',
    '#title' => t('Document Type'),
    '#options' => taxonomy_allowed_values(field_info_field('field_document_type')),
    '#default_value' => variable_get('group_actualites_document_type'),
    '#required' => TRUE,
  );

  $form['#submit'] = array(
    'kandb_group_settings_cta_link'
  );
  $form['#validate'] = array(
    'kandb_group_news_admin_validate_form'
  );

  return system_settings_form($form);
}

/**
 * Get value from Form and put to function managed_file_upload
 */
function kandb_group_new(&$form, &$form_state) {
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

/*
 * Validate for CTA link.
 */

function kandb_group_news_admin_validate_form(&$form, &$form_state) {
  $val = $form_state['values'];
  if (isset($val['links_fieldset']['cta'])) {
    foreach ($val['links_fieldset']['cta'] as $key => $item) {
      if (isset($item['title'])) {
        if (preg_match('/[\/~`\!@#\$%\^&\*\(\)_\-\+=\{\}\[\]\|;:"\<\>,\.\?\\\]/', $item['title'])) {
          form_set_error('links_fieldset][cta][' . $key . '][title', t('Please check the title again, only alphanumeric is acceptable'));
        }
      }
    }
  }
}

/*
 * Submit and save variable for CTA link.
 */

function kandb_group_settings_cta_link(&$form, &$form_state) {
  $val = $form_state['values'];
  if (isset($val['links_fieldset']['cta'])) {
    foreach ($val['links_fieldset']['cta'] as $key => $item) {
      if (isset($item['url']) && isset($item['title'])) {
        variable_set($key, $item);
      }
    }
  }
}
