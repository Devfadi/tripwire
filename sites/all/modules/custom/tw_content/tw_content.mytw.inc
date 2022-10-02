<?php

function tw_content_mytw() {
    drupal_add_css(drupal_get_path('module', 'tw_content') . '/css/mytripwire.css');
    $person = profile2_load_by_user($_COOKIE['Drupal_visitor_user_uid'], 'personal_information');
    $name = '';
    if(isset($person->field_first_name['und'][0]['value'])) {
        $name .= filter_xss($person->field_first_name['und'][0]['value']) . ' ';
    }
    if(isset($person->field_last_name['und'][0]['value'])) {
        $name .= filter_xss($person->field_last_name['und'][0]['value']) . ' ';
    }
    drupal_set_title('My TRIPwire for ' . $name);

    /* T2OM-162: Saving My TRIPwire subscription info so we do not need to keep loading it */
    if (!isset($_SESSION['mtw'])) {
        tw_content_generate_mtw();
    } else {
    }
    drupal_add_js(array('tw_content' => array('mtw' => $_SESSION['mtw'])), 'setting');
    drupal_add_js(drupal_get_path('module', 'tw_content') . '/js/mytripwire.js', 'file');
    return '';
}

function tw_content_generate_mtw() {
    $profile =  profile2_load_by_user($_COOKIE['Drupal_visitor_user_uid'], 'my_tripwire_subscriptions');
    $tids = array();
    $mtw = array();
    if (!empty($profile->field_federal_region)) {
        foreach ($profile->field_federal_region['und'] as $fr) {
        $tids[] = $fr['tid'];
        }
        $fr_names = taxonomy_term_load_multiple($tids);
        foreach ($fr_names as $term) {
            $trim = substr($term->name , 0, strpos($term->name , ":"));
        $mtw['fed_region'][] = $trim;
        }
    }

    if (!empty($profile->field_subject)) {
        unset ($tids);
        $tids = array();
        foreach ($profile->field_subject['und'] as $s) {
        $tids[] = $s['tid'];
        }
        $subject_names = taxonomy_term_load_multiple($tids);
        foreach ($subject_names as $term) {
        $mtw['subject'][] = $term->name;
        }
    }

    if (!empty($profile->field_author_publisher)) {
        unset ($tids);
        $tids = array();
        foreach ($profile->field_author_publisher['und'] as $ap) {
        $tids[] = $ap['tid'];
        }
        $ap_names = taxonomy_term_load_multiple($tids);
        foreach ($ap_names as $term) {
        $mtw['author'][] = $term->name;
        }
    }

    $_SESSION['mtw'] = $mtw;
}