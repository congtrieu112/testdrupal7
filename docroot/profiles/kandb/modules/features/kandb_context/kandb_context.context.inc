<?php
/**
 * @file
 * kandb_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function kandb_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'header_and_footer';
  $context->description = '';
  $context->tag = 'Theme';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'kandb_context-header_empty' => array(
          'module' => 'kandb_context',
          'delta' => 'header_empty',
          'region' => 'header',
          'weight' => '-10',
        ),
        'kandb_context-footer_empty' => array(
          'module' => 'kandb_context',
          'delta' => 'footer_empty',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Theme');
  $export['header_and_footer'] = $context;

  return $export;
}
