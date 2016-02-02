<?php
/**
 * @file
 * kandb_menu_b2b.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function kandb_menu_b2b_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-b2b-footer-menu.
  $menus['menu-b2b-footer-menu'] = array(
    'menu_name' => 'menu-b2b-footer-menu',
    'title' => 'B2B footer menu',
    'description' => '',
  );
  // Exported menu: menu-b2b-main-menu.
  $menus['menu-b2b-main-menu'] = array(
    'menu_name' => 'menu-b2b-main-menu',
    'title' => 'B2B main menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('B2B footer menu');
  t('B2B main menu');


  return $menus;
}
