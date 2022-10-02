<?php

function tw_security_check_force($uid) {
    $field_name = 'field_privacy_act_statement';
    $field_info = field_info_field($field_name);
    $markup = $field_info['settings']['markup']['value'];
    drupal_add_js(drupal_get_path('module', 'tw_security_check') .'/js/tw_security.js', 'file');
    drupal_add_css(drupal_get_path('module', 'tw_security_check') .'/css/tw_security.css', 'file');
    $html = '';
    $html = ' <form class="security-annual" action="/agreement-check" method="GET">';
    $html .= '<p>TripWIRE users are required to review and accept the Security Agreement each year.</p>';
    $html .= '<p>In order to maintain access to TripWIRE, please review the terms and conditions below and indicate your acceptance of the terms by checking the checkbox at the bottom of this page';
    $html .= '<div class="prviacy-info-markup">';
    $html .= $markup;
    $html .= '</div>';
    $html .= '<div class="field-type-list-boolean field-name-field-privacy-agreement field-widget-options-onoff form-wrapper" id="edit-profile-privacy-information-field-privacy-agreement"><div class="form-item form-type-checkbox form-item-profile-privacy-information-field-privacy-agreement-und">    <input type="checkbox" id="edit-profile-privacy-information-field-privacy-agreement-und" name="agree_terms" value="agree" class="form-checkbox required">  <label class="option" for="edit-profile-privacy-information-field-privacy-agreement-und">I have read and agree to the Terms of Service and Privacy Notice. <span class="form-required" title="This field is required.">*</span></label></div></div>';
    $html .= '<input type="hidden" name="uid" value=' . $uid . ' />';
    $html .= '<input type="submit" id="edit-next" name="op" value="Next" class="form-submit disabled" disabled="">';
    $html .= '</form>';

    return $html;
}

function tw_security_check_validate() {
    $agree = filter_xss(htmlspecialchars($_GET['agree_terms']));
    $uid = filter_xss(htmlspecialchars($_GET['uid']));
    if (!isset($uid)) {
        drupal_set_message(t('An error occurred and processing did not complete.'), 'error');
        drupal_goto('/');
    }
    if ($agree !== 'agree') {
        drupal_set_message(t('You must accept the annual security terms.'), 'error');
        drupal_goto('agreement/' . $uid);
    }

    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'user')
        ->propertyCondition('uid', $uid);
    
    $result = $query->execute();

    // not found?
    if (!isset($result['user'])) return;

    $query = db_update('tw_security_check_users')
                ->fields(array('last_security_accept' => REQUEST_TIME))
                ->condition('uid', $uid)
                ->execute();
    $query2 = db_update('users')
                ->fields(array('tw_security_check' => 0))
                ->condition('uid', $uid)
                ->execute();
    
    $user = user_load($uid);
    _write_record($user, 'security_agreement', 'User ' . $user->name . ' has accepted the Annual Security Agreement.', 'SKIP');
    drupal_set_message(t('Thank you for accepting the Annual Security Agreement.'), 'status');
    drupal_goto('/');
}