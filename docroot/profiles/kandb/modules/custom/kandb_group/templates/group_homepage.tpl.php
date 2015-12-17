<?php
if (isset($data['group_header'])):
  print render($data['group_header']);
endif;
?>
<section class="section-padding groupHomepageArticle bg-lightGrey">
    <div class="wrapper">
        <div data-equalizer data-equalizer-mq="medium-up" class="articleList__list">
            <?php if ($data['documents']): ?>
              <div data-equalizer-watch class="articleList__item">
                  <div class="inner">
                      <div class="articleList__item__infos">
                          <h4 class="articleList__item__infos__heading"><?php print t('Derniers Communiqués'); ?></h4>
                          <dl class="articleList__item__infos__list">
                              <?php foreach ($data['documents'] as $document) : ?>
                                <dt>
                                <a href="<?php print url('node/' . $document->nid); ?>">
                                    <span class="icon icon-communique"></span>
                                    <span class="text"><?php print date('d.m.Y', strtotime($document->field_document_date[LANGUAGE_NONE][0]['value'])); ?></span>
                                </a>
                                </dt>
                                <dd>
                                    <p><?php print $document->title; ?></p>
                                </dd>
                              <?php endforeach; ?>
                          </dl>
                      </div>
                  </div>
              </div>
            <?php endif; ?>
            <div data-equalizer-watch="data-equalizer-watch" class="articleList__item">
                <div class="inner">
                    <div class="articleList__item__img">
                        <!-- [Responsive img] start--><img alt="test" data-interchange="[test_assets/advices-small.jpg, (small)], [test_assets/advices-medium.jpg, (large)]"/>
                        <noscript><img src="test_assets/advices-medium.jpg" alt="test"/></noscript>
                        <!-- [Responsive img] end-->
                    </div>
                    <div class="articleList__item__infos">
                        <h4 class="articleList__item__infos__heading">Qualite: Nos labels</h4>
                        <ul class="articleList__item__infos__links">
                            <li><a href="#" title="La garatie de remboursement ou d'achevement">La garatie de remboursement ou d'achevement</a></li>
                            <li><a href="#" title="La garatie de remboursement ou">La garatie de remboursement ou</a></li>
                            <li><a href="#" title="La garatie de remboursement ou d'achevement remboursement ou d'achevement">La garatie de remboursement ou d'achevement remboursement ou d'achevement</a></li>
                        </ul>
                    </div>
                </div>
            </div>
            <div data-equalizer-watch="data-equalizer-watch" class="articleList__item">
                <div class="inner">
                    <div class="articleList__item__img">
                        <!-- [Responsive img] start--><img alt="test" data-interchange="[test_assets/advices-small.jpg, (small)], [test_assets/advices-medium.jpg, (large)]"/>
                        <noscript><img src="test_assets/advices-medium.jpg" alt="test"/></noscript>
                        <!-- [Responsive img] end-->
                    </div>
                    <div class="articleList__item__infos">
                        <h4 class="articleList__item__infos__heading">Frais réduit et taux preferentiels</h4>
                        <ul class="articleList__item__infos__links">
                            <li><a href="#" title="La garatie de remboursement ou d'achevement">La garatie de remboursement ou d'achevement</a></li>
                            <li><a href="#" title="La garatie de remboursement ou">La garatie de remboursement ou</a></li>
                            <li><a href="#" title="La garatie de">La garatie de</a></li>
                        </ul>
                    </div>
                </div>
            </div>
        </div>
    </div>
</section>