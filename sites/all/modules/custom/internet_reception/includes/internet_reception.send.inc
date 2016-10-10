<?php

/**
 * @file
 * Check the fields and send mail.
 */

/**
 * Validate function for internet_reception_page_form.
 */
function internet_reception_form_validate($form, $form_state) {
  if ($form_state['values']['age'] <= -1) {
    form_set_error('age', t('Age can not be negative'));
  }
  if ($form_state['values']['age'] == 0) {
    form_set_error('age', t('Age is not equal to 0'));
  }
  if (ctype_alnum($form_state['values']['age'] == 0)) {
    form_set_error('age', t('Only numbers!'));
  }
  if (ctype_digit($form_state['values']['full_name'])) {
    form_set_error('full_name', t('Only text!'));
  }
}

/**
 * Send email function for internet reception.
 * @param $form_values The constructed form values array of the submitted form.
 */
function internet_reception_mail_send($form_values) {
  global $user;
  $module = 'internet_reception';
  $key = 'internet_reception';
  $to = $user->mail;
  $from = variable_get('site_mail', ini_get('sendmail_from'));
  $params = $form_values;
  $language = language_default();

  $send = TRUE;
  $result = drupal_mail($module, $key, $to, $language, $params, $from, $send);
  if ($result['result'] == TRUE) {
    drupal_set_message(t('Your message has been sent.'));
  }
  else {
    drupal_set_message(t('There was a problem sending your message and it was not sent.'), 'error');
  }
}

/**
 * Submit function for internet_reception_page_form.
 * @param $form An array of form elements
 * @param $form_state An array which stores information about the form.
 */
function internet_reception_form_submit($form ,&$form_state) {
  internet_reception_mail_send($form_state['values']);
}
