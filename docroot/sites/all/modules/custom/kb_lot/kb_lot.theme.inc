<?php
/**
 * @file
 * kb_lot.theme.inc
 */

/**
 * Theme Lot full page.
 */
function theme_kb_lot_full($variables) {
  $output = '';
  $kb_lot = $variables['kb_lot'];

  $output .= '<div class="name">' . $kb_lot->name .  '</div>';
  $output .= '<div class="desc">' . $kb_lot->desc_1 .  '</div>';
  $output .= '<div class="desc">' . $kb_lot->desc_2 .  '</div>';
  $output .= '<div class="desc">' . $kb_lot->desc_3 .  '</div>';
  $output .= '<div class="desc">' . $kb_lot->desc_4 .  '</div>';

  if (user_access('administer lot entities') && isset($kb_lot->idkp)) {
    $edit_link = '<ul class="tabs primary"><li>';
    $edit_link .= l(t('Edit'), 'admin/content/lot/manage/' . $kb_lot->idkp, array('attributes' => array('class' => 'admin-edit-link')));
    $edit_link .= '</li></ul>';
    $output .= $edit_link;
  }

  $output .= '</div>';

  return $output;
}
