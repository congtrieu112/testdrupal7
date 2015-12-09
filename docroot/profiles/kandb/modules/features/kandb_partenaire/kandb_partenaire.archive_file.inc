<?php

/**
 * Implements hook_node_insert().
 * @param type $node
 */
function kandb_partenaire_node_insert($node) {
  if ($node->type == 'partenaire' && $node->is_new == 1 && isset($node->field_partenaire_export[LANGUAGE_NONE][0]['value']) && isset($node->field_partenaire_plan[LANGUAGE_NONE][0]['value']) && $node->field_partenaire_plan[LANGUAGE_NONE][0]['value'] == 1) {
    kandb_partenaire_create_archive_file($node);
  }
  elseif ($node->type == 'bien' && $node->status == 1 && isset ($node->field_bien_plan[LANGUAGE_NONE][0]['fid']) && isset ($node->field_programme[LANGUAGE_NONE][0]['target_id'])) {
    kandb_partenaire_update_archive_file($node);
  }
}

/**
 * Implements hook_node_update()
 * @param type $node
 */
function kandb_partenaire_node_update($node) {
  if ($node->type == 'partenaire' && $node->field_partenaire_export[LANGUAGE_NONE][0]['value'] != $node->original->field_partenaire_export[LANGUAGE_NONE][0]['value'] && isset($node->field_partenaire_plan[LANGUAGE_NONE][0]['value']) && $node->field_partenaire_plan[LANGUAGE_NONE][0]['value'] == 1) {
    kandb_partenaire_create_archive_file($node);
  }
  elseif ($node->type == 'programme' && ($node->status != $node->original->status || !empty(array_diff($node->domains, $node->original->domains)) || !empty(array_diff($node->original->domains, $node->domains)))) {
    kandb_partenaire_update_archive_file($node);
  }
  elseif ($node->type == 'bien') {
    $update_archive = FALSE;
    if (isset ($node->field_bien_plan[LANGUAGE_NONE][0]['fid'])) {
      if (!isset ($node->original->field_bien_plan[LANGUAGE_NONE][0]['fid']) || $node->original->field_bien_plan[LANGUAGE_NONE][0]['fid'] != $node->field_bien_plan[LANGUAGE_NONE][0]['fid']) {
        $update_archive = TRUE;
      }
    }
    elseif (isset ($node->original->field_bien_plan[LANGUAGE_NONE][0]['fid'])) {
      $update_archive = TRUE;
    }
    
    if ($update_archive && $node->status == 0 && $node->original->status == 0) {
      $update_archive = FALSE;
    }
    
    if ($update_archive && !isset ($node->field_programme[LANGUAGE_NONE][0]['target_id'])) {
      $update_archive = FALSE;
    }
    
    if ($update_archive) {
      kandb_partenaire_update_archive_file($node);
    }
  }
}

/**
 * Implements hook_node_delete().
 * @param type $node
 */
function kandb_partenaire_node_delete($node) {
  if ($node->type == 'partenaire') {
    $path = drupal_realpath('public://');
    $dir = $path . '/partenaire/' . $node->vuuid . '/';
    foreach (glob($dir . "/*.*") as $filename) {
      if (is_file($filename)) {
        unlink($filename);
      }
    }
    rmdir($dir);
  }
  elseif ($node->type == 'programme' && $node->status == 1) {
    kandb_partenaire_update_archive_file($node);
  }
  elseif ($node->type == 'bien' && $node->status == 1 && isset ($node->field_bien_plan[LANGUAGE_NONE][0]['fid']) && isset ($node->field_programme[LANGUAGE_NONE][0]['target_id'])) {
    kandb_partenaire_update_archive_file($node);
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
      kandb_partenaire_create_archive_file($partenaire);
    }
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
      $db_or = db_or();
        $db_and = db_and();
        $db_and->condition('pe.field_partenaire_export_value', 3);
        $db_and->condition('prog.entity_type', 'node');
        $db_and->condition('prog.bundle', 'partenaire');
        $db_and->condition('prog.field_partenaire_programmes_target_id', $programme->nid);
      $db_or->condition($db_and);
        $db_and = db_and();
          $db_sub_or = db_or();
          if (isset($programme->domains[2]) || isset($programme->original->domains[2])) {
            $db_sub_or->condition('pe.field_partenaire_export_value', 2);
          }
          if (isset($programme->domains[3]) || isset($programme->original->domains[3])) {
            $db_sub_or->condition('pe.field_partenaire_export_value', 1);
          }
        $db_and->condition($db_sub_or);
      $db_or->condition($db_and);
    $db_query->condition($db_or);
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
  if (!isset($node->vuuid) || $node->vuuid == '') {
    return ;
  }
  $partenaire_export = $node->field_partenaire_export[LANGUAGE_NONE][0]['value'];
  $path = drupal_realpath('public://');
  $all_pdf_files = array();
  $dir = $path . '/partenaire/' . $node->vuuid . '/';
  if (file_exists($dir)) {
    foreach (glob($dir . "/*.*") as $filename) {
      if (is_file($filename)) {
        unlink($filename);
      }
    }
    rmdir($dir);
  }

  if (!file_exists($path . '/partenaire/')) {
    mkdir($path . '/partenaire/', 0777);
  }

  if (!file_exists($path . '/partenaire/' . $node->vuuid . '/')) {
    mkdir($path . '/partenaire/' . $node->vuuid . '/', 0777);
  }
  if ($partenaire_export == 1 || $partenaire_export == 2) {
    $all_pdf_files = get_files_in_bien_related($partenaire_export);
  }
  elseif ($partenaire_export == 3) {
    $list_programme = array();
    if (isset($node->field_partenaire_programmes[LANGUAGE_NONE])) {
      foreach ($node->field_partenaire_programmes[LANGUAGE_NONE] as $target) {
        $list_programme[] = $target['target_id'];
      }
    }
    $all_pdf_files = get_files_in_bien_related(NULL, $list_programme);
  }
  $files_info = kandb_partenaire_get_file_info($all_pdf_files);
  kandb_partenaire_create_file_zip($path . '/partenaire/' . $node->vuuid . '/Programme.zip', $files_info);
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