<?php
/**
 * @file
 * Template of B2B Simple Dash Board.
 */

// Get block Dash Board Header.
$dash_board_header = module_invoke('bean', 'block_view', 'dash-board');
if (isset($dash_board_header['content']) AND $dash_board_header['content']) :
  print render($dash_board_header['content']);
endif;

$latest_offers = views_embed_view('b2b_nos_dernieres_offres', 'block');
print $latest_offers;

$special_offers = views_embed_view('b2b_nos_dernieres_offres', 'block-1');
print $special_offers;
