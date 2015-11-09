<?php
/**
 * @file
 * kandb_dossier.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function kandb_dossier_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dossier_articles_block1|node|dossier|form';
  $field_group->group_name = 'group_dossier_articles_block1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dossier';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dossier_articles';
  $field_group->data = array(
    'label' => 'Premier bloc d\'article',
    'weight' => '16',
    'children' => array(
      0 => 'field_articles_block1_ref',
      1 => 'field_articles_block1_title',
      2 => 'field_articles_block1_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dossier-articles-block1 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dossier_articles_block1|node|dossier|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dossier_articles_block2|node|dossier|form';
  $field_group->group_name = 'group_dossier_articles_block2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dossier';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dossier_articles';
  $field_group->data = array(
    'label' => 'Second bloc d\'article',
    'weight' => '17',
    'children' => array(
      0 => 'field_articles_block2_ref',
      1 => 'field_articles_block2_title',
      2 => 'field_articles_block2_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dossier-articles-block2 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dossier_articles_block2|node|dossier|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dossier_articles_block3|node|dossier|form';
  $field_group->group_name = 'group_dossier_articles_block3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dossier';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dossier_articles';
  $field_group->data = array(
    'label' => 'Troisième bloc d\'article',
    'weight' => '18',
    'children' => array(
      0 => 'field_articles_block3_ref',
      1 => 'field_articles_block3_title',
      2 => 'field_articles_block3_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dossier-articles-block3 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dossier_articles_block3|node|dossier|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dossier_articles|node|dossier|form';
  $field_group->group_name = 'group_dossier_articles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dossier';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lien vers les articles',
    'weight' => '10',
    'children' => array(
      0 => 'field_dossier_articles_intro',
      1 => 'field_dossier_articles_title',
      2 => 'group_dossier_articles_block1',
      3 => 'group_dossier_articles_block2',
      4 => 'group_dossier_articles_block3',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dossier-articles field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dossier_articles|node|dossier|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dossier_block1|node|dossier|form';
  $field_group->group_name = 'group_dossier_block1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dossier';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Premier bloc',
    'weight' => '5',
    'children' => array(
      0 => 'field_dossier_block1_image',
      1 => 'field_dossier_block1_text',
      2 => 'field_dossier_block1_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dossier-block1 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dossier_block1|node|dossier|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dossier_block2|node|dossier|form';
  $field_group->group_name = 'group_dossier_block2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dossier';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Second bloc',
    'weight' => '6',
    'children' => array(
      0 => 'field_dossier_block2_image',
      1 => 'field_dossier_block2_text',
      2 => 'field_dossier_block2_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dossier-block2 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dossier_block2|node|dossier|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dossier_block3|node|dossier|form';
  $field_group->group_name = 'group_dossier_block3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dossier';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Troisème bloc',
    'weight' => '7',
    'children' => array(
      0 => 'field_dossier_block3_image',
      1 => 'field_dossier_block3_text',
      2 => 'field_dossier_block3_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dossier-block3 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dossier_block3|node|dossier|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dossier_block4|node|dossier|form';
  $field_group->group_name = 'group_dossier_block4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dossier';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Quatrième bloc',
    'weight' => '8',
    'children' => array(
      0 => 'field_dossier_block4_image',
      1 => 'field_dossier_block4_text',
      2 => 'field_dossier_block4_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dossier-block4 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dossier_block4|node|dossier|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dossier_block5|node|dossier|form';
  $field_group->group_name = 'group_dossier_block5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dossier';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cinquième bloc',
    'weight' => '9',
    'children' => array(
      0 => 'field_dossier_block5_image',
      1 => 'field_dossier_block5_text',
      2 => 'field_dossier_block5_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dossier-block5 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dossier_block5|node|dossier|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_tags|node|dossier|form';
  $field_group->group_name = 'group_meta_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dossier';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta Tag',
    'weight' => '24',
    'children' => array(
      0 => 'field_meta_title',
      1 => 'field_meta_description',
      2 => 'field_meta_url_trunc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta-tags field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_meta_tags|node|dossier|form'] = $field_group;

  return $export;
}
