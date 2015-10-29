<?php
/**
 * @file
 * kandb_bien.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_bien_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
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
function kandb_bien_node_info() {
  $items = array(
    'bien' => array(
      'name' => t('Bien'),
      'base' => 'node_content',
      'description' => t('"Bien" is an could be an apartment, a house, etc.
A "Bien" is inside a program. A "Bien" can only be linked to 1 program, a program can be linked to multiple "Bien".
This data is majorly imported from the "program.txt" file, anyway it can be overridden in the backoffice by the B2B BackOffice Content '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
