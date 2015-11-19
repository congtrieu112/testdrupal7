<?php

function migration_errorlog_form($form, &$form_state) {
  //$type = arg(3);
  $path = 'private://migration';
  $allFiles = scandir($path);
  $allFiles = array_diff($allFiles, array('.', '..'));

  $fileInfoes = array();
  if ($allFiles) {
    foreach ($allFiles as $file_name) {
      if (strpos($file_name, 'migration_log', 1) == 0) {
        $fileInfoes[] = array(
          'id' => $file_name,
          'importer' => str_replace("_", " ", 'migration_import'),
          'file_name' => $file_name,
          'operations' => l(t('delete'), 'migration-errorlog/delete/' . $file_name, array('query' => drupal_get_destination())) . "&nbsp;&nbsp;&nbsp;&nbsp;" . l(t('download'), 'migration-errorlog/download/' . $file_name, array('query' => drupal_get_destination())),
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
  if ($fileInfoes) {
    foreach ($fileInfoes as $fileInfo) {
      $options[$fileInfo['id']] = array(
        'importer' => $fileInfo['importer'],
        'file_name' => $fileInfo['file_name'],
        'operations' => $fileInfo['operations'],
      );
    }
  }

  $form['errorlogs'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No migration errorlog found'),
  );

  $form['submit']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#attributes' => array('onclick' => 'if(!confirm("Are you sure you want to delete this logs?")){return false;}')
  );

  return $form;
}

function migration_errorlog_form_validate($form, &$form_state) {
  $error_logs = $form_state['values']['errorlogs'];

  $status = FALSE;
  foreach ($error_logs as $log) {
    if ($log) {
      $status = TRUE;
      break;
    }
  }

  if ($status == FALSE) {
    drupal_set_message(t('Please select at least one item.'), 'error');
  }
}

function migration_errorlog_form_submit(&$form, &$form_state) {
  if ($form_state['values']['delete'] == $form_state['clicked_button']['#value']) {
    foreach ($form_state['values']['errorlogs'] as $name) {
      if ($name) {
        delete_feeds_errorlog($name);
      }
    }
  }
}
