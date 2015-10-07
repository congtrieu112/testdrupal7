<?php
/**
 * Override or insert variables into the page template.
 */
function kandb_theme_process_page(&$variables) {
  $variables['hide_site_name']   = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($variables['hide_site_name']) {
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Kaufman & Broad'));
  }
  if ($variables['hide_site_slogan']) {
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  if (!empty($variables['title_suffix']['add_or_remove_shortcut']) && $variables['title']) {
    $variables['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $variables['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    $variables['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }
}