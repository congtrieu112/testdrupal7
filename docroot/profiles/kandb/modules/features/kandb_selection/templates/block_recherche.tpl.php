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
          <?php foreach ($recherches as $recherche): ?>
            <li data-selection-item="data-selection-item" class="search">
              <div class="search__desc">
                <ul class="search__type">
                  <li><?php print $recherche['place'][0]; ?></li>
                  <?php if(isset($recherche['field_type']) && !empty($recherche['field_type'])) : ?>
                    <li><?php print implode('</li><li>', $recherche['field_type']); ?></li>
                  <?php endif; ?>
                </ul>
                <?php
                  $filter_pattern = array(
                    'prix_min' => 'Min. !value€',
                    'prix_max' => 'Max. !value€',
                    'field_nb_pieces' => '!value',
                    'field_superficie' => 'Min. !valuem²',
                    'field_caracteristique' => '!value',
                  );
                  $filters = array_intersect_key($recherche, $filter_pattern);
                ?>
                <?php if (!empty($filters)) : ?>
                  <ul class="search__options">
                    <?php foreach ($filters as $field => $array_of_value) : ?>
                      <?php foreach ($array_of_value as $value) : ?>
                        <li><?php print str_replace('!value', $value, $filter_pattern[$field]); ?></li>
                      <?php endforeach; ?>
                    <?php endforeach; ?>
                  </ul>
                <?php endif; ?>
              </div>
              <div class="search__tools"><a href="<?php print $recherche['url']; ?>" title="lancer cette recherche" class="btn-primary btn-rounded btn-icon search__tools__exec"><span class="button__content"><span class="icon icon-search"></span>Rechercher</span></a>
                <button data-cookie="recherches" data-cookie-remove="<?php print $recherche['url']; ?>" data-cookie-callback="removeSelection" class="display-status display-status--suppr search__tools__remove"><span class="show-for-sr">Supprimer le programme de vos sélections</span></button>
              </div>
            </li>
          <?php endforeach; ?>
        </ul>
      </div>

      <?php if (count($recherches) > 5): ?>
        <!-- [seeMore] start-->
        <div data-seemore="searches" data-seemore-nbr="5" class="voir-plus">
          <button class="btn-primary btn-rounded">Voir plus<span class="icon icon-arrow down"></span></button>
        </div>
        <!-- [seeMore] end-->
      <?php endif; ?>

  </section>
<?php else: ?>
  <section class="section-padding bg-lightGrey">
    <div class="wrapper">
      <header class="heading heading--bordered">
        <h1 class="heading__title">Mes recherches sauvegardées</h1>
      </header>
      <div class="noSelection bg-white">
        <div class="heading--small">
          <h2 class="heading__title">Vous n'avez enregistré aucune recherche</h2>
          <p class="heading__title heading__title--sub">Trouvez dès maintenant les biens qui vous correspondent</p>
        </div><a href="/<?php print URL_SEARCH_B2C ?>" title="Je trouve mon bien" class="btn-primary btn-rounded">Je trouve mon bien</a>
      </div>
    </div>
  </section>
<?php endif; ?>
