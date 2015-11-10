<?php

function kb_import_ftp_get_files () {
  
  $file_name = variable_get('kb_ftp_filename', "ARRONDISSEMENT.TXT\nVILLE.TXT\nMAISON.TXT\nPROGRAMME.TXT\nLOT.TXT");
  $file_name_arr = array_map('trim', explode("\n", $file_name));
  $getting_file_status = TRUE;
  $config = array(
    'server' => variable_get('kb_ftp_server', '194.150.11.65'),
    'username' => variable_get('kb_ftp_username', 'KETB_DIGITAS'),
    'port' => variable_get('kb_ftp_port', 21),
    'directory' => variable_get('kb_ftp_directory', '/import'),
    'password' => variable_get('kb_ftp_password', 'Su9jW6b6'),
    'local_directory' => variable_get('kb_ftp_local_directory', 'import'),
  );
  //Connect to server
  $connect = kb_import_ftp_connection($config);
  if ($connect) {
    //Get list file from sever's directory
    $files = kb_import_ftp_file_list($connect, variable_get('kb_ftp_directory'));
    if ($files === FALSE) {
      $getting_file_status = FALSE;
      @ftp_close($connect);
      kb_daily_import_logging('Unabled to list remote directory: ' . $config['directory']);
    }
    elseif (empty ($files)) {
      kb_daily_import_logging('Directory empty: ' . $config['directory']);
    }
    else {
      $existing_files = array_intersect($file_name_arr, $files);
      //Download to store files
      foreach ($existing_files as $file) {
        $temp_filename = kb_import_ftp_download($connect, $file, $config['directory'] );
        if (!$temp_filename) {
          kb_daily_import_logging('Failed to retrieve ' . $file . ' from remote directory ' . $config['directory']);
          if ($file == 'PROGRAMME.TXT' || $file == 'LOT.TXT') {
            $getting_file_status = FALSE;
          }
        }
        else {
          $uri = 'public://' . $config['local_directory'] . '/';
          $prepare_file = file_prepare_directory($uri, FILE_CREATE_DIRECTORY);
          if($prepare_file){
            $path = drupal_realpath($uri . $file);
            $data = file_get_contents($temp_filename);
            drupal_chmod($uri);
            file_save_data($data, $uri . $file, FILE_EXISTS_REPLACE);
            //Delete temporary file
            file_unmanaged_delete($temp_filename);
          }
        }
      }
      $files_not_found = array_diff($file_name_arr, $files);
      foreach ($files_not_found as $file_not_found) {
        //Logging file not found
        kb_daily_import_logging('File not found: ' . $file_not_found);
        if (($file_not_found == 'PROGRAMME.TXT' || $file_not_found == 'LOT.TXT') && in_array($file_not_found, $file_name_arr)) {
          $getting_file_status = FALSE;
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

function kb_import_ftp_connection($config) {
  $connect = FALSE;
  try {
    // trim server name and user name to remove any trailing spaces
    $server_name = trim($config['server']);
    $user_name = trim($config['username']);
    $ftp_password = $config['password'];
    // Connect to FTP server.
    $connect = kb_import_ftp_connect($server_name, $user_name, $ftp_password, $config['port']);
    if (!$connect) {
      kb_daily_import_logging('Failed to connect to ftp server: ' . $server_name);
    }
    else {
    //Change directory on FTP server.
      if (!kb_import_ftp_chdir($connect, $config['directory'])) {
        @ftp_close($connect);
        kb_daily_import_logging('Failed to change FTP directory');
      }
    }
  }
  catch (Exception $e) {
    drupal_set_message('Error: ' . $e->getMessage());
  }

  return $connect;
}

function kb_import_ftp_file_list($connect, $directory) {
  $files = array();

  if ($connect) {
    $files = @ftp_nlist($connect, $directory);
    if (count($files) > 0) {
      foreach ($files as $idx => &$filename) {
        // Strip out any file names beginning with a period.
        if (substr($filename, 0, 1) == '.') {
          unset($files[$idx]);
        }
        // Remove 0 byte files and subfolders which has file size = -1.
        if (@ftp_size($connect, $filename) < 1) {
          unset($files[$idx]);
        }
        else {
          $filename = str_replace($directory . '/', '', $filename);
        }
      }
    }
  }

  // Re-index the list of file names before returning it.
  return array_values($files);
}
function kb_import_ftp_download($connect, $file, $directory) {
  $result = FALSE;
  if ($connect) {
    $temp_file = file_create_filename($file, file_directory_temp());
    $fp = @fopen($temp_file, 'w');
    if (@ftp_fget($connect, $fp, $directory . '/' . $file, FTP_BINARY)) {
      $result = $temp_file; 
    }
    @fclose($fp);
  }
  return $result;
}
function kb_import_ftp_connect($server, $username, $password, $port) {
  if ($connect = ftp_connect($server, $port)) {
    ftp_login($connect, $username, $password);
    ftp_pasv($connect, TRUE);
    return $connect;
  }
  return FALSE;
}

function kb_import_ftp_chdir($connect, $directory) {
  if ($connect) {
    return @ftp_chdir($connect, $directory);
  }
  return FALSE;
}