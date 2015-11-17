<?php
if (isset($content['nos_offre'])):
  print render($content['nos_offre']);
endif;
if (isset($content['view_menu_nos_offres'])):
  print render($content['view_menu_nos_offres']);
endif;
?>

<!-- [Avant-premiere] start-->
<section class="bg-lightGrey">
    <div class="wrapper section-padding">
        <header class="heading heading--bordered">
            <h2 class="heading__title">Avant-première</h2>
            <p class="heading__title heading__title--sub heading__title--limit">Découvrez nos prochains programmes immobilier en avant-première et soyiez alerté dès l’ouverture des ventes</p>
        </header>
        <!-- [carousel] start-->
        <div data-slick="{&quot;slidesToShow&quot;: 3, &quot;slidesToScroll&quot;: 3}" data-equalizer="squaredImageItem" class="slick-slider__item-3">
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem false">
                    <aside>
                        <p class="squaredImageItem__date">24 &amp; 25 &amp; 26 Décembre</p>
                    </aside>
                    <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                        <ul class="squaredImageItem__img__tags">
                            <li>
                                <div class="tag tag--important">Plus que deux T3 disponibles</div>
                            </li>
                            <li>
                                <button data-reveal-trigger="promotion-1-1" class="tag">TVA 7%<sup>(2)</sup></button>
                                <!-- [popin] start-->
                                <div data-reveal="promotion-1-1" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                                    <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                        <p class="heading heading--bordered heading--small"><strong class="heading__title">Mentions legales</strong></p>
                                        <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                                        <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                                    </div>
                                </div>
                                <!-- [popin] end-->
                            </li>
                            <li>
                                <button data-reveal-trigger="promotion-2-1" class="tag">Livraison immédiate<sup>(1)</sup></button>
                                <!-- [popin] start-->
                                <div data-reveal="promotion-2-1" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                                    <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                        <p class="heading heading--bordered heading--small"><strong class="heading__title">Mentions legales</strong></p>
                                        <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                                        <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                                    </div>
                                </div>
                                <!-- [popin] end-->
                            </li>
                        </ul>
                    </div>
                    <div data-equalizer-watch="squaredImageItem" class="squaredImageItem__infos">
                        <div class="squaredImageItem__details">
                            <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <h3 class="heading__title">Puteaux / 92</h3>
                                    <p class="heading__title heading__title--sub">Le Capitole</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="1" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem false">
                    <aside>
                        <p class="squaredImageItem__date">24 &amp; 25 &amp; 26 Décembre</p>
                    </aside>
                    <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                    </div>
                    <div data-equalizer-watch="squaredImageItem" class="squaredImageItem__infos">
                        <div class="squaredImageItem__details">
                            <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <h3 class="heading__title">Villeneuve D’Ornon / 33</h3>
                                    <p class="heading__title heading__title--sub">Le domaine de testerins</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="2" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem false">
                    <aside>
                        <p class="squaredImageItem__date">24 &amp; 25 &amp; 26 Décembre</p>
                    </aside>
                    <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                    </div>
                    <div data-equalizer-watch="squaredImageItem" class="squaredImageItem__infos">
                        <div class="squaredImageItem__details">
                            <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <h3 class="heading__title">Villeneuve D’Ornon / 33</h3>
                                    <p class="heading__title heading__title--sub">Le domaine de testerins</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="3" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem false">
                    <aside>
                        <p class="squaredImageItem__date">24 &amp; 25 &amp; 26 Décembre</p>
                    </aside>
                    <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                    </div>
                    <div data-equalizer-watch="squaredImageItem" class="squaredImageItem__infos">
                        <div class="squaredImageItem__details">
                            <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <h3 class="heading__title">Villeneuve D’Ornon / 33</h3>
                                    <p class="heading__title heading__title--sub">Le domaine de testerins</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="4" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem false">
                    <aside>
                        <p class="squaredImageItem__date">24 &amp; 25 &amp; 26 Décembre</p>
                    </aside>
                    <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                    </div>
                    <div data-equalizer-watch="squaredImageItem" class="squaredImageItem__infos">
                        <div class="squaredImageItem__details">
                            <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <h3 class="heading__title">Villeneuve D’Ornon / 33</h3>
                                    <p class="heading__title heading__title--sub">Le domaine de testerins</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="5" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem false">
                    <aside>
                        <p class="squaredImageItem__date">24 &amp; 25 &amp; 26 Décembre</p>
                    </aside>
                    <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                    </div>
                    <div data-equalizer-watch="squaredImageItem" class="squaredImageItem__infos">
                        <div class="squaredImageItem__details">
                            <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <h3 class="heading__title">Villeneuve D’Ornon / 33</h3>
                                    <p class="heading__title heading__title--sub">Le domaine de testerins</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="6" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem false">
                    <aside>
                        <p class="squaredImageItem__date">24 &amp; 25 &amp; 26 Décembre</p>
                    </aside>
                    <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                    </div>
                    <div data-equalizer-watch="squaredImageItem" class="squaredImageItem__infos">
                        <div class="squaredImageItem__details">
                            <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                    <h3 class="heading__title">Villeneuve D’Ornon / 33</h3>
                                    <p class="heading__title heading__title--sub">Le domaine de testerins</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="7" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
        </div>
        <!-- [carousel] end-->

    </div>
</section>
<!-- [Avant-premiere] end-->
<!-- [Prochainement] start-->
<section id="shortly" class="wrapper section-padding">
    <header class="heading heading--bordered filter-aside">
        <h2 class="heading__title">Prochainement</h2>
        <div class="filter">
            <div class="filter__label">Trier par</div>
            <div class="form-dropdown form-dropdown--floating filter__item">
                <button aria-expanded="false" aria-controls="offerFilter" data-app-dropdown class="form-dropdown__trigger"><span class="text">Marseilles</span><span aria-hidden="true" class="icon icon-expand"></span></button>
                <div id="offerFilter" aria-hidden="true" class="form-dropdown__content form-dropdown__content--last hidden">
                    <ul class="ul-unstyled undo-padding">
                        <li class="bordered"><a href="B2C-offersThumbnails.html#shortly" tabindex="0" aria-selected="true">Marseilles</a></li>
                        <li class="bordered"><a href="B2C-offersThumbnails.html#shortly" tabindex="0" aria-selected="false">Paris</a></li>
                    </ul>
                </div>
            </div>
        </div>
    </header>
    <ul class="small-block-grid-1 medium-block-grid-3">
        <li>
            <!-- [squaredImageItem] start-->
            <article class="squaredImageItem false">
                <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                    <ul class="squaredImageItem__img__tags">
                        <li>
                            <div class="tag tag--important">Plus que deux T3 disponibles</div>
                        </li>
                        <li>
                            <button data-reveal-trigger="promotion-1-8" class="tag">TVA 7%<sup>(2)</sup></button>
                            <!-- [popin] start-->
                            <div data-reveal="promotion-1-8" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                                <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                    <p class="heading heading--bordered heading--small"><strong class="heading__title">Mentions legales</strong></p>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                                </div>
                            </div>
                            <!-- [popin] end-->
                        </li>
                        <li>
                            <button data-reveal-trigger="promotion-2-8" class="tag">Livraison immédiate<sup>(1)</sup></button>
                            <!-- [popin] start-->
                            <div data-reveal="promotion-2-8" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                                <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                    <p class="heading heading--bordered heading--small"><strong class="heading__title">Mentions legales</strong></p>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                                </div>
                            </div>
                            <!-- [popin] end-->
                        </li>
                    </ul>
                </div>
                <div class="squaredImageItem__infos">
                    <div class="squaredImageItem__details">
                        <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                <h3 class="heading__title">Puteaux / 92</h3>
                                <p class="heading__title heading__title--sub">Le Capitole</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="8" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                    </div>
                </div>
            </article>
            <!-- [squaredImageItem] end-->
        </li>
        <li>
            <!-- [squaredImageItem] start-->
            <article class="squaredImageItem false">
                <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                </div>
                <div class="squaredImageItem__infos">
                    <div class="squaredImageItem__details">
                        <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                <h3 class="heading__title">Villeneuve D’Ornon / 33</h3>
                                <p class="heading__title heading__title--sub">Le domaine de testerins</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="9" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                    </div>
                </div>
            </article>
            <!-- [squaredImageItem] end-->
        </li>
        <li>
            <!-- [squaredImageItem] start-->
            <article class="squaredImageItem false">
                <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                    <ul class="squaredImageItem__img__tags">
                        <li>
                            <div class="tag tag--important">Plus que deux T3 disponibles</div>
                        </li>
                        <li>
                            <button data-reveal-trigger="promotion-1-10" class="tag">TVA 7%<sup>(2)</sup></button>
                            <!-- [popin] start-->
                            <div data-reveal="promotion-1-10" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                                <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                    <p class="heading heading--bordered heading--small"><strong class="heading__title">Mentions legales</strong></p>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                                </div>
                            </div>
                            <!-- [popin] end-->
                        </li>
                        <li>
                            <button data-reveal-trigger="promotion-2-10" class="tag">Livraison immédiate<sup>(1)</sup></button>
                            <!-- [popin] start-->
                            <div data-reveal="promotion-2-10" aria-hidden="true" role="dialog" class="reveal-modal full scroll reduced">
                                <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                                    <p class="heading heading--bordered heading--small"><strong class="heading__title">Mentions legales</strong></p>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Velit veniam natus delectus quam sed, unde iusto nobis voluptas molestiae minima ratione aperiam repudiandae numquam, sint autem eius iste nisi? Nulla.</p>
                                </div>
                            </div>
                            <!-- [popin] end-->
                        </li>
                    </ul>
                </div>
                <div class="squaredImageItem__infos">
                    <div class="squaredImageItem__details">
                        <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                <h3 class="heading__title">Puteaux / 92</h3>
                                <p class="heading__title heading__title--sub">Le Capitole</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="10" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                    </div>
                </div>
            </article>
            <!-- [squaredImageItem] end-->
        </li>
        <li>
            <!-- [squaredImageItem] start-->
            <article class="squaredImageItem false">
                <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                </div>
                <div class="squaredImageItem__infos">
                    <div class="squaredImageItem__details">
                        <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                <h3 class="heading__title">Villeneuve D’Ornon / 33</h3>
                                <p class="heading__title heading__title--sub">Le domaine de testerins</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="11" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                    </div>
                </div>
            </article>
            <!-- [squaredImageItem] end-->
        </li>
        <li>
            <!-- [squaredImageItem] start-->
            <article class="squaredImageItem false">
                <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                </div>
                <div class="squaredImageItem__infos">
                    <div class="squaredImageItem__details">
                        <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                <h3 class="heading__title">Villeneuve D’Ornon / 33</h3>
                                <p class="heading__title heading__title--sub">Le domaine de testerins</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="12" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                    </div>
                </div>
            </article>
            <!-- [squaredImageItem] end-->
        </li>
        <li>
            <!-- [squaredImageItem] start-->
            <article class="squaredImageItem false">
                <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                </div>
                <div class="squaredImageItem__infos">
                    <div class="squaredImageItem__details">
                        <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                <h3 class="heading__title">Villeneuve D’Ornon / 33</h3>
                                <p class="heading__title heading__title--sub">Le domaine de testerins</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="13" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                    </div>
                </div>
            </article>
            <!-- [squaredImageItem] end-->
        </li>
        <li>
            <!-- [squaredImageItem] start-->
            <article class="squaredImageItem false">
                <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                </div>
                <div class="squaredImageItem__infos">
                    <div class="squaredImageItem__details">
                        <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                <h3 class="heading__title">Villeneuve D’Ornon / 33</h3>
                                <p class="heading__title heading__title--sub">Le domaine de testerins</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="14" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                    </div>
                </div>
            </article>
            <!-- [squaredImageItem] end-->
        </li>
        <li>
            <!-- [squaredImageItem] start-->
            <article class="squaredImageItem false">
                <div class="squaredImageItem__img"><a href="#" title="Go to programme page"><img src="test_assets/results-1.jpg" alt="description de la photo"/></a>
                </div>
                <div class="squaredImageItem__infos">
                    <div class="squaredImageItem__details">
                        <div class="heading-favorite"><a href="#" title="Go to programme page" class="heading heading--small">
                                <h3 class="heading__title">Villeneuve D’Ornon / 33</h3>
                                <p class="heading__title heading__title--sub">Le domaine de testerins</p></a><a href="" title="Add item to favorites" data-cookie="offres" data-cookie-add="15" class="btn-icon--only"><span class="icon icon-love"></span></a></div>
                    </div>
                </div>
            </article>
            <!-- [squaredImageItem] end-->
        </li>
    </ul>
</section>
<!-- [Prochainement] end-->