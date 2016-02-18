<?php

define('WATCHEEZY', 'http://api.watcheezy.com/deliver/watcheezy.js?key=efe59c556a4504811f4170e760bf17af&install=footer&lang=FR');
define('ARTICLE_LIMIT_CONTENT', 250);

if (!defined('TAXONOMY_STATUS_LOGEMENT_DISPONIBLE')) {
  define('TAXONOMY_STATUS_LOGEMENT_DISPONIBLE', 'Disponible / Libre');
}

// Constant to see if the page is loaded in AJAX
define('IS_AJAX', (!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') ? TRUE : FALSE);
/**
 *  insert class  into the body page template.
 */

function kandb_theme_preprocess_html(&$variables) {
  $header = drupal_get_http_header('status');
  if ($header == '404 Not Found' ||  $variables['is_front'] ){
    $variables['classes_array'][] = 'homepage';
  }
  // Change template on AJAX request
  if (IS_AJAX) {
    $variables['theme_hook_suggestions'][] = 'html__ajax';
  }
}

/**
 * Implements hook_js_alter()
 */
function kandb_theme_js_alter(&$javascript) {
  // Change template on AJAX request
  if (IS_AJAX) {
    if (menu_get_object()->type == 'webform') {
      unset($javascript[drupal_get_path('theme', 'kandb_theme') . '/js/bundle.js']);
      unset($javascript[drupal_get_path('theme', 'kandb_theme') . '/js/modernizr.js']);
      foreach ($javascript as $key => $js_array) {
        if (strpos($key, 'watcheezy') !== FALSE) {
          unset($javascript[$key]);
        }
      }
    };
  }
}

/**
 * Override or insert variables into the page template.
 */
function kandb_theme_process_page(&$variables) {
  $variables['hide_site_name'] = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($variables['hide_site_name']) {
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Kaufman & Broad'));
  }
  if ($variables['hide_site_slogan']) {
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  if (!empty($variables['title_suffix']['add_or_remove_shortcut']) && $variables['title']) {
    $variables['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $variables['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    $variables['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }

  $common_js = array(
    'bundle',
  );
  // Add custom script and keep them in footer scope.
  kandb_theme_include_common_js($common_js);

  // Add live chat script all page.
  drupal_add_js(WATCHEEZY, 'external');

  // Change template on AJAX request
  if (IS_AJAX) {
    $variables['theme_hook_suggestions'][] = 'page__ajax';

    // If we are applying to a specific job we add info and change the title
    if(isset($_GET['annonce']) && is_numeric($_GET['annonce'])) {
      $annonce = node_load($_GET['annonce']);
      $terms = taxonomy_term_load_multiple(array(
        $annonce->field_annonce_fonction['und'][0]['tid'],
        $annonce->field_annonce_type_contrat['und'][0]['tid'],
        $annonce->field_annonce_ville['und'][0]['tid']
      ));
      $variables['title'] = $terms[$annonce->field_annonce_fonction['und'][0]['tid']]->name;

      // Dirty to Delete
      $date = str_replace(
        array('January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December', 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'),
        array('janvier', 'février', 'mars', 'avril', 'mai', 'juin', 'juillet', 'août', 'septembre', 'octobre', 'novembre', 'décembre', 'Dimanche', 'Lundi', 'Mardi', 'Mercredi', 'Jeudi', 'Vendredi', 'Samedi'),
        date('l d F Y', strtotime($annonce->field_annonce_date_mise_en_ligne['und'][0]['value']))
      );

      foreach($variables['node']->webform['components'] as $id => &$component) {
        if($component['form_key'] == 'vous_souhaitez_postuler_a_un_post_de') {
          $component['extra']['private'] = 1;
          $component['extra']['attributes'] = array('style' => array('display:none;'));
          $component['extra']['disabled'] = 1;
          $component['extra']['placeholder'] = 'SELE4';
        }
      }
      $variables['title_suffix'] = '<div class="postuler-popin">
              <div class="postuler-popin__intro">' . $terms[$annonce->field_annonce_ville['und'][0]['tid']]->name . '</div>
              <div class="postuler-popin__details">' . $terms[$annonce->field_annonce_type_contrat['und'][0]['tid']]->name . '  /  Service : ' . $annonce->field_annonce_service['und'][0]['value'] . '  /  Date de l’Annonce : ' . $date . '</div>
            </div>';
    }
  }
  $header = drupal_get_http_header('status');
  if ($header == '404 Not Found') {
    $variables['theme_hook_suggestions'][] = 'page__404';
  }
}

/**
 * Implements hook_form_alter()
 */
function kandb_theme_form_alter(&$form, &$form_state, $form_id) {
  // Hide the first field if we are applying for a specific job
  if(isset($form['#node']) && $form['#node']->type == 'webform' && $form['#node']->webform['machine_name'] == 'candidature'){
    if(isset($_GET['annonce'])){
      $form['submitted']['row1']['vous_souhaitez_postuler_a_un_post_de']['#access'] = false;
    }
    $form['#suffix'] = '<div class="legalNote">Les données collectées vous concernant sont destinées au Groupe Kaufman & Broad, responsable du traitement, qui les utilise à des fins d\'information commerciale. Conformément à l\'article 34 de la loi Informatique et Libertés vous disposez d\'un droit d\'accès, de modification, de rectification et de suppression des données qui vous concernent. Pour l\'exercer, adressez-vous à Kaufman & Broad, Département Internet, 127 avenue Charles de Gaulle, 92207 Neuilly-sur-Seine Cedex.</div>';
  }
}

/**
 * Returns HTML for primary and secondary local tasks.
 *
 * @ingroup themeable
 */
function kandb_theme_menu_local_tasks(&$variables) {
  $output = '';

  // Style the tabs
  // programCharacteristics__nav clearfix
  if ($variables['primary']) {

    if ($primary = menu_primary_local_tasks()) {
      $output .= '<ul class="programCharacteristics__nav" style="margin:5px 0px; text-align:left;position:relative;" >';
      foreach ($primary as $tab) {
        $tab['#link']['localized_options']['attributes']['class'][] = 'test';
        $tab['#link']['localized_options']['attributes']['style'][] = 'margin:0px;';
        $output .= render($tab);
      }
      $output .= '</ul>';
    }
    if ($secondary = menu_secondary_local_tasks()) {
      $output .= '<ul class="tabs secondary">';
      foreach ($secondary as $tab) {
        $output .= render($tab);
      }
      $output .= "</ul>";
    }
  }
  return $output;
}

/**
 * Implementation theme_preprocess_form_element_label()
 */
function kandb_theme_preprocess_form_element_label(&$variables) {
  if (isset($variables['element']['#theme']) && $variables['element']['#theme'] == 'checkbox') {
    $variables['element']['#attributes']['class'][] = 'label-checkbox';
  }
}

/**
 * Implement include css/js for each page.
 */
function kandb_theme_include_asset($variable, $type) {
  $path = drupal_get_path('theme', 'kandb_theme');
  if ($type == 'css') {
    foreach ($variable as $key => $item) {
      drupal_add_css($path . '/css/' . $item . '.css', array(
        'group' => CSS_THEME,
        'type' => 'file',
        'media' => 'screen',
        'preprocess' => FALSE,
        'every_page' => FALSE,
        'group' => CSS_THEME,
        'weight' => $key,
      ));
    }
  }
  if ($type == 'js') {
    foreach ($variable as $key => $item) {
      drupal_add_js($path . '/js/' . $item . '.js', array(
        'type' => 'file',
        'scope' => 'footer',
        'group' => JS_THEME,
        'every_page' => FALSE,
        'weight' => $key,
      ));
    }
  }
}

/**
 * Implement include js common in footer for every page.
 */
function kandb_theme_include_common_js($variable) {
  $path = drupal_get_path('theme', 'kandb_theme');
  foreach ($variable as $item) {
    drupal_add_js($path . '/js/' . $item . '.js', array(
      'type' => 'file',
      'scope' => 'footer',
      'group' => JS_THEME,
      'every_page' => TRUE,
      'weight' => -1,
    ));
  }
}

/**
 * Get the direction path from a theme.
 */
function kandb_theme_get_path($dir_name = NULL, $theme_name = NULL) {
  if (empty($dir_name)) {
    return NULL;
  }
  global $base_url, $theme;
  $theme_name = (empty($theme_name)) ? $theme : $theme_name;
  return $base_url . '/' . drupal_get_path('theme', $theme_name) . '/' . $dir_name . '/';
}

/**
 * Implemnts hook_preprocess_node().
 */
function kandb_theme_preprocess_node(&$vars) {
  global $_domain;
  $arg = arg();
  global $user;
  switch ($vars['view_mode']) {
    case 'teaser_carrousel_3':
      $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__teaser_carrousel_3';
      $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__teaser_carrousel_3';
      break;

    case 'dossier_big_teaser':
      $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__dossier_big_teaser';
      $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__dossier_big_teaser';
      break;

    case 'teaser':
      $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__teaser';
      $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__teaser';
      break;


    default:
      break;
  }

  if ($vars['view_mode'] == 'full' && ($vars['type'] == 'bien' || $vars['type'] == 'programme')) {

    $programme = NULL;
    if ($vars['type'] == 'programme') {
      $programme = $vars['node'];
    }
    elseif (isset($vars['field_programme'][0]['entity'])) {
      $programme = $vars['field_programme'][0]['entity'];
    }
    $price_tva_min = $price_tva_max = 0;
    if (!empty($vars['field_tva']) && $programme != NULL) {
      if (isset($programme->field_program_low_tva_price_max[LANGUAGE_NONE][0]['value'])) {
        $price_tva_max = $programme->field_program_low_tva_price_max[LANGUAGE_NONE][0]['value'];
      }
      if (isset($programme->field_program_low_tva_price_min[LANGUAGE_NONE][0]['value'])) {
        $price_tva_min = $programme->field_program_low_tva_price_min[LANGUAGE_NONE][0]['value'];
      }
    }
    if ($price_tva_max != 0) {
      $vars['price_tva_max'] = $price_tva_max;
    }
    if ($price_tva_min != 0) {
      $vars['price_tva_min'] = $price_tva_min;
    }

    $vars['anchor'] = FALSE;
    if ($vars['title']) {
      $vars['anchor'] = TRUE;
    }
  }

  if ($vars['view_mode'] == 'full' && $vars['type'] == 'bien') {
    $name_program_characteristic_on_bien = array();
    if(isset($vars['field_programme'][0]['entity']->field_caracteristiques[LANGUAGE_NONE]) && !empty($vars['field_programme'][0]['entity']->field_caracteristiques[LANGUAGE_NONE])) {
      $terms_array = $vars['field_programme'][0]['entity']->field_caracteristiques[LANGUAGE_NONE];
      $terms_ids = array();
      foreach($terms_array as $term){
        $terms_ids[] = $term['tid'];
      }
      $vars['program_characteristic_on_bien'] = array();
      if($terms = taxonomy_term_load_multiple($terms_ids)){
        foreach($terms as $term) {
          if(isset($term->field_show_on_bien_page) && $term->field_show_on_bien_page[LANGUAGE_NONE][0]['value'] == 1) {
            $vars['program_characteristic_on_bien'][] = $term;
            $name_program_characteristic_on_bien[] = $term->name;
          }
        }
      }


    }
    if(!in_array('Chauffage', $name_program_characteristic_on_bien)){
      if(isset($vars['field_programme'][0]['entity']->field_caracteristique_chauffage[LANGUAGE_NONE][0]['tid']) && $chauffage = $vars['field_programme'][0]['entity']->field_caracteristique_chauffage[LANGUAGE_NONE][0]['tid']){
        $vars['program_characteristic_on_bien'][]->name = "Chauffage";
      }
    }
  }

  // Implement redirect bien detail if status is Indisponible;
  if ($vars['type'] == 'bien' && isset($arg[1]) && $arg[1] == $vars['nid']) {
    if (empty($user->uid)) {
      if (isset($vars['field_bien_statut'][LANGUAGE_NONE][0]['tid'])) {
        $bien_status = taxonomy_term_load($vars['field_bien_statut'][LANGUAGE_NONE][0]['tid']);
        if ($bien_status->name && $bien_status->name == 'Indisponible') {
          $programme_id = $vars['field_programme'][0]['target_id'];
          $programme_status = $vars['field_programme'][0]['entity']->field_programme_statut[LANGUAGE_NONE][0]['value'];
          if ($programme_status == 1) {
            drupal_goto('node/' . $programme_id);
          }
          else {
            drupal_goto(URL_SEARCH_B2C);
          }
        }
      }
    }
  }

  // Get list Biens for Bien page
  global $_domain;
  $gid = $_domain['domain_id'];
  $vars['gid'] = $gid;

  $current_nb_pieces = NULL;
  $list_bien_more = array();
  if ($vars['type'] == 'bien' && arg(0) == 'node' && is_numeric(arg(1)) && arg(2) == NULL) {
    $node_bien = node_load(arg(1));
    $current_nb_pieces = isset($node_bien->field_nb_pieces[LANGUAGE_NONE][0]['tid']) ? $node_bien->field_nb_pieces[LANGUAGE_NONE][0]['tid'] : NULL;
    $node = NULL;
    if (isset($node_bien->field_programme[LANGUAGE_NONE][0]['target_id'])) {
        $node = node_load($node_bien->field_programme[LANGUAGE_NONE][0]['target_id']);
        $key = $node_bien->field_programme[LANGUAGE_NONE][0]['target_id'];
      }
      if ($node && isset($node->type) && $node->type == 'programme') {
        $logement_block['title'] = $node->title;
        $tid = 0;
        $terms = taxonomy_get_term_by_name('Disponible / Libre');
        if ($terms) {
          foreach ($terms as $id => $term) {
            $tid = $id;
          }
        }

      $node_program = $node;
      $tva = 0; $stock = 0;
      if($node_program) {
        $tva = isset($node_program->field_tva[LANGUAGE_NONE][0]['taxonomy_term']->field_facteur[LANGUAGE_NONE][0]['value']) ? $node_program->field_tva[LANGUAGE_NONE][0]['taxonomy_term']->field_facteur[LANGUAGE_NONE][0]['value'] : '';
        $stock = isset($node_program->field_programme_stock[LANGUAGE_NONE][0]['value']) ? $node_program->field_programme_stock[LANGUAGE_NONE][0]['value'] : '';
      }
      if ($tid) {
        $programme_promotion = getListPromotionProgramme($key);
        if (isset($programme_promotion['node'])) {
          $logement_block['programme_promotion'] = TRUE;
        }

        $listBien = countListBienGroupByTypeBien($tid, $key, $gid);
        $arr_price_remain =  '';
        if ($listBien->rowCount() > 0) {
          $listBien = $listBien->fetchAll();
          foreach ($listBien as $program_list_biens) {

            $bien_id = explode(",", $program_list_biens->bien_id);
            $biens = node_load_multiple($bien_id);
            $variables = array();
            foreach($biens as $bien) {
              $nb_pieces_tid = isset($bien->field_nb_pieces[LANGUAGE_NONE][0]['tid']) ? $bien->field_nb_pieces[LANGUAGE_NONE][0]['tid'] : '';
              if($nb_pieces_tid) {
                $nb_pieces_node = taxonomy_term_load($nb_pieces_tid);
                if($nb_pieces_node) {
                  $nb_pieces_weight = $nb_pieces_node->weight;
                  $nb_pieces_name = $nb_pieces_node->name;
                }
              }

              // Images des types de Lots.
              $img_num_piece = '';

              if (preg_match_all('/(studio|2|3|4|5)/i', $nb_pieces_name, $matches)) {

                if (isset($matches[0][0]) AND $num_piece = $matches[0][0]) {
                  $img_num_piece_field = is_numeric($num_piece) ? 'field_image_' . $matches[0][0] . '_piece' : 'field_image_' . $matches[0][0];
                  $img_num_piece = field_get_items('node', $node, $img_num_piece_field);
                  if (($img_num_piece AND isset($img_num_piece[0]['uri']))) {
                    $img_num_piece = image_style_url('program_image_num_piece', $img_num_piece[0]['uri']);
                  } else {
                    $image_default_number_piece = variable_get('image_default_number_piece_' . $num_piece);
                    $image_default_number_piece = $image_default_number_piece ? file_load($image_default_number_piece) : '';
                    $img_num_piece = isset($image_default_number_piece->uri) ? image_style_url('program_image_num_piece', $image_default_number_piece->uri) : '';
                  }
                }
              }

              if($program_list_biens->name == 'Appartement') {
                $variables[$nb_pieces_weight . '-' . $program_list_biens->name . '-' . $bien->field_nb_pieces[LANGUAGE_NONE][0]['tid']][$bien->title]['price'] = isset($bien->field_prix_tva_20[LANGUAGE_NONE][0]['value']) ? $bien->field_prix_tva_20[LANGUAGE_NONE][0]['value'] : '';
                $variables[$nb_pieces_weight . '-' . $program_list_biens->name . '-' . $bien->field_nb_pieces[LANGUAGE_NONE][0]['tid']][$bien->title]['superficie'] = isset($bien->field_superficie[LANGUAGE_NONE][0]['value']) ? $bien->field_superficie[LANGUAGE_NONE][0]['value'] : '';
                $logement_block['programme_bien_images'][$nb_pieces_weight . '-' . $program_list_biens->name . '-' . $bien->field_nb_pieces[LANGUAGE_NONE][0]['tid']] = $img_num_piece;
                $logement_block['type_de_bien'][$nb_pieces_weight . '-' . $program_list_biens->name . '-' . $bien->field_nb_pieces[LANGUAGE_NONE][0]['tid']] = $program_list_biens->name;
                $variables[$nb_pieces_weight . '-' . $program_list_biens->name . '-' . $bien->field_nb_pieces[LANGUAGE_NONE][0]['tid']][$bien->title]['node'] = $bien;
              } elseif($program_list_biens->name == 'Maison') {
                $variables['99-' . $program_list_biens->name . '-' . $bien->field_nb_chambres[LANGUAGE_NONE][0]['tid']][$bien->title]['price'] = isset($bien->field_prix_tva_20[LANGUAGE_NONE][0]['value']) ? $bien->field_prix_tva_20[LANGUAGE_NONE][0]['value'] : '';
                $variables['99-' . $program_list_biens->name . '-' . $bien->field_nb_chambres[LANGUAGE_NONE][0]['tid']][$bien->title]['superficie'] = isset($bien->field_superficie[LANGUAGE_NONE][0]['value']) ? $bien->field_superficie[LANGUAGE_NONE][0]['value'] : '';
                $logement_block['programme_bien_images']['99-' . $program_list_biens->name . '-' . $bien->field_nb_chambres[LANGUAGE_NONE][0]['tid']] = $img_num_piece;
                $logement_block['type_de_bien']['99-' . $program_list_biens->name . '-' . $bien->field_nb_chambres[LANGUAGE_NONE][0]['tid']] = $program_list_biens->name;
                $variables['99-' . $program_list_biens->name . '-' . $bien->field_nb_chambres[LANGUAGE_NONE][0]['tid']][$bien->title]['node'] = $bien;
              } else {
                $variables['99-' . $program_list_biens->name][$bien->title]['price'] = $bien->field_prix_tva_20[LANGUAGE_NONE][0]['value'];
                $variables['99-' . $program_list_biens->name][$bien->title]['superficie'] = $bien->field_superficie[LANGUAGE_NONE][0]['value'];
                $logement_block['type_de_bien']['99-' .   $program_list_biens->name] = $program_list_biens->name;
                //$logement_block['programme_bien_images']['99-' . $program_list_biens->name] = $img_num_piece;
                $variables['99-' . $program_list_biens->name][$bien->title]['node'] = $bien;
              }
            }

            $arr_price_max = ''; $arr_price_min = '';
            foreach($variables as $key => $values) {
              $logement_block['total_bien'][$key] = ceil(count($values) * $stock / 100);
              $logement_block['tva_bien'][$key] = $tva;

              $bien_id_max = array_search(max($values), $values);
              $bien_id_min = array_search(min($values), $values);

              $max = max($values);
              $arr_price_max[$key][$bien_id_max] = $max;
              if(isset($arr_price_max[$key][$bien_id_max]['superficie'])) {
                unset($arr_price_max[$key][$bien_id_max]['superficie']);
              }

              $min = min($values);
              $arr_price_min[$key][$bien_id_min] = $min;
              if(isset($arr_price_min[$key][$bien_id_min]['superficie'])) {
                unset($arr_price_min[$key][$bien_id_min]['superficie']);
              }

              $logement_block['price_min_tva20_bien'][$key] = $min['price'];
              $logement_block['price_min_tva_un_20_bien'][$key] = $min['price'] / 1.2 * ($tva + 1);

              $total_bien_stock = ceil(count($values) * $stock / 100);
              if($max == $min || ($max != $min && count($values) <= 2)) {

                if(isset($values[$bien_id_max]['superficie'])) {
                  unset($values[$bien_id_max]['superficie']);
                }
                if(isset($values[$bien_id_min]['superficie'])) {
                  unset($values[$bien_id_min]['superficie']);
                }

                $arr_price_remain[$key] = array_slice($values, 0, $total_bien_stock);
              } else {
                unset($values[$bien_id_max]);
                unset($values[$bien_id_min]);
                foreach ($values as $k => $v) {
                  $arr_price_superficie[$k]['price'] = $v['price'];
                  $arr_price_superficie[$k]['node'] = $v['node'];
                }
                arsort($arr_price_superficie);
                $arr_merge = array_merge($arr_price_min[$key], $arr_price_max[$key], $arr_price_superficie);
                $arr_price_remain[$key] = array_slice($arr_merge, 0, $total_bien_stock);
              }
            }

            $logement_block['popin_program'] = $arr_price_remain;
          }
          foreach($logement_block['popin_program'] as $v) {
            foreach ($v as $sv) {
              if ($sv['node']->nid != $node_bien->nid && isset($sv['node']->field_nb_pieces[LANGUAGE_NONE][0]['tid']) && $sv['node']->field_nb_pieces[LANGUAGE_NONE][0]['tid'] == $current_nb_pieces) {
                $list_bien_more[] = $sv['node'];
                $vars['list_bien_more'] = $list_bien_more;
              }
            }
          }
        }
      }
    }
  }

  if ($vars['view_mode'] == 'full' && $vars['type'] == 'programme') {

    $content = &$vars['content'];
    $node = &$vars['node'];

    // TODO : Remove
    // $path_img = kandb_theme_get_path('test_assets', 'kandb_theme');

    /**
     * HEADER
     */
    // Get promotion by programme nid.
    $vars['promotions'] = get_nids_promotions_by_programme($node->nid);

    // Information for header programme page

    $vars['title'] = $node->title;

    if (isset($node->field_image_principale) && !empty($node->field_image_principale)) {
      foreach($node->field_image_principale[LANGUAGE_NONE] as $id => &$image){
        if(!empty($image['uri'])){
          $image['small'] = image_style_url("bien_small__640_x_316", $image['uri']);
          $image['medium'] = image_style_url("bien_medium__1024x506", $image['uri']);
          $image['large'] = image_style_url("bien_large__1380_x_600", $image['uri']);
        }
      }
    }

    $vars['nouveau'] = isset($node->field_nouveau[LANGUAGE_NONE][0]['value']) ? $node->field_nouveau[LANGUAGE_NONE][0]['value'] : 0;
    $vars['caracteristiques'] = isset($node->field_caracteristiques[LANGUAGE_NONE]) ? $node->field_caracteristiques[LANGUAGE_NONE] : '';
    $vars['programme_loc_arr_name'] = isset($node->field_programme_loc_arr[LANGUAGE_NONE][0]['taxonomy_term']->name) ? trim(str_replace('arrondissement', '', $node->field_programme_loc_arr[LANGUAGE_NONE][0]['taxonomy_term']->name)) : '';
    $vars['program_loc_department'] = isset($node->field_programme_loc_department[LANGUAGE_NONE][0]['tid']) ? $node->field_programme_loc_department[LANGUAGE_NONE][0]['taxonomy_term']->field_numero_departement[LANGUAGE_NONE][0]['value'] : '';
    $vars['program_loc_ville'] = isset($node->field_programme_loc_ville[LANGUAGE_NONE][0]['taxonomy_term']->name) ? $node->field_programme_loc_ville[LANGUAGE_NONE][0]['taxonomy_term']->name : '';

    $trimstre_id = isset($node->field_trimestre[LANGUAGE_NONE][0]['value']) ? $node->field_trimestre[LANGUAGE_NONE][0]['value'] : '';
    $vars['trimstre'] = '';
    if ($trimstre_id) {
      if ($trimstre_id == 1) {
        $vars['trimstre'] = t('1er trimestre');
      }
      $vars['trimstre'] = $trimstre_id . t('ème trimestre');
    }

    $vars['annee'] = isset($node->field_annee[LANGUAGE_NONE][0]['value']) ? $node->field_annee[LANGUAGE_NONE][0]['value'] : '';

    if(isset($_domain['domain_id'])) {
      $stock= $programme->field_programme_stock['und'][0]['value'];
      if($_domain['domain_id'] == DOMAIN_B2B) {
        $vars['flat_available'] = isset($node->field_programme_flat_available_b[LANGUAGE_NONE][0]['value']) ? ceil($node->field_programme_flat_available_b[LANGUAGE_NONE][0]['value'] * $stock / 100) . t(' appartements disponibles') : '';
      } elseif ($_domain['domain_id'] == DOMAIN_B2C) {
        $vars['flat_available'] = isset($node->field_programme_flat_available[LANGUAGE_NONE][0]['value']) ? ceil($node->field_programme_flat_available[LANGUAGE_NONE][0]['value'] * $stock / 100) . t(' appartements disponibles') : '';
      }
    }

    $pieces_min = 0; $pieces_max = 0;
    if(isset($_domain['domain_id'])) {
      if($_domain['domain_id'] == DOMAIN_B2B) {
        $pieces_min = isset($node->field_programme_room_min_b[LANGUAGE_NONE][0]['value']) ? $node->field_programme_room_min_b[LANGUAGE_NONE][0]['value'] : '';
        $pieces_max = isset($node->field_programme_room_max_b[LANGUAGE_NONE][0]['value']) ? $node->field_programme_room_max_b[LANGUAGE_NONE][0]['value'] : '';
      } elseif ($_domain['domain_id'] == DOMAIN_B2C) {
        $pieces_min = isset($node->field_programme_room_min[LANGUAGE_NONE][0]['value']) ? $node->field_programme_room_min[LANGUAGE_NONE][0]['value'] : '';
        $pieces_max = isset($node->field_programme_room_max[LANGUAGE_NONE][0]['value']) ? $node->field_programme_room_max[LANGUAGE_NONE][0]['value'] : '';
      }
    }

    //Example: 24 appartements disponibles du studio au 3 pièces
    //         24 appartements disponibles de 2 à 3 pièces
    //         24 appartements disponibles de 3 pièces
    //         24 appartements disponibles studios
    $vars['de_a_pieces'] = '';
    if ($pieces_min && $pieces_max) {
      if($pieces_min != $pieces_max) {
        $vars['de_a_pieces'] = t('de') . ' ' . $pieces_min . ' ' . t('à') . ' ' . $pieces_max . ' ' . t('pièces');
        if($pieces_min == 1) {
          $vars['de_a_pieces'] = t('du') . ' studio ' . t('au') . ' ' . $pieces_max . ' ' . t('pièces');
        }
      } else {
        $vars['de_a_pieces'] = ($pieces_max == 1)  ? 'studios' : 'de' . ' ' . $pieces_max . ' ' . t('pièces');
      }
    }
    elseif (!$pieces_min && $pieces_max) {
      $vars['de_a_pieces'] = ($pieces_max == 1)  ? 'studios' : 'de' . ' ' . $pieces_max . ' ' . t('pièces');
    }
    elseif ($pieces_min && !$pieces_max) {
      $vars['de_a_pieces'] = ($pieces_min == 1)  ? 'studios' : 'de' . ' ' . $pieces_min . ' ' . t('pièces');
    }

    $price_tva_min = 0; $price_tva_max = 0;
    if(isset($_domain['domain_id'])) {
      if($_domain['domain_id'] == DOMAIN_B2B) {
        $price_tva_min = isset($node->field_program_low_tva_price_minb[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_program_low_tva_price_minb[LANGUAGE_NONE][0]['value']) : '';
        $price_tva_max = isset($node->field_program_low_tva_price_maxb[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_program_low_tva_price_maxb[LANGUAGE_NONE][0]['value']) : '';
      } elseif ($_domain['domain_id'] == DOMAIN_B2C) {
        $price_tva_min = isset($node->field_program_low_tva_price_min[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_program_low_tva_price_min[LANGUAGE_NONE][0]['value']) : '';
        $price_tva_max = isset($node->field_program_low_tva_price_max[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_program_low_tva_price_max[LANGUAGE_NONE][0]['value']) : '';
      }
    }

    $vars['de_a_price_tva'] = '';
    if ($price_tva_min && $price_tva_max) {
      $vars['de_a_price_tva'] = 'De' . ' ' . $price_tva_min . '€' . ' ' . 'à' . ' ' . $price_tva_max . '€';
    }
    elseif (!$price_tva_min && $price_tva_max) {
      $vars['de_a_price_tva'] = 'De' . ' ' . $price_tva_max . '€' . ' ' . 'à' . ' ' . $price_tva_max . '€';
    }
    elseif ($price_tva_min && !$price_tva_max) {
      $vars['de_a_price_tva'] = 'De' . ' ' . $price_tva_min . '€' . ' ' . 'à' . ' ' . $price_tva_min . '€';
    }

    $vars['tva'] = isset($node->field_tva[LANGUAGE_NONE][0]['taxonomy_term']->name) ? $node->field_tva[LANGUAGE_NONE][0]['taxonomy_term']->name : '';
    $vars['affichage_double_grille'] = isset($node->field_affichage_double_grille[LANGUAGE_NONE][0]['value']) ? $node->field_affichage_double_grille[LANGUAGE_NONE][0]['value'] : 0;

    $price_min = 0; $price_max = 0;
    if(isset($_domain['domain_id'])) {
      if($_domain['domain_id'] == DOMAIN_B2B) {
        $price_min = isset($node->field_programme_price_min_b[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_programme_price_min_b[LANGUAGE_NONE][0]['value']) : '';
        $price_max = isset($node->field_programme_price_max_b[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_programme_price_max_b[LANGUAGE_NONE][0]['value']) : '';
      } elseif ($_domain['domain_id'] == DOMAIN_B2C) {
        $price_min = isset($node->field_programme_price_min[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_programme_price_min[LANGUAGE_NONE][0]['value']) : '';
        $price_max = isset($node->field_programme_price_max[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_programme_price_max[LANGUAGE_NONE][0]['value']) : '';
      }
    }

    $vars['de_a_price'] = '';
    if ($price_min && $price_max) {
      $vars['de_a_price'] = 'De' . ' ' . $price_min . '€' . ' ' . 'à' . ' ' . $price_max . '€';
    }
    elseif (!$price_min && $price_max) {
      $vars['de_a_price'] = 'De' . ' ' . $price_max . '€' . ' ' . 'à' . ' ' . $price_max . '€';
    }
    elseif ($price_min && !$price_max) {
      $vars['de_a_price'] = 'De' . ' ' . $price_min . '€' . ' ' . 'à' . ' ' . $price_min . '€';
    }

    $vars['en_quelques_mots'] = isset($node->field_en_quelques_mots[LANGUAGE_NONE][0]['value']) ? $node->field_en_quelques_mots[LANGUAGE_NONE][0]['value'] : '';
    $vars['programme_mtn_legale'] = isset($node->field_programme_mtn_legale[LANGUAGE_NONE][0]['value']) ? $node->field_programme_mtn_legale[LANGUAGE_NONE][0]['value'] : '';


    /**
     * BIENS
     */
    //check all bien status
    $programme_id = $node->vid;
    $vars['flag'] = 0;
    $status = 1;
    if ($tid = get_tid_by_id_field($status)) {
      // Find out the list of biens which referenced to programme.
      $biens_status = get_status_biens($programme_id, $tid);
      $vars['flag'] = ($biens_status) ? 1 : 0;
    }


    /**
     * DOWNLOAD FILES
     */
    //get link file Plaquette commerciale
    $vars['file_plaquette_commerciale'] = '';
    if (isset($content['field_plaquette_commerciale']['#object']->field_plaquette_commerciale['und'][0]['uri'])) {
      $vars['file_plaquette_commerciale'] = $content['field_plaquette_commerciale']['#object']->field_plaquette_commerciale['und'][0]['uri'];
    }

    //get link file fiche reseignement
    $vars['file_fiche_renseignement'] = '';
    if (isset($content['field_fiche_renseignement']['#object']->field_fiche_renseignement['und'][0]['uri'])) {
      $vars['file_fiche_renseignement'] = $content['field_fiche_renseignement']['#object']->field_fiche_renseignement['und'][0]['uri'];
    }

    //get link file fiche Prestations du programme
    $vars['file_prestations_programme'] = '';
    if (isset($content['field_prestations_programme']['#object']->field_prestations_programme['und'][0]['uri'])) {
      $vars['file_prestations_programme'] = $content['field_prestations_programme']['#object']->field_prestations_programme['und'][0]['uri'];
    }

    //get link file Kit fiscal
    $vars['file_kit_fiscal'] = '';
    if (isset($content['field_kit_fiscal']['#object']->field_kit_fiscal['und'][0]['uri'])) {
      $vars['file_kit_fiscal'] = $content['field_kit_fiscal']['#object']->field_kit_fiscal['und'][0]['uri'];
    }

    //get link file Plan du bâtiment
    $vars['file_plan_batiment'] = '';
    if (isset($content['field_plan_batiment']['#object']->field_plan_batiment['und'][0]['uri'])) {
      $vars['file_plan_batiment'] = $content['field_plan_batiment']['#object']->field_plan_batiment['und'][0]['uri'];
    }

    //get link zip file
    $addMore = '_';
    $nid = $node->nid;
    $path = file_create_url('public://');
    $real_path = drupal_realpath('public://');
    $fileName = 'Programme' . $addMore . preg_replace('@[^a-z0-9-]+@', '-', strtolower($node->title)) . '.zip';
    if (file_exists($real_path . '/Programme/archive/' . $nid . '/')) {
      $filePath = $real_path . '/Programme/archive/' . $nid . '/' . $fileName;
      $linkfile = $path . 'Programme/archive/' . $nid . '/' . $fileName;
      if ($filePath) {
        if (file_exists($filePath)) {
          $vars['link_to_zip'] = $linkfile;
        }
      }
    }

    // Hide the files area if no document are uploaded
    $arr_document = array(
      'field_plaquette_commerciale',
      'field_fiche_renseignement',
      'field_plan_batiment',
      'field_kit_fiscal',
    );

    $vars['status_document'] = FALSE;
    foreach ($arr_document as $field_name) {
      $document = isset($node->$field_name) ? $node->$field_name : '';
      if (isset($document[LANGUAGE_NONE][0]['fid'])) {
        $vars['status_document'] = TRUE;
        break;
      }
    }


    /**
     * HABITEO
     */
    $vars['habiteo_id'] = isset($node->field_programme_habiteo_id['und'][0]['value']) ? $node->field_programme_habiteo_id['und'][0]['value'] : '';
    $vars['habiteo_key'] = variable_get('habiteo_widget_security_key');
    $vars['habiteo_video_de_quartier_url'] = variable_get('habiteo_video-de-quartier_url');
    $vars['habiteo_vue_generale_url'] = variable_get('habiteo_vue-generale_url');
    $vars['habiteo_plan_3d_url'] = variable_get('habiteo_plan-3d_url');
    $vars['lat'] = isset($node->field_programme_loc_lat[LANGUAGE_NONE][0]['value']) ? $node->field_programme_loc_lat[LANGUAGE_NONE][0]['value'] : '';
    $vars['lon'] = isset($node->field_programme_loc_long[LANGUAGE_NONE][0]['value']) ? $node->field_programme_loc_long[LANGUAGE_NONE][0]['value'] : '';
    $vars['video_id'] = isset($node->field_quartier_video[LANGUAGE_NONE][0]['video_id']) ? $node->field_quartier_video[LANGUAGE_NONE][0]['video_id'] : '';
    $vars['logementBlock'] = module_invoke('kandb_programme', 'block_view', 'logement_block');
    $vars['program_characteristic'] = module_invoke('kandb_programme', 'block_view', 'program_characteristic');
    $loc_num = isset($node->field_programme_loc_num[LANGUAGE_NONE][0]['value']) ? $node->field_programme_loc_num[LANGUAGE_NONE][0]['value'] : '';
    $loc_rue = isset($node->field_programme_loc_rue[LANGUAGE_NONE][0]['value']) ? $node->field_programme_loc_rue[LANGUAGE_NONE][0]['value'] : '';
    $type_voie = isset($node->field_programme_loc_type[LANGUAGE_NONE][0]['tid']) ? $node->field_programme_loc_type[LANGUAGE_NONE][0]['tid'] : '';
    $type_voies = taxonomy_term_load($type_voie);
    $type_voies_name = isset($type_voies->name) ? $type_voies->name : '';
    $space = '&nbsp;';
    $html = '';
    $vars['address'] = '';
    if ($loc_num || $type_voies_name || $loc_rue) {

        if ($loc_num && !$type_voies_name) {
            $html = $loc_num . $space . $loc_rue;
        } elseif (!$loc_num && $type_voies_name) {
            $html = $type_voies_name . $space . $loc_rue;
        } elseif (!$loc_num && !$type_voies_name) {
            $html = $loc_rue;
        } else {
            $html = $loc_num . $space . $type_voies_name . $space . $loc_rue;
        }
        $vars['address'] = '<p class="text-bold">' . $html . '</p>';
    }

        /**
     * SLIDER
     */
    $arr_slider = array(
      'field_prestations_titre',
      'field_prestations_sous_titre',
      'field_slider_exterieur_titre',
      'field_slider_exterieur_desc',
      'field_slider_exterieur_image',
      'field_slider_interieur_titre',
      'field_slider_interieur_desc',
      'field_slider_interieur_image',
      'field_slider_securite_titre',
      'field_slider_securite_desc',
      'field_slider_securite_image',
      'field_slider_rt2012_titre',
      'field_slider_rt2012_image',
      'field_slider_rt2012_desc',
    );

    $vars['status_slider'] = FALSE;
    foreach ($arr_slider as $field_name) {
      $slider = isset($node->$field_name) ? $node->$field_name : '';
      if (isset($slider[LANGUAGE_NONE][0]['value']) && $slider[LANGUAGE_NONE][0]['value']  || isset($slider[LANGUAGE_NONE][0]['fid']) && $slider[LANGUAGE_NONE][0]['fid']) {
        $vars['status_slider'] = TRUE;
        break;
      }
    }
  }

  if ($vars['view_mode'] == 'selection' && $vars['type'] == 'programme') {
    $node = &$vars['node'];

    $department = taxonomy_term_load($node->field_programme_loc_department[LANGUAGE_NONE][0]['tid']);
    $vars['num_department'] = isset($department->field_numero_departement) ? $department->field_numero_departement[LANGUAGE_NONE][0]['value'] : '';

    $ville = taxonomy_term_load($node->field_programme_loc_ville[LANGUAGE_NONE][0]['tid']);
    $vars['ville_name'] = $ville->name;

    $vars['promotions'] = get_nids_promotions_by_programme($vars['nid']);

    if(isset($vars['field_image_principale'])){
      $image = $vars['field_image_principale'][LANGUAGE_NONE][0]['uri'];
      $vars['programme_selection_very_small'] = image_style_url('programme_selection_very_small', $image);
      $vars['programme_selection_small'] = image_style_url('programme_selection_small', $image);
      $vars['programme_selection_medium'] = image_style_url('programme_selection_medium', $image);
    }

    if(!empty($vars['field_photo_conseiller'])){
      $image = $vars['field_photo_conseiller'][LANGUAGE_NONE][0]['uri'];
      $vars['field_photo_conseiller'][LANGUAGE_NONE][0]['contact_selection'] = image_style_url('contact_selection', $image);
    }

    // Programme selection
    $trimstre_id = isset($node->field_trimestre[LANGUAGE_NONE][0]['value']) ? $node->field_trimestre[LANGUAGE_NONE][0]['value'] : '';
    $vars['trimstre'] = '';
    if ($trimstre_id) {
      if ($trimstre_id == 1) {
        $vars['trimstre'] = t('1er trimestre');
      }
      $vars['trimstre'] = $trimstre_id . t('ème trimestre');
    }

    $vars['annee'] = isset($node->field_annee[LANGUAGE_NONE][0]['value']) ? $node->field_annee[LANGUAGE_NONE][0]['value'] : '';

    if(isset($_domain['domain_id'])) {
      if($_domain['domain_id'] == DOMAIN_B2B) {
        $vars['flat_available'] = isset($node->field_programme_flat_available_b[LANGUAGE_NONE][0]['value']) ? $node->field_programme_flat_available_b[LANGUAGE_NONE][0]['value'] . t(' appartements disponibles') : '';
      } elseif ($_domain['domain_id'] == DOMAIN_B2C) {
        $vars['flat_available'] = isset($node->field_programme_flat_available[LANGUAGE_NONE][0]['value']) ? $node->field_programme_flat_available[LANGUAGE_NONE][0]['value'] . t(' appartements disponibles') : '';
      }
    }

    $price_tva_min = 0; $price_tva_max = 0;
    if(isset($_domain['domain_id'])) {
      if($_domain['domain_id'] == DOMAIN_B2B) {
        $price_tva_min = isset($node->field_program_low_tva_price_minb[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_program_low_tva_price_minb[LANGUAGE_NONE][0]['value']) : '';
        $price_tva_max = isset($node->field_program_low_tva_price_maxb[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_program_low_tva_price_maxb[LANGUAGE_NONE][0]['value']) : '';
      } elseif ($_domain['domain_id'] == DOMAIN_B2C) {
        $price_tva_min = isset($node->field_program_low_tva_price_min[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_program_low_tva_price_min[LANGUAGE_NONE][0]['value']) : '';
        $price_tva_max = isset($node->field_program_low_tva_price_max[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_program_low_tva_price_max[LANGUAGE_NONE][0]['value']) : '';
      }
    }

    $vars['de_a_price_tva'] = '';
    if ($price_tva_min && $price_tva_max) {
      $vars['de_a_price_tva'] = 'De' . ' <strong>' . $price_tva_min . '€</strong>' . ' ' . 'à' . ' <strong>' . $price_tva_max . '€</strong>';
    }
    elseif (!$price_tva_min && $price_tva_max) {
      $vars['de_a_price_tva'] = 'De' . ' <strong>' . $price_tva_max . '€</strong>' . ' ' . 'à' . ' <strong>' . $price_tva_max . '€</strong>';
    }
    elseif ($price_tva_min && !$price_tva_max) {
      $vars['de_a_price_tva'] = 'De' . ' <strong>' . $price_tva_min . '€</strong>' . ' ' . 'à' . ' <strong>' . $price_tva_min . '€</strong>';
    }
    if(isset($node->field_tva[LANGUAGE_NONE][0]['tid'])){
      $tva = taxonomy_term_load($node->field_tva[LANGUAGE_NONE][0]['tid']);
      $vars['temp'] = $tva;
      $vars['tva'] = isset($tva->name) ? $tva->name : '';
    }
    $vars['affichage_double_grille'] = isset($node->field_affichage_double_grille[LANGUAGE_NONE][0]['value']) ? $node->field_affichage_double_grille[LANGUAGE_NONE][0]['value'] : 0;

    $price_min = 0; $price_max = 0;
    if(isset($_domain['domain_id'])) {
      if($_domain['domain_id'] == DOMAIN_B2B) {
        $price_min = isset($node->field_programme_price_min_b[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_programme_price_min_b[LANGUAGE_NONE][0]['value']) : '';
        $price_max = isset($node->field_programme_price_max_b[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_programme_price_max_b[LANGUAGE_NONE][0]['value']) : '';
      } elseif ($_domain['domain_id'] == DOMAIN_B2C) {
        $price_min = isset($node->field_programme_price_min[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_programme_price_min[LANGUAGE_NONE][0]['value']) : '';
        $price_max = isset($node->field_programme_price_max[LANGUAGE_NONE][0]['value']) ? numberFormatGlobalSpace($node->field_programme_price_max[LANGUAGE_NONE][0]['value']) : '';
      }
    }

    $vars['de_a_price'] = '';
    if ($price_min && $price_max) {
      $vars['de_a_price'] = 'De' . ' <strong>' . $price_min . '€</strong>' . ' ' . 'à' . ' <strong>' . $price_max . '€</strong>';
    }
    elseif (!$price_min && $price_max) {
      $vars['de_a_price'] = 'De' . ' <strong>' . $price_max . '€</strong>' . ' ' . 'à' . ' <strong>' . $price_max . '€</strong>';
    }
    elseif ($price_min && !$price_max) {
      $vars['de_a_price'] = 'De' . ' <strong>' . $price_min . '€</strong>' . ' ' . 'à' . ' <strong>' . $price_min . '€</strong>';
    }

    $vars['en_quelques_mots'] = isset($node->field_en_quelques_mots[LANGUAGE_NONE][0]['value']) ? $node->field_en_quelques_mots[LANGUAGE_NONE][0]['value'] : '';
    $vars['programme_mtn_legale'] = isset($node->field_programme_mtn_legale[LANGUAGE_NONE][0]['value']) ? $node->field_programme_mtn_legale[LANGUAGE_NONE][0]['value'] : '';

  }

  $vars['livraison_date'] = isset($node->field_programme_livraison_date[LANGUAGE_NONE][0]['value']) ? $node->field_programme_livraison_date[LANGUAGE_NONE][0]['value'] : '';
  $vars['actabilite_date'] = isset($node->field_programme_actabilite_date[LANGUAGE_NONE][0]['value']) ? $node->field_programme_actabilite_date[LANGUAGE_NONE][0]['value'] : '';

  $vars['programme_loc_region_kb'] = isset($node->field_programme_loc_region_kb[LANGUAGE_NONE][0]['target_id']) ? $node->field_programme_loc_region_kb[LANGUAGE_NONE][0]['target_id'] : '';
  if($vars['type'] == 'bien') {
    $node = &$vars['node'];
    if (!empty($node->field_type) && isset($node->field_type[LANGUAGE_NONE][0]['tid'])) {
      $name_taxonomy = taxonomy_term_load($node->field_type[LANGUAGE_NONE][0]['tid']);
      if (!empty($name_taxonomy) && $name_taxonomy->name == 'Maison') {
        if (!empty($node->field_bien_type_maison) && isset($node->field_bien_type_maison['und'][0]['target_id'])) {
          $field_bien_type_maison = $node->field_bien_type_maison['und'][0]['target_id'];
          $node_maison = node_load($field_bien_type_maison);
          if (!empty($node_maison)) {
            $vars['title_maison'] = $node_maison->title;
          }
        }
      }
    }
  }
}

/**
 * Implemnts hook_preprocess_region().
 */
function kandb_theme_preprocess_region(&$vars) {
  // Header
  if ($vars['region'] == 'header') {
    // Main menu
    $vars['main_menu'] = false;
    $menu_main_links_source = variable_get('menu_main_links_source', false);
    if ($menu_main_links_source) {
      $vars['main_menu'] = menu_navigation_links($menu_main_links_source);
    }
  }

  // Footer
  if ($vars['region'] == 'footer') {

    // Get variables
    $vars['icon_setting'] = variable_get('kandb_settings_social_display', FALSE);
    $vars['facebook'] = variable_get('kandb_settings_footer_link_face', FALSE);
    $vars['youtube'] = variable_get('kandb_settings_footer_link_youtube', FALSE);
    $vars['twitter'] = variable_get('kandb_settings_footer_link_twitter', FALSE);
    $vars['link_prescripteur'] = variable_get('kandb_settings_footer_link_espace_collaborateur', FALSE);

    // Logo and link "Espace prescripteur"
    $vars['path_img'] = kandb_theme_get_path('test_assets', 'kandb_theme');
    $vars['logo_svg'] = kandb_theme_get_path('assets', 'kandb_theme') . '/images/logo-Kaufman-Broad.svg';
    if (theme_get_setting('footer_link_custom')) {
      $vars['link_custom'] = theme_get_setting('footer_link_custom');
    }

    // Menu footer
    $vars['menu_footer'] = false;
    $menu_secondary_links_source = variable_get('menu_secondary_links_source', false);
    if ($menu_secondary_links_source) {
      $vars['menu_footer'] = menu_navigation_links($menu_secondary_links_source);
    }
  }
}

function cut_character($content, $limit = ARTICLE_LIMIT_CONTENT) {
  if ($limit <= 0 || !is_numeric($limit) || strlen($content) < $limit) {
    return $content;
  }

  $i = $limit - 1;
  while (1) {
    if ($i + 15 > $limit) {
      break;
    }
    if ($content[$i + 1] != ' ') {
      $i++;
    }
    else {
      break;
    }
  }

  $end = '';
  if (mb_strlen($content, "UTF-8") > $limit) {
    $end = '...';
  }
  if (function_exists('mb_substr')) {
    $content = mb_substr($content, 0, $i, "UTF-8");
  }
  else {
    $content = substr($content, 0, $i);
  }
  return $content . $end;
}

/**
 * @todo to get taxonomy status du logement by name
 * @param type $term_name
 * @return type
 */
function get_tax_status_du_logement_by_name($term_name, $search_by_name = TRUE) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term');
  //->entityCondition('bundle', TAXONOMY_STATUS_LOGEMENT)

  if (!$search_by_name) {
    $query->fieldCondition('field_id_file', 'value', $term_name, '=');
  }
  else {
    $query->propertyCondition('name', $term_name);
  }

  $query->range(0, 1);
  $results = $query->execute();
  if (!empty($results)) {
    return array_shift($results["taxonomy_term"])->tid;
  }

  return $results;
}

/**
 * @todo to get list bien follow piece && programme
 * @param type $id_programme
 * @param type $id_piece
 */
function get_biens_follow_piece_program($id_programme, $gid, $id_piece = 0, $id_bien = 0) {
  $status_disponible = get_tax_status_du_logement_by_name(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_bien_statut', 'bs', 'bs.entity_id = n.nid');
  $query->leftJoin('field_data_field_programme', 'p', 'p.entity_id = n.nid');
  $query->leftJoin('field_data_field_superficie', 's', 's.entity_id = n.nid');
  $query->leftJoin('field_data_field_id_bien', 'ib', 'ib.entity_id = n.nid');
  $query->leftJoin('field_data_field_nb_pieces', 'np', 'np.entity_id = n.nid');
  $query->leftJoin('domain_access', 'da', 'da.nid = p.entity_id');
  $query
    ->fields('n', array('nid'))
    ->condition('field_bien_statut_tid', $status_disponible, '=')
    ->condition('field_programme_target_id', $id_programme, '=')
    ->condition('gid', $gid,'=')
    ->orderBy('field_superficie_value');

  if (!empty($id_bien)) {
    $query->condition('field_id_bien_value', $id_bien, '!=');
  }

  if (!empty($id_piece)) {
    $query->condition('field_nb_pieces_tid', $id_piece, '=');
  }

  $result = $query->execute();
  if($result) {
    return $result->fetchAllAssoc('nid');
  }

  return array();
}

/**
 * @todo to get list bien have price max-min follow piece && programme
 * @param type $id_programme
 * @param type $id_piece
 * @return type
 */
function get_biens_price_max_min_follow_piece_program($id_programme, $gid, $id_piece = 0, $id_bien = 0, $order_by = 'ASC') {
  $status_disponible = get_tax_status_du_logement_by_name(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);

  $status_disponible = get_tax_status_du_logement_by_name(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_bien_statut', 'bs', 'bs.entity_id = n.nid');
  $query->leftJoin('field_data_field_programme', 'p', 'p.entity_id = n.nid');
  $query->leftJoin('field_data_field_prix_tva_20', 's', 's.entity_id = n.nid');
  $query->leftJoin('field_data_field_id_bien', 'ib', 'ib.entity_id = n.nid');
  $query->leftJoin('field_data_field_nb_pieces', 'np', 'np.entity_id = n.nid');
  $query->leftJoin('domain_access', 'da', 'da.nid = p.entity_id');
  $query
    ->fields('n', array('nid'))
    ->condition('field_bien_statut_tid', $status_disponible, '=')
    ->condition('field_programme_target_id', $id_programme, '=')
    ->condition('gid', $gid,'=')
    ->orderBy('field_prix_tva_20_value', $order_by)
    ->range(0,1);

  if (!empty($id_bien)) {
    $query->condition('field_id_bien_value', $id_bien, '!=');
  }

  if (!empty($id_piece)) {
    $query->condition('field_nb_pieces_tid', $id_piece, '=');
  }

  $result = $query->execute();
  if($result) {
    return $result->fetchAllAssoc('nid');
  }

  return array();
}



/**
 * Returns HTML for a form element label and required marker.
 *
 * Form element labels include the #title and a #required marker. The label is
 * associated with the element itself by the element #id. Labels may appear
 * before or after elements, depending on theme_form_element() and
 * #title_display.
 *
 * This function will not be called for elements with no labels, depending on
 * #title_display. For elements that have an empty #title and are not required,
 * this function will output no label (''). For required elements that have an
 * empty #title, this will output the required marker alone within the label.
 * The label will use the #id to associate the marker with the field that is
 * required. That is especially important for screenreader users to know
 * which field is required.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #required, #title, #id, #value, #description.
 *
 * @ingroup themeable
 */
function kandb_theme_form_element_label($variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
  $attributes['class'] = '';
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'] = 'element-invisible';
  }

  if (isset($variables['element']['#attributes']['class']) && !empty($variables['element']['#attributes']['class'])) {
    $attributes['class'] .= ' ' . implode(' ', $variables['element']['#attributes']['class']);
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '><span>' . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</span></label>\n";
}

/**
 * Returns HTML for a checkbox form element.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #id, #name, #attributes, #checked, #return_value.
 *
 * @ingroup themeable
 */
function kandb_theme_checkbox($variables) {
  $variables['element']['#attributes']['class'][] = 'input-checkbox';
  return theme_checkbox($variables);
}

/**
 * Returns HTML for a select form element.
 *
 * It is possible to group options together; to do this, change the format of
 * $options to an associative array in which the keys are group labels, and the
 * values are associative arrays in the normal $options format.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #title, #value, #options, #description, #extra,
 *     #multiple, #required, #name, #attributes, #size.
 *
 * @ingroup themeable
 */
function kandb_theme_select($variables) {
  $variables['element']['#attributes']['data-app-select'] = '';
  if ($variables['element']['#id'] == 'edit-submitted-row-2-rappeler-horaire' || $variables['element']['#id'] == 'edit-submitted-ap-connu' || $variables['element']['#id'] == 'edit-submitted-rdv-connu') {
    $variables['element']['#options'][''] = '-';
  }
  return theme_select($variables);
}
/**
 * Implementation of hook_css_alter()
 */
function kandb_theme_css_alter(&$css) {
  unset($css['modules/system/system.messages.css']);
  unset($css['modules/system/system.menus.css']);
}

/**
 * Returns HTML for a fieldset form element and its children.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #attributes, #children, #collapsed, #collapsible,
 *     #description, #id, #title, #value.
 *
 * @ingroup themeable
 */
function kandb_theme_fieldset($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id'));
  _form_set_class($element, array('form-wrapper'));

  $output = '<fieldset' . drupal_attributes($element['#attributes']) . '>';
  if (!empty($element['#title'])) {
    // Always wrap fieldset legends in a SPAN for CSS positioning.
    $output .= '<legend><span class="fieldset-legend">' . $element['#title'] . '</span></legend>';
  }
  //$output .= '<div class="fieldset-wrapper">';
  if (!empty($element['#description'])) {
    $output .= '<div class="fieldset-description">' . $element['#description'] . '</div>';
  }
  $output .= $element['#children'];
  if (isset($element['#value'])) {
    $output .= $element['#value'];
  }
  //$output .= '</div>';
  $output .= "</fieldset>\n";
  return $output;
}


/**
 * Returns HTML for a query pager.
 *
 * Menu callbacks that display paged query results should call theme('pager') to
 * retrieve a pager control so that users can view other results. Format a list
 * of nearby pages with additional query results.
 *
 * @param $variables
 *   An associative array containing:
 *   - tags: An array of labels for the controls in the pager.
 *   - element: An optional integer to distinguish between multiple pagers on
 *     one page.
 *   - parameters: An associative array of query string parameters to append to
 *     the pager links.
 *   - quantity: The number of pages in the list.
 *
 * @ingroup themeable
 */
function kandb_theme_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = FALSE; // $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = FALSE; // $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = FALSE; // $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = FALSE; // $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('pager-last'),
        'data' => $li_last,
      );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));
  }
}

/**
 * Returns HTML for the "previous page" link in a query pager.
 *
 * @param $variables
 *   An associative array containing:
 *   - text: The name (or image) of the link.
 *   - element: An optional integer to distinguish between multiple pagers on
 *     one page.
 *   - interval: The number of pages to move backward when the link is clicked.
 *   - parameters: An associative array of query string parameters to append to
 *     the pager links.
 *
 * @ingroup themeable
 */
function kandb_theme_pager_previous($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  global $pager_page_array;
  $output = '';

  // If we are anywhere but the first page
  if ($pager_page_array[$element] > 0) {
    $page_new = pager_load_array($pager_page_array[$element] - $interval, $element, $pager_page_array);

    // If the previous page is the first page, mark the link as such.
    $vars = array('text' => $text, 'element' => $element, 'parameters' => $parameters);
    if(isset($interval) && $interval == 1) $vars['attributes'] = array('rel' => 'prev');
    if ($page_new[$element] == 0) {
      $output = theme('pager_first', $vars);
    }
    // The previous page is not the first page.
    else {
      $vars['page_new'] = $page_new;
      $output = theme('pager_link', $vars);
    }
  }
  return $output;
}

/**
 * Returns HTML for the "next page" link in a query pager.
 *
 * @param $variables
 *   An associative array containing:
 *   - text: The name (or image) of the link.
 *   - element: An optional integer to distinguish between multiple pagers on
 *     one page.
 *   - interval: The number of pages to move forward when the link is clicked.
 *   - parameters: An associative array of query string parameters to append to
 *     the pager links.
 *
 * @ingroup themeable
 */
function kandb_theme_pager_next($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  global $pager_page_array, $pager_total;
  $output = '';

  // If we are anywhere but the last page
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $page_new = pager_load_array($pager_page_array[$element] + $interval, $element, $pager_page_array);
    // If the next page is the last page, mark the link as such.
    $vars = array('text' => $text, 'element' => $element, 'parameters' => $parameters);
    if(isset($interval) && $interval == 1) $vars['attributes'] = array('rel' => 'next');
    if ($page_new[$element] == ($pager_total[$element] - 1)) {
      $output = theme('pager_last', $vars);
    }
    // The next page is not the last page.
    else {
      $vars['page_new'] = $page_new;
      $output = theme('pager_link', $vars);
    }
  }

  return $output;
}

/**
 * Returns HTML for the "first page" link in a query pager.
 *
 * @param $variables
 *   An associative array containing:
 *   - text: The name (or image) of the link.
 *   - element: An optional integer to distinguish between multiple pagers on
 *     one page.
 *   - parameters: An associative array of query string parameters to append to
 *     the pager links.
 *
 * @ingroup themeable
 */
function kandb_theme_pager_first($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  global $pager_page_array;
  $output = '';

  // If we are anywhere but the first page
  if ($pager_page_array[$element] > 0) {
    $output = theme('pager_link', array('text' => $text, 'page_new' => pager_load_array(0, $element, $pager_page_array), 'element' => $element, 'parameters' => $parameters, 'attributes' => $attributes));
  }

  return $output;
}

/**
 * Returns HTML for the "last page" link in query pager.
 *
 * @param $variables
 *   An associative array containing:
 *   - text: The name (or image) of the link.
 *   - element: An optional integer to distinguish between multiple pagers on
 *     one page.
 *   - parameters: An associative array of query string parameters to append to
 *     the pager links.
 *
 * @ingroup themeable
 */
function kandb_theme_pager_last($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  global $pager_page_array, $pager_total;
  $output = '';

  // If we are anywhere but the last page
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $output = theme('pager_link', array('text' => $text, 'page_new' => pager_load_array($pager_total[$element] - 1, $element, $pager_page_array), 'element' => $element, 'parameters' => $parameters, 'attributes' => $attributes));
  }

  return $output;
}

/**
 * Get list bien caracteris is checked
 * @param stdClss() $bien_more
 * @return array()
 */
function get_list_bien_caracteris($bien_more) {
  $arr_caracteris = array();
  $arr_caracteris[] = isset($bien_more->field_caracteristique_balcon[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_balcon[LANGUAGE_NONE][0]['value'] > 0 ? 'Balcon' : '';
  $arr_caracteris[] = isset($bien_more->field_caracteristique_box[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_box[LANGUAGE_NONE][0]['value'] >= 0 ? 'Box' : '';
  $arr_caracteris[] = isset($bien_more->field_caracteristique_cave[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_cave[LANGUAGE_NONE][0]['value'] >= 0 ? 'Cave' : '';
  $arr_caracteris[] = isset($bien_more->field_caracteristique_jardin[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_jardin[LANGUAGE_NONE][0]['value'] > 0 ? 'Jardin' : '';
  $arr_caracteris[] = isset($bien_more->field_caracteristique_parking[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_parking[LANGUAGE_NONE][0]['value'] >= 0? 'Parking' : '';
  $arr_caracteris[] = isset($bien_more->field_caracteristique_terrasse[LANGUAGE_NONE][0]['value']) && $bien_more->field_caracteristique_terrasse[LANGUAGE_NONE][0]['value'] > 0 ? 'Terrasse' : '';

  // Remove all value is emtpy in array
  $arr_caracteris = array_filter($arr_caracteris);
  $caracteristiques = isset($bien_more->field_caracteristique[LANGUAGE_NONE]) ? $bien_more->field_caracteristique[LANGUAGE_NONE] : '';
  if ($caracteristiques && count($caracteristiques) > 0) {
    foreach ($caracteristiques as $caracteristique) {
      $term_caracteristique = taxonomy_term_load($caracteristique['tid']);
      if ($term_caracteristique) {
        if(isset($term_caracteristique->name) && !in_array($term_caracteristique->name, $arr_caracteris)) {
          $arr_caracteris[] = $term_caracteristique->name;
        }
      }
    }
  }

  return $arr_caracteris;
}