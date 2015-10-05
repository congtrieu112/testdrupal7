<?php
/**
 * @file
 * kandb_domains.domains.inc
 */

/**
 * Implements hook_domain_default_domains().
 */
function kandb_domains_domain_default_domains() {
  $domains = array();
  $domains['kandb_git_local'] = array(
    'subdomain' => 'kandb.local',
    'sitename' => 'Kaufman & Broad',
    'scheme' => 'http',
    'valid' => 1,
    'weight' => -2,
    'is_default' => 1,
    'machine_name' => 'kandb_git_local',
  );

  return $domains;
}

/**
 * Implements hook_domain_conf_default_variables().
 */
function kandb_domains_domain_conf_default_variables() {
  $domain_variables = array();
  $domain_variables['kandb_git_local'] = array(
    'site_name' => 'KandB',
    'site_mail' => 'gregory.montigny@digitaslbi.fr',
    'site_slogan' => '',
    'site_frontpage' => 'homepage',
    'anonymous' => 'Anonymous',
    'admin_theme' => 'ember',
    'date_default_timezone' => 'Europe/Paris',
    'cache' => 0,
    'cache_lifetime' => 0,
    'maintenance_mode' => 0,
    'maintenance_mode_message' => 'KandB is currently under maintenance. We should be back shortly. Thank you for your patience.',
    'menu_main_links_source' => 'main-menu',
    'menu_secondary_links_source' => 0,
    'menu_options_article' => array(
      'main-menu' => 'main-menu',
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_article' => 'main-menu:0',
    'menu_options_webform' => array(
      'main-menu' => 'main-menu',
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_webform' => 'main-menu:0',
    'menu_options_page' => array(
      'main-menu' => 'main-menu',
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_page' => 'main-menu:0',
    'menu_options_homepage' => array(
      'main-menu' => 'main-menu',
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_homepage' => 'main-menu:0',
    'menu_options_programme' => array(
      'main-menu' => 'main-menu',
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_programme' => 'main-menu:0',
  );

  return $domain_variables;
}
