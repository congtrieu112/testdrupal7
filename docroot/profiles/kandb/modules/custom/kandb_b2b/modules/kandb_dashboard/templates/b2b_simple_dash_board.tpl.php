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
?>

<!-- [offers] start-->
<section class="section-padding">
    <div class="wrapper">
        <h2 class="heading__title">Les programmes les plus proches</h2>
        <?php
        $latest_offers = views_embed_view('b2b_nos_dernieres_offres', 'block');
        print $latest_offers;
        ?>
        <div class="btn-wrapper btn-wrapper--center"><a href="#" class="btn-rounded btn-primary">Voir toutes nos offres<span class="icon icon-arrow"></span></a>
        </div>
    </div>
</section>
<!-- [offers] end-->

<?php
$special_offers = views_embed_view('b2b_nos_dernieres_offres', 'block-1');
print $special_offers;
?>