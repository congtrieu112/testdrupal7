<?php
/**
 * @file
 * kandb_dashboard_b2c.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function kandb_dashboard_b2c_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mes_selections';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'mon-projet' => 'mon-projet',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-kandb_dashboard_b2c-block' => array(
          'module' => 'views',
          'delta' => 'kandb_dashboard_b2c-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['mes_selections'] = $context;

  return $export;
}
