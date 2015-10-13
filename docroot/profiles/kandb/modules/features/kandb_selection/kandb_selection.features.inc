<?php
/**
 * @file
 * kandb_selection.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_selection_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kandb_selection_node_info() {
  $items = array(
    'selection' => array(
      'name' => t('Selection'),
      'base' => 'node_content',
      'description' => t('A "Selection" is a user list to keep all "Bien" that he likes.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
