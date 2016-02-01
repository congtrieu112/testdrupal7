<?php

/**
 * @file Template for B2B.
 */

function kandb_b2b_theme_preprocess_page(&$variables) {
  global $theme;
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
    $vars['main_menu'] = false;
    $menu_main_links_source = variable_get('menu_main_links_source', false);
    if ($menu_main_links_source) {
      $vars['main_menu'] = menu_navigation_links($menu_main_links_source);
      $vars['uid'] = $user->uid;
    }
  }
}
