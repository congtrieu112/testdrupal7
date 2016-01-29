<?php

define('TYPE_FLUX', 2);
define('TYPE_EXPORT', 3);
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
    if ($node->status == 1 && isset($node->field_partenaire_export[LANGUAGE_NONE][0]['value'])) {
      if ($node->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 3) {
        $file_path .= $vuuid . '/LOT.TXT';
        if (is_file($file_path)) {
          $file_path = $partenaire_directory . $vuuid . '/LOT.TXT';
        } else {
          $file_exist = FALSE;
        }
      } elseif ($node->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 1) {
        $file_path .= 'b2c/LOT.TXT';
        if (is_file($file_path)) {
          $file_path = $partenaire_directory . 'b2c/LOT.TXT';
        } else {
          $file_exist = FALSE;
        }
      } elseif ($node->field_partenaire_export[LANGUAGE_NONE][0]['value'] == 2) {
        $file_path .= 'b2b/LOT.TXT';
        if (is_file($file_path)) {
          $file_path = $partenaire_directory . 'b2b/LOT.TXT';
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
    $content = file_get_contents($file_path);
    if ($content) {
      header('Content-Type: text/plain; charset=utf-8');
      print $content;
    }
    drupal_exit();
  } else {
    drupal_set_message(t('The file to download does not exist.'));
  }
}

/**
 * Get partenaire has reference type.
 */
function kandb_get_partenaire_lot_plan() {
  // Export b2b and b2c biens lost.txt.
  kandb_export_common_b2b_b2c();
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'partenaire')
    ->fieldCondition('field_partenaire_type_flux', 'value', TYPE_FLUX, '=')
    ->fieldCondition('field_partenaire_export', 'value', TYPE_EXPORT, '=')
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

/*
 * Implement export parternair has reference.
 */

function kandb_create_partenaire_lot_file($nodes) {
  if ($nodes) {
    foreach ($nodes as $node) {
      $is_export_lot_b2b = isset($node->field_partenaire_lots_b2b[LANGUAGE_NONE][0]['value']) ? (bool) $node->field_partenaire_lots_b2b[LANGUAGE_NONE][0]['value'] : FALSE;
      $is_export_lot_b2c = isset($node->field_partenaire_lots_b2c[LANGUAGE_NONE][0]['value']) ? (bool) $node->field_partenaire_lots_b2c[LANGUAGE_NONE][0]['value'] : FALSE;
      $domain_type = NULL;
      $uri_partenaire = 'public://partenaire/';
      $id_partenaire = $node->field_id_partenaire[LANGUAGE_NONE][0]['value'];
      $uri = $uri_partenaire . $id_partenaire;
      $path_file = drupal_realpath($uri . '/LOT.TXT');
      if (file_exists($path_file)) {
        unlink($path_file);
      }

      if (!file_exists($uri)) {
        mkdir(drupal_realpath($uri), 0777);
      } else {
        chmod(drupal_realpath($uri), 0777);
      }
      $export_type = $node->field_partenaire_export[LANGUAGE_NONE][0]['value'];
      $uri_lots = $uri . '/LOT.TXT';
      if ($export_type == 3 && ($is_export_lot_b2b || $is_export_lot_b2c)) {
        if (!$is_export_lot_b2c) {
          $domain_type = ID_B2B;
        }
        elseif (!$is_export_lot_b2b) {
          $domain_type = ID_B2C;
        }
        if (isset($node->field_partenaire_programmes[LANGUAGE_NONE])) {
          foreach ($node->field_partenaire_programmes[LANGUAGE_NONE] as $item) {
            $bien_nids = kandb_get_biens_by_programme_id_type($item['target_id'], $domain_type);
            if ($bien_nids) {
              $biens = node_load_multiple($bien_nids);
              kandb_export_lots_txt($biens, $uri_lots);
            }
          }
        }
      }
    }
  }
}

/**
 * Implement export common b2c and b2b biens.
 */
function kandb_export_common_b2b_b2c() {
  $uri_partenaire_b2b = 'public://partenaire/b2b/';
  $uri_partenaire_b2c = 'public://partenaire/b2c/';
  $path_file_b2b = drupal_realpath($uri_partenaire_b2b . '/LOT.TXT');
  $path_file_b2c = drupal_realpath($uri_partenaire_b2c . '/LOT.TXT');
  if (file_exists($path_file_b2b)) {
    unlink($path_file_b2b);
  }
  if (file_exists($path_file_b2c)) {
    unlink($path_file_b2c);
  }

  if (!file_exists($uri_partenaire_b2b)) {
    mkdir(drupal_realpath($uri_partenaire_b2b), 0777);
  } else {
    chmod(drupal_realpath($uri_partenaire_b2b), 0777);
  }
  if (!file_exists($uri_partenaire_b2c)) {
    mkdir(drupal_realpath($uri_partenaire_b2c), 0777);
  } else {
    chmod(drupal_realpath($uri_partenaire_b2c), 0777);
  }
  kandb_get_bien_by_domain(ID_B2C, $uri_partenaire_b2c . 'LOT.TXT');
  kandb_get_bien_by_domain(ID_B2B, $uri_partenaire_b2b . 'LOT.TXT');
}

/**
 * Implements get biens by domain and export lots.
 */
function kandb_get_bien_by_domain($type, $uri_lots) {
  $items = get_list_programme_bien_by_domain($type);
  if ($items) {
    foreach ($items as $item) {
      $row = '';
      $biens = '';
      if (isset($item->entity_id) && isset($item->bien_id)) {
        $biens = isset($item->bien_id) ? node_load_multiple(explode(',', $item->bien_id)) : '';
        kandb_export_lots_txt($biens, $uri_lots);
      }
    }
  }
}

/**
 * For testing.
 */
/* function kandb_test() {
  kandb_get_partenaire_lot_plan();
  } */

/**
 * Implements write content to txt.
 */
function kandb_export_lots_txt($biens, $uri_lots) {
  if ($biens) {
    foreach ($biens as $bien) {
      $row = '';
      $numero_lot = isset($bien->field_numero_lot[LANGUAGE_NONE][0]['value']) ? $bien->field_numero_lot[LANGUAGE_NONE][0]['value'] : '';
      $programme_load = isset($bien->field_programme[LANGUAGE_NONE][0]['target_id']) ? node_load($bien->field_programme[LANGUAGE_NONE][0]['target_id']) : '';
      $programme_id = isset($programme_load->field_id_programme[LANGUAGE_NONE][0]['value']) ? $programme_load->field_id_programme[LANGUAGE_NONE][0]['value'] : '';
      $tax_type = isset($bien->field_type[LANGUAGE_NONE][0]['tid']) ? taxonomy_term_load($bien->field_type[LANGUAGE_NONE][0]['tid']) : '';
      $type = isset($tax_type->name) ? $tax_type->name : '';
      $prix_tva_20 = isset($bien->field_prix_tva_20[LANGUAGE_NONE][0]['value']) ? (int) $bien->field_prix_tva_20[LANGUAGE_NONE][0]['value'] : '';
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
      $parking_mode = ($caracteristique_parking > 0) ? t('PARKING NON INCLUS') : t('');
      if ($caracteristique_parking == 0) {
        $parking_carater = t('Parking Compris');
      }
      if ($caracteristique_parking > 0) {
        $parking_carater = (int) $caracteristique_parking;
      }
      $row .= $numero_lot . '¤' . $programme_id . '¤' . $type . '¤' . $prix_tva_20 . '¤' . $nb_pieces . '¤' . $nb_chambres . '¤' . $etage . '¤' . $superficie . '¤' . $orientation . '¤' . $parking_mode . '¤' . $caracteristique_jardin . '¤' . $caracteristique_balcon . '¤' . $caracteristique_terrasse . '¤¤¤¤' . $parking_carater . '|' . "\n";

      if (file_exists($uri_lots)) {
        $current = file_get_contents($uri_lots);
        $current .= $row;
        file_save_data($current, $uri_lots, FILE_EXISTS_REPLACE);
      } else {
        file_save_data($row, $uri_lots, FILE_EXISTS_REPLACE);
      }
    }
  }
}

/**
 * Implements get programmes and biens by domain.
 */
function get_list_programme_bien_by_domain($type) {
  $tid = get_tid_status_du_logement_by_name(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
  if ($tid) {
    $listPartenaire_query = db_select('node', 'n')->distinct();
    $listPartenaire_query->leftjoin('field_data_field_id_programme', 'ip', 'ip.entity_id=n.nid');
    $listPartenaire_query
      ->fields('ip', array('entity_id'))
      ->condition('status', 1);

    if ($type == 3) {
      $str = '(select group_concat(p.entity_id) from node n1 left join field_data_field_programme p on p.entity_id=n1.nid left join domain_access d1 on n1.nid=d1.nid left join field_data_field_bien_statut bs on bs.entity_id=p.entity_id where n1.status=1 and d1.gid = 3 and bs.field_bien_statut_tid = ' . $tid . ' and p.field_programme_target_id = ip.entity_id)';
      $listPartenaire_query->addExpression($str, 'bien_id');
    } elseif ($type == 2) {
      $str = '(select group_concat(p.entity_id) from node n1 left join field_data_field_programme p on p.entity_id=n1.nid left join domain_access d1 on n1.nid=d1.nid left join field_data_field_bien_statut bs on bs.entity_id=p.entity_id where n1.status=1 and d1.gid = 2 and bs.field_bien_statut_tid = ' . $tid . ' and p.field_programme_target_id = ip.entity_id)';
      $listPartenaire_query->addExpression($str, 'bien_id');
    }

    return $listPartenaire_query->execute()->fetchAll();
  }

  return FALSE;
}

/**
 * Implement get term id for type bien.
 */
function get_tid_status_du_logement_by_name($term_name = TAXONOMY_STATUS_LOGEMENT_DISPONIBLE) {
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

/**
 * Implements get biens by programmes_id and type domain.
 */
function kandb_get_biens_by_programme_id_type($programme_id, $type = null) {
  $tid = get_tid_status_du_logement_by_name(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
  if ($tid) {
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_programme', 'p', 'p.entity_id = n.nid');
    $query->condition('p.field_programme_target_id', $programme_id);
    $query->leftJoin('field_data_field_bien_statut', 't', 't.entity_id = n.nid');
    $query->condition('t.field_bien_statut_tid', $tid);
    $query->fields('n', array('nid'));
    $query->condition('n.type', 'bien');
    $query->condition('n.status', 1);
    if ($type) {
      $query->leftJoin('domain_access', 'dm', 'dm.nid=n.nid');
      $query->condition('dm.realm', 'domain_id');
      $query->condition('dm.gid', $type);
    }
    $result = $query->execute()->fetchCol();
    if (isset($result)) {
      return $result;
    }
  }
  return false;
}
