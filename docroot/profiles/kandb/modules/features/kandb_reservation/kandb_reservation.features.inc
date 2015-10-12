<?php
/**
 * @file
 * kandb_reservation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_reservation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kandb_reservation_node_info() {
  $items = array(
    'reservation' => array(
      'name' => t('Réservation'),
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
