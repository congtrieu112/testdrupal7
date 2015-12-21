<?php
/**
 * @file
 * kandb_article.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function kandb_article_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|selection';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'selection';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_article_content',
        1 => 'domain',
        2 => 'field_article_resume',
        3 => 'field_article_article_ref',
        4 => 'field_article_teaser_image',
        5 => 'field_article_image',
      ),
    ),
    'fields' => array(
      'field_article_content' => 'ds_content',
      'domain' => 'ds_content',
      'field_article_resume' => 'ds_content',
      'field_article_article_ref' => 'ds_content',
      'field_article_teaser_image' => 'ds_content',
      'field_article_image' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|article|selection'] = $ds_layout;

  return $export;
}
