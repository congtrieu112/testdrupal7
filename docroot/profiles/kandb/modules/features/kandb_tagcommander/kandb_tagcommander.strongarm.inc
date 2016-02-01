<?php
/**
 * @file
 * kandb_tagcommander.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kandb_tagcommander_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tagcommander_account_login';
  $strongarm->value = 'gregory.montigny@digitaslbi.fr';
  $export['tagcommander_account_login'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tagcommander_account_password';
  $strongarm->value = 'a0538d0e1065f1476de27ac0f1827dd9';
  $export['tagcommander_account_password'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tagcommander_containers';
  $strongarm->value = array(
    0 => (object) array(
      'id' => 3,
      'name' => 'Haut de page',
      'url' => 'http://cdn.tagcommander.com/1642/tc_KaufmanandBroad_1.js',
      'position' => '1',
    ),
  );
  $export['tagcommander_containers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tagcommander_externals_variables';
  $strongarm->value = array(
    0 => array(
      'id_external' => 1,
      'label' => 'tc_vars["env_template"]',
      'description' => 'Nom du template
',
      'description_detailed' => '',
      'value' => 'env_template',
      'default' => '',
    ),
    1 => array(
      'id_external' => 3,
      'label' => 'tc_vars["env_language"]',
      'description' => 'Langue pays
',
      'description_detailed' => '',
      'value' => 'env_language',
      'default' => '',
    ),
    2 => array(
      'id_external' => 5,
      'label' => 'tc_vars["env_country"]',
      'description' => 'Pays
',
      'description_detailed' => '',
      'value' => 'env_country',
      'default' => '',
    ),
    3 => array(
      'id_external' => 7,
      'label' => 'tc_vars["env_site"]',
      'description' => 'Nom du site
',
      'description_detailed' => '',
      'value' => 'env_site',
      'default' => '',
    ),
    4 => array(
      'id_external' => 9,
      'label' => 'tc_vars["env_channel"]',
      'description' => 'Channel
',
      'description_detailed' => 'web, mobile',
      'value' => 'env_channel',
      'default' => '',
    ),
    5 => array(
      'id_external' => 11,
      'label' => 'tc_vars["env_work"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'env_work',
      'default' => '',
    ),
    6 => array(
      'id_external' => 57,
      'label' => 'tc_vars["user_agent"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'user_agent',
      'default' => '',
    ),
    7 => array(
      'id_external' => 13,
      'label' => 'tc_vars["user_id"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'user_id',
      'default' => '',
    ),
    8 => array(
      'id_external' => 15,
      'label' => 'tc_vars["user_logged"]',
      'description' => 'Visiteur logÃ© ou non
',
      'description_detailed' => '',
      'value' => 'user_logged',
      'default' => '',
    ),
    9 => array(
      'id_external' => 17,
      'label' => 'tc_vars["user_surname"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'user_surname',
      'default' => '',
    ),
    10 => array(
      'id_external' => 19,
      'label' => 'tc_vars["user_lastname"]',
      'description' => 'Nom utilisateur
',
      'description_detailed' => '',
      'value' => 'user_lastname',
      'default' => '',
    ),
    11 => array(
      'id_external' => 21,
      'label' => 'tc_vars["user_postalcode"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'user_postalcode',
      'default' => '',
    ),
    12 => array(
      'id_external' => 23,
      'label' => 'tc_vars["user_email"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'user_email',
      'default' => '',
    ),
    13 => array(
      'id_external' => 25,
      'label' => 'tc_vars["user_newsletter"]',
      'description' => 'Newsletter
',
      'description_detailed' => '',
      'value' => 'user_newsletter',
      'default' => '',
    ),
    14 => array(
      'id_external' => 53,
      'label' => 'tc_vars["user_address"]',
      'description' => 'Address
',
      'description_detailed' => '',
      'value' => 'user_address',
      'default' => '',
    ),
    15 => array(
      'id_external' => 55,
      'label' => 'tc_vars["user_city"]',
      'description' => 'City
',
      'description_detailed' => '',
      'value' => 'user_city',
      'default' => '',
    ),
    16 => array(
      'id_external' => 125,
      'label' => 'tc_vars["user_type"]',
      'description' => 'Type de client (Profiling)',
      'description_detailed' => '',
      'value' => 'user_type',
      'default' => '',
    ),
    17 => array(
      'id_external' => 127,
      'label' => 'tc_vars["user_category"]',
      'description' => 'user category',
      'description_detailed' => '',
      'value' => 'user_category',
      'default' => '',
    ),
    18 => array(
      'id_external' => 27,
      'label' => 'tc_vars["page_cat1"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'page_cat1',
      'default' => '',
    ),
    19 => array(
      'id_external' => 29,
      'label' => 'tc_vars["page_cat2"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'page_cat2',
      'default' => '',
    ),
    20 => array(
      'id_external' => 31,
      'label' => 'tc_vars["page_cat3"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'page_cat3',
      'default' => '',
    ),
    21 => array(
      'id_external' => 33,
      'label' => 'tc_vars["page_name"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'page_name',
      'default' => '',
    ),
    22 => array(
      'id_external' => 35,
      'label' => 'tc_vars["conversion_type"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'conversion_type',
      'default' => '',
    ),
    23 => array(
      'id_external' => 37,
      'label' => 'tc_vars["conversion_id"]',
      'description' => 'ID de dossier
',
      'description_detailed' => '',
      'value' => 'conversion_id',
      'default' => '',
    ),
    24 => array(
      'id_external' => 159,
      'label' => 'tc_vars["type_bloc"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'type_bloc',
      'default' => '',
    ),
    25 => array(
      'id_external' => 161,
      'label' => 'tc_vars["agence_associee"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'agence_associe',
      'default' => '',
    ),
    26 => array(
      'id_external' => 39,
      'label' => 'tc_vars["programme_list"]',
      'description' => 'Array details (1 bloc = 1 separate product):
tc_vars["programme_list"][0] = new Array();
tc_vars["programme_list"][0]["product_programme_list_id"] = \'\';
tc_vars["programme_list"][0]["product_programme_list_type"] = \'\';
tc_vars["programme_list"][0]["product_programme_name"] = \'\';

',
      'description_detailed' => '',
      'value' => 'programme_list',
      'default' => '',
    ),
    27 => array(
      'id_external' => 41,
      'label' => 'tc_vars["search_request"]',
      'description' => 'Requete cherchÃ©e
',
      'description_detailed' => '',
      'value' => 'search_request',
      'default' => '',
    ),
    28 => array(
      'id_external' => 43,
      'label' => 'tc_vars["search_results_number"]',
      'description' => 'search_nb_results
',
      'description_detailed' => '',
      'value' => 'search_results_number',
      'default' => '',
    ),
    29 => array(
      'id_external' => 45,
      'label' => 'tc_vars["search_results_affichage"]',
      'description' => 'search_vue-affichage
',
      'description_detailed' => '',
      'value' => 'search_results_affichage',
      'default' => '',
    ),
    30 => array(
      'id_external' => 129,
      'label' => 'tc_vars["availability"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'availability',
      'default' => '',
    ),
    31 => array(
      'id_external' => 131,
      'label' => 'tc_vars["price_range"]',
      'description' => 'search price range ',
      'description_detailed' => '',
      'value' => 'price_range',
      'default' => '',
    ),
    32 => array(
      'id_external' => 133,
      'label' => 'tc_vars["number_room"]',
      'description' => 'number room',
      'description_detailed' => '',
      'value' => 'number_room',
      'default' => '',
    ),
    33 => array(
      'id_external' => 135,
      'label' => 'tc_vars["surface"]',
      'description' => 'surface',
      'description_detailed' => '',
      'value' => 'surface',
      'default' => '',
    ),
    34 => array(
      'id_external' => 137,
      'label' => 'tc_vars["option"]',
      'description' => 'option',
      'description_detailed' => '',
      'value' => 'option',
      'default' => '',
    ),
    35 => array(
      'id_external' => 139,
      'label' => 'tc_vars["pinel_law"]',
      'description' => 'Loi Pinel',
      'description_detailed' => '',
      'value' => 'pinel_law',
      'default' => '',
    ),
    36 => array(
      'id_external' => 141,
      'label' => 'tc_vars["accessibility"]',
      'description' => 'accessibilitÃ©',
      'description_detailed' => '',
      'value' => 'accessibility',
      'default' => '',
    ),
    37 => array(
      'id_external' => 47,
      'label' => 'tc_vars["programme_id"]',
      'description' => 'ID du programme
',
      'description_detailed' => '',
      'value' => 'programme_id',
      'default' => '',
    ),
    38 => array(
      'id_external' => 49,
      'label' => 'tc_vars["programme_name"]',
      'description' => 'Nom du programme
',
      'description_detailed' => '',
      'value' => 'programme_name',
      'default' => '',
    ),
    39 => array(
      'id_external' => 51,
      'label' => 'tc_vars["url_page"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'url_page',
      'default' => '',
    ),
    40 => array(
      'id_external' => 143,
      'label' => 'tc_vars["programme_region"]',
      'description' => 'Region programme',
      'description_detailed' => '',
      'value' => 'programme_region',
      'default' => '',
    ),
    41 => array(
      'id_external' => 145,
      'label' => 'tc_vars["programme_departement"]',
      'description' => 'Departement programme',
      'description_detailed' => '',
      'value' => 'programme_departement',
      'default' => '',
    ),
    42 => array(
      'id_external' => 147,
      'label' => 'tc_vars["programme_city"]',
      'description' => 'Ville Programme',
      'description_detailed' => '',
      'value' => 'programme_city',
      'default' => '',
    ),
    43 => array(
      'id_external' => 163,
      'label' => 'tc_vars["programme_type"]',
      'description' => '',
      'description_detailed' => '',
      'value' => 'programme_type',
      'default' => '',
    ),
    44 => array(
      'id_external' => 149,
      'label' => 'tc_vars["property_type"]',
      'description' => 'Type de bien',
      'description_detailed' => '',
      'value' => 'property_type',
      'default' => '',
    ),
    45 => array(
      'id_external' => 151,
      'label' => 'tc_vars["property_name"]',
      'description' => 'Nom du bien',
      'description_detailed' => '',
      'value' => 'property_name',
      'default' => '',
    ),
    46 => array(
      'id_external' => 153,
      'label' => 'tc_vars["site_niveau_1"]',
      'description' => 'site de niveau 1',
      'description_detailed' => '',
      'value' => 'site_niveau_1',
      'default' => '',
    ),
    47 => array(
      'id_external' => 155,
      'label' => 'tc_vars["site_niveau_2"]',
      'description' => 'site de niveau 2',
      'description_detailed' => '',
      'value' => 'site_niveau_2',
      'default' => '',
    ),
    48 => array(
      'id_external' => 157,
      'label' => 'tc_vars["xt_page"]',
      'description' => 'xt page',
      'description_detailed' => '',
      'value' => 'xt_page',
      'default' => '',
    ),
  );
  $export['tagcommander_externals_variables'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tagcommander_website_id';
  $strongarm->value = '1642';
  $export['tagcommander_website_id'] = $strongarm;

  return $export;
}
