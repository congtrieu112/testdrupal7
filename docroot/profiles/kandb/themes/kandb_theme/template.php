<?php

define('WATCHEEZY', 'http://api.watcheezy.com/deliver/watcheezy.js?key=efe59c556a4504811f4170e760bf17af&install=footer&lang=FR');
define('ARTICLE_LIMIT_CONTENT', 250);

if(!defined('TAXONOMY_STATUS_LOGEMENT_DISPONIBLE')){
  define('TAXONOMY_STATUS_LOGEMENT_DISPONIBLE', 'Disponible / Libre');  
}

// Constant to see if the page is loaded in AJAX
define('IS_AJAX', (!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') ? TRUE : FALSE);

/**
 * Override or insert variables into the html template.
 */
function kandb_theme_preprocess_html(&$variables) {
  // Change template on AJAX request
  if (!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {    
    $variables['theme_hook_suggestions'][] = 'html__ajax';
  }
}

/**
 * Override or insert variables into the block template.
 */
function kandb_theme_preprocess_block(&$variables) {
  // Change template on AJAX request
  if (!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {    
    $variables['theme_hook_suggestions'][] = 'block__ajax';
  }
}
/**
 * Override or insert variables into the page template.
 */
function kandb_theme_process_page(&$variables) {
  $variables['hide_site_name'] = theme_get_setting('toggle_name') ? FALSE : TRUE;
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

  $common_js = array(
    'bundle',
  );
  // Add custom script and keep them in footer scope.
  kandb_theme_include_common_js($common_js);

  // Add live chat script all page.
  drupal_add_js(WATCHEEZY, 'external');

  // Change template on AJAX request
  if (IS_AJAX) {
    $variables['theme_hook_suggestions'][] = 'page__ajax';
  }
}



/**
 * Returns HTML for primary and secondary local tasks.
 *
 * @ingroup themeable
 */
function kandb_theme_menu_local_tasks(&$variables) {
  $output = '';

  // Style the tabs
  // programCharacteristics__nav clearfix
  if($variables['primary']){

    if ($primary = menu_primary_local_tasks()) {
      $output .= '<ul class="programCharacteristics__nav" style="margin:5px 0px; text-align:left;position:relative;" >';
      foreach($primary as $tab){
        $tab['#link']['localized_options']['attributes']['class'][] = 'test';
        $tab['#link']['localized_options']['attributes']['style'][] = 'margin:0px;';
        $output .= render($tab);
      }
      $output .= '</ul>';
    }
    if ($secondary = menu_secondary_local_tasks()) {
      $output .= '<ul class="tabs secondary">';
      foreach($secondary as $tab) {
        $output .= render($tab);
      }
      $output .= "</ul>";
    }
  }
  return $output;
}

/**
 * Implementation theme_preprocess_form_element_label()
 */
function kandb_theme_preprocess_form_element_label(&$variables) {
  if ($variables['element']['#theme'] == 'checkbox') {
    $variables['element']['#attributes']['class'][] = 'label-checkbox';
  }
}

/**
 * Implement include css/js for each page.
 */
function kandb_theme_include_asset($variable, $type) {
  $path = drupal_get_path('theme', 'kandb_theme');
  if ($type == 'css') {
    foreach ($variable as $key => $item) {
      drupal_add_css($path . '/css/' . $item . '.css', array(
        'group' => CSS_THEME,
        'type' => 'file',
        'media' => 'screen',
        'preprocess' => FALSE,
        'every_page' => FALSE,
        'group' => CSS_THEME,
        'weight' => $key,
      ));
    }
  }
  if ($type == 'js') {
    foreach ($variable as $key => $item) {
      drupal_add_js($path . '/js/' . $item . '.js', array(
        'type' => 'file',
        'scope' => 'footer',
        'group' => JS_THEME,
        'every_page' => FALSE,
        'weight' => $key,
      ));
    }
  }
}

/**
 * Implement include js common in footer for every page.
 */
function kandb_theme_include_common_js($variable) {
  $path = drupal_get_path('theme', 'kandb_theme');
  foreach ($variable as $item) {
    drupal_add_js($path . '/js/' . $item . '.js', array(
      'type' => 'file',
      'scope' => 'footer',
      'group' => JS_THEME,
      'every_page' => TRUE,
      'weight' => -1,
    ));
  }
}

/**
 * Get the direction path from a theme.
 */
function kandb_theme_get_path($dir_name = NULL, $theme_name = NULL) {
  if (empty($dir_name)) {
    return NULL;
  }
  global $base_url, $theme;
  $theme_name = (empty($theme_name)) ? $theme : $theme_name;
  return $base_url . '/' . drupal_get_path('theme', $theme_name) . '/' . $dir_name . '/';
}

/**
 * Implemnts hook_preprocess_node().
 */
function kandb_theme_preprocess_node(&$vars) {
  switch ($vars['view_mode']) {
    case 'teaser_carrousel_3':
      $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__teaser_carrousel_3';
      $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__teaser_carrousel_3';
      break;

    case 'dossier_big_teaser':
      $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__dossier_big_teaser';
      $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__dossier_big_teaser';
      break;

    case 'teaser':
      $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__teaser';
      $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__teaser';
      break;


    default:
      break;
  }

  if ($vars['view_mode'] == 'full' && ($vars['type'] == 'bien' || $vars['type'] == 'programme')) {
    $programme = NULL;
    if ($vars['type'] == 'programme') {
      $programme = $vars['node'];
    }
    elseif (isset($vars['field_programme'][0]['entity'])) {
      $programme = $vars['field_programme'][0]['entity'];
    }
    $price_tva_min = $price_tva_max = 0;
    if (!empty($vars['field_tva']) && $programme != NULL) {
      if (isset($programme->field_program_low_tva_price_max[LANGUAGE_NONE][0]['value'])) {
        $price_tva_max = $programme->field_program_low_tva_price_max[LANGUAGE_NONE][0]['value'];
      }
      if (isset($programme->field_program_low_tva_price_min[LANGUAGE_NONE][0]['value'])) {
        $price_tva_min = $programme->field_program_low_tva_price_min[LANGUAGE_NONE][0]['value'];
      }
    }
    if ($price_tva_max != 0) {
      $vars['price_tva_max'] = $price_tva_max;
    }
    if ($price_tva_min != 0) {
      $vars['price_tva_min'] = $price_tva_min;
    }

    $vars['anchor'] = FALSE;
    if ($vars['title']) {
      $vars['anchor'] = TRUE;
    }
  }
  if ($vars['type'] == 'webform') {
    if (!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {    
      $vars['theme_hook_suggestions'][] = 'node__webform__ajax';
    }
  }
}

/**
 * Implemnts hook_preprocess_region().
 */
function kandb_theme_preprocess_region(&$vars){
  // Header
  if ($vars['region'] == 'header'){
    // Main menu
    $vars['main_menu'] = false;
    $menu_main_links_source = variable_get('menu_main_links_source', false);
    if ($menu_main_links_source) {
      $vars['main_menu'] = menu_navigation_links($menu_main_links_source);
    }
  }

  // Footer
  if ($vars['region'] == 'footer'){

    // Get variables
    $vars['icon_setting'] = variable_get('kandb_settings_social_display', FALSE);
    $vars['facebook'] = variable_get('kandb_settings_footer_link_face', FALSE);
    $vars['youtube'] = variable_get('kandb_settings_footer_link_youtube', FALSE);
    $vars['twitter'] = variable_get('kandb_settings_footer_link_twitter', FALSE);
    $vars['link_prescripteur'] = variable_get('kandb_settings_footer_link_espace_collaborateur', FALSE);

    // Logo and link "Espace prescripteur"
    $vars['path_img'] = kandb_theme_get_path('test_assets', 'kandb_theme');
    $vars['logo_svg'] = kandb_theme_get_path('assets', 'kandb_theme') . '/images/logo-Kaufman-Broad.svg';
    if (theme_get_setting('footer_link_custom')) {
      $vars['link_custom'] = theme_get_setting('footer_link_custom');
    }

    // Menu footer
    $vars['menu_footer'] = false;
    $menu_secondary_links_source = variable_get('menu_secondary_links_source', false);
    if ($menu_secondary_links_source) {
      $vars['menu_footer'] = menu_navigation_links($menu_secondary_links_source);
    }
  }
  // Change template on AJAX request
  if (!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {    
    $vars['theme_hook_suggestions'][] = 'region__ajax';
  }
}

function cut_character($content, $limit = ARTICLE_LIMIT_CONTENT){
  if ($limit <= 0 || !is_numeric($limit) || strlen($content) < $limit) {
      return $content;
  }
  
  $i = $limit - 1;
  while(1){
    if($i + 15 > $limit){
      break;
    }
    if($content[$i + 1] != ' '){
      $i++;
    }else{
      break;
    }
  }

  $end = '';
  if (mb_strlen($content, "UTF-8") > $limit) {
    $end = '...';
  }
  if (function_exists('mb_substr')) {
      $content = mb_substr($content, 0, $i, "UTF-8");
  } else {
      $content = substr($content, 0, $i);
  }
  return $content . $end;
}

/**
   * @todo to get taxonomy status du logement by name
   * @param type $term_name
   * @return type
   */
function get_tax_status_du_logement_by_name($term_name, $search_by_name = TRUE) {    
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term');
    //->entityCondition('bundle', TAXONOMY_STATUS_LOGEMENT)

    if (!$search_by_name) {
      $query->fieldCondition('field_id_file', 'value', $term_name, '=');
    }
    else {
      $query->propertyCondition('name', $term_name);
    }

    $query->range(0, 1);
    $results = $query->execute();
    if (!empty($results)) {
      return array_shift($results["taxonomy_term"])->tid;
    }

    return $results;
  }

/**
 * @todo to get list bien follow piece && programme
 * @param type $id_programme
 * @param type $id_piece
 */
function get_biens_follow_piece_program($id_programme, $id_piece = 0){
  $status_disponible = get_tax_status_du_logement_by_name(TAXONOMY_STATUS_LOGEMENT_DISPONIBLE);
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', CONTENT_TYPE_BIEN)
      ->fieldCondition('field_bien_statut', 'tid', $status_disponible, '=')
      ->fieldCondition('field_programme', 'target_id', $id_programme, '=')        
  ;

  if(!empty($id_piece)){      
    $query->fieldCondition('field_nb_pieces', 'tid', $id_piece, '=');
  }
  $results = $query->execute();
  if (!empty($results)) {
    return $results["node"];
  }
  
  return array();
}

/**
 * Returns HTML for a form element label and required marker.
 *
 * Form element labels include the #title and a #required marker. The label is
 * associated with the element itself by the element #id. Labels may appear
 * before or after elements, depending on theme_form_element() and
 * #title_display.
 *
 * This function will not be called for elements with no labels, depending on
 * #title_display. For elements that have an empty #title and are not required,
 * this function will output no label (''). For required elements that have an
 * empty #title, this will output the required marker alone within the label.
 * The label will use the #id to associate the marker with the field that is
 * required. That is especially important for screenreader users to know
 * which field is required.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #required, #title, #id, #value, #description.
 *
 * @ingroup themeable
 */
function kandb_theme_form_element_label($variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'] = 'element-invisible';
  }

  if (!empty($variables['element']['#attributes']['class'])) {
    $attributes['class'] .= ' ' . implode(' ', $variables['element']['#attributes']['class']);
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '><span>' . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</span></label>\n";
}

/**
 * Returns HTML for a checkbox form element.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #id, #name, #attributes, #checked, #return_value.
 *
 * @ingroup themeable
 */
function kandb_theme_checkbox($variables) {
  $variables['element']['#attributes']['class'][] = 'input-checkbox';
  return theme_checkbox($variables);
}

/**
 * Returns HTML for a select form element.
 *
 * It is possible to group options together; to do this, change the format of
 * $options to an associative array in which the keys are group labels, and the
 * values are associative arrays in the normal $options format.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #title, #value, #options, #description, #extra,
 *     #multiple, #required, #name, #attributes, #size.
 *
 * @ingroup themeable
 */
function kandb_theme_select($variables) {
  $variables['element']['#attributes']['data-app-select'] = '';
  if ($variables['element']['#id'] == 'edit-submitted-row-2-rappeler-horaire' || $variables['element']['#id'] == 'edit-submitted-rdv-connu') {
    $variables['element']['#options'][''] = '-';
  }
  return theme_select($variables);
}

/**
 * Implementation of hook_css_alter()
 */
function kandb_theme_css_alter(&$css){
  unset($css['modules/system/system.messages.css']);
}
