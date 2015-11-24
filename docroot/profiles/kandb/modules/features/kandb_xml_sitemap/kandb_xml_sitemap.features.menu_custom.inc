<?php
/**
 * @file
 * kandb_xml_sitemap.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function kandb_xml_sitemap_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-b2c-public-menu.
  $menus['menu-b2c-public-menu'] = array(
    'menu_name' => 'menu-b2c-public-menu',
    'title' => 'B2C public menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('B2C public menu');


  return $menus;
}
