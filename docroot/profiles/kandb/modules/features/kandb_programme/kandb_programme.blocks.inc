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
  return theme('kandb_programme');
}

/**
 * Implements of hook_theme().
 */
function kandb_programme_theme($existing, $type, $theme, $path) {
  return array(
    'kandb_programme' => array(
      'template' => 'templates/kandb_programme',
      'variables' => array('main_menu' => NULL),
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
  }
  return $block;
}

function numberFormatGlobal($number) {
  return number_format($number, 0, ",", ".");
}

/**
 * Get logement block content.
 */
function _get_logement_block_content() {
  $blocks = array();
  $type = arg(0);
  $key = arg(1);
  $page = arg(2);

  $terms = taxonomy_get_term_by_name('Disponible / Libre');
  
  $tid = 0;
  if ($terms) {
    foreach ($terms as $id => $term) {
      $tid = $id;
    }
  }

  if ($type && $key && $page) {
    if ($type == 'programme' && $tid > 0) {
      // Get minimum price and maximumm price
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
        $str_price_max_min = '';
        foreach ($listMaxMinPrice as $program_prices) {
          $tva = ($program_prices->tva == NULL) ? 0 : $program_prices->tva;
          $price_tva_min = round(($program_prices->min / 1.2) * ($tva + 1));
          $price_tva_max = round(($program_prices->max / 1.2) * ($tva + 1));
          $str_price_max_min .= 'Title:  ' . "<b>" . $program_prices->title . "</b>" . "</br>";
          $str_price_max_min .= 'Type:  ' . $program_prices->name . "</br>";
          $str_price_max_min .= 'Price:  ' . '$' . numberFormatGlobal($program_prices->min) . ' - ' . '$' . numberFormatGlobal($program_prices->max) . "</br>";
          $str_price_max_min .= 'Price tva: ' . '$' . numberFormatGlobal($price_tva_min) . ' - ' . '$' . numberFormatGlobal($price_tva_max) . "</br>";
          $str_price_max_min .= '----------------------------------------------------------------------------------------------------------------' . "</br></br>";
        }
        $blocks['rs_price_max_min'] = $str_price_max_min;
      }

      // Get list, total bien with current programme
      $listBien = db_query('select count(field_programme_target_id) as total, field_programme_target_id, field_nb_pieces_tid, title, name, field_programme_stock_value '
        . 'from {field_data_field_prix_tva_20} prize '
        . 'inner join {field_data_field_programme} program on prize.entity_id = program.entity_id '
        . 'inner join {field_data_field_nb_pieces} nb on nb.entity_id=program.entity_id '
        . 'inner join {field_data_field_programme_stock} stock on stock.entity_id = program.field_programme_target_id '
        . 'inner join {taxonomy_term_data} taxo on taxo.tid = nb.field_nb_pieces_tid '
        . 'inner join {node} n on n.nid=program.field_programme_target_id '
        . 'inner join {field_data_field_bien_statut} bien on bien.entity_id = program.entity_id '
        . 'where field_bien_statut_tid=:tid and field_programme_target_id=:key '
        . 'group by field_programme_target_id, field_nb_pieces_tid, name, field_programme_stock_value', array(':tid' => $tid, ':key' => $key));

      if ($listBien->rowCount() > 0) {
        $listBien = $listBien->fetchAll();
        $str_price_most = '';
        $str_price_least = '';
        foreach ($listBien as $program_list_biens) {

          $total = ceil($program_list_biens->total * $program_list_biens->field_programme_stock_value / 100);
          $nb_pieces_id = $program_list_biens->field_nb_pieces_tid;
          $least = (int) ($total / 2);
          $most = round($total / 2);

          // Get list the most expensive bien
          $listPriceMost = db_query_range('select field_prix_tva_20_value, name, title '
            . 'from {field_data_field_prix_tva_20 prize} '
            . 'inner join {field_data_field_programme} program on prize.entity_id = program.entity_id '
            . 'inner join {field_data_field_nb_pieces} nb on nb.entity_id=program.entity_id '
            . 'inner join {field_data_field_bien_statut} bien on bien.entity_id = program.entity_id '
            . 'inner join {taxonomy_term_data} taxo on taxo.tid = nb.field_nb_pieces_tid '
            . 'inner join {node} n on n.nid=program.field_programme_target_id '
            . 'where field_bien_statut_tid=:tid and field_programme_target_id=:program_id and field_nb_pieces_tid=:nb_pieces_id '
            . 'order by field_prix_tva_20_value desc', 0, $most, array(':tid' => $tid, ':program_id' => $key, ':nb_pieces_id' => $nb_pieces_id));

          // Show results
          if ($listPriceMost->rowCount() > 0) {
            $listPriceMost = $listPriceMost->fetchAll();
            $str_price_most = "<h6>The most experience</h6>" . "</br>";
            $nb_pieces_most = '';
            foreach ($listPriceMost as $programs_most) {
              $nb_pieces_most = $programs_most->name;
              $str_price_most .= 'Title: ' . $programs_most->title . "</br>";
              $str_price_most .= 'Name: ' . $programs_most->name . "</br>";
              $str_price_most .= 'Price:  ' . '$' . numberFormatGlobal($programs_most->field_prix_tva_20_value) . "</br>";
              $str_price_most .= '----------------------------------------------------------------------------------------------------------------' . "</br></br>";
            }
            $blocks['rs_price_most'][$nb_pieces_most] = $str_price_most;
          }


          // Sql get list the least expensive bien
          $listPriceLeast = db_query_range('select field_prix_tva_20_value, name, title '
            . 'from {field_data_field_prix_tva_20} prize '
            . 'inner join {field_data_field_programme} program on prize.entity_id = program.entity_id '
            . 'inner join {field_data_field_nb_pieces} nb on nb.entity_id=program.entity_id '
            . 'inner join {field_data_field_bien_statut} bien on bien.entity_id = program.entity_id '
            . 'inner join {taxonomy_term_data} taxo on taxo.tid = nb.field_nb_pieces_tid '
            . 'inner join {node} n on n.nid=program.field_programme_target_id '
            . 'where field_bien_statut_tid=:tid and field_programme_target_id=:program_id and field_nb_pieces_tid=:nb_pieces_id '
            . 'order by field_prix_tva_20_value', 0, $least, array(':tid' => $tid, ':program_id' => $key, ':nb_pieces_id' => $nb_pieces_id));

          // Show results
          if ($listPriceLeast->rowCount() > 0) {
            $listPriceLeast = $listPriceLeast->fetchAll();
            $str_price_least = "<h6>The least experience</h6>" . "</br>";
            $nb_pieces_least = '';
            foreach ($listPriceLeast as $programs_least) {
              $nb_pieces_least = $programs_least->name;
              $str_price_least .= 'Title: ' . $programs_least->title . "</br>";
              $str_price_least .= 'Name: ' . $programs_least->name . "</br>";
              $str_price_least .= 'Price:  ' . '$' . numberFormatGlobal($programs_least->field_prix_tva_20_value) . "</br>";
              $str_price_least .= '----------------------------------------------------------------------------------------------------------------' . "</br></br>";
            }
            $blocks['rs_price_least'][$nb_pieces_least] = $str_price_least;
          }
        }
      }
    }
  }

  return $blocks;
}

function document_block_form($form, &$form_submit) {
  $form['submit'] = array('#type' => 'submit', '#value' => t('Tous télécharger'));
  return $form;
}

function document_block_form_submit() {
  $type = arg(0);
  $key = arg(1);
  $page = arg(2);

  if ($type && $key && $page) {
    if ($type == 'programme') {
      $node = node_load($key);

      if ($node) {
        $addMore = ($page == 'B2B') ? '_B2B_' : '_';

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
