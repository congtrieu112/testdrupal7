<?php
/**
 * @file
 * kandb_region_kb.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function kandb_region_kb_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_agence1|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_agence1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_agences';
  $field_group->data = array(
    'label' => 'Agence 1',
    'weight' => '16',
    'children' => array(
      0 => 'field_kb_agence1_address',
      1 => 'field_kb_agence1_email',
      2 => 'field_kb_agence1_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-agence1 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_agence1|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_agence2|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_agence2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_agences';
  $field_group->data = array(
    'label' => 'Agence 2',
    'weight' => '17',
    'children' => array(
      0 => 'field_kb_agence2_address',
      1 => 'field_kb_agence2_email',
      2 => 'field_kb_agence2_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-agence2 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_agence2|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_agence3|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_agence3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_agences';
  $field_group->data = array(
    'label' => 'Agence 3',
    'weight' => '18',
    'children' => array(
      0 => 'field_kb_agence3_address',
      1 => 'field_kb_agence3_email',
      2 => 'field_t_l_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-agence3 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_agence3|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_agence4|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_agence4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_agences';
  $field_group->data = array(
    'label' => 'Agence 4',
    'weight' => '19',
    'children' => array(
      0 => 'field_kb_agence4_address',
      1 => 'field_kb_agence4_email',
      2 => 'field_kb_agence4_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-agence4 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_agence4|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_agence5|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_agence5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_agences';
  $field_group->data = array(
    'label' => 'Agence 5',
    'weight' => '20',
    'children' => array(
      0 => 'field_kb_agence5_address',
      1 => 'field_kb_agence5_email',
      2 => 'field_kb_agence5_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-agence5 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_agence5|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_agences|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_agences';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Agences',
    'weight' => '14',
    'children' => array(
      0 => 'group_region_kb_agence1',
      1 => 'group_region_kb_agence2',
      2 => 'group_region_kb_agence3',
      3 => 'group_region_kb_agence4',
      4 => 'group_region_kb_agence5',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-agences field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_agences|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_service1|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_service1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_services';
  $field_group->data = array(
    'label' => 'Service 1',
    'weight' => '31',
    'children' => array(
      0 => 'field_kb_service1_address',
      1 => 'field_kb_service1_email',
      2 => 'field_kb_service1_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-service1 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_service1|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_service2|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_service2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_services';
  $field_group->data = array(
    'label' => 'Service 2',
    'weight' => '32',
    'children' => array(
      0 => 'field_kb_service2_address',
      1 => 'field_kb_service2_email',
      2 => 'field_kb_service2_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-service2 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_service2|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_service3|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_service3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_services';
  $field_group->data = array(
    'label' => 'Service 3',
    'weight' => '33',
    'children' => array(
      0 => 'field_kb_service3_address',
      1 => 'field_kb_service3_email',
      2 => 'field_kb_service3_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-service3 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_service3|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_service4|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_service4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_services';
  $field_group->data = array(
    'label' => 'Service 4',
    'weight' => '34',
    'children' => array(
      0 => 'field_kb_service4_address',
      1 => 'field_kb_service4_email',
      2 => 'field_kb_service4_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-service4 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_service4|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_service5|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_service5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_services';
  $field_group->data = array(
    'label' => 'Service 5',
    'weight' => '35',
    'children' => array(
      0 => 'field_kb_service5_address',
      1 => 'field_kb_service5_email',
      2 => 'field_kb_service5_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-service5 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_service5|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_services|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_services';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Services',
    'weight' => '15',
    'children' => array(
      0 => 'group_region_kb_service1',
      1 => 'group_region_kb_service2',
      2 => 'group_region_kb_service3',
      3 => 'group_region_kb_service4',
      4 => 'group_region_kb_service5',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-services field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_services|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_showroom1|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_showroom1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_showroom';
  $field_group->data = array(
    'label' => 'Showroom 1',
    'weight' => '19',
    'children' => array(
      0 => 'field_kb_showroom1_address',
      1 => 'field_kb_showroom1_email',
      2 => 'field_kb_showroom1_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-showroom1 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_showroom1|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_showroom2|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_showroom2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_showroom';
  $field_group->data = array(
    'label' => 'Showroom 2',
    'weight' => '20',
    'children' => array(
      0 => 'field_kb_showroom2_address',
      1 => 'field_kb_showroom2_email',
      2 => 'field_kb_showroom2_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-showroom2 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_showroom2|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_showroom3|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_showroom3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_showroom';
  $field_group->data = array(
    'label' => 'Showroom 3',
    'weight' => '21',
    'children' => array(
      0 => 'field_kb_showroom3_address',
      1 => 'field_kb_showroom3_email',
      2 => 'field_kb_showroom3_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-showroom3 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_showroom3|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_showroom4|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_showroom4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_showroom';
  $field_group->data = array(
    'label' => 'Showroom 4',
    'weight' => '22',
    'children' => array(
      0 => 'field_kb_showroom4_address',
      1 => 'field_kb_showroom4_email',
      2 => 'field_kb_showroom4_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-showroom4 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_showroom4|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_showroom5|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_showroom5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_region_kb_showroom';
  $field_group->data = array(
    'label' => 'Showroom 5',
    'weight' => '23',
    'children' => array(
      0 => 'field_kb_showroom5_address',
      1 => 'field_kb_showroom5_email',
      2 => 'field_kb_showroom5_telephone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-showroom5 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_showroom5|node|region_kb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_region_kb_showroom|node|region_kb|form';
  $field_group->group_name = 'group_region_kb_showroom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'region_kb';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Showroom',
    'weight' => '16',
    'children' => array(
      0 => 'group_region_kb_showroom1',
      1 => 'group_region_kb_showroom2',
      2 => 'group_region_kb_showroom3',
      3 => 'group_region_kb_showroom4',
      4 => 'group_region_kb_showroom5',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-region-kb-showroom field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_region_kb_showroom|node|region_kb|form'] = $field_group;

  return $export;
}
