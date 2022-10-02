<?php

function tw_maintenance_version() {
    if (file_exists("ver.php")) {
        $branchfile = fopen("ver.php", "r");
        $branch = fread($branchfile, filesize("ver.php"));
        fclose($branchfile);
    } else {
        $branch = 'File with GIT branch not found.';
    }


    global $base_url;
    $envs = array();
    $envs['dev'] = variable_get('dev_env', 'http://tripwiren3sj2eqkxf.devcloud.acquia-sites.com');
    $envs['stage'] = variable_get('stage_env', 'http://tripwire6pv9xetnky.devcloud.acquia-sites.com');
    $envs['prod'] = variable_get('prod_env', 'http://tripwirewqfbstv3ag.devcloud.acquia-sites.com');
    if (false !== $key = array_search($base_url, $envs)) {
        $current = $key;
    } else {
        $current = 'Unable to determine environment. Current base URL does not match any environments defined at <a href="/admin/config/system/tw_version">TripWIRE Version Settings</a>.';
    }
    $html = '<p><strong>Site Version</strong>: ' . $branch . '</p>';
    $html .= '<p><strong>Current Environment</strong>: <span style="text-transform: uppercase">' . $current . '</span></p>';

    return $html;

}