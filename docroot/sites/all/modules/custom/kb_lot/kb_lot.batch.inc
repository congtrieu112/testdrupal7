<?php

class import_lot_batch {

  public static
    function start() {
    batch_import_lot_prepare();
  }

}

function batch_import_lot_prepare() {
  $file_name = 'LOT.TXT';
  // Get the contents of the .sql file.
  $file_content = file_get_contents(drupal_get_path('module', 'kb_lot') . '/' . $file_name);
  // Split into individual statements based on new lines.
  $statements = preg_split('/[|]/', $file_content, -1, PREG_SPLIT_NO_EMPTY);
  $statements = array_map('trim', $statements);

  $batch = array(
    'operations' => array(
      array('batch_import_lot_process', array($statements)),
    ),
    'finished' => 'batch_import_lot_finished',
    'title' => t('Processing Import Lot Batch'),
    'init_message' => t('Import Lot is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Import Lot Batch has encountered an error.'),
    'file' => drupal_get_path('module', 'kb_lot') . '/kb_lot.batch.inc',
  );
  batch_set($batch);
  batch_process('admin');
}

function batch_import_lot_process($statements, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['results']['processed'] = 0;
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['statements'] = $statements;
    $context['sandbox']['max'] = count($statements);
  }

  $limit = 500;
  $count = 0;
  if ($limit > count($context['sandbox']['statements'])) {
    $limit = count($context['sandbox']['statements']);
  }

  while ($count < $limit) {
    $content = $context['sandbox']['statements'][$count];
    $arr_content = explode(chr(164), $content);

    $date_liv = isset($arr_content[31]) ? $arr_content[31] : 0;
    if ($date_liv != '') {
      $date_liv = strtotime($arr_content[31]);
    } else {
      $date_liv = 0;
    }

    if ($arr_content[0]) {
      module_load_include('php', 'kb_program', 'KBAPI');
      $KBAPI = new KBAPI();

      $result = db_select('lot', 'kblo')
        ->fields('kblo', array('idkp', 'idktl', 'nbre_pieces', 'nbre_chambres', 'etage', 'idko', 'statut', 'visibilite'))
        ->condition('idkl', $arr_content[0])
        ->range(0, 1)
        ->execute()
        ->fetchAssoc();

      $status = 0;
      if ($result) {
        try {
          $status = db_update('lot') // Table name no longer needs {}
            ->fields(array(
              'idkp' => (int) $arr_content[1],
              'idktl' => $arr_content[2],
              'price' => (int) $arr_content[3],
              'nbre_pieces' => (int) $arr_content[4],
              'nbre_chambres' => (int) $arr_content[5],
              'etage' => (int) $arr_content[6],
              'duplex' => (int) $arr_content[8],
              'surface ' => floatval(str_replace(",", ".", $arr_content[9])),
              'idko' => $arr_content[10],
              'description_fr' => utf8_encode($arr_content[11]),
              'description_uk' => utf8_encode($arr_content[12]),
              'url_visite' => utf8_encode($arr_content[13]),
              'idkm' => (int) $arr_content[14],
              'label_model' => (int) $arr_content[15],
              'garden ' => floatval(str_replace(",", ".", $arr_content[16])),
              'balcon ' => floatval(str_replace(",", ".", $arr_content[17])),
              'loggia ' => floatval(str_replace(",", ".", $arr_content[18])),
              'terrace ' => floatval(str_replace(",", ".", $arr_content[19])),
              'terrain ' => floatval(str_replace(",", ".", $arr_content[20])),
              'parking' => (int) $arr_content[21],
              'box' => (int) str_replace("-", "", $arr_content[22]),
              'cave' => (int) str_replace("-", "", $arr_content[23]),
              'opportunite' => (int) $arr_content[24],
              'res_second' => (int) $arr_content[25],
              'pls' => (int) $arr_content[26],
              'statut' => $arr_content[27],
              'lib_parking' => utf8_encode($arr_content[28]),
              'lib_cave' => utf8_encode($arr_content[29]),
              'visibilite' => $arr_content[30],
              'date_liv' => $date_liv,
            ))
            ->condition('idkl', $arr_content[0])
            ->execute();

          $arr_taxo = array(
            'idktl' => $arr_content[2],
            'nbre_pieces' => (int) $arr_content[4],
            'nbre_chambres' => (int) $arr_content[5],
            'etage' => (int) $arr_content[6],
            'idko' => $arr_content[10],
            'statut' => $arr_content[27],
            'visibilite' => $arr_content[30],
          );
          foreach ($arr_taxo as $key_taxo => $value_taxo) {
            if ($value_taxo) {
              //$pieces = explode("_", $key_taxo);
              //$tbl_name = $pieces[0];
              $field_name = $key_taxo;

              $result_new = $KBAPI->getTaxonomyTermDataByFieldName('field_' . $field_name, $value_taxo);
              $result_old = $KBAPI->getTaxonomyTermDataByFieldName('field_' . $field_name, $result[$field_name]);

              $data_new = '';
              if($result_new && is_array($result_new['taxonomy_term'])) {
                $data_new = reset($result_new['taxonomy_term']);
              }

              $data_old = '';
              if($result_old && is_array($result_old['taxonomy_term'])) {
                $data_old = reset($result_old['taxonomy_term']);
              }

              if ($data_new) {
                if ($result[$field_name] != $value_taxo) {
                  $num_deleted = 0;
                  if ($data_old) {
                    try {
                      $KBAPI->deleteTableIndex('lot_index', 'idkl', $arr_content[0], $data_old->tid);
                      $KBAPI->deleteTableIndex('lot_index', 'idkl', $arr_content[0], $data_new->tid);
                    }
                    catch (Exception $ex) {
                      watchdog('PHP', "Deleted(updated) lot-index error: %error", array('%error' => $e), WATCHDOG_ERROR);
                    }

                    $KBAPI->insertTableIndex('lot_index', 'idkl', $arr_content[0], $data_new->tid);
                  }
                }
              }
            }
          }
        }
        catch (Exception $ex) {
          watchdog('PHP', "Import(updated) file lot error: Last id inserted:%id.<br/>%error", array('%id' => $arr_content[0], '%error' => $e), WATCHDOG_ERROR);
        }

        $context['results']['processed'] ++;
        $context['sandbox']['progress'] ++;

        unset($context['sandbox']['statements'][$count]);
        $count++;

        continue;
      }

      try {
        //error_log('idkl: ' . $arr_content[0]);
        $id = db_insert('lot') // Table name no longer needs {}
          ->fields(array(
            'idkl' => $arr_content[0],
            'idkp' => (int) $arr_content[1],
            'idktl' => $arr_content[2],
            'price' => (int) $arr_content[3],
            'nbre_pieces' => (int) $arr_content[4],
            'nbre_chambres' => (int) $arr_content[5],
            'etage' => (int) $arr_content[6],
            'duplex' => (int) $arr_content[8],
            'surface ' => floatval(str_replace(",", ".", $arr_content[9])),
            'idko' => $arr_content[10],
            'description_fr' => utf8_encode($arr_content[11]),
            'description_uk' => utf8_encode($arr_content[12]),
            'url_visite' => utf8_encode($arr_content[13]),
            'idkm' => (int) $arr_content[14],
            'label_model' => (int) $arr_content[15],
            'garden ' => floatval(str_replace(",", ".", $arr_content[16])),
            'balcon ' => floatval(str_replace(",", ".", $arr_content[17])),
            'loggia ' => floatval(str_replace(",", ".", $arr_content[18])),
            'terrace ' => floatval(str_replace(",", ".", $arr_content[19])),
            'terrain ' => floatval(str_replace(",", ".", $arr_content[20])),
            'parking' => (int) $arr_content[21],
            'box' => (int) str_replace("-", "", $arr_content[22]),
            'cave' => (int) str_replace("-", "", $arr_content[23]),
            'opportunite' => (int) $arr_content[24],
            'res_second' => (int) $arr_content[25],
            'pls' => (int) $arr_content[26],
            'statut' => $arr_content[27],
            'lib_parking' => utf8_encode($arr_content[28]),
            'lib_cave' => utf8_encode($arr_content[29]),
            'visibilite' => $arr_content[30],
            'date_liv' => $date_liv,
          ))
          ->execute();

        $arr_taxo = array(
          'idktl' => $arr_content[2],
          'nbre_pieces' => (int) $arr_content[4],
          'nbre_chambres' => (int) $arr_content[5],
          'etage' => (int) $arr_content[6],
          'idko' => $arr_content[10],
          'statut' => $arr_content[27],
          'visibilite' => $arr_content[30],
        );
        foreach ($arr_taxo as $key_taxo => $value_taxo) {
          //error_log('key: ' . $key_taxo);
          //error_log('value: ' . $value_taxo);
          if ($value_taxo) {
            //$pieces = explode("_", $key_taxo);
            //$tbl_name = $pieces[0];
            $field_name = $key_taxo;

            $result_new = $KBAPI->getTaxonomyTermDataByFieldName('field_' . $field_name, $value_taxo);

            $data_new = '';
            if($result_new && is_array($result_new['taxonomy_term'])) {
              $data_new = reset($result_new['taxonomy_term']);
            }
            //error_log('key: ' . $key_taxo . ', value: ' . $value_taxo . ', data_new: ' .$data_new->tid);
            if ($data_new) {
              //error_log('Delete: ' . $data_new->tid);
              if ($result[$field_name] != $value_taxo) {
                try {
                  $KBAPI->deleteTableIndex('lot_index', 'idkl', $arr_content[0], $data_new->tid);
                }
                catch (Exception $ex) {
                  watchdog('PHP', "Deleted(inserted) lot-index error: %error", array('%error' => $e), WATCHDOG_ERROR);
                }
                //error_log('Insert: ' . $data_new->tid);
                $KBAPI->insertTableIndex('lot_index', 'idkl', $arr_content[0], $data_new->tid);
              }
            }

          }
        }
      }
      catch (Exception $e) {
        watchdog('PHP', "Import(inserted) file lot  error: Last id inserted:%id.<br/>%error", array('%id' => $arr_content[0], '%error' => $e), WATCHDOG_ERROR);
      }

      $context['results']['processed'] ++;
      $context['sandbox']['progress'] ++;
    }

    unset($context['sandbox']['statements'][$count]);
    $count++;
  }

  $context['message'] = 'Processed '. $context['sandbox']['progress'] . '/' . $context['sandbox']['max'] . ' terms';

  //error_log('Count statements: ' . count($context['sandbox']['statements']));
  if (count($context['sandbox']['statements']) > 0) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    //error_log('Finish 1: ' . $context['finished']);
    $context['sandbox']['statements'] = array_values($context['sandbox']['statements']);
  } else {
    //error_log('Finish 2: ' . $context['finished']);
    $context['finished'] = 1;
  }
}

/**
 * Batch 'finished' callback
 */
function batch_import_lot_finished($success, $results, $operations) {
  $message = $results['processed'] . ' processed.';
  drupal_set_message($message);
}
