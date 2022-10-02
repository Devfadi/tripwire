<?php
/**
 * @file
 * share_content.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function share_content_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'share_stats';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'forward_log';
  $view->human_name = 'Share stats';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Shares';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    41 => '41',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'path' => 'path',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'path' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Forward: Uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'forward_log';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Forward: Forwarded Path */
  $handler->display->display_options['fields']['path_1']['id'] = 'path_1';
  $handler->display->display_options['fields']['path_1']['table'] = 'forward_log';
  $handler->display->display_options['fields']['path_1']['field'] = 'path';
  $handler->display->display_options['fields']['path_1']['label'] = '';
  $handler->display->display_options['fields']['path_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path_1']['element_label_colon'] = FALSE;
  /* Field: COUNT(Forward: Forwarded Path) */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'forward_log';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['group_type'] = 'count';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = '[path_1] ([path])';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['relationship'] = 'uid';
  /* Sort criterion: COUNT(Forward: Forwarded Path) */
  $handler->display->display_options['sorts']['path']['id'] = 'path';
  $handler->display->display_options['sorts']['path']['table'] = 'forward_log';
  $handler->display->display_options['sorts']['path']['field'] = 'path';
  $handler->display->display_options['sorts']['path']['group_type'] = 'count';
  $handler->display->display_options['sorts']['path']['order'] = 'DESC';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/dashboard/shares';
  $export['share_stats'] = $view;

  return $export;
}
