<?php
$header_title = variable_get('header_title_seo_logement_block', '');
$header_resume = variable_get('header_resume_seo_logement_block', '');
$header_image = variable_get('header_image_seo_logement_block', '');

$header_image = is_numeric($header_image) ? file_load($header_image) : '';
$header_image_m = (isset($header_image->uri) AND $header_image->uri) ? image_style_url('1380x400', $header_image->uri) : '';
$header_image_s = (isset($header_image->uri) AND $header_image->uri) ? image_style_url('640x400', $header_image->uri) : '';

$heading_title = variable_get('heading_title_seo_logement_block', '');
$heading_subtitle = variable_get('heading_subtitle_seo_logement_block', '');

$typelogement_title = variable_get('typelogement_title_seo_logement_block', '');
$typelogement_description = variable_get('typelogement_description_seo_logement_block', '');
?>


<!-- [header type logements] start-->
<!-- images need to have 2 different formats:
- small: 640 x 400 (High compression)
- large: 1380 x 400
-->
<?php if($header_title || $header_resume || $header_image_m || $header_image_s) : ?>
<section data-interchange="[<?php print $header_image_s; ?>, (small)], [<?php print $header_image_m; ?>, (medium)]" class="narrow-header">
  <?php if($header_title || $header_resume) : ?>
  <div class="wrapper">
    <div class="heading heading--bordered heading--white">
      <?php if($header_title) : ?><div class="heading__title"><?php print $header_title; ?></div><?php endif; ?>
      <?php if($header_resume) : ?><div class="heading__title heading__title--sub"><?php print $header_resume; ?></div><?php endif; ?>
    </div>
  </div>
  <?php endif; ?>
</section>
<?php endif; ?>
<!-- [header type logements] end-->
<!-- [Typo Logements content] start-->
<section class="section-padding">
  <?php if($heading_title || $heading_subtitle) : ?>
  <div class="wrapper">
    <header class="heading heading--bordered">
      <?php if($heading_title) : ?><h2 class="heading__title"><?php print $heading_title; ?></h2><?php endif; ?>
      <?php if($heading_subtitle) : ?><p class="heading__title heading__title--sub"><?php print $heading_subtitle; ?></p><?php endif; ?>
    </header>
  </div>
  <?php endif; ?>
  <?php if($typelogement_title || $typelogement_description || $results) : ?>
  <article class="section-padding bg-lightGrey">
    <div class="typeLogements wrapper">
      <?php if($typelogement_title || $typelogement_description) : ?>
      <div class="typeLogements__heading">
        <?php if($typelogement_title) : ?><h3><?php print $typelogement_title; ?></h3><?php endif; ?>
        <?php isset($typelogement_description['value']) ? print $typelogement_description['value'] : print ''; ?>
      </div>
      <?php endif; ?>
      <?php if(!empty($results)) : ?>
        <?php foreach ($results as $type => $pieces) : ?>
        <div class="typeLogements__list bg-white">
          <dl>
            <dt><?php print $type; ?></dt>
            <dd>
              <ul>
                <?php foreach ($pieces as $piece) : ?>
                <li><a href="/<?php print current_path(); ?>/achat-<?php print $sanitized_strings[$type]; ?>-<?php print $sanitized_strings[$piece]; ?>" title="<?php print $type; ?> <?php print $piece; ?>"><?php print $type; ?> <?php print $piece; ?></a></li>
                <?php endforeach; ?>
              </ul>
            </dd>
          </dl>
        </div>
        <?php endforeach; ?>
      <?php endif; ?>
    </div>
  </article>
  <?php endif; ?>
</section>
<!-- [Typo Logements content] end-->