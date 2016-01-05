<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */
function kandb_group_active_tertiaire_form($form, $form_state) {

    $form['bloc_edito'] = array(
      '#type' => 'fieldset',
      '#title' => t('bloc Édito'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['bloc_edito']['bloc_edito_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => variable_get('bloc_edito_title'),
    );
    $form['bloc_edito']['bloc_edito_sub_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Sub title'),
      '#default_value' => variable_get('bloc_edito_sub_title'),
    );
    $form['bloc_edito']['bloc_edito_description'] = array(
      '#title' => t('Description'),
      '#type' => 'text_format',
      '#default_value' => variable_get('bloc_edito_description'),
    );
    $form['bloc_edito']['bloc_edito_kpi_item_image'] = array(
      '#type' => 'managed_file',
      '#title' => t(' KPI item'),
      '#default_value' => variable_get('bloc_edito_kpi_item_image'),
      '#upload_location' => 'public://',
    );
    //bloc Bureau
    $form['bloc_bureau'] = array(
      '#type' => 'fieldset',
      '#title' => t('bloc Bureau'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
     $form['bloc_bureau']['bloc_bureau_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => variable_get('bloc_bureau_title'),
    );
    $form['bloc_bureau']['bloc_bureau_sub_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Sub title'),
      '#default_value' => variable_get('bloc_bureau_sub_title'),
    );
    $form['bloc_bureau']['bloc_bureau_description'] = array(
      '#title' => t('Description'),
      '#type' => 'text_format',
      '#default_value' => variable_get('bloc_bureau_description'),
    );
    $form['bloc_bureau']['bloc_bureau_kpi'] = array(
      '#type' => 'fieldset',
      '#title' => t('KPI'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    for ($i = 1; $i <= BLOC_BUREAU_KPI_ITEMS_NUM; $i++) {
      $form['bloc_bureau']['bloc_bureau_kpi']['bloc_bureau_kpi_component_' . $i] = array(
        '#type' => 'fieldset',
        '#title' => t('KPI Component ' . $i),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['bloc_bureau']['bloc_bureau_kpi']['bloc_bureau_kpi_component_' . $i]['bloc_bureau_kpi_component_title_' . $i ] = array(
        '#type' => 'textfield',
        '#title' => t('Component Title'),
        '#default_value' => variable_get('bloc_bureau_kpi_component_title_' . $i ),
      );
      $form['bloc_bureau']['bloc_bureau_kpi']['bloc_bureau_kpi_component_' . $i]['bloc_bureau_kpi_component_sub_title_' . $i ] = array(
        '#type' => 'textfield',
        '#title' => t('Component Sub-Title'),
        '#default_value' => variable_get('bloc_bureau_kpi_component_sub_title_' . $i ),
      );
      $form['bloc_bureau']['bloc_bureau_kpi']['bloc_bureau_kpi_component_' . $i]['bloc_bureau_kpi_component_image_' . $i ] = array(
        '#type' => 'managed_file',
        '#title' => t('Component Image'),
        '#default_value' => variable_get('bloc_bureau_kpi_component_image_' . $i ),
        '#upload_location' => 'public://',
      );
    }
    $form['bloc_bureau']['bloc_bureau_cta_text'] = array(
      '#title' => t('Cta Text'),
      '#type' => 'textfield',
      '#default_value' => variable_get('bloc_bureau_cta_text'),
    );
    $form['bloc_bureau']['bloc_bureau_cta_url'] = array(
      '#title' => t('Cta Url'),
      '#type' => 'textfield',
      '#default_value' => variable_get('bloc_bureau_cta_url'),
    );
    //bloc Logistique
    $form['bloc_logistique'] = array(
      '#type' => 'fieldset',
      '#title' => t('bloc logistique'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
     $form['bloc_logistique']['bloc_logistique_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => variable_get('bloc_logistique_title'),
    );
    $form['bloc_logistique']['bloc_logistique_sub_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Sub title'),
      '#default_value' => variable_get('bloc_logistique_sub_title'),
    );
    $form['bloc_logistique']['bloc_logistique_description'] = array(
      '#title' => t('Description'),
      '#type' => 'text_format',
      '#default_value' => variable_get('bloc_logistique_description'),
    );
     // START Finance presentation KPI.
    $form['bloc_logistique']['bloc_logistique_kpi'] = array(
      '#type' => 'fieldset',
      '#title' => t('KPI'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    for ($i = 1; $i <= BLOC_BUREAU_KPI_ITEMS_NUM; $i++) {
      $form['bloc_logistique']['bloc_logistique_kpi']['bloc_logistique_kpi_component_' . $i] = array(
        '#type' => 'fieldset',
        '#title' => t('KPI Component ' . $i),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['bloc_logistique']['bloc_logistique_kpi']['bloc_logistique_kpi_component_' . $i]['bloc_logistique_kpi_component_title_' . $i ] = array(
        '#type' => 'textfield',
        '#title' => t('Component Title'),
        '#default_value' => variable_get('bloc_logistique_kpi_component_title_' . $i ),
      );
      $form['bloc_logistique']['bloc_logistique_kpi']['bloc_logistique_kpi_component_' . $i]['bloc_logistique_kpi_component_sub_title_' . $i ] = array(
        '#type' => 'textfield',
        '#title' => t('Component Sub-Title'),
        '#default_value' => variable_get('bloc_logistique_kpi_component_sub_title_' . $i ),
      );
      $form['bloc_logistique']['bloc_logistique_kpi']['bloc_logistique_kpi_component_' . $i]['bloc_logistique_kpi_component_image_' . $i ] = array(
        '#type' => 'managed_file',
        '#title' => t('Component Image'),
        '#default_value' => variable_get('bloc_logistique_kpi_component_image_' . $i ),
        '#upload_location' => 'public://',
      );
    }
    /**/
    $form['bloc_logistique']['habitat'] = array(
      '#title' => t('Habitat'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['bloc_logistique']['habitat']['bloc_logistique_habitat_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => variable_get('bloc_logistique_habitat_title'),
    );
    $form['bloc_logistique']['habitat']['bloc_logistique_habitat_sub_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Sub title'),
      '#default_value' => variable_get('bloc_logistique_habitat_sub_title'),
    );
    $form['bloc_logistique']['habitat']['bloc_logistique_habitat_image'] = array(
      '#type' => 'managed_file',
      '#title' => t('Image Habitat'),
      '#default_value' => variable_get('bloc_logistique_habitat_image'),
      '#upload_location' => 'public://',
    );
    $form['bloc_logistique']['habitat']['bloc_logistique_habitat_description'] = array(
      '#title' => t('Description'),
      '#type' => 'textarea',
      '#default_value' => variable_get('bloc_logistique_habitat_description'),
    );
     $form['bloc_logistique']['habitat']['bloc_logistique_cta_text'] = array(
      '#title' => t('Cta Text'),
      '#type' => 'textfield',
      '#default_value' => variable_get('bloc_logistique_cta_text'),
    );
    $form['bloc_logistique']['habitat']['bloc_logistique_cta_url'] = array(
      '#title' => t('Cta Url'),
      '#type' => 'textfield',
      '#default_value' => variable_get('bloc_logistique_cta_url'),
    );
    //bloc Hôtellerie
    $form['bloc_hotell'] = array(
      '#type' => 'fieldset',
      '#title' => t('bloc Hôtellerie'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
     $form['bloc_hotell']['bloc_hotell_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => variable_get('bloc_hotell_title'),
    );
    $form['bloc_hotell']['bloc_hotell_sub_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Sub title'),
      '#default_value' => variable_get('bloc_hotell_sub_title'),
    );
    $form['bloc_hotell']['bloc_hotell_description'] = array(
      '#title' => t('Description'),
      '#type' => 'text_format',
      '#default_value' => variable_get('bloc_hotell_description'),
    );
    $form['bloc_hotell']['bloc_hotell_kpi'] = array(
      '#type' => 'fieldset',
      '#title' => t('KPI'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    for ($i = 1; $i <= BLOC_BUREAU_KPI_ITEMS_NUM; $i++) {
      $form['bloc_hotell']['bloc_hotell_kpi']['bloc_hotell_kpi_component_' . $i] = array(
        '#type' => 'fieldset',
        '#title' => t('KPI Component ' . $i),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['bloc_hotell']['bloc_hotell_kpi']['bloc_hotell_kpi_component_' . $i]['bloc_hotell_kpi_component_title_' . $i ] = array(
        '#type' => 'textfield',
        '#title' => t('Component Title'),
        '#default_value' => variable_get('bloc_hotell_kpi_component_title_' . $i ),
      );
      $form['bloc_hotell']['bloc_hotell_kpi']['bloc_hotell_kpi_component_' . $i]['bloc_hotell_kpi_component_sub_title_' . $i ] = array(
        '#type' => 'textfield',
        '#title' => t('Component Sub-Title'),
        '#default_value' => variable_get('bloc_hotell_kpi_component_sub_title_' . $i ),
      );
      $form['bloc_hotell']['bloc_hotell_kpi']['bloc_hotell_kpi_component_' . $i]['bloc_hotell_kpi_component_image_' . $i ] = array(
        '#type' => 'managed_file',
        '#title' => t('Component Image'),
        '#default_value' => variable_get('bloc_hotell_kpi_component_image_' . $i ),
        '#upload_location' => 'public://',
      );
    }
    $form['bloc_hotell']['bloc_hotell_cta_text'] = array(
      '#title' => t('Cta Text'),
      '#type' => 'textfield',
      '#default_value' => variable_get('bloc_hotell_cta_text'),
    );
    $form['bloc_hotell']['bloc_hotell_cta_url'] = array(
      '#title' => t('Cta Url'),
      '#type' => 'textfield',
      '#default_value' => variable_get('bloc_hotell_cta_url'),
    );
    //bloc Commercer
    $form['bloc_commercer'] = array(
      '#type' => 'fieldset',
      '#title' => t('bloc Commercer'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
     $form['bloc_commercer']['bloc_commercer_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => variable_get('bloc_commercer_title'),
    );
    $form['bloc_commercer']['bloc_commercer_sub_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Sub title'),
      '#default_value' => variable_get('bloc_commercer_sub_title'),
    );
    $form['bloc_commercer']['bloc_commercer_description'] = array(
      '#title' => t('Description'),
      '#type' => 'text_format',
      '#default_value' => variable_get('bloc_commercer_description'),
    );
    $form['bloc_commercer']['bloc_commercer_kpi'] = array(
      '#type' => 'fieldset',
      '#title' => t('KPI'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    for ($i = 1; $i <= BLOC_BUREAU_KPI_ITEMS_NUM; $i++) {
      $form['bloc_commercer']['bloc_commercer_kpi']['bloc_commercer_kpi_component_' . $i] = array(
        '#type' => 'fieldset',
        '#title' => t('KPI Component ' . $i),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['bloc_commercer']['bloc_commercer_kpi']['bloc_commercer_kpi_component_' . $i]['bloc_commercer_kpi_component_title_' . $i ] = array(
        '#type' => 'textfield',
        '#title' => t('Component Title'),
        '#default_value' => variable_get('bloc_commercer_kpi_component_title_' . $i ),
      );
      $form['bloc_commercer']['bloc_commercer_kpi']['bloc_commercer_kpi_component_' . $i]['bloc_commercer_kpi_component_sub_title_' . $i ] = array(
        '#type' => 'textfield',
        '#title' => t('Component Sub-Title'),
        '#default_value' => variable_get('bloc_commercer_kpi_component_sub_title_' . $i ),
      );
      $form['bloc_commercer']['bloc_commercer_kpi']['bloc_commercer_kpi_component_' . $i]['bloc_commercer_kpi_component_image_' . $i ] = array(
        '#type' => 'managed_file',
        '#title' => t('Component Image'),
        '#default_value' => variable_get('bloc_commercer_kpi_component_image_' . $i ),
        '#upload_location' => 'public://',
      );
    }
    $form['bloc_commercer']['bloc_commercer_cta_text'] = array(
      '#title' => t('Cta Text'),
      '#type' => 'textfield',
      '#default_value' => variable_get('bloc_commercer_cta_text'),
    );
    $form['bloc_commercer']['bloc_commercer_cta_url'] = array(
      '#title' => t('Cta Url'),
      '#type' => 'textfield',
      '#default_value' => variable_get('bloc_commercer_cta_url'),
    );
    return system_settings_form($form);
}