<?php
/**
 * @file
 * kb_program.theme.inc
 */

/**
 * Theme Lot full page.
 */
function theme_kb_program_full($variables) {
  $output = '';
  $kb_program = $variables['kb_program'];

  $output .= '<div class="name">' . $kb_program->name .  '</div>';
  $output .= '<div class="desc">' . $kb_program->desc_1 .  '</div>';
  $output .= '<div class="desc">' . $kb_program->desc_2 .  '</div>';
  $output .= '<div class="desc">' . $kb_program->desc_3 .  '</div>';
  $output .= '<div class="desc">' . $kb_program->desc_4 .  '</div>';

  if (user_access('administer program entities') && isset($kb_program->idkp)) {
    $edit_link = '<ul class="tabs primary"><li>';
    $edit_link .= l(t('Edit'), 'admin/content/program/manage/' . $kb_program->idkp, array('attributes' => array('class' => 'admin-edit-link')));
    $edit_link .= '</li></ul>';
    $output .= $edit_link;
  }

  $output .= '</div>';

  return $output;
}
