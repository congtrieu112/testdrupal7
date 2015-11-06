<?php
$path_img = kandb_theme_get_path('test_assets', 'kandb_theme');
$logo_svg = kandb_theme_get_path('assets', 'kandb_theme') . '/images/logo-Kaufman-Broad.svg';
$title = isset($logement_block['title']) ? $logement_block['title'] : '';
?>
<?php
if ($logement_block && isset($logement_block['total_bien'])) :
  ?>
  <section class="section-padding">
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h2 class="heading__title"><?php print t('Découvrir les logements'); ?></h2>
          </header>
      </div>
      <!-- [carousel] start-->
      <div data-slick="{&quot;slidesToShow&quot;: 1, &quot;slidesToScroll&quot;: 1}" class="slick-slider__item-1 programParcel">
          <?php
          $count = 1;
          foreach ($logement_block['total_bien'] as $type => $total) :
            if ($count % 6 == 1) :
              print '<div class="unwrap">';
            endif;
            ?>
            <article class="programParcelItem">
                <figure>
                    <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img; ?>programParcel-small.jpg, (small)], [<?php print $path_img; ?>programParcel-medium.jpg, (large)]"/>
                    <noscript><img src="<?php print $path_img; ?>programParcel-medium.jpg" alt="test"/></noscript>
                    <!-- [Responsive img] end-->
                </figure>
                <div class="programParcelItem__content">
                    <h3 class="programParcelItem__heading"><?php print $total; ?>&nbsp;<?php print t('appartements de'); ?>&nbsp;<?php print $type; ?>&nbsp;<?php print t('disponibles'); ?></h3>
                    <div class="programParcelItem__prices">
                        <?php
                        if (isset($logement_block['price_min_tva_un_20_bien'][$type]) && isset($logement_block['tva_bien'][$type])) :
                          ?>
                          <p><span><?php print t('À partir de '); ?><?php print number_format($logement_block['price_min_tva_un_20_bien'][$type], 0, '', ' ') . '€'; ?></span><span class="tva"><?php print 'TVA ' . $logement_block['tva_bien'][$type] . '%'; ?></span></p>
                          <?php
                        endif;
                        ?>

                        <?php
                        if (isset($logement_block['price_min_tva20_bien'][$type])) :
                          ?>
                          <p><span><?php print t('À partir de '); ?><?php print number_format($logement_block['price_min_tva20_bien'][$type], 0, '', ' ') . '€'; ?></span><span class="tva tva--high">TVA 20%</span></p>
                          <?php
                        endif;
                        ?>

                    </div>
                </div>
            </article>

            <?php
            if ($count % 6 == 0) :
              print '</div>';
            endif;
            $count++;
          endforeach;
          ?>
      </div>
      <!-- [carousel] end-->
  </section>
<?php endif; ?>