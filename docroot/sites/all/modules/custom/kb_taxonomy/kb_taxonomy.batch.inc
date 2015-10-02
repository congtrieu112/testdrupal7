<?php

/**
 * @file
 * Functions callback for batch.
 */

function batch_kb_taxonomy_one_time_process(&$context) {
    $path = drupal_get_path('module', 'kb_taxonomy') . '/data-ori/';
    $vocabularies = array(
        'chauffage' => array(
            'title' => 'Chauffage',
            'file' => 'chauffage.txt'
        ),
        'departement' => array(
            'title' => 'Departement',
            'file' => 'departement.txt'
        ),
        'marque_de_commercialisation' => array(
            'title' => 'Marque de Commercialisation',
            'file' => 'marque_de_commercialisation.txt'
        ),
        'type_de_programme' => array(
            'title' => 'Type de programme',
            'file' => 'type_de_programme.txt'
        ),
        'type_logement' => array(
            'title' => 'Type Logement',
            'file' => 'type_logement.txt'
        ),
        'zone' => array(
            'title' => 'Zone',
            'file' => 'zone.txt'
        ),
        'nombre_piece' => array(
            'title' => 'Nombre Piece',
            'file' => 'nombre_piece.txt'
        ),
        'nombre_chambre' => array(
            'title' => 'Nombre Chambre',
            'file' => 'nombre_chambre.txt'
        ),
        'etage_si_appartement' => array(
            'title' => 'Etage (si appartement)',
            'file' => 'etage_si_appartement.txt'
        ),
        'orientation' => array(
            'title' => 'Orientation',
            'file' => 'orientation.txt'
        ),
        'statut_logement' => array(
            'title' => 'Statut Logement',
            'file' => 'statut_logement.txt'
        ),
        'visibilite_logement' => array(
            'title' => 'Visibilite Logement',
            'file' => 'visibilite_logement.txt'
        ),
        'voie_type' => array(
            'title' => 'Type de voie',
            'file' => 'voie_type.txt'
        ),
    );
    $indexes = array_keys($vocabularies);
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($vocabularies);
  }
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    $current_voc = $vocabularies[$indexes[$context['sandbox']['progress']]];
    $context['results'][] = $current_voc['title'];
    $context['message'] = $current_voc['title'];
    $data = file_get_contents($path . $current_voc['file']);
    kb_taxonomy_create_terms($indexes[$context['sandbox']['progress']], $data);
  }
  $context['sandbox']['progress']++;
}

function batch_kb_taxonomy_one_time_finished($success, $results, $operations) {
  if ($success) {
    $message = t('@count vocabularies successfully processed:', array('@count' => count($results)));
    $message .= theme('item_list', array('items' => $results));
    drupal_set_message($message);
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
}

function kb_taxonomy_create_terms($v_name, $data) {
    if ($v_name == '' || trim($data) == '') {
        return ;
    }
    $arr_rows = preg_split('/\|/', $data);
    $vid = kb_taxonomy_get_vocabulary_by_name($v_name);
    $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vid));
    $ids = array();
    $arr_old_source = array();
    $id_source = array();
    foreach ($terms as $k => $term) {
       $ids[$term->field_source_data['und'][0]['value']] = $term->tid; 
       $arr_old_source[$k] = $term->field_source_data['und'][0]['value'];
       switch ($v_name) {
           case 'chauffage':
                $id_source[$term->field_idkc['und'][0]['value']] = $k;
           break;
           case 'departement':
                $id_source[$term->field_idkd['und'][0]['value']] = $k;
                break;
           case 'marque_de_commercialisation':
                $id_source[$term->field_idkb['und'][0]['value']] = $k;
                break;
           case 'type_de_programme':
                $id_source[$term->field_idktp['und'][0]['value']] = $k;
                break;
           case 'type_logement':
                $id_source[$term->field_idktl['und'][0]['value']] = $k;
                break;
           case 'zone':
                $id_source[$term->field_idkz['und'][0]['value']] = $k;
                break;
           case 'nombre_piece':
                $id_source[$term->field_nbre_pieces['und'][0]['value']] = $k;
                break;
           case 'nombre_chambre':
                $id_source[$term->field_nbre_chambres['und'][0]['value']] = $k;
                break;
           case 'etage_si_appartement':
                $id_source[$term->field_etage['und'][0]['value']] = $k;
                break;
           case 'orientation':
                $id_source[$term->field_idko['und'][0]['value']] = $k;
                break;
           case 'statut_logement':
                $id_source[$term->field_statut['und'][0]['value']] = $k;
                break;
           case 'visibilite_logement':
                $id_source[$term->field_visibilite['und'][0]['value']] = $k;
                break;
           case 'voie_type':
                $id_source[$term->field_voie_type['und'][0]['value']] = $k;
                break;
       }
    }
    foreach ($arr_rows as $row) {
        $str = trim($row);
        if ($str) {
            if (in_array($str, $arr_old_source)) {
                unset($terms[$ids[$str]]);
            }
            else {
                $cols = preg_split('/@/', $str);
                if (array_key_exists($id_source, $cols[0])) {
                    $term = $terms[$id_source[$cols[0]]];
                    unset($terms[$term->tid]);
                }
                else {
                    $term = new stdClass();
                }
                $term->field_source_data['und'][0]['value'] = $str;
                $term->name = $cols[1];
                $term->vid = kb_taxonomy_get_vocabulary_by_name($v_name);
                switch ($v_name) {
                    case 'chauffage':
                        $term->field_idkc['und'][0]['value'] = $cols[0];
                        break;
                    case 'departement':
                        $term->field_idkd['und'][0]['value'] = $cols[0];
                        break;
                    case 'marque_de_commercialisation':
                        $term->field_idkb['und'][0]['value'] = $cols[0];
                        break;
                    case 'type_de_programme':
                        $term->field_idktp['und'][0]['value'] = $cols[0];
                        break;
                    case 'type_logement':
                        $term->field_idktl['und'][0]['value'] = $cols[0];
                        break;
                    case 'zone':
                        $term->field_idkz['und'][0]['value'] = $cols[0];
                        break;
                    case 'nombre_piece':
                        $term->field_nbre_pieces['und'][0]['value'] = $cols[0];
                        break;
                    case 'nombre_chambre':
                        $term->field_nbre_chambres['und'][0]['value'] = $cols[0];
                        break;
                    case 'etage_si_appartement':
                        $term->field_etage['und'][0]['value'] = $cols[0];
                        break;
                    case 'orientation':
                        $term->field_idko['und'][0]['value'] = $cols[0];
                        break;
                    case 'statut_logement':
                        $term->field_statut['und'][0]['value'] = $cols[0];
                        break;
                    case 'visibilite_logement':
                        $term->field_visibilite['und'][0]['value'] = $cols[0];
                        break;
                    case 'voie_type':
                        $term->field_voie_type['und'][0]['value'] = $cols[0];
                        break;
                    }
                taxonomy_term_save($term);
            }
        }
    }
    foreach ($terms as $k => $v) {
        taxonomy_term_delete($k);
    }
}

function batch_kb_taxonomy_daily_process($type, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $path = drupal_get_path('module', 'kb_taxonomy');
    if ($type == 'city') {
      $city_data = file_get_contents($path . '/data-ori/VILLE.TXT');
      $all_rows = preg_split('/\|/', $city_data);
      $db_query = db_select('field_data_field_idk', 'idk');
      $db_query->fields('idk', array('entity_id', 'field_idk_value'));
      $db_query->condition('idk.entity_type', 'taxonomy_term');
      $db_query->condition('idk.bundle', 'city');
      $db_query->leftJoin('field_data_field_source_data', 'sd', 'sd.entity_id=idk.entity_id');
      $db_query->condition('sd.entity_type', 'taxonomy_term');
      $db_query->condition('sd.bundle', 'city');
      $db_query->addField('sd', 'field_source_data_value');
      $db_query->distinct();
      $all_terms = $db_query->execute()->fetchAll();
    }
    elseif ($type == 'district') {
        $district_data = file_get_contents($path . '/data-ori/ARRONDISSEMENT.TXT');
        $all_rows = preg_split('/\|/', $district_data);
        $db_query = db_select('field_data_field_idka', 'idka');
        $db_query->fields('idka', array('entity_id', 'field_idka_value'));
        $db_query->condition('idka.entity_type', 'taxonomy_term');
        $db_query->condition('idka.bundle', 'district');
        $db_query->leftJoin('field_data_field_source_data', 'sd', 'sd.entity_id=idka.entity_id');
        $db_query->condition('sd.entity_type', 'taxonomy_term');
        $db_query->condition('sd.bundle', 'district');
        $db_query->addField('sd', 'field_source_data_value');
        $db_query->distinct();
        $all_terms = $db_query->execute()->fetchAll(); 
    }
    $context['sandbox']['all_row'] = $all_rows;
    $context['sandbox']['all_terms'] = $all_terms;
  }
  $all_rows = $context['sandbox']['all_row'];
  $all_terms = $context['sandbox']['all_terms'];
  $context['sandbox']['max'] = count($all_rows);
  $context['results']['max'] = $context['sandbox']['progress'];
  $context['message'] = 'Processed ' . $context['sandbox']['progress'] . '/' . $context['sandbox']['max'] . ' terms';
  $row = $all_rows[$context['sandbox']['progress']];
    if ($type == 'city') {
        $tid = import_city_table($row, $all_terms);
    }
    if ($type == 'district') {
        $tid = import_district_table($row, $all_terms);
    }
    if ($tid != -1) {
        $context['sandbox']['processed'][] = $tid;
    }
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
  else {
      $context['finished'] = 1;
      foreach ($all_terms as $term) {
          if (!in_array($term->entity_id, $context['sandbox']['processed'])) {
              taxonomy_term_delete($term->entity_id);
          }
      }
  }
  $context['sandbox']['progress']++;
}

function import_city_table($row, $all_city) {
    $vid = kb_taxonomy_get_vocabulary_by_name('city');
    if (!$vid) {
        return;
    }
    $idkvs = array();
    $sd = array();
    $tid = -1;
    foreach ($all_city as $index => $city) {
        $idkvs[$city->entity_id] = $city->field_idk_value;
        $sd[$city->entity_id] = $city->field_source_data_value;
    }
        $str = trim(mb_convert_encoding($row, "UTF-8", 'iso-8859-1'));
        if ($str != '') {
            $cols = preg_split('/\¤/' , $str );
            $tmp_rf = strlen($cols[4]) == 1 ? '0' . $cols[4] : $cols[4];
            $db_query = db_select('field_data_field_idkd', 'idkd');
            $db_query->fields('idkd', array('entity_id'));
            $db_query->condition('idkd.entity_type', 'taxonomy_term');
            $db_query->condition('idkd.bundle', 'departement');
            $db_query->condition('idkd.field_idkd_value', $tmp_rf);
            $idkd = $db_query->execute()->fetchField();
            if (!in_array($cols[0], $idkvs)) {
                $term = new stdClass();
                $term->field_idk['und'][0]['value'] = $cols[0];
                $term->name = $cols[1];
                $term->field_longitude['und'][0]['value'] = $cols[2];
                $term->field_latitude['und'][0]['value'] = $cols[3];
                if ($idkd) {
                    $term->field_idkd_rf['und'][0]['tid'] = $idkd;
                }
                $term->field_source_data['und'][0]['value'] = $str;
                $term->vid = $vid;
                taxonomy_term_save($term);
            }
            else {
                $tid = array_search($cols[0], $idkvs);
                if (!(isset($sd[$tid]) && $sd[$tid] == $str)) {
                    $term = taxonomy_term_load($tid);
                    $term->name = $cols[1];
                    $term->field_longitude['und'][0]['value'] = $cols[2];
                    $term->field_latitude['und'][0]['value'] = $cols[3];
                    if ($idkd) {
                        $term->field_idkd_rf['und'][0]['tid'] = $idkd;
                    }
                    $term->field_source_data['und'][0]['value'] = $str;
                    taxonomy_term_save($term);
                }
            }
        }
    return $tid;
}

function import_district_table($row, $all_district) {
    $vid = kb_taxonomy_get_vocabulary_by_name('district');
    if (!$vid) {
        return;
    }
    $idkas = array();
    $sd = array();
    $tid = -1;
    foreach ($all_district as $index => $district) {
        $idkas[$district->entity_id] = $district->field_idka_value;
        $sd[$district->entity_id] = $district->field_source_data_value;
    }
        $str = trim(mb_convert_encoding($row, "UTF-8", 'iso-8859-1'));
        if ($str != '') {
            $cols = preg_split('/¤/' , $str );
            $db_query = db_select('field_data_field_idk', 'idk');
            $db_query->fields('idk', array('entity_id'));
            $db_query->condition('idk.entity_type', 'taxonomy_term');
            $db_query->condition('idk.bundle', 'city');
            $db_query->condition('idk.field_idk_value', $cols[1]);
            $idk = $db_query->execute()->fetchField();
            if (!in_array($cols[0], $idkas)) {
                $term = new stdClass();
                $term->field_idka['und'][0]['value'] = $cols[0];
                if ($idk) {
                    $term->field_idk_rf['und'][0]['tid'] = $idk;
                }
                $term->name = $cols[2];
                $term->field_longitude['und'][0]['value'] = $cols[3];
                $term->field_latitude['und'][0]['value'] = $cols[4];
                $term->field_source_data['und'][0]['value'] = $str;
                $term->vid = $vid;
                taxonomy_term_save($term);
            }
            else {
                $tid = array_search($cols[0], $idkas);
                if (!(isset($sd[$tid]) && $sd[$tid] == $str)) {
                    $term = taxonomy_term_load($tid);
                    if ($idk) {
                        $term->field_idk_rf['und'][0]['tid'] = $idk;
                    }
                    $term->name = $cols[2];
                    $term->field_longitude['und'][0]['value'] = $cols[3];
                    $term->field_latitude['und'][0]['value'] = $cols[4];
                    $term->field_source_data['und'][0]['value'] = $str;
                    taxonomy_term_save($term);
                }
            }
        }
    return $tid;
}

function batch_kb_taxonomy_daily_finished($success, $results, $operations) {
  if ($success) {
    $message = t('@count terms successfully processed', array('@count' => $results['max']));
    drupal_set_message($message);
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
}