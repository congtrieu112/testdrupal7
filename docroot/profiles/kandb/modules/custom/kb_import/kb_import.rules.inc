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
    'kb_programme_migration_finish' => array(
      'label' => t('Stop programme migration and loging'),
      'group' => t('Kandb import'),
    ),
    'kb_bien_migration_finish' => array(
      'label' => t('Stop bien migration and loging'),
      'group' => t('Kandb import'),
    ),
    'kb_document_migration_finish' => array(
      'label' => t('Stop document migration and loging'),
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
  $conditions['status_of_migration'] = array(
    'label' => t('Daily migration status'),
    'group' => t('Kandb import'),
    'parameter' => array(
      'kb_var_name' => array(
        'type' => 'text',
        'label' => t('Variable name'),
        'options list' => 'kb_migration_status_list',
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
    $events['migration_importer_finish'] = array(
      'label' => t('A daily migration importer finished'),
      'group' => t('Kandb import'),
      'variables' => array(
        'kb_migration_importer_finish' => array(
          'type' => 'text',
          'label' => t('migration importer finished'),
        ),
      ),
    );
    $events['starting_daily_import'] = array(
      'label' => t('Daily import starting'),
      'group' => t('Kandb import'),
    );
    $events['start_migration_import'] = array(
      'label' => t('Daily migration starting'),
      'group' => t('Kandb import'),
    );
  return $events;
}


function kb_import_run_importer($importer = '') {
  if ($importer) {
    //Set status
    $kb_rule = '';
    $kb_daily_import_status = get_daily_import_status ();
    $kb_migration_status = get_migration_status();
    if (isset($kb_daily_import_status['start_daily_import']) && $kb_daily_import_status['start_daily_import'] == 1) {
      $kb_daily_import_status[$importer . '_status'] = -1;
      set_daily_import_status($kb_daily_import_status);
      $kb_rule = 'daily_import';
    }
    else {
      if (isset($kb_migration_status['start_migration']) && $kb_migration_status['start_migration'] == 1) {
        $kb_migration_status[$importer . '_status'] = -1;
        set_migration_status($kb_migration_status);
        $kb_rule = 'migration';
        kb_migration_logging ('migration : start ' . $importer);
      }
    }
    //Run importer
    if($importer != 'import_bien_pdf' && function_exists('feeds_source')) {
      $source = feeds_source($importer);
      try {
        while (FEEDS_BATCH_COMPLETE != $source->import()) {
          sleep(15);
        }
      }
      catch (Exception $e){
        if ($kb_rule == 'daily_import') {
           kb_daily_import_logging ('daily import | ' . $importer . ' | Error: ' . $e->getMessage());
           rules_invoke_event('daily_import_importer_finish', $importer);
        }
        elseif ($kb_rule == 'migration') {
          kb_migration_logging ('migration | ' . $importer . ' | Error: ' . $e->getMessage());
          rules_invoke_event('migration_importer_finish', $importer);
        }
        set_migration_status(migration_status_default());
        set_daily_import_status(daily_import_status_default());
      }
    }
    elseif ($importer == 'import_bien_pdf') {
      $dir_parrent = variable_get('import_bien_pdf_dir_parent');
      if ($dir_parrent == NULL) {
        variable_set('import_bien_pdf_dir_parent', 'lot_plan/');
      }
      try {
        batch_set(import_bien_pdf_batch_operation());
        $batch = & batch_get();
        $batch['progressive'] = FALSE;
        batch_process();
      }
      catch (Exception $e) {
        if ($kb_rule == 'migration') {
          kb_migration_logging ('migration | import_bien_pdf | Error: ' . $e->getMessage());
          rules_invoke_event('migration_importer_finish', 'import_bien_pdf');
          set_migration_status(migration_status_default());
          set_daily_import_status(daily_import_status_default());
        }
      }
    } 
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
function kb_migration_status_list() {
  $list = array();
  $vars = array_keys(migration_status_default());
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
function status_of_migration($var_name = '' , $value) {
  $conpare = FALSE;
  $vars = get_migration_status();
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
    kb_daily_import_logging ('daily-import: Start run business rule for programme_feed_import');
    kandb_business_rules_feeds_after_import_callback('programme_feed_import');
    kb_daily_import_logging ('daily-import: Finish run business rule for programme_feed_import');
    kb_daily_import_logging ('daily-import: Start run business rule for parcel_feed_import');
    kandb_business_rules_feeds_after_import_callback('parcel_feed_import');
    kb_daily_import_logging ('daily-import: Finish run business rule for parcel_feed_import');
  }
  else {
    kb_daily_import_logging ('daily-import: Daily import error');
    if ($kb_daily_import_status['programme_feed_import_status'] == 1) {
      kb_daily_import_logging ('daily-import: Start run business rule for programme_feed_import');
      kandb_business_rules_feeds_after_import_callback('programme_feed_import');
      kb_daily_import_logging ('daily-import: Finish run business rule for programme_feed_import');
    }
  }
  $kb_daily_import_status = daily_import_status_default();
  set_daily_import_status ($kb_daily_import_status);
}
function kb_programme_migration_finish () {
  $kb_migration_status = get_migration_status();
  if (isset($kb_migration_status['kb_patrimoine_import_status'])) {
    $migration_programme_status = 0;
    if ($kb_migration_status['kb_patrimoine_import_status'] == 1) {
      kb_migration_logging ('migration programme: migration programme success');
      $migration_programme_status = 1;
    }
    elseif ($kb_migration_status['kb_patrimoine_import_status'] == -1) {
      kb_migration_logging ('migration programme: migration programme error | migration kb_patrimoine_import error');
      $migration_programme_status = -1;
    }
    elseif (isset ($kb_migration_status['migration_program_import_status']) && $kb_migration_status['migration_program_import_status'] == -1) {
      kb_migration_logging ('migration programme: migration programme error | migration migration_program_import error');
      $migration_programme_status = -1;
    }
    //Check other status
    if ($kb_migration_status['migration_document_status'] != 0 && $kb_migration_status['migration_bien_status'] != 0) {
      set_migration_status(migration_status_default());
      kb_migration_logging ('migration : migration success');
      if ($kb_migration_status['parcel_feed_import_status'] == 1) {
        kb_migration_logging ('daily-import: Start run business rule for parcel_feed_import');
        kandb_business_rules_feeds_after_import_callback('parcel_feed_import');
        kb_migration_logging ('daily-import: Finish run business rule for parcel_feed_import');
      }
      kb_starting_daily_import();
    }
    else {
      $kb_migration_status['migration_program_status'] = $migration_programme_status;
      set_migration_status($kb_migration_status);
    }
  }
}
function kb_bien_migration_finish () {
  $kb_migration_status = get_migration_status();
  $migration_bien_status = -1;
  if (isset($kb_migration_status['migration_bien_import_status']) && $kb_migration_status['migration_bien_import_status'] == -1) {
    kb_migration_logging ('migration bien: migration bien error | migration_bien_import error');
  }
  else {
    if (isset($kb_migration_status['parcel_feed_import_status']) && $kb_migration_status['parcel_feed_import_status'] == -1) {
      kb_migration_logging ('migration bien: migration bien error | parcel_feed_import error');
    }
    else {
      if (isset($kb_migration_status['migration_program_video_import_status']) && $kb_migration_status['migration_program_video_import_status'] == -1) {
        kb_migration_logging ('migration bien: migration bien error | migration_program_video_import error');
      }
      else {
        if (isset($kb_migration_status['import_bien_pdf_status']) && $kb_migration_status['import_bien_pdf_status'] == -1) {
          kb_migration_logging ('migration bien: migration bien error | import_bien_pdf error');
        }
        else {
          kb_migration_logging ('migration bien: migration bien success');
          $migration_bien_status = 1;
        }
      }
    }
  }
  if ($kb_migration_status['migration_program_status'] != 0 && $kb_migration_status['migration_document_status'] != 0) {
    set_migration_status(migration_status_default());
    kb_migration_logging ('migration : migration success');
    if ($kb_migration_status['parcel_feed_import_status'] == 1) {
      kb_migration_logging ('daily-import: Start run business rule for parcel_feed_import');
      kandb_business_rules_feeds_after_import_callback('parcel_feed_import');
      kb_migration_logging ('daily-import: Finish run business rule for parcel_feed_import');
    }
    kb_starting_daily_import();
  }
  else {
    $kb_migration_status['migration_bien_status'] = $migration_bien_status;
    set_migration_status($kb_migration_status);
  }
}
function kb_document_migration_finish () {
  $kb_migration_status = get_migration_status();
  if (isset($kb_migration_status['document_import_communique_de_presse_status'])) {
    $migration_document_status = 0;
    if ($kb_migration_status['document_import_communique_de_presse_status'] == 1) {
      kb_migration_logging ('migration document: migration document success');
      $migration_document_status = 1;
    }
    else {
      $migration_document_status = -1;
    }
    if ($kb_migration_status['migration_program_status'] != 0 && $kb_migration_status['migration_bien_status'] != 0) {
      set_migration_status(migration_status_default());
      kb_migration_logging ('migration : migration success');
      if ($kb_migration_status['parcel_feed_import_status'] == 1) {
        kb_migration_logging ('daily-import: Start run business rule for parcel_feed_import');
        kandb_business_rules_feeds_after_import_callback('parcel_feed_import');
        kb_migration_logging ('daily-import: Finish run business rule for parcel_feed_import');
      }
      kb_starting_daily_import();
    }
    else {
      $kb_migration_status['migration_document_status'] = $migration_document_status;
      set_migration_status($kb_migration_status);
    }
  }
}