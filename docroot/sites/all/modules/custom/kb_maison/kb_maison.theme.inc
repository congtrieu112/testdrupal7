<?php
/**
 * @file
 * kb_maison.theme.inc
 */

/**
 * Theme Lot full page.
 */
function theme_kb_maison_full($variables) {
  $output = '';
  $kb_maison = $variables['kb_maison'];

  $output .= '<div class="name">' . $kb_maison->name .  '</div>';
  $output .= '<div class="desc">' . $kb_maison->desc_1 .  '</div>';
  $output .= '<div class="desc">' . $kb_maison->desc_2 .  '</div>';
  $output .= '<div class="desc">' . $kb_maison->desc_3 .  '</div>';
  $output .= '<div class="desc">' . $kb_maison->desc_4 .  '</div>';

  if (user_access('administer maison entities') && isset($kb_maison->idkp)) {
    $edit_link = '<ul class="tabs primary"><li>';
    $edit_link .= l(t('Edit'), 'admin/content/maison/manage/' . $kb_maison->idkp, array('attributes' => array('class' => 'admin-edit-link')));
    $edit_link .= '</li></ul>';
    $output .= $edit_link;
  }

  $output .= '</div>';

  return $output;
}
