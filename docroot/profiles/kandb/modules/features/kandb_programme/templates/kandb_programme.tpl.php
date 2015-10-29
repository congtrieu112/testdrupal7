<?php
$path_img = kandb_theme_get_path('test_assets', 'kandb_theme');
$logo_svg = kandb_theme_get_path('assets', 'kandb_theme') . '/images/logo-Kaufman-Broad.svg';


$logementBlock = module_invoke('kandb_programme', 'block_view', 'logement_block');
$documentBlock = module_invoke('kandb_programme', 'block_view', 'document_block');

print render($documentBlock['content']);

print render($logementBlock['content']['rs_price_max_min']);
foreach($logementBlock['content']['rs_price_most'] as $key => $value) {
  print render($logementBlock['content']['rs_price_most'][$key]);
  print render($logementBlock['content']['rs_price_least'][$key]);
}