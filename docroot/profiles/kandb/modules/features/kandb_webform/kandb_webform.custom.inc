<?php

/**
 * @file
 * kandb_xml_sitemap.custom.inc
 */

/**
 * Implements hook_webform_form_alter().
 */
function kandb_webform_form_alter(&$form, $form_state, $form_id) {
// Get webform candidate
  $webform_candidature = webform_features_machine_name_load('candidature');
  $webform_id_candidature = isset($webform_candidature->nid) ? 'webform_client_form_' . $webform_candidature->nid : '';
  // Get webform Être rappelé
  $webform_tre_rappel = webform_features_machine_name_load('_tre_rappel_');
  $webform_id_tre_rappel = isset($webform_tre_rappel->nid) ? 'webform_client_form_' . $webform_tre_rappel->nid : '';

  if ($form_id == $webform_id_candidature || $form_id == $webform_id_tre_rappel) {
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