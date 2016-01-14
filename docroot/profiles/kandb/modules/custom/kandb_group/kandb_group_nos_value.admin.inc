<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */
function kandb_group_nos_valeurs_admin_form($form, $form_state) {
  $form['news_values_module_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Module Title'),
    '#default_value' => variable_get('news_values_module_title'),
  );
  $form['news_values_module_sub_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Sub-Title'),
    '#default_value' => variable_get('news_values_module_sub_title'),
  );
  $form['fieldset_news_values'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  for ($i = 0; $i <= KANDB_GROUP_NEWS_ITEMS_NUM; $i++) {
    $form['fieldset_news_values']['news_values_item_' . $i] = array(
      '#type' => 'fieldset',
      '#title' => t('Block #' . ($i + 1)),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['fieldset_news_values']['news_values_item_' . $i]['news_values_item_title_' . $i] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => variable_get('news_values_item_title_' . $i),
    );
    $description = variable_get('news_values_item_description_' . $i);
    $description = isset($description['value']) ? $description['value'] : '';
    $form['fieldset_news_values']['news_values_item_' . $i]['news_values_item_description_' . $i] = array(
      '#type' => 'text_format',
      '#title' => t('Description'),
      '#format' => 'simple',
      '#default_value' => $description,
    );
    $form['fieldset_news_values']['news_values_item_' . $i]['news_values_item_image_' . $i] = array(
      '#type' => 'managed_file',
      '#title' => t('Image Full'),
      '#default_value' => variable_get('news_values_item_image_' . $i),
      '#upload_location' => 'public://',
    );
    $form['#field_uploads'][] = 'news_values_item_image_' . $i;
  }

  return system_settings_form($form);
}
