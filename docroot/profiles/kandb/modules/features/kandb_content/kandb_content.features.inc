<?php
/**
 * @file
 * kandb_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_content_ctools_plugin_api($module = NULL, $api = NULL) {
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
function kandb_content_node_info() {
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
    'programme' => array(
      'name' => t('Programme'),
      'base' => 'node_content',
      'description' => t('"Programme" is a building that was not built already.
This data is majorly imported from the "program.txt" file, anyway it can be overridden in the backoffice by the B2B BackOffice Content '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'prospect_b2b' => array(
      'name' => t('Prospect B2B'),
      'base' => 'node_content',
      'description' => t('A Prospect B2B is an client (not Drupal) of a CGP.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
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
