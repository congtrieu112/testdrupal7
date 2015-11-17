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
 * Implements hook_image_default_styles().
 */
function kandb_bien_image_default_styles() {
  $styles = array();

  // Exported image style: bien_large__1380_x_670.
  $styles['bien_large__1380_x_670'] = array(
    'label' => 'Bien large (1380 x 670)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1380,
          'height' => 670,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: bien_medium__1024x506.
  $styles['bien_medium__1024x506'] = array(
    'label' => 'Bien medium (1024 x 506)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1024,
          'height' => 506,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: bien_small__640_x_316.
  $styles['bien_small__640_x_316'] = array(
    'label' => 'Bien small (640 x 316)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 316,
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
