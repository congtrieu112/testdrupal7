<?php

/**
 * @file
 * Implements business functions related K&B B2B.
 */

/**
 * Render B2B homepage.
 */
function render_b2b_homepage() {
  // Login block form.
  $login_form = drupal_get_form("user_login");

  // Selected program.
  $program_var = variable_get('kandb_b2b_homepage_program');
  preg_match_all('/\[([0-9]+?)\]/', $program_var, $matches);
  if (isset($matches[1][0]) AND is_numeric($matches[1][0])) {
    $program = node_load($matches[1][0]);
    if ($program) {
      $program_title = isset($program->title) ? $program->title : '';

      $program_bg = field_get_items('node', $program, 'field_image_principale');
      $program_bg = isset($program_bg[0]['uri']) ? $program_bg[0]['uri'] : '';
      if ($program_bg) {
        $bg_image_small = image_style_url('homepageb2b_backgound_small', $program_bg);
        $bg_image_large = image_style_url('homepageb2b_backgound_large', $program_bg);
      }

      $program_ville = field_get_items('node', $program, 'field_programme_loc_ville');
      $program_ville = isset($program_ville[0]['tid']) ? taxonomy_term_load($program_ville[0]['tid']) : '';
      $program_ville = $program_ville ? $program_ville->name : '';

      $program_department = field_get_items('node', $program, 'field_programme_loc_department');
      $program_department = isset($program_department[0]['tid']) ? taxonomy_term_load($program_department[0]['tid']) : '';
      $program_department = $program_department ? $program_department->name : '';
      
      $program_loc_num = field_get_items('node', $program, 'field_programme_loc_num');
      $program_loc_num = isset($program_loc_num[0]['value']) ? $program_loc_num[0]['value'] : '';
      $program_loc_rue = field_get_items('node', $program, 'field_programme_loc_rue');
      $program_loc_rue = isset($program_loc_rue[0]['value']) ? $program_loc_rue[0]['value'] : '';
      $program_address = trim($program_loc_num . ' ' . $program_loc_rue);

      $promotions = get_nids_promotions_by_programme($program->nid);
      $program_promotions = array();
      if ($promotions) {
        foreach ($promotions as $item) {
          $promotion_mention_legale = field_get_items('node', $item, 'field_promotion_mention_legale');
          $promotion_mention_legale = isset($promotion_mention_legale[0]['value']) ? $promotion_mention_legale[0]['value'] : '';
          $program_promotions[] = array(
            'nid' => $item->nid,
            'title' => $item->title,
            'mention_legale' => $promotion_mention_legale,
          );
        }
      }
    }
  }

  // Default Home page background image.
  $bg_image_fid = variable_get('kandb_b2b_homepage_background_image');
  $bg_image = is_numeric($bg_image_fid) ? file_load($bg_image_fid) : '';
  if (!isset($bg_image_small) AND ! isset($bg_image_large)) {
    if (isset($bg_image->uri) AND $bg_image_uri = $bg_image->uri) {
      $bg_image_small = image_style_url('homepageb2b_backgound_small', $bg_image_uri);
      $bg_image_large = image_style_url('homepageb2b_backgound_large', $bg_image_uri);
    }
  }
  
  // Links to access legal information.
  $legal_page_url = url('content/mentions-légales');

  return theme('b2b_homepage', array(
    'login_form' => $login_form,
    'bg_image_small' => $bg_image_small,
    'bg_image_large' => $bg_image_large,
    'program_title' => $program_title,
    'program_ville' => $program_ville,
    'program_department' => $program_department,
    'program_address' => $program_address,
    'program_promotions' => $program_promotions,
    'legal_page_url' => $legal_page_url,
  ));
}
