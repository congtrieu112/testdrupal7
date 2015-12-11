<?php

// Domain for Acquia Purge
if (isset($_ENV['AH_SITE_ENVIRONMENT'])) {
  switch ($_ENV['AH_SITE_ENVIRONMENT']) {
    case 'dev':
      $sites['dev.kbpatrimoine.com'] = 'default';
      $sites['dev.kaufmanbroad.fr'] = 'default';
      $sites['kaufmanetbroaddev.prod.acquia-sites.com'] = 'default';
      break;

    case 'test':
      $sites['stage.kbpatrimoine.com'] = 'default';
      $sites['stage.kaufmanbroad.fr'] = 'default';
      $sites['kaufmanetbroadstg.prod.acquia-sites.com'] = 'default';
      break;

    case 'prod':
      $sites['www.kbpatrimoine.com'] = 'default';
      $sites['www.kaufmanbroad.fr'] = 'default';
      $sites['prod.kbpatrimoine.com'] = 'default';
      $sites['prod.kaufmanbroad.fr'] = 'default';
      $sites['kaufmanetbroad.prod.acquia-sites.com'] = 'default';
      break;
  }
}