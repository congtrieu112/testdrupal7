<?php
/**
 * @file
 * kandb_region_kb.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_region_kb_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kandb_region_kb_node_info() {
  $items = array(
    'region_kb' => array(
      'name' => t('Contact KB'),
      'base' => 'node_content',
      'description' => t('Region KB are used only to display the Page Contact'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
