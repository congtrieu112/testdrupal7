<?php
/**
 * @file
 * kandb_settings.default_elysia_cron_rules.inc
 */

/**
 * Implements hook_default_elysia_cron_rules().
 */
function kandb_settings_default_elysia_cron_rules() {
  $cron_rules = array();

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = ':default';
  $cron_rule->disable = FALSE;
  $cron_rule->rule = NULL;
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules[':default'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'acquia_agent_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = 2;
  $cron_rule->context = NULL;
  $cron_rules['acquia_agent_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'acquia_purge_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = 3;
  $cron_rule->context = NULL;
  $cron_rules['acquia_purge_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'ctools_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -45;
  $cron_rule->context = NULL;
  $cron_rules['ctools_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'domain_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -44;
  $cron_rule->context = NULL;
  $cron_rules['domain_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'feeds_cron';
  $cron_rule->disable = TRUE;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['feeds_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'field_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -43;
  $cron_rule->context = NULL;
  $cron_rules['field_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'import_habiteo_programme';
  $cron_rule->disable = TRUE;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -49;
  $cron_rule->context = NULL;
  $cron_rules['import_habiteo_programme'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'job_scheduler_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -42;
  $cron_rule->context = NULL;
  $cron_rules['job_scheduler_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'kandb_starting_daily_import';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -50;
  $cron_rule->context = NULL;
  $cron_rules['kandb_starting_daily_import'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'kandb_start_migration_import';
  $cron_rule->disable = TRUE;
  $cron_rule->rule = NULL;
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['kandb_start_migration_import'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'kb_feeds_delete_errorlogs_earlier_than_a_month';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = 1;
  $cron_rule->context = NULL;
  $cron_rules['kb_feeds_delete_errorlogs_earlier_than_a_month'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'node_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -48;
  $cron_rule->context = NULL;
  $cron_rules['node_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'redirect_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -41;
  $cron_rule->context = NULL;
  $cron_rules['redirect_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'rules_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -40;
  $cron_rule->context = NULL;
  $cron_rules['rules_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'search_api_acquia_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -5;
  $cron_rule->context = NULL;
  $cron_rules['search_api_acquia_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'search_api_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -9;
  $cron_rule->context = NULL;
  $cron_rules['search_api_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'search_api_solr_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -8;
  $cron_rule->context = NULL;
  $cron_rules['search_api_solr_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'smart_ip_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -19;
  $cron_rule->context = NULL;
  $cron_rules['smart_ip_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'system_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = 0;
  $cron_rule->context = NULL;
  $cron_rules['system_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'update_cron';
  $cron_rule->disable = TRUE;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['update_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'views_bulk_operations_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -20;
  $cron_rule->context = NULL;
  $cron_rules['views_bulk_operations_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'views_data_export_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -10;
  $cron_rule->context = NULL;
  $cron_rules['views_data_export_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'xmlsitemap_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -7;
  $cron_rule->context = NULL;
  $cron_rules['xmlsitemap_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'xmlsitemap_menu_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -6;
  $cron_rule->context = NULL;
  $cron_rules['xmlsitemap_menu_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'xmlsitemap_node_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '5 0 * * *';
  $cron_rule->weight = -5;
  $cron_rule->context = NULL;
  $cron_rules['xmlsitemap_node_cron'] = $cron_rule;

  return $cron_rules;

}
