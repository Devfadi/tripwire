<?php

if ($view->name == 'extremist_threat_reports_dashboard' || $view->name == 'documents_available_to_international_users') {
  if (!empty($view->exposed_raw_input['created'])) {
    print("Results of search for reports added since " . $view->exposed_raw_input['created']);
    print("\r\n");
  }
  if ($view->exposed_raw_input['date_filter']['value'] !== NULL) {
    print("Results of reports for the month of " . $view->exposed_raw_input['date_filter']['value']);
    print("\r\n");
  }
  if(isset($view->total_rows)) {
    print("There are ". $view->total_rows . " results.  \r\n");
  } else {
    if (isset($view->result)) {
      print("There are " . count($view->result) . " results.  \r\n");
    }
  }
}

// Print out header row, if option was selected.
if ($options['header']) {
  print implode($separator, $header) . "\r\n";
}

