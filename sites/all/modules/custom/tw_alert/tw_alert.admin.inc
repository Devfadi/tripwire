<?php

/**
 * Menu callback: Display the settings form.
 */
function tw_alert_settings_form() {
    $block = block_load('block', 51);
    if ($block->status == 0) {
      $message = 'Incident alert box is currently disabled.';
    } else {
      $message = 'Incident alert box is currently enabled.';
    }
    drupal_set_message($message,'warning', FALSE);

    $form = array();

    $form['html'] = array(
      '#type' => 'markup',
      '#markup' => '<p><a href="/admin/structure/block/manage/block/51/configure">Configure the Incident Alert block</a></p>',
     );

    $form['enable_alert_block'] = array(
      '#type' => 'submit',
      '#value' => t('Enable Alert Box'),
      '#limit_validation_errors' => array(),
      '#submit' => array('tw_alert_enable_alert'), //call function
    );

    $form['disable_alert_block'] = array(
      '#type' => 'submit',
      '#value' => t('Disable Alert Box'),
      '#limit_validation_errors' => array(),
      '#submit' => array('tw_alert_disable_alert'), //call function
    );

    return $form;
    
}

function tw_alert_enable_alert() {
  db_update('block')
    ->fields(array(
      'status' =>'1',
      'weight' => '0',
      'region' => 'content_top',
    ))
    ->condition('module', 'block')
    ->condition('delta', '51')
    ->condition('theme', 'rubix_responsive_theme')
    ->execute();
    $message = 'Incident alert block enabled';
    drupal_set_message($message,'status', FALSE);
}

function tw_alert_disable_alert() {
  db_update('block')
    ->fields(array(
      'status' =>'0',
      'weight' => '0',
      'region' => 'content_top',
    ))
    ->condition('module', 'block')
    ->condition('delta', '51')
    ->condition('theme', 'rubix_responsive_theme')
    ->execute();
    $message = 'Incident alert block disabled';
    drupal_set_message($message,'status', FALSE);
}