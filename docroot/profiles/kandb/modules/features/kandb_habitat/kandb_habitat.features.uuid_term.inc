<?php
/**
 * @file
 * kandb_habitat.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function kandb_habitat_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Residences gerees',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '025127ef-8a80-448f-af95-13ac3eef1f68',
    'vocabulary_machine_name' => 'type_de_habitat',
  );
  $terms[] = array(
    'name' => 'Allier',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '053b2efd-2747-4def-ad8f-0bd1b981b9f0',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => '03',
          'format' => NULL,
          'safe_value' => '03',
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '5bdda1cb-4966-4de4-887e-afc57210699b',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Rhône-Alpes',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '068ab95f-a04c-467f-8d73-e102269c8fb0',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Meurthe et Moselle',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '0ffdcdf6-de77-4247-a415-5b4636c9ea73',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 54,
          'format' => NULL,
          'safe_value' => 54,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '4497554f-08f7-49c7-8444-654ccf21706e',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Cher',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1191d355-6dcd-4087-bfe0-1b450b8e4dd7',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 18,
          'format' => NULL,
          'safe_value' => 18,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '469810b2-f030-48c0-b738-ea05610c4c25',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Nièvre',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '168efaa0-d16f-4fd2-bb6e-08a39d2b4ac4',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 58,
          'format' => NULL,
          'safe_value' => 58,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '6c06d578-8854-41e1-bd22-fce6565ea461',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ille et Vilaine',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '19518d5c-2ed3-45bc-80c5-71f7f39bda45',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 35,
          'format' => NULL,
          'safe_value' => 35,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'd195a755-0e85-4200-8ee4-fb1d9d94b6da',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Maine et Loire',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1bcbcd74-1e63-49b3-a570-245203887217',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 49,
          'format' => NULL,
          'safe_value' => 49,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'd30614f8-f0bf-4f9f-ae1a-b86b2fc60064',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Côte d’Or',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1f536c66-4660-4796-bd84-834d7334b8d7',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 21,
          'format' => NULL,
          'safe_value' => 21,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '6c06d578-8854-41e1-bd22-fce6565ea461',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Limousin',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '22a4748b-70b1-4902-be29-3d26b85c55c1',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Oise',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '23a0d0ce-6bef-4862-9003-d7fff44fdae0',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 60,
          'format' => NULL,
          'safe_value' => 60,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '5bdda1cb-4966-4de4-887e-afc57210699b',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Saône et Loire',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '241ffbe0-2340-4b5d-9965-350d6870d4fc',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 71,
          'format' => NULL,
          'safe_value' => 71,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '6c06d578-8854-41e1-bd22-fce6565ea461',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Languedoc-Roussillon',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '255451a5-c0cb-4db7-a0d3-2254fac6abe4',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Meuse',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '25a2ec0d-fffd-4fa2-9bbe-8d6ae3d0deb7',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 55,
          'format' => NULL,
          'safe_value' => 55,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '4497554f-08f7-49c7-8444-654ccf21706e',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Indre et Loire',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '26770375-6b9e-47e3-a2d6-3accefee5155',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 37,
          'format' => NULL,
          'safe_value' => 37,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '469810b2-f030-48c0-b738-ea05610c4c25',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Hautes Pyrénées',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '283a2ca6-cbfb-4dbb-900a-e29d94bfa879',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 65,
          'format' => NULL,
          'safe_value' => 65,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '8f7a4318-f820-4d97-81b3-75960f9a8ca3',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Nord',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '293206e6-be6a-490a-ac8d-a6e60d9f65ec',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 59,
          'format' => NULL,
          'safe_value' => 59,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'efef5001-c9bf-4bce-9a08-4dece3b35b92',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Val d’Oise',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2ac0a62c-23f6-43e7-ae30-a64d153ef7c8',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 95,
          'format' => NULL,
          'safe_value' => 95,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '83c72ca9-5e9e-4a04-9d24-325a0de8700f',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Haute Saône',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2b2eab0c-fab2-4270-b700-8da075b1e1aa',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 70,
          'format' => NULL,
          'safe_value' => 70,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '41d8bb9b-54f3-469a-b1b9-4468c81c9052',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ardennes',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2feb3635-c49a-4302-bf05-eefb6179e534',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => '08',
          'format' => NULL,
          'safe_value' => '08',
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '3380aa03-777c-4c87-b45e-b86c01198a7d',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Bas Rhin',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '30ae1249-021a-425f-b9f6-2c8140b77d4e',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 67,
          'format' => NULL,
          'safe_value' => 67,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '4d6388c5-ecb4-4bb9-891f-34ed939b5ac8',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Hautes Alpes',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3181a5ba-87bf-41c2-8a02-d54c9553147f',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => '05',
          'format' => NULL,
          'safe_value' => '05',
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '5cf404d1-9a47-4af3-9178-72cee26f690d',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Haute-Corse',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '31d089a4-2f6d-48a1-b416-a595ac4d2b0f',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => '2B',
          'format' => NULL,
          'safe_value' => '2B',
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'd9847079-bf25-41d1-b303-1692142edb5c',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Indre',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3238ac0d-e339-4842-a3e2-a340cf166756',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 36,
          'format' => NULL,
          'safe_value' => 36,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '469810b2-f030-48c0-b738-ea05610c4c25',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Champagne-Ardenne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3380aa03-777c-4c87-b45e-b86c01198a7d',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Eure et Loire',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '348b40c2-22af-47f1-a527-064943f2d629',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 28,
          'format' => NULL,
          'safe_value' => 28,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '469810b2-f030-48c0-b738-ea05610c4c25',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Haute Loire',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3576f04c-dba7-4236-8bac-47cd078b7ea4',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 43,
          'format' => NULL,
          'safe_value' => 43,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'e0850f4c-8001-4a5c-a4b1-434e0fe8a7b9',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Vendée',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3c37ec05-3e2f-4e5f-8b0b-e247733830a6',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 85,
          'format' => NULL,
          'safe_value' => 85,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'd30614f8-f0bf-4f9f-ae1a-b86b2fc60064',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ariège',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3fdaf07d-a83f-4b8c-9e22-b084c1c6d92d',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => '09',
          'format' => NULL,
          'safe_value' => '09',
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '8f7a4318-f820-4d97-81b3-75960f9a8ca3',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Seine Maritime',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '400cc223-0b5d-4a37-893b-b9d13eaca82c',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 76,
          'format' => NULL,
          'safe_value' => 76,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '8dde61bb-dd29-47b5-9f86-ece9e51b8af0',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Franche-Comté',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '41d8bb9b-54f3-469a-b1b9-4468c81c9052',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Lorraine',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4497554f-08f7-49c7-8444-654ccf21706e',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Loire Atlantique',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '45e356fc-4cac-42e4-8980-d6b19e4ff987',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 44,
          'format' => NULL,
          'safe_value' => 44,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'd30614f8-f0bf-4f9f-ae1a-b86b2fc60064',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Centre-Val de Loire',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '469810b2-f030-48c0-b738-ea05610c4c25',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Paris',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '47acc6f3-02b0-4bd5-ab2f-4c9b02f8031a',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 75,
          'format' => NULL,
          'safe_value' => 75,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '83c72ca9-5e9e-4a04-9d24-325a0de8700f',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Hautes Pyrénées',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '480e95d7-5acd-4fa8-945a-9f05505d5cc1',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 66,
          'format' => NULL,
          'safe_value' => 66,
        ),
      ),
    ),
    'field_region' => array(),
  );
  $terms[] = array(
    'name' => 'Lot',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4c4fb422-adf9-4243-a34f-681eb7f29a40',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 46,
          'format' => NULL,
          'safe_value' => 46,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '8f7a4318-f820-4d97-81b3-75960f9a8ca3',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Alsace',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4d6388c5-ecb4-4bb9-891f-34ed939b5ac8',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Loiret',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4ee19619-5670-45cf-8a78-774e3b45a281',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 45,
          'format' => NULL,
          'safe_value' => 45,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '469810b2-f030-48c0-b738-ea05610c4c25',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Lot et Garonne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4ef05e8c-1c41-404d-8989-d37d051b0778',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 47,
          'format' => NULL,
          'safe_value' => 47,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'a9cfd8d8-2bfb-4651-94db-e487ca43960c',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'uawurigehu',
    'description' => 'description of uawurigehu',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '4fd39890-5e85-4b58-af37-540f2ee8b0d7',
    'vocabulary_machine_name' => 'ville',
    'field_code_departement' => array(
      'und' => array(
        0 => array(
          'value' => 'Conventio ea immitto in iustum molior pecus premo sino velit.',
          'format' => 'plain_text',
          'safe_value' => 'Conventio ea immitto in iustum molior pecus premo sino velit.',
        ),
      ),
    ),
    'field_idk' => array(
      'und' => array(
        0 => array(
          'value' => 'Haero incassum olim secundum similis valetudo validus. Esse illum importunus ut. Caecus dolus ex iusto macto nulla persto praesent vereor. Dolore et oppeto. Eu exerci fere gemino nunc paratus praemitto quidem sagaciter ut. Commoveo defui ex persto.',
          'format' => 'plain_text',
          'safe_value' => 'Haero incassum olim secundum similis valetudo validus. Esse illum importunus ut. Caecus dolus ex iusto macto nulla persto praesent vereor. Dolore et oppeto. Eu exerci fere gemino nunc paratus praemitto quidem sagaciter ut. Commoveo defui ex persto.',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Val de Marne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4fec5dda-d0b6-445e-9f12-4a1ac5fb5351',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 94,
          'format' => NULL,
          'safe_value' => 94,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '83c72ca9-5e9e-4a04-9d24-325a0de8700f',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Corrèze',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '518d422d-7f6f-49aa-a4c1-3583830dd979',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 19,
          'format' => NULL,
          'safe_value' => 19,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '22a4748b-70b1-4902-be29-3d26b85c55c1',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Yonne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '51fd7b43-fb19-4779-8c14-38b72894ef30',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 89,
          'format' => NULL,
          'safe_value' => 89,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '6c06d578-8854-41e1-bd22-fce6565ea461',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Gard',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '530d3660-070f-48ea-8a50-cf0956b8e426',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 30,
          'format' => NULL,
          'safe_value' => 30,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '255451a5-c0cb-4db7-a0d3-2254fac6abe4',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Calvados',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '532adf46-4fb1-475f-9c84-831fbb8f986b',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 14,
          'format' => NULL,
          'safe_value' => 14,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'cee77f25-0f4f-4df1-b910-97bd23cc6cb2',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Somme',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5613d6a4-a52a-44b4-b26c-ee4ec41b6485',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 80,
          'format' => NULL,
          'safe_value' => 80,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '5bdda1cb-4966-4de4-887e-afc57210699b',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'spo',
    'description' => 'description of spo',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '56a3f447-48dd-4ff7-a8db-f17b6747cea0',
    'vocabulary_machine_name' => 'ville',
    'field_code_departement' => array(
      'und' => array(
        0 => array(
          'value' => 'Comis conventio euismod ex luctus nostrud probo quidem utinam. Consequat neque usitas velit vero. Abbas ad dolore eu luctus nutus virtus. Causa elit ex odio oppeto quia tamen vicis. Appellatio importunus incassum os praesent quibus roto vel. Hendrerit pro',
          'format' => 'plain_text',
          'safe_value' => 'Comis conventio euismod ex luctus nostrud probo quidem utinam. Consequat neque usitas velit vero. Abbas ad dolore eu luctus nutus virtus. Causa elit ex odio oppeto quia tamen vicis. Appellatio importunus incassum os praesent quibus roto vel. Hendrerit pro',
        ),
      ),
    ),
    'field_idk' => array(
      'und' => array(
        0 => array(
          'value' => 'Aptent vulpes wisi. Dolore haero iusto jugis quidem sudo typicus. Exerci facilisi lobortis os refero validus vero vulpes.',
          'format' => 'plain_text',
          'safe_value' => 'Aptent vulpes wisi. Dolore haero iusto jugis quidem sudo typicus. Exerci facilisi lobortis os refero validus vero vulpes.',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Seine Saint Denis',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '583db210-9bf6-40a9-8779-3fc0da3ae275',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 93,
          'format' => NULL,
          'safe_value' => 93,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '83c72ca9-5e9e-4a04-9d24-325a0de8700f',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Hérault',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '59116692-98a6-49d2-b8d6-af5aadae15d6',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 34,
          'format' => NULL,
          'safe_value' => 34,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '255451a5-c0cb-4db7-a0d3-2254fac6abe4',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Pyrénées Orientales',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5a176ae6-7a94-4ee6-8978-f07613a1f624',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 66,
          'format' => NULL,
          'safe_value' => 66,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '255451a5-c0cb-4db7-a0d3-2254fac6abe4',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Haute Garonne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5b1f3e5b-6360-4f55-a65e-502d633707b7',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 31,
          'format' => NULL,
          'safe_value' => 31,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '8f7a4318-f820-4d97-81b3-75960f9a8ca3',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Picardie',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5bdda1cb-4966-4de4-887e-afc57210699b',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Vaucluse',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5cbde678-e78a-450a-866b-e1c43e44d381',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 84,
          'format' => NULL,
          'safe_value' => 84,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '5cf404d1-9a47-4af3-9178-72cee26f690d',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Provence-Alpes-Côte d\'Azur',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5cf404d1-9a47-4af3-9178-72cee26f690d',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'tr',
    'description' => 'description of tr',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '639a3ed3-ceaf-4a01-86f9-b15cfa739c67',
    'vocabulary_machine_name' => 'ville',
    'field_code_departement' => array(
      'und' => array(
        0 => array(
          'value' => 'Consectetuer eros esse immitto imputo lucidus neque populus. Natu neque paulatim quia refoveo tincidunt. Abluo brevitas metuo nostrud. Iaceo inhibeo nimis similis ullamcorper vulputate. Abbas iusto jumentum nisl sed.',
          'format' => 'plain_text',
          'safe_value' => 'Consectetuer eros esse immitto imputo lucidus neque populus. Natu neque paulatim quia refoveo tincidunt. Abluo brevitas metuo nostrud. Iaceo inhibeo nimis similis ullamcorper vulputate. Abbas iusto jumentum nisl sed.',
        ),
      ),
    ),
    'field_idk' => array(
      'und' => array(
        0 => array(
          'value' => 'Appellatio haero luptatum pneum suscipit tation wisi. Macto mos persto quibus sit turpis. Accumsan commodo molior nobis populus probo rusticus vicis vindico. Elit facilisi quia. At consectetuer duis hendrerit ideo illum iriure paratus venio.',
          'format' => 'plain_text',
          'safe_value' => 'Appellatio haero luptatum pneum suscipit tation wisi. Macto mos persto quibus sit turpis. Accumsan commodo molior nobis populus probo rusticus vicis vindico. Elit facilisi quia. At consectetuer duis hendrerit ideo illum iriure paratus venio.',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'phasle',
    'description' => 'description of phasle',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '64810679-8055-4b9f-882f-615afab41d87',
    'vocabulary_machine_name' => 'ville',
    'field_code_departement' => array(
      'und' => array(
        0 => array(
          'value' => 'Augue comis commoveo huic ille molior torqueo. Imputo metuo neque pecus plaga qui. Aliquam ille lobortis magna persto quidne ulciscor veniam.',
          'format' => 'plain_text',
          'safe_value' => 'Augue comis commoveo huic ille molior torqueo. Imputo metuo neque pecus plaga qui. Aliquam ille lobortis magna persto quidne ulciscor veniam.',
        ),
      ),
    ),
    'field_idk' => array(
      'und' => array(
        0 => array(
          'value' => 'Commoveo gemino laoreet natu nostrud vicis. Quadrum refoveo venio. Causa damnum euismod interdico os pagus pecus praemitto utrum. Ex loquor oppeto vereor vulputate ymo. Aptent decet illum melior neque occuro pneum qui uxor valetudo.',
          'format' => 'plain_text',
          'safe_value' => 'Commoveo gemino laoreet natu nostrud vicis. Quadrum refoveo venio. Causa damnum euismod interdico os pagus pecus praemitto utrum. Ex loquor oppeto vereor vulputate ymo. Aptent decet illum melior neque occuro pneum qui uxor valetudo.',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Yvelines',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '65284820-f7bc-400c-80c3-0499513b7415',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 78,
          'format' => NULL,
          'safe_value' => 78,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '83c72ca9-5e9e-4a04-9d24-325a0de8700f',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Bourgogne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6c06d578-8854-41e1-bd22-fce6565ea461',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Appartements',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6cab8b1a-bbb7-4334-8009-1d41e785fa97',
    'vocabulary_machine_name' => 'type_de_habitat',
  );
  $terms[] = array(
    'name' => 'Haute Savoie',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6f8256d0-dd43-4705-b4bb-afcc804e0a66',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 74,
          'format' => NULL,
          'safe_value' => 74,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '068ab95f-a04c-467f-8d73-e102269c8fb0',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Alpes Maritimes',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6fb0012f-445b-4a0b-bb13-67b6202818a4',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => '06',
          'format' => NULL,
          'safe_value' => '06',
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '5cf404d1-9a47-4af3-9178-72cee26f690d',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Loire',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '72f05584-eac4-48a7-b39e-8fdf2d9ff2e7',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 42,
          'format' => NULL,
          'safe_value' => 42,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '068ab95f-a04c-467f-8d73-e102269c8fb0',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Charente Maritime',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '760cff33-3980-4233-9a46-c0c5c092c6ed',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 17,
          'format' => NULL,
          'safe_value' => 17,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'c2433b6e-de2b-4d97-9820-25c734a23539',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Marne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '77d01d0b-59af-4358-a5c0-651aa8fd6c6f',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 51,
          'format' => NULL,
          'safe_value' => 51,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '3380aa03-777c-4c87-b45e-b86c01198a7d',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Loir et Cher',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '79529570-ac1d-4eb2-a669-d975285be0f0',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 41,
          'format' => NULL,
          'safe_value' => 41,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '469810b2-f030-48c0-b738-ea05610c4c25',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Hauts de Seine',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7f1b411b-f992-4faf-beb9-86c2b20e883b',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 92,
          'format' => NULL,
          'safe_value' => 92,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '83c72ca9-5e9e-4a04-9d24-325a0de8700f',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Bouches du Rhône',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7fbbb588-11ed-41cd-9f59-6d157614d3d6',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 13,
          'format' => NULL,
          'safe_value' => 13,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '5cf404d1-9a47-4af3-9178-72cee26f690d',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Creuse',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7ff8253f-5cb3-4070-a5af-cb5745c0b6a4',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 23,
          'format' => NULL,
          'safe_value' => 23,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '22a4748b-70b1-4902-be29-3d26b85c55c1',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Territoire de Belfort',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '820b78ad-4611-4adb-90d8-d6d12b29ada7',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 90,
          'format' => NULL,
          'safe_value' => 90,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '41d8bb9b-54f3-469a-b1b9-4468c81c9052',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Île-de-France',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '83c72ca9-5e9e-4a04-9d24-325a0de8700f',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Landes',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '85c46f64-2f60-41e5-b803-03b85454be5a',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 40,
          'format' => NULL,
          'safe_value' => 40,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'a9cfd8d8-2bfb-4651-94db-e487ca43960c',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ain',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8ae85039-3fb2-49e4-95d3-ad92bdc4f932',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => '01',
          'format' => NULL,
          'safe_value' => '01',
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '068ab95f-a04c-467f-8d73-e102269c8fb0',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Haut Rhin',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8cc637bd-9dbf-43ba-b748-ad62d2ff9389',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 68,
          'format' => NULL,
          'safe_value' => 68,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '4d6388c5-ecb4-4bb9-891f-34ed939b5ac8',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Haute-Normandie',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8dde61bb-dd29-47b5-9f86-ece9e51b8af0',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Midi-Pyrénées',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8f7a4318-f820-4d97-81b3-75960f9a8ca3',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Gironde',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9374e9eb-c82c-4121-b770-25c729b98ea3',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 33,
          'format' => NULL,
          'safe_value' => 33,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'a9cfd8d8-2bfb-4651-94db-e487ca43960c',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Cantal',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '97f00011-b282-4d8b-9183-c379e8b5fa11',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 15,
          'format' => NULL,
          'safe_value' => 15,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'e0850f4c-8001-4a5c-a4b1-434e0fe8a7b9',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Haute Marne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '98133f64-c362-474b-85d9-f0008756a1f5',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 52,
          'format' => NULL,
          'safe_value' => 52,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '3380aa03-777c-4c87-b45e-b86c01198a7d',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Doubs',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a3bf4254-a630-42cc-8e80-9a5b8fa12e90',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 25,
          'format' => NULL,
          'safe_value' => 25,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '41d8bb9b-54f3-469a-b1b9-4468c81c9052',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Tarn et Garonne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a3e78396-0b05-4027-b907-d31b2b88dff8',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 82,
          'format' => NULL,
          'safe_value' => 82,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '8f7a4318-f820-4d97-81b3-75960f9a8ca3',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Aveyron',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a657ceb4-c27e-40ba-ba94-6e0cea362c48',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 12,
          'format' => NULL,
          'safe_value' => 12,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '8f7a4318-f820-4d97-81b3-75960f9a8ca3',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'ru',
    'description' => 'description of ru',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'a78d8b00-dbcd-4f4a-9dd2-4af2bc7a6d8e',
    'vocabulary_machine_name' => 'ville',
    'field_code_departement' => array(
      'und' => array(
        0 => array(
          'value' => 'Aliquip amet cui dignissim huic refero sagaciter tego vulputate zelus. Dignissim dolore enim haero. Adipiscing importunus refero. Causa praesent sagaciter tincidunt. Aliquip bene feugiat interdico letalis natu quibus secundum.',
          'format' => 'plain_text',
          'safe_value' => 'Aliquip amet cui dignissim huic refero sagaciter tego vulputate zelus. Dignissim dolore enim haero. Adipiscing importunus refero. Causa praesent sagaciter tincidunt. Aliquip bene feugiat interdico letalis natu quibus secundum.',
        ),
      ),
    ),
    'field_idk' => array(
      'und' => array(
        0 => array(
          'value' => 'Accumsan brevitas duis gemino incassum tamen tego ut venio. Abdo consectetuer diam esca macto odio velit. Abigo facilisi in patria similis te. Exputo neque zelus. Ad amet bene eu eum immitto letalis mauris tego utrum.',
          'format' => 'plain_text',
          'safe_value' => 'Accumsan brevitas duis gemino incassum tamen tego ut venio. Abdo consectetuer diam esca macto odio velit. Abigo facilisi in patria similis te. Exputo neque zelus. Ad amet bene eu eum immitto letalis mauris tego utrum.',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Aquitaine',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a9cfd8d8-2bfb-4651-94db-e487ca43960c',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Pyrénées Atlantiques',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'aa69fb97-d8f5-41d0-9090-61f72e9a6e7d',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 64,
          'format' => NULL,
          'safe_value' => 64,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'a9cfd8d8-2bfb-4651-94db-e487ca43960c',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ardèche',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'abcb384a-099b-4ab6-a0c2-4efe7149aa8e',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => '07',
          'format' => NULL,
          'safe_value' => '07',
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '068ab95f-a04c-467f-8d73-e102269c8fb0',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Var',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ae672341-707e-4256-a856-419509831301',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 83,
          'format' => NULL,
          'safe_value' => 83,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '5cf404d1-9a47-4af3-9178-72cee26f690d',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Seine et Marne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'af26230b-d182-48e0-9158-cd4216219350',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 77,
          'format' => NULL,
          'safe_value' => 77,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '83c72ca9-5e9e-4a04-9d24-325a0de8700f',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Jura',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b40ef5fc-06bd-4147-872d-9d92e02d4964',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 39,
          'format' => NULL,
          'safe_value' => 39,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '41d8bb9b-54f3-469a-b1b9-4468c81c9052',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Isère',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b6e0cf45-ee7b-4fed-96c3-1339659654da',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 38,
          'format' => NULL,
          'safe_value' => 38,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '068ab95f-a04c-467f-8d73-e102269c8fb0',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Moselle',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b7811ff2-59d0-4b4e-9119-2d834e8a4573',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 57,
          'format' => NULL,
          'safe_value' => 57,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '4497554f-08f7-49c7-8444-654ccf21706e',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Finistère',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c20db490-dccc-4cd1-b2be-2ed770b8e7d8',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 29,
          'format' => NULL,
          'safe_value' => 29,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'd195a755-0e85-4200-8ee4-fb1d9d94b6da',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Poitou-Charentes',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c2433b6e-de2b-4d97-9820-25c734a23539',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Vienne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c784d86c-9870-449b-8968-c5a3fdf32769',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 86,
          'format' => NULL,
          'safe_value' => 86,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'c2433b6e-de2b-4d97-9820-25c734a23539',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Rhône-Alpes',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cad37e79-ab59-4fb6-847f-192a808b4723',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 69,
          'format' => NULL,
          'safe_value' => 69,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '068ab95f-a04c-467f-8d73-e102269c8fb0',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Deux Sèvres',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cb5cc837-bf90-4a8f-8001-ba8b7475128c',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 79,
          'format' => NULL,
          'safe_value' => 79,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'c2433b6e-de2b-4d97-9820-25c734a23539',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Gers',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cbb2cf68-072b-4b31-a535-8a3ce96e18a9',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 32,
          'format' => NULL,
          'safe_value' => 32,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '8f7a4318-f820-4d97-81b3-75960f9a8ca3',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Côte d\'Armor',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cca537c1-9484-4465-ad8b-fcfa532d6b18',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 22,
          'format' => NULL,
          'safe_value' => 22,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'd195a755-0e85-4200-8ee4-fb1d9d94b6da',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Basse-Normandie',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cee77f25-0f4f-4df1-b910-97bd23cc6cb2',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Orne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cff63adb-ebc8-4551-ab52-6b88d3012cca',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 61,
          'format' => NULL,
          'safe_value' => 61,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'cee77f25-0f4f-4df1-b910-97bd23cc6cb2',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Bretagne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd195a755-0e85-4200-8ee4-fb1d9d94b6da',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Pays de la Loire',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd30614f8-f0bf-4f9f-ae1a-b86b2fc60064',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Haute Vienne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd6954bc3-4e1b-4a44-8255-954aaa4f68f4',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 87,
          'format' => NULL,
          'safe_value' => 87,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '22a4748b-70b1-4902-be29-3d26b85c55c1',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Corse',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd9847079-bf25-41d1-b303-1692142edb5c',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Eure',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'dc69ae93-c87b-498e-8eae-5f7bcfe602a5',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 27,
          'format' => NULL,
          'safe_value' => 27,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '8dde61bb-dd29-47b5-9f86-ece9e51b8af0',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Charente',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'dd641565-a30d-4cd9-a8d7-6bc17bb0606f',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 16,
          'format' => NULL,
          'safe_value' => 16,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'c2433b6e-de2b-4d97-9820-25c734a23539',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Corse-du-Sud',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ddbff50e-1f0a-43af-ba63-7fc447b2b1cd',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => '2A',
          'format' => NULL,
          'safe_value' => '2A',
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'd9847079-bf25-41d1-b303-1692142edb5c',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Manche',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'de27d119-861b-4e33-b1bc-44a074768fce',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 50,
          'format' => NULL,
          'safe_value' => 50,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'cee77f25-0f4f-4df1-b910-97bd23cc6cb2',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Auvergne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e0850f4c-8001-4a5c-a4b1-434e0fe8a7b9',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Dordogne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e122b0bf-0ff1-45b1-b0bd-8db900e84908',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 24,
          'format' => NULL,
          'safe_value' => 24,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'a9cfd8d8-2bfb-4651-94db-e487ca43960c',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Alpes de Haute Provence',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e31cdb4d-1a4a-4ba9-9e16-a96138c6438a',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => '04',
          'format' => NULL,
          'safe_value' => '04',
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'e0850f4c-8001-4a5c-a4b1-434e0fe8a7b9',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Maison',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e33ca9e6-807c-4b51-bf2d-de290a05461a',
    'vocabulary_machine_name' => 'type_de_habitat',
  );
  $terms[] = array(
    'name' => 'Lozère',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e3c2a47d-81eb-4f13-a78d-cdeddde7953d',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 48,
          'format' => NULL,
          'safe_value' => 48,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '255451a5-c0cb-4db7-a0d3-2254fac6abe4',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Vosges',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e42eb59c-b995-424d-a64e-0b1557aa96b4',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 88,
          'format' => NULL,
          'safe_value' => 88,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '4497554f-08f7-49c7-8444-654ccf21706e',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Tarn',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e57e5f80-028b-4427-b9fa-ba7b82ac4315',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 81,
          'format' => NULL,
          'safe_value' => 81,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '8f7a4318-f820-4d97-81b3-75960f9a8ca3',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Aude',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e87f2d35-92b8-41d6-8e50-b4ba9b75d4c6',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 11,
          'format' => NULL,
          'safe_value' => 11,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '255451a5-c0cb-4db7-a0d3-2254fac6abe4',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Essonne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e8993471-4914-4ff5-995b-7ff34f9a4408',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 91,
          'format' => NULL,
          'safe_value' => 91,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '83c72ca9-5e9e-4a04-9d24-325a0de8700f',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Aube',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e998e8ea-e520-4b53-9e3d-9551681b71b2',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 10,
          'format' => NULL,
          'safe_value' => 10,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '3380aa03-777c-4c87-b45e-b86c01198a7d',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Puy-de-Dôme',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'edf80168-9baf-4bea-8c80-1ba772f02039',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 63,
          'format' => NULL,
          'safe_value' => 63,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'e0850f4c-8001-4a5c-a4b1-434e0fe8a7b9',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Nord-Pas-de-Calais',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'efef5001-c9bf-4bce-9a08-4dece3b35b92',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Mayenne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f3ef68b3-a2b5-4369-be32-1bbf570626cf',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 53,
          'format' => NULL,
          'safe_value' => 53,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'd30614f8-f0bf-4f9f-ae1a-b86b2fc60064',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Morbihan',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f79f52df-6d05-4d9e-aea8-65026075ee7e',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 56,
          'format' => NULL,
          'safe_value' => 56,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'd195a755-0e85-4200-8ee4-fb1d9d94b6da',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Savoie',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f92736c4-0700-4686-890b-1f73e65fb799',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 73,
          'format' => NULL,
          'safe_value' => 73,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '068ab95f-a04c-467f-8d73-e102269c8fb0',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Sarthe',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'faddea7b-55a0-4af9-9c8b-55b505d1ce40',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 72,
          'format' => NULL,
          'safe_value' => 72,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'd30614f8-f0bf-4f9f-ae1a-b86b2fc60064',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Pas de Calais',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fc7c0c90-f10a-4b82-a493-686987ba88c5',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 62,
          'format' => NULL,
          'safe_value' => 62,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => 'efef5001-c9bf-4bce-9a08-4dece3b35b92',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Drôme',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fd371496-99c7-452d-8cf0-b274dcfa0b11',
    'vocabulary_machine_name' => 'departement',
    'field_numero_departement' => array(
      'und' => array(
        0 => array(
          'value' => 26,
          'format' => NULL,
          'safe_value' => 26,
        ),
      ),
    ),
    'field_region' => array(
      'und' => array(
        0 => array(
          'tid' => '068ab95f-a04c-467f-8d73-e102269c8fb0',
        ),
      ),
    ),
  );
  return $terms;
}
