<?php
/**
 * @file
 * kandb_webform_contact_settings.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function kandb_webform_contact_settings_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_webform-contact-settings:admin/config/webform_contact
  $menu_links['management_webform-contact-settings:admin/config/webform_contact'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/webform_contact',
    'router_path' => 'admin/config/webform_contact',
    'link_title' => 'Webform Contact settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Set ID webform for contact form.',
      ),
      'identifier' => 'management_webform-contact-settings:admin/config/webform_contact',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Webform Contact settings');

  return $menu_links;
}
