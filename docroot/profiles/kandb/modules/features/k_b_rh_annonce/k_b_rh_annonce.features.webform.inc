<?php
/**
 * @file
 * k_b_rh_annonce.features.webform.inc
 */

/**
 * Implements hook_webform_defaults().
 */
function k_b_rh_annonce_webform_defaults() {
$webforms = array();
  $webforms['candidature'] = array(
  'title' => 'Candidature',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '3611b72f-513f-4748-88de-f35c147508e6',
  'type' => 'webform',
  'language' => 'en',
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'c6106028-928d-4fb4-9b16-a1b5b8800074',
  'webform' => array(
    'next_serial' => 2,
    'confirmation' => 'Merci, votre soumission a été reçue',
    'confirmation_format' => 'plain_text',
    'redirect_url' => '<none>',
    'status' => 1,
    'block' => 0,
    'allow_draft' => 0,
    'auto_save' => 0,
    'submit_notice' => 0,
    'confidential' => 0,
    'submit_text' => '',
    'submit_limit' => -1,
    'submit_interval' => -1,
    'total_submit_limit' => -1,
    'total_submit_interval' => -1,
    'progressbar_bar' => 1,
    'progressbar_page_number' => 0,
    'progressbar_percent' => 0,
    'progressbar_pagebreak_labels' => 1,
    'progressbar_include_confirmation' => 1,
    'progressbar_label_first' => 'Start',
    'progressbar_label_confirmation' => 'Complete',
    'preview' => 0,
    'preview_next_button_label' => '',
    'preview_prev_button_label' => '',
    'preview_title' => '',
    'preview_message' => '',
    'preview_message_format' => 'plain_text',
    'preview_excluded_components' => array(),
    'machine_name' => 'candidature',
    'webform_ajax' => 1,
    'record_exists' => TRUE,
    'roles' => array(
      0 => 1,
      1 => 2,
    ),
    'emails' => array(),
    'components' => array(
      'prendre_rendez_vous__rdv_idkl' => array(
        'form_key' => 'row1',
        'name' => 'Row1',
        'type' => 'fieldset',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'css_classes' => '',
          'collapsible' => 0,
          'collapsed' => 0,
          'description' => '',
        ),
        'required' => 0,
        'weight' => 14,
        'machine_name' => 'prendre_rendez_vous__rdv_idkl',
        'page_num' => 1,
      ),
      'telechargement_documents__row_1' => array(
        'form_key' => 'vous_souhaitez_postuler_a_un_post_de',
        'name' => 'Vous souhaitez postuler à un post de',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'title_display' => 'before',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => 0,
          'description' => '',
          'placeholder' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 0,
        'weight' => 15,
        'machine_name' => 'telechargement_documents__row_1',
        'page_num' => 1,
        'parent_machine_name' => 'prendre_rendez_vous__rdv_idkl',
      ),
      'prendre_rendez_vous__rdv_type_contact' => array(
        'form_key' => 'row2',
        'name' => 'Row2',
        'type' => 'fieldset',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'css_classes' => 'row row--noGutter medium-uncollapse small-collapse',
          'collapsible' => 0,
          'collapsed' => 0,
          'description' => '',
        ),
        'required' => 0,
        'weight' => 16,
        'machine_name' => 'prendre_rendez_vous__rdv_type_contact',
        'page_num' => 1,
      ),
      'prendre_rendez_vous__rdv_prenom' => array(
        'form_key' => 'nom',
        'name' => 'Nom',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'title_display' => 'before',
          'private' => 0,
          'wrapper_classes' => 'webform-component webform-component-textfield small-12 medium-6 columns',
          'css_classes' => '',
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => 0,
          'description' => '',
          'placeholder' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 1,
        'weight' => 17,
        'machine_name' => 'prendre_rendez_vous__rdv_prenom',
        'page_num' => 1,
        'parent_machine_name' => 'prendre_rendez_vous__rdv_type_contact',
      ),
      'prendre_rendez_vous__rdv_adresse1' => array(
        'form_key' => 'prenom',
        'name' => 'Prénom',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'title_display' => 'before',
          'private' => 0,
          'wrapper_classes' => 'webform-component webform-component-textfield small-12 medium-6 columns',
          'css_classes' => '',
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => 0,
          'description' => '',
          'placeholder' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 1,
        'weight' => 18,
        'machine_name' => 'prendre_rendez_vous__rdv_adresse1',
        'page_num' => 1,
        'parent_machine_name' => 'prendre_rendez_vous__rdv_type_contact',
      ),
      'prendre_rendez_vous__ville_prog' => array(
        'form_key' => 'row4',
        'name' => 'Row4',
        'type' => 'fieldset',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'css_classes' => 'row row--noGutter medium-uncollapse small-collapse',
          'collapsible' => 0,
          'collapsed' => 0,
          'description' => '',
        ),
        'required' => 0,
        'weight' => 22,
        'machine_name' => 'prendre_rendez_vous__ville_prog',
        'page_num' => 1,
      ),
      'prendre_rendez_vous__dept_prog' => array(
        'form_key' => 'row5',
        'name' => 'Row5',
        'type' => 'fieldset',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'css_classes' => 'row row--noGutter medium-uncollapse small-collapse',
          'collapsible' => 0,
          'collapsed' => 0,
          'description' => '',
        ),
        'required' => 0,
        'weight' => 25,
        'machine_name' => 'prendre_rendez_vous__dept_prog',
        'page_num' => 1,
      ),
      '_tre_rappel___type_de_contact' => array(
        'form_key' => 'code_postal',
        'name' => 'Code Postal',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'title_display' => 'before',
          'private' => 0,
          'wrapper_classes' => 'webform-component webform-component-textfield small-12 medium-6 columns',
          'css_classes' => '',
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => 0,
          'description' => '',
          'placeholder' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 1,
        'weight' => 26,
        'machine_name' => '_tre_rappel___type_de_contact',
        'page_num' => 1,
        'parent_machine_name' => 'prendre_rendez_vous__dept_prog',
      ),
      '_tre_rappel___rdv_idkp' => array(
        'form_key' => 'pays',
        'name' => 'Pays',
        'type' => 'select',
        'value' => '',
        'extra' => array(
          'items' => 'Afghanistan|Afghanistan
Afrique_du_Sud|Afrique du Sud
Albanie|Albanie
Algérie|Algérie
Allemagne|Allemagne
Andorre|Andorre
Arabie_saoudite|Arabie saoudite
Argentine|Argentine
Arménie|Arménie
Australie|Australie
Autriche|Autriche
Azerbaïdjan|Azerbaïdjan
Bahamas|Bahamas
Bahreïn|Bahreïn
Bangladesh|Bangladesh
Barbade|Barbade
Belgique|Belgique
Belize|Belize
Bénin|Bénin
Biélorussie|Biélorussie
Birmanie|Birmanie
Bolivie|Bolivie
Bosnie-Herzégovine|Bosnie-Herzégovine
Botswana|Botswana
Brésil|Brésil
Bulgarie|Bulgarie
Burkina_Faso|Burkina Faso
Burundi|Burundi
Cambodge|Cambodge
Cameroun|Cameroun
Canada|Canada
Centrafrique|Centrafrique
Chili|Chili
Chine|Chine
Chypre|Chypre
Colombie|Colombie
Comores|Comores
Corée_du_Nord|Corée du Nord
Corée_du_Sud|Corée du Sud
Costa_Rica|Costa Rica
Côte_d_Ivoire|Côte d\'Ivoire
Croatie|Croatie
Cuba|Cuba
Danemark|Danemark
Djibouti|Djibouti
Égypte|Égypte
Émirats_arabes_unis|Émirats arabes unis
Équateur|Équateur
Érythrée|Érythrée
Espagne|Espagne
Estonie|Estonie
États-Unis|États-Unis
Éthiopie|Éthiopie
Fidji|Fidji
Finlande|Finlande
France|France
Gabon|Gabon
Gambie|Gambie
Géorgie|Géorgie
Ghana|Ghana
Grèce|Grèce
Guatemala|Guatemala
Guinée|Guinée
Guinée_équatoriale|Guinée équatoriale
Guinée-Bissau|Guinée-Bissau
Guyana|Guyana
Haïti|Haïti
Honduras|Honduras
Hongrie|Hongrie
Inde|Inde
Indonésie|Indonésie
Irak|Irak
Iran|Iran
Irlande|Irlande
Islande|Islande
Italie|Italie
Jamaïque|Jamaïque
Japon|Japon
Jordanie|Jordanie
Kazakhstan|Kazakhstan
Kenya|Kenya
Kirghizistan|Kirghizistan
Koweït|Koweït
Laos|Laos
Lettonie|Lettonie
Liban|Liban
Libéria|Libéria
Libye|Libye
Liechtenstein|Liechtenstein
Lituanie|Lituanie
Luxembourg|Luxembourg
Macédoine|Macédoine
Madagascar|Madagascar
Malaisie|Malaisie
Malawi|Malawi
Maldives|Maldives
Mali|Mali
Malte|Malte
Maroc|Maroc
Mauritanie|Mauritanie
Mexique|Mexique
Moldavie|Moldavie
Monaco|Monaco
Mongolie|Mongolie
Monténégro|Monténégro
Mozambique|Mozambique
Népal|Népal
Nicaragua|Nicaragua
Niger|Niger
Nigeria|Nigeria
Norvège|Norvège
Nouvelle-Zélande|Nouvelle-Zélande
Oman|Oman
Ouganda|Ouganda
Ouzbékistan|Ouzbékistan
Pakistan|Pakistan
Panama|Panama
Papouasie-Nouvelle-Guinée|Papouasie-Nouvelle-Guinée
Paraguay|Paraguay
Pays-Bas|Pays-Bas
Pérou|Pérou
Philippines|Philippines
Pologne|Pologne
Portugal|Portugal
Qatar|Qatar
République_démocratique_du_Congo|République démocratique du Congo
République_dominicaine|République dominicaine
République_tchèque|République tchèque
Roumanie|Roumanie
Royaume-Uni|Royaume-Uni
Russie|Russie
Rwanda|Rwanda
Salvador|Salvador
Samoa|Samoa
Sao_Tomé-et-Principe|Sao Tomé-et-Principe
Sénégal|Sénégal
Serbie|Serbie
Seychelles|Seychelles
Sierra_Leone|Sierra Leone
Singapour|Singapour
Slovaquie|Slovaquie
Slovénie|Slovénie
Somalie|Somalie
Soudan|Soudan
Sri_Lanka|Sri Lanka
Suède|Suède
Suisse|Suisse
Suriname|Suriname
Swaziland|Swaziland
Syrie|Syrie
Tadjikistan|Tadjikistan
Tanzanie|Tanzanie
Tchad|Tchad
Thaïlande|Thaïlande
Tibet|Tibet
Togo|Togo
Tonga|Tonga
Trinité-et-Tobago|Trinité-et-Tobago
Tunisie|Tunisie
Turkménistan|Turkménistan
Turquie|Turquie
Tuvalu|Tuvalu
Ukraine|Ukraine
Uruguay|Uruguay
Vanuatu|Vanuatu
Venezuela|Venezuela
Viêt_Nam|Viêt Nam
Yémen|Yémen
Zambie|Zambie
Zimbabwe|Zimbabwe',
          'multiple' => 0,
          'title_display' => 'before',
          'private' => 0,
          'wrapper_classes' => 'webform-component webform-component-textfield small-12 medium-6 columns',
          'css_classes' => '',
          'aslist' => 1,
          'empty_option' => 'Choisissez',
          'optrand' => 0,
          'other_option' => NULL,
          'other_text' => 'Other...',
          'description' => '',
          'custom_keys' => FALSE,
          'options_source' => '',
          'analysis' => TRUE,
        ),
        'required' => 1,
        'weight' => 27,
        'machine_name' => '_tre_rappel___rdv_idkp',
        'page_num' => 1,
        'parent_machine_name' => 'prendre_rendez_vous__dept_prog',
      ),
      'prendre_rendez_vous__row_1' => array(
        'form_key' => 'row6',
        'name' => 'Row6',
        'type' => 'fieldset',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'css_classes' => 'row row--noGutter medium-uncollapse small-collapse',
          'collapsible' => 0,
          'collapsed' => 0,
          'description' => '',
        ),
        'required' => 0,
        'weight' => 28,
        'machine_name' => 'prendre_rendez_vous__row_1',
        'page_num' => 1,
      ),
      '_tre_rappel___rdv_idkl' => array(
        'form_key' => 'e_mail',
        'name' => 'E-mail',
        'type' => 'email',
        'value' => '',
        'extra' => array(
          'title_display' => 'before',
          'private' => 0,
          'wrapper_classes' => 'webform-component webform-component-textfield small-12 medium-6 columns',
          'css_classes' => '',
          'multiple' => 0,
          'format' => 'short',
          'width' => '',
          'unique' => 0,
          'disabled' => 0,
          'description' => '',
          'placeholder' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 1,
        'weight' => 29,
        'machine_name' => '_tre_rappel___rdv_idkl',
        'page_num' => 1,
        'parent_machine_name' => 'prendre_rendez_vous__row_1',
      ),
      '_tre_rappel___rappeler_nom' => array(
        'form_key' => 'telephone',
        'name' => 'Téléphone',
        'type' => 'number',
        'value' => '',
        'extra' => array(
          'title_display' => 'before',
          'private' => 0,
          'wrapper_classes' => 'webform-component webform-component-textfield small-12 medium-6 columns',
          'css_classes' => '',
          'separator' => '',
          'point' => ',',
          'integer' => 1,
          'type' => 'textfield',
          'field_prefix' => '',
          'field_suffix' => '',
          'disabled' => 0,
          'unique' => 0,
          'description' => '',
          'attributes' => array(),
          'analysis' => FALSE,
          'min' => '',
          'max' => '',
          'step' => '',
          'decimals' => '',
          'excludezero' => 0,
        ),
        'required' => 1,
        'weight' => 30,
        'machine_name' => '_tre_rappel___rappeler_nom',
        'page_num' => 1,
        'parent_machine_name' => 'prendre_rendez_vous__row_1',
      ),
      'prendre_rendez_vous__row_3' => array(
        'form_key' => 'row7',
        'name' => 'Row7',
        'type' => 'fieldset',
        'value' => '',
        'extra' => array(
          'title_display' => 'none',
          'private' => 0,
          'css_classes' => '',
          'collapsible' => 0,
          'collapsed' => 0,
          'description' => '',
        ),
        'required' => 0,
        'weight' => 31,
        'machine_name' => 'prendre_rendez_vous__row_3',
        'page_num' => 1,
      ),
      '_tre_rappel___rappeler_prenom' => array(
        'form_key' => 'lettre_motivation',
        'name' => 'Joindre votre lettre de motivation * (pdf ou word, 1 Mo max.) :',
        'type' => 'file',
        'value' => '',
        'extra' => array(
          'title_display' => 'inline',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'filtering' => array(
            'size' => '1 MB',
            'types' => array(
              0 => 'pdf',
              1 => 'doc',
              2 => 'docx',
            ),
            'addextensions' => '',
          ),
          'rename' => '',
          'scheme' => 'public',
          'directory' => '',
          'progress_indicator' => 'throbber',
          'description' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 1,
        'weight' => 32,
        'machine_name' => '_tre_rappel___rappeler_prenom',
        'page_num' => 1,
        'parent_machine_name' => 'prendre_rendez_vous__row_3',
      ),
      '_tre_rappel___rappeler_telephone' => array(
        'form_key' => 'curriculum_vitae',
        'name' => 'Joindre votre CV* (pdf ou word, 1 Mo max.) :',
        'type' => 'file',
        'value' => '',
        'extra' => array(
          'title_display' => 'inline',
          'private' => 0,
          'wrapper_classes' => '',
          'css_classes' => '',
          'filtering' => array(
            'size' => '1 MB',
            'types' => array(
              0 => 'pdf',
              1 => 'doc',
              2 => 'docx',
            ),
            'addextensions' => '',
          ),
          'rename' => '',
          'scheme' => 'public',
          'directory' => '',
          'progress_indicator' => 'throbber',
          'description' => '',
          'attributes' => array(),
          'analysis' => FALSE,
        ),
        'required' => 1,
        'weight' => 33,
        'machine_name' => '_tre_rappel___rappeler_telephone',
        'page_num' => 1,
        'parent_machine_name' => 'prendre_rendez_vous__row_3',
      ),
    ),
    'conditionals' => array(),
  ),
  'domains' => array(
    1 => 1,
    2 => 2,
    3 => 3,
  ),
  'domain_site' => TRUE,
  'subdomains' => array(
    0 => 'All affiliates',
    1 => 'Drupal',
    2 => 'Kaufman & Broad Patrimoine',
    3 => 'Kaufman & Broad',
  ),
  'locations' => array(),
  'location' => array(),
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'webform_features_author' => 'admin',
  'webform_features_revision_author' => 'admin',
);
return $webforms;
}
