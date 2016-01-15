<?php

define('TYPE_FLUX', 2);
define('ID_B2B', 2);
define('ID_B2C', 3);

function kandb_partenaire_lots_prepare_download_file($vuuid = '') {
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

function kandb_get_partenaire_lot_plan() {
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'partenaire')
    ->fieldCondition('field_partenaire_type_flux', 'value', TYPE_FLUX, '=')
    ->propertyCondition('status', NODE_PUBLISHED);

  $result = $query->execute();

  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
    if ($nodes) {
      kandb_create_partenaire_lot_file($nodes);
    }
  }
}

function kandb_create_partenaire_lot_file($nodes) {
  if ($nodes) {
    foreach ($nodes as $node) {
      $uri_partenaire = 'public://partenaire/';
      $id_partenaire = $node->field_id_partenaire[LANGUAGE_NONE][0]['value'];
      $uri = $uri_partenaire . $id_partenaire;
      $path_file = drupal_realpath($uri . '/lots.txt');
      if (file_exists($path_file)) {
        unlink($path_file);
      }

      if (!file_exists($uri)) {
        mkdir(drupal_realpath($uri), 0777);
      } else {
        chmod(drupal_realpath($uri), 0777);
      }
      $export_type = $node->field_partenaire_export[LANGUAGE_NONE][0]['value'];
      $uri_lots = $uri . '/lots.txt';
      if ($export_type == 1) {
        kandb_get_bien_by_domain(ID_B2C, $uri_lots);
      }
      if ($export_type == 2) {
        kandb_get_bien_by_domain(ID_B2B, $uri_lots);
      }
      if ($export_type == 3) {
        kandb_get_bien_by_domain(null, $uri_lots);
      }
    }
  }
}

function kandb_get_bien_by_domain($type, $uri_lots) {
  $items = getListProgrammeBienByDomain($type);
  if ($items) {
    foreach ($items as $item) {
      $row = '';
      if (isset($item->entity_id) && isset($item->bien_id)) {
        $biens = isset($item->bien_id) ? node_load_multiple(explode(',', $item->bien_id)) : '';
        foreach ($biens as $bien) {
          $numero_lot = isset($bien->field_numero_lot[LANGUAGE_NONE][0]['value']) ? $bien->field_numero_lot[LANGUAGE_NONE][0]['value'] : '';
          $programme_load = isset($bien->field_programme[LANGUAGE_NONE][0]['target_id']) ? node_load($bien->field_programme[LANGUAGE_NONE][0]['target_id']) : '';
          $programme_id = isset($programme_load->field_id_programme[LANGUAGE_NONE][0]['value']) ? $programme_load->field_id_programme[LANGUAGE_NONE][0]['value'] : '';
          $tax_type = isset($bien->field_type[LANGUAGE_NONE][0]['tid']) ? taxonomy_term_load($bien->field_type[LANGUAGE_NONE][0]['tid']) : '';
          $type = isset($tax_type->name) ? $tax_type->name : '';
          $prix_tva_20 = isset($bien->field_prix_tva_20[LANGUAGE_NONE][0]['value']) ? $bien->field_prix_tva_20[LANGUAGE_NONE][0]['value'] : '';
          $tax_nb_pieces = isset($bien->field_nb_pieces[LANGUAGE_NONE][0]['tid']) ? taxonomy_term_load($bien->field_nb_pieces[LANGUAGE_NONE][0]['tid']) : '';
          $nb_pieces = isset($tax_nb_pieces->field_id_nombre_pieces[LANGUAGE_NONE][0]['value']) ? $tax_nb_pieces->field_id_nombre_pieces[LANGUAGE_NONE][0]['value'] : '';
          $tax_nb_chambres = isset($bien->field_nb_chambres[LANGUAGE_NONE][0]['tid']) ? taxonomy_term_load($bien->field_nb_chambres[LANGUAGE_NONE][0]['tid']) : '';
          $nb_chambres = isset($tax_nb_chambres->field_id_nombre_chambre[LANGUAGE_NONE][0]['value']) ? $tax_nb_chambres->field_id_nombre_chambre[LANGUAGE_NONE][0]['value'] : '';
          //field_etage
          $tax_etage = isset($bien->field_etage[LANGUAGE_NONE][0]['tid']) ? taxonomy_term_load($bien->field_etage[LANGUAGE_NONE][0]['tid']) : '';
          $etage = isset($tax_etage->name) ? $tax_etage->name : '';
          //field_superficie
          $superficie = isset($bien->field_superficie[LANGUAGE_NONE][0]['value']) ? $bien->field_superficie[LANGUAGE_NONE][0]['value'] : '';
          //field_orientation
          $tax_orientation = isset($bien->field_orientation[LANGUAGE_NONE][0]['tid']) ? taxonomy_term_load($bien->field_orientation[LANGUAGE_NONE][0]['tid']) : '';
          $orientation = isset($tax_orientation->name) ? $tax_orientation->name : '';
          //field_caracteristique_jardin
          $caracteristique_jardin = isset($bien->field_caracteristique_jardin[LANGUAGE_NONE][0]['value']) ? $bien->field_caracteristique_jardin[LANGUAGE_NONE][0]['value'] : '';
          //field_caracteristique_balcon
          $caracteristique_balcon = isset($bien->field_caracteristique_balcon[LANGUAGE_NONE][0]['value']) ? $bien->field_caracteristique_balcon[LANGUAGE_NONE][0]['value'] : '';
          //field_caracteristique_terrasse
          $caracteristique_terrasse = isset($bien->field_caracteristique_terrasse[LANGUAGE_NONE][0]['value']) ? $bien->field_caracteristique_terrasse[LANGUAGE_NONE][0]['value'] : '';
          //field_caracteristique_parking
          $caracteristique_parking = isset($bien->field_caracteristique_parking[LANGUAGE_NONE][0]['value']) ? $bien->field_caracteristique_parking[LANGUAGE_NONE][0]['value'] : '';
          $parking_carater = '';
          if ($caracteristique_parking == 0) {
            $parking_carater = t('Parking Compris');
          }
          if ($caracteristique_parking > 0) {
            $parking_carater = $caracteristique_parking;
          }
          $row .= $numero_lot . '¤' . $programme_id . '¤' . $type . '¤' . $prix_tva_20 . '¤' . $nb_pieces . '¤' . $nb_chambres . '¤' . $etage . '¤' . $superficie . '¤' . $orientation . '¤' . $parking_carater . '¤' . $caracteristique_jardin . '¤' . $caracteristique_balcon . '¤' . $caracteristique_terrasse . '¤¤¤¤' . $parking_carater . '|' . "\n";
          file_save_data($row, $uri_lots, FILE_EXISTS_REPLACE);
        }
      }
    }
  }
}

function kandb_test() {
  kandb_get_partenaire_lot_plan();
}

function getListProgrammeBienByDomain($type) {
  $tid = getTidStatusDuLogementByName(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
  if ($tid) {
    $listPartenaire_query = db_select('node', 'n')->distinct();
    $listPartenaire_query->leftjoin('field_data_field_id_programme', 'ip', 'ip.entity_id=n.nid');
    $listPartenaire_query->leftJoin('domain_access', 'd', 'd.nid=n.nid');
    $listPartenaire_query
      ->fields('ip', array('entity_id'))
      ->condition('status', 1);

    if ($type == 3) {
      $str = '(select group_concat(p.entity_id) from node n1 left join field_data_field_programme p on p.entity_id=n1.nid left join domain_access d1 on n1.nid=d1.nid left join field_data_field_bien_statut bs on bs.entity_id=p.entity_id where n1.status=1 and d1.gid = 3 and bs.field_bien_statut_tid = ' . $tid . ' and p.field_programme_target_id = ip.entity_id)';
      $listPartenaire_query->condition('d.gid', 3);
      $listPartenaire_query->addExpression($str, 'bien_id');
    } elseif ($type == 2) {
      $str = '(select group_concat(p.entity_id) from node n1 left join field_data_field_programme p on p.entity_id=n1.nid left join domain_access d1 on n1.nid=d1.nid left join field_data_field_bien_statut bs on bs.entity_id=p.entity_id where n1.status=1 and d1.gid = 2 and bs.field_bien_statut_tid = ' . $tid . ' and p.field_programme_target_id = ip.entity_id)';
      $listPartenaire_query->condition('d.gid', 2);
      $listPartenaire_query->addExpression($str, 'bien_id');
    }

    return $listPartenaire_query->execute()->fetchAll();
  }

  return FALSE;
}

function getTidStatusDuLogementByName($term_name = TAXONOMY_STATUS_LOGEMENT_DISPONIBLE) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term');
  $query->propertyCondition('name', $term_name);
  $query->range(0, 1);

  $results = $query->execute();
  if ($results) {
    return array_shift($results["taxonomy_term"])->tid;
  }

  return 0;
}
