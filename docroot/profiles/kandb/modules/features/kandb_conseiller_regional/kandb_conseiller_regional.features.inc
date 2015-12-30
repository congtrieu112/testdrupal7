<?php
/**
 * @file
 * kandb_conseiller_regional.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_conseiller_regional_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function kandb_conseiller_regional_image_default_styles() {
  $styles = array();

  // Exported image style: 69x69.
  $styles['69x69'] = array(
    'label' => '69x69',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 69,
          'height' => 69,
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
function kandb_conseiller_regional_node_info() {
  $items = array(
    'conseiller_regional' => array(
      'name' => t('Conseiller régional'),
      'base' => 'node_content',
      'description' => t('"conseiller_regional" are used only to display the Page Contact'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
