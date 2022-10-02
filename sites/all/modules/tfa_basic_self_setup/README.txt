INTRODUCTION
============
This module is used to address the UX concerns and general problems that exist
when trying to allow users to set up their own two-factor authentication.

https://www.drupal.org/project/tfa_basic/issues/2838432

The module alters core user login, profile and one-time login forms to route
users to the TFA setup screens if they have not yet completed them.

REQUIREMENTS
============
https://www.drupal.org/project/tfa
https://www.drupal.org/project/tfa_basic

INSTALLATION
============
Nothing special, just enable as you normally would. There is no admin interface
for this module.

CONFIGURATION
=============
None. Note that the module grants TFA Basic's "setup own tfa" permission
when enabled; this is required for the module to function properly.
