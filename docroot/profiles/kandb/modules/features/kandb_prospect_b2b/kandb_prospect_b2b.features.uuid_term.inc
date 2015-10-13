<?php
/**
 * @file
 * kandb_prospect_b2b.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function kandb_prospect_b2b_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Plein pied',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '039bd663-6017-487f-8a60-71ac0247ebf6',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => 'Hopitaux',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1c65ab25-d08e-4479-b32b-8337d0629025',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => '4 pièces',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '1cdf49ff-a950-4872-b62d-80d5c727f721',
    'vocabulary_machine_name' => 'nb_pieces',
    'field_id_nombre_pieces' => array(
      'und' => array(
        0 => array(
          'value' => 4,
          'format' => NULL,
          'safe_value' => 4,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Métro',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '26cd475e-28a5-40a2-bccc-da0415bfb37b',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => 'Terrain',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '308d752f-c501-4e8a-82f3-117c5c7ce82d',
    'vocabulary_machine_name' => 'type_de_bien',
    'field_id_type_bien' => array(
      'und' => array(
        0 => array(
          'value' => 'TE',
          'format' => NULL,
          'safe_value' => 'TE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '3 pièces',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '3a4f2eea-49e2-4685-98f9-fcba42923122',
    'vocabulary_machine_name' => 'nb_pieces',
    'field_id_nombre_pieces' => array(
      'und' => array(
        0 => array(
          'value' => 3,
          'format' => NULL,
          'safe_value' => 3,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Garage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5148ccda-8c3b-4636-b9b3-fdfa0f97368b',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => 'Dernier étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5bcb4a56-fc94-46f2-ae83-085390b44107',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => 'Ascenseur',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5d51c992-aaae-44ac-a276-0339c23ab874',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => 'Bureau',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '69f51529-9f8b-4277-a814-bb61194ec3ec',
    'vocabulary_machine_name' => 'type_de_bien',
    'field_id_type_bien' => array(
      'und' => array(
        0 => array(
          'value' => 'BU',
          'format' => NULL,
          'safe_value' => 'BU',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'TVA 7%',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7a064e09-fa16-4bc1-981a-d5e4f0e92c2e',
    'vocabulary_machine_name' => 'tva',
    'field_facteur' => array(
      'und' => array(
        0 => array(
          'value' => 0.007,
          'format' => NULL,
          'safe_value' => 0.007,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Train',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7ef30dbc-1f5f-4f9d-b6ac-113fc66e0ac9',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => 'Local-activité',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '83606e01-5605-4229-a58b-e2ce9606be24',
    'vocabulary_machine_name' => 'type_de_bien',
    'field_id_type_bien' => array(
      'und' => array(
        0 => array(
          'value' => 'AC',
          'format' => NULL,
          'safe_value' => 'AC',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'RER',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '94142950-8942-4790-a010-57d95ba8fb1f',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => 'Maison',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9f66a0c0-6c3b-4d71-aaeb-ca16876e8b1d',
    'vocabulary_machine_name' => 'type_de_bien',
    'field_id_type_bien' => array(
      'und' => array(
        0 => array(
          'value' => 'MA',
          'format' => NULL,
          'safe_value' => 'MA',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Parking',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a1e14c18-39e8-425a-9ed2-96071bed666c',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => 'Commerce',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a51933e5-17a8-42bf-98de-93ebe1907f9c',
    'vocabulary_machine_name' => 'type_de_bien',
    'field_id_type_bien' => array(
      'und' => array(
        0 => array(
          'value' => 'CO',
          'format' => NULL,
          'safe_value' => 'CO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ecoles',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'af354588-f627-435e-844d-98e82e6701dd',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => 'Appartement',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b1037e21-c7b2-48f3-90bd-1be1ff496095',
    'vocabulary_machine_name' => 'type_de_bien',
    'field_id_type_bien' => array(
      'und' => array(
        0 => array(
          'value' => 'AP',
          'format' => NULL,
          'safe_value' => 'AP',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Jardin',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b62972cd-cf80-45bb-9f1c-eadb9147c7b1',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => 'studio',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b9107d2a-b815-45bb-877a-c63c057b4918',
    'vocabulary_machine_name' => 'nb_pieces',
    'field_id_nombre_pieces' => array(
      'und' => array(
        0 => array(
          'value' => 1,
          'format' => NULL,
          'safe_value' => 1,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Duplex',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'bc20f6fa-6ccf-4042-a450-69182e7a10c3',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => 'Terrasse',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ce124ec1-4ade-4f49-9438-f47e8ab85e86',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => 'Commerces',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ce6f6fa8-9ab1-4bfb-b6d2-b627bf110818',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => '5 pièces et +',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => 'd4e30183-42fa-43eb-b969-8aaf68a35ef2',
    'vocabulary_machine_name' => 'nb_pieces',
    'field_id_nombre_pieces' => array(
      'und' => array(
        0 => array(
          'value' => 5,
          'format' => NULL,
          'safe_value' => 5,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '2 pièces',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'ed044a86-613b-4d55-9c77-46894a35f858',
    'vocabulary_machine_name' => 'nb_pieces',
    'field_id_nombre_pieces' => array(
      'und' => array(
        0 => array(
          'value' => 2,
          'format' => NULL,
          'safe_value' => 2,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'TVA 5.5%',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f2bfd133-479c-4e2d-9be2-0990fb7d0f4e',
    'vocabulary_machine_name' => 'tva',
    'field_facteur' => array(
      'und' => array(
        0 => array(
          'value' => 0.055,
          'format' => NULL,
          'safe_value' => 0.055,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Accès mobilité réduite',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fb85256f-7a45-4fc3-a657-fbfdf34452d4',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  $terms[] = array(
    'name' => 'Balcon',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fc53ec7e-9b0c-4720-8f10-e4436a6bf4a9',
    'vocabulary_machine_name' => 'caracteristiques',
  );
  return $terms;
}
