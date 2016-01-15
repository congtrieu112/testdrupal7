<?php
if (isset($data['group_header'])):
  print render($data['group_header']);
endif;
?>
<section class="section-padding groupHomepageArticle bg-lightGrey">
    <div class="wrapper">
        <div data-equalizer data-equalizer-mq="medium-up" class="articleList__list">
            <?php if (isset($data['documents'])): ?>
              <div data-equalizer-watch class="articleList__item">
                  <div class="inner">
                      <div class="articleList__item__infos">
                          <h4 class="articleList__item__infos__heading"><?php print t('Derniers Communiqués'); ?></h4>
                          <dl class="articleList__item__infos__list">
                              <?php foreach ($data['documents'] as $document) : ?>
                                <dt>
                                <a href="<?php print url('corporate/finance/publication'); ?>">
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
            <?php if (isset($data['finance_block']) && isset($data['finance_block']['image']) && $data['finance_block']['image']): ?>
              <div data-equalizer-watch="data-equalizer-watch" class="articleList__item">
                  <div class="inner">
                      <div class="articleList__item__img">
                          <!-- [Responsive img] start--><img alt="<?php print $data['finance_block']['title']; ?>" data-interchange="[<?php print $data['finance_block']['image']; ?>, (small)], [<?php print $data['finance_block']['image']; ?>, (large)]"/>
                          <noscript><img src="<?php print $data['finance_block']['image']; ?>" alt="<?php print $data['finance_block']['title']; ?>"/></noscript>
                          <!-- [Responsive img] end-->
                      </div>
                      <div class="articleList__item__infos">
                          <div class="lang">
                            <nav class="wrapper">
                              <ul>
                                <li class="fr active"><a href="javascript:void(0)" title="<?php print t('Version française de la page'); ?>"><?php print t('fr'); ?></a></li>
                                <li class="en"><a href="<?php print url('corporate/finance/presentation/en'); ?>" title="<?php print t('English version of the page'); ?>"><?php print t('en'); ?></a></li>
                              </ul>
                            </nav>
                          </div>
                          <h4 class="articleList__item__infos__heading"><?php print $data['finance_block']['title']; ?></h4>
                          <ul class="articleList__item__infos__links">
                              <?php if (isset($data['finance_block']['cta'])): ?>
                                <?php foreach ($data['finance_block']['cta'] as $value) : ?>
                                  <?php if (trim($value['title'])): ?>
                                    <li><a href="<?php print url($value['url']); ?>" title="<?php print trim($value['title']); ?>"><?php print trim($value['title']); ?></a></li>
                                  <?php endif; ?>
                                <?php endforeach; ?>
                                <li><a href="<?php print url('corporate/finance/presentation/en'); ?>" title="<?php print t('English version'); ?>"><?php print t('English version'); ?></a></li>
                              <?php endif; ?>
                          </ul>
                      </div>
                  </div>
              </div>
            <?php endif; ?>
            <?php if (isset($data['ressources_humaines_block']) && isset($data['ressources_humaines_block']['image']) && $data['ressources_humaines_block']['image']): ?>
              <div data-equalizer-watch="data-equalizer-watch" class="articleList__item">
                  <div class="inner">
                      <div class="articleList__item__img">
                          <!-- [Responsive img] start--><img alt="<?php print $data['ressources_humaines_block']['title']; ?>" data-interchange="[<?php print $data['ressources_humaines_block']['image']; ?>, (small)], [<?php print $data['ressources_humaines_block']['image']; ?>, (large)]"/>
                          <noscript><img src="<?php print $data['ressources_humaines_block']['image']; ?>" alt="<?php print $data['finance_block']['title']; ?>"/></noscript>
                          <!-- [Responsive img] end-->
                      </div>
                      <div class="articleList__item__infos">
                          <h4 class="articleList__item__infos__heading"><?php print $data['ressources_humaines_block']['title']; ?></h4>
                          <ul class="articleList__item__infos__links">
                              <?php if (isset($data['ressources_humaines_block']['cta'])): ?>
                                <?php foreach ($data['ressources_humaines_block']['cta'] as $value) : ?>
                                  <?php if (trim($value['title'])): ?>
                                    <li><a href="<?php print url($value['url']); ?>" title="<?php print trim($value['title']); ?>"><?php print trim($value['title']); ?></a></li>
                                  <?php endif; ?>

                                <?php endforeach; ?>
                              <?php endif; ?>
                          </ul>
                      </div>
                  </div>
              </div>
            <?php endif; ?>
            <?php if (isset($data['activites_block']) && isset($data['activites_block']['image']) && $data['activites_block']['image']): ?>
              <div data-equalizer-watch="data-equalizer-watch" class="articleList__item">
                  <div class="inner">
                      <div class="articleList__item__img">
                          <!-- [Responsive img] start--><img alt="<?php print $data['activites_block']['title']; ?>" data-interchange="[<?php print $data['activites_block']['image']; ?>, (small)], [<?php print $data['activites_block']['image']; ?>, (large)]"/>
                          <noscript><img src="<?php print $data['activites_block']['image']; ?>" alt="<?php print $data['activites_block']['title']; ?>"/></noscript>
                          <!-- [Responsive img] end-->
                      </div>
                      <div class="articleList__item__infos">
                          <h4 class="articleList__item__infos__heading"><?php print $data['activites_block']['title']; ?></h4>
                          <ul class="articleList__item__infos__links">
                              <?php if (isset($data['activites_block']['cta'])): ?>
                                <?php foreach ($data['activites_block']['cta'] as $value) : ?>
                                  <?php if (trim($value['title'])): ?>
                                    <li><a href="<?php print url($value['url']); ?>" title="<?php print trim($value['title']); ?>"><?php print trim($value['title']); ?></a></li>
                                  <?php endif; ?>

                                <?php endforeach; ?>
                              <?php endif; ?>
                          </ul>
                      </div>
                  </div>
              </div>
            <?php endif; ?>
            <?php if (isset($data['actualites_block']) && isset($data['actualites_block']['image']) && $data['actualites_block']['image']): ?>
              <div data-equalizer-watch="data-equalizer-watch" class="articleList__item">
                  <div class="inner">
                      <div class="articleList__item__img">
                          <!-- [Responsive img] start--><img alt="<?php print $data['actualites_block']['title']; ?>" data-interchange="[<?php print $data['actualites_block']['image']; ?>, (small)], [<?php print $data['actualites_block']['image']; ?>, (large)]"/>
                          <noscript><img src="<?php print $data['actualites_block']['image']; ?>" alt="<?php print $data['actualites_block']['title']; ?>"/></noscript>
                          <!-- [Responsive img] end-->
                      </div>
                      <div class="articleList__item__infos">
                          <h4 class="articleList__item__infos__heading"><?php print $data['actualites_block']['title']; ?></h4>
                          <ul class="articleList__item__infos__links">
                              <?php if (isset($data['actualites_block']['cta'])): ?>
                                <?php foreach ($data['actualites_block']['cta'] as $value) : ?>
                                  <?php if (trim($value['title'])): ?>
                                    <li><a href="<?php print url($value['url']); ?>" title="<?php print trim($value['title']); ?>"><?php print trim($value['title']); ?></a></li>
                                  <?php endif; ?>

                                <?php endforeach; ?>
                              <?php endif; ?>
                          </ul>
                      </div>
                  </div>
              </div>
            <?php endif; ?>
            <?php if (isset($data['developpement_durable_block']) && isset($data['developpement_durable_block']['image']) && $data['developpement_durable_block']['image']): ?>
              <div data-equalizer-watch="data-equalizer-watch" class="articleList__item">
                  <div class="inner">
                      <div class="articleList__item__img">
                          <!-- [Responsive img] start--><img alt="<?php print $data['developpement_durable_block']['title']; ?>" data-interchange="[<?php print $data['developpement_durable_block']['image']; ?>, (small)], [<?php print $data['developpement_durable_block']['image']; ?>, (large)]"/>
                          <noscript><img src="<?php print $data['developpement_durable_block']['image']; ?>" alt="<?php print $data['developpement_durable_block']['title']; ?>"/></noscript>
                          <!-- [Responsive img] end-->
                      </div>
                      <div class="articleList__item__infos">
                          <h4 class="articleList__item__infos__heading"><?php print $data['developpement_durable_block']['title']; ?></h4>
                          <ul class="articleList__item__infos__links">
                              <?php if (isset($data['developpement_durable_block']['cta'])): ?>
                                <?php foreach ($data['developpement_durable_block']['cta'] as $value) : ?>
                                  <?php if (trim($value['title'])): ?>
                                    <li><a href="<?php print url($value['url']); ?>" title="<?php print trim($value['title']); ?>"><?php print trim($value['title']); ?></a></li>
                                  <?php endif; ?>

                                <?php endforeach; ?>
                              <?php endif; ?>
                          </ul>
                      </div>
                  </div>
              </div>
            <?php endif; ?> 
            <!--            <div data-equalizer-watch="data-equalizer-watch" class="articleList__item">
                            <div class="inner">
                                <div class="articleList__item__img">
                                     [Responsive img] start<img alt="test" data-interchange="[test_assets/advices-small.jpg, (small)], [test_assets/advices-medium.jpg, (large)]"/>
                                    <noscript><img src="test_assets/advices-medium.jpg" alt="test"/></noscript>
                                     [Responsive img] end
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
                        </div>-->
        </div>
    </div>
</section>