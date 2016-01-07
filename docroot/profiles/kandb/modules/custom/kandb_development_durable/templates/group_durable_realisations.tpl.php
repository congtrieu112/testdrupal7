<?php
print theme('group_durable_header');

$title = $data['title'];
$subtitle = $data['subtitle'];
$content = $data['content'];
$path_image = $data['path_image'];
$embed = $data['embed'];
$articles = $data['articles']
?>
<?php if($title || $resume || $content || $path_image || $embed) : ?>
<!-- [content Advice] start-->
<article class="wrapper section-padding ourAdvices">
  <!-- [Advice introduction] start-->
  <?php if($title || $subtitle) : ?>
  <header class="heading heading--bordered">
    <?php if($title) : ?><h1 class="heading__title"><?php print $title ?></h1><?php endif; ?>
    <?php if($subtitle) : ?><p class="heading__title heading__title--sub"><?php print $subtitle ?></p><?php endif; ?>
  </header>
  <?php endif; ?>
  <!-- images need to have 2 formats:
 - small: 560 x 350 (High compression)
 - medium: 1180 x 380
  -->
  <?php if ($embed): ?>
  <a href="<?php if ($embed) print 'http://www.youtube.com/watch?v=' . $embed; ?>" title="<?php print $title; ?>" data-reveal-id="videoConseilMain" data-interchange="<?php
  if ($path_image) {
    print $path_image;
    ?>, (small)], [<?php
          print $path_image . ', (medium)]';
        }
        ?>" class="ourAdvices__video heading heading--white"><span class="icon icon-play"></span></a>
  <!-- [popin] start-->
  <div id="videoConseilMain" data-reveal="data-reveal" aria-hidden="true" role="dialog" class="reveal-modal full scroll">
    <div class="reveal-modal__wrapper"><a aria-label="Fermer" class="close-reveal-modal icon icon-close"></a>
      <div class="flex-video youtube">
        <iframe width="1280" height="720" src="" data-src="//www.youtube.com/embed/<?php print $embed ?>" frameborder="0" allowfullscreen allowtransparency="true"></iframe>
      </div>
    </div>
  </div>
  <?php else : ?>
  <div data-interchange="<?php
  if ($path_image) {
    print $path_image;
    ?>, (small)], [<?php
          print $path_image . ', (medium)]';
        }
        ?>" class="ourAdvices__video heading heading--white"></div>
  <?php endif; ?>
  <!-- [popin] end-->

  <p class="ourAdvices__text"><?php print $content['value'] ?></p>
  <!-- [Advice introduction] end-->

  <?php for($i = 1; $i <= 5; $i++) :
    $block_1_title = isset($articles[$i]['article_title']) ? $articles[$i]['article_title'] : '';
    $uri_block_1_image = isset($articles[$i]['article_path_image']) ? $articles[$i]['article_path_image'] : '';
    $block_1_text = isset($articles[$i]['article_subtitle']) ? $articles[$i]['article_subtitle'] : '';
  ?>

    <?php if ($block_1_title) { ?>
      <!-- [Article Advice] start-->
    <article class="text-center">
      <figure class="ourAdvices__figure">
        <!-- images need to have 2 formats in data-interchange attribute:
        - small:
        - medium: 850 x 345
        -->
        <?php if ($uri_block_1_image): ?>
          <!-- [Responsive img] start--><img alt="<?php print $block_1_title ?>" data-interchange="[<?php print $uri_block_1_image ?>, (small)], [<?php print $uri_block_1_image ?>, (medium)]"/>
          <noscript><img src="<?php print $uri_block_1_image ?>" alt="<?php print $block_1_title ?>"/></noscript>
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
  <?php endfor; ?>
</article>
<?php endif; ?>