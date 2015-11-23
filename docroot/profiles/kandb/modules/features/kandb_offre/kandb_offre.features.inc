<?php
/**
 * @file
 * kandb_offre.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_offre_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kandb_offre_node_info() {
  $items = array(
    'offre' => array(
      'name' => t('Offre'),
      'base' => 'node_content',
      'description' => t('CT Offre'),
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
function kandb_offre_weight_features_default_settings() {
  $settings = array();

  $settings['offre'] = array(
    'enabled' => 1,
    'range' => 10,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
