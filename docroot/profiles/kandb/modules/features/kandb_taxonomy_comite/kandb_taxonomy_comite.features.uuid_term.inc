<?php
/**
 * @file
 * kandb_taxonomy_comite.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function kandb_taxonomy_comite_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Comité de Direction Elargi',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '939a6a4d-c53a-4157-abfa-6cc7ce67b27f',
    'vocabulary_machine_name' => 'comite',
    'field_comite_display_description' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
    'field_comite_title_en' => array(
      'und' => array(
        0 => array(
          'value' => 'Complete Executive Committee',
          'format' => NULL,
          'safe_value' => 'Complete Executive Committee',
        ),
      ),
    ),
    'field_comite_title_fr' => array(
      'und' => array(
        0 => array(
          'value' => 'Comité de Direction Elargi',
          'format' => NULL,
          'safe_value' => 'Comité de Direction Elargi',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Conseil d\'Administration',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '93d7db19-9521-44c4-84a4-7eeec9fbc1b7',
    'vocabulary_machine_name' => 'comite',
    'field_comite_display_description' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_comite_title_en' => array(
      'und' => array(
        0 => array(
          'value' => 'Governance',
          'format' => NULL,
          'safe_value' => 'Governance',
        ),
      ),
    ),
    'field_comite_title_fr' => array(
      'und' => array(
        0 => array(
          'value' => 'Conseil d\'Administration',
          'format' => NULL,
          'safe_value' => 'Conseil d&#039;Administration',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Comité de Direction',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '967ddf18-97ec-4b59-8227-fa3d05ab3d8a',
    'vocabulary_machine_name' => 'comite',
    'field_comite_display_description' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
    'field_comite_title_en' => array(
      'und' => array(
        0 => array(
          'value' => 'Executive Committee',
          'format' => NULL,
          'safe_value' => 'Executive Committee',
        ),
      ),
    ),
    'field_comite_title_fr' => array(
      'und' => array(
        0 => array(
          'value' => 'Comité de Direction',
          'format' => NULL,
          'safe_value' => 'Comité de Direction',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Comex',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'b8a74054-c5dd-424b-941f-1eb36f9818cc',
    'vocabulary_machine_name' => 'comite',
    'field_comite_display_description' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
    'field_comite_title_en' => array(
      'und' => array(
        0 => array(
          'value' => 'Comex',
          'format' => NULL,
          'safe_value' => 'Comex',
        ),
      ),
    ),
    'field_comite_title_fr' => array(
      'und' => array(
        0 => array(
          'value' => 'Comex',
          'format' => NULL,
          'safe_value' => 'Comex',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Comité de Nomination et de Rémunération',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'c1eddb82-d943-49eb-b887-87295257e252',
    'vocabulary_machine_name' => 'comite',
    'field_comite_display_description' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
    'field_comite_title_en' => array(
      'und' => array(
        0 => array(
          'value' => 'Careers Committee',
          'format' => NULL,
          'safe_value' => 'Careers Committee',
        ),
      ),
    ),
    'field_comite_title_fr' => array(
      'und' => array(
        0 => array(
          'value' => 'Comité de Nomination et de Rémunération',
          'format' => NULL,
          'safe_value' => 'Comité de Nomination et de Rémunération',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Composition',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => 'd902ec70-9c91-47d2-a75f-6b4a70a5cb6a',
    'vocabulary_machine_name' => 'comite',
    'field_comite_display_description' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
    'field_comite_title_en' => array(
      'und' => array(
        0 => array(
          'value' => 'Composition',
          'format' => NULL,
          'safe_value' => 'Composition',
        ),
      ),
    ),
    'field_comite_title_fr' => array(
      'und' => array(
        0 => array(
          'value' => 'Composition',
          'format' => NULL,
          'safe_value' => 'Composition',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Comité d\'Audit',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'e3630d67-213a-4955-a7b4-0e57592be799',
    'vocabulary_machine_name' => 'comite',
    'field_comite_display_description' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
    'field_comite_title_en' => array(
      'und' => array(
        0 => array(
          'value' => 'Audit Committee',
          'format' => NULL,
          'safe_value' => 'Audit Committee',
        ),
      ),
    ),
    'field_comite_title_fr' => array(
      'und' => array(
        0 => array(
          'value' => 'Comité d\'Audit',
          'format' => NULL,
          'safe_value' => 'Comité d&#039;Audit',
        ),
      ),
    ),
  );
  return $terms;
}
