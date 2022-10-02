<?php

function tw_activateuser_verify($arg1) {
  $query = new EntityFieldQuery;
  $email = filter_xss(htmlspecialchars($_GET['email']));
  if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
    return 'Invalid email format';
  }
  $query->entityCondition('entity_type', 'user')
    ->propertyCondition('mail', $email);

  $result = $query->execute();

  // not found?
  if (!isset($result['user'])) return;

  // found, keys are uids
  $uids = array_keys($result['user']);
  $account = user_load($uids[0]);

  $uid = $account->uid;
  // Try to retrieve the question for a valid user.
  $questions = $uid ? tw_security_questions_user_question_get($uid) : FALSE;
  //start new code
  $html = '';
  $i = 0;
  foreach ($questions as $question) {
    ++$i;
    $html .= '<form class="verify-user" action="verify-user-check" method="POST">';
    $html .= '  <div id="edit-challenge-' . $i . '-question" class="form-item form-type-item">';
    $html .= '    <label for="edit-challenge-' . $i . '-question">Security question '. $i . '</label>';
    $html .= '    <em class="placeholder">' . $question->question . '</em>';
    $html .= '  </div>';
    $html .= '  <div><input type="text" name="answer' . $i . '" id="edit-challenge-' . $i . '-answer" size="60" class="form-text required"></div>';
  }
  $html .= '  <input type="hidden" name="uid" value="' . $uid . '">';
  $html .= '  <input type="submit">';
  $html .= '</form>';

  return $html;

}

function tw_activateuser_verifycheck($arg1) {
  $uid = $_POST['uid'];
  $questions = $uid ? tw_security_questions_user_question_get($uid) : FALSE;
  $a[1] = filter_xss(_tw_security_questions_answer_sanitise($_POST['answer1']));
  $a[2] = filter_xss(_tw_security_questions_answer_sanitise($_POST['answer2']));
  $pass1 = FALSE;
  $pass2 = FALSE;
  $i = 0;

  foreach ($questions as $question) {
    ++$i;
    if(_tw_security_questions_answer_check($question->answer, $a[$i]) == '1') {
      $pass[$i] = TRUE;
    } else {
      $pass[$i] = FALSE;
    }
  }

  if ($pass[1] == TRUE && $pass[2] == TRUE) {
    $user = user_load($uid);

    $tids = array();
    $tids[] = key(taxonomy_get_term_by_name('Awaiting Approval'));
    $tids[] = key(taxonomy_get_term_by_name('Imported from TW 1.0'));

    //Unassign existing taxonomy terms for user status field
    $i = 0;
    foreach ($user->field_user_status['und'] as $u) {
      unset($user->field_user_status['und'][$i]);
      ++$i;
    }
    $user->field_user_status['und'] = array_values($user->field_user_status['und']);
    
    //Assign taxonomy terms
    foreach ($tids as $tid) {
      $user->field_user_status['und'][]['tid'] = $tid;
    }
    user_save($user);
    $html = 'Thank you for verifying your account. A site administrator will review your profile and activate your account.';
  } else {
    $html = 'Sorry, but your answers did not match your security question.  <a href="/activate">Please try again by clicking here</a>.';
  }

  return $html;
}
