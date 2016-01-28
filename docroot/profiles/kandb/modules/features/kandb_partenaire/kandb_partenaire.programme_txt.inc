<?php

function kandb_update_b2c_b2b_partenaire_programme_txt_files() {
  ini_set ('memory_limit', '1024M');
  set_time_limit(0);
  $domain_b2b_id = domain_load_domain_id('kandb_b2b');
  $domain_b2c_id = domain_load_domain_id('kandb_b2c');
  $b2b_programmes = $b2c_programmes = array();
  $b2b_programme_ids = kandb_update_b2c_b2b_partenaire_get_programme($domain_b2b_id);
  $b2c_programme_ids = kandb_update_b2c_b2b_partenaire_get_programme($domain_b2c_id);
  $b2b_programme_ids_arr = array_chunk($b2b_programme_ids, 100);
  $b2c_programme_ids_arr = array_chunk($b2c_programme_ids, 100);
  $b2b_data = '';
  $b2c_data = '';
  $uri = 'public://partenaire/';
  $prepare_file = file_prepare_directory($uri, FILE_CREATE_DIRECTORY);
  if ($prepare_file) {
    $file_name = 'PROGRAMME.TXT';
    $uri_b2c = $uri . 'b2c';
    file_prepare_directory($uri_b2c, FILE_CREATE_DIRECTORY);
    drupal_chmod($uri_b2c, 0755);
    $uri_b2b = $uri . 'b2b';
    file_prepare_directory($uri_b2b, FILE_CREATE_DIRECTORY);
    drupal_chmod($uri_b2b, 0755);
    $ori_path = $path = drupal_realpath($uri);
    $path = $ori_path . '/b2c/';
    if (file_exists($path)) {
      foreach (glob($path . "/*.*") as $filename) {
        if (is_file($filename)) {
          $tmp_filename = str_replace($path . '/', '', $filename);
          if ($tmp_filename == 'PROGRAMME.TXT') {
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
          if ($tmp_filename == 'PROGRAMME.TXT') {
            unlink($filename);
          }
        }
      }
    }
    file_save_data($b2b_data, $uri_b2b . '/' . $file_name, FILE_EXISTS_REPLACE);
    foreach ($b2b_programme_ids_arr as $k => $v) {
      $b2b_data = kandb_update_b2c_b2b_partenaire_build_programme_data($v);
      if ($b2b_data && $k == count($b2b_programme_ids_arr) - 1) {
        $b2b_data .= "|";
      }
      elseif ($b2b_data) {
        $b2b_data .= "|\n";
      }
      file_put_contents($ori_path . '/b2b/' . $file_name, $b2b_data, FILE_APPEND);
      sleep(5);
    }
    file_save_data($b2c_data, $uri_b2c . '/' . $file_name, FILE_EXISTS_REPLACE);
    
    foreach ($b2c_programme_ids_arr as $k => $v) {
      $b2c_data = kandb_update_b2c_b2b_partenaire_build_programme_data($v);
      if ($b2c_data && $k == count($b2c_programme_ids_arr) - 1) {
        $b2c_data .= "|";
      }
      elseif ($b2c_data) {
        $b2c_data .= "|\n";
      }
      file_put_contents($ori_path . '/b2c/' . $file_name, $b2c_data, FILE_APPEND);
      sleep(5);
    }
    $patenaires = get_partenaire();
    foreach ($patenaires as $patenaire) {
      $vuuid = isset($patenaire->field_id_partenaire[LANGUAGE_NONE][0]['value']) ? $patenaire->field_id_partenaire[LANGUAGE_NONE][0]['value'] : '';
      if ($vuuid != '') {
        $uri_patenaire = $uri . $vuuid;
        $path = $ori_path . $vuuid .'/';
        if (file_exists($path)) {
          foreach (glob($path . "/*.*") as $filename) {
            if (is_file($filename)) {
              $tmp_filename = str_replace($path . '/', '', $filename);
              if ($tmp_filename == 'PROGRAMME.TXT') {
                unlink($filename);
              }
            }
          }
        }
        file_prepare_directory($uri_patenaire, FILE_CREATE_DIRECTORY);
        drupal_chmod($uri_patenaire, 0755);
        $programme_patenaire = array();
        if (isset($patenaire->field_partenaire_programmes[LANGUAGE_NONE])) {
          foreach ($patenaire->field_partenaire_programmes[LANGUAGE_NONE] as $value) {
            $programme_patenaire[] = $value['target_id'];
          }
        }
        $programme_patenaire = kandb_update_b2c_b2b_partenaire_get_programme(NULL, $programme_patenaire);
        $data_patenaire = kandb_update_b2c_b2b_partenaire_build_programme_data($programme_patenaire);
        if ($data_patenaire) {
          file_save_data($data_patenaire, $uri_patenaire . '/' . $file_name, FILE_EXISTS_REPLACE);
        }
      }
    }
  }
}

function get_partenaire(){
  $partenaire = array();
  $db_query = db_select('node', 'n');
  $db_query->fields('n', array('nid'));
  $db_query->condition('n.status', 1);
  $db_query->condition('n.type', 'partenaire');
  $db_query->leftJoin('field_data_field_partenaire_type_flux', 'tf', 'tf.entity_id=n.nid');
  $db_query->condition('tf.entity_type', 'node');
  $db_query->condition('tf.bundle', 'partenaire');
  $db_query->condition('tf.field_partenaire_type_flux_value', 2);
  $db_query->leftJoin('field_data_field_partenaire_export', 'pe', 'pe.entity_id=n.nid');
  $db_query->condition('pe.entity_type', 'node');
  $db_query->condition('pe.bundle', 'partenaire');
  $db_query->condition('pe.field_partenaire_export_value', 3);
  $partenaire = $db_query->distinct()->execute()->fetchCol();
  return node_load_multiple($partenaire);
}
function kandb_update_b2c_b2b_partenaire_get_programme($domain_id = NULL, $programmes_id = array()){
  $nids = array();
  if (!is_numeric($domain_id) && empty($programmes_id)) {
    return $nids;
  }
  $db_query = db_select('node', 'n');
  $db_query->fields('n', array('nid'));
  $db_query->condition('n.status', 1);
  $db_query->condition('n.type', 'programme');
  $db_query->leftJoin('domain_access', 'dm', 'dm.nid=n.nid');
  if (!empty($programmes_id)) {
    $db_query->condition('n.nid', $programmes_id, 'IN');
  }
  elseif(is_numeric($domain_id)) {
    $db_query->condition('dm.gid', $domain_id);
    $db_query->condition('dm.realm', 'domain_id');
  }
  $nids = $db_query->distinct()->execute()->fetchCol();
  return $nids;
}

function kandb_update_b2c_b2b_partenaire_build_programme_data($programmes = array()){
  global $base_url;
  $data = '';
  if(empty($programmes)){
    return $data;
  }
  $default_row = array();
  $mailing_list = trim(str_replace("\r", '', variable_get('kb_call_center_mailing_list', '')));
  $default_row[18] = $default_row[19] = str_replace("\n", ';', $mailing_list);
  $default_row[20] = $default_row[21] = trim(variable_get('kb_call_center_sender_mail', ''));
  $rows = array();
  $reset_sleep = 0;
  foreach ($programmes as $nid) {
    $programme = node_load($nid);
    $biens = get_bien_disponibles_by_programme_id($programme->nid);
    $row = $default_row;
    $col_term_name = array(
      2 => 'field_marque_comm',
      3 => 'field_programme_loc_ville',
      4 => 'field_programme_loc_arr',
      7 => 'field_programme_loc_type',
      13 => 'field_caracteristique_chauffage',
      42 => 'field_tva',
    );
    foreach ($col_term_name as $index => $field) {
      $row[$index] = '';
      if (isset($programme->{$field}[LANGUAGE_NONE][0]['tid'])) {
        $term = taxonomy_term_load($programme->{$field}[LANGUAGE_NONE][0]['tid']);
        $row[$index] = isset($term->name) ? $term->name : '';
      }
    }
    $col_field_value = array(
      0 => 'field_id_programme',
      6 => 'field_programme_loc_num',
      8 => 'field_programme_loc_rue',
      9 => 'field_programme_loc_cp',
      10 => 'field_trimestre',
      11 => 'field_annee',
      16 => 'field_en_quelques_mots',
      22 => 'field_nom_conseiller',
      23 => 'field_espace_vente_adresse',
      27 => 'field_espace_vente_tel',
      28 => 'field_espace_vente_email',
      29 => 'field_espace_vente_horaire',
    );
    foreach ($col_field_value as $index => $field) {
      $row[$index] = isset($programme->{$field}[LANGUAGE_NONE][0]['value']) ? $programme->{$field}[LANGUAGE_NONE][0]['value'] : '';
    }
    $col_empty = array(
      14 => '',
      15 => '',
      17 => '',
      24 => '',
      25 => '',
      26 => '',
      31 => '',
      32 => '',
      33 => '',
      34 => '',
      35 => '',
      36 => '',
      37 => '',
      38 => '',
      39 => '',
      44 => '',
      46 => '',
      47 => '',
      48 => '',
      49 => '',
    );
    foreach ($col_empty as $index => $value) {
      $row[$index] = $value;
    }
    $row[1] = $programme->title;
    $row[5] = count($biens) > 0 ? count($biens) : '';
    $row[12] = get_type_of_bien_disponibles_by_programme_id($biens);
    $row[30] = $base_url . url('node/' . $programme->nid);
    $is_livraison = FALSE;
    $current_year = date('Y');
    $current_month = date('n');
    $current_quarters = ceil($current_month/3);
    if(isset($programme->field_annee[LANGUAGE_NONE][0]['value']) && isset($programme->field_trimestre[LANGUAGE_NONE][0]['value'])) {
      if ($programme->field_annee[LANGUAGE_NONE][0]['value'] == $current_year && $programme->field_trimestre[LANGUAGE_NONE][0]['value'] == $current_quarters) {
        $is_livraison = TRUE;
      }
      elseif($programme->field_annee[LANGUAGE_NONE][0]['value'] == $current_year + 1 && $programme->field_trimestre[LANGUAGE_NONE][0]['value'] == 1 && $current_quarters == 4){
        $is_livraison = TRUE;
      }
    }
    $row[40] = $is_livraison ? 'Livraison immédiate' : '';
    $nouveau = isset($programme->field_nouveau[LANGUAGE_NONE][0]['value']) ? $programme->field_nouveau[LANGUAGE_NONE][0]['value'] : 0;
    $row[41] = $nouveau == 1 ? 'Nouveauté' : '';
    $field_slider_rt2012_bbc = field_info_field('field_slider_rt2012_bbc');
    $field_slider_rt2012_bbc_list_allowed_values = list_allowed_values($field_slider_rt2012_bbc);
    $key_field_slider_rt2012_bbc = isset($programme->field_slider_rt2012_bbc[LANGUAGE_NONE][0]['value']) ? $programme->field_slider_rt2012_bbc[LANGUAGE_NONE][0]['value'] : NULL;
    $row[43] = isset($field_slider_rt2012_bbc_list_allowed_values[$key_field_slider_rt2012_bbc]) ? $field_slider_rt2012_bbc_list_allowed_values[$key_field_slider_rt2012_bbc] : '';
    $row[45] = '';
    $term_name_45 = array();
    if (isset($programme->field_caracteristiques[LANGUAGE_NONE])) {
      foreach ($programme->field_caracteristiques[LANGUAGE_NONE] as $index => $value) {
        $term = taxonomy_term_load($value['tid']);
        if (isset($term->name)) {
          $term_name_45 []= $term->name;
        }
      }
    }
    if (!empty($term_name_45)) {
      $row[45] = implode('&', $term_name_45);
    }
    $row[50] = '';
    if ($programme->status == 1) {
      if (count($biens) > 0) {
        $row[50] = 'oui';
      }
    }
    ksort($row);
    $rows[] = implode('¤', $row);
    $reset_sleep++;
    if ($reset_sleep == 50) {
      $reset_sleep = 0;
      sleep(5);
    }
  }
  $data = implode("|\n", $rows);
  return $data;
}

function get_type_of_bien_disponibles_by_programme_id($biens = array()){
  if (empty($biens)) {
    return '';
  }
  $terms_name = array();
  $db_query = db_select('field_data_field_type', 'ft');//field_type_tid
  $db_query->fields('ft', array('field_type_tid'));
  $db_query->condition('ft.entity_type', 'node');
  $db_query->condition('ft.bundle', 'bien');
  $db_query->condition('ft.entity_id', $biens, 'IN');
  $tids = $db_query->distinct()->execute()->fetchCol();

  foreach($tids as $tid){
    $term = taxonomy_term_load($tid);
    if(isset($term->name)){
      $terms_name[] = $term->name;
    }
  }
  $db_query->fields('ft', array('field_type_tid'));
  return empty($terms_name) ? '' : implode(';', $terms_name);
}
function get_bien_disponibles_by_programme_id($programme_id = 0){
  $biens = array();
  if (!is_numeric($programme_id) || $programme_id == 0) {
    return $biens;
  }
  $db_query = db_select('field_data_field_programme', 'prog');
  $db_query->fields('prog', array('entity_id'));
  $db_query->leftJoin('field_data_field_bien_statut', 'ft', 'ft.entity_id=prog.entity_id');
  $db_query->condition('ft.entity_type', 'node');
  $db_query->condition('ft.bundle', 'bien');
  $db_query->leftJoin('field_data_field_id_xls', 'xls', 'xls.entity_id=ft.field_bien_statut_tid');
  $db_query->condition('xls.entity_type', 'taxonomy_term');
  $db_query->condition('xls.bundle', 'status_logement');
  $db_query->condition('xls.field_id_xls_value', 1);
  $db_query->condition('prog.entity_type', 'node');
  $db_query->condition('prog.bundle', 'bien');
  $db_query->leftJoin('node', 'n', 'n.nid=prog.entity_id');
  $db_query->condition('n.status', 1);
  $db_query->condition('prog.field_programme_target_id', $programme_id);
  $biens = $db_query->distinct()->execute()->fetchCol();
  return $biens;
}

function kandb_partenaire_download_programme_txt($vuuid = '') {
  if ($vuuid == '') {
    return;
  }
  $file_name = 'PROGRAMME.TXT';
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
    if ($node->status == 1 && isset($node->field_partenaire_type_flux[LANGUAGE_NONE][0]['value']) && $node->field_partenaire_type_flux[LANGUAGE_NONE][0]['value'] == 2 && isset($node->field_partenaire_export[LANGUAGE_NONE][0]['value'])) {
      if ($node->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 3) {
        $file_path .= $vuuid . '/' . $file_name;
        if(!is_file($file_path)) {
          $file_exist = FALSE;
        }
      }
      elseif ($node->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 1) {
        $file_path .= 'b2c/' . $file_name;
        if(!is_file($file_path)) {
          $file_exist = FALSE;
        }
      }
      elseif ($node->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 2) {
        $file_path .= 'b2b/' . $file_name;
        if(!is_file($file_path)) {
          $file_exist = FALSE;
        }
      }
    }
    if (!$file_exist) {
      $message = t('File does not exist');
      drupal_set_message($message);
      return $message;
    }
  }
  else {
    $message = t('The partenaire not found');
    drupal_set_message($message);
    return $message;
  }
  if (is_file($file_path)) {
    $content = file_get_contents($file_path);
    if ($content) {
      header('Content-Type: text/plain; charset=utf-8');
      print $content;
    }
    drupal_exit();
  }
  else {
    $message = t('The file to download does not exist.');
    drupal_set_message($message);
    return $message;
  }
}