<?php

/**
 * @file
 * Implements Backo-end functions related K&B B2B.
 */

/**
 * List All sub-menu of the B2B content settings.
 */
function kandb_b2b_setttings_page_content() {
  $parent = menu_link_get_preferred(current_path());
  $parameters = array(
    'active_trail' => array($parent['plid']),
    'only_active_trail' => FALSE,
    'min_depth' => $parent['depth'] + 1,
    'max_depth' => $parent['depth'] + 1,
    'conditions' => array('plid' => $parent['mlid']),
  );

  $children = menu_build_tree($parent['menu_name'], $parameters);
  foreach ($children as &$data) {
    if ($data['link']['link_path'] != 'admin/content/ketb/list')
      $data['link']['hidden'] = FALSE;
  }
  $menu_render = menu_tree_output($children);

  return '<div class="content-sub-menu content-padder">' . drupal_render($menu_render) . '</div>';
}

/**
 * B2B Homepage settings form.
 */
function kandb_b2b_homepage_settings($form, $form_state) {
  $form = array();
  global $language;

  $form['links_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('CTA Links'),
    '#tree' => TRUE,
  );

  $form['kandb_b2b_homepage_background_image'] = array(
    '#type' => 'managed_file',
    '#title' => 'Background image default',
    '#default_value' => variable_get('kandb_b2b_homepage_background_image'),
    '#upload_location' => 'public://',
  );

  $form['kandb_b2b_homepage_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Title'),
    '#default_value' => variable_get('kandb_b2b_homepage_title', ''),
  );

  $form['kandb_b2b_homepage_subtitle'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Sub Title'),
    '#default_value' => variable_get('kandb_b2b_homepage_subtitle', ''),
  );

  $cta = array();
  $cta = variable_get('kandb_b2b_homepage_cta');
  if (isset($cta['url']) && $cta['url'] && isset($cta['title']) && $cta['title']) {
    $url = $cta['url'];
    $title = $cta['title'];
  }
  $form['links_fieldset']['kandb_b2b_homepage_cta'] = array(
    '#type' => 'link_field',
    '#title' => t('CTA  Voir les conditions'),
    '#field_parents' => NULL,
    '#description' => 'URL should be relative link. EX: /node/{nid}',
    '#language' => $language->language,
    '#field_name' => 'kandb_b2b_homepage_cta',
    '#delta' => 0,
    '#default_value' => array(
      'title' => $title,
      'url' => $url,
    ),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['kandb_b2b_homepage_program'] = array(
    '#type' => 'textfield',
    '#title' => t('Programme reference'),
    '#autocomplete_path' => 'admin/content/kandb-b2b/homepage-programme/autocomplete',
    '#default_value' => variable_get('kandb_b2b_homepage_program', ''),
  );


  $form['#submit'] = array(
    'kandb_b2b_homepage_submit'
  );
  return system_settings_form($form);
}

/*
 * Additional submit handler for making the file permanent.
 */

function kandb_b2b_homepage_submit($form, &$form_state) {
  $val = $form_state['values'];
  $links = $val['links_fieldset']['kandb_b2b_homepage_cta'];
  variable_set('kandb_b2b_homepage_cta', array('url' => $links['url'], 'title' => $links['title']));
}

/**
 * Ajax callback for select a program to show in B2B homepage.
 */
function _kandb_b2b_homepage_programme_autocomplete($string) {
  $matches = array();

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'programme')
    ->propertyCondition('title', '%' . $string . '%', 'like')
    ->propertyCondition('status', NODE_PUBLISHED);
  $result = $query->execute();

  if (isset($result['node'])) {
    $nodes = entity_load('node', array_keys($result['node']));
  }

  if ($nodes) {
    foreach ($nodes as $item) {
      $matches['[' . $item->nid . ']' . $item->title] = $item->title;
    }
  }

  drupal_json_output($matches);
}

/**
 * Implement form setting for register page.
 */
function kandb_b2b_register_page_settings($form, $form_state) {

  $form['kandb_b2b_register_page_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Header Title'),
    '#description' => ('The title on header'),
    '#default_value' => variable_get('kandb_b2b_register_page_title', t('Devenez un prescripteur privilégié')),
  );

  $form['kandb_b2b_register_page_subtitle'] = array(
    '#type' => 'textfield',
    '#title' => t('Header Sub Title'),
    '#description' => ('The sub title on header'),
    '#default_value' => variable_get('kandb_b2b_register_page_subtitle', t('Kaufman et Broad')),
  );
  $form['kandb_b2b_register_page_background_header'] = array(
    '#type' => 'managed_file',
    '#title' => 'Background header',
    '#default_value' => variable_get('kandb_b2b_register_page_background_header'),
    '#upload_location' => 'public://',
  );

  $form['kandb_b2b_register_form_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Form Title'),
    '#description' => ('The title on Form'),
    '#default_value' => variable_get('kandb_b2b_register_form_title', t('Remplissez vos informations')),
  );
  $form['kandb_b2b_register_form_subtitle'] = array(
    '#type' => 'textfield',
    '#title' => t('Form Sub Title'),
    '#description' => ('The sub title on Form'),
    '#default_value' => variable_get('kandb_b2b_register_form_subtitle', t('Pour demander l\'ouverture d\'un compte')),
  );
  return system_settings_form($form);
}
