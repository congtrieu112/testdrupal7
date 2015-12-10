<?php

// Domain for Acquia Purge
if (isset($_ENV['AH_SITE_ENVIRONMENT'])) {
  switch ($_ENV['AH_SITE_ENVIRONMENT']) {
    case 'dev':
      $sites['dev.kbpatrimoine.com'] = 'dev.kbpatrimoine.com';
      $sites['dev.kaufmanbroad.fr'] = 'dev.kaufmanbroad.fr';
      $sites['kaufmanetbroaddev.prod.acquia-sites.com'] = 'kaufmanetbroaddev.prod.acquia-sites.com';
      break;

    case 'test':
      $sites['stage.kbpatrimoine.com'] = 'stage.kbpatrimoine.com';
      $sites['stage.kaufmanbroad.fr'] = 'stage.kaufmanbroad.fr';
      $sites['kaufmanetbroadstg.prod.acquia-sites.com'] = 'kaufmanetbroadstg.prod.acquia-sites.com';
      break;

    case 'prod':
      $sites['www.kbpatrimoine.com'] = 'www.kbpatrimoine.com';
      $sites['www.kaufmanbroad.fr'] = 'www.kaufmanbroad.fr';
      $sites['prod.kbpatrimoine.com'] = 'prod.kbpatrimoine.com';
      $sites['prod.kaufmanbroad.fr'] = 'prod.kaufmanbroad.fr';
      $sites['kaufmanetbroad.prod.acquia-sites.com'] = 'kaufmanetbroad.prod.acquia-sites.com';
      break;
  }
}