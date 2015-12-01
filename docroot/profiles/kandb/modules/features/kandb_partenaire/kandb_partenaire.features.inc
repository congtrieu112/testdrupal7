<?php
/**
 * @file
 * kandb_partenaire.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_partenaire_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kandb_partenaire_node_info() {
  $items = array(
    'partenaire' => array(
      'name' => t('Partenaire'),
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
