<?php
if (isset($content['nos_offre'])):
  print render($content['nos_offre']);
endif;
if (isset($content['view_menu_nos_offres'])):
  print render($content['view_menu_nos_offres']);
endif;
?>
<?php if (isset($content['field_offre_view1'])): ?>
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
<?php endif; ?>
<?php if (isset($content['field_offre_view2'])): ?>
  <!-- [Prochainement] start-->
  <section id="shortly" class="wrapper section-padding">
      <header class="heading heading--bordered filter-aside">
          <h2 class="heading__title"><?php print $content['field_offre_title2'][0]['#markup']; ?></h2>
      </header>
      <?php print render($content['field_offre_view2']); ?>
  </section>
  <!-- [Prochainement] end-->
<?php endif; ?>