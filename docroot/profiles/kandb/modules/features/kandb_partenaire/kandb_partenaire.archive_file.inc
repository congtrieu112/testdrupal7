<?php

define('PARTENAIRE_EXPORT_GRAND_PUBLIC_B2C', 1);
define('PARTENAIRE_EXPORT_PRESCRIPTEURS_B2B', 2);
define('PARTENAIRE_EXPORT_SELECTION_DE_PROGRAMMES', 3);

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
  return $items;
}
function kandb_partenaire_cronapi($op, $job = NULL) {
  $items['kandb_update_b2c_b2b_partenaire_files'] = array(
    'description' => 'Update b2c/b2b partenaire files',
    'rule' => '0 6 * * 1-5',
    'callback' => 'kandb_create_b2c_b2b_archive_file' ,
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
        if(is_file($file_path)) {
          drupal_goto($partenaire_directory . $vuuid . '/document_lot_plan.zip');
        }
        else {
          $file_exist = FALSE;
        }
      }
      elseif ($node->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 1) {
        $file_path .= 'b2c/document_lot_plan.zip';
        if(is_file($file_path)) {
          drupal_goto($partenaire_directory . 'b2c/document_lot_plan.zip');
        }
        else {
          $file_exist = FALSE;
        }
      }
      elseif ($node->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 2) {
        $file_path .= 'b2b/document_lot_plan.zip';
        if(is_file($file_path)) {
          drupal_goto($partenaire_directory . 'b2b/document_lot_plan.zip');
        }
        else {
          $file_exist = FALSE;
        }
      }
    }
    if (!$file_exist) {
      return 'File does not exist';
    }
  }
  else {
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
  }
  else {
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
  }
  elseif ($node->type == 'bien') {
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
    $pathB2C = $ori_path . '/b2c/Programme.xml';
    $pathB2B = $ori_path . '/b2b/Programme.xml';

    // Preparing some data which use to create file XML
    $arr_type_partenaire_export = array($pathB2C => PARTENAIRE_EXPORT_GRAND_PUBLIC_B2C, $pathB2B => PARTENAIRE_EXPORT_PRESCRIPTEURS_B2B, $ori_path => PARTENAIRE_EXPORT_SELECTION_DE_PROGRAMMES);
    foreach($arr_type_partenaire_export as $_path_parten_export => $_type_parten_export) {
      unlink($_path_parten_export);
      $listPartenaire = getListPartenairesCustom($_type_parten_export);
      $first_time = TRUE;
      if ($listPartenaire && $listPartenaire->rowCount() > 0) {
        $partenaires = $listPartenaire->fetchAll();
        foreach($partenaires as $partenaire) {
          $programmes = isset($partenaire->field_partenaire_programmes_target_id) ? node_load($partenaire->field_partenaire_programmes_target_id) : '';
          $biens = isset($partenaire->bien_id) ? node_load_multiple(explode(',', $partenaire->bien_id)) : '';
          $partenaire_title = isset($partenaire->partenaire_title) ? $partenaire->partenaire_title : '';
          $partenaire_id = isset($partenaire->field_id_partenaire_value) ? $partenaire->field_id_partenaire_value : '';
          $path = $_path_parten_export;
          if($_type_parten_export == PARTENAIRE_EXPORT_SELECTION_DE_PROGRAMMES) {
            $first_time = TRUE;
            $uriBoth = $uri . $partenaire_id;
            file_prepare_directory($uriBoth, FILE_CREATE_DIRECTORY);
            drupal_chmod($uriBoth, 0777);
            unlink($_path_parten_export . '/' . $partenaire_id . '/Programme.xml');
            $path = $_path_parten_export . '/' . $partenaire_id . '/Programme.xml';
          }
          if($programmes || $biens) {
            createFileXML($programmes, $biens, $partenaire_title, $first_time, $path);
          }
          $first_time = FALSE;
        }
      }
    }

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
    return ;
  }
  $partenaire_export = $node->field_partenaire_export[LANGUAGE_NONE][0]['value'];
  $all_pdf_files = array();
  $uri = 'public://partenaire/'. $vuuid ;
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
  }
  elseif($partenaire_export == 1 || $partenaire_export == 2) {
    $db_query->leftJoin('domain_access', 'dm', 'dm.nid=nb.nid');
    $db_query->condition('dm.realm', 'domain_id');
    $db_query->leftJoin('domain_access', 'dmp', 'dmp.nid=np.nid');
    $db_query->condition('dmp.realm', 'domain_id');
    if ($partenaire_export == 1) {
      $db_query->condition('dm.gid', 3);
      $db_query->condition('dmp.gid', 3);
    }
    elseif ($partenaire_export == 2) {
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

/**
 * Get tid of taxonomy status du logement by name
 * @param type $term_name
 * @return int
 */
function getTidStatusDuLogementByName($term_name = TAXONOMY_STATUS_LOGEMENT_DISPONIBLE) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term');
  $query->propertyCondition('name', $term_name);
  $query->range(0, 1);

  $results = $query->execute();
  if($results){
    return array_shift($results["taxonomy_term"])->tid;
  }

  return 0;
}

/**
 * Get list partenaires by Type Partenaire Export (custom)
 * @param type $type
 * @return boolean
 */
function getListPartenairesCustom($type) {
  $tid = getTidStatusDuLogementByName(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
  if($tid) {
    $listPartenaire_query = db_select('node', 'n');
    $listPartenaire_query->leftjoin('field_data_field_partenaire_programmes', 'pp', 'n.nid=pp.field_partenaire_programmes_target_id');
    $listPartenaire_query->leftJoin('field_data_field_partenaire_type_flux', 'ptf', 'pp.entity_id=ptf.entity_id');
    $listPartenaire_query->leftJoin('field_data_field_id_partenaire', 'ip', 'ptf.entity_id=ip.entity_id');
    $listPartenaire_query->leftJoin('field_data_field_partenaire_export', 'pe', 'pe.entity_id=ptf.entity_id');
    $listPartenaire_query->leftJoin('domain_access', 'dm', 'dm.nid=n.nid');
    $listPartenaire_query->addExpression('(select title from node n where n.nid = pp.entity_id)', 'partenaire_title');
    $listPartenaire_query
      ->fields('pp', array('field_partenaire_programmes_target_id'))
      ->fields('ip', array('field_id_partenaire_value'))
      ->condition('field_partenaire_type_flux_value', 3)
      ->condition('status', 1)
      ->condition('field_partenaire_export_value', $type);

    if ($type == PARTENAIRE_EXPORT_GRAND_PUBLIC_B2C) {
      $str = '(select group_concat(p.entity_id) from node n left join field_data_field_programme p on n.nid=p.entity_id left join domain_access d on d.nid=n.nid left join field_data_field_bien_statut bs on bs.entity_id=p.entity_id where n.status = 1 and bs.field_bien_statut_tid = ' . $tid . ' and d.gid = 3 and p.field_programme_target_id = pp.field_partenaire_programmes_target_id)';
      $listPartenaire_query->condition('dm.gid', 3);
      $listPartenaire_query->addExpression($str, 'bien_id');
    }
    elseif ($type == PARTENAIRE_EXPORT_PRESCRIPTEURS_B2B) {
      $str = '(select group_concat(p.entity_id) from node n left join field_data_field_programme p on n.nid=p.entity_id left join domain_access d on d.nid=n.nid left join field_data_field_bien_statut bs on bs.entity_id=p.entity_id where n.status = 1 and bs.field_bien_statut_tid = ' . $tid . ' and d.gid = 2 and p.field_programme_target_id = pp.field_partenaire_programmes_target_id)';
      $listPartenaire_query->condition('dm.gid', 2);
      $listPartenaire_query->addExpression($str, 'bien_id');
    } elseif($type == PARTENAIRE_EXPORT_SELECTION_DE_PROGRAMMES) {
      $str = '(select group_concat(p.entity_id) from node n left join field_data_field_programme p on n.nid=p.entity_id left join field_data_field_bien_statut bs on bs.entity_id=p.entity_id where n.status = 1 and bs.field_bien_statut_tid = ' . $tid . ' and p.field_programme_target_id = pp.field_partenaire_programmes_target_id)';
      $listPartenaire_query->condition('dm.gid', array(2,3), 'IN');
      $listPartenaire_query->addExpression($str, 'bien_id');
      $listPartenaire_query->distinct();
    }

    return $listPartenaire_query->execute();
  }

  return FALSE;
}

/**
 * Create file XML
 * @global type $base_url
 * @param type $programmes
 * @param type $biens
 * @param type $partenaire_title
 * @param type $first_time
 * @param type $path
 */
function createFileXML($programmes, $biens, $partenaire_title, $first_time, $path) {
  global $base_url;
  $programme_id = isset($programmes->field_id_programme[LANGUAGE_NONE][0]['value']) ? $programmes->field_id_programme[LANGUAGE_NONE][0]['value'] : '';
  $programme_title = isset($programmes->title) ? $programmes->title : '';
  $programme_loc_num = isset($programmes->field_programme_loc_num[LANGUAGE_NONE][0]['value']) ? $programmes->field_programme_loc_num[LANGUAGE_NONE][0]['value'] : '';
  $programme_loc_type = isset($programmes->field_programme_loc_type[LANGUAGE_NONE][0]['tid']) ? $programmes->field_programme_loc_type[LANGUAGE_NONE][0]['tid'] : '';
  $programme_loc_rue = isset($programmes->field_programme_loc_rue[LANGUAGE_NONE][0]['value']) ? $programmes->field_programme_loc_rue[LANGUAGE_NONE][0]['value'] : '';
  $term_programme_loc_type = taxonomy_term_load($programme_loc_type);
  if($term_programme_loc_type) {
    $programme_loc_type = isset($term_programme_loc_type->name) ? $term_programme_loc_type->name : '';
  }
  $programme_address = $programme_loc_num . ' ' . $programme_loc_type . ' ' . $programme_loc_rue;
  $programme_cp = isset($programmes->field_programme_loc_cp[LANGUAGE_NONE][0]['value']) ? $programmes->field_programme_loc_cp[LANGUAGE_NONE][0]['value'] : '';
  $programme_ville = isset($programmes->field_programme_loc_ville[LANGUAGE_NONE][0]['value']) ? $programmes->field_programme_loc_ville[LANGUAGE_NONE][0]['value'] : '';
  $sender_mail = variable_get('kb_call_center_sender_mail', '');

  $programme_annee = isset($programmes->field_annee[LANGUAGE_NONE][0]['value']) ? $programmes->field_annee[LANGUAGE_NONE][0]['value'] : '';
  $programme_trimestre = isset($programmes->field_trimestre[LANGUAGE_NONE][0]['value']) ? $programmes->field_trimestre[LANGUAGE_NONE][0]['value'] : '';
  $programme_livraison = $programme_annee . $programme_trimestre;
  $programme_en_quelques_mots = isset($programmes->field_en_quelques_mots[LANGUAGE_NONE][0]['value']) ? $programmes->field_en_quelques_mots[LANGUAGE_NONE][0]['value'] : '';
  $programme_address_web = $base_url . '/' . drupal_get_path_alias('node/' . $programmes->nid);

  $bien_image_principale_fid = isset($programmes->field_image_principale[LANGUAGE_NONE][0]['fid']) ? $programmes->field_image_principale[LANGUAGE_NONE][0]['fid'] : '';
  $bien_perspective = '';
  if($bien_image_principale_fid) {
    $files = file_load($bien_image_principale_fid);
    if($files && isset($files->uri)) {
      $url = file_create_url($files->uri);
      $url = parse_url($url);
      $bien_perspective = $base_url . $url['path'];
    }
  }

  $reponse = '';
  $doc = '';
  if($first_time == TRUE) {
    $doc = new DOMDocument('1.0');
    // we want a nice output
    $doc->formatOutput = true;

    $reponse = $doc->createElement('REPONSE');
    $reponse = $doc->appendChild($reponse);

    $entete = $doc->createElement('ENTETE');
    $entete = $reponse->appendChild($entete);

    $promoteur = $doc->createElement('PROMOTEUR');
    $promoteur = $entete->appendChild($promoteur);
    $promoteur_value = $doc->createTextNode($partenaire_title);
    $promoteur_value = $promoteur->appendChild($promoteur_value);

    $date = $doc->createElement('DATE');
    $date = $entete->appendChild($date);
    $date_value = $doc->createTextNode(date("Y-m-d", time()));
    $date_value = $date->appendChild($date_value);
  } elseif($first_time == FALSE && file_exists($path)) {
    $doc = new DOMDocument();
    $doc->load($path);

    $reponse = $doc->firstChild;
  }

  $programme = $doc->createElement('PROGRAMME');
  $programme = $reponse->appendChild($programme);

  createElementXML($doc, $programme, 'REF_OPERATION', $programme_id);
  createElementXML($doc, $programme, 'NUMERO', $programme_id);
  createElementXML($doc, $programme, 'NOM', $programme_title);
  createElementXML($doc, $programme, 'ADRESSE', $programme_address);
  createElementXML($doc, $programme, 'CP', $programme_cp);
  createElementXML($doc, $programme, 'VILLE', $programme_cp);
  createElementXML($doc, $programme, 'PAYS', 'France');
  createElementXML($doc, $programme, 'ADRESSE_MAIL', $sender_mail);
  createElementXML($doc, $programme, 'ADRESSE_WEB', $programme_address_web);
  createElementXML($doc, $programme, 'PERSPECTIVE', $bien_perspective);
  createElementXML($doc, $programme, 'DATE_LIVRAISON', $programme_livraison);
  createElementXML($doc, $programme, 'DATE_VENTE', '');
  createElementXML($doc, $programme, 'OBJECTIF', 'mixte');
  createElementXML($doc, $programme, 'DESCRIPTIF_COURT', '');
  createElementXML($doc, $programme, 'DESCRIPTIF_LONG', $programme_en_quelques_mots);
  createElementXML($doc, $programme, 'DESCRIPTIF_COURT_EN', '');
  createElementXML($doc, $programme, 'DESCRIPTIF_LONG_EN', '');

  foreach($biens as $bien) {
    $lot = $doc->createElement('LOT');
    $lot = $programme->appendChild($lot);

    $bien_numero_lot = isset($bien->field_numero_lot[LANGUAGE_NONE][0]['value']) ? $bien->field_numero_lot[LANGUAGE_NONE][0]['value'] : '';
    $term_bien_type =  isset($bien->field_type[LANGUAGE_NONE][0]['tid']) ? taxonomy_term_load($bien->field_type[LANGUAGE_NONE][0]['tid']) : '';
    $bien_type = ($term_bien_type && isset($term_bien_type->name)) ? $term_bien_type->name : '';

    $term_bien_orientation =  isset($bien->field_orientation[LANGUAGE_NONE][0]['tid']) ? taxonomy_term_load($bien->field_orientation[LANGUAGE_NONE][0]['tid']) : '';
    $bien_orientation = ($term_bien_orientation && isset($term_bien_orientation->name)) ? $term_bien_orientation->name : '';

    $term_bien_nb_pieces =  isset($bien->field_nb_pieces[LANGUAGE_NONE][0]['tid']) ? taxonomy_term_load($bien->field_nb_pieces[LANGUAGE_NONE][0]['tid']) : '';
    $bien_nb_pieces = ($term_bien_nb_pieces && isset($term_bien_nb_pieces->name)) ? $term_bien_nb_pieces->name : '';

    $term_bien_etage =  isset($bien->field_etage[LANGUAGE_NONE][0]['tid']) ? taxonomy_term_load($bien->field_etage[LANGUAGE_NONE][0]['tid']) : '';
    $bien_etage = ($term_bien_etage && isset($term_bien_etage->name)) ? $term_bien_etage->name : '';

    $bien_tva = isset($bien->field_tva[LANGUAGE_NONE][0]['tid']) ? 'N' : 'O';

    $bien_plan_vente_fid = isset($bien->field_bien_plan[LANGUAGE_NONE][0]['fid']) ? $bien->field_bien_plan[LANGUAGE_NONE][0]['fid'] : '';
    $bien_plan_vente = '';
    if($bien_plan_vente_fid) {
      $files = file_load($bien_plan_vente_fid);
      if($files && isset($files->uri)) {
        $url = file_create_url($files->uri);
        $url = parse_url($url);
        $bien_plan_vente = $base_url . $url['path'];
      }
    }

    $bien_caracteristique_terrasse = isset($bien->field_caracteristique_terrasse[LANGUAGE_NONE][0]['value']) ? $bien->field_caracteristique_terrasse[LANGUAGE_NONE][0]['value'] : '';
    $bien_caracteristique_balcon = isset($bien->field_caracteristique_balcon[LANGUAGE_NONE][0]['value']) ? $bien->field_caracteristique_balcon[LANGUAGE_NONE][0]['value'] : '';
    $bien_caracteristique_parking = isset($bien->field_caracteristique_parking[LANGUAGE_NONE][0]['value']) ? $bien->field_caracteristique_parking[LANGUAGE_NONE][0]['value'] : '';
    if($bien_caracteristique_parking && $bien_caracteristique_parking > 0) {
      $bien_caracteristique_parking = 1;
    } else {
      $bien_caracteristique_parking = 0;
    }

    $bien_caracteristique_cave = isset($bien->field_caracteristique_cave[LANGUAGE_NONE][0]['value']) ? $bien->field_caracteristique_cave[LANGUAGE_NONE][0]['value'] : '';
    if($bien_caracteristique_cave && $bien_caracteristique_cave > 0) {
      $bien_caracteristique_cave = 1;
    } else {
      $bien_caracteristique_cave = 0;
    }

    createElementXML($doc, $lot, 'REF_LOT', $bien_numero_lot);
    createElementXML($doc, $lot, 'NUMERO', $bien_numero_lot);
    createElementXML($doc, $lot, 'ADRESSE_WEB', '');
    createElementXML($doc, $lot, 'TYPE_BIEN', $bien_type);
    createElementXML($doc, $lot, 'ORIENTATION', $bien_orientation);
    createElementXML($doc, $lot, 'SURFACE_HABITABLE', '');
    createElementXML($doc, $lot, 'SURFACE_TERRAIN', '');
    createElementXML($doc, $lot, 'NB_PIECES', $bien_nb_pieces);
    createElementXML($doc, $lot, 'ETAGE', $bien_etage);
    createElementXML($doc, $lot, 'DATE_LIVRAISON', $programme_livraison);
    createElementXML($doc, $lot, 'DATE_VENTE', '');
    createElementXML($doc, $lot, 'PRIX_ACCESSION', '');
    createElementXML($doc, $lot, 'MONTANT_MOBILIER', 0);
    createElementXML($doc, $lot, 'MONTANT_TRAVAUX', 0);
    createElementXML($doc, $lot, 'MONTANT_TERRAIN', 0);
    createElementXML($doc, $lot, 'LOYER', 0);
    createElementXML($doc, $lot, 'TVA_REDUITE', $bien_tva);
    createElementXML($doc, $lot, 'TYPE_FISCALITE', '');
    createElementXML($doc, $lot, 'OPTION', '');
    createElementXML($doc, $lot, 'PLAN_VENTE', $bien_plan_vente);
    createElementXML($doc, $lot, 'SURFACE_TERRASSE', $bien_caracteristique_terrasse);
    createElementXML($doc, $lot, 'SURFACE_BALCON', $bien_caracteristique_balcon);
    createElementXML($doc, $lot, 'PARKINGS', $bien_caracteristique_parking);
    createElementXML($doc, $lot, 'GARAGES', '');
    createElementXML($doc, $lot, 'CAVE', $bien_caracteristique_cave);
    createElementXML($doc, $lot, 'NUM_TRANCHE', 1);
  }

  $status = 'Wrote: ' . $doc->save($path) . ' bytes';
}

/**
 * Create elements in file XML
 * @param type $doc
 * @param type $parent
 * @param type $tag_value
 * @param type $append_value
 */
function createElementXML($doc, $parent, $tag_value, $append_value) {
  $element = $doc->createElement($tag_value);
  $element = $parent->appendChild($element);
  $element_value = $doc->createTextNode($append_value);
  $element_value = $element->appendChild($element_value);
}