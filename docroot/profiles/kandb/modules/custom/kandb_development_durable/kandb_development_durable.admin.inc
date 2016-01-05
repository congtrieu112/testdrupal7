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
    //'#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
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

  $charte_description = variable_get('charte_description_group_development_block');
  $charte_description = isset($charte_description['value']) ? $charte_description['value'] : '';
  $form['fieldset_group_development_block']['charte_fieldset']['charte_description_group_development_block'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#format' => 'simple',
    '#default_value' => $charte_description,
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

  $nos_clients_description = variable_get('nos_clients_description_group_development_block');
  $nos_clients_description = isset($nos_clients_description['value']) ? $nos_clients_description['value'] : '';
  $form['fieldset_group_development_block']['nos_clients_fieldset']['nos_clients_description_group_development_block'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#format' => 'simple',
    '#default_value' => $nos_clients_description,
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

  $nos_partenaires_description = variable_get('nos_partenaires_description_group_development_block');
  $nos_partenaires_description = isset($nos_partenaires_description['value']) ? $nos_partenaires_description['value'] : '';
  $form['fieldset_group_development_block']['nos_partenaires_fieldset']['nos_partenaires_description_group_development_block'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#format' => 'simple',
    '#default_value' => $nos_partenaires_description,
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

  $nos_equipes_description = variable_get('nos_equipes_description_group_development_block');
  $nos_equipes_description = isset($nos_equipes_description['value']) ? $nos_equipes_description['value'] : '';
  $form['fieldset_group_development_block']['nos_equipes_fieldset']['nos_equipes_description_group_development_block'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#format' => 'simple',
    '#default_value' => $nos_equipes_description,
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

  $realisations_description = variable_get('realisations_description_group_development_block');
  $realisations_description = isset($realisations_description['value']) ? $realisations_description['value'] : '';
  $form['fieldset_group_development_block']['realisations_fieldset']['realisations_description_group_development_block'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#format' => 'simple',
    '#default_value' => $realisations_description,
  );

  $form['fieldset_group_development_block']['realisations_fieldset']['realisations_image_group_development_block'] = array(
    '#type' => 'managed_file',
    '#title' => t('Image Full'),
    '#default_value' => variable_get('realisations_image_group_development_block'),
    '#upload_location' => 'public://',
  );

  $form['fieldset_group_development_block']['realisations_fieldset']['realisations_embed_group_development_block'] = array(
    '#type' => 'textfield',
    '#title' => t('Embed'),
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
    $form['fieldset_group_development_block']['realisations_fieldset']['article_fieldset_' . $i]['realisations_article_' . $i . '_subtitle_group_development_block'] = array(
      '#type' => 'textfield',
      '#title' => t('Article Subtitle'),
      '#default_value' => variable_get('realisations_article_' . $i . '_subtitle_group_development_block'),
    );
    $form['fieldset_group_development_block']['realisations_fieldset']['article_fieldset_' . $i]['realisations_article_' . $i . '_image_group_development_block'] = array(
      '#type' => 'managed_file',
      '#title' => t('Article Image Full'),
      '#default_value' => variable_get('realisations_article_' . $i . '_image_group_development_block'),
      '#upload_location' => 'public://',
    );
  }

  $form['#submit'] = array(
    'kandb_group_development_manage_cta_link'
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
