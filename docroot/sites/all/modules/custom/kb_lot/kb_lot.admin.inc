<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Implements hook_form().
 */
function kb_lot_form($form, &$form_state, $kb_lot = NULL) {
  $form = array();
  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#default_value' => isset($kb_lot->name) ? $kb_lot->name : '',
    '#description' => t('Program name.'),
    '#required' => TRUE,
    '#maxlength' => 255,
  );

  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textarea',
    '#default_value' => isset($kb_lot->name) ? $kb_lot->name : '',
    '#required' => TRUE,
  );

  $form['desc_2'] = array(
    '#title' => t('Description 2'),
    '#type' => 'textarea',
    '#default_value' => isset($kb_lot->desc_2) ? $kb_lot->desc_2 : '',
    '#required' => TRUE,
    '#maxlength' => 255,
  );

  $form['desc_3'] = array(
    '#title' => t('Description 3'),
    '#type' => 'textarea',
    '#default_value' => isset($kb_lot->desc_3) ? $kb_lot->desc_3 : '',
    '#required' => TRUE,
  );

  $form['desc_4'] = array(
    '#title' => t('Description 4'),
    '#type' => 'textarea',
    '#default_value' => isset($kb_lot->desc_4) ? $kb_lot->desc_4 : '',
    '#required' => TRUE,
  );

  field_attach_form('kb_lot', $kb_lot, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($kb_lot->kb_lot_id) ? t('Update Program') : t('Save Program'),
    ),
    'delete_link' => array(
      '#markup' => isset($kb_lot->kb_lot_id) ? l(t('Delete'), 'admin/content/lot/manage/' . $kb_lot->kb_lot_id . '/delete', array('attributes' => array('id' => array('lot-delete-' . $kb_lot->kb_lot_id), 'class' => array('button remove')), 'query' => array('destination' => 'admin/content/lot'))) : ''));

  return $form;
}

/**
 * Implements hook_form_validate().
 */
function kb_lot_form_validate($form, &$form_state) {
}

/**
 * Implements hook_form_submit().
 */
function kb_lot_form_submit($form, &$form_state) {
  $kb_lot = entity_ui_form_submit_build_entity($form, $form_state);
  $kb_lot->save();
  drupal_set_message(t('@name lot has been saved.', array('@name' => $kb_lot->name)));
  // $form_state['redirect'] = 'admin/content/lot';
  $form_state['redirect'] = 'lot/' . $kb_lot->kb_lot_id;
}

/**
 * Confirmation before bulk deleting lot.
 */
function kb_lot_bulk_delete($form, &$form_state, $kb_lot_ids) {
  $kb_lot_ids = explode('|', $kb_lot_ids);
  $kb_lot = kb_lot_load_multiple($kb_lot_ids);

  $form = array();
  $form_state['kb_lot_ids'] = $kb_lot_ids;

  $variables = array(
    'type' => 'ul',
    'items' => array(),
    'title' => '',
    'attributes' => array(),
  );

  foreach ($kb_lot as $pro) {
    $variables['items'][] = $pro->name;
  }

  $form['summary'] = array(
    '#markup' => theme_item_list($variables),
  );

  return confirm_form($form, t('Delete all lot?'), 'admin/content/lot', t('Placeholder description'), t('Delete all'), t('Cancel'));
}

/**
 * Implements hook_submit().
 */
function kb_lot_bulk_delete_submit($form, &$form_state) {
  $kb_lot_ids = $form_state['kb_lot_ids'];
  kb_lot_delete_multiple($kb_lot_ids);

  drupal_set_message(t('lot deleted'));
  drupal_goto('admin/content/lot');
}