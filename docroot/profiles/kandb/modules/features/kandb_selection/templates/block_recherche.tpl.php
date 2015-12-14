<?php
/**
 * @file
 * Template file for search block of my selection
 *
 * Receive :
 * $recherches
 */
?>
<?php if (!empty($recherches)): ?>

  <!-- [mySelections: searches] start-->
  <section class="bg-lightGrey section-padding">
    <div class="wrapper">
      <h2 class="heading heading--bordered">
        <div class="heading__title">Mes recherches sauvegardées</div>
      </h2>
    </div>
    <div class="wrapper--narrow">
      <ul data-seemore-list="searches" class="searches">
        <?php foreach ($recherches as $url_recherche): ?>
          <li data-selection-item="data-selection-item" class="search">
            <div class="search__desc">
              <div class="search__name">Marseille / 13</div>
              <div class="search__type">Appartement</div>
            </div>
            <ul class="search__options">
              <li>Max. 300.000€</li>
              <li>Min. 40m</li>
              <li>2/3 pièces</li>
              <li>Terrase / parking</li>
            </ul>
            <div class="search__tools"><a href="#" title="lancer cette recherche" class="btn-primary btn-rounded btn-icon search__tools__exec"><span class="button__content"><span class="icon icon-search"></span>Rechercher</span></a>
              <button data-cookie="offres" data-cookie-remove="5" data-cookie-callback="removeSelection" class="display-status display-status--suppr search__tools__remove"><span class="show-for-sr">Supprimer le programme de vos sélections</span></button>
            </div>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
    <!-- [seeMore] start-->
    <div data-seemore="searches" data-seemore-nbr="5" class="voir-plus">
      <button class="btn-primary btn-rounded">Voir plus<span class="icon icon-arrow down"></span></button>
    </div>
    <!-- [seeMore] end-->
  </section>

<?php endif; ?>
