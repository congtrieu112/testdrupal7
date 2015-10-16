<?php
/**
 * @file
 * kandb_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kandb_article_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kandb_article_node_info() {
  $items = array(
    'article' => array(
      'name' => t('CT Article'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
