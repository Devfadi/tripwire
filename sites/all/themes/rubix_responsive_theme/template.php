<?php
/**
 * Implements hook_html_head_alter().
 * This will overwrite the default meta character type tag with HTML5 version.
 */
function rubix_responsive_theme_html_head_alter(&$head_elements) {
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8'
  );
}

/**
 * Insert themed breadcrumb page navigation at top of the node content.
 */
function rubix_responsive_theme_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {
    // Use CSS to hide titile .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    // comment below line to hide current page to breadcrumb
	$breadcrumb[] = drupal_get_title();
    $output .= '<nav class="breadcrumb">' . implode(' » ', $breadcrumb) . '</nav>';
    return $output;
  }
}

/**
 * Override or insert variables into the page template.
 */
function rubix_responsive_theme_preprocess_page(&$vars) {
  if (isset($vars['main_menu'])) {
    $vars['main_menu'] = theme('links__system_main_menu', array(
      'links' => $vars['main_menu'],
      'attributes' => array(
        'class' => array('links', 'main-menu', 'clearfix'),
      ),
      'heading' => array(
        'text' => t('Main menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }
  else {
    $vars['main_menu'] = FALSE;
  }
  if (isset($vars['secondary_menu'])) {
    $vars['secondary_menu'] = theme('links__system_secondary_menu', array(
      'links' => $vars['secondary_menu'],
      'attributes' => array(
        'class' => array('links', 'secondary-menu', 'clearfix'),
      ),
      'heading' => array(
        'text' => t('Secondary menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }
  else {
    $vars['secondary_menu'] = FALSE;
  }
}

/**
 * Duplicate of theme_menu_local_tasks() but adds clearfix to tabs.
 */
function rubix_responsive_theme_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs primary clearfix">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs secondary clearfix">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }
  return $output;
}

function rubix_responsive_theme_preprocess_menu_link(&$variables) {
  /**
   * T2OM-107: Adding iframe hack to fix IE11 issues with main menu hiding behind PDF
   * https://stackoverflow.com/questions/47026860/main-menu-css-is-behind-pdf-inside-iframe-in-ie
   */
  if ($variables['theme_hook_original'] == 'menu_link__main_menu') {
    if (empty($variables['element']['#below'])) {
      $variables['element']['#below']['#markup'] = '<iframe class="iframetrick"></iframe>';
    }
  }
}

/**
 * Override or insert variables into the node template.
 */
function rubix_responsive_theme_preprocess_node(&$variables) {
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full' && node_is_page($variables['node'])) {
    $variables['classes_array'][] = 'node-full';
  }
}

function rubix_responsive_theme_page_alter($page) {
  // <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1"/>
  $viewport = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
    'name' =>  'viewport',
    'content' =>  'width=device-width'
    )
  );
  drupal_add_html_head($viewport, 'viewport');
}

function rubix_responsive_theme_preprocess_html(&$variables){
  drupal_add_library('system', 'ui.tooltip');
}

function rubix_responsive_theme_preprocess_form_element(&$variables) {
  if (isset($variables['element']['#title'])) {
    if($variables['element']['#title'] === 'Val' || $variables['element']['#title'] === 'Like') {
      $variables['element']['#title'] = '';
    }
  }
}
