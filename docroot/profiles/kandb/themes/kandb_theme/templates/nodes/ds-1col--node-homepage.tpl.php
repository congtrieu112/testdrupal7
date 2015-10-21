<?php
$path_img = kandb_theme_get_path('test_assets', 'kandb_theme');
$logo_svg = kandb_theme_get_path('assets', 'kandb_theme') . '/images/logo-Kaufman-Broad.svg';
?>
        <!-- [homeSearch] start-->
        <!-- images need to have 2 different pictures see data-exchange attribute:
        - small: 640 x 845
        - large: 1380 x 590
        -->
        <section data-interchange="[<?php print file_create_url($content['field_hp_block_search_img_mob']['#items'][0]['uri']); ?>, (small)], [<?php print file_create_url($content['field_hp_block_search_img_des']['#items'][0]['uri']); ?>, (medium)]" class="homepage__search">
            <div class="wrapper">
                <div class="heading heading--bordered heading--white">
                    <div class="heading__title"><?php print render($content['field_hp_block_search_title']['#items'][0]['value']); ?></div>
                    <div class="heading__title heading__title--sub"><?php print render($content['field_hp_block_search_stitle']['#items'][0]['value']); ?></div>
                </div>
                 <?php print render($content['hp_block_search']); ?>
            </div>
        </section>
        <!-- [homeSearch] end-->

        <!-- [offers] start-->
        <section class="wrapper section-padding">
            <header class="heading heading--bordered">
                <h2 class="heading__title">Nos dernières offres</h2>
                <p class="heading__title heading__title--sub">Profitez des meilleures opportunités du moment !</p>
            </header>
            <!-- [carousel] start-->
            <div data-slick="{&quot;slidesToShow&quot;: 3, &quot;slidesToScroll&quot;: 3}" class="slick-slider__item-3">
                <?php print render($content['hp_block_offre']);?>
<!--                <div class="slick-slider__item">
                     [squaredImageItem] start
                    <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img; ?>/results-1.jpg" alt="description de la photo"/>
                            <div class="tag">Plus que deux T3 disponibles</div></a>
                        <div class="squaredImageItem__infos">
                            <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <p class="heading__title">Appartement</p>
                                    <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                            </div>
                        </div>
                    </article>
                     [squaredImageItem] end
                </div>
                <div class="slick-slider__item">
                     [squaredImageItem] start
                    <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img; ?>/results-1.jpg" alt="description de la photo"/></a>
                        <div class="squaredImageItem__infos">
                            <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <p class="heading__title">Appartement</p>
                                    <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                            </div>
                        </div>
                    </article>
                     [squaredImageItem] end
                </div>
                <div class="slick-slider__item">
                     [squaredImageItem] start
                    <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img; ?>/results-1.jpg" alt="description de la photo"/></a>
                        <div class="squaredImageItem__infos">
                            <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <p class="heading__title">Appartement</p>
                                    <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                            </div>
                        </div>
                    </article>
                     [squaredImageItem] end
                </div>
                <div class="slick-slider__item">
                     [squaredImageItem] start
                    <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img; ?>/results-1.jpg" alt="description de la photo"/></a>
                        <div class="squaredImageItem__infos">
                            <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <p class="heading__title">Appartement</p>
                                    <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                            </div>
                        </div>
                    </article>
                     [squaredImageItem] end
                </div>
                <div class="slick-slider__item">
                     [squaredImageItem] start
                    <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img; ?>/results-1.jpg" alt="description de la photo"/></a>
                        <div class="squaredImageItem__infos">
                            <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <p class="heading__title">Appartement</p>
                                    <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                            </div>
                        </div>
                    </article>
                     [squaredImageItem] end
                </div>
                <div class="slick-slider__item">
                     [squaredImageItem] start
                    <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img; ?>/results-1.jpg" alt="description de la photo"/></a>
                        <div class="squaredImageItem__infos">
                            <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <p class="heading__title">Appartement</p>
                                    <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                            </div>
                        </div>
                    </article>
                     [squaredImageItem] end
                </div>
                <div class="slick-slider__item">
                     [squaredImageItem] start
                    <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img; ?>/results-1.jpg" alt="description de la photo"/></a>
                        <div class="squaredImageItem__infos">
                            <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <p class="heading__title">Appartement</p>
                                    <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                            </div>
                        </div>
                    </article>
                     [squaredImageItem] end
                </div>-->
            </div>
            <!-- [carousel] end-->

            <div class="btn-wrapper btn-wrapper--center"><a href="#" class="btn-rounded btn-primary">Voir toutes nos offres<span class="icon icon-arrow"></span></a>
            </div>
        </section>
        <!-- [offers] end-->

        <!-- [homeDocs] start-->
        <section class="homeDocs">
            <div class="wrapper">
                <header class="heading heading--bordered">
                    <h2 class="heading__title">Nos conseils</h2>
                    <p class="heading__title heading__title--sub">Tout savoir sur l'immobilier neuf</p>
                </header>
                <div class="homeDocs__main">
                    <!-- images need to have 2 formats in data-interchange attribute:
                    - small: 560 x 365 (VERY high compression)
                    - medium: 1180 x 380
                    --><a href="https://www.youtube.com/watch?v=jO8k7fsdIIg" title="vidéo" data-reveal-id="videoConseilMain" data-interchange="[<?php print $path_img; ?>/advices-small.jpg, (small)], [<?php print $path_img; ?>/advices-large.jpg, (medium)]" class="homeDocs__main__link heading heading--white">
                        <h3 class="heading__title">Pourquoi acheter dans le neuf&nbsp;?</h3>
                        <div class="btn-icon"><span class="button__content"><span class="icon icon-play"></span>Lire la vidéo</span></div></a>
                    <!-- [popin] start-->
                    <div id="videoConseilMain" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal large">
                        <div class="reveal-modal__wrapper">
                            <div class="flex-video youtube">
                                <iframe width="1280" height="720" src="" data-src="//www.youtube.com/embed/jO8k7fsdIIg" frameborder="0" allowfullscreen allowtransparency="true"></iframe>
                            </div><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                        </div>
                    </div>
                    <!-- [popin] start-->
                    <div class="homeDocs__main__desc">
                        <p class="color-jet">Envie de devenir propriétaire&nbsp;? Ce rêve est à portée de main&nbsp;! Tour d’horizon des avantages de l’immobilier neuf.</p>
                        <div class="btn-wrapper"><a href="#" class="btn-secondary btn-rounded">Lire le dossier<span class="icon icon-arrow"></span></a></div>
                    </div>
                </div>
                <div class="homeDocs__list">
                    <div class="heading text-center">
                        <h3 class="heading__title heading__title--sub">Des solutions adaptées à chacun</h3>
                    </div>
                    <div data-equalizer data-slick="{&quot;slidesToShow&quot;: 1, &quot;slidesToScroll&quot;: 1}" data-slick-responsive="small-only" class="fileItem-list">
                        <!-- [fileItem] start-->
                        <article class="fileItem"><a href="https://www.youtube.com/watch?v=jO8k7fsdIIg" title="Lire la vidéo" data-reveal-id="videofileItem" class="fileItem__img"><span class="icon icon-play"></span>
                                <!-- images need to have 2 formats:
                                - small: 560 x 365 (HEAVY compression!!!)
                                - large: 560 x 365
                                -->
                                <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img; ?>/advices-small.jpg, (small)], [<?php print $path_img; ?>/advices-medium.jpg, (large)]"/>
                                <noscript><img src="<?php print $path_img; ?>/advices-medium.jpg" alt="test"/></noscript>
                                <!-- [Responsive img] end--></a>
                            <!-- [popin] start-->
                            <div id="videofileItem" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal large">
                                <div class="reveal-modal__wrapper">
                                    <div class="flex-video youtube">
                                        <iframe width="1280" height="720" src="" data-src="//www.youtube.com/embed/jO8k7fsdIIg" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true"></iframe>
                                    </div><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                </div>
                            </div>
                            <!-- [popin] start-->
                            <div data-equalizer-watch="data-equalizer-watch" class="fileItem__infos">
                                <h4 class="fileItem__infos__heading">Acheter pour la première fois</h4>
                                <div class="btn-wrapper text-center"><a href="#" class="btn-primary btn-rounded">Lire le dossier<span class="icon icon-arrow"></span></a></div>
                            </div>
                        </article>
                        <!-- [fileItem] end-->
                        <!-- [fileItem] start-->
                        <article class="fileItem"><a href="https://www.youtube.com/watch?v=jO8k7fsdIIg" title="Lire la vidéo" data-reveal-id="videofileItem" class="fileItem__img"><span class="icon icon-play"></span>
                                <!-- images need to have 2 formats:
                                - small: 560 x 365 (HEAVY compression!!!)
                                - large: 560 x 365
                                -->
                                <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img; ?>/advices-small.jpg, (small)], [<?php print $path_img; ?>/advices-medium.jpg, (large)]"/>
                                <noscript><img src="<?php print $path_img; ?>/advices-medium.jpg" alt="test"/></noscript>
                                <!-- [Responsive img] end--></a>
                            <!-- [popin] start-->
                            <div id="videofileItem" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal large">
                                <div class="reveal-modal__wrapper">
                                    <div class="flex-video youtube">
                                        <iframe width="1280" height="720" src="" data-src="//www.youtube.com/embed/jO8k7fsdIIg" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true"></iframe>
                                    </div><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                </div>
                            </div>
                            <!-- [popin] start-->
                            <div data-equalizer-watch="data-equalizer-watch" class="fileItem__infos">
                                <h4 class="fileItem__infos__heading">Investir dans le neuf</h4>
                                <p>Lorem ipsum dolor sit amet.</p>
                                <div class="btn-wrapper text-center"><a href="#" class="btn-primary btn-rounded">Lire le dossier<span class="icon icon-arrow"></span></a></div>
                            </div>
                        </article>
                        <!-- [fileItem] end-->
                        <!-- [fileItem] start-->
                        <article class="fileItem"><a href="https://www.youtube.com/watch?v=jO8k7fsdIIg" title="Lire la vidéo" data-reveal-id="videofileItem" class="fileItem__img"><span class="icon icon-play"></span>
                                <!-- images need to have 2 formats:
                                - small: 560 x 365 (HEAVY compression!!!)
                                - large: 560 x 365
                                -->
                                <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img; ?>/advices-small.jpg, (small)], [<?php print $path_img; ?>/advices-medium.jpg, (large)]"/>
                                <noscript><img src="<?php print $path_img; ?>/advices-medium.jpg" alt="test"/></noscript>
                                <!-- [Responsive img] end--></a>
                            <!-- [popin] start-->
                            <div id="videofileItem" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal large">
                                <div class="reveal-modal__wrapper">
                                    <div class="flex-video youtube">
                                        <iframe width="1280" height="720" src="" data-src="//www.youtube.com/embed/jO8k7fsdIIg" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true"></iframe>
                                    </div><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                </div>
                            </div>
                            <!-- [popin] start-->
                            <div data-equalizer-watch="data-equalizer-watch" class="fileItem__infos">
                                <h4 class="fileItem__infos__heading">Bien vivre sa retraite</h4>
                                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</p>
                                <div class="btn-wrapper text-center"><a href="#" class="btn-primary btn-rounded">Lire le dossier<span class="icon icon-arrow"></span></a></div>
                            </div>
                        </article>
                        <!-- [fileItem] end-->
                        <!-- [fileItem] start-->
                        <article class="fileItem"><a href="https://www.youtube.com/watch?v=jO8k7fsdIIg" title="Lire la vidéo" data-reveal-id="videofileItem" class="fileItem__img"><span class="icon icon-play"></span>
                                <!-- images need to have 2 formats:
                                - small: 560 x 365 (HEAVY compression!!!)
                                - large: 560 x 365
                                -->
                                <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img; ?>/advices-small.jpg, (small)], [<?php print $path_img; ?>/advices-medium.jpg, (large)]"/>
                                <noscript><img src="<?php print $path_img; ?>/advices-medium.jpg" alt="test"/></noscript>
                                <!-- [Responsive img] end--></a>
                            <!-- [popin] start-->
                            <div id="videofileItem" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal large">
                                <div class="reveal-modal__wrapper">
                                    <div class="flex-video youtube">
                                        <iframe width="1280" height="720" src="" data-src="//www.youtube.com/embed/jO8k7fsdIIg" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true"></iframe>
                                    </div><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                </div>
                            </div>
                            <!-- [popin] start-->
                            <div data-equalizer-watch="data-equalizer-watch" class="fileItem__infos">
                                <h4 class="fileItem__infos__heading">Acheter pour la première fois</h4>
                                <div class="btn-wrapper text-center"><a href="#" class="btn-primary btn-rounded">Lire le dossier<span class="icon icon-arrow"></span></a></div>
                            </div>
                        </article>
                        <!-- [fileItem] end-->
                    </div>
                </div>
            </div>
        </section>
        <!-- [homeDocs] end-->