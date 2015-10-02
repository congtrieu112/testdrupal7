<?php

class import_program_batch {

  public static
    function start() {
    batch_import_program_prepare();
  }

}

function batch_import_program_prepare() {
  $file_name = 'PROGRAMME.TXT';
  // Get the contents of the .sql file.
  $file_content = file_get_contents(drupal_get_path('module', 'kb_program') . '/' . $file_name);
  // Split into individual statements based on new lines.
  $statements = preg_split('/[|]/', $file_content, -1, PREG_SPLIT_NO_EMPTY);
  $statements = array_map('trim', $statements);

  $batch = array(
    'operations' => array(
      array('batch_import_program_process', array($statements)),
    ),
    'finished' => 'batch_import_program_finished',
    'title' => t('Processing Import Lot Batch'),
    'init_message' => t('Import Program is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Import Lot Batch has encountered an error.'),
    'file' => drupal_get_path('module', 'kb_program') . '/kb_program.batch.inc',
  );
  batch_set($batch);
  batch_process('admin');
}

function batch_import_program_process($statements, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['results']['processed'] = 0;
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['statements'] = $statements;
    $context['sandbox']['max'] = count($statements);
  }

  $limit = 100;
  $count = 0;
  if ($limit > count($context['sandbox']['statements'])) {
    $limit = count($context['sandbox']['statements']);
  }

  while ($count < $limit) {
    $content = $context['sandbox']['statements'][$count];
    $arr_content = explode(chr(164), $content);

    $date_liv = isset($arr_content[31]) ? $arr_content[31] : 0;
    if ($date_liv) {
      $date_liv = strtotime($arr_content[31]);
    }

    if ($arr_content[0]) {
      $arr_program = array(
        'idkp' => (int) $arr_content[0],
        'name' => utf8_encode($arr_content[1]),
        'idkb' => $arr_content[2],
        'idkz' => (int) $arr_content[3],
        'idk' => (int) $arr_content[4],
        'idka' => (int) $arr_content[5],
        'nbr_lot' => (int) $arr_content[6],
        'street_num' => (int) $arr_content[7],
        'voie_type' => $arr_content[8],
        'street_name' => utf8_encode($arr_content[9]),
        'code_postal' => $arr_content[10],
        'exception' => (int) $arr_content[11],
        'delivery_quarter' => $arr_content[12],
        'delivery_year' => $arr_content[13],
        'idktp' => $arr_content[14],
        'idkc' => $arr_content[15],
        'price_min' => floatval(str_replace(",", ".", $arr_content[16])),
        'price_avg' => floatval(str_replace(",", ".", $arr_content[17])),
        'x' => $arr_content[18],
        'y' => $arr_content[19],
        'transport1' => $arr_content[20],
        'transport2' => $arr_content[21],
        'transport3' => $arr_content[22],
        'transport4' => $arr_content[23],
        'reduced_vat' => (int) $arr_content[24],
        'poss_box_garage' => (int) $arr_content[25],
        'ideal_investor' => (int) $arr_content[26],
        'gardien' => (int) $arr_content[27],
        'qualitel' => (int) $arr_content[28],
        'digicode' => (int) $arr_content[29],
        'hqe' => (int) $arr_content[30],
        'air_conditioning' => (int) $arr_content[31],
        'elevator' => (int) $arr_content[32],
        'url_virtual_area' => utf8_encode($arr_content[33]),
        'url_virtual_accom' => utf8_encode($arr_content[34]),
        'short_desc_fr' => utf8_encode($arr_content[35]),
        'long_desc_fr' => utf8_encode($arr_content[36]),
        'short_desc_uk' => utf8_encode($arr_content[37]),
        'long_desc_uk' => utf8_encode($arr_content[38]),
        'accuse_doc_fr' => utf8_encode($arr_content[39]),
        'accuse_rdv_fr' => utf8_encode($arr_content[40]),
        'accuse_doc_uk' => utf8_encode($arr_content[41]),
        'accuse_rdv_uk' => utf8_encode($arr_content[42]),
        'email_doc1' => utf8_encode($arr_content[43]),
        'email_rdv1' => utf8_encode($arr_content[44]),
        'email_doc2' => utf8_encode($arr_content[45]),
        'email_rdv2' => utf8_encode($arr_content[46]),
        'email_doc3' => utf8_encode($arr_content[47]),
        'email_rdv3' => utf8_encode($arr_content[48]),
        'bdv_seller_nom' => utf8_encode($arr_content[49]),
        'bdv_address' => utf8_encode($arr_content[50]),
        'bdv_dept' => utf8_encode($arr_content[51]),
        'bdv_city' => utf8_encode($arr_content[52]),
        'bdv_tel1' => $arr_content[53],
        'bdv_tel2' => $arr_content[54],
        'bdv_email' => utf8_encode($arr_content[55]),
        'bdv_hours_fr' => utf8_encode($arr_content[56]),
        'bdv_hours_uk' => utf8_encode($arr_content[57]),
        'bdv_x' => $arr_content[58],
        'bdv_y' => $arr_content[59],
        'prg_env_leg1' => utf8_encode($arr_content[60]),
        'prg_env_leg2' => utf8_encode($arr_content[61]),
        'prg_env_leg3' => utf8_encode($arr_content[62]),
        'link_useful_text1' => utf8_encode($arr_content[63]),
        'link_useful_url1' => utf8_encode($arr_content[64]),
        'link_useful_text2' => utf8_encode($arr_content[65]),
        'link_useful_url2' => utf8_encode($arr_content[66]),
        'link_useful_text3' => utf8_encode($arr_content[67]),
        'link_useful_url3' => utf8_encode($arr_content[68]),
        'acc_name' => utf8_encode($arr_content[69]),
        'acc_firstname' => utf8_encode($arr_content[70]),
        'acc_phone' => $arr_content[71],
        'acc_fax' => $arr_content[72],
        'acc_email' => utf8_encode($arr_content[73]),
        'asl_name' => utf8_encode($arr_content[74]),
        'asl_address' => utf8_encode($arr_content[75]),
        'asl_code_postal' => $arr_content[76],
        'asl_city' => utf8_encode($arr_content[77]),
        'asl_tel' => $arr_content[78],
        'asl_fax' => $arr_content[79],
        'asl_email' => utf8_encode($arr_content[80]),
        'cc_email' => utf8_encode($arr_content[81]),
        'sav_address' => utf8_encode($arr_content[82]),
        'sav_telephone' => $arr_content[83],
        'sav_fax' => $arr_content[84],
        'sav_email' => utf8_encode($arr_content[85]),
        'sav_name' => utf8_encode($arr_content[86]),
        'sav_prename' => utf8_encode($arr_content[87]),
        'csr_address' => utf8_encode($arr_content[88]),
        'csr_fax' => $arr_content[89],
        'csr_telephone' => $arr_content[90],
        'csr_email' => utf8_encode($arr_content[91]),
      );

      $arr_program_serialize = serialize($arr_program);

      module_load_include('php', 'kb_program', 'KBAPI');
      $KBAPI = new KBAPI();

      $result = db_select('program', 'kbpr')
        ->fields('kbpr', array('idkb', 'idkz', 'voie_type', 'idktp', 'idkc', 'idk', 'idka'))
        ->condition('idkp', (int) $arr_content[0])
        ->range(0, 1)
        ->execute()
        ->fetchAssoc();

      if ($result) {
        try {
          unset($arr_program['idkp']);
          db_update('program')
            ->fields($arr_program)
            ->condition('idkp', (int) $arr_content[0])
            ->execute();

          $arr_taxo = array(
            'idkb' => $arr_content[2],
            'idkz' => (int) $arr_content[3],
            'voie_type' => $arr_content[8],
            'idktp' => $arr_content[14],
            'idkc' => $arr_content[15],
            'idk' => (int) $arr_content[4],
            'idka' => (int) $arr_content[5],
          );
          foreach ($arr_taxo as $key_taxo => $value_taxo) {
            if ($value_taxo) {
              //$pieces = explode("_", $key_taxo);
              //$tbl_name = $pieces[0];
              $field_name = $key_taxo;

              $result_new = $KBAPI->getTaxonomyTermDataByFieldName('field_' . $field_name, $value_taxo);
              $result_old = $KBAPI->getTaxonomyTermDataByFieldName('field_' . $field_name, $result[$field_name]);

              $data_new = '';
              if ($result_new && is_array($result_new['taxonomy_term'])) {
                $data_new = reset($result_new['taxonomy_term']);
              }

              $data_old = '';
              if ($result_old && is_array($result_old['taxonomy_term'])) {
                $data_old = reset($result_old['taxonomy_term']);
              }

              if ($data_new) {
                if ($result[$field_name] != $value_taxo) {
                  $num_deleted = 0;
                  if ($data_old) {
                    try {
                      $KBAPI->deleteTableIndex('program_index', 'idkp', (int) $arr_content[0], $data_old->tid);
                      $KBAPI->deleteTableIndex('program_index', 'idkp', (int) $arr_content[0], $data_new->tid);
                    }
                    catch (Exception $ex) {
                      watchdog('PHP', "Deleted(updated) program-index error: %error", array('%error' => $e), WATCHDOG_ERROR);
                    }

                    $KBAPI->insertTableIndex('program_index', 'idkp', (int) $arr_content[0], $data_new->tid);
                  }
                }
              }
            }
          }
        }
        catch (Exception $ex) {
          //error_log($ex);
          watchdog('PHP', "Import(updated) file program error: Last id inserted:%id.<br/>%error", array('%id' => $arr_content[0], '%error' => $e), WATCHDOG_ERROR);
          die();
        }

        insert_node_programme($arr_content, $arr_program_serialize);

        $context['results']['processed'] ++;
        $context['sandbox']['progress'] ++;

        unset($context['sandbox']['statements'][$count]);
        $count++;

        continue;
      }

      try {
        $id = db_insert('program') // Table name no longer needs {}
          ->fields($arr_program)
          ->execute();

        $arr_taxo = array(
          'idkb' => $arr_content[2],
          'idkz' => (int) $arr_content[3],
          'voie_type' => $arr_content[8],
          'idktp' => $arr_content[14],
          'idkc' => $arr_content[15],
          'idk' => (int) $arr_content[4],
          'idka' => (int) $arr_content[5],
        );
        foreach ($arr_taxo as $key_taxo => $value_taxo) {
          if ($value_taxo) {
            //$pieces = explode("_", $key_taxo);
            //$tbl_name = $pieces[0];
            $field_name = $key_taxo;

            $result_new = $KBAPI->getTaxonomyTermDataByFieldName('field_' . $field_name, $value_taxo);

            $data_new = '';
            if ($result_new && is_array($result_new['taxonomy_term'])) {
              $data_new = reset($result_new['taxonomy_term']);
            }

            if ($data_new) {
              if ($result[$field_name] != $value_taxo) {
                try {
                  $KBAPI->deleteTableIndex('program_index', 'idkp', (int) $arr_content[0], $data_new->tid);
                }
                catch (Exception $ex) {
                  watchdog('PHP', "Deleted(inserted) program-index error: %error", array('%error' => $e), WATCHDOG_ERROR);
                }

                $KBAPI->insertTableIndex('program_index', 'idkp', (int) $arr_content[0], $data_new->tid);
              }
            }
          }
        }
      }
      catch (Exception $e) {
        watchdog('PHP', "Import(inserted) file program error: Last id inserted:%id.<br/>%error", array('%id' => $id, '%error' => $e), WATCHDOG_ERROR);
        continue;
      }

      insert_node_programme($arr_content, $arr_program_serialize);

      $context['results']['processed'] ++;
      $context['sandbox']['progress'] ++;
    }

    unset($context['sandbox']['statements'][$count]);
    $count++;
  }

  $context['message'] = 'Processed ' . $context['sandbox']['progress'] . '/' . $context['sandbox']['max'] . ' terms';

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

function insert_node_programme($arr_content, $arr_program_serialize) {
  module_load_include('php', 'kb_program', 'KBAPI');
  $KBAPI = new KBAPI();

  $node_programme = $KBAPI->checkExistsProgramme((int) $arr_content[0]);
  if ($node_programme && is_array($node_programme)) {
    $node_programme = reset($node_programme);
    $KBAPI->updateNodeProgramme($node_programme->nid, $arr_program_serialize);
  } else {
    $params = array(
      'idkp' => (int) $arr_content[0],
      'name' => utf8_encode($arr_content[1]),
      'structure' => $arr_program_serialize,
    );
    $KBAPI->insertNodeProgramme($params);
  }
}

/**
 * Batch 'finished' callback
 */
function batch_import_program_finished($success, $results, $operations) {
  $message = $results['processed'] . ' processed.';
  drupal_set_message($message);
}
