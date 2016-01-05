<?php
print theme('group_activities_header');
?>

<!-- [Activities] start-->
<section class="section-padding activities">
    <div class="wrapper">
        <header class="heading heading--bordered">
            <h1 class="heading__title"><?php print variable_get('title_group_habitat_section', t('A propos de l’habitat')); ?></h1>
            <p class="heading__title heading__title--sub"><?php print variable_get('subtitle_group_habitat_section', t('Nulla vitae elit libero, a pharetra augue donec ullamcorper nulla non')); ?></p>
        </header>
        <div class="heading--small activities__heading">
            <h2 class="heading__title"><?php print variable_get('label_group_habitat_section', t('Donec id elit non mi porta gravida at eget metus morbi leo risus')); ?></h2>
        </div>
        <p class="activities__desc"><?php print nl2br(variable_get('desciption_group_habitat_section', t('Sed posuere consectetur est at lobortis. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur'))) ?></p>
        <!-- [linksBlock: buttons] start-->
        <nav class="form-dropdown form-dropdown--responsive">
            <button aria-expanded="false" aria-controls="dropdown-downloadDocs" data-app-dropdown="data-app-dropdown" data-app-dropdown-responsive="small-only" class="form-dropdown__trigger">Les actualités<span aria-hidden="true" class="icon icon-expand"></span></button>
            <div id="dropdown-downloadDocs" aria-hidden="true" class="form-dropdown__content hidden">
                <ul class="ul-unstyled undo-padding">
                    <?php if (isset($data['type'])): ?>
                      <?php foreach ($data['type'] as $term): ?>
                        <li class="bordered"><a href="<?php print $term->tid; ?>" class=""><span><?php print $term->name; ?></span></a></li>
                      <?php endforeach; ?>
                    <?php endif; ?>
                </ul>
            </div>
        </nav>
        <!-- [linksBlock: buttons] end-->
        <div class="activities__list"></div>
        <!-- images need to have 2 formats:
        - small: 450 x 380 (High compression)
        - medium: 780 x 380
        -->
        <div class="activities__item">
            <div class="activities__item__img">
                <!-- [Responsive img] start--><img alt="test" data-interchange="[test_assets/activity-small.jpg, (small)], [test_assets/activity-medium.jpg, (large)]"/>
                <noscript><img src="test_assets/activity-medium.jpg" alt="test"/></noscript>
                <!-- [Responsive img] end-->
            </div>
            <div class="activities__item__infos">
                <h4 class="activities__item__title">75014 Paris</h4>
                <p class="activities__item__subs">Avenue Paul Vaillant Couturier SHON 8 2002</p>
                <p>Aenean lacinia bibendum nulla sed consectetur. Morbi leo risus, porta ac consectetur ac, vestibulum at eros. Fusce dapibus, tellus ac cursus commodo, tortor mauris condimentum nibh, ut fermentum massa justo sit amet risus.</p>
            </div>
        </div>
        <div class="activities__item">
            <div class="activities__item__img">
                <!-- [Responsive img] start--><img alt="test" data-interchange="[test_assets/activity-small.jpg, (small)], [test_assets/activity-medium.jpg, (large)]"/>
                <noscript><img src="test_assets/activity-medium.jpg" alt="test"/></noscript>
                <!-- [Responsive img] end-->
            </div>
            <div class="activities__item__infos">
                <h4 class="activities__item__title">75014 Paris</h4>
                <p class="activities__item__subs">Avenue Paul Vaillant Couturier SHON 8 2002</p>
                <p>Aenean lacinia bibendum nulla sed consectetur. Morbi leo risus, porta ac consectetur ac, vestibulum at eros. Fusce dapibus, tellus ac cursus commodo, tortor mauris condimentum nibh, ut fermentum massa justo sit amet risus.</p>
            </div>
        </div>
        <div class="activities__item">
            <div class="activities__item__img">
                <!-- [Responsive img] start--><img alt="test" data-interchange="[test_assets/activity-small.jpg, (small)], [test_assets/activity-medium.jpg, (large)]"/>
                <noscript><img src="test_assets/activity-medium.jpg" alt="test"/></noscript>
                <!-- [Responsive img] end-->
            </div>
            <div class="activities__item__infos">
                <h4 class="activities__item__title">75014 Paris</h4>
                <p class="activities__item__subs">Avenue Paul Vaillant Couturier SHON 8 2002</p>
                <p>Aenean lacinia bibendum nulla sed consectetur. Morbi leo risus, porta ac consectetur ac, vestibulum at eros. Fusce dapibus, tellus ac cursus commodo, tortor mauris condimentum nibh, ut fermentum massa justo sit amet risus.</p>
            </div>
        </div>
    </div>
</section>
<!-- [Activities] end-->