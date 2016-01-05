<?php
/**
 * @file
 * k_b_rh_annonce.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function k_b_rh_annonce_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function k_b_rh_annonce_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function k_b_rh_annonce_node_info() {
  $items = array(
    'rh_annonce' => array(
      'name' => t('RH Annonce'),
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
