<?php
/**
 * Created by PhpStorm.
 * User: ralph
 * Date: 06.02.15
 * Time: 17:23
 */

global $pixelgarage_path;

// redesign of login forms
include_once($pixelgarage_path . '/inc/login.inc');
include_once($pixelgarage_path . '/inc/background.inc');

/**
 * Preprocess variables for the html template.
 */
function pixelgarage_preprocess_html(&$vars) {
  global $base_url;

  // make sure jQuery UI and effects is loaded for anonymous users
  drupal_add_library('system', 'ui');
  drupal_add_library('system', 'effects');

  // add head links
  $path = $base_url . '/' . drupal_get_path('theme', 'pixelgarage');
  drupal_add_html_head_link(array('href' => $path . '/fonts/ss-steedicons/ss-steedicons.css', 'rel'=>'stylesheet'));
}

/**
 * Override or insert variables for the page templates.
 */
function pixelgarage_preprocess_page(&$vars) {
  // hides page title on login forms
  pg_login_preprocess_page($vars);

  // add a random page background
  pg_background_preprocess_page($vars);
}

/**
 * Preprocess the variables of the proximity view.
 *
 * @param $vars
 */
function pixelgarage_preprocess_views_view_proximity(&$vars) {
  // add the rendered node fields (hidden) to $vars, so that it can be separately printed in the template
  $view = &$vars['view'];
  $count = 0;

  foreach ($vars['view']->result as $id => $row) {
    switch ($id) {
      case 1: // Projekte -> ProjectPage view mode
        $vars['rendered_nodes'][] = $view->style_plugin->get_field($id, 'rendered_entity_1');
        break;
      case 2: // Kontakt -> ContactPage view mode
        $vars['rendered_nodes'][] = $view->style_plugin->get_field($id, 'rendered_entity_2');
        break;
      case 4: // Gallerie -> GalleryPage view mode
        $vars['rendered_nodes'][] = $view->style_plugin->get_field($id, 'rendered_entity_3');
        break;
      default: // -> full view mode
        $vars['rendered_nodes'][] = $view->style_plugin->get_field($id, 'rendered_entity');
        break;
    }
    $vars['titles'][] =  $view->style_plugin->get_field($id, 'title');
    $count++;
  }

  // define percentage width of items
  $vars['percentage_width'] = 100 / $count;

  // close button text
  $vars['close_text'] = t('Schliessen');
}

/**
 * Preprocess the bootstrap accordion view.
 * @param $vars
 */
function pixelgarage_preprocess_views_bootstrap_accordion_plugin_style(&$vars) {
  $view = &$vars['view'];

  // Get title fields.
  foreach ($vars['view']->result as $id => $row) {
    $vars['dates'][$id] = t('Start: ') . strip_tags($view->style_plugin->get_field($id, 'field_season_year'));
  }
}
