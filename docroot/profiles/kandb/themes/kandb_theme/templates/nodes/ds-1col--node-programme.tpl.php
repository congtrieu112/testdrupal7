<?php
$path_img = kandb_theme_get_path('test_assets', 'kandb_theme');
//get link file Plaquette commerciale
$file_plaquette_commerciale = '';
if (isset($content['field_plaquette_commerciale']['#object']->field_plaquette_commerciale['und'][0]['uri'])) {
$file_plaquette_commerciale = $content['field_plaquette_commerciale']['#object']->field_plaquette_commerciale['und'][0]['uri'];
}
//get link file fiche reseignement
$file_fiche_renseignement = '';
if (isset($content['field_fiche_renseignement']['#object']->field_fiche_renseignement['und'][0]['uri'])) {
$file_fiche_renseignement = $content['field_fiche_renseignement']['#object']->field_fiche_renseignement['und'][0]['uri'];
}
//get link file Kit fiscal
$file_kit_fiscal = '';
if (isset($content['field_kit_fiscal']['#object']->field_kit_fiscal['und'][0]['uri'])) {
$file_kit_fiscal = $content['field_kit_fiscal']['#object']->field_kit_fiscal['und'][0]['uri'];
}//get link file Plan du bâtiment
$file_plan_batiment = '';
if (isset($content['field_plan_batiment']['#object']->field_plan_batiment['und'][0]['uri'])) {
$file_plan_batiment = $content['field_plan_batiment']['#object']->field_plan_batiment['und'][0]['uri'];
}
//get link zip file
$addMore = '_';
$path_args = explode('/', current_path());
$node = node_load($path_args[1]);
$nid = $node->nid;
$title = $node->title;
$path = file_create_url('public://');
$real_path = drupal_realpath('public://');
$fileName = 'Programme' . $addMore . preg_replace('@[^a-z0-9-]+@', '-', strtolower($node->title)) . '.zip';
if (file_exists($real_path . '/Programme/archive/' . $nid . '/')) {
$filePath = $real_path . '/Programme/archive/' . $nid . '/' . $fileName;
$linkfile = $path . 'Programme/archive/' . $nid . '/' . $fileName;
if ($filePath) {
if (file_exists($filePath)) {
$link_to_zip = $linkfile;
}
}
}
?>
<!-- [programParcel] start-->
<section class="section-padding bg-lightGrey">
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h2 class="heading__title">Découvrir les logements</h2>
        </header>
    </div>
    <!-- [carousel] start-->
    <div data-slick="{&quot;slidesToShow&quot;: 1, &quot;slidesToScroll&quot;: 1}" class="slick-slider__item-1 programParcel">
        <div class="unwrap">
            <article class="programParcelItem">
                <figure>
                    <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img ?>programParcel-small.jpg, (small)], [<?php print $path_img ?>programParcel-medium.jpg, (large)]"/>
                    <noscript><img src="<?php print $path_img ?>programParcel-medium.jpg" alt="test"/></noscript>
                    <!-- [Responsive img] end-->
                </figure>
                <div class="programParcelItem__content">
                    <h3 class="programParcelItem__heading">5 appartements de 3/4 pièces disponibles</h3>
                    <div class="programParcelItem__prices">
                        <p><span>À partir de 54&nbsp;000&nbsp;€</span><span class="tva">TVA 5,5%</span></p>
                        <p><span>À partir de 1&nbsp;684&nbsp;000&nbsp;€</span><span class="tva tva--high">TVA 20%</span></p>
                    </div>
                </div>
            </article>
            <article class="programParcelItem">
                <figure>
                    <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img ?>programParcel-small.jpg, (small)], [<?php print $path_img ?>programParcel-medium.jpg, (large)]"/>
                    <noscript><img src="<?php print $path_img ?>programParcel-medium.jpg" alt="test"/></noscript>
                    <!-- [Responsive img] end-->
                </figure>
                <div class="programParcelItem__content">
                    <h3 class="programParcelItem__heading">5 appartements de 3/4 pièces disponibles</h3>
                    <div class="programParcelItem__prices">
                        <p><span>À partir de 54&nbsp;000&nbsp;€</span><span class="tva">TVA 5,5%</span></p>
                        <p><span>À partir de 1&nbsp;684&nbsp;000&nbsp;€</span><span class="tva tva--high">TVA 20%</span></p>
                    </div>
                </div>
            </article>
            <article class="programParcelItem">
                <figure>
                    <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img ?>programParcel-small.jpg, (small)], [<?php print $path_img ?>programParcel-medium.jpg, (large)]"/>
                    <noscript><img src="<?php print $path_img ?>programParcel-medium.jpg" alt="test"/></noscript>
                    <!-- [Responsive img] end-->
                </figure>
                <div class="programParcelItem__content">
                    <h3 class="programParcelItem__heading">5 appartements de 3/4 pièces disponibles</h3>
                    <div class="programParcelItem__prices">
                        <p><span>À partir de 54&nbsp;000&nbsp;€</span><span class="tva">TVA 5,5%</span></p>
                        <p><span>À partir de 1&nbsp;684&nbsp;000&nbsp;€</span><span class="tva tva--high">TVA 20%</span></p>
                    </div>
                </div>
            </article>
            <article class="programParcelItem">
                <figure>
                    <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img ?>programParcel-small.jpg, (small)], [<?php print $path_img ?>programParcel-medium.jpg, (large)]"/>
                    <noscript><img src="<?php print $path_img ?>programParcel-medium.jpg" alt="test"/></noscript>
                    <!-- [Responsive img] end-->
                </figure>
                <div class="programParcelItem__content">
                    <h3 class="programParcelItem__heading">5 appartements de 3/4 pièces disponibles</h3>
                    <div class="programParcelItem__prices">
                        <p><span>À partir de 54&nbsp;000&nbsp;€</span><span class="tva">TVA 5,5%</span></p>
                        <p><span>À partir de 1&nbsp;684&nbsp;000&nbsp;€</span><span class="tva tva--high">TVA 20%</span></p>
                    </div>
                </div>
            </article>
            <article class="programParcelItem">
                <figure>
                    <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img ?>programParcel-small.jpg, (small)], [<?php print $path_img ?>programParcel-medium.jpg, (large)]"/>
                    <noscript><img src="<?php print $path_img ?>programParcel-medium.jpg" alt="test"/></noscript>
                    <!-- [Responsive img] end-->
                </figure>
                <div class="programParcelItem__content">
                    <h3 class="programParcelItem__heading">5 appartements de 3/4 pièces disponibles</h3>
                    <div class="programParcelItem__prices">
                        <p><span>À partir de 54&nbsp;000&nbsp;€</span><span class="tva">TVA 5,5%</span></p>
                        <p><span>À partir de 1&nbsp;684&nbsp;000&nbsp;€</span><span class="tva tva--high">TVA 20%</span></p>
                    </div>
                </div>
            </article>
            <article class="programParcelItem">
                <figure>
                    <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img ?>programParcel-small.jpg, (small)], [<?php print $path_img ?>programParcel-medium.jpg, (large)]"/>
                    <noscript><img src="<?php print $path_img ?>programParcel-medium.jpg" alt="test"/></noscript>
                    <!-- [Responsive img] end-->
                </figure>
                <div class="programParcelItem__content">
                    <h3 class="programParcelItem__heading">5 appartements de 3/4 pièces disponibles</h3>
                    <div class="programParcelItem__prices">
                        <p><span>À partir de 54&nbsp;000&nbsp;€</span><span class="tva">TVA 5,5%</span></p>
                        <p><span>À partir de 1&nbsp;684&nbsp;000&nbsp;€</span><span class="tva tva--high">TVA 20%</span></p>
                    </div>
                </div>
            </article>
        </div>
        <div class="unwrap">
            <article class="programParcelItem">
                <figure>
                    <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img ?>programParcel-small.jpg, (small)], [<?php print $path_img ?>programParcel-medium.jpg, (large)]"/>
                    <noscript><img src="<?php print $path_img ?>programParcel-medium.jpg" alt="test"/></noscript>
                    <!-- [Responsive img] end-->
                </figure>
                <div class="programParcelItem__content">
                    <h3 class="programParcelItem__heading">5 appartements de 3/4 pièces disponibles</h3>
                    <div class="programParcelItem__prices">
                        <p><span>À partir de 54&nbsp;000&nbsp;€</span><span class="tva">TVA 5,5%</span></p>
                        <p><span>À partir de 1&nbsp;684&nbsp;000&nbsp;€</span><span class="tva tva--high">TVA 20%</span></p>
                    </div>
                </div>
            </article>
            <article class="programParcelItem">
                <figure>
                    <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print $path_img ?>programParcel-small.jpg, (small)], [<?php print $path_img ?>programParcel-medium.jpg, (large)]"/>
                    <noscript><img src="<?php print $path_img ?>programParcel-medium.jpg" alt="test"/></noscript>
                    <!-- [Responsive img] end-->
                </figure>
                <div class="programParcelItem__content">
                    <h3 class="programParcelItem__heading">5 appartements de 3/4 pièces disponibles</h3>
                    <div class="programParcelItem__prices">
                        <p><span>À partir de 54&nbsp;000&nbsp;€</span><span class="tva">TVA 5,5%</span></p>
                        <p><span>À partir de 1&nbsp;684&nbsp;000&nbsp;€</span><span class="tva tva--high">TVA 20%</span></p>
                    </div>
                </div>
            </article>
        </div>
    </div>
    <!-- [carousel] end-->
</section>
<!-- [programParcel] end-->

<!-- [3rd party: video-de-quartier] start-->
<section class="section-padding">
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h2 class="heading__title">Un arrondissement</h2>
            <p class="heading__title heading__title--sub">à l’image des familles</p>
        </header>
    </div>
    <div class="swapItem">
        <div class="swapItem__2">
            <div class="wrapper--medium-up">
                <div class="iframe iframe--video-de-quartier">
                    <iframe src="" data-src="http://widgets.habiteo.com/video-de-quartier?id=2G90uqxgE640JojGXGTdL1&amp;key=5lxfgCv4mKCknnPCWEsIYl" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
                </div>
            </div>
        </div>
        <div class="swapItem__1">
            <div class="wrapper">
                <div class="heading heading--small text-center">
                    <h3 class="heading__title">Batignolles, la renaissance d’un quartier</h3>
                </div>
            </div>
        </div>
        <div class="swapItem__3">
            <div class="wrapper">
                <div class="content-centered">
                    <P>Le quartier des Batignolles a conservé des allures de village avec ses petits commerces, ses galeries d'art et ses nombreux espaces verts qui en font l'un des plus charmants de Paris.</P>
                </div>
            </div>
        </div>
    </div>
</section>
<!-- [3rd party: video-de-quartier] start-->
<!-- [programCharacteristics] start-->
<section class="section-padding bg-lightGrey">
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h2 class="heading__title">Prestations du programme</h2>
            <div class="heading__title heading__title--sub">Un immeuble haut-de-gamme et sécurisé</div>
        </header>
    </div>
    <div class="programCharacteristics">
        <!-- Tablet and Desktop navigation-->
        <ul role="tablist" data-slick-nav="data-slick-nav" class="show-for-medium-up programCharacteristics__nav">
            <li><a href="#slide0" data-slick-links="data-slick-links" role="tab" aria-controls="slide0" class="active">Extérieur</a></li>
            <li><a href="#slide1" data-slick-links="data-slick-links" role="tab" aria-controls="slide1">Intérieur</a></li>
            <li><a href="#slide2" data-slick-links="data-slick-links" role="tab" aria-controls="slide2">Services</a></li>
            <li><a href="#slide3" data-slick-links="data-slick-links" role="tab" aria-controls="slide03">RT 2012</a></li>
        </ul>
        <ul data-slick="data-slick" data-slick-responsive="medium" data-app-accordion="data-app-accordion" data-app-accordion-responsive="small-only" class="accordion fullwidth">
            <li id="slide0">
                <!-- mobile accordion trigger--><a href="#slide0" data-app-accordion-link="data-app-accordion-link" role="tab" class="show-for-small-only accordion__link active">Extérieur<span class="display-status"></span></a>
                <!-- [programCharacteristicsItem] start-->
                <!-- image need to have 2 formats:
                - small: 560 x 230 (HEAVY compression!!!)
                - medium: 1380 x 400
                -->
                <article data-app-accordion-content="data-app-accordion-content" class="programCharacteristicsItem">
                    <div class="programCharacteristicsItem__img">
                        <!-- [Responsive img] start--><img alt="Photo extérieure" data-interchange="[<?php print $path_img ?>programCharacteristics-small.jpg, (small)], [<?php print $path_img ?>programCharacteristics-medium.jpg, (medium)]"/>
                        <noscript><img src="<?php print $path_img ?>programCharacteristics-medium.jpg" alt="Photo extérieure"/></noscript>
                        <!-- [Responsive img] end-->
                    </div>
                    <div class="programCharacteristicsItem__content">
                        <h3 class="heading--tiny">Une vue somptueuse sur la ville</h3>
                        <p>Du studio au 5 pièces, tous sans exception possèdent un prolongement extérieur, qu'il s'agisse d'un agréable balcon sur la ville, du parc ou bien d'une magnifique terrasse prête à accueillir un jardin suspendu. Partout la lumière est chez elle, pénétrant par les larges baies, et ce d'autant plus dans les appartements traversants.</p>
                    </div>
                </article>
                <!-- [programCharacteristicsItem] end-->
            </li>
            <li id="slide1">
                <!-- mobile accordion trigger--><a href="#slide1" data-app-accordion-link="data-app-accordion-link" role="tab" class="show-for-small-only accordion__link">Intérieur<span class="display-status"></span></a>
                <!-- [programCharacteristicsItem] start-->
                <!-- image need to have 2 formats:
                - small: 560 x 230 (HEAVY compression!!!)
                - medium: 1380 x 400
                -->
                <article data-app-accordion-content="data-app-accordion-content" class="programCharacteristicsItem">
                    <div class="programCharacteristicsItem__img">
                        <!-- [Responsive img] start--><img alt="Photo extérieure" data-interchange="[<?php print $path_img ?>programCharacteristics-small.jpg, (small)], [<?php print $path_img ?>programCharacteristics-medium.jpg, (medium)]"/>
                        <noscript><img src="<?php print $path_img ?>programCharacteristics-medium.jpg" alt="Photo extérieure"/></noscript>
                        <!-- [Responsive img] end-->
                    </div>
                    <div class="programCharacteristicsItem__content">
                        <h3 class="heading--tiny">Une vue somptueuse sur la ville</h3>
                        <p>Du studio au 5 pièces, tous sans exception possèdent un prolongement extérieur, qu'il s'agisse d'un agréable balcon sur la ville, du parc ou bien d'une magnifique terrasse prête à accueillir un jardin suspendu. Partout la lumière est chez elle, pénétrant par les larges baies, et ce d'autant plus dans les appartements traversants.</p>
                    </div>
                </article>
                <!-- [programCharacteristicsItem] end-->
            </li>
            <li id="slide2">
                <!-- mobile accordion trigger--><a href="#slide2" data-app-accordion-link="data-app-accordion-link" role="tab" class="show-for-small-only accordion__link">Services<span class="display-status"></span></a>
                <!-- [programCharacteristicsItem] start-->
                <!-- image need to have 2 formats:
                - small: 560 x 230 (HEAVY compression!!!)
                - medium: 1380 x 400
                -->
                <article data-app-accordion-content="data-app-accordion-content" class="programCharacteristicsItem">
                    <div class="programCharacteristicsItem__img">
                        <!-- [Responsive img] start--><img alt="Photo extérieure" data-interchange="[<?php print $path_img ?>programCharacteristics-small.jpg, (small)], [<?php print $path_img ?>programCharacteristics-medium.jpg, (medium)]"/>
                        <noscript><img src="<?php print $path_img ?>programCharacteristics-medium.jpg" alt="Photo extérieure"/></noscript>
                        <!-- [Responsive img] end-->
                    </div>
                    <div class="programCharacteristicsItem__content">
                        <h3 class="heading--tiny">Une vue somptueuse sur la ville</h3>
                        <p>Du studio au 5 pièces, tous sans exception possèdent un prolongement extérieur, qu'il s'agisse d'un agréable balcon sur la ville, du parc ou bien d'une magnifique terrasse prête à accueillir un jardin suspendu. Partout la lumière est chez elle, pénétrant par les larges baies, et ce d'autant plus dans les appartements traversants.</p>
                    </div>
                </article>
                <!-- [programCharacteristicsItem] end-->
            </li>
            <li id="slide3">
                <!-- mobile accordion trigger--><a href="#slide3" data-app-accordion-link="data-app-accordion-link" role="tab" class="show-for-small-only accordion__link">RT 2012<span class="display-status"></span></a>
                <!-- [programCharacteristicsItem] start-->
                <!-- image need to have 2 formats:
                - small: 560 x 230 (HEAVY compression!!!)
                - medium: 1380 x 400
                -->
                <article data-app-accordion-content="data-app-accordion-content" class="programCharacteristicsItem">
                    <div class="programCharacteristicsItem__img">
                        <!-- [Responsive img] start--><img alt="Photo extérieure" data-interchange="[<?php print $path_img ?>programCharacteristics-small.jpg, (small)], [<?php print $path_img ?>programCharacteristics-medium.jpg, (medium)]"/>
                        <noscript><img src="<?php print $path_img ?>programCharacteristics-medium.jpg" alt="Photo extérieure"/></noscript>
                        <!-- [Responsive img] end-->
                    </div>
                    <div class="programCharacteristicsItem__content">
                        <h3 class="heading--tiny">Une vue somptueuse sur la ville</h3>
                        <p>Du studio au 5 pièces, tous sans exception possèdent un prolongement extérieur, qu'il s'agisse d'un agréable balcon sur la ville, du parc ou bien d'une magnifique terrasse prête à accueillir un jardin suspendu. Partout la lumière est chez elle, pénétrant par les larges baies, et ce d'autant plus dans les appartements traversants.</p>
                    </div>
                </article>
                <!-- [programCharacteristicsItem] end-->
            </li>
        </ul>
    </div>
</section>
<!-- [programCharacteristics] end-->

<!-- [3rd party: vue-generale] start-->
<section class="section-padding show-for-medium-up">
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h2 class="heading__title">Découvrez la modélisation 3D</h2>
        </header>
        <div class="iframe iframe--vue-generale">
            <iframe src="" data-src="http://widgets.habiteo.com/vue-generale?id=2G90uqxgE640JojGXGTdL1&amp;key=5lxfgCv4mKCknnPCWEsIYl" frameborder="0" allowfullscreen="allowfullscreen" allowtransparency="true" scrolling="no" class="iframe__content"></iframe>
        </div>
        <div class="content-centered">
            <P>Le quartier des Batignolles a conservé des allures de village avec ses petits commerces, ses galeries d'art et ses nombreux espaces verts qui en font l'un des plus charmants de Paris.</P>
        </div>
    </div>
</section>
<!-- [3rd party: vue-generale] start-->
<!-- [programDocumentDownload] start-->
<section class="section-padding">
    <div class="wrapper">
        <div class="programDocumentDownload">
            <?php
            $nocontent = 'data-reveal-id="downloadInformationForm"';
            ?>
            <div class="programDocumentDownload__heading">
                <header class="heading">
                    <h2 class="heading__title">Documents <br>téléchargeables</h2>
                </header>
                <a  href="<?php if (isset($link_to_zip) && $link_to_zip) print $link_to_zip; ?>">
                    <button <?php if (!isset($link_to_zip) ||!$link_to_zip) print $nocontent; ?> class="btn-primary btn-rounded hide-for-small-only">
                        Tout télécharger (.zip)</button></a>
            </div>
            <div class="programDocumentDownload__items">
                <ul class="row">
                    <?php if($file_plaquette_commerciale): ?>
                    <li class="programDocumentDownload__items__item"><a href="<?php print file_create_url($file_plaquette_commerciale) ?>" <?php if (!$file_plaquette_commerciale) print $nocontent; ?> ><span class="icon icon-flyer"></span>
                            <div class="heading heading--small">
                                <div class="heading__title">Plaquette commerciale</div>
                            </div></a>
                    </li>
                    <?php endif; ?>
                    <?php if($file_fiche_renseignement): ?>
                    <li class="programDocumentDownload__items__item"><a href="<?php print file_create_url($file_fiche_renseignement) ?>" <?php if (!$file_fiche_renseignement) print $nocontent; ?>><span class="icon icon-file"></span>
                            <div class="heading heading--small">
                                <div class="heading__title">Kit juridique</div>
                            </div></a>
                    </li>
                    <?php endif; ?>
                    <?php if($file_kit_fiscal): ?>
                    <li class="programDocumentDownload__items__item"><a href="<?php print file_create_url($file_kit_fiscal) ?>" <?php if (!$file_kit_fiscal) print $nocontent; ?>><span class="icon icon-calculator"></span>
                            <div class="heading heading--small">
                                <div class="heading__title">Kit fiscal</div>
                            </div></a>
                    </li>
                    <?php endif; ?>
                    <?php if($file_plan_batiment): ?>
                    <li class="programDocumentDownload__items__item"><a href="<?php print file_create_url($file_plan_batiment) ?>" <?php if (!$file_plan_batiment) print $nocontent; ?>><span class="icon icon-plan"></span>
                            <div class="heading heading--small">
                                <div class="heading__title">Plan du bâtiment</div>
                            </div></a>
                    </li>
                    <?php endif; ?>
                </ul>
            </div>
            <div class="btn-wrapper btn-wrapper--center show-for-small-only">
                <a  href="<?php if (isset($link_to_zip) && $link_to_zip) print $link_to_zip; ?>"><button <?php if (!isset($link_to_zip) ||!$link_to_zip) print $nocontent; ?> class="btn-primary btn-rounded btn-download">Tout télécharger (.zip)</button></a>
            </div>
            <!-- [popin] start-->
            <div id="downloadInformationForm" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
                <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
                    <div class="programDocumentDownload__content">
                        <p>Content Update later</p>
                    </div>
                </div>
            </div>
            <!-- [popin] end-->
        </div>
    </div>
</section>
<!-- [programDocumentDownload] end-->

<!-- [offers] start-->
<section class="section-padding bg-lightGrey">
    <div class="wrapper">
        <h2 class="heading--tiny">Les programmes les plus proches</h2>
        <!-- [carousel] start-->
        <div data-slick="{&quot;slidesToShow&quot;: 3, &quot;slidesToScroll&quot;: 3}" class="slick-slider__item-3">
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/>
                        <ul class="squaredImageItem__img__tags">
                            <li>
                                <div class="tag tag--important">Plus que deux T3 disponibles</div>
                            </li>
                            <li>
                                <div class="tag">TVA 7%<sup>(2)</sup></div>
                            </li>
                            <li>
                                <div class="tag">Livraison immédiate<sup>(1)</sup></div>
                            </li>
                        </ul></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
            <div class="slick-slider__item">
                <!-- [squaredImageItem] start-->
                <article class="squaredImageItem squaredImageItem--stacked false"><a href="#" title="Go to programme page" class="squaredImageItem__img"><img src="<?php print $path_img ?>results-1.jpg" alt="description de la photo"/></a>
                    <div class="squaredImageItem__infos">
                        <div class="squaredImageItem__details"><a href="#" title="Go to programme page" class="heading heading--small">
                                <p class="heading__title">Appartement</p>
                                <p class="heading__title heading__title--sub">2 pièces - 43,2&nbsp;m2</p></a>
                        </div>
                    </div>
                </article>
                <!-- [squaredImageItem] end-->
            </div>
        </div>
        <!-- [carousel] end-->

        <div class="btn-wrapper btn-wrapper--center"><a href="#" class="btn-rounded btn-primary">Voir toutes nos offres<span class="icon icon-arrow"></span></a>
        </div>
    </div>
</section>
<!-- [offers] end-->
<!-- [contactUs complete] start-->
<!-- [contactUs complete] end-->