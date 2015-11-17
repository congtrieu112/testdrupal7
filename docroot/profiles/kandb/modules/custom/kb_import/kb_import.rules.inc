<?php

function kb_import_rules_action_info() {
  $actions = array(
    'kb_import_run_importer' => array(
      'label' => t('Run importer'),
      'group' => t('Kandb import'),
      'parameter' => array(
        'kb_importer' => array(
          'type' => 'text',
          'label' => t('Importer will be run'),
          'options list' => 'kb_daily_import_importer_list',
        ),
      ),
    ),
    'kb_import_finish_daily_import' => array(
      'label' => t('Stop daily import and loging'),
      'group' => t('Kandb import'),
    ),
  );
  return $actions;
}
function kb_import_rules_condition_info() {
  $conditions = array();
  $conditions['status_of_daily_import'] = array(
    'label' => t('Daily import status'),
    'group' => t('Kandb import'),
    'parameter' => array(
      'kb_var_name' => array(
        'type' => 'text',
        'label' => t('Variable name'),
        'options list' => 'kb_daily_import_status_list',
      ),
      'kb_var_val' => array(
        'type' => 'text',
        'label' => t('Value of variable'),
        'options list' => 'kb_daily_import_status_value_list',
      ),
    ),
  );

  return $conditions;
}

function kb_import_rules_event_info() {
  $events = array();
    $events['daily_import_importer_finish'] = array(
      'label' => t('A daily import importer finished'),
      'group' => t('Kandb import'),
      'variables' => array(
        'kb_importer_finish' => array(
          'type' => 'text',
          'label' => t('importer finished'),
        ),
      ),
    );
    $events['starting_daily_import'] = array(
      'label' => t('Daily import starting'),
      'group' => t('Kandb import'),
    );
  return $events;
}


function kb_import_run_importer($importer = '') {
  if($importer && function_exists('feeds_source')) {
    $source = feeds_source($importer);
    $source->import();
  }
}

function kb_daily_import_status_list() {
  $list = array();
  $vars = array_keys(daily_import_status_default());
  foreach($vars as $var) {
    $list[$var] = str_replace('_', ' ', $var);
  }
  return $list;
}
function kb_daily_import_status_value_list() {
  return array(
    0 => 'Do not start',
    1 => 'Started',
    -1 => 'Failed',
  );
}
function status_of_daily_import($var_name = '' , $value) {
  $conpare = FALSE;
  $vars = get_daily_import_status();
  if(isset($vars[$var_name]) && $vars[$var_name] == $value) {
    $conpare = TRUE;
  }
  return $conpare;
}
function kb_import_finish_daily_import() {
  $kb_daily_import_status = get_daily_import_status();
  $daily_status = TRUE;
  //City feed import
  if (isset($kb_daily_import_status['city_feed_import_status'])) {
    if ($kb_daily_import_status['city_feed_import_status'] == 1) {
      kb_daily_import_logging ('jnb-102: City feed import success');
    }
    elseif ($kb_daily_import_status['city_feed_import_status'] == -1) {
      kb_daily_import_logging ('jnb-102: City feed import error');
    }
  }
  //District feed import
  if (isset($kb_daily_import_status['district_feed_import_status'])) {
    if ($kb_daily_import_status['district_feed_import_status'] == 1) {
      kb_daily_import_logging ('jnb-101: District feed import success');
    }
    elseif ($kb_daily_import_status['district_feed_import_status'] == -1) {
      kb_daily_import_logging ('jnb-101: District feed import error');
    }
  }
  //Maison feed import
  if (isset($kb_daily_import_status['maison_feed_import_status'])) {
    if ($kb_daily_import_status['maison_feed_import_status'] == 1) {
      kb_daily_import_logging ('jnb-103: Maison feed import success');
    }
    elseif ($kb_daily_import_status['maison_feed_import_status'] == -1) {
      kb_daily_import_logging ('jnb-103: Maison feed import error');
    }
  }
  //Programme feed import
  if (isset($kb_daily_import_status['programme_feed_import_status'])) {
    if ($kb_daily_import_status['programme_feed_import_status'] == 1) {
      kb_daily_import_logging ('jnb-104: Programme feed import success');
    }
    elseif ($kb_daily_import_status['programme_feed_import_status'] == -1) {
      $daily_status = FALSE;
      kb_daily_import_logging ('jnb-104: Programme feed import error');
    }
  }
  //Parcel feed import
  if (isset($kb_daily_import_status['parcel_feed_import_status'])) {
    if ($kb_daily_import_status['parcel_feed_import_status'] == 1) {
      kb_daily_import_logging ('jnb-105: Parcel feed import success');
    }
    elseif ($kb_daily_import_status['parcel_feed_import_status'] == -1) {
      $daily_status = FALSE;
      kb_daily_import_logging ('jnb-105: Parcel feed import error');
    }
    elseif ($kb_daily_import_status['parcel_feed_import_status'] == 0) {
      $daily_status = FALSE;
    }
  }
  if ($daily_status) {
    kb_daily_import_logging ('daily-import: Daily import success');
  }
  else {
    kb_daily_import_logging ('daily-import: Daily import error');
  }
  $kb_daily_import_status = daily_import_status_default();
  set_daily_import_status ($kb_daily_import_status);
}