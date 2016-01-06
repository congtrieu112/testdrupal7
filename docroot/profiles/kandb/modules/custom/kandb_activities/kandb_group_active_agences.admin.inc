<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */

/**
 * Group Home RH admin form.
 */
function kandb_group_active_agences_form($form, $form_state) {
  global $language;

  $form['fieldset_agences_section'] = array(
    '#type' => 'fieldset',
    '#title' => 'Agences Section',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Section Habitat.
  $form['fieldset_agences_section']['title_group_agences_section'] = array(
    '#type' => 'textfield',
    '#title' => t('Title block'),
    '#default_value' => variable_get('title_group_agences_section', t('Contactez-nous')),
    '#size' => 60,
    '#maxlength' => 128,
  );
  $form['fieldset_agences_section']['desciption_group_agences_section'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => variable_get('desciption_group_agences_section', t('Retrouvez ci-dessous les coordonées de l\'ensemble des conseillers régionaux K&B Patrimoine')),
  );

  return system_settings_form($form);
}
