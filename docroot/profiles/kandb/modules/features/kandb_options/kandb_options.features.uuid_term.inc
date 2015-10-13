<?php
/**
 * @file
 * kandb_options.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function kandb_options_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Réservé',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '0050afc0-008d-4d4d-b870-f9b8e8845218',
    'vocabulary_machine_name' => 'status_logement',
    'field_id_xls' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
          'safe_value' => 2,
        ),
      ),
    ),
    'field_id_file' => array(
      'und' => array(
        0 => array(
          'value' => 'R',
          'format' => NULL,
          'safe_value' => 'R',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Indisponible',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '279b27ff-ea86-45d2-a40c-3299c552eaff',
    'vocabulary_machine_name' => 'status_logement',
    'field_id_xls' => array(
      'und' => array(
        0 => array(
          'value' => 0,
          'format' => NULL,
          'safe_value' => 0,
        ),
      ),
    ),
    'field_id_file' => array(),
  );
  $terms[] = array(
    'name' => 'Vendu',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2a1ebc1a-7f40-4d29-bab2-b9c6397d61ee',
    'vocabulary_machine_name' => 'status_logement',
    'field_id_xls' => array(
      'und' => array(
        0 => array(
          'value' => 3,
          'format' => NULL,
          'safe_value' => 3,
        ),
      ),
    ),
    'field_id_file' => array(),
  );
  $terms[] = array(
    'name' => 'Disponible / Libre',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8f3a55c4-5d44-49fe-b4f4-63aa54abeb38',
    'vocabulary_machine_name' => 'status_logement',
    'field_id_xls' => array(
      'und' => array(
        0 => array(
          'value' => 1,
          'format' => NULL,
          'safe_value' => 1,
        ),
      ),
    ),
    'field_id_file' => array(
      'und' => array(
        0 => array(
          'value' => 'L',
          'format' => NULL,
          'safe_value' => 'L',
        ),
      ),
    ),
  );
  return $terms;
}
