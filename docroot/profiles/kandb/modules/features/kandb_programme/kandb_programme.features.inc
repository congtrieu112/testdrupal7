<?php
/**
 * @file
 * kandb_programme.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_programme_ctools_plugin_api($module = NULL, $api = NULL) {
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
 * Implements hook_image_default_styles().
 */
function kandb_programme_image_default_styles() {
  $styles = array();

  // Exported image style: program_characteristic_medium.
  $styles['program_characteristic_medium'] = array(
    'label' => 'Program characteristic medium',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1380,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: program_characteristic_small.
  $styles['program_characteristic_small'] = array(
    'label' => 'Program characteristic small',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 230,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
