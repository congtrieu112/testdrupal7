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
 * Get logement block content.
 */
function _get_logement_block_content() {
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

      if ($tid) {
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'promotion')
          ->fieldCondition('field_promotion_programme', 'target_id', $key)
          ->fieldCondition('field_promotion_start', 'value', date("Y-m-d"), '>=')
          ->fieldCondition('field_promotion_stop', 'value', date("Y-m-d"), '<=')
          ->range(0, 1);

        $programme_promotion = $query->execute();
        if (isset($programme_promotion['node'])) {
          $logement_block['programme_promotion'] = TRUE;
        }

        $listBien = db_query('select count(field_programme_target_id) as total, group_concat(program.entity_id) as bien_id, field_programme_target_id, field_nb_pieces_tid, title, name, field_programme_stock_value '
          . 'from {field_data_field_prix_tva_20} prize '
          . 'inner join {field_data_field_programme} program on prize.entity_id = program.entity_id '
          . 'inner join {field_data_field_nb_pieces} nb on nb.entity_id=program.entity_id '
          . 'left join {field_data_field_programme_stock} stock on stock.entity_id = program.field_programme_target_id '
          . 'inner join {taxonomy_term_data} taxo on taxo.tid = nb.field_nb_pieces_tid '
          . 'inner join {node} n on n.nid=program.field_programme_target_id '
          . 'inner join {field_data_field_bien_statut} bien on bien.entity_id = program.entity_id '
          . 'where field_bien_statut_tid=:tid and field_programme_target_id=:key '
          . 'group by field_programme_target_id, field_nb_pieces_tid, name, field_programme_stock_value order by name=:name desc, name', array(':tid' => $tid, ':key' => $key, ':name' => 'studio'));

        if ($listBien->rowCount() > 0) {
          $listBien = $listBien->fetchAll();
          foreach ($listBien as $program_list_biens) {
            $logement_block['total_bien'][$program_list_biens->name] = $program_list_biens->total;

            // Images des types de Lots.
            if (preg_match_all('/(studio|2|3|4|5)/i', $program_list_biens->name, $matches)) {
              $img_num_piece = '';
              if (isset($matches[0][0]) AND $num_piece = $matches[0][0]) {
                $img_num_piece_field = is_numeric($num_piece) ? 'field_image_' . $matches[0][0] . '_piece' : 'field_image_' . $matches[0][0];
                $img_num_piece = field_get_items('node', $node, $img_num_piece_field);
                if (($img_num_piece AND isset($img_num_piece[0]['uri']))) {
                  $img_num_piece = image_style_url('program_image_num_piece', $img_num_piece[0]['uri']);
                }
                else {
                  $image_default_number_piece = variable_get('image_default_number_piece_' . $num_piece);
                  $image_default_number_piece = $image_default_number_piece ? file_load($image_default_number_piece) : '';
                  $img_num_piece = isset($image_default_number_piece->uri) ? image_style_url('program_image_num_piece', $image_default_number_piece->uri) : '';
                }
              }

              $logement_block['programme_bien_images'][$program_list_biens->name] = $img_num_piece;
            }

            $query = new EntityFieldQuery();
            $query->entityCondition('entity_type', 'node')
              ->entityCondition('bundle', 'promotion')
              ->fieldCondition('field_promotion_biens', 'target_id', array($program_list_biens->bien_id), 'IN')
              ->fieldCondition('field_promotion_start', 'value', date("Y-m-d"), '>=')
              ->fieldCondition('field_promotion_stop', 'value', date("Y-m-d"), '<=')
              ->range(0, 1);

            $bien_promotion = $query->execute();

            if (isset($bien_promotion['node'])) {
              $logement_block['bien_promotion'][$program_list_biens->name] = TRUE;
            }

            $total_bien_stock = ceil($program_list_biens->total * $program_list_biens->field_programme_stock_value / 100);
            $logement_block['total_bien_stock'][$program_list_biens->name] = $total_bien_stock;

            $nb_pieces_id = $program_list_biens->field_nb_pieces_tid;
            // Get list the most expensive bien
            $listPriceMost = db_query_range('select program.entity_id, field_prix_tva_20_value, name, title '
              . 'from {field_data_field_prix_tva_20 prize} '
              . 'inner join {field_data_field_programme} program on prize.entity_id = program.entity_id '
              . 'inner join {field_data_field_nb_pieces} nb on nb.entity_id=program.entity_id '
              . 'inner join {field_data_field_bien_statut} bien on bien.entity_id = program.entity_id '
              . 'inner join {taxonomy_term_data} taxo on taxo.tid = nb.field_nb_pieces_tid '
              . 'inner join {node} n on n.nid=program.field_programme_target_id '
              . 'where field_bien_statut_tid=:tid and field_programme_target_id=:program_id and field_nb_pieces_tid=:nb_pieces_id '
              . 'order by field_prix_tva_20_value desc', 0, 1, array(':tid' => $tid, ':program_id' => $key, ':nb_pieces_id' => $nb_pieces_id));

            $the_most_id = 0;
            // Show results
            if ($listPriceMost->rowCount() > 0) {
              $listPriceMost = $listPriceMost->fetchAll();
              foreach ($listPriceMost as $program_most) {
                $total_bien_stock -= 1;
                $the_most_id = $program_most->entity_id;
                $logement_block['popin_program'][$program_most->name][] = $program_most->entity_id;
              }
            }


            if ($total_bien_stock > 0) {
              // Sql get list the least expensive bien
              $listPriceLeast = db_query_range('select program.entity_id as entity_id, field_prix_tva_20_value, name, title '
                . 'from {field_data_field_prix_tva_20} prize '
                . 'inner join {field_data_field_programme} program on prize.entity_id = program.entity_id '
                . 'inner join {field_data_field_nb_pieces} nb on nb.entity_id=program.entity_id '
                . 'inner join {field_data_field_bien_statut} bien on bien.entity_id = program.entity_id '
                . 'inner join {taxonomy_term_data} taxo on taxo.tid = nb.field_nb_pieces_tid '
                . 'inner join {node} n on n.nid=program.field_programme_target_id '
                . 'where field_bien_statut_tid=:tid and field_programme_target_id=:program_id and field_nb_pieces_tid=:nb_pieces_id '
                . 'order by field_prix_tva_20_value', 0, 1, array(':tid' => $tid, ':program_id' => $key, ':nb_pieces_id' => $nb_pieces_id));


              // Show results
              $the_least_id = 0;
              if ($listPriceLeast->rowCount() > 0) {
                $listPriceLeast = $listPriceLeast->fetchAll();
                foreach ($listPriceLeast as $program_least) {
                  $total_bien_stock -= 1;
                  $the_least_id = $program_least->entity_id;
                  $logement_block['popin_program'][$program_least->name][] = $program_least->entity_id;
                }
              }
            }

            if ($total_bien_stock > 0) {
              $listPriceRemain = db_query_range('select program.entity_id as entity_id, field_superficie_value, field_prix_tva_20_value, name, title '
                . 'from {field_data_field_prix_tva_20} prize '
                . 'inner join {field_data_field_programme} program on prize.entity_id = program.entity_id '
                . 'inner join {field_data_field_nb_pieces} nb on nb.entity_id=program.entity_id '
                . 'inner join {field_data_field_bien_statut} bien on bien.entity_id = program.entity_id '
                . 'inner join {taxonomy_term_data} taxo on taxo.tid = nb.field_nb_pieces_tid '
                . 'inner join {node} n on n.nid=program.field_programme_target_id '
                . 'left join {field_data_field_superficie} super on program.entity_id = super.entity_id '
                . 'where field_bien_statut_tid=:tid and field_programme_target_id=:program_id and field_nb_pieces_tid=:nb_pieces_id and program.entity_id not in(:least, :most) '
                . 'order by field_superficie_value', 0, $total_bien_stock, array(':tid' => $tid, ':program_id' => $key, ':nb_pieces_id' => $nb_pieces_id, ':least' => $the_least_id, ':most' => $the_most_id));

              if ($listPriceRemain->rowCount() > 0) {
                $listPriceRemain = $listPriceRemain->fetchAll();
                foreach ($listPriceRemain as $program_remain) {
                  $the_least_id = $program_remain->entity_id;
                  $logement_block['popin_program'][$program_remain->name][] = $program_remain->entity_id;
                }
              }
            }
          }
        }

        $listMaxMinPrice = db_query('select max(field_prix_tva_20_value) as max, min(field_prix_tva_20_value) as min, '
          . '(select field_facteur_value '
          . 'from {field_data_field_facteur} fact '
          . 'where fact.entity_id=tva.field_tva_tid) as tva, '
          . 'field_programme_target_id, field_nb_pieces_tid, name, title '
          . 'from field_data_field_prix_tva_20 prize '
          . 'inner join {field_data_field_programme} program on prize.entity_id = program.entity_id '
          . 'inner join {field_data_field_nb_pieces} nb on nb.entity_id=program.entity_id '
          . 'inner join {taxonomy_term_data} taxo on taxo.tid = nb.field_nb_pieces_tid '
          . 'inner join {node} n on n.nid=program.field_programme_target_id '
          . 'inner join {field_data_field_bien_statut} bien on bien.entity_id = program.entity_id '
          . 'left join {field_data_field_tva} tva on tva.entity_id=program.field_programme_target_id '
          . 'where field_bien_statut_tid=:tid and field_programme_target_id=:key '
          . 'group by field_programme_target_id, field_nb_pieces_tid, name, title', array(':tid' => $tid, ':key' => $key));

        // Show results
        if ($listMaxMinPrice->rowCount() > 0) {
          $listMaxMinPrice = $listMaxMinPrice->fetchAll();
          foreach ($listMaxMinPrice as $program_prices) {
            $logement_block['price_min_tva20_bien'][$program_prices->name] = $program_prices->min;
            $tva = isset($program_prices->tva) ? $program_prices->tva : 0;
            $min = isset($program_prices->min) ? $program_prices->min : 0;
            if ($tva) {
              $logement_block['tva_bien'][$program_prices->name] = $tva;
              $logement_block['price_min_tva_un_20_bien'][$program_prices->name] = $min / 1.2 * ($tva + 1);
            }
          }
        }
      }
    }
  }

  return theme('kandb_programme', array('logement_block' => $logement_block));
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
