<?php

/**
 * Implements hook_node_insert().
 * @param type $node
 */
function kandb_partenaire_node_insert($node) {
// By pass apply rule in case apply habiteo API.
  if (isset($node->flag_habiteo) && $node->flag_habiteo) {
    return;
  }
// No need apply BRs in case devel generate.
  if ($_GET['q'] == 'admin/config/development/generate/content' ||
    (isset($node->devel_generate) && !empty($node->devel_generate))
  ) {
    return;
  }
  if ($node->type == 'partenaire' && $node->is_new == 1 && isset($node->field_partenaire_export[LANGUAGE_NONE][0]['value']) && $node->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 3 && isset($node->field_partenaire_plan[LANGUAGE_NONE][0]['value']) && $node->field_partenaire_plan[LANGUAGE_NONE][0]['value'] == 1) {
    kandb_partenaire_create_archive_file($node);
  }
//  elseif ($node->type == 'bien' && $node->status == 1 && isset ($node->field_bien_plan[LANGUAGE_NONE][0]['fid']) && isset ($node->field_programme[LANGUAGE_NONE][0]['target_id'])) {
//    kandb_partenaire_update_archive_file($node);
//  }
}

/**
 * Implements hook_node_update()
 * @param type $node
 */
function kandb_partenaire_node_update($node) {
// By pass apply rule in case apply habiteo API.
  if (isset($node->flag_habiteo) && $node->flag_habiteo) {
    return;
  }
  if ($node->type == 'partenaire' && $node->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 3 && isset($node->field_partenaire_plan[LANGUAGE_NONE][0]['value']) && $node->field_partenaire_plan[LANGUAGE_NONE][0]['value'] == 1) {
    $programme = array();
    $old_programme = array();
    if (isset($node->field_partenaire_programmes[LANGUAGE_NONE])) {
      foreach ($node->field_partenaire_programmes[LANGUAGE_NONE] as $target) {
        $programme[] = $target['target_id'];
      }
    }
    if (isset($node->original->field_partenaire_programmes[LANGUAGE_NONE])) {
      foreach ($node->original->field_partenaire_programmes[LANGUAGE_NONE] as $target) {
        $old_programme[] = $target['target_id'];
      }
    }
    if (!empty(array_diff($old_programme, $programme)) || !empty(array_diff($programme, $old_programme))) {
      kandb_partenaire_create_archive_file($node);
    }
  }
//  elseif ($node->type == 'programme' && ($node->status != $node->original->status || !empty(array_diff($node->domains, $node->original->domains)) || !empty(array_diff($node->original->domains, $node->domains)))) {
//    kandb_partenaire_update_archive_file($node);
//  }
//  elseif ($node->type == 'bien') {
//    $update_archive = FALSE;
//    if (isset ($node->field_bien_plan[LANGUAGE_NONE][0]['fid'])) {
//      if (!isset ($node->original->field_bien_plan[LANGUAGE_NONE][0]['fid']) || $node->original->field_bien_plan[LANGUAGE_NONE][0]['fid'] != $node->field_bien_plan[LANGUAGE_NONE][0]['fid']) {
//        $update_archive = TRUE;
//      }
//    }
//    elseif (isset ($node->original->field_bien_plan[LANGUAGE_NONE][0]['fid'])) {
//      $update_archive = TRUE;
//    }
//
//    if ($update_archive && $node->status == 0 && $node->original->status == 0) {
//      $update_archive = FALSE;
//    }
//
//    if ($update_archive && !isset ($node->field_programme[LANGUAGE_NONE][0]['target_id'])) {
//      $update_archive = FALSE;
//    }
//
//    if ($update_archive) {
//      kandb_partenaire_update_archive_file($node);
//    }
//  }
}

/**
 * Implements hook_node_delete().
 * @param type $node
 */
//function kandb_partenaire_node_delete($node) {
//  if ($node->type == 'partenaire' && isset($node->field_id_partenaire[LANGUAGE_NONE][0]['value'])) {
//    $path = drupal_realpath('public://');
//    $dir = $path . '/partenaire/' . $node->field_id_partenaire[LANGUAGE_NONE][0]['value'] . '/';
//    foreach (glob($dir . "/*.*") as $filename) {
//      if (is_file($filename)) {
//        unlink($filename);
//      }
//    }
//    rmdir($dir);
//  }
//  elseif ($node->type == 'programme' && $node->status == 1) {
//    kandb_partenaire_update_archive_file($node);
//  }
//  elseif ($node->type == 'bien' && $node->status == 1 && isset ($node->field_bien_plan[LANGUAGE_NONE][0]['fid']) && isset ($node->field_programme[LANGUAGE_NONE][0]['target_id'])) {
//    kandb_partenaire_update_archive_file($node);
//  }
//}

function kandb_partenaire_menu() {
  $items['partenaires/%/document_lot_plan.zip'] = array(
    'title' => 'Download document lot plan',
    'access callback' => TRUE,
    'type' => MENU_NORMAL_ITEM,
    'page callback' => 'kandb_partenaire_prepare_download_file',
    'page arguments' => array(1),
  );
  
  $items['partenaires/%/PROGRAMME.TXT'] = array(
    'title' => 'Download PROGRAMME.TXT',
    'access callback' => TRUE,
    'type' => MENU_NORMAL_ITEM,
    'page callback' => 'kandb_partenaire_download_programme_txt',
    'page arguments' => array(1),
    'file' => 'kandb_partenaire.programme_txt.inc',
    'file path' => drupal_get_path('module', 'kandb_partenaire'),
  );

  $items['partenaires/%/lots.txt'] = array(
    'title' => 'Download lot txt',
    'access callback' => TRUE,
    'type' => MENU_NORMAL_ITEM,
    'page callback' => 'kandb_partenaire_lots_prepare_download_file',
    'page arguments' => array(1),
  );

  /* $items['partenaire-test'] = array(
    'title' => 'test Download lot txt',
    'access callback' => TRUE,
    'type' => MENU_NORMAL_ITEM,
    'page callback' => 'kandb_test',
    'page arguments' => array(1),
    ); */
  
  return $items;
}

function kandb_partenaire_cronapi($op, $job = NULL) {
  $items['kandb_update_b2c_b2b_partenaire_files'] = array(
    'description' => 'Update b2c/b2b partenaire files',
    'rule' => '0 6 * * 1-5',
    'callback' => 'kandb_create_b2c_b2b_archive_file',
  );
  return $items;
}

function kandb_partenaire_prepare_download_file($vuuid = '') {
  if ($vuuid == '') {
    return;
  }
  $partenaire_directory = 'sites/default/files/partenaire/';
  $vuuid_str = urldecode($vuuid);
  $uri = 'public://partenaire/';
  $file_path = drupal_realpath($uri) . '/';
  $db_query = db_select('field_data_field_id_partenaire', 'idp');
  $db_query->fields('idp', array('entity_id'));
  $db_query->condition('idp.entity_type', 'node');
  $db_query->condition('idp.field_id_partenaire_value', $vuuid_str);
  $pid = $db_query->execute()->fetchField();
  if ($pid) {
    $node = node_load($pid);
    $file_exist = TRUE;
    if ($node->status == 1 && isset($node->field_partenaire_plan[LANGUAGE_NONE][0]['value']) && $node->field_partenaire_plan[LANGUAGE_NONE][0]['value'] == 1 && isset($node->field_partenaire_export[LANGUAGE_NONE][0]['value'])) {
      if ($node->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 3) {
        $file_path .= $vuuid . '/document_lot_plan.zip';
        if (is_file($file_path)) {
          drupal_goto($partenaire_directory . $vuuid . '/document_lot_plan.zip');
        } else {
          $file_exist = FALSE;
        }
      } elseif ($node->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 1) {
        $file_path .= 'b2c/document_lot_plan.zip';
        if (is_file($file_path)) {
          drupal_goto($partenaire_directory . 'b2c/document_lot_plan.zip');
        } else {
          $file_exist = FALSE;
        }
      } elseif ($node->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 2) {
        $file_path .= 'b2b/document_lot_plan.zip';
        if (is_file($file_path)) {
          drupal_goto($partenaire_directory . 'b2b/document_lot_plan.zip');
        } else {
          $file_exist = FALSE;
        }
      }
    }
    if (!$file_exist) {
      return 'File does not exist';
    }
  } else {
    return 'The partenaire not found';
  }
  if (is_file($file_path)) {
    header("Pragma: public");
    header("Expires: 0");
    header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
    header("Cache-Control: public");
    header('Content-type: application/octet-stream');
    header("Content-Transfer-Encoding: Binary");
    header('Content-Disposition: attachment; filename="document_lot_plan.zip"');
    header("Content-Length: " . filesize($file_path));

    $fp = @fopen($file_path, "rb");
    if ($fp) {
      while (!feof($fp)) {
        echo fread($fp, 8192);
        flush();
        if (connection_status() != 0) {
          @fclose($file_path);
          die();
        }
      }
      @fclose($file_path);
    }
  } else {
    drupal_set_message(t('The file to download does not exist.'));
  }
}

function kandb_partenaire_update_archive_file($node) {
  $programme = NULL;
  $partenaires_id = array();
  if ($node->type == 'programme') {
    $files_pdf = get_files_in_bien_related(NULL, array($node->nid));
    if (!empty($files_pdf)) {
      $programme = $node;
      $partenaires_id = kandb_get_partenaire_related_to_programme($node);
    }
  } elseif ($node->type == 'bien') {
    $programme = node_load($node->field_programme[LANGUAGE_NONE][0]['target_id']);
    if ($programme) {
      if ($programme->status == 1) {
        $partenaires_id = kandb_get_partenaire_related_to_programme($programme);
      }
    }
  }
  if ($programme && $partenaires_id) {
    $partenaires = node_load_multiple($partenaires_id);
    foreach ($partenaires as $partenaire) {
      if (isset($partenaire->field_partenaire_export[LANGUAGE_NONE][0]['value'])) {
        if ($partenaire->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 3) {
          kandb_partenaire_create_archive_file($partenaire);
        }
      }
    }
  }
}

function kandb_create_b2c_b2b_archive_file($file = '') {
  $uri = 'public://partenaire/';
  $all_pdf_files = array();
  $files_info = array();
  $prepare_file = file_prepare_directory($uri, FILE_CREATE_DIRECTORY);
  if ($prepare_file) {
    $uri_b2c = $uri . 'b2c';
    file_prepare_directory($uri_b2c, FILE_CREATE_DIRECTORY);
    drupal_chmod($uri . 'b2c', 0777);
    $uri_b2b = $uri . 'b2b';
    file_prepare_directory($uri_b2b, FILE_CREATE_DIRECTORY);
    drupal_chmod($uri . 'b2b', 0777);
    $ori_path = $path = drupal_realpath($uri);
    $path = $ori_path . '/b2c/';
    if (file_exists($path)) {
      foreach (glob($path . "/*.*") as $filename) {
        if (is_file($filename)) {
          $tmp_filename = str_replace($path . '/', '', $filename);
          if ($tmp_filename == 'document_lot_plan.zip') {
            unlink($filename);
          }
        }
      }
    }
    $path = $ori_path . '/b2b/';
    if (file_exists($path)) {
      foreach (glob($path . "/*.*") as $filename) {
        if (is_file($filename)) {
          $tmp_filename = str_replace($path . '/', '', $filename);
          if ($tmp_filename == 'document_lot_plan.zip') {
            unlink($filename);
          }
        }
      }
    }
    //Create/update B2C file
    $all_pdf_files = get_files_in_bien_related(1);
    $files_info = kandb_partenaire_get_file_info($all_pdf_files);
    kandb_partenaire_create_file_zip($ori_path . '/b2c/document_lot_plan.zip', $files_info);
    //Create/update B2B file
    $all_pdf_files = get_files_in_bien_related(2);
    $files_info = kandb_partenaire_get_file_info($all_pdf_files);
    kandb_partenaire_create_file_zip($ori_path . '/b2b/document_lot_plan.zip', $files_info);

    kandb_get_partenaire_lot_plan();
    //PROGRAMME.TXT
    kandb_update_b2c_b2b_partenaire_programme_txt_files();
    
  }
}

function kandb_get_partenaire_related_to_programme($programme = NULL) {
  $partenaire = array();
  if (isset($programme->nid)) {
    $db_query = db_select('node', 'n');
    $db_query->fields('n', array('nid'));
    $db_query->condition('n.type', 'partenaire');
    $db_query->leftJoin('field_data_field_partenaire_programmes', 'prog', 'prog.entity_id=n.nid');
    $db_query->leftJoin('field_data_field_partenaire_export', 'pe', 'pe.entity_id=n.nid');
    $db_query->condition('pe.entity_type', 'node');
    $db_query->condition('pe.bundle', 'partenaire');
    $db_query->leftJoin('field_data_field_partenaire_plan', 'pl', 'pl.entity_id=n.nid');
    $db_query->condition('pl.entity_type', 'node');
    $db_query->condition('pl.bundle', 'partenaire');
    $db_query->condition('pl.field_partenaire_plan_value', 1);
    $db_query->condition('pe.field_partenaire_export_value', 3);
    $db_query->condition('prog.entity_type', 'node');
    $db_query->condition('prog.bundle', 'partenaire');
    $db_query->condition('prog.field_partenaire_programmes_target_id', $programme->nid);
    $partenaire = $db_query->distinct()->execute()->fetchCol();
  }
  return $partenaire;
}

function kandb_partenaire_create_file_zip($real_path, $files_info = array()) {
  $zip = new ZipArchive();
  if ($zip->open($real_path, ZipArchive::CREATE) == TRUE) {
    foreach ($files_info as $file) {
      $zip->addFile(drupal_realpath($file['file_uri']), $file['file_name']);
    }
    $zip->close();
  }
}

function kandb_partenaire_get_file_info($fids = array()) {
  $files = array();
  foreach ($fids as $fid) {
    $file_info = file_load($fid);
    if ($file_info) {
      $files[$fid] = array('file_name' => $file_info->filename, 'file_uri' => $file_info->uri);
    }
  }
  return $files;
}

function kandb_partenaire_create_archive_file($node) {
  $vuuid = isset($node->field_id_partenaire[LANGUAGE_NONE][0]['value']) ? $node->field_id_partenaire[LANGUAGE_NONE][0]['value'] : '';
  if ($vuuid == '') {
    return;
  }
  $partenaire_export = $node->field_partenaire_export[LANGUAGE_NONE][0]['value'];
  $all_pdf_files = array();
  $uri = 'public://partenaire/' . $vuuid;
  file_prepare_directory($uri, FILE_CREATE_DIRECTORY);
  drupal_chmod($uri, 0777);
  $path = drupal_realpath($uri);

  if (file_exists($path)) {
    foreach (glob($path . "/*.*") as $filename) {
      if (is_file($filename)) {
        unlink($filename);
      }
    }
  }
  if ($partenaire_export == 3) {
    $list_programme = array();
    if (isset($node->field_partenaire_programmes[LANGUAGE_NONE])) {
      foreach ($node->field_partenaire_programmes[LANGUAGE_NONE] as $target) {
        $list_programme[] = $target['target_id'];
      }
    }
    $all_pdf_files = get_files_in_bien_related(NULL, $list_programme);
  }
  $files_info = kandb_partenaire_get_file_info($all_pdf_files);
  kandb_partenaire_create_file_zip($path . '/document_lot_plan.zip', $files_info);
}

function get_files_in_bien_related($partenaire_export = NULL, $list_programme = array()) {
  if ($partenaire_export != 1 && $partenaire_export != 2 && empty($list_programme)) {
    return array();
  }
  $all_pdf_files = array();
  $db_query = db_select('field_data_field_bien_plan', 'fb');
  $db_query->fields('fb', array('field_bien_plan_fid'));
  $db_query->condition('fb.entity_type', 'node');
  $db_query->condition('fb.bundle', 'bien');
  $db_query->leftJoin('node', 'nb', 'nb.nid=fb.entity_id');
  $db_query->condition('nb.status', 1);
  $db_query->leftJoin('field_data_field_bien_statut', 'ft', 'ft.entity_id=fb.entity_id');
  $db_query->condition('ft.entity_type', 'node');
  $db_query->condition('ft.bundle', 'bien');
  $db_query->leftJoin('field_data_field_id_xls', 'xls', 'xls.entity_id=ft.field_bien_statut_tid');
  $db_query->condition('xls.entity_type', 'taxonomy_term');
  $db_query->condition('xls.bundle', 'status_logement');
  $db_query->condition('xls.field_id_xls_value', 1);
  $db_query->leftJoin('field_data_field_programme', 'prog', 'prog.entity_id=fb.entity_id');
  $db_query->condition('prog.entity_type', 'node');
  $db_query->condition('prog.bundle', 'bien');
  $db_query->leftJoin('node', 'np', 'np.nid=prog.field_programme_target_id');
  $db_query->condition('np.status', 1);
  if (!empty($list_programme)) {
    $db_query->condition('prog.field_programme_target_id', $list_programme, 'IN');
  } elseif ($partenaire_export == 1 || $partenaire_export == 2) {
    $db_query->leftJoin('domain_access', 'dm', 'dm.nid=nb.nid');
    $db_query->condition('dm.realm', 'domain_id');
    $db_query->leftJoin('domain_access', 'dmp', 'dmp.nid=np.nid');
    $db_query->condition('dmp.realm', 'domain_id');
    if ($partenaire_export == 1) {
      $db_query->condition('dm.gid', 3);
      $db_query->condition('dmp.gid', 3);
    } elseif ($partenaire_export == 2) {
      $db_query->condition('dm.gid', 2);
      $db_query->condition('dmp.gid', 2);
    }
  }
  $all_pdf_files = $db_query->distinct()->execute()->fetchCol();
  return $all_pdf_files;
}

/**
 * Generate UUID.
 */
function generate_uuid() {
  return sprintf('%04x%04x-%04x-%04x-%04x-%04x%04x%04x',
    // 32 bits for "time_low".
    mt_rand(0, 0xffff), mt_rand(0, 0xffff),
    // 16 bits for "time_mid".
    mt_rand(0, 0xffff),
    // 16 bits for "time_hi_and_version",
    // four most significant bits holds version number 4.
    mt_rand(0, 0x0fff) | 0x4000,
    // 16 bits, 8 bits for "clk_seq_hi_res",
    // 8 bits for "clk_seq_low",
    // two most significant bits holds zero and one for variant DCE1.1.
    mt_rand(0, 0x3fff) | 0x8000,
    // 48 bits for "node".
    mt_rand(0, 0xffff), mt_rand(0, 0xffff), mt_rand(0, 0xffff)
  );
}
