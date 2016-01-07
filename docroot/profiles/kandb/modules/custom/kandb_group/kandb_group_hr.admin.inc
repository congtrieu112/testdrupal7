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
  $form['#validate'] = array(
    'kandb_group_rh_admin_validate_form'
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
function kandb_group_rh_explore_our_businesses_admin_form($form, &$form_state) {
  $form['explore_our_businesses_module_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Module Title'),
    '#default_value' => variable_get('explore_our_businesses_module_title'),
  );
  $form['fieldset_expolore_our_businesses'] = array(
    '#type' => 'fieldset',
    '#title' => t('Expolore Our Businesses'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  for ($i = 0; $i <= KANDB_GROUP_OUR_BUSINESS_ITEMS_NUM; $i++) {
    $form['fieldset_expolore_our_businesses']['expolore_our_businesses_item_' . $i] = array(
      '#type' => 'fieldset',
      '#title' => t('Our Business ' . ($i + 1)),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['fieldset_expolore_our_businesses']['expolore_our_businesses_item_' . $i]['expolore_our_businesses_wording' . $i] = array(
      '#type' => 'textfield',
      '#title' => t('Wording'),
      '#default_value' => variable_get('expolore_our_businesses_wording' . $i),
    );
    $description = variable_get('expolore_our_businesses_description' . $i);
    $description = isset($description['value']) ? $description['value'] : '';
    $form['fieldset_expolore_our_businesses']['expolore_our_businesses_item_' . $i]['expolore_our_businesses_description' . $i] = array(
      '#type' => 'text_format',
      '#title' => t('Description'),
      '#format' => 'simple',
      '#default_value' => $description,
    );
  }
  $form['explore_our_businesses_button_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Button Label'),
    '#default_value' => variable_get('explore_our_businesses_button_label'),
  );
  $form['explore_our_businesses_button_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Button Link'),
    '#default_value' => variable_get('explore_our_businesses_button_link'),
  );

  return system_settings_form($form);
}

function kandb_group_rh_your_career_admin_form($form, &$form_state) {
  $form['your_career_module_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Module Title'),
    '#default_value' => variable_get('your_career_module_title'),
  );
  $form['your_career_module_sub_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Sub-Title'),
    '#default_value' => variable_get('your_career_module_sub_title'),
  );
  $form['fieldset_your_career'] = array(
    '#type' => 'fieldset',
    '#title' => t('Your Career'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  for ($i = 0; $i <= KANDB_GROUP_YOUR_CAREER_ITEMS_NUM; $i++) {
    $form['fieldset_your_career']['your_career_item_' . $i] = array(
      '#type' => 'fieldset',
      '#title' => t('Our Business ' . ($i + 1)),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['fieldset_your_career']['your_career_item_' . $i]['your_career_item_title_' . $i] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => variable_get('your_career_item_title_' . $i),
    );
    $description = variable_get('your_career_item_description_' . $i);
    $description = isset($description['value']) ? $description['value'] : '';
    $form['fieldset_your_career']['your_career_item_' . $i]['your_career_item_description_' . $i] = array(
      '#type' => 'text_format',
      '#title' => t('Description'),
      '#format' => 'simple',
      '#default_value' => $description,
    );
    $form['fieldset_your_career']['your_career_item_' . $i]['your_career_item_image_' . $i] = array(
      '#type' => 'managed_file',
      '#title' => t('Image Full'),
      '#default_value' => variable_get('your_career_item_image_' . $i),
      '#upload_location' => 'public://',
    );
    $form['#field_uploads'][] = 'your_career_item_image_' . $i;
  }

  $form['#submit'] = array(
    'kandb_group_hr'
  );

  return system_settings_form($form);
}

/**
 * Get value from Form and put to function managed_file_upload
 */
function kandb_group_hr(&$form, &$form_state) {
  module_load_include('inc', 'kandb_development_durable', 'kandb_development_durable.admin');
  $field_uploads = $form['#field_uploads'];
  foreach ($field_uploads as $field) {
    $fid_form = $form_state['values'][$field];
    $fid_variable = variable_get($field, FALSE);
    $module_name = 'kandb_group';
    $type = $field;
    group_page_managed_file_upload($fid_form, $fid_variable, $module_name, $type);
  }
}
/*
 * Validate for CTA link.
 */
function kandb_group_rh_admin_validate_form(&$form, &$form_state){
  $val = $form_state['values'];
  if (isset($val['links_fieldset']['cta'])) {
    foreach ($val['links_fieldset']['cta'] as $key => $item) {
      if (isset($item['title'])) {
        if (preg_match('/[\/~`\!@#\$%\^&\*\(\)_\-\+=\{\}\[\]\|;:"\<\>,\.\?\\\]/', $item['title'])) {
          form_set_error('links_fieldset][cta]['.$key.'][title', t('Please check the title again, only alphanumeric is acceptable'));
        }
      }
    }
  }
}
