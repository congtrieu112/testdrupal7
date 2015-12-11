<?php
/**
 * @file
 * kandb_bean.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function kandb_bean_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'b2b_block_tutorial';
  $bean_type->label = 'B2B block tutorial';
  $bean_type->options = '';
  $bean_type->description = 'B2B block tutorial in Dashboard';
  $export['b2b_block_tutorial'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'block_header';
  $bean_type->label = 'Block header';
  $bean_type->options = '';
  $bean_type->description = 'Utiliser cette entité pour créer des blocs au dessus du contenu comme sur les pages &quot;Nos conseils&quot; et &quot;Nos offres&quot;';
  $export['block_header'] = $bean_type;

  return $export;
}
