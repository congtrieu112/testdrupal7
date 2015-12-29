<?php
/**
 * @file
 * kandb_finance_gouvernance.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_finance_gouvernance_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kandb_finance_gouvernance_node_info() {
  $items = array(
    'finance_gouvernance' => array(
      'name' => t('Finance Gouvernance'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function kandb_finance_gouvernance_weight_features_default_settings() {
  $settings = array();

  $settings['finance_gouvernance'] = array(
    'enabled' => 1,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
