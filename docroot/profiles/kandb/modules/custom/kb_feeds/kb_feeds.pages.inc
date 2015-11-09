<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function feeds_errorlog_form($form, &$form_state, $vars) {
  //$type = arg(3);
  $path = 'private://feeds/log';
  $allFiles = scandir($path);
  $allFiles = array_diff($allFiles, array('.', '..'));


  if ($allFiles) {
    $fileInfoes = array();
    foreach ($allFiles as $file_name) {
      if (strpos($file_name, substr($vars, 1)) != FALSE) {
        $fileInfoes[] = array(
          'id' => $file_name,
          'importer' => str_replace("_", " ", $vars),
          'file_name' => $file_name,
          'operations' => l(t('delete'), 'feeds-errorlog/delete/' . $file_name, array('query' => drupal_get_destination())) . "&nbsp;&nbsp;&nbsp;&nbsp;" . l(t('download'), 'feeds-errorlog/download/' . $file_name, array('query' => drupal_get_destination())),
        );
      }
    }
  }

  $header = array(
    'importer' => t('Importer'),
    'file_name' => t('File name'),
    'operations' => t('Operations'),
  );
  $options = array();
  foreach ($fileInfoes as $fileInfo) {
    $options[$fileInfo['id']] = array(
      'importer' => $fileInfo['importer'],
      'file_name' => $fileInfo['file_name'],
      'operations' => $fileInfo['operations'],
    );
  }

  $form['errorlogs'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No feeds errorlog found'),
  );

  $form['submit']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#attributes' => array('onclick' => 'if(!confirm("Are you sure you want to delete this logs?")){return false;}')
  );

  return $form;
}

function feeds_errorlog_form_validate($form, &$form_state) {
  $error_logs = $form_state['values']['errorlogs'];

  $status = FALSE;
  foreach ($error_logs as $log) {
    if ($log) {
      $status = TRUE;
      break;
    }
  }

  if($status == FALSE) {
    drupal_set_message(t('Please select at least one item.'), 'error');
  }
}

function feeds_errorlog_form_submit(&$form, &$form_state) {
  if ($form_state['values']['delete'] == $form_state['clicked_button']['#value']) {
    foreach ($form_state['values']['errorlogs'] as $name) {
      if($name) {
        delete_feeds_errorlog($name);
      }
    }
  }
}
