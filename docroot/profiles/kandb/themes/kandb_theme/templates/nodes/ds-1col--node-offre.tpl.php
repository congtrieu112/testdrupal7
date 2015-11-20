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
            <h2 class="heading__title"><?php print $node->title; ?></h2>
            <p class="heading__title heading__title--sub heading__title--limit"><?php print $content['field_offre_subtitle'][0]['#markup']; ?></p>
        </header>
        <!-- [carousel] start-->
        <?php
        print render($content['field_offre_view1']);
        ?>
        <!-- [carousel] end-->
    </div>
</section>
<!-- [Avant-premiere] end-->
<!-- [Prochainement] start-->
<section id="shortly" class="wrapper section-padding">
    <header class="heading heading--bordered filter-aside">
        <h2 class="heading__title"><?php print $content['field_offre_title2'][0]['#markup']; ?></h2>
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
    <?php print render($content['field_offre_view2']); ?>
</section>
<!-- [Prochainement] end-->