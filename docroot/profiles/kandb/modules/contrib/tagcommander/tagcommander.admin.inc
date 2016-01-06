<?php

/**
 * Form builder to show account settings and website setting
 *
 * @ingroup forms
 * @see tagcommander_admin_settings_submit()
 */
function tagcommander_admin_settings()
{
    // Administrative role option.
    $form['account'] = array(
        '#type' => 'container',
        '#title' => t('Account'),
        '#attributes' => array('class' => array('admin-panel'))
    );

    $form['account']['title'] = array(
        '#markup' => t('Account'),
        '#prefix' => '<h3>',
        '#suffix' => '</h3><hr/>'
    );

    $form['account']['login'] = array(
        '#type' => 'textfield',
        '#title' => t('Login'),
        '#default_value' => variable_get('tagcommander_account_login', ''),
        '#maxlength' => 180
    );

    $form['account']['password'] = array(
        '#type' => 'password',
        '#title' => t('Password'),
        '#default_value' => variable_get('tagcommander_account_password', ''),
        '#maxlength' => 180
    );

    $form['account']['submit'] = array('#type' => 'submit', '#value' => t('Login'), '#submit' => array('tagcommander_admin_settings_submit'));

    try{
        if (TagCommander::getInstance()->checkAccount()) {

            $form['website'] = array(
                '#type' => 'container',
                '#title' => t('Website'),
                '#attributes' => array('class' => array('admin-panel'))
            );

            $form['website']['title'] = array(
                '#markup' => t('Website'),
                '#prefix' => '<h3>',
                '#suffix' => '</h3><hr/>'
            );

            $options = array();
            $sites = TagCommander::getInstance()->getSites();
            foreach ($sites as $site) {
                $options[$site['id_site']] = utf8_encode($site['name']);
            }
            $form['website']['website_select'] = array(
                '#type' => 'select',
                '#title' => t('Website'),
                '#default_value' => variable_get('tagcommander_website_id', 000),
                '#options' => $options,
                '#maxlength' => 180,
                '#empty_option' => t('Select a website')
            );

            $form['website']['submit'] = array('#type' => 'submit', '#value' => t('Save'), '#submit' => array('tagcommander_admin_settings_submit'));
        }
    }catch(Exception $e)
    {
        drupal_set_message(t('Login or Password are invalid'), 'warning');
    }


    return $form;
}

/**
 * Submit handler for account and website settings.
 *
 * @see tagcommander_admin_settings()
 */
function tagcommander_admin_settings_submit($form, &$form_state)
{

    // Test if is the account settings
    if ($form_state['triggering_element']['#value'] == t('Login')) {
        variable_set('menu_rebuild_needed', TRUE);
        variable_set('tagcommander_account_login', $form_state['values']['login']);
        variable_set('tagcommander_account_password', md5($form_state['values']['password']));

        variable_set('tagcommander_account_token', '');
        variable_set('tagcommander_account_validity', 0);
        variable_set('tagcommander_website_id', 0);
        variable_set('tagcommander_containers', array());

        if (!empty($form_state['values']['login']) && !empty($form_state['values']['password'])) {

            try {
                $token = TagCommander::getInstance()->getValidToken();

            } catch (Exception $e) {
                drupal_set_message(t('Login or Password are invalid'), 'warning');
            }

            if (!empty($token)) {
                drupal_set_message(t('Your configuration has been saved.'));
            }
        } else {
            drupal_set_message(t('Login or Password are invalid'), 'warning');
        }
    } else { // or website setting
        $websiteId = variable_get('tagcommander_website_id', 0);
        if ($websiteId !== $form_state['values']['website_select']) {
            variable_set('tagcommander_website_id', $form_state['values']['website_select']);
            variable_set('tagcommander_externals_variables', array());
            variable_set('tagcommander_containers', array());
            drupal_set_message(t('Your configuration has been saved.'));
        }
    }
}

/**
 * Returns HTML for an administrative block for display.
 *
 * @param $variables
 *   An associative array containing:
 *   - block: An array containing information about the block:
 *     - show: A Boolean whether to output the block. Defaults to FALSE.
 *     - title: The block's title.
 *     - content: (optional) Formatted content for the block.
 *     - description: (optional) Description of the block. Only output if
 *       'content' is not set.
 *
 * @ingroup themeable
 */
function theme_tagcommander_admin_settings($variables)
{
    $form = $variables['form'];
    return drupal_render_children($form);
}

/**
 * Form builder to list and manage containers.
 *
 * @ingroup forms
 * @see tagcommander_overview_containers_submit()
 * @see theme_tagcommander_overview_containers()
 */
function tagcommander_overview_containers($form, &$form_state)
{
    $containers = variable_get('tagcommander_containers', array());
    $form['#tree'] = TRUE;
    foreach ($containers as $container) {
        $form[$container->id]['#container'] = $container;
        $form[$container->id]['name'] = array('#markup' => check_plain($container->name));
        $form[$container->id]['position'] = array('#markup' => $container->position == 0 ? 'Header' : 'Footer');
        $form[$container->id]['url'] = array('#markup' => check_plain($container->url));
        $form[$container->id]['edit'] = array('#type' => 'link', '#title' => t('Edit container'), '#href' => "admin/config/tagcommander/containers/edit/$container->id");
        $form[$container->id]['delete'] = array(
            '#type' => 'link',
            '#title' => t('Delete container'),
            '#href' => "admin/config/tagcommander/containers/delete/" . $container->id,
        );
    }

    return $form;
}

/**
 * Returns HTML for the containers overview form .
 *
 * @param $variables
 *   An associative array containing:
 *   - form: A render element representing the form.
 *
 * @see tagcommander_overview_containers()
 * @ingroup themeable
 */
function theme_tagcommander_overview_containers($variables)
{
    $form = $variables['form'];

    $rows = array();

    foreach (element_children($form) as $key) {
        if (isset($form[$key]['name'])) {
            $vocabulary = & $form[$key];

            $row = array();
            $row[] = drupal_render($vocabulary['name']);
            $row[] = drupal_render($vocabulary['position']);
            $row[] = drupal_render($vocabulary['url']);
            $row[] = drupal_render($vocabulary['edit']);
            $row[] = drupal_render($vocabulary['delete']);
            $rows[] = array('data' => $row, 'class' => array('item-' . $key));
        }
    }

    $header = array(
        t('Container name'),
        t('Position'),
        t('Url'),
        array('data' => t('Operations'), 'colspan' => '2', "style" => 'text-align:center;')
    );

    $data = array(
        'header' => $header,
        'rows' => $rows,
        'attributes' => array('id' => 'container')
    );

    try{
        if (TagCommander::getInstance()->checkAccount()) {
            $data['empty'] = t('No tag container. <a href="@link">Add container</a>.', array('@link' => url('admin/config/tagcommander/containers/add')));
        }else{
            throw new Exception('No logged');
        }
    }catch(Exception $e)
    {
        $data['rows'] = array();
        $data['empty'] = t('You must be logged to view or add a tag container. <a href="@link">Go to login</a>.', array('@link' => url('admin/config/tagcommander/settings')));
    }

    $style = " <style type='text/css'>ul.action-links li{ float:right }</style> ";

    return theme('table', $data) . drupal_render_children($form) . $style;
}

/**
 * Form builder to confirm deleting container
 *
 * @ingroup forms
 * @see tagcommander_container_confirm_delete_submit()
 */
function tagcommander_container_confirm_delete($form, &$form_state, $container_id)
{
    $containers = variable_get('tagcommander_containers', array());

    $current_container = false;
    foreach ($containers as $container) {
        if ($container->id == $container_id) {
            $current_container = $container;
            break;
        }
    }

    if ($current_container == false) {
        $form_state['redirect'] = 'admin/config/tagcommander/containers';
        return;
    }

    // Always provide entity id in the same form key as in the entity edit form.
    $form['tcid'] = array('#type' => 'value', '#value' => $container_id);

    $form['#container'] = $current_container;
    $form['#id'] = 'taxonomy_vocabulary_confirm_delete';
    $form['type'] = array('#type' => 'value', '#value' => 'tagcommander_container');
    $form['name'] = array('#type' => 'value', '#value' => $current_container->name);
    $form['#submit'] = array('tagcommander_container_confirm_delete_submit');

    return confirm_form($form,
//        t('Are you sure you want to delete the container %title?',
        t('Container(s) configuration'),
        'admin/config/tagcommander/containers',
        t('Are you sure you want to delete the container %title? This action cannot be undone. However, this container will be available if you want to add it later',
            array('%title' => $current_container->name)
        ),
        t('Delete'),
        t('Cancel'));
}

/**
 * Submit handler for delete container.
 *
 * @see tagcommander_container_confirm_delete()
 */
function tagcommander_container_confirm_delete_submit($form, &$form_state)
{
    $containers = variable_get('tagcommander_containers', array());

    foreach ($containers as $key => $container) {
        if ($container->id == $form_state['values']['tcid']) {
            unset($containers[$key]);
            break;
        }
    }
    variable_set('tagcommander_containers', $containers);

    drupal_set_message(t('Deleted tag container %name.', array('%name' => $form_state['values']['name'])));
    watchdog('tagcommander', 'Deleted tag container %name.', array('%name' => $form_state['values']['name']), WATCHDOG_NOTICE);
    $form_state['redirect'] = 'admin/config/tagcommander/containers';
    cache_clear_all();
    return;
}

/**
 * Form builder to add or edit a container
 *
 * @ingroup forms
 * @see tagcommander_form_container_validate()
 * @see tagcommander_form_container_submit()
 */
function tagcommander_form_container($form, &$form_state, $id_container = false)
{
    $remote_containers = TagCommander::getInstance()->getContainers();
    $containers = variable_get('tagcommander_containers', array());

    $current_container = null;
    $current_key = null;
    $options = array();
    if( is_array($remote_containers) )
    {
        foreach ($remote_containers as $container) {
            $options[$container['id_container']] = utf8_encode($container['name_container']);
        }
    }



    if ($id_container !== false || !empty($containers)) {
        foreach ($containers as $key => $container) {
            if ($id_container !== false && $container) {
                $current_container = $container;
                $current_key = $key;
            } else {
                unset($options[$container->id]);
            }
        }
    }

    $form['container'] = array(
        '#type' => 'select',
        '#title' => t('Container'),
        '#options' => $options,
        '#maxlength' => 180,
    );

    $form['position'] = array(
        '#type' => 'radios',
        '#title' => t('Position'),
        '#default_value' => 0,
        '#options' => array(0 => t('Header'), 1 => t('Footer')),
        '#description' => t('Position to display the container'),
        '#required' => TRUE,
    );

    $form['url'] = array(
        '#type' => 'textfield',
        '#title' => t('Url'),
        '#maxlength' => 180,
        '#required' => TRUE,
    );

    $form['submit'] = array('#type' => 'submit', '#value' => t('Add'), '#submit' => array('tagcommander_form_container_submit'), '#validate' => array('tagcommander_form_container_validate'));

    if ($current_container !== null) {
        $form['container']['#default_value'] = $current_container->id;
        $form['container']['#disabled'] = true;

        $form['position']['#default_value'] = $current_container->position;
        $form['url']['#default_value'] = $current_container->url;

        $form['tcid'] = array('#type' => 'value', '#value' => $current_container->id);
        $form['tckey'] = array('#type' => 'value', '#value' => $current_key);

        $form['submit']['#value'] = t('Save');

    } else {
        $form['container']['#required'] = true;
    }

    return $form;
}

/**
 * Form validation handler for tagcommander_form_container().
 *
 * Makes sure that the url of the container is valid
 *
 * @see tagcommander_form_container()
 * @see tagcommander_form_container_submit()
 */
function tagcommander_form_container_validate($form, &$form_state)
{
    $url = $form_state['values']['url'];

    if (strpos($url, '//') === 0) {
        $url = 'http:' . $url;
    }

    if (!valid_url($url, true)) {
        form_set_error('url', t('You must set a valid url for this tag container.'));
    }
}

/**
 * Submit handler for add or edit container.
 *
 * @see tagcommander_form_container()
 */
function tagcommander_form_container_submit($form, &$form_state)
{
    $containers = variable_get('tagcommander_containers', array());

    foreach ($form['container']['#options'] as $key => $container) {
        if ($form_state['values']['container'] == $key) {
            $cont = new stdClass();
            $cont->id = $key;
            $cont->name = $container;
            $cont->url = $form_state['values']['url'];
            $cont->position = $form_state['values']['position'];

            if (isset($form_state['values']['tckey'])) {
                $containers[$form_state['values']['tckey']] = $cont;
            } else {
                $containers[] = $cont;
            }
            break;
        }
    }

    variable_set('tagcommander_containers', $containers);

    drupal_set_message(t('A container has been added.'));

    $form_state['redirect'] = 'admin/config/tagcommander/containers';
    cache_clear_all();
}

/**
 * Form builder to manage mapping
 *
 * @ingroup forms
 * @see theme_tagcommander_admin_mappings()
 * @see tagcommander_admin_mappings_submit()
 */
function tagcommander_admin_mappings($form, &$form_state)
{
    $variables = variable_get('tagcommander_externals_variables', array());
    $form['#tree'] = TRUE;

    if (empty($variables)) {
        $variables = TagCommander::getInstance()->getExternalsVariables();
        if( is_array($variables) )
        {
            foreach ($variables as &$var) {
                $var['label'] = utf8_encode($var['label']);
                $var['description'] = utf8_encode($var['description']);
                $var['default'] = utf8_encode($var['value']);
                $var['value'] = '';
            }
        }else{
            $variables = array();
        }

        variable_set('tagcommander_externals_variables', $variables);
    }

    $options = array();
    $options['Default variables'] = tagcommander_cms_variables();

    $types = node_type_get_types();

    foreach ($types as $type => $properties) {

        $type_name = ucfirst($type);
        $instances = field_info_instances('node', $type);
        $options[$type_name] = array();

        $key = 'node/' . $type . '/nid';
        $options[$type_name][$key] = t('Id');

        if ($properties->has_title === '1') {
            $key = 'node/' . $type . '/title';
            $options[$type_name][$key] = t('Title');
        }

        foreach ($instances as $name => $instance) {
            $field = field_info_field($instance['field_name']);

            if ($field['module'] != 'text' && $field['module'] != 'taxonomy') {
                continue;
            }

            $key = 'node/' . $type . '/' . $instance['field_name'];
            $options[$type_name][$key] = $instance['label'];
        }
    }

    foreach ($variables as $variable) {

        $form[$variable['id_external']]['name'] = array('#markup' => check_plain($variable['label']));
        $form[$variable['id_external']]['description'] = array('#markup' => check_plain($variable['description']));
        $form[$variable['id_external']]['default'] = array('#markup' => check_plain($variable['default']));
        $form[$variable['id_external']]['value'] = array(
            '#type' => 'select',
            '#options' => $options,
            '#default_value' => $variable['value'] === '' ? $variable['default'] : $variable['value'],
            '#empty_option' => t('Select a Drupal Variable')
        );
    }

    $form['submit'] = array('#type' => 'submit', '#value' => t('Save'), '#submit' => array('tagcommander_admin_mappings_submit'));
    $form['reload'] = array('#type' => 'submit', '#value' => t('Reload'), '#submit' => array('tagcommander_admin_mappings_submit'));

    return $form;
}

/**
 * Returns HTML for the variables mapping form .
 *
 * @param $variables
 *   An associative array containing:
 *   - form: A render element representing the form.
 *
 * @see tagcommander_admin_mappings()
 * @ingroup themeable
 */
function theme_tagcommander_admin_mappings($variables)
{
    $form = $variables['form'];

    $rows = array();

    foreach (element_children($form) as $key) {
        if (isset($form[$key]['name'])) {
            $vocabulary = & $form[$key];

            $row = array();
            $row[] = drupal_render($vocabulary['name']);
            $row[] = drupal_render($vocabulary['description']);
            $row[] = drupal_render($vocabulary['default']);
            $row[] = drupal_render($vocabulary['value']);
            $rows[] = array('data' => $row, 'class' => array('item-' . $key));
        }
    }

    $header = array(
        t('Name of Variable'),
        t('Description'),
        t('Default Value'),
        t('Value'),
    );

    $data = array(
        'header' => $header,
        'rows' => $rows,
        'attributes' => array('id' => 'variable_mapping')
    );

    try{
        if (TagCommander::getInstance()->checkAccount()) {
            $data['empty'] = t('You must add external variable into the Tagcommander Admin.');
            $return = theme('table', $data) . drupal_render_children($form);
        } else {
            throw new Exception('No logged');
        }

    }catch(Exception $e)
    {
        $data['rows'] = array();
        $data['empty'] = t('You must be logged to manage mapping. <a href="@link">Go to login</a>.', array('@link' => url('admin/config/tagcommander/settings')));
        $return = theme('table', $data);
    }


    return $return;

}

/**
 * Submit handler for reload (redirect) or save mapping settings.
 *
 * @see tagcommander_admin_mappings()
 */
function tagcommander_admin_mappings_submit($form, &$form_state)
{

    if ($form_state['triggering_element']['#value'] == t('Reload')) {
        $form_state['redirect'] = 'admin/config/tagcommander/mapping/confirm';
        return;
    }

    $variables = variable_get('tagcommander_externals_variables', array());

    foreach ($variables as &$var) {
        $var['value'] = $form_state['values'][$var['id_external']]['value'];
    }

    variable_set('tagcommander_externals_variables', $variables);

    drupal_set_message(t('Variables mapping has been saved.'));

    cache_clear_all();
}

/**
 * Form builder to confirm reloading mapping settings
 *
 * @ingroup forms
 * @see tagcommander_admin_mappings_reload_submit()
 */
function tagcommander_admin_mappings_reload($form, &$form_state)
{
    $form['#id'] = 'tagcommander_admin_mappings_reload';
    $form['#submit'] = array('tagcommander_admin_mappings_reload_submit');

    return confirm_form($form,
        t('Datalayer configuration'),
        'admin/config/tagcommander/mapping',
        t('Are you sure you want to reset & reload all variables? This action cannot be undone.'),
        t('Reload'),
        t('Cancel'));
}

/**
 * Submit handler for reload mapping settings.
 *
 * @see tagcommander_admin_mappings_reload()
 */
function tagcommander_admin_mappings_reload_submit($form, &$form_state)
{
    variable_set('tagcommander_externals_variables', array());
    drupal_set_message(t('All variables reloaded'));
    $form_state['redirect'] = 'admin/config/tagcommander/mapping';
    cache_clear_all();
}