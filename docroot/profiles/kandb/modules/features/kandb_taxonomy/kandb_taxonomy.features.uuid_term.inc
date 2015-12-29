<?php
/**
 * @file
 * kandb_taxonomy.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function kandb_taxonomy_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Réservé',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '0050afc0-008d-4d4d-b870-f9b8e8845218',
    'vocabulary_machine_name' => 'status_logement',
    'field_id_file' => array(
      'und' => array(
        0 => array(
          'value' => 'R',
          'format' => NULL,
          'safe_value' => 'R',
        ),
      ),
    ),
    'field_id_xls' => array(
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
    'name' => 'Rocade',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '02200368-a73d-474f-aa55-d64a95e8f026',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'RCD',
          'format' => NULL,
          'safe_value' => 'RCD',
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
    'name' => 'Massy- Palaiseau - Les Ulis (A10)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '03094f45-5d78-4a3b-8325-df2fd190ddba',
    'vocabulary_machine_name' => 'zone_activite',
    'field_id_zone_activite' => array(
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
    'name' => 'Plein pied',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '039bd663-6017-487f-8a60-71ac0247ebf6',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'name' => 'Rhône-Alpes',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '068ab95f-a04c-467f-8d73-e102269c8fb0',
    'vocabulary_machine_name' => 'region',
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
    'name' => 'Pack silver',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0fd28321-995f-4127-93b2-e964fb7c9db2',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-pack-silver',
          'format' => NULL,
          'safe_value' => 'icon-pack-silver',
        ),
      ),
    ),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
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
    'name' => 'Evry (A6)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1083a0bc-21b4-4eb5-8961-fa3157973055',
    'vocabulary_machine_name' => 'zone_activite',
    'field_id_zone_activite' => array(
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
    'name' => 'Paris La Défense',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '11074d8d-72dc-4821-acc0-8d59281821f7',
    'vocabulary_machine_name' => 'zone_activite',
    'field_id_zone_activite' => array(
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
    'name' => 'Solarium',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '12814810-d7ec-4aeb-b8ab-a7b5b68773a4',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-solarium',
          'format' => NULL,
          'safe_value' => 'icon-solarium',
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
    'name' => 'Rue',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1331faa9-dbe1-4c1f-96cd-6c26a47f7abd',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'RUE',
          'format' => NULL,
          'safe_value' => 'RUE',
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
    'name' => 'Est Parisien (A3)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '182bbdf5-1622-4f0f-abc7-061650825ed4',
    'vocabulary_machine_name' => 'zone_activite',
    'field_id_zone_activite' => array(
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
    'name' => 'Quartier',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1b3e8c20-4673-4400-a661-6e984f48a9ca',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'QTR',
          'format' => NULL,
          'safe_value' => 'QTR',
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
    'name' => 'bis, Place',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1c223ad2-419d-4c1b-a492-a701d4243da3',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'PLB',
          'format' => NULL,
          'safe_value' => 'PLB',
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
    'name' => 'Hopitaux',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1c65ab25-d08e-4479-b32b-8337d0629025',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'name' => 'SM2I',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1dcc0274-f74c-436c-a722-6cf2e203cc4a',
    'vocabulary_machine_name' => 'marque_commercialisation',
    'field_id_marque_comm' => array(
      'und' => array(
        0 => array(
          'value' => 'SM2I',
          'format' => NULL,
          'safe_value' => 'SM2I',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Etage',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1e37446e-786a-40f7-86f6-57a9ea249178',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-4etage',
          'format' => NULL,
          'safe_value' => 'icon-4etage',
        ),
      ),
    ),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'name' => 'RT2012',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1fef5d14-23b5-4fa0-939a-9157229011b4',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-rt-2012',
          'format' => NULL,
          'safe_value' => 'icon-rt-2012',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Esplanade',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2069a27e-3932-4d67-b883-f4a9166324d1',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'ESP',
          'format' => NULL,
          'safe_value' => 'ESP',
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
    'name' => 'Etages',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2268174c-7b8b-467c-bade-d6d8811b03ca',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-4etage',
          'format' => NULL,
          'safe_value' => 'icon-4etage',
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
    'name' => 'Cergy - Pontoise (A15)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '241898f3-5914-4655-abbc-242cdb6d877e',
    'vocabulary_machine_name' => 'zone_activite',
    'field_id_zone_activite' => array(
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
    'name' => 'Rond-point',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '276d7b76-6396-4d1c-af66-baa74b08ffa7',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'RTE',
          'format' => NULL,
          'safe_value' => 'RTE',
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
    'field_id_file' => array(),
    'field_id_xls' => array(
      'und' => array(
        0 => array(
          'value' => 0,
          'format' => NULL,
          'safe_value' => 0,
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
    'field_id_file' => array(),
    'field_id_xls' => array(
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
    'name' => 'Salle de sports',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2af0167b-c83c-4603-9a75-51dc48cd76db',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-salle-sport',
          'format' => NULL,
          'safe_value' => 'icon-salle-sport',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Senart (A5)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2b0e7ea9-2270-4278-9144-9e7c75728510',
    'vocabulary_machine_name' => 'zone_activite',
    'field_id_zone_activite' => array(
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
    'name' => 'Boucle',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2eb333ad-9d30-4213-b570-c131241c07b3',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'BCL',
          'format' => NULL,
          'safe_value' => 'BCL',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Digicode & Interphone',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2fa02c23-b10b-493d-9c77-0665c4c17741',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-digicode-interphone',
          'format' => NULL,
          'safe_value' => 'icon-digicode-interphone',
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
    'weight' => 5,
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
    'name' => 'Réunions d\'information',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '32e0e9ef-e42e-4a56-b565-1ac6c37add6c',
    'vocabulary_machine_name' => 'type_de_document',
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
    'name' => 'Appartement',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '375f3578-f03b-455c-894a-2ad3891cdfba',
    'vocabulary_machine_name' => 'type_de_programme',
    'field_id_type_programme' => array(
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
    'name' => 'Cité',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '394ad147-55c9-46ba-aebc-c0c76edd5fe2',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'CTE',
          'format' => NULL,
          'safe_value' => 'CTE',
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
    'name' => 'Voie',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3efa52bd-f952-4c40-8961-35711b0aafbb',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'VOI',
          'format' => NULL,
          'safe_value' => 'VOI',
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
    'name' => 'Franche-Comté',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '41d8bb9b-54f3-469a-b1b9-4468c81c9052',
    'vocabulary_machine_name' => 'region',
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
    'name' => 'Climatisation',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '44835a21-8819-4cc1-b340-9e18a093e8ed',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-climatisation',
          'format' => NULL,
          'safe_value' => 'icon-climatisation',
        ),
      ),
    ),
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
    'name' => 'Chauffage',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '45b28b8a-b856-4bbe-86c1-342b2942872a',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-chauffage',
          'format' => NULL,
          'safe_value' => 'icon-chauffage',
        ),
      ),
    ),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
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
    'name' => 'Accès mobilité Réduite',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '4b6c894c-d185-45a6-aad8-1ab1aaf9f2f7',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(),
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
    'name' => 'Alsace',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4d6388c5-ecb4-4bb9-891f-34ed939b5ac8',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'ter, Rue',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4daee5c3-f596-4f20-8d19-8f1c3af4c5af',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'RUT',
          'format' => NULL,
          'safe_value' => 'RUT',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Présentations financières',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '4dda9e67-a196-48a5-b9f9-b70f98528abb',
    'vocabulary_machine_name' => 'type_de_document',
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
    'name' => 'Digicode & Vidéophone',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '500649de-89fc-4dd0-bf6e-7236fbb9ce36',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-digicode-videophone',
          'format' => NULL,
          'safe_value' => 'icon-digicode-videophone',
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
    'name' => 'Garage',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5148ccda-8c3b-4636-b9b3-fdfa0f97368b',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-garage',
          'format' => NULL,
          'safe_value' => 'icon-garage',
        ),
      ),
    ),
    'field_searchable' => array(),
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
    'name' => 'Boulevard',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '53006eb0-2544-4386-863d-ecc2a374f3fa',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'BLD',
          'format' => NULL,
          'safe_value' => 'BLD',
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
    'name' => 'Vallée de Seine (A6)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '54255144-fcba-4523-9f68-1761c198549b',
    'vocabulary_machine_name' => 'zone_activite',
    'field_id_zone_activite' => array(
      'und' => array(
        0 => array(
          'value' => 7,
          'format' => NULL,
          'safe_value' => 7,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'bis, Rue',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '547e7237-77a4-4fea-b797-81f9a945081f',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'RUB',
          'format' => NULL,
          'safe_value' => 'RUB',
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
    'name' => 'Rond-point',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '57bcf7df-5fa7-47c2-ad54-af4d44e3212d',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'RPO',
          'format' => NULL,
          'safe_value' => 'RPO',
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
    'name' => 'Rapports',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '5838ee3c-817b-44ea-a2a7-35437c5629d4',
    'vocabulary_machine_name' => 'type_de_document',
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
    'name' => 'Assemblée générale',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => '5ae4be86-b081-4861-b92e-0b2487e6f3bb',
    'vocabulary_machine_name' => 'type_de_document',
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
    'name' => 'Dernier étage',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5bcb4a56-fc94-46f2-ae83-085390b44107',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'name' => 'Breguet',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5c1cf8a0-2ec1-4246-886b-e75bbf71cad4',
    'vocabulary_machine_name' => 'marque_commercialisation',
    'field_id_marque_comm' => array(
      'und' => array(
        0 => array(
          'value' => 'BREG',
          'format' => NULL,
          'safe_value' => 'BREG',
        ),
      ),
    ),
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
    'name' => 'Ascenseur',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5d51c992-aaae-44ac-a276-0339c23ab874',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-ascenseur',
          'format' => NULL,
          'safe_value' => 'icon-ascenseur',
        ),
      ),
    ),
    'field_searchable' => array(),
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
    'name' => 'Promenade',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5f768bab-fdab-45d7-9cd8-c55ae797ac57',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'PRM',
          'format' => NULL,
          'safe_value' => 'PRM',
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
    'name' => 'BBC',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '63532d24-d9e5-4aa0-bbbc-3d828f1cecc2',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(),
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
    'name' => 'Piscine',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6570a97d-21b8-4964-96fd-149a8c5748c5',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-piscine',
          'format' => NULL,
          'safe_value' => 'icon-piscine',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Séfima',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6668a41d-3dd2-4bdf-b42b-e5c5ccb2d3bf',
    'vocabulary_machine_name' => 'marque_commercialisation',
    'field_id_marque_comm' => array(
      'und' => array(
        0 => array(
          'value' => 'SEFI',
          'format' => NULL,
          'safe_value' => 'SEFI',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Terrain',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '68c19579-dd07-4ee5-8e82-032b5a255338',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'weight' => 2,
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
    'name' => 'Malardeau',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6a771d1e-1a34-403a-8aa8-7cd20ee92685',
    'vocabulary_machine_name' => 'marque_commercialisation',
    'field_id_marque_comm' => array(
      'und' => array(
        0 => array(
          'value' => 'MALA',
          'format' => NULL,
          'safe_value' => 'MALA',
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
    'name' => 'Bourgogne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6c06d578-8854-41e1-bd22-fce6565ea461',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Résidence',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6c660e09-fd85-4279-bf8f-b7553475ab50',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'RSD',
          'format' => NULL,
          'safe_value' => 'RSD',
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
    'name' => 'Orientation',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '702e732c-8b2e-40ec-b75e-def4ad7bae37',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-sud-sud-est',
          'format' => NULL,
          'safe_value' => 'icon-sud-sud-est',
        ),
      ),
    ),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'name' => 'Ascenseur',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '73617819-6bfa-471e-8c43-0e727c94071a',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-ascenseur',
          'format' => NULL,
          'safe_value' => 'icon-ascenseur',
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
    'name' => 'Documents aux actionnaires',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '74fb33a5-b8f0-4f27-8286-97fce348e71d',
    'vocabulary_machine_name' => 'type_de_document',
  );
  $terms[] = array(
    'name' => 'St Quentin en Yvelines (N118 – A12)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '74fbd30f-1d13-4571-b205-7d46b1274578',
    'vocabulary_machine_name' => 'zone_activite',
    'field_id_zone_activite' => array(
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
    'name' => 'Vigik',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '751aa427-a36c-4dba-a2fb-2ca8ea6bc999',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-vigik',
          'format' => NULL,
          'safe_value' => 'icon-vigik',
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
    'name' => 'TVA 7%',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7a064e09-fa16-4bc1-981a-d5e4f0e92c2e',
    'vocabulary_machine_name' => 'tva',
    'field_facteur' => array(
      'und' => array(
        0 => array(
          'value' => 0.07,
          'format' => NULL,
          'safe_value' => 0.07,
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
    'name' => 'Groupe Avantis',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '81b0edaf-ff70-42da-9453-46fabfce5a94',
    'vocabulary_machine_name' => 'marque_commercialisation',
    'field_id_marque_comm' => array(
      'und' => array(
        0 => array(
          'value' => 'AVAN',
          'format' => NULL,
          'safe_value' => 'AVAN',
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
    'name' => 'Local-activité',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
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
    'name' => 'Île-de-France',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '83c72ca9-5e9e-4a04-9d24-325a0de8700f',
    'vocabulary_machine_name' => 'region',
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
    'name' => 'SMCI',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '85a702fc-fa0a-4a0a-9033-e6ea7fc6577a',
    'vocabulary_machine_name' => 'marque_commercialisation',
    'field_id_marque_comm' => array(
      'und' => array(
        0 => array(
          'value' => 'SMCI',
          'format' => NULL,
          'safe_value' => 'SMCI',
        ),
      ),
    ),
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
    'name' => 'Chauffage',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '894facd5-86d9-49fc-b497-1ebfbb20e5f9',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-chauffage',
          'format' => NULL,
          'safe_value' => 'icon-chauffage',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Bati Service',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8a589dc3-c305-4b4d-af15-d654e4541730',
    'vocabulary_machine_name' => 'marque_commercialisation',
    'field_id_marque_comm' => array(
      'und' => array(
        0 => array(
          'value' => 'BATI',
          'format' => NULL,
          'safe_value' => 'BATI',
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
    'name' => 'Domotique',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8b393649-e9fe-499d-b834-ee6c73ef241a',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-domotique',
          'format' => NULL,
          'safe_value' => 'icon-domotique',
        ),
      ),
    ),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'field_id_file' => array(
      'und' => array(
        0 => array(
          'value' => 'L',
          'format' => NULL,
          'safe_value' => 'L',
        ),
      ),
    ),
    'field_id_xls' => array(
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
    'name' => 'Midi-Pyrénées',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8f7a4318-f820-4d97-81b3-75960f9a8ca3',
    'vocabulary_machine_name' => 'region',
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
    'name' => 'Parkings',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9145d5c1-f37d-4f29-a02a-0ea53995f267',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-parking',
          'format' => NULL,
          'safe_value' => 'icon-parking',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Square',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '91fe069e-9f03-4e9c-ad24-ecb7bea67e2f',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'SQU',
          'format' => NULL,
          'safe_value' => 'SQU',
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
    'name' => 'Cour',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9c137eba-7ce0-4fa8-9d44-5451d21df765',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'COU',
          'format' => NULL,
          'safe_value' => 'COU',
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
    'name' => 'Sente',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9df0ee89-226b-4475-9635-dfdf67f10276',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'SEN',
          'format' => NULL,
          'safe_value' => 'SEN',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Maison',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
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
    'uuid' => 'a0a2ea9e-c580-4651-a52a-36a8bbd5be8d',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'PKG',
          'format' => NULL,
          'safe_value' => 'PKG',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Parking',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a1e14c18-39e8-425a-9ed2-96071bed666c',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-parking',
          'format' => NULL,
          'safe_value' => 'icon-parking',
        ),
      ),
    ),
    'field_searchable' => array(),
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
    'name' => 'Commerce',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
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
    'name' => 'Box',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a588ded9-efb2-4dc6-8480-e51eb868d45e',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-box',
          'format' => NULL,
          'safe_value' => 'icon-box',
        ),
      ),
    ),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'name' => 'Garonor – Aéroport Charles de Gaulle (A1)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'aac28985-1798-4e1d-8ae6-095f89fd0600',
    'vocabulary_machine_name' => 'zone_activite',
    'field_id_zone_activite' => array(
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
    'name' => 'Place',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ac9ed056-7672-4a7e-9f38-7039a092e1a4',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'PLA',
          'format' => NULL,
          'safe_value' => 'PLA',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Franck Arthur Promotion',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'aceca57b-df0d-4fd1-afbc-f879cc98b985',
    'vocabulary_machine_name' => 'marque_commercialisation',
    'field_id_marque_comm' => array(
      'und' => array(
        0 => array(
          'value' => 'FAPR',
          'format' => NULL,
          'safe_value' => 'FAPR',
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
    'name' => 'Conciergerie',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'af1e18f7-4a88-463f-930a-d7c45d4a6a34',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-conciergerie',
          'format' => NULL,
          'safe_value' => 'icon-conciergerie',
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
    'name' => 'Ecoles',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'af354588-f627-435e-844d-98e82e6701dd',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'name' => 'Electrique',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b0b92d95-a738-4830-b110-5fafa8eefafa',
    'vocabulary_machine_name' => 'chauffage',
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
    'name' => 'Maisons et appartements',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b16e053a-18c5-409c-bc98-e6bb7678d046',
    'vocabulary_machine_name' => 'type_de_programme',
    'field_id_type_programme' => array(
      'und' => array(
        0 => array(
          'value' => 'MI',
          'format' => NULL,
          'safe_value' => 'MI',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Idéal Résidence Secondaire',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b1b86290-d5ca-4201-896a-de3b5e95b07a',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-residence-secondaire',
          'format' => NULL,
          'safe_value' => 'icon-residence-secondaire',
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
    'name' => 'Sopra Promotion',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b3ff5d64-9bb2-4aae-bbaf-a3853e89c10e',
    'vocabulary_machine_name' => 'marque_commercialisation',
    'field_id_marque_comm' => array(
      'und' => array(
        0 => array(
          'value' => 'SOPR',
          'format' => NULL,
          'safe_value' => 'SOPR',
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
    'name' => 'Première',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b48f257f-ce5f-4609-ad2f-5b4fa9a7a9e5',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'PRA',
          'format' => NULL,
          'safe_value' => 'PRA',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Avenue',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b5b61d6d-2e27-46f8-95b6-6f90eb0c3a4b',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'AVE',
          'format' => NULL,
          'safe_value' => 'AVE',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Jardin Privatif',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b62972cd-cf80-45bb-9f1c-eadb9147c7b1',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-jardin-privatif',
          'format' => NULL,
          'safe_value' => 'icon-jardin-privatif',
        ),
      ),
    ),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'name' => 'Marne la Vallée (A4)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b82a56b6-79fc-45ce-a077-97f6547468b9',
    'vocabulary_machine_name' => 'zone_activite',
    'field_id_zone_activite' => array(
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
    'name' => 'Jardin paysager',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bc20cf15-e074-44ad-a408-c95c09c82234',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-jardin-paysager',
          'format' => NULL,
          'safe_value' => 'icon-jardin-paysager',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Duplex',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bc20f6fa-6ccf-4042-a450-69182e7a10c3',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-duplex',
          'format' => NULL,
          'safe_value' => 'icon-duplex',
        ),
      ),
    ),
    'field_searchable' => array(),
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
    'name' => 'Communiqué de presse',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bddbac61-26b7-452d-ae2a-8842e7781976',
    'vocabulary_machine_name' => 'type_de_document',
  );
  $terms[] = array(
    'name' => 'Domotique',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'be7c13c9-1332-4949-bcea-13638577d6f3',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-domotique',
          'format' => NULL,
          'safe_value' => 'icon-domotique',
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
    'name' => 'Assemblée Générale Extraordinaire',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => 'c27fed84-5f08-4d6e-8f6c-fc78d9319bff',
    'vocabulary_machine_name' => 'type_de_document',
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
    'name' => 'Kaufman & Broad',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c3de611d-a132-4922-ac5a-cb421e6994f7',
    'vocabulary_machine_name' => 'marque_commercialisation',
    'field_id_marque_comm' => array(
      'und' => array(
        0 => array(
          'value' => 'KETB',
          'format' => NULL,
          'safe_value' => 'KETB',
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
    'name' => 'ZAC',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c4b8a9ec-431f-47cf-8e55-71f66b10898d',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'ZAC',
          'format' => NULL,
          'safe_value' => 'ZAC',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Mail',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c743b5ac-ad0a-47b0-9753-8e7d81d118ea',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'MAL',
          'format' => NULL,
          'safe_value' => 'MAL',
        ),
      ),
    ),
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
    'name' => 'Terrasse',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'ce124ec1-4ade-4f49-9438-f47e8ab85e86',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'name' => 'Commerces',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ce6f6fa8-9ab1-4bfb-b6d2-b627bf110818',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(),
    'field_searchable' => array(),
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
    'name' => 'Pack silver',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cf282100-b22e-4713-ac40-d864806d4895',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-pack-silver',
          'format' => NULL,
          'safe_value' => 'icon-pack-silver',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Ter, Première',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cf553b87-c096-4ef5-8d36-bd0973b141f8',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'PRT',
          'format' => NULL,
          'safe_value' => 'PRT',
        ),
      ),
    ),
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
    'name' => 'Bretagne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd195a755-0e85-4200-8ee4-fb1d9d94b6da',
    'vocabulary_machine_name' => 'region',
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
    'name' => 'Lieu-dit',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd26bbc03-0b21-481d-81a4-3992f22d2622',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'LIE',
          'format' => NULL,
          'safe_value' => 'LIE',
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
    'name' => 'Passage',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd2f20cd1-5bf6-42e8-9629-0acb5e748303',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'PAS',
          'format' => NULL,
          'safe_value' => 'PAS',
        ),
      ),
    ),
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
    'name' => 'Impasse',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd710126a-0f15-4c62-bd38-5d1e8dea895b',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'IMP',
          'format' => NULL,
          'safe_value' => 'IMP',
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
    'name' => 'Corse',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd9847079-bf25-41d1-b303-1692142edb5c',
    'vocabulary_machine_name' => 'region',
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
    'name' => 'Patrimoine Compagnie',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd9dc895b-21bf-4353-b38d-211adc81c067',
    'vocabulary_machine_name' => 'marque_commercialisation',
    'field_id_marque_comm' => array(
      'und' => array(
        0 => array(
          'value' => 'PATR',
          'format' => NULL,
          'safe_value' => 'PATR',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Maison Individuelle',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'db7212df-0ccf-4f57-985c-156c1181338b',
    'vocabulary_machine_name' => 'type_de_programme',
    'field_id_type_programme' => array(
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
    'name' => 'Park Promotion',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'dde7e372-b3c3-49ad-848e-dda77f70a220',
    'vocabulary_machine_name' => 'marque_commercialisation',
    'field_id_marque_comm' => array(
      'und' => array(
        0 => array(
          'value' => 'PARK',
          'format' => NULL,
          'safe_value' => 'PARK',
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
    'name' => 'Collectif',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'de70bfb8-a2ca-4d1b-838b-eed7b63c6b09',
    'vocabulary_machine_name' => 'chauffage',
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
    'name' => 'Auvergne',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e0850f4c-8001-4a5c-a4b1-434e0fe8a7b9',
    'vocabulary_machine_name' => 'region',
  );
  $terms[] = array(
    'name' => 'Chemin',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e11d0bf0-5d87-4d21-86fb-0e16c4f3ad26',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'CHE',
          'format' => NULL,
          'safe_value' => 'CHE',
        ),
      ),
    ),
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
    'name' => 'Cave',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e26166cf-8cc7-4771-8c94-56292a4bd8c4',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-cave',
          'format' => NULL,
          'safe_value' => 'icon-cave',
        ),
      ),
    ),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'name' => 'Quai',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e3ce50c7-e270-4164-9465-476aaca16e02',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'QU',
          'format' => NULL,
          'safe_value' => 'QU',
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
    'name' => 'Autres Informations réglementée',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e5e9e415-fdba-4a69-a1f5-316036b90260',
    'vocabulary_machine_name' => 'type_de_document',
  );
  $terms[] = array(
    'name' => 'Loggia',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e61278ee-6645-4e1f-bd0b-3702d5362b17',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-loggia',
          'format' => NULL,
          'safe_value' => 'icon-loggia',
        ),
      ),
    ),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'name' => 'Gardien',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e8b49f7a-3738-41b5-a548-294da4589e5b',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-gardien',
          'format' => NULL,
          'safe_value' => 'icon-gardien',
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
    'name' => 'Idéal résidence secondaire',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e8fdacde-4af8-40fb-909c-111d62eea41a',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-residence-secondaire',
          'format' => NULL,
          'safe_value' => 'icon-residence-secondaire',
        ),
      ),
    ),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
    'name' => 'Information légale',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'ec06a6f2-b0bd-4c91-b91d-91d45498f1c6',
    'vocabulary_machine_name' => 'type_de_document',
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
    'name' => 'Bis, Première',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ecc9178a-c201-4d4f-81fe-32485a7e5a55',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'PRB',
          'format' => NULL,
          'safe_value' => 'PRB',
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
    'name' => 'Nord-Pas-de-Calais',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'efef5001-c9bf-4bce-9a08-4dece3b35b92',
    'vocabulary_machine_name' => 'region',
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
    'name' => 'Gaz',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fb3f939f-2fec-4665-9d79-e96d4934f7dd',
    'vocabulary_machine_name' => 'chauffage',
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
    'name' => 'Allée',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fb4e2556-20dd-4dd9-b60b-e0783af2fd9b',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'ALL',
          'format' => NULL,
          'safe_value' => 'ALL',
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
    'name' => 'Sentier',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fc09ca3b-476b-45c9-94cc-d032e0c99e05',
    'vocabulary_machine_name' => 'type_voie',
    'field_id_type_voie' => array(
      'und' => array(
        0 => array(
          'value' => 'SNT',
          'format' => NULL,
          'safe_value' => 'SNT',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Résidence Bernard Teillaud',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fc3c1d8f-0b36-4720-bf02-aac92fd4cdc1',
    'vocabulary_machine_name' => 'marque_commercialisation',
    'field_id_marque_comm' => array(
      'und' => array(
        0 => array(
          'value' => 'RBTG',
          'format' => NULL,
          'safe_value' => 'RBTG',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Balcon',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fc53ec7e-9b0c-4720-8f10-e4436a6bf4a9',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-balcon',
          'format' => NULL,
          'safe_value' => 'icon-balcon',
        ),
      ),
    ),
    'field_searchable' => array(),
  );
  $terms[] = array(
    'name' => 'Local Vélo',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fc659986-8639-4600-97a6-90e44001ce9a',
    'vocabulary_machine_name' => 'caracteristiques_programme',
    'field_picto_css_class' => array(
      'und' => array(
        0 => array(
          'value' => 'icon-local-velo',
          'format' => NULL,
          'safe_value' => 'icon-local-velo',
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
  $terms[] = array(
    'name' => 'Accès mobilité réduite',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fdc23854-6ea5-4860-a58d-57d35aff1c25',
    'vocabulary_machine_name' => 'caracteristiques',
    'field_icon_name' => array(),
    'field_searchable' => array(
      'und' => array(
        0 => array(
          'value' => 0,
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
