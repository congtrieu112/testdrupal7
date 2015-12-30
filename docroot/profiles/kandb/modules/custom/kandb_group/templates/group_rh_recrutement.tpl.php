<?php
print theme('group_rh_header');
$recruitment_section_image_uri = $date_1_value = $date_2_value = '';
$recruitment_section_image_id = variable_get('image_group_hr_recruitment_section');

if ($recruitment_section_image_id) :
  $recruitment_section_image = file_load($recruitment_section_image_id);
  if ($recruitment_section_image):
    $recruitment_section_image_uri = isset($recruitment_section_image->uri) ? $recruitment_section_image->uri : '';
  endif;
endif;
// Agenda.
$angenda_img_block_1_uri = kandb_group_get_image_uri(variable_get('image_group_hr_agenda_section_1'));
$angenda_img_block_2_uri = kandb_group_get_image_uri(variable_get('image_group_hr_agenda_section_2'));
$date_1 = variable_get('date_group_hr_agenda_section_1');
if ($date_1) :
  $date_1_value = date('d.m.Y', strtotime($date_1));
endif;
$date_2 = variable_get('date_group_hr_agenda_section_2');
if ($date_2) :
  $date_2_value = date('d.m.Y', strtotime($date_2));
endif;
?>
<!-- [graphic presentation] start-->
<section class="section-padding graphicPresentation">
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h1 class="heading__title"><?php print variable_get('title_group_hr_recruitment_section', t('Recrutement')); ?></h1>
            <p class="heading__title heading__title--sub"><?php print variable_get('subtitle_group_hr_recruitment_section', t('Morbi leo sirus porta ac consectertur, vestibulum at eros.')) ?></p>
        </header>
        <!-- [Article Advice] start-->
        <article class="text-center">
            <figure class="ourAdvices__figure">
                <!-- images need to have 2 formats in data-interchange attribute:
                - small:
                - medium: 850 x 345
                -->
                <!-- [Responsive img] start-->
                <img alt="A woman and a baby playing" data-interchange="[<?php print image_style_url('dossier_small_teaser', $recruitment_section_image_uri); ?>, (small)], [<?php print image_style_url('dossier_big_teaser', $recruitment_section_image_uri); ?>, (medium)]"/>
                <noscript>
                <img src="<?php print image_style_url('dossier_big_teaser', $recruitment_section_image_uri); ?>" alt="<?php print variable_get('title_group_hr_recruitment_section', t('Recrutement')); ?>"/>
                </noscript>
                <!-- [Responsive img] end-->
            </figure>
            <?php if (variable_get('desciption_1_group_hr_recruitment_section')): ?>
              <p class="ourAdvices__text"><?php print variable_get('desciption_1_group_hr_recruitment_section'); ?></p>
            <?php endif; ?>
            <?php if (variable_get('desciption_2_group_hr_recruitment_section')): ?>
              <p class="ourAdvices__text"><?php print variable_get('desciption_2_group_hr_recruitment_section'); ?></p>
            <?php endif; ?>
        </article>
        <!-- [Article Advice] end-->
    </div>
</section>
<!-- [graphic presentation] end-->
<!-- [diary] start-->
<section class="section-padding diary bg-lightGrey">
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h1 class="heading__title"><?php print variable_get('title_group_hr_agenda_section', t('Agenda')); ?></h1>
        </header>
        <ul class="diary__list">
            <li>
                <div class="diary__list__img">
                    <div class="inner">
                        <!-- images need to have square format:- 240 x 240
                        --><img src="<?php print image_style_url('search_medium', $angenda_img_block_1_uri); ?>" alt="<?php print variable_get('title_group_hr_agenda_section', t('Agenda')); ?>"/>
                    </div>
                </div>
                <div class="diary__list__content">
                    <div class="diary__list__content--title"><a href="#" title="<?php print $date_1_value; ?>"><?php print $date_1_value; ?></a>
                        <p><?php print variable_get('title_group_hr_agenda_section_1', t('Forum des métiers du batiment')); ?></p>
                    </div>
                    <p class="diary__list__content--description"><?php print variable_get('description_group_hr_agenda_section_1'); ?></p>
                </div>
            </li>
            <li>
                <div class="diary__list__img">
                    <div class="inner">
                        <!-- images need to have square format:- 240 x 240
                        --><img src="<?php print image_style_url('search_medium', $angenda_img_block_2_uri); ?>" alt="Forum des maisons de France"/>
                    </div>
                </div>
                <div class="diary__list__content">
                    <div class="diary__list__content--title"><a href="#" title="<?php print $date_2_value; ?>"><?php print $date_2_value; ?></a>
                        <p><?php print variable_get('title_group_hr_agenda_section_2', t('Forum des maisons de France')); ?></p>
                    </div>
                    <p class="diary__list__content--description"><?php print variable_get('description_group_hr_agenda_section_2'); ?></p>
                </div>
            </li>
        </ul>
<!--        <div class="btn-wrapper"><a href="#" class="btn-rounded btn-primary">Voir tout<span class="icon icon-arrow"></span></a>-->
    </div>
</div>
</section>
<!-- [diary] end-->
<!-- [latest Jobs] start-->
<section class="section-padding latestJobs">
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h3 class="heading__title">Nos dernières offres d’emploi</h3>
        </header>
        <div data-slick="{&quot;slidesToShow&quot;: 1, &quot;slidesToScroll&quot;: 1}" data-slick-responsive="small-only" class="latestJobs__list">
            <div class="latestJobs__item column medium-4 large-3">
                <div class="latestJobs__item__content">
                    <div class="latestJobs__item__heading">
                        <h4 class="latestJobs__item__date">20.06.2015</h4>
                        <h4 class="latestJobs__item__title">Comptable Général</h4><span class="latestJobs__item__address">Neuilly-Sur-Seine</span>
                    </div>
                    <p>En charge du suivi comptable de SCI et SNC, vous gérez les éléments suivants : suivi comptable…</p>
                    <p class="text-bold">Expérience exigée :<span>5 ans minimum</span></p>
                </div><a href="#" class="btn-rounded btn-primary">Voir l’offre<span class="icon icon-arrow"></span></a>
            </div>
            <div class="latestJobs__item column medium-4 large-3">
                <div class="latestJobs__item__content">
                    <div class="latestJobs__item__heading">
                        <h4 class="latestJobs__item__date">20.06.2015</h4>
                        <h4 class="latestJobs__item__title">Directeur Région</h4><span class="latestJobs__item__address">Nice</span>
                    </div>
                    <p>En charge du suivi comptable de SCI et SNC, vous gérez les éléments suivants : suivi comptable…</p>
                    <p class="text-bold">Expérience exigée :<span>4 ans minimum</span></p>
                </div><a href="#" class="btn-rounded btn-primary">Voir l’offre<span class="icon icon-arrow"></span></a>
            </div>
            <div class="latestJobs__item column medium-4 large-3">
                <div class="latestJobs__item__content">
                    <div class="latestJobs__item__heading">
                        <h4 class="latestJobs__item__date">20.06.2015</h4>
                        <h4 class="latestJobs__item__title">Comptable Général</h4><span class="latestJobs__item__address">Neuilly-Sur-Seine</span>
                    </div>
                    <p>En charge du suivi comptable de SCI et SNC, vous gérez les éléments suivants : suivi comptable…</p>
                    <p class="text-bold">Expérience exigée :<span>3 ans minimum</span></p>
                </div><a href="#" class="btn-rounded btn-primary">Voir l’offre<span class="icon icon-arrow"></span></a>
            </div>
            <div class="latestJobs__item column medium-4 large-3">
                <div class="latestJobs__item__content">
                    <div class="latestJobs__item__heading">
                        <h4 class="latestJobs__item__date">20.06.2015</h4>
                        <h4 class="latestJobs__item__title">Manager finance</h4><span class="latestJobs__item__address">Paris</span>
                    </div>
                    <p>En charge du suivi comptable de SCI et SNC, vous gérez les éléments suivants : suivi comptable…</p>
                    <p class="text-bold">Expérience exigée :<span>5 ans minimum</span></p>
                </div><a href="#" class="btn-rounded btn-primary">Voir l’offre<span class="icon icon-arrow"></span></a>
            </div>
        </div>
        <div class="btn-wrapper"><a href="#" class="btn-rounded btn-primary">Voir toutes nos offres<span class="icon icon-arrow"></span></a>
        </div>
    </div>
</section>
<!-- [latest Jobs] end-->