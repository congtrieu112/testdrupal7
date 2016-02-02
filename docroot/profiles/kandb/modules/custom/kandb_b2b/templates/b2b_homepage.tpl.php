<?php
/**
 * @file
 * Template of B2B Homepage.
 */
$url = $title = '';
$default_title = variable_get('kandb_b2b_homepage_title', '');
$default_subtitle = variable_get('kandb_b2b_homepage_subtitle', '');
$default_cta = variable_get('kandb_b2b_homepage_cta');
if (isset($default_cta['url']) && $default_cta['url'] && isset($default_cta['title']) && $default_cta['title']) :
  $url = $default_cta['url'];
  $title = $default_cta['title'];
endif;
?>
<section data-equalizer data-equalizer-mq="medium-up" class="homepageB2B">
    <div data-interchange="[<?php print $bg_image_small; ?>, (small)], [<?php print $bg_image_large; ?>, (medium)]" class="homepageB2B__heading">
        <div data-equalizer-watch class="wrapper">
            <?php if ($program_ville || $default_title): ?>
              <div class="heading heading--bordered heading--white">
                  <div class="heading__title">
                      <?php if ($program_ville && $program_department): ?>
                        <?php print $program_ville; ?><?php print ($program_ville AND $program_department) ? ' / ' : ''; ?><?php print $program_department; ?><br>
                        <?php print $program_title; ?>
                      <?php else: ?>
                        <?php print $default_title; ?>
                      <?php endif; ?>
                  </div>
                  <?php if ($program_address || $default_subtitle) : ?>
                    <div class="heading__title heading__title--sub"><?php print ($program_address) ? $program_address : $default_subtitle; ?></div>
                  <?php endif; ?>
                  <?php if ($program_promotions) : ?>
                    <ul class="tags-list">
                        <?php foreach ($program_promotions as $key => $item) : ?>
                          <?php if (isset($item['title']) AND $item['title'] AND isset($item['nid']) AND $item['nid']) : ?>
                            <li>
                                <button data-reveal-id="<?php print 'B2bDetail' . $item['nid']; ?>" class="homepageB2B__popin__btn tag tag--important">
                                    <?php print $item['title']; ?><sup>&nbsp;(<?php print $key + 1; ?>)</sup>
                                </button>
                            </li>
                          <?php endif; ?>
                        <?php endforeach; ?>
                    </ul>
                  <?php endif; ?>
                  <?php if ($url && $title): ?>
                    <a href="<?php print url($url); ?>" title="<?php print $title; ?>">* <?php print $title; ?></a>
                  <?php endif; ?>
              </div>
            <?php endif; ?>
            <?php if ($program_promotions) : ?>
              <?php foreach ($program_promotions as $key => $item) : ?>
                <?php if (isset($item['mention_legale']) AND $item['mention_legale'] AND isset($item['nid']) AND $item['nid']) : ?>
                  <div id="<?php print 'B2bDetail' . $item['nid']; ?>" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
                      <div class="reveal-modal__wrapper">
                          <a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                          <div class="homepageB2B__popin__content">
                              <p><?php print $item['mention_legale']; ?></p>
                          </div>
                      </div>
                  </div>
                <?php endif; ?>
              <?php endforeach; ?>
            <?php endif; ?>
        </div>
    </div>
    <!-- [homepageB2B__login] start-->
    <div class="homepageB2B__login">
        <div class="wrapper">
            <div data-equalizer-watch class="homepageB2B__login--inner">
                <?php
                if ($login_form) :
                  print drupal_render($login_form);
                endif;
                ?>
                <div class="homepageB2B__login__content">
                    <div class="heading heading--switchColor">
                        <h3 class="heading__title"><?php print t('Pas encore inscrit ?'); ?></h3>
                    </div>
                    <p><?php print t('Devenez un partenaire de Kaufman & Broad et accédez à plus de 1000 logements correspondants'); ?></p>
                    <a href="<?php print url('user/register'); ?>" title="<?php print t('Inscrivez - vous'); ?>" class="btn-primary btn-rounded"><?php print t('Inscrivez - vous'); ?></a>
                </div>
            </div>
        </div>
    </div>
    <!-- [homepageB2B__login] end-->
</section>