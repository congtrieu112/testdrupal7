<?php
/**
 * @file
 * kandb_domains.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kandb_domains_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_bootstrap_modules';
  $strongarm->value = array(
    0 => 'domain_alias',
    1 => 'domain_conf',
  );
  $export['domain_bootstrap_modules'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_classes';
  $strongarm->value = 'domain-[current-domain:machine_name]';
  $export['domain_classes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_cron_rule';
  $strongarm->value = 1;
  $export['domain_cron_rule'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_debug';
  $strongarm->value = '0';
  $export['domain_debug'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_default_source';
  $strongarm->value = '-1';
  $export['domain_default_source'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_edit_on_primary';
  $strongarm->value = 0;
  $export['domain_edit_on_primary'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_force_admin';
  $strongarm->value = '0';
  $export['domain_force_admin'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_grant_all';
  $strongarm->value = 'user/*/track';
  $export['domain_grant_all'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_list_size';
  $strongarm->value = '25';
  $export['domain_list_size'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_article';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_avant_premiere';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_avant_premiere'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_bien';
  $strongarm->value = array();
  $export['domain_node_bien'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_document';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_dossier';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_dossier'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_homepage';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_maison';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_maison'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_offre';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_offre'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_options';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_programme';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_programme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_promotion';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_promotion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_prospect_b2b';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_prospect_b2b'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_reservation';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_reservation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_selection';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_standard_page';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_standard_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_webform';
  $strongarm->value = array(
    'DOMAIN_ALL' => 'DOMAIN_ALL',
    'DOMAIN_ACTIVE' => 0,
    'kandb_local' => 0,
    'kandb_b2b' => 0,
    'kandb_b2c' => 0,
  );
  $export['domain_node_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_paths';
  $strongarm->value = 'node/%n
node/%n/edit
comment/reply/%n
node/add/book/parent/%n
book/export/html/%n
node/%n/outline';
  $export['domain_paths'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_search';
  $strongarm->value = '0';
  $export['domain_search'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_select_format';
  $strongarm->value = '0';
  $export['domain_select_format'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_seo';
  $strongarm->value = '0';
  $export['domain_seo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_settings_behavior';
  $strongarm->value = '2';
  $export['domain_settings_behavior'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_settings_forms';
  $strongarm->value = '';
  $export['domain_settings_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_settings_form_visibility';
  $strongarm->value = '1';
  $export['domain_settings_form_visibility'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_sitename_override';
  $strongarm->value = 1;
  $export['domain_sitename_override'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_vertical_tab';
  $strongarm->value = '1';
  $export['domain_vertical_tab'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_www';
  $strongarm->value = '0';
  $export['domain_www'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_xmlrpc_rule';
  $strongarm->value = 0;
  $export['domain_xmlrpc_rule'] = $strongarm;

  return $export;
}
