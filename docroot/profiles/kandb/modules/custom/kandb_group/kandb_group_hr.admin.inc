<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */

/**
 * Group Home RH admin form.
 */
function kandb_group_rh_admin_form($form, $form_state) {
  global $language;
  $form['fieldset_group_block_header'] = array(
    '#type' => 'fieldset',
    '#title' => 'BLOCK HEADER',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['fieldset_group_block_header']['links_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('CTA Links'),
    '#tree' => TRUE,
  );

  $number_cta = NUMBER_CTA_RH;
  $default_menu_titles = unserialize(KANDB_GROUP_RH_HEADER_MENU_DEFAULT_TITLES);
  $default_menu_links = unserialize(KANDB_GROUP_RH_HEADER_MENU_DEFAULT_LINKS);
  for ($i = 0; $i < $number_cta; $i++) {
    $url = $title = '';
    $cta = array();
    $cta = variable_get('cta_group_rh_block_header_' . $i);
    if (isset($cta['url']) && $cta['url'] && isset($cta['title']) && $cta['title']) {
      $url = $cta['url'];
      $title = $cta['title'];
    } else {
      $url = $default_menu_links[$i];
      $title = $default_menu_titles[$i];
    }
    $form['fieldset_group_block_header']['links_fieldset']['cta']['cta_group_rh_block_header_' . $i] = array(
      '#type' => 'link_field',
      '#title' => t('CTA') . ' #' . ($i + 1),
      '#field_parents' => NULL,
      '#description' => 'URL should be relative link. EX: /node/{nid}',
      '#language' => $language->language,
      '#field_name' => 'cta_group_rh_block_header_' . $i,
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
    'kandb_group_settings_cta_link'
  );

  return system_settings_form($form);
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
