<?php

/**
 * @file
 * Template of B2B Simple Dash Board.
 */
// Get block Dash Board Header
$dash_board_header = module_invoke('bean', 'block_view', 'dash-board');
if ($dash_board_header['content']) {
  print render($dash_board_header['content']);
}
?>

