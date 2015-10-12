<?php
/**
 * Enable some features.
 */
function kandb_update_7001(&$sandbox) {
  $module_list = array(
    'kandb_taxonomy',
    'kandb_bien',
    'kandb_options',
    'kandb_programme',
    'kandb_prospect_b2b',
    'kandb_reservation',
    'kandb_selection',

  );
  module_enable($module_list);
}