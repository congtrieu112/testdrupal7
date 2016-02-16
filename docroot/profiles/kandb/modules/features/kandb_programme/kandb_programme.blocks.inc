<?php

/**
 *  Implements hook_menu().
 */
function kandb_programme_menu() {
  $items = array();
  $items['programme/%/%'] = array(
    'title' => 'Programme',
    'page callback' => 'kandb_programme_page',
    'access callback' => TRUE,
  );

  return $items;
}

function kandb_programme_page() {
  return theme('kandb_programme_detail');
}

/**
 * Implements of hook_theme().
 */
function kandb_programme_theme($existing, $type, $theme, $path) {
  return array(
    'program_characteristic' => array(
      'template' => 'program_characteristic',
      'variables' => array('programme_variables' => NULL),
    ),
    'kandb_programme' => array(
      'variables' => array(
        'logement_block' => NULL,
      ),
      'template' => 'templates/kandb_programme',
    ),
  );
}

/**
 * Implements hook_block_info().
 * @return type
 */
function kandb_programme_block_info() {
  $blocks = array();
  $blocks['logement_block'] = array(
    'info' => 'Logement block',
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['document_block'] = array(
    'info' => 'Document block',
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['program_characteristic'] = array(
    'info' => 'Program Characteristic',
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 * @param type $delta
 * @return type
 */
function kandb_programme_block_view($delta = '') {
  $block = array();
  switch ($delta) {
    case 'document_block':
      $block['subject'] = '';
      $block['content'] = drupal_get_form('document_block_form');
      break;
    case 'logement_block':
      $block['subject'] = '';
      $block['content'] = _get_logement_block_content();
      break;
    case 'program_characteristic':
      $block['subject'] = '';
      $block['content'] = _get_program_characteristic_content();
      break;
  }
  return $block;
}

function numberFormatGlobal($number) {
  return number_format($number, 0, ",", ".");
}

function numberFormatGlobalSpace($number) {
  return number_format($number, 0, "", " ");
}

/**
 * Get list promotion programme
 * @param int $key: Programme NID
 * @return array()
 */
function getListPromotionProgramme($key) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'promotion')
    ->fieldCondition('field_promotion_programme', 'target_id', $key)
    ->fieldCondition('field_promotion_start', 'value', date("Y-m-d"), '>=')
    ->fieldCondition('field_promotion_stop', 'value', date("Y-m-d"), '<=')
    ->range(0, 1);

  return $query->execute();
}

/**
 * Get list promotion biens
 * @param int $key: Bien NID
 * @return array()
 */
function getListPromotionBiens($key) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'promotion')
    ->fieldCondition('field_promotion_biens', 'target_id', array($key), 'IN')
    ->fieldCondition('field_promotion_start', 'value', date("Y-m-d"), '>=')
    ->fieldCondition('field_promotion_stop', 'value', date("Y-m-d"), '<=')
    ->range(0, 1);

  return $query->execute();
}

/**
 * Get logement block content.
 */
function _get_logement_block_content() {
  global $_domain;
  $gid = $_domain['domain_id'];
  $maisons = array();
  $content = '';
  if (arg(0) == 'node' && is_numeric(arg(1)) && arg(2) == NULL) {
    $node = node_load(arg(1));
    $key = arg(1);
    if ($node && isset($node->type) && $node->type == 'programme') {
      $logement_block['title'] = $node->title;
      $tid = 0;
      $terms = taxonomy_get_term_by_name('Disponible / Libre');
      if ($terms) {
        foreach ($terms as $id => $term) {
          $tid = $id;
        }
      }
      
      $tid_maison = 0;
      $terms_maison = taxonomy_get_term_by_name('Maison');
      if ($terms_maison) {
        foreach ($terms_maison as $id => $term_maison) {
          if ($term_maison->vocabulary_machine_name == 'type_de_bien') {
            $tid_maison = $id;
          }
        }
      }
      
      $node_program = node_load($key);
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
              $maison = '';
              $node_maison = NULL;
              if (isset($bien->field_type[LANGUAGE_NONE][0]['tid']) && isset($bien->field_bien_type_maison[LANGUAGE_NONE][0]['target_id']) && $bien->field_type[LANGUAGE_NONE][0]['tid'] == $tid_maison) {
                $node_maison = node_load($bien->field_bien_type_maison[LANGUAGE_NONE][0]['target_id']);
              }
              if (isset($node_maison->title)) {
                $maison = $node_maison->title;
              }
              $maisons[$bien->title] = $maison;
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
              } elseif($program_list_biens->name == 'Maison') {
                $variables['99-' . $program_list_biens->name . '-' . $bien->field_nb_chambres[LANGUAGE_NONE][0]['tid']][$bien->title]['price'] = isset($bien->field_prix_tva_20[LANGUAGE_NONE][0]['value']) ? $bien->field_prix_tva_20[LANGUAGE_NONE][0]['value'] : '';
                $variables['99-' . $program_list_biens->name . '-' . $bien->field_nb_chambres[LANGUAGE_NONE][0]['tid']][$bien->title]['superficie'] = isset($bien->field_superficie[LANGUAGE_NONE][0]['value']) ? $bien->field_superficie[LANGUAGE_NONE][0]['value'] : '';
                $logement_block['programme_bien_images']['99-' . $program_list_biens->name . '-' . $bien->field_nb_chambres[LANGUAGE_NONE][0]['tid']] = $img_num_piece;
                $logement_block['type_de_bien']['99-' . $program_list_biens->name . '-' . $bien->field_nb_chambres[LANGUAGE_NONE][0]['tid']] = $program_list_biens->name;
              } else {
                $variables['99-' . $program_list_biens->name][$bien->title]['price'] = $bien->field_prix_tva_20[LANGUAGE_NONE][0]['value'];
                $variables['99-' . $program_list_biens->name][$bien->title]['superficie'] = $bien->field_superficie[LANGUAGE_NONE][0]['value'];
                $logement_block['type_de_bien']['99-' .   $program_list_biens->name] = $program_list_biens->name;
                //$logement_block['programme_bien_images']['99-' . $program_list_biens->name] = $img_num_piece;
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
                  $arr_price_superficie[$k] = $v['superficie'];
                }
                arsort($arr_price_superficie);
                $arr_merge = array_merge($arr_price_min[$key], $arr_price_max[$key], $arr_price_superficie);
                $arr_price_remain[$key] = array_slice($arr_merge, 0, $total_bien_stock);
              }
            }

            $logement_block['popin_program'] = $arr_price_remain;
          }
        }
      }
    }
  }

  return theme('kandb_programme', array('logement_block' => $logement_block, 'node' => $node, 'maisons' => $maisons));
}

function document_block_form($form, &$form_submit) {
  $form['submit']['B2B'] = array('#type' => 'submit', '#value' => t('Tous télécharger B2B'), '#name' => 'B2B');
  $form['submit']['B2C'] = array('#type' => 'submit', '#value' => t('Tous télécharger B2C'), '#name' => 'B2C');

  return $form;
}

function document_block_form_submit($form, $form_state) {
  $key = arg(1);
  $node = node_load($key);

  if ($key && $node) {
    if ($node->type == 'programme') {
      $addMore = '';
      if ($form_state['values']['B2B'] == $form_state['clicked_button']['#value']) {
        $addMore = '_B2B_';
      } elseif ($form_state['values']['B2C'] == $form_state['clicked_button']['#value']) {
        $addMore = '_';
      }

      $nid = $node->nid;
      $title = $node->title;
      $path = drupal_realpath('public://');
      $fileName = 'Programme' . $addMore . preg_replace('@[^a-z0-9-]+@', '-', strtolower($node->title)) . '.zip';

      if (file_exists($path . '/Programme/archive/' . $nid . '/')) {
        $filePath = $path . '/Programme/archive/' . $nid . '/' . $fileName;
        if ($filePath) {
          if (file_exists($filePath)) {
            // set headers push to download the zip
            header("Pragma: public");
            header("Expires: 0");
            header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
            header("Cache-Control: public");
            header('Content-type: application/zip');
            header("Content-Transfer-Encoding: Binary");
            header('Content-Disposition: attachment; filename="' . $fileName . '"');
            header("Content-Length: " . filesize($filePath));

            $fp = @fopen($filePath, "rb");
            if ($fp) {
              while (!feof($fp)) {
                echo fread($fp, 8192);
                flush();
                if (connection_status() != 0) {
                  @fclose($filePath);
                  die();
                }
              }
              @fclose($filePath);
            }
            //unlink($filePath);
          }
        }
      }
    }
  }
}

/**
 * Implements hook_node_insert().
 * @param type $node
 */
function kandb_programme_node_insert($node) {
  if ($node->type == 'programme' && $node->is_new == 1) {
    createFileArchireForProgramme($node);
  }
}

/**
 * Implements hook_node_presave()
 * @param type $node
 */
function kandb_programme_node_presave($node) {
  // By pass apply rule in case apply habiteo API.
  if (isset($node->flag_habiteo) && $node->flag_habiteo) {
    return;
  }

  if ($node->type == 'programme' && $node->is_new != 1) {
    createFileArchireForProgramme($node);
  }
}

/**
 * Create file archive
 * @param type $realPath
 * @param type $params
 */
function createFileZip($realPath, $params = array()) {
  $zip = new ZipArchive();
  if ($zip->open($realPath, ZipArchive::CREATE) == TRUE) {
    foreach ($params as $fileName => $filePath) {
      //$zip->addFile(drupal_realpath('public://') . '/' . $fileName, $fileName);
      $zip->addFile(drupal_realpath($filePath), $fileName);
    }

    $zip->close();
  }
}

function getFilenameUriFromFiles($node, $params = array()) {
  $files = array();
  foreach ($params as $field) {
    $fields = $node->$field;
    if (isset($fields[LANGUAGE_NONE][0]['fid'])) {
      $fileInfo = file_load($fields[LANGUAGE_NONE][0]['fid']);
      if ($fileInfo) {
        $files[$fileInfo->filename] = $fileInfo->uri;
      }
    }
  }

  return $files;
}

/**
 * Implements hook_node_delete().
 */
function kandb_programme_node_delete($node) {
  if ($node->type == 'programme') {
    $path = drupal_realpath('public://');

    $dir = $path . '/Programme/archive/' . $node->nid . '/';
    foreach (glob($dir . "/*.*") as $filename) {
      if (is_file($filename)) {
        unlink($filename);
      }
    }
    rmdir($dir);
  }
}

/**
 * Create 2 kind file archive for 2 pages (B2B, B2C)
 * @param type $node
 */
function createFileArchireForProgramme($node) {
  $path = drupal_realpath('public://');
  $fileNameB2B = 'Programme_B2B_' . preg_replace('@[^a-z0-9-]+@', '-', strtolower($node->title)) . '.zip';
  $fileNameB2C = '/Programme_' . preg_replace('@[^a-z0-9-]+@', '-', strtolower($node->title)) . '.zip';

  $dir = $path . '/Programme/archive/' . $node->nid . '/';
  if (file_exists($dir) && $node->nid) {
    foreach (glob($dir . "/*.*") as $filename) {
      if (is_file($filename)) {
        unlink($filename);
      }
    }
    rmdir($dir);
  }

  if (!file_exists($path . '/Programme/')) {
    mkdir($path . '/Programme/', 0777);
  }

  if (!file_exists($path . '/Programme/archive/')) {
    mkdir($path . '/Programme/archive/', 0777);
  }

  if (!file_exists($path . '/Programme/archive/' . $node->nid . '/')) {
    mkdir($path . '/Programme/archive/' . $node->nid . '/', 0777);
  }

  if (file_exists($path . '/Programme/archive/' . $node->nid . '/')) {
    $paramsB2B = getFilenameUriFromFiles($node, array(
      'field_plaquette_commerciale',
      'field_fiche_renseignement',
      'field_plan_batiment',
      'field_kit_fiscal',
      'field_contrat_reservation',
      'field_etat_des_risques',
      'field_lettre_de_banque',
      'field_prestations_programme',
      'field_mandat_gestion_locative',
      'field_plan_masse_sous_sol',
      'field_visuel_grande_taille',
      'field_bail_commercial',
      'field_bon_commande_mobilier',
      'field_autre_documents'
    ));
    $paramsB2C = getFilenameUriFromFiles($node, array(
      'field_plaquette_commerciale',
      'field_fiche_renseignement',
      'field_plan_batiment',
      'field_kit_fiscal',
    ));

    $statusFileB2B = createFileZip($path . '/Programme/archive/' . $node->nid . '/' . $fileNameB2B, $paramsB2B);
    $statusFileB2C = createFileZip($path . '/Programme/archive/' . $node->nid . '/' . $fileNameB2C, $paramsB2C);
  }
}

function _get_program_characteristic_content() {
  $content = '';
  if (arg(0) == 'node' && is_numeric(arg(1)) && arg(2) == NULL) {
    $node = node_load(arg(1));
    if (isset($node->type) && $node->type == 'programme') {
      $programme_variables = array();
      $programme_variables['prestations_titre'] = isset($node->field_prestations_titre[LANGUAGE_NONE][0]['value']) ? $node->field_prestations_titre[LANGUAGE_NONE][0]['value'] : '';
      $programme_variables['prestations_sous_titre'] = isset($node->field_prestations_sous_titre[LANGUAGE_NONE][0]['value']) ? $node->field_prestations_sous_titre[LANGUAGE_NONE][0]['value'] : '';
      //Tab 1
      $programme_variables['slider_exterieur_titre'] = isset($node->field_slider_exterieur_titre[LANGUAGE_NONE][0]['value']) ? $node->field_slider_exterieur_titre[LANGUAGE_NONE][0]['value'] : '';
      $uri = isset($node->field_slider_exterieur_image[LANGUAGE_NONE][0]['uri']) ? $node->field_slider_exterieur_image[LANGUAGE_NONE][0]['uri'] : kandb_settings_get_uri_by_variable('image_default_slider_exterieur_image');
      if ($uri) {
        $programme_variables['slider_exterieur_image_small'] = image_style_url('program_characteristic_small', $uri);
        $programme_variables['slider_exterieur_image_medium'] = image_style_url('program_characteristic_medium', $uri);
        $programme_variables['slider_exterieur_image_alt'] = $node->field_slider_exterieur_image[LANGUAGE_NONE][0]['alt'];
      }
      $programme_variables['slider_exterieur_description'] = isset($node->field_slider_exterieur_desc[LANGUAGE_NONE][0]['value']) ? $node->field_slider_exterieur_desc[LANGUAGE_NONE][0]['value'] : '';
      //Tab 2
      $programme_variables['slider_interieur_titre'] = isset($node->field_slider_interieur_titre[LANGUAGE_NONE][0]['value']) ? $node->field_slider_interieur_titre[LANGUAGE_NONE][0]['value'] : '';
      $uri = isset($node->field_slider_interieur_image[LANGUAGE_NONE][0]['uri']) ? $node->field_slider_interieur_image[LANGUAGE_NONE][0]['uri'] : kandb_settings_get_uri_by_variable('image_default_slider_interieur_image');
      if ($uri) {
        $programme_variables['slider_interieur_image_small'] = image_style_url('program_characteristic_small', $uri);
        $programme_variables['slider_interieur_image_medium'] = image_style_url('program_characteristic_medium', $uri);
        $programme_variables['slider_interieur_image_alt'] = $node->field_slider_interieur_image[LANGUAGE_NONE][0]['alt'];
      }
      $programme_variables['slider_interieur_description'] = isset($node->field_slider_interieur_desc[LANGUAGE_NONE][0]['value']) ? $node->field_slider_interieur_desc[LANGUAGE_NONE][0]['value'] : '';
      //Tab 3
      $programme_variables['slider_securite_titre'] = isset($node->field_slider_securite_titre[LANGUAGE_NONE][0]['value']) ? $node->field_slider_securite_titre[LANGUAGE_NONE][0]['value'] : '';
      $uri = isset($node->field_slider_securite_image[LANGUAGE_NONE][0]['uri']) ? $node->field_slider_securite_image[LANGUAGE_NONE][0]['uri'] : kandb_settings_get_uri_by_variable('image_default_slider_securite_image');
      if ($uri) {
        $programme_variables['slider_securite_image_small'] = image_style_url('program_characteristic_small', $uri);
        $programme_variables['slider_securite_image_medium'] = image_style_url('program_characteristic_medium', $uri);
        $programme_variables['slider_securite_image_alt'] = $node->field_slider_securite_image[LANGUAGE_NONE][0]['alt'];
      }
      $programme_variables['slider_securite_description'] = isset($node->field_slider_securite_desc[LANGUAGE_NONE][0]['value']) ? $node->field_slider_securite_desc[LANGUAGE_NONE][0]['value'] : '';
      //Tab 4
      $programme_variables['slider_rt2012_titre'] = isset($node->field_slider_rt2012_titre[LANGUAGE_NONE][0]['value']) ? $node->field_slider_rt2012_titre[LANGUAGE_NONE][0]['value'] : '';
      $uri = isset($node->field_slider_rt2012_image[LANGUAGE_NONE][0]['uri']) ? $node->field_slider_rt2012_image[LANGUAGE_NONE][0]['uri'] : kandb_settings_get_uri_by_variable('image_default_slider_rt2012_image');
      if ($uri) {
        $programme_variables['slider_rt2012_image_small'] = image_style_url('program_characteristic_small', $uri);
        $programme_variables['slider_rt2012_image_medium'] = image_style_url('program_characteristic_medium', $uri);
        $programme_variables['slider_rt2012_image_alt'] = $node->field_slider_rt2012_image[LANGUAGE_NONE][0]['alt'];
      }
      $programme_variables['slider_rt2012_description'] = isset($node->field_slider_rt2012_desc[LANGUAGE_NONE][0]['value']) ? $node->field_slider_rt2012_desc[LANGUAGE_NONE][0]['value'] : '';
      $content = theme('program_characteristic', array('programme_variables' => $programme_variables, 'node' => $node));
    }
  }

  return $content;
}

/**
 * Count all list bien group by nomber pieces
 * @param int $tid: Status of Bien (Require: Disponible)
 * @param int $key: Programme ID
 * @param int $gid
 * @return array()
 */
function countListBienGroupByNbPieces($tid, $key, $gid) {
  $listBien_query = db_select('node', 'n');
  $listBien_query->join('field_data_field_programme', 'program', 'n.nid=program.field_programme_target_id');
  $listBien_query->join('field_data_field_prix_tva_20', 'prize', 'prize.entity_id = program.entity_id');
  $listBien_query->join('field_data_field_nb_pieces', 'nb', 'nb.entity_id=program.entity_id');
  $listBien_query->join('field_data_field_bien_statut', 'bien', 'bien.entity_id = program.entity_id');
  $listBien_query->join('taxonomy_term_data', 'taxo', 'taxo.tid = nb.field_nb_pieces_tid');
  $listBien_query->leftJoin('field_data_field_programme_stock', 'stock', 'stock.entity_id = program.field_programme_target_id');
  //$listBien_query->join('domain_access', 'da', 'da.nid = program.entity_id');
  $listBien_query->addExpression('count("field_programme_target_id")', 'total');
  $listBien_query->addExpression('GROUP_CONCAT(program.entity_id)', 'bien_id');
  $listBien_query->addExpression("case when name='studio' then 0 else 1 end", 'special_name');
  $listBien_query->groupBy('field_programme_target_id, field_nb_pieces_tid, name, field_programme_stock_value');
  $listBien = $listBien_query
    ->addTag('program_access_domain')
    ->fields('program', array('field_programme_target_id', 'entity_id'))
    ->fields('nb', array('field_nb_pieces_tid'))
    ->fields('n', array('title'))
    ->fields('taxo', array('name'))
    ->fields('stock', array('field_programme_stock_value'))
    ->condition('field_bien_statut_tid', $tid, '=')
    ->condition('field_programme_target_id', $key, '=')
    //->condition('gid', $gid, '=')
    ->orderBy('special_name', 'ASC')
    ->orderBy('name', 'ASC')
    ->execute();

  return $listBien;
}


function countListBienGroupByTypeBien($tid, $key, $gid) {
  $listBien_query = db_select('node', 'n');
  $listBien_query->join('field_data_field_programme', 'program', 'n.nid=program.field_programme_target_id');
  $listBien_query->join('field_data_field_prix_tva_20', 'prize', 'prize.entity_id = program.entity_id');
  $listBien_query->join('field_data_field_bien_statut', 'bien', 'bien.entity_id = program.entity_id');
  $listBien_query->join('field_data_field_type', 'type', 'type.entity_id=bien.entity_id');
  $listBien_query->join('taxonomy_term_data', 'taxo', 'taxo.tid = type.field_type_tid');
  $listBien_query->leftJoin('field_data_field_programme_stock', 'stock', 'stock.entity_id = program.field_programme_target_id');
  $listBien_query->join('domain_access', 'da', 'da.nid = program.entity_id');
  $listBien_query->addExpression('count("field_programme_target_id")', 'total');
  $listBien_query->addExpression('GROUP_CONCAT(program.entity_id)', 'bien_id');
  $listBien_query->addExpression("case when name='studio' then 0 else 1 end", 'special_name');
  $listBien_query->groupBy('field_programme_target_id, field_type_tid, name, field_programme_stock_value');
  $listBien = $listBien_query
    ->addTag('program_access_domain')
    ->fields('program', array('field_programme_target_id', 'entity_id'))
    ->fields('type', array('field_type_tid'))
    ->fields('n', array('title'))
    ->fields('taxo', array('name'))
    ->fields('stock', array('field_programme_stock_value'))
    ->condition('field_bien_statut_tid', $tid, '=')
    ->condition('field_programme_target_id', $key, '=')
    ->condition('gid', $gid, '=')
    ->orderBy('special_name', 'ASC')
    ->orderBy('name', 'ASC')
    ->execute();

  return $listBien;
}
/**
 * Get list the most or the least expensive bien
 * @param int $tid: Status of Bien (Require: Disponible)
 * @param int $key: Programme ID
 * @param int $nb_pieces_id: Type pieces
 * @param int $gid: Domain ID
 * @param string $order
 * @return array()
 */
function getTheMostLeastExpensiveBienByNbPieces($tid, $key, $nb_pieces_id, $gid, $order = 'ASC') {
  $listPriceMost_query = db_select('node', 'n');
  $listPriceMost_query->join('field_data_field_programme', 'program', 'n.nid=program.field_programme_target_id');
  $listPriceMost_query->join('field_data_field_prix_tva_20', 'prize', 'prize.entity_id = program.entity_id');
  $listPriceMost_query->join('field_data_field_nb_pieces', 'nb', 'nb.entity_id=program.entity_id');
  $listPriceMost_query->join('field_data_field_bien_statut', 'bien', 'bien.entity_id = program.entity_id');
  $listPriceMost_query->join('taxonomy_term_data', 'taxo', 'taxo.tid = nb.field_nb_pieces_tid');
  //$listPriceMost_query->leftJoin('domain_access', 'da', 'da.nid = program.entity_id');
  $listPriceMost = $listPriceMost_query
    ->addTag('program_access_domain')
    ->fields('program', array('entity_id'))
    ->fields('prize', array('field_prix_tva_20_value'))
    ->fields('taxo', array('name'))
    ->fields('n', array('title'))
    ->condition('field_bien_statut_tid', $tid,'=')
    ->condition('field_programme_target_id', $key,'=')
    ->condition('field_nb_pieces_tid', $nb_pieces_id,'=')
    //->condition('gid', $gid,'=')
    ->orderBy('field_prix_tva_20_value', $order)
    ->range(0,1)
    ->execute();

  return $listPriceMost;
}


/**
 * Get list remain after exclude biens (the most, the least) after order the superficie_value is asc
 * @param int $tid
 * @param int $key
 * @param int $nb_pieces_id
 * @param int $the_least_id
 * @param int $the_most_id
 * @param int $total_bien_stock
 * @return array()
 */
function getListRemainExcludeMostLeastBien($tid, $key, $nb_pieces_id, $the_least_id, $the_most_id, $gid, $total_bien_stock) {
  $listPriceRemain_query = db_select('node', 'n');
  $listPriceRemain_query->join('field_data_field_programme', 'program', 'n.nid=program.field_programme_target_id');
  $listPriceRemain_query->join('field_data_field_prix_tva_20', 'prize', 'prize.entity_id = program.entity_id');
  $listPriceRemain_query->join('field_data_field_nb_pieces', 'nb', 'nb.entity_id=program.entity_id');
  $listPriceRemain_query->join('field_data_field_bien_statut', 'bien', 'bien.entity_id = program.entity_id');
  $listPriceRemain_query->join('taxonomy_term_data', 'taxo', 'taxo.tid = nb.field_nb_pieces_tid');
  $listPriceRemain_query->leftJoin('field_data_field_superficie', 'super', 'program.entity_id = super.entity_id');
  //$listPriceRemain_query->leftJoin('domain_access', 'da', 'da.nid = program.entity_id');
  $listPriceRemain = $listPriceRemain_query
    ->addTag('program_access_domain')
    ->fields('program', array('entity_id'))
    ->fields('super', array('field_superficie_value'))
    ->fields('prize', array('field_prix_tva_20_value'))
    ->fields('taxo', array('name'))
    ->fields('n', array('title'))
    ->condition('field_bien_statut_tid', $tid,'=')
    ->condition('field_programme_target_id', $key,'=')
    ->condition('field_nb_pieces_tid', $nb_pieces_id,'=')
    ->condition('program.entity_id', array($the_least_id, $the_most_id),'NOT IN')
    //->condition('gid', $gid,'=')
    ->orderBy('field_superficie_value', 'ASC')
    ->range(0, $total_bien_stock)
    ->execute();

  return $listPriceRemain;
}

/**
 * Get list price(max-min) of bien
 * @param type $tid
 * @param type $key
 * @param type $gid
 * @return type
 */
function getListPriceMaxMinofBien($tid, $key, $gid) {
  $listMaxMinPrice_query = db_select('node', 'n');
  $listMaxMinPrice_query->join('field_data_field_programme', 'program', 'n.nid=program.field_programme_target_id');
  $listMaxMinPrice_query->join('field_data_field_prix_tva_20', 'prize', 'prize.entity_id = program.entity_id');
  $listMaxMinPrice_query->join('field_data_field_nb_pieces', 'nb', 'nb.entity_id=program.entity_id');
  $listMaxMinPrice_query->join('field_data_field_bien_statut', 'bien', 'bien.entity_id = program.entity_id');
  $listMaxMinPrice_query->join('taxonomy_term_data', 'taxo', 'taxo.tid = nb.field_nb_pieces_tid');
  $listMaxMinPrice_query->leftJoin('field_data_field_tva', 'tva', 'tva.entity_id=program.field_programme_target_id');
  //$listMaxMinPrice_query->leftJoin('domain_access', 'da', 'da.nid = program.entity_id');
  $listMaxMinPrice_query->addExpression('max(field_prix_tva_20_value)', 'max');
  $listMaxMinPrice_query->addExpression('min(field_prix_tva_20_value)', 'min');
  $listMaxMinPrice_query->addExpression('(select field_facteur_value from field_data_field_facteur fact where fact.entity_id=tva.field_tva_tid)', 'tva');
  $listMaxMinPrice_query->groupBy('field_programme_target_id, field_nb_pieces_tid, name, title');
  $listMaxMinPrice = $listMaxMinPrice_query
    ->addTag('program_access_domain')
    ->fields('program', array('field_programme_target_id'))
    ->fields('nb', array('field_nb_pieces_tid'))
    ->fields('taxo', array('name'))
    ->fields('n', array('title'))
    ->condition('field_bien_statut_tid', $tid,'=')
    ->condition('field_programme_target_id', $key,'=')
    //->condition('gid', $gid,'=')
    ->execute();

  return $listMaxMinPrice;
}
