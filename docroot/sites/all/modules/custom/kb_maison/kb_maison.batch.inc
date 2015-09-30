<?php

class import_maison_batch {

  public static
    function start() {
    batch_import_maison_prepare();
  }

}

function batch_import_maison_prepare() {
  $file_name = 'MAISON.TXT';
  // Get the contents of the .sql file.
  $file_content = file_get_contents(drupal_get_path('module', 'kb_maison') . '/' . $file_name);
  // Split into individual statements based on new lines.
  $statements = preg_split('/[|]/', $file_content, -1, PREG_SPLIT_NO_EMPTY);
  $statements = array_map('trim', $statements);

  $batch = array(
    'operations' => array(
      array('batch_import_maison_process', array($statements)),
    ),
    'finished' => 'batch_import_maison_finished',
    'title' => t('Processing Import Lot Batch'),
    'init_message' => t('Import Lot is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Import Lot Batch has encountered an error.'),
    'file' => drupal_get_path('module', 'kb_maison') . '/kb_maison.batch.inc',
  );
  batch_set($batch);
  batch_process('admin');
}

function batch_import_maison_process($statements, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['results']['processed'] = 0;
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['statements'] = $statements;
    $context['sandbox']['max'] = count($statements);
  }

  $limit = 5;
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
      $result = db_select('maison', 'kbma')
        ->fields('kbma', array('idkm'))
        ->condition('idkm', (int) $arr_content[0])
        ->range(0, 1)
        ->execute()
        ->rowCount();

      if ($result) {
        try {
          db_update('maison') // Table name no longer needs {}
            ->fields(array(
              'name' => utf8_encode($arr_content[1]),
              'short_desc_fr' => utf8_encode($arr_content[2]),
              'short_desc_uk' => utf8_encode($arr_content[3]),
              'nbre_floor' => (int) $arr_content[4],
              'nbre_room' => (int) $arr_content[5],
              'nbre_chambres' => (int) $arr_content[6],
              'nbre_bathrooms' => (int) $arr_content[7],
              'desc_fr' => utf8_encode($arr_content[8]),
              'desc_uk' => utf8_encode($arr_content[9]),
              'surface_stay' => floatval(str_replace(",", ".", $arr_content[10])),
              'surface_cuisine' => floatval(str_replace(",", ".", $arr_content[11])),
              'surface_totale' => floatval(str_replace(",", ".", $arr_content[12])),
              'url_visite' => utf8_encode($arr_content[13]),
              'pos_ammenagement_fr' => utf8_encode($arr_content[14]),
              'pos_ammenagement_uk' => utf8_encode($arr_content[15]),
            ))
            ->condition('idkm', (int) $arr_content[0])
            ->execute();
        }
        catch (Exception $ex) {
          watchdog('PHP', "Import(updated) file maison error: Last id inserted:%id.<br/>%error", array('%id' => $arr_content[0], '%error' => $e), WATCHDOG_ERROR);
        }

        $context['results']['processed'] ++;
        $context['sandbox']['progress'] ++;

        unset($context['sandbox']['statements'][$count]);
        $count++;

        continue;
      }

      $id = 0;
      try {
        //error_log('idkm: ' . $arr_content[0]);
        $id = db_insert('maison') // Table name no longer needs {}
          ->fields(array(
            'idkm' => (int) $arr_content[0],
            'name' => utf8_encode($arr_content[1]),
            'short_desc_fr' => utf8_encode($arr_content[2]),
            'short_desc_uk' => utf8_encode($arr_content[3]),
            'nbre_floor' => (int) $arr_content[4],
            'nbre_room' => (int) $arr_content[5],
            'nbre_chambres' => (int) $arr_content[6],
            'nbre_bathrooms' => (int) $arr_content[7],
            'desc_fr' => utf8_encode($arr_content[8]),
            'desc_uk' => utf8_encode($arr_content[9]),
            'surface_stay' => floatval(str_replace(",", ".", $arr_content[10])),
            'surface_cuisine' => floatval(str_replace(",", ".", $arr_content[11])),
            'surface_totale' => floatval(str_replace(",", ".", $arr_content[12])),
            'url_visite' => utf8_encode($arr_content[13]),
            'pos_ammenagement_fr' => utf8_encode($arr_content[14]),
            'pos_ammenagement_uk' => utf8_encode($arr_content[15]),
          ))
          ->execute();
      }
      catch (Exception $e) {
        watchdog('PHP', "Import(inserted) file maison  error: Last id inserted:%id.<br/>%error", array('%id' => $arr_content[0], '%error' => $e), WATCHDOG_ERROR);
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
function batch_import_maison_finished($success, $results, $operations) {
  $message = $results['processed'] . ' processed.';
  drupal_set_message($message);
}
