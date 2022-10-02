<?php

class TfaBasicEmail extends TfaBasePlugin implements TfaValidationPluginInterface, TfaSendPluginInterface {

  const TFA_EMAIL_CODE_LENGTH = 6;
  const TFA_EMAIL_CODE_CHARACTERS = '0123456789';
  const TFA_EMAIL_CODE_EXPIRATION_SECONDS = 600;
  const TFA_EMAIL_CODE_CASE_INSENSITIVE = FALSE;

  protected $siteEmailAddress;
  protected $userEmailAddress;
  protected $account;
  protected $code;
  protected $expiration;
  protected $codeLength;
  protected $codeCharacters;
  protected $codeExpiration;
  protected $codeCaseInsensitive;
  protected $language;

  public function __construct(array $context, $account) {
    parent::__construct($context);
    if (!empty($context['validate_context']) && !empty($context['validate_context']['code'])) {
      $this->code = $context['validate_context']['code'];
      if (isset($context['validate_context']['expiration'])
        && !empty($context['validate_context']['expiration'])
      ) {
        $this->expiration = $context['validate_context']['expiration'];
        }
    }

    $this->account = $account;
    $this->siteEmailAddress = variable_get('site_mail', ini_get('sendmail_from'));
    $this->codeLength = variable_get('tfa_basic_email_code_length', self::TFA_EMAIL_CODE_LENGTH);
    $this->codeCharacters = variable_get('tfa_basic_email_code_characters', self::TFA_EMAIL_CODE_CHARACTERS);
    $this->codeExpiration = variable_get('tfa_basic_email_code_expiration', self::TFA_EMAIL_CODE_EXPIRATION_SECONDS);
    $this->codeCaseInsensitive = variable_get('tfa_basic_email_code_case_insensitive', self::TFA_EMAIL_CODE_CASE_INSENSITIVE);
    $this->language = user_preferred_language($account);

    $this->userEmailAddress = $this->getUserEmailAddress();
  }

  /**
  * Determine if the plugin can run for the current TFA context.
  *
  * @return bool
  */
  public function ready() {
    if (empty($this->account->uid)) {
      return FALSE;
   }
    $tfa_data = tfa_basic_get_tfa_data($this->account);
    if (!isset($tfa_data['data']['plugins'])
      || !is_array($tfa_data['data']['plugins'])
    ) {
      return FALSE;
    }
    if (in_array('tfa_basic_email', $tfa_data['data']['plugins'])) {
      return TRUE;
    }
    return FALSE;
  }

  /**
  *
  */
  public function begin() {
    if (!$this->code) {
      $this->code = $this->generate();
      $this->expiration = $this->expiration();
      if (!$this->sendCode($this->code)) {
        $this->showErrorMessage();
        }
    }
  }

  public function getForm(array $form, array &$form_state) {
    $form['code'] = array(
      '#type' => 'textfield',
      '#title' => t('Email verification code'),
      '#required' => TRUE,
      '#description' => t('Enter @length-character code sent to your email account (@email).', array('@length' => $this->codeLength, '@email' => $this->userEmailAddress)),
      '#attributes' => array('autocomplete' => array('off')),
    );
    $form['actions']['#type'] = 'actions';
    // @todo optionally report on when code was sent/delivered.
    $form['actions']['login'] = array(
      '#type' => 'submit',
      '#value' => t('Verify'),
    );
    $form['actions']['resend'] = array(
      '#type' => 'submit',
      '#value' => t('Resend'),
      '#submit' => array('tfa_form_submit'),
      '#limit_validation_errors' => array(),
    );

    return $form;
  }

  public function validateForm(array $form, array &$form_state) {
    // If operation is resend then do not attempt to validate code.
    if ($form_state['values']['op'] === $form_state['values']['resend']) {
      return TRUE;
    }

    if (!empty($this->expiration) && $this->expiration < time()) {
      $this->errorMessages['code'] = t('Invalid code.');
      return FALSE;
    }

    if (!$this->validate($form_state['values']['code'])) {
      $this->errorMessages['code'] = t('Invalid code.');
      return FALSE;
    }

    return TRUE;
  }

  public function showErrorMessage() {
    $email_error_message = variable_get('tfa_basic_email_error_message', t('An error occurred while attempting to email your authentication code.  If you continue to experience difficulties, please contact us.'));
    drupal_set_message($email_error_message, 'error');

    // clear the message that is automatically generated by core.
    // We don't want to tell the user "Contact the site administrator..."
    $unwanted_core_message = t('Unable to send e-mail. Contact the site administrator if the problem persists.');
    $error_messages = drupal_get_messages('error', TRUE);
    while (($key = array_search($unwanted_core_message, $error_messages['error'])) !== FALSE) {
      unset($error_messages['error'][$key]);
    }
    // restore any queued error messages
    foreach ($error_messages['error'] as $key => $message) {
      drupal_set_message($message, 'error');
    }
    // Take the user back to the login page to view the error message.
    drupal_goto('user');
  }

  public function submitForm(array $form, array &$form_state) {
    // Resend code if pushed.
    if ($form_state['values']['op'] === $form_state['values']['resend']) {
      $this->code = $this->generate();
      $this->expiration = $this->expiration();
      if (!$this->sendCode($this->code)) {
        $this->showErrorMessage();
      }
      else {
        drupal_set_message(t('Code resent'));
      }
      return FALSE;
    }
    else {
      return parent::submitForm($form, $form_state);
    }
  }

  /**
  * Return context for this plugin.
  *
  * @return array
  */
  public function getPluginContext() {
    return array(
      'code' => $this->code,
      'expiration' => $this->expiration,
    );
  }

  protected function generate() {
    $allowable_characters = '0123456789';

    // Zero-based count of characters in the allowable list:
    $len = strlen($allowable_characters) - 1;

    // Declare the password as a blank string.
    $string = '';

    // Loop the number of times specified by codeLength.
    for ($i = 0; $i < $this->codeLength; $i++) {
      do {
        // Find a secure random number within the range needed.
        $index = ord(drupal_random_bytes(1));
        } while ($index > $len);

      // Each iteration, pick a random character from the
      // allowable string and append it to the password:
      $string .= $allowable_characters[$index];
    }
    return $string;
  }

  protected function expiration() {
    return time() + $this->codeExpiration;
  }

  protected function getUserEmailAddress() {
    $email = $this->account->mail;
    if (!empty($this->context['user_email_address'])) {
      $email = $this->context['user_email_address'];
    }
    // Allow other modules to update the email address
    drupal_alter('tfa_basic_email_get_user_email_address', $this->account, $email);
    return $email;
  }

  /**
  * Send the code via the drupal_mail function.
  *
  * @param string $code
  *    The 2-factor authentication code that the challenged user must provide.
  * @return bool
  *    Whether or not an error was detected while sending the message.
  */
  protected function sendCode($code) {
    $to = $this->userEmailAddress;
    $key = 'tfa_basic_email_send_code';
    $params = array(
      'site_name' => variable_get('site_name', 'Your login'),
      'authentication_code' => $code,
      'langcode' => $this->language->language,
      );
    $message_result = drupal_mail('tfa_basic', $key, $to, $this->language, $params);
    return ($message_result['result'] == TRUE);
  }

  /**
  * Validate code.
  * Inspired from https://github.com/facebook/php-graph-sdk/blob/5.x/src/Facebook/polyfills.php.
  *
  * @param string $code Code to be validated.
  * @return bool Whether code is valid.
  */
  protected function validate($code) {
    $this->isValid = FALSE;

    $kLen = strlen($code);
    $uLen = strlen($this->code);

    if ($kLen !== $uLen) {
      return FALSE;
    }

    $result = 0;
    for ($i = 0; $i < $kLen; $i++) {
      $result |= (ord($code[$i]) ^ ord($this->code[$i]));
    }
    // They are only identical strings if $result is exactly 0...
    if (0 === $result) {
      $this->isValid = TRUE;
      return TRUE;
    }

    return FALSE;
  }
}

 /**
 * Class TfaBasicEmailSetup.
 */
class TfaBasicEmailSetup extends TfaBasicEmail implements TfaSetupPluginInterface {

  public function __construct(array $context, $account) {
    parent::__construct($context, $account);
    }

  public function begin() {
    if (empty($this->code)) {
      $this->code = $this->generate();
      $this->expiration = $this->expiration();
      if (!$this->sendCode($this->code)) {
        $this->errorMessages[''] = t('Unable to deliver verification code to (@email_address).', array('@email_address' => $this->account->mail));
      }
    }
  }

  /**
  * @copydoc TfaSetupPluginInterface::getSetupForm()
  */
  public function getSetupForm(array $form, array &$form_state) {
    $form['email_code'] = array(
      '#type' => 'textfield',
      '#title' => t('Verification Code'),
      '#required' => TRUE,
      '#description' => t('Enter @length-character code sent to your email account (@email_address).', array('@length' => $this->codeLength, '@email_address' => $this->account->mail)),
    );
    $form['actions']['verify'] = array(
      '#type' => 'submit',
      '#value' => t('Verify and save'),
    );

    return $form;
  }

  /**
     * @copydoc TfaSetupPluginInterface::validateSetupForm()
  */
  public function validateSetupForm(array $form, array &$form_state) {
    if (!$this->validate($form_state['values']['email_code'])) {
      $this->errorMessages['email_code'] = t('Invalid code. Please try again.');
      return FALSE;
    }
    else {
      return TRUE;
    }
  }

  /**
     * @copydoc TfaSetupPluginInterface::submitSetupForm()
   */
  public function submitSetupForm(array $form, array &$form_state) {
    // No submission handling required.
    return TRUE;
  }

}