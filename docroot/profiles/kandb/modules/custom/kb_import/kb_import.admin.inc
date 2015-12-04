<?php

function config_ftp_page() {
  $form = array();

  $form['kb_ftp_server'] = array(
    '#type' => 'textfield',
    '#title' => t('Server'),
    '#description' => t("Enter a server hostname or IP adress. Do not include 'ftp://' prefix."),
    '#default_value' => variable_get('kb_ftp_server', ''),
    '#required' => TRUE,
  );

  $form['kb_ftp_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Port'),
    '#description' => t('Enter a port to connect on.'),
    '#default_value' => variable_get('kb_ftp_port', ''),
    '#required' => TRUE,
  );

  $form['kb_ftp_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#description' => t('The username used to connect to the FTP server.'),
    '#default_value' => variable_get('kb_ftp_username', ''),
    '#required' => TRUE,
  );

  $form['kb_ftp_password'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#description' => t('The password used to connect to the FTP server.'),
    '#required' => FALSE,
    '#attributes' => array('value' => variable_get('kb_ftp_password', '')),
  );

  $form['kb_ftp_directory'] = array(
    '#type' => 'textfield',
    '#title' => t('Directory'),
    '#description' => t("The directory on the FTP server. E.g., '/import'"),
    '#default_value' => variable_get('kb_ftp_directory', ''),
    '#required' => TRUE,
  );

  $form['kb_ftp_filename'] = array(
    '#type' => 'textarea',
    '#title' => t('Filename'),
    '#description' => t('The list filename in the directory on the FTP server. Enter one file per line.'),
    '#default_value' => variable_get('kb_ftp_filename', ""),
  );
  
  $form['kb_ftp_local_directory'] = array(
    '#type' => 'textfield',
    '#title' => t('Local directory'),
    '#description' => t('The directory under public:// on local to store files. Do not include "public://" prefix.'),
    '#default_value' => variable_get('kb_ftp_local_directory', ''),
    '#required' => TRUE,
  );
  
  $form['#submit'][] = 'config_ftp_page_submit';
  
  return system_settings_form($form);
}

/**
 * Submit handler for the custom form.
 */
function config_ftp_page_submit($form, &$form_state) {

  $config = array(
    'server' => $form['kb_ftp_server']['#value'],
    'username' => $form['kb_ftp_username']['#value'],
    'port' => $form['kb_ftp_port']['#value'],
    'directory' => $form['kb_ftp_directory']['#value'],
    'password' => $form['kb_ftp_password']['#value'],
    'local_directory' => $form['kb_ftp_local_directory']['#value'],
  );
    
  try {
    // Connect to FTP server.
    if ($connect = ftp_connect($config['server'], $config['port'])) {
      ftp_login($connect, $config['username'], $config['password']);
      ftp_pasv($connect, TRUE);
      ftp_chdir($connect, $config['directory']);
      ftp_close($connect);
      
      drupal_set_message('Connect to ftp server: ' . $config['server']);
    } else {
      drupal_set_message('Failed to connect to ftp server: ' . $config['server'], 'error');
    }
  }
  catch (Exception $e) {
    drupal_set_message('Error: ' . $e->getMessage(), 'error');
  }
  
  
}

function migration_impor_admin_form() {
  $form = array();
  $form['getting_file'] = array(
    '#type' => 'checkbox',
    '#title' => t('Get file import via FTP'),
  );
  $form['actions'] = array(
    '#type' => 'actions',
    );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Migration'),
  );
  return $form;
}

function migration_impor_admin_form_submit($form, &$form_state) {
  kb_start_migration_import($form['getting_file']['#value']);
}

function reset_status_page () {
  $form = array();
  $form['reset_migration'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reset migration status'),
  );
  $form['reset_daily_import'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reset daily import status'),
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Reset'),
  );
  return $form;
}

function reset_status_page_submit ($form, &$form_state) {
  if (isset($values['reset_migration']) && $values['reset_migration'] == 1) {
    set_migration_status(migration_status_default());
  }
  if (isset($values['reset_daily_import']) && $values['reset_daily_import'] == 1) {
    set_daily_import_status(daily_import_status_default());
  }
}