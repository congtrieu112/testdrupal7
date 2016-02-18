<?php
$tabs = kandb_group_button_tabs_header('corporate/activites/habitat', $_GET['q']);
print $tabs;
print theme('group_activities_header');
$description = variable_get('desciption_group_habitat_section', t('Sed posuere consectetur est at lobortis. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur'));
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
        <p class="activities__desc"><?php print isset($description['value']) ? $description['value'] : ''; ?></p>
        <!-- [linksBlock: buttons] start-->
        <nav class="form-dropdown form-dropdown--responsive">
            <button aria-expanded="false" aria-controls="dropdown-downloadDocs" data-app-dropdown="data-app-dropdown" data-app-dropdown-responsive="small-only" class="form-dropdown__trigger"><?php print $data['term_name']; ?><span aria-hidden="true" class="icon icon-expand"></span></button>
            <div id="dropdown-downloadDocs" aria-hidden="true" class="form-dropdown__content hidden">
                <ul class="ul-unstyled undo-padding">
                    <?php if (isset($data['type'])): ?>
                      <?php foreach ($data['type'] as $term): ?>
                        <?php if (isset($data['active']) && $term->tid == $data['active']): ?>
                          <li class="bordered"><a href="<?php print url('corporate/activites/habitat/' . $term->tid); ?>" class="active" onclick="javascript:return tc_events_1(this,'CLICK',{'LABEL':'activites::habitat::<?php print kandb_tagcommander_sanitize_for_event($term->name); ?>','XTCLICK_EVENT':'C','XTCLICK_S2':'5','XTCLICK_TYPE':'N'});"><span><?php print $term->name; ?></span></a></li>
                        <?php else: ?>
                          <li class="bordered"><a href="<?php print url('corporate/activites/habitat/' . $term->tid); ?>" onclick="javascript:return tc_events_1(this,'CLICK',{'LABEL':'activites::habitat::<?php print kandb_tagcommander_sanitize_for_event($term->name); ?>','XTCLICK_EVENT':'C','XTCLICK_S2':'5','XTCLICK_TYPE':'N'});"><span><?php print $term->name; ?></span></a></li>
                        <?php endif; ?>
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
        <?php if (isset($data['nodes'])): ?>
          <?php
          foreach ($data['nodes'] as $node):
            $ville = isset($node->field_habitat_ville[LANGUAGE_NONE][0]['tid']) ? taxonomy_term_load($node->field_habitat_ville[LANGUAGE_NONE][0]['tid']) : '';
            ?>
            <div class="activities__item">
                <div class="activities__item__img">
                    <!-- [Responsive img] start--><img alt="test" data-interchange="[<?php print image_style_url('programme_teaser_3', $node->field_habitat_image['und'][0]['uri']); ?>, (small)], [<?php print image_style_url('bien_more_info_programe_large_780_x_298', $node->field_habitat_image['und'][0]['uri']) ?>, (large)]"/>
                    <noscript><img src="<?php print image_style_url('bien_more_info_programe_large_780_x_298', $node->field_habitat_image['und'][0]['uri']); ?>" alt="test"/></noscript>
                    <!-- [Responsive img] end-->
                </div>
                <div class="activities__item__infos">
                    <h4 class="activities__item__title"><?php print $node->field_habitat_code_postal[LANGUAGE_NONE][0]['value']; ?> <?php print isset($ville->name) ? $ville->name : ''; ?></h4>
                    <p class="activities__item__subs"><?php print isset($node->field_habitat_address['und'][0]['value']) ? $node->field_habitat_address['und'][0]['value'] : ''; ?></p>
                    <p><?php print isset($node->field_habitat_content['und'][0]['value']) ? nl2br($node->field_habitat_content['und'][0]['value']) : ''; ?></p>
                </div>
            </div>
          <?php endforeach; ?>
        <?php endif; ?>

    </div>
</section>
<!-- [Activities] end-->
