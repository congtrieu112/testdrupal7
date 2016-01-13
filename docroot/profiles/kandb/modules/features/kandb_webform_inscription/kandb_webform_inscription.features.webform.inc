<?php
/**
 * @file
 * kandb_webform_inscription.features.webform.inc
 */

/**
 * Implements hook_webform_defaults().
 */
function kandb_webform_inscription_webform_defaults() {
$webforms = array();
  $webforms['inscription'] = array(
  'title' => 'inscription',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'vuuid' => '3d1abf60-824c-427a-9062-83eb09b44733',
  'type' => 'webform',
  'language' => 'en',
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '64c71631-71de-4f97-9058-b5fefcaf2611',
  'webform' => array(
    'next_serial' => 5,
    'confirmation' => 'Merci, votre soumission a été reçue',
    'confirmation_format' => 'plain_text',
    'redirect_url' => '<none>',
    'status' => 1,
    'block' => 0,
    'allow_draft' => 0,
    'auto_save' => 0,
    'submit_notice' => 1,
    'confidential' => 0,
    'submit_text' => '',
    'submit_limit' => -1,
    'submit_interval' => -1,
    'total_submit_limit' => -1,
    'total_submit_interval' => -1,
    'progressbar_bar' => 1,
    'progressbar_page_number' => 0,
    'progressbar_percent' => 0,
    'progressbar_pagebreak_labels' => 1,
    'progressbar_include_confirmation' => 1,
    'progressbar_label_first' => 'Start',
    'progressbar_label_confirmation' => 'Complete',
    'preview' => 0,
    'preview_next_button_label' => '',
    'preview_prev_button_label' => '',
    'preview_title' => '',
    'preview_message' => '',
    'preview_message_format' => 'plain_text',
    'preview_excluded_components' => array(),
    'machine_name' => 'inscription',
    'webform_ajax' => 1,
    'record_exists' => TRUE,
    'roles' => array(
      0 => 1,
      1 => 2,
    ),
    'emails' => array(),
    'components' => array(
      'inscription__inscription_email' => array(
        'form_key' => 'inscription_email',
        'name' => 'inscription email',
        'type' => 'email',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'multiple' => 0,
          'format' => 'short',
          'width' => '',
          'unique' => 0,
          'disabled' => 0,
          'description' => '',
          'placeholder' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 0,
        'weight' => 0,
        'machine_name' => 'inscription__inscription_email',
        'page_num' => 1,
      ),
      'inscription__inscription_point_dinteret' => array(
        'form_key' => 'inscription_point_dinteret',
        'name' => 'inscription point d\'intérêt',
        'type' => 'hidden',
        'value' => '',
        'extra' => array(
          'hidden_type' => 'hidden',
          'private' => 0,
          'analysis' => FALSE,
        ),
        'required' => 0,
        'weight' => 1,
        'machine_name' => 'inscription__inscription_point_dinteret',
        'page_num' => 1,
      ),
    ),
    'conditionals' => array(),
  ),
  'domains' => array(
    3 => 3,
  ),
  'domain_site' => TRUE,
  'subdomains' => array(
    0 => 'All affiliates',
    1 => 'Kaufman & Broad',
  ),
  'locations' => array(),
  'location' => array(),
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'webform_features_author' => 'admin',
  'webform_features_revision_author' => 'admin',
);
return $webforms;
}
