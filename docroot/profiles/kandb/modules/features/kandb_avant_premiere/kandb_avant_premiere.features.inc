<?php
/**
 * @file
 * kandb_avant_premiere.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_avant_premiere_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kandb_avant_premiere_node_info() {
  $items = array(
    'avant_premiere' => array(
      'name' => t('Avant-première'),
      'base' => 'node_content',
      'description' => t('CT Avant-première '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
