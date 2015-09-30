<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Implements hook_form().
 */
function kb_program_form($form, &$form_state, $kb_program = NULL) {
  $form = array();
  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#default_value' => isset($kb_program->name) ? $kb_program->name : '',
    '#description' => t('Program name.'),
    '#required' => TRUE,
    '#maxlength' => 255,
  );

  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textarea',
    '#default_value' => isset($kb_program->name) ? $kb_program->name : '',
    '#required' => TRUE,
  );

  $form['desc_2'] = array(
    '#title' => t('Description 2'),
    '#type' => 'textarea',
    '#default_value' => isset($kb_program->desc_2) ? $kb_program->desc_2 : '',
    '#required' => TRUE,
    '#maxlength' => 255,
  );

  $form['desc_3'] = array(
    '#title' => t('Description 3'),
    '#type' => 'textarea',
    '#default_value' => isset($kb_program->desc_3) ? $kb_program->desc_3 : '',
    '#required' => TRUE,
  );

  $form['desc_4'] = array(
    '#title' => t('Description 4'),
    '#type' => 'textarea',
    '#default_value' => isset($kb_program->desc_4) ? $kb_program->desc_4 : '',
    '#required' => TRUE,
  );

  field_attach_form('kb_program', $kb_program, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($kb_program->kb_program_id) ? t('Update Program') : t('Save Program'),
    ),
    'delete_link' => array(
      '#markup' => isset($kb_program->kb_program_id) ? l(t('Delete'), 'admin/content/program/manage/' . $kb_program->kb_program_id . '/delete', array('attributes' => array('id' => array('program-delete-' . $kb_program->kb_program_id), 'class' => array('button remove')), 'query' => array('destination' => 'admin/content/program'))) : ''));

  return $form;
}

/**
 * Implements hook_form_validate().
 */
function kb_program_form_validate($form, &$form_state) {
}

/**
 * Implements hook_form_submit().
 */
function kb_program_form_submit($form, &$form_state) {
  $kb_program = entity_ui_form_submit_build_entity($form, $form_state);
  $kb_program->save();
  drupal_set_message(t('@name program has been saved.', array('@name' => $kb_program->name)));
  // $form_state['redirect'] = 'admin/content/program';
  $form_state['redirect'] = 'program/' . $kb_program->kb_program_id;
}

/**
 * Confirmation before bulk deleting program.
 */
function kb_program_bulk_delete($form, &$form_state, $kb_program_ids) {
  $kb_program_ids = explode('|', $kb_program_ids);
  $kb_program = kb_program_load_multiple($kb_program_ids);

  $form = array();
  $form_state['kb_program_ids'] = $kb_program_ids;

  $variables = array(
    'type' => 'ul',
    'items' => array(),
    'title' => '',
    'attributes' => array(),
  );

  foreach ($kb_program as $pro) {
    $variables['items'][] = $pro->name;
  }

  $form['summary'] = array(
    '#markup' => theme_item_list($variables),
  );

  return confirm_form($form, t('Delete all program?'), 'admin/content/program', t('Placeholder description'), t('Delete all'), t('Cancel'));
}

/**
 * Implements hook_submit().
 */
function kb_program_bulk_delete_submit($form, &$form_state) {
  $kb_program_ids = $form_state['kb_program_ids'];
  kb_program_delete_multiple($kb_program_ids);

  drupal_set_message(t('program deleted'));
  drupal_goto('admin/content/program');
}