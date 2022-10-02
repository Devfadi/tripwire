<?php
  function tw_user_history_status_track() {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'user');
    $results = $query->execute();

    $users = user_load_multiple(array_keys($results['user']));
    $timestamp = REQUEST_TIME;
    foreach ($users as $u) {
      //Don't include anonymous user
      if ($u->uid == 0) { continue; }

      $name = $u->name;
      $ustatus = array();
      if (isset($u->field_user_status['und'])) {
        foreach ($u->field_user_status['und'] as $us) {
          $term = taxonomy_term_load($us['tid']);
          $ustatus[] = $term->name;
        }
      }
      if (!empty($ustatus)) {
        $status = implode(", ", $ustatus);
      } else { 
        $status = ''; 
      }
      
      $ustate = array();
      if (isset($u->field_account_states['und'])) {
        foreach ($u->field_account_states['und'] as $as) {
          $term = taxonomy_term_load($as['tid']);
          $ustate[] = $term->name;
        }
      }
      if (!empty($ustate)) {
        $state = implode(",", $ustate);
      } else { 
        $state = ''; 
      }
      
      $roles = implode(",", $u->roles);
      $profile =  profile2_load_by_user($u, 'personal_information');
      $fed_region = '';
      if(isset($profile)) { 
        if (isset($profile->field_federal_sector_of_employme['und'])) {
          $fed_region = $profile->field_federal_sector_of_employme['und'][0]['value'];
        }
        tw_user_history_write_status_record($name, $status, $state, $roles, $fed_region, $timestamp, $u->status);
      }
    }
  }

  function tw_user_history_write_status_record($name, $status, $state, $roles, $fed_region, $timestamp, $drupal_status) {
    $data = array(
      'name' => $name,
      'status' => $status,
      'state' => $state,
      'roles' => $roles,
      'fed_region' => $fed_region,
      'timestamp' => REQUEST_TIME,
      'drupal_status' => $drupal_status,
    );
    return drupal_write_record('tw_status_history', $data);
  }
?>