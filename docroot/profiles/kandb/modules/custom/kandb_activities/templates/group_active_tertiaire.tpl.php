<?php
print theme('group_activities_header');
?>
<section class="section-padding activities">
    <div class="wrapper">
        <?php
        $title = variable_get('bloc_edito_title');
        $subtitle = variable_get('bloc_edito_sub_title');
        if ($title || $subtitle) :
          ?>
          <header class="heading heading--bordered">
              <h1 class="heading__title"><?php print $title; ?></h1>
              <p class="heading__title heading__title--sub"><?php print $subtitle; ?></p>
          </header>
        <?php endif; ?>
        <?php
        $bloc_edito_description = variable_get('bloc_edito_description', array('value' => '', 'format' => NULL));
        if ($bloc_edito_description && isset($bloc_edito_description['value'])) :
          ?>
          <div class="heading--small activities__heading">
              <?php
              print $bloc_edito_description['value'];
              ?>
          </div>
        <?php endif; ?>
        <?php
        $edito_kpi_component_image = variable_get('bloc_edito_kpi_item_image');
        $edito_kpi_component_image = $edito_kpi_component_image ? file_load($edito_kpi_component_image) : '';
        $edito_kpi_component_image = (isset($edito_kpi_component_image->uri) AND $edito_kpi_component_image->uri) ? image_style_url('dossier_medium_850x345', $edito_kpi_component_image->uri) : '';
        ?>
        <?php if ($edito_kpi_component_image) : ?>
          <div class="graphicPresentation__list">
              <div class="graphicPresentation__item columns text-center">
                  <div class="graphicPresentation__item__img">
                      <img alt="<?php print $edito_kpi_component_image; ?>" data-interchange="[<?php print $edito_kpi_component_image; ?>, (small)], [<?php print $edito_kpi_component_image; ?>, (large)]"/>
                      <noscript><img src="<?php print $edito_kpi_component_image; ?>" alt="<?php print $edito_kpi_component_image; ?>"/></noscript>
                  </div>
              </div>
          </div>
        <?php endif; ?>
    </div>
</section>
<!-- bloc Bureau -->
<section class="section-padding activities">
    <div class="wrapper">
        <?php
        $title = variable_get('bloc_bureau_title');
        $subtitle = variable_get('bloc_bureau_sub_title');
        if ($title || $subtitle) :
          ?>
          <header class="heading heading--bordered">
              <h1 class="heading__title"><?php print $title; ?></h1>
              <p class="heading__title heading__title--sub"><?php print $subtitle; ?></p>
          </header>
        <?php endif; ?>
        <div class="heading--small activities__heading">
            <?php
            $bloc_bureau_description = variable_get('bloc_bureau_description', array('value' => '', 'format' => NULL));
            print $bloc_bureau_description['value'];
            ?>
        </div>
        <!-- -->
        <?php
        $bureau_kpi_component_arr = $last_bureau_kpi_component_arr = array();
        for ($i = 1; $i <= BLOC_BUREAU_KPI_ITEMS_NUM; $i++) :
          $bureau_component_title = variable_get('bloc_bureau_kpi_component_title_' . $i);
          $bureau_kpi_component_sub_title = variable_get('bloc_bureau_kpi_component_sub_title_' . $i);
          $bureau_kpi_component_image = variable_get('bloc_bureau_kpi_component_image_' . $i);
          $bureau_kpi_component_image = $bureau_kpi_component_image ? file_load($bureau_kpi_component_image) : '';
          $bureau_kpi_component_image = (isset($bureau_kpi_component_image->uri) AND $bureau_kpi_component_image->uri) ? image_style_url('kpi_component_580_x_296', $bureau_kpi_component_image->uri) : '';
          if ($bureau_component_title OR $bureau_kpi_component_sub_title OR $bureau_kpi_component_image) :
            $bureau_kpi_component_arr[] = array(
              'bureau_kpi_component_title' => $bureau_component_title,
              'bureau_kpi_component_sub_title' => $bureau_kpi_component_sub_title,
              'bureau_kpi_component_image' => $bureau_kpi_component_image,
            );
          endif;
        endfor;
        if (count($bureau_kpi_component_arr) % 2 != 0) :
          $last_bureau_kpi_component_arr = end($bureau_kpi_component_arr);
          array_pop($bureau_kpi_component_arr);
        endif;
        ?>
        <?php if ($bureau_kpi_component_arr OR $last_bureau_kpi_component_arr) : ?>
          <div class="wrapper actionnaireCarnet__listInfor">
              <?php if ($bureau_kpi_component_arr) : ?>
                <div class="graphicPresentation__list">
                    <?php $i = 0; foreach ($bureau_kpi_component_arr as $item) : ?>
                      <?php if ($i % 2 == 0) : ?>
                        <div data-equalizer="" data-equalizer-mq="medium-up" class="graphicPresentation__list">
                      <?php endif; ?>
                        <div class="graphicPresentation__item columns medium-6" data-equalizer-watch="data-equalizer-watch">
                          <h4 class="graphicPresentation__item__heading"><?php print $item['bureau_kpi_component_title']; ?></h4>
                          <p class="desc"><?php print $item['bureau_kpi_component_sub_title']; ?></p>
                          <div class="graphicPresentation__item__img">
                            <!-- [Responsive img] start-->
                              <img alt="<?php print $item['bureau_kpi_component_title']; ?>" data-interchange="[<?php print $item['bureau_kpi_component_image']; ?>, (small)], [<?php print $item['bureau_kpi_component_image']; ?>, (large)]"/>
                              <noscript><img src="<?php print $item['bureau_kpi_component_image']; ?>" alt="<?php print $item['bureau_kpi_component_title']; ?>"/></noscript>
                            <!-- [Responsive img] end-->
                          </div>
                        </div>
                      <?php $i++; if ($i % 2 == 0) : ?>
                        </div>
                      <?php endif; ?>
                    <?php endforeach; ?>
                </div>
              <?php endif; ?>
              <?php if ($last_bureau_kpi_component_arr) : ?>
                <div class="graphicPresentation__list">
                  <div class="graphicPresentation__item columns text-center">
                    <h4 class="graphicPresentation__item__heading"><?php print $last_bureau_kpi_component_arr['bureau_kpi_component_title']; ?></h4>
                    <p class="desc"><?php print $last_bureau_kpi_component_arr['bureau_kpi_component_sub_title']; ?></p>
                    <div class="graphicPresentation__item__img">
                      <!-- [Responsive img] start-->
                      <img alt="<?php print $last_bureau_kpi_component_arr['bureau_kpi_component_title']; ?>" data-interchange="[<?php print $last_bureau_kpi_component_arr['bureau_kpi_component_image']; ?>, (small)], [<?php print $last_bureau_kpi_component_arr['bureau_kpi_component_image']; ?>, (large)]"/>
                      <noscript><img src="<?php print $last_bureau_kpi_component_arr['bureau_kpi_component_image']; ?>" alt="<?php print $last_bureau_kpi_component_arr['bureau_kpi_component_title']; ?>"/></noscript>
                      <!-- [Responsive img] end-->
                    </div>
                  </div>
                </div>
              <?php endif; ?>
          </div>
        <?php endif; ?>
        <!-- -->
        <div class="btn-wrapper">
            <?php
            $text = variable_get('bloc_bureau_cta_text');
            $url = variable_get('bloc_bureau_cta_url');
            if ($text && $url) :
              ?>
              <a href="<?php print $url; ?>" class="btn-rounded btn-primary"><?php print $text; ?></a>
            <?php endif; ?>
        </div>
    </div>
</section>
<!-- bloc Logistique -->
<section class="section-padding activities">
    <div class="wrapper">
        <?php
        $title = variable_get('bloc_logistique_title');
        $subtitle = variable_get('bloc_logistique_sub_title');

        if ($title || $subtitle) :
          ?>
          <header class="heading heading--bordered">
              <h1 class="heading__title"><?php print $title; ?></h1>
              <p class="heading__title heading__title--sub"><?php print $subtitle; ?></p>
          </header>

        <?php endif; ?>
        <div class="heading--small activities__heading">
            <?php
            $bloc_logistique_description = variable_get('bloc_logistique_description', array('value' => '', 'format' => NULL));
            print $bloc_logistique_description['value'];
            ?>
        </div>
        <!-- -->
        <?php
        $logistique_kpi_component_arr = $last_logistique_kpi_component_arr = array();
        for ($i = 1; $i <= BLOC_BUREAU_KPI_ITEMS_NUM; $i++) :
          $logistique_component_title = variable_get('bloc_logistique_kpi_component_title_' . $i);
          $logistique_kpi_component_sub_title = variable_get('bloc_logistique_kpi_component_sub_title_' . $i);
          $logistique_kpi_component_image = variable_get('bloc_logistique_kpi_component_image_' . $i);
          $logistique_kpi_component_image = $logistique_kpi_component_image ? file_load($logistique_kpi_component_image) : '';
          $logistique_kpi_component_image = (isset($logistique_kpi_component_image->uri) AND $logistique_kpi_component_image->uri) ? image_style_url('kpi_component_580_x_296', $logistique_kpi_component_image->uri) : '';
          if ($logistique_component_title OR $logistique_kpi_component_sub_title OR $logistique_kpi_component_image) :
            $logistique_kpi_component_arr[] = array(
              'logistique_kpi_component_title' => $logistique_component_title,
              'logistique_kpi_component_sub_title' => $logistique_kpi_component_sub_title,
              'logistique_kpi_component_image' => $logistique_kpi_component_image,
            );
          endif;
        endfor;
        if (count($logistique_kpi_component_arr) % 2 != 0) :
          $last_logistique_kpi_component_arr = end($logistique_kpi_component_arr);
          array_pop($logistique_kpi_component_arr);
        endif;
        ?>
        <?php if ($logistique_kpi_component_arr OR $last_logistique_kpi_component_arr) : ?>
          <div class="wrapper actionnaireCarnet__listInfor">
              <?php if ($logistique_kpi_component_arr) : ?>
                <div class="graphicPresentation__list">
                    <?php $i = 0; foreach ($logistique_kpi_component_arr as $item) : ?>
                      <?php if ($i % 2 == 0) : ?>
                         <div data-equalizer="" data-equalizer-mq="medium-up" class="graphicPresentation__list">
                      <?php endif; ?>
                         <div class="graphicPresentation__item columns medium-6" data-equalizer-watch="data-equalizer-watch">
                           <h4 class="graphicPresentation__item__heading"><?php print $item['logistique_kpi_component_title']; ?></h4>
                           <p class="desc"><?php print $item['logistique_kpi_component_sub_title']; ?></p>
                           <div class="graphicPresentation__item__img">
                             <!-- [Responsive img] start-->
                              <img alt="<?php print $item['logistique_kpi_component_title']; ?>" data-interchange="[<?php print $item['logistique_kpi_component_image']; ?>, (small)], [<?php print $item['logistique_kpi_component_image']; ?>, (large)]"/>
                              <noscript><img src="<?php print $item['logistique_kpi_component_image']; ?>" alt="<?php print $item['logistique_kpi_component_title']; ?>"/></noscript>
                             <!-- [Responsive img] end-->
                           </div>
                         </div>
                      <?php $i++; if ($i % 2 == 0) : ?>
                         </div>
                      <?php endif; ?>
                    <?php endforeach; ?>
                </div>
              <?php endif; ?>
              <?php if ($last_logistique_kpi_component_arr) : ?>
                <div class="graphicPresentation__list">
                  <div class="graphicPresentation__item columns text-center">
                    <h4 class="graphicPresentation__item__heading"><?php print $last_logistique_kpi_component_arr['logistique_kpi_component_title']; ?></h4>
                    <p class="desc"><?php print $last_logistique_kpi_component_arr['logistique_kpi_component_sub_title']; ?></p>
                    <div class="graphicPresentation__item__img">
                      <!-- [Responsive img] start-->
                      <img alt="<?php print $last_logistique_kpi_component_arr['logistique_kpi_component_title']; ?>" data-interchange="[<?php print $last_logistique_kpi_component_arr['logistique_kpi_component_image']; ?>, (small)], [<?php print $last_logistique_kpi_component_arr['logistique_kpi_component_image']; ?>, (large)]"/>
                      <noscript><img src="<?php print $last_logistique_kpi_component_arr['logistique_kpi_component_image']; ?>" alt="<?php print $last_logistique_kpi_component_arr['logistique_kpi_component_title']; ?>"/></noscript>
                      <!-- [Responsive img] end-->
                    </div>
                  </div>
                </div>
              <?php endif; ?>
          </div>
        <?php endif; ?>
        <!-- -->
        <div class="activities__item">
            <?php
            $logistique_habitat_kpi_component_image = variable_get('bloc_logistique_habitat_image');
            $logistique_habitat_kpi_component_image = $logistique_habitat_kpi_component_image ? file_load($logistique_habitat_kpi_component_image) : '';
            $logistique_habitat_kpi_component_image = (isset($logistique_habitat_kpi_component_image->uri) AND $logistique_habitat_kpi_component_image->uri) ? image_style_url('habitat_img_780x380', $logistique_habitat_kpi_component_image->uri) : '';
            ?>
            <?php if ($logistique_habitat_kpi_component_image) : ?>
              <div class="activities__item__img">
                  <!-- [Responsive img] start-->
                  <img alt="<?php print $logistique_habitat_kpi_component_image; ?>" data-interchange="[<?php print $logistique_habitat_kpi_component_image; ?>, (small)], [<?php print $logistique_habitat_kpi_component_image; ?>, (large)]"/>
                  <noscript><img src="<?php print $logistique_habitat_kpi_component_image; ?>" alt="<?php print $logistique_habitat_kpi_component_image; ?>"/></noscript>
                  <!-- [Responsive img] end-->
              </div>
              <div class="activities__item__infos">
                  <h4 class="activities__item__title"><?php print variable_get('bloc_logistique_habitat_title'); ?></h4>
                  <p class="activities__item__subs"><?php print variable_get('bloc_logistique_habitat_sub_title'); ?></p>
                  <p>
                      <?php
                      $bloc_logistique_habitat_description = variable_get('bloc_logistique_habitat_description');
                      print isset($bloc_logistique_habitat_description['value']) ? $bloc_logistique_habitat_description['value'] : '';
                      ?>
                  </p>
              </div>
            <?php endif; ?>
        </div>
        <div class="btn-wrapper">
          <?php
          $text = variable_get('bloc_logistique_cta_text');
          $url = variable_get('bloc_logistique_cta_url');
          if ($text && $url) :
            ?>
            <a href="<?php print $url; ?>" class="btn-rounded btn-primary"><?php print $text; ?></a>
          <?php endif; ?>
        </div>
    </div>
</section>
<!-- bloc Hôtellerie -->
<section class="section-padding activities">
    <div class="wrapper">
        <?php
        $title = variable_get('bloc_hotell_title');
        $subtitle = variable_get('bloc_hotell_sub_title');
        if ($title || $subtitle) :
          ?>
          <header class="heading heading--bordered">
              <h1 class="heading__title"><?php print $title; ?></h1>
              <p class="heading__title heading__title--sub"><?php print $subtitle; ?></p>
          </header>
        <?php endif; ?>
        <div class="heading--small activities__heading">
            <?php
            $bloc_hotell_description = variable_get('bloc_hotell_description', array('value' => '', 'format' => NULL));
            print $bloc_hotell_description['value'];
            ?>
        </div>
        <!-- -->
        <?php
        $hotell_kpi_component_arr = $last_hotell_kpi_component_arr = array();
        for ($i = 1; $i <= BLOC_BUREAU_KPI_ITEMS_NUM; $i++) :
          $hotell_component_title = variable_get('bloc_hotell_kpi_component_title_' . $i);
          $hotell_kpi_component_sub_title = variable_get('bloc_hotell_kpi_component_sub_title_' . $i);
          $hotell_kpi_component_image = variable_get('bloc_hotell_kpi_component_image_' . $i);
          $hotell_kpi_component_image = $hotell_kpi_component_image ? file_load($hotell_kpi_component_image) : '';
          $hotell_kpi_component_image = (isset($hotell_kpi_component_image->uri) AND $hotell_kpi_component_image->uri) ? image_style_url('kpi_component_580_x_296', $hotell_kpi_component_image->uri) : '';
          if ($hotell_component_title OR $hotell_kpi_component_sub_title OR $hotell_kpi_component_image) :
            $hotell_kpi_component_arr[] = array(
              'hotell_kpi_component_title' => $hotell_component_title,
              'hotell_kpi_component_sub_title' => $hotell_kpi_component_sub_title,
              'hotell_kpi_component_image' => $hotell_kpi_component_image,
            );
          endif;
        endfor;
        if (count($hotell_kpi_component_arr) % 2 != 0) :
          $last_hotell_kpi_component_arr = end($hotell_kpi_component_arr);
          array_pop($hotell_kpi_component_arr);
        endif;
        ?>
        <?php if ($hotell_kpi_component_arr OR $last_hotell_kpi_component_arr) : ?>
          <div class="wrapper actionnaireCarnet__listInfor">
              <?php if ($hotell_kpi_component_arr) : ?>
                <div class="graphicPresentation__list">
                    <?php $i = 0; foreach ($hotell_kpi_component_arr as $item) : ?>
                      <?php if ($i % 2 == 0) : ?>
                        <div data-equalizer="" data-equalizer-mq="medium-up" class="graphicPresentation__list">
                      <?php endif; ?>
                          <div class="graphicPresentation__item columns medium-6" data-equalizer-watch="data-equalizer-watch">
                            <h4 class="graphicPresentation__item__heading"><?php print $item['hotell_kpi_component_title']; ?></h4>
                            <p class="desc"><?php print $item['hotell_kpi_component_sub_title']; ?></p>
                            <div class="graphicPresentation__item__img">
                              <!-- [Responsive img] start-->
                              <img alt="<?php print $item['hotell_kpi_component_title']; ?>" data-interchange="[<?php print $item['hotell_kpi_component_image']; ?>, (small)], [<?php print $item['hotell_kpi_component_image']; ?>, (large)]"/>
                              <noscript><img src="<?php print $item['hotell_kpi_component_image']; ?>" alt="<?php print $item['hotell_kpi_component_title']; ?>"/></noscript>
                              <!-- [Responsive img] end-->
                            </div>
                          </div>
                         <?php $i++; if ($i % 2 == 0) : ?>
                            </div>
                      <?php endif; ?>
                    <?php endforeach; ?>
                </div>
              <?php endif; ?>
              <?php if ($last_hotell_kpi_component_arr) : ?>
                <div class="graphicPresentation__list">
                  <div class="graphicPresentation__item columns text-center">
                    <h4 class="graphicPresentation__item__heading"><?php print $last_hotell_kpi_component_arr['hotell_kpi_component_title']; ?></h4>
                    <p class="desc"><?php print $last_hotell_kpi_component_arr['hotell_kpi_component_sub_title']; ?></p>
                    <div class="graphicPresentation__item__img">
                      <!-- [Responsive img] start-->
                      <img alt="<?php print $last_hotell_kpi_component_arr['hotell_kpi_component_title']; ?>" data-interchange="[<?php print $last_hotell_kpi_component_arr['hotell_kpi_component_image']; ?>, (small)], [<?php print $last_hotell_kpi_component_arr['hotell_kpi_component_image']; ?>, (large)]"/>
                      <noscript><img src="<?php print $last_hotell_kpi_component_arr['hotell_kpi_component_image']; ?>" alt="<?php print $last_hotell_kpi_component_arr['hotell_kpi_component_title']; ?>"/></noscript>
                      <!-- [Responsive img] end-->
                    </div>
                  </div>
                </div>
              <?php endif; ?>
          </div>
        <?php endif; ?>
        <div class="btn-wrapper">
            <?php
            $text = variable_get('bloc_hotell_cta_text');
            $url = variable_get('bloc_hotell_cta_url');
            if ($text && $url) :
              ?>
              <a href="<?php print $url; ?>" class="btn-rounded btn-primary"><?php print $text; ?></a>
            <?php endif; ?>
        </div>
        <!-- -->
    </div>
</section>
<!-- bloc Commercer -->
<section class="section-padding activities">
    <div class="wrapper">
        <?php
        $title = variable_get('bloc_commercer_title');
        $subtitle = variable_get('bloc_commercer_sub_title');
        if ($title || $subtitle) :
          ?>
          <header class="heading heading--bordered">
              <h1 class="heading__title"><?php print $title; ?></h1>
              <p class="heading__title heading__title--sub"><?php print $subtitle; ?></p>
          </header>
        <?php endif; ?>
        <div class="heading--small activities__heading">
            <?php
            $bloc_commercer_description = variable_get('bloc_commercer_description', array('value' => '', 'format' => NULL));
            print $bloc_commercer_description['value'];
            ?>
        </div>
        <!-- -->
        <?php
        $commercer_kpi_component_arr = $last_commercer_kpi_component_arr = array();
        for ($i = 1; $i <= BLOC_BUREAU_KPI_ITEMS_NUM; $i++) :
          $commercer_component_title = variable_get('bloc_commercer_kpi_component_title_' . $i);
          $commercer_kpi_component_sub_title = variable_get('bloc_commercer_kpi_component_sub_title_' . $i);
          $commercer_kpi_component_image = variable_get('bloc_commercer_kpi_component_image_' . $i);
          $commercer_kpi_component_image = $commercer_kpi_component_image ? file_load($commercer_kpi_component_image) : '';
          $commercer_kpi_component_image = (isset($commercer_kpi_component_image->uri) AND $commercer_kpi_component_image->uri) ? image_style_url('kpi_component_580_x_296', $commercer_kpi_component_image->uri) : '';
          if ($commercer_component_title OR $commercer_kpi_component_sub_title OR $commercer_kpi_component_image) :
            $commercer_kpi_component_arr[] = array(
              'commercer_kpi_component_title' => $commercer_component_title,
              'commercer_kpi_component_sub_title' => $commercer_kpi_component_sub_title,
              'commercer_kpi_component_image' => $commercer_kpi_component_image,
            );
          endif;
        endfor;
        if (count($commercer_kpi_component_arr) % 2 != 0) :
          $last_commercer_kpi_component_arr = end($commercer_kpi_component_arr);
          array_pop($commercer_kpi_component_arr);
        endif;
        ?>
        <?php if ($commercer_kpi_component_arr OR $last_commercer_kpi_component_arr) : ?>
          <div class="wrapper actionnaireCarnet__listInfor">
              <?php if ($commercer_kpi_component_arr) : ?>
                <div class="graphicPresentation__list">
                    <?php $i = 0; foreach ($commercer_kpi_component_arr as $item) : ?>
                      <?php if ($i % 2 == 0) : ?>
                        <div data-equalizer="" data-equalizer-mq="medium-up" class="graphicPresentation__list">
                      <?php endif; ?>
                          <div class="graphicPresentation__item columns medium-6" data-equalizer-watch="data-equalizer-watch">
                            <h4 class="graphicPresentation__item__heading"><?php print $item['commercer_kpi_component_title']; ?></h4>
                            <p class="desc"><?php print $item['commercer_kpi_component_sub_title']; ?></p>
                            <div class="graphicPresentation__item__img">
                              <!-- [Responsive img] start-->
                              <img alt="<?php print $item['commercer_kpi_component_title']; ?>" data-interchange="[<?php print $item['commercer_kpi_component_image']; ?>, (small)], [<?php print $item['commercer_kpi_component_image']; ?>, (large)]"/>
                              <noscript><img src="<?php print $item['commercer_kpi_component_image']; ?>" alt="<?php print $item['commercer_kpi_component_title']; ?>"/></noscript>
                              <!-- [Responsive img] end-->
                            </div>
                          </div>
                      <?php $i++; if ($i % 2 == 0) : ?>
                        </div>
                      <?php endif; ?>
                    <?php endforeach; ?>
                </div>
              <?php endif; ?>
              <?php if ($last_commercer_kpi_component_arr) : ?>
                <div class="graphicPresentation__list">
                  <div class="graphicPresentation__item columns text-center">
                    <h4 class="graphicPresentation__item__heading"><?php print $last_commercer_kpi_component_arr['commercer_kpi_component_title']; ?></h4>
                    <p class="desc"><?php print $last_commercer_kpi_component_arr['commercer_kpi_component_sub_title']; ?></p>
                    <div class="graphicPresentation__item__img">
                      <!-- [Responsive img] start-->
                      <img alt="<?php print $last_commercer_kpi_component_arr['commercer_kpi_component_title']; ?>" data-interchange="[<?php print $last_commercer_kpi_component_arr['commercer_kpi_component_image']; ?>, (small)], [<?php print $last_commercer_kpi_component_arr['commercer_kpi_component_image']; ?>, (large)]"/>
                      <noscript><img src="<?php print $last_commercer_kpi_component_arr['commercer_kpi_component_image']; ?>" alt="<?php print $last_commercer_kpi_component_arr['commercer_kpi_component_title']; ?>"/></noscript>
                      <!-- [Responsive img] end-->
                    </div>
                  </div>
                </div>
              <?php endif; ?>
          </div>
        <?php endif; ?>
        <!-- -->
        <div class="btn-wrapper">
            <?php
            $text = variable_get('bloc_commercer_cta_text');
            $url = variable_get('bloc_commercer_cta_url');
            if ($text && $url) :
              ?>
              <a href="<?php $url; ?>" class="btn-rounded btn-primary"><?php print $text; ?></a>
            <?php endif; ?>
        </div>
    </div>
</section>