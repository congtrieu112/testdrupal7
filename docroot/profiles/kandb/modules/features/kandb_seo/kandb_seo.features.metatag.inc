<?php
/**
 * @file
 * kandb_seo.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function kandb_seo_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[current-page:title] | [site:name]',
      ),
      'generator' => array(
        'value' => 'Drupal 7 (http://drupal.org)',
      ),
      'canonical' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
      ),
    ),
  );

  // Exported Metatag config instance: global:403.
  $config['global:403'] = array(
    'instance' => 'global:403',
    'disabled' => FALSE,
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:404.
  $config['global:404'] = array(
    'instance' => 'global:404',
    'disabled' => FALSE,
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:frontpage.
  $config['global:frontpage'] = array(
    'instance' => 'global:frontpage',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[site:name]',
      ),
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:summary]',
      ),
    ),
  );

  // Exported Metatag config instance: node:bien.
  $config['node:bien'] = array(
    'instance' => 'node:bien',
    'config' => array(
      'title' => array(
        'value' => '[node:field_type] [node:field_nb_pieces] [node:field-programme:field_programme_loc_ville] [node:field-programme:field_programme_loc_cp] - [node:field_numero_lot] | [site:name]',
      ),
      'description' => array(
        'value' => 'Vous recherchez : [node:field_type] [node:field_nb_pieces] dans le [node:field-programme:field_programme_loc_cp] [node:field-programme:field_programme_loc_ville] ? Kaufman et Broad a le bien qu\'il vous faut, achetez notre [node:field_type] [node:field_nb_pieces] [node:field_numero_lot] !',
      ),
    ),
  );

  // Exported Metatag config instance: node:programme.
  $config['node:programme'] = array(
    'instance' => 'node:programme',
    'config' => array(
      'title' => array(
        'value' => 'Programme [node:title] [node:field_programme_loc_ville] [node:field_programme_loc_cp] | [site:name]',
      ),
      'description' => array(
        'value' => 'Le programme immobilier [node:title] de Kaufman et Broad est localisé dans le [node:field_programme_loc_cp] [node:field_programme_loc_ville] et est proche des commerces. Découvrez ses biens !',
      ),
    ),
  );

  return $config;
}
