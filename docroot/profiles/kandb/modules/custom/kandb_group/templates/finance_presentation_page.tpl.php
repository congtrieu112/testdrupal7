<?php
/**
 * @file
 * Render finance presentation page.
 */
$current_lang = arg(2);

$speech_module_title = variable_get('finance_presentation_speech_module_title_' . $current_lang);
$speech_image = variable_get('finance_presentation_speech_image_' . $current_lang);
$speech_image = $speech_image ? file_load($speech_image) : '';
$speech_image = (isset($speech_image->uri) AND $speech_image->uri) ? image_style_url('finance_presentation_speech_215_x_215', $speech_image->uri) : '';
$speech_quote = variable_get('finance_presentation_speech_quote_' . $current_lang);
$speech_author_name = variable_get('finance_presentation_speech_author_name_' . $current_lang);
$speech_job_title = variable_get('finance_presentation_speech_job_title_' . $current_lang);
$speech_buton_url = variable_get('finance_presentation_speech_buton_url_' . $current_lang);
?>

<!-- [president quote] start-->
<section class="section-padding presidentQuote">
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