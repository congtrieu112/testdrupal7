<?php
function kandb_theme_form_system_theme_settings_alter(&$form, $form_state) {
    global $base_url;
    $home = $base_url;
    if(theme_get_setting('footer_link_custom')){
        $home = theme_get_setting('footer_link_custom');
    }
  $form['social'] = array(
    '#type' => 'fieldset',
    '#title' => t('Social Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
 
  // display socail
  $form['social']['social_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display social icon'),
    '#description' => t('Show / hidden social icon'),
    '#default_value' => theme_get_setting('social_display'),
  );
  $form['social']['facebook_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook'),
    '#description' => t('Link facebook '),
    '#default_value' => theme_get_setting('footer_link_face'),
  );
  $form['social']['youtube_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Youtube'),
    '#description' => t('Link youtube'),
    '#default_value' => theme_get_setting('footer_link_youtube'),
  );
  $form['social']['twiiter_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Twiiter'),
    '#description' => t('Link twiiter'),
    '#default_value' => theme_get_setting('footer_link_twiiter'),
  );
  $form['link_custom'] = array(
    '#type' => 'textfield',
    '#title' => t('Link footer'),
    '#description' => t('URl footer'),
    '#default_value' => $home,
  );
  
  
  
  
}
