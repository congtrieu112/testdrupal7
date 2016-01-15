<?php if ($selection_programme_bien_avant_premiere): ?>
  <?php print $selection_programme_bien_avant_premiere; ?>
<?php else: ?>
  <section class="section-padding bg-lightGrey">
    <div class="wrapper">
      <header class="heading heading--bordered">
        <h1 class="heading__title">Mes sélections</h1>
      </header>
      <div class="noSelection bg-white">
        <div class="heading--small">
          <h2 class="heading__title">Vous n'avez enregistré aucun programme</h2>
          <p class="heading__title heading__title--sub">Trouvez dès maintenant les biens qui vous correspondent</p>
        </div><a href="/<?php print URL_SEARCH_B2C ?>" title="Je trouve mon bien" class="btn-primary btn-rounded">Je trouve mon bien</a>
      </div>
    </div>
  </section>
<?php endif; ?>

<?php if ($selection_article): ?>
  <?php print $selection_article; ?>
<?php else: ?>
<section class="section-padding bg-lightGrey">
  <div class="wrapper">
    <header class="heading heading--bordered">
      <h1 class="heading__title">Mes articles</h1>
    </header>
    <div class="noSelection bg-white">
      <div class="heading--small">
        <h2 class="heading__title">Vous n'avez enregistré aucun article</h2>
      </div>
    </div>
  </div>
</section>
<?php endif; ?>
<?php print $recherche; ?>
