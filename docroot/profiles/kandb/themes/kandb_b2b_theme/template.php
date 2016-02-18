<?php

/**
 * @file Template for B2B.
 */
function kandb_b2b_theme_preprocess_page(&$variables) {
  global $theme, $user;
  if ($user->uid && $theme == 'kandb_b2b_theme' && drupal_is_front_page()) {
    drupal_goto('dash-board');
  }
}

/**
 * Implements of hook_theme().
 */
function kandb_theme_theme() {
  $items = array();

  $items['user_login'] = array(
    'render element' => 'form',
    'template' => 'templates/forms/user-login',
    'preprocess functions' => array(
      'kandb_theme_preprocess_user_login'
    ),
  );

  return $items;
}

/**
 * Implements of preprocess user login form.
 */
function kandb_theme_preprocess_user_login(&$vars) {
  // Username textfield .
  $vars['form']['name']['#theme_wrappers'] = NULL;
  $vars['form']['name']['#description'] = '';
  $vars['form']['name']['#attributes']['required'] = 'required';
  $vars['form']['name']['#attributes']['placeholder'] = t('Votre identifiant');

  // Password textfield.
  $vars['form']['pass']['#theme_wrappers'] = NULL;
  $vars['form']['pass']['#description'] = '';
  $vars['form']['pass']['#attributes']['required'] = 'required';
  $vars['form']['pass']['#attributes']['placeholder'] = t('Votre mot de passe');

  // Remember me checkbox.
  $vars['form']['remember_me']['#theme_wrappers'] = NULL;

  // Submit button.
  $vars['form']['actions']['#theme_wrappers'] = NULL;
  $vars['form']['actions']['submit']['#value'] = t('Me connecter');
  $vars['form']['actions']['submit']['#attributes']['class'] = array('btn-primary', 'btn-rounded');
}

/**
 * Implemnts hook_preprocess_region().
 */
function kandb_b2b_theme_preprocess_region(&$vars) {
  global $user;
  // Header
  if ($vars['region'] == 'header' && $user->uid) {
    // Main menu
    $vars['main_menu'] = menu_navigation_links('menu-b2b-main-menu');
    $vars['user'] = $user;
  }

  // Footer
  if ($vars['region'] == 'footer') {
    $vars['logo_svg'] = kandb_theme_get_path('assets', 'kandb_theme') . '/images/logo-Kaufman-Broad.svg';
    $vars['menu_footer'] = menu_navigation_links('menu-b2b-footer-menu');
  }
}

/**
 * Implements hook_preprocess_html()
 * @param type $vars
 */
function kandb_b2b_theme_preprocess_html(&$vars) {
  $vars['classes_array'][] = 'homepage b2b';
}

/**
 * Get list bien caracteris is checked
 * @param stdClss() $bien_more
 * @return array()
 */
function get_list_bien_b2b_caracteris($bien_more) {
  $arr_caracteris = array();
  $arr_caracteris[] = isset($bien_more->field_caracteristique_balcon[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_balcon[LANGUAGE_NONE][0]['value'] > 0 ? 'Balcon' : '';
  $arr_caracteris[] = isset($bien_more->field_caracteristique_box[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_box[LANGUAGE_NONE][0]['value'] >= 0 ? 'Box' : '';
  $arr_caracteris[] = isset($bien_more->field_caracteristique_cave[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_cave[LANGUAGE_NONE][0]['value'] >= 0 ? 'Cave' : '';
  $arr_caracteris[] = isset($bien_more->field_caracteristique_jardin[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_jardin[LANGUAGE_NONE][0]['value'] > 0 ? 'Jardin' : '';
  $arr_caracteris[] = isset($bien_more->field_caracteristique_parking[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_parking[LANGUAGE_NONE][0]['value'] >= 0? 'Parking' : '';
  $arr_caracteris[] = isset($bien_more->field_caracteristique_terrasse[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_terrasse[LANGUAGE_NONE][0]['value'] > 0 ? 'Terrasse' : '';

  // Remove all value is emtpy in array
  $arr_caracteris = array_filter($arr_caracteris);
  $caracteristiques = isset($bien_more->field_caracteristique[LANGUAGE_NONE]) ? $bien_more->field_caracteristique[LANGUAGE_NONE] : '';
  if ($caracteristiques && count($caracteristiques) > 0) {
    foreach ($caracteristiques as $caracteristique) {
      $term_caracteristique = taxonomy_term_load($caracteristique['tid']);
      if ($term_caracteristique) {
        if(isset($term_caracteristique->name) && !in_array($term_caracteristique->name, $arr_caracteris)) {
          $arr_caracteris[] = $term_caracteristique->name;
        }
      }
    }
  }

  return $arr_caracteris;
}