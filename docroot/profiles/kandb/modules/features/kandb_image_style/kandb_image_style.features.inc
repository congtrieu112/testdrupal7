<?php
/**
 * @file
 * kandb_image_style.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function kandb_image_style_image_default_styles() {
  $styles = array();

  // Exported image style: article_selection.
  $styles['article_selection'] = array(
    'label' => 'Article Selection (440x440)',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 440,
          'height' => 440,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: bien_large__1380_x_600.
  $styles['bien_large__1380_x_600'] = array(
    'label' => 'Bien large (1380 x 670)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1380,
          'height' => 600,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: bien_more_info_programe_large_780_x_298.
  $styles['bien_more_info_programe_large_780_x_298'] = array(
    'label' => 'Bien more info programe large (780 x 298)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 780,
          'height' => 298,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: bien_more_info_programe_medium_632_x_241.
  $styles['bien_more_info_programe_medium_632_x_241'] = array(
    'label' => 'Bien more info programe medium (632 x 241)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 632,
          'height' => 241,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: bien_more_info_programe_small_560_x_214.
  $styles['bien_more_info_programe_small_560_x_214'] = array(
    'label' => 'Bien more info programe small (560 x 214)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 214,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: contact_selection.
  $styles['contact_selection'] = array(
    'label' => 'Contact Selection (60x60)',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => 1,
      ),
      10 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 10,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: dossier_big_teaser.
  $styles['dossier_big_teaser'] = array(
    'label' => 'Dossier Big Teaser (1180x380)',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1180,
          'height' => 380,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: dossier_big_teaser_mobile.
  $styles['dossier_big_teaser_mobile'] = array(
    'label' => 'Dossier Big Teaser Mobile (560x365)',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 365,
        ),
        'weight' => 1,
      ),
      9 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 20,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: dossier_small_teaser.
  $styles['dossier_small_teaser'] = array(
    'label' => 'Dossier Small Teaser (560x365)',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 365,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: dossier_small_teaser_mobile.
  $styles['dossier_small_teaser_mobile'] = array(
    'label' => 'Dossier Small Teaser Mobile (560x365)',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 365,
        ),
        'weight' => 1,
      ),
      12 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 20,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: finance_presentation_speech_215_x_215.
  $styles['finance_presentation_speech_215_x_215'] = array(
    'label' => 'Finance Presentation Speech (215 x 215)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 215,
          'height' => 215,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: homepageb2b_backgound_large.
  $styles['homepageb2b_backgound_large'] = array(
    'label' => 'HomepageB2B Backgound Large (1380x712)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1380,
          'height' => 712,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: homepageb2b_backgound_small.
  $styles['homepageb2b_backgound_small'] = array(
    'label' => 'HomepageB2B Backgound Small (640x448)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 448,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hp_search_block.
  $styles['hp_search_block'] = array(
    'label' => 'HP Search Block (1380x590)',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1380,
          'height' => 590,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hp_search_block_mobile.
  $styles['hp_search_block_mobile'] = array(
    'label' => 'HP Search Block Mobile (640x845)',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 845,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: kpi_component_580_x_296.
  $styles['kpi_component_580_x_296'] = array(
    'label' => 'KPI Component (580 x 296)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 580,
          'height' => 296,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: program_image_num_piece.
  $styles['program_image_num_piece'] = array(
    'label' => 'Program image num piece',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 380,
          'height' => 230,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: programme_selection_medium.
  $styles['programme_selection_medium'] = array(
    'label' => 'Programme Selection Medium (300x300)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: programme_selection_small.
  $styles['programme_selection_small'] = array(
    'label' => 'Programme Selection Small (560x310) with compression',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 310,
        ),
        'weight' => 1,
      ),
      3 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 10,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: programme_selection_very_small.
  $styles['programme_selection_very_small'] = array(
    'label' => 'Programme Selection Very Small (160x160)',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 160,
          'height' => 160,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: programme_teaser_3.
  $styles['programme_teaser_3'] = array(
    'label' => 'Programme Teaser 3 (440x440)',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 440,
          'height' => 440,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: search_medium.
  $styles['search_medium'] = array(
    'label' => 'Search Medium (180x180)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 180,
          'height' => 180,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: search_small.
  $styles['search_small'] = array(
    'label' => 'Search Small (180x180)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 180,
          'height' => 180,
        ),
        'weight' => 1,
      ),
      3 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 5,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
