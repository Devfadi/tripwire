<?php
/**
 * @file
 * search_results_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function search_results_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'search_results';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_drupal_search';
  $view->human_name = 'Search Results';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'TRIPwire Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 0;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Search Block HTML */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'Search Block HTML';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<form action="/search" method="get" id="views-exposed-form-search-results-page" accept-charset="UTF-8" _lpchecked="1"><div><div class="views-exposed-form">
  <div class="views-exposed-widgets clearfix">
          <div id="edit-search-api-views-fulltext-wrapper" class="views-exposed-widget views-widget-filter-search_api_views_fulltext">
                        <div class="views-widget">
          <div class="form-item form-type-textfield form-item-search-api-views-fulltext">
 <input type="text" id="edit-search-api-views-fulltext" name="search_api_views_fulltext" value="" size="30" maxlength="128" class="form-text">
</div>
        </div>
              </div>
                    <div class="views-exposed-widget views-submit-button">
      <input type="submit" id="edit-submit-search-results" name="" value="Apply" class="form-submit">    </div>
      </div>
</div>
</div></form>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_drupal_search';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_drupal_search';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Search: Excerpt */
  $handler->display->display_options['fields']['search_api_excerpt']['id'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['table'] = 'search_api_index_drupal_search';
  $handler->display->display_options['fields']['search_api_excerpt']['field'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['label'] = '';
  $handler->display->display_options['fields']['search_api_excerpt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['empty'] = '[body]';
  $handler->display->display_options['fields']['search_api_excerpt']['link_to_entity'] = 0;
  /* Field: Indexed Node: Document */
  $handler->display->display_options['fields']['field_pdf_doc']['id'] = 'field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['table'] = 'search_api_index_drupal_search';
  $handler->display->display_options['fields']['field_pdf_doc']['field'] = 'field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_pdf_doc']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pdf_doc']['type'] = 'file_download_link';
  $handler->display->display_options['fields']['field_pdf_doc']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  $handler->display->display_options['fields']['field_pdf_doc']['delta_offset'] = '0';
  /* Field: Indexed Node: Subject */
  $handler->display->display_options['fields']['field_subject']['id'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['table'] = 'search_api_index_drupal_search';
  $handler->display->display_options['fields']['field_subject']['field'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_subject']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_subject']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_subject']['bypass_access'] = 0;
  /* Field: Indexed Node: Training &amp; Education */
  $handler->display->display_options['fields']['field_training_education']['id'] = 'field_training_education';
  $handler->display->display_options['fields']['field_training_education']['table'] = 'search_api_index_drupal_search';
  $handler->display->display_options['fields']['field_training_education']['field'] = 'field_training_education';
  $handler->display->display_options['fields']['field_training_education']['label'] = 'Training & Education';
  $handler->display->display_options['fields']['field_training_education']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_training_education']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_training_education']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_training_education']['bypass_access'] = 0;
  /* Field: Indexed Node: Training Courses */
  $handler->display->display_options['fields']['field_training_courses']['id'] = 'field_training_courses';
  $handler->display->display_options['fields']['field_training_courses']['table'] = 'search_api_index_drupal_search';
  $handler->display->display_options['fields']['field_training_courses']['field'] = 'field_training_courses';
  $handler->display->display_options['fields']['field_training_courses']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_training_courses']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_training_courses']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_training_courses']['bypass_access'] = 0;
  /* Field: Indexed Node: Number of views */
  $handler->display->display_options['fields']['views']['id'] = 'views';
  $handler->display->display_options['fields']['views']['table'] = 'search_api_index_drupal_search';
  $handler->display->display_options['fields']['views']['field'] = 'views';
  $handler->display->display_options['fields']['views']['label'] = '';
  $handler->display->display_options['fields']['views']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['views']['alter']['text'] = '[views] views';
  $handler->display->display_options['fields']['views']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['views']['link_to_entity'] = 0;
  /* Field: Rating */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['ui_name'] = 'Rating';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'rating_only';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_drupal_search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    7 => 0,
    21 => 0,
    10 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    14 => 0,
    3 => 0,
    41 => 0,
    4 => 0,
    6 => 0,
    36 => 0,
    31 => 0,
    26 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'search';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'search_result';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'search-results-nf';
  $export['search_results'] = $view;

  return $export;
}
