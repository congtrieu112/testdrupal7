<?php
/**
 * @file
 * kandb_habitat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_habitat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kandb_habitat_node_info() {
  $items = array(
    'habitat' => array(
      'name' => t('Habitat'),
      'base' => 'node_content',
      'description' => t('Page Activités - Habitat'),
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
function kandb_habitat_weight_features_default_settings() {
  $settings = array();

  $settings['habitat'] = array(
    'enabled' => 1,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
