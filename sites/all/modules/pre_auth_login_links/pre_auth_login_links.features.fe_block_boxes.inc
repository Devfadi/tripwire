<?php
/**
 * @file
 * pre_auth_login_links.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function pre_auth_login_links_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Log In';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'custom_login';
  $fe_block_boxes->body = '<p><a class="login-button" href="/user">TRIP<span>wire</span> Login</a></p>';

  $export['custom_login'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Register';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'custom_register';
  $fe_block_boxes->body = '<p>Need an account? <a class="register-now" href="user/register">Register now</a></p>';

  $export['custom_register'] = $fe_block_boxes;

  return $export;
}
