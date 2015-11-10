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
  return system_settings_form($form);
}