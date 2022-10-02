<?php


/**
 * This function creates the settings page. It is a callback function for drupal_get_form()
 */
function tw_maintenance_settings($form, &$form_state) {
    $form['#attached']['css'][] = drupal_get_path('module', 'tw_maintenance') . '/css/tw_maintenance.css';
    $form['#attached']['js'][] = drupal_get_path('module', 'tw_maintenance') . '/js/validate.js';

    $form['dev_env'] = array (
        '#type' => 'textfield',
        '#title' => t('Dev Environment URL'),
        '#default_value' => variable_get('dev_env', 'https://tripwire-dev.k2share.com'),
        
    );

    $form['stage_env'] = array (
        '#type' => 'textfield',
        '#title' => t('Stage Environment URL'),
        '#default_value' => variable_get('stage_env', 'http://tripwire6pv9xetnky.devcloud.acquia-sites.com'),
    );

    $form['prod_env'] = array (
        '#type' => 'textfield',
        '#title' => t('Prod Environment URL'),
        '#default_value' => variable_get('prod_env', 'http://tripwirewqfbstv3ag.devcloud.acquia-sites.com'),
    );

    return system_settings_form($form);
}