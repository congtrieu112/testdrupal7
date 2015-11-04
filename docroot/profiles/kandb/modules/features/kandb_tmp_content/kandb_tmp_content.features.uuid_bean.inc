<?php
/**
 * @file
 * kandb_tmp_content.features.uuid_bean.inc
 */

/**
 * Implements hook_uuid_features_default_beans().
 */
function kandb_tmp_content_uuid_features_default_beans() {
  $beans = array();

  $beans[] = array(
    'label' => 'Nos conseils',
    'description' => NULL,
    'title' => 'Nos conseils',
    'type' => 'block_header',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'nos-conseils',
    'view_mode' => 'default',
    'created' => 1445249259,
    'log' => '',
    'uid' => 1,
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => 'dd06f108-d9a9-4449-91ee-1188ec20f50b',
    'uuid' => '446d4873-23bd-45ea-ad3a-32c41cd63d0c',
    'field_block_header_image' => array(),
    'field_block_header_stitre' => array(
      'und' => array(
        0 => array(
          'value' => 'Accompagner à chaque étape de votre projet immobilier',
          'format' => NULL,
          'safe_value' => 'Accompagner à chaque étape de votre projet immobilier',
        ),
      ),
    ),
    'url_alias' => array(),
  );
  return $beans;
}
