<?php
/**
 * @file
 * Provides functionality to integrate a dynamic page background.
 *
 * Prerequisites:
 * - a content type 'pxl_background' has to exist, otherwise nothing is performed
 */

/**
 * Override or insert variables for the page templates.
 */
function pg_background_preprocess_page(&$vars) {
  if (!($rendered_item = _get_rendered_background_item('field_images'))) return;

  $vars['background_item'] = drupal_render($rendered_item);
}

/**
 * Retrieves the background element from the background node and render it.
 *
 * @param $item  string A string defining a field name or the complete node rendered on the background. 'node'|'field-name'
 * @return array|bool
 */
function _get_rendered_background_item($item = 'node') {
  // prerequisite: a content type called background has to exist
  $result = db_query("SELECT nid FROM {node} WHERE type = :type", array(':type' => 'pxl_background'));

  if ($result) {
    // get the first background node
    foreach ($result as $record) {
      // return rendered node
      $node = node_load($record->nid);
      switch ($item) {
        case 'node':
          return node_view($node);
        case 'field_images':
          $images = field_get_items('node', $node, $item);
          return field_view_value('node', $node, $item, $images[mt_rand(0, count($images)-1)], 'full');
          break;
      }
    }

  } else {
    //drupal_set_message(t('No content type "pxl_background" available. Please add a content type with machine name "pxl_background" to define the dynamic background in it.'), 'warning');
    return FALSE;
  }

}

