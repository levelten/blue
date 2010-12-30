<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function blue_yourself_imagecache_default_presets() {
  $items = array(
    'blueme' => array(
      'presetname' => 'blueme',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_desaturate',
          'data' => array(),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache_coloractions',
          'action' => 'imagecache_colorshift',
          'data' => array(
            'RGB' => array(
              'HEX' => '0033FF',
            ),
          ),
        ),
      ),
    ),
    'blueme_preview' => array(
      'presetname' => 'blueme_preview',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '200',
            'height' => '150',
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache',
          'action' => 'imagecache_desaturate',
          'data' => array(),
        ),
        '2' => array(
          'weight' => '-8',
          'module' => 'imagecache_coloractions',
          'action' => 'imagecache_colorshift',
          'data' => array(
            'RGB' => array(
              'HEX' => '0033FF',
            ),
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function blue_yourself_node_info() {
  $items = array(
    'picture' => array(
      'name' => t('Picture'),
      'module' => 'features',
      'description' => t('Upload a picture you would like to blue.  Please keep this family friendly.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function blue_yourself_views_api() {
  return array(
    'api' => '2',
  );
}
