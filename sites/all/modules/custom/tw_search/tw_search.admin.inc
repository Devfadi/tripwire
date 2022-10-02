<?php

/**
 * Menu callback: Display the settings form.
 */
function tw_search_settings_form() {
    //$config = _tw_search_variable_get();
    $form = array();

    $form['tw_search_promo1'] = array(
        '#type' => 'textfield',
        '#title' => t('Promoted search phrase 1'),
        '#default_value' => variable_get('tw_search_promo1'),
      );

      $form['tw_search_promo2'] = array(
        '#type' => 'textfield',
        '#title' => t('Promoted search phrase 2'),
        '#default_value' => variable_get('tw_search_promo2'),
      );

      $form['tw_search_promo3'] = array(
        '#type' => 'textfield',
        '#title' => t('Promoted search phrase 3'),
        '#default_value' => variable_get('tw_search_promo3'),
      );

    return system_settings_form($form);
    
}