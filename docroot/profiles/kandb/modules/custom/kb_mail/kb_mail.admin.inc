<?php

function config_mailing_list() {
  $form = array();
  $form['kb_call_center_sender_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Sender name'),
    '#description' => t('The username of sender.'),
    '#default_value' => variable_get('kb_call_center_sender_name', ''),
    '#required' => TRUE,
  );
  $form['kb_call_center_sender_mail'] = array(
    '#type' => 'textfield',
    '#title' => t('Sender mail'),
    '#description' => t('The email of sender.'),
    '#default_value' => variable_get('kb_call_center_sender_mail', ''),
    '#required' => TRUE,
  );
  $form['kb_call_center_mailing_list'] = array(
    '#type' => 'textarea',
    '#title' => t('Mailing list'),
    '#description' => t('The list mail of call center to send. Enter account per line. For example: Name <email@email.com>'),
    '#default_value' => variable_get('kb_call_center_mailing_list', ""),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}