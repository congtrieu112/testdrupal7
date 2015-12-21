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

  $form['fieldset_group_block_finance']['links_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('CTA Links'),
    '#tree' => TRUE,
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

  $number_cta = NUMBER_CTA_GROUP;
  for ($i = 0; $i < $number_cta; $i++) {
    $url = $title = '';
    $cta = array();
    $cta = variable_get('cta_group_home_block_finance_' . $i);
    if (isset($cta['url']) && isset($cta['title'])) {
      $url = $cta['url'];
      $title = $cta['title'];
    }
    $form['fieldset_group_block_finance']['links_fieldset']['cta']['cta_group_home_block_finance_' . $i] = array(
      '#type' => 'link_field',
      '#title' => t('CTA') . ' #' . ($i+1),
      '#field_parents' => NULL,
      '#description' => 'URL should be relative link. EX: /node/{nid}',
      '#language' => $language->language,
      '#field_name' => 'cta_title_group_home_block_finance_' . $i,
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

  $form['#submit'] = array(
    'bkandb_group_settings_cta_link'
  );

  return system_settings_form($form);
}

/*
 * Submit and save variable for CTA link.
 */

function bkandb_group_settings_cta_link(&$form, &$form_state) {
  $val = $form_state['values'];
  if (isset($val['links_fieldset']['cta'])) {
    foreach ($val['links_fieldset']['cta'] as $key => $item) {
      if (isset($item['url']) && isset($item['title'])) {
        variable_set($key, $item);
      }
    }
  }
}
