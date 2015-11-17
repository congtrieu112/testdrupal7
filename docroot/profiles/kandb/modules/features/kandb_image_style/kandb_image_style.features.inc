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
