<?php

/**
 * @file
 * Implements Backo-end functions related K&B B2B.
 */

/**
 * List All sub-menu of the B2B content settings.
 */
function kandb_b2b_setttings_page_content() {
  $parent = menu_link_get_preferred(current_path());
  $parameters = array(
    'active_trail' => array($parent['plid']),
    'only_active_trail' => FALSE,
    'min_depth' => $parent['depth'] + 1,
    'max_depth' => $parent['depth'] + 1,
    'conditions' => array('plid' => $parent['mlid']),
  );

  $children = menu_build_tree($parent['menu_name'], $parameters);
  foreach ($children as &$data) {
    if ($data['link']['link_path'] != 'admin/content/ketb/list')
      $data['link']['hidden'] = FALSE;
  }
  $menu_render = menu_tree_output($children);

  return '<div class="content-sub-menu content-padder">' . drupal_render($menu_render) . '</div>';
}

/**
 * B2B Homepage settings form.
 */
function kandb_b2b_homepage_settings($form, $form_state) {
  $form = array();

  $form['kandb_b2b_homepage_background_image'] = array(
    '#type' => 'managed_file',
    '#title' => t('Background image'),
    '#upload_location' => 'public://files',
    '#default_value' => variable_get('kandb_b2b_homepage_background_image', ''),
  );

  $form['kandb_b2b_homepage_program'] = array(
    '#type' => 'textfield',
    '#title' => t('Programme'),
    '#autocomplete_path' => 'admin/content/kandb-b2b/homepage-programme/autocomplete',
    '#default_value' => variable_get('kandb_b2b_homepage_program', ''),
  );

  $form['#submit'][] = 'kandb_b2b_homepage_background_image_submit';
  return system_settings_form($form);
}

/*
 * Additional submit handler for making the file permanent.
 */

function kandb_b2b_homepage_background_image_submit($form, &$form_state) {
  if ($form['kandb_b2b_homepage_background_image']['#file']) {
    $form['kandb_b2b_homepage_background_image']['#file']->status = FILE_STATUS_PERMANENT;
    file_save($form['kandb_b2b_homepage_background_image']['#file']);
  }
}

/**
 * Ajax callback for select a program to show in B2B homepage.
 */
function _kandb_b2b_homepage_programme_autocomplete($string) {
  $matches = array();

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'programme')
    ->propertyCondition('title', '%' . $string . '%', 'like')
    ->propertyCondition('status', NODE_PUBLISHED);
  $result = $query->execute();

  if (isset($result['node'])) {
    $nodes = entity_load('node', array_keys($result['node']));
  }

  if ($nodes) {
    foreach ($nodes as $item) {
      $matches['[' . $item->nid . ']' . $item->title] = $item->title;
    }
  }

  drupal_json_output($matches);
}
