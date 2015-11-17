<?php
/**
 * @file
 * kandb_offre.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_offre_ctools_plugin_api($module = NULL, $api = NULL) {
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
