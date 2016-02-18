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
