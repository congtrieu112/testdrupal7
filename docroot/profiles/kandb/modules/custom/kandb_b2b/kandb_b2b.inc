<?php
/**
 * @file
 * Implements business functions related K&B B2B.
 */

function render_b2b_homepage() {
  $login_form = drupal_get_form("user_login");
//  kpr($login_form);die;
  return theme('b2b_homepage', array('login_form' => $login_form));
}