<?php
  function bmap_icon_fix_form() {
    $form = array();
    
    $form['run_icon_fix'] = array(
      '#type' => 'submit',
      '#value' => t('Run BMAP Icon Script'),
      '#limit_validation_errors' => array(),
      '#submit' => array('bmap_icon_fix'), //call function
    );

    return $form;

  }

  function bmap_icon_fix() {
    $runcount = 0;
    $day_start = date("Y-m-d", strtotime("-366 day"));
    $day_end = date("Y-m-d", strtotime("-364 day"));
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'bmap_activity_data')
            ->fieldCondition('field_date_of_activity', 'value', array($day_start, $day_end), 'BETWEEN')
            ->range(0,50);
     $result = $query->execute();
    if (isset($result['node'])) {
       $runcount++;
       watchdog('tw_content', 'Running BMAP icon script, pass ' . $runcount, array(), WATCHDOG_INFO, NULL);
       bmap_run($result);
     }
  }

  function bmap_run($array) {
    $now = strtotime("-1 year");
      $nids = array();
      foreach ($array['node'] as $n) {
        $nids[] = $n->nid;
        //$node = node_load($n->nid);
      }
      foreach (node_load_multiple($nids) as $node) {
        if (isset($node->field_date_of_activity['und'])) {
          $date = strtotime($node->field_date_of_activity['und'][0]['value']);
          if ($date < $now) {
             $node->field_bmap_map_flag['und'][0]['tid'] = '4991';
          } else {
            $node->field_bmap_map_flag['und'][0]['tid'] = '4990';
          }
          node_save($node);
        }
      }
    //bmap_icon_fix();
  } 
?>
