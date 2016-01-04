<?php

/**
 * @file
 * Implements Back-end functions of KB Simulator.
 */

/**
 * Simulator admin form.
 */
function kandb_simulator_admin_form($form, $form_state) {
  global $language;
  $form['fieldset_simulator_block_header'] = array(
      '#type' => 'fieldset',
      '#title' => 'BLOCK HEADER',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
  );

  $form['fieldset_simulator_block_header']['links_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Simuler Links'),
      '#tree' => TRUE,
  );
  $form['fieldset_calculer_section'] = array(
      '#type' => 'fieldset',
      '#title' => t('Calculer votre capacité d’achat Section'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
  );
  $form['fieldset_estimer_section'] = array(
      '#type' => 'fieldset',
      '#title' => 'Estimer les mensualités de remboursement Section',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
  );
  $form['fieldset_simuler_vos_section'] = array(
      '#type' => 'fieldset',
      '#title' => 'Simuler vos droits au PTZ+ Section',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
  );
  $form['fieldset_simuler_mon_section'] = array(
      '#type' => 'fieldset',
      '#title' => 'Simuler mon investissement avec la loi Pinel Section',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
  );

  $number_si = NUMBER_SIMULATOR;
  $default_menu_titles = unserialize(KANDB_SIMULATOR_HEADER_MENU_DEFAULT_TITLES);
  $default_menu_links = unserialize(KANDB_SIMULATOR_HEADER_MENU_DEFAULT_LINKS);
  for ($i = 0; $i < $number_si; $i++) {
    $url = $title = '';
    $si = array();
    $si = variable_get('si_simulator_block_header_' . $i);
    if (isset($si['url']) && $si['url'] && isset($si['title']) && $si['title']) {
      $url = $si['url'];
      $title = $si['title'];
    } else {
      $url = $default_menu_links[$i];
      $title = $default_menu_titles[$i];
    }
    $form['fieldset_simulator_block_header']['links_fieldset']['si']['si_simulator_block_header_' . $i] = array(
        '#type' => 'link_field',
        '#title' => t('Simuler') . ' #' . ($i + 1),
        '#field_parents' => NULL,
        '#description' => 'URL should be relative link',
        '#language' => $language->language,
        '#field_name' => 'si_simulator_block_header_' . $i,
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
  //Calculer votre capacité d’achat
  $form['fieldset_calculer_section']['title_simulator_calculer_section'] = array(
      '#type' => 'textfield',
      '#title' => t('Title block'),
      '#default_value' => variable_get('title_simulator_calculer_section'),
      '#size' => 60,
      '#maxlength' => 128,
  );
  $form['fieldset_calculer_section']['subtitle_simulator_calculer_section'] = array(
      '#type' => 'textfield',
      '#title' => t('SubTitle block'),
      '#default_value' => variable_get('subtitle_simulator_calculer_section'),
      '#size' => 60,
      '#maxlength' => 128,
  );

  //Estimer les mensualités de remboursement
  $form['fieldset_estimer_section']['title_simulator_estimer_section'] = array(
      '#type' => 'textfield',
      '#title' => t('Title block'),
      '#default_value' => variable_get('title_simulator_estimer_section'),
      '#size' => 60,
      '#maxlength' => 128,
  );
  $form['fieldset_estimer_section']['subtitle_simulator_estimer_section'] = array(
      '#type' => 'textfield',
      '#title' => t('SubTitle block'),
      '#default_value' => variable_get('subtitle_simulator_estimer_section'),
      '#size' => 60,
      '#maxlength' => 128,
  );
  //Simuler vos droits au PTZ+
  $form['fieldset_simuler_vos_section']['title_simulator_vos_section'] = array(
      '#type' => 'textfield',
      '#title' => t('Title block'),
      '#default_value' => variable_get('title_simulator_vos_section'),
      '#size' => 60,
      '#maxlength' => 128,
  );
  $form['fieldset_simuler_vos_section']['subtitle_simulator_vos_section'] = array(
      '#type' => 'textfield',
      '#title' => t('SubTitle block'),
      '#default_value' => variable_get('subtitle_simulator_vos_section'),
      '#size' => 60,
      '#maxlength' => 128,
  );

  //Simuler mon investissement avec la loi Pinel
  $form['fieldset_simuler_mon_section']['title_simulator_mon_section'] = array(
      '#type' => 'textfield',
      '#title' => t('Title block'),
      '#default_value' => variable_get('title_simulator_mon_section'),
      '#size' => 60,
      '#maxlength' => 128,
  );
  $form['fieldset_simuler_mon_section']['subtitle_simulator_mon_section'] = array(
      '#type' => 'textfield',
      '#title' => t('SubTitle block'),
      '#default_value' => variable_get('subtitle_simulator_mon_section'),
      '#size' => 60,
      '#maxlength' => 128,
  );


  $form['#submit'] = array(
      'kandb_simulator_settings_si_link'
  );

  return system_settings_form($form);
}

/*
 * Submit and save variable for Si link.
 */

function kandb_simulator_settings_si_link(&$form, &$form_state) {
  $val = $form_state['values'];
  if (isset($val['links_fieldset']['si'])) {
    foreach ($val['links_fieldset']['si'] as $key => $item) {
      if (isset($item['url']) && isset($item['title'])) {
        variable_set($key, $item);
      }
    }
  }
}
