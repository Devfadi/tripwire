<?php

/**
 * @file
 * program_landing_page_content_type.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function program_landing_page_content_type_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'program_landing_page_carousel';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Program landing page carousel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Program landing page carousel';
  $handler->display->display_options['css_class'] = 'program-carousel';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slick';
  $handler->display->display_options['style_options']['slide_field_wrapper'] = 0;
  $handler->display->display_options['style_options']['asnavfor_auto'] = 0;
  $handler->display->display_options['style_options']['skin'] = 'classic';
  $handler->display->display_options['style_options']['slide_caption'] = array(
    'field_program_carousel' => 0,
  );
  $handler->display->display_options['style_options']['slide_overlay'] = '';
  $handler->display->display_options['style_options']['preserve_keys'] = 0;
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['overridables'] = array(
    'autoplay' => 'autoplay',
    'arrows' => 0,
    'dots' => 0,
    'draggable' => 0,
  );
  $handler->display->display_options['style_options']['cache'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Post-Auth program carousel */
  $handler->display->display_options['fields']['field_program_carousel']['id'] = 'field_program_carousel';
  $handler->display->display_options['fields']['field_program_carousel']['table'] = 'field_data_field_program_carousel';
  $handler->display->display_options['fields']['field_program_carousel']['field'] = 'field_program_carousel';
  $handler->display->display_options['fields']['field_program_carousel']['label'] = '';
  $handler->display->display_options['fields']['field_program_carousel']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_carousel']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_program_carousel']['settings'] = array(
    'image_style' => 'program_landing_page_carousel',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_program_carousel']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_program_carousel']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program_landing_page' => 'program_landing_page',
  );

  /* Display: Post-Auth Program Carousel */
  $handler = $view->new_display('block', 'Post-Auth Program Carousel', 'block');

  /* Display: Pre-Auth Program Carousel */
  $handler = $view->new_display('block', 'Pre-Auth Program Carousel', 'block_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Pre-Auth program carousel */
  $handler->display->display_options['fields']['field_pre_auth_program_carousel']['id'] = 'field_pre_auth_program_carousel';
  $handler->display->display_options['fields']['field_pre_auth_program_carousel']['table'] = 'field_data_field_pre_auth_program_carousel';
  $handler->display->display_options['fields']['field_pre_auth_program_carousel']['field'] = 'field_pre_auth_program_carousel';
  $handler->display->display_options['fields']['field_pre_auth_program_carousel']['label'] = '';
  $handler->display->display_options['fields']['field_pre_auth_program_carousel']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pre_auth_program_carousel']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pre_auth_program_carousel']['settings'] = array(
    'image_style' => 'program_landing_page_carousel',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_pre_auth_program_carousel']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_pre_auth_program_carousel']['delta_offset'] = '0';
  $export['program_landing_page_carousel'] = $view;

  $view = new view();
  $view->name = 'program_landing_page_documents';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Program Landing Page Documents';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_documents_target_id']['id'] = 'field_related_documents_target_id';
  $handler->display->display_options['relationships']['field_related_documents_target_id']['table'] = 'field_data_field_related_documents';
  $handler->display->display_options['relationships']['field_related_documents_target_id']['field'] = 'field_related_documents_target_id';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_related_documents_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_screenshot']['id'] = 'field_screenshot';
  $handler->display->display_options['fields']['field_screenshot']['table'] = 'field_data_field_screenshot';
  $handler->display->display_options['fields']['field_screenshot']['field'] = 'field_screenshot';
  $handler->display->display_options['fields']['field_screenshot']['relationship'] = 'field_related_documents_target_id';
  $handler->display->display_options['fields']['field_screenshot']['label'] = '';
  $handler->display->display_options['fields']['field_screenshot']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_screenshot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_screenshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_screenshot']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Link URL */
  $handler->display->display_options['fields']['field_link_url']['id'] = 'field_link_url';
  $handler->display->display_options['fields']['field_link_url']['table'] = 'field_data_field_link_url';
  $handler->display->display_options['fields']['field_link_url']['field'] = 'field_link_url';
  $handler->display->display_options['fields']['field_link_url']['relationship'] = 'field_related_documents_target_id';
  $handler->display->display_options['fields']['field_link_url']['label'] = '';
  $handler->display->display_options['fields']['field_link_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_link_url']['alter']['text'] = '<a href="[field_link_url]" class="linked-image">[field_screenshot]</a>';
  $handler->display->display_options['fields']['field_link_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_url']['empty'] = '<a href="[path]" target="_blank">[field_screenshot]</a>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_related_documents_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: PDF Document */
  $handler->display->display_options['fields']['field_pdf_doc']['id'] = 'field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['table'] = 'field_data_field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['field'] = 'field_pdf_doc';
  $handler->display->display_options['fields']['field_pdf_doc']['relationship'] = 'field_related_documents_target_id';
  $handler->display->display_options['fields']['field_pdf_doc']['label'] = '';
  $handler->display->display_options['fields']['field_pdf_doc']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pdf_doc']['alter']['text'] = '<a href="[field_pdf_doc]" target="_blank">Click here to download [title]</a>';
  $handler->display->display_options['fields']['field_pdf_doc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pdf_doc']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pdf_doc']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_pdf_doc']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['program_landing_page_documents'] = $view;

  return $export;
}
