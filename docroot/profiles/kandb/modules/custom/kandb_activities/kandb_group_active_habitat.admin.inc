<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */

/**
 * Group Home RH admin form.
 */
function kandb_group_active_habitat_form($form, $form_state) {
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

  $form['fieldset_habitat_section'] = array(
    '#type' => 'fieldset',
    '#title' => 'Habitat Section',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );


  $number_cta = NUMBER_CTA_ACTIVE;
  $default_menu_titles = unserialize(KANDB_GROUP_ACTIVITES_HEADER_MENU_DEFAULT_TITLES);
  $default_menu_links = unserialize(KANDB_GROUP_ACTIVITES_HEADER_MENU_DEFAULT_LINKS);
  for ($i = 0; $i < $number_cta; $i++) {
    $url = $title = '';
    $cta = array();
    $cta = variable_get('cta_group_activites_block_header_' . $i);
    if (isset($cta['url']) && $cta['url'] && isset($cta['title']) && $cta['title']) {
      $url = $cta['url'];
      $title = $cta['title'];
    } else {
      $url = $default_menu_links[$i];
      $title = $default_menu_titles[$i];
    }
    $form['fieldset_group_block_header']['links_fieldset']['cta']['cta_group_activites_block_header_' . $i] = array(
      '#type' => 'link_field',
      '#title' => t('CTA') . ' #' . ($i + 1),
      '#field_parents' => NULL,
      '#description' => 'URL should be relative link. EX: /node/{nid}',
      '#language' => $language->language,
      '#field_name' => 'cta_group_activites_block_header_' . $i,
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
  // Section Habitat.
  $form['fieldset_habitat_section']['title_group_habitat_section'] = array(
    '#type' => 'textfield',
    '#title' => t('Title block'),
    '#default_value' => variable_get('title_group_habitat_section', t('A propos de l’habitat')),
    '#size' => 60,
    '#maxlength' => 128,
  );
  $form['fieldset_habitat_section']['subtitle_group_habitat_section'] = array(
    '#type' => 'textfield',
    '#title' => t('SubTitle block'),
    '#default_value' => variable_get('subtitle_group_habitat_section', t('Nulla vitae elit libero, a pharetra augue donec ullamcorper nulla non')),
    '#size' => 60,
    '#maxlength' => 128,
  );
    $form['fieldset_habitat_section']['label_group_habitat_section'] = array(
    '#type' => 'textfield',
    '#title' => t('SubTitle for Description'),
    '#default_value' => variable_get('label_group_habitat_section', t('Donec id elit non mi porta gravida at eget metus morbi leo risus')),
    '#size' => 60,
    '#maxlength' => 128,
  );
  $form['fieldset_habitat_section']['desciption_group_habitat_section'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => variable_get('desciption_group_habitat_section', t('Sed posuere consectetur est at lobortis. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur')),
  );

  $form['#submit'] = array(
    'kandb_group_active_habitat_cta_link'
  );

  return system_settings_form($form);
}

/*
 * Submit and save variable for CTA link.
 */

function kandb_group_active_habitat_cta_link(&$form, &$form_state) {
  $val = $form_state['values'];
  if (isset($val['links_fieldset']['cta'])) {
    foreach ($val['links_fieldset']['cta'] as $key => $item) {
      if (isset($item['url']) && isset($item['title'])) {
        variable_set($key, $item);
      }
    }
  }
}
