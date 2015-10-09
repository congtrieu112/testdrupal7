<?php
/**
 * @file
 * kandb_programme.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_programme_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kandb_programme_node_info() {
  $items = array(
    'programme' => array(
      'name' => t('Programme'),
      'base' => 'node_content',
      'description' => t('"Programme" is a building that was not built already.
This data is majorly imported from the "program.txt" file, anyway it can be overridden in the backoffice by the B2B BackOffice Content '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
