<?php
/**
 * @file
 * kandb_prospect_b2b.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_prospect_b2b_ctools_plugin_api($module = NULL, $api = NULL) {
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
function kandb_prospect_b2b_node_info() {
  $items = array(
    'prospect_b2b' => array(
      'name' => t('Prospect B2B'),
      'base' => 'node_content',
      'description' => t('A Prospect B2B is an client (not Drupal) of a CGP.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
