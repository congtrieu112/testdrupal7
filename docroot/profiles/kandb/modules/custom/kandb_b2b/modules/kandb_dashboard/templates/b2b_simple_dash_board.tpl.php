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
?>

<!-- [offers] start-->
<?php if ($latest_offers): ?>
  <section class="section-padding">
      <div class="wrapper">
          <h2 class="heading--tiny"><?php print t('Les offres spéciales'); ?></h2>
          <!-- [carousel] start-->
          <?php
          print $latest_offers;
          ?>
          <!-- [carousel] end-->
      </div>
  </section>
  <!-- [offers] end-->
<?php endif; ?>




<?php
$special_offers = views_embed_view('b2b_nos_dernieres_offres', 'block_2');
if ($special_offers):
  ?>
  <!-- [nouvates] start-->
  <section class="section-padding bg-lightGrey">
      <div class="wrapper">
          <h2 class="heading--tiny"><?php print t('Nouveautés et avant premières'); ?></h2>
          <!-- [carousel] start-->
          <?php
          print $special_offers;
          ?>
          <!-- [carousel] end-->
      </div>
  </section>
  <!-- [nouvates] end-->

<?php endif; ?>
