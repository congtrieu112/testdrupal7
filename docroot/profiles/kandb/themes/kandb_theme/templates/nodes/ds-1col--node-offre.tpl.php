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
  $terms = array();
  foreach($result as $res){
    if(isset($res->field_field_avant_premiere_ville[0]['raw']) && !empty($res->field_field_avant_premiere_ville[0]['raw'])){
      $terms[$res->field_field_avant_premiere_ville[0]['raw']['taxonomy_term']->name] = $res->field_field_avant_premiere_ville[0]['raw']['taxonomy_term']->tid;
    }
  }
  ksort($terms);


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
                      foreach ($terms as $name => $id) :
                        ?>
                        <option value="<?php print $id; ?>"><?php print $name; ?></option>
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
