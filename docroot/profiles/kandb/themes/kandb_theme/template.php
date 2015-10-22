<?php

/**
 * Override or insert variables into the page template.
 */
function kandb_theme_process_page(&$variables)
{
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

    $common_css = array(
        'app'
    );
    $common_js = array(
        'modernizr',
        'bundle',
    );
    kandb_theme_include_asset($common_css, 'css');
    kandb_theme_include_common_js($common_js);
}

/**
 * Implement include css/js for each page.
 */
function kandb_theme_include_asset($variable, $type)
{
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
function kandb_theme_include_common_js($variable)
{
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
function kandb_theme_get_path($dir_name = NULL, $theme_name = NULL)
{
    if (empty($dir_name)) {
        return NULL;
    }
    global $base_url, $theme;
    $theme_name = (empty($theme_name)) ? $theme : $theme_name;
    return $base_url . '/' . drupal_get_path('theme', $theme_name) . '/' . $dir_name . '/';
}
