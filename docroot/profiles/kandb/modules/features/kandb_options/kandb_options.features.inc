<?php
/**
 * @file
 * kandb_options.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_options_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kandb_options_node_info() {
  $items = array(
    'options' => array(
      'name' => t('Options'),
      'base' => 'node_content',
      'description' => t('An option can be set by the CGP, on an available appartment.
Once the option set in the system, the appartment is not available anymore, and does not show on the B2C site
The option automatically becomes obsolete after 3 days
Then the appartment is available back'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
