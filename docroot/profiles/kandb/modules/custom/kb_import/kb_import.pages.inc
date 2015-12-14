<?php

function migration_errorlog_form($form, &$form_state,  $is_daily_import = FALSE) {
  $path = $is_daily_import ? 'private://daily-import-log' : 'private://migration';
  $allFiles = scandir($path);
  $allFiles = array_diff($allFiles, array('.', '..'));
  $file_prefix = $is_daily_import ? 'daily_import_log' : 'migration_import';
  $prefix_path_action = $is_daily_import ? 'daily-import-errorlog' : 'migration-errorlog';
  $empty_message = $is_daily_import ?  t('No daily import errorlog found') : t('No migration errorlog found');
  $fileInfoes = array();
  if ($allFiles) {
    foreach ($allFiles as $file_name) {
      if (strpos($file_name, 'migration_log', 1) == 0) {
        $fileInfoes[] = array(
          'id' => $file_name,
          'importer' => str_replace("_", " ", $file_prefix),
          'file_name' => $file_name,
          'operations' => l(t('delete'), $prefix_path_action . '/delete/' . $file_name, array('query' => drupal_get_destination())) . "&nbsp;&nbsp;&nbsp;&nbsp;" . l(t('download'), $prefix_path_action . '/download/' . $file_name, array('query' => drupal_get_destination())),
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
    '#empty' => $empty_message,
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
