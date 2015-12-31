<?php

function import_bien_pdf_for_particular_programme ($programme_id = '') {
  if ($programme_id == '') {
    return;
  }
  kb_import_bien_pdf_loging('Start import bien PDF for programme ' . $programme_id);
  $uri = 'public://kbmedia/doc/' . $programme_id;
  $prepare_file = file_prepare_directory($uri, FILE_CREATE_DIRECTORY);
  drupal_chmod($uri);
  if ($prepare_file) {
    drupal_chmod($uri);
    kb_import_bien_pdf_loging('Start get file via FTP');
    $getting_file_status = import_bien_pdf_for_particular_programme_get_and_store_file($programme_id);
    if ($getting_file_status) {
      kb_import_bien_pdf_loging('Finish get file via FTP');
      kb_import_bien_pdf_loging('Start import bien PDF');
      import_bien_pdf_for_particular_programme_import($programme_id);
    }
    else {
      kb_import_bien_pdf_loging('Get file via FTP error');
    }
  }
}

function import_bien_pdf_for_particular_programme_get_and_store_file ($programme_id) {
  if ($programme_id == '') {
    return '';
  }
  module_load_include('inc', 'kb_import', 'kb_import.GettingFiles');
  $getting_file_status = TRUE;
  $config = array(
    'server' => variable_get('kb_ftp_server', ''),
    'username' => variable_get('kb_ftp_username', ''),
    'port' => variable_get('kb_ftp_port', ''),
    'directory' => '/doc/' . $programme_id,
    'password' => variable_get('kb_ftp_password', ''),
    'local_directory' => 'kbmedia/doc/' . $programme_id,
  );
  if ($config['server'] == '' || $config['username'] == '' || $config['port'] == '' ||  $config['password'] == '' ) {
    kb_import_bien_pdf_loging('Form config: Server\'s information is not configured.');
    return;
  }
  $connect = kb_import_ftp_connection_for_importing_bien_pdf($config);

  if ($connect) {
    //Get list file from sever's directory
    $files = kb_import_ftp_file_list($connect, $config['directory']);
    if ($files === FALSE) {
      $getting_file_status = FALSE;
      @ftp_close($connect);
      kb_import_bien_pdf_loging('Unabled to list remote directory: ' . $config['directory']);
    }
    elseif (empty ($files)) {
      $getting_file_status = FALSE;
      kb_import_bien_pdf_loging('Directory empty: ' . $config['directory']);
    }
    else {
      foreach ($files as $file) {
        if (strpos($file, '.pdf') == FALSE) {
          continue;
        }
        $temp_filename = kb_import_ftp_download($connect, $file, $config['directory'] );
        if ($temp_filename) {
          $uri = 'public://' . $config['local_directory'] . '/';
          $prepare_file = file_prepare_directory($uri, FILE_CREATE_DIRECTORY);
          if($prepare_file){
            drupal_realpath($uri . $file);
            $data = file_get_contents($temp_filename);
            drupal_chmod($uri);
            file_save_data($data, $uri . $file, FILE_EXISTS_REPLACE);
            file_unmanaged_delete($temp_filename);
          }
        }
      }
    }
    @ftp_close($connect);
  }
  else {
    $getting_file_status = FALSE;
  }
  return $getting_file_status;
}

function import_bien_pdf_for_particular_programme_import($programme_id = '') {
  try {
    batch_set(import_bien_pdf_particular_programme_batch_operation($programme_id));
    batch_process();
  }
  catch (Exception $e) {
    kb_import_bien_pdf_loging('Failed to import bien PDF');
    kb_import_bien_pdf_loging('Error: ' . $e->getMessage());
    drupal_set_message('Error: ' . $e->getMessage());
  }
}

function import_bien_pdf_particular_programme_batch_operation ($programme_id = '') {
  if ($programme_id == '') {
    return ;
  }
  $operations = array();
  $path = drupal_realpath('public://kbmedia/doc/' . $programme_id);
  if (is_dir($path)) {
    if ($handle = opendir($path)) {
      $files = glob($path . "/*.pdf");
      foreach($files as $file) {
        $file_name = substr($file, strrpos($file, '/') + 1);
        $file_name_arr = explode('_', $file_name);
        $idbien_extension = explode('.', $file_name_arr[count($file_name_arr) - 1]);
        $id_bien = $idbien_extension[0];
        $nid_bien = get_bien_by_id($programme_id . '-%-' . $id_bien);
        if ($nid_bien) {
          $operations[] = array('import_bien_pdf_particular_programme_batch_operation_process', array(array('programme_id' => $programme_id, 'file' => $file, 'bien_id' => $nid_bien)));
        }
      }
      closedir($handle);
    }
  }
  $batch = array(
    'title' => t('Import bien pdf for particular programme'),
    'operations' => $operations,
    'finished' => 'import_bien_pdf_for_particular_programme_batch_finished',
    'file' => drupal_get_path('module', 'kb_import') . '/import_bien_pdf_for_particular_programme.inc'
  );
  return $batch;
}

function import_bien_pdf_particular_programme_batch_operation_process($data, &$context) {
  $context['results']['processed'][] = t('Bien of programme @programme is updating', array('@programme' => $data['programme_id']));
  $context['results']['programme_id'] = $data['programme_id'];
  $context['message'] = t('Updated the bien has bien ID @bien_id', array('@bien_id' => $data['bien_id']));
  save_bien_pdf_file($data['bien_id'], $data['file']);
}

function import_bien_pdf_for_particular_programme_batch_finished ($success, $results, $operations) {
  kb_import_bien_pdf_loging('Processed ' . count($results['processed']) . ' node bien');
  $uri = 'public://kbmedia/doc/' . $results['programme_id'];
  $prepare_file = file_prepare_directory($uri);
  if ($prepare_file) {
    $path = drupal_realpath($uri);
    if (file_exists($path)) {
      foreach (glob($path . "/*.*") as $filename) {
        if (is_file($filename)) {
          unlink($filename);
        }
      }
      kb_import_bien_pdf_loging('Deleted PDF files');
    }
  }
  if ($success) {
    kb_import_bien_pdf_loging('Import bien PDF success');
    drupal_set_message(t('@count Node Bien processed.', array('@count' => count($results['processed']))));
  } else {
    $error_operation = reset($operations);
    kb_import_bien_pdf_loging('Import bien PDF error: ' . $error_operation[0]);
    drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array('@operation' => $error_operation[0], '@args' => print_r($error_operation[0], TRUE))));
  }
}

function get_bien_by_id($id_bien) {
  $db_query = db_select('field_data_field_id_bien', 'idb');
  $db_query->fields('idb', array('entity_id'));
  $db_query->condition('idb.entity_type', 'node');
  $db_query->condition('idb.bundle', 'bien');
  $db_or = db_or();
  $db_or->condition('idb.field_id_bien_value', $id_bien, 'LIKE');
  $db_or->condition('idb.field_id_bien_value', "\r\n" . $id_bien, 'LIKE');
  $db_query->condition($db_or);
  $bien = $db_query->distinct()->execute()->fetchField();
  return $bien;
}

function kb_import_ftp_connection_for_importing_bien_pdf($config) {
  $connect = FALSE;
  try {
    $server_name = trim($config['server']);
    $user_name = trim($config['username']);
    $ftp_password = $config['password'];
    $connect = kb_import_ftp_connect($server_name, $user_name, $ftp_password, $config['port']);
    if (!$connect) {
      kb_import_bien_pdf_loging('Failed to connect to ftp server: ' . $server_name);
    }
    else {
      if (!kb_import_ftp_chdir($connect, $config['directory'])) {
        @ftp_close($connect);
        kb_import_bien_pdf_loging('Failed to change FTP directory');
      }
    }
  }
  catch (Exception $e) {
    drupal_set_message('Error: ' . $e->getMessage());
  }

  return $connect;
}