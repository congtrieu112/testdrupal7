<?php

function kandb_bien_block_info() {
    $blocks['appartements_disponibles'] = array(
        'info' => 'Appartements disponibles on bien page',
    );
    return $blocks;
}
function kandb_bien_block_view($delta) {
    $block = array();
    switch ($delta) {
        case 'appartements_disponibles':
            _get_block_data($delta, $block);
            break;
    }
    return $block;
}
function kandb_bien_theme($existing, $type, $theme, $path) {
    return array(
        'bien_block_appartements_disponibles' => array(
            'variables' => array(
                'biens_rows' => NULL,
            ),
            'template' => 'appartements_disponibles',
        ),
    );
}
function _get_block_data($delta, &$block) {
    $block = array('subject' => '', 'content' => '');
    if($delta == 'appartements_disponibles'){
        if(arg(0) == 'node' && is_numeric(arg(1)) && arg(2) == NULL) {
            $nids = array();
            $block['subject'] = 'Appartements de 3 pièces disponibles';
            $block['content'] = '';
            $current_bien_id = arg(1);
            $least_most_expensive = array();
            $current_bien = node_load($current_bien_id);
            if(!$current_bien || !isset($current_bien->type) || $current_bien->type != 'bien') {
                return ;
            }
            $nbr = 0;
            if(isset($current_bien->field_nb_pieces[LANGUAGE_NONE][0]['tid'])){
                $term_nbr = taxonomy_term_load($current_bien->field_nb_pieces[LANGUAGE_NONE][0]['tid']);
                if(isset($term_nbr->field_id_nombre_pieces[LANGUAGE_NONE][0]['value'])){
                    $nbr = $term_nbr->field_id_nombre_pieces[LANGUAGE_NONE][0]['value'];
                    $block['subject'] = t('Appartements de @nbr pièces disponibles', array('@nbr' => $nbr));
                }
            }
            $programme_id = 0;
            if(isset($current_bien->field_programme[LANGUAGE_NONE][0]['target_id'])) {
                $programme_id = $current_bien->field_programme[LANGUAGE_NONE][0]['target_id'];
            }
            $programme = node_load($programme_id);
            $current_prix = 0;
            if(isset($current_bien->field_prix_tva_20[LANGUAGE_NONE][0]['value'])) {
                $current_prix = (float)$current_bien->field_prix_tva_20[LANGUAGE_NONE][0]['value'];
            }
            $programme_stock = 100;
            if(isset($programme->field_programme_stock[LANGUAGE_NONE][0]['value'])){
                $programme_stock = (int)$programme->field_programme_stock[LANGUAGE_NONE][0]['value'];
            }
            //Select biens related
            $db_query = db_select('node', 'n');
            $db_query->fields('n', array('nid'));
            $db_query->condition('n.status', 1);
            $db_query->condition('n.nid', $current_bien_id, '<>');
            $db_query->condition('n.type', 'bien');
            //Bien in Disponible
            $db_query->leftJoin('field_data_field_bien_statut', 'bst', 'bst.entity_id=n.nid');
            $db_query->condition('bst.entity_type', 'node');
            $db_query->condition('bst.bundle', 'bien');
            $db_query->leftJoin('field_data_field_id_xls', 'xls', 'bst.field_bien_statut_tid=xls.entity_id');
            $db_query->condition('xls.entity_type', 'taxonomy_term');
            $db_query->condition('xls.bundle', 'status_logement');
            $db_query->condition('xls.field_id_xls_value', 1);
            //The same programme
            if($programme_id != 0) {
                $db_query->leftJoin('field_data_field_programme', 'prg', 'prg.entity_id=n.nid');
                $db_query->condition('prg.entity_type', 'node');
                $db_query->condition('prg.bundle', 'bien');
                $db_query->condition('prg.field_programme_target_id', $programme_id);
            }
            //Get prix of bien
            $db_query->leftJoin('field_data_field_prix_tva_20', 'prix', 'prix.entity_id=n.nid');
            $db_query->condition('prix.entity_type', 'node');
            $db_query->condition('prix.bundle', 'bien');
            $db_query->addField('prix', 'field_prix_tva_20_value');
            //Get field_nb_pieces field
            $db_query->leftJoin('field_data_field_nb_pieces', 'nbr', 'nbr.entity_id=n.nid');
            $db_query->condition('nbr.entity_type', 'node');
            $db_query->condition('nbr.bundle', 'bien');
            $db_query->leftJoin('field_data_field_id_nombre_pieces', 'id_nbr', 'id_nbr.entity_id=nbr.field_nb_pieces_tid');
            $db_query->condition('id_nbr.entity_type', 'taxonomy_term');
            $db_query->condition('id_nbr.bundle', 'nb_pieces');
            if($nbr > 0) {
                $db_query->condition('id_nbr.field_id_nombre_pieces_value', $nbr);
            }
            $all_biens = $db_query->distinct()->execute()->fetchAll();
            if(empty($all_biens)){
                return ;
            }
            $limit = round(count($all_biens) * $programme_stock / 100, 0);
            if($current_prix == 0){
                $least_most_expensive = array_slice($all_biens, 0, $limit);
                foreach($least_most_expensive as $k => $v) {
                    $nids[] = $v->nid;
                }
            }
            else {
                $least_expensive_number = $most_expensive_number = $limit / 2;
                if($limit%2 == 1){
                    $least_expensive_number = ($limit - 1)/2 + 1;
                    $most_expensive_number  = ($limit - 1)/2;
                }
                $rejected_bien = array();
                foreach ($all_biens as $k => $bien) {
                    if ($bien->field_prix_tva_20_value < $current_prix && $least_expensive_number > 0) {
                        $nids[] = $bien->nid;
                        $least_expensive_number--;
                    }
                    elseif ($bien->field_prix_tva_20_value > $current_prix && $most_expensive_number > 0) {
                        $nids[] = $bien->nid;
                        $most_expensive_number--;
                    }
                    else {
                        $rejected_bien[] = $bien;
                    }
                }
                if($most_expensive_number > 0 || $least_expensive_number > 0){
                    $addition_bien = $most_expensive_number + $least_expensive_number;
                    foreach ($rejected_bien as $k => $bien) {
                        if ($addition_bien > 0) {
                            $nids[] = $bien->nid;
                            $addition_bien--;
                        }
                    }
                }
            }
            
            $nodes = node_load_multiple($nids);
            $biens_variables = array();
            foreach ($nodes as $nid => $node) {
                //Id of bien
                $biens_variables[$nid]['id'] = '';
                if(isset($node->field_id_bien[LANGUAGE_NONE][0]['value'])){
                    $id_bien  = $node->field_id_bien[LANGUAGE_NONE][0]['value'];
                    if(strpos($id_bien, '-') > 0){
                        $id_bien = substr($id_bien, strrpos($id_bien, '-') + 1);
                    }
                    $biens_variables[$nid]['id'] = $id_bien;
                }
                //Prix 20% and 5.5%
                $biens_variables[$nid]['prix_20'] = '';
                $biens_variables[$nid]['prix_5_5'] = '';
                if(isset($node->field_prix_tva_20[LANGUAGE_NONE][0]['value'])){
                    $biens_variables[$nid]['prix_20'] = $node->field_prix_tva_20[LANGUAGE_NONE][0]['value'];
                    $biens_variables[$nid]['prix_5_5'] = $biens_variables[$nid]['prix_20'] / 1.2 * 1.055;
                }
                //caracteristiques
                $biens_variables[$nid]['caracteristiques'] = '';
                if(isset($node->field_caracteristiques[LANGUAGE_NONE])){
                    $caracteristiques_arr = array();
                    foreach($node->field_caracteristiques[LANGUAGE_NONE] as $id => $value) {
                        $caracteristiques_arr[] = $value['value'];
                    }
                    $biens_variables[$nid]['caracteristiques'] = implode(' - ', $caracteristiques_arr);
                }
                //field_superficie
                $biens_variables[$nid]['superficie'] = '';
                if(isset($node->field_superficie[LANGUAGE_NONE][0]['value'])){
                    $biens_variables[$nid]['superficie'] = $node->field_superficie[LANGUAGE_NONE][0]['value'];
                }
                //field_etage
                $biens_variables[$nid]['etage'] = '';
                if(isset($node->field_etage[LANGUAGE_NONE][0]['tid'])){
                    $term_etage = taxonomy_term_load($node->field_etage[LANGUAGE_NONE][0]['tid']);
                    if(isset($term_etage->field_id_etage[LANGUAGE_NONE][0]['value'])) {
                        $biens_variables[$nid]['etage'] = $term_etage->field_id_etage[LANGUAGE_NONE][0]['value'];
                    }
                }
            }
            $block['content'] = theme('bien_block_appartements_disponibles', array('biens_rows' => $biens_variables));
        }
    }
}
