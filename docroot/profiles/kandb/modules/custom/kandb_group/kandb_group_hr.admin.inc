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
  $form['fieldset_recruitment_section'] = array(
    '#type' => 'fieldset',
    '#title' => 'Recruitment Section',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['fieldset_agenda_section'] = array(
    '#type' => 'fieldset',
    '#title' => 'Agenda Section',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['fieldset_offers_section'] = array(
    '#type' => 'fieldset',
    '#title' => 'Our recent job offers Section',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
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
    }
    else {
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

  $form['fieldset_recruitment_section']['image_group_hr_recruitment_section'] = array(
    '#type' => 'managed_file',
    '#title' => 'Image for block Recruitment Section',
    '#default_value' => variable_get('image_group_hr_recruitment_section'),
    '#upload_location' => 'public://',
  );
  $form['fieldset_recruitment_section']['title_group_hr_recruitment_section'] = array(
    '#type' => 'textfield',
    '#title' => t('Title block'),
    '#default_value' => variable_get('title_group_hr_recruitment_section', t('Recrutement')),
    '#size' => 60,
    '#maxlength' => 128,
  );
  $form['fieldset_recruitment_section']['subtitle_group_hr_recruitment_section'] = array(
    '#type' => 'textfield',
    '#title' => t('SubTitle block'),
    '#default_value' => variable_get('subtitle_group_hr_recruitment_section', t('Morbi leo sirus porta ac consectertur, vestibulum at eros.')),
    '#size' => 60,
    '#maxlength' => 128,
  );
  $form['fieldset_recruitment_section']['desciption_1_group_hr_recruitment_section'] = array(
    '#type' => 'textarea',
    '#title' => t('Description 1'),
    '#default_value' => variable_get('desciption_1_group_hr_recruitment_section'),
  );
  $form['fieldset_recruitment_section']['desciption_2_group_hr_recruitment_section'] = array(
    '#type' => 'textarea',
    '#title' => t('Description 2'),
    '#default_value' => variable_get('desciption_2_group_hr_recruitment_section'),
  );
  // Agenda.
  $form['fieldset_agenda_section']['title_group_hr_agenda_section'] = array(
    '#type' => 'textfield',
    '#title' => t('Title Block'),
    '#default_value' => variable_get('title_group_hr_agenda_section', t('Agenda')),
    '#size' => 60,
    '#maxlength' => 128,
  );
  $form['fieldset_agenda_section']['image_group_hr_agenda_section_1'] = array(
    '#type' => 'managed_file',
    '#title' => 'Image for block Agenda Section block 1',
    '#default_value' => variable_get('image_group_hr_agenda_section_1'),
    '#upload_location' => 'public://',
  );
  $form['fieldset_agenda_section']['date_group_hr_agenda_section_1'] = array(
    '#type' => 'date_select',
    '#title' => t('Date 1'),
    '#default_value' => variable_get('date_group_hr_agenda_section_1'),
    '#date_format' => 'Y-m-d',
  );
  $form['fieldset_agenda_section']['title_group_hr_agenda_section_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Title 1'),
    '#default_value' => variable_get('title_group_hr_agenda_section_1', t('Forum des métiers du batiment')),
    '#size' => 60,
    '#maxlength' => 128,
  );
  $form['fieldset_agenda_section']['description_group_hr_agenda_section_1'] = array(
    '#type' => 'textarea',
    '#title' => t('Description 1'),
    '#default_value' => variable_get('description_group_hr_agenda_section_1'),
  );

  $form['fieldset_agenda_section']['image_group_hr_agenda_section_2'] = array(
    '#type' => 'managed_file',
    '#title' => 'Image for block Agenda Section block 2',
    '#default_value' => variable_get('image_group_hr_agenda_section_2'),
    '#upload_location' => 'public://',
  );
  $form['fieldset_agenda_section']['date_group_hr_agenda_section_2'] = array(
    '#type' => 'date_select',
    '#title' => t('Date 2'),
    '#default_value' => variable_get('date_group_hr_agenda_section_2'),
    '#date_format' => 'Y-m-d',
  );
  $form['fieldset_agenda_section']['title_group_hr_agenda_section_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Title 2'),
    '#default_value' => variable_get('title_group_hr_agenda_section_2', t('Forum des maisons de France')),
    '#size' => 60,
    '#maxlength' => 128,
  );
  $form['fieldset_agenda_section']['description_group_hr_agenda_section_2'] = array(
    '#type' => 'textarea',
    '#title' => t('Description 2'),
    '#default_value' => variable_get('description_group_hr_agenda_section_2'),
  );

  $form['fieldset_offers_section']['title_group_hr_offres_section'] = array(
    '#type' => 'textfield',
    '#title' => t('SubTitle block'),
    '#default_value' => variable_get('title_group_hr_offres_section', t('Nos dernières offres d’emploi')),
    '#size' => 60,
    '#maxlength' => 128,
  );

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

/**
 * Explore Our Businesses Admin Settings Form.
 */
function kandb_group_rh_explore_our_businesses_admin_form($form, $form_state) {
  $form['explore_our_businesses_module_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Module Title'),
    '#default_value' => variable_get('explore_our_businesses_module_title'),
  );
  $form['explore_our_businesses_button_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Button Link'),
    '#default_value' => variable_get('explore_our_businesses_button_link'),
  );
  return system_settings_form($form);
}

/**
 * Apply Offers Admin Settings Form.
 */
function kandb_group_rh_apply_offers_admin_form($form, $form_state) {
  $form['fieldset_section_apply'] = array(
    '#type' => 'fieldset',
    '#title' => 'Section Apply',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['fieldset_section_apply']['section_apply_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('section_apply_title'),
  );
  $form['fieldset_section_apply']['section_apply_sub_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Sub Title'),
    '#default_value' => variable_get('section_apply_sub_title'),
  );
  $form['fieldset_section_apply']['section_apply_hang'] = array(
    '#type' => 'textfield',
    '#title' => t('Hang'),
    '#default_value' => variable_get('section_apply_hang'),
  );
  $form['fieldset_section_apply']['section_apply_descriptive'] = array(
    '#type' => 'textarea',
    '#title' => t('Descriptive'),
    '#default_value' => variable_get('section_apply_descriptive'),
  );
  $form['fieldset_section_apply']['section_apply_button_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Button Link'),
    '#default_value' => variable_get('section_apply_button_link'),
  );
  $form['fieldset_section_offers'] = array(
    '#type' => 'fieldset',
    '#title' => 'Section Offers',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['fieldset_section_offers']['section_offers_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('section_offers_title'),
  );

  return system_settings_form($form);
}