<?php
/**
 * @file
 * dhs_password_rules.default_password_policy.inc
 */

/**
 * Implements hook_default_password_policy().
 */
function dhs_password_rules_default_password_policy() {
  $export = array();

  $password_policy = new stdClass();
  $password_policy->disabled = FALSE; /* Edit this to true to make a default password_policy disabled initially */
  $password_policy->api_version = 1;
  $password_policy->name = 'DHS Password Rules';
  $password_policy->config = 'a:17:{s:10:"alpha_case";a:1:{s:10:"alpha_case";i:1;}s:11:"alpha_count";a:1:{s:11:"alpha_count";s:0:"";}s:9:"blacklist";a:2:{s:9:"blacklist";s:0:"";s:26:"blacklist_match_substrings";i:1;}s:10:"char_count";a:1:{s:10:"char_count";s:2:"12";}s:11:"consecutive";a:1:{s:22:"consecutive_char_count";s:0:"";}s:5:"delay";a:2:{s:5:"delay";s:0:"";s:9:"threshold";s:1:"1";}s:15:"drupal_strength";a:1:{s:15:"drupal_strength";s:0:"";}s:9:"int_count";a:1:{s:9:"int_count";s:1:"1";}s:9:"no_spaces";a:1:{s:9:"no_spaces";i:1;}s:14:"past_passwords";a:1:{s:14:"past_passwords";s:1:"8";}s:12:"symbol_count";a:2:{s:12:"symbol_count";s:1:"1";s:20:"symbol_count_symbols";s:32:"`~!@#$%^&*()_+=-|}{"?:><,./;\'\\[]";}s:8:"username";a:1:{s:8:"username";i:1;}s:7:"authmap";a:1:{s:11:"authmodules";a:1:{s:18:"simplesamlphp_auth";i:0;}}s:4:"role";a:1:{s:5:"roles";a:19:{i:1;i:0;i:2;i:0;i:8;i:0;i:7;i:0;i:21;i:0;i:10;i:0;i:9;i:0;i:11;i:0;i:12;i:0;i:14;i:0;i:3;i:0;i:41;i:0;i:4;i:0;i:6;i:0;i:36;i:0;i:31;i:0;i:26;i:0;i:42;i:0;i:43;i:0;}}s:6:"expire";a:6:{s:14:"expire_enabled";i:0;s:12:"expire_limit";s:8:"6 months";s:22:"expire_warning_message";s:48:"Your password has expired. Please change it now.";s:25:"expire_warning_email_sent";s:8:"-14 days";s:28:"expire_warning_email_message";s:0:"";s:28:"expire_warning_email_subject";s:94:"[user:name], your password on [site:name] shall expire in [password_expiration_date:interval] ";}s:10:"char_limit";a:1:{s:10:"char_limit";s:2:"15";}s:11:"digit_check";a:1:{s:11:"digit_check";i:1;}}';
  $export['DHS Password Rules'] = $password_policy;

  return $export;
}
