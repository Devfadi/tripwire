<?php

function tw_activateuser_activation() {
  $html = ' <form class="activate-user" action="verify-user" method="GET">';
  $html .='  <input type="text" size="50" placeholder="Enter your TW 1.0 email address" name="email" /><br />';
  $html .='  <input type="submit" value="Submit" />';
  $html .= '</form>';
  return $html;
}
