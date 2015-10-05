<?php

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

function kb_process_voc($all_vocs , $current_voc, $machine_names){
    foreach ($current_voc as $k => $v) {
        if (!in_array($k, $machine_names)) {
            $new_voc = new stdClass();
            $new_voc->name = $v['title'];
            $new_voc->description = $v['description'];
            $new_voc->machine_name = $k;
            $new_voc->hierarchy = 0;
            $new_voc->module = 'taxonomy';
            $new_voc->weight = 0;
            taxonomy_vocabulary_save($new_voc);
            foreach($v['fields'] as $field_name => $op){
                $field = field_info_field($field_name);
                if($field == NULL){
                    $field = array(
                        'settings' => $op['settings'],
                        'field_name' => $field_name,
                        'type' => $op['type'],
                        'module' => $op['module'],
                    );
                    field_create_field($field);
                }
                $field_instance = field_info_instance('taxonomy_term', $field_name, $k);
                if($field_instance == NULL){
                    $field_instance = array(
                        'label' => $op['title'],
                        'field_name' => $field_name,
                        'entity_type' => 'taxonomy_term',
                        'bundle' => $k,
                    );
                    field_create_instance($field_instance);
                }
            }
            $field_sd = field_info_field('field_source_data');
            if($field_sd == NULL){
                $field_sd = array(
                    'settings' => array('max_length' => 255),
                    'field_name' => 'field_source_data',
                    'type' => 'text',
                    'module' => 'text',
                );
                field_create_field($field_sd);
            }
            $field_sd_instance = field_info_instance('taxonomy_term', 'field_source_data', $k);
            if($field_sd_instance == NULL){
                $field_sd_instance = array(
                    'label' => 'Source data',
                    'field_name' => 'field_source_data',
                    'entity_type' => 'taxonomy_term',
                    'bundle' => $k,
               );
               field_create_instance($field_sd_instance);
            }
        }
        else {
            $vid = array_search($k, $machine_names);
            $tmp_voc = $all_vocs[$vid];
            if($tmp_voc->name != $v['title'] || $tmp_voc->description != $v['description']){
                $tmp_voc->name = $v['title'];
                $tmp_voc->description = $v['description'];
                taxonomy_vocabulary_save($tmp_voc);
            }
        }
    }
}
function batch_kb_taxonomy_voc_process($vocs , $process){
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($process);
    $context['sandbox']['all_vocs'] = taxonomy_get_vocabularies(NULL);
    $machine_names = array();
    foreach ($context['sandbox']['all_vocs'] as $id => $voc) {
        $machine_names[$id] = $voc->machine_name;
    }
    $context['sandbox']['machine_names'] = $machine_names;
  }
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    $current_voc = $vocs[$process[$context['sandbox']['progress']]];
    $context['results'][] = $current_voc['title'];
    $context['message'] = $current_voc['title'];
    $all_vocs = $context['sandbox']['all_vocs'];
    kb_process_voc($all_vocs , array($process[$context['sandbox']['progress']] => $current_voc), $context['sandbox']['machine_names']);
  }
  $context['sandbox']['progress']++;  
}

function batch_kb_taxonomy_term_process($vocs , $process){
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($process);
  }
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    $current_voc = $vocs[$process[$context['sandbox']['progress']]];
    $context['results'][] = $current_voc['title'];
    $context['message'] = $current_voc['title'];
    $all_terms = '';
    kb_process_term($process[$context['sandbox']['progress']], $current_voc);
  }
  $context['sandbox']['progress']++;  
}
function kb_process_term($v_name, $current_voc){
    $mapping = $current_voc['mapping_data'];
    $file = drupal_get_path('module', 'kb_taxonomy') . '/data-ori/' . $v_name . '.txt';
    if(!file_exists($file)){
        return ;
    }
    $data = file_get_contents($file);
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
       $ids[$term->field_source_data[LANGUAGE_NONE][0]['value']] = $term->tid; 
       $arr_old_source[$k] = $term->field_source_data[LANGUAGE_NONE][0]['value'];
       $id_source[$term->{$mapping[0]}[LANGUAGE_NONE][0]['value']] = $k;
    }
    foreach ($arr_rows as $row) {
        $str = trim($row);
        if ($str) {
            if (in_array($str, $arr_old_source)) {
                unset($terms[$ids[$str]]);
            }
            else {
                $cols = preg_split('/¤/', $str);
                if (array_key_exists($cols[0] , $id_source)) {
                    $term = $terms[$id_source[$cols[0]]];
                    unset($terms[$term->tid]);
                }
                else {
                    $term = new stdClass();
                }
                $term->field_source_data['und'][0]['value'] = $str;
                $term->vid = $vid;
                foreach($mapping as $k => $v){
                    if($v != 'name'){
                        $term->{$v}[LANGUAGE_NONE][0]['value'] = $cols[$k];
                    }
                    else {
                        $term->name = $cols[$k];
                    }
                }
                taxonomy_term_save($term);
            }
        }
    }
    foreach ($terms as $k => $v) {
        taxonomy_term_delete($k);
    }
}
function batch_kb_taxonomy_finished($success, $results, $operations){
  if ($success) {
    $message = t('All your request processed');
    drupal_set_message($message);
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
}