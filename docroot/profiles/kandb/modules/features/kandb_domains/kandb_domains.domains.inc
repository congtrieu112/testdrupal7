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
  $domains['kandb_b2b'] = array(
    'subdomain' => 'www.kbpatrimoine.com',
    'sitename' => 'Kaufman & Broad Patrimoine',
    'scheme' => 'http',
    'valid' => 1,
    'weight' => -1,
    'is_default' => 0,
    'machine_name' => 'kandb_b2b',
  );
  $domains['kandb_b2c'] = array(
    'subdomain' => 'www.ketb.com',
    'sitename' => 'Kaufman & Broad',
    'scheme' => 'http',
    'valid' => 1,
    'weight' => 0,
    'is_default' => 1,
    'machine_name' => 'kandb_b2c',
  );

  return $domains;
}

/**
 * Implements hook_domain_alias_default_aliases().
 */
function kandb_domains_domain_alias_default_aliases() {
  $domain_aliases = array();
  $domain_aliases['kandb_b2b'] = array(
    'kbpatrimoine.local' => array(
      'pattern' => 'kbpatrimoine.local',
      'redirect' => 0,
      'machine_name' => 'kandb_b2b',
    ),
    'dev.kbpatrimoine.com' => array(
      'pattern' => 'dev.kbpatrimoine.com',
      'redirect' => 0,
      'machine_name' => 'kandb_b2b',
    ),
    'stage.kbpatrimoine.com' => array(
      'pattern' => 'stage.kbpatrimoine.com',
      'redirect' => 0,
      'machine_name' => 'kandb_b2b',
    ),
    'prod.kbpatrimoine.com' => array(
      'pattern' => 'prod.kbpatrimoine.com',
      'redirect' => 0,
      'machine_name' => 'kandb_b2b',
    ),
  );
  $domain_aliases['kandb_b2c'] = array(
    'kandb.local' => array(
      'pattern' => 'kandb.local',
      'redirect' => 0,
      'machine_name' => 'kandb_b2c',
    ),
    'dev.ketb.com' => array(
      'pattern' => 'dev.ketb.com',
      'redirect' => 0,
      'machine_name' => 'kandb_b2c',
    ),
    'stage.ketb.com' => array(
      'pattern' => 'stage.ketb.com',
      'redirect' => 0,
      'machine_name' => 'kandb_b2c',
    ),
    'prod.ketb.com' => array(
      'pattern' => 'prod.ketb.com',
      'redirect' => 0,
      'machine_name' => 'kandb_b2c',
    ),
    'kaufmanetbroaddev.prod.acquia-sites.com' => array(
      'pattern' => 'kaufmanetbroaddev.prod.acquia-sites.com',
      'redirect' => 0,
      'machine_name' => 'kandb_b2c',
    ),
    'kaufmanetbroadstg.prod.acquia-sites.com' => array(
      'pattern' => 'kaufmanetbroadstg.prod.acquia-sites.com',
      'redirect' => 0,
      'machine_name' => 'kandb_b2c',
    ),
    'kaufmanetbroad.prod.acquia-sites.com' => array(
      'pattern' => 'kaufmanetbroad.prod.acquia-sites.com',
      'redirect' => 0,
      'machine_name' => 'kandb_b2c',
    ),
  );

  return $domain_aliases;
}

/**
 * Implements hook_domain_conf_default_variables().
 */
function kandb_domains_domain_conf_default_variables() {
  $domain_variables = array();
  $domain_variables['kandb_b2b'] = array(
    'site_name' => 'KandB',
    'site_mail' => 'gregory.montigny@digitaslbi.fr',
    'site_slogan' => '',
    'site_frontpage' => 'homepage',
    'anonymous' => 'Anonymous',
    'admin_theme' => 'adminimal',
    'date_default_timezone' => 'Europe/Paris',
    'cache' => 0,
    'cache_lifetime' => 0,
    'maintenance_mode' => 0,
    'maintenance_mode_message' => 'Kaufman &amp; Broad Patrimoine is currently under maintenance. We should be back shortly. Thank you for your patience.',
    'menu_main_links_source' => 'main-menu',
    'menu_secondary_links_source' => 0,
    'menu_options_article' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_article' => 'main-menu:0',
    'menu_options_webform' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
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
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_homepage' => 'main-menu:0',
    'menu_options_programme' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_programme' => 'main-menu:0',
    'language_default' => 'domain-conf-ignore',
    'menu_options_bien' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_bien' => 'main-menu:0',
    'menu_options_dossier' => array(
      'devel' => 0,
      'menu-footer' => 0,
      'main-menu' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_dossier' => 'main-menu:0',
    'menu_options_maison' => array(
      'devel' => 0,
      'menu-footer' => 0,
      'main-menu' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_maison' => 'main-menu:0',
    'menu_options_options' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_options' => 'main-menu:0',
    'menu_options_prospect_b2b' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_prospect_b2b' => 'main-menu:0',
    'menu_options_reservation' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_reservation' => 'main-menu:0',
    'menu_options_selection' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_selection' => 'main-menu:0',
  );
  $domain_variables['kandb_b2c'] = array(
    'site_name' => 'Site-Install',
    'site_mail' => 'gregory.montigny@digitaslbi.fr',
    'site_slogan' => '',
    'site_frontpage' => 'homepage',
    'anonymous' => 'Anonymous',
    'admin_theme' => 'adminimal',
    'date_default_timezone' => 'Europe/Paris',
    'cache' => 0,
    'cache_lifetime' => 0,
    'maintenance_mode' => 0,
    'maintenance_mode_message' => 'Kaufman &amp; Broad is currently under maintenance. We should be back shortly. Thank you for your patience.',
    'language_default' => 'domain-conf-ignore',
    'menu_main_links_source' => 'main-menu',
    'menu_secondary_links_source' => 0,
    'menu_options_article' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_article' => 'main-menu:0',
    'menu_options_bien' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_bien' => 'main-menu:0',
    'menu_options_dossier' => array(
      'devel' => 0,
      'menu-footer' => 0,
      'main-menu' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_dossier' => 'main-menu:0',
    'menu_options_homepage' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_homepage' => 'main-menu:0',
    'menu_options_maison' => array(
      'devel' => 0,
      'menu-footer' => 0,
      'main-menu' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_maison' => 'main-menu:0',
    'menu_options_options' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_options' => 'main-menu:0',
    'menu_options_programme' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_programme' => 'main-menu:0',
    'menu_options_prospect_b2b' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_prospect_b2b' => 'main-menu:0',
    'menu_options_reservation' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_reservation' => 'main-menu:0',
    'menu_options_selection' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_selection' => 'main-menu:0',
    'menu_options_webform' => array(
      'main-menu' => 'main-menu',
      'devel' => 0,
      'menu-footer' => 0,
      'management' => 0,
      'navigation' => 0,
      'user-menu' => 0,
    ),
    'menu_parent_webform' => 'main-menu:0',
  );

  return $domain_variables;
}
