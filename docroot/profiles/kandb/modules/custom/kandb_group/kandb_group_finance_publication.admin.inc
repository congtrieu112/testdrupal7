<?php
/**
 * Finance admin form.
 */
function kandb_group_finance_publication_admin_form($form, $form_state) {
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
  $form['current_lang'] = array('#type' => 'hidden', '#value' => ($current_lang));

  // START Finance presentation calendrier.
  $form['finance_publication_calendrier'] = array(
    '#type' => 'fieldset',
    '#title' => t('Calendrier'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  // START Finance publication form email.
  $form['finance_publication_email'] = array(
    '#type' => 'fieldset',
    '#title' => t('Email Form Setting'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $form['finance_publication_email']['finance_publication_email_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Email Title'),
    '#default_value' => variable_get('finance_publication_email_title_' . $current_lang),
  );
  $form['finance_publication_email']['finance_publication_email_input_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Email Input'),
    '#default_value' => variable_get('finance_publication_email_input_' . $current_lang),    
  );
  
  $form['finance_publication_calendrier']['finance_publication_calendrier_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Calendrier Title'),
    '#default_value' => variable_get('finance_publication_calendrier_title_' . $current_lang),    
  );
  $form['finance_publication_calendrier']['finance_publication_document_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Document Title'),
    '#default_value' => variable_get('finance_publication_document_title_' . $current_lang),    
  );

  for ($i = 1; $i <= 20; $i++) {
    $form['finance_publication_calendrier'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Calendrier ' . $i),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['finance_publication_calendrier'][$i]['finance_publication_calendrier_content_' . $current_lang . '_' . $i] = array(
      '#type' => 'textfield',
      '#title' => t('Content'),
      '#default_value' => variable_get('finance_publication_calendrier_content_' . $current_lang . '_' . $i, ''),
    );
    $form['finance_publication_calendrier'][$i]['finance_publication_calendrier_date_' . $current_lang . '_' . $i] = array(
      '#type' => 'date_select',
      '#title' => t('Date'),
      '#default_value' => variable_get('finance_publication_calendrier_date_' . $current_lang . '_' . $i, ''),
      '#date_format' => 'Y-m-d',
    );
  }

  return system_settings_form($form);
}

/**
 * Render finance language tabs.
 */
function kandb_ground_finance_language_tabs() {
  $result = '';
  $query_arr = drupal_get_query_parameters();
  $current_lang = (isset($query_arr['lang']) AND $query_arr['lang']) ? $query_arr['lang'] : 'fr';
  $lang_list = array(
    'fr' => t('French'),
    'en' => t('English'),
  );

  $i = 0;
  foreach ($lang_list as $key => $value) {
    if($current_lang == $key) {
      $value = '<strong>' . $value . '</strong>';
    }
    $link = '<a href="' . (url(current_path(), array('query' => array('lang' => $key)))) . '">' . $value . '</a>';
    $result .= ($i == 0) ? $link : (' | ' . $link);
    $i++;
  }

  return $result;
}



