<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */

/**
 * Finance admin form.
 */
function kandb_group_finance_presentation_admin_form($form, $form_state) {
  $form['settings_links'] = array(
    '#markup' => kandb_ground_finance_language_tabs(),
  );

  $form['finance_presentation_speech'] = array(
    '#type' => 'fieldset',
    '#title' => t('Speech'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['finance_presentation_speech']['finance_presentation_speech_module_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Module Title'),
    '#default_value' => variable_get(''),
    '#required' => TRUE,
  );
  $form['finance_presentation_speech']['finance_presentation_speech_quote'] = array(
    '#title' => t('Quote'),
    '#type' => 'textarea',
    '#default_value' => '',
    '#required' => TRUE,
  );

  return $form;
}

function kandb_ground_finance_language_tabs() {
  global $base_root;
  $result = '';
  $lang_list = array(
    'fr' => t('French'),
    'en' => t('English'),
  );

  $i = 0;
  foreach ($lang_list as $key => $value) {
    $link = l($value, $base_root . '/' . current_path() . '?key=' . $key);
    $result .= ($i == 0) ? $link : (' | ' . $link);
    $i++;
  }

  return $result;
}
