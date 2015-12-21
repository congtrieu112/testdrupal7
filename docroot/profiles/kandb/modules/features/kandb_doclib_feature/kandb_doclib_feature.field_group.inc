<?php
/**
 * @file
 * kandb_doclib_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function kandb_doclib_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_document_contacts|node|document|form';
  $field_group->group_name = 'group_document_contacts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contacts',
    'weight' => '11',
    'children' => array(
      0 => 'field_contact1_display',
      1 => 'field_contact1_email',
      2 => 'field_contact1_text',
      3 => 'field_contact1_title',
      4 => 'field_contact2_display',
      5 => 'field_contact2_email',
      6 => 'field_contact2_text',
      7 => 'field_contact2_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-document-contacts field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_document_contacts|node|document|form'] = $field_group;

  return $export;
}
