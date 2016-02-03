<?php

/**
 * @file
 * kandb_xml_sitemap.custom.inc
 */

/**
 * Implements hook_webform_form_alter().
 */
function kandb_webform_form_alter(&$form, $form_state, $form_id) {
  if (preg_match('/webform/i', $form_id)) {
    // Include JS inline to autoresetdom.
    drupal_add_js(
        'Drupal.ajax.prototype.commands.autoresetdom = function(ajax, response, status) {
          App.launchUpdaters();
      }', 'inline'
    );
  }
}

/**
 * Implement hook_ajax_render_alter().
 */
function kandb_webform_ajax_render_alter(&$commands) {
  $commands[] = array('command' => 'autoresetdom');
}