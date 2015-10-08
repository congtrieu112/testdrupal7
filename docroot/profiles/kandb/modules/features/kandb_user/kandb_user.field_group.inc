<?php
/**
 * @file
 * kandb_user.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function kandb_user_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile|user|user|form';
  $field_group->group_name = 'group_profile';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile',
    'weight' => '43',
    'children' => array(
      0 => 'field_prenom',
      1 => 'field_user_nom',
      2 => 'field_user_adresse',
      3 => 'field_user_code_postal',
      4 => 'field_user_ville',
      5 => 'field_user_pays',
      6 => 'field_user_telephone',
      7 => 'field_user_email',
      8 => 'field_user_societe',
      9 => 'field_user_message',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-profile field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_profile|user|user|form'] = $field_group;

  return $export;
}
