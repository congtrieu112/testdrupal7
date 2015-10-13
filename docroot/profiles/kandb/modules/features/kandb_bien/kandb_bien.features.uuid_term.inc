<?php
/**
 * @file
 * kandb_bien.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function kandb_bien_uuid_features_default_terms() {
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
    'name' => 'NORD/NORD-OUEST/EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '015859b7-c7af-45ad-9bf6-0fbe00d38a07',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/NO/E',
          'format' => NULL,
          'safe_value' => 'N/NO/E',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '45 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '025a6a2f-8430-4fbb-9f9c-66dd4a4a7eae',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 45,
          'format' => NULL,
          'safe_value' => 45,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-OUEST/OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '02a7c199-bb78-40d9-b78b-b4974b3baa77',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SO/O',
          'format' => NULL,
          'safe_value' => 'SO/O',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '11 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '03ac75df-069a-49f8-8cb7-bdec1557b3f4',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 11,
          'format' => NULL,
          'safe_value' => 11,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-EST/NORD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '04fe6ccc-d495-482c-8207-9624cb3c9b2f',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SE/NE',
          'format' => NULL,
          'safe_value' => 'SE/NE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-OUEST/NORD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '05b3424a-0678-4544-9c4a-977eb33356ce',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SO/NE',
          'format' => NULL,
          'safe_value' => 'SO/NE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '10 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '08decc01-40d4-406f-b6ab-af4c049642ec',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 10,
          'format' => NULL,
          'safe_value' => 10,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'EST/SUD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '0908df07-f01f-459a-8a8a-ba30ce7d5cd3',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'E/S',
          'format' => NULL,
          'safe_value' => 'E/S',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '13 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '0c122321-918d-4dea-af5d-52ac20558b7d',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 13,
          'format' => NULL,
          'safe_value' => 13,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '18 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '0c2b49d3-9913-4fd6-a14a-97aa28bf197c',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 18,
          'format' => NULL,
          'safe_value' => 18,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD/SUD-EST/NORD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '0e2d0105-adba-426a-b23b-4172d5d50f67',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/SE/NE',
          'format' => NULL,
          'safe_value' => 'S/SE/NE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD/NORD-OUEST/SUD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '0e35b3c1-f322-4772-ad93-645d64a3a37a',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/NO/S',
          'format' => NULL,
          'safe_value' => 'N/NO/S',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1076efcb-b662-4a01-9707-edb0d492b7b3',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SE',
          'format' => NULL,
          'safe_value' => 'SE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-EST/EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '12f22e52-be89-44bb-bce6-e6e437c4b492',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NE/E',
          'format' => NULL,
          'safe_value' => 'NE/E',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OUEST/SUDEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '14c9d463-9760-48de-a871-8dbe8762f5e4',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'O/SE',
          'format' => NULL,
          'safe_value' => 'O/SE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD/OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '15c47f50-5e2a-4022-a7a6-ac46ffefe948',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/O',
          'format' => NULL,
          'safe_value' => 'N/O',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '17aaa15d-5a0f-4a71-83c1-bc712666e020',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'E',
          'format' => NULL,
          'safe_value' => 'E',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD/NORD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1aa8a5ef-4381-40d7-8b85-10cd8b97a765',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/NE',
          'format' => NULL,
          'safe_value' => 'N/NE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-OUEST/SUD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1c2be6d1-1f83-42be-b259-a4805922630a',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NO/SO',
          'format' => NULL,
          'safe_value' => 'NO/SO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD/EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1c360932-5aa0-46ee-a060-3847bc7b4744',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/E',
          'format' => NULL,
          'safe_value' => 'S/E',
        ),
      ),
    ),
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
    'name' => '43 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '20903a39-c532-4ea8-a931-b99163860d86',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 43,
          'format' => NULL,
          'safe_value' => 43,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'EST/NORD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '211211cc-4f70-483b-86f2-01955c09647c',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'E/N',
          'format' => NULL,
          'safe_value' => 'E/N',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '1 er étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '22c41169-ad62-4cad-9ad3-ec687e90686b',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
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
    'name' => 'EST/SUD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '23c001e6-dc02-43cb-a84f-49eef17af024',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'E/SO',
          'format' => NULL,
          'safe_value' => 'E/SO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD/NORD-OUEST/SUD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '26c0c4b7-d828-486f-8384-7d6edf91a3e6',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/NO/SE',
          'format' => NULL,
          'safe_value' => 'N/NO/SE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-OUEST/EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2701a262-855c-4883-9d7e-d15473caacbf',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SO/E',
          'format' => NULL,
          'safe_value' => 'SO/E',
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
    'name' => '48 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2957222b-28d0-4cf9-a2cc-a36f721132b0',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 48,
          'format' => NULL,
          'safe_value' => 48,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '1 chambre',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '299737cd-f31f-4cc5-b311-e070f342ff93',
    'vocabulary_machine_name' => 'nb_chambres',
    'field_id_nombre_chambre' => array(
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
    'name' => '3 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2a6ed22e-3b60-4c2c-9c5d-c16b115fa058',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
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
    'name' => 'SUD/NORD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2ab1305f-03ac-4c26-b5cf-1afe704cd856',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/NO',
          'format' => NULL,
          'safe_value' => 'S/NO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OUEST/SUD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2bd06909-7527-4706-b602-8531f56d8e78',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'O/S',
          'format' => NULL,
          'safe_value' => 'O/S',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-EST/NORD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2c4adc17-a28c-47ba-bb65-6187cc3b12cb',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SE/NO',
          'format' => NULL,
          'safe_value' => 'SE/NO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '40 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2cbb42f6-8886-48f7-a942-97baee33057d',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 40,
          'format' => NULL,
          'safe_value' => 40,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2d497ca4-af3d-42fd-9052-deaa091ecebc',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SO',
          'format' => NULL,
          'safe_value' => 'SO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OUEST/NORD/EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2e1e9c78-ef48-405a-b80a-997f27bece88',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'O/N/E',
          'format' => NULL,
          'safe_value' => 'O/N/E',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '5 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2fed0587-b291-4197-baea-c605d4cdb7ac',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
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
    'name' => 'SUD/OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3191957f-9561-4321-a7e6-85ceb9d000ee',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/O',
          'format' => NULL,
          'safe_value' => 'S/O',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-OUEST/SUD-EST/SUD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '32a99ce8-c042-4188-8cb6-0a42d9c56123',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NO/NE/SO',
          'format' => NULL,
          'safe_value' => 'NO/NE/SO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '5 chambres et +',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '371e28aa-e96c-41bc-80f8-d1e48890de42',
    'vocabulary_machine_name' => 'nb_chambres',
    'field_id_nombre_chambre' => array(
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
    'name' => 'NORD-OUEST/NORD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '37ca1d5f-90b4-4bb9-8a4b-1a88e2234457',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NO/NE',
          'format' => NULL,
          'safe_value' => 'NO/NE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '20 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '38e9e858-2876-4179-9293-2dd22a54419f',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 20,
          'format' => NULL,
          'safe_value' => 20,
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
    'name' => '4 / 5 éme étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3a5d7cf8-3e1e-488b-9c14-e57c9b085c99',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => '4/5',
          'format' => NULL,
          'safe_value' => '4/5',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OUEST/NORD-OUEST/EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3bf70a96-4d19-4549-b12f-865253c25c07',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'O/NO/E',
          'format' => NULL,
          'safe_value' => 'O/NO/E',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '37 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3da33725-eb59-4568-918c-066e6fe0e453',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 37,
          'format' => NULL,
          'safe_value' => 37,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '6 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3fb90b60-cf12-430b-9bd3-dad197d2a82d',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 6,
          'format' => NULL,
          'safe_value' => 6,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OUEST/SUD/EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4135563b-94b9-4459-8cc6-bad8c7f4ba2d',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'O/S/E',
          'format' => NULL,
          'safe_value' => 'O/S/E',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '4 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '41d752d7-a74b-4dfc-b0ef-04f74d215ed6',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
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
    'name' => 'EST/SUD/OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '43bf6fbf-c93a-49c6-bd3a-cc6fe178cdf6',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'E/S/O',
          'format' => NULL,
          'safe_value' => 'E/S/O',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'EST/NORD/OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '44218683-7765-4cb7-a7f9-839ef1abadfe',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'E/N/O',
          'format' => NULL,
          'safe_value' => 'E/N/O',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD/EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '44252904-8b8c-44b7-ab33-d53cdf3e0866',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/E',
          'format' => NULL,
          'safe_value' => 'N/E',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'EST/SUD-EST/SUD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '47080ee4-4ddd-4c48-8d65-bb11c5bd33be',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'E/SE/SO',
          'format' => NULL,
          'safe_value' => 'E/SE/SO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OUEST/NORD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '47bdf498-f94f-4bf9-84c9-fba6b05e4acc',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'O/NO',
          'format' => NULL,
          'safe_value' => 'O/NO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '17 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '47c7b9e3-8d0e-47a8-afa8-a289800e3c49',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 17,
          'format' => NULL,
          'safe_value' => 17,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '47 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4d4b38e4-a0e9-41ab-bf2b-e01536e3d89e',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 47,
          'format' => NULL,
          'safe_value' => 47,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '39 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4defde69-cc07-4ac1-8ed2-be31af155d43',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 39,
          'format' => NULL,
          'safe_value' => 39,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD/OUEST/SUD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '511250d6-8bb8-4e61-9ca9-d0cbc3f0f557',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/O/SE',
          'format' => NULL,
          'safe_value' => 'N/O/SE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-EST/OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '53957054-3945-434c-b14a-61866093e0e7',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SE/O',
          'format' => NULL,
          'safe_value' => 'SE/O',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '30 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '53f27edc-cc64-4249-b35e-ab6280a70f73',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 30,
          'format' => NULL,
          'safe_value' => 30,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '15 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '58072d31-59a0-4970-b95d-0f78b90d7fa8',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 15,
          'format' => NULL,
          'safe_value' => 15,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD/OUEST/NORD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '58a407dd-e2a0-403f-bd0d-bac9104833ed',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/O/N',
          'format' => NULL,
          'safe_value' => 'S/O/N',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '36 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5b406ee2-02b4-4970-a2ca-55382c521730',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 36,
          'format' => NULL,
          'safe_value' => 36,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-EST/NORD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5f0bb8f7-0f6f-4041-baab-c4190213dc9b',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SE/N',
          'format' => NULL,
          'safe_value' => 'SE/N',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OUEST/NORD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '604b4872-5e46-4882-9a32-906320332376',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'O/N',
          'format' => NULL,
          'safe_value' => 'O/N',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD/SUD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6212f3d6-7025-4efe-886a-1fa303002dcb',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/SE',
          'format' => NULL,
          'safe_value' => 'N/SE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-EST/SUD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '62c497a6-3f31-4f48-b4cc-5deff60e6e32',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NE/SE',
          'format' => NULL,
          'safe_value' => 'NE/SE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '25 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '647e1ac9-ac6f-4626-a640-98fb38eb6a70',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 25,
          'format' => NULL,
          'safe_value' => 25,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'EST/OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '69d9f43d-b529-4603-984f-ac76dc76421f',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'E/O',
          'format' => NULL,
          'safe_value' => 'E/O',
        ),
      ),
    ),
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
    'name' => 'SUD/NORD/EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6b65c8de-9e0d-44e2-9158-d0bec968f458',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/N/E',
          'format' => NULL,
          'safe_value' => 'S/N/E',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '2 chambres',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6b8c6264-5020-4a8f-9a6c-e7b4dae4224d',
    'vocabulary_machine_name' => 'nb_chambres',
    'field_id_nombre_chambre' => array(
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
    'name' => '23 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6bd43437-7dd3-4806-8740-9a870e02cff9',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 23,
          'format' => NULL,
          'safe_value' => 23,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD/SUD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6bd7fe34-e3fd-43c9-b7b1-c9d84c47425a',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/SO',
          'format' => NULL,
          'safe_value' => 'S/SO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '14 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6f21a86b-4b44-4d6f-9cab-53512fdf9271',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 14,
          'format' => NULL,
          'safe_value' => 14,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '22 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '70224639-a573-4ec6-ad43-1247eab9bc95',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 22,
          'format' => NULL,
          'safe_value' => 22,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '5 / 6 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '726e075d-3b2b-4b10-b42c-8d5008beb705',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => '5/6',
          'format' => NULL,
          'safe_value' => '5/6',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NULL',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '727bf68e-3f8c-4684-a799-294ef6ec085b',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 'NP',
          'format' => NULL,
          'safe_value' => 'NP',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-OUEST/EST/NORD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '73766474-a781-45f7-9cb9-d8ec128e5685',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SO/E/N',
          'format' => NULL,
          'safe_value' => 'SO/E/N',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-EST/SUD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7465442d-3a0c-4cfa-99fc-6584803a1829',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NE/SO',
          'format' => NULL,
          'safe_value' => 'NE/SO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Duplex en sous-sol',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '78283b3f-6ad6-4940-9739-b79bf1c43fae',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => -2,
          'format' => NULL,
          'safe_value' => -2,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '3 / 4 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '798623c0-b37e-4257-aadd-002506339b31',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => '3/4',
          'format' => NULL,
          'safe_value' => '3/4',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OUEST/EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7c254eef-edfa-4538-9cfc-2acfb38d984d',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'O/E',
          'format' => NULL,
          'safe_value' => 'O/E',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD/NORD/NORD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7f6cc42d-3a10-41a6-b69b-778f96460e63',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/N/NE',
          'format' => NULL,
          'safe_value' => 'S/N/NE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '42 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7f85e77a-8c27-4931-bfda-bdd661f7fd2c',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 42,
          'format' => NULL,
          'safe_value' => 42,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Entre sol',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '80784aae-72ea-4a37-addb-f51d9b253de9',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 'E/S',
          'format' => NULL,
          'safe_value' => 'E/S',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-OUEST/SUD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8139b86a-2de4-4e79-aeb5-b04ff9f28d80',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NO/SE',
          'format' => NULL,
          'safe_value' => 'NO/SE',
        ),
      ),
    ),
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
    'name' => 'NORD/SUD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '83f1a137-c8b7-4a0b-b69e-d3b3b0e17d2e',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/SO',
          'format' => NULL,
          'safe_value' => 'N/SO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '44 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '850b39e7-cf19-4343-8fb7-4e694096fdfe',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 44,
          'format' => NULL,
          'safe_value' => 44,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-OUEST/SUD-EST/NORD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '87c25caf-71ec-41aa-9a89-b81c445baa6c',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SO/SE/NE',
          'format' => NULL,
          'safe_value' => 'SO/SE/NE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '3 chambres',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8ae4c2a6-528d-4646-bdca-71a6275f3463',
    'vocabulary_machine_name' => 'nb_chambres',
    'field_id_nombre_chambre' => array(
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
    'name' => '29 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8b9dbb89-b231-4dc3-823e-f7064b9d006f',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 29,
          'format' => NULL,
          'safe_value' => 29,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-OUEST/OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8e4a2849-1151-4b94-9ee4-d451fef74840',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NO/O',
          'format' => NULL,
          'safe_value' => 'NO/O',
        ),
      ),
    ),
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
  $terms[] = array(
    'name' => 'NORD/EST/OUEST/SUD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '91084ca0-fbf8-48c2-86e5-d810e544e2f7',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/E/O/S',
          'format' => NULL,
          'safe_value' => 'N/E/O/S',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-EST/NORD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '934cc1ee-da64-47bf-bc98-a193fb985f13',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NE/NO',
          'format' => NULL,
          'safe_value' => 'NE/NO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-OUEST/NORD-EST/SUD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '93febf63-e264-4606-a440-ca4c1d662db2',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NO/NE/SO',
          'format' => NULL,
          'safe_value' => 'NO/NE/SO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '35 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '994258ef-310b-4825-8d50-41819d6a4100',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 35,
          'format' => NULL,
          'safe_value' => 35,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD/EST/OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '99718fa4-0010-431b-b170-dae244e60273',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/E/O',
          'format' => NULL,
          'safe_value' => 'S/E/O',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '33 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9c3177a5-5022-415d-b5a9-541a6ee47290',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 33,
          'format' => NULL,
          'safe_value' => 33,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '12 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9cbc5f1d-95c4-4c2f-a2dc-24e34d60c5ab',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 12,
          'format' => NULL,
          'safe_value' => 12,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '27 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9d6dceb2-f7b6-43f2-b3a7-29e0af745a07',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 27,
          'format' => NULL,
          'safe_value' => 27,
        ),
      ),
    ),
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
    'name' => 'SUD/NORD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a325dee0-d60a-411f-b76d-f0605ad264e0',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/NE',
          'format' => NULL,
          'safe_value' => 'S/NE',
        ),
      ),
    ),
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
    'name' => 'SUD/SUD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a6462b4e-970c-4922-a6c3-9385adf756be',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/SE',
          'format' => NULL,
          'safe_value' => 'S/SE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '26 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a783dad3-9fb1-4287-a15f-874e715af919',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 26,
          'format' => NULL,
          'safe_value' => 26,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-OUEST/NORD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a7e33cfd-0728-4c53-8a50-1f3f431a5e93',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NO/N',
          'format' => NULL,
          'safe_value' => 'NO/N',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Plain pied',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a8201918-c5b0-468d-83a7-d19d23900e50',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 'PPD',
          'format' => NULL,
          'safe_value' => 'PPD',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '34 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ad259271-3fa4-4964-9abc-d808ad1bad00',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 34,
          'format' => NULL,
          'safe_value' => 34,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '46 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'afedb65d-cfde-40f8-9efd-43f7472ef6df',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 46,
          'format' => NULL,
          'safe_value' => 46,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '24 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b02531e8-b9a9-414e-b320-52e31f0af221',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 24,
          'format' => NULL,
          'safe_value' => 24,
        ),
      ),
    ),
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
    'name' => 'NORD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b30dc16a-801b-4a4e-a2b4-9fa2242f058a',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N',
          'format' => NULL,
          'safe_value' => 'N',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '31 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b3734fda-2bb4-4f4c-a42d-0a0f5374eadf',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 31,
          'format' => NULL,
          'safe_value' => 31,
        ),
      ),
    ),
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
    'name' => '2 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b9b63279-4a5f-4c45-a7e8-387fd0d7c24f',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
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
    'name' => 'NORD/NORD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'bb740b6b-3211-4a66-acc0-21ec890ab248',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/NO',
          'format' => NULL,
          'safe_value' => 'N/NO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '8 / 9 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'bc3c226f-377f-4da2-a581-8b90e321c0a5',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => '8/9',
          'format' => NULL,
          'safe_value' => '8/9',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-OUEST/SUD-OUEST/SUD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'bfb09e15-0775-42fe-aaf0-ae1a9eff1291',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NO/SO/SE',
          'format' => NULL,
          'safe_value' => 'NO/SO/SE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '4 chambres',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c1350f73-481c-47d4-8d3f-f2fcefdb237e',
    'vocabulary_machine_name' => 'nb_chambres',
    'field_id_nombre_chambre' => array(
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
    'name' => 'Rez de chaussée',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c1c24a1f-83d1-4302-9d17-d467e97cb84f',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 'RDC',
          'format' => NULL,
          'safe_value' => 'RDC',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '7 / 8 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c3a3d627-8d36-403a-b707-2f8994ad38a1',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => '7/8',
          'format' => NULL,
          'safe_value' => '7/8',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD/EST/SUD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c44ad114-da48-45db-a982-4f142338ea60',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/E/S',
          'format' => NULL,
          'safe_value' => 'N/E/S',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'EST/SUD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c457e6ff-d7f0-4eaf-8926-6788695e7568',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'E/SE',
          'format' => NULL,
          'safe_value' => 'E/SE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '16 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c788cb50-b418-4be0-aaf5-70da4a082a42',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 16,
          'format' => NULL,
          'safe_value' => 16,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'EST/NORD/OUEST/SUD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c7e41cc1-f3ba-433c-b938-c4e92934586a',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'ENOS',
          'format' => NULL,
          'safe_value' => 'ENOS',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c8362353-77ee-44bc-b624-71a318a3dc67',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NO',
          'format' => NULL,
          'safe_value' => 'NO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD/EST/OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c844a98f-d8eb-4607-8916-5a1f47842a27',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/E/O',
          'format' => NULL,
          'safe_value' => 'N/E/O',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '28 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c9dde75f-fc61-4339-a4f5-a746d094a093',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 28,
          'format' => NULL,
          'safe_value' => 28,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '49 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ca7d4636-fa1c-4086-93ab-3b1d2eb9c684',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 49,
          'format' => NULL,
          'safe_value' => 49,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-OUEST/SUD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ce144d4c-603c-4a82-819e-a1789ba1a0af',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SO/SE',
          'format' => NULL,
          'safe_value' => 'SO/SE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD/NORD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cf162c93-48a4-41ab-ad7d-1f2521009348',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/N',
          'format' => NULL,
          'safe_value' => 'S/N',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD/SUD-OUEST/ESTNORD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd00fc3f4-e20e-4167-bd91-167078e99ea5',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/SO/ENE',
          'format' => NULL,
          'safe_value' => 'S/SO/ENE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '38 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd1d7ce06-ec39-4463-9219-7a57fccefe44',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 38,
          'format' => NULL,
          'safe_value' => 38,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OUEST/NORD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd20dae9f-1e97-416f-b3e8-9414f100a7d7',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'O/NE',
          'format' => NULL,
          'safe_value' => 'O/NE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NULL',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd2a0ccd5-c98b-4546-b2d8-25da5f75aa45',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => -1,
          'format' => NULL,
          'safe_value' => -1,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OUEST/SUD/EST/NORD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd3c00900-a0d9-41bf-bae9-b4bf997ba31d',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'OSEN',
          'format' => NULL,
          'safe_value' => 'OSEN',
        ),
      ),
    ),
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
    'name' => '6 / 7 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd6d399ff-4905-4774-a180-eebab849c4ec',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => '6/7',
          'format' => NULL,
          'safe_value' => '6/7',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd749c6e5-01fc-41a2-92cd-869faff26bbb',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S',
          'format' => NULL,
          'safe_value' => 'S',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '9 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd78e6186-b347-47d4-9b44-976213c4964b',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 9,
          'format' => NULL,
          'safe_value' => 9,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD/SUD-OUEST/EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd7ea1783-7e6f-4081-a2c9-1eb35f476df8',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'S/SO/E',
          'format' => NULL,
          'safe_value' => 'S/SO/E',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'EST/NORD/SUD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd9426980-5945-420b-917b-97e2249e1612',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'E/N/S',
          'format' => NULL,
          'safe_value' => 'E/N/S',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-EST/SUD-EST/EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd9b4b4ba-b571-4c1f-b1ff-3e7672e6c9ca',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NE/SE/E',
          'format' => NULL,
          'safe_value' => 'NE/SE/E',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '50 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'def76158-b58b-4889-9a92-011424e238fb',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 50,
          'format' => NULL,
          'safe_value' => 50,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORDNORD-OUEST/SUDSUD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e2b035af-cf8b-48c6-bf90-24c87889d2fc',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NNO/SSE',
          'format' => NULL,
          'safe_value' => 'NNO/SSE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-EST/SUD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e2cf82c8-e086-4252-95c8-f8bf1b26bd25',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SE/SO',
          'format' => NULL,
          'safe_value' => 'SE/SO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Sous-Sol',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e37a2df0-c10e-46b6-9cb0-0bdbfc8f904b',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 'SS',
          'format' => NULL,
          'safe_value' => 'SS',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '19 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e59be378-7b53-425c-8b71-e03e337d29b7',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 19,
          'format' => NULL,
          'safe_value' => 19,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'EST/OUEST/NORD/SUD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e8ca8666-41bf-4896-b977-04ffd658fd24',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'E/O/N/S',
          'format' => NULL,
          'safe_value' => 'E/O/N/S',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Combles',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'eb308021-8a96-40d0-a13a-d79e6aa4c090',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 'CMB',
          'format' => NULL,
          'safe_value' => 'CMB',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD/SUD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ec0dad20-0d92-4741-9cc2-457c1a168ac6',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'N/S',
          'format' => NULL,
          'safe_value' => 'N/S',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ec95e1dd-be41-40b3-a4c0-83ede8bf113e',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'O',
          'format' => NULL,
          'safe_value' => 'O',
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
    'name' => 'NORD-EST/SUDEST/NORD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'eede3c50-71b4-44af-8c56-f532fdd2c3ed',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NE/SE/NO',
          'format' => NULL,
          'safe_value' => 'NE/SE/NO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'EST/NORD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'efd2b9f0-9dfa-44bf-a972-7d37d10b582f',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'E/NO',
          'format' => NULL,
          'safe_value' => 'E/NO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '41 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f5c9fe37-fbd4-437e-999d-5ac847f23289',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 41,
          'format' => NULL,
          'safe_value' => 41,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'SUD-OUEST/SUD-EST/NORD-OUEST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f737a021-4d77-4abb-844d-32a4f3efa7d2',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'SO/SE/NO',
          'format' => NULL,
          'safe_value' => 'SO/SE/NO',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '8 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f7d1d9eb-3568-4f1e-817d-09e5953f4a00',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 8,
          'format' => NULL,
          'safe_value' => 8,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '32 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f8598a34-7384-46a4-bfb7-f53619eaef30',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 32,
          'format' => NULL,
          'safe_value' => 32,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '21 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fa024a96-0665-4463-bba2-61d80787ea19',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 21,
          'format' => NULL,
          'safe_value' => 21,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'NORD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fabdbfb0-9322-4363-a0f2-8941cc533d6b',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'NE',
          'format' => NULL,
          'safe_value' => 'NE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Rez de jardin',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fb46c770-6d3c-47f6-94b3-c922e01748ec',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 'RDJ',
          'format' => NULL,
          'safe_value' => 'RDJ',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'EST/NORD-EST',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fbe6b11e-551c-401f-ba2b-35518adb2135',
    'vocabulary_machine_name' => 'orientation',
    'field_id_orientation' => array(
      'und' => array(
        0 => array(
          'value' => 'E/NE',
          'format' => NULL,
          'safe_value' => 'E/NE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '7 ème étage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fea8fda4-3162-4da3-b3e0-dac251b22b08',
    'vocabulary_machine_name' => 'etage',
    'field_id_etage' => array(
      'und' => array(
        0 => array(
          'value' => 7,
          'format' => NULL,
          'safe_value' => 7,
        ),
      ),
    ),
  );
  return $terms;
}
