<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */

/**
 * Group Home RH admin form.
 */
function kandb_group_development_manage_form($form, $form_state) {
  global $language;
  $form['fieldset_group_development_block'] = array(
    '#type' => 'fieldset',
    '#title' => 'BLOCK DEVELOPMENT',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['fieldset_group_development_block']['links_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('CTA Links'),
    '#tree' => TRUE,
  );


  $number_cta = KANDB_GROUP_DEVELOPMENT_NUMBER_CTA_ACTIVE;
  $default_menu_titles = unserialize(KANDB_GROUP_DEVELOPMENT_HEADER_MENU_DEFAULT_TITLES);
  $default_menu_links = unserialize(KANDB_GROUP_DEVELOPMENT_HEADER_MENU_DEFAULT_LINKS);
  for ($i = 0; $i < $number_cta; $i++) {
    $url = $title = '';
    $cta = array();
    $cta = variable_get('cta_group_development_block_' . $i);
    if (isset($cta['url']) && $cta['url'] && isset($cta['title']) && $cta['title']) {
      $url = $cta['url'];
      $title = $cta['title'];
    } else {
      $url = $default_menu_links[$i];
      $title = $default_menu_titles[$i];
    }
    $form['fieldset_group_development_block']['links_fieldset']['cta']['cta_group_development_block_' . $i] = array(
      '#type' => 'link_field',
      '#title' => t('CTA') . ' #' . ($i + 1),
      '#field_parents' => NULL,
      '#description' => 'URL should be relative link. EX: /node/{nid}',
      '#language' => $language->language,
      '#field_name' => 'cta_group_development_block_' . $i,
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

  // Charte RSE
  $form['fieldset_group_development_block']['charte_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Charte RSE'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['fieldset_group_development_block']['charte_fieldset']['charte_title_group_development_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('charte_title_group_development_block'),
  );

  $form['fieldset_group_development_block']['charte_fieldset']['charte_resume_group_development_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Resume'),
    '#default_value' => variable_get('charte_resume_group_development_block'),
  );

  $charte_description = variable_get('charte_description_group_development_block', array('value' => '', 'format' => NULL));
  $form['fieldset_group_development_block']['charte_fieldset']['charte_description_group_development_block'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#format' => isset($charte_description['format']) ? $charte_description['format'] : '',
    '#default_value' => isset($charte_description['value']) ? $charte_description['value'] : '',
  );

  $form['fieldset_group_development_block']['charte_fieldset']['charte_image_group_development_block'] = array(
    '#type' => 'managed_file',
    '#title' => t('Image Full'),
    '#default_value' => variable_get('charte_image_group_development_block'),
    '#upload_location' => 'public://',
  );

  // Nos engagements clients
  $form['fieldset_group_development_block']['nos_clients_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Nos engagements clients'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['fieldset_group_development_block']['nos_clients_fieldset']['nos_clients_title_group_development_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('nos_clients_title_group_development_block'),
  );

  $form['fieldset_group_development_block']['nos_clients_fieldset']['nos_clients_resume_group_development_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Resume'),
    '#default_value' => variable_get('nos_clients_resume_group_development_block'),
  );

  $nos_clients_description = variable_get('nos_clients_description_group_development_block', array('value' => '', 'format' => NULL));
  $form['fieldset_group_development_block']['nos_clients_fieldset']['nos_clients_description_group_development_block'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#format' => isset($nos_clients_description['format']) ? $nos_clients_description['format'] : 'simple',
    '#default_value' => isset($nos_clients_description['value']) ? $nos_clients_description['value'] : '',
  );

  $form['fieldset_group_development_block']['nos_clients_fieldset']['nos_clients_image_group_development_block'] = array(
    '#type' => 'managed_file',
    '#title' => t('Image Full'),
    '#default_value' => variable_get('nos_clients_image_group_development_block'),
    '#upload_location' => 'public://',
  );

  // Nos engagements partenaires
  $form['fieldset_group_development_block']['nos_partenaires_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Nos engagements partenaires'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['fieldset_group_development_block']['nos_partenaires_fieldset']['nos_partenaires_title_group_development_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('nos_partenaires_title_group_development_block'),
  );

  $form['fieldset_group_development_block']['nos_partenaires_fieldset']['nos_partenaires_resume_group_development_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Resume'),
    '#default_value' => variable_get('nos_partenaires_resume_group_development_block'),
  );

  $nos_partenaires_description = variable_get('nos_partenaires_description_group_development_block', array('value' => '', 'format' => NULL));
  $form['fieldset_group_development_block']['nos_partenaires_fieldset']['nos_partenaires_description_group_development_block'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#format' => isset($nos_partenaires_description['format']) ? $nos_partenaires_description['format'] : 'simple',
    '#default_value' => isset($nos_partenaires_description['value']) ? $nos_partenaires_description['value'] : '',
  );

  $form['fieldset_group_development_block']['nos_partenaires_fieldset']['nos_partenaires_image_group_development_block'] = array(
    '#type' => 'managed_file',
    '#title' => t('Image Full'),
    '#default_value' => variable_get('nos_partenaires_image_group_development_block'),
    '#upload_location' => 'public://',
  );

  //Nos engagements équipes
  $form['fieldset_group_development_block']['nos_equipes_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Nos engagements équipes'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['fieldset_group_development_block']['nos_equipes_fieldset']['nos_equipes_title_group_development_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('nos_equipes_title_group_development_block'),
  );

  $form['fieldset_group_development_block']['nos_equipes_fieldset']['nos_equipes_resume_group_development_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Resume'),
    '#default_value' => variable_get('nos_equipes_resume_group_development_block'),
  );

  $nos_equipes_description = variable_get('nos_equipes_description_group_development_block', array('value' => '', 'format' => NULL));
  $form['fieldset_group_development_block']['nos_equipes_fieldset']['nos_equipes_description_group_development_block'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#format' => isset($nos_equipes_description['format']) ? $nos_equipes_description['format'] : 'simple',
    '#default_value' => isset($nos_equipes_description['value']) ? $nos_equipes_description['value'] : '',
  );

  $form['fieldset_group_development_block']['nos_equipes_fieldset']['nos_equipes_image_group_development_block'] = array(
    '#type' => 'managed_file',
    '#title' => t('Image Full'),
    '#default_value' => variable_get('nos_equipes_image_group_development_block'),
    '#upload_location' => 'public://',
  );

  // Réalisations
  $form['fieldset_group_development_block']['realisations_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Realisations'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['fieldset_group_development_block']['realisations_fieldset']['realisations_title_group_development_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('realisations_title_group_development_block'),
  );

  $form['fieldset_group_development_block']['realisations_fieldset']['realisations_subtitle_group_development_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Sub title'),
    '#default_value' => variable_get('realisations_subtitle_group_development_block'),
  );

  $realisations_description = variable_get('realisations_description_group_development_block', array('value' => '', 'format' => NULL));
  $form['fieldset_group_development_block']['realisations_fieldset']['realisations_description_group_development_block'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#format' => isset($realisations_description['format']) ? $realisations_description['format'] : 'simple',
    '#default_value' => isset($realisations_description['value']) ? $realisations_description['value'] : '',
  );

  $form['fieldset_group_development_block']['realisations_fieldset']['realisations_image_group_development_block'] = array(
    '#type' => 'managed_file',
    '#title' => t('Image Full'),
    '#default_value' => variable_get('realisations_image_group_development_block'),
    '#upload_location' => 'public://',
  );

  $form['fieldset_group_development_block']['realisations_fieldset']['realisations_embed_group_development_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Youtube Video ID'),
    '#default_value' => variable_get('realisations_embed_group_development_block'),
  );

  for($i = 1; $i <= 5; $i++) {
    $form['fieldset_group_development_block']['realisations_fieldset']['article_fieldset_' . $i] = array(
      '#type' => 'fieldset',
      '#title' => t('Realisations Article ' . $i),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['fieldset_group_development_block']['realisations_fieldset']['article_fieldset_' . $i]['realisations_article_' . $i . '_title_group_development_block'] = array(
      '#type' => 'textfield',
      '#title' => t('Article Title'),
      '#default_value' => variable_get('realisations_article_' . $i . '_title_group_development_block'),
    );
    $article_description = variable_get('realisations_article_' . $i . '_subtitle_group_development_block', array('value' => '', 'format' => NULL));
    $form['fieldset_group_development_block']['realisations_fieldset']['article_fieldset_' . $i]['realisations_article_' . $i . '_subtitle_group_development_block'] = array(
      '#type' => 'text_format',
      '#title' => t('Article Description'),
      '#format' => isset($article_description['format']) ? $article_description['format'] : 'simple',
      '#default_value' => isset($article_description['value']) ? $article_description['value'] : '',
    );
    $form['fieldset_group_development_block']['realisations_fieldset']['article_fieldset_' . $i]['realisations_article_' . $i . '_image_group_development_block'] = array(
      '#type' => 'managed_file',
      '#title' => t('Article Image Full'),
      '#default_value' => variable_get('realisations_article_' . $i . '_image_group_development_block'),
      '#upload_location' => 'public://',
    );
  }

  $form['#field_uploads'] = array(
    'charte_image_group_development_block',
    'nos_clients_image_group_development_block',
    'nos_partenaires_image_group_development_block',
    'nos_equipes_image_group_development_block',
    'realisations_image_group_development_block',
    'realisations_article_1_image_group_development_block',
    'realisations_article_2_image_group_development_block',
    'realisations_article_3_image_group_development_block',
    'realisations_article_4_image_group_development_block',
    'realisations_article_5_image_group_development_block',
  );

  $form['#submit'] = array(
    'kandb_group_development_manage_cta_link',
    'kandb_group_development_manage_form_update_status_managed_filed'
  );
  return system_settings_form($form);
}

/*
 * Submit and save variable for CTA link.
 */

function kandb_group_development_manage_cta_link(&$form, &$form_state) {
  $val = $form_state['values'];
  if (isset($val['links_fieldset']['cta'])) {
    foreach ($val['links_fieldset']['cta'] as $key => $item) {
      if (isset($item['url']) && isset($item['title'])) {
        variable_set($key, $item);
      }
    }
  }
}

/**
 * Get value from Form and put to function managed_file_upload
 */
function kandb_group_development_manage_form_update_status_managed_filed(&$form, &$form_state) {
  $field_uploads = $form['#field_uploads'];
  foreach ($field_uploads as $field) {
    $fid_form = $form_state['values'][$field];
    $fid_variable = variable_get($field, FALSE);
    $module_name = 'kandb_development_durable';
    $type = $field;
    group_page_managed_file_upload($fid_form, $fid_variable, $module_name, $type);
  }
}

/**
 * Managed file when users upload or delete.
 */
function group_page_managed_file_upload($fid_form, $fid_variable, $module_name, $type) {
  if ($fid_form != 0 && $fid_form != $fid_variable) {
    $file = file_load($fid_form);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, $module_name, $type, 1);
  }
  elseif ($fid_form == 0) {
    if ($fid_variable) {
      $delete_file = file_load($fid_variable);
      if($delete_file) {
        file_usage_delete($delete_file, $module_name, $type, 1);
        $status = file_delete($delete_file);
      }
    }
  }
}