<?php

/**
 * @file
 * Implements Back-end functions of KB Group.
 */

/**
 * Group Home RH admin form.
 */
function kandb_group_active_habitat_form($form, $form_state) {
  global $language;


  $form['#submit'] = array(
    'kandb_group_active_habitat_cta_link'
  );

  return system_settings_form($form);
}

/*
 * Submit and save variable for CTA link.
 */

function kandb_group_active_habitat_cta_link(&$form, &$form_state) {
  $val = $form_state['values'];
  if (isset($val['links_fieldset']['cta'])) {
    foreach ($val['links_fieldset']['cta'] as $key => $item) {
      if (isset($item['url']) && isset($item['title'])) {
        variable_set($key, $item);
      }
    }
  }
}
