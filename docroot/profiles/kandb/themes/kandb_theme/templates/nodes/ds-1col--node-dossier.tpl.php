<?php
$path_img = kandb_theme_get_path('test_assets', 'kandb_theme');
$title = '';
$sub_title = '';
$introduction = '';
$video_content = '';
$image_content = '';
$image_content_title = '';
$uri_block_1_image = '';
$block_1_title = '';
$block_1_text = '';
$uri_block_2_image = '';
$block_2_title = '';
$block_2_text = '';
$uri_block_3_image = '';
$block_3_title = '';
$block_3_text = '';
$uri_block_4_image = '';
$block_4_title = '';
$block_4_text = '';
$uri_block_5_image = '';
$block_5_title = '';
$block_5_text = '';
$url_video_content = '';
$id_video_content = '';
$title_main_block_article = '';
$intro_main_block_article = '';
$title_block_article_1 = '';
$list_block_article_1 = array();
$title_block_article_2 = '';
$list_block_article_2 = array();
$title_block_article_3 = '';
$list_block_article_3 = array();

//get title
if (isset($content['title']['#object']->title))
  $title = $content['title']['#object']->title;
//end get title
//get subtitle
if (isset($content['field_dossier_sous_titre']['#object']->field_dossier_sous_titre['und'][0]['value']))
  $sub_title = $content['field_dossier_sous_titre']['#object']->field_dossier_sous_titre['und'][0]['value'];
//end get subtitle
//get introduction
if (isset($content['field_dossier_introduction']['#object']->field_dossier_introduction['und'][0]['value']))
  $introduction = $content['field_dossier_introduction']['#object']->field_dossier_introduction['und'][0]['value'];
//end get introduction
//get image
if (isset($content['field_dossier_image']['#object']->field_dossier_image['und'][0]['uri']))
  $image_content = $content['field_dossier_image']['#object']->field_dossier_image['und'][0]['uri'];
if (isset($content['field_dossier_image']['#object']->field_dossier_image['und'][0]['title']))
  $image_content_title = $content['field_dossier_image']['#object']->field_dossier_image['und'][0]['title'];

//end get image
//get video
if (isset($content['field_dossier_video']['#object']->field_dossier_video['und'][0]['input']))
  $url_video_content = $content['field_dossier_video']['#object']->field_dossier_video['und'][0]['input'];
if (isset($content['field_dossier_video']['#object']->field_dossier_video['und'][0]['input']))
  $id_video_content = $content['field_dossier_video']['#object']->field_dossier_video['und'][0]['video_id'];
//end get video
//Block 1 of the dossier page	
//get uri image
if (isset($content['field_dossier_block1_image']['#object']->field_dossier_block1_image['und'][0]['uri']))
  $uri_block_1_image = $content['field_dossier_block1_image']['#object']->field_dossier_block1_image['und'][0]['uri'];
//get title block 1
if (isset($content['field_dossier_block1_title']['#object']->field_dossier_block1_title['und'][0]['value']))
  $block_1_title = $content['field_dossier_block1_title']['#object']->field_dossier_block1_title['und'][0]['value'];
//get text block 1
if (isset($content['field_dossier_block1_text']['#object']->field_dossier_block1_text['und'][0]['value']))
  $block_1_text = $content['field_dossier_block1_text']['#object']->field_dossier_block1_text['und'][0]['value'];
//end Block 1 of the dossier page
//block 2 of the dossier page	
//get uri image
if (isset($content['field_dossier_block2_image']['#object']->field_dossier_block2_image['und'][0]['uri']))
  $uri_block_2_image = $content['field_dossier_block2_image']['#object']->field_dossier_block2_image['und'][0]['uri'];
//get title block 2
if (isset($content['field_dossier_block2_title']['#object']->field_dossier_block2_title['und'][0]['value']))
  $block_2_title = $content['field_dossier_block2_title']['#object']->field_dossier_block2_title['und'][0]['value'];
//get text block 2
if (isset($content['field_dossier_block2_text']['#object']->field_dossier_block2_text['und'][0]['value']))
  $block_2_text = $content['field_dossier_block2_text']['#object']->field_dossier_block2_text['und'][0]['value'];
//end block 2 of the dossier page	
//block 3 of the dossier page	
//get uri image
if (isset($content['field_dossier_block3_image']['#object']->field_dossier_block3_image['und'][0]['uri']))
  $uri_block_3_image = $content['field_dossier_block3_image']['#object']->field_dossier_block3_image['und'][0]['uri'];
//get title block 3
if (isset($content['field_dossier_block3_title']['#object']->field_dossier_block3_title['und'][0]['value']))
  $block_3_title = $content['field_dossier_block3_title']['#object']->field_dossier_block3_title['und'][0]['value'];
//get text block 3
if (isset($content['field_dossier_block3_text']['#object']->field_dossier_block3_text['und'][0]['value']))
  $block_3_text = $content['field_dossier_block3_text']['#object']->field_dossier_block3_text['und'][0]['value'];
//end block 3 of the dossier page	
//block 4 of the dossier page	
//get uri image
if (isset($content['field_dossier_block4_image']['#object']->field_dossier_block4_image['und'][0]['uri']))
  $uri_block_4_image = $content['field_dossier_block4_image']['#object']->field_dossier_block4_image['und'][0]['uri'];
//get title block 4
if (isset($content['field_dossier_block4_title']['#object']->field_dossier_block4_title['und'][0]['value']))
  $block_4_title = $content['field_dossier_block4_title']['#object']->field_dossier_block4_title['und'][0]['value'];
//get text block 4
if (isset($content['field_dossier_block4_text']['#object']->field_dossier_block4_text['und'][0]['value']))
  $block_4_text = $content['field_dossier_block4_text']['#object']->field_dossier_block4_text['und'][0]['value'];
//end block 4 of the dossier page	
//block 5 of the dossier page	
//get uri image
if (isset($content['field_dossier_block5_image']['#object']->field_dossier_block5_image['und'][0]['uri']))
  $uri_block_5_image = $content['field_dossier_block5_image']['#object']->field_dossier_block5_image['und'][0]['uri'];
//get title block 5
if (isset($content['field_dossier_block5_title']['#object']->field_dossier_block5_title['und'][0]['value']))
  $block_5_title = $content['field_dossier_block5_title']['#object']->field_dossier_block5_title['und'][0]['value'];
//get text block 5
if (isset($content['field_dossier_block5_text']['#object']->field_dossier_block5_text['und'][0]['value']))
  $block_5_text = $content['field_dossier_block5_text']['#object']->field_dossier_block5_text['und'][0]['value'];
//end block 5 of the dossier page	
//title of main block article
if (isset($content['field_dossier_articles_title']['#object']->field_dossier_articles_title['und'][0]['value']))
  $title_main_block_article = $content['field_dossier_articles_title']['#object']->field_dossier_articles_title['und'][0]['value'];
//end title of main block article
//introduc of main block article
if (isset($content['field_dossier_articles_intro']['#object']->field_dossier_articles_intro['und'][0]['value']))
  $intro_main_block_article = $content['field_dossier_articles_intro']['#object']->field_dossier_articles_intro['und'][0]['value'];
//end introduc of main block article
//title of block article 1
if (isset($content['field_articles_block1_title']['#object']->field_articles_block1_title['und'][0]['value']))
  $title_block_article_1 = $content['field_articles_block1_title']['#object']->field_articles_block1_title['und'][0]['value'];
//end title of block article 1
//list article block article 1
if (isset($content['field_articles_block1_ref']['#object']->field_articles_block1_ref['und']) && count($content['field_articles_block1_ref']['#object']->field_articles_block1_ref['und']))
  $list_block_article_1 = $content['field_articles_block1_ref']['#object']->field_articles_block1_ref['und'];

//end list article block article 1
//get image block article 1
if (isset($content['field_articles_block1_image']['#object']->field_articles_block1_image['und'][0]['uri']))
  $image_block_article_1 = $content['field_articles_block1_image']['#object']->field_articles_block1_image['und'][0]['uri'];
//end image block article 1
//title of block article 2
if (isset($content['field_articles_block2_title']['#object']->field_articles_block2_title['und'][0]['value']))
  $title_block_article_2 = $content['field_articles_block2_title']['#object']->field_articles_block2_title['und'][0]['value'];
//end title of block article 2
//list article block article 2
if (isset($content['field_articles_block2_ref']['#object']->field_articles_block2_ref['und']) && count($content['field_articles_block2_ref']['#object']->field_articles_block2_ref['und']))
  $list_block_article_2 = $content['field_articles_block2_ref']['#object']->field_articles_block2_ref['und'];
//end list article block article 2
//get image block article 2
if (isset($content['field_articles_block2_image']['#object']->field_articles_block2_image['und'][0]['uri']))
  $image_block_article_2 = $content['field_articles_block2_image']['#object']->field_articles_block2_image['und'][0]['uri'];
//end image block article 2
//title of block article 3
if (isset($content['field_articles_block3_title']['#object']->field_articles_block3_title['und'][0]['value']))
  $title_block_article_3 = $content['field_articles_block3_title']['#object']->field_articles_block3_title['und'][0]['value'];
//end title of block article 3
//list article block article 3
if (isset($content['field_articles_block3_ref']['#object']->field_articles_block3_ref['und']) && count($content['field_articles_block3_ref']['#object']->field_articles_block3_ref['und']))
  $list_block_article_3 = $content['field_articles_block3_ref']['#object']->field_articles_block3_ref['und'];
//end list article block article 3
//get image block article 3
if (isset($content['field_articles_block3_image']['#object']->field_articles_block3_image['und'][0]['uri']))
  $image_block_article_3 = $content['field_articles_block3_image']['#object']->field_articles_block3_image['und'][0]['uri'];
//end image block article 3
?>
<?php
if (isset($content['nos_conseils'])):
  print render($content['nos_conseils']);
endif;
// render menu, limit 5
if (isset($content['view_menu_nos_conseils'])):
  print render($content['view_menu_nos_conseils']);
endif;
?>
<!-- [pageHeaderNav] end-->
<!-- [content Advice] start-->
<article class="wrapper section-padding ourAdvices">
    <!-- [Advice introduction] start-->
    <header class="heading heading--bordered">
        <h1 class="heading__title"><?php print $title ?></h1>
        <p class="heading__title heading__title--sub"><?php print $sub_title ?></p>
    </header>
    <!-- images need to have 2 formats:
   - small: 560 x 350 (High compression)
   - medium: 1180 x 380
    --><a href="<?php if ($url_video_content) print $url_video_content ?>" title="vidéo" data-reveal-id="videoConseilMain" data-interchange="<?php
    if ($image_content) {
      print file_create_url($image_content);
      ?>, (small)], [<?php
            print file_create_url($image_content) . ', (medium)]';
          }
          ?>" class="ourAdvices__video heading heading--white"><span class="icon icon-play"></span></a>
    <!-- [popin] start-->
    <?php if ($url_video_content): ?>
      <div id="videoConseilMain" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
          <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
              <div class="flex-video youtube">
                  <iframe width="1280" height="720" src="" data-src="//www.youtube.com/embed/<?php print $id_video_content ?>" frameborder="0" allowfullscreen allowtransparency="true"></iframe>
              </div>
          </div>
      </div>
    <?php endif; ?>
    <!-- [popin] end-->

    <p class="ourAdvices__text"><?php print $introduction ?></p>
    <!-- [Advice introduction] end-->


    <?php if ($block_1_title) { ?>
      <!-- [Article Advice] start-->
      <article class="text-center">
          <figure class="ourAdvices__figure">
              <!-- images need to have 2 formats in data-interchange attribute:
              - small:
              - medium: 850 x 345
              -->
              <?php if ($uri_block_1_image): ?>
                <!-- [Responsive img] start--><img alt="<?php print $block_1_title ?>" data-interchange="[<?php print file_create_url($uri_block_1_image) ?>, (small)], [<?php print file_create_url($uri_block_1_image) ?>, (medium)]"/>
                <noscript><img src="<?php print file_create_url($uri_block_1_image) ?>" alt="<?php print $block_1_title ?>"/></noscript>
                <!-- [Responsive img] end-->
              <?php endif; ?>
          </figure>
          <?php if ($block_1_title): ?>
            <div class="heading--small ourAdvices__heading">
                <h2 class="heading__title"><?php print $block_1_title ?></h2>
            </div>
          <?php endif; ?>
          <?php if ($block_1_text): ?>
            <p class="ourAdvices__text"><?php print $block_1_text ?></p>
          <?php endif; ?>
      </article>
      <!-- [Article Advice] end-->
    <?php } ?>

    <?php if ($block_2_title) { ?>
      <!-- [Article Advice] start-->
      <article class="text-center">
          <figure class="ourAdvices__figure">
              <!-- images need to have 2 formats in data-interchange attribute:
              - small:
              - medium: 850 x 345
              -->
              <?php if ($uri_block_2_image): ?>
                <!-- [Responsive img] start--><img alt="<?php print $block_2_title ?>" data-interchange="[<?php print file_create_url($uri_block_2_image) ?>, (small)], [<?php print file_create_url($uri_block_2_image) ?>, (medium)]"/>
                <noscript><img src="<?php print file_create_url($uri_block_2_image) ?>" alt="<?php print $block_2_title ?>"/></noscript>
                <!-- [Responsive img] end-->
              <?php endif; ?>
          </figure>
          <?php if ($block_2_title): ?>
            <div class="heading--small ourAdvices__heading">
                <h2 class="heading__title"><?php print $block_2_title ?></h2>
            </div>
          <?php endif; ?>
          <?php if ($block_2_text): ?>
            <p class="ourAdvices__text"><?php print $block_2_text ?></p>
          <?php endif; ?>
      </article>
      <!-- [Article Advice] end-->
    <?php } ?>
    <?php if ($block_3_title) { ?>
      <!-- [Article Advice] start-->
      <article class="text-center">
          <figure class="ourAdvices__figure">
              <!-- images need to have 2 formats in data-interchange attribute:
              - small:
              - medium: 850 x 345
              -->
              <?php if ($uri_block_3_image): ?>
                <!-- [Responsive img] start--><img alt="<?php print $block_3_title ?>" data-interchange="[<?php print file_create_url($uri_block_3_image) ?>, (small)], [<?php print file_create_url($uri_block_3_image) ?>, (medium)]"/>
                <noscript><img src="<?php print file_create_url($uri_block_3_image) ?>" alt="<?php print $block_3_title ?>"/></noscript>
                <!-- [Responsive img] end-->
              <?php endif; ?>
          </figure>
          <?php if ($block_3_title): ?>
            <div class="heading--small ourAdvices__heading">
                <h2 class="heading__title"><?php print $block_3_title ?></h2>
            </div>
          <?php endif; ?>
          <?php if ($block_3_text): ?>
            <p class="ourAdvices__text"><?php print $block_3_text ?></p>
          <?php endif; ?>
      </article>
      <!-- [Article Advice] end-->
    <?php } ?>
    <?php if ($block_4_title) { ?>
      <!-- [Article Advice] start-->
      <article class="text-center">
          <figure class="ourAdvices__figure">
              <!-- images need to have 2 formats in data-interchange attribute:
              - small:
              - medium: 850 x 345
              -->
              <?php if ($uri_block_4_image): ?>
                <!-- [Responsive img] start--><img alt="<?php print $block_4_title ?>" data-interchange="[<?php print file_create_url($uri_block_4_image) ?>, (small)], [<?php print file_create_url($uri_block_4_image) ?>, (medium)]"/>
                <noscript><img src="<?php print file_create_url($uri_block_4_image) ?>" alt="<?php print $block_4_title ?>"/></noscript>
                <!-- [Responsive img] end-->
              <?php endif; ?>
          </figure>
          <?php if ($block_4_title): ?>
            <div class="heading--small ourAdvices__heading">
                <h2 class="heading__title"><?php print $block_4_title ?></h2>
            </div>
          <?php endif; ?>
          <?php if ($block_4_text): ?>
            <p class="ourAdvices__text"><?php print $block_4_text ?></p>
          <?php endif; ?>
      </article>
      <!-- [Article Advice] end-->
    <?php } ?>
    <?php if ($block_5_title) { ?>
      <!-- [Article Advice] start-->
      <article class="text-center">
          <figure class="ourAdvices__figure">
              <!-- images need to have 2 formats in data-interchange attribute:
              - small:
              - medium: 850 x 345
              -->
              <?php if ($uri_block_5_image): ?>
                <!-- [Responsive img] start--><img alt="<?php print $block_5_title ?>" data-interchange="[<?php print file_create_url($uri_block_5_image) ?>, (small)], [<?php print file_create_url($uri_block_5_image) ?>, (medium)]"/>
                <noscript><img src="<?php print file_create_url($uri_block_5_image) ?>" alt="<?php print $block_5_title ?>"/></noscript>
                <!-- [Responsive img] end-->
              <?php endif; ?>
          </figure>
          <?php if ($block_5_title): ?>
            <div class="heading--small ourAdvices__heading">
                <h2 class="heading__title"><?php print $block_5_title ?></h2>
            </div>
          <?php endif; ?>
          <?php if ($block_5_text): ?>
            <p class="ourAdvices__text"><?php print $block_5_text ?></p>
          <?php endif; ?>
      </article>
      <!-- [Article Advice] end-->
    <?php } ?>
</article>
<!-- [content Advice] end-->
<!-- [article list] start-->
<section class="section-padding articleList bg-lightGrey">
    <div class="wrapper">
        <header class="heading text-center">
            <h3 class="heading__title heading__title--sub"><?php print $title_main_block_article ?></h3>
            <p class="articleList__intro"><?php print $intro_main_block_article ?></p>
        </header>
        <div data-equalizer data-slick="{&quot;slidesToShow&quot;: 1, &quot;slidesToScroll&quot;: 1}" data-slick-responsive="small-only" class="articleList__list">
            <?php if ($title_block_article_1): ?>
              <div class="articleList__item">
                  <?php if ($image_block_article_1): ?>
                    <div class="articleList__item__img">
                        <!-- [Responsive img] start--><img alt="<?php print $title_block_article_1 ?>" data-interchange="[<?php print file_create_url($image_block_article_1) ?>, (small)], [<?php print file_create_url($image_block_article_1) ?>, (large)]"/>
                        <noscript><img src="<?php print file_create_url($image_block_article_1) ?>" alt="<?php print $title_block_article_1 ?>"/></noscript>
                        <!-- [Responsive img] end-->
                    </div>
                  <?php endif; ?>
                  <div data-equalizer-watch="data-equalizer-watch" class="articleList__item__infos">
                      <h4 class="articleList__item__infos__heading"><?php print $title_block_article_1 ?></h4>
                      <?php if ($list_block_article_1): ?>
                        <ul class="articleList__item__infos__links">
                            <?php
                            foreach ($list_block_article_1 as $l):
                              $article_alias = url('node/' . $l['entity']->nid);
                              $article_alias = explode('/', $article_alias);
                              $article_alias = end($article_alias);
                              $path = $article_alias;
                              $current_dossier_path = request_path();
                              $path = $current_dossier_path . '/' . $path;
                              $path = str_replace('content/', '', $path);
                              ?>
                              <li><a href="<?php print $path ?>" title="<?php print $l['entity']->title ?>"><?php print $l['entity']->title ?></a></li>
                            <?php endforeach; ?>
                        </ul>
                      <?php endif; ?>
                  </div>
              </div>
            <?php endif; ?>
            <?php if ($title_block_article_2): ?>
              <div class="articleList__item">
                  <?php if ($image_block_article_2): ?>
                    <div class="articleList__item__img">
                        <!-- [Responsive img] start--><img alt="<?php print $title_block_article_2 ?>" data-interchange="[<?php print file_create_url($image_block_article_2) ?>, (small)], [<?php print file_create_url($image_block_article_2) ?>, (large)]"/>
                        <noscript><img src="<?php print file_create_url($image_block_article_2) ?>" alt="<?php print $title_block_article_2 ?>"/></noscript>
                        <!-- [Responsive img] end-->
                    </div>
                  <?php endif; ?>
                  <div data-equalizer-watch="data-equalizer-watch" class="articleList__item__infos">
                      <h4 class="articleList__item__infos__heading"><?php print $title_block_article_2 ?></h4>
                      <?php if ($list_block_article_2): ?>
                        <ul class="articleList__item__infos__links">
                            <?php
                            foreach ($list_block_article_1 as $l):
                              $article_alias = url('node/' . $l['entity']->nid);
                              $article_alias = explode('/', $article_alias);
                              $article_alias = end($article_alias);
                              $path = $article_alias;
                              $current_dossier_path = request_path();
                              $path = $current_dossier_path . '/' . $path;
                              $path = str_replace('content/', '', $path);
                              ?>
                              <li><a href="<?php print $path ?>" title="<?php print $l['entity']->title ?>"><?php print $l['entity']->title ?></a></li>
                            <?php endforeach; ?>
                        </ul>
                      <?php endif; ?>
                  </div>
              </div>
            <?php endif; ?>
            <?php if ($title_block_article_3): ?>
              <div class="articleList__item">
                  <?php if ($image_block_article_3): ?>
                    <div class="articleList__item__img">
                        <!-- [Responsive img] start--><img alt="<?php print $title_block_article_3 ?>" data-interchange="[<?php print file_create_url($image_block_article_3) ?>, (small)], [<?php print file_create_url($image_block_article_3) ?>, (large)]"/>
                        <noscript><img src="<?php print file_create_url($image_block_article_3) ?>" alt="<?php print $title_block_article_3 ?>"/></noscript>
                        <!-- [Responsive img] end-->
                    </div>
                  <?php endif; ?>
                  <div data-equalizer-watch="data-equalizer-watch" class="articleList__item__infos">
                      <h4 class="articleList__item__infos__heading"><?php print $title_block_article_3 ?></h4>
                      <?php if ($list_block_article_3): ?>
                        <ul class="articleList__item__infos__links">
                            <?php
                            foreach ($list_block_article_1 as $l):
                              $article_alias = url('node/' . $l['entity']->nid);
                              $article_alias = explode('/', $article_alias);
                              $article_alias = end($article_alias);
                              $path = $article_alias;
                              $current_dossier_path = request_path();
                              $path = $current_dossier_path . '/' . $path;
                              $path = str_replace('content/', '', $path);
                              ?>
                              <li><a href="<?php print $path ?>" title="<?php print $l['entity']->title ?>"><?php print $l['entity']->title ?></a></li>
                            <?php endforeach; ?>
                        </ul>
                      <?php endif; ?>
                  </div>
              </div>
            <?php endif; ?>
        </div>
    </div>
</section>
<!-- [article list] end-->
<!-- [contactUs generic] start-->
<aside class="contactUs section-padding contactUs-generic">
    <div style="background-image: url(<?php print $path_img ?>contactUs.jpg)" class="contactUs__img show-for-medium-up"></div>
    <div class="wrapper">
        <div class="contactUs__informations">
            <div class="small-wrapper">
                <p class="contactUs__informations__heading">Nous pouvons vous aider à concrétiser votre projet immobilier</p>
                <p class="contactUs__informations__text">D’autres consommateurs se posent les même questions que vous</p>
                <div class="contactUs__informations__cta">
                    <a href="tel://0800544000" class="btn-phone-green">
                        <span>N°&nbsp;vert&nbsp;</span>0 800 544 000</a>
                    <a href="#" class="btn-white">Consulter notre FAQ<span class="icon icon-arrow"></span></a>
                </div>
            </div>
        </div>
        <div class="contactUs__cta"><a href="partials/formCallBack.html" data-reveal-id="popinLeadForm" data-reveal-ajax="true" class="btn-primary btn-rounded">Rappelez moi</a><a href="partials/formRendezVous.html" data-reveal-id="popinLeadForm" data-reveal-ajax="true" class="btn-secondary btn-rounded">Prendre rendez-vous</a></div>
    </div>
</aside>
<!-- [contactUs generic] end-->