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

  $items['user_register_form'] = array(
    'render element' => 'form',
    'template' => 'templates/forms/user_register_form',
    'preprocess functions' => array(
      'kandb_theme_preprocess_user_register_form'
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

function kandb_theme_preprocess_user_register_form(&$vars) {
  $vars['form']['account']['name']['#theme_wrappers'] = NULL;
  $vars['form']['account']['name']['#description'] = '';

  $vars['form']['account']['mail']['#theme_wrappers'] = NULL;
  $vars['form']['account']['mail']['#description'] = '';

  $vars['form']['group_profile']['field_user_nom'][LANGUAGE_NONE][0]['value']['#theme_wrappers'] = NULL;
  $vars['form']['group_profile']['field_user_nom'][LANGUAGE_NONE]['#description'] = '';

  $vars['form']['group_profile']['field_prenom'][LANGUAGE_NONE][0]['value']['#theme_wrappers'] = NULL;
  $vars['form']['group_profile']['field_prenom'][LANGUAGE_NONE]['#description'] = '';

  $vars['form']['group_profile']['field_user_societe'][LANGUAGE_NONE][0]['value']['#theme_wrappers'] = NULL;
  $vars['form']['group_profile']['field_user_societe'][LANGUAGE_NONE]['#description'] = '';

  $vars['form']['group_profile']['field_user_adresse'][LANGUAGE_NONE][0]['value']['#theme_wrappers'] = NULL;
  $vars['form']['group_profile']['field_user_adresse'][LANGUAGE_NONE]['#description'] = '';

  $vars['form']['group_profile']['field_user_code_postal'][LANGUAGE_NONE][0]['value']['#theme_wrappers'] = NULL;
  $vars['form']['group_profile']['field_user_code_postal'][LANGUAGE_NONE]['#description'] = '';

  $vars['form']['group_profile']['field_user_telephone'][LANGUAGE_NONE][0]['value']['#theme_wrappers'] = NULL;
  $vars['form']['group_profile']['field_user_telephone'][LANGUAGE_NONE]['#description'] = '';

  $vars['form']['group_profile']['field_user_message'][LANGUAGE_NONE][0]['value']['#theme_wrappers'] = NULL;
  $vars['form']['group_profile']['field_user_message'][LANGUAGE_NONE]['#description'] = '';

  $vars['form']['group_profile']['field_user_pays'][LANGUAGE_NONE][0]['value']['#theme_wrappers'] = NULL;
  $vars['form']['group_profile']['field_user_pays'][LANGUAGE_NONE]['#description'] = '';

  $vars['form']['group_profile']['field_user_ville'][LANGUAGE_NONE][0]['value']['#theme_wrappers'] = NULL;
  $vars['form']['group_profile']['field_user_ville'][LANGUAGE_NONE]['#description'] = '';

  $vars['form']['group_profile']['field_user_email'][LANGUAGE_NONE][0]['value']['#theme_wrappers'] = NULL;
  $vars['form']['group_profile']['field_user_email'][LANGUAGE_NONE]['#description'] = '';

  $vars['form']['account']['name']['#required'] = FALSE;
  // Submit button.
  $vars['form']['actions']['#theme_wrappers'] = NULL;
  $vars['form']['actions']['submit']['#value'] = t('Envoyer');
  $vars['form']['actions']['submit']['#attributes']['class'] = array('btn-primary', 'btn-rounded');
}
