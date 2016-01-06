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

  if (isset($form_state['input']['current_lang']) AND $form_state['input']['current_lang']) {
    $current_lang = $form_state['input']['current_lang'];
  }
  else {
    $query_arr = drupal_get_query_parameters();
    $current_lang = (isset($query_arr['lang']) AND $query_arr['lang']) ? $query_arr['lang'] : 'fr';
  }
  $form['current_lang'] = array('#type' => 'hidden', '#value' => ($current_lang));

  // START Finance presentation speech.
  $form['finance_presentation_speech'] = array(
    '#type' => 'fieldset',
    '#title' => t('Speech'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['finance_presentation_speech']['finance_presentation_speech_module_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Module Title'),
    '#default_value' => variable_get('finance_presentation_speech_module_title_' . $current_lang),
    '#required' => TRUE,
  );
  $form['finance_presentation_speech']['finance_presentation_speech_image_' . $current_lang] = array(
    '#type' => 'managed_file',
    '#title' => t('Image'),
    '#default_value' => variable_get('finance_presentation_speech_image_' . $current_lang),
    '#upload_location' => 'public://',
  );
  $form['finance_presentation_speech']['finance_presentation_speech_quote_' . $current_lang] = array(
    '#title' => t('Quote'),
    '#type' => 'textarea',
    '#default_value' => variable_get('finance_presentation_speech_quote_' . $current_lang),
    '#required' => TRUE,
  );
  $form['finance_presentation_speech']['finance_presentation_speech_author_name_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Author Name'),
    '#default_value' => variable_get('finance_presentation_speech_author_name_' . $current_lang),
    '#required' => TRUE,
  );
  $form['finance_presentation_speech']['finance_presentation_speech_job_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Job Title'),
    '#default_value' => variable_get('finance_presentation_speech_job_title_' . $current_lang),
    '#required' => TRUE,
  );
  $form['finance_presentation_speech']['finance_presentation_speech_buton_url_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Button URL'),
    '#default_value' => variable_get('finance_presentation_speech_buton_url_' . $current_lang),
    '#required' => TRUE,
  );
  // END Finance presentation speech.
  // START Finance presentation KPI.
  $form['finance_presentation_kpi'] = array(
    '#type' => 'fieldset',
    '#title' => t('KPI'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['finance_presentation_kpi']['finance_presentation_kpi_module_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Module Title'),
    '#default_value' => variable_get('finance_presentation_kpi_module_title_' . $current_lang),
    '#required' => TRUE,
  );
  for ($i = 1; $i <= KANDB_GROUP_KPI_ITEMS_NUM; $i++) {
    $form['finance_presentation_kpi']['finance_presentation_kpi_component_' . $i] = array(
      '#type' => 'fieldset',
      '#title' => t('KPI Component ' . $i),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['finance_presentation_kpi']['finance_presentation_kpi_component_' . $i]['finance_presentation_kpi_component_title_' . $i . '_' . $current_lang] = array(
      '#type' => 'textfield',
      '#title' => t('Component Title'),
      '#default_value' => variable_get('finance_presentation_kpi_component_title_' . $i . '_' . $current_lang),
    );
    $form['finance_presentation_kpi']['finance_presentation_kpi_component_' . $i]['finance_presentation_kpi_component_sub_title_' . $i . '_' . $current_lang] = array(
      '#type' => 'textfield',
      '#title' => t('Component Sub-Title'),
      '#default_value' => variable_get('finance_presentation_kpi_component_sub_title_' . $i . '_' . $current_lang),
    );
    $form['finance_presentation_kpi']['finance_presentation_kpi_component_' . $i]['finance_presentation_kpi_component_image_' . $i . '_' . $current_lang] = array(
      '#type' => 'managed_file',
      '#title' => t('Component Image'),
      '#default_value' => variable_get('finance_presentation_kpi_component_image_' . $i . '_' . $current_lang),
      '#upload_location' => 'public://',
    );
  }
  // END Finance presentation KPI.
  // START Finance presentation Notebooks.
  $form['finance_presentation_notebooks'] = array(
    '#type' => 'fieldset',
    '#title' => t('Notebooks'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['finance_presentation_notebooks']['finance_presentation_notebooks_module_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Module Title'),
    '#default_value' => variable_get('finance_presentation_notebooks_module_title_' . $current_lang),
    '#required' => TRUE,
  );
  $form['finance_presentation_notebooks']['finance_presentation_notebooks_data_block'] = array(
    '#type' => 'fieldset',
    '#title' => t('Data Block'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['finance_presentation_notebooks']['finance_presentation_notebooks_data_block']['finance_presentation_notebooks_data_block_part_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Part Title'),
    '#default_value' => variable_get('finance_presentation_notebooks_data_block_part_title_' . $current_lang),
    '#required' => TRUE,
  );
  for ($i = 1; $i <= KANDB_GROUP_DATA_BLOCK_ITEMS_NUM; $i++) {
    $form['finance_presentation_notebooks']['finance_presentation_notebooks_data_block']['finance_presentation_notebooks_data_block_line_' . $i] = array(
      '#type' => 'fieldset',
      '#title' => t('Data Line ' . $i),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['finance_presentation_notebooks']['finance_presentation_notebooks_data_block']['finance_presentation_notebooks_data_block_line_' . $i]['finance_presentation_notebooks_data_block_line_label_' . $i . '_' . $current_lang] = array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#default_value' => variable_get('finance_presentation_notebooks_data_block_line_label_' . $i . '_' . $current_lang),
    );
    $form['finance_presentation_notebooks']['finance_presentation_notebooks_data_block']['finance_presentation_notebooks_data_block_line_' . $i]['finance_presentation_notebooks_data_block_line_data_' . $i . '_' . $current_lang] = array(
      '#type' => 'textfield',
      '#title' => t('Data'),
      '#default_value' => variable_get('finance_presentation_notebooks_data_block_line_data_' . $i . '_' . $current_lang),
    );
  }
  $form['finance_presentation_notebooks']['finance_presentation_notebooks_image_' . $current_lang] = array(
    '#type' => 'managed_file',
    '#title' => t('Notebooks Image'),
    '#default_value' => variable_get('finance_presentation_notebooks_image_' . $current_lang),
    '#upload_location' => 'public://',
  );
  $form['finance_presentation_notebooks']['finance_presentation_notebooks_kpi'] = array(
    '#type' => 'fieldset',
    '#title' => t('KPI'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  for ($i = 1; $i <= KANDB_GROUP_NOTEBOOKS_KPI_ITEMS_NUM; $i++) {
    $form['finance_presentation_notebooks']['finance_presentation_notebooks_kpi']['finance_presentation_notebooks_kpi_component_' . $i] = array(
      '#type' => 'fieldset',
      '#title' => t('KPI Component ' . $i),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['finance_presentation_notebooks']['finance_presentation_notebooks_kpi']['finance_presentation_notebooks_kpi_component_' . $i]['finance_presentation_notebooks_kpi_component_title_' . $i . '_' . $current_lang] = array(
      '#type' => 'textfield',
      '#title' => t('Component Title'),
      '#default_value' => variable_get('finance_presentation_notebooks_kpi_component_title_' . $i . '_' . $current_lang),
    );
    $form['finance_presentation_notebooks']['finance_presentation_notebooks_kpi']['finance_presentation_notebooks_kpi_component_' . $i]['finance_presentation_notebooks_kpi_component_sub_title_' . $i . '_' . $current_lang] = array(
      '#type' => 'textfield',
      '#title' => t('Component Sub-Title'),
      '#default_value' => variable_get('finance_presentation_notebooks_kpi_component_sub_title_' . $i . '_' . $current_lang),
    );
    $form['finance_presentation_notebooks']['finance_presentation_notebooks_kpi']['finance_presentation_notebooks_kpi_component_' . $i]['finance_presentation_notebooks_kpi_component_image_' . $i . '_' . $current_lang] = array(
      '#type' => 'managed_file',
      '#title' => t('Component Image'),
      '#default_value' => variable_get('finance_presentation_notebooks_kpi_component_image_' . $i . '_' . $current_lang),
      '#upload_location' => 'public://',
    );
  }
  $form['finance_presentation_notebooks']['finance_presentation_notebooks_data_block_2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Data Block 2'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['finance_presentation_notebooks']['finance_presentation_notebooks_data_block_2']['finance_presentation_notebooks_data_block_2_part_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Part Title'),
    '#default_value' => variable_get('finance_presentation_notebooks_data_block_2_part_title_' . $current_lang),
    '#required' => TRUE,
  );
  for ($i = 1; $i <= KANDB_GROUP_DATA_BLOCK_ITEMS_NUM; $i++) {
    $form['finance_presentation_notebooks']['finance_presentation_notebooks_data_block_2']['finance_presentation_notebooks_data_block_2_line_' . $i] = array(
      '#type' => 'fieldset',
      '#title' => t('Data Line ' . $i),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['finance_presentation_notebooks']['finance_presentation_notebooks_data_block_2']['finance_presentation_notebooks_data_block_2_line_' . $i]['finance_presentation_notebooks_data_block_2_line_label_' . $i . '_' . $current_lang] = array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#default_value' => variable_get('finance_presentation_notebooks_data_block_2_line_label_' . $i . '_' . $current_lang),
    );
    $form['finance_presentation_notebooks']['finance_presentation_notebooks_data_block_2']['finance_presentation_notebooks_data_block_2_line_' . $i]['finance_presentation_notebooks_data_block_2_line_data_' . $i . '_' . $current_lang] = array(
      '#type' => 'textfield',
      '#title' => t('Data'),
      '#default_value' => variable_get('finance_presentation_notebooks_data_block_2_line_data_' . $i . '_' . $current_lang),
    );
  }
  // END Finance presentation Notebooks.
  // Add a validation for Data Block - 1 Max fields (mandatory) for each text data entered.
  $form['#validate'][] = 'finance_presentation_notebooks_data_block_validate';
  // Add a validation for Data Block 2 - 1 Max fields (mandatory) for each text data entered.
  $form['#validate'][] = 'finance_presentation_notebooks_data_block_2_validate';
  return system_settings_form($form);
}

/**
 * Gouvernance admin form.
 */
function kandb_group_finance_gouvernance_admin_form($form, $form_state) {
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

  $form['finance_gouvernance_module_title_' . $current_lang] = array(
    '#type' => 'textfield',
    '#title' => t('Module Title'),
    '#default_value' => variable_get('finance_gouvernance_module_title_' . $current_lang),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}

/**
 * Validation for Data Block - 1 Max fields (mandatory) for each text data entered.
 */
function finance_presentation_notebooks_data_block_validate($form, &$form_state) {
  $current_lang = $form_state['input']['current_lang'];
  $validated = FALSE;
  for ($i = 1; $i <= KANDB_GROUP_KPI_ITEMS_NUM; $i++) {
    $label = $form_state['input']['finance_presentation_notebooks_data_block_line_label_' . $i . '_' . $current_lang];
    $data = $form_state['input']['finance_presentation_notebooks_data_block_line_data_' . $i . '_' . $current_lang];
    if ($label AND $data) {
      $validated = TRUE;
      break;
    }
  }

  if ($validated == FALSE) {
    form_set_error('finance_presentation_notebooks_data_block_line_1', t('Data Block - 1 Max fields (mandatory) for each text data entered'));
  }
}

/**
 * Validation for Data Block 2 - 1 Max fields (mandatory) for each text data entered.
 */
function finance_presentation_notebooks_data_block_2_validate($form, &$form_state) {
  $current_lang = $form_state['input']['current_lang'];
  $validated = FALSE;
  for ($i = 1; $i <= KANDB_GROUP_KPI_ITEMS_NUM; $i++) {
    $label = $form_state['input']['finance_presentation_notebooks_data_block_2_line_label_' . $i . '_' . $current_lang];
    $data = $form_state['input']['finance_presentation_notebooks_data_block_2_line_data_' . $i . '_' . $current_lang];
    if ($label AND $data) {
      $validated = TRUE;
      break;
    }
  }

  if ($validated == FALSE) {
    form_set_error('finance_presentation_notebooks_data_block_2_line_1', t('Data Block 2 - 1 Max fields (mandatory) for each text data entered'));
  }
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
