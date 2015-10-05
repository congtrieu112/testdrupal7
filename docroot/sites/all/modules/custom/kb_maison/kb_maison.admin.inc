<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Implements hook_form().
 */
function kb_maison_form($form, &$form_state, $kb_maison = NULL) {
  $form = array();
  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#default_value' => isset($kb_maison->name) ? $kb_maison->name : '',
    '#description' => t('Program name.'),
    '#required' => TRUE,
    '#maxlength' => 255,
  );

  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textarea',
    '#default_value' => isset($kb_maison->name) ? $kb_maison->name : '',
    '#required' => TRUE,
  );

  $form['desc_2'] = array(
    '#title' => t('Description 2'),
    '#type' => 'textarea',
    '#default_value' => isset($kb_maison->desc_2) ? $kb_maison->desc_2 : '',
    '#required' => TRUE,
    '#maxlength' => 255,
  );

  $form['desc_3'] = array(
    '#title' => t('Description 3'),
    '#type' => 'textarea',
    '#default_value' => isset($kb_maison->desc_3) ? $kb_maison->desc_3 : '',
    '#required' => TRUE,
  );

  $form['desc_4'] = array(
    '#title' => t('Description 4'),
    '#type' => 'textarea',
    '#default_value' => isset($kb_maison->desc_4) ? $kb_maison->desc_4 : '',
    '#required' => TRUE,
  );

  field_attach_form('kb_maison', $kb_maison, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($kb_maison->kb_maison_id) ? t('Update Program') : t('Save Program'),
    ),
    'delete_link' => array(
      '#markup' => isset($kb_maison->kb_maison_id) ? l(t('Delete'), 'admin/content/maison/manage/' . $kb_maison->kb_maison_id . '/delete', array('attributes' => array('id' => array('maison-delete-' . $kb_maison->kb_maison_id), 'class' => array('button remove')), 'query' => array('destination' => 'admin/content/maison'))) : ''));

  return $form;
}

/**
 * Implements hook_form_validate().
 */
function kb_maison_form_validate($form, &$form_state) {
}

/**
 * Implements hook_form_submit().
 */
function kb_maison_form_submit($form, &$form_state) {
  $kb_maison = entity_ui_form_submit_build_entity($form, $form_state);
  $kb_maison->save();
  drupal_set_message(t('@name maison has been saved.', array('@name' => $kb_maison->name)));
  // $form_state['redirect'] = 'admin/content/maison';
  $form_state['redirect'] = 'maison/' . $kb_maison->kb_maison_id;
}

/**
 * Confirmation before bulk deleting maison.
 */
function kb_maison_bulk_delete($form, &$form_state, $kb_maison_ids) {
  $kb_maison_ids = explode('|', $kb_maison_ids);
  $kb_maison = kb_maison_load_multiple($kb_maison_ids);

  $form = array();
  $form_state['kb_maison_ids'] = $kb_maison_ids;

  $variables = array(
    'type' => 'ul',
    'items' => array(),
    'title' => '',
    'attributes' => array(),
  );

  foreach ($kb_maison as $pro) {
    $variables['items'][] = $pro->name;
  }

  $form['summary'] = array(
    '#markup' => theme_item_list($variables),
  );

  return confirm_form($form, t('Delete all maison?'), 'admin/content/maison', t('Placeholder description'), t('Delete all'), t('Cancel'));
}

/**
 * Implements hook_submit().
 */
function kb_maison_bulk_delete_submit($form, &$form_state) {
  $kb_maison_ids = $form_state['kb_maison_ids'];
  kb_maison_delete_multiple($kb_maison_ids);

  drupal_set_message(t('maison deleted'));
  drupal_goto('admin/content/maison');
}