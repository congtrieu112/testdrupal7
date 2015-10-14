<?php
/**
 * @file
 * kandb_maison.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_maison_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kandb_maison_node_info() {
  $items = array(
    'maison' => array(
      'name' => t('Maison'),
      'base' => 'node_content',
      'description' => t('A "Maison" is a house model.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
