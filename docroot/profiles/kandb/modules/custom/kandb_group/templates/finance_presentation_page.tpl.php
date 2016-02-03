<?php
/**
 * @file
 * Render finance presentation page.
 */

// Speech section.
$speech_module_title = variable_get('finance_presentation_speech_module_title_' . $current_lang);
$speech_image = variable_get('finance_presentation_speech_image_' . $current_lang);
$speech_image = $speech_image ? file_load($speech_image) : '';
$speech_image = (isset($speech_image->uri) AND $speech_image->uri) ? image_style_url('finance_presentation_speech_215_x_215', $speech_image->uri) : '';
$speech_quote = variable_get('finance_presentation_speech_quote_' . $current_lang);
$speech_author_name = variable_get('finance_presentation_speech_author_name_' . $current_lang);
$speech_job_title = variable_get('finance_presentation_speech_job_title_' . $current_lang);
$speech_buton_url = variable_get('finance_presentation_speech_buton_url_' . $current_lang);

// KPI section.
$kpi_module_title = variable_get('finance_presentation_kpi_module_title_' . $current_lang);
$kpi_component_arr = $last_kpi_component_arr = array();
for ($i = 1; $i <= KANDB_GROUP_KPI_ITEMS_NUM; $i++) :
  $kpi_component_title = variable_get('finance_presentation_kpi_component_title_' . $i . '_' . $current_lang);
  $kpi_component_sub_title = variable_get('finance_presentation_kpi_component_sub_title_' . $i . '_' . $current_lang);
  $kpi_component_image = variable_get('finance_presentation_kpi_component_image_' . $i . '_' . $current_lang);
  $kpi_component_image = $kpi_component_image ? file_load($kpi_component_image) : '';
  $kpi_component_image = (isset($kpi_component_image->uri) AND $kpi_component_image->uri) ? image_style_url('kpi_component_580_x_296', $kpi_component_image->uri) : '';

  if ($kpi_component_title AND $kpi_component_sub_title AND $kpi_component_image) :
    $kpi_component_arr[] = array(
      'kpi_component_title' => $kpi_component_title,
      'kpi_component_sub_title' => $kpi_component_sub_title,
      'kpi_component_image' => $kpi_component_image,
    );
  endif;
endfor;

if (count($kpi_component_arr) % 2 != 0) :
  $last_kpi_component_arr = end($kpi_component_arr);
  array_pop($kpi_component_arr);
endif;

// Notebooks section.
$notebooks_module_title = variable_get('finance_presentation_notebooks_module_title_' . $current_lang);
$data_block_part_title = variable_get('finance_presentation_notebooks_data_block_part_title_' . $current_lang);
$data_block_2_part_title = variable_get('finance_presentation_notebooks_data_block_2_part_title_' . $current_lang);
$notebooks_kpi_component_arr = $last_notebooks_kpi_component_arr = array();
for ($i = 1; $i <= KANDB_GROUP_NOTEBOOKS_KPI_ITEMS_NUM; $i++) :
  $notebooks_kpi_component_title = variable_get('finance_presentation_notebooks_kpi_component_title_' . $i . '_' . $current_lang);
  $notebooks_kpi_component_sub_title = variable_get('finance_presentation_notebooks_kpi_component_sub_title_' . $i . '_' . $current_lang);
  $notebooks_kpi_component_image = variable_get('finance_presentation_notebooks_kpi_component_image_' . $i . '_' . $current_lang);
  $notebooks_kpi_component_image = $notebooks_kpi_component_image ? file_load($notebooks_kpi_component_image) : '';
  $notebooks_kpi_component_image = (isset($notebooks_kpi_component_image->uri) AND $notebooks_kpi_component_image->uri) ? image_style_url('kpi_component_580_x_296', $notebooks_kpi_component_image->uri) : '';

  if ($notebooks_kpi_component_title AND $notebooks_kpi_component_sub_title AND $notebooks_kpi_component_image) :
    $notebooks_kpi_component_arr[] = array(
      'notebooks_kpi_component_title' => $notebooks_kpi_component_title,
      'notebooks_kpi_component_sub_title' => $notebooks_kpi_component_sub_title,
      'notebooks_kpi_component_image' => $notebooks_kpi_component_image,
    );
  endif;
endfor;

if (count($notebooks_kpi_component_arr) % 2 != 0) :
  $last_notebooks_kpi_component_arr = end($notebooks_kpi_component_arr);
  array_pop($notebooks_kpi_component_arr);
endif;
$tabs = kandb_group_button_tabs_header('corporate/finance/presentation', $_GET['q']);
print $tabs;
?>
<?php
print theme('finance_header_block');
?>
<!-- [president quote] start-->
<section class="section-padding presidentQuote bg-lightGrey">
    <?php if ($speech_module_title) : ?>
      <div class="wrapper">
          <header class="heading heading--bordered">
              <h1 class="heading__title"><?php print $speech_module_title; ?></h1>
          </header>
      </div>
    <?php endif; ?>
    <div class="wrapper">
        <div class="presidentQuote__content">
            <?php if ($speech_image) : ?>
              <div class="presidentQuote__img">
                  <img src="<?php print $speech_image; ?>" alt="<?php print $speech_module_title; ?>"/>
              </div>
            <?php endif; ?>
            <div class="presidentQuote__quote">
                <?php if ($speech_quote) : ?>
                  <blockquote>
                      <p><?php print $speech_quote; ?></p>
                  </blockquote>
                <?php endif; ?>
                <?php if ($speech_author_name) : ?>
                  <h3 class="presidentQuote__title"><?php print $speech_author_name; ?></h3>
                <?php endif; ?>
                <?php if ($speech_job_title) : ?>
                  <span class="presidentQuote__sub"><?php print $speech_job_title; ?></span>
                <?php endif; ?>
                <?php if ($speech_buton_url) : ?>
                  <div class="presidentQuote__cta">
                      <a href="<?php print $speech_buton_url; ?>" class="btn-primary btn-rounded">
                          <?php print t('Découvrir la gouvernance de l’entreprise'); ?>
                      </a>
                  </div>
                <?php endif; ?>
            </div>
        </div>
    </div>
</section>
<!-- [president quote] end-->
<!-- [graphic presentation] start-->
<section class="section-padding graphicPresentation">
    <div class="wrapper">
        <?php if ($kpi_module_title) : ?>
          <header class="heading heading--bordered">
              <h1 class="heading__title"><?php print $kpi_module_title; ?></h1>
          </header>
        <?php endif; ?>
        <?php if ($kpi_component_arr) : ?>
          <div class="graphicPresentation__list">
              <?php foreach ($kpi_component_arr as $item) : ?>
                <div class="graphicPresentation__item columns medium-6">
                    <h4 class="graphicPresentation__item__heading"><?php print $item['kpi_component_title']; ?></h4>
                    <p class="desc"><?php print $item['kpi_component_sub_title']; ?></p>
                    <div class="graphicPresentation__item__img">
                        <img alt="<?php print $item['kpi_component_title']; ?>" data-interchange="[<?php print $item['kpi_component_image']; ?>, (small)], [<?php print $item['kpi_component_image']; ?>, (large)]"/>
                        <noscript><img src="<?php print $item['kpi_component_image']; ?>" alt="<?php print $item['kpi_component_title']; ?>"/></noscript>
                    </div>
                </div>
              <?php endforeach; ?>
          </div>
        <?php endif; ?>
        <?php if ($last_kpi_component_arr) : ?>
          <div class="graphicPresentation__list">
              <div class="graphicPresentation__item columns text-center">
                  <h4 class="graphicPresentation__item__heading"><?php print $last_kpi_component_arr['kpi_component_title']; ?></h4>
                  <p class="desc"><?php print $last_kpi_component_arr['kpi_component_sub_title']; ?></p>
                  <div class="graphicPresentation__item__img">
                      <img alt="<?php print $last_kpi_component_arr['kpi_component_title']; ?>" data-interchange="[<?php print $last_kpi_component_arr['kpi_component_image']; ?>, (small)], [<?php print $last_kpi_component_arr['kpi_component_image']; ?>, (large)]"/>
                      <noscript><img src="<?php print $last_kpi_component_arr['kpi_component_image']; ?>" alt="<?php print $last_kpi_component_arr['kpi_component_title']; ?>"/></noscript>
                  </div>
              </div>
          </div>
        <?php endif; ?>
    </div>
</section>
<!-- [graphic presentation] end-->
<!-- [content actionnaireCarnet] start-->
<section class="section-padding actionnaireCarnet bg-lightGrey">
    <div class="wrapper">
        <?php if ($notebooks_module_title): ?>
          <header class="heading heading--bordered">
              <h1 class="heading__title"><?php print $notebooks_module_title; ?></h1>
          </header>
        <?php endif; ?>

        <div class="wrapper actionnaireCarnet__listInfor">
            <div class="inner">
                <?php if ($data_block_part_title): ?>
                  <div class="heading heading--small">
                      <h1 class="heading__title"><?php print $data_block_part_title; ?></h1>
                  </div>
                <?php endif; ?>
                <dl class="actionnaireCarnet__listInfor__list">
                    <?php for ($i = 1; $i <= KANDB_GROUP_DATA_BLOCK_ITEMS_NUM; $i++) : ?>
                      <?php
                      $label = variable_get('finance_presentation_notebooks_data_block_line_label_' . $i . '_' . $current_lang);
                      $data = variable_get('finance_presentation_notebooks_data_block_line_data_' . $i . '_' . $current_lang);
                      ?>
                      <?php if ($label AND $data): ?>
                        <dt><p><?php print $label ?></p></dt>
                        <dd><p><?php print $data ?></p></dd>
                      <?php endif; ?>
                    <?php endfor; ?>
                </dl>
            </div>
        </div>

        <?php if ($notebooks_kpi_component_arr OR $last_notebooks_kpi_component_arr) : ?>
          <div class="wrapper actionnaireCarnet__listInfor">
              <?php if ($notebooks_kpi_component_arr) : ?>
                <div class="graphicPresentation__list">
                    <?php foreach ($notebooks_kpi_component_arr as $item) : ?>
                      <div class="graphicPresentation__item columns medium-6">
                          <h4 class="graphicPresentation__item__heading"><?php print $item['notebooks_kpi_component_title']; ?></h4>
                          <p class="desc"><?php print $item['notebooks_kpi_component_sub_title']; ?></p>
                          <div class="graphicPresentation__item__img">
                              <img alt="<?php print $item['notebooks_kpi_component_title']; ?>" data-interchange="[<?php print $item['notebooks_kpi_component_image']; ?>, (small)], [<?php print $item['notebooks_kpi_component_image']; ?>, (large)]"/>
                              <noscript><img src="<?php print $item['notebooks_kpi_component_image']; ?>" alt="<?php print $item['notebooks_kpi_component_title']; ?>"/></noscript>
                          </div>
                      </div>
                    <?php endforeach; ?>
                </div>
              <?php endif; ?>
              <?php if ($last_notebooks_kpi_component_arr) : ?>
                <div class="graphicPresentation__list">
                    <div class="graphicPresentation__item columns text-center">
                        <h4 class="graphicPresentation__item__heading"><?php print $last_notebooks_kpi_component_arr['notebooks_kpi_component_title']; ?></h4>
                        <p class="desc"><?php print $last_notebooks_kpi_component_arr['notebooks_kpi_component_sub_title']; ?></p>
                        <div class="graphicPresentation__item__img">
                            <img alt="<?php print $last_notebooks_kpi_component_arr['notebooks_kpi_component_title']; ?>" data-interchange="[<?php print $last_notebooks_kpi_component_arr['notebooks_kpi_component_image']; ?>, (small)], [<?php print $last_notebooks_kpi_component_arr['notebooks_kpi_component_image']; ?>, (large)]"/>
                            <noscript><img src="<?php print $last_notebooks_kpi_component_arr['notebooks_kpi_component_image']; ?>" alt="<?php print $last_notebooks_kpi_component_arr['notebooks_kpi_component_title']; ?>"/></noscript>
                        </div>
                    </div>
                </div>
              <?php endif; ?>
          </div>
        <?php endif; ?>

        <div class="wrapper actionnaireCarnet__listInfor">
            <div class="inner">
                <?php if ($data_block_part_title): ?>
                  <div class="heading heading--small">
                      <h1 class="heading__title"><?php print $data_block_2_part_title; ?></h1>
                  </div>
                <?php endif; ?>
                <dl class="actionnaireCarnet__listInfor__list">
                    <?php for ($i = 1; $i <= KANDB_GROUP_DATA_BLOCK_ITEMS_NUM; $i++) : ?>
                      <?php
                      $label = variable_get('finance_presentation_notebooks_data_block_2_line_label_' . $i . '_' . $current_lang);
                      $data = variable_get('finance_presentation_notebooks_data_block_2_line_data_' . $i . '_' . $current_lang);
                      ?>
                      <?php if ($label AND $data): ?>
                        <dt><p><?php print $label ?></p></dt>
                        <dd><p><?php print $data ?></p></dd>
                      <?php endif; ?>
                    <?php endfor; ?>
                </dl>
            </div>
        </div>
    </div>
</section>
<!-- [content actionnaireCarnet] end-->