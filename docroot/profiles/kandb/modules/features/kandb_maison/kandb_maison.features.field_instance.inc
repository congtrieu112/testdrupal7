<?php
/**
 * @file
 * kandb_maison.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function kandb_maison_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-maison-field_maison_description'
  $field_instances['node-maison-field_maison_description'] = array(
    'bundle' => 'maison',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'plain_text',
          ),
        ),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_maison_description',
    'label' => 'Descriptif',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 'ds_code',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'raw_html' => 'raw_html',
          'userbase' => 'userbase',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ds_code' => array(
              'weight' => 12,
            ),
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'raw_html' => array(
              'weight' => -6,
            ),
            'userbase' => array(
              'weight' => -7,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-maison-field_maison_image'
  $field_instances['node-maison-field_maison_image'] = array(
    'bundle' => 'maison',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_maison_image',
    'label' => 'Image modèle',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'imgs',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-maison-field_maison_nb_chambres'
  $field_instances['node-maison-field_maison_nb_chambres'] = array(
    'bundle' => 'maison',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'quickedit' => array(
            'editor' => 'form',
          ),
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
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
    'field_name' => 'field_maison_nb_chambres',
    'label' => 'Nombre de chambres',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-maison-field_maison_nb_etage'
  $field_instances['node-maison-field_maison_nb_etage'] = array(
    'bundle' => 'maison',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'quickedit' => array(
            'editor' => 'form',
          ),
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
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
    'field_name' => 'field_maison_nb_etage',
    'label' => 'Nombre d\'étages',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-maison-field_maison_nb_pieces'
  $field_instances['node-maison-field_maison_nb_pieces'] = array(
    'bundle' => 'maison',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'quickedit' => array(
            'editor' => 'form',
          ),
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
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
    'field_name' => 'field_maison_nb_pieces',
    'label' => 'Nombre de pièces',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-maison-field_maison_nb_salle_bain'
  $field_instances['node-maison-field_maison_nb_salle_bain'] = array(
    'bundle' => 'maison',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'quickedit' => array(
            'editor' => 'form',
          ),
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
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
    'field_name' => 'field_maison_nb_salle_bain',
    'label' => 'Nombre de salle de bain',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-maison-field_maison_point_fort'
  $field_instances['node-maison-field_maison_point_fort'] = array(
    'bundle' => 'maison',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'plain_text',
          ),
        ),
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
    'field_name' => 'field_maison_point_fort',
    'label' => 'Avantages',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 'ds_code',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'raw_html' => 'raw_html',
          'userbase' => 'userbase',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ds_code' => array(
              'weight' => 12,
            ),
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'raw_html' => array(
              'weight' => -6,
            ),
            'userbase' => array(
              'weight' => -7,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-maison-field_maison_pos_ammenagement'
  $field_instances['node-maison-field_maison_pos_ammenagement'] = array(
    'bundle' => 'maison',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'plain_text',
          ),
        ),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_maison_pos_ammenagement',
    'label' => 'Possibilité d’aménagement',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 'ds_code',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'raw_html' => 'raw_html',
          'userbase' => 'userbase',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ds_code' => array(
              'weight' => 12,
            ),
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'raw_html' => array(
              'weight' => -6,
            ),
            'userbase' => array(
              'weight' => -7,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
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
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-maison-field_maison_surface_cuisine'
  $field_instances['node-maison-field_maison_surface_cuisine'] = array(
    'bundle' => 'maison',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'quickedit' => array(
            'editor' => 'form',
          ),
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_maison_surface_cuisine',
    'label' => 'Surface cuisine',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-maison-field_maison_surface_sejour'
  $field_instances['node-maison-field_maison_surface_sejour'] = array(
    'bundle' => 'maison',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'quickedit' => array(
            'editor' => 'form',
          ),
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_maison_surface_sejour',
    'label' => 'Surface séjour',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-maison-field_maison_surface_totale'
  $field_instances['node-maison-field_maison_surface_totale'] = array(
    'bundle' => 'maison',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'quickedit' => array(
            'editor' => 'form',
          ),
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_maison_surface_totale',
    'label' => 'Surface totale',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-maison-field_maison_url_visite'
  $field_instances['node-maison-field_maison_url_visite'] = array(
    'bundle' => 'maison',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'link_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_maison_url_visite',
    'label' => 'Url visite',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'rel_remove' => 'default',
      'title' => 'required',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Avantages');
  t('Descriptif');
  t('Image modèle');
  t('Nombre d\'étages');
  t('Nombre de chambres');
  t('Nombre de pièces');
  t('Nombre de salle de bain');
  t('Possibilité d’aménagement');
  t('Surface cuisine');
  t('Surface séjour');
  t('Surface totale');
  t('Url visite');

  return $field_instances;
}
