<?php
/**
 * @file
 * new_user_registration.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function new_user_registration_default_rules_configuration() {
  $items = array();
  $items['rules_new_profile_redirect'] = entity_import('rules_config', '{ "rules_new_profile_redirect" : {
      "LABEL" : "New profile redirect",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "profile2" ],
      "ON" : { "profile2_update" : [] },
      "DO" : [
        { "php_eval" : { "code" : "if (current_path() == \\u0027user\\/register\\/confirmation\\u0027) {\\r\\ndpm(\\u0022HIT\\u0022);\\r\\n\\/\\/watchdog(\\u0027MyModule\\u0027, \\u0027My message\\u0027, array(), WATCHDOG_INFO, NULL);\\r\\ndrupal_goto(\\u0027thanks\\u0027);\\r\\n}" } }
      ]
    }
  }');
  $items['rules_new_user_registration'] = entity_import('rules_config', '{ "rules_new_user_registration" : {
      "LABEL" : "New user registration",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "user", "id" : [ "account:uid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "user_add_role" : {
            "account" : [ "entity-fetched" ],
            "roles" : { "value" : { "22" : "22" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-fetched:field-user-status" ],
            "value" : { "value" : { "4377" : "4377" } }
          }
        }
      ]
    }
  }');
  $items['rules_password_verification'] = entity_import('rules_config', '{ "rules_password_verification" : {
      "LABEL" : "Password verification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "logintoboggan_rules" ],
      "ON" : { "logintoboggan_validated" : [] },
      "DO" : [
        { "drupal_message" : { "message" : "Validated!!!!!" } },
        { "entity_fetch" : {
            "USING" : { "type" : "user", "id" : [ "account:uid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-fetched:field-user-status" ],
            "value" : { "value" : { "4378" : "4378" } }
          }
        },
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "23" : "23" } } } }
      ]
    }
  }');
  $items['rules_prevent_login'] = entity_import('rules_config', '{ "rules_prevent_login" : {
      "LABEL" : "Prevent login",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php" ],
      "ON" : { "node_view" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "23" : "23" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "php_eval" : { "code" : "global $user;\\r\\nsetcookie(\\u0027my_message\\u0027, t(\\u0022Thank you for verifying your email address.  Our service team will review your account for activation and contact you directly when you have been approved.\\u0022), time() + (86400 * 30), \\u0022\\/\\u0022);\\r\\ndrupal_goto(\\u0027\\/user\\/logout\\u0027);\\r\\n" } }
      ]
    }
  }');
  return $items;
}
