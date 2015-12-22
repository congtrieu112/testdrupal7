<?php
//kpr($content);


if (isset($content['nos_offre'])):
  print render($content['nos_offre']);
endif;
if (isset($content['view_menu_nos_offres'])):
  print render($content['view_menu_nos_offres']);
endif;
?>
<?php
if (isset($content['field_offre_view1'])):
  $result_carousel = isset($content['field_offre_view1'][0]['#view']->result) ? $content['field_offre_view1'][0]['#view']->result : '';
  if ($result_carousel):
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
  <?php endif; ?>
<?php endif; ?>
<?php
if (isset($content['field_offre_view2'])):
  $result = isset($content['field_offre_view2'][0]['#view']->result) ? $content['field_offre_view2'][0]['#view']->result : '';
  $terms = kandb_validate_get_ville_has_reference($content['field_offre_view2'][0]['#view_name'], $result);
  if ($result):
    ?>
    <!-- [Prochainement] start-->
    <section id="shortly" class="wrapper section-padding">
        <header class="heading heading--bordered filter-aside">
            <h2 class="heading__title"><?php print $content['field_offre_title2'][0]['#markup']; ?></h2>
            <form class="filter">
                <label for="offersFilter" class="filter__label"><?php print t('Trier par'); ?></label>
                <select id="offersFilter" data-app-select data-app-filter="prochainement" name="offersFilter" class="filter__select">
                    <option value="">-</option>
                    <?php
                    if ($terms):
                      foreach ($terms as $key => $term) :
                        ?>
                        <option value="<?php print $key; ?>"><?php print $term; ?></option>
                        <?php
                      endforeach;
                    endif;
                    ?>
                </select>
            </form>
        </header>
        <?php print render($content['field_offre_view2']); ?>
    </section>
    <!-- [Prochainement] end-->
  <?php endif; ?>
<?php endif; ?>