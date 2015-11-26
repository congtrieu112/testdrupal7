<?php
/**
 * @file
 * kandb_offre.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function kandb_offre_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-offre-body'
  $field_instances['node-offre-body'] = array(
    'bundle' => 'offre',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'node-offre-field_offre_subtitle'
  $field_instances['node-offre-field_offre_subtitle'] = array(
    'bundle' => 'offre',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_offre_subtitle',
    'label' => 'Sous-titre offre mise en avant',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'node-offre-field_offre_subtitle2'
  $field_instances['node-offre-field_offre_subtitle2'] = array(
    'bundle' => 'offre',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_offre_subtitle2',
    'label' => 'Sous-titre autres offres',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 45,
    ),
  );

  // Exported field_instance: 'node-offre-field_offre_title2'
  $field_instances['node-offre-field_offre_title2'] = array(
    'bundle' => 'offre',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_offre_title2',
    'label' => 'Titre autres offres',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 44,
    ),
  );

  // Exported field_instance: 'node-offre-field_offre_view1'
  $field_instances['node-offre-field_offre_view1'] = array(
    'bundle' => 'offre',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_offre_view1',
    'label' => 'Offre mise en avan',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'admin_views_node' => 0,
        'admin_views_user' => 0,
        'avant_premiere_check' => 'avant_premiere_check',
        'block_search_b2c' => 0,
        'contact_us_export' => 0,
        'dossier' => 0,
        'dossier_weight' => 0,
        'feeds_log' => 0,
        'kandb_dashboard_b2c' => 0,
        'kandb_menu_our_advice' => 0,
        'livraison_immediate' => 'livraison_immediate',
        'menu_nos_offres' => 0,
        'nos_dernieres_offres' => 0,
        'notre_offre_en_france' => 'notre_offre_en_france',
        'nouveaute' => 'nouveaute',
        'offres_weight' => 0,
        'search' => 0,
        'solr_views' => 0,
        'webform_analysis' => 0,
        'webform_results' => 0,
        'webform_submissions' => 0,
        'webform_webforms' => 0,
        'weight' => 0,
      ),
      'force_default' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 43,
    ),
  );

  // Exported field_instance: 'node-offre-field_offre_view2'
  $field_instances['node-offre-field_offre_view2'] = array(
    'bundle' => 'offre',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_offre_view2',
    'label' => 'Autres offres',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'admin_views_node' => 0,
        'admin_views_user' => 0,
        'avant_premiere_check' => 'avant_premiere_check',
        'block_search_b2c' => 0,
        'contact_us_export' => 0,
        'dossier' => 0,
        'dossier_weight' => 0,
        'feeds_log' => 0,
        'kandb_dashboard_b2c' => 0,
        'kandb_menu_our_advice' => 0,
        'livraison_immediate' => 'livraison_immediate',
        'menu_nos_offres' => 0,
        'nos_dernieres_offres' => 0,
        'notre_offre_en_france' => 'notre_offre_en_france',
        'nouveaute' => 'nouveaute',
        'offres_weight' => 0,
        'search' => 0,
        'solr_views' => 0,
        'webform_analysis' => 0,
        'webform_results' => 0,
        'webform_submissions' => 0,
        'webform_webforms' => 0,
        'weight' => 0,
      ),
      'force_default' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 46,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Autres offres');
  t('Body');
  t('Offre mise en avan');
  t('Sous-titre autres offres');
  t('Sous-titre offre mise en avant');
  t('Titre autres offres');

  return $field_instances;
}
